#include "format/dpreg.hpp"

namespace veda64 {
namespace format {
namespace dpreg {

// Encoding structures union
union DpregEncoding {
    uint32_t raw;
    // ABS: Absolute value
    // Encoding: ABS_32_dp_1src
    // Template: ABS  <Wd>, <Wn>
    struct Abs32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b001000 (0x8)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Abs32Dp1src abs32dp1src;

    // ABS: Absolute value
    // Encoding: ABS_64_dp_1src
    // Template: ABS  <Xd>, <Xn>
    struct Abs64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b001000 (0x8)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Abs64Dp1src abs64dp1src;

    // ADC: Add with carry
    // Encoding: ADC_32_addsub_carry
    // Template: ADC  <Wd>, <Wn>, <Wm>
    struct Adc32AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Adc32AddsubCarry adc32addsub_carry;

    // ADC: Add with carry
    // Encoding: ADC_64_addsub_carry
    // Template: ADC  <Xd>, <Xn>, <Xm>
    struct Adc64AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Adc64AddsubCarry adc64addsub_carry;

    // ADCS: Add with carry, setting flags
    // Encoding: ADCS_32_addsub_carry
    // Template: ADCS  <Wd>, <Wn>, <Wm>
    struct Adcs32AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Adcs32AddsubCarry adcs32addsub_carry;

    // ADCS: Add with carry, setting flags
    // Encoding: ADCS_64_addsub_carry
    // Template: ADCS  <Xd>, <Xn>, <Xm>
    struct Adcs64AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Adcs64AddsubCarry adcs64addsub_carry;

    // ADD: Add extended and scaled register
    // Encoding: ADD_32_addsub_ext
    // Template: ADD  <Wd|WSP>, <Wn|WSP>, <Wm>{, <extend> {#<amount>}}
    struct Add32AddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Add32AddsubExt add32addsub_ext;

    // ADD: Add extended and scaled register
    // Encoding: ADD_64_addsub_ext
    // Template: ADD  <Xd|SP>, <Xn|SP>, <R><m>{, <extend> {#<amount>}}
    struct Add64AddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Add64AddsubExt add64addsub_ext;

    // ADD: Add optionally-shifted register
    // Encoding: ADD_32_addsub_shift
    // Template: ADD  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Add32AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Add32AddsubShift add32addsub_shift;

    // ADD: Add optionally-shifted register
    // Encoding: ADD_64_addsub_shift
    // Template: ADD  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Add64AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Add64AddsubShift add64addsub_shift;

    // ADDPT: Add checked pointer
    // Encoding: ADDPT_64_addsub_pt
    // Template: ADDPT  <Xd|SP>, <Xn|SP>, <Xm>{, LSL #<amount>}
    struct Addpt64AddsubPt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Addpt64AddsubPt addpt64addsub_pt;

    // ADDS: Add extended and scaled register, setting flags
    // Encoding: ADDS_32S_addsub_ext
    // Template: ADDS  <Wd>, <Wn|WSP>, <Wm>{, <extend> {#<amount>}}
    struct Adds32sAddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Adds32sAddsubExt adds32s_addsub_ext;

    // ADDS: Add extended and scaled register, setting flags
    // Encoding: ADDS_64S_addsub_ext
    // Template: ADDS  <Xd>, <Xn|SP>, <R><m>{, <extend> {#<amount>}}
    struct Adds64sAddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Adds64sAddsubExt adds64s_addsub_ext;

    // ADDS: Add optionally-shifted register, setting flags
    // Encoding: ADDS_32_addsub_shift
    // Template: ADDS  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Adds32AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Adds32AddsubShift adds32addsub_shift;

    // ADDS: Add optionally-shifted register, setting flags
    // Encoding: ADDS_64_addsub_shift
    // Template: ADDS  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Adds64AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Adds64AddsubShift adds64addsub_shift;

    // AND: Bitwise AND (shifted register)
    // Encoding: AND_32_log_shift
    // Template: AND  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct And32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    And32LogShift and32log_shift;

    // AND: Bitwise AND (shifted register)
    // Encoding: AND_64_log_shift
    // Template: AND  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct And64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    And64LogShift and64log_shift;

    // ANDS: Bitwise AND (shifted register), setting flags
    // Encoding: ANDS_32_log_shift
    // Template: ANDS  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Ands32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ands32LogShift ands32log_shift;

    // ANDS: Bitwise AND (shifted register), setting flags
    // Encoding: ANDS_64_log_shift
    // Template: ANDS  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Ands64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ands64LogShift ands64log_shift;

    // ASRV: Arithmetic shift right (register)
    // Encoding: ASR_ASRV_32_dp_2src
    // Template: ASR  <Wd>, <Wn>, <Wm>
    struct AsrAsrv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    AsrAsrv32Dp2src asr_asrv32dp2src;

    // ASRV: Arithmetic shift right (register)
    // Encoding: ASR_ASRV_64_dp_2src
    // Template: ASR  <Xd>, <Xn>, <Xm>
    struct AsrAsrv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    AsrAsrv64Dp2src asr_asrv64dp2src;

    // ASRV: Arithmetic shift right variable
    // Encoding: ASRV_32_dp_2src
    // Template: ASRV  <Wd>, <Wn>, <Wm>
    struct Asrv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Asrv32Dp2src asrv32dp2src;

    // ASRV: Arithmetic shift right variable
    // Encoding: ASRV_64_dp_2src
    // Template: ASRV  <Xd>, <Xn>, <Xm>
    struct Asrv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Asrv64Dp2src asrv64dp2src;

    // : Authenticate data address, using key A
    // Encoding: AUTDA_64P_dp_1src
    // Template: AUTDA  <Xd>, <Xn|SP>
    struct Autda64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b110 (0x6)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autda64pDp1src autda64p_dp1src;

    // : Authenticate data address, using key A
    // Encoding: AUTDZA_64Z_dp_1src
    // Template: AUTDZA  <Xd>
    struct Autdza64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b110 (0x6)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autdza64zDp1src autdza64z_dp1src;

    // : Authenticate data address, using key B
    // Encoding: AUTDB_64P_dp_1src
    // Template: AUTDB  <Xd>, <Xn|SP>
    struct Autdb64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b111 (0x7)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autdb64pDp1src autdb64p_dp1src;

    // : Authenticate data address, using key B
    // Encoding: AUTDZB_64Z_dp_1src
    // Template: AUTDZB  <Xd>
    struct Autdzb64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b111 (0x7)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autdzb64zDp1src autdzb64z_dp1src;

    // : Authenticate instruction address, using key A
    // Encoding: AUTIA_64P_dp_1src
    // Template: AUTIA  <Xd>, <Xn|SP>
    struct Autia64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autia64pDp1src autia64p_dp1src;

    // : Authenticate instruction address, using key A
    // Encoding: AUTIZA_64Z_dp_1src
    // Template: AUTIZA  <Xd>
    struct Autiza64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autiza64zDp1src autiza64z_dp1src;

    // AUTIA171615: Authenticate instruction address, using key A
    // Encoding: AUTIA171615_64LR_dp_1src
    // Template: AUTIA171615
    struct Autia17161564lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b101110 (0x2E)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autia17161564lrDp1src autia17161564lr_dp1src;

    // AUTIASPPCR: Authenticate return address using key A, using a register
    // Encoding: AUTIASPPCR_64LRR_dp_1src
    // Template: AUTIASPPCR  <Xn>
    struct Autiasppcr64lrrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b100100 (0x24)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autiasppcr64lrrDp1src autiasppcr64lrr_dp1src;

    // : Authenticate instruction address, using key B
    // Encoding: AUTIB_64P_dp_1src
    // Template: AUTIB  <Xd>, <Xn|SP>
    struct Autib64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autib64pDp1src autib64p_dp1src;

    // : Authenticate instruction address, using key B
    // Encoding: AUTIZB_64Z_dp_1src
    // Template: AUTIZB  <Xd>
    struct Autizb64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autizb64zDp1src autizb64z_dp1src;

    // AUTIB171615: Authenticate instruction address, using key B
    // Encoding: AUTIB171615_64LR_dp_1src
    // Template: AUTIB171615
    struct Autib17161564lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b101111 (0x2F)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autib17161564lrDp1src autib17161564lr_dp1src;

    // AUTIBSPPCR: Authenticate return address using key B, using a register
    // Encoding: AUTIBSPPCR_64LRR_dp_1src
    // Template: AUTIBSPPCR  <Xn>
    struct Autibsppcr64lrrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b100101 (0x25)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Autibsppcr64lrrDp1src autibsppcr64lrr_dp1src;

    // BIC: Bitwise bit clear (shifted register)
    // Encoding: BIC_32_log_shift
    // Template: BIC  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Bic32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Bic32LogShift bic32log_shift;

    // BIC: Bitwise bit clear (shifted register)
    // Encoding: BIC_64_log_shift
    // Template: BIC  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Bic64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Bic64LogShift bic64log_shift;

    // BICS: Bitwise bit clear (shifted register), setting flags
    // Encoding: BICS_32_log_shift
    // Template: BICS  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Bics32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Bics32LogShift bics32log_shift;

    // BICS: Bitwise bit clear (shifted register), setting flags
    // Encoding: BICS_64_log_shift
    // Template: BICS  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Bics64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Bics64LogShift bics64log_shift;

    // CCMN: Conditional compare negative (immediate)
    // Encoding: CCMN_32_condcmp_imm
    // Template: CCMN  <Wn>, #<imm>, #<nzcv>, <cond>
    struct Ccmn32CondcmpImm {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t cond : 4;
        uint32_t imm5 : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ccmn32CondcmpImm ccmn32condcmp_imm;

    // CCMN: Conditional compare negative (immediate)
    // Encoding: CCMN_64_condcmp_imm
    // Template: CCMN  <Xn>, #<imm>, #<nzcv>, <cond>
    struct Ccmn64CondcmpImm {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t cond : 4;
        uint32_t imm5 : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ccmn64CondcmpImm ccmn64condcmp_imm;

    // CCMN: Conditional compare negative (register)
    // Encoding: CCMN_32_condcmp_reg
    // Template: CCMN  <Wn>, <Wm>, #<nzcv>, <cond>
    struct Ccmn32CondcmpReg {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ccmn32CondcmpReg ccmn32condcmp_reg;

    // CCMN: Conditional compare negative (register)
    // Encoding: CCMN_64_condcmp_reg
    // Template: CCMN  <Xn>, <Xm>, #<nzcv>, <cond>
    struct Ccmn64CondcmpReg {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ccmn64CondcmpReg ccmn64condcmp_reg;

    // CCMP: Conditional compare (immediate)
    // Encoding: CCMP_32_condcmp_imm
    // Template: CCMP  <Wn>, #<imm>, #<nzcv>, <cond>
    struct Ccmp32CondcmpImm {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t cond : 4;
        uint32_t imm5 : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ccmp32CondcmpImm ccmp32condcmp_imm;

    // CCMP: Conditional compare (immediate)
    // Encoding: CCMP_64_condcmp_imm
    // Template: CCMP  <Xn>, #<imm>, #<nzcv>, <cond>
    struct Ccmp64CondcmpImm {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t cond : 4;
        uint32_t imm5 : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ccmp64CondcmpImm ccmp64condcmp_imm;

    // CCMP: Conditional compare (register)
    // Encoding: CCMP_32_condcmp_reg
    // Template: CCMP  <Wn>, <Wm>, #<nzcv>, <cond>
    struct Ccmp32CondcmpReg {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ccmp32CondcmpReg ccmp32condcmp_reg;

    // CCMP: Conditional compare (register)
    // Encoding: CCMP_64_condcmp_reg
    // Template: CCMP  <Xn>, <Xm>, #<nzcv>, <cond>
    struct Ccmp64CondcmpReg {
        uint32_t nzcv : 4;
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010010 (0xD2)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ccmp64CondcmpReg ccmp64condcmp_reg;

    // CSINC: Conditional increment
    // Encoding: CINC_CSINC_32_condsel
    // Template: CINC  <Wd>, <Wn>, <invcond>
    struct CincCsinc32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // partial: != 11111
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // partial: != 11111
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CincCsinc32Condsel cinc_csinc32condsel;

    // CSINC: Conditional increment
    // Encoding: CINC_CSINC_64_condsel
    // Template: CINC  <Xd>, <Xn>, <invcond>
    struct CincCsinc64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // partial: != 11111
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // partial: != 11111
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CincCsinc64Condsel cinc_csinc64condsel;

    // CSINV: Conditional invert
    // Encoding: CINV_CSINV_32_condsel
    // Template: CINV  <Wd>, <Wn>, <invcond>
    struct CinvCsinv32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // partial: != 11111
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // partial: != 11111
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CinvCsinv32Condsel cinv_csinv32condsel;

    // CSINV: Conditional invert
    // Encoding: CINV_CSINV_64_condsel
    // Template: CINV  <Xd>, <Xn>, <invcond>
    struct CinvCsinv64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // partial: != 11111
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // partial: != 11111
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CinvCsinv64Condsel cinv_csinv64condsel;

    // CLS: Count leading sign bits
    // Encoding: CLS_32_dp_1src
    // Template: CLS  <Wd>, <Wn>
    struct Cls32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00010 (0x2)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cls32Dp1src cls32dp1src;

    // CLS: Count leading sign bits
    // Encoding: CLS_64_dp_1src
    // Template: CLS  <Xd>, <Xn>
    struct Cls64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00010 (0x2)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cls64Dp1src cls64dp1src;

    // CLZ: Count leading zeros
    // Encoding: CLZ_32_dp_1src
    // Template: CLZ  <Wd>, <Wn>
    struct Clz32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00010 (0x2)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Clz32Dp1src clz32dp1src;

    // CLZ: Count leading zeros
    // Encoding: CLZ_64_dp_1src
    // Template: CLZ  <Xd>, <Xn>
    struct Clz64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00010 (0x2)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Clz64Dp1src clz64dp1src;

    // ADDS: Compare negative (extended register)
    // Encoding: CMN_ADDS_32S_addsub_ext
    // Template: CMN  <Wn|WSP>, <Wm>{, <extend> {#<amount>}}
    struct CmnAdds32sAddsubExt {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CmnAdds32sAddsubExt cmn_adds32s_addsub_ext;

    // ADDS: Compare negative (extended register)
    // Encoding: CMN_ADDS_64S_addsub_ext
    // Template: CMN  <Xn|SP>, <R><m>{, <extend> {#<amount>}}
    struct CmnAdds64sAddsubExt {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmnAdds64sAddsubExt cmn_adds64s_addsub_ext;

    // ADDS: Compare negative (shifted register)
    // Encoding: CMN_ADDS_32_addsub_shift
    // Template: CMN  <Wn>, <Wm>{, <shift> #<amount>}
    struct CmnAdds32AddsubShift {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CmnAdds32AddsubShift cmn_adds32addsub_shift;

    // ADDS: Compare negative (shifted register)
    // Encoding: CMN_ADDS_64_addsub_shift
    // Template: CMN  <Xn>, <Xm>{, <shift> #<amount>}
    struct CmnAdds64AddsubShift {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmnAdds64AddsubShift cmn_adds64addsub_shift;

    // SUBS: Compare (extended register)
    // Encoding: CMP_SUBS_32S_addsub_ext
    // Template: CMP  <Wn|WSP>, <Wm>{, <extend> {#<amount>}}
    struct CmpSubs32sAddsubExt {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CmpSubs32sAddsubExt cmp_subs32s_addsub_ext;

    // SUBS: Compare (extended register)
    // Encoding: CMP_SUBS_64S_addsub_ext
    // Template: CMP  <Xn|SP>, <R><m>{, <extend> {#<amount>}}
    struct CmpSubs64sAddsubExt {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmpSubs64sAddsubExt cmp_subs64s_addsub_ext;

    // SUBS: Compare (shifted register)
    // Encoding: CMP_SUBS_32_addsub_shift
    // Template: CMP  <Wn>, <Wm>{, <shift> #<amount>}
    struct CmpSubs32AddsubShift {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CmpSubs32AddsubShift cmp_subs32addsub_shift;

    // SUBS: Compare (shifted register)
    // Encoding: CMP_SUBS_64_addsub_shift
    // Template: CMP  <Xn>, <Xm>{, <shift> #<amount>}
    struct CmpSubs64AddsubShift {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmpSubs64AddsubShift cmp_subs64addsub_shift;

    // SUBPS: Compare with tag
    // Encoding: CMPP_SUBPS_64S_dp_2src
    // Template: CMPP  <Xn|SP>, <Xm|SP>
    struct CmppSubps64sDp2src {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CmppSubps64sDp2src cmpp_subps64s_dp2src;

    // CSNEG: Conditional negate
    // Encoding: CNEG_CSNEG_32_condsel
    // Template: CNEG  <Wd>, <Wn>, <invcond>
    struct CnegCsneg32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CnegCsneg32Condsel cneg_csneg32condsel;

    // CSNEG: Conditional negate
    // Encoding: CNEG_CSNEG_64_condsel
    // Template: CNEG  <Xd>, <Xn>, <invcond>
    struct CnegCsneg64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CnegCsneg64Condsel cneg_csneg64condsel;

    // CNT: Count bits
    // Encoding: CNT_32_dp_1src
    // Template: CNT  <Wd>, <Wn>
    struct Cnt32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000111 (0x7)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cnt32Dp1src cnt32dp1src;

    // CNT: Count bits
    // Encoding: CNT_64_dp_1src
    // Template: CNT  <Xd>, <Xn>
    struct Cnt64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000111 (0x7)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cnt64Dp1src cnt64dp1src;

    // : CRC32 checksum
    // Encoding: CRC32B_32C_dp_2src
    // Template: CRC32B  <Wd>, <Wn>, <Wm>
    struct Crc32b32cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b00 (0x0)
        uint32_t C : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Crc32b32cDp2src crc32b32c_dp2src;

    // : CRC32 checksum
    // Encoding: CRC32H_32C_dp_2src
    // Template: CRC32H  <Wd>, <Wn>, <Wm>
    struct Crc32h32cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b01 (0x1)
        uint32_t C : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Crc32h32cDp2src crc32h32c_dp2src;

    // : CRC32 checksum
    // Encoding: CRC32W_32C_dp_2src
    // Template: CRC32W  <Wd>, <Wn>, <Wm>
    struct Crc32w32cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b10 (0x2)
        uint32_t C : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Crc32w32cDp2src crc32w32c_dp2src;

    // : CRC32 checksum
    // Encoding: CRC32X_64C_dp_2src
    // Template: CRC32X  <Wd>, <Wn>, <Xm>
    struct Crc32x64cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b11 (0x3)
        uint32_t C : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Crc32x64cDp2src crc32x64c_dp2src;

    // : CRC32C checksum
    // Encoding: CRC32CB_32C_dp_2src
    // Template: CRC32CB  <Wd>, <Wn>, <Wm>
    struct Crc32cb32cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b00 (0x0)
        uint32_t C : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Crc32cb32cDp2src crc32cb32c_dp2src;

    // : CRC32C checksum
    // Encoding: CRC32CH_32C_dp_2src
    // Template: CRC32CH  <Wd>, <Wn>, <Wm>
    struct Crc32ch32cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b01 (0x1)
        uint32_t C : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Crc32ch32cDp2src crc32ch32c_dp2src;

    // : CRC32C checksum
    // Encoding: CRC32CW_32C_dp_2src
    // Template: CRC32CW  <Wd>, <Wn>, <Wm>
    struct Crc32cw32cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b10 (0x2)
        uint32_t C : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Crc32cw32cDp2src crc32cw32c_dp2src;

    // : CRC32C checksum
    // Encoding: CRC32CX_64C_dp_2src
    // Template: CRC32CX  <Wd>, <Wn>, <Xm>
    struct Crc32cx64cDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t sz : 2;  // fixed: 0b11 (0x3)
        uint32_t C : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Crc32cx64cDp2src crc32cx64c_dp2src;

    // CSEL: Conditional select
    // Encoding: CSEL_32_condsel
    // Template: CSEL  <Wd>, <Wn>, <Wm>, <cond>
    struct Csel32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Csel32Condsel csel32condsel;

    // CSEL: Conditional select
    // Encoding: CSEL_64_condsel
    // Template: CSEL  <Xd>, <Xn>, <Xm>, <cond>
    struct Csel64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Csel64Condsel csel64condsel;

    // CSINC: Conditional set
    // Encoding: CSET_CSINC_32_condsel
    // Template: CSET  <Wd>, <invcond>
    struct CsetCsinc32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CsetCsinc32Condsel cset_csinc32condsel;

    // CSINC: Conditional set
    // Encoding: CSET_CSINC_64_condsel
    // Template: CSET  <Xd>, <invcond>
    struct CsetCsinc64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CsetCsinc64Condsel cset_csinc64condsel;

    // CSINV: Conditional set mask
    // Encoding: CSETM_CSINV_32_condsel
    // Template: CSETM  <Wd>, <invcond>
    struct CsetmCsinv32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CsetmCsinv32Condsel csetm_csinv32condsel;

    // CSINV: Conditional set mask
    // Encoding: CSETM_CSINV_64_condsel
    // Template: CSETM  <Xd>, <invcond>
    struct CsetmCsinv64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;  // partial: != 111x
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CsetmCsinv64Condsel csetm_csinv64condsel;

    // CSINC: Conditional select increment
    // Encoding: CSINC_32_condsel
    // Template: CSINC  <Wd>, <Wn>, <Wm>, <cond>
    struct Csinc32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Csinc32Condsel csinc32condsel;

    // CSINC: Conditional select increment
    // Encoding: CSINC_64_condsel
    // Template: CSINC  <Xd>, <Xn>, <Xm>, <cond>
    struct Csinc64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Csinc64Condsel csinc64condsel;

    // CSINV: Conditional select invert
    // Encoding: CSINV_32_condsel
    // Template: CSINV  <Wd>, <Wn>, <Wm>, <cond>
    struct Csinv32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Csinv32Condsel csinv32condsel;

    // CSINV: Conditional select invert
    // Encoding: CSINV_64_condsel
    // Template: CSINV  <Xd>, <Xn>, <Xm>, <cond>
    struct Csinv64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Csinv64Condsel csinv64condsel;

    // CSNEG: Conditional select negation
    // Encoding: CSNEG_32_condsel
    // Template: CSNEG  <Wd>, <Wn>, <Wm>, <cond>
    struct Csneg32Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Csneg32Condsel csneg32condsel;

    // CSNEG: Conditional select negation
    // Encoding: CSNEG_64_condsel
    // Template: CSNEG  <Xd>, <Xn>, <Xm>, <cond>
    struct Csneg64Condsel {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t cond : 4;
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010100 (0xD4)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Csneg64Condsel csneg64condsel;

    // CTZ: Count trailing zeros
    // Encoding: CTZ_32_dp_1src
    // Template: CTZ  <Wd>, <Wn>
    struct Ctz32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000110 (0x6)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Ctz32Dp1src ctz32dp1src;

    // CTZ: Count trailing zeros
    // Encoding: CTZ_64_dp_1src
    // Template: CTZ  <Xd>, <Xn>
    struct Ctz64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000110 (0x6)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Ctz64Dp1src ctz64dp1src;

    // EON: Bitwise exclusive-OR NOT (shifted register)
    // Encoding: EON_32_log_shift
    // Template: EON  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Eon32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Eon32LogShift eon32log_shift;

    // EON: Bitwise exclusive-OR NOT (shifted register)
    // Encoding: EON_64_log_shift
    // Template: EON  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Eon64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Eon64LogShift eon64log_shift;

    // EOR: Bitwise exclusive-OR (shifted register)
    // Encoding: EOR_32_log_shift
    // Template: EOR  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Eor32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Eor32LogShift eor32log_shift;

    // EOR: Bitwise exclusive-OR (shifted register)
    // Encoding: EOR_64_log_shift
    // Template: EOR  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Eor64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Eor64LogShift eor64log_shift;

    // GMI: Tag mask insert
    // Encoding: GMI_64G_dp_2src
    // Template: GMI  <Xd>, <Xn|SP>, <Xm>
    struct Gmi64gDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000101 (0x5)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Gmi64gDp2src gmi64g_dp2src;

    // IRG: Insert random tag
    // Encoding: IRG_64I_dp_2src
    // Template: IRG  <Xd|SP>, <Xn|SP>{, <Xm>}
    struct Irg64iDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000100 (0x4)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Irg64iDp2src irg64i_dp2src;

    // LSLV: Logical shift left (register)
    // Encoding: LSL_LSLV_32_dp_2src
    // Template: LSL  <Wd>, <Wn>, <Wm>
    struct LslLslv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    LslLslv32Dp2src lsl_lslv32dp2src;

    // LSLV: Logical shift left (register)
    // Encoding: LSL_LSLV_64_dp_2src
    // Template: LSL  <Xd>, <Xn>, <Xm>
    struct LslLslv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    LslLslv64Dp2src lsl_lslv64dp2src;

    // LSLV: Logical shift left variable
    // Encoding: LSLV_32_dp_2src
    // Template: LSLV  <Wd>, <Wn>, <Wm>
    struct Lslv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Lslv32Dp2src lslv32dp2src;

    // LSLV: Logical shift left variable
    // Encoding: LSLV_64_dp_2src
    // Template: LSLV  <Xd>, <Xn>, <Xm>
    struct Lslv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Lslv64Dp2src lslv64dp2src;

    // LSRV: Logical shift right (register)
    // Encoding: LSR_LSRV_32_dp_2src
    // Template: LSR  <Wd>, <Wn>, <Wm>
    struct LsrLsrv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    LsrLsrv32Dp2src lsr_lsrv32dp2src;

    // LSRV: Logical shift right (register)
    // Encoding: LSR_LSRV_64_dp_2src
    // Template: LSR  <Xd>, <Xn>, <Xm>
    struct LsrLsrv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    LsrLsrv64Dp2src lsr_lsrv64dp2src;

    // LSRV: Logical shift right variable
    // Encoding: LSRV_32_dp_2src
    // Template: LSRV  <Wd>, <Wn>, <Wm>
    struct Lsrv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Lsrv32Dp2src lsrv32dp2src;

    // LSRV: Logical shift right variable
    // Encoding: LSRV_64_dp_2src
    // Template: LSRV  <Xd>, <Xn>, <Xm>
    struct Lsrv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Lsrv64Dp2src lsrv64dp2src;

    // MADD: Multiply-add
    // Encoding: MADD_32A_dp_3src
    // Template: MADD  <Wd>, <Wn>, <Wm>, <Wa>
    struct Madd32aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Madd32aDp3src madd32a_dp3src;

    // MADD: Multiply-add
    // Encoding: MADD_64A_dp_3src
    // Template: MADD  <Xd>, <Xn>, <Xm>, <Xa>
    struct Madd64aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Madd64aDp3src madd64a_dp3src;

    // MADDPT: Multiply-add checked pointer
    // Encoding: MADDPT_64A_dp_3src
    // Template: MADDPT  <Xd>, <Xn>, <Xm>, <Xa>
    struct Maddpt64aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Maddpt64aDp3src maddpt64a_dp3src;

    // MSUB: Multiply-negate
    // Encoding: MNEG_MSUB_32A_dp_3src
    // Template: MNEG  <Wd>, <Wn>, <Wm>
    struct MnegMsub32aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MnegMsub32aDp3src mneg_msub32a_dp3src;

    // MSUB: Multiply-negate
    // Encoding: MNEG_MSUB_64A_dp_3src
    // Template: MNEG  <Xd>, <Xn>, <Xm>
    struct MnegMsub64aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MnegMsub64aDp3src mneg_msub64a_dp3src;

    // ORR: Move register value
    // Encoding: MOV_ORR_32_log_shift
    // Template: MOV  <Wd>, <Wm>
    struct MovOrr32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MovOrr32LogShift mov_orr32log_shift;

    // ORR: Move register value
    // Encoding: MOV_ORR_64_log_shift
    // Template: MOV  <Xd>, <Xm>
    struct MovOrr64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MovOrr64LogShift mov_orr64log_shift;

    // MSUB: Multiply-subtract
    // Encoding: MSUB_32A_dp_3src
    // Template: MSUB  <Wd>, <Wn>, <Wm>, <Wa>
    struct Msub32aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Msub32aDp3src msub32a_dp3src;

    // MSUB: Multiply-subtract
    // Encoding: MSUB_64A_dp_3src
    // Template: MSUB  <Xd>, <Xn>, <Xm>, <Xa>
    struct Msub64aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Msub64aDp3src msub64a_dp3src;

    // MSUBPT: Multiply-subtract checked pointer
    // Encoding: MSUBPT_64A_dp_3src
    // Template: MSUBPT  <Xd>, <Xn>, <Xm>, <Xa>
    struct Msubpt64aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Msubpt64aDp3src msubpt64a_dp3src;

    // MADD: Multiply
    // Encoding: MUL_MADD_32A_dp_3src
    // Template: MUL  <Wd>, <Wn>, <Wm>
    struct MulMadd32aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MulMadd32aDp3src mul_madd32a_dp3src;

    // MADD: Multiply
    // Encoding: MUL_MADD_64A_dp_3src
    // Template: MUL  <Xd>, <Xn>, <Xm>
    struct MulMadd64aDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t op31 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b11011 (0x1B)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MulMadd64aDp3src mul_madd64a_dp3src;

    // ORN: Bitwise NOT
    // Encoding: MVN_ORN_32_log_shift
    // Template: MVN  <Wd>, <Wm>{, <shift> #<amount>}
    struct MvnOrn32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    MvnOrn32LogShift mvn_orn32log_shift;

    // ORN: Bitwise NOT
    // Encoding: MVN_ORN_64_log_shift
    // Template: MVN  <Xd>, <Xm>{, <shift> #<amount>}
    struct MvnOrn64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    MvnOrn64LogShift mvn_orn64log_shift;

    // SUB: Negate (shifted register)
    // Encoding: NEG_SUB_32_addsub_shift
    // Template: NEG  <Wd>, <Wm>{, <shift> #<amount>}
    struct NegSub32AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    NegSub32AddsubShift neg_sub32addsub_shift;

    // SUB: Negate (shifted register)
    // Encoding: NEG_SUB_64_addsub_shift
    // Template: NEG  <Xd>, <Xm>{, <shift> #<amount>}
    struct NegSub64AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    NegSub64AddsubShift neg_sub64addsub_shift;

    // SUBS: Negate, setting flags
    // Encoding: NEGS_SUBS_32_addsub_shift
    // Template: NEGS  <Wd>, <Wm>{, <shift> #<amount>}
    struct NegsSubs32AddsubShift {
        uint32_t Rd : 5;  // partial: != 11111
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    NegsSubs32AddsubShift negs_subs32addsub_shift;

    // SUBS: Negate, setting flags
    // Encoding: NEGS_SUBS_64_addsub_shift
    // Template: NEGS  <Xd>, <Xm>{, <shift> #<amount>}
    struct NegsSubs64AddsubShift {
        uint32_t Rd : 5;  // partial: != 11111
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    NegsSubs64AddsubShift negs_subs64addsub_shift;

    // SBC: Negate with carry
    // Encoding: NGC_SBC_32_addsub_carry
    // Template: NGC  <Wd>, <Wm>
    struct NgcSbc32AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    NgcSbc32AddsubCarry ngc_sbc32addsub_carry;

    // SBC: Negate with carry
    // Encoding: NGC_SBC_64_addsub_carry
    // Template: NGC  <Xd>, <Xm>
    struct NgcSbc64AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    NgcSbc64AddsubCarry ngc_sbc64addsub_carry;

    // SBCS: Negate with carry, setting flags
    // Encoding: NGCS_SBCS_32_addsub_carry
    // Template: NGCS  <Wd>, <Wm>
    struct NgcsSbcs32AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    NgcsSbcs32AddsubCarry ngcs_sbcs32addsub_carry;

    // SBCS: Negate with carry, setting flags
    // Encoding: NGCS_SBCS_64_addsub_carry
    // Template: NGCS  <Xd>, <Xm>
    struct NgcsSbcs64AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    NgcsSbcs64AddsubCarry ngcs_sbcs64addsub_carry;

    // ORN: Bitwise OR NOT (shifted register)
    // Encoding: ORN_32_log_shift
    // Template: ORN  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Orn32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Orn32LogShift orn32log_shift;

    // ORN: Bitwise OR NOT (shifted register)
    // Encoding: ORN_64_log_shift
    // Template: ORN  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Orn64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b1 (0x1)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Orn64LogShift orn64log_shift;

    // ORR: Bitwise OR (shifted register)
    // Encoding: ORR_32_log_shift
    // Template: ORR  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Orr32LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Orr32LogShift orr32log_shift;

    // ORR: Bitwise OR (shifted register)
    // Encoding: ORR_64_log_shift
    // Template: ORR  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Orr64LogShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Orr64LogShift orr64log_shift;

    // : Pointer Authentication Code for data address, using key A
    // Encoding: PACDA_64P_dp_1src
    // Template: PACDA  <Xd>, <Xn|SP>
    struct Pacda64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b010 (0x2)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacda64pDp1src pacda64p_dp1src;

    // : Pointer Authentication Code for data address, using key A
    // Encoding: PACDZA_64Z_dp_1src
    // Template: PACDZA  <Xd>
    struct Pacdza64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b010 (0x2)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacdza64zDp1src pacdza64z_dp1src;

    // : Pointer Authentication Code for data address, using key B
    // Encoding: PACDB_64P_dp_1src
    // Template: PACDB  <Xd>, <Xn|SP>
    struct Pacdb64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b011 (0x3)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacdb64pDp1src pacdb64p_dp1src;

    // : Pointer Authentication Code for data address, using key B
    // Encoding: PACDZB_64Z_dp_1src
    // Template: PACDZB  <Xd>
    struct Pacdzb64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b011 (0x3)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacdzb64zDp1src pacdzb64z_dp1src;

    // PACGA: Pointer Authentication Code, using generic key
    // Encoding: PACGA_64P_dp_2src
    // Template: PACGA  <Xd>, <Xn>, <Xm|SP>
    struct Pacga64pDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b001100 (0xC)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacga64pDp2src pacga64p_dp2src;

    // : Pointer Authentication Code for instruction address, using key A
    // Encoding: PACIA_64P_dp_1src
    // Template: PACIA  <Xd>, <Xn|SP>
    struct Pacia64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b000 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacia64pDp1src pacia64p_dp1src;

    // : Pointer Authentication Code for instruction address, using key A
    // Encoding: PACIZA_64Z_dp_1src
    // Template: PACIZA  <Xd>
    struct Paciza64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b000 (0x0)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Paciza64zDp1src paciza64z_dp1src;

    // PACIA171615: Pointer Authentication Code for instruction address, using key A
    // Encoding: PACIA171615_64LR_dp_1src
    // Template: PACIA171615
    struct Pacia17161564lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b100010 (0x22)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacia17161564lrDp1src pacia17161564lr_dp1src;

    // PACIASPPC: Pointer Authentication Code for return address, using key A
    // Encoding: PACIASPPC_64LR_dp_1src
    // Template: PACIASPPC
    struct Paciasppc64lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b101000 (0x28)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Paciasppc64lrDp1src paciasppc64lr_dp1src;

    // : Pointer Authentication Code for instruction address, using key B
    // Encoding: PACIB_64P_dp_1src
    // Template: PACIB  <Xd>, <Xn|SP>
    struct Pacib64pDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacib64pDp1src pacib64p_dp1src;

    // : Pointer Authentication Code for instruction address, using key B
    // Encoding: PACIZB_64Z_dp_1src
    // Template: PACIZB  <Xd>
    struct Pacizb64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacizb64zDp1src pacizb64z_dp1src;

    // PACIB171615: Pointer Authentication Code for instruction address, using key B
    // Encoding: PACIB171615_64LR_dp_1src
    // Template: PACIB171615
    struct Pacib17161564lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b100011 (0x23)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacib17161564lrDp1src pacib17161564lr_dp1src;

    // PACIBSPPC: Pointer Authentication Code for return address, using key B
    // Encoding: PACIBSPPC_64LR_dp_1src
    // Template: PACIBSPPC
    struct Pacibsppc64lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b101001 (0x29)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacibsppc64lrDp1src pacibsppc64lr_dp1src;

    // PACNBIASPPC: Pointer Authentication Code for return address, using key A, not a branch target
    // Encoding: PACNBIASPPC_64LR_dp_1src
    // Template: PACNBIASPPC
    struct Pacnbiasppc64lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b100000 (0x20)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacnbiasppc64lrDp1src pacnbiasppc64lr_dp1src;

    // PACNBIBSPPC: Pointer Authentication Code for return address, using key B, not a branch target
    // Encoding: PACNBIBSPPC_64LR_dp_1src
    // Template: PACNBIBSPPC
    struct Pacnbibsppc64lrDp1src {
        uint32_t Rd : 5;  // fixed: 0b11110 (0x1E)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opcode : 6;  // fixed: 0b100001 (0x21)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Pacnbibsppc64lrDp1src pacnbibsppc64lr_dp1src;

    // RBIT: Reverse bits
    // Encoding: RBIT_32_dp_1src
    // Template: RBIT  <Wd>, <Wn>
    struct Rbit32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Rbit32Dp1src rbit32dp1src;

    // RBIT: Reverse bits
    // Encoding: RBIT_64_dp_1src
    // Template: RBIT  <Xd>, <Xn>
    struct Rbit64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Rbit64Dp1src rbit64dp1src;

    // REV: Reverse bytes
    // Encoding: REV_32_dp_1src
    // Template: REV  <Wd>, <Wn>
    struct Rev32Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Rev32Dp1src rev32dp1src;

    // REV: Reverse bytes
    // Encoding: REV_64_dp_1src
    // Template: REV  <Xd>, <Xn>
    struct Rev64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Rev64Dp1src rev64dp1src;

    // REV16: Reverse bytes in 16-bit halfwords
    // Encoding: REV16_32_dp_1src
    // Template: REV16  <Wd>, <Wn>
    struct Rev1632Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Rev1632Dp1src rev1632dp1src;

    // REV16: Reverse bytes in 16-bit halfwords
    // Encoding: REV16_64_dp_1src
    // Template: REV16  <Xd>, <Xn>
    struct Rev1664Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Rev1664Dp1src rev1664dp1src;

    // REV32: Reverse bytes in 32-bit words
    // Encoding: REV32_64_dp_1src
    // Template: REV32  <Xd>, <Xn>
    struct Rev3264Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_4 : 4;  // fixed: 0b0000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Rev3264Dp1src rev3264dp1src;

    // REV: Reverse bytes
    // Encoding: REV64_REV_64_dp_1src
    // Template: REV64  <Xd>, <Xn>
    struct Rev64Rev64Dp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_4 : 4;  // fixed: 0b0000 (0x0)
        uint32_t opcode2 : 5;  // fixed: 0b00000 (0x0)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Rev64Rev64Dp1src rev64rev64dp1src;

    // RMIF: Rotate, mask insert flags
    // Encoding: RMIF_only_rmif
    // Template: RMIF  <Xn>, #<shift>, #<mask>
    struct RmifOnlyRmif {
        uint32_t mask : 4;
        uint32_t o2 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t _unnamed_3 : 5;  // fixed: 0b00001 (0x1)
        uint32_t imm6 : 6;
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    RmifOnlyRmif rmif_only_rmif;

    // RORV: Rotate right (register)
    // Encoding: ROR_RORV_32_dp_2src
    // Template: ROR  <Wd>, <Wn>, <Wm>
    struct RorRorv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    RorRorv32Dp2src ror_rorv32dp2src;

    // RORV: Rotate right (register)
    // Encoding: ROR_RORV_64_dp_2src
    // Template: ROR  <Xd>, <Xn>, <Xm>
    struct RorRorv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    RorRorv64Dp2src ror_rorv64dp2src;

    // RORV: Rotate right variable
    // Encoding: RORV_32_dp_2src
    // Template: RORV  <Wd>, <Wn>, <Wm>
    struct Rorv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Rorv32Dp2src rorv32dp2src;

    // RORV: Rotate right variable
    // Encoding: RORV_64_dp_2src
    // Template: RORV  <Xd>, <Xn>, <Xm>
    struct Rorv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t op2 : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0010 (0x2)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Rorv64Dp2src rorv64dp2src;

    // SBC: Subtract with carry
    // Encoding: SBC_32_addsub_carry
    // Template: SBC  <Wd>, <Wn>, <Wm>
    struct Sbc32AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sbc32AddsubCarry sbc32addsub_carry;

    // SBC: Subtract with carry
    // Encoding: SBC_64_addsub_carry
    // Template: SBC  <Xd>, <Xn>, <Xm>
    struct Sbc64AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sbc64AddsubCarry sbc64addsub_carry;

    // SBCS: Subtract with carry, setting flags
    // Encoding: SBCS_32_addsub_carry
    // Template: SBCS  <Wd>, <Wn>, <Wm>
    struct Sbcs32AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sbcs32AddsubCarry sbcs32addsub_carry;

    // SBCS: Subtract with carry, setting flags
    // Encoding: SBCS_64_addsub_carry
    // Template: SBCS  <Xd>, <Xn>, <Xm>
    struct Sbcs64AddsubCarry {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sbcs64AddsubCarry sbcs64addsub_carry;

    // SDIV: Signed divide
    // Encoding: SDIV_32_dp_2src
    // Template: SDIV  <Wd>, <Wn>, <Wm>
    struct Sdiv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o1 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sdiv32Dp2src sdiv32dp2src;

    // SDIV: Signed divide
    // Encoding: SDIV_64_dp_2src
    // Template: SDIV  <Xd>, <Xn>, <Xm>
    struct Sdiv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o1 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sdiv64Dp2src sdiv64dp2src;

    // : Evaluation of 8-bit or 16-bit flag values
    // Encoding: SETF8_only_setf
    // Template: SETF8  <Wn>
    struct Setf8OnlySetf {
        uint32_t mask : 4;  // fixed: 0b1101 (0xD)
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
        uint32_t sz : 1;  // fixed: 0b0 (0x0)
        uint32_t opcode2 : 6;  // fixed: 0b000000 (0x0)
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Setf8OnlySetf setf8only_setf;

    // : Evaluation of 8-bit or 16-bit flag values
    // Encoding: SETF16_only_setf
    // Template: SETF16  <Wn>
    struct Setf16OnlySetf {
        uint32_t mask : 4;  // fixed: 0b1101 (0xD)
        uint32_t o3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rn : 5;
        uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
        uint32_t sz : 1;  // fixed: 0b1 (0x1)
        uint32_t opcode2 : 6;  // fixed: 0b000000 (0x0)
        uint32_t _unnamed_0 : 8;  // fixed: 0b11010000 (0xD0)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Setf16OnlySetf setf16only_setf;

    // SMADDL: Signed multiply-add long
    // Encoding: SMADDL_64WA_dp_3src
    // Template: SMADDL  <Xd>, <Wn>, <Wm>, <Xa>
    struct Smaddl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smaddl64waDp3src smaddl64wa_dp3src;

    // SMAX: Signed maximum (register)
    // Encoding: SMAX_32_dp_2src
    // Template: SMAX  <Wd>, <Wn>, <Wm>
    struct Smax32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011000 (0x18)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Smax32Dp2src smax32dp2src;

    // SMAX: Signed maximum (register)
    // Encoding: SMAX_64_dp_2src
    // Template: SMAX  <Xd>, <Xn>, <Xm>
    struct Smax64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011000 (0x18)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smax64Dp2src smax64dp2src;

    // SMIN: Signed minimum (register)
    // Encoding: SMIN_32_dp_2src
    // Template: SMIN  <Wd>, <Wn>, <Wm>
    struct Smin32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011010 (0x1A)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Smin32Dp2src smin32dp2src;

    // SMIN: Signed minimum (register)
    // Encoding: SMIN_64_dp_2src
    // Template: SMIN  <Xd>, <Xn>, <Xm>
    struct Smin64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011010 (0x1A)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smin64Dp2src smin64dp2src;

    // SMSUBL: Signed multiply-negate long
    // Encoding: SMNEGL_SMSUBL_64WA_dp_3src
    // Template: SMNEGL  <Xd>, <Wn>, <Wm>
    struct SmneglSmsubl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SmneglSmsubl64waDp3src smnegl_smsubl64wa_dp3src;

    // SMSUBL: Signed multiply-subtract long
    // Encoding: SMSUBL_64WA_dp_3src
    // Template: SMSUBL  <Xd>, <Wn>, <Wm>, <Xa>
    struct Smsubl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smsubl64waDp3src smsubl64wa_dp3src;

    // SMULH: Signed multiply high
    // Encoding: SMULH_64_dp_3src
    // Template: SMULH  <Xd>, <Xn>, <Xm>
    struct Smulh64Dp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
        uint32_t U : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Smulh64Dp3src smulh64dp3src;

    // SMADDL: Signed multiply long
    // Encoding: SMULL_SMADDL_64WA_dp_3src
    // Template: SMULL  <Xd>, <Wn>, <Wm>
    struct SmullSmaddl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    SmullSmaddl64waDp3src smull_smaddl64wa_dp3src;

    // SUB: Subtract extended and scaled register
    // Encoding: SUB_32_addsub_ext
    // Template: SUB  <Wd|WSP>, <Wn|WSP>, <Wm>{, <extend> {#<amount>}}
    struct Sub32AddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sub32AddsubExt sub32addsub_ext;

    // SUB: Subtract extended and scaled register
    // Encoding: SUB_64_addsub_ext
    // Template: SUB  <Xd|SP>, <Xn|SP>, <R><m>{, <extend> {#<amount>}}
    struct Sub64AddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sub64AddsubExt sub64addsub_ext;

    // SUB: Subtract optionally-shifted register
    // Encoding: SUB_32_addsub_shift
    // Template: SUB  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Sub32AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Sub32AddsubShift sub32addsub_shift;

    // SUB: Subtract optionally-shifted register
    // Encoding: SUB_64_addsub_shift
    // Template: SUB  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Sub64AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Sub64AddsubShift sub64addsub_shift;

    // SUBP: Subtract pointer
    // Encoding: SUBP_64S_dp_2src
    // Template: SUBP  <Xd>, <Xn|SP>, <Xm|SP>
    struct Subp64sDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subp64sDp2src subp64s_dp2src;

    // SUBPS: Subtract pointer, setting flags
    // Encoding: SUBPS_64S_dp_2src
    // Template: SUBPS  <Xd>, <Xn|SP>, <Xm|SP>
    struct Subps64sDp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b000000 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subps64sDp2src subps64s_dp2src;

    // SUBPT: Subtract checked pointer
    // Encoding: SUBPT_64_addsub_pt
    // Template: SUBPT  <Xd|SP>, <Xn|SP>, <Xm>{, LSL #<amount>}
    struct Subpt64AddsubPt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subpt64AddsubPt subpt64addsub_pt;

    // SUBS: Subtract extended and scaled register, setting flags
    // Encoding: SUBS_32S_addsub_ext
    // Template: SUBS  <Wd>, <Wn|WSP>, <Wm>{, <extend> {#<amount>}}
    struct Subs32sAddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Subs32sAddsubExt subs32s_addsub_ext;

    // SUBS: Subtract extended and scaled register, setting flags
    // Encoding: SUBS_64S_addsub_ext
    // Template: SUBS  <Xd>, <Xn|SP>, <R><m>{, <extend> {#<amount>}}
    struct Subs64sAddsubExt {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm3 : 3;
        uint32_t option : 3;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t opt : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subs64sAddsubExt subs64s_addsub_ext;

    // SUBS: Subtract optionally-shifted register, setting flags
    // Encoding: SUBS_32_addsub_shift
    // Template: SUBS  <Wd>, <Wn>, <Wm>{, <shift> #<amount>}
    struct Subs32AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Subs32AddsubShift subs32addsub_shift;

    // SUBS: Subtract optionally-shifted register, setting flags
    // Encoding: SUBS_64_addsub_shift
    // Template: SUBS  <Xd>, <Xn>, <Xm>{, <shift> #<amount>}
    struct Subs64AddsubShift {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01011 (0xB)
        uint32_t S : 1;  // fixed: 0b1 (0x1)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Subs64AddsubShift subs64addsub_shift;

    // ANDS: Test (shifted register)
    // Encoding: TST_ANDS_32_log_shift
    // Template: TST  <Wn>, <Wm>{, <shift> #<amount>}
    struct TstAnds32LogShift {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    TstAnds32LogShift tst_ands32log_shift;

    // ANDS: Test (shifted register)
    // Encoding: TST_ANDS_64_log_shift
    // Template: TST  <Xn>, <Xm>{, <shift> #<amount>}
    struct TstAnds64LogShift {
        uint32_t Rd : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t imm6 : 6;
        uint32_t Rm : 5;
        uint32_t N : 1;  // fixed: 0b0 (0x0)
        uint32_t shift : 2;
        uint32_t _unnamed_0 : 5;  // fixed: 0b01010 (0xA)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    TstAnds64LogShift tst_ands64log_shift;

    // UDIV: Unsigned divide
    // Encoding: UDIV_32_dp_2src
    // Template: UDIV  <Wd>, <Wn>, <Wm>
    struct Udiv32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o1 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Udiv32Dp2src udiv32dp2src;

    // UDIV: Unsigned divide
    // Encoding: UDIV_64_dp_2src
    // Template: UDIV  <Xd>, <Xn>, <Xm>
    struct Udiv64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t o1 : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Udiv64Dp2src udiv64dp2src;

    // UMADDL: Unsigned multiply-add long
    // Encoding: UMADDL_64WA_dp_3src
    // Template: UMADDL  <Xd>, <Wn>, <Wm>, <Xa>
    struct Umaddl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umaddl64waDp3src umaddl64wa_dp3src;

    // UMAX: Unsigned maximum (register)
    // Encoding: UMAX_32_dp_2src
    // Template: UMAX  <Wd>, <Wn>, <Wm>
    struct Umax32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011001 (0x19)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Umax32Dp2src umax32dp2src;

    // UMAX: Unsigned maximum (register)
    // Encoding: UMAX_64_dp_2src
    // Template: UMAX  <Xd>, <Xn>, <Xm>
    struct Umax64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011001 (0x19)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umax64Dp2src umax64dp2src;

    // UMIN: Unsigned minimum (register)
    // Encoding: UMIN_32_dp_2src
    // Template: UMIN  <Wd>, <Wn>, <Wm>
    struct Umin32Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011011 (0x1B)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Umin32Dp2src umin32dp2src;

    // UMIN: Unsigned minimum (register)
    // Encoding: UMIN_64_dp_2src
    // Template: UMIN  <Xd>, <Xn>, <Xm>
    struct Umin64Dp2src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t opcode : 6;  // fixed: 0b011011 (0x1B)
        uint32_t Rm : 5;
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umin64Dp2src umin64dp2src;

    // UMSUBL: Unsigned multiply-negate long
    // Encoding: UMNEGL_UMSUBL_64WA_dp_3src
    // Template: UMNEGL  <Xd>, <Wn>, <Wm>
    struct UmneglUmsubl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    UmneglUmsubl64waDp3src umnegl_umsubl64wa_dp3src;

    // UMSUBL: Unsigned multiply-subtract long
    // Encoding: UMSUBL_64WA_dp_3src
    // Template: UMSUBL  <Xd>, <Wn>, <Wm>, <Xa>
    struct Umsubl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umsubl64waDp3src umsubl64wa_dp3src;

    // UMULH: Unsigned multiply high
    // Encoding: UMULH_64_dp_3src
    // Template: UMULH  <Xd>, <Xn>, <Xm>
    struct Umulh64Dp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
        uint32_t U : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Umulh64Dp3src umulh64dp3src;

    // UMADDL: Unsigned multiply long
    // Encoding: UMULL_UMADDL_64WA_dp_3src
    // Template: UMULL  <Xd>, <Wn>, <Wm>
    struct UmullUmaddl64waDp3src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;
        uint32_t Ra : 5;  // fixed: 0b11111 (0x1F)
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        uint32_t Rm : 5;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t U : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t op54 : 2;  // fixed: 0b00 (0x0)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    UmullUmaddl64waDp3src umull_umaddl64wa_dp3src;

    // : Strip Pointer Authentication Code
    // Encoding: XPACD_64Z_dp_1src
    // Template: XPACD  <Xd>
    struct Xpacd64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t D : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 5;  // fixed: 0b01000 (0x8)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Xpacd64zDp1src xpacd64z_dp1src;

    // : Strip Pointer Authentication Code
    // Encoding: XPACI_64Z_dp_1src
    // Template: XPACI  <Xd>
    struct Xpaci64zDp1src {
        uint32_t Rd : 5;
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t D : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 5;  // fixed: 0b01000 (0x8)
        uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
        uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
        uint32_t S : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Xpaci64zDp1src xpaci64z_dp1src;

};
static_assert(sizeof(DpregEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_abs_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.abs32dp1src.Rd = Rd;
    insn.abs32dp1src.Rn = Rn;
    insn.abs32dp1src.opcode = 0b001000;
    insn.abs32dp1src.opcode2 = 0b00000;
    insn.abs32dp1src._unnamed_1 = 0b11010110;
    insn.abs32dp1src.S = 0b0;
    insn.abs32dp1src._unnamed_0 = 0b1;
    insn.abs32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_abs_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.abs64dp1src.Rd = Rd;
    insn.abs64dp1src.Rn = Rn;
    insn.abs64dp1src.opcode = 0b001000;
    insn.abs64dp1src.opcode2 = 0b00000;
    insn.abs64dp1src._unnamed_1 = 0b11010110;
    insn.abs64dp1src.S = 0b0;
    insn.abs64dp1src._unnamed_0 = 0b1;
    insn.abs64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_adc_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.adc32addsub_carry.Rd = Rd;
    insn.adc32addsub_carry.Rn = Rn;
    insn.adc32addsub_carry._unnamed_1 = 0b000000;
    insn.adc32addsub_carry.Rm = Rm;
    insn.adc32addsub_carry._unnamed_0 = 0b11010000;
    insn.adc32addsub_carry.S = 0b0;
    insn.adc32addsub_carry.op = 0b0;
    insn.adc32addsub_carry.sf = 0b0;
    return insn.raw;
}

uint32_t encode_adc_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.adc64addsub_carry.Rd = Rd;
    insn.adc64addsub_carry.Rn = Rn;
    insn.adc64addsub_carry._unnamed_1 = 0b000000;
    insn.adc64addsub_carry.Rm = Rm;
    insn.adc64addsub_carry._unnamed_0 = 0b11010000;
    insn.adc64addsub_carry.S = 0b0;
    insn.adc64addsub_carry.op = 0b0;
    insn.adc64addsub_carry.sf = 0b1;
    return insn.raw;
}

uint32_t encode_adcs_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.adcs32addsub_carry.Rd = Rd;
    insn.adcs32addsub_carry.Rn = Rn;
    insn.adcs32addsub_carry._unnamed_1 = 0b000000;
    insn.adcs32addsub_carry.Rm = Rm;
    insn.adcs32addsub_carry._unnamed_0 = 0b11010000;
    insn.adcs32addsub_carry.S = 0b1;
    insn.adcs32addsub_carry.op = 0b0;
    insn.adcs32addsub_carry.sf = 0b0;
    return insn.raw;
}

uint32_t encode_adcs_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.adcs64addsub_carry.Rd = Rd;
    insn.adcs64addsub_carry.Rn = Rn;
    insn.adcs64addsub_carry._unnamed_1 = 0b000000;
    insn.adcs64addsub_carry.Rm = Rm;
    insn.adcs64addsub_carry._unnamed_0 = 0b11010000;
    insn.adcs64addsub_carry.S = 0b1;
    insn.adcs64addsub_carry.op = 0b0;
    insn.adcs64addsub_carry.sf = 0b1;
    return insn.raw;
}

uint32_t encode_add_32_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.add32addsub_ext.Rd = Rd;
    insn.add32addsub_ext.Rn = Rn;
    insn.add32addsub_ext.imm3 = imm3;
    insn.add32addsub_ext.option = option;
    insn.add32addsub_ext.Rm = Rm;
    insn.add32addsub_ext._unnamed_1 = 0b1;
    insn.add32addsub_ext.opt = 0b00;
    insn.add32addsub_ext._unnamed_0 = 0b01011;
    insn.add32addsub_ext.S = 0b0;
    insn.add32addsub_ext.op = 0b0;
    insn.add32addsub_ext.sf = 0b0;
    return insn.raw;
}

uint32_t encode_add_64_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.add64addsub_ext.Rd = Rd;
    insn.add64addsub_ext.Rn = Rn;
    insn.add64addsub_ext.imm3 = imm3;
    insn.add64addsub_ext.option = option;
    insn.add64addsub_ext.Rm = Rm;
    insn.add64addsub_ext._unnamed_1 = 0b1;
    insn.add64addsub_ext.opt = 0b00;
    insn.add64addsub_ext._unnamed_0 = 0b01011;
    insn.add64addsub_ext.S = 0b0;
    insn.add64addsub_ext.op = 0b0;
    insn.add64addsub_ext.sf = 0b1;
    return insn.raw;
}

uint32_t encode_add_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.add32addsub_shift.Rd = Rd;
    insn.add32addsub_shift.Rn = Rn;
    insn.add32addsub_shift.imm6 = imm6;
    insn.add32addsub_shift.Rm = Rm;
    insn.add32addsub_shift._unnamed_1 = 0b0;
    insn.add32addsub_shift.shift = shift;
    insn.add32addsub_shift._unnamed_0 = 0b01011;
    insn.add32addsub_shift.S = 0b0;
    insn.add32addsub_shift.op = 0b0;
    insn.add32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_add_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.add64addsub_shift.Rd = Rd;
    insn.add64addsub_shift.Rn = Rn;
    insn.add64addsub_shift.imm6 = imm6;
    insn.add64addsub_shift.Rm = Rm;
    insn.add64addsub_shift._unnamed_1 = 0b0;
    insn.add64addsub_shift.shift = shift;
    insn.add64addsub_shift._unnamed_0 = 0b01011;
    insn.add64addsub_shift.S = 0b0;
    insn.add64addsub_shift.op = 0b0;
    insn.add64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_addpt_64_addsub_pt(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.addpt64addsub_pt.Rd = Rd;
    insn.addpt64addsub_pt.Rn = Rn;
    insn.addpt64addsub_pt.imm3 = imm3;
    insn.addpt64addsub_pt._unnamed_3 = 0b001;
    insn.addpt64addsub_pt.Rm = Rm;
    insn.addpt64addsub_pt._unnamed_2 = 0b0000;
    insn.addpt64addsub_pt._unnamed_1 = 0b101;
    insn.addpt64addsub_pt._unnamed_0 = 0b1;
    insn.addpt64addsub_pt.S = 0b0;
    insn.addpt64addsub_pt.op = 0b0;
    insn.addpt64addsub_pt.sf = 0b1;
    return insn.raw;
}

uint32_t encode_adds_32s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.adds32s_addsub_ext.Rd = Rd;
    insn.adds32s_addsub_ext.Rn = Rn;
    insn.adds32s_addsub_ext.imm3 = imm3;
    insn.adds32s_addsub_ext.option = option;
    insn.adds32s_addsub_ext.Rm = Rm;
    insn.adds32s_addsub_ext._unnamed_1 = 0b1;
    insn.adds32s_addsub_ext.opt = 0b00;
    insn.adds32s_addsub_ext._unnamed_0 = 0b01011;
    insn.adds32s_addsub_ext.S = 0b1;
    insn.adds32s_addsub_ext.op = 0b0;
    insn.adds32s_addsub_ext.sf = 0b0;
    return insn.raw;
}

uint32_t encode_adds_64s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.adds64s_addsub_ext.Rd = Rd;
    insn.adds64s_addsub_ext.Rn = Rn;
    insn.adds64s_addsub_ext.imm3 = imm3;
    insn.adds64s_addsub_ext.option = option;
    insn.adds64s_addsub_ext.Rm = Rm;
    insn.adds64s_addsub_ext._unnamed_1 = 0b1;
    insn.adds64s_addsub_ext.opt = 0b00;
    insn.adds64s_addsub_ext._unnamed_0 = 0b01011;
    insn.adds64s_addsub_ext.S = 0b1;
    insn.adds64s_addsub_ext.op = 0b0;
    insn.adds64s_addsub_ext.sf = 0b1;
    return insn.raw;
}

uint32_t encode_adds_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.adds32addsub_shift.Rd = Rd;
    insn.adds32addsub_shift.Rn = Rn;
    insn.adds32addsub_shift.imm6 = imm6;
    insn.adds32addsub_shift.Rm = Rm;
    insn.adds32addsub_shift._unnamed_1 = 0b0;
    insn.adds32addsub_shift.shift = shift;
    insn.adds32addsub_shift._unnamed_0 = 0b01011;
    insn.adds32addsub_shift.S = 0b1;
    insn.adds32addsub_shift.op = 0b0;
    insn.adds32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_adds_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.adds64addsub_shift.Rd = Rd;
    insn.adds64addsub_shift.Rn = Rn;
    insn.adds64addsub_shift.imm6 = imm6;
    insn.adds64addsub_shift.Rm = Rm;
    insn.adds64addsub_shift._unnamed_1 = 0b0;
    insn.adds64addsub_shift.shift = shift;
    insn.adds64addsub_shift._unnamed_0 = 0b01011;
    insn.adds64addsub_shift.S = 0b1;
    insn.adds64addsub_shift.op = 0b0;
    insn.adds64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_and_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.and32log_shift.Rd = Rd;
    insn.and32log_shift.Rn = Rn;
    insn.and32log_shift.imm6 = imm6;
    insn.and32log_shift.Rm = Rm;
    insn.and32log_shift.N = 0b0;
    insn.and32log_shift.shift = shift;
    insn.and32log_shift._unnamed_0 = 0b01010;
    insn.and32log_shift.opc = 0b00;
    insn.and32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_and_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.and64log_shift.Rd = Rd;
    insn.and64log_shift.Rn = Rn;
    insn.and64log_shift.imm6 = imm6;
    insn.and64log_shift.Rm = Rm;
    insn.and64log_shift.N = 0b0;
    insn.and64log_shift.shift = shift;
    insn.and64log_shift._unnamed_0 = 0b01010;
    insn.and64log_shift.opc = 0b00;
    insn.and64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ands_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.ands32log_shift.Rd = Rd;
    insn.ands32log_shift.Rn = Rn;
    insn.ands32log_shift.imm6 = imm6;
    insn.ands32log_shift.Rm = Rm;
    insn.ands32log_shift.N = 0b0;
    insn.ands32log_shift.shift = shift;
    insn.ands32log_shift._unnamed_0 = 0b01010;
    insn.ands32log_shift.opc = 0b11;
    insn.ands32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ands_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.ands64log_shift.Rd = Rd;
    insn.ands64log_shift.Rn = Rn;
    insn.ands64log_shift.imm6 = imm6;
    insn.ands64log_shift.Rm = Rm;
    insn.ands64log_shift.N = 0b0;
    insn.ands64log_shift.shift = shift;
    insn.ands64log_shift._unnamed_0 = 0b01010;
    insn.ands64log_shift.opc = 0b11;
    insn.ands64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_asr_asrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.asr_asrv32dp2src.Rd = Rd;
    insn.asr_asrv32dp2src.Rn = Rn;
    insn.asr_asrv32dp2src.op2 = 0b10;
    insn.asr_asrv32dp2src._unnamed_2 = 0b0010;
    insn.asr_asrv32dp2src.Rm = Rm;
    insn.asr_asrv32dp2src._unnamed_1 = 0b11010110;
    insn.asr_asrv32dp2src.S = 0b0;
    insn.asr_asrv32dp2src._unnamed_0 = 0b0;
    insn.asr_asrv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_asr_asrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.asr_asrv64dp2src.Rd = Rd;
    insn.asr_asrv64dp2src.Rn = Rn;
    insn.asr_asrv64dp2src.op2 = 0b10;
    insn.asr_asrv64dp2src._unnamed_2 = 0b0010;
    insn.asr_asrv64dp2src.Rm = Rm;
    insn.asr_asrv64dp2src._unnamed_1 = 0b11010110;
    insn.asr_asrv64dp2src.S = 0b0;
    insn.asr_asrv64dp2src._unnamed_0 = 0b0;
    insn.asr_asrv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_asrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.asrv32dp2src.Rd = Rd;
    insn.asrv32dp2src.Rn = Rn;
    insn.asrv32dp2src.op2 = 0b10;
    insn.asrv32dp2src._unnamed_2 = 0b0010;
    insn.asrv32dp2src.Rm = Rm;
    insn.asrv32dp2src._unnamed_1 = 0b11010110;
    insn.asrv32dp2src.S = 0b0;
    insn.asrv32dp2src._unnamed_0 = 0b0;
    insn.asrv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_asrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.asrv64dp2src.Rd = Rd;
    insn.asrv64dp2src.Rn = Rn;
    insn.asrv64dp2src.op2 = 0b10;
    insn.asrv64dp2src._unnamed_2 = 0b0010;
    insn.asrv64dp2src.Rm = Rm;
    insn.asrv64dp2src._unnamed_1 = 0b11010110;
    insn.asrv64dp2src.S = 0b0;
    insn.asrv64dp2src._unnamed_0 = 0b0;
    insn.asrv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autda_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.autda64p_dp1src.Rd = Rd;
    insn.autda64p_dp1src.Rn = Rn;
    insn.autda64p_dp1src._unnamed_3 = 0b110;
    insn.autda64p_dp1src.Z = 0b0;
    insn.autda64p_dp1src._unnamed_2 = 0b00;
    insn.autda64p_dp1src.opcode2 = 0b00001;
    insn.autda64p_dp1src._unnamed_1 = 0b11010110;
    insn.autda64p_dp1src.S = 0b0;
    insn.autda64p_dp1src._unnamed_0 = 0b1;
    insn.autda64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autdza_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.autdza64z_dp1src.Rd = Rd;
    insn.autdza64z_dp1src.Rn = 0b11111;
    insn.autdza64z_dp1src._unnamed_3 = 0b110;
    insn.autdza64z_dp1src.Z = 0b1;
    insn.autdza64z_dp1src._unnamed_2 = 0b00;
    insn.autdza64z_dp1src.opcode2 = 0b00001;
    insn.autdza64z_dp1src._unnamed_1 = 0b11010110;
    insn.autdza64z_dp1src.S = 0b0;
    insn.autdza64z_dp1src._unnamed_0 = 0b1;
    insn.autdza64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autdb_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.autdb64p_dp1src.Rd = Rd;
    insn.autdb64p_dp1src.Rn = Rn;
    insn.autdb64p_dp1src._unnamed_3 = 0b111;
    insn.autdb64p_dp1src.Z = 0b0;
    insn.autdb64p_dp1src._unnamed_2 = 0b00;
    insn.autdb64p_dp1src.opcode2 = 0b00001;
    insn.autdb64p_dp1src._unnamed_1 = 0b11010110;
    insn.autdb64p_dp1src.S = 0b0;
    insn.autdb64p_dp1src._unnamed_0 = 0b1;
    insn.autdb64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autdzb_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.autdzb64z_dp1src.Rd = Rd;
    insn.autdzb64z_dp1src.Rn = 0b11111;
    insn.autdzb64z_dp1src._unnamed_3 = 0b111;
    insn.autdzb64z_dp1src.Z = 0b1;
    insn.autdzb64z_dp1src._unnamed_2 = 0b00;
    insn.autdzb64z_dp1src.opcode2 = 0b00001;
    insn.autdzb64z_dp1src._unnamed_1 = 0b11010110;
    insn.autdzb64z_dp1src.S = 0b0;
    insn.autdzb64z_dp1src._unnamed_0 = 0b1;
    insn.autdzb64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autia_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.autia64p_dp1src.Rd = Rd;
    insn.autia64p_dp1src.Rn = Rn;
    insn.autia64p_dp1src._unnamed_3 = 0b100;
    insn.autia64p_dp1src.Z = 0b0;
    insn.autia64p_dp1src._unnamed_2 = 0b00;
    insn.autia64p_dp1src.opcode2 = 0b00001;
    insn.autia64p_dp1src._unnamed_1 = 0b11010110;
    insn.autia64p_dp1src.S = 0b0;
    insn.autia64p_dp1src._unnamed_0 = 0b1;
    insn.autia64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autiza_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.autiza64z_dp1src.Rd = Rd;
    insn.autiza64z_dp1src.Rn = 0b11111;
    insn.autiza64z_dp1src._unnamed_3 = 0b100;
    insn.autiza64z_dp1src.Z = 0b1;
    insn.autiza64z_dp1src._unnamed_2 = 0b00;
    insn.autiza64z_dp1src.opcode2 = 0b00001;
    insn.autiza64z_dp1src._unnamed_1 = 0b11010110;
    insn.autiza64z_dp1src.S = 0b0;
    insn.autiza64z_dp1src._unnamed_0 = 0b1;
    insn.autiza64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autia171615_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.autia17161564lr_dp1src.Rd = 0b11110;
    insn.autia17161564lr_dp1src.Rn = 0b11111;
    insn.autia17161564lr_dp1src.opcode = 0b101110;
    insn.autia17161564lr_dp1src.opcode2 = 0b00001;
    insn.autia17161564lr_dp1src._unnamed_3 = 0b0110;
    insn.autia17161564lr_dp1src._unnamed_2 = 0b101;
    insn.autia17161564lr_dp1src._unnamed_1 = 0b1;
    insn.autia17161564lr_dp1src.S = 0b0;
    insn.autia17161564lr_dp1src._unnamed_0 = 0b1;
    insn.autia17161564lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autiasppcr_64lrr_dp_1src(uint32_t Rn) {
    DpregEncoding insn = {};
    insn.autiasppcr64lrr_dp1src.Rd = 0b11110;
    insn.autiasppcr64lrr_dp1src.Rn = Rn;
    insn.autiasppcr64lrr_dp1src.opcode = 0b100100;
    insn.autiasppcr64lrr_dp1src.opcode2 = 0b00001;
    insn.autiasppcr64lrr_dp1src._unnamed_3 = 0b0110;
    insn.autiasppcr64lrr_dp1src._unnamed_2 = 0b101;
    insn.autiasppcr64lrr_dp1src._unnamed_1 = 0b1;
    insn.autiasppcr64lrr_dp1src.S = 0b0;
    insn.autiasppcr64lrr_dp1src._unnamed_0 = 0b1;
    insn.autiasppcr64lrr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autib_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.autib64p_dp1src.Rd = Rd;
    insn.autib64p_dp1src.Rn = Rn;
    insn.autib64p_dp1src._unnamed_3 = 0b101;
    insn.autib64p_dp1src.Z = 0b0;
    insn.autib64p_dp1src._unnamed_2 = 0b00;
    insn.autib64p_dp1src.opcode2 = 0b00001;
    insn.autib64p_dp1src._unnamed_1 = 0b11010110;
    insn.autib64p_dp1src.S = 0b0;
    insn.autib64p_dp1src._unnamed_0 = 0b1;
    insn.autib64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autizb_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.autizb64z_dp1src.Rd = Rd;
    insn.autizb64z_dp1src.Rn = 0b11111;
    insn.autizb64z_dp1src._unnamed_3 = 0b101;
    insn.autizb64z_dp1src.Z = 0b1;
    insn.autizb64z_dp1src._unnamed_2 = 0b00;
    insn.autizb64z_dp1src.opcode2 = 0b00001;
    insn.autizb64z_dp1src._unnamed_1 = 0b11010110;
    insn.autizb64z_dp1src.S = 0b0;
    insn.autizb64z_dp1src._unnamed_0 = 0b1;
    insn.autizb64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autib171615_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.autib17161564lr_dp1src.Rd = 0b11110;
    insn.autib17161564lr_dp1src.Rn = 0b11111;
    insn.autib17161564lr_dp1src.opcode = 0b101111;
    insn.autib17161564lr_dp1src.opcode2 = 0b00001;
    insn.autib17161564lr_dp1src._unnamed_3 = 0b0110;
    insn.autib17161564lr_dp1src._unnamed_2 = 0b101;
    insn.autib17161564lr_dp1src._unnamed_1 = 0b1;
    insn.autib17161564lr_dp1src.S = 0b0;
    insn.autib17161564lr_dp1src._unnamed_0 = 0b1;
    insn.autib17161564lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autibsppcr_64lrr_dp_1src(uint32_t Rn) {
    DpregEncoding insn = {};
    insn.autibsppcr64lrr_dp1src.Rd = 0b11110;
    insn.autibsppcr64lrr_dp1src.Rn = Rn;
    insn.autibsppcr64lrr_dp1src.opcode = 0b100101;
    insn.autibsppcr64lrr_dp1src.opcode2 = 0b00001;
    insn.autibsppcr64lrr_dp1src._unnamed_3 = 0b0110;
    insn.autibsppcr64lrr_dp1src._unnamed_2 = 0b101;
    insn.autibsppcr64lrr_dp1src._unnamed_1 = 0b1;
    insn.autibsppcr64lrr_dp1src.S = 0b0;
    insn.autibsppcr64lrr_dp1src._unnamed_0 = 0b1;
    insn.autibsppcr64lrr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_bic_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.bic32log_shift.Rd = Rd;
    insn.bic32log_shift.Rn = Rn;
    insn.bic32log_shift.imm6 = imm6;
    insn.bic32log_shift.Rm = Rm;
    insn.bic32log_shift.N = 0b1;
    insn.bic32log_shift.shift = shift;
    insn.bic32log_shift._unnamed_0 = 0b01010;
    insn.bic32log_shift.opc = 0b00;
    insn.bic32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_bic_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.bic64log_shift.Rd = Rd;
    insn.bic64log_shift.Rn = Rn;
    insn.bic64log_shift.imm6 = imm6;
    insn.bic64log_shift.Rm = Rm;
    insn.bic64log_shift.N = 0b1;
    insn.bic64log_shift.shift = shift;
    insn.bic64log_shift._unnamed_0 = 0b01010;
    insn.bic64log_shift.opc = 0b00;
    insn.bic64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_bics_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.bics32log_shift.Rd = Rd;
    insn.bics32log_shift.Rn = Rn;
    insn.bics32log_shift.imm6 = imm6;
    insn.bics32log_shift.Rm = Rm;
    insn.bics32log_shift.N = 0b1;
    insn.bics32log_shift.shift = shift;
    insn.bics32log_shift._unnamed_0 = 0b01010;
    insn.bics32log_shift.opc = 0b11;
    insn.bics32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_bics_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.bics64log_shift.Rd = Rd;
    insn.bics64log_shift.Rn = Rn;
    insn.bics64log_shift.imm6 = imm6;
    insn.bics64log_shift.Rm = Rm;
    insn.bics64log_shift.N = 0b1;
    insn.bics64log_shift.shift = shift;
    insn.bics64log_shift._unnamed_0 = 0b01010;
    insn.bics64log_shift.opc = 0b11;
    insn.bics64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ccmn_32_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5) {
    DpregEncoding insn = {};
    insn.ccmn32condcmp_imm.nzcv = nzcv;
    insn.ccmn32condcmp_imm.o3 = 0b0;
    insn.ccmn32condcmp_imm.Rn = Rn;
    insn.ccmn32condcmp_imm.o2 = 0b0;
    insn.ccmn32condcmp_imm._unnamed_1 = 0b1;
    insn.ccmn32condcmp_imm.cond = cond;
    insn.ccmn32condcmp_imm.imm5 = imm5;
    insn.ccmn32condcmp_imm._unnamed_0 = 0b11010010;
    insn.ccmn32condcmp_imm.S = 0b1;
    insn.ccmn32condcmp_imm.op = 0b0;
    insn.ccmn32condcmp_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ccmn_64_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5) {
    DpregEncoding insn = {};
    insn.ccmn64condcmp_imm.nzcv = nzcv;
    insn.ccmn64condcmp_imm.o3 = 0b0;
    insn.ccmn64condcmp_imm.Rn = Rn;
    insn.ccmn64condcmp_imm.o2 = 0b0;
    insn.ccmn64condcmp_imm._unnamed_1 = 0b1;
    insn.ccmn64condcmp_imm.cond = cond;
    insn.ccmn64condcmp_imm.imm5 = imm5;
    insn.ccmn64condcmp_imm._unnamed_0 = 0b11010010;
    insn.ccmn64condcmp_imm.S = 0b1;
    insn.ccmn64condcmp_imm.op = 0b0;
    insn.ccmn64condcmp_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ccmn_32_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ccmn32condcmp_reg.nzcv = nzcv;
    insn.ccmn32condcmp_reg.o3 = 0b0;
    insn.ccmn32condcmp_reg.Rn = Rn;
    insn.ccmn32condcmp_reg.o2 = 0b0;
    insn.ccmn32condcmp_reg._unnamed_1 = 0b0;
    insn.ccmn32condcmp_reg.cond = cond;
    insn.ccmn32condcmp_reg.Rm = Rm;
    insn.ccmn32condcmp_reg._unnamed_0 = 0b11010010;
    insn.ccmn32condcmp_reg.S = 0b1;
    insn.ccmn32condcmp_reg.op = 0b0;
    insn.ccmn32condcmp_reg.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ccmn_64_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ccmn64condcmp_reg.nzcv = nzcv;
    insn.ccmn64condcmp_reg.o3 = 0b0;
    insn.ccmn64condcmp_reg.Rn = Rn;
    insn.ccmn64condcmp_reg.o2 = 0b0;
    insn.ccmn64condcmp_reg._unnamed_1 = 0b0;
    insn.ccmn64condcmp_reg.cond = cond;
    insn.ccmn64condcmp_reg.Rm = Rm;
    insn.ccmn64condcmp_reg._unnamed_0 = 0b11010010;
    insn.ccmn64condcmp_reg.S = 0b1;
    insn.ccmn64condcmp_reg.op = 0b0;
    insn.ccmn64condcmp_reg.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ccmp_32_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5) {
    DpregEncoding insn = {};
    insn.ccmp32condcmp_imm.nzcv = nzcv;
    insn.ccmp32condcmp_imm.o3 = 0b0;
    insn.ccmp32condcmp_imm.Rn = Rn;
    insn.ccmp32condcmp_imm.o2 = 0b0;
    insn.ccmp32condcmp_imm._unnamed_1 = 0b1;
    insn.ccmp32condcmp_imm.cond = cond;
    insn.ccmp32condcmp_imm.imm5 = imm5;
    insn.ccmp32condcmp_imm._unnamed_0 = 0b11010010;
    insn.ccmp32condcmp_imm.S = 0b1;
    insn.ccmp32condcmp_imm.op = 0b1;
    insn.ccmp32condcmp_imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ccmp_64_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5) {
    DpregEncoding insn = {};
    insn.ccmp64condcmp_imm.nzcv = nzcv;
    insn.ccmp64condcmp_imm.o3 = 0b0;
    insn.ccmp64condcmp_imm.Rn = Rn;
    insn.ccmp64condcmp_imm.o2 = 0b0;
    insn.ccmp64condcmp_imm._unnamed_1 = 0b1;
    insn.ccmp64condcmp_imm.cond = cond;
    insn.ccmp64condcmp_imm.imm5 = imm5;
    insn.ccmp64condcmp_imm._unnamed_0 = 0b11010010;
    insn.ccmp64condcmp_imm.S = 0b1;
    insn.ccmp64condcmp_imm.op = 0b1;
    insn.ccmp64condcmp_imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ccmp_32_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ccmp32condcmp_reg.nzcv = nzcv;
    insn.ccmp32condcmp_reg.o3 = 0b0;
    insn.ccmp32condcmp_reg.Rn = Rn;
    insn.ccmp32condcmp_reg.o2 = 0b0;
    insn.ccmp32condcmp_reg._unnamed_1 = 0b0;
    insn.ccmp32condcmp_reg.cond = cond;
    insn.ccmp32condcmp_reg.Rm = Rm;
    insn.ccmp32condcmp_reg._unnamed_0 = 0b11010010;
    insn.ccmp32condcmp_reg.S = 0b1;
    insn.ccmp32condcmp_reg.op = 0b1;
    insn.ccmp32condcmp_reg.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ccmp_64_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ccmp64condcmp_reg.nzcv = nzcv;
    insn.ccmp64condcmp_reg.o3 = 0b0;
    insn.ccmp64condcmp_reg.Rn = Rn;
    insn.ccmp64condcmp_reg.o2 = 0b0;
    insn.ccmp64condcmp_reg._unnamed_1 = 0b0;
    insn.ccmp64condcmp_reg.cond = cond;
    insn.ccmp64condcmp_reg.Rm = Rm;
    insn.ccmp64condcmp_reg._unnamed_0 = 0b11010010;
    insn.ccmp64condcmp_reg.S = 0b1;
    insn.ccmp64condcmp_reg.op = 0b1;
    insn.ccmp64condcmp_reg.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cinc_csinc_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cinc_csinc32condsel.Rd = Rd;
    insn.cinc_csinc32condsel.Rn = Rn;
    insn.cinc_csinc32condsel.o2 = 0b1;
    insn.cinc_csinc32condsel._unnamed_1 = 0b0;
    insn.cinc_csinc32condsel.cond = cond;
    insn.cinc_csinc32condsel.Rm = Rm;
    insn.cinc_csinc32condsel._unnamed_0 = 0b11010100;
    insn.cinc_csinc32condsel.S = 0b0;
    insn.cinc_csinc32condsel.op = 0b0;
    insn.cinc_csinc32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cinc_csinc_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cinc_csinc64condsel.Rd = Rd;
    insn.cinc_csinc64condsel.Rn = Rn;
    insn.cinc_csinc64condsel.o2 = 0b1;
    insn.cinc_csinc64condsel._unnamed_1 = 0b0;
    insn.cinc_csinc64condsel.cond = cond;
    insn.cinc_csinc64condsel.Rm = Rm;
    insn.cinc_csinc64condsel._unnamed_0 = 0b11010100;
    insn.cinc_csinc64condsel.S = 0b0;
    insn.cinc_csinc64condsel.op = 0b0;
    insn.cinc_csinc64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cinv_csinv_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cinv_csinv32condsel.Rd = Rd;
    insn.cinv_csinv32condsel.Rn = Rn;
    insn.cinv_csinv32condsel.o2 = 0b0;
    insn.cinv_csinv32condsel._unnamed_1 = 0b0;
    insn.cinv_csinv32condsel.cond = cond;
    insn.cinv_csinv32condsel.Rm = Rm;
    insn.cinv_csinv32condsel._unnamed_0 = 0b11010100;
    insn.cinv_csinv32condsel.S = 0b0;
    insn.cinv_csinv32condsel.op = 0b1;
    insn.cinv_csinv32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cinv_csinv_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cinv_csinv64condsel.Rd = Rd;
    insn.cinv_csinv64condsel.Rn = Rn;
    insn.cinv_csinv64condsel.o2 = 0b0;
    insn.cinv_csinv64condsel._unnamed_1 = 0b0;
    insn.cinv_csinv64condsel.cond = cond;
    insn.cinv_csinv64condsel.Rm = Rm;
    insn.cinv_csinv64condsel._unnamed_0 = 0b11010100;
    insn.cinv_csinv64condsel.S = 0b0;
    insn.cinv_csinv64condsel.op = 0b1;
    insn.cinv_csinv64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cls_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.cls32dp1src.Rd = Rd;
    insn.cls32dp1src.Rn = Rn;
    insn.cls32dp1src.op = 0b1;
    insn.cls32dp1src._unnamed_2 = 0b00010;
    insn.cls32dp1src.opcode2 = 0b00000;
    insn.cls32dp1src._unnamed_1 = 0b11010110;
    insn.cls32dp1src.S = 0b0;
    insn.cls32dp1src._unnamed_0 = 0b1;
    insn.cls32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cls_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.cls64dp1src.Rd = Rd;
    insn.cls64dp1src.Rn = Rn;
    insn.cls64dp1src.op = 0b1;
    insn.cls64dp1src._unnamed_2 = 0b00010;
    insn.cls64dp1src.opcode2 = 0b00000;
    insn.cls64dp1src._unnamed_1 = 0b11010110;
    insn.cls64dp1src.S = 0b0;
    insn.cls64dp1src._unnamed_0 = 0b1;
    insn.cls64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_clz_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.clz32dp1src.Rd = Rd;
    insn.clz32dp1src.Rn = Rn;
    insn.clz32dp1src.op = 0b0;
    insn.clz32dp1src._unnamed_2 = 0b00010;
    insn.clz32dp1src.opcode2 = 0b00000;
    insn.clz32dp1src._unnamed_1 = 0b11010110;
    insn.clz32dp1src.S = 0b0;
    insn.clz32dp1src._unnamed_0 = 0b1;
    insn.clz32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_clz_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.clz64dp1src.Rd = Rd;
    insn.clz64dp1src.Rn = Rn;
    insn.clz64dp1src.op = 0b0;
    insn.clz64dp1src._unnamed_2 = 0b00010;
    insn.clz64dp1src.opcode2 = 0b00000;
    insn.clz64dp1src._unnamed_1 = 0b11010110;
    insn.clz64dp1src.S = 0b0;
    insn.clz64dp1src._unnamed_0 = 0b1;
    insn.clz64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmn_adds_32s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cmn_adds32s_addsub_ext.Rd = 0b11111;
    insn.cmn_adds32s_addsub_ext.Rn = Rn;
    insn.cmn_adds32s_addsub_ext.imm3 = imm3;
    insn.cmn_adds32s_addsub_ext.option = option;
    insn.cmn_adds32s_addsub_ext.Rm = Rm;
    insn.cmn_adds32s_addsub_ext._unnamed_1 = 0b1;
    insn.cmn_adds32s_addsub_ext.opt = 0b00;
    insn.cmn_adds32s_addsub_ext._unnamed_0 = 0b01011;
    insn.cmn_adds32s_addsub_ext.S = 0b1;
    insn.cmn_adds32s_addsub_ext.op = 0b0;
    insn.cmn_adds32s_addsub_ext.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cmn_adds_64s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cmn_adds64s_addsub_ext.Rd = 0b11111;
    insn.cmn_adds64s_addsub_ext.Rn = Rn;
    insn.cmn_adds64s_addsub_ext.imm3 = imm3;
    insn.cmn_adds64s_addsub_ext.option = option;
    insn.cmn_adds64s_addsub_ext.Rm = Rm;
    insn.cmn_adds64s_addsub_ext._unnamed_1 = 0b1;
    insn.cmn_adds64s_addsub_ext.opt = 0b00;
    insn.cmn_adds64s_addsub_ext._unnamed_0 = 0b01011;
    insn.cmn_adds64s_addsub_ext.S = 0b1;
    insn.cmn_adds64s_addsub_ext.op = 0b0;
    insn.cmn_adds64s_addsub_ext.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmn_adds_32_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.cmn_adds32addsub_shift.Rd = 0b11111;
    insn.cmn_adds32addsub_shift.Rn = Rn;
    insn.cmn_adds32addsub_shift.imm6 = imm6;
    insn.cmn_adds32addsub_shift.Rm = Rm;
    insn.cmn_adds32addsub_shift._unnamed_1 = 0b0;
    insn.cmn_adds32addsub_shift.shift = shift;
    insn.cmn_adds32addsub_shift._unnamed_0 = 0b01011;
    insn.cmn_adds32addsub_shift.S = 0b1;
    insn.cmn_adds32addsub_shift.op = 0b0;
    insn.cmn_adds32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cmn_adds_64_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.cmn_adds64addsub_shift.Rd = 0b11111;
    insn.cmn_adds64addsub_shift.Rn = Rn;
    insn.cmn_adds64addsub_shift.imm6 = imm6;
    insn.cmn_adds64addsub_shift.Rm = Rm;
    insn.cmn_adds64addsub_shift._unnamed_1 = 0b0;
    insn.cmn_adds64addsub_shift.shift = shift;
    insn.cmn_adds64addsub_shift._unnamed_0 = 0b01011;
    insn.cmn_adds64addsub_shift.S = 0b1;
    insn.cmn_adds64addsub_shift.op = 0b0;
    insn.cmn_adds64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmp_subs_32s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cmp_subs32s_addsub_ext.Rd = 0b11111;
    insn.cmp_subs32s_addsub_ext.Rn = Rn;
    insn.cmp_subs32s_addsub_ext.imm3 = imm3;
    insn.cmp_subs32s_addsub_ext.option = option;
    insn.cmp_subs32s_addsub_ext.Rm = Rm;
    insn.cmp_subs32s_addsub_ext._unnamed_1 = 0b1;
    insn.cmp_subs32s_addsub_ext.opt = 0b00;
    insn.cmp_subs32s_addsub_ext._unnamed_0 = 0b01011;
    insn.cmp_subs32s_addsub_ext.S = 0b1;
    insn.cmp_subs32s_addsub_ext.op = 0b1;
    insn.cmp_subs32s_addsub_ext.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cmp_subs_64s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cmp_subs64s_addsub_ext.Rd = 0b11111;
    insn.cmp_subs64s_addsub_ext.Rn = Rn;
    insn.cmp_subs64s_addsub_ext.imm3 = imm3;
    insn.cmp_subs64s_addsub_ext.option = option;
    insn.cmp_subs64s_addsub_ext.Rm = Rm;
    insn.cmp_subs64s_addsub_ext._unnamed_1 = 0b1;
    insn.cmp_subs64s_addsub_ext.opt = 0b00;
    insn.cmp_subs64s_addsub_ext._unnamed_0 = 0b01011;
    insn.cmp_subs64s_addsub_ext.S = 0b1;
    insn.cmp_subs64s_addsub_ext.op = 0b1;
    insn.cmp_subs64s_addsub_ext.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmp_subs_32_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.cmp_subs32addsub_shift.Rd = 0b11111;
    insn.cmp_subs32addsub_shift.Rn = Rn;
    insn.cmp_subs32addsub_shift.imm6 = imm6;
    insn.cmp_subs32addsub_shift.Rm = Rm;
    insn.cmp_subs32addsub_shift._unnamed_1 = 0b0;
    insn.cmp_subs32addsub_shift.shift = shift;
    insn.cmp_subs32addsub_shift._unnamed_0 = 0b01011;
    insn.cmp_subs32addsub_shift.S = 0b1;
    insn.cmp_subs32addsub_shift.op = 0b1;
    insn.cmp_subs32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cmp_subs_64_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.cmp_subs64addsub_shift.Rd = 0b11111;
    insn.cmp_subs64addsub_shift.Rn = Rn;
    insn.cmp_subs64addsub_shift.imm6 = imm6;
    insn.cmp_subs64addsub_shift.Rm = Rm;
    insn.cmp_subs64addsub_shift._unnamed_1 = 0b0;
    insn.cmp_subs64addsub_shift.shift = shift;
    insn.cmp_subs64addsub_shift._unnamed_0 = 0b01011;
    insn.cmp_subs64addsub_shift.S = 0b1;
    insn.cmp_subs64addsub_shift.op = 0b1;
    insn.cmp_subs64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cmpp_subps_64s_dp_2src(uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cmpp_subps64s_dp2src.Rd = 0b11111;
    insn.cmpp_subps64s_dp2src.Rn = Rn;
    insn.cmpp_subps64s_dp2src.opcode = 0b000000;
    insn.cmpp_subps64s_dp2src.Rm = Rm;
    insn.cmpp_subps64s_dp2src._unnamed_3 = 0b0110;
    insn.cmpp_subps64s_dp2src._unnamed_2 = 0b101;
    insn.cmpp_subps64s_dp2src._unnamed_1 = 0b1;
    insn.cmpp_subps64s_dp2src.S = 0b1;
    insn.cmpp_subps64s_dp2src._unnamed_0 = 0b0;
    insn.cmpp_subps64s_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cneg_csneg_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cneg_csneg32condsel.Rd = Rd;
    insn.cneg_csneg32condsel.Rn = Rn;
    insn.cneg_csneg32condsel.o2 = 0b1;
    insn.cneg_csneg32condsel._unnamed_1 = 0b0;
    insn.cneg_csneg32condsel.cond = cond;
    insn.cneg_csneg32condsel.Rm = Rm;
    insn.cneg_csneg32condsel._unnamed_0 = 0b11010100;
    insn.cneg_csneg32condsel.S = 0b0;
    insn.cneg_csneg32condsel.op = 0b1;
    insn.cneg_csneg32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cneg_csneg_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.cneg_csneg64condsel.Rd = Rd;
    insn.cneg_csneg64condsel.Rn = Rn;
    insn.cneg_csneg64condsel.o2 = 0b1;
    insn.cneg_csneg64condsel._unnamed_1 = 0b0;
    insn.cneg_csneg64condsel.cond = cond;
    insn.cneg_csneg64condsel.Rm = Rm;
    insn.cneg_csneg64condsel._unnamed_0 = 0b11010100;
    insn.cneg_csneg64condsel.S = 0b0;
    insn.cneg_csneg64condsel.op = 0b1;
    insn.cneg_csneg64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cnt_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.cnt32dp1src.Rd = Rd;
    insn.cnt32dp1src.Rn = Rn;
    insn.cnt32dp1src.opcode = 0b000111;
    insn.cnt32dp1src.opcode2 = 0b00000;
    insn.cnt32dp1src._unnamed_1 = 0b11010110;
    insn.cnt32dp1src.S = 0b0;
    insn.cnt32dp1src._unnamed_0 = 0b1;
    insn.cnt32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cnt_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.cnt64dp1src.Rd = Rd;
    insn.cnt64dp1src.Rn = Rn;
    insn.cnt64dp1src.opcode = 0b000111;
    insn.cnt64dp1src.opcode2 = 0b00000;
    insn.cnt64dp1src._unnamed_1 = 0b11010110;
    insn.cnt64dp1src.S = 0b0;
    insn.cnt64dp1src._unnamed_0 = 0b1;
    insn.cnt64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_crc32b_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32b32c_dp2src.Rd = Rd;
    insn.crc32b32c_dp2src.Rn = Rn;
    insn.crc32b32c_dp2src.sz = 0b00;
    insn.crc32b32c_dp2src.C = 0b0;
    insn.crc32b32c_dp2src._unnamed_2 = 0b010;
    insn.crc32b32c_dp2src.Rm = Rm;
    insn.crc32b32c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32b32c_dp2src.S = 0b0;
    insn.crc32b32c_dp2src._unnamed_0 = 0b0;
    insn.crc32b32c_dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_crc32h_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32h32c_dp2src.Rd = Rd;
    insn.crc32h32c_dp2src.Rn = Rn;
    insn.crc32h32c_dp2src.sz = 0b01;
    insn.crc32h32c_dp2src.C = 0b0;
    insn.crc32h32c_dp2src._unnamed_2 = 0b010;
    insn.crc32h32c_dp2src.Rm = Rm;
    insn.crc32h32c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32h32c_dp2src.S = 0b0;
    insn.crc32h32c_dp2src._unnamed_0 = 0b0;
    insn.crc32h32c_dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_crc32w_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32w32c_dp2src.Rd = Rd;
    insn.crc32w32c_dp2src.Rn = Rn;
    insn.crc32w32c_dp2src.sz = 0b10;
    insn.crc32w32c_dp2src.C = 0b0;
    insn.crc32w32c_dp2src._unnamed_2 = 0b010;
    insn.crc32w32c_dp2src.Rm = Rm;
    insn.crc32w32c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32w32c_dp2src.S = 0b0;
    insn.crc32w32c_dp2src._unnamed_0 = 0b0;
    insn.crc32w32c_dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_crc32x_64c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32x64c_dp2src.Rd = Rd;
    insn.crc32x64c_dp2src.Rn = Rn;
    insn.crc32x64c_dp2src.sz = 0b11;
    insn.crc32x64c_dp2src.C = 0b0;
    insn.crc32x64c_dp2src._unnamed_2 = 0b010;
    insn.crc32x64c_dp2src.Rm = Rm;
    insn.crc32x64c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32x64c_dp2src.S = 0b0;
    insn.crc32x64c_dp2src._unnamed_0 = 0b0;
    insn.crc32x64c_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_crc32cb_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32cb32c_dp2src.Rd = Rd;
    insn.crc32cb32c_dp2src.Rn = Rn;
    insn.crc32cb32c_dp2src.sz = 0b00;
    insn.crc32cb32c_dp2src.C = 0b1;
    insn.crc32cb32c_dp2src._unnamed_2 = 0b010;
    insn.crc32cb32c_dp2src.Rm = Rm;
    insn.crc32cb32c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32cb32c_dp2src.S = 0b0;
    insn.crc32cb32c_dp2src._unnamed_0 = 0b0;
    insn.crc32cb32c_dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_crc32ch_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32ch32c_dp2src.Rd = Rd;
    insn.crc32ch32c_dp2src.Rn = Rn;
    insn.crc32ch32c_dp2src.sz = 0b01;
    insn.crc32ch32c_dp2src.C = 0b1;
    insn.crc32ch32c_dp2src._unnamed_2 = 0b010;
    insn.crc32ch32c_dp2src.Rm = Rm;
    insn.crc32ch32c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32ch32c_dp2src.S = 0b0;
    insn.crc32ch32c_dp2src._unnamed_0 = 0b0;
    insn.crc32ch32c_dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_crc32cw_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32cw32c_dp2src.Rd = Rd;
    insn.crc32cw32c_dp2src.Rn = Rn;
    insn.crc32cw32c_dp2src.sz = 0b10;
    insn.crc32cw32c_dp2src.C = 0b1;
    insn.crc32cw32c_dp2src._unnamed_2 = 0b010;
    insn.crc32cw32c_dp2src.Rm = Rm;
    insn.crc32cw32c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32cw32c_dp2src.S = 0b0;
    insn.crc32cw32c_dp2src._unnamed_0 = 0b0;
    insn.crc32cw32c_dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_crc32cx_64c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.crc32cx64c_dp2src.Rd = Rd;
    insn.crc32cx64c_dp2src.Rn = Rn;
    insn.crc32cx64c_dp2src.sz = 0b11;
    insn.crc32cx64c_dp2src.C = 0b1;
    insn.crc32cx64c_dp2src._unnamed_2 = 0b010;
    insn.crc32cx64c_dp2src.Rm = Rm;
    insn.crc32cx64c_dp2src._unnamed_1 = 0b11010110;
    insn.crc32cx64c_dp2src.S = 0b0;
    insn.crc32cx64c_dp2src._unnamed_0 = 0b0;
    insn.crc32cx64c_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_csel_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csel32condsel.Rd = Rd;
    insn.csel32condsel.Rn = Rn;
    insn.csel32condsel.o2 = 0b0;
    insn.csel32condsel._unnamed_1 = 0b0;
    insn.csel32condsel.cond = cond;
    insn.csel32condsel.Rm = Rm;
    insn.csel32condsel._unnamed_0 = 0b11010100;
    insn.csel32condsel.S = 0b0;
    insn.csel32condsel.op = 0b0;
    insn.csel32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_csel_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csel64condsel.Rd = Rd;
    insn.csel64condsel.Rn = Rn;
    insn.csel64condsel.o2 = 0b0;
    insn.csel64condsel._unnamed_1 = 0b0;
    insn.csel64condsel.cond = cond;
    insn.csel64condsel.Rm = Rm;
    insn.csel64condsel._unnamed_0 = 0b11010100;
    insn.csel64condsel.S = 0b0;
    insn.csel64condsel.op = 0b0;
    insn.csel64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cset_csinc_32_condsel(uint32_t Rd, uint32_t cond) {
    DpregEncoding insn = {};
    insn.cset_csinc32condsel.Rd = Rd;
    insn.cset_csinc32condsel.Rn = 0b11111;
    insn.cset_csinc32condsel.o2 = 0b1;
    insn.cset_csinc32condsel._unnamed_1 = 0b0;
    insn.cset_csinc32condsel.cond = cond;
    insn.cset_csinc32condsel.Rm = 0b11111;
    insn.cset_csinc32condsel._unnamed_0 = 0b11010100;
    insn.cset_csinc32condsel.S = 0b0;
    insn.cset_csinc32condsel.op = 0b0;
    insn.cset_csinc32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cset_csinc_64_condsel(uint32_t Rd, uint32_t cond) {
    DpregEncoding insn = {};
    insn.cset_csinc64condsel.Rd = Rd;
    insn.cset_csinc64condsel.Rn = 0b11111;
    insn.cset_csinc64condsel.o2 = 0b1;
    insn.cset_csinc64condsel._unnamed_1 = 0b0;
    insn.cset_csinc64condsel.cond = cond;
    insn.cset_csinc64condsel.Rm = 0b11111;
    insn.cset_csinc64condsel._unnamed_0 = 0b11010100;
    insn.cset_csinc64condsel.S = 0b0;
    insn.cset_csinc64condsel.op = 0b0;
    insn.cset_csinc64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_csetm_csinv_32_condsel(uint32_t Rd, uint32_t cond) {
    DpregEncoding insn = {};
    insn.csetm_csinv32condsel.Rd = Rd;
    insn.csetm_csinv32condsel.Rn = 0b11111;
    insn.csetm_csinv32condsel.o2 = 0b0;
    insn.csetm_csinv32condsel._unnamed_1 = 0b0;
    insn.csetm_csinv32condsel.cond = cond;
    insn.csetm_csinv32condsel.Rm = 0b11111;
    insn.csetm_csinv32condsel._unnamed_0 = 0b11010100;
    insn.csetm_csinv32condsel.S = 0b0;
    insn.csetm_csinv32condsel.op = 0b1;
    insn.csetm_csinv32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_csetm_csinv_64_condsel(uint32_t Rd, uint32_t cond) {
    DpregEncoding insn = {};
    insn.csetm_csinv64condsel.Rd = Rd;
    insn.csetm_csinv64condsel.Rn = 0b11111;
    insn.csetm_csinv64condsel.o2 = 0b0;
    insn.csetm_csinv64condsel._unnamed_1 = 0b0;
    insn.csetm_csinv64condsel.cond = cond;
    insn.csetm_csinv64condsel.Rm = 0b11111;
    insn.csetm_csinv64condsel._unnamed_0 = 0b11010100;
    insn.csetm_csinv64condsel.S = 0b0;
    insn.csetm_csinv64condsel.op = 0b1;
    insn.csetm_csinv64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_csinc_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csinc32condsel.Rd = Rd;
    insn.csinc32condsel.Rn = Rn;
    insn.csinc32condsel.o2 = 0b1;
    insn.csinc32condsel._unnamed_1 = 0b0;
    insn.csinc32condsel.cond = cond;
    insn.csinc32condsel.Rm = Rm;
    insn.csinc32condsel._unnamed_0 = 0b11010100;
    insn.csinc32condsel.S = 0b0;
    insn.csinc32condsel.op = 0b0;
    insn.csinc32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_csinc_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csinc64condsel.Rd = Rd;
    insn.csinc64condsel.Rn = Rn;
    insn.csinc64condsel.o2 = 0b1;
    insn.csinc64condsel._unnamed_1 = 0b0;
    insn.csinc64condsel.cond = cond;
    insn.csinc64condsel.Rm = Rm;
    insn.csinc64condsel._unnamed_0 = 0b11010100;
    insn.csinc64condsel.S = 0b0;
    insn.csinc64condsel.op = 0b0;
    insn.csinc64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_csinv_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csinv32condsel.Rd = Rd;
    insn.csinv32condsel.Rn = Rn;
    insn.csinv32condsel.o2 = 0b0;
    insn.csinv32condsel._unnamed_1 = 0b0;
    insn.csinv32condsel.cond = cond;
    insn.csinv32condsel.Rm = Rm;
    insn.csinv32condsel._unnamed_0 = 0b11010100;
    insn.csinv32condsel.S = 0b0;
    insn.csinv32condsel.op = 0b1;
    insn.csinv32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_csinv_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csinv64condsel.Rd = Rd;
    insn.csinv64condsel.Rn = Rn;
    insn.csinv64condsel.o2 = 0b0;
    insn.csinv64condsel._unnamed_1 = 0b0;
    insn.csinv64condsel.cond = cond;
    insn.csinv64condsel.Rm = Rm;
    insn.csinv64condsel._unnamed_0 = 0b11010100;
    insn.csinv64condsel.S = 0b0;
    insn.csinv64condsel.op = 0b1;
    insn.csinv64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_csneg_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csneg32condsel.Rd = Rd;
    insn.csneg32condsel.Rn = Rn;
    insn.csneg32condsel.o2 = 0b1;
    insn.csneg32condsel._unnamed_1 = 0b0;
    insn.csneg32condsel.cond = cond;
    insn.csneg32condsel.Rm = Rm;
    insn.csneg32condsel._unnamed_0 = 0b11010100;
    insn.csneg32condsel.S = 0b0;
    insn.csneg32condsel.op = 0b1;
    insn.csneg32condsel.sf = 0b0;
    return insn.raw;
}

uint32_t encode_csneg_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.csneg64condsel.Rd = Rd;
    insn.csneg64condsel.Rn = Rn;
    insn.csneg64condsel.o2 = 0b1;
    insn.csneg64condsel._unnamed_1 = 0b0;
    insn.csneg64condsel.cond = cond;
    insn.csneg64condsel.Rm = Rm;
    insn.csneg64condsel._unnamed_0 = 0b11010100;
    insn.csneg64condsel.S = 0b0;
    insn.csneg64condsel.op = 0b1;
    insn.csneg64condsel.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ctz_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.ctz32dp1src.Rd = Rd;
    insn.ctz32dp1src.Rn = Rn;
    insn.ctz32dp1src.opcode = 0b000110;
    insn.ctz32dp1src.opcode2 = 0b00000;
    insn.ctz32dp1src._unnamed_1 = 0b11010110;
    insn.ctz32dp1src.S = 0b0;
    insn.ctz32dp1src._unnamed_0 = 0b1;
    insn.ctz32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ctz_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.ctz64dp1src.Rd = Rd;
    insn.ctz64dp1src.Rn = Rn;
    insn.ctz64dp1src.opcode = 0b000110;
    insn.ctz64dp1src.opcode2 = 0b00000;
    insn.ctz64dp1src._unnamed_1 = 0b11010110;
    insn.ctz64dp1src.S = 0b0;
    insn.ctz64dp1src._unnamed_0 = 0b1;
    insn.ctz64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_eon_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.eon32log_shift.Rd = Rd;
    insn.eon32log_shift.Rn = Rn;
    insn.eon32log_shift.imm6 = imm6;
    insn.eon32log_shift.Rm = Rm;
    insn.eon32log_shift.N = 0b1;
    insn.eon32log_shift.shift = shift;
    insn.eon32log_shift._unnamed_0 = 0b01010;
    insn.eon32log_shift.opc = 0b10;
    insn.eon32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_eon_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.eon64log_shift.Rd = Rd;
    insn.eon64log_shift.Rn = Rn;
    insn.eon64log_shift.imm6 = imm6;
    insn.eon64log_shift.Rm = Rm;
    insn.eon64log_shift.N = 0b1;
    insn.eon64log_shift.shift = shift;
    insn.eon64log_shift._unnamed_0 = 0b01010;
    insn.eon64log_shift.opc = 0b10;
    insn.eon64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_eor_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.eor32log_shift.Rd = Rd;
    insn.eor32log_shift.Rn = Rn;
    insn.eor32log_shift.imm6 = imm6;
    insn.eor32log_shift.Rm = Rm;
    insn.eor32log_shift.N = 0b0;
    insn.eor32log_shift.shift = shift;
    insn.eor32log_shift._unnamed_0 = 0b01010;
    insn.eor32log_shift.opc = 0b10;
    insn.eor32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_eor_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.eor64log_shift.Rd = Rd;
    insn.eor64log_shift.Rn = Rn;
    insn.eor64log_shift.imm6 = imm6;
    insn.eor64log_shift.Rm = Rm;
    insn.eor64log_shift.N = 0b0;
    insn.eor64log_shift.shift = shift;
    insn.eor64log_shift._unnamed_0 = 0b01010;
    insn.eor64log_shift.opc = 0b10;
    insn.eor64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_gmi_64g_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.gmi64g_dp2src.Rd = Rd;
    insn.gmi64g_dp2src.Rn = Rn;
    insn.gmi64g_dp2src.opcode = 0b000101;
    insn.gmi64g_dp2src.Rm = Rm;
    insn.gmi64g_dp2src._unnamed_3 = 0b0110;
    insn.gmi64g_dp2src._unnamed_2 = 0b101;
    insn.gmi64g_dp2src._unnamed_1 = 0b1;
    insn.gmi64g_dp2src.S = 0b0;
    insn.gmi64g_dp2src._unnamed_0 = 0b0;
    insn.gmi64g_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_irg_64i_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.irg64i_dp2src.Rd = Rd;
    insn.irg64i_dp2src.Rn = Rn;
    insn.irg64i_dp2src.opcode = 0b000100;
    insn.irg64i_dp2src.Rm = Rm;
    insn.irg64i_dp2src._unnamed_3 = 0b0110;
    insn.irg64i_dp2src._unnamed_2 = 0b101;
    insn.irg64i_dp2src._unnamed_1 = 0b1;
    insn.irg64i_dp2src.S = 0b0;
    insn.irg64i_dp2src._unnamed_0 = 0b0;
    insn.irg64i_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_lsl_lslv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lsl_lslv32dp2src.Rd = Rd;
    insn.lsl_lslv32dp2src.Rn = Rn;
    insn.lsl_lslv32dp2src.op2 = 0b00;
    insn.lsl_lslv32dp2src._unnamed_2 = 0b0010;
    insn.lsl_lslv32dp2src.Rm = Rm;
    insn.lsl_lslv32dp2src._unnamed_1 = 0b11010110;
    insn.lsl_lslv32dp2src.S = 0b0;
    insn.lsl_lslv32dp2src._unnamed_0 = 0b0;
    insn.lsl_lslv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_lsl_lslv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lsl_lslv64dp2src.Rd = Rd;
    insn.lsl_lslv64dp2src.Rn = Rn;
    insn.lsl_lslv64dp2src.op2 = 0b00;
    insn.lsl_lslv64dp2src._unnamed_2 = 0b0010;
    insn.lsl_lslv64dp2src.Rm = Rm;
    insn.lsl_lslv64dp2src._unnamed_1 = 0b11010110;
    insn.lsl_lslv64dp2src.S = 0b0;
    insn.lsl_lslv64dp2src._unnamed_0 = 0b0;
    insn.lsl_lslv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_lslv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lslv32dp2src.Rd = Rd;
    insn.lslv32dp2src.Rn = Rn;
    insn.lslv32dp2src.op2 = 0b00;
    insn.lslv32dp2src._unnamed_2 = 0b0010;
    insn.lslv32dp2src.Rm = Rm;
    insn.lslv32dp2src._unnamed_1 = 0b11010110;
    insn.lslv32dp2src.S = 0b0;
    insn.lslv32dp2src._unnamed_0 = 0b0;
    insn.lslv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_lslv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lslv64dp2src.Rd = Rd;
    insn.lslv64dp2src.Rn = Rn;
    insn.lslv64dp2src.op2 = 0b00;
    insn.lslv64dp2src._unnamed_2 = 0b0010;
    insn.lslv64dp2src.Rm = Rm;
    insn.lslv64dp2src._unnamed_1 = 0b11010110;
    insn.lslv64dp2src.S = 0b0;
    insn.lslv64dp2src._unnamed_0 = 0b0;
    insn.lslv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_lsr_lsrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lsr_lsrv32dp2src.Rd = Rd;
    insn.lsr_lsrv32dp2src.Rn = Rn;
    insn.lsr_lsrv32dp2src.op2 = 0b01;
    insn.lsr_lsrv32dp2src._unnamed_2 = 0b0010;
    insn.lsr_lsrv32dp2src.Rm = Rm;
    insn.lsr_lsrv32dp2src._unnamed_1 = 0b11010110;
    insn.lsr_lsrv32dp2src.S = 0b0;
    insn.lsr_lsrv32dp2src._unnamed_0 = 0b0;
    insn.lsr_lsrv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_lsr_lsrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lsr_lsrv64dp2src.Rd = Rd;
    insn.lsr_lsrv64dp2src.Rn = Rn;
    insn.lsr_lsrv64dp2src.op2 = 0b01;
    insn.lsr_lsrv64dp2src._unnamed_2 = 0b0010;
    insn.lsr_lsrv64dp2src.Rm = Rm;
    insn.lsr_lsrv64dp2src._unnamed_1 = 0b11010110;
    insn.lsr_lsrv64dp2src.S = 0b0;
    insn.lsr_lsrv64dp2src._unnamed_0 = 0b0;
    insn.lsr_lsrv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_lsrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lsrv32dp2src.Rd = Rd;
    insn.lsrv32dp2src.Rn = Rn;
    insn.lsrv32dp2src.op2 = 0b01;
    insn.lsrv32dp2src._unnamed_2 = 0b0010;
    insn.lsrv32dp2src.Rm = Rm;
    insn.lsrv32dp2src._unnamed_1 = 0b11010110;
    insn.lsrv32dp2src.S = 0b0;
    insn.lsrv32dp2src._unnamed_0 = 0b0;
    insn.lsrv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_lsrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.lsrv64dp2src.Rd = Rd;
    insn.lsrv64dp2src.Rn = Rn;
    insn.lsrv64dp2src.op2 = 0b01;
    insn.lsrv64dp2src._unnamed_2 = 0b0010;
    insn.lsrv64dp2src.Rm = Rm;
    insn.lsrv64dp2src._unnamed_1 = 0b11010110;
    insn.lsrv64dp2src.S = 0b0;
    insn.lsrv64dp2src._unnamed_0 = 0b0;
    insn.lsrv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_madd_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.madd32a_dp3src.Rd = Rd;
    insn.madd32a_dp3src.Rn = Rn;
    insn.madd32a_dp3src.Ra = Ra;
    insn.madd32a_dp3src.o0 = 0b0;
    insn.madd32a_dp3src.Rm = Rm;
    insn.madd32a_dp3src.op31 = 0b000;
    insn.madd32a_dp3src._unnamed_0 = 0b11011;
    insn.madd32a_dp3src.op54 = 0b00;
    insn.madd32a_dp3src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_madd_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.madd64a_dp3src.Rd = Rd;
    insn.madd64a_dp3src.Rn = Rn;
    insn.madd64a_dp3src.Ra = Ra;
    insn.madd64a_dp3src.o0 = 0b0;
    insn.madd64a_dp3src.Rm = Rm;
    insn.madd64a_dp3src.op31 = 0b000;
    insn.madd64a_dp3src._unnamed_0 = 0b11011;
    insn.madd64a_dp3src.op54 = 0b00;
    insn.madd64a_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_maddpt_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.maddpt64a_dp3src.Rd = Rd;
    insn.maddpt64a_dp3src.Rn = Rn;
    insn.maddpt64a_dp3src.Ra = Ra;
    insn.maddpt64a_dp3src.o0 = 0b0;
    insn.maddpt64a_dp3src.Rm = Rm;
    insn.maddpt64a_dp3src.op31 = 0b011;
    insn.maddpt64a_dp3src._unnamed_2 = 0b1;
    insn.maddpt64a_dp3src._unnamed_1 = 0b101;
    insn.maddpt64a_dp3src._unnamed_0 = 0b1;
    insn.maddpt64a_dp3src.op54 = 0b00;
    insn.maddpt64a_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mneg_msub_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.mneg_msub32a_dp3src.Rd = Rd;
    insn.mneg_msub32a_dp3src.Rn = Rn;
    insn.mneg_msub32a_dp3src.Ra = 0b11111;
    insn.mneg_msub32a_dp3src.o0 = 0b1;
    insn.mneg_msub32a_dp3src.Rm = Rm;
    insn.mneg_msub32a_dp3src.op31 = 0b000;
    insn.mneg_msub32a_dp3src._unnamed_0 = 0b11011;
    insn.mneg_msub32a_dp3src.op54 = 0b00;
    insn.mneg_msub32a_dp3src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mneg_msub_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.mneg_msub64a_dp3src.Rd = Rd;
    insn.mneg_msub64a_dp3src.Rn = Rn;
    insn.mneg_msub64a_dp3src.Ra = 0b11111;
    insn.mneg_msub64a_dp3src.o0 = 0b1;
    insn.mneg_msub64a_dp3src.Rm = Rm;
    insn.mneg_msub64a_dp3src.op31 = 0b000;
    insn.mneg_msub64a_dp3src._unnamed_0 = 0b11011;
    insn.mneg_msub64a_dp3src.op54 = 0b00;
    insn.mneg_msub64a_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mov_orr_32_log_shift(uint32_t Rd, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.mov_orr32log_shift.Rd = Rd;
    insn.mov_orr32log_shift.Rn = 0b11111;
    insn.mov_orr32log_shift.imm6 = 0b000000;
    insn.mov_orr32log_shift.Rm = Rm;
    insn.mov_orr32log_shift.N = 0b0;
    insn.mov_orr32log_shift.shift = 0b00;
    insn.mov_orr32log_shift._unnamed_0 = 0b01010;
    insn.mov_orr32log_shift.opc = 0b01;
    insn.mov_orr32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mov_orr_64_log_shift(uint32_t Rd, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.mov_orr64log_shift.Rd = Rd;
    insn.mov_orr64log_shift.Rn = 0b11111;
    insn.mov_orr64log_shift.imm6 = 0b000000;
    insn.mov_orr64log_shift.Rm = Rm;
    insn.mov_orr64log_shift.N = 0b0;
    insn.mov_orr64log_shift.shift = 0b00;
    insn.mov_orr64log_shift._unnamed_0 = 0b01010;
    insn.mov_orr64log_shift.opc = 0b01;
    insn.mov_orr64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_msub_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.msub32a_dp3src.Rd = Rd;
    insn.msub32a_dp3src.Rn = Rn;
    insn.msub32a_dp3src.Ra = Ra;
    insn.msub32a_dp3src.o0 = 0b1;
    insn.msub32a_dp3src.Rm = Rm;
    insn.msub32a_dp3src.op31 = 0b000;
    insn.msub32a_dp3src._unnamed_0 = 0b11011;
    insn.msub32a_dp3src.op54 = 0b00;
    insn.msub32a_dp3src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_msub_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.msub64a_dp3src.Rd = Rd;
    insn.msub64a_dp3src.Rn = Rn;
    insn.msub64a_dp3src.Ra = Ra;
    insn.msub64a_dp3src.o0 = 0b1;
    insn.msub64a_dp3src.Rm = Rm;
    insn.msub64a_dp3src.op31 = 0b000;
    insn.msub64a_dp3src._unnamed_0 = 0b11011;
    insn.msub64a_dp3src.op54 = 0b00;
    insn.msub64a_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_msubpt_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.msubpt64a_dp3src.Rd = Rd;
    insn.msubpt64a_dp3src.Rn = Rn;
    insn.msubpt64a_dp3src.Ra = Ra;
    insn.msubpt64a_dp3src.o0 = 0b1;
    insn.msubpt64a_dp3src.Rm = Rm;
    insn.msubpt64a_dp3src.op31 = 0b011;
    insn.msubpt64a_dp3src._unnamed_2 = 0b1;
    insn.msubpt64a_dp3src._unnamed_1 = 0b101;
    insn.msubpt64a_dp3src._unnamed_0 = 0b1;
    insn.msubpt64a_dp3src.op54 = 0b00;
    insn.msubpt64a_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mul_madd_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.mul_madd32a_dp3src.Rd = Rd;
    insn.mul_madd32a_dp3src.Rn = Rn;
    insn.mul_madd32a_dp3src.Ra = 0b11111;
    insn.mul_madd32a_dp3src.o0 = 0b0;
    insn.mul_madd32a_dp3src.Rm = Rm;
    insn.mul_madd32a_dp3src.op31 = 0b000;
    insn.mul_madd32a_dp3src._unnamed_0 = 0b11011;
    insn.mul_madd32a_dp3src.op54 = 0b00;
    insn.mul_madd32a_dp3src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mul_madd_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.mul_madd64a_dp3src.Rd = Rd;
    insn.mul_madd64a_dp3src.Rn = Rn;
    insn.mul_madd64a_dp3src.Ra = 0b11111;
    insn.mul_madd64a_dp3src.o0 = 0b0;
    insn.mul_madd64a_dp3src.Rm = Rm;
    insn.mul_madd64a_dp3src.op31 = 0b000;
    insn.mul_madd64a_dp3src._unnamed_0 = 0b11011;
    insn.mul_madd64a_dp3src.op54 = 0b00;
    insn.mul_madd64a_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_mvn_orn_32_log_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.mvn_orn32log_shift.Rd = Rd;
    insn.mvn_orn32log_shift.Rn = 0b11111;
    insn.mvn_orn32log_shift.imm6 = imm6;
    insn.mvn_orn32log_shift.Rm = Rm;
    insn.mvn_orn32log_shift.N = 0b1;
    insn.mvn_orn32log_shift.shift = shift;
    insn.mvn_orn32log_shift._unnamed_0 = 0b01010;
    insn.mvn_orn32log_shift.opc = 0b01;
    insn.mvn_orn32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_mvn_orn_64_log_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.mvn_orn64log_shift.Rd = Rd;
    insn.mvn_orn64log_shift.Rn = 0b11111;
    insn.mvn_orn64log_shift.imm6 = imm6;
    insn.mvn_orn64log_shift.Rm = Rm;
    insn.mvn_orn64log_shift.N = 0b1;
    insn.mvn_orn64log_shift.shift = shift;
    insn.mvn_orn64log_shift._unnamed_0 = 0b01010;
    insn.mvn_orn64log_shift.opc = 0b01;
    insn.mvn_orn64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_neg_sub_32_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.neg_sub32addsub_shift.Rd = Rd;
    insn.neg_sub32addsub_shift.Rn = 0b11111;
    insn.neg_sub32addsub_shift.imm6 = imm6;
    insn.neg_sub32addsub_shift.Rm = Rm;
    insn.neg_sub32addsub_shift._unnamed_1 = 0b0;
    insn.neg_sub32addsub_shift.shift = shift;
    insn.neg_sub32addsub_shift._unnamed_0 = 0b01011;
    insn.neg_sub32addsub_shift.S = 0b0;
    insn.neg_sub32addsub_shift.op = 0b1;
    insn.neg_sub32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_neg_sub_64_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.neg_sub64addsub_shift.Rd = Rd;
    insn.neg_sub64addsub_shift.Rn = 0b11111;
    insn.neg_sub64addsub_shift.imm6 = imm6;
    insn.neg_sub64addsub_shift.Rm = Rm;
    insn.neg_sub64addsub_shift._unnamed_1 = 0b0;
    insn.neg_sub64addsub_shift.shift = shift;
    insn.neg_sub64addsub_shift._unnamed_0 = 0b01011;
    insn.neg_sub64addsub_shift.S = 0b0;
    insn.neg_sub64addsub_shift.op = 0b1;
    insn.neg_sub64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_negs_subs_32_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.negs_subs32addsub_shift.Rd = Rd;
    insn.negs_subs32addsub_shift.Rn = 0b11111;
    insn.negs_subs32addsub_shift.imm6 = imm6;
    insn.negs_subs32addsub_shift.Rm = Rm;
    insn.negs_subs32addsub_shift._unnamed_1 = 0b0;
    insn.negs_subs32addsub_shift.shift = shift;
    insn.negs_subs32addsub_shift._unnamed_0 = 0b01011;
    insn.negs_subs32addsub_shift.S = 0b1;
    insn.negs_subs32addsub_shift.op = 0b1;
    insn.negs_subs32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_negs_subs_64_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.negs_subs64addsub_shift.Rd = Rd;
    insn.negs_subs64addsub_shift.Rn = 0b11111;
    insn.negs_subs64addsub_shift.imm6 = imm6;
    insn.negs_subs64addsub_shift.Rm = Rm;
    insn.negs_subs64addsub_shift._unnamed_1 = 0b0;
    insn.negs_subs64addsub_shift.shift = shift;
    insn.negs_subs64addsub_shift._unnamed_0 = 0b01011;
    insn.negs_subs64addsub_shift.S = 0b1;
    insn.negs_subs64addsub_shift.op = 0b1;
    insn.negs_subs64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ngc_sbc_32_addsub_carry(uint32_t Rd, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ngc_sbc32addsub_carry.Rd = Rd;
    insn.ngc_sbc32addsub_carry.Rn = 0b11111;
    insn.ngc_sbc32addsub_carry._unnamed_1 = 0b000000;
    insn.ngc_sbc32addsub_carry.Rm = Rm;
    insn.ngc_sbc32addsub_carry._unnamed_0 = 0b11010000;
    insn.ngc_sbc32addsub_carry.S = 0b0;
    insn.ngc_sbc32addsub_carry.op = 0b1;
    insn.ngc_sbc32addsub_carry.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ngc_sbc_64_addsub_carry(uint32_t Rd, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ngc_sbc64addsub_carry.Rd = Rd;
    insn.ngc_sbc64addsub_carry.Rn = 0b11111;
    insn.ngc_sbc64addsub_carry._unnamed_1 = 0b000000;
    insn.ngc_sbc64addsub_carry.Rm = Rm;
    insn.ngc_sbc64addsub_carry._unnamed_0 = 0b11010000;
    insn.ngc_sbc64addsub_carry.S = 0b0;
    insn.ngc_sbc64addsub_carry.op = 0b1;
    insn.ngc_sbc64addsub_carry.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ngcs_sbcs_32_addsub_carry(uint32_t Rd, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ngcs_sbcs32addsub_carry.Rd = Rd;
    insn.ngcs_sbcs32addsub_carry.Rn = 0b11111;
    insn.ngcs_sbcs32addsub_carry._unnamed_1 = 0b000000;
    insn.ngcs_sbcs32addsub_carry.Rm = Rm;
    insn.ngcs_sbcs32addsub_carry._unnamed_0 = 0b11010000;
    insn.ngcs_sbcs32addsub_carry.S = 0b1;
    insn.ngcs_sbcs32addsub_carry.op = 0b1;
    insn.ngcs_sbcs32addsub_carry.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ngcs_sbcs_64_addsub_carry(uint32_t Rd, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ngcs_sbcs64addsub_carry.Rd = Rd;
    insn.ngcs_sbcs64addsub_carry.Rn = 0b11111;
    insn.ngcs_sbcs64addsub_carry._unnamed_1 = 0b000000;
    insn.ngcs_sbcs64addsub_carry.Rm = Rm;
    insn.ngcs_sbcs64addsub_carry._unnamed_0 = 0b11010000;
    insn.ngcs_sbcs64addsub_carry.S = 0b1;
    insn.ngcs_sbcs64addsub_carry.op = 0b1;
    insn.ngcs_sbcs64addsub_carry.sf = 0b1;
    return insn.raw;
}

uint32_t encode_orn_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.orn32log_shift.Rd = Rd;
    insn.orn32log_shift.Rn = Rn;
    insn.orn32log_shift.imm6 = imm6;
    insn.orn32log_shift.Rm = Rm;
    insn.orn32log_shift.N = 0b1;
    insn.orn32log_shift.shift = shift;
    insn.orn32log_shift._unnamed_0 = 0b01010;
    insn.orn32log_shift.opc = 0b01;
    insn.orn32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_orn_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.orn64log_shift.Rd = Rd;
    insn.orn64log_shift.Rn = Rn;
    insn.orn64log_shift.imm6 = imm6;
    insn.orn64log_shift.Rm = Rm;
    insn.orn64log_shift.N = 0b1;
    insn.orn64log_shift.shift = shift;
    insn.orn64log_shift._unnamed_0 = 0b01010;
    insn.orn64log_shift.opc = 0b01;
    insn.orn64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_orr_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.orr32log_shift.Rd = Rd;
    insn.orr32log_shift.Rn = Rn;
    insn.orr32log_shift.imm6 = imm6;
    insn.orr32log_shift.Rm = Rm;
    insn.orr32log_shift.N = 0b0;
    insn.orr32log_shift.shift = shift;
    insn.orr32log_shift._unnamed_0 = 0b01010;
    insn.orr32log_shift.opc = 0b01;
    insn.orr32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_orr_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.orr64log_shift.Rd = Rd;
    insn.orr64log_shift.Rn = Rn;
    insn.orr64log_shift.imm6 = imm6;
    insn.orr64log_shift.Rm = Rm;
    insn.orr64log_shift.N = 0b0;
    insn.orr64log_shift.shift = shift;
    insn.orr64log_shift._unnamed_0 = 0b01010;
    insn.orr64log_shift.opc = 0b01;
    insn.orr64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacda_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.pacda64p_dp1src.Rd = Rd;
    insn.pacda64p_dp1src.Rn = Rn;
    insn.pacda64p_dp1src._unnamed_3 = 0b010;
    insn.pacda64p_dp1src.Z = 0b0;
    insn.pacda64p_dp1src._unnamed_2 = 0b00;
    insn.pacda64p_dp1src.opcode2 = 0b00001;
    insn.pacda64p_dp1src._unnamed_1 = 0b11010110;
    insn.pacda64p_dp1src.S = 0b0;
    insn.pacda64p_dp1src._unnamed_0 = 0b1;
    insn.pacda64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacdza_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.pacdza64z_dp1src.Rd = Rd;
    insn.pacdza64z_dp1src.Rn = 0b11111;
    insn.pacdza64z_dp1src._unnamed_3 = 0b010;
    insn.pacdza64z_dp1src.Z = 0b1;
    insn.pacdza64z_dp1src._unnamed_2 = 0b00;
    insn.pacdza64z_dp1src.opcode2 = 0b00001;
    insn.pacdza64z_dp1src._unnamed_1 = 0b11010110;
    insn.pacdza64z_dp1src.S = 0b0;
    insn.pacdza64z_dp1src._unnamed_0 = 0b1;
    insn.pacdza64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacdb_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.pacdb64p_dp1src.Rd = Rd;
    insn.pacdb64p_dp1src.Rn = Rn;
    insn.pacdb64p_dp1src._unnamed_3 = 0b011;
    insn.pacdb64p_dp1src.Z = 0b0;
    insn.pacdb64p_dp1src._unnamed_2 = 0b00;
    insn.pacdb64p_dp1src.opcode2 = 0b00001;
    insn.pacdb64p_dp1src._unnamed_1 = 0b11010110;
    insn.pacdb64p_dp1src.S = 0b0;
    insn.pacdb64p_dp1src._unnamed_0 = 0b1;
    insn.pacdb64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacdzb_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.pacdzb64z_dp1src.Rd = Rd;
    insn.pacdzb64z_dp1src.Rn = 0b11111;
    insn.pacdzb64z_dp1src._unnamed_3 = 0b011;
    insn.pacdzb64z_dp1src.Z = 0b1;
    insn.pacdzb64z_dp1src._unnamed_2 = 0b00;
    insn.pacdzb64z_dp1src.opcode2 = 0b00001;
    insn.pacdzb64z_dp1src._unnamed_1 = 0b11010110;
    insn.pacdzb64z_dp1src.S = 0b0;
    insn.pacdzb64z_dp1src._unnamed_0 = 0b1;
    insn.pacdzb64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacga_64p_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.pacga64p_dp2src.Rd = Rd;
    insn.pacga64p_dp2src.Rn = Rn;
    insn.pacga64p_dp2src.opcode = 0b001100;
    insn.pacga64p_dp2src.Rm = Rm;
    insn.pacga64p_dp2src._unnamed_3 = 0b0110;
    insn.pacga64p_dp2src._unnamed_2 = 0b101;
    insn.pacga64p_dp2src._unnamed_1 = 0b1;
    insn.pacga64p_dp2src.S = 0b0;
    insn.pacga64p_dp2src._unnamed_0 = 0b0;
    insn.pacga64p_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacia_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.pacia64p_dp1src.Rd = Rd;
    insn.pacia64p_dp1src.Rn = Rn;
    insn.pacia64p_dp1src._unnamed_3 = 0b000;
    insn.pacia64p_dp1src.Z = 0b0;
    insn.pacia64p_dp1src._unnamed_2 = 0b00;
    insn.pacia64p_dp1src.opcode2 = 0b00001;
    insn.pacia64p_dp1src._unnamed_1 = 0b11010110;
    insn.pacia64p_dp1src.S = 0b0;
    insn.pacia64p_dp1src._unnamed_0 = 0b1;
    insn.pacia64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_paciza_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.paciza64z_dp1src.Rd = Rd;
    insn.paciza64z_dp1src.Rn = 0b11111;
    insn.paciza64z_dp1src._unnamed_3 = 0b000;
    insn.paciza64z_dp1src.Z = 0b1;
    insn.paciza64z_dp1src._unnamed_2 = 0b00;
    insn.paciza64z_dp1src.opcode2 = 0b00001;
    insn.paciza64z_dp1src._unnamed_1 = 0b11010110;
    insn.paciza64z_dp1src.S = 0b0;
    insn.paciza64z_dp1src._unnamed_0 = 0b1;
    insn.paciza64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacia171615_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.pacia17161564lr_dp1src.Rd = 0b11110;
    insn.pacia17161564lr_dp1src.Rn = 0b11111;
    insn.pacia17161564lr_dp1src.opcode = 0b100010;
    insn.pacia17161564lr_dp1src.opcode2 = 0b00001;
    insn.pacia17161564lr_dp1src._unnamed_3 = 0b0110;
    insn.pacia17161564lr_dp1src._unnamed_2 = 0b101;
    insn.pacia17161564lr_dp1src._unnamed_1 = 0b1;
    insn.pacia17161564lr_dp1src.S = 0b0;
    insn.pacia17161564lr_dp1src._unnamed_0 = 0b1;
    insn.pacia17161564lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_paciasppc_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.paciasppc64lr_dp1src.Rd = 0b11110;
    insn.paciasppc64lr_dp1src.Rn = 0b11111;
    insn.paciasppc64lr_dp1src.opcode = 0b101000;
    insn.paciasppc64lr_dp1src.opcode2 = 0b00001;
    insn.paciasppc64lr_dp1src._unnamed_3 = 0b0110;
    insn.paciasppc64lr_dp1src._unnamed_2 = 0b101;
    insn.paciasppc64lr_dp1src._unnamed_1 = 0b1;
    insn.paciasppc64lr_dp1src.S = 0b0;
    insn.paciasppc64lr_dp1src._unnamed_0 = 0b1;
    insn.paciasppc64lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacib_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.pacib64p_dp1src.Rd = Rd;
    insn.pacib64p_dp1src.Rn = Rn;
    insn.pacib64p_dp1src._unnamed_3 = 0b001;
    insn.pacib64p_dp1src.Z = 0b0;
    insn.pacib64p_dp1src._unnamed_2 = 0b00;
    insn.pacib64p_dp1src.opcode2 = 0b00001;
    insn.pacib64p_dp1src._unnamed_1 = 0b11010110;
    insn.pacib64p_dp1src.S = 0b0;
    insn.pacib64p_dp1src._unnamed_0 = 0b1;
    insn.pacib64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacizb_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.pacizb64z_dp1src.Rd = Rd;
    insn.pacizb64z_dp1src.Rn = 0b11111;
    insn.pacizb64z_dp1src._unnamed_3 = 0b001;
    insn.pacizb64z_dp1src.Z = 0b1;
    insn.pacizb64z_dp1src._unnamed_2 = 0b00;
    insn.pacizb64z_dp1src.opcode2 = 0b00001;
    insn.pacizb64z_dp1src._unnamed_1 = 0b11010110;
    insn.pacizb64z_dp1src.S = 0b0;
    insn.pacizb64z_dp1src._unnamed_0 = 0b1;
    insn.pacizb64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacib171615_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.pacib17161564lr_dp1src.Rd = 0b11110;
    insn.pacib17161564lr_dp1src.Rn = 0b11111;
    insn.pacib17161564lr_dp1src.opcode = 0b100011;
    insn.pacib17161564lr_dp1src.opcode2 = 0b00001;
    insn.pacib17161564lr_dp1src._unnamed_3 = 0b0110;
    insn.pacib17161564lr_dp1src._unnamed_2 = 0b101;
    insn.pacib17161564lr_dp1src._unnamed_1 = 0b1;
    insn.pacib17161564lr_dp1src.S = 0b0;
    insn.pacib17161564lr_dp1src._unnamed_0 = 0b1;
    insn.pacib17161564lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacibsppc_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.pacibsppc64lr_dp1src.Rd = 0b11110;
    insn.pacibsppc64lr_dp1src.Rn = 0b11111;
    insn.pacibsppc64lr_dp1src.opcode = 0b101001;
    insn.pacibsppc64lr_dp1src.opcode2 = 0b00001;
    insn.pacibsppc64lr_dp1src._unnamed_3 = 0b0110;
    insn.pacibsppc64lr_dp1src._unnamed_2 = 0b101;
    insn.pacibsppc64lr_dp1src._unnamed_1 = 0b1;
    insn.pacibsppc64lr_dp1src.S = 0b0;
    insn.pacibsppc64lr_dp1src._unnamed_0 = 0b1;
    insn.pacibsppc64lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacnbiasppc_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.pacnbiasppc64lr_dp1src.Rd = 0b11110;
    insn.pacnbiasppc64lr_dp1src.Rn = 0b11111;
    insn.pacnbiasppc64lr_dp1src.opcode = 0b100000;
    insn.pacnbiasppc64lr_dp1src.opcode2 = 0b00001;
    insn.pacnbiasppc64lr_dp1src._unnamed_3 = 0b0110;
    insn.pacnbiasppc64lr_dp1src._unnamed_2 = 0b101;
    insn.pacnbiasppc64lr_dp1src._unnamed_1 = 0b1;
    insn.pacnbiasppc64lr_dp1src.S = 0b0;
    insn.pacnbiasppc64lr_dp1src._unnamed_0 = 0b1;
    insn.pacnbiasppc64lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacnbibsppc_64lr_dp_1src() {
    DpregEncoding insn = {};
    insn.pacnbibsppc64lr_dp1src.Rd = 0b11110;
    insn.pacnbibsppc64lr_dp1src.Rn = 0b11111;
    insn.pacnbibsppc64lr_dp1src.opcode = 0b100001;
    insn.pacnbibsppc64lr_dp1src.opcode2 = 0b00001;
    insn.pacnbibsppc64lr_dp1src._unnamed_3 = 0b0110;
    insn.pacnbibsppc64lr_dp1src._unnamed_2 = 0b101;
    insn.pacnbibsppc64lr_dp1src._unnamed_1 = 0b1;
    insn.pacnbibsppc64lr_dp1src.S = 0b0;
    insn.pacnbibsppc64lr_dp1src._unnamed_0 = 0b1;
    insn.pacnbibsppc64lr_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rbit_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rbit32dp1src.Rd = Rd;
    insn.rbit32dp1src.Rn = Rn;
    insn.rbit32dp1src.opcode = 0b000000;
    insn.rbit32dp1src.opcode2 = 0b00000;
    insn.rbit32dp1src._unnamed_1 = 0b11010110;
    insn.rbit32dp1src.S = 0b0;
    insn.rbit32dp1src._unnamed_0 = 0b1;
    insn.rbit32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_rbit_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rbit64dp1src.Rd = Rd;
    insn.rbit64dp1src.Rn = Rn;
    insn.rbit64dp1src.opcode = 0b000000;
    insn.rbit64dp1src.opcode2 = 0b00000;
    insn.rbit64dp1src._unnamed_1 = 0b11010110;
    insn.rbit64dp1src.S = 0b0;
    insn.rbit64dp1src._unnamed_0 = 0b1;
    insn.rbit64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rev_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rev32dp1src.Rd = Rd;
    insn.rev32dp1src.Rn = Rn;
    insn.rev32dp1src.opc = 0b10;
    insn.rev32dp1src._unnamed_2 = 0b0000;
    insn.rev32dp1src.opcode2 = 0b00000;
    insn.rev32dp1src._unnamed_1 = 0b11010110;
    insn.rev32dp1src.S = 0b0;
    insn.rev32dp1src._unnamed_0 = 0b1;
    insn.rev32dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_rev_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rev64dp1src.Rd = Rd;
    insn.rev64dp1src.Rn = Rn;
    insn.rev64dp1src.opc = 0b11;
    insn.rev64dp1src._unnamed_2 = 0b0000;
    insn.rev64dp1src.opcode2 = 0b00000;
    insn.rev64dp1src._unnamed_1 = 0b11010110;
    insn.rev64dp1src.S = 0b0;
    insn.rev64dp1src._unnamed_0 = 0b1;
    insn.rev64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rev16_32_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rev1632dp1src.Rd = Rd;
    insn.rev1632dp1src.Rn = Rn;
    insn.rev1632dp1src.opc = 0b01;
    insn.rev1632dp1src._unnamed_2 = 0b0000;
    insn.rev1632dp1src.opcode2 = 0b00000;
    insn.rev1632dp1src._unnamed_1 = 0b11010110;
    insn.rev1632dp1src.S = 0b0;
    insn.rev1632dp1src._unnamed_0 = 0b1;
    insn.rev1632dp1src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_rev16_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rev1664dp1src.Rd = Rd;
    insn.rev1664dp1src.Rn = Rn;
    insn.rev1664dp1src.opc = 0b01;
    insn.rev1664dp1src._unnamed_2 = 0b0000;
    insn.rev1664dp1src.opcode2 = 0b00000;
    insn.rev1664dp1src._unnamed_1 = 0b11010110;
    insn.rev1664dp1src.S = 0b0;
    insn.rev1664dp1src._unnamed_0 = 0b1;
    insn.rev1664dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rev32_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rev3264dp1src.Rd = Rd;
    insn.rev3264dp1src.Rn = Rn;
    insn.rev3264dp1src.opc = 0b10;
    insn.rev3264dp1src._unnamed_4 = 0b0000;
    insn.rev3264dp1src.opcode2 = 0b00000;
    insn.rev3264dp1src._unnamed_3 = 0b0110;
    insn.rev3264dp1src._unnamed_2 = 0b101;
    insn.rev3264dp1src._unnamed_1 = 0b1;
    insn.rev3264dp1src.S = 0b0;
    insn.rev3264dp1src._unnamed_0 = 0b1;
    insn.rev3264dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rev64_rev_64_dp_1src(uint32_t Rd, uint32_t Rn) {
    DpregEncoding insn = {};
    insn.rev64rev64dp1src.Rd = Rd;
    insn.rev64rev64dp1src.Rn = Rn;
    insn.rev64rev64dp1src.opc = 0b11;
    insn.rev64rev64dp1src._unnamed_4 = 0b0000;
    insn.rev64rev64dp1src.opcode2 = 0b00000;
    insn.rev64rev64dp1src._unnamed_3 = 0b0110;
    insn.rev64rev64dp1src._unnamed_2 = 0b101;
    insn.rev64rev64dp1src._unnamed_1 = 0b1;
    insn.rev64rev64dp1src.S = 0b0;
    insn.rev64rev64dp1src._unnamed_0 = 0b1;
    insn.rev64rev64dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rmif_only_rmif(uint32_t mask, uint32_t Rn, uint32_t imm6) {
    DpregEncoding insn = {};
    insn.rmif_only_rmif.mask = mask;
    insn.rmif_only_rmif.o2 = 0b0;
    insn.rmif_only_rmif.Rn = Rn;
    insn.rmif_only_rmif._unnamed_3 = 0b00001;
    insn.rmif_only_rmif.imm6 = imm6;
    insn.rmif_only_rmif._unnamed_2 = 0b0000;
    insn.rmif_only_rmif._unnamed_1 = 0b101;
    insn.rmif_only_rmif._unnamed_0 = 0b1;
    insn.rmif_only_rmif.S = 0b1;
    insn.rmif_only_rmif.op = 0b0;
    insn.rmif_only_rmif.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ror_rorv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ror_rorv32dp2src.Rd = Rd;
    insn.ror_rorv32dp2src.Rn = Rn;
    insn.ror_rorv32dp2src.op2 = 0b11;
    insn.ror_rorv32dp2src._unnamed_2 = 0b0010;
    insn.ror_rorv32dp2src.Rm = Rm;
    insn.ror_rorv32dp2src._unnamed_1 = 0b11010110;
    insn.ror_rorv32dp2src.S = 0b0;
    insn.ror_rorv32dp2src._unnamed_0 = 0b0;
    insn.ror_rorv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ror_rorv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.ror_rorv64dp2src.Rd = Rd;
    insn.ror_rorv64dp2src.Rn = Rn;
    insn.ror_rorv64dp2src.op2 = 0b11;
    insn.ror_rorv64dp2src._unnamed_2 = 0b0010;
    insn.ror_rorv64dp2src.Rm = Rm;
    insn.ror_rorv64dp2src._unnamed_1 = 0b11010110;
    insn.ror_rorv64dp2src.S = 0b0;
    insn.ror_rorv64dp2src._unnamed_0 = 0b0;
    insn.ror_rorv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_rorv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.rorv32dp2src.Rd = Rd;
    insn.rorv32dp2src.Rn = Rn;
    insn.rorv32dp2src.op2 = 0b11;
    insn.rorv32dp2src._unnamed_2 = 0b0010;
    insn.rorv32dp2src.Rm = Rm;
    insn.rorv32dp2src._unnamed_1 = 0b11010110;
    insn.rorv32dp2src.S = 0b0;
    insn.rorv32dp2src._unnamed_0 = 0b0;
    insn.rorv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_rorv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.rorv64dp2src.Rd = Rd;
    insn.rorv64dp2src.Rn = Rn;
    insn.rorv64dp2src.op2 = 0b11;
    insn.rorv64dp2src._unnamed_2 = 0b0010;
    insn.rorv64dp2src.Rm = Rm;
    insn.rorv64dp2src._unnamed_1 = 0b11010110;
    insn.rorv64dp2src.S = 0b0;
    insn.rorv64dp2src._unnamed_0 = 0b0;
    insn.rorv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sbc_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sbc32addsub_carry.Rd = Rd;
    insn.sbc32addsub_carry.Rn = Rn;
    insn.sbc32addsub_carry._unnamed_1 = 0b000000;
    insn.sbc32addsub_carry.Rm = Rm;
    insn.sbc32addsub_carry._unnamed_0 = 0b11010000;
    insn.sbc32addsub_carry.S = 0b0;
    insn.sbc32addsub_carry.op = 0b1;
    insn.sbc32addsub_carry.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sbc_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sbc64addsub_carry.Rd = Rd;
    insn.sbc64addsub_carry.Rn = Rn;
    insn.sbc64addsub_carry._unnamed_1 = 0b000000;
    insn.sbc64addsub_carry.Rm = Rm;
    insn.sbc64addsub_carry._unnamed_0 = 0b11010000;
    insn.sbc64addsub_carry.S = 0b0;
    insn.sbc64addsub_carry.op = 0b1;
    insn.sbc64addsub_carry.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sbcs_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sbcs32addsub_carry.Rd = Rd;
    insn.sbcs32addsub_carry.Rn = Rn;
    insn.sbcs32addsub_carry._unnamed_1 = 0b000000;
    insn.sbcs32addsub_carry.Rm = Rm;
    insn.sbcs32addsub_carry._unnamed_0 = 0b11010000;
    insn.sbcs32addsub_carry.S = 0b1;
    insn.sbcs32addsub_carry.op = 0b1;
    insn.sbcs32addsub_carry.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sbcs_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sbcs64addsub_carry.Rd = Rd;
    insn.sbcs64addsub_carry.Rn = Rn;
    insn.sbcs64addsub_carry._unnamed_1 = 0b000000;
    insn.sbcs64addsub_carry.Rm = Rm;
    insn.sbcs64addsub_carry._unnamed_0 = 0b11010000;
    insn.sbcs64addsub_carry.S = 0b1;
    insn.sbcs64addsub_carry.op = 0b1;
    insn.sbcs64addsub_carry.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sdiv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sdiv32dp2src.Rd = Rd;
    insn.sdiv32dp2src.Rn = Rn;
    insn.sdiv32dp2src.o1 = 0b1;
    insn.sdiv32dp2src._unnamed_2 = 0b00001;
    insn.sdiv32dp2src.Rm = Rm;
    insn.sdiv32dp2src._unnamed_1 = 0b11010110;
    insn.sdiv32dp2src.S = 0b0;
    insn.sdiv32dp2src._unnamed_0 = 0b0;
    insn.sdiv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sdiv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sdiv64dp2src.Rd = Rd;
    insn.sdiv64dp2src.Rn = Rn;
    insn.sdiv64dp2src.o1 = 0b1;
    insn.sdiv64dp2src._unnamed_2 = 0b00001;
    insn.sdiv64dp2src.Rm = Rm;
    insn.sdiv64dp2src._unnamed_1 = 0b11010110;
    insn.sdiv64dp2src.S = 0b0;
    insn.sdiv64dp2src._unnamed_0 = 0b0;
    insn.sdiv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_setf8_only_setf(uint32_t Rn) {
    DpregEncoding insn = {};
    insn.setf8only_setf.mask = 0b1101;
    insn.setf8only_setf.o3 = 0b0;
    insn.setf8only_setf.Rn = Rn;
    insn.setf8only_setf._unnamed_1 = 0b0010;
    insn.setf8only_setf.sz = 0b0;
    insn.setf8only_setf.opcode2 = 0b000000;
    insn.setf8only_setf._unnamed_0 = 0b11010000;
    insn.setf8only_setf.S = 0b1;
    insn.setf8only_setf.op = 0b0;
    insn.setf8only_setf.sf = 0b0;
    return insn.raw;
}

uint32_t encode_setf16_only_setf(uint32_t Rn) {
    DpregEncoding insn = {};
    insn.setf16only_setf.mask = 0b1101;
    insn.setf16only_setf.o3 = 0b0;
    insn.setf16only_setf.Rn = Rn;
    insn.setf16only_setf._unnamed_1 = 0b0010;
    insn.setf16only_setf.sz = 0b1;
    insn.setf16only_setf.opcode2 = 0b000000;
    insn.setf16only_setf._unnamed_0 = 0b11010000;
    insn.setf16only_setf.S = 0b1;
    insn.setf16only_setf.op = 0b0;
    insn.setf16only_setf.sf = 0b0;
    return insn.raw;
}

uint32_t encode_smaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smaddl64wa_dp3src.Rd = Rd;
    insn.smaddl64wa_dp3src.Rn = Rn;
    insn.smaddl64wa_dp3src.Ra = Ra;
    insn.smaddl64wa_dp3src.o0 = 0b0;
    insn.smaddl64wa_dp3src.Rm = Rm;
    insn.smaddl64wa_dp3src._unnamed_3 = 0b01;
    insn.smaddl64wa_dp3src.U = 0b0;
    insn.smaddl64wa_dp3src._unnamed_2 = 0b1;
    insn.smaddl64wa_dp3src._unnamed_1 = 0b101;
    insn.smaddl64wa_dp3src._unnamed_0 = 0b1;
    insn.smaddl64wa_dp3src.op54 = 0b00;
    insn.smaddl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smax_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smax32dp2src.Rd = Rd;
    insn.smax32dp2src.Rn = Rn;
    insn.smax32dp2src.opcode = 0b011000;
    insn.smax32dp2src.Rm = Rm;
    insn.smax32dp2src._unnamed_1 = 0b11010110;
    insn.smax32dp2src.S = 0b0;
    insn.smax32dp2src._unnamed_0 = 0b0;
    insn.smax32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_smax_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smax64dp2src.Rd = Rd;
    insn.smax64dp2src.Rn = Rn;
    insn.smax64dp2src.opcode = 0b011000;
    insn.smax64dp2src.Rm = Rm;
    insn.smax64dp2src._unnamed_1 = 0b11010110;
    insn.smax64dp2src.S = 0b0;
    insn.smax64dp2src._unnamed_0 = 0b0;
    insn.smax64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smin_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smin32dp2src.Rd = Rd;
    insn.smin32dp2src.Rn = Rn;
    insn.smin32dp2src.opcode = 0b011010;
    insn.smin32dp2src.Rm = Rm;
    insn.smin32dp2src._unnamed_1 = 0b11010110;
    insn.smin32dp2src.S = 0b0;
    insn.smin32dp2src._unnamed_0 = 0b0;
    insn.smin32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_smin_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smin64dp2src.Rd = Rd;
    insn.smin64dp2src.Rn = Rn;
    insn.smin64dp2src.opcode = 0b011010;
    insn.smin64dp2src.Rm = Rm;
    insn.smin64dp2src._unnamed_1 = 0b11010110;
    insn.smin64dp2src.S = 0b0;
    insn.smin64dp2src._unnamed_0 = 0b0;
    insn.smin64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smnegl_smsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smnegl_smsubl64wa_dp3src.Rd = Rd;
    insn.smnegl_smsubl64wa_dp3src.Rn = Rn;
    insn.smnegl_smsubl64wa_dp3src.Ra = 0b11111;
    insn.smnegl_smsubl64wa_dp3src.o0 = 0b1;
    insn.smnegl_smsubl64wa_dp3src.Rm = Rm;
    insn.smnegl_smsubl64wa_dp3src._unnamed_3 = 0b01;
    insn.smnegl_smsubl64wa_dp3src.U = 0b0;
    insn.smnegl_smsubl64wa_dp3src._unnamed_2 = 0b1;
    insn.smnegl_smsubl64wa_dp3src._unnamed_1 = 0b101;
    insn.smnegl_smsubl64wa_dp3src._unnamed_0 = 0b1;
    insn.smnegl_smsubl64wa_dp3src.op54 = 0b00;
    insn.smnegl_smsubl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smsubl64wa_dp3src.Rd = Rd;
    insn.smsubl64wa_dp3src.Rn = Rn;
    insn.smsubl64wa_dp3src.Ra = Ra;
    insn.smsubl64wa_dp3src.o0 = 0b1;
    insn.smsubl64wa_dp3src.Rm = Rm;
    insn.smsubl64wa_dp3src._unnamed_3 = 0b01;
    insn.smsubl64wa_dp3src.U = 0b0;
    insn.smsubl64wa_dp3src._unnamed_2 = 0b1;
    insn.smsubl64wa_dp3src._unnamed_1 = 0b101;
    insn.smsubl64wa_dp3src._unnamed_0 = 0b1;
    insn.smsubl64wa_dp3src.op54 = 0b00;
    insn.smsubl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smulh_64_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smulh64dp3src.Rd = Rd;
    insn.smulh64dp3src.Rn = Rn;
    insn.smulh64dp3src.Ra = 0b11111;
    insn.smulh64dp3src.o0 = 0b0;
    insn.smulh64dp3src.Rm = Rm;
    insn.smulh64dp3src._unnamed_3 = 0b10;
    insn.smulh64dp3src.U = 0b0;
    insn.smulh64dp3src._unnamed_2 = 0b1;
    insn.smulh64dp3src._unnamed_1 = 0b101;
    insn.smulh64dp3src._unnamed_0 = 0b1;
    insn.smulh64dp3src.op54 = 0b00;
    insn.smulh64dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_smull_smaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.smull_smaddl64wa_dp3src.Rd = Rd;
    insn.smull_smaddl64wa_dp3src.Rn = Rn;
    insn.smull_smaddl64wa_dp3src.Ra = 0b11111;
    insn.smull_smaddl64wa_dp3src.o0 = 0b0;
    insn.smull_smaddl64wa_dp3src.Rm = Rm;
    insn.smull_smaddl64wa_dp3src._unnamed_3 = 0b01;
    insn.smull_smaddl64wa_dp3src.U = 0b0;
    insn.smull_smaddl64wa_dp3src._unnamed_2 = 0b1;
    insn.smull_smaddl64wa_dp3src._unnamed_1 = 0b101;
    insn.smull_smaddl64wa_dp3src._unnamed_0 = 0b1;
    insn.smull_smaddl64wa_dp3src.op54 = 0b00;
    insn.smull_smaddl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sub_32_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sub32addsub_ext.Rd = Rd;
    insn.sub32addsub_ext.Rn = Rn;
    insn.sub32addsub_ext.imm3 = imm3;
    insn.sub32addsub_ext.option = option;
    insn.sub32addsub_ext.Rm = Rm;
    insn.sub32addsub_ext._unnamed_1 = 0b1;
    insn.sub32addsub_ext.opt = 0b00;
    insn.sub32addsub_ext._unnamed_0 = 0b01011;
    insn.sub32addsub_ext.S = 0b0;
    insn.sub32addsub_ext.op = 0b1;
    insn.sub32addsub_ext.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sub_64_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.sub64addsub_ext.Rd = Rd;
    insn.sub64addsub_ext.Rn = Rn;
    insn.sub64addsub_ext.imm3 = imm3;
    insn.sub64addsub_ext.option = option;
    insn.sub64addsub_ext.Rm = Rm;
    insn.sub64addsub_ext._unnamed_1 = 0b1;
    insn.sub64addsub_ext.opt = 0b00;
    insn.sub64addsub_ext._unnamed_0 = 0b01011;
    insn.sub64addsub_ext.S = 0b0;
    insn.sub64addsub_ext.op = 0b1;
    insn.sub64addsub_ext.sf = 0b1;
    return insn.raw;
}

uint32_t encode_sub_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.sub32addsub_shift.Rd = Rd;
    insn.sub32addsub_shift.Rn = Rn;
    insn.sub32addsub_shift.imm6 = imm6;
    insn.sub32addsub_shift.Rm = Rm;
    insn.sub32addsub_shift._unnamed_1 = 0b0;
    insn.sub32addsub_shift.shift = shift;
    insn.sub32addsub_shift._unnamed_0 = 0b01011;
    insn.sub32addsub_shift.S = 0b0;
    insn.sub32addsub_shift.op = 0b1;
    insn.sub32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_sub_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.sub64addsub_shift.Rd = Rd;
    insn.sub64addsub_shift.Rn = Rn;
    insn.sub64addsub_shift.imm6 = imm6;
    insn.sub64addsub_shift.Rm = Rm;
    insn.sub64addsub_shift._unnamed_1 = 0b0;
    insn.sub64addsub_shift.shift = shift;
    insn.sub64addsub_shift._unnamed_0 = 0b01011;
    insn.sub64addsub_shift.S = 0b0;
    insn.sub64addsub_shift.op = 0b1;
    insn.sub64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subp_64s_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.subp64s_dp2src.Rd = Rd;
    insn.subp64s_dp2src.Rn = Rn;
    insn.subp64s_dp2src.opcode = 0b000000;
    insn.subp64s_dp2src.Rm = Rm;
    insn.subp64s_dp2src._unnamed_3 = 0b0110;
    insn.subp64s_dp2src._unnamed_2 = 0b101;
    insn.subp64s_dp2src._unnamed_1 = 0b1;
    insn.subp64s_dp2src.S = 0b0;
    insn.subp64s_dp2src._unnamed_0 = 0b0;
    insn.subp64s_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subps_64s_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.subps64s_dp2src.Rd = Rd;
    insn.subps64s_dp2src.Rn = Rn;
    insn.subps64s_dp2src.opcode = 0b000000;
    insn.subps64s_dp2src.Rm = Rm;
    insn.subps64s_dp2src._unnamed_3 = 0b0110;
    insn.subps64s_dp2src._unnamed_2 = 0b101;
    insn.subps64s_dp2src._unnamed_1 = 0b1;
    insn.subps64s_dp2src.S = 0b1;
    insn.subps64s_dp2src._unnamed_0 = 0b0;
    insn.subps64s_dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subpt_64_addsub_pt(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.subpt64addsub_pt.Rd = Rd;
    insn.subpt64addsub_pt.Rn = Rn;
    insn.subpt64addsub_pt.imm3 = imm3;
    insn.subpt64addsub_pt._unnamed_3 = 0b001;
    insn.subpt64addsub_pt.Rm = Rm;
    insn.subpt64addsub_pt._unnamed_2 = 0b0000;
    insn.subpt64addsub_pt._unnamed_1 = 0b101;
    insn.subpt64addsub_pt._unnamed_0 = 0b1;
    insn.subpt64addsub_pt.S = 0b0;
    insn.subpt64addsub_pt.op = 0b1;
    insn.subpt64addsub_pt.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subs_32s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.subs32s_addsub_ext.Rd = Rd;
    insn.subs32s_addsub_ext.Rn = Rn;
    insn.subs32s_addsub_ext.imm3 = imm3;
    insn.subs32s_addsub_ext.option = option;
    insn.subs32s_addsub_ext.Rm = Rm;
    insn.subs32s_addsub_ext._unnamed_1 = 0b1;
    insn.subs32s_addsub_ext.opt = 0b00;
    insn.subs32s_addsub_ext._unnamed_0 = 0b01011;
    insn.subs32s_addsub_ext.S = 0b1;
    insn.subs32s_addsub_ext.op = 0b1;
    insn.subs32s_addsub_ext.sf = 0b0;
    return insn.raw;
}

uint32_t encode_subs_64s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.subs64s_addsub_ext.Rd = Rd;
    insn.subs64s_addsub_ext.Rn = Rn;
    insn.subs64s_addsub_ext.imm3 = imm3;
    insn.subs64s_addsub_ext.option = option;
    insn.subs64s_addsub_ext.Rm = Rm;
    insn.subs64s_addsub_ext._unnamed_1 = 0b1;
    insn.subs64s_addsub_ext.opt = 0b00;
    insn.subs64s_addsub_ext._unnamed_0 = 0b01011;
    insn.subs64s_addsub_ext.S = 0b1;
    insn.subs64s_addsub_ext.op = 0b1;
    insn.subs64s_addsub_ext.sf = 0b1;
    return insn.raw;
}

uint32_t encode_subs_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.subs32addsub_shift.Rd = Rd;
    insn.subs32addsub_shift.Rn = Rn;
    insn.subs32addsub_shift.imm6 = imm6;
    insn.subs32addsub_shift.Rm = Rm;
    insn.subs32addsub_shift._unnamed_1 = 0b0;
    insn.subs32addsub_shift.shift = shift;
    insn.subs32addsub_shift._unnamed_0 = 0b01011;
    insn.subs32addsub_shift.S = 0b1;
    insn.subs32addsub_shift.op = 0b1;
    insn.subs32addsub_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_subs_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.subs64addsub_shift.Rd = Rd;
    insn.subs64addsub_shift.Rn = Rn;
    insn.subs64addsub_shift.imm6 = imm6;
    insn.subs64addsub_shift.Rm = Rm;
    insn.subs64addsub_shift._unnamed_1 = 0b0;
    insn.subs64addsub_shift.shift = shift;
    insn.subs64addsub_shift._unnamed_0 = 0b01011;
    insn.subs64addsub_shift.S = 0b1;
    insn.subs64addsub_shift.op = 0b1;
    insn.subs64addsub_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_tst_ands_32_log_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.tst_ands32log_shift.Rd = 0b11111;
    insn.tst_ands32log_shift.Rn = Rn;
    insn.tst_ands32log_shift.imm6 = imm6;
    insn.tst_ands32log_shift.Rm = Rm;
    insn.tst_ands32log_shift.N = 0b0;
    insn.tst_ands32log_shift.shift = shift;
    insn.tst_ands32log_shift._unnamed_0 = 0b01010;
    insn.tst_ands32log_shift.opc = 0b11;
    insn.tst_ands32log_shift.sf = 0b0;
    return insn.raw;
}

uint32_t encode_tst_ands_64_log_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift) {
    DpregEncoding insn = {};
    insn.tst_ands64log_shift.Rd = 0b11111;
    insn.tst_ands64log_shift.Rn = Rn;
    insn.tst_ands64log_shift.imm6 = imm6;
    insn.tst_ands64log_shift.Rm = Rm;
    insn.tst_ands64log_shift.N = 0b0;
    insn.tst_ands64log_shift.shift = shift;
    insn.tst_ands64log_shift._unnamed_0 = 0b01010;
    insn.tst_ands64log_shift.opc = 0b11;
    insn.tst_ands64log_shift.sf = 0b1;
    return insn.raw;
}

uint32_t encode_udiv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.udiv32dp2src.Rd = Rd;
    insn.udiv32dp2src.Rn = Rn;
    insn.udiv32dp2src.o1 = 0b0;
    insn.udiv32dp2src._unnamed_2 = 0b00001;
    insn.udiv32dp2src.Rm = Rm;
    insn.udiv32dp2src._unnamed_1 = 0b11010110;
    insn.udiv32dp2src.S = 0b0;
    insn.udiv32dp2src._unnamed_0 = 0b0;
    insn.udiv32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_udiv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.udiv64dp2src.Rd = Rd;
    insn.udiv64dp2src.Rn = Rn;
    insn.udiv64dp2src.o1 = 0b0;
    insn.udiv64dp2src._unnamed_2 = 0b00001;
    insn.udiv64dp2src.Rm = Rm;
    insn.udiv64dp2src._unnamed_1 = 0b11010110;
    insn.udiv64dp2src.S = 0b0;
    insn.udiv64dp2src._unnamed_0 = 0b0;
    insn.udiv64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umaddl64wa_dp3src.Rd = Rd;
    insn.umaddl64wa_dp3src.Rn = Rn;
    insn.umaddl64wa_dp3src.Ra = Ra;
    insn.umaddl64wa_dp3src.o0 = 0b0;
    insn.umaddl64wa_dp3src.Rm = Rm;
    insn.umaddl64wa_dp3src._unnamed_3 = 0b01;
    insn.umaddl64wa_dp3src.U = 0b1;
    insn.umaddl64wa_dp3src._unnamed_2 = 0b1;
    insn.umaddl64wa_dp3src._unnamed_1 = 0b101;
    insn.umaddl64wa_dp3src._unnamed_0 = 0b1;
    insn.umaddl64wa_dp3src.op54 = 0b00;
    insn.umaddl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umax_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umax32dp2src.Rd = Rd;
    insn.umax32dp2src.Rn = Rn;
    insn.umax32dp2src.opcode = 0b011001;
    insn.umax32dp2src.Rm = Rm;
    insn.umax32dp2src._unnamed_1 = 0b11010110;
    insn.umax32dp2src.S = 0b0;
    insn.umax32dp2src._unnamed_0 = 0b0;
    insn.umax32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_umax_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umax64dp2src.Rd = Rd;
    insn.umax64dp2src.Rn = Rn;
    insn.umax64dp2src.opcode = 0b011001;
    insn.umax64dp2src.Rm = Rm;
    insn.umax64dp2src._unnamed_1 = 0b11010110;
    insn.umax64dp2src.S = 0b0;
    insn.umax64dp2src._unnamed_0 = 0b0;
    insn.umax64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umin_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umin32dp2src.Rd = Rd;
    insn.umin32dp2src.Rn = Rn;
    insn.umin32dp2src.opcode = 0b011011;
    insn.umin32dp2src.Rm = Rm;
    insn.umin32dp2src._unnamed_1 = 0b11010110;
    insn.umin32dp2src.S = 0b0;
    insn.umin32dp2src._unnamed_0 = 0b0;
    insn.umin32dp2src.sf = 0b0;
    return insn.raw;
}

uint32_t encode_umin_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umin64dp2src.Rd = Rd;
    insn.umin64dp2src.Rn = Rn;
    insn.umin64dp2src.opcode = 0b011011;
    insn.umin64dp2src.Rm = Rm;
    insn.umin64dp2src._unnamed_1 = 0b11010110;
    insn.umin64dp2src.S = 0b0;
    insn.umin64dp2src._unnamed_0 = 0b0;
    insn.umin64dp2src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umnegl_umsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umnegl_umsubl64wa_dp3src.Rd = Rd;
    insn.umnegl_umsubl64wa_dp3src.Rn = Rn;
    insn.umnegl_umsubl64wa_dp3src.Ra = 0b11111;
    insn.umnegl_umsubl64wa_dp3src.o0 = 0b1;
    insn.umnegl_umsubl64wa_dp3src.Rm = Rm;
    insn.umnegl_umsubl64wa_dp3src._unnamed_3 = 0b01;
    insn.umnegl_umsubl64wa_dp3src.U = 0b1;
    insn.umnegl_umsubl64wa_dp3src._unnamed_2 = 0b1;
    insn.umnegl_umsubl64wa_dp3src._unnamed_1 = 0b101;
    insn.umnegl_umsubl64wa_dp3src._unnamed_0 = 0b1;
    insn.umnegl_umsubl64wa_dp3src.op54 = 0b00;
    insn.umnegl_umsubl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umsubl64wa_dp3src.Rd = Rd;
    insn.umsubl64wa_dp3src.Rn = Rn;
    insn.umsubl64wa_dp3src.Ra = Ra;
    insn.umsubl64wa_dp3src.o0 = 0b1;
    insn.umsubl64wa_dp3src.Rm = Rm;
    insn.umsubl64wa_dp3src._unnamed_3 = 0b01;
    insn.umsubl64wa_dp3src.U = 0b1;
    insn.umsubl64wa_dp3src._unnamed_2 = 0b1;
    insn.umsubl64wa_dp3src._unnamed_1 = 0b101;
    insn.umsubl64wa_dp3src._unnamed_0 = 0b1;
    insn.umsubl64wa_dp3src.op54 = 0b00;
    insn.umsubl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umulh_64_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umulh64dp3src.Rd = Rd;
    insn.umulh64dp3src.Rn = Rn;
    insn.umulh64dp3src.Ra = 0b11111;
    insn.umulh64dp3src.o0 = 0b0;
    insn.umulh64dp3src.Rm = Rm;
    insn.umulh64dp3src._unnamed_3 = 0b10;
    insn.umulh64dp3src.U = 0b1;
    insn.umulh64dp3src._unnamed_2 = 0b1;
    insn.umulh64dp3src._unnamed_1 = 0b101;
    insn.umulh64dp3src._unnamed_0 = 0b1;
    insn.umulh64dp3src.op54 = 0b00;
    insn.umulh64dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_umull_umaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    DpregEncoding insn = {};
    insn.umull_umaddl64wa_dp3src.Rd = Rd;
    insn.umull_umaddl64wa_dp3src.Rn = Rn;
    insn.umull_umaddl64wa_dp3src.Ra = 0b11111;
    insn.umull_umaddl64wa_dp3src.o0 = 0b0;
    insn.umull_umaddl64wa_dp3src.Rm = Rm;
    insn.umull_umaddl64wa_dp3src._unnamed_3 = 0b01;
    insn.umull_umaddl64wa_dp3src.U = 0b1;
    insn.umull_umaddl64wa_dp3src._unnamed_2 = 0b1;
    insn.umull_umaddl64wa_dp3src._unnamed_1 = 0b101;
    insn.umull_umaddl64wa_dp3src._unnamed_0 = 0b1;
    insn.umull_umaddl64wa_dp3src.op54 = 0b00;
    insn.umull_umaddl64wa_dp3src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_xpacd_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.xpacd64z_dp1src.Rd = Rd;
    insn.xpacd64z_dp1src.Rn = 0b11111;
    insn.xpacd64z_dp1src.D = 0b1;
    insn.xpacd64z_dp1src._unnamed_2 = 0b01000;
    insn.xpacd64z_dp1src.opcode2 = 0b00001;
    insn.xpacd64z_dp1src._unnamed_1 = 0b11010110;
    insn.xpacd64z_dp1src.S = 0b0;
    insn.xpacd64z_dp1src._unnamed_0 = 0b1;
    insn.xpacd64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_xpaci_64z_dp_1src(uint32_t Rd) {
    DpregEncoding insn = {};
    insn.xpaci64z_dp1src.Rd = Rd;
    insn.xpaci64z_dp1src.Rn = 0b11111;
    insn.xpaci64z_dp1src.D = 0b0;
    insn.xpaci64z_dp1src._unnamed_2 = 0b01000;
    insn.xpaci64z_dp1src.opcode2 = 0b00001;
    insn.xpaci64z_dp1src._unnamed_1 = 0b11010110;
    insn.xpaci64z_dp1src.S = 0b0;
    insn.xpaci64z_dp1src._unnamed_0 = 0b1;
    insn.xpaci64z_dp1src.sf = 0b1;
    return insn.raw;
}

// Decode a dpreg instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_dpreg(uint32_t insn) {
    // Switch for mask 0xFFFFFFFFu (8 patterns, 8 encodings)
    switch (insn & 0xFFFFFFFFu) {
        case 0xDAC183FEu: { // PACNBIASPPC_64LR_dp_1src
                        Instruction result(Mnemonic::PACNBIASPPC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC187FEu: { // PACNBIBSPPC_64LR_dp_1src
                        Instruction result(Mnemonic::PACNBIBSPPC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC18BFEu: { // PACIA171615_64LR_dp_1src
                        Instruction result(Mnemonic::PACIA171615, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC18FFEu: { // PACIB171615_64LR_dp_1src
                        Instruction result(Mnemonic::PACIB171615, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC1A3FEu: { // PACIASPPC_64LR_dp_1src
                        Instruction result(Mnemonic::PACIASPPC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC1A7FEu: { // PACIBSPPC_64LR_dp_1src
                        Instruction result(Mnemonic::PACIBSPPC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC1BBFEu: { // AUTIA171615_64LR_dp_1src
                        Instruction result(Mnemonic::AUTIA171615, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xDAC1BFFEu: { // AUTIB171615_64LR_dp_1src
                        Instruction result(Mnemonic::AUTIB171615, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFFE0u (10 patterns, 10 encodings)
    switch (insn & 0xFFFFFFE0u) {
        case 0xDAC123E0u: { // PACIZA_64Z_dp_1src
                        Instruction result(Mnemonic::PACIZA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.paciza64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC127E0u: { // PACIZB_64Z_dp_1src
                        Instruction result(Mnemonic::PACIZB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacizb64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC12BE0u: { // PACDZA_64Z_dp_1src
                        Instruction result(Mnemonic::PACDZA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacdza64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC12FE0u: { // PACDZB_64Z_dp_1src
                        Instruction result(Mnemonic::PACDZB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacdzb64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC133E0u: { // AUTIZA_64Z_dp_1src
                        Instruction result(Mnemonic::AUTIZA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autiza64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC137E0u: { // AUTIZB_64Z_dp_1src
                        Instruction result(Mnemonic::AUTIZB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autizb64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC13BE0u: { // AUTDZA_64Z_dp_1src
                        Instruction result(Mnemonic::AUTDZA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autdza64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC13FE0u: { // AUTDZB_64Z_dp_1src
                        Instruction result(Mnemonic::AUTDZB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autdzb64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC143E0u: { // XPACI_64Z_dp_1src
                        Instruction result(Mnemonic::XPACI, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.xpaci64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC147E0u: { // XPACD_64Z_dp_1src
                        Instruction result(Mnemonic::XPACD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.xpacd64z_dp1src.Rd, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFC1Fu (4 patterns, 4 encodings)
    switch (insn & 0xFFFFFC1Fu) {
        case 0x3A00080Du: { // SETF8_only_setf
                        Instruction result(Mnemonic::SETF8, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.setf8only_setf.Rn, is_64bit));
                        return result;
        }
        case 0x3A00480Du: { // SETF16_only_setf
                        Instruction result(Mnemonic::SETF16, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.setf16only_setf.Rn, is_64bit));
                        return result;
        }
        case 0xDAC1901Eu: { // AUTIASPPCR_64LRR_dp_1src
                        Instruction result(Mnemonic::AUTIASPPCR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autiasppcr64lrr_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC1941Eu: { // AUTIBSPPCR_64LRR_dp_1src
                        Instruction result(Mnemonic::AUTIBSPPCR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autibsppcr64lrr_dp1src.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFC00u (25 patterns, 26 encodings)
    switch (insn & 0xFFFFFC00u) {
        case 0x5AC00000u: { // RBIT_32_dp_1src
                        Instruction result(Mnemonic::RBIT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.rbit32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rbit32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC00400u: { // REV16_32_dp_1src
                        Instruction result(Mnemonic::REV16, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.rev1632dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rev1632dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC00800u: { // REV_32_dp_1src
                        Instruction result(Mnemonic::REV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.rev32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rev32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC01000u: { // CLZ_32_dp_1src
                        Instruction result(Mnemonic::CLZ, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.clz32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.clz32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC01400u: { // CLS_32_dp_1src
                        Instruction result(Mnemonic::CLS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cls32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cls32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC01800u: { // CTZ_32_dp_1src
                        Instruction result(Mnemonic::CTZ, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ctz32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ctz32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC01C00u: { // CNT_32_dp_1src
                        Instruction result(Mnemonic::CNT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cnt32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cnt32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0x5AC02000u: { // ABS_32_dp_1src
                        Instruction result(Mnemonic::ABS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.abs32dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.abs32dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC00000u: { // RBIT_64_dp_1src
                        Instruction result(Mnemonic::RBIT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.rbit64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rbit64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC00400u: { // REV16_64_dp_1src
                        Instruction result(Mnemonic::REV16, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.rev1664dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rev1664dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC00800u: { // REV32_64_dp_1src
                        Instruction result(Mnemonic::REV32, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.rev3264dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rev3264dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC00C00u: { // REV_64_dp_1src
            // Also matches: REV64_REV_64_dp_1src (REV)
                        Instruction result(Mnemonic::REV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.rev64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.rev64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC01000u: { // CLZ_64_dp_1src
                        Instruction result(Mnemonic::CLZ, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.clz64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.clz64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC01400u: { // CLS_64_dp_1src
                        Instruction result(Mnemonic::CLS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cls64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cls64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC01800u: { // CTZ_64_dp_1src
                        Instruction result(Mnemonic::CTZ, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ctz64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ctz64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC01C00u: { // CNT_64_dp_1src
                        Instruction result(Mnemonic::CNT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cnt64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cnt64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC02000u: { // ABS_64_dp_1src
                        Instruction result(Mnemonic::ABS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.abs64dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.abs64dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC10000u: { // PACIA_64P_dp_1src
                        Instruction result(Mnemonic::PACIA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacia64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacia64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC10400u: { // PACIB_64P_dp_1src
                        Instruction result(Mnemonic::PACIB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacib64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacib64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC10800u: { // PACDA_64P_dp_1src
                        Instruction result(Mnemonic::PACDA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacda64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacda64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC10C00u: { // PACDB_64P_dp_1src
                        Instruction result(Mnemonic::PACDB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacdb64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacdb64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC11000u: { // AUTIA_64P_dp_1src
                        Instruction result(Mnemonic::AUTIA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autia64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.autia64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC11400u: { // AUTIB_64P_dp_1src
                        Instruction result(Mnemonic::AUTIB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autib64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.autib64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC11800u: { // AUTDA_64P_dp_1src
                        Instruction result(Mnemonic::AUTDA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autda64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.autda64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC11C00u: { // AUTDB_64P_dp_1src
                        Instruction result(Mnemonic::AUTDB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autdb64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.autdb64p_dp1src.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF0FE0u (4 patterns, 4 encodings)
    switch (insn & 0xFFFF0FE0u) {
        case 0x1A9F07E0u: { // CSET_CSINC_32_condsel
                        Instruction result(Mnemonic::CSINC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cset_csinc32condsel.Rd, is_64bit));
                        result.condition = static_cast<Condition>(enc.cset_csinc32condsel.cond);
                        return result;
        }
        case 0x5A9F03E0u: { // CSETM_CSINV_32_condsel
                        Instruction result(Mnemonic::CSINV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.csetm_csinv32condsel.Rd, is_64bit));
                        result.condition = static_cast<Condition>(enc.csetm_csinv32condsel.cond);
                        return result;
        }
        case 0x9A9F07E0u: { // CSET_CSINC_64_condsel
                        Instruction result(Mnemonic::CSINC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cset_csinc64condsel.Rd, is_64bit));
                        result.condition = static_cast<Condition>(enc.cset_csinc64condsel.cond);
                        return result;
        }
        case 0xDA9F03E0u: { // CSETM_CSINV_64_condsel
                        Instruction result(Mnemonic::CSINV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.csetm_csinv64condsel.Rd, is_64bit));
                        result.condition = static_cast<Condition>(enc.csetm_csinv64condsel.cond);
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0FFE0u (6 patterns, 6 encodings)
    switch (insn & 0xFFE0FFE0u) {
        case 0x2A0003E0u: { // MOV_ORR_32_log_shift
                        Instruction result(Mnemonic::ORR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_orr32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_orr32log_shift.Rm, is_64bit));
                        return result;
        }
        case 0x5A0003E0u: { // NGC_SBC_32_addsub_carry
                        Instruction result(Mnemonic::SBC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ngc_sbc32addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ngc_sbc32addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0x7A0003E0u: { // NGCS_SBCS_32_addsub_carry
                        Instruction result(Mnemonic::SBCS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ngcs_sbcs32addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ngcs_sbcs32addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0xAA0003E0u: { // MOV_ORR_64_log_shift
                        Instruction result(Mnemonic::ORR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_orr64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_orr64log_shift.Rm, is_64bit));
                        return result;
        }
        case 0xDA0003E0u: { // NGC_SBC_64_addsub_carry
                        Instruction result(Mnemonic::SBC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ngc_sbc64addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ngc_sbc64addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0xFA0003E0u: { // NGCS_SBCS_64_addsub_carry
                        Instruction result(Mnemonic::SBCS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ngcs_sbcs64addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ngcs_sbcs64addsub_carry.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0FC1Fu (1 pattern, 1 encoding)
    switch (insn & 0xFFE0FC1Fu) {
        case 0xBAC0001Fu: { // CMPP_SUBPS_64S_dp_2src
                        Instruction result(Mnemonic::SUBPS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cmpp_subps64s_dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cmpp_subps64s_dp2src.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0FC00u (49 patterns, 57 encodings)
    switch (insn & 0xFFE0FC00u) {
        case 0x1A000000u: { // ADC_32_addsub_carry
                        Instruction result(Mnemonic::ADC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.adc32addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adc32addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adc32addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0x1AC00800u: { // UDIV_32_dp_2src
                        Instruction result(Mnemonic::UDIV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.udiv32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.udiv32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.udiv32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC00C00u: { // SDIV_32_dp_2src
                        Instruction result(Mnemonic::SDIV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sdiv32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sdiv32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sdiv32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC02000u: { // LSL_LSLV_32_dp_2src
            // Also matches: LSLV_32_dp_2src (LSLV)
                        Instruction result(Mnemonic::LSLV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_lslv32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_lslv32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_lslv32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC02400u: { // LSR_LSRV_32_dp_2src
            // Also matches: LSRV_32_dp_2src (LSRV)
                        Instruction result(Mnemonic::LSRV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_lsrv32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_lsrv32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_lsrv32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC02800u: { // ASR_ASRV_32_dp_2src
            // Also matches: ASRV_32_dp_2src (ASRV)
                        Instruction result(Mnemonic::ASRV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_asrv32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_asrv32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_asrv32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC02C00u: { // ROR_RORV_32_dp_2src
            // Also matches: RORV_32_dp_2src (RORV)
                        Instruction result(Mnemonic::RORV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ror_rorv32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ror_rorv32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ror_rorv32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC04000u: { // CRC32B_32C_dp_2src
                        Instruction result(Mnemonic::CRC32B, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32b32c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32b32c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32b32c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC04400u: { // CRC32H_32C_dp_2src
                        Instruction result(Mnemonic::CRC32H, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32h32c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32h32c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32h32c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC04800u: { // CRC32W_32C_dp_2src
                        Instruction result(Mnemonic::CRC32W, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32w32c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32w32c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32w32c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC05000u: { // CRC32CB_32C_dp_2src
                        Instruction result(Mnemonic::CRC32CB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cb32c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cb32c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cb32c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC05400u: { // CRC32CH_32C_dp_2src
                        Instruction result(Mnemonic::CRC32CH, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32ch32c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32ch32c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32ch32c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC05800u: { // CRC32CW_32C_dp_2src
                        Instruction result(Mnemonic::CRC32CW, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cw32c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cw32c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cw32c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC06000u: { // SMAX_32_dp_2src
                        Instruction result(Mnemonic::SMAX, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.smax32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smax32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smax32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC06400u: { // UMAX_32_dp_2src
                        Instruction result(Mnemonic::UMAX, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.umax32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umax32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umax32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC06800u: { // SMIN_32_dp_2src
                        Instruction result(Mnemonic::SMIN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.smin32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smin32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smin32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1AC06C00u: { // UMIN_32_dp_2src
                        Instruction result(Mnemonic::UMIN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.umin32dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umin32dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umin32dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x1B007C00u: { // MUL_MADD_32A_dp_3src
                        Instruction result(Mnemonic::MADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mul_madd32a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mul_madd32a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mul_madd32a_dp3src.Rm, is_64bit));
                        return result;
        }
        case 0x1B00FC00u: { // MNEG_MSUB_32A_dp_3src
                        Instruction result(Mnemonic::MSUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mneg_msub32a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mneg_msub32a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mneg_msub32a_dp3src.Rm, is_64bit));
                        return result;
        }
        case 0x3A000000u: { // ADCS_32_addsub_carry
                        Instruction result(Mnemonic::ADCS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.adcs32addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adcs32addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adcs32addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0x5A000000u: { // SBC_32_addsub_carry
                        Instruction result(Mnemonic::SBC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sbc32addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbc32addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbc32addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0x7A000000u: { // SBCS_32_addsub_carry
                        Instruction result(Mnemonic::SBCS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sbcs32addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbcs32addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbcs32addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0x9A000000u: { // ADC_64_addsub_carry
                        Instruction result(Mnemonic::ADC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.adc64addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adc64addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adc64addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0x9AC00000u: { // SUBP_64S_dp_2src
                        Instruction result(Mnemonic::SUBP, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.subp64s_dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subp64s_dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subp64s_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC00800u: { // UDIV_64_dp_2src
                        Instruction result(Mnemonic::UDIV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.udiv64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.udiv64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.udiv64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC00C00u: { // SDIV_64_dp_2src
                        Instruction result(Mnemonic::SDIV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sdiv64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sdiv64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sdiv64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC01000u: { // IRG_64I_dp_2src
                        Instruction result(Mnemonic::IRG, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.irg64i_dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.irg64i_dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.irg64i_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC01400u: { // GMI_64G_dp_2src
                        Instruction result(Mnemonic::GMI, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.gmi64g_dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.gmi64g_dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.gmi64g_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC02000u: { // LSL_LSLV_64_dp_2src
            // Also matches: LSLV_64_dp_2src (LSLV)
                        Instruction result(Mnemonic::LSLV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_lslv64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_lslv64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsl_lslv64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC02400u: { // LSR_LSRV_64_dp_2src
            // Also matches: LSRV_64_dp_2src (LSRV)
                        Instruction result(Mnemonic::LSRV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_lsrv64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_lsrv64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.lsr_lsrv64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC02800u: { // ASR_ASRV_64_dp_2src
            // Also matches: ASRV_64_dp_2src (ASRV)
                        Instruction result(Mnemonic::ASRV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_asrv64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_asrv64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.asr_asrv64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC02C00u: { // ROR_RORV_64_dp_2src
            // Also matches: RORV_64_dp_2src (RORV)
                        Instruction result(Mnemonic::RORV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ror_rorv64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ror_rorv64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ror_rorv64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC03000u: { // PACGA_64P_dp_2src
                        Instruction result(Mnemonic::PACGA, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacga64p_dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacga64p_dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacga64p_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC04C00u: { // CRC32X_64C_dp_2src
                        Instruction result(Mnemonic::CRC32X, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32x64c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32x64c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32x64c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC05C00u: { // CRC32CX_64C_dp_2src
                        Instruction result(Mnemonic::CRC32CX, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cx64c_dp2src.Rd, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cx64c_dp2src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.crc32cx64c_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC06000u: { // SMAX_64_dp_2src
                        Instruction result(Mnemonic::SMAX, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smax64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smax64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smax64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC06400u: { // UMAX_64_dp_2src
                        Instruction result(Mnemonic::UMAX, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umax64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umax64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umax64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC06800u: { // SMIN_64_dp_2src
                        Instruction result(Mnemonic::SMIN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smin64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smin64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smin64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9AC06C00u: { // UMIN_64_dp_2src
                        Instruction result(Mnemonic::UMIN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umin64dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umin64dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umin64dp2src.Rm, is_64bit));
                        return result;
        }
        case 0x9B007C00u: { // MUL_MADD_64A_dp_3src
                        Instruction result(Mnemonic::MADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.mul_madd64a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mul_madd64a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mul_madd64a_dp3src.Rm, is_64bit));
                        return result;
        }
        case 0x9B00FC00u: { // MNEG_MSUB_64A_dp_3src
                        Instruction result(Mnemonic::MSUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.mneg_msub64a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mneg_msub64a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mneg_msub64a_dp3src.Rm, is_64bit));
                        return result;
        }
        case 0x9B207C00u: { // SMULL_SMADDL_64WA_dp_3src
                        Instruction result(Mnemonic::SMADDL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smull_smaddl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.smull_smaddl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.smull_smaddl64wa_dp3src.Rm, false));
                        return result;
        }
        case 0x9B20FC00u: { // SMNEGL_SMSUBL_64WA_dp_3src
                        Instruction result(Mnemonic::SMSUBL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smnegl_smsubl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.smnegl_smsubl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.smnegl_smsubl64wa_dp3src.Rm, false));
                        return result;
        }
        case 0x9BA07C00u: { // UMULL_UMADDL_64WA_dp_3src
                        Instruction result(Mnemonic::UMADDL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umull_umaddl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.umull_umaddl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.umull_umaddl64wa_dp3src.Rm, false));
                        return result;
        }
        case 0x9BA0FC00u: { // UMNEGL_UMSUBL_64WA_dp_3src
                        Instruction result(Mnemonic::UMSUBL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umnegl_umsubl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.umnegl_umsubl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.umnegl_umsubl64wa_dp3src.Rm, false));
                        return result;
        }
        case 0xBA000000u: { // ADCS_64_addsub_carry
                        Instruction result(Mnemonic::ADCS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.adcs64addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adcs64addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adcs64addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0xBAC00000u: { // SUBPS_64S_dp_2src
                        Instruction result(Mnemonic::SUBPS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.subps64s_dp2src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subps64s_dp2src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subps64s_dp2src.Rm, is_64bit));
                        return result;
        }
        case 0xDA000000u: { // SBC_64_addsub_carry
                        Instruction result(Mnemonic::SBC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sbc64addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbc64addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbc64addsub_carry.Rm, is_64bit));
                        return result;
        }
        case 0xFA000000u: { // SBCS_64_addsub_carry
                        Instruction result(Mnemonic::SBCS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sbcs64addsub_carry.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbcs64addsub_carry.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sbcs64addsub_carry.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0E000u (2 patterns, 2 encodings)
    switch (insn & 0xFFE0E000u) {
        case 0x9A002000u: { // ADDPT_64_addsub_pt
                        Instruction result(Mnemonic::ADDPT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.addpt64addsub_pt.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.addpt64addsub_pt.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.addpt64addsub_pt.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.addpt64addsub_pt.imm3, true));
                        return result;
        }
        case 0xDA002000u: { // SUBPT_64_addsub_pt
                        Instruction result(Mnemonic::SUBPT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.subpt64addsub_pt.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subpt64addsub_pt.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subpt64addsub_pt.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.subpt64addsub_pt.imm3, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE08000u (12 patterns, 12 encodings)
    switch (insn & 0xFFE08000u) {
        case 0x1B000000u: { // MADD_32A_dp_3src
                        Instruction result(Mnemonic::MADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.madd32a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.madd32a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.madd32a_dp3src.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.madd32a_dp3src.Ra, is_64bit));
                        return result;
        }
        case 0x1B008000u: { // MSUB_32A_dp_3src
                        Instruction result(Mnemonic::MSUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.msub32a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msub32a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msub32a_dp3src.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msub32a_dp3src.Ra, is_64bit));
                        return result;
        }
        case 0x9B000000u: { // MADD_64A_dp_3src
                        Instruction result(Mnemonic::MADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.madd64a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.madd64a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.madd64a_dp3src.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.madd64a_dp3src.Ra, is_64bit));
                        return result;
        }
        case 0x9B008000u: { // MSUB_64A_dp_3src
                        Instruction result(Mnemonic::MSUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.msub64a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msub64a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msub64a_dp3src.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msub64a_dp3src.Ra, is_64bit));
                        return result;
        }
        case 0x9B200000u: { // SMADDL_64WA_dp_3src
                        Instruction result(Mnemonic::SMADDL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smaddl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.smaddl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.smaddl64wa_dp3src.Rm, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.smaddl64wa_dp3src.Ra, true));
                        return result;
        }
        case 0x9B208000u: { // SMSUBL_64WA_dp_3src
                        Instruction result(Mnemonic::SMSUBL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smsubl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.smsubl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.smsubl64wa_dp3src.Rm, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.smsubl64wa_dp3src.Ra, true));
                        return result;
        }
        case 0x9B400000u: { // SMULH_64_dp_3src
                        Instruction result(Mnemonic::SMULH, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.smulh64dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smulh64dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.smulh64dp3src.Rm, is_64bit));
                        return result;
        }
        case 0x9B600000u: { // MADDPT_64A_dp_3src
                        Instruction result(Mnemonic::MADDPT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.maddpt64a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.maddpt64a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.maddpt64a_dp3src.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.maddpt64a_dp3src.Ra, is_64bit));
                        return result;
        }
        case 0x9B608000u: { // MSUBPT_64A_dp_3src
                        Instruction result(Mnemonic::MSUBPT, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.msubpt64a_dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msubpt64a_dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msubpt64a_dp3src.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.msubpt64a_dp3src.Ra, is_64bit));
                        return result;
        }
        case 0x9BA00000u: { // UMADDL_64WA_dp_3src
                        Instruction result(Mnemonic::UMADDL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umaddl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.umaddl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.umaddl64wa_dp3src.Rm, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.umaddl64wa_dp3src.Ra, true));
                        return result;
        }
        case 0x9BA08000u: { // UMSUBL_64WA_dp_3src
                        Instruction result(Mnemonic::UMSUBL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umsubl64wa_dp3src.Rd, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.umsubl64wa_dp3src.Rn, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.umsubl64wa_dp3src.Rm, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.umsubl64wa_dp3src.Ra, true));
                        return result;
        }
        case 0x9BC00000u: { // UMULH_64_dp_3src
                        Instruction result(Mnemonic::UMULH, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.umulh64dp3src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umulh64dp3src.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.umulh64dp3src.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE07C10u (1 pattern, 1 encoding)
    switch (insn & 0xFFE07C10u) {
        case 0xBA000400u: { // RMIF_only_rmif
                        Instruction result(Mnemonic::RMIF, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.rmif_only_rmif.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.rmif_only_rmif.imm6, true));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.rmif_only_rmif.mask, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00C10u (8 patterns, 8 encodings)
    switch (insn & 0xFFE00C10u) {
        case 0x3A400000u: { // CCMN_32_condcmp_reg
                        Instruction result(Mnemonic::CCMN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmn32condcmp_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmn32condcmp_reg.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.ccmn32condcmp_reg.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmn32condcmp_reg.nzcv, true));
                        return result;
        }
        case 0x3A400800u: { // CCMN_32_condcmp_imm
                        Instruction result(Mnemonic::CCMN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmn32condcmp_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmn32condcmp_imm.imm5, true));
                        result.condition = static_cast<Condition>(enc.ccmn32condcmp_imm.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmn32condcmp_imm.nzcv, true));
                        return result;
        }
        case 0x7A400000u: { // CCMP_32_condcmp_reg
                        Instruction result(Mnemonic::CCMP, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmp32condcmp_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmp32condcmp_reg.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.ccmp32condcmp_reg.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmp32condcmp_reg.nzcv, true));
                        return result;
        }
        case 0x7A400800u: { // CCMP_32_condcmp_imm
                        Instruction result(Mnemonic::CCMP, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmp32condcmp_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmp32condcmp_imm.imm5, true));
                        result.condition = static_cast<Condition>(enc.ccmp32condcmp_imm.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmp32condcmp_imm.nzcv, true));
                        return result;
        }
        case 0xBA400000u: { // CCMN_64_condcmp_reg
                        Instruction result(Mnemonic::CCMN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmn64condcmp_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmn64condcmp_reg.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.ccmn64condcmp_reg.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmn64condcmp_reg.nzcv, true));
                        return result;
        }
        case 0xBA400800u: { // CCMN_64_condcmp_imm
                        Instruction result(Mnemonic::CCMN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmn64condcmp_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmn64condcmp_imm.imm5, true));
                        result.condition = static_cast<Condition>(enc.ccmn64condcmp_imm.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmn64condcmp_imm.nzcv, true));
                        return result;
        }
        case 0xFA400000u: { // CCMP_64_condcmp_reg
                        Instruction result(Mnemonic::CCMP, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmp64condcmp_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmp64condcmp_reg.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.ccmp64condcmp_reg.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmp64condcmp_reg.nzcv, true));
                        return result;
        }
        case 0xFA400800u: { // CCMP_64_condcmp_imm
                        Instruction result(Mnemonic::CCMP, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ccmp64condcmp_imm.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmp64condcmp_imm.imm5, true));
                        result.condition = static_cast<Condition>(enc.ccmp64condcmp_imm.cond);
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ccmp64condcmp_imm.nzcv, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00C00u (8 patterns, 14 encodings)
    switch (insn & 0xFFE00C00u) {
        case 0x1A800000u: { // CSEL_32_condsel
                        Instruction result(Mnemonic::CSEL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.csel32condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csel32condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csel32condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.csel32condsel.cond);
                        return result;
        }
        case 0x1A800400u: { // CINC_CSINC_32_condsel
            // Also matches: CSINC_32_condsel (CSINC)
            if (!(((insn >> 16) & 0x1F) == 0x1F || ((insn >> 5) & 0x1F) == 0x1F)) {
                                Instruction result(Mnemonic::CSINC, insn);
                                DpregEncoding enc = {};
                                enc.raw = insn;
                                bool is_64bit = false;
                                result.operands.push_back(Operand(OperandType::Register, enc.cinc_csinc32condsel.Rd, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinc_csinc32condsel.Rn, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinc_csinc32condsel.Rm, is_64bit));
                                result.condition = static_cast<Condition>(enc.cinc_csinc32condsel.cond);
                                return result;
            }
                        Instruction result(Mnemonic::CSINC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.csinc32condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinc32condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinc32condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.csinc32condsel.cond);
                        return result;
        }
        case 0x5A800000u: { // CINV_CSINV_32_condsel
            // Also matches: CSINV_32_condsel (CSINV)
            if (!(((insn >> 16) & 0x1F) == 0x1F || ((insn >> 5) & 0x1F) == 0x1F)) {
                                Instruction result(Mnemonic::CSINV, insn);
                                DpregEncoding enc = {};
                                enc.raw = insn;
                                bool is_64bit = false;
                                result.operands.push_back(Operand(OperandType::Register, enc.cinv_csinv32condsel.Rd, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinv_csinv32condsel.Rn, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinv_csinv32condsel.Rm, is_64bit));
                                result.condition = static_cast<Condition>(enc.cinv_csinv32condsel.cond);
                                return result;
            }
                        Instruction result(Mnemonic::CSINV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.csinv32condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinv32condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinv32condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.csinv32condsel.cond);
                        return result;
        }
        case 0x5A800400u: { // CNEG_CSNEG_32_condsel
            // Also matches: CSNEG_32_condsel (CSNEG)
                        Instruction result(Mnemonic::CSNEG, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cneg_csneg32condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cneg_csneg32condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cneg_csneg32condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.cneg_csneg32condsel.cond);
                        return result;
        }
        case 0x9A800000u: { // CSEL_64_condsel
                        Instruction result(Mnemonic::CSEL, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.csel64condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csel64condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csel64condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.csel64condsel.cond);
                        return result;
        }
        case 0x9A800400u: { // CINC_CSINC_64_condsel
            // Also matches: CSINC_64_condsel (CSINC)
            if (!(((insn >> 16) & 0x1F) == 0x1F || ((insn >> 5) & 0x1F) == 0x1F)) {
                                Instruction result(Mnemonic::CSINC, insn);
                                DpregEncoding enc = {};
                                enc.raw = insn;
                                bool is_64bit = true;
                                result.operands.push_back(Operand(OperandType::Register, enc.cinc_csinc64condsel.Rd, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinc_csinc64condsel.Rn, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinc_csinc64condsel.Rm, is_64bit));
                                result.condition = static_cast<Condition>(enc.cinc_csinc64condsel.cond);
                                return result;
            }
                        Instruction result(Mnemonic::CSINC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.csinc64condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinc64condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinc64condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.csinc64condsel.cond);
                        return result;
        }
        case 0xDA800000u: { // CINV_CSINV_64_condsel
            // Also matches: CSINV_64_condsel (CSINV)
            if (!(((insn >> 16) & 0x1F) == 0x1F || ((insn >> 5) & 0x1F) == 0x1F)) {
                                Instruction result(Mnemonic::CSINV, insn);
                                DpregEncoding enc = {};
                                enc.raw = insn;
                                bool is_64bit = true;
                                result.operands.push_back(Operand(OperandType::Register, enc.cinv_csinv64condsel.Rd, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinv_csinv64condsel.Rn, is_64bit));
                                result.operands.push_back(Operand(OperandType::Register, enc.cinv_csinv64condsel.Rm, is_64bit));
                                result.condition = static_cast<Condition>(enc.cinv_csinv64condsel.cond);
                                return result;
            }
                        Instruction result(Mnemonic::CSINV, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.csinv64condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinv64condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.csinv64condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.csinv64condsel.cond);
                        return result;
        }
        case 0xDA800400u: { // CNEG_CSNEG_64_condsel
            // Also matches: CSNEG_64_condsel (CSNEG)
                        Instruction result(Mnemonic::CSNEG, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cneg_csneg64condsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cneg_csneg64condsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cneg_csneg64condsel.Rm, is_64bit));
                        result.condition = static_cast<Condition>(enc.cneg_csneg64condsel.cond);
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Fu (4 patterns, 4 encodings)
    switch (insn & 0xFFE0001Fu) {
        case 0x2B20001Fu: { // CMN_ADDS_32S_addsub_ext
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.cmn_adds32s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.cmn_adds32s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.cmn_adds32s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.cmn_adds32s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0x6B20001Fu: { // CMP_SUBS_32S_addsub_ext
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.cmp_subs32s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.cmp_subs32s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.cmp_subs32s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.cmp_subs32s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0xAB20001Fu: { // CMN_ADDS_64S_addsub_ext
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.cmn_adds64s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.cmn_adds64s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.cmn_adds64s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.cmn_adds64s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0xEB20001Fu: { // CMP_SUBS_64S_addsub_ext
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.cmp_subs64s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.cmp_subs64s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.cmp_subs64s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.cmp_subs64s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00000u (8 patterns, 8 encodings)
    switch (insn & 0xFFE00000u) {
        case 0x0B200000u: { // ADD_32_addsub_ext
                        Instruction result(Mnemonic::ADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.add32addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.add32addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.add32addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.add32addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.add32addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0x2B200000u: { // ADDS_32S_addsub_ext
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.adds32s_addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.adds32s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.adds32s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.adds32s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.adds32s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0x4B200000u: { // SUB_32_addsub_ext
                        Instruction result(Mnemonic::SUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.sub32addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.sub32addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.sub32addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.sub32addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.sub32addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0x6B200000u: { // SUBS_32S_addsub_ext
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        { Operand op(OperandType::Register, enc.subs32s_addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.subs32s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.subs32s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.subs32s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.subs32s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0x8B200000u: { // ADD_64_addsub_ext
                        Instruction result(Mnemonic::ADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.add64addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.add64addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.add64addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.add64addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.add64addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0xAB200000u: { // ADDS_64S_addsub_ext
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.adds64s_addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.adds64s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.adds64s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.adds64s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.adds64s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0xCB200000u: { // SUB_64_addsub_ext
                        Instruction result(Mnemonic::SUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.sub64addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.sub64addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.sub64addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.sub64addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.sub64addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        case 0xEB200000u: { // SUBS_64S_addsub_ext
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        { Operand op(OperandType::Register, enc.subs64s_addsub_ext.Rd, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        { Operand op(OperandType::Register, enc.subs64s_addsub_ext.Rn, is_64bit); op.is_sp = true; result.operands.push_back(op); }
                        uint32_t option = enc.subs64s_addsub_ext.option;
                        bool rm_is_64 = is_64bit && ((option & 3) == 3);
                        result.operands.push_back(Operand(OperandType::Register, enc.subs64s_addsub_ext.Rm, rm_is_64));
                        uint32_t imm3 = enc.subs64s_addsub_ext.imm3;
                        bool is_default = (is_64bit ? (option == 3) : (option == 2)) && imm3 == 0;
                        if (!is_default) {
                            result.operands.push_back(Operand(OperandType::Extend, option | (imm3 << 8), is_64bit));
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF2003E0u (6 patterns, 6 encodings)
    switch (insn & 0xFF2003E0u) {
        case 0x2A2003E0u: { // MVN_ORN_32_log_shift
                        Instruction result(Mnemonic::ORN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mvn_orn32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mvn_orn32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.mvn_orn32log_shift.shift;
                            uint32_t shift_amount = enc.mvn_orn32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x4B0003E0u: { // NEG_SUB_32_addsub_shift
                        Instruction result(Mnemonic::SUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.neg_sub32addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.neg_sub32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.neg_sub32addsub_shift.shift;
                            uint32_t shift_amount = enc.neg_sub32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x6B0003E0u: { // NEGS_SUBS_32_addsub_shift
            if (((insn >> 0) & 0x1F) == 0x1F) break;
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.negs_subs32addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.negs_subs32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.negs_subs32addsub_shift.shift;
                            uint32_t shift_amount = enc.negs_subs32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xAA2003E0u: { // MVN_ORN_64_log_shift
                        Instruction result(Mnemonic::ORN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.mvn_orn64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.mvn_orn64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.mvn_orn64log_shift.shift;
                            uint32_t shift_amount = enc.mvn_orn64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xCB0003E0u: { // NEG_SUB_64_addsub_shift
                        Instruction result(Mnemonic::SUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.neg_sub64addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.neg_sub64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.neg_sub64addsub_shift.shift;
                            uint32_t shift_amount = enc.neg_sub64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xEB0003E0u: { // NEGS_SUBS_64_addsub_shift
            if (((insn >> 0) & 0x1F) == 0x1F) break;
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.negs_subs64addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.negs_subs64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.negs_subs64addsub_shift.shift;
                            uint32_t shift_amount = enc.negs_subs64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF20001Fu (6 patterns, 6 encodings)
    switch (insn & 0xFF20001Fu) {
        case 0x2B00001Fu: { // CMN_ADDS_32_addsub_shift
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cmn_adds32addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cmn_adds32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.cmn_adds32addsub_shift.shift;
                            uint32_t shift_amount = enc.cmn_adds32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x6A00001Fu: { // TST_ANDS_32_log_shift
                        Instruction result(Mnemonic::ANDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.tst_ands32log_shift.shift;
                            uint32_t shift_amount = enc.tst_ands32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x6B00001Fu: { // CMP_SUBS_32_addsub_shift
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cmp_subs32addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cmp_subs32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.cmp_subs32addsub_shift.shift;
                            uint32_t shift_amount = enc.cmp_subs32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xAB00001Fu: { // CMN_ADDS_64_addsub_shift
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cmn_adds64addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cmn_adds64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.cmn_adds64addsub_shift.shift;
                            uint32_t shift_amount = enc.cmn_adds64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xEA00001Fu: { // TST_ANDS_64_log_shift
                        Instruction result(Mnemonic::ANDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.tst_ands64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.tst_ands64log_shift.shift;
                            uint32_t shift_amount = enc.tst_ands64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xEB00001Fu: { // CMP_SUBS_64_addsub_shift
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cmp_subs64addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cmp_subs64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.cmp_subs64addsub_shift.shift;
                            uint32_t shift_amount = enc.cmp_subs64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF200000u (24 patterns, 24 encodings)
    switch (insn & 0xFF200000u) {
        case 0x0A000000u: { // AND_32_log_shift
                        Instruction result(Mnemonic::AND, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.and32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.and32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.and32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.and32log_shift.shift;
                            uint32_t shift_amount = enc.and32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x0A200000u: { // BIC_32_log_shift
                        Instruction result(Mnemonic::BIC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.bic32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bic32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bic32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.bic32log_shift.shift;
                            uint32_t shift_amount = enc.bic32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x0B000000u: { // ADD_32_addsub_shift
                        Instruction result(Mnemonic::ADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.add32addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.add32addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.add32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.add32addsub_shift.shift;
                            uint32_t shift_amount = enc.add32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x2A000000u: { // ORR_32_log_shift
                        Instruction result(Mnemonic::ORR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.orr32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orr32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orr32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.orr32log_shift.shift;
                            uint32_t shift_amount = enc.orr32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x2A200000u: { // ORN_32_log_shift
                        Instruction result(Mnemonic::ORN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.orn32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orn32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orn32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.orn32log_shift.shift;
                            uint32_t shift_amount = enc.orn32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x2B000000u: { // ADDS_32_addsub_shift
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.adds32addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adds32addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adds32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.adds32addsub_shift.shift;
                            uint32_t shift_amount = enc.adds32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x4A000000u: { // EOR_32_log_shift
                        Instruction result(Mnemonic::EOR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.eor32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eor32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eor32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.eor32log_shift.shift;
                            uint32_t shift_amount = enc.eor32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x4A200000u: { // EON_32_log_shift
                        Instruction result(Mnemonic::EON, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.eon32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eon32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eon32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.eon32log_shift.shift;
                            uint32_t shift_amount = enc.eon32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x4B000000u: { // SUB_32_addsub_shift
                        Instruction result(Mnemonic::SUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sub32addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sub32addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sub32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.sub32addsub_shift.shift;
                            uint32_t shift_amount = enc.sub32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x6A000000u: { // ANDS_32_log_shift
                        Instruction result(Mnemonic::ANDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ands32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ands32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ands32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.ands32log_shift.shift;
                            uint32_t shift_amount = enc.ands32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x6A200000u: { // BICS_32_log_shift
                        Instruction result(Mnemonic::BICS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.bics32log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bics32log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bics32log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.bics32log_shift.shift;
                            uint32_t shift_amount = enc.bics32log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x6B000000u: { // SUBS_32_addsub_shift
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.subs32addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subs32addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subs32addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.subs32addsub_shift.shift;
                            uint32_t shift_amount = enc.subs32addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x8A000000u: { // AND_64_log_shift
                        Instruction result(Mnemonic::AND, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.and64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.and64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.and64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.and64log_shift.shift;
                            uint32_t shift_amount = enc.and64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x8A200000u: { // BIC_64_log_shift
                        Instruction result(Mnemonic::BIC, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.bic64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bic64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bic64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.bic64log_shift.shift;
                            uint32_t shift_amount = enc.bic64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0x8B000000u: { // ADD_64_addsub_shift
                        Instruction result(Mnemonic::ADD, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.add64addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.add64addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.add64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.add64addsub_shift.shift;
                            uint32_t shift_amount = enc.add64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xAA000000u: { // ORR_64_log_shift
                        Instruction result(Mnemonic::ORR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.orr64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orr64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orr64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.orr64log_shift.shift;
                            uint32_t shift_amount = enc.orr64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xAA200000u: { // ORN_64_log_shift
                        Instruction result(Mnemonic::ORN, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.orn64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orn64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.orn64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.orn64log_shift.shift;
                            uint32_t shift_amount = enc.orn64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xAB000000u: { // ADDS_64_addsub_shift
                        Instruction result(Mnemonic::ADDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.adds64addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adds64addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.adds64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.adds64addsub_shift.shift;
                            uint32_t shift_amount = enc.adds64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xCA000000u: { // EOR_64_log_shift
                        Instruction result(Mnemonic::EOR, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.eor64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eor64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eor64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.eor64log_shift.shift;
                            uint32_t shift_amount = enc.eor64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xCA200000u: { // EON_64_log_shift
                        Instruction result(Mnemonic::EON, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.eon64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eon64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.eon64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.eon64log_shift.shift;
                            uint32_t shift_amount = enc.eon64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xCB000000u: { // SUB_64_addsub_shift
                        Instruction result(Mnemonic::SUB, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.sub64addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sub64addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sub64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.sub64addsub_shift.shift;
                            uint32_t shift_amount = enc.sub64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xEA000000u: { // ANDS_64_log_shift
                        Instruction result(Mnemonic::ANDS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ands64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ands64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ands64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.ands64log_shift.shift;
                            uint32_t shift_amount = enc.ands64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xEA200000u: { // BICS_64_log_shift
                        Instruction result(Mnemonic::BICS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.bics64log_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bics64log_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bics64log_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.bics64log_shift.shift;
                            uint32_t shift_amount = enc.bics64log_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        case 0xEB000000u: { // SUBS_64_addsub_shift
                        Instruction result(Mnemonic::SUBS, insn);
                        DpregEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.subs64addsub_shift.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subs64addsub_shift.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.subs64addsub_shift.Rm, is_64bit));
                        {
                            uint32_t shift_type = enc.subs64addsub_shift.shift;
                            uint32_t shift_amount = enc.subs64addsub_shift.imm6;
                            // Only emit shift operand if non-zero (suppress LSL #0)
                            if (shift_type < 4 && (shift_type != 0 || shift_amount != 0)) {
                                result.operands.push_back(Operand(OperandType::Shift, (shift_type << 8) | shift_amount, true));
                            }
                        }
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace dpreg
} // namespace format
} // namespace veda64
