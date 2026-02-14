#include "format/dpimm.hpp"

namespace veda64 {
namespace format {
namespace dpimm {

// Encoding structures union
union DpimmEncoding {
    uint32_t raw;
    // ADD: Add immediate value
    // Encoding: ADD_32_addsub_imm
    // Template: ADD  <Wd|WSP>, <Wn|WSP>, #<imm>{, <shift>}
    struct Add32AddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Add32AddsubImm add32addsub_imm;

    // ADD: Add immediate value
    // Encoding: ADD_64_addsub_imm
    // Template: ADD  <Xd|SP>, <Xn|SP>, #<imm>{, <shift>}
    struct Add64AddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Add64AddsubImm add64addsub_imm;

    // ADDG: Add with tag
    // Encoding: ADDG_64_addsub_immtags
    // Template: ADDG  <Xd|SP>, <Xn|SP>, #<uimm6>, #<uimm4>
    struct Addg64AddsubImmtags {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm4 : 4;
        uint32_t op3 : 2;  // partial: (0)(0)
        uint32_t imm6 : 6;
        uint32_t _unnamed_1 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Addg64AddsubImmtags addg64addsub_immtags;

    // ADDS: Add immediate value, setting flags
    // Encoding: ADDS_32S_addsub_imm
    // Template: ADDS  <Wd>, <Wn|WSP>, #<imm>{, <shift>}
    struct Adds32sAddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Adds32sAddsubImm adds32s_addsub_imm;

    // ADDS: Add immediate value, setting flags
    // Encoding: ADDS_64S_addsub_imm
    // Template: ADDS  <Xd>, <Xn|SP>, #<imm>{, <shift>}
    struct Adds64sAddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Adds64sAddsubImm adds64s_addsub_imm;

    // ADR: Form PC-relative address
    // Encoding: ADR_only_pcreladdr
    // Template: ADR  <Xd>, <label>
    struct AdrOnlyPcreladdr {
        uint32_t Rd : 5;
        int32_t immhi : 19;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        int32_t immlo : 2;
        uint32_t op : 1;  // fixed: 0b0 (0x0)
    };

    AdrOnlyPcreladdr adr_only_pcreladdr;

    // ADRP: Form PC-relative address to 4KB page
    // Encoding: ADRP_only_pcreladdr
    // Template: ADRP  <Xd>, <label>
    struct AdrpOnlyPcreladdr {
        uint32_t Rd : 5;
        int32_t immhi : 19;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        int32_t immlo : 2;
        uint32_t op : 1;  // fixed: 0b1 (0x1)
    };

    AdrpOnlyPcreladdr adrp_only_pcreladdr;

    // AND: Bitwise AND (immediate)
    // Encoding: AND_32_log_imm
    // Template: AND  <Wd|WSP>, <Wn>, #<imm>
    struct And32LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    And32LogImm and32log_imm;

    // AND: Bitwise AND (immediate)
    // Encoding: AND_64_log_imm
    // Template: AND  <Xd|SP>, <Xn>, #<imm>
    struct And64LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    And64LogImm and64log_imm;

    // ANDS: Bitwise AND (immediate), setting flags
    // Encoding: ANDS_32S_log_imm
    // Template: ANDS  <Wd>, <Wn>, #<imm>
    struct Ands32sLogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ands32sLogImm ands32s_log_imm;

    // ANDS: Bitwise AND (immediate), setting flags
    // Encoding: ANDS_64S_log_imm
    // Template: ANDS  <Xd>, <Xn>, #<imm>
    struct Ands64sLogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ands64sLogImm ands64s_log_imm;

    // SBFM: Arithmetic shift right (immediate)
    // Encoding: ASR_SBFM_32M_bitfield
    // Template: ASR  <Wd>, <Wn>, #<shift>
    struct AsrSbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b011111 (0x1F)
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    AsrSbfm32mBitfield asr_sbfm32m_bitfield;

    // SBFM: Arithmetic shift right (immediate)
    // Encoding: ASR_SBFM_64M_bitfield
    // Template: ASR  <Xd>, <Xn>, #<shift>
    struct AsrSbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b111111 (0x3F)
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    AsrSbfm64mBitfield asr_sbfm64m_bitfield;

    // AUTIASPPC: Authenticate return address using key A, using an immediate offset
    // Encoding: AUTIASPPC_only_dp_1src_imm
    // Template: AUTIASPPC  <label>
    struct AutiasppcOnlyDp1srcImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm16 : 16;
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_2 : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_1 : 3;  // fixed: 0b100 (0x4)
        uint32_t _unnamed_0 : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    AutiasppcOnlyDp1srcImm autiasppc_only_dp1src_imm;

    // AUTIBSPPC: Authenticate return address using key B, using an immediate offset
    // Encoding: AUTIBSPPC_only_dp_1src_imm
    // Template: AUTIBSPPC  <label>
    struct AutibsppcOnlyDp1srcImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm16 : 16;
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_1 : 3;  // fixed: 0b100 (0x4)
        uint32_t _unnamed_0 : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    AutibsppcOnlyDp1srcImm autibsppc_only_dp1src_imm;

    // BFM: Bitfield clear
    // Encoding: BFC_BFM_32M_bitfield
    // Template: BFC  <Wd>, #<lsb>, #<width>
    struct BfcBfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    BfcBfm32mBitfield bfc_bfm32m_bitfield;

    // BFM: Bitfield clear
    // Encoding: BFC_BFM_64M_bitfield
    // Template: BFC  <Xd>, #<lsb>, #<width>
    struct BfcBfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    BfcBfm64mBitfield bfc_bfm64m_bitfield;

    // BFM: Bitfield insert
    // Encoding: BFI_BFM_32M_bitfield
    // Template: BFI  <Wd>, <Wn>, #<lsb>, #<width>
    struct BfiBfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // partial: != 11111
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    BfiBfm32mBitfield bfi_bfm32m_bitfield;

    // BFM: Bitfield insert
    // Encoding: BFI_BFM_64M_bitfield
    // Template: BFI  <Xd>, <Xn>, #<lsb>, #<width>
    struct BfiBfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // partial: != 11111
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    BfiBfm64mBitfield bfi_bfm64m_bitfield;

    // BFM: Bitfield move
    // Encoding: BFM_32M_bitfield
    // Template: BFM  <Wd>, <Wn>, #<immr>, #<imms>
    struct Bfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Bfm32mBitfield bfm32m_bitfield;

    // BFM: Bitfield move
    // Encoding: BFM_64M_bitfield
    // Template: BFM  <Xd>, <Xn>, #<immr>, #<imms>
    struct Bfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Bfm64mBitfield bfm64m_bitfield;

    // BFM: Bitfield extract and insert at low end
    // Encoding: BFXIL_BFM_32M_bitfield
    // Template: BFXIL  <Wd>, <Wn>, #<lsb>, #<width>
    struct BfxilBfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    BfxilBfm32mBitfield bfxil_bfm32m_bitfield;

    // BFM: Bitfield extract and insert at low end
    // Encoding: BFXIL_BFM_64M_bitfield
    // Template: BFXIL  <Xd>, <Xn>, #<lsb>, #<width>
    struct BfxilBfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    BfxilBfm64mBitfield bfxil_bfm64m_bitfield;

    // ADDS: Compare negative (immediate)
    // Encoding: CMN_ADDS_32S_addsub_imm
    // Template: CMN  <Wn|WSP>, #<imm>{, <shift>}
    struct CmnAdds32sAddsubImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CmnAdds32sAddsubImm cmn_adds32s_addsub_imm;

    // ADDS: Compare negative (immediate)
    // Encoding: CMN_ADDS_64S_addsub_imm
    // Template: CMN  <Xn|SP>, #<imm>{, <shift>}
    struct CmnAdds64sAddsubImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmnAdds64sAddsubImm cmn_adds64s_addsub_imm;

    // SUBS: Compare (immediate)
    // Encoding: CMP_SUBS_32S_addsub_imm
    // Template: CMP  <Wn|WSP>, #<imm>{, <shift>}
    struct CmpSubs32sAddsubImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CmpSubs32sAddsubImm cmp_subs32s_addsub_imm;

    // SUBS: Compare (immediate)
    // Encoding: CMP_SUBS_64S_addsub_imm
    // Template: CMP  <Xn|SP>, #<imm>{, <shift>}
    struct CmpSubs64sAddsubImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmpSubs64sAddsubImm cmp_subs64s_addsub_imm;

    // EOR: Bitwise exclusive-OR (immediate)
    // Encoding: EOR_32_log_imm
    // Template: EOR  <Wd|WSP>, <Wn>, #<imm>
    struct Eor32LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Eor32LogImm eor32log_imm;

    // EOR: Bitwise exclusive-OR (immediate)
    // Encoding: EOR_64_log_imm
    // Template: EOR  <Xd|SP>, <Xn>, #<imm>
    struct Eor64LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Eor64LogImm eor64log_imm;

    // EXTR: Extract register
    // Encoding: EXTR_32_extract
    // Template: EXTR  <Wd>, <Wn>, <Wm>, #<lsb>
    struct Extr32Extract {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // partial: 0xxxxx
        uint32_t Rm : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100111 (0x27)
        uint32_t op21 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Extr32Extract extr32extract;

    // EXTR: Extract register
    // Encoding: EXTR_64_extract
    // Template: EXTR  <Xd>, <Xn>, <Xm>, #<lsb>
    struct Extr64Extract {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t Rm : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100111 (0x27)
        uint32_t op21 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Extr64Extract extr64extract;

    // UBFM: Logical shift left (immediate)
    // Encoding: LSL_UBFM_32M_bitfield
    // Template: LSL  <Wd>, <Wn>, #<shift>
    struct LslUbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    LslUbfm32mBitfield lsl_ubfm32m_bitfield;

    // UBFM: Logical shift left (immediate)
    // Encoding: LSL_UBFM_64M_bitfield
    // Template: LSL  <Xd>, <Xn>, #<shift>
    struct LslUbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    LslUbfm64mBitfield lsl_ubfm64m_bitfield;

    // UBFM: Logical shift right (immediate)
    // Encoding: LSR_UBFM_32M_bitfield
    // Template: LSR  <Wd>, <Wn>, #<shift>
    struct LsrUbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b011111 (0x1F)
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    LsrUbfm32mBitfield lsr_ubfm32m_bitfield;

    // UBFM: Logical shift right (immediate)
    // Encoding: LSR_UBFM_64M_bitfield
    // Template: LSR  <Xd>, <Xn>, #<shift>
    struct LsrUbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b111111 (0x3F)
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    LsrUbfm64mBitfield lsr_ubfm64m_bitfield;

    // ADD: Move register value to or from SP
    // Encoding: MOV_ADD_32_addsub_imm
    // Template: MOV  <Wd|WSP>, <Wn|WSP>
    struct MovAdd32AddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;  // fixed: 0b000000000000 (0x0)
        uint32_t sh : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MovAdd32AddsubImm mov_add32addsub_imm;

    // ADD: Move register value to or from SP
    // Encoding: MOV_ADD_64_addsub_imm
    // Template: MOV  <Xd|SP>, <Xn|SP>
    struct MovAdd64AddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;  // fixed: 0b000000000000 (0x0)
        uint32_t sh : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MovAdd64AddsubImm mov_add64addsub_imm;

    // MOVN: Move inverted wide immediate value
    // Encoding: MOV_MOVN_32_movewide
    // Template: MOV  <Wd>, #<imm>
    struct MovMovn32Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;  // partial: 0x
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MovMovn32Movewide mov_movn32movewide;

    // MOVN: Move inverted wide immediate value
    // Encoding: MOV_MOVN_64_movewide
    // Template: MOV  <Xd>, #<imm>
    struct MovMovn64Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MovMovn64Movewide mov_movn64movewide;

    // MOVZ: Move wide immediate value
    // Encoding: MOV_MOVZ_32_movewide
    // Template: MOV  <Wd>, #<imm>
    struct MovMovz32Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;  // partial: 0x
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MovMovz32Movewide mov_movz32movewide;

    // MOVZ: Move wide immediate value
    // Encoding: MOV_MOVZ_64_movewide
    // Template: MOV  <Xd>, #<imm>
    struct MovMovz64Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MovMovz64Movewide mov_movz64movewide;

    // ORR: Move bitmask immediate value
    // Encoding: MOV_ORR_32_log_imm
    // Template: MOV  <Wd|WSP>, #<imm>
    struct MovOrr32LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MovOrr32LogImm mov_orr32log_imm;

    // ORR: Move bitmask immediate value
    // Encoding: MOV_ORR_64_log_imm
    // Template: MOV  <Xd|SP>, #<imm>
    struct MovOrr64LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MovOrr64LogImm mov_orr64log_imm;

    // MOVK: Move wide with keep
    // Encoding: MOVK_32_movewide
    // Template: MOVK  <Wd>, #<imm>{, LSL #<shift>}
    struct Movk32Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;  // partial: 0x
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Movk32Movewide movk32movewide;

    // MOVK: Move wide with keep
    // Encoding: MOVK_64_movewide
    // Template: MOVK  <Xd>, #<imm>{, LSL #<shift>}
    struct Movk64Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Movk64Movewide movk64movewide;

    // MOVN: Move wide with NOT
    // Encoding: MOVN_32_movewide
    // Template: MOVN  <Wd>, #<imm>{, LSL #<shift>}
    struct Movn32Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;  // partial: 0x
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Movn32Movewide movn32movewide;

    // MOVN: Move wide with NOT
    // Encoding: MOVN_64_movewide
    // Template: MOVN  <Xd>, #<imm>{, LSL #<shift>}
    struct Movn64Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Movn64Movewide movn64movewide;

    // MOVZ: Move wide with zero
    // Encoding: MOVZ_32_movewide
    // Template: MOVZ  <Wd>, #<imm>{, LSL #<shift>}
    struct Movz32Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;  // partial: 0x
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Movz32Movewide movz32movewide;

    // MOVZ: Move wide with zero
    // Encoding: MOVZ_64_movewide
    // Template: MOVZ  <Xd>, #<imm>{, LSL #<shift>}
    struct Movz64Movewide {
        uint32_t Rd : 5;
        uint32_t imm16 : 16;
        uint32_t hw : 2;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100101 (0x25)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Movz64Movewide movz64movewide;

    // ORR: Bitwise OR (immediate)
    // Encoding: ORR_32_log_imm
    // Template: ORR  <Wd|WSP>, <Wn>, #<imm>
    struct Orr32LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Orr32LogImm orr32log_imm;

    // ORR: Bitwise OR (immediate)
    // Encoding: ORR_64_log_imm
    // Template: ORR  <Xd|SP>, <Xn>, #<imm>
    struct Orr64LogImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Orr64LogImm orr64log_imm;

    // EXTR: Rotate right (immediate)
    // Encoding: ROR_EXTR_32_extract
    // Template: ROR  <Wd>, <Ws>, #<shift>
    struct RorExtr32Extract {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // partial: 0xxxxx
        uint32_t Rm : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100111 (0x27)
        uint32_t op21 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    RorExtr32Extract ror_extr32extract;

    // EXTR: Rotate right (immediate)
    // Encoding: ROR_EXTR_64_extract
    // Template: ROR  <Xd>, <Xs>, #<shift>
    struct RorExtr64Extract {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t Rm : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100111 (0x27)
        uint32_t op21 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    RorExtr64Extract ror_extr64extract;

    // SBFM: Signed bitfield insert in zeros
    // Encoding: SBFIZ_SBFM_32M_bitfield
    // Template: SBFIZ  <Wd>, <Wn>, #<lsb>, #<width>
    struct SbfizSbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    SbfizSbfm32mBitfield sbfiz_sbfm32m_bitfield;

    // SBFM: Signed bitfield insert in zeros
    // Encoding: SBFIZ_SBFM_64M_bitfield
    // Template: SBFIZ  <Xd>, <Xn>, #<lsb>, #<width>
    struct SbfizSbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SbfizSbfm64mBitfield sbfiz_sbfm64m_bitfield;

    // SBFM: Signed bitfield move
    // Encoding: SBFM_32M_bitfield
    // Template: SBFM  <Wd>, <Wn>, #<immr>, #<imms>
    struct Sbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sbfm32mBitfield sbfm32m_bitfield;

    // SBFM: Signed bitfield move
    // Encoding: SBFM_64M_bitfield
    // Template: SBFM  <Xd>, <Xn>, #<immr>, #<imms>
    struct Sbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sbfm64mBitfield sbfm64m_bitfield;

    // SBFM: Signed bitfield extract
    // Encoding: SBFX_SBFM_32M_bitfield
    // Template: SBFX  <Wd>, <Wn>, #<lsb>, #<width>
    struct SbfxSbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    SbfxSbfm32mBitfield sbfx_sbfm32m_bitfield;

    // SBFM: Signed bitfield extract
    // Encoding: SBFX_SBFM_64M_bitfield
    // Template: SBFX  <Xd>, <Xn>, #<lsb>, #<width>
    struct SbfxSbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SbfxSbfm64mBitfield sbfx_sbfm64m_bitfield;

    // SMAX: Signed maximum (immediate)
    // Encoding: SMAX_32_minmax_imm
    // Template: SMAX  <Wd>, <Wn>, #<simm>
    struct Smax32MinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Smax32MinmaxImm smax32minmax_imm;

    // SMAX: Signed maximum (immediate)
    // Encoding: SMAX_64_minmax_imm
    // Template: SMAX  <Xd>, <Xn>, #<simm>
    struct Smax64MinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smax64MinmaxImm smax64minmax_imm;

    // SMIN: Signed minimum (immediate)
    // Encoding: SMIN_32_minmax_imm
    // Template: SMIN  <Wd>, <Wn>, #<simm>
    struct Smin32MinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Smin32MinmaxImm smin32minmax_imm;

    // SMIN: Signed minimum (immediate)
    // Encoding: SMIN_64_minmax_imm
    // Template: SMIN  <Xd>, <Xn>, #<simm>
    struct Smin64MinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smin64MinmaxImm smin64minmax_imm;

    // SUB: Subtract immediate value
    // Encoding: SUB_32_addsub_imm
    // Template: SUB  <Wd|WSP>, <Wn|WSP>, #<imm>{, <shift>}
    struct Sub32AddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sub32AddsubImm sub32addsub_imm;

    // SUB: Subtract immediate value
    // Encoding: SUB_64_addsub_imm
    // Template: SUB  <Xd|SP>, <Xn|SP>, #<imm>{, <shift>}
    struct Sub64AddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sub64AddsubImm sub64addsub_imm;

    // SUBG: Subtract with tag
    // Encoding: SUBG_64_addsub_immtags
    // Template: SUBG  <Xd|SP>, <Xn|SP>, #<uimm6>, #<uimm4>
    struct Subg64AddsubImmtags {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm4 : 4;
        uint32_t op3 : 2;  // partial: (0)(0)
        uint32_t imm6 : 6;
        uint32_t _unnamed_1 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subg64AddsubImmtags subg64addsub_immtags;

    // SUBS: Subtract immediate value, setting flags
    // Encoding: SUBS_32S_addsub_imm
    // Template: SUBS  <Wd>, <Wn|WSP>, #<imm>{, <shift>}
    struct Subs32sAddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Subs32sAddsubImm subs32s_addsub_imm;

    // SUBS: Subtract immediate value, setting flags
    // Encoding: SUBS_64S_addsub_imm
    // Template: SUBS  <Xd>, <Xn|SP>, #<imm>{, <shift>}
    struct Subs64sAddsubImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm12 : 12;
        uint32_t sh : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100010 (0x22)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subs64sAddsubImm subs64s_addsub_imm;

    // SBFM: Signed extend byte
    // Encoding: SXTB_SBFM_32M_bitfield
    // Template: SXTB  <Wd>, <Wn>
    struct SxtbSbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b000111 (0x7)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    SxtbSbfm32mBitfield sxtb_sbfm32m_bitfield;

    // SBFM: Signed extend byte
    // Encoding: SXTB_SBFM_64M_bitfield
    // Template: SXTB  <Xd>, <Wn>
    struct SxtbSbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b000111 (0x7)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SxtbSbfm64mBitfield sxtb_sbfm64m_bitfield;

    // SBFM: Sign extend halfword
    // Encoding: SXTH_SBFM_32M_bitfield
    // Template: SXTH  <Wd>, <Wn>
    struct SxthSbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b001111 (0xF)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    SxthSbfm32mBitfield sxth_sbfm32m_bitfield;

    // SBFM: Sign extend halfword
    // Encoding: SXTH_SBFM_64M_bitfield
    // Template: SXTH  <Xd>, <Wn>
    struct SxthSbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b001111 (0xF)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SxthSbfm64mBitfield sxth_sbfm64m_bitfield;

    // SBFM: Sign extend word
    // Encoding: SXTW_SBFM_64M_bitfield
    // Template: SXTW  <Xd>, <Wn>
    struct SxtwSbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b011111 (0x1F)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SxtwSbfm64mBitfield sxtw_sbfm64m_bitfield;

    // ANDS: Test bits (immediate)
    // Encoding: TST_ANDS_32S_log_imm
    // Template: TST  <Wn>, #<imm>
    struct TstAnds32sLogImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    TstAnds32sLogImm tst_ands32s_log_imm;

    // ANDS: Test bits (immediate)
    // Encoding: TST_ANDS_64S_log_imm
    // Template: TST  <Xn>, #<imm>
    struct TstAnds64sLogImm {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;
        uint32_t _unnamed_0 : 6;  // fixed: 0b100100 (0x24)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    TstAnds64sLogImm tst_ands64s_log_imm;

    // UBFM: Unsigned bitfield insert in zeros
    // Encoding: UBFIZ_UBFM_32M_bitfield
    // Template: UBFIZ  <Wd>, <Wn>, #<lsb>, #<width>
    struct UbfizUbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    UbfizUbfm32mBitfield ubfiz_ubfm32m_bitfield;

    // UBFM: Unsigned bitfield insert in zeros
    // Encoding: UBFIZ_UBFM_64M_bitfield
    // Template: UBFIZ  <Xd>, <Xn>, #<lsb>, #<width>
    struct UbfizUbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    UbfizUbfm64mBitfield ubfiz_ubfm64m_bitfield;

    // UBFM: Unsigned bitfield move
    // Encoding: UBFM_32M_bitfield
    // Template: UBFM  <Wd>, <Wn>, #<immr>, #<imms>
    struct Ubfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ubfm32mBitfield ubfm32m_bitfield;

    // UBFM: Unsigned bitfield move
    // Encoding: UBFM_64M_bitfield
    // Template: UBFM  <Xd>, <Xn>, #<immr>, #<imms>
    struct Ubfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ubfm64mBitfield ubfm64m_bitfield;

    // UBFM: Unsigned bitfield extract
    // Encoding: UBFX_UBFM_32M_bitfield
    // Template: UBFX  <Wd>, <Wn>, #<lsb>, #<width>
    struct UbfxUbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    UbfxUbfm32mBitfield ubfx_ubfm32m_bitfield;

    // UBFM: Unsigned bitfield extract
    // Encoding: UBFX_UBFM_64M_bitfield
    // Template: UBFX  <Xd>, <Xn>, #<lsb>, #<width>
    struct UbfxUbfm64mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;
        uint32_t immr : 6;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b100110 (0x26)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    UbfxUbfm64mBitfield ubfx_ubfm64m_bitfield;

    // UMAX: Unsigned maximum (immediate)
    // Encoding: UMAX_32U_minmax_imm
    // Template: UMAX  <Wd>, <Wn>, #<uimm>
    struct Umax32uMinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Umax32uMinmaxImm umax32u_minmax_imm;

    // UMAX: Unsigned maximum (immediate)
    // Encoding: UMAX_64U_minmax_imm
    // Template: UMAX  <Xd>, <Xn>, #<uimm>
    struct Umax64uMinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umax64uMinmaxImm umax64u_minmax_imm;

    // UMIN: Unsigned minimum (immediate)
    // Encoding: UMIN_32U_minmax_imm
    // Template: UMIN  <Wd>, <Wn>, #<uimm>
    struct Umin32uMinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Umin32uMinmaxImm umin32u_minmax_imm;

    // UMIN: Unsigned minimum (immediate)
    // Encoding: UMIN_64U_minmax_imm
    // Template: UMIN  <Xd>, <Xn>, #<uimm>
    struct Umin64uMinmaxImm {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm8 : 8;
        uint32_t opc : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1000111 (0x47)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umin64uMinmaxImm umin64u_minmax_imm;

    // UBFM: Unsigned extend byte
    // Encoding: UXTB_UBFM_32M_bitfield
    // Template: UXTB  <Wd>, <Wn>
    struct UxtbUbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b000111 (0x7)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    UxtbUbfm32mBitfield uxtb_ubfm32m_bitfield;

    // UBFM: Unsigned extend halfword
    // Encoding: UXTH_UBFM_32M_bitfield
    // Template: UXTH  <Wd>, <Wn>
    struct UxthUbfm32mBitfield {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imms : 6;  // fixed: 0b001111 (0xF)
        uint32_t immr : 6;  // fixed: 0b000000 (0x0)
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 3;  // fixed: 0b100 (0x4)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    UxthUbfm32mBitfield uxth_ubfm32m_bitfield;

};
static_assert(sizeof(DpimmEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_add_32_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.add32addsub_imm.Rd = Rd;
    insn.add32addsub_imm.Rn = Rn;
    insn.add32addsub_imm.imm12 = imm12;
    insn.add32addsub_imm.sh = sh;
    insn.add32addsub_imm._unnamed_0 = 0b100010;
    insn.add32addsub_imm.S = 0b0;
    insn.add32addsub_imm.op = 0b0;
    insn.add32addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_add_64_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.add64addsub_imm.Rd = Rd;
    insn.add64addsub_imm.Rn = Rn;
    insn.add64addsub_imm.imm12 = imm12;
    insn.add64addsub_imm.sh = sh;
    insn.add64addsub_imm._unnamed_0 = 0b100010;
    insn.add64addsub_imm.S = 0b0;
    insn.add64addsub_imm.op = 0b0;
    insn.add64addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_addg_64_addsub_immtags(uint32_t Rd, uint32_t Rn, uint32_t imm4, uint32_t op3, uint32_t imm6) {
    DpimmEncoding insn = {};
    insn.addg64addsub_immtags.Rd = Rd;
    insn.addg64addsub_immtags.Rn = Rn;
    insn.addg64addsub_immtags.imm4 = imm4;
    insn.addg64addsub_immtags.op3 = op3;
    insn.addg64addsub_immtags.imm6 = imm6;
    insn.addg64addsub_immtags._unnamed_1 = 0b0110;
    insn.addg64addsub_immtags._unnamed_0 = 0b100;
    insn.addg64addsub_immtags.S = 0b0;
    insn.addg64addsub_immtags.op = 0b0;
    insn.addg64addsub_immtags.sf = 0b1;
    return insn.raw;
}

uint32_t encode_adds_32s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.adds32s_addsub_imm.Rd = Rd;
    insn.adds32s_addsub_imm.Rn = Rn;
    insn.adds32s_addsub_imm.imm12 = imm12;
    insn.adds32s_addsub_imm.sh = sh;
    insn.adds32s_addsub_imm._unnamed_0 = 0b100010;
    insn.adds32s_addsub_imm.S = 0b1;
    insn.adds32s_addsub_imm.op = 0b0;
    insn.adds32s_addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_adds_64s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.adds64s_addsub_imm.Rd = Rd;
    insn.adds64s_addsub_imm.Rn = Rn;
    insn.adds64s_addsub_imm.imm12 = imm12;
    insn.adds64s_addsub_imm.sh = sh;
    insn.adds64s_addsub_imm._unnamed_0 = 0b100010;
    insn.adds64s_addsub_imm.S = 0b1;
    insn.adds64s_addsub_imm.op = 0b0;
    insn.adds64s_addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_adr_only_pcreladdr(uint32_t Rd, int32_t immhi, int32_t immlo) {
    DpimmEncoding insn = {};
    insn.adr_only_pcreladdr.Rd = Rd;
    insn.adr_only_pcreladdr.immhi = immhi;
    insn.adr_only_pcreladdr._unnamed_1 = 0b00;
    insn.adr_only_pcreladdr._unnamed_0 = 0b100;
    insn.adr_only_pcreladdr.immlo = immlo;
    insn.adr_only_pcreladdr.op = 0b0;
    return insn.raw;
}

uint32_t encode_adrp_only_pcreladdr(uint32_t Rd, int32_t immhi, int32_t immlo) {
    DpimmEncoding insn = {};
    insn.adrp_only_pcreladdr.Rd = Rd;
    insn.adrp_only_pcreladdr.immhi = immhi;
    insn.adrp_only_pcreladdr._unnamed_1 = 0b00;
    insn.adrp_only_pcreladdr._unnamed_0 = 0b100;
    insn.adrp_only_pcreladdr.immlo = immlo;
    insn.adrp_only_pcreladdr.op = 0b1;
    return insn.raw;
}

uint32_t encode_and_32_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.and32log_imm.Rd = Rd;
    insn.and32log_imm.Rn = Rn;
    insn.and32log_imm.imms = imms;
    insn.and32log_imm.immr = immr;
    insn.and32log_imm.N = 0b0;
    insn.and32log_imm._unnamed_0 = 0b100100;
    insn.and32log_imm.opc = 0b00;
    insn.and32log_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_and_64_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N) {
    DpimmEncoding insn = {};
    insn.and64log_imm.Rd = Rd;
    insn.and64log_imm.Rn = Rn;
    insn.and64log_imm.imms = imms;
    insn.and64log_imm.immr = immr;
    insn.and64log_imm.N = N;
    insn.and64log_imm._unnamed_0 = 0b100100;
    insn.and64log_imm.opc = 0b00;
    insn.and64log_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ands_32s_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ands32s_log_imm.Rd = Rd;
    insn.ands32s_log_imm.Rn = Rn;
    insn.ands32s_log_imm.imms = imms;
    insn.ands32s_log_imm.immr = immr;
    insn.ands32s_log_imm.N = 0b0;
    insn.ands32s_log_imm._unnamed_0 = 0b100100;
    insn.ands32s_log_imm.opc = 0b11;
    insn.ands32s_log_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ands_64s_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N) {
    DpimmEncoding insn = {};
    insn.ands64s_log_imm.Rd = Rd;
    insn.ands64s_log_imm.Rn = Rn;
    insn.ands64s_log_imm.imms = imms;
    insn.ands64s_log_imm.immr = immr;
    insn.ands64s_log_imm.N = N;
    insn.ands64s_log_imm._unnamed_0 = 0b100100;
    insn.ands64s_log_imm.opc = 0b11;
    insn.ands64s_log_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_asr_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.asr_sbfm32m_bitfield.Rd = Rd;
    insn.asr_sbfm32m_bitfield.Rn = Rn;
    insn.asr_sbfm32m_bitfield.imms = 0b011111;
    insn.asr_sbfm32m_bitfield.immr = immr;
    insn.asr_sbfm32m_bitfield.N = 0b0;
    insn.asr_sbfm32m_bitfield._unnamed_0 = 0b100110;
    insn.asr_sbfm32m_bitfield.opc = 0b00;
    insn.asr_sbfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_asr_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.asr_sbfm64m_bitfield.Rd = Rd;
    insn.asr_sbfm64m_bitfield.Rn = Rn;
    insn.asr_sbfm64m_bitfield.imms = 0b111111;
    insn.asr_sbfm64m_bitfield.immr = immr;
    insn.asr_sbfm64m_bitfield.N = 0b1;
    insn.asr_sbfm64m_bitfield._unnamed_0 = 0b100110;
    insn.asr_sbfm64m_bitfield.opc = 0b00;
    insn.asr_sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autiasppc_only_dp_1src_imm(uint32_t imm16) {
    DpimmEncoding insn = {};
    insn.autiasppc_only_dp1src_imm.Rd = 0b11111;
    insn.autiasppc_only_dp1src_imm.imm16 = imm16;
    insn.autiasppc_only_dp1src_imm.opc = 0b00;
    insn.autiasppc_only_dp1src_imm._unnamed_2 = 0b111;
    insn.autiasppc_only_dp1src_imm._unnamed_1 = 0b100;
    insn.autiasppc_only_dp1src_imm._unnamed_0 = 0b11;
    insn.autiasppc_only_dp1src_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autibsppc_only_dp_1src_imm(uint32_t imm16) {
    DpimmEncoding insn = {};
    insn.autibsppc_only_dp1src_imm.Rd = 0b11111;
    insn.autibsppc_only_dp1src_imm.imm16 = imm16;
    insn.autibsppc_only_dp1src_imm.opc = 0b01;
    insn.autibsppc_only_dp1src_imm._unnamed_2 = 0b111;
    insn.autibsppc_only_dp1src_imm._unnamed_1 = 0b100;
    insn.autibsppc_only_dp1src_imm._unnamed_0 = 0b11;
    insn.autibsppc_only_dp1src_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_bfc_bfm_32m_bitfield(uint32_t Rd, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfc_bfm32m_bitfield.Rd = Rd;
    insn.bfc_bfm32m_bitfield.Rn = 0b11111;
    insn.bfc_bfm32m_bitfield.imms = imms;
    insn.bfc_bfm32m_bitfield.immr = immr;
    insn.bfc_bfm32m_bitfield.N = 0b0;
    insn.bfc_bfm32m_bitfield._unnamed_0 = 0b100110;
    insn.bfc_bfm32m_bitfield.opc = 0b01;
    insn.bfc_bfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_bfc_bfm_64m_bitfield(uint32_t Rd, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfc_bfm64m_bitfield.Rd = Rd;
    insn.bfc_bfm64m_bitfield.Rn = 0b11111;
    insn.bfc_bfm64m_bitfield.imms = imms;
    insn.bfc_bfm64m_bitfield.immr = immr;
    insn.bfc_bfm64m_bitfield.N = 0b1;
    insn.bfc_bfm64m_bitfield._unnamed_0 = 0b100110;
    insn.bfc_bfm64m_bitfield.opc = 0b01;
    insn.bfc_bfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_bfi_bfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfi_bfm32m_bitfield.Rd = Rd;
    insn.bfi_bfm32m_bitfield.Rn = Rn;
    insn.bfi_bfm32m_bitfield.imms = imms;
    insn.bfi_bfm32m_bitfield.immr = immr;
    insn.bfi_bfm32m_bitfield.N = 0b0;
    insn.bfi_bfm32m_bitfield._unnamed_0 = 0b100110;
    insn.bfi_bfm32m_bitfield.opc = 0b01;
    insn.bfi_bfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_bfi_bfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfi_bfm64m_bitfield.Rd = Rd;
    insn.bfi_bfm64m_bitfield.Rn = Rn;
    insn.bfi_bfm64m_bitfield.imms = imms;
    insn.bfi_bfm64m_bitfield.immr = immr;
    insn.bfi_bfm64m_bitfield.N = 0b1;
    insn.bfi_bfm64m_bitfield._unnamed_0 = 0b100110;
    insn.bfi_bfm64m_bitfield.opc = 0b01;
    insn.bfi_bfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_bfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfm32m_bitfield.Rd = Rd;
    insn.bfm32m_bitfield.Rn = Rn;
    insn.bfm32m_bitfield.imms = imms;
    insn.bfm32m_bitfield.immr = immr;
    insn.bfm32m_bitfield.N = 0b0;
    insn.bfm32m_bitfield._unnamed_0 = 0b100110;
    insn.bfm32m_bitfield.opc = 0b01;
    insn.bfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_bfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfm64m_bitfield.Rd = Rd;
    insn.bfm64m_bitfield.Rn = Rn;
    insn.bfm64m_bitfield.imms = imms;
    insn.bfm64m_bitfield.immr = immr;
    insn.bfm64m_bitfield.N = 0b1;
    insn.bfm64m_bitfield._unnamed_0 = 0b100110;
    insn.bfm64m_bitfield.opc = 0b01;
    insn.bfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_bfxil_bfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfxil_bfm32m_bitfield.Rd = Rd;
    insn.bfxil_bfm32m_bitfield.Rn = Rn;
    insn.bfxil_bfm32m_bitfield.imms = imms;
    insn.bfxil_bfm32m_bitfield.immr = immr;
    insn.bfxil_bfm32m_bitfield.N = 0b0;
    insn.bfxil_bfm32m_bitfield._unnamed_0 = 0b100110;
    insn.bfxil_bfm32m_bitfield.opc = 0b01;
    insn.bfxil_bfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_bfxil_bfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.bfxil_bfm64m_bitfield.Rd = Rd;
    insn.bfxil_bfm64m_bitfield.Rn = Rn;
    insn.bfxil_bfm64m_bitfield.imms = imms;
    insn.bfxil_bfm64m_bitfield.immr = immr;
    insn.bfxil_bfm64m_bitfield.N = 0b1;
    insn.bfxil_bfm64m_bitfield._unnamed_0 = 0b100110;
    insn.bfxil_bfm64m_bitfield.opc = 0b01;
    insn.bfxil_bfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmn_adds_32s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.cmn_adds32s_addsub_imm.Rd = 0b11111;
    insn.cmn_adds32s_addsub_imm.Rn = Rn;
    insn.cmn_adds32s_addsub_imm.imm12 = imm12;
    insn.cmn_adds32s_addsub_imm.sh = sh;
    insn.cmn_adds32s_addsub_imm._unnamed_0 = 0b100010;
    insn.cmn_adds32s_addsub_imm.S = 0b1;
    insn.cmn_adds32s_addsub_imm.op = 0b0;
    insn.cmn_adds32s_addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cmn_adds_64s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.cmn_adds64s_addsub_imm.Rd = 0b11111;
    insn.cmn_adds64s_addsub_imm.Rn = Rn;
    insn.cmn_adds64s_addsub_imm.imm12 = imm12;
    insn.cmn_adds64s_addsub_imm.sh = sh;
    insn.cmn_adds64s_addsub_imm._unnamed_0 = 0b100010;
    insn.cmn_adds64s_addsub_imm.S = 0b1;
    insn.cmn_adds64s_addsub_imm.op = 0b0;
    insn.cmn_adds64s_addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmp_subs_32s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.cmp_subs32s_addsub_imm.Rd = 0b11111;
    insn.cmp_subs32s_addsub_imm.Rn = Rn;
    insn.cmp_subs32s_addsub_imm.imm12 = imm12;
    insn.cmp_subs32s_addsub_imm.sh = sh;
    insn.cmp_subs32s_addsub_imm._unnamed_0 = 0b100010;
    insn.cmp_subs32s_addsub_imm.S = 0b1;
    insn.cmp_subs32s_addsub_imm.op = 0b1;
    insn.cmp_subs32s_addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cmp_subs_64s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.cmp_subs64s_addsub_imm.Rd = 0b11111;
    insn.cmp_subs64s_addsub_imm.Rn = Rn;
    insn.cmp_subs64s_addsub_imm.imm12 = imm12;
    insn.cmp_subs64s_addsub_imm.sh = sh;
    insn.cmp_subs64s_addsub_imm._unnamed_0 = 0b100010;
    insn.cmp_subs64s_addsub_imm.S = 0b1;
    insn.cmp_subs64s_addsub_imm.op = 0b1;
    insn.cmp_subs64s_addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_eor_32_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.eor32log_imm.Rd = Rd;
    insn.eor32log_imm.Rn = Rn;
    insn.eor32log_imm.imms = imms;
    insn.eor32log_imm.immr = immr;
    insn.eor32log_imm.N = 0b0;
    insn.eor32log_imm._unnamed_0 = 0b100100;
    insn.eor32log_imm.opc = 0b10;
    insn.eor32log_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_eor_64_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N) {
    DpimmEncoding insn = {};
    insn.eor64log_imm.Rd = Rd;
    insn.eor64log_imm.Rn = Rn;
    insn.eor64log_imm.imms = imms;
    insn.eor64log_imm.immr = immr;
    insn.eor64log_imm.N = N;
    insn.eor64log_imm._unnamed_0 = 0b100100;
    insn.eor64log_imm.opc = 0b10;
    insn.eor64log_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_extr_32_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm) {
    DpimmEncoding insn = {};
    insn.extr32extract.Rd = Rd;
    insn.extr32extract.Rn = Rn;
    insn.extr32extract.imms = imms;
    insn.extr32extract.Rm = Rm;
    insn.extr32extract.o0 = 0b0;
    insn.extr32extract.N = 0b0;
    insn.extr32extract._unnamed_0 = 0b100111;
    insn.extr32extract.op21 = 0b00;
    insn.extr32extract.sf = 0b0;
    return insn.raw;
}

uint32_t encode_extr_64_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm) {
    DpimmEncoding insn = {};
    insn.extr64extract.Rd = Rd;
    insn.extr64extract.Rn = Rn;
    insn.extr64extract.imms = imms;
    insn.extr64extract.Rm = Rm;
    insn.extr64extract.o0 = 0b0;
    insn.extr64extract.N = 0b1;
    insn.extr64extract._unnamed_0 = 0b100111;
    insn.extr64extract.op21 = 0b00;
    insn.extr64extract.sf = 0b1;
    return insn.raw;
}

uint32_t encode_lsl_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.lsl_ubfm32m_bitfield.Rd = Rd;
    insn.lsl_ubfm32m_bitfield.Rn = Rn;
    insn.lsl_ubfm32m_bitfield.imms = imms;
    insn.lsl_ubfm32m_bitfield.immr = immr;
    insn.lsl_ubfm32m_bitfield.N = 0b0;
    insn.lsl_ubfm32m_bitfield._unnamed_0 = 0b100110;
    insn.lsl_ubfm32m_bitfield.opc = 0b10;
    insn.lsl_ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_lsl_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.lsl_ubfm64m_bitfield.Rd = Rd;
    insn.lsl_ubfm64m_bitfield.Rn = Rn;
    insn.lsl_ubfm64m_bitfield.imms = imms;
    insn.lsl_ubfm64m_bitfield.immr = immr;
    insn.lsl_ubfm64m_bitfield.N = 0b1;
    insn.lsl_ubfm64m_bitfield._unnamed_0 = 0b100110;
    insn.lsl_ubfm64m_bitfield.opc = 0b10;
    insn.lsl_ubfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_lsr_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.lsr_ubfm32m_bitfield.Rd = Rd;
    insn.lsr_ubfm32m_bitfield.Rn = Rn;
    insn.lsr_ubfm32m_bitfield.imms = 0b011111;
    insn.lsr_ubfm32m_bitfield.immr = immr;
    insn.lsr_ubfm32m_bitfield.N = 0b0;
    insn.lsr_ubfm32m_bitfield._unnamed_0 = 0b100110;
    insn.lsr_ubfm32m_bitfield.opc = 0b10;
    insn.lsr_ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_lsr_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.lsr_ubfm64m_bitfield.Rd = Rd;
    insn.lsr_ubfm64m_bitfield.Rn = Rn;
    insn.lsr_ubfm64m_bitfield.imms = 0b111111;
    insn.lsr_ubfm64m_bitfield.immr = immr;
    insn.lsr_ubfm64m_bitfield.N = 0b1;
    insn.lsr_ubfm64m_bitfield._unnamed_0 = 0b100110;
    insn.lsr_ubfm64m_bitfield.opc = 0b10;
    insn.lsr_ubfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mov_add_32_addsub_imm(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.mov_add32addsub_imm.Rd = Rd;
    insn.mov_add32addsub_imm.Rn = Rn;
    insn.mov_add32addsub_imm.imm12 = 0b000000000000;
    insn.mov_add32addsub_imm.sh = 0b0;
    insn.mov_add32addsub_imm._unnamed_0 = 0b100010;
    insn.mov_add32addsub_imm.S = 0b0;
    insn.mov_add32addsub_imm.op = 0b0;
    insn.mov_add32addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mov_add_64_addsub_imm(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.mov_add64addsub_imm.Rd = Rd;
    insn.mov_add64addsub_imm.Rn = Rn;
    insn.mov_add64addsub_imm.imm12 = 0b000000000000;
    insn.mov_add64addsub_imm.sh = 0b0;
    insn.mov_add64addsub_imm._unnamed_0 = 0b100010;
    insn.mov_add64addsub_imm.S = 0b0;
    insn.mov_add64addsub_imm.op = 0b0;
    insn.mov_add64addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mov_movn_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.mov_movn32movewide.Rd = Rd;
    insn.mov_movn32movewide.imm16 = imm16;
    insn.mov_movn32movewide.hw = hw;
    insn.mov_movn32movewide._unnamed_0 = 0b100101;
    insn.mov_movn32movewide.opc = 0b00;
    insn.mov_movn32movewide.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mov_movn_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.mov_movn64movewide.Rd = Rd;
    insn.mov_movn64movewide.imm16 = imm16;
    insn.mov_movn64movewide.hw = hw;
    insn.mov_movn64movewide._unnamed_0 = 0b100101;
    insn.mov_movn64movewide.opc = 0b00;
    insn.mov_movn64movewide.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mov_movz_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.mov_movz32movewide.Rd = Rd;
    insn.mov_movz32movewide.imm16 = imm16;
    insn.mov_movz32movewide.hw = hw;
    insn.mov_movz32movewide._unnamed_0 = 0b100101;
    insn.mov_movz32movewide.opc = 0b10;
    insn.mov_movz32movewide.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mov_movz_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.mov_movz64movewide.Rd = Rd;
    insn.mov_movz64movewide.imm16 = imm16;
    insn.mov_movz64movewide.hw = hw;
    insn.mov_movz64movewide._unnamed_0 = 0b100101;
    insn.mov_movz64movewide.opc = 0b10;
    insn.mov_movz64movewide.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mov_orr_32_log_imm(uint32_t Rd, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.mov_orr32log_imm.Rd = Rd;
    insn.mov_orr32log_imm.Rn = 0b11111;
    insn.mov_orr32log_imm.imms = imms;
    insn.mov_orr32log_imm.immr = immr;
    insn.mov_orr32log_imm.N = 0b0;
    insn.mov_orr32log_imm._unnamed_0 = 0b100100;
    insn.mov_orr32log_imm.opc = 0b01;
    insn.mov_orr32log_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mov_orr_64_log_imm(uint32_t Rd, uint32_t imms, uint32_t immr, uint32_t N) {
    DpimmEncoding insn = {};
    insn.mov_orr64log_imm.Rd = Rd;
    insn.mov_orr64log_imm.Rn = 0b11111;
    insn.mov_orr64log_imm.imms = imms;
    insn.mov_orr64log_imm.immr = immr;
    insn.mov_orr64log_imm.N = N;
    insn.mov_orr64log_imm._unnamed_0 = 0b100100;
    insn.mov_orr64log_imm.opc = 0b01;
    insn.mov_orr64log_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_movk_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.movk32movewide.Rd = Rd;
    insn.movk32movewide.imm16 = imm16;
    insn.movk32movewide.hw = hw;
    insn.movk32movewide._unnamed_0 = 0b100101;
    insn.movk32movewide.opc = 0b11;
    insn.movk32movewide.sf = 0b0;
    return insn.raw;
}

uint32_t encode_movk_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.movk64movewide.Rd = Rd;
    insn.movk64movewide.imm16 = imm16;
    insn.movk64movewide.hw = hw;
    insn.movk64movewide._unnamed_0 = 0b100101;
    insn.movk64movewide.opc = 0b11;
    insn.movk64movewide.sf = 0b1;
    return insn.raw;
}

uint32_t encode_movn_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.movn32movewide.Rd = Rd;
    insn.movn32movewide.imm16 = imm16;
    insn.movn32movewide.hw = hw;
    insn.movn32movewide._unnamed_0 = 0b100101;
    insn.movn32movewide.opc = 0b00;
    insn.movn32movewide.sf = 0b0;
    return insn.raw;
}

uint32_t encode_movn_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.movn64movewide.Rd = Rd;
    insn.movn64movewide.imm16 = imm16;
    insn.movn64movewide.hw = hw;
    insn.movn64movewide._unnamed_0 = 0b100101;
    insn.movn64movewide.opc = 0b00;
    insn.movn64movewide.sf = 0b1;
    return insn.raw;
}

uint32_t encode_movz_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.movz32movewide.Rd = Rd;
    insn.movz32movewide.imm16 = imm16;
    insn.movz32movewide.hw = hw;
    insn.movz32movewide._unnamed_0 = 0b100101;
    insn.movz32movewide.opc = 0b10;
    insn.movz32movewide.sf = 0b0;
    return insn.raw;
}

uint32_t encode_movz_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw) {
    DpimmEncoding insn = {};
    insn.movz64movewide.Rd = Rd;
    insn.movz64movewide.imm16 = imm16;
    insn.movz64movewide.hw = hw;
    insn.movz64movewide._unnamed_0 = 0b100101;
    insn.movz64movewide.opc = 0b10;
    insn.movz64movewide.sf = 0b1;
    return insn.raw;
}

uint32_t encode_orr_32_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.orr32log_imm.Rd = Rd;
    insn.orr32log_imm.Rn = Rn;
    insn.orr32log_imm.imms = imms;
    insn.orr32log_imm.immr = immr;
    insn.orr32log_imm.N = 0b0;
    insn.orr32log_imm._unnamed_0 = 0b100100;
    insn.orr32log_imm.opc = 0b01;
    insn.orr32log_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_orr_64_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N) {
    DpimmEncoding insn = {};
    insn.orr64log_imm.Rd = Rd;
    insn.orr64log_imm.Rn = Rn;
    insn.orr64log_imm.imms = imms;
    insn.orr64log_imm.immr = immr;
    insn.orr64log_imm.N = N;
    insn.orr64log_imm._unnamed_0 = 0b100100;
    insn.orr64log_imm.opc = 0b01;
    insn.orr64log_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ror_extr_32_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm) {
    DpimmEncoding insn = {};
    insn.ror_extr32extract.Rd = Rd;
    insn.ror_extr32extract.Rn = Rn;
    insn.ror_extr32extract.imms = imms;
    insn.ror_extr32extract.Rm = Rm;
    insn.ror_extr32extract.o0 = 0b0;
    insn.ror_extr32extract.N = 0b0;
    insn.ror_extr32extract._unnamed_0 = 0b100111;
    insn.ror_extr32extract.op21 = 0b00;
    insn.ror_extr32extract.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ror_extr_64_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm) {
    DpimmEncoding insn = {};
    insn.ror_extr64extract.Rd = Rd;
    insn.ror_extr64extract.Rn = Rn;
    insn.ror_extr64extract.imms = imms;
    insn.ror_extr64extract.Rm = Rm;
    insn.ror_extr64extract.o0 = 0b0;
    insn.ror_extr64extract.N = 0b1;
    insn.ror_extr64extract._unnamed_0 = 0b100111;
    insn.ror_extr64extract.op21 = 0b00;
    insn.ror_extr64extract.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sbfiz_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.sbfiz_sbfm32m_bitfield.Rd = Rd;
    insn.sbfiz_sbfm32m_bitfield.Rn = Rn;
    insn.sbfiz_sbfm32m_bitfield.imms = imms;
    insn.sbfiz_sbfm32m_bitfield.immr = immr;
    insn.sbfiz_sbfm32m_bitfield.N = 0b0;
    insn.sbfiz_sbfm32m_bitfield._unnamed_0 = 0b100110;
    insn.sbfiz_sbfm32m_bitfield.opc = 0b00;
    insn.sbfiz_sbfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sbfiz_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.sbfiz_sbfm64m_bitfield.Rd = Rd;
    insn.sbfiz_sbfm64m_bitfield.Rn = Rn;
    insn.sbfiz_sbfm64m_bitfield.imms = imms;
    insn.sbfiz_sbfm64m_bitfield.immr = immr;
    insn.sbfiz_sbfm64m_bitfield.N = 0b1;
    insn.sbfiz_sbfm64m_bitfield._unnamed_0 = 0b100110;
    insn.sbfiz_sbfm64m_bitfield.opc = 0b00;
    insn.sbfiz_sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.sbfm32m_bitfield.Rd = Rd;
    insn.sbfm32m_bitfield.Rn = Rn;
    insn.sbfm32m_bitfield.imms = imms;
    insn.sbfm32m_bitfield.immr = immr;
    insn.sbfm32m_bitfield.N = 0b0;
    insn.sbfm32m_bitfield._unnamed_0 = 0b100110;
    insn.sbfm32m_bitfield.opc = 0b00;
    insn.sbfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.sbfm64m_bitfield.Rd = Rd;
    insn.sbfm64m_bitfield.Rn = Rn;
    insn.sbfm64m_bitfield.imms = imms;
    insn.sbfm64m_bitfield.immr = immr;
    insn.sbfm64m_bitfield.N = 0b1;
    insn.sbfm64m_bitfield._unnamed_0 = 0b100110;
    insn.sbfm64m_bitfield.opc = 0b00;
    insn.sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sbfx_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.sbfx_sbfm32m_bitfield.Rd = Rd;
    insn.sbfx_sbfm32m_bitfield.Rn = Rn;
    insn.sbfx_sbfm32m_bitfield.imms = imms;
    insn.sbfx_sbfm32m_bitfield.immr = immr;
    insn.sbfx_sbfm32m_bitfield.N = 0b0;
    insn.sbfx_sbfm32m_bitfield._unnamed_0 = 0b100110;
    insn.sbfx_sbfm32m_bitfield.opc = 0b00;
    insn.sbfx_sbfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sbfx_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.sbfx_sbfm64m_bitfield.Rd = Rd;
    insn.sbfx_sbfm64m_bitfield.Rn = Rn;
    insn.sbfx_sbfm64m_bitfield.imms = imms;
    insn.sbfx_sbfm64m_bitfield.immr = immr;
    insn.sbfx_sbfm64m_bitfield.N = 0b1;
    insn.sbfx_sbfm64m_bitfield._unnamed_0 = 0b100110;
    insn.sbfx_sbfm64m_bitfield.opc = 0b00;
    insn.sbfx_sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smax_32_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.smax32minmax_imm.Rd = Rd;
    insn.smax32minmax_imm.Rn = Rn;
    insn.smax32minmax_imm.imm8 = imm8;
    insn.smax32minmax_imm.opc = 0b0000;
    insn.smax32minmax_imm._unnamed_0 = 0b1000111;
    insn.smax32minmax_imm.S = 0b0;
    insn.smax32minmax_imm.op = 0b0;
    insn.smax32minmax_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_smax_64_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.smax64minmax_imm.Rd = Rd;
    insn.smax64minmax_imm.Rn = Rn;
    insn.smax64minmax_imm.imm8 = imm8;
    insn.smax64minmax_imm.opc = 0b0000;
    insn.smax64minmax_imm._unnamed_0 = 0b1000111;
    insn.smax64minmax_imm.S = 0b0;
    insn.smax64minmax_imm.op = 0b0;
    insn.smax64minmax_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smin_32_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.smin32minmax_imm.Rd = Rd;
    insn.smin32minmax_imm.Rn = Rn;
    insn.smin32minmax_imm.imm8 = imm8;
    insn.smin32minmax_imm.opc = 0b0010;
    insn.smin32minmax_imm._unnamed_0 = 0b1000111;
    insn.smin32minmax_imm.S = 0b0;
    insn.smin32minmax_imm.op = 0b0;
    insn.smin32minmax_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_smin_64_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.smin64minmax_imm.Rd = Rd;
    insn.smin64minmax_imm.Rn = Rn;
    insn.smin64minmax_imm.imm8 = imm8;
    insn.smin64minmax_imm.opc = 0b0010;
    insn.smin64minmax_imm._unnamed_0 = 0b1000111;
    insn.smin64minmax_imm.S = 0b0;
    insn.smin64minmax_imm.op = 0b0;
    insn.smin64minmax_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sub_32_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.sub32addsub_imm.Rd = Rd;
    insn.sub32addsub_imm.Rn = Rn;
    insn.sub32addsub_imm.imm12 = imm12;
    insn.sub32addsub_imm.sh = sh;
    insn.sub32addsub_imm._unnamed_0 = 0b100010;
    insn.sub32addsub_imm.S = 0b0;
    insn.sub32addsub_imm.op = 0b1;
    insn.sub32addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sub_64_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.sub64addsub_imm.Rd = Rd;
    insn.sub64addsub_imm.Rn = Rn;
    insn.sub64addsub_imm.imm12 = imm12;
    insn.sub64addsub_imm.sh = sh;
    insn.sub64addsub_imm._unnamed_0 = 0b100010;
    insn.sub64addsub_imm.S = 0b0;
    insn.sub64addsub_imm.op = 0b1;
    insn.sub64addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subg_64_addsub_immtags(uint32_t Rd, uint32_t Rn, uint32_t imm4, uint32_t op3, uint32_t imm6) {
    DpimmEncoding insn = {};
    insn.subg64addsub_immtags.Rd = Rd;
    insn.subg64addsub_immtags.Rn = Rn;
    insn.subg64addsub_immtags.imm4 = imm4;
    insn.subg64addsub_immtags.op3 = op3;
    insn.subg64addsub_immtags.imm6 = imm6;
    insn.subg64addsub_immtags._unnamed_1 = 0b0110;
    insn.subg64addsub_immtags._unnamed_0 = 0b100;
    insn.subg64addsub_immtags.S = 0b0;
    insn.subg64addsub_immtags.op = 0b1;
    insn.subg64addsub_immtags.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subs_32s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.subs32s_addsub_imm.Rd = Rd;
    insn.subs32s_addsub_imm.Rn = Rn;
    insn.subs32s_addsub_imm.imm12 = imm12;
    insn.subs32s_addsub_imm.sh = sh;
    insn.subs32s_addsub_imm._unnamed_0 = 0b100010;
    insn.subs32s_addsub_imm.S = 0b1;
    insn.subs32s_addsub_imm.op = 0b1;
    insn.subs32s_addsub_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_subs_64s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh) {
    DpimmEncoding insn = {};
    insn.subs64s_addsub_imm.Rd = Rd;
    insn.subs64s_addsub_imm.Rn = Rn;
    insn.subs64s_addsub_imm.imm12 = imm12;
    insn.subs64s_addsub_imm.sh = sh;
    insn.subs64s_addsub_imm._unnamed_0 = 0b100010;
    insn.subs64s_addsub_imm.S = 0b1;
    insn.subs64s_addsub_imm.op = 0b1;
    insn.subs64s_addsub_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sxtb_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.sxtb_sbfm32m_bitfield.Rd = Rd;
    insn.sxtb_sbfm32m_bitfield.Rn = Rn;
    insn.sxtb_sbfm32m_bitfield.imms = 0b000111;
    insn.sxtb_sbfm32m_bitfield.immr = 0b000000;
    insn.sxtb_sbfm32m_bitfield.N = 0b0;
    insn.sxtb_sbfm32m_bitfield._unnamed_0 = 0b100110;
    insn.sxtb_sbfm32m_bitfield.opc = 0b00;
    insn.sxtb_sbfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sxtb_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.sxtb_sbfm64m_bitfield.Rd = Rd;
    insn.sxtb_sbfm64m_bitfield.Rn = Rn;
    insn.sxtb_sbfm64m_bitfield.imms = 0b000111;
    insn.sxtb_sbfm64m_bitfield.immr = 0b000000;
    insn.sxtb_sbfm64m_bitfield.N = 0b1;
    insn.sxtb_sbfm64m_bitfield._unnamed_0 = 0b100110;
    insn.sxtb_sbfm64m_bitfield.opc = 0b00;
    insn.sxtb_sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sxth_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.sxth_sbfm32m_bitfield.Rd = Rd;
    insn.sxth_sbfm32m_bitfield.Rn = Rn;
    insn.sxth_sbfm32m_bitfield.imms = 0b001111;
    insn.sxth_sbfm32m_bitfield.immr = 0b000000;
    insn.sxth_sbfm32m_bitfield.N = 0b0;
    insn.sxth_sbfm32m_bitfield._unnamed_0 = 0b100110;
    insn.sxth_sbfm32m_bitfield.opc = 0b00;
    insn.sxth_sbfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sxth_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.sxth_sbfm64m_bitfield.Rd = Rd;
    insn.sxth_sbfm64m_bitfield.Rn = Rn;
    insn.sxth_sbfm64m_bitfield.imms = 0b001111;
    insn.sxth_sbfm64m_bitfield.immr = 0b000000;
    insn.sxth_sbfm64m_bitfield.N = 0b1;
    insn.sxth_sbfm64m_bitfield._unnamed_0 = 0b100110;
    insn.sxth_sbfm64m_bitfield.opc = 0b00;
    insn.sxth_sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sxtw_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.sxtw_sbfm64m_bitfield.Rd = Rd;
    insn.sxtw_sbfm64m_bitfield.Rn = Rn;
    insn.sxtw_sbfm64m_bitfield.imms = 0b011111;
    insn.sxtw_sbfm64m_bitfield.immr = 0b000000;
    insn.sxtw_sbfm64m_bitfield.N = 0b1;
    insn.sxtw_sbfm64m_bitfield._unnamed_1 = 0b110;
    insn.sxtw_sbfm64m_bitfield._unnamed_0 = 0b100;
    insn.sxtw_sbfm64m_bitfield.opc = 0b00;
    insn.sxtw_sbfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_tst_ands_32s_log_imm(uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.tst_ands32s_log_imm.Rd = 0b11111;
    insn.tst_ands32s_log_imm.Rn = Rn;
    insn.tst_ands32s_log_imm.imms = imms;
    insn.tst_ands32s_log_imm.immr = immr;
    insn.tst_ands32s_log_imm.N = 0b0;
    insn.tst_ands32s_log_imm._unnamed_0 = 0b100100;
    insn.tst_ands32s_log_imm.opc = 0b11;
    insn.tst_ands32s_log_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_tst_ands_64s_log_imm(uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N) {
    DpimmEncoding insn = {};
    insn.tst_ands64s_log_imm.Rd = 0b11111;
    insn.tst_ands64s_log_imm.Rn = Rn;
    insn.tst_ands64s_log_imm.imms = imms;
    insn.tst_ands64s_log_imm.immr = immr;
    insn.tst_ands64s_log_imm.N = N;
    insn.tst_ands64s_log_imm._unnamed_0 = 0b100100;
    insn.tst_ands64s_log_imm.opc = 0b11;
    insn.tst_ands64s_log_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ubfiz_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ubfiz_ubfm32m_bitfield.Rd = Rd;
    insn.ubfiz_ubfm32m_bitfield.Rn = Rn;
    insn.ubfiz_ubfm32m_bitfield.imms = imms;
    insn.ubfiz_ubfm32m_bitfield.immr = immr;
    insn.ubfiz_ubfm32m_bitfield.N = 0b0;
    insn.ubfiz_ubfm32m_bitfield._unnamed_0 = 0b100110;
    insn.ubfiz_ubfm32m_bitfield.opc = 0b10;
    insn.ubfiz_ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ubfiz_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ubfiz_ubfm64m_bitfield.Rd = Rd;
    insn.ubfiz_ubfm64m_bitfield.Rn = Rn;
    insn.ubfiz_ubfm64m_bitfield.imms = imms;
    insn.ubfiz_ubfm64m_bitfield.immr = immr;
    insn.ubfiz_ubfm64m_bitfield.N = 0b1;
    insn.ubfiz_ubfm64m_bitfield._unnamed_0 = 0b100110;
    insn.ubfiz_ubfm64m_bitfield.opc = 0b10;
    insn.ubfiz_ubfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ubfm32m_bitfield.Rd = Rd;
    insn.ubfm32m_bitfield.Rn = Rn;
    insn.ubfm32m_bitfield.imms = imms;
    insn.ubfm32m_bitfield.immr = immr;
    insn.ubfm32m_bitfield.N = 0b0;
    insn.ubfm32m_bitfield._unnamed_0 = 0b100110;
    insn.ubfm32m_bitfield.opc = 0b10;
    insn.ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ubfm64m_bitfield.Rd = Rd;
    insn.ubfm64m_bitfield.Rn = Rn;
    insn.ubfm64m_bitfield.imms = imms;
    insn.ubfm64m_bitfield.immr = immr;
    insn.ubfm64m_bitfield.N = 0b1;
    insn.ubfm64m_bitfield._unnamed_0 = 0b100110;
    insn.ubfm64m_bitfield.opc = 0b10;
    insn.ubfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ubfx_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ubfx_ubfm32m_bitfield.Rd = Rd;
    insn.ubfx_ubfm32m_bitfield.Rn = Rn;
    insn.ubfx_ubfm32m_bitfield.imms = imms;
    insn.ubfx_ubfm32m_bitfield.immr = immr;
    insn.ubfx_ubfm32m_bitfield.N = 0b0;
    insn.ubfx_ubfm32m_bitfield._unnamed_0 = 0b100110;
    insn.ubfx_ubfm32m_bitfield.opc = 0b10;
    insn.ubfx_ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ubfx_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr) {
    DpimmEncoding insn = {};
    insn.ubfx_ubfm64m_bitfield.Rd = Rd;
    insn.ubfx_ubfm64m_bitfield.Rn = Rn;
    insn.ubfx_ubfm64m_bitfield.imms = imms;
    insn.ubfx_ubfm64m_bitfield.immr = immr;
    insn.ubfx_ubfm64m_bitfield.N = 0b1;
    insn.ubfx_ubfm64m_bitfield._unnamed_0 = 0b100110;
    insn.ubfx_ubfm64m_bitfield.opc = 0b10;
    insn.ubfx_ubfm64m_bitfield.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umax_32u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.umax32u_minmax_imm.Rd = Rd;
    insn.umax32u_minmax_imm.Rn = Rn;
    insn.umax32u_minmax_imm.imm8 = imm8;
    insn.umax32u_minmax_imm.opc = 0b0001;
    insn.umax32u_minmax_imm._unnamed_0 = 0b1000111;
    insn.umax32u_minmax_imm.S = 0b0;
    insn.umax32u_minmax_imm.op = 0b0;
    insn.umax32u_minmax_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_umax_64u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.umax64u_minmax_imm.Rd = Rd;
    insn.umax64u_minmax_imm.Rn = Rn;
    insn.umax64u_minmax_imm.imm8 = imm8;
    insn.umax64u_minmax_imm.opc = 0b0001;
    insn.umax64u_minmax_imm._unnamed_0 = 0b1000111;
    insn.umax64u_minmax_imm.S = 0b0;
    insn.umax64u_minmax_imm.op = 0b0;
    insn.umax64u_minmax_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umin_32u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.umin32u_minmax_imm.Rd = Rd;
    insn.umin32u_minmax_imm.Rn = Rn;
    insn.umin32u_minmax_imm.imm8 = imm8;
    insn.umin32u_minmax_imm.opc = 0b0011;
    insn.umin32u_minmax_imm._unnamed_0 = 0b1000111;
    insn.umin32u_minmax_imm.S = 0b0;
    insn.umin32u_minmax_imm.op = 0b0;
    insn.umin32u_minmax_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_umin_64u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8) {
    DpimmEncoding insn = {};
    insn.umin64u_minmax_imm.Rd = Rd;
    insn.umin64u_minmax_imm.Rn = Rn;
    insn.umin64u_minmax_imm.imm8 = imm8;
    insn.umin64u_minmax_imm.opc = 0b0011;
    insn.umin64u_minmax_imm._unnamed_0 = 0b1000111;
    insn.umin64u_minmax_imm.S = 0b0;
    insn.umin64u_minmax_imm.op = 0b0;
    insn.umin64u_minmax_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_uxtb_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.uxtb_ubfm32m_bitfield.Rd = Rd;
    insn.uxtb_ubfm32m_bitfield.Rn = Rn;
    insn.uxtb_ubfm32m_bitfield.imms = 0b000111;
    insn.uxtb_ubfm32m_bitfield.immr = 0b000000;
    insn.uxtb_ubfm32m_bitfield.N = 0b0;
    insn.uxtb_ubfm32m_bitfield._unnamed_1 = 0b110;
    insn.uxtb_ubfm32m_bitfield._unnamed_0 = 0b100;
    insn.uxtb_ubfm32m_bitfield.opc = 0b10;
    insn.uxtb_ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

uint32_t encode_uxth_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn) {
    DpimmEncoding insn = {};
    insn.uxth_ubfm32m_bitfield.Rd = Rd;
    insn.uxth_ubfm32m_bitfield.Rn = Rn;
    insn.uxth_ubfm32m_bitfield.imms = 0b001111;
    insn.uxth_ubfm32m_bitfield.immr = 0b000000;
    insn.uxth_ubfm32m_bitfield.N = 0b0;
    insn.uxth_ubfm32m_bitfield._unnamed_1 = 0b110;
    insn.uxth_ubfm32m_bitfield._unnamed_0 = 0b100;
    insn.uxth_ubfm32m_bitfield.opc = 0b10;
    insn.uxth_ubfm32m_bitfield.sf = 0b0;
    return insn.raw;
}

// Decode a dpimm instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_dpimm(uint32_t insn) {
    // Switch for mask 0xFFFFFC00u (9 patterns, 9 encodings)
    switch (insn & 0xFFFFFC00u) {
        case 0x11000000u: { // MOV_ADD_32_addsub_imm
                        Instruction result(Mnemonic::ADD, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.mov_add32addsub_imm.Rd, false); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.mov_add32addsub_imm.Rn, false); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.mov_add32addsub_imm.imm12, true));
                        if (enc.mov_add32addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x13001C00u: { // SXTB_SBFM_32M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sxtb_sbfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sxtb_sbfm32m_bitfield.Rn, is_64bit));
                        return result;
        }
        case 0x13003C00u: { // SXTH_SBFM_32M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sxth_sbfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sxth_sbfm32m_bitfield.Rn, is_64bit));
                        return result;
        }
        case 0x53001C00u: { // UXTB_UBFM_32M_bitfield
                        Instruction result(Mnemonic::UBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.uxtb_ubfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.uxtb_ubfm32m_bitfield.Rn, is_64bit));
                        return result;
        }
        case 0x53003C00u: { // UXTH_UBFM_32M_bitfield
                        Instruction result(Mnemonic::UBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.uxth_ubfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.uxth_ubfm32m_bitfield.Rn, is_64bit));
                        return result;
        }
        case 0x91000000u: { // MOV_ADD_64_addsub_imm
                        Instruction result(Mnemonic::ADD, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.mov_add64addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.mov_add64addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.mov_add64addsub_imm.imm12, true));
                        if (enc.mov_add64addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x93401C00u: { // SXTB_SBFM_64M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sxtb_sbfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sxtb_sbfm64m_bitfield.Rn, is_64bit));
                        return result;
        }
        case 0x93403C00u: { // SXTH_SBFM_64M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sxth_sbfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sxth_sbfm64m_bitfield.Rn, is_64bit));
                        return result;
        }
        case 0x93407C00u: { // SXTW_SBFM_64M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sxtw_sbfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sxtw_sbfm64m_bitfield.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFC0000u (8 patterns, 8 encodings)
    switch (insn & 0xFFFC0000u) {
        case 0x11C00000u: { // SMAX_32_minmax_imm
                        Instruction result(Mnemonic::SMAX, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.smax32minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smax32minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.smax32minmax_imm.imm8, true));
                        return result;
        }
        case 0x11C40000u: { // UMAX_32U_minmax_imm
                        Instruction result(Mnemonic::UMAX, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.umax32u_minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umax32u_minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.umax32u_minmax_imm.imm8, true));
                        return result;
        }
        case 0x11C80000u: { // SMIN_32_minmax_imm
                        Instruction result(Mnemonic::SMIN, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.smin32minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smin32minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.smin32minmax_imm.imm8, true));
                        return result;
        }
        case 0x11CC0000u: { // UMIN_32U_minmax_imm
                        Instruction result(Mnemonic::UMIN, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.umin32u_minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umin32u_minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.umin32u_minmax_imm.imm8, true));
                        return result;
        }
        case 0x91C00000u: { // SMAX_64_minmax_imm
                        Instruction result(Mnemonic::SMAX, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smax64minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smax64minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.smax64minmax_imm.imm8, true));
                        return result;
        }
        case 0x91C40000u: { // UMAX_64U_minmax_imm
                        Instruction result(Mnemonic::UMAX, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umax64u_minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umax64u_minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.umax64u_minmax_imm.imm8, true));
                        return result;
        }
        case 0x91C80000u: { // SMIN_64_minmax_imm
                        Instruction result(Mnemonic::SMIN, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smin64minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smin64minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.smin64minmax_imm.imm8, true));
                        return result;
        }
        case 0x91CC0000u: { // UMIN_64U_minmax_imm
                        Instruction result(Mnemonic::UMIN, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umin64u_minmax_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umin64u_minmax_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.umin64u_minmax_imm.imm8, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE08000u (1 pattern, 2 encodings)
    switch (insn & 0xFFE08000u) {
        case 0x13800000u: { // EXTR_32_extract
            // Also matches: ROR_EXTR_32_extract (EXTR)
                        Instruction result(Mnemonic::EXTR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.extr32extract.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.extr32extract.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.extr32extract.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.extr32extract.imms, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Fu (2 patterns, 2 encodings)
    switch (insn & 0xFFE0001Fu) {
        case 0xF380001Fu: { // AUTIASPPC_only_dp_1src_imm
                        Instruction result(Mnemonic::AUTIASPPC, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.autiasppc_only_dp1src_imm.imm16, true));
                        return result;
        }
        case 0xF3A0001Fu: { // AUTIBSPPC_only_dp_1src_imm
                        Instruction result(Mnemonic::AUTIBSPPC, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.autibsppc_only_dp1src_imm.imm16, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00000u (1 pattern, 2 encodings)
    switch (insn & 0xFFE00000u) {
        case 0x93C00000u: { // EXTR_64_extract
            // Also matches: ROR_EXTR_64_extract (EXTR)
                        Instruction result(Mnemonic::EXTR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.extr64extract.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.extr64extract.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.extr64extract.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.extr64extract.imms, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFC48000u (2 patterns, 2 encodings)
    switch (insn & 0xFFC48000u) {
        case 0x91800000u: { // ADDG_64_addsub_immtags
                        Instruction result(Mnemonic::ADDG, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.addg64addsub_immtags.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.addg64addsub_immtags.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.addg64addsub_immtags.imm6, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.addg64addsub_immtags.imm4, true));
                        return result;
        }
        case 0xD1800000u: { // SUBG_64_addsub_immtags
                        Instruction result(Mnemonic::SUBG, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.subg64addsub_immtags.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subg64addsub_immtags.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.subg64addsub_immtags.imm6, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.subg64addsub_immtags.imm4, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFC0FC00u (4 patterns, 4 encodings)
    switch (insn & 0xFFC0FC00u) {
        case 0x13007C00u: { // ASR_SBFM_32M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_sbfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_sbfm32m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.asr_sbfm32m_bitfield.immr, true));
                        return result;
        }
        case 0x53007C00u: { // LSR_UBFM_32M_bitfield
                        Instruction result(Mnemonic::UBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_ubfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_ubfm32m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.lsr_ubfm32m_bitfield.immr, true));
                        return result;
        }
        case 0x9340FC00u: { // ASR_SBFM_64M_bitfield
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_sbfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_sbfm64m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.asr_sbfm64m_bitfield.immr, true));
                        return result;
        }
        case 0xD340FC00u: { // LSR_UBFM_64M_bitfield
                        Instruction result(Mnemonic::UBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_ubfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_ubfm64m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.lsr_ubfm64m_bitfield.immr, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFC003E0u (3 patterns, 5 encodings)
    switch (insn & 0xFFC003E0u) {
        case 0x320003E0u: { // MOV_ORR_32_log_imm
                        Instruction result(Mnemonic::ORR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.mov_orr32log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_orr32log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.mov_orr32log_imm.N, enc.mov_orr32log_imm.imms, enc.mov_orr32log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0x330003E0u: { // BFC_BFM_32M_bitfield
            // Also matches: BFI_BFM_32M_bitfield (BFM)
                        Instruction result(Mnemonic::BFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.bfc_bfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfc_bfm32m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfc_bfm32m_bitfield.imms, true));
                        return result;
        }
        case 0xB34003E0u: { // BFC_BFM_64M_bitfield
            // Also matches: BFI_BFM_64M_bitfield (BFM)
                        Instruction result(Mnemonic::BFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.bfc_bfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfc_bfm64m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfc_bfm64m_bitfield.imms, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFC0001Fu (1 pattern, 1 encoding)
    switch (insn & 0xFFC0001Fu) {
        case 0x7200001Fu: { // TST_ANDS_32S_log_imm
                        Instruction result(Mnemonic::ANDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands32s_log_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands32s_log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.tst_ands32s_log_imm.N, enc.tst_ands32s_log_imm.imms, enc.tst_ands32s_log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFC00000u (13 patterns, 27 encodings)
    switch (insn & 0xFFC00000u) {
        case 0x12000000u: { // AND_32_log_imm
                        Instruction result(Mnemonic::AND, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.and32log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.and32log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.and32log_imm.N, enc.and32log_imm.imms, enc.and32log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0x12800000u: { // MOV_MOVN_32_movewide
            // Also matches: MOVN_32_movewide (MOVN)
                        Instruction result(Mnemonic::MOVN, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_movn32movewide.Rd, false));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.mov_movn32movewide.imm16, true));
                        if (enc.mov_movn32movewide.hw != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, enc.mov_movn32movewide.hw * 16, true));
                        }
                        return result;
        }
        case 0x13000000u: { // SBFIZ_SBFM_32M_bitfield
            // Also matches: SBFM_32M_bitfield (SBFM)
            // Also matches: SBFX_SBFM_32M_bitfield (SBFM)
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sbfiz_sbfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbfiz_sbfm32m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sbfiz_sbfm32m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sbfiz_sbfm32m_bitfield.imms, true));
                        return result;
        }
        case 0x32000000u: { // ORR_32_log_imm
                        Instruction result(Mnemonic::ORR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.orr32log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.orr32log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.orr32log_imm.N, enc.orr32log_imm.imms, enc.orr32log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0x33000000u: { // BFM_32M_bitfield
            // Also matches: BFXIL_BFM_32M_bitfield (BFM)
                        Instruction result(Mnemonic::BFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.bfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bfm32m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfm32m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfm32m_bitfield.imms, true));
                        return result;
        }
        case 0x52000000u: { // EOR_32_log_imm
                        Instruction result(Mnemonic::EOR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.eor32log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.eor32log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.eor32log_imm.N, enc.eor32log_imm.imms, enc.eor32log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0x52800000u: { // MOV_MOVZ_32_movewide
            // Also matches: MOVZ_32_movewide (MOVZ)
                        Instruction result(Mnemonic::MOVZ, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_movz32movewide.Rd, false));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.mov_movz32movewide.imm16, true));
                        if (enc.mov_movz32movewide.hw != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, enc.mov_movz32movewide.hw * 16, true));
                        }
                        return result;
        }
        case 0x53000000u: { // LSL_UBFM_32M_bitfield
            // Also matches: UBFIZ_UBFM_32M_bitfield (UBFM)
            // Also matches: UBFM_32M_bitfield (UBFM)
            // Also matches: UBFX_UBFM_32M_bitfield (UBFM)
                        Instruction result(Mnemonic::UBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_ubfm32m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_ubfm32m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.lsl_ubfm32m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.lsl_ubfm32m_bitfield.imms, true));
                        return result;
        }
        case 0x72000000u: { // ANDS_32S_log_imm
                        Instruction result(Mnemonic::ANDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ands32s_log_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ands32s_log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.ands32s_log_imm.N, enc.ands32s_log_imm.imms, enc.ands32s_log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0x72800000u: { // MOVK_32_movewide
                        Instruction result(Mnemonic::MOVK, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.movk32movewide.Rd, false));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.movk32movewide.imm16, true));
                        if (enc.movk32movewide.hw != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, enc.movk32movewide.hw * 16, true));
                        }
                        return result;
        }
        case 0x93400000u: { // SBFIZ_SBFM_64M_bitfield
            // Also matches: SBFM_64M_bitfield (SBFM)
            // Also matches: SBFX_SBFM_64M_bitfield (SBFM)
                        Instruction result(Mnemonic::SBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sbfiz_sbfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbfiz_sbfm64m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sbfiz_sbfm64m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sbfiz_sbfm64m_bitfield.imms, true));
                        return result;
        }
        case 0xB3400000u: { // BFM_64M_bitfield
            // Also matches: BFXIL_BFM_64M_bitfield (BFM)
                        Instruction result(Mnemonic::BFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.bfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bfm64m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfm64m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.bfm64m_bitfield.imms, true));
                        return result;
        }
        case 0xD3400000u: { // LSL_UBFM_64M_bitfield
            // Also matches: UBFIZ_UBFM_64M_bitfield (UBFM)
            // Also matches: UBFM_64M_bitfield (UBFM)
            // Also matches: UBFX_UBFM_64M_bitfield (UBFM)
                        Instruction result(Mnemonic::UBFM, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_ubfm64m_bitfield.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_ubfm64m_bitfield.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.lsl_ubfm64m_bitfield.immr, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.lsl_ubfm64m_bitfield.imms, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF8003E0u (1 pattern, 1 encoding)
    switch (insn & 0xFF8003E0u) {
        case 0xB20003E0u: { // MOV_ORR_64_log_imm
                        Instruction result(Mnemonic::ORR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.mov_orr64log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_orr64log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.mov_orr64log_imm.N, enc.mov_orr64log_imm.imms, enc.mov_orr64log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF80001Fu (5 patterns, 5 encodings)
    switch (insn & 0xFF80001Fu) {
        case 0x3100001Fu: { // CMN_ADDS_32S_addsub_imm
                        Instruction result(Mnemonic::ADDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.cmn_adds32s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.cmn_adds32s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cmn_adds32s_addsub_imm.imm12, true));
                        if (enc.cmn_adds32s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x7100001Fu: { // CMP_SUBS_32S_addsub_imm
                        Instruction result(Mnemonic::SUBS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.cmp_subs32s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.cmp_subs32s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cmp_subs32s_addsub_imm.imm12, true));
                        if (enc.cmp_subs32s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0xB100001Fu: { // CMN_ADDS_64S_addsub_imm
                        Instruction result(Mnemonic::ADDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.cmn_adds64s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.cmn_adds64s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cmn_adds64s_addsub_imm.imm12, true));
                        if (enc.cmn_adds64s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0xF100001Fu: { // CMP_SUBS_64S_addsub_imm
                        Instruction result(Mnemonic::SUBS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.cmp_subs64s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.cmp_subs64s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cmp_subs64s_addsub_imm.imm12, true));
                        if (enc.cmp_subs64s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0xF200001Fu: { // TST_ANDS_64S_log_imm
                        Instruction result(Mnemonic::ANDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands64s_log_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands64s_log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.tst_ands64s_log_imm.N, enc.tst_ands64s_log_imm.imms, enc.tst_ands64s_log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF800000u (15 patterns, 17 encodings)
    switch (insn & 0xFF800000u) {
        case 0x11000000u: { // ADD_32_addsub_imm
                        Instruction result(Mnemonic::ADD, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.add32addsub_imm.Rd, false); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.add32addsub_imm.Rn, false); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.add32addsub_imm.imm12, true));
                        if (enc.add32addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x31000000u: { // ADDS_32S_addsub_imm
                        Instruction result(Mnemonic::ADDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.adds32s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.adds32s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.adds32s_addsub_imm.imm12, true));
                        if (enc.adds32s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x51000000u: { // SUB_32_addsub_imm
                        Instruction result(Mnemonic::SUB, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.sub32addsub_imm.Rd, false); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.sub32addsub_imm.Rn, false); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sub32addsub_imm.imm12, true));
                        if (enc.sub32addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x71000000u: { // SUBS_32S_addsub_imm
                        Instruction result(Mnemonic::SUBS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.subs32s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.subs32s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.subs32s_addsub_imm.imm12, true));
                        if (enc.subs32s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x91000000u: { // ADD_64_addsub_imm
                        Instruction result(Mnemonic::ADD, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.add64addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.add64addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.add64addsub_imm.imm12, true));
                        if (enc.add64addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0x92000000u: { // AND_64_log_imm
                        Instruction result(Mnemonic::AND, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.and64log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.and64log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.and64log_imm.N, enc.and64log_imm.imms, enc.and64log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0x92800000u: { // MOV_MOVN_64_movewide
            // Also matches: MOVN_64_movewide (MOVN)
                        Instruction result(Mnemonic::MOVN, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_movn64movewide.Rd, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.mov_movn64movewide.imm16, true));
                        if (enc.mov_movn64movewide.hw != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, enc.mov_movn64movewide.hw * 16, true));
                        }
                        return result;
        }
        case 0xB1000000u: { // ADDS_64S_addsub_imm
                        Instruction result(Mnemonic::ADDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.adds64s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.adds64s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.adds64s_addsub_imm.imm12, true));
                        if (enc.adds64s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0xB2000000u: { // ORR_64_log_imm
                        Instruction result(Mnemonic::ORR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.orr64log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.orr64log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.orr64log_imm.N, enc.orr64log_imm.imms, enc.orr64log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0xD1000000u: { // SUB_64_addsub_imm
                        Instruction result(Mnemonic::SUB, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.sub64addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.sub64addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sub64addsub_imm.imm12, true));
                        if (enc.sub64addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0xD2000000u: { // EOR_64_log_imm
                        Instruction result(Mnemonic::EOR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.eor64log_imm.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Register, enc.eor64log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.eor64log_imm.N, enc.eor64log_imm.imms, enc.eor64log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0xD2800000u: { // MOV_MOVZ_64_movewide
            // Also matches: MOVZ_64_movewide (MOVZ)
                        Instruction result(Mnemonic::MOVZ, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_movz64movewide.Rd, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.mov_movz64movewide.imm16, true));
                        if (enc.mov_movz64movewide.hw != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, enc.mov_movz64movewide.hw * 16, true));
                        }
                        return result;
        }
        case 0xF1000000u: { // SUBS_64S_addsub_imm
                        Instruction result(Mnemonic::SUBS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        { Operand op(OperandType::Register, enc.subs64s_addsub_imm.Rd, true); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.subs64s_addsub_imm.Rn, true); op.is_sp = true; result.operands.push_back(op); }
                        result.operands.push_back(Operand(OperandType::Immediate, enc.subs64s_addsub_imm.imm12, true));
                        if (enc.subs64s_addsub_imm.sh != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, 12, true));
                        }
                        return result;
        }
        case 0xF2000000u: { // ANDS_64S_log_imm
                        Instruction result(Mnemonic::ANDS, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ands64s_log_imm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ands64s_log_imm.Rn, is_64bit));
                        uint64_t imm_val = decode_bit_masks(enc.ands64s_log_imm.N, enc.ands64s_log_imm.imms, enc.ands64s_log_imm.immr, is_64bit);
                        result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(imm_val), is_64bit));
                        return result;
        }
        case 0xF2800000u: { // MOVK_64_movewide
                        Instruction result(Mnemonic::MOVK, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.movk64movewide.Rd, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.movk64movewide.imm16, true));
                        if (enc.movk64movewide.hw != 0) {
                            result.operands.push_back(Operand(OperandType::Shift, enc.movk64movewide.hw * 16, true));
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0x9F000000u (2 patterns, 2 encodings)
    switch (insn & 0x9F000000u) {
        case 0x10000000u: { // ADR_only_pcreladdr
                        Instruction result(Mnemonic::ADR, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.adr_only_pcreladdr.Rd, true));
                        int32_t imm21 = static_cast<int32_t>((enc.adr_only_pcreladdr.immhi << 2) | (enc.adr_only_pcreladdr.immlo & 0x3));
                        if (imm21 & 0x100000) imm21 |= static_cast<int32_t>(0xFFE00000);
                        int32_t offset = imm21;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0x90000000u: { // ADRP_only_pcreladdr
                        Instruction result(Mnemonic::ADRP, insn);
                        DpimmEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.adrp_only_pcreladdr.Rd, true));
                        int32_t imm21 = static_cast<int32_t>((enc.adrp_only_pcreladdr.immhi << 2) | (enc.adrp_only_pcreladdr.immlo & 0x3));
                        if (imm21 & 0x100000) imm21 |= static_cast<int32_t>(0xFFE00000);
                        int32_t offset = imm21 << 12;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace dpimm
} // namespace format
} // namespace veda64
