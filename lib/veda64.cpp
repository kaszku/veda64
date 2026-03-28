// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include "format/format.hpp"
#include <cstring>
#include <iomanip>
#include <sstream>

namespace veda64 {

#ifdef VEDA64_STRINGS
// Convert mnemonic enum to string
const char* mnemonic_to_string(Mnemonic mnem) {
    switch (mnem) {
        case Mnemonic::ABS: return "abs";
        case Mnemonic::ADC: return "adc";
        case Mnemonic::ADCLB: return "adclb";
        case Mnemonic::ADCLT: return "adclt";
        case Mnemonic::ADCS: return "adcs";
        case Mnemonic::ADD: return "add";
        case Mnemonic::ADDG: return "addg";
        case Mnemonic::ADDHA: return "addha";
        case Mnemonic::ADDHN: return "addhn";
        case Mnemonic::ADDHNB: return "addhnb";
        case Mnemonic::ADDHNT: return "addhnt";
        case Mnemonic::ADDP: return "addp";
        case Mnemonic::ADDPL: return "addpl";
        case Mnemonic::ADDPT: return "addpt";
        case Mnemonic::ADDQP: return "addqp";
        case Mnemonic::ADDQV: return "addqv";
        case Mnemonic::ADDS: return "adds";
        case Mnemonic::ADDSPL: return "addspl";
        case Mnemonic::ADDSUBP: return "addsubp";
        case Mnemonic::ADDSVL: return "addsvl";
        case Mnemonic::ADDV: return "addv";
        case Mnemonic::ADDVA: return "addva";
        case Mnemonic::ADDVL: return "addvl";
        case Mnemonic::ADR: return "adr";
        case Mnemonic::ADRP: return "adrp";
        case Mnemonic::AESD: return "aesd";
        case Mnemonic::AESDIMC: return "aesdimc";
        case Mnemonic::AESE: return "aese";
        case Mnemonic::AESEMC: return "aesemc";
        case Mnemonic::AESIMC: return "aesimc";
        case Mnemonic::AESMC: return "aesmc";
        case Mnemonic::AND: return "and";
        case Mnemonic::ANDQV: return "andqv";
        case Mnemonic::ANDS: return "ands";
        case Mnemonic::ANDV: return "andv";
        case Mnemonic::APAS: return "apas";
        case Mnemonic::ASR: return "asr";
        case Mnemonic::ASRD: return "asrd";
        case Mnemonic::ASRR: return "asrr";
        case Mnemonic::ASRV: return "asrv";
        case Mnemonic::AT: return "at";
        case Mnemonic::AUTDA: return "autda";
        case Mnemonic::AUTDB: return "autdb";
        case Mnemonic::AUTDZA: return "autdza";
        case Mnemonic::AUTDZB: return "autdzb";
        case Mnemonic::AUTIA: return "autia";
        case Mnemonic::AUTIA1716: return "autia1716";
        case Mnemonic::AUTIA171615: return "autia171615";
        case Mnemonic::AUTIASP: return "autiasp";
        case Mnemonic::AUTIASPPC: return "autiasppc";
        case Mnemonic::AUTIASPPCR: return "autiasppcr";
        case Mnemonic::AUTIAZ: return "autiaz";
        case Mnemonic::AUTIB: return "autib";
        case Mnemonic::AUTIB1716: return "autib1716";
        case Mnemonic::AUTIB171615: return "autib171615";
        case Mnemonic::AUTIBSP: return "autibsp";
        case Mnemonic::AUTIBSPPC: return "autibsppc";
        case Mnemonic::AUTIBSPPCR: return "autibsppcr";
        case Mnemonic::AUTIBZ: return "autibz";
        case Mnemonic::AUTIZA: return "autiza";
        case Mnemonic::AUTIZB: return "autizb";
        case Mnemonic::AXFLAG: return "axflag";
        case Mnemonic::B: return "b";
        case Mnemonic::BC: return "bc";
        case Mnemonic::BCAX: return "bcax";
        case Mnemonic::BDEP: return "bdep";
        case Mnemonic::BEXT: return "bext";
        case Mnemonic::BF1CVT: return "bf1cvt";
        case Mnemonic::BF1CVTL: return "bf1cvtl";
        case Mnemonic::BF1CVTLT: return "bf1cvtlt";
        case Mnemonic::BF2CVT: return "bf2cvt";
        case Mnemonic::BF2CVTL: return "bf2cvtl";
        case Mnemonic::BF2CVTLT: return "bf2cvtlt";
        case Mnemonic::BFADD: return "bfadd";
        case Mnemonic::BFC: return "bfc";
        case Mnemonic::BFCLAMP: return "bfclamp";
        case Mnemonic::BFCVT: return "bfcvt";
        case Mnemonic::BFCVTN: return "bfcvtn";
        case Mnemonic::BFCVTNT: return "bfcvtnt";
        case Mnemonic::BFDOT: return "bfdot";
        case Mnemonic::BFI: return "bfi";
        case Mnemonic::BFM: return "bfm";
        case Mnemonic::BFMAX: return "bfmax";
        case Mnemonic::BFMAXNM: return "bfmaxnm";
        case Mnemonic::BFMIN: return "bfmin";
        case Mnemonic::BFMINNM: return "bfminnm";
        case Mnemonic::BFMLA: return "bfmla";
        case Mnemonic::BFMLAL: return "bfmlal";
        case Mnemonic::BFMLALB: return "bfmlalb";
        case Mnemonic::BFMLALT: return "bfmlalt";
        case Mnemonic::BFMLS: return "bfmls";
        case Mnemonic::BFMLSL: return "bfmlsl";
        case Mnemonic::BFMLSLB: return "bfmlslb";
        case Mnemonic::BFMLSLT: return "bfmlslt";
        case Mnemonic::BFMMLA: return "bfmmla";
        case Mnemonic::BFMOP4A: return "bfmop4a";
        case Mnemonic::BFMOP4S: return "bfmop4s";
        case Mnemonic::BFMOPA: return "bfmopa";
        case Mnemonic::BFMOPS: return "bfmops";
        case Mnemonic::BFMUL: return "bfmul";
        case Mnemonic::BFSCALE: return "bfscale";
        case Mnemonic::BFSUB: return "bfsub";
        case Mnemonic::BFTMOPA: return "bftmopa";
        case Mnemonic::BFVDOT: return "bfvdot";
        case Mnemonic::BGRP: return "bgrp";
        case Mnemonic::BIC: return "bic";
        case Mnemonic::BICS: return "bics";
        case Mnemonic::BIF: return "bif";
        case Mnemonic::BIT: return "bit";
        case Mnemonic::BL: return "bl";
        case Mnemonic::BLR: return "blr";
        case Mnemonic::BLRAA: return "blraa";
        case Mnemonic::BLRAAZ: return "blraaz";
        case Mnemonic::BLRAB: return "blrab";
        case Mnemonic::BLRABZ: return "blrabz";
        case Mnemonic::BMOPA: return "bmopa";
        case Mnemonic::BMOPS: return "bmops";
        case Mnemonic::BR: return "br";
        case Mnemonic::BRAA: return "braa";
        case Mnemonic::BRAAZ: return "braaz";
        case Mnemonic::BRAB: return "brab";
        case Mnemonic::BRABZ: return "brabz";
        case Mnemonic::BRB: return "brb";
        case Mnemonic::BRK: return "brk";
        case Mnemonic::BRKA: return "brka";
        case Mnemonic::BRKAS: return "brkas";
        case Mnemonic::BRKB: return "brkb";
        case Mnemonic::BRKBS: return "brkbs";
        case Mnemonic::BRKN: return "brkn";
        case Mnemonic::BRKNS: return "brkns";
        case Mnemonic::BRKPA: return "brkpa";
        case Mnemonic::BRKPAS: return "brkpas";
        case Mnemonic::BRKPB: return "brkpb";
        case Mnemonic::BRKPBS: return "brkpbs";
        case Mnemonic::BSL: return "bsl";
        case Mnemonic::BSL1N: return "bsl1n";
        case Mnemonic::BSL2N: return "bsl2n";
        case Mnemonic::BTI: return "bti";
        case Mnemonic::CADD: return "cadd";
        case Mnemonic::CAS: return "cas";
        case Mnemonic::CASA: return "casa";
        case Mnemonic::CASAB: return "casab";
        case Mnemonic::CASAH: return "casah";
        case Mnemonic::CASAL: return "casal";
        case Mnemonic::CASALB: return "casalb";
        case Mnemonic::CASALH: return "casalh";
        case Mnemonic::CASALT: return "casalt";
        case Mnemonic::CASAT: return "casat";
        case Mnemonic::CASB: return "casb";
        case Mnemonic::CASH: return "cash";
        case Mnemonic::CASL: return "casl";
        case Mnemonic::CASLB: return "caslb";
        case Mnemonic::CASLH: return "caslh";
        case Mnemonic::CASLT: return "caslt";
        case Mnemonic::CASP: return "casp";
        case Mnemonic::CASPA: return "caspa";
        case Mnemonic::CASPAL: return "caspal";
        case Mnemonic::CASPALT: return "caspalt";
        case Mnemonic::CASPAT: return "caspat";
        case Mnemonic::CASPL: return "caspl";
        case Mnemonic::CASPLT: return "casplt";
        case Mnemonic::CASPT: return "caspt";
        case Mnemonic::CAST: return "cast";
        case Mnemonic::CBBEQ: return "cbbeq";
        case Mnemonic::CBBGE: return "cbbge";
        case Mnemonic::CBBGT: return "cbbgt";
        case Mnemonic::CBBHI: return "cbbhi";
        case Mnemonic::CBBHS: return "cbbhs";
        case Mnemonic::CBBNE: return "cbbne";
        case Mnemonic::CBEQ: return "cbeq";
        case Mnemonic::CBGE: return "cbge";
        case Mnemonic::CBGT: return "cbgt";
        case Mnemonic::CBHEQ: return "cbheq";
        case Mnemonic::CBHGE: return "cbhge";
        case Mnemonic::CBHGT: return "cbhgt";
        case Mnemonic::CBHHI: return "cbhhi";
        case Mnemonic::CBHHS: return "cbhhs";
        case Mnemonic::CBHI: return "cbhi";
        case Mnemonic::CBHNE: return "cbhne";
        case Mnemonic::CBHS: return "cbhs";
        case Mnemonic::CBLO: return "cblo";
        case Mnemonic::CBLT: return "cblt";
        case Mnemonic::CBNE: return "cbne";
        case Mnemonic::CBNZ: return "cbnz";
        case Mnemonic::CBZ: return "cbz";
        case Mnemonic::CCMN: return "ccmn";
        case Mnemonic::CCMP: return "ccmp";
        case Mnemonic::CDOT: return "cdot";
        case Mnemonic::CFINV: return "cfinv";
        case Mnemonic::CFP: return "cfp";
        case Mnemonic::CHKFEAT: return "chkfeat";
        case Mnemonic::CINC: return "cinc";
        case Mnemonic::CINV: return "cinv";
        case Mnemonic::CLASTA: return "clasta";
        case Mnemonic::CLASTB: return "clastb";
        case Mnemonic::CLRBHB: return "clrbhb";
        case Mnemonic::CLREX: return "clrex";
        case Mnemonic::CLS: return "cls";
        case Mnemonic::CLZ: return "clz";
        case Mnemonic::CMEQ: return "cmeq";
        case Mnemonic::CMGE: return "cmge";
        case Mnemonic::CMGT: return "cmgt";
        case Mnemonic::CMHI: return "cmhi";
        case Mnemonic::CMHS: return "cmhs";
        case Mnemonic::CMLA: return "cmla";
        case Mnemonic::CMLE: return "cmle";
        case Mnemonic::CMLT: return "cmlt";
        case Mnemonic::CMN: return "cmn";
        case Mnemonic::CMP: return "cmp";
        case Mnemonic::CMPEQ: return "cmpeq";
        case Mnemonic::CMPGE: return "cmpge";
        case Mnemonic::CMPGT: return "cmpgt";
        case Mnemonic::CMPHI: return "cmphi";
        case Mnemonic::CMPHS: return "cmphs";
        case Mnemonic::CMPLE: return "cmple";
        case Mnemonic::CMPLO: return "cmplo";
        case Mnemonic::CMPLS: return "cmpls";
        case Mnemonic::CMPLT: return "cmplt";
        case Mnemonic::CMPNE: return "cmpne";
        case Mnemonic::CMPP: return "cmpp";
        case Mnemonic::CMTST: return "cmtst";
        case Mnemonic::CNEG: return "cneg";
        case Mnemonic::CNOT: return "cnot";
        case Mnemonic::CNT: return "cnt";
        case Mnemonic::CNTB: return "cntb";
        case Mnemonic::CNTD: return "cntd";
        case Mnemonic::CNTH: return "cnth";
        case Mnemonic::CNTP: return "cntp";
        case Mnemonic::CNTW: return "cntw";
        case Mnemonic::COMPACT: return "compact";
        case Mnemonic::COSP: return "cosp";
        case Mnemonic::CPP: return "cpp";
        case Mnemonic::CPY: return "cpy";
        case Mnemonic::CPYE: return "cpye";
        case Mnemonic::CPYEN: return "cpyen";
        case Mnemonic::CPYERN: return "cpyern";
        case Mnemonic::CPYERT: return "cpyert";
        case Mnemonic::CPYERTN: return "cpyertn";
        case Mnemonic::CPYERTRN: return "cpyertrn";
        case Mnemonic::CPYERTWN: return "cpyertwn";
        case Mnemonic::CPYET: return "cpyet";
        case Mnemonic::CPYETN: return "cpyetn";
        case Mnemonic::CPYETRN: return "cpyetrn";
        case Mnemonic::CPYETWN: return "cpyetwn";
        case Mnemonic::CPYEWN: return "cpyewn";
        case Mnemonic::CPYEWT: return "cpyewt";
        case Mnemonic::CPYEWTN: return "cpyewtn";
        case Mnemonic::CPYEWTRN: return "cpyewtrn";
        case Mnemonic::CPYEWTWN: return "cpyewtwn";
        case Mnemonic::CPYFE: return "cpyfe";
        case Mnemonic::CPYFEN: return "cpyfen";
        case Mnemonic::CPYFERN: return "cpyfern";
        case Mnemonic::CPYFERT: return "cpyfert";
        case Mnemonic::CPYFERTN: return "cpyfertn";
        case Mnemonic::CPYFERTRN: return "cpyfertrn";
        case Mnemonic::CPYFERTWN: return "cpyfertwn";
        case Mnemonic::CPYFET: return "cpyfet";
        case Mnemonic::CPYFETN: return "cpyfetn";
        case Mnemonic::CPYFETRN: return "cpyfetrn";
        case Mnemonic::CPYFETWN: return "cpyfetwn";
        case Mnemonic::CPYFEWN: return "cpyfewn";
        case Mnemonic::CPYFEWT: return "cpyfewt";
        case Mnemonic::CPYFEWTN: return "cpyfewtn";
        case Mnemonic::CPYFEWTRN: return "cpyfewtrn";
        case Mnemonic::CPYFEWTWN: return "cpyfewtwn";
        case Mnemonic::CPYFM: return "cpyfm";
        case Mnemonic::CPYFMN: return "cpyfmn";
        case Mnemonic::CPYFMRN: return "cpyfmrn";
        case Mnemonic::CPYFMRT: return "cpyfmrt";
        case Mnemonic::CPYFMRTN: return "cpyfmrtn";
        case Mnemonic::CPYFMRTRN: return "cpyfmrtrn";
        case Mnemonic::CPYFMRTWN: return "cpyfmrtwn";
        case Mnemonic::CPYFMT: return "cpyfmt";
        case Mnemonic::CPYFMTN: return "cpyfmtn";
        case Mnemonic::CPYFMTRN: return "cpyfmtrn";
        case Mnemonic::CPYFMTWN: return "cpyfmtwn";
        case Mnemonic::CPYFMWN: return "cpyfmwn";
        case Mnemonic::CPYFMWT: return "cpyfmwt";
        case Mnemonic::CPYFMWTN: return "cpyfmwtn";
        case Mnemonic::CPYFMWTRN: return "cpyfmwtrn";
        case Mnemonic::CPYFMWTWN: return "cpyfmwtwn";
        case Mnemonic::CPYFP: return "cpyfp";
        case Mnemonic::CPYFPN: return "cpyfpn";
        case Mnemonic::CPYFPRN: return "cpyfprn";
        case Mnemonic::CPYFPRT: return "cpyfprt";
        case Mnemonic::CPYFPRTN: return "cpyfprtn";
        case Mnemonic::CPYFPRTRN: return "cpyfprtrn";
        case Mnemonic::CPYFPRTWN: return "cpyfprtwn";
        case Mnemonic::CPYFPT: return "cpyfpt";
        case Mnemonic::CPYFPTN: return "cpyfptn";
        case Mnemonic::CPYFPTRN: return "cpyfptrn";
        case Mnemonic::CPYFPTWN: return "cpyfptwn";
        case Mnemonic::CPYFPWN: return "cpyfpwn";
        case Mnemonic::CPYFPWT: return "cpyfpwt";
        case Mnemonic::CPYFPWTN: return "cpyfpwtn";
        case Mnemonic::CPYFPWTRN: return "cpyfpwtrn";
        case Mnemonic::CPYFPWTWN: return "cpyfpwtwn";
        case Mnemonic::CPYM: return "cpym";
        case Mnemonic::CPYMN: return "cpymn";
        case Mnemonic::CPYMRN: return "cpymrn";
        case Mnemonic::CPYMRT: return "cpymrt";
        case Mnemonic::CPYMRTN: return "cpymrtn";
        case Mnemonic::CPYMRTRN: return "cpymrtrn";
        case Mnemonic::CPYMRTWN: return "cpymrtwn";
        case Mnemonic::CPYMT: return "cpymt";
        case Mnemonic::CPYMTN: return "cpymtn";
        case Mnemonic::CPYMTRN: return "cpymtrn";
        case Mnemonic::CPYMTWN: return "cpymtwn";
        case Mnemonic::CPYMWN: return "cpymwn";
        case Mnemonic::CPYMWT: return "cpymwt";
        case Mnemonic::CPYMWTN: return "cpymwtn";
        case Mnemonic::CPYMWTRN: return "cpymwtrn";
        case Mnemonic::CPYMWTWN: return "cpymwtwn";
        case Mnemonic::CPYP: return "cpyp";
        case Mnemonic::CPYPN: return "cpypn";
        case Mnemonic::CPYPRN: return "cpyprn";
        case Mnemonic::CPYPRT: return "cpyprt";
        case Mnemonic::CPYPRTN: return "cpyprtn";
        case Mnemonic::CPYPRTRN: return "cpyprtrn";
        case Mnemonic::CPYPRTWN: return "cpyprtwn";
        case Mnemonic::CPYPT: return "cpypt";
        case Mnemonic::CPYPTN: return "cpyptn";
        case Mnemonic::CPYPTRN: return "cpyptrn";
        case Mnemonic::CPYPTWN: return "cpyptwn";
        case Mnemonic::CPYPWN: return "cpypwn";
        case Mnemonic::CPYPWT: return "cpypwt";
        case Mnemonic::CPYPWTN: return "cpypwtn";
        case Mnemonic::CPYPWTRN: return "cpypwtrn";
        case Mnemonic::CPYPWTWN: return "cpypwtwn";
        case Mnemonic::CRC32B: return "crc32b";
        case Mnemonic::CRC32CB: return "crc32cb";
        case Mnemonic::CRC32CH: return "crc32ch";
        case Mnemonic::CRC32CW: return "crc32cw";
        case Mnemonic::CRC32CX: return "crc32cx";
        case Mnemonic::CRC32H: return "crc32h";
        case Mnemonic::CRC32W: return "crc32w";
        case Mnemonic::CRC32X: return "crc32x";
        case Mnemonic::CSDB: return "csdb";
        case Mnemonic::CSEL: return "csel";
        case Mnemonic::CSET: return "cset";
        case Mnemonic::CSETM: return "csetm";
        case Mnemonic::CSINC: return "csinc";
        case Mnemonic::CSINV: return "csinv";
        case Mnemonic::CSNEG: return "csneg";
        case Mnemonic::CTERMEQ: return "ctermeq";
        case Mnemonic::CTERMNE: return "ctermne";
        case Mnemonic::CTZ: return "ctz";
        case Mnemonic::DC: return "dc";
        case Mnemonic::DCPS1: return "dcps1";
        case Mnemonic::DCPS2: return "dcps2";
        case Mnemonic::DCPS3: return "dcps3";
        case Mnemonic::DECB: return "decb";
        case Mnemonic::DECD: return "decd";
        case Mnemonic::DECH: return "dech";
        case Mnemonic::DECP: return "decp";
        case Mnemonic::DECW: return "decw";
        case Mnemonic::DGH: return "dgh";
        case Mnemonic::DMB: return "dmb";
        case Mnemonic::DRPS: return "drps";
        case Mnemonic::DSB: return "dsb";
        case Mnemonic::DUP: return "dup";
        case Mnemonic::DUPM: return "dupm";
        case Mnemonic::DUPQ: return "dupq";
        case Mnemonic::DVP: return "dvp";
        case Mnemonic::EON: return "eon";
        case Mnemonic::EOR: return "eor";
        case Mnemonic::EOR3: return "eor3";
        case Mnemonic::EORBT: return "eorbt";
        case Mnemonic::EORQV: return "eorqv";
        case Mnemonic::EORS: return "eors";
        case Mnemonic::EORTB: return "eortb";
        case Mnemonic::EORV: return "eorv";
        case Mnemonic::ERET: return "eret";
        case Mnemonic::ERETAA: return "eretaa";
        case Mnemonic::ERETAB: return "eretab";
        case Mnemonic::ESB: return "esb";
        case Mnemonic::EXPAND: return "expand";
        case Mnemonic::EXT: return "ext";
        case Mnemonic::EXTQ: return "extq";
        case Mnemonic::EXTR: return "extr";
        case Mnemonic::F1CVT: return "f1cvt";
        case Mnemonic::F1CVTL: return "f1cvtl";
        case Mnemonic::F1CVTLT: return "f1cvtlt";
        case Mnemonic::F2CVT: return "f2cvt";
        case Mnemonic::F2CVTL: return "f2cvtl";
        case Mnemonic::F2CVTLT: return "f2cvtlt";
        case Mnemonic::FABD: return "fabd";
        case Mnemonic::FABS: return "fabs";
        case Mnemonic::FACGE: return "facge";
        case Mnemonic::FACGT: return "facgt";
        case Mnemonic::FADD: return "fadd";
        case Mnemonic::FADDA: return "fadda";
        case Mnemonic::FADDP: return "faddp";
        case Mnemonic::FADDQV: return "faddqv";
        case Mnemonic::FADDV: return "faddv";
        case Mnemonic::FAMAX: return "famax";
        case Mnemonic::FAMIN: return "famin";
        case Mnemonic::FCADD: return "fcadd";
        case Mnemonic::FCCMP: return "fccmp";
        case Mnemonic::FCCMPE: return "fccmpe";
        case Mnemonic::FCLAMP: return "fclamp";
        case Mnemonic::FCMEQ: return "fcmeq";
        case Mnemonic::FCMGE: return "fcmge";
        case Mnemonic::FCMGT: return "fcmgt";
        case Mnemonic::FCMLA: return "fcmla";
        case Mnemonic::FCMLE: return "fcmle";
        case Mnemonic::FCMLT: return "fcmlt";
        case Mnemonic::FCMNE: return "fcmne";
        case Mnemonic::FCMP: return "fcmp";
        case Mnemonic::FCMPE: return "fcmpe";
        case Mnemonic::FCMUO: return "fcmuo";
        case Mnemonic::FCPY: return "fcpy";
        case Mnemonic::FCSEL: return "fcsel";
        case Mnemonic::FCVT: return "fcvt";
        case Mnemonic::FCVTAS: return "fcvtas";
        case Mnemonic::FCVTAU: return "fcvtau";
        case Mnemonic::FCVTL: return "fcvtl";
        case Mnemonic::FCVTLT: return "fcvtlt";
        case Mnemonic::FCVTMS: return "fcvtms";
        case Mnemonic::FCVTMU: return "fcvtmu";
        case Mnemonic::FCVTN: return "fcvtn";
        case Mnemonic::FCVTNB: return "fcvtnb";
        case Mnemonic::FCVTNS: return "fcvtns";
        case Mnemonic::FCVTNT: return "fcvtnt";
        case Mnemonic::FCVTNU: return "fcvtnu";
        case Mnemonic::FCVTPS: return "fcvtps";
        case Mnemonic::FCVTPU: return "fcvtpu";
        case Mnemonic::FCVTX: return "fcvtx";
        case Mnemonic::FCVTXN: return "fcvtxn";
        case Mnemonic::FCVTXNT: return "fcvtxnt";
        case Mnemonic::FCVTZS: return "fcvtzs";
        case Mnemonic::FCVTZSN: return "fcvtzsn";
        case Mnemonic::FCVTZU: return "fcvtzu";
        case Mnemonic::FCVTZUN: return "fcvtzun";
        case Mnemonic::FDIV: return "fdiv";
        case Mnemonic::FDIVR: return "fdivr";
        case Mnemonic::FDOT: return "fdot";
        case Mnemonic::FDUP: return "fdup";
        case Mnemonic::FEXPA: return "fexpa";
        case Mnemonic::FIRSTP: return "firstp";
        case Mnemonic::FJCVTZS: return "fjcvtzs";
        case Mnemonic::FLOGB: return "flogb";
        case Mnemonic::FMAD: return "fmad";
        case Mnemonic::FMADD: return "fmadd";
        case Mnemonic::FMAX: return "fmax";
        case Mnemonic::FMAXNM: return "fmaxnm";
        case Mnemonic::FMAXNMP: return "fmaxnmp";
        case Mnemonic::FMAXNMQV: return "fmaxnmqv";
        case Mnemonic::FMAXNMV: return "fmaxnmv";
        case Mnemonic::FMAXP: return "fmaxp";
        case Mnemonic::FMAXQV: return "fmaxqv";
        case Mnemonic::FMAXV: return "fmaxv";
        case Mnemonic::FMIN: return "fmin";
        case Mnemonic::FMINNM: return "fminnm";
        case Mnemonic::FMINNMP: return "fminnmp";
        case Mnemonic::FMINNMQV: return "fminnmqv";
        case Mnemonic::FMINNMV: return "fminnmv";
        case Mnemonic::FMINP: return "fminp";
        case Mnemonic::FMINQV: return "fminqv";
        case Mnemonic::FMINV: return "fminv";
        case Mnemonic::FMLA: return "fmla";
        case Mnemonic::FMLAL: return "fmlal";
        case Mnemonic::FMLAL2: return "fmlal2";
        case Mnemonic::FMLALB: return "fmlalb";
        case Mnemonic::FMLALL: return "fmlall";
        case Mnemonic::FMLALLBB: return "fmlallbb";
        case Mnemonic::FMLALLBT: return "fmlallbt";
        case Mnemonic::FMLALLTB: return "fmlalltb";
        case Mnemonic::FMLALLTT: return "fmlalltt";
        case Mnemonic::FMLALT: return "fmlalt";
        case Mnemonic::FMLS: return "fmls";
        case Mnemonic::FMLSL: return "fmlsl";
        case Mnemonic::FMLSL2: return "fmlsl2";
        case Mnemonic::FMLSLB: return "fmlslb";
        case Mnemonic::FMLSLT: return "fmlslt";
        case Mnemonic::FMMLA: return "fmmla";
        case Mnemonic::FMOP4A: return "fmop4a";
        case Mnemonic::FMOP4S: return "fmop4s";
        case Mnemonic::FMOPA: return "fmopa";
        case Mnemonic::FMOPS: return "fmops";
        case Mnemonic::FMOV: return "fmov";
        case Mnemonic::FMSB: return "fmsb";
        case Mnemonic::FMSUB: return "fmsub";
        case Mnemonic::FMUL: return "fmul";
        case Mnemonic::FMULX: return "fmulx";
        case Mnemonic::FNEG: return "fneg";
        case Mnemonic::FNMAD: return "fnmad";
        case Mnemonic::FNMADD: return "fnmadd";
        case Mnemonic::FNMLA: return "fnmla";
        case Mnemonic::FNMLS: return "fnmls";
        case Mnemonic::FNMSB: return "fnmsb";
        case Mnemonic::FNMSUB: return "fnmsub";
        case Mnemonic::FNMUL: return "fnmul";
        case Mnemonic::FRECPE: return "frecpe";
        case Mnemonic::FRECPS: return "frecps";
        case Mnemonic::FRECPX: return "frecpx";
        case Mnemonic::FRINT32X: return "frint32x";
        case Mnemonic::FRINT32Z: return "frint32z";
        case Mnemonic::FRINT64X: return "frint64x";
        case Mnemonic::FRINT64Z: return "frint64z";
        case Mnemonic::FRINTA: return "frinta";
        case Mnemonic::FRINTI: return "frinti";
        case Mnemonic::FRINTM: return "frintm";
        case Mnemonic::FRINTN: return "frintn";
        case Mnemonic::FRINTP: return "frintp";
        case Mnemonic::FRINTX: return "frintx";
        case Mnemonic::FRINTZ: return "frintz";
        case Mnemonic::FRSQRTE: return "frsqrte";
        case Mnemonic::FRSQRTS: return "frsqrts";
        case Mnemonic::FSCALE: return "fscale";
        case Mnemonic::FSQRT: return "fsqrt";
        case Mnemonic::FSUB: return "fsub";
        case Mnemonic::FSUBR: return "fsubr";
        case Mnemonic::FTMAD: return "ftmad";
        case Mnemonic::FTMOPA: return "ftmopa";
        case Mnemonic::FTSMUL: return "ftsmul";
        case Mnemonic::FTSSEL: return "ftssel";
        case Mnemonic::FVDOT: return "fvdot";
        case Mnemonic::FVDOTB: return "fvdotb";
        case Mnemonic::FVDOTT: return "fvdott";
        case Mnemonic::GCSB: return "gcsb";
        case Mnemonic::GCSPOPCX: return "gcspopcx";
        case Mnemonic::GCSPOPM: return "gcspopm";
        case Mnemonic::GCSPOPX: return "gcspopx";
        case Mnemonic::GCSPUSHM: return "gcspushm";
        case Mnemonic::GCSPUSHX: return "gcspushx";
        case Mnemonic::GCSSS1: return "gcsss1";
        case Mnemonic::GCSSS2: return "gcsss2";
        case Mnemonic::GCSSTR: return "gcsstr";
        case Mnemonic::GCSSTTR: return "gcssttr";
        case Mnemonic::GIC: return "gic";
        case Mnemonic::GICR: return "gicr";
        case Mnemonic::GMI: return "gmi";
        case Mnemonic::GSB: return "gsb";
        case Mnemonic::HINT: return "hint";
        case Mnemonic::HISTCNT: return "histcnt";
        case Mnemonic::HISTSEG: return "histseg";
        case Mnemonic::HLT: return "hlt";
        case Mnemonic::HVC: return "hvc";
        case Mnemonic::IC: return "ic";
        case Mnemonic::INCB: return "incb";
        case Mnemonic::INCD: return "incd";
        case Mnemonic::INCH: return "inch";
        case Mnemonic::INCP: return "incp";
        case Mnemonic::INCW: return "incw";
        case Mnemonic::INDEX: return "index";
        case Mnemonic::INS: return "ins";
        case Mnemonic::INSR: return "insr";
        case Mnemonic::IRG: return "irg";
        case Mnemonic::ISB: return "isb";
        case Mnemonic::LASTA: return "lasta";
        case Mnemonic::LASTB: return "lastb";
        case Mnemonic::LASTP: return "lastp";
        case Mnemonic::LD1: return "ld1";
        case Mnemonic::LD1B: return "ld1b";
        case Mnemonic::LD1D: return "ld1d";
        case Mnemonic::LD1H: return "ld1h";
        case Mnemonic::LD1Q: return "ld1q";
        case Mnemonic::LD1R: return "ld1r";
        case Mnemonic::LD1RB: return "ld1rb";
        case Mnemonic::LD1RD: return "ld1rd";
        case Mnemonic::LD1RH: return "ld1rh";
        case Mnemonic::LD1ROB: return "ld1rob";
        case Mnemonic::LD1ROD: return "ld1rod";
        case Mnemonic::LD1ROH: return "ld1roh";
        case Mnemonic::LD1ROW: return "ld1row";
        case Mnemonic::LD1RQB: return "ld1rqb";
        case Mnemonic::LD1RQD: return "ld1rqd";
        case Mnemonic::LD1RQH: return "ld1rqh";
        case Mnemonic::LD1RQW: return "ld1rqw";
        case Mnemonic::LD1RSB: return "ld1rsb";
        case Mnemonic::LD1RSH: return "ld1rsh";
        case Mnemonic::LD1RSW: return "ld1rsw";
        case Mnemonic::LD1RW: return "ld1rw";
        case Mnemonic::LD1SB: return "ld1sb";
        case Mnemonic::LD1SH: return "ld1sh";
        case Mnemonic::LD1SW: return "ld1sw";
        case Mnemonic::LD1W: return "ld1w";
        case Mnemonic::LD2: return "ld2";
        case Mnemonic::LD2B: return "ld2b";
        case Mnemonic::LD2D: return "ld2d";
        case Mnemonic::LD2H: return "ld2h";
        case Mnemonic::LD2Q: return "ld2q";
        case Mnemonic::LD2R: return "ld2r";
        case Mnemonic::LD2W: return "ld2w";
        case Mnemonic::LD3: return "ld3";
        case Mnemonic::LD3B: return "ld3b";
        case Mnemonic::LD3D: return "ld3d";
        case Mnemonic::LD3H: return "ld3h";
        case Mnemonic::LD3Q: return "ld3q";
        case Mnemonic::LD3R: return "ld3r";
        case Mnemonic::LD3W: return "ld3w";
        case Mnemonic::LD4: return "ld4";
        case Mnemonic::LD4B: return "ld4b";
        case Mnemonic::LD4D: return "ld4d";
        case Mnemonic::LD4H: return "ld4h";
        case Mnemonic::LD4Q: return "ld4q";
        case Mnemonic::LD4R: return "ld4r";
        case Mnemonic::LD4W: return "ld4w";
        case Mnemonic::LD64B: return "ld64b";
        case Mnemonic::LDADD: return "ldadd";
        case Mnemonic::LDADDA: return "ldadda";
        case Mnemonic::LDADDAB: return "ldaddab";
        case Mnemonic::LDADDAH: return "ldaddah";
        case Mnemonic::LDADDAL: return "ldaddal";
        case Mnemonic::LDADDALB: return "ldaddalb";
        case Mnemonic::LDADDALH: return "ldaddalh";
        case Mnemonic::LDADDB: return "ldaddb";
        case Mnemonic::LDADDH: return "ldaddh";
        case Mnemonic::LDADDL: return "ldaddl";
        case Mnemonic::LDADDLB: return "ldaddlb";
        case Mnemonic::LDADDLH: return "ldaddlh";
        case Mnemonic::LDAP: return "ldap";
        case Mnemonic::LDAP1: return "ldap1";
        case Mnemonic::LDAPP: return "ldapp";
        case Mnemonic::LDAPR: return "ldapr";
        case Mnemonic::LDAPRB: return "ldaprb";
        case Mnemonic::LDAPRH: return "ldaprh";
        case Mnemonic::LDAPUR: return "ldapur";
        case Mnemonic::LDAPURB: return "ldapurb";
        case Mnemonic::LDAPURH: return "ldapurh";
        case Mnemonic::LDAPURSB: return "ldapursb";
        case Mnemonic::LDAPURSH: return "ldapursh";
        case Mnemonic::LDAPURSW: return "ldapursw";
        case Mnemonic::LDAR: return "ldar";
        case Mnemonic::LDARB: return "ldarb";
        case Mnemonic::LDARH: return "ldarh";
        case Mnemonic::LDATXR: return "ldatxr";
        case Mnemonic::LDAXP: return "ldaxp";
        case Mnemonic::LDAXR: return "ldaxr";
        case Mnemonic::LDAXRB: return "ldaxrb";
        case Mnemonic::LDAXRH: return "ldaxrh";
        case Mnemonic::LDBFADD: return "ldbfadd";
        case Mnemonic::LDBFADDA: return "ldbfadda";
        case Mnemonic::LDBFADDAL: return "ldbfaddal";
        case Mnemonic::LDBFADDL: return "ldbfaddl";
        case Mnemonic::LDBFMAX: return "ldbfmax";
        case Mnemonic::LDBFMAXA: return "ldbfmaxa";
        case Mnemonic::LDBFMAXAL: return "ldbfmaxal";
        case Mnemonic::LDBFMAXL: return "ldbfmaxl";
        case Mnemonic::LDBFMAXNM: return "ldbfmaxnm";
        case Mnemonic::LDBFMAXNMA: return "ldbfmaxnma";
        case Mnemonic::LDBFMAXNMAL: return "ldbfmaxnmal";
        case Mnemonic::LDBFMAXNML: return "ldbfmaxnml";
        case Mnemonic::LDBFMIN: return "ldbfmin";
        case Mnemonic::LDBFMINA: return "ldbfmina";
        case Mnemonic::LDBFMINAL: return "ldbfminal";
        case Mnemonic::LDBFMINL: return "ldbfminl";
        case Mnemonic::LDBFMINNM: return "ldbfminnm";
        case Mnemonic::LDBFMINNMA: return "ldbfminnma";
        case Mnemonic::LDBFMINNMAL: return "ldbfminnmal";
        case Mnemonic::LDBFMINNML: return "ldbfminnml";
        case Mnemonic::LDCLR: return "ldclr";
        case Mnemonic::LDCLRA: return "ldclra";
        case Mnemonic::LDCLRAB: return "ldclrab";
        case Mnemonic::LDCLRAH: return "ldclrah";
        case Mnemonic::LDCLRAL: return "ldclral";
        case Mnemonic::LDCLRALB: return "ldclralb";
        case Mnemonic::LDCLRALH: return "ldclralh";
        case Mnemonic::LDCLRB: return "ldclrb";
        case Mnemonic::LDCLRH: return "ldclrh";
        case Mnemonic::LDCLRL: return "ldclrl";
        case Mnemonic::LDCLRLB: return "ldclrlb";
        case Mnemonic::LDCLRLH: return "ldclrlh";
        case Mnemonic::LDCLRP: return "ldclrp";
        case Mnemonic::LDCLRPA: return "ldclrpa";
        case Mnemonic::LDCLRPAL: return "ldclrpal";
        case Mnemonic::LDCLRPL: return "ldclrpl";
        case Mnemonic::LDEOR: return "ldeor";
        case Mnemonic::LDEORA: return "ldeora";
        case Mnemonic::LDEORAB: return "ldeorab";
        case Mnemonic::LDEORAH: return "ldeorah";
        case Mnemonic::LDEORAL: return "ldeoral";
        case Mnemonic::LDEORALB: return "ldeoralb";
        case Mnemonic::LDEORALH: return "ldeoralh";
        case Mnemonic::LDEORB: return "ldeorb";
        case Mnemonic::LDEORH: return "ldeorh";
        case Mnemonic::LDEORL: return "ldeorl";
        case Mnemonic::LDEORLB: return "ldeorlb";
        case Mnemonic::LDEORLH: return "ldeorlh";
        case Mnemonic::LDFADD: return "ldfadd";
        case Mnemonic::LDFADDA: return "ldfadda";
        case Mnemonic::LDFADDAL: return "ldfaddal";
        case Mnemonic::LDFADDL: return "ldfaddl";
        case Mnemonic::LDFF1B: return "ldff1b";
        case Mnemonic::LDFF1D: return "ldff1d";
        case Mnemonic::LDFF1H: return "ldff1h";
        case Mnemonic::LDFF1SB: return "ldff1sb";
        case Mnemonic::LDFF1SH: return "ldff1sh";
        case Mnemonic::LDFF1SW: return "ldff1sw";
        case Mnemonic::LDFF1W: return "ldff1w";
        case Mnemonic::LDFMAX: return "ldfmax";
        case Mnemonic::LDFMAXA: return "ldfmaxa";
        case Mnemonic::LDFMAXAL: return "ldfmaxal";
        case Mnemonic::LDFMAXL: return "ldfmaxl";
        case Mnemonic::LDFMAXNM: return "ldfmaxnm";
        case Mnemonic::LDFMAXNMA: return "ldfmaxnma";
        case Mnemonic::LDFMAXNMAL: return "ldfmaxnmal";
        case Mnemonic::LDFMAXNML: return "ldfmaxnml";
        case Mnemonic::LDFMIN: return "ldfmin";
        case Mnemonic::LDFMINA: return "ldfmina";
        case Mnemonic::LDFMINAL: return "ldfminal";
        case Mnemonic::LDFMINL: return "ldfminl";
        case Mnemonic::LDFMINNM: return "ldfminnm";
        case Mnemonic::LDFMINNMA: return "ldfminnma";
        case Mnemonic::LDFMINNMAL: return "ldfminnmal";
        case Mnemonic::LDFMINNML: return "ldfminnml";
        case Mnemonic::LDG: return "ldg";
        case Mnemonic::LDGM: return "ldgm";
        case Mnemonic::LDIAPP: return "ldiapp";
        case Mnemonic::LDLAR: return "ldlar";
        case Mnemonic::LDLARB: return "ldlarb";
        case Mnemonic::LDLARH: return "ldlarh";
        case Mnemonic::LDNF1B: return "ldnf1b";
        case Mnemonic::LDNF1D: return "ldnf1d";
        case Mnemonic::LDNF1H: return "ldnf1h";
        case Mnemonic::LDNF1SB: return "ldnf1sb";
        case Mnemonic::LDNF1SH: return "ldnf1sh";
        case Mnemonic::LDNF1SW: return "ldnf1sw";
        case Mnemonic::LDNF1W: return "ldnf1w";
        case Mnemonic::LDNP: return "ldnp";
        case Mnemonic::LDNT1B: return "ldnt1b";
        case Mnemonic::LDNT1D: return "ldnt1d";
        case Mnemonic::LDNT1H: return "ldnt1h";
        case Mnemonic::LDNT1SB: return "ldnt1sb";
        case Mnemonic::LDNT1SH: return "ldnt1sh";
        case Mnemonic::LDNT1SW: return "ldnt1sw";
        case Mnemonic::LDNT1W: return "ldnt1w";
        case Mnemonic::LDP: return "ldp";
        case Mnemonic::LDPSW: return "ldpsw";
        case Mnemonic::LDR: return "ldr";
        case Mnemonic::LDRAA: return "ldraa";
        case Mnemonic::LDRAB: return "ldrab";
        case Mnemonic::LDRB: return "ldrb";
        case Mnemonic::LDRH: return "ldrh";
        case Mnemonic::LDRSB: return "ldrsb";
        case Mnemonic::LDRSH: return "ldrsh";
        case Mnemonic::LDRSW: return "ldrsw";
        case Mnemonic::LDSET: return "ldset";
        case Mnemonic::LDSETA: return "ldseta";
        case Mnemonic::LDSETAB: return "ldsetab";
        case Mnemonic::LDSETAH: return "ldsetah";
        case Mnemonic::LDSETAL: return "ldsetal";
        case Mnemonic::LDSETALB: return "ldsetalb";
        case Mnemonic::LDSETALH: return "ldsetalh";
        case Mnemonic::LDSETB: return "ldsetb";
        case Mnemonic::LDSETH: return "ldseth";
        case Mnemonic::LDSETL: return "ldsetl";
        case Mnemonic::LDSETLB: return "ldsetlb";
        case Mnemonic::LDSETLH: return "ldsetlh";
        case Mnemonic::LDSETP: return "ldsetp";
        case Mnemonic::LDSETPA: return "ldsetpa";
        case Mnemonic::LDSETPAL: return "ldsetpal";
        case Mnemonic::LDSETPL: return "ldsetpl";
        case Mnemonic::LDSMAX: return "ldsmax";
        case Mnemonic::LDSMAXA: return "ldsmaxa";
        case Mnemonic::LDSMAXAB: return "ldsmaxab";
        case Mnemonic::LDSMAXAH: return "ldsmaxah";
        case Mnemonic::LDSMAXAL: return "ldsmaxal";
        case Mnemonic::LDSMAXALB: return "ldsmaxalb";
        case Mnemonic::LDSMAXALH: return "ldsmaxalh";
        case Mnemonic::LDSMAXB: return "ldsmaxb";
        case Mnemonic::LDSMAXH: return "ldsmaxh";
        case Mnemonic::LDSMAXL: return "ldsmaxl";
        case Mnemonic::LDSMAXLB: return "ldsmaxlb";
        case Mnemonic::LDSMAXLH: return "ldsmaxlh";
        case Mnemonic::LDSMIN: return "ldsmin";
        case Mnemonic::LDSMINA: return "ldsmina";
        case Mnemonic::LDSMINAB: return "ldsminab";
        case Mnemonic::LDSMINAH: return "ldsminah";
        case Mnemonic::LDSMINAL: return "ldsminal";
        case Mnemonic::LDSMINALB: return "ldsminalb";
        case Mnemonic::LDSMINALH: return "ldsminalh";
        case Mnemonic::LDSMINB: return "ldsminb";
        case Mnemonic::LDSMINH: return "ldsminh";
        case Mnemonic::LDSMINL: return "ldsminl";
        case Mnemonic::LDSMINLB: return "ldsminlb";
        case Mnemonic::LDSMINLH: return "ldsminlh";
        case Mnemonic::LDTADD: return "ldtadd";
        case Mnemonic::LDTADDA: return "ldtadda";
        case Mnemonic::LDTADDAL: return "ldtaddal";
        case Mnemonic::LDTADDL: return "ldtaddl";
        case Mnemonic::LDTCLR: return "ldtclr";
        case Mnemonic::LDTCLRA: return "ldtclra";
        case Mnemonic::LDTCLRAL: return "ldtclral";
        case Mnemonic::LDTCLRL: return "ldtclrl";
        case Mnemonic::LDTNP: return "ldtnp";
        case Mnemonic::LDTP: return "ldtp";
        case Mnemonic::LDTR: return "ldtr";
        case Mnemonic::LDTRB: return "ldtrb";
        case Mnemonic::LDTRH: return "ldtrh";
        case Mnemonic::LDTRSB: return "ldtrsb";
        case Mnemonic::LDTRSH: return "ldtrsh";
        case Mnemonic::LDTRSW: return "ldtrsw";
        case Mnemonic::LDTSET: return "ldtset";
        case Mnemonic::LDTSETA: return "ldtseta";
        case Mnemonic::LDTSETAL: return "ldtsetal";
        case Mnemonic::LDTSETL: return "ldtsetl";
        case Mnemonic::LDTXR: return "ldtxr";
        case Mnemonic::LDUMAX: return "ldumax";
        case Mnemonic::LDUMAXA: return "ldumaxa";
        case Mnemonic::LDUMAXAB: return "ldumaxab";
        case Mnemonic::LDUMAXAH: return "ldumaxah";
        case Mnemonic::LDUMAXAL: return "ldumaxal";
        case Mnemonic::LDUMAXALB: return "ldumaxalb";
        case Mnemonic::LDUMAXALH: return "ldumaxalh";
        case Mnemonic::LDUMAXB: return "ldumaxb";
        case Mnemonic::LDUMAXH: return "ldumaxh";
        case Mnemonic::LDUMAXL: return "ldumaxl";
        case Mnemonic::LDUMAXLB: return "ldumaxlb";
        case Mnemonic::LDUMAXLH: return "ldumaxlh";
        case Mnemonic::LDUMIN: return "ldumin";
        case Mnemonic::LDUMINA: return "ldumina";
        case Mnemonic::LDUMINAB: return "lduminab";
        case Mnemonic::LDUMINAH: return "lduminah";
        case Mnemonic::LDUMINAL: return "lduminal";
        case Mnemonic::LDUMINALB: return "lduminalb";
        case Mnemonic::LDUMINALH: return "lduminalh";
        case Mnemonic::LDUMINB: return "lduminb";
        case Mnemonic::LDUMINH: return "lduminh";
        case Mnemonic::LDUMINL: return "lduminl";
        case Mnemonic::LDUMINLB: return "lduminlb";
        case Mnemonic::LDUMINLH: return "lduminlh";
        case Mnemonic::LDUR: return "ldur";
        case Mnemonic::LDURB: return "ldurb";
        case Mnemonic::LDURH: return "ldurh";
        case Mnemonic::LDURSB: return "ldursb";
        case Mnemonic::LDURSH: return "ldursh";
        case Mnemonic::LDURSW: return "ldursw";
        case Mnemonic::LDXP: return "ldxp";
        case Mnemonic::LDXR: return "ldxr";
        case Mnemonic::LDXRB: return "ldxrb";
        case Mnemonic::LDXRH: return "ldxrh";
        case Mnemonic::LSL: return "lsl";
        case Mnemonic::LSLR: return "lslr";
        case Mnemonic::LSLV: return "lslv";
        case Mnemonic::LSR: return "lsr";
        case Mnemonic::LSRR: return "lsrr";
        case Mnemonic::LSRV: return "lsrv";
        case Mnemonic::LUTI2: return "luti2";
        case Mnemonic::LUTI4: return "luti4";
        case Mnemonic::LUTI6: return "luti6";
        case Mnemonic::MAD: return "mad";
        case Mnemonic::MADD: return "madd";
        case Mnemonic::MADDPT: return "maddpt";
        case Mnemonic::MADPT: return "madpt";
        case Mnemonic::MATCH: return "match";
        case Mnemonic::MLA: return "mla";
        case Mnemonic::MLAPT: return "mlapt";
        case Mnemonic::MLBI: return "mlbi";
        case Mnemonic::MLS: return "mls";
        case Mnemonic::MNEG: return "mneg";
        case Mnemonic::MOV: return "mov";
        case Mnemonic::MOVA: return "mova";
        case Mnemonic::MOVAZ: return "movaz";
        case Mnemonic::MOVI: return "movi";
        case Mnemonic::MOVK: return "movk";
        case Mnemonic::MOVN: return "movn";
        case Mnemonic::MOVPRFX: return "movprfx";
        case Mnemonic::MOVS: return "movs";
        case Mnemonic::MOVT: return "movt";
        case Mnemonic::MOVZ: return "movz";
        case Mnemonic::MRRS: return "mrrs";
        case Mnemonic::MRS: return "mrs";
        case Mnemonic::MSB: return "msb";
        case Mnemonic::MSR: return "msr";
        case Mnemonic::MSRR: return "msrr";
        case Mnemonic::MSUB: return "msub";
        case Mnemonic::MSUBPT: return "msubpt";
        case Mnemonic::MUL: return "mul";
        case Mnemonic::MVN: return "mvn";
        case Mnemonic::MVNI: return "mvni";
        case Mnemonic::NAND: return "nand";
        case Mnemonic::NANDS: return "nands";
        case Mnemonic::NBSL: return "nbsl";
        case Mnemonic::NEG: return "neg";
        case Mnemonic::NEGS: return "negs";
        case Mnemonic::NGC: return "ngc";
        case Mnemonic::NGCS: return "ngcs";
        case Mnemonic::NMATCH: return "nmatch";
        case Mnemonic::NOP: return "nop";
        case Mnemonic::NOR: return "nor";
        case Mnemonic::NORS: return "nors";
        case Mnemonic::NOT: return "not";
        case Mnemonic::ORN: return "orn";
        case Mnemonic::ORNS: return "orns";
        case Mnemonic::ORQV: return "orqv";
        case Mnemonic::ORR: return "orr";
        case Mnemonic::ORRS: return "orrs";
        case Mnemonic::ORV: return "orv";
        case Mnemonic::PACDA: return "pacda";
        case Mnemonic::PACDB: return "pacdb";
        case Mnemonic::PACDZA: return "pacdza";
        case Mnemonic::PACDZB: return "pacdzb";
        case Mnemonic::PACGA: return "pacga";
        case Mnemonic::PACIA: return "pacia";
        case Mnemonic::PACIA1716: return "pacia1716";
        case Mnemonic::PACIA171615: return "pacia171615";
        case Mnemonic::PACIASP: return "paciasp";
        case Mnemonic::PACIASPPC: return "paciasppc";
        case Mnemonic::PACIAZ: return "paciaz";
        case Mnemonic::PACIB: return "pacib";
        case Mnemonic::PACIB1716: return "pacib1716";
        case Mnemonic::PACIB171615: return "pacib171615";
        case Mnemonic::PACIBSP: return "pacibsp";
        case Mnemonic::PACIBSPPC: return "pacibsppc";
        case Mnemonic::PACIBZ: return "pacibz";
        case Mnemonic::PACIZA: return "paciza";
        case Mnemonic::PACIZB: return "pacizb";
        case Mnemonic::PACM: return "pacm";
        case Mnemonic::PACNBIASPPC: return "pacnbiasppc";
        case Mnemonic::PACNBIBSPPC: return "pacnbibsppc";
        case Mnemonic::PEXT: return "pext";
        case Mnemonic::PFALSE: return "pfalse";
        case Mnemonic::PFIRST: return "pfirst";
        case Mnemonic::PMLAL: return "pmlal";
        case Mnemonic::PMOV: return "pmov";
        case Mnemonic::PMUL: return "pmul";
        case Mnemonic::PMULL: return "pmull";
        case Mnemonic::PMULLB: return "pmullb";
        case Mnemonic::PMULLT: return "pmullt";
        case Mnemonic::PNEXT: return "pnext";
        case Mnemonic::PRFB: return "prfb";
        case Mnemonic::PRFD: return "prfd";
        case Mnemonic::PRFH: return "prfh";
        case Mnemonic::PRFM: return "prfm";
        case Mnemonic::PRFUM: return "prfum";
        case Mnemonic::PRFW: return "prfw";
        case Mnemonic::PSB: return "psb";
        case Mnemonic::PSEL: return "psel";
        case Mnemonic::PSSBB: return "pssbb";
        case Mnemonic::PTEST: return "ptest";
        case Mnemonic::PTRUE: return "ptrue";
        case Mnemonic::PTRUES: return "ptrues";
        case Mnemonic::PUNPKHI: return "punpkhi";
        case Mnemonic::PUNPKLO: return "punpklo";
        case Mnemonic::RADDHN: return "raddhn";
        case Mnemonic::RADDHNB: return "raddhnb";
        case Mnemonic::RADDHNT: return "raddhnt";
        case Mnemonic::RAX1: return "rax1";
        case Mnemonic::RBIT: return "rbit";
        case Mnemonic::RCWCAS: return "rcwcas";
        case Mnemonic::RCWCASA: return "rcwcasa";
        case Mnemonic::RCWCASAL: return "rcwcasal";
        case Mnemonic::RCWCASL: return "rcwcasl";
        case Mnemonic::RCWCASP: return "rcwcasp";
        case Mnemonic::RCWCASPA: return "rcwcaspa";
        case Mnemonic::RCWCASPAL: return "rcwcaspal";
        case Mnemonic::RCWCASPL: return "rcwcaspl";
        case Mnemonic::RCWCLR: return "rcwclr";
        case Mnemonic::RCWCLRA: return "rcwclra";
        case Mnemonic::RCWCLRAL: return "rcwclral";
        case Mnemonic::RCWCLRL: return "rcwclrl";
        case Mnemonic::RCWCLRP: return "rcwclrp";
        case Mnemonic::RCWCLRPA: return "rcwclrpa";
        case Mnemonic::RCWCLRPAL: return "rcwclrpal";
        case Mnemonic::RCWCLRPL: return "rcwclrpl";
        case Mnemonic::RCWSCAS: return "rcwscas";
        case Mnemonic::RCWSCASA: return "rcwscasa";
        case Mnemonic::RCWSCASAL: return "rcwscasal";
        case Mnemonic::RCWSCASL: return "rcwscasl";
        case Mnemonic::RCWSCASP: return "rcwscasp";
        case Mnemonic::RCWSCASPA: return "rcwscaspa";
        case Mnemonic::RCWSCASPAL: return "rcwscaspal";
        case Mnemonic::RCWSCASPL: return "rcwscaspl";
        case Mnemonic::RCWSCLR: return "rcwsclr";
        case Mnemonic::RCWSCLRA: return "rcwsclra";
        case Mnemonic::RCWSCLRAL: return "rcwsclral";
        case Mnemonic::RCWSCLRL: return "rcwsclrl";
        case Mnemonic::RCWSCLRP: return "rcwsclrp";
        case Mnemonic::RCWSCLRPA: return "rcwsclrpa";
        case Mnemonic::RCWSCLRPAL: return "rcwsclrpal";
        case Mnemonic::RCWSCLRPL: return "rcwsclrpl";
        case Mnemonic::RCWSET: return "rcwset";
        case Mnemonic::RCWSETA: return "rcwseta";
        case Mnemonic::RCWSETAL: return "rcwsetal";
        case Mnemonic::RCWSETL: return "rcwsetl";
        case Mnemonic::RCWSETP: return "rcwsetp";
        case Mnemonic::RCWSETPA: return "rcwsetpa";
        case Mnemonic::RCWSETPAL: return "rcwsetpal";
        case Mnemonic::RCWSETPL: return "rcwsetpl";
        case Mnemonic::RCWSSET: return "rcwsset";
        case Mnemonic::RCWSSETA: return "rcwsseta";
        case Mnemonic::RCWSSETAL: return "rcwssetal";
        case Mnemonic::RCWSSETL: return "rcwssetl";
        case Mnemonic::RCWSSETP: return "rcwssetp";
        case Mnemonic::RCWSSETPA: return "rcwssetpa";
        case Mnemonic::RCWSSETPAL: return "rcwssetpal";
        case Mnemonic::RCWSSETPL: return "rcwssetpl";
        case Mnemonic::RCWSSWP: return "rcwsswp";
        case Mnemonic::RCWSSWPA: return "rcwsswpa";
        case Mnemonic::RCWSSWPAL: return "rcwsswpal";
        case Mnemonic::RCWSSWPL: return "rcwsswpl";
        case Mnemonic::RCWSSWPP: return "rcwsswpp";
        case Mnemonic::RCWSSWPPA: return "rcwsswppa";
        case Mnemonic::RCWSSWPPAL: return "rcwsswppal";
        case Mnemonic::RCWSSWPPL: return "rcwsswppl";
        case Mnemonic::RCWSWP: return "rcwswp";
        case Mnemonic::RCWSWPA: return "rcwswpa";
        case Mnemonic::RCWSWPAL: return "rcwswpal";
        case Mnemonic::RCWSWPL: return "rcwswpl";
        case Mnemonic::RCWSWPP: return "rcwswpp";
        case Mnemonic::RCWSWPPA: return "rcwswppa";
        case Mnemonic::RCWSWPPAL: return "rcwswppal";
        case Mnemonic::RCWSWPPL: return "rcwswppl";
        case Mnemonic::RDFFR: return "rdffr";
        case Mnemonic::RDFFRS: return "rdffrs";
        case Mnemonic::RDSVL: return "rdsvl";
        case Mnemonic::RDVL: return "rdvl";
        case Mnemonic::RET: return "ret";
        case Mnemonic::RETAA: return "retaa";
        case Mnemonic::RETAASPPC: return "retaasppc";
        case Mnemonic::RETAASPPCR: return "retaasppcr";
        case Mnemonic::RETAB: return "retab";
        case Mnemonic::RETABSPPC: return "retabsppc";
        case Mnemonic::RETABSPPCR: return "retabsppcr";
        case Mnemonic::REV: return "rev";
        case Mnemonic::REV16: return "rev16";
        case Mnemonic::REV32: return "rev32";
        case Mnemonic::REV64: return "rev64";
        case Mnemonic::REVB: return "revb";
        case Mnemonic::REVD: return "revd";
        case Mnemonic::REVH: return "revh";
        case Mnemonic::REVW: return "revw";
        case Mnemonic::RMIF: return "rmif";
        case Mnemonic::ROR: return "ror";
        case Mnemonic::RORV: return "rorv";
        case Mnemonic::RPRFM: return "rprfm";
        case Mnemonic::RSHRN: return "rshrn";
        case Mnemonic::RSHRNB: return "rshrnb";
        case Mnemonic::RSHRNT: return "rshrnt";
        case Mnemonic::RSUBHN: return "rsubhn";
        case Mnemonic::RSUBHNB: return "rsubhnb";
        case Mnemonic::RSUBHNT: return "rsubhnt";
        case Mnemonic::SABA: return "saba";
        case Mnemonic::SABAL: return "sabal";
        case Mnemonic::SABALB: return "sabalb";
        case Mnemonic::SABALT: return "sabalt";
        case Mnemonic::SABD: return "sabd";
        case Mnemonic::SABDL: return "sabdl";
        case Mnemonic::SABDLB: return "sabdlb";
        case Mnemonic::SABDLT: return "sabdlt";
        case Mnemonic::SADALP: return "sadalp";
        case Mnemonic::SADDL: return "saddl";
        case Mnemonic::SADDLB: return "saddlb";
        case Mnemonic::SADDLBT: return "saddlbt";
        case Mnemonic::SADDLP: return "saddlp";
        case Mnemonic::SADDLT: return "saddlt";
        case Mnemonic::SADDLV: return "saddlv";
        case Mnemonic::SADDV: return "saddv";
        case Mnemonic::SADDW: return "saddw";
        case Mnemonic::SADDWB: return "saddwb";
        case Mnemonic::SADDWT: return "saddwt";
        case Mnemonic::SB: return "sb";
        case Mnemonic::SBC: return "sbc";
        case Mnemonic::SBCLB: return "sbclb";
        case Mnemonic::SBCLT: return "sbclt";
        case Mnemonic::SBCS: return "sbcs";
        case Mnemonic::SBFIZ: return "sbfiz";
        case Mnemonic::SBFM: return "sbfm";
        case Mnemonic::SCLAMP: return "sclamp";
        case Mnemonic::SCVTF: return "scvtf";
        case Mnemonic::SCVTFLT: return "scvtflt";
        case Mnemonic::SDIV: return "sdiv";
        case Mnemonic::SDIVR: return "sdivr";
        case Mnemonic::SDOT: return "sdot";
        case Mnemonic::SEL: return "sel";
        case Mnemonic::SETE: return "sete";
        case Mnemonic::SETEN: return "seten";
        case Mnemonic::SETET: return "setet";
        case Mnemonic::SETETN: return "setetn";
        case Mnemonic::SETF16: return "setf16";
        case Mnemonic::SETF8: return "setf8";
        case Mnemonic::SETFFR: return "setffr";
        case Mnemonic::SETGE: return "setge";
        case Mnemonic::SETGEN: return "setgen";
        case Mnemonic::SETGET: return "setget";
        case Mnemonic::SETGETN: return "setgetn";
        case Mnemonic::SETGM: return "setgm";
        case Mnemonic::SETGMN: return "setgmn";
        case Mnemonic::SETGMT: return "setgmt";
        case Mnemonic::SETGMTN: return "setgmtn";
        case Mnemonic::SETGP: return "setgp";
        case Mnemonic::SETGPN: return "setgpn";
        case Mnemonic::SETGPT: return "setgpt";
        case Mnemonic::SETGPTN: return "setgptn";
        case Mnemonic::SETM: return "setm";
        case Mnemonic::SETMN: return "setmn";
        case Mnemonic::SETMT: return "setmt";
        case Mnemonic::SETMTN: return "setmtn";
        case Mnemonic::SETP: return "setp";
        case Mnemonic::SETPN: return "setpn";
        case Mnemonic::SETPT: return "setpt";
        case Mnemonic::SETPTN: return "setptn";
        case Mnemonic::SEV: return "sev";
        case Mnemonic::SEVL: return "sevl";
        case Mnemonic::SHA1C: return "sha1c";
        case Mnemonic::SHA1H: return "sha1h";
        case Mnemonic::SHA1M: return "sha1m";
        case Mnemonic::SHA1P: return "sha1p";
        case Mnemonic::SHA1SU0: return "sha1su0";
        case Mnemonic::SHA1SU1: return "sha1su1";
        case Mnemonic::SHA256H: return "sha256h";
        case Mnemonic::SHA256H2: return "sha256h2";
        case Mnemonic::SHA256SU0: return "sha256su0";
        case Mnemonic::SHA256SU1: return "sha256su1";
        case Mnemonic::SHA512H: return "sha512h";
        case Mnemonic::SHA512H2: return "sha512h2";
        case Mnemonic::SHA512SU0: return "sha512su0";
        case Mnemonic::SHA512SU1: return "sha512su1";
        case Mnemonic::SHADD: return "shadd";
        case Mnemonic::SHL: return "shl";
        case Mnemonic::SHLL: return "shll";
        case Mnemonic::SHRN: return "shrn";
        case Mnemonic::SHRNB: return "shrnb";
        case Mnemonic::SHRNT: return "shrnt";
        case Mnemonic::SHSUB: return "shsub";
        case Mnemonic::SHSUBR: return "shsubr";
        case Mnemonic::SHUH: return "shuh";
        case Mnemonic::SLI: return "sli";
        case Mnemonic::SM3PARTW1: return "sm3partw1";
        case Mnemonic::SM3PARTW2: return "sm3partw2";
        case Mnemonic::SM3SS1: return "sm3ss1";
        case Mnemonic::SM3TT1A: return "sm3tt1a";
        case Mnemonic::SM3TT1B: return "sm3tt1b";
        case Mnemonic::SM3TT2A: return "sm3tt2a";
        case Mnemonic::SM3TT2B: return "sm3tt2b";
        case Mnemonic::SM4E: return "sm4e";
        case Mnemonic::SM4EKEY: return "sm4ekey";
        case Mnemonic::SMADDL: return "smaddl";
        case Mnemonic::SMAX: return "smax";
        case Mnemonic::SMAXP: return "smaxp";
        case Mnemonic::SMAXQV: return "smaxqv";
        case Mnemonic::SMAXV: return "smaxv";
        case Mnemonic::SMC: return "smc";
        case Mnemonic::SMIN: return "smin";
        case Mnemonic::SMINP: return "sminp";
        case Mnemonic::SMINQV: return "sminqv";
        case Mnemonic::SMINV: return "sminv";
        case Mnemonic::SMLAL: return "smlal";
        case Mnemonic::SMLALB: return "smlalb";
        case Mnemonic::SMLALL: return "smlall";
        case Mnemonic::SMLALT: return "smlalt";
        case Mnemonic::SMLSL: return "smlsl";
        case Mnemonic::SMLSLB: return "smlslb";
        case Mnemonic::SMLSLL: return "smlsll";
        case Mnemonic::SMLSLT: return "smlslt";
        case Mnemonic::SMMLA: return "smmla";
        case Mnemonic::SMNEGL: return "smnegl";
        case Mnemonic::SMOP4A: return "smop4a";
        case Mnemonic::SMOP4S: return "smop4s";
        case Mnemonic::SMOPA: return "smopa";
        case Mnemonic::SMOPS: return "smops";
        case Mnemonic::SMOV: return "smov";
        case Mnemonic::SMSTART: return "smstart";
        case Mnemonic::SMSTOP: return "smstop";
        case Mnemonic::SMSUBL: return "smsubl";
        case Mnemonic::SMULH: return "smulh";
        case Mnemonic::SMULL: return "smull";
        case Mnemonic::SMULLB: return "smullb";
        case Mnemonic::SMULLT: return "smullt";
        case Mnemonic::SPLICE: return "splice";
        case Mnemonic::SQABS: return "sqabs";
        case Mnemonic::SQADD: return "sqadd";
        case Mnemonic::SQCADD: return "sqcadd";
        case Mnemonic::SQCVT: return "sqcvt";
        case Mnemonic::SQCVTN: return "sqcvtn";
        case Mnemonic::SQCVTU: return "sqcvtu";
        case Mnemonic::SQCVTUN: return "sqcvtun";
        case Mnemonic::SQDECB: return "sqdecb";
        case Mnemonic::SQDECD: return "sqdecd";
        case Mnemonic::SQDECH: return "sqdech";
        case Mnemonic::SQDECP: return "sqdecp";
        case Mnemonic::SQDECW: return "sqdecw";
        case Mnemonic::SQDMLAL: return "sqdmlal";
        case Mnemonic::SQDMLALB: return "sqdmlalb";
        case Mnemonic::SQDMLALBT: return "sqdmlalbt";
        case Mnemonic::SQDMLALT: return "sqdmlalt";
        case Mnemonic::SQDMLSL: return "sqdmlsl";
        case Mnemonic::SQDMLSLB: return "sqdmlslb";
        case Mnemonic::SQDMLSLBT: return "sqdmlslbt";
        case Mnemonic::SQDMLSLT: return "sqdmlslt";
        case Mnemonic::SQDMULH: return "sqdmulh";
        case Mnemonic::SQDMULL: return "sqdmull";
        case Mnemonic::SQDMULLB: return "sqdmullb";
        case Mnemonic::SQDMULLT: return "sqdmullt";
        case Mnemonic::SQINCB: return "sqincb";
        case Mnemonic::SQINCD: return "sqincd";
        case Mnemonic::SQINCH: return "sqinch";
        case Mnemonic::SQINCP: return "sqincp";
        case Mnemonic::SQINCW: return "sqincw";
        case Mnemonic::SQNEG: return "sqneg";
        case Mnemonic::SQRDCMLAH: return "sqrdcmlah";
        case Mnemonic::SQRDMLAH: return "sqrdmlah";
        case Mnemonic::SQRDMLSH: return "sqrdmlsh";
        case Mnemonic::SQRDMULH: return "sqrdmulh";
        case Mnemonic::SQRSHL: return "sqrshl";
        case Mnemonic::SQRSHLR: return "sqrshlr";
        case Mnemonic::SQRSHR: return "sqrshr";
        case Mnemonic::SQRSHRN: return "sqrshrn";
        case Mnemonic::SQRSHRNB: return "sqrshrnb";
        case Mnemonic::SQRSHRNT: return "sqrshrnt";
        case Mnemonic::SQRSHRU: return "sqrshru";
        case Mnemonic::SQRSHRUN: return "sqrshrun";
        case Mnemonic::SQRSHRUNB: return "sqrshrunb";
        case Mnemonic::SQRSHRUNT: return "sqrshrunt";
        case Mnemonic::SQSHL: return "sqshl";
        case Mnemonic::SQSHLR: return "sqshlr";
        case Mnemonic::SQSHLU: return "sqshlu";
        case Mnemonic::SQSHRN: return "sqshrn";
        case Mnemonic::SQSHRNB: return "sqshrnb";
        case Mnemonic::SQSHRNT: return "sqshrnt";
        case Mnemonic::SQSHRUN: return "sqshrun";
        case Mnemonic::SQSHRUNB: return "sqshrunb";
        case Mnemonic::SQSHRUNT: return "sqshrunt";
        case Mnemonic::SQSUB: return "sqsub";
        case Mnemonic::SQSUBR: return "sqsubr";
        case Mnemonic::SQXTN: return "sqxtn";
        case Mnemonic::SQXTNB: return "sqxtnb";
        case Mnemonic::SQXTNT: return "sqxtnt";
        case Mnemonic::SQXTUN: return "sqxtun";
        case Mnemonic::SQXTUNB: return "sqxtunb";
        case Mnemonic::SQXTUNT: return "sqxtunt";
        case Mnemonic::SRHADD: return "srhadd";
        case Mnemonic::SRI: return "sri";
        case Mnemonic::SRSHL: return "srshl";
        case Mnemonic::SRSHLR: return "srshlr";
        case Mnemonic::SRSHR: return "srshr";
        case Mnemonic::SRSRA: return "srsra";
        case Mnemonic::SSBB: return "ssbb";
        case Mnemonic::SSHL: return "sshl";
        case Mnemonic::SSHLL: return "sshll";
        case Mnemonic::SSHLLB: return "sshllb";
        case Mnemonic::SSHLLT: return "sshllt";
        case Mnemonic::SSHR: return "sshr";
        case Mnemonic::SSRA: return "ssra";
        case Mnemonic::SSUBL: return "ssubl";
        case Mnemonic::SSUBLB: return "ssublb";
        case Mnemonic::SSUBLBT: return "ssublbt";
        case Mnemonic::SSUBLT: return "ssublt";
        case Mnemonic::SSUBLTB: return "ssubltb";
        case Mnemonic::SSUBW: return "ssubw";
        case Mnemonic::SSUBWB: return "ssubwb";
        case Mnemonic::SSUBWT: return "ssubwt";
        case Mnemonic::ST1: return "st1";
        case Mnemonic::ST1B: return "st1b";
        case Mnemonic::ST1D: return "st1d";
        case Mnemonic::ST1H: return "st1h";
        case Mnemonic::ST1Q: return "st1q";
        case Mnemonic::ST1W: return "st1w";
        case Mnemonic::ST2: return "st2";
        case Mnemonic::ST2B: return "st2b";
        case Mnemonic::ST2D: return "st2d";
        case Mnemonic::ST2G: return "st2g";
        case Mnemonic::ST2H: return "st2h";
        case Mnemonic::ST2Q: return "st2q";
        case Mnemonic::ST2W: return "st2w";
        case Mnemonic::ST3: return "st3";
        case Mnemonic::ST3B: return "st3b";
        case Mnemonic::ST3D: return "st3d";
        case Mnemonic::ST3H: return "st3h";
        case Mnemonic::ST3Q: return "st3q";
        case Mnemonic::ST3W: return "st3w";
        case Mnemonic::ST4: return "st4";
        case Mnemonic::ST4B: return "st4b";
        case Mnemonic::ST4D: return "st4d";
        case Mnemonic::ST4H: return "st4h";
        case Mnemonic::ST4Q: return "st4q";
        case Mnemonic::ST4W: return "st4w";
        case Mnemonic::ST64B: return "st64b";
        case Mnemonic::ST64BV: return "st64bv";
        case Mnemonic::ST64BV0: return "st64bv0";
        case Mnemonic::STBFADD: return "stbfadd";
        case Mnemonic::STBFADDL: return "stbfaddl";
        case Mnemonic::STBFMAX: return "stbfmax";
        case Mnemonic::STBFMAXL: return "stbfmaxl";
        case Mnemonic::STBFMAXNM: return "stbfmaxnm";
        case Mnemonic::STBFMAXNML: return "stbfmaxnml";
        case Mnemonic::STBFMIN: return "stbfmin";
        case Mnemonic::STBFMINL: return "stbfminl";
        case Mnemonic::STBFMINNM: return "stbfminnm";
        case Mnemonic::STBFMINNML: return "stbfminnml";
        case Mnemonic::STCPH: return "stcph";
        case Mnemonic::STFADD: return "stfadd";
        case Mnemonic::STFADDL: return "stfaddl";
        case Mnemonic::STFMAX: return "stfmax";
        case Mnemonic::STFMAXL: return "stfmaxl";
        case Mnemonic::STFMAXNM: return "stfmaxnm";
        case Mnemonic::STFMAXNML: return "stfmaxnml";
        case Mnemonic::STFMIN: return "stfmin";
        case Mnemonic::STFMINL: return "stfminl";
        case Mnemonic::STFMINNM: return "stfminnm";
        case Mnemonic::STFMINNML: return "stfminnml";
        case Mnemonic::STG: return "stg";
        case Mnemonic::STGM: return "stgm";
        case Mnemonic::STGP: return "stgp";
        case Mnemonic::STILP: return "stilp";
        case Mnemonic::STL1: return "stl1";
        case Mnemonic::STLLR: return "stllr";
        case Mnemonic::STLLRB: return "stllrb";
        case Mnemonic::STLLRH: return "stllrh";
        case Mnemonic::STLP: return "stlp";
        case Mnemonic::STLR: return "stlr";
        case Mnemonic::STLRB: return "stlrb";
        case Mnemonic::STLRH: return "stlrh";
        case Mnemonic::STLTXR: return "stltxr";
        case Mnemonic::STLUR: return "stlur";
        case Mnemonic::STLURB: return "stlurb";
        case Mnemonic::STLURH: return "stlurh";
        case Mnemonic::STLXP: return "stlxp";
        case Mnemonic::STLXR: return "stlxr";
        case Mnemonic::STLXRB: return "stlxrb";
        case Mnemonic::STLXRH: return "stlxrh";
        case Mnemonic::STMOPA: return "stmopa";
        case Mnemonic::STNP: return "stnp";
        case Mnemonic::STNT1B: return "stnt1b";
        case Mnemonic::STNT1D: return "stnt1d";
        case Mnemonic::STNT1H: return "stnt1h";
        case Mnemonic::STNT1W: return "stnt1w";
        case Mnemonic::STP: return "stp";
        case Mnemonic::STR: return "str";
        case Mnemonic::STRB: return "strb";
        case Mnemonic::STRH: return "strh";
        case Mnemonic::STSHH: return "stshh";
        case Mnemonic::STTNP: return "sttnp";
        case Mnemonic::STTP: return "sttp";
        case Mnemonic::STTR: return "sttr";
        case Mnemonic::STTRB: return "sttrb";
        case Mnemonic::STTRH: return "sttrh";
        case Mnemonic::STTXR: return "sttxr";
        case Mnemonic::STUR: return "stur";
        case Mnemonic::STURB: return "sturb";
        case Mnemonic::STURH: return "sturh";
        case Mnemonic::STXP: return "stxp";
        case Mnemonic::STXR: return "stxr";
        case Mnemonic::STXRB: return "stxrb";
        case Mnemonic::STXRH: return "stxrh";
        case Mnemonic::STZ2G: return "stz2g";
        case Mnemonic::STZG: return "stzg";
        case Mnemonic::STZGM: return "stzgm";
        case Mnemonic::SUB: return "sub";
        case Mnemonic::SUBG: return "subg";
        case Mnemonic::SUBHN: return "subhn";
        case Mnemonic::SUBHNB: return "subhnb";
        case Mnemonic::SUBHNT: return "subhnt";
        case Mnemonic::SUBP: return "subp";
        case Mnemonic::SUBPS: return "subps";
        case Mnemonic::SUBPT: return "subpt";
        case Mnemonic::SUBR: return "subr";
        case Mnemonic::SUBS: return "subs";
        case Mnemonic::SUDOT: return "sudot";
        case Mnemonic::SUMLALL: return "sumlall";
        case Mnemonic::SUMOP4A: return "sumop4a";
        case Mnemonic::SUMOP4S: return "sumop4s";
        case Mnemonic::SUMOPA: return "sumopa";
        case Mnemonic::SUMOPS: return "sumops";
        case Mnemonic::SUNPK: return "sunpk";
        case Mnemonic::SUNPKHI: return "sunpkhi";
        case Mnemonic::SUNPKLO: return "sunpklo";
        case Mnemonic::SUQADD: return "suqadd";
        case Mnemonic::SUTMOPA: return "sutmopa";
        case Mnemonic::SUVDOT: return "suvdot";
        case Mnemonic::SVC: return "svc";
        case Mnemonic::SVDOT: return "svdot";
        case Mnemonic::SWP: return "swp";
        case Mnemonic::SWPA: return "swpa";
        case Mnemonic::SWPAB: return "swpab";
        case Mnemonic::SWPAH: return "swpah";
        case Mnemonic::SWPAL: return "swpal";
        case Mnemonic::SWPALB: return "swpalb";
        case Mnemonic::SWPALH: return "swpalh";
        case Mnemonic::SWPB: return "swpb";
        case Mnemonic::SWPH: return "swph";
        case Mnemonic::SWPL: return "swpl";
        case Mnemonic::SWPLB: return "swplb";
        case Mnemonic::SWPLH: return "swplh";
        case Mnemonic::SWPP: return "swpp";
        case Mnemonic::SWPPA: return "swppa";
        case Mnemonic::SWPPAL: return "swppal";
        case Mnemonic::SWPPL: return "swppl";
        case Mnemonic::SWPT: return "swpt";
        case Mnemonic::SWPTA: return "swpta";
        case Mnemonic::SWPTAL: return "swptal";
        case Mnemonic::SWPTL: return "swptl";
        case Mnemonic::SXTB: return "sxtb";
        case Mnemonic::SXTH: return "sxth";
        case Mnemonic::SXTL: return "sxtl";
        case Mnemonic::SXTW: return "sxtw";
        case Mnemonic::SYS: return "sys";
        case Mnemonic::SYSL: return "sysl";
        case Mnemonic::SYSP: return "sysp";
        case Mnemonic::TBL: return "tbl";
        case Mnemonic::TBLQ: return "tblq";
        case Mnemonic::TBNZ: return "tbnz";
        case Mnemonic::TBX: return "tbx";
        case Mnemonic::TBXQ: return "tbxq";
        case Mnemonic::TBZ: return "tbz";
        case Mnemonic::TLBI: return "tlbi";
        case Mnemonic::TLBIP: return "tlbip";
        case Mnemonic::TRCIT: return "trcit";
        case Mnemonic::TRN1: return "trn1";
        case Mnemonic::TRN2: return "trn2";
        case Mnemonic::TSB: return "tsb";
        case Mnemonic::TST: return "tst";
        case Mnemonic::UABA: return "uaba";
        case Mnemonic::UABAL: return "uabal";
        case Mnemonic::UABALB: return "uabalb";
        case Mnemonic::UABALT: return "uabalt";
        case Mnemonic::UABD: return "uabd";
        case Mnemonic::UABDL: return "uabdl";
        case Mnemonic::UABDLB: return "uabdlb";
        case Mnemonic::UABDLT: return "uabdlt";
        case Mnemonic::UADALP: return "uadalp";
        case Mnemonic::UADDL: return "uaddl";
        case Mnemonic::UADDLB: return "uaddlb";
        case Mnemonic::UADDLP: return "uaddlp";
        case Mnemonic::UADDLT: return "uaddlt";
        case Mnemonic::UADDLV: return "uaddlv";
        case Mnemonic::UADDV: return "uaddv";
        case Mnemonic::UADDW: return "uaddw";
        case Mnemonic::UADDWB: return "uaddwb";
        case Mnemonic::UADDWT: return "uaddwt";
        case Mnemonic::UBFM: return "ubfm";
        case Mnemonic::UCLAMP: return "uclamp";
        case Mnemonic::UCVTF: return "ucvtf";
        case Mnemonic::UCVTFLT: return "ucvtflt";
        case Mnemonic::UDF: return "udf";
        case Mnemonic::UDIV: return "udiv";
        case Mnemonic::UDIVR: return "udivr";
        case Mnemonic::UDOT: return "udot";
        case Mnemonic::UHADD: return "uhadd";
        case Mnemonic::UHSUB: return "uhsub";
        case Mnemonic::UHSUBR: return "uhsubr";
        case Mnemonic::UMADDL: return "umaddl";
        case Mnemonic::UMAX: return "umax";
        case Mnemonic::UMAXP: return "umaxp";
        case Mnemonic::UMAXQV: return "umaxqv";
        case Mnemonic::UMAXV: return "umaxv";
        case Mnemonic::UMIN: return "umin";
        case Mnemonic::UMINP: return "uminp";
        case Mnemonic::UMINQV: return "uminqv";
        case Mnemonic::UMINV: return "uminv";
        case Mnemonic::UMLAL: return "umlal";
        case Mnemonic::UMLALB: return "umlalb";
        case Mnemonic::UMLALL: return "umlall";
        case Mnemonic::UMLALT: return "umlalt";
        case Mnemonic::UMLSL: return "umlsl";
        case Mnemonic::UMLSLB: return "umlslb";
        case Mnemonic::UMLSLL: return "umlsll";
        case Mnemonic::UMLSLT: return "umlslt";
        case Mnemonic::UMMLA: return "ummla";
        case Mnemonic::UMNEGL: return "umnegl";
        case Mnemonic::UMOP4A: return "umop4a";
        case Mnemonic::UMOP4S: return "umop4s";
        case Mnemonic::UMOPA: return "umopa";
        case Mnemonic::UMOPS: return "umops";
        case Mnemonic::UMOV: return "umov";
        case Mnemonic::UMSUBL: return "umsubl";
        case Mnemonic::UMULH: return "umulh";
        case Mnemonic::UMULL: return "umull";
        case Mnemonic::UMULLB: return "umullb";
        case Mnemonic::UMULLT: return "umullt";
        case Mnemonic::UQADD: return "uqadd";
        case Mnemonic::UQCVT: return "uqcvt";
        case Mnemonic::UQCVTN: return "uqcvtn";
        case Mnemonic::UQDECB: return "uqdecb";
        case Mnemonic::UQDECD: return "uqdecd";
        case Mnemonic::UQDECH: return "uqdech";
        case Mnemonic::UQDECP: return "uqdecp";
        case Mnemonic::UQDECW: return "uqdecw";
        case Mnemonic::UQINCB: return "uqincb";
        case Mnemonic::UQINCD: return "uqincd";
        case Mnemonic::UQINCH: return "uqinch";
        case Mnemonic::UQINCP: return "uqincp";
        case Mnemonic::UQINCW: return "uqincw";
        case Mnemonic::UQRSHL: return "uqrshl";
        case Mnemonic::UQRSHLR: return "uqrshlr";
        case Mnemonic::UQRSHR: return "uqrshr";
        case Mnemonic::UQRSHRN: return "uqrshrn";
        case Mnemonic::UQRSHRNB: return "uqrshrnb";
        case Mnemonic::UQRSHRNT: return "uqrshrnt";
        case Mnemonic::UQSHL: return "uqshl";
        case Mnemonic::UQSHLR: return "uqshlr";
        case Mnemonic::UQSHRN: return "uqshrn";
        case Mnemonic::UQSHRNB: return "uqshrnb";
        case Mnemonic::UQSHRNT: return "uqshrnt";
        case Mnemonic::UQSUB: return "uqsub";
        case Mnemonic::UQSUBR: return "uqsubr";
        case Mnemonic::UQXTN: return "uqxtn";
        case Mnemonic::UQXTNB: return "uqxtnb";
        case Mnemonic::UQXTNT: return "uqxtnt";
        case Mnemonic::URECPE: return "urecpe";
        case Mnemonic::URHADD: return "urhadd";
        case Mnemonic::URSHL: return "urshl";
        case Mnemonic::URSHLR: return "urshlr";
        case Mnemonic::URSHR: return "urshr";
        case Mnemonic::URSQRTE: return "ursqrte";
        case Mnemonic::URSRA: return "ursra";
        case Mnemonic::USDOT: return "usdot";
        case Mnemonic::USHL: return "ushl";
        case Mnemonic::USHLL: return "ushll";
        case Mnemonic::USHLLB: return "ushllb";
        case Mnemonic::USHLLT: return "ushllt";
        case Mnemonic::USHR: return "ushr";
        case Mnemonic::USMLALL: return "usmlall";
        case Mnemonic::USMMLA: return "usmmla";
        case Mnemonic::USMOP4A: return "usmop4a";
        case Mnemonic::USMOP4S: return "usmop4s";
        case Mnemonic::USMOPA: return "usmopa";
        case Mnemonic::USMOPS: return "usmops";
        case Mnemonic::USQADD: return "usqadd";
        case Mnemonic::USRA: return "usra";
        case Mnemonic::USTMOPA: return "ustmopa";
        case Mnemonic::USUBL: return "usubl";
        case Mnemonic::USUBLB: return "usublb";
        case Mnemonic::USUBLT: return "usublt";
        case Mnemonic::USUBW: return "usubw";
        case Mnemonic::USUBWB: return "usubwb";
        case Mnemonic::USUBWT: return "usubwt";
        case Mnemonic::USVDOT: return "usvdot";
        case Mnemonic::UTMOPA: return "utmopa";
        case Mnemonic::UUNPK: return "uunpk";
        case Mnemonic::UUNPKHI: return "uunpkhi";
        case Mnemonic::UUNPKLO: return "uunpklo";
        case Mnemonic::UVDOT: return "uvdot";
        case Mnemonic::UXTB: return "uxtb";
        case Mnemonic::UXTH: return "uxth";
        case Mnemonic::UXTL: return "uxtl";
        case Mnemonic::UXTW: return "uxtw";
        case Mnemonic::UZP: return "uzp";
        case Mnemonic::UZP1: return "uzp1";
        case Mnemonic::UZP2: return "uzp2";
        case Mnemonic::UZPQ1: return "uzpq1";
        case Mnemonic::UZPQ2: return "uzpq2";
        case Mnemonic::WFE: return "wfe";
        case Mnemonic::WFET: return "wfet";
        case Mnemonic::WFI: return "wfi";
        case Mnemonic::WFIT: return "wfit";
        case Mnemonic::WHILEGE: return "whilege";
        case Mnemonic::WHILEGT: return "whilegt";
        case Mnemonic::WHILEHI: return "whilehi";
        case Mnemonic::WHILEHS: return "whilehs";
        case Mnemonic::WHILELE: return "whilele";
        case Mnemonic::WHILELO: return "whilelo";
        case Mnemonic::WHILELS: return "whilels";
        case Mnemonic::WHILELT: return "whilelt";
        case Mnemonic::WHILERW: return "whilerw";
        case Mnemonic::WHILEWR: return "whilewr";
        case Mnemonic::WRFFR: return "wrffr";
        case Mnemonic::XAFLAG: return "xaflag";
        case Mnemonic::XAR: return "xar";
        case Mnemonic::XPACD: return "xpacd";
        case Mnemonic::XPACI: return "xpaci";
        case Mnemonic::XPACLRI: return "xpaclri";
        case Mnemonic::XTN: return "xtn";
        case Mnemonic::YIELD: return "yield";
        case Mnemonic::ZERO: return "zero";
        case Mnemonic::ZIP: return "zip";
        case Mnemonic::ZIP1: return "zip1";
        case Mnemonic::ZIP2: return "zip2";
        case Mnemonic::ZIPQ1: return "zipq1";
        case Mnemonic::ZIPQ2: return "zipq2";
        case Mnemonic::UNKNOWN: return "<unknown>";
        default: return "<invalid>";
    }
}

#ifdef VEDA64_STRINGS
// SYS alias operation name string table (used by Operand::to_string)
static const char* sys_ops[] = {"vmalle1os", "vae1os", "aside1os", "vaae1os", "vale1os", "vaale1os", "rvae1is", "rvaae1is", "rvale1is", "rvaale1is", "vmalle1is", "vae1is", "aside1is", "vaae1is", "vale1is", "vaale1is", "rvae1os", "rvaae1os", "rvale1os", "rvaale1os", "rvae1", "rvaae1", "rvale1", "rvaale1", "vmalle1", "vae1", "aside1", "vaae1", "vale1", "vaale1", "vmalle1osnxs", "vae1osnxs", "aside1osnxs", "vaae1osnxs", "vale1osnxs", "vaale1osnxs", "rvae1isnxs", "rvaae1isnxs", "rvale1isnxs", "rvaale1isnxs", "vmalle1isnxs", "vae1isnxs", "aside1isnxs", "vaae1isnxs", "vale1isnxs", "vaale1isnxs", "rvae1osnxs", "rvaae1osnxs", "rvale1osnxs", "rvaale1osnxs", "rvae1nxs", "rvaae1nxs", "rvale1nxs", "rvaale1nxs", "vmalle1nxs", "vae1nxs", "aside1nxs", "vaae1nxs", "vale1nxs", "vaale1nxs", "ipas2e1is", "ripas2e1is", "ipas2le1is", "ripas2le1is", "alle2os", "vae2os", "alle1os", "vale2os", "vmalls12e1os", "rvae2is", "vmallws2e1is", "rvale2is", "alle2is", "vae2is", "alle1is", "vale2is", "vmalls12e1is", "ipas2e1os", "ipas2e1", "ripas2e1", "ripas2e1os", "ipas2le1os", "ipas2le1", "ripas2le1", "ripas2le1os", "rvae2os", "vmallws2e1os", "rvale2os", "rvae2", "vmallws2e1", "rvale2", "alle2", "vae2", "alle1", "vale2", "vmalls12e1", "ipas2e1isnxs", "ripas2e1isnxs", "ipas2le1isnxs", "ripas2le1isnxs", "alle2osnxs", "vae2osnxs", "alle1osnxs", "vale2osnxs", "vmalls12e1osnxs", "rvae2isnxs", "vmallws2e1isnxs", "rvale2isnxs", "alle2isnxs", "vae2isnxs", "alle1isnxs", "vale2isnxs", "vmalls12e1isnxs", "ipas2e1osnxs", "ipas2e1nxs", "ripas2e1nxs", "ripas2e1osnxs", "ipas2le1osnxs", "ipas2le1nxs", "ripas2le1nxs", "ripas2le1osnxs", "rvae2osnxs", "vmallws2e1osnxs", "rvale2osnxs", "rvae2nxs", "vmallws2e1nxs", "rvale2nxs", "alle2nxs", "vae2nxs", "alle1nxs", "vale2nxs", "vmalls12e1nxs", "alle3os", "vae3os", "paallos", "vale3os", "rvae3is", "rvale3is", "alle3is", "vae3is", "vale3is", "rpaos", "rpalos", "rvae3os", "rvale3os", "rvae3", "rvale3", "alle3", "vae3", "paall", "vale3", "alle3osnxs", "vae3osnxs", "vale3osnxs", "rvae3isnxs", "rvale3isnxs", "alle3isnxs", "vae3isnxs", "vale3isnxs", "rvae3osnxs", "rvale3osnxs", "rvae3nxs", "rvale3nxs", "alle3nxs", "vae3nxs", "vale3nxs", "ivac", "isw", "igvac", "igsw", "igdvac", "igdsw", "csw", "cgsw", "cgdsw", "cisw", "cigsw", "cigdsw", "civaps", "cigdvaps", "zva", "gva", "gzva", "zgbva", "gbva", "cvac", "cgvac", "cgdvac", "cvaoc", "cvau", "cgdvaoc", "cvap", "cgvap", "cgdvap", "cvadp", "cgvadp", "cgdvadp", "civac", "cigvac", "cigdvac", "civaoc", "cigdvaoc", "cipae", "cigdpae", "cipapa", "cigdpapa", "s1e1r", "s1e1w", "s1e0r", "s1e0w", "s1e1rp", "s1e1wp", "s1e1a", "s1e2r", "s1e2w", "s12e1r", "s12e1w", "s12e0r", "s12e0w", "s1e2a", "s1e3r", "s1e3w", "s1e3a", "ialluis", "iallu", "ivau", "cddis", "cden", "cdpri", "cdaff", "cdpend", "cdrcfg", "cdeoi", "cddi", "cdhm", "vddis", "vden", "vdpri", "vdaff", "vdpend", "vdrcfg", "vddi", "vdhm", "lddis", "lden", "ldpri", "ldaff", "ldpend", "ldrcfg", "lddi", "ldhm", "iall", "inj", "rctx", "s2poc"};
#endif // VEDA64_STRINGS

// Format a general purpose register
std::string Operand::format_register(uint32_t reg, bool is_64bit, bool is_sp) {
    if (reg == 31) {
        if (is_sp) {
            return is_64bit ? "sp" : "wsp";
        } else {
            return is_64bit ? "xzr" : "wzr";
        }
    }
    // Note: x29/x30 shown as x29/x30, not fp/lr (ARM disassembly convention)
    char prefix = is_64bit ? 'x' : 'w';
    return std::string(1, prefix) + std::to_string(reg);
}

// Format a vector register
std::string Operand::format_vector_register(uint32_t reg, Arrangement arrangement) {
    // Scalar prefixes: B→b, H→h, S→s, D→d, Q→q
    if (arrangement >= Arrangement::B && arrangement <= Arrangement::Q) {
        const char prefix[] = {0, 'b', 'h', 's', 'd', 'q'};
        return std::string(1, prefix[static_cast<int>(arrangement)]) + std::to_string(reg);
    }
    std::string result = "v" + std::to_string(reg);
    if (arrangement != Arrangement::None) {
        result += ".";
        result += arrangement_to_string(arrangement);
    }
    return result;
}

Arrangement Operand::arr_from_size(uint32_t size) {
    static const Arrangement table[] = { Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D };
    return size < 4 ? table[size] : Arrangement::None;
}

Arrangement Operand::arr_narrow_from_size(uint32_t size) {
    static const Arrangement table[] = { Arrangement::None, Arrangement::B, Arrangement::H, Arrangement::S };
    return size < 4 ? table[size] : Arrangement::None;
}

Arrangement Operand::arr_wide_from_size(uint32_t size) {
    static const Arrangement table[] = { Arrangement::H, Arrangement::S, Arrangement::D };
    return size < 3 ? table[size] : Arrangement::None;
}

Arrangement Operand::vec_arr(uint32_t size, uint32_t q) {
    static const Arrangement table[2][4] = {
        { Arrangement::B8, Arrangement::H4, Arrangement::S2, Arrangement::D1 },
        { Arrangement::B16, Arrangement::H8, Arrangement::S4, Arrangement::D2 }
    };
    return (size < 4 && q < 2) ? table[q][size] : Arrangement::None;
}

// arrangement_to_string is now a free inline function in types.hpp

#endif // VEDA64_STRINGS

#ifdef VEDA64_STRINGS
const char* condition_to_string(Condition cond) {
    static const char* names[] = {"eq", "ne", "hs", "lo", "mi", "pl", "vs", "vc",
                                   "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"};
    auto idx = static_cast<int8_t>(cond);
    if (idx >= 0 && idx < 16) return names[idx];
    return nullptr;
}

// Helper: check if OperandType is a register type (Register or IndexedRegister)
inline bool is_register_type(OperandType t) { return t == OperandType::Register || t == OperandType::IndexedRegister; }

// Synthesize pseudo-instruction aliases
std::optional<std::string> synthesize_alias(const Instruction& insn) {
    // Helper: check if operand value is SP or WSP Register enum
    auto is_sp_reg = [](uint32_t v) { return v == static_cast<uint32_t>(Register::SP) || v == static_cast<uint32_t>(Register::WSP); };
    auto reg_num = [](uint32_t v) { return v > 31 ? register_num(static_cast<Register>(v)) : v; };

    // MOV Aliases: ADD/ORR with sp or Rn==Rm pattern
    if (insn.mnemonic == Mnemonic::ADD) {
        // MOV: 2-operand form (alias decoder emitted Rd, Rn with imm=0 implied)
        // Alias condition: Rd or Rn is SP
        if (insn.operands.size() == 2) {
            auto& op0 = insn.operands[0]; auto& op1 = insn.operands[1];
            if (op0.type == OperandType::Register && op1.type == OperandType::Register) {
                if (is_sp_reg(op0.reg_val()) || is_sp_reg(op1.reg_val())) {
                    return std::string("mov ") + op0.to_string() + ", " + op1.to_string();
                } else {
                    std::string r0 = op0.to_string(), r1 = op1.to_string();
                    return std::string("add ") + r0 + ", " + r1 + ", #0";
                }
            }
        }
        if (insn.operands.size() >= 3) {
        auto& op0 = insn.operands[0];
        auto& op1 = insn.operands[1];
        auto& op2 = insn.operands[2];
        if ((is_sp_reg(op0.reg_val()) || is_sp_reg(op1.reg_val())) &&
            op2.type == OperandType::Immediate && op2.iv.value == 0) {
            return std::string("mov ") + op0.to_string() + ", " + op1.to_string();
        }
        }
    }

    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() >= 2) {
        // MOV Rd, Rm = ORR Rd, XZR/WZR, Rm (no shift)
        if (insn.operands.size() == 2 && insn.operands[1].type == OperandType::Register) {
            // 2-operand form: MOV alias encoding (Rn=XZR is implicit)
            return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string();
        }
        if (insn.operands.size() >= 3 && reg_num(insn.operands[1].reg_val()) == 31 && insn.operands[1].type == OperandType::Register) {
            bool no_shift = insn.operands.size() < 4 || insn.operands[3].type != OperandType::Shift || (insn.operands[3].sh.shift_type == ShiftType::LSL && insn.operands[3].sh.amount == 0);
            if (no_shift) {
                return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[2].to_string();
            }
        }
    }

    // MOVZ/MOVN/MOVK with or without shifts -> MOV/MVN alias
    if (insn.mnemonic == Mnemonic::MOVZ && insn.operands.size() >= 2) {
        // hw = bits 22:21 of raw instruction; shift_amt = hw * 16
        uint32_t hw_val = (insn.raw_value >> 21) & 0x3;
        uint64_t imm_val = insn.operands[1].iv.value;
        bool is_64z = register_is_64bit(static_cast<Register>(insn.operands[0].reg_val()));
        uint64_t final_val = imm_val << (hw_val * 16);
        std::ostringstream oss;
        oss << "mov " << insn.operands[0].to_string() << ", #";
        if (!is_64z && final_val >= 0x80000000ULL)
            oss << "-0x" << std::hex << (0x100000000ULL - final_val);
        else if (is_64z && final_val >= 0x8000000000000000ULL)
            oss << "-0x" << std::hex << (0ULL - final_val);
        else
            oss << "0x" << std::hex << final_val;
        return oss.str();
    }

    if (insn.mnemonic == Mnemonic::MOVN && insn.operands.size() >= 2) {
        // hw = bits 22:21 of raw instruction; shift_amt = hw * 16
        uint32_t hw_val = (insn.raw_value >> 21) & 0x3;
        uint64_t imm_val = insn.operands[1].iv.value;
        bool is_64n = register_is_64bit(static_cast<Register>(insn.operands[0].reg_val()));
        uint64_t final_val = ~(imm_val << (hw_val * 16));
        if (!is_64n) final_val &= 0xFFFFFFFFULL;
        std::ostringstream oss;
        oss << "mov " << insn.operands[0].to_string() << ", #";
        if (!is_64n && final_val >= 0x80000000ULL)
            oss << "-0x" << std::hex << (0x100000000ULL - final_val);
        else if (is_64n && final_val >= 0x8000000000000000ULL)
            oss << "-0x" << std::hex << (0ULL - final_val);
        else
            oss << "0x" << std::hex << final_val;
        return oss.str();
    }

    // CMP/CMN/TST aliases: Rd (bits [4:0]) == 31 (XZR)
    // Use raw bits to detect - alias encodings may omit Rd from operands
    if (insn.mnemonic == Mnemonic::SUBS && (insn.raw_value & 0x1F) == 0x1F) {
        // CMP alias: skip Rd if present in operands
        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && reg_num(insn.operands[0].reg_val()) == 31) ? 1 : 0;
        std::string result = "cmp";
        for (size_t i = start; i < insn.operands.size(); ++i) {
            result += (i == start ? " " : ", ") + insn.operands[i].to_string();
        }
        return result;
    }

    if (insn.mnemonic == Mnemonic::ADDS && (insn.raw_value & 0x1F) == 0x1F) {
        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && reg_num(insn.operands[0].reg_val()) == 31) ? 1 : 0;
        std::string result = "cmn";
        for (size_t i = start; i < insn.operands.size(); ++i) {
            result += (i == start ? " " : ", ") + insn.operands[i].to_string();
        }
        return result;
    }

    if (insn.mnemonic == Mnemonic::ANDS && (insn.raw_value & 0x1F) == 0x1F) {
        size_t start = (insn.operands.size() >= 3 && insn.operands[0].type == OperandType::Register && reg_num(insn.operands[0].reg_val()) == 31) ? 1 : 0;
        std::string result = "tst";
        for (size_t i = start; i < insn.operands.size(); ++i) {
            result += (i == start ? " " : ", ") + insn.operands[i].to_string();
        }
        return result;
    }

    // NEG Aliases: SUB/SUBS with Rn (bits [9:5]) == 31 (shifted register form only)
    // Shifted register: bit 28=0 (register form), bit 21=0 (not extended)
    // Extended register: bit 21=1, Rn=31 means SP not XZR — NOT a NEG
    if (insn.mnemonic == Mnemonic::SUB && ((insn.raw_value >> 5) & 0x1F) == 0x1F) {
        if ((insn.raw_value & (1u << 28)) == 0 && (insn.raw_value & (1u << 21)) == 0) {
            // Emit Rd, Rm (skip Rn which is xzr)
            size_t rd_idx = 0;
            size_t rm_idx = (insn.operands.size() >= 3 && insn.operands[1].type == OperandType::Register && reg_num(insn.operands[1].reg_val()) == 31) ? 2 : 1;
            std::string result = "neg " + insn.operands[rd_idx].to_string();
            for (size_t i = rm_idx; i < insn.operands.size(); ++i) {
                result += ", " + insn.operands[i].to_string();
            }
            return result;
        }
    }

    if (insn.mnemonic == Mnemonic::SUBS && ((insn.raw_value >> 5) & 0x1F) == 0x1F && (insn.raw_value & 0x1F) != 0x1F) {
        if ((insn.raw_value & (1u << 28)) == 0 && (insn.raw_value & (1u << 21)) == 0) {
            size_t rd_idx = 0;
            size_t rm_idx = (insn.operands.size() >= 3 && insn.operands[1].type == OperandType::Register && reg_num(insn.operands[1].reg_val()) == 31) ? 2 : 1;
            std::string result = "negs " + insn.operands[rd_idx].to_string();
            for (size_t i = rm_idx; i < insn.operands.size(); ++i) {
                result += ", " + insn.operands[i].to_string();
            }
            return result;
        }
    }

    // MUL Aliases: MADD/MSUB with Ra==31 (4 operands) or alias encoding (3 operands)
    if (insn.mnemonic == Mnemonic::MADD) {
        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && reg_num(insn.operands[3].reg_val()) == 31)) {
            return std::string("mul ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    if (insn.mnemonic == Mnemonic::MSUB) {
        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && reg_num(insn.operands[3].reg_val()) == 31)) {
            return std::string("mneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    // SMULL/UMULL/SMNEGL/UMNEGL Aliases
    if (insn.mnemonic == Mnemonic::SMADDL) {
        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && reg_num(insn.operands[3].reg_val()) == 31)) {
            return std::string("smull ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }
    if (insn.mnemonic == Mnemonic::UMADDL) {
        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && reg_num(insn.operands[3].reg_val()) == 31)) {
            return std::string("umull ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }
    if (insn.mnemonic == Mnemonic::SMSUBL) {
        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && reg_num(insn.operands[3].reg_val()) == 31)) {
            return std::string("smnegl ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }
    if (insn.mnemonic == Mnemonic::UMSUBL) {
        if (insn.operands.size() == 3 || (insn.operands.size() >= 4 && reg_num(insn.operands[3].reg_val()) == 31)) {
            return std::string("umnegl ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    // ROR Aliases: EXTR with Rn==Rm (ROR is EXTR with both operands same)
    if (insn.mnemonic == Mnemonic::EXTR && insn.operands.size() >= 4) {
        if (insn.operands[1].reg_val() == insn.operands[2].reg_val()) {
            return std::string("ror ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[3].to_string();
        }
    }

    // RORV -> ROR alias (variable rotate is just called ROR in disassembly)
    if (insn.mnemonic == Mnemonic::RORV && insn.operands.size() >= 3) {
        return std::string("ror ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
    }

    // LSLV/LSRV/ASRV -> LSL/LSR/ASR aliases (variable shift is just called LSL/LSR/ASR)
    if (insn.mnemonic == Mnemonic::LSLV && insn.operands.size() >= 3) {
        return std::string("lsl ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
    }
    if (insn.mnemonic == Mnemonic::LSRV && insn.operands.size() >= 3) {
        return std::string("lsr ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
    }
    if (insn.mnemonic == Mnemonic::ASRV && insn.operands.size() >= 3) {
        return std::string("asr ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
    }

    // UBFM/SBFM/BFM aliases: Extract immr/imms from raw bits since specific
    // alias encodings (LSR_UBFM, ASR_SBFM etc.) have imms as fixed field
    if (insn.mnemonic == Mnemonic::UBFM && insn.operands.size() >= 2) {
        uint32_t immr = (insn.raw_value >> 16) & 0x3F;
        uint32_t imms = (insn.raw_value >> 10) & 0x3F;
        bool is_64 = register_is_64bit(static_cast<Register>(insn.operands[0].reg_val()));
        uint32_t regsize = is_64 ? 64 : 32;
        auto& rd = insn.operands[0];
        auto& rn = insn.operands[1];
        if (!is_64 && immr == 0 && imms == 7) {
            return std::string("uxtb ") + rd.to_string() + ", " + rn.to_string();
        }
        if (!is_64 && immr == 0 && imms == 15) {
            return std::string("uxth ") + rd.to_string() + ", " + rn.to_string();
        }
        if (imms == regsize - 1) {
            return std::string("lsr ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr);
        }
        if (imms + 1 == immr) {
            uint32_t shift = regsize - immr;
            return std::string("lsl ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(shift);
        }
        if (imms >= immr) {
            uint32_t width = imms - immr + 1;
            return std::string("ubfx ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr) + ", #" + std::to_string(width);
        }
    }

    if (insn.mnemonic == Mnemonic::SBFM && insn.operands.size() >= 2) {
        uint32_t immr = (insn.raw_value >> 16) & 0x3F;
        uint32_t imms = (insn.raw_value >> 10) & 0x3F;
        bool is_64 = register_is_64bit(static_cast<Register>(insn.operands[0].reg_val()));
        uint32_t regsize = is_64 ? 64 : 32;
        auto& rd = insn.operands[0];
        auto& rn = insn.operands[1];
        // SXT aliases: source register is always W-form (sign-extending from smaller type)
        std::string rn_w = register_to_string(make_gp_reg(reg_num(rn.reg_val()), false));
        if (immr == 0 && imms == 7) {
            return std::string("sxtb ") + rd.to_string() + ", " + rn_w;
        }
        if (immr == 0 && imms == 15) {
            return std::string("sxth ") + rd.to_string() + ", " + rn_w;
        }
        if (is_64 && immr == 0 && imms == 31) {
            return std::string("sxtw ") + rd.to_string() + ", " + rn_w;
        }
        if (imms == regsize - 1) {
            return std::string("asr ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr);
        }
        if (imms >= immr) {
            uint32_t width = imms - immr + 1;
            return std::string("sbfx ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr) + ", #" + std::to_string(width);
        }
    }

    if (insn.mnemonic == Mnemonic::BFM && insn.operands.size() >= 2) {
        uint32_t immr = (insn.raw_value >> 16) & 0x3F;
        uint32_t imms = (insn.raw_value >> 10) & 0x3F;
        bool is_64 = register_is_64bit(static_cast<Register>(insn.operands[0].reg_val()));
        uint32_t regsize = is_64 ? 64 : 32;
        auto& rd = insn.operands[0];
        auto& rn = insn.operands[1];
        if (imms < immr) {
            uint32_t lsb = (regsize - immr) & (regsize - 1);
            uint32_t width = imms + 1;
            return std::string("bfi ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(lsb) + ", #" + std::to_string(width);
        } else {
            uint32_t width = imms - immr + 1;
            return std::string("bfxil ") + rd.to_string() + ", " + rn.to_string() + ", #" + std::to_string(immr) + ", #" + std::to_string(width);
        }
    }

    // CSINC aliases: CSET (Rn=Rm=31), CINC (Rn==Rm)
    if (insn.mnemonic == Mnemonic::CSINC && insn.condition != Condition::None) {
        int cond_val = static_cast<int>(insn.condition);
        if ((cond_val & 0xE) != 0xE) {  // Not AL/NV
            const char* inv_cond = condition_to_string(static_cast<Condition>(cond_val ^ 1));
            // CSET: Rn=Rm=31 implied (1-operand form from alias-specific decoder)
            if (insn.operands.size() == 1) {
                return std::string("cset ") + insn.operands[0].to_string() + ", " + inv_cond;
            }
            // 2-operand form: Rm from raw instruction, check Rn==Rm for CINC
            if (insn.operands.size() == 2) {
                uint32_t raw_rn = (insn.raw_value >> 5) & 0x1F;
                uint32_t raw_rm = (insn.raw_value >> 16) & 0x1F;
                bool is_64 = register_is_64bit(static_cast<Register>(insn.operands[1].reg_val()));
                if (raw_rn == raw_rm) {
                    return std::string("cinc ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + inv_cond;
                } else {
                    // Rn!=Rm: full CSINC form, reconstruct Rm operand from raw
                    Operand rm_op = Operand::gp(raw_rm, is_64);
                    return std::string("csinc ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + rm_op.to_string() + ", " + condition_to_string(insn.condition);
                }
            }
            if (insn.operands.size() >= 3) {
                auto& rn = insn.operands[1];
                auto& rm = insn.operands[2];
                if (reg_num(rn.reg_val()) == 31 && reg_num(rm.reg_val()) == 31) {
                    return std::string("cset ") + insn.operands[0].to_string() + ", " + inv_cond;
                }
                if (rn.reg_val() == rm.reg_val()) {
                    return std::string("cinc ") + insn.operands[0].to_string() + ", " + rn.to_string() + ", " + inv_cond;
                }
            }
        }
    }

    // CSINV aliases: CSETM (Rn=Rm=31), CINV (Rn==Rm)
    if (insn.mnemonic == Mnemonic::CSINV && insn.condition != Condition::None) {
        int cond_val = static_cast<int>(insn.condition);
        if ((cond_val & 0xE) != 0xE) {  // Not AL/NV
            const char* inv_cond = condition_to_string(static_cast<Condition>(cond_val ^ 1));
            // CSETM: Rn=Rm=31 implied (1-operand form from alias-specific decoder)
            if (insn.operands.size() == 1) {
                return std::string("csetm ") + insn.operands[0].to_string() + ", " + inv_cond;
            }
            // 2-operand form: check Rn==Rm from raw for CINV
            if (insn.operands.size() == 2) {
                uint32_t raw_rn = (insn.raw_value >> 5) & 0x1F;
                uint32_t raw_rm = (insn.raw_value >> 16) & 0x1F;
                bool is_64 = register_is_64bit(static_cast<Register>(insn.operands[1].reg_val()));
                if (raw_rn == raw_rm) {
                    return std::string("cinv ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + inv_cond;
                } else {
                    Operand rm_op = Operand::gp(raw_rm, is_64);
                    return std::string("csinv ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + rm_op.to_string() + ", " + condition_to_string(insn.condition);
                }
            }
            if (insn.operands.size() >= 3) {
                auto& rn = insn.operands[1];
                auto& rm = insn.operands[2];
                if (reg_num(rn.reg_val()) == 31 && reg_num(rm.reg_val()) == 31) {
                    return std::string("csetm ") + insn.operands[0].to_string() + ", " + inv_cond;
                }
                if (rn.reg_val() == rm.reg_val()) {
                    return std::string("cinv ") + insn.operands[0].to_string() + ", " + rn.to_string() + ", " + inv_cond;
                }
            }
        }
    }

    // CSNEG alias: CNEG (Rn==Rm)
    if (insn.mnemonic == Mnemonic::CSNEG && insn.condition != Condition::None) {
        int cond_val = static_cast<int>(insn.condition);
        if ((cond_val & 0xE) != 0xE) {  // Not AL/NV
            const char* inv_cond = condition_to_string(static_cast<Condition>(cond_val ^ 1));
            // 2-operand form: check Rn==Rm from raw for CNEG
            if (insn.operands.size() == 2) {
                uint32_t raw_rn = (insn.raw_value >> 5) & 0x1F;
                uint32_t raw_rm = (insn.raw_value >> 16) & 0x1F;
                bool is_64 = register_is_64bit(static_cast<Register>(insn.operands[1].reg_val()));
                if (raw_rn == raw_rm) {
                    return std::string("cneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + inv_cond;
                } else {
                    Operand rm_op = Operand::gp(raw_rm, is_64);
                    return std::string("csneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + rm_op.to_string() + ", " + condition_to_string(insn.condition);
                }
            }
            if (insn.operands.size() >= 3) {
            auto& rn = insn.operands[1];
            auto& rm = insn.operands[2];
            if (rn.reg_val() == rm.reg_val()) {
                return std::string("cneg ") + insn.operands[0].to_string() + ", " + rn.to_string() + ", " + inv_cond;
            }
            }
        }
    }

    // MOVA → MOV: ZA tile slice operand format
    if (insn.mnemonic == Mnemonic::MOVA) {
        uint32_t raw = insn.raw_value;
        // Detect mov_za_p_rz variants (vector to/from ZA tile with predicate)
        // These have top byte 0xC0 and bit 20=0, bits [19:16]=0
        if ((raw & 0xFF200000u) == 0xC0000000u && ((raw >> 16) & 0xF) == 0) {
            uint32_t size = (raw >> 22) & 3;
            bool is_q = ((raw >> 16) & 1) != 0;  // Q bit for .Q variant
            uint32_t V = (raw >> 15) & 1;
            uint32_t Rs = (raw >> 13) & 3;
            uint32_t Pg = (raw >> 10) & 7;
            uint32_t Zn = (raw >> 5) & 0x1F;
            std::ostringstream oss;
            oss << "mov ";
            // ZA tile operand: za<tile><hv>.<sz>[w<12+Rs>, <offset>]
            const char* hv = V ? "v" : "h";
            const char* sz_name;
            uint32_t tile, offset;
            if (size == 0 && !is_q) {
                // .B: ZAd is always 0, offset is 4 bits [3:0]
                sz_name = "b"; tile = 0; offset = raw & 0xF;
            } else if (size == 1) {
                // .H: ZAd is 1 bit [3], offset is 3 bits [2:0]
                sz_name = "h"; tile = (raw >> 3) & 1; offset = raw & 7;
            } else if (size == 2) {
                // .S: ZAd is 2 bits [3:2], offset is 2 bits [1:0]
                sz_name = "s"; tile = (raw >> 2) & 3; offset = raw & 3;
            } else if (size == 3 && !is_q) {
                // .D: ZAd is 3 bits [3:1], offset is 1 bit [0]
                sz_name = "d"; tile = (raw >> 1) & 7; offset = raw & 1;
            } else {
                // .Q: ZAd is 4 bits [3:0], no offset
                sz_name = "q"; tile = raw & 0xF; offset = 0;
            }
            oss << "za" << tile << hv << "." << sz_name;
            oss << "[w" << (12 + Rs) << ", ";
            if (offset >= 10) oss << "0x" << std::hex << offset;
            else oss << std::dec << offset;
            oss << "], p" << std::dec << Pg << "/m, z" << Zn << "." << sz_name;
            return oss.str();
        }
        // Detect mov_z_p_rza variants (ZA tile slice → Z vector): bit17=1, bits[21:18]=0
        if ((raw & 0xFF3E0000u) == 0xC0020000u) {
            uint32_t size = (raw >> 22) & 3;
            bool is_q = ((raw >> 16) & 1) != 0;
            uint32_t V = (raw >> 15) & 1;
            uint32_t Rs = (raw >> 13) & 3;
            uint32_t Pg = (raw >> 10) & 7;
            uint32_t Zd = raw & 0x1F;
            std::ostringstream oss;
            oss << "mov ";
            const char* hv = V ? "v" : "h";
            const char* sz_name;
            uint32_t tile, offset;
            // tile/offset encoded in bits[8:5] of the instruction
            if (size == 0 && !is_q) {
                sz_name = "b"; tile = 0; offset = (raw >> 5) & 0xF;
            } else if (size == 1 && !is_q) {
                sz_name = "h"; tile = (raw >> 8) & 1; offset = (raw >> 5) & 7;
            } else if (size == 2 && !is_q) {
                sz_name = "s"; tile = (raw >> 7) & 3; offset = (raw >> 5) & 3;
            } else if (size == 3 && !is_q) {
                sz_name = "d"; tile = (raw >> 6) & 7; offset = (raw >> 5) & 1;
            } else {
                sz_name = "q"; tile = (raw >> 5) & 0xF; offset = 0;
            }
            oss << "z" << Zd << "." << sz_name;
            oss << ", p" << std::dec << Pg << "/m, ";
            oss << "za" << tile << hv << "." << sz_name;
            oss << "[w" << (12 + Rs) << ", ";
            if (offset >= 10) oss << "0x" << std::hex << offset;
            else oss << std::dec << offset;
            oss << "]";
            return oss.str();
        }
    }

    // DSB CRm=0 → SSBB, CRm=4 → PSSBB
    if (insn.mnemonic == Mnemonic::DSB) {
        // Fixed-CRm encodings (no operands): check raw instruction bits
        uint32_t crm = (insn.raw_value >> 8) & 0xF;
        if (crm == 0) return std::string("ssbb");
        if (crm == 4) return std::string("pssbb");
    }

    // SVE: CPY → MOV alias
    if (insn.mnemonic == Mnemonic::CPY && insn.operands.size() >= 3) {
        std::ostringstream oss;
        oss << "mov";
        for (size_t i = 0; i < insn.operands.size(); ++i) {
            oss << (i == 0 ? " " : ", ") << insn.operands[i].to_string();
        }
        return oss.str();
    }

    // SVE: AND p,p/z,p,p with Pn==Pm → MOV p,p/z,p
    if (insn.mnemonic == Mnemonic::AND && insn.operands.size() == 4) {
        auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];
        if (op2.type == OperandType::Register && op3.type == OperandType::Register && register_num(op2.r.reg) == register_num(op3.r.reg)) {
            std::ostringstream oss;
            oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << op2.to_string();
            return oss.str();
        }
    }

    // SVE: EOR p,p/z,p,p with Pm==Pg → NOT p,p/z,p
    if (insn.mnemonic == Mnemonic::EOR && insn.operands.size() == 4 && insn.operands[0].reg_val() >= REG_P_BASE && insn.operands[0].reg_val() < REG_PN_BASE) {
        auto& op1 = insn.operands[1]; auto& op3 = insn.operands[3];
        if (op1.type == OperandType::Register && op3.type == OperandType::Register && register_num(op1.r.reg) == register_num(op3.r.reg)) {
            std::ostringstream oss;
            oss << "not " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();
            return oss.str();
        }
    }

    // SVE: ANDS p,p/z,p,p with Pn==Pm → MOVS p,p/z,p
    if (insn.mnemonic == Mnemonic::ANDS && insn.operands.size() == 4) {
        auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];
        if (op2.type == OperandType::Register && op3.type == OperandType::Register && register_num(op2.r.reg) == register_num(op3.r.reg)) {
            std::ostringstream oss;
            oss << "movs " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << op2.to_string();
            return oss.str();
        }
    }

    // SVE: EORS p,p/z,p,p with Pm==Pg → NOTS p,p/z,p
    if (insn.mnemonic == Mnemonic::EORS && insn.operands.size() == 4 && insn.operands[0].reg_val() >= REG_P_BASE && insn.operands[0].reg_val() < REG_PN_BASE) {
        auto& op1 = insn.operands[1]; auto& op3 = insn.operands[3];
        if (op1.type == OperandType::Register && op3.type == OperandType::Register && register_num(op1.r.reg) == register_num(op3.r.reg)) {
            std::ostringstream oss;
            oss << "nots " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();
            return oss.str();
        }
    }

    // SVE: DUP → MOV alias
    if (insn.mnemonic == Mnemonic::DUP && insn.operands.size() >= 1 && insn.operands[0].type == OperandType::Register && insn.operands[0].reg_val() >= static_cast<uint16_t>(Register::Z0)) {
        std::ostringstream oss;
        oss << "mov";
        for (size_t i = 0; i < insn.operands.size(); ++i) {
            oss << (i == 0 ? " " : ", ") << insn.operands[i].to_string();
        }
        return oss.str();
    }

    // SVE: SEL Pd, Pg, Pn, Pm → MOV Pd, Pg/M, Pn when Pd==Pm (predicate form)
    if (insn.mnemonic == Mnemonic::SEL && insn.operands.size() >= 4 && insn.operands[0].type == OperandType::Register) {
        if (register_num(insn.operands[0].r.reg) == register_num(insn.operands[3].r.reg)) {
            std::ostringstream oss;
            oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();
            return oss.str();
        }
    }

    // SVE: SEL Zd, Pg, Zn, Zm → MOV Zd, Pg/M, Zn when Zd==Zm
    if (insn.mnemonic == Mnemonic::SEL && insn.operands.size() >= 4 && insn.operands[0].type == OperandType::Register) {
        if (register_num(insn.operands[0].r.reg) == register_num(insn.operands[3].r.reg)) {
            std::ostringstream oss;
            oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string() << ", " << insn.operands[2].to_string();
            return oss.str();
        }
    }

    // SVE: ORR z,z,z with Zn==Zm → MOV z,z
    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() == 3 && insn.operands[0].type == OperandType::Register && insn.operands[0].reg_val() >= static_cast<uint16_t>(Register::Z0)) {
        auto& op1 = insn.operands[1]; auto& op2 = insn.operands[2];
        if (op1.type == OperandType::Register && op2.type == OperandType::Register && op1.reg_val() == op2.reg_val()) {
            std::ostringstream oss;
            oss << "mov " << insn.operands[0].to_string() << ", " << op1.to_string();
            return oss.str();
        }
    }

    // SVE: DUPM → MOV (preferred alias)
    if (insn.mnemonic == Mnemonic::DUPM) {
        std::ostringstream oss;
        oss << "mov " << insn.operands[0].to_string() << ", " << insn.operands[1].to_string();
        return oss.str();
    }

    // SVE: ORR p,p/z,p,p with Pn==Pm → MOV p,p/z,p
    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() == 4 && insn.operands[0].type == OperandType::Register) {
        auto& op1 = insn.operands[1]; auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];
        if (op2.type == OperandType::Register && op3.type == OperandType::Register && op2.reg_val() == op3.reg_val()) {
            std::ostringstream oss;
            if (op1.reg_val() == op2.reg_val())
                oss << "mov " << insn.operands[0].to_string() << ", " << op1.to_string();
            else
                oss << "mov " << insn.operands[0].to_string() << ", " << op1.to_string() << ", " << op2.to_string();
            return oss.str();
        }
    }

    // SVE: ORRS p,p/z,p,p with Pn==Pm → MOVS p,p/z,p
    if (insn.mnemonic == Mnemonic::ORRS && insn.operands.size() == 4) {
        auto& op1 = insn.operands[1]; auto& op2 = insn.operands[2]; auto& op3 = insn.operands[3];
        if (op2.type == OperandType::Register && op3.type == OperandType::Register && op2.reg_val() == op3.reg_val()) {
            std::ostringstream oss;
            if (op1.reg_val() == op2.reg_val())
                oss << "movs " << insn.operands[0].to_string() << ", " << op1.to_string();
            else
                oss << "movs " << insn.operands[0].to_string() << ", " << op1.to_string() << ", " << op2.to_string();
            return oss.str();
        }
    }

    // NOT (SIMD vector) → MVN alias (only for V registers, not SVE Z)
    if (insn.mnemonic == Mnemonic::NOT && !insn.operands.empty() && insn.operands[0].type == OperandType::Register && insn.operands[0].reg_val() < static_cast<uint16_t>(Register::Z0)) {
        std::ostringstream oss;
        oss << "mvn";
        for (size_t i = 0; i < insn.operands.size(); ++i) { oss << (i == 0 ? " " : ", ") << insn.operands[i].to_string(); }
        return oss.str();
    }

    return std::nullopt;  // No alias
}

// Format instruction as disassembly
std::string Instruction::to_string() const {
    // Try to synthesize a pseudo-instruction alias
    auto alias = synthesize_alias(*this);
    if (alias) {
        return *alias;
    }

    // Fall back to base mnemonic
    std::string result = mnemonic_to_string(mnemonic);

    // SIMD long/wide instructions: Q=1 → add '2' suffix (PMULL→PMULL2, SMLAL→SMLAL2, etc.)
    // Only for SIMD (bit31=0); SME2 instructions have bit31=1 and must not get this suffix
    // Also exclude scalar forms (asisdmisc) which have bit30=1 as fixed but no Q field
    // Check: first operand must have a multi-element arrangement (not scalar B/H/S/D/Q)
    Arrangement _first_arr = !operands.empty() ? register_arrangement(operands[0].r.reg) : Arrangement::None;
    bool _has_vector_arr = !operands.empty() && operands[0].type == OperandType::Register &&
        _first_arr != Arrangement::B && _first_arr != Arrangement::H &&
        _first_arr != Arrangement::S && _first_arr != Arrangement::D &&
        _first_arr != Arrangement::Q && _first_arr != Arrangement::None;
    if (_has_vector_arr && !(raw_value >> 31) && ((raw_value >> 30) & 1)) {  // Q bit, non-SME only
        if (mnemonic == Mnemonic::PMULL || mnemonic == Mnemonic::SMLAL || mnemonic == Mnemonic::SMLSL ||
            mnemonic == Mnemonic::UMLAL || mnemonic == Mnemonic::UMLSL || mnemonic == Mnemonic::SMULL ||
            mnemonic == Mnemonic::UMULL || mnemonic == Mnemonic::SQDMLAL || mnemonic == Mnemonic::SQDMLSL ||
            mnemonic == Mnemonic::SQDMULL || mnemonic == Mnemonic::SABAL || mnemonic == Mnemonic::UABAL ||
            mnemonic == Mnemonic::SABDL || mnemonic == Mnemonic::UABDL || mnemonic == Mnemonic::SADDL ||
            mnemonic == Mnemonic::UADDL || mnemonic == Mnemonic::SSUBL || mnemonic == Mnemonic::USUBL ||
            mnemonic == Mnemonic::SSHLL || mnemonic == Mnemonic::USHLL ||
            mnemonic == Mnemonic::ADDHN || mnemonic == Mnemonic::SUBHN ||
            mnemonic == Mnemonic::RADDHN || mnemonic == Mnemonic::RSUBHN ||
            mnemonic == Mnemonic::FCVTXN ||
            mnemonic == Mnemonic::XTN || mnemonic == Mnemonic::SQXTN ||
            mnemonic == Mnemonic::UQXTN || mnemonic == Mnemonic::SQXTUN) {
            result += "2";
        }
    }

    // For B/BC: condition is a suffix on the mnemonic (e.g., b.eq)
    if (condition != Condition::None &&
        (mnemonic == Mnemonic::B || mnemonic == Mnemonic::BC)) {
        const char* cond_str = condition_to_string(condition);
        if (cond_str) {
            result += ".";
            result += cond_str;
        }
    }

    if (!operands.empty()) {
        result += " ";
        for (size_t i = 0; i < operands.size(); ++i) {
            if (i > 0) result += ", ";
            result += operands[i].to_string();
        }
    }

    // For other instructions: condition at the end (e.g., ccmp w0, w0, #0, ne)
    if (condition != Condition::None &&
        mnemonic != Mnemonic::B && mnemonic != Mnemonic::BC) {
        const char* cond_str = condition_to_string(condition);
        if (cond_str) {
            if (!operands.empty()) result += ", ";
            else result += " ";
            result += cond_str;
        }
    }

    return result;
}

// Format operand for disassembly
std::string Operand::to_string() const {
    switch (type) {
        case OperandType::IndexedRegister:
        case OperandType::Register: {
            auto rv = r.reg;
            uint16_t rv_i = static_cast<uint16_t>(rv);
            std::string s = register_to_string(rv);
            // P registers: qualifier and PSEL index
            if (rv_i >= REG_P_BASE && rv_i < REG_PN_BASE) {
                if (r.qual == PredQual::Zeroing) s += "/z";
                else if (r.qual == PredQual::Merging) s += "/m";
                if (type == OperandType::IndexedRegister) s += std::string("[") + register_to_string(r.idx_reg) + ", " + std::to_string(r.index) + "]";
                return s;
            }
            // PN registers: index then qualifier
            if (rv_i >= REG_PN_BASE && rv_i < REG_ZA_BASE) {
                if (type == OperandType::IndexedRegister) s += "[" + std::to_string(r.index) + "]";
                if (r.qual == PredQual::Zeroing) s += "/z";
                else if (r.qual == PredQual::Merging) s += "/m";
                return s;
            }
            // Generic index display for V/Z/ZT0 etc.
            if (type == OperandType::IndexedRegister) {
                if (r.index >= 10) { std::ostringstream _oss; _oss << "[0x" << std::hex << r.index << "]"; s += _oss.str(); }
                else s += "[" + std::to_string(r.index) + "]";
            }
            return s;
        }

        case OperandType::DecimalImmediate:
            return "#" + std::to_string(iv.value);
        case OperandType::Immediate:
            {
                std::ostringstream oss;
                uint64_t display_val = iv.value;
                if (display_val <= 9) {
                    oss << "#" << std::dec << display_val;
                } else {
                    oss << "#0x" << std::hex << display_val;
                }
                return oss.str();
            }

        case OperandType::SignedImmediate:
            {
                std::ostringstream oss;
                int32_t sval = si.offset;
                if (sval < 0) {
                    if (sval >= -9) {
                        oss << "#" << std::dec << sval;
                    } else {
                        oss << "#-0x" << std::hex << (-sval);
                    }
                } else {
                    if (sval <= 9) {
                        oss << "#" << std::dec << sval;
                    } else {
                        oss << "#0x" << std::hex << sval;
                    }
                }
                return oss.str();
            }


        case OperandType::SMETileRegister:
            {
            auto _sme_rv = sme.tile;
            auto _sme_arr = register_arrangement(_sme_rv);
            auto _sme_num = register_num(_sme_rv);
            // mode==2: VGx mode: za.T[wN, offs{, vgxN}]
            if (sme.wv && sme.mode == 2) {
                std::string s = "za";
                if (_sme_arr != Arrangement::None) { s += "."; s += arrangement_to_string(_sme_arr); }
                s += "[w" + std::to_string(sme.wv) + ", " + std::to_string(sme.start);
                int32_t vgx = static_cast<int32_t>(sme.detail);
                if (vgx > 1) s += ", vgx" + std::to_string(vgx);
                s += "]";
                return s;
            }
            // mode==1 or 3: ZA accumulator range za.T[wN, start:end{, vgxN}]
            if (sme.wv && (sme.mode == 1 || sme.mode == 3)) {
                std::string s = "za";
                if (_sme_arr != Arrangement::None) { s += "."; s += arrangement_to_string(_sme_arr); }
                s += "[w" + std::to_string(sme.wv) + ", ";
                if (sme.start >= 10) { std::ostringstream oss; oss << "0x" << std::hex << static_cast<uint32_t>(sme.start); s += oss.str(); }
                else s += std::to_string(sme.start);
                s += ":";
                uint32_t range_end = static_cast<uint32_t>(sme.detail & 0xFFFF);
                if (range_end >= 10) { std::ostringstream oss; oss << "0x" << std::hex << range_end; s += oss.str(); }
                else s += std::to_string(range_end);
                if (sme.mode == 3) { int32_t vgx = (sme.detail >> 16) & 0xFFFF; if (vgx > 1) s += ", vgx" + std::to_string(vgx); }
                s += "]";
                return s;
            }
            // mode==5: LDR/STR ZA: za[wN, offs] (no tile number, no H/V)
            if (sme.wv && sme.mode == 5) {
                std::string s = "za[w" + std::to_string(sme.wv) + ", " + std::to_string(sme.start) + "]";
                return s;
            }
            // mode==4 or 12: MOVA-style za tile with H/V + range: zaTILEh/v.T[wN, start:end]
            // bit 3 of mode = vertical flag (4=h, 12=v)
            if (sme.wv && (sme.mode == 4 || sme.mode == 12)) {
                std::string s = "za" + std::to_string(_sme_num);
                s += (sme.mode & 8) ? "v" : "h";
                if (_sme_arr != Arrangement::None) { s += "."; s += arrangement_to_string(_sme_arr); }
                s += "[w" + std::to_string(sme.wv) + ", ";
                s += std::to_string(sme.start);
                uint32_t range_end = static_cast<uint32_t>(sme.detail & 0xFFFF);
                if (range_end != sme.start) { s += ":"; s += std::to_string(range_end); }
                s += "]";
                return s;
            }
            // wv nonzero: ZA tile slice {zaXv/h.T[wN, offs]} (no spaces inside braces)
            // bit 3 of mode = vertical flag (0=h, 8=v)
            if (sme.wv) {
                std::string s = "{za" + std::to_string(_sme_num);
                s += (sme.mode & 8) ? "v" : "h";
                if (_sme_arr != Arrangement::None) { s += "."; s += arrangement_to_string(_sme_arr); }
                s += "[w" + std::to_string(sme.wv) + ", ";
                if (sme.start >= 10) { std::ostringstream oss; oss << "0x" << std::hex << static_cast<uint32_t>(sme.start); s += oss.str(); }
                else s += std::to_string(sme.start);
                s += "]}";
                return s;
            }
            {
                std::string s = register_to_string(_sme_rv);
                return s;
            }
            }


        case OperandType::PstateField:
            {
                const char* s = pstate_to_string(e.pstate);
                if (s) return s;
                return "#" + std::to_string(static_cast<uint16_t>(e.pstate));
            }

        case OperandType::FixedSym:
            {
                static const char* fixed_syms[] = {"csync", "dsync"};
                if (sv.val < 2) return fixed_syms[sv.val];
                return "?";
            }

        case OperandType::SysOp:
            {
                const char* s = sysop_to_string(e.sysop);
                if (s) return s;
                return sys_ops[static_cast<uint16_t>(e.sysop)];
            }

        case OperandType::Memory: {
            std::string base = format_base_reg(mem.base);
            // PostIndex: [base], #offset
            if (mem.mode == MemoryMode::PostIndex) {
                std::ostringstream oss;
                oss << "[" << base << "], #";
                if (mem.offset < 0) {
                    if (mem.offset >= -15) oss << std::dec << mem.offset;
                    else oss << "-0x" << std::hex << (-mem.offset);
                } else {
                    if (mem.offset <= 15) oss << std::dec << mem.offset;
                    else oss << "0x" << std::hex << mem.offset;
                }
                return oss.str();
            }
            // Base or zero offset: [base]
            if (mem.offset == 0 && mem.mode != MemoryMode::PreIndex) {
                return "[" + base + "]";
            }
            // Offset or PreIndex or MulVL: [base, #offset]{!}{, mul vl}
            {
                std::ostringstream oss;
                oss << "[" << base << ", #";
                if (mem.offset < 0) {
                    if (mem.offset >= -15) oss << std::dec << mem.offset;
                    else oss << "-0x" << std::hex << (-mem.offset);
                } else {
                    if (mem.offset <= 15) oss << std::dec << mem.offset;
                    else oss << "0x" << std::hex << mem.offset;
                }
                if (mem.mode == MemoryMode::MulVL) oss << ", mul vl";
                oss << "]";
                if (mem.mode == MemoryMode::PreIndex) oss << "!";
                return oss.str();
            }
        }

        case OperandType::MemoryRegOffset:
            // [Xn|SP, Rm{, extend {#amount}}] or [Xn|SP, Zm.T{, lsl #N}]
            {
                uint8_t _ext = static_cast<uint8_t>(mreg.extend);
                std::string result = "[" + format_base_reg(mreg.base) + ", ";
                uint16_t idx_i = static_cast<uint16_t>(mreg.index);
                if (idx_i >= REG_Z_BASE && idx_i < REG_P_BASE) {
                    // SVE Z register index: [Xn, Zm.T{, mod #N}]
                    result += register_to_string(mreg.index);
                    const char* sve_extends[] = {"uxtb", "uxth", "uxtw", "lsl",
                                                  "sxtb", "sxth", "sxtw", "sxtx"};
                    if (_ext < 8 && _ext != 0) {
                        result += std::string(", ") + sve_extends[_ext];
                        if (mreg.amount > 0) result += " #" + std::to_string(mreg.amount);
                    } else if (mreg.amount > 0) {
                        result += ", lsl #" + std::to_string(mreg.amount);
                    }
                } else {
                    // GP index register (W/X already encoded in Register enum)
                    result += register_to_string(mreg.index);
                    // extend=3 (UXTX) is equivalent to LSL for 64-bit index
                    // Suppress extend=3 with amount=0 (it's the default)
                    if (_ext == 3 && mreg.amount == 0) {
                        // Default: no extend/shift needed
                    } else if (_ext != 0 || mreg.amount != 0) {
                        const char* extends[] = {"uxtb", "uxth", "uxtw", "lsl",
                                                 "sxtb", "sxth", "sxtw", "sxtx"};
                        if (_ext < 8) {
                            result += ", " + std::string(extends[_ext]);
                            if (mreg.amount != 0) {
                                result += " #" + std::to_string(mreg.amount);
                            }
                        }
                    }
                }
                result += "]";
                return result;
            }

        case OperandType::SystemRegister:
            {
                if (sys.sysreg != SystemRegister::UNKNOWN) {
                    return sysreg_to_string(sys.sysreg);
                }
                // Fallback: decode from raw value
                uint32_t o0 = (sv.val >> 14) & 1;
                uint32_t op1 = (sv.val >> 11) & 7;
                uint32_t crn = (sv.val >> 7) & 0xF;
                uint32_t crm = (sv.val >> 3) & 0xF;
                uint32_t op2v = sv.val & 7;
                // Try lookup from encoding
                SystemRegister sr = sysreg_from_encoding(2 + o0, op1, crn, crm, op2v);
                if (sr != SystemRegister::UNKNOWN) {
                    return sysreg_to_string(sr);
                }
                // Final fallback: S<op0>_<op1>_C<CRn>_C<CRm>_<op2>
                std::ostringstream oss;
                oss << "s" << (2 + o0) << "_" << op1 << "_c" << crn << "_c" << crm << "_" << op2v;
                return oss.str();
            }

        case OperandType::Shift:
            {
                const char* shifts[] = {"lsl", "lsr", "asr", "ror", "msl"};
                uint32_t st = static_cast<uint32_t>(sh.shift_type);
                if (st > 4) st = 0;  // safety
                std::ostringstream oss;
                oss << shifts[st] << " #";
                if (sh.amount <= 15) oss << std::dec << static_cast<uint32_t>(sh.amount);
                else oss << "0x" << std::hex << static_cast<uint32_t>(sh.amount);
                return oss.str();
            }

        case OperandType::Extend64:
            {
                uint32_t et = static_cast<uint32_t>(ext.ext_type) & 0x7;
                const char* names[] = {"uxtb", "uxth", "uxtw", "lsl",
                                       "sxtb", "sxth", "sxtw", "sxtx"};
                std::string result = names[et];
                if (ext.amount != 0) result += " #" + std::to_string(ext.amount);
                return result;
            }
        case OperandType::Extend:
            {
                uint32_t et = static_cast<uint32_t>(ext.ext_type) & 0x7;
                const char* names[] = {"uxtb", "uxth", "uxtw", "uxtx",
                                       "sxtb", "sxth", "sxtw", "sxtx"};
                std::string result = names[et];
                if (ext.amount != 0) result += " #" + std::to_string(ext.amount);
                return result;
            }

        case OperandType::Index:
            return "[" + std::to_string(sv.val) + "]";

        case OperandType::Label:
            // Format as signed hex offset
            {
                std::ostringstream oss;
                int32_t sval = si.offset;
                if (sval < 0) oss << "#-0x" << std::hex << (-sval);
                else oss << "#0x" << std::hex << sval;
                return oss.str();
            }

        case OperandType::Relative:
            // Format as PC-relative offset (.+0x10 or .-0x10)
            {
                std::ostringstream oss;
                int64_t sval = static_cast<int64_t>(iv.value);
                if (sval < 0) oss << ".-0x" << std::hex << (-sval);
                else oss << ".+0x" << std::hex << sval;
                return oss.str();
            }

        case OperandType::Pattern:
            {
                const char* s = pattern_to_string(e.pattern);
                if (s) return s;
                return "#" + std::to_string(static_cast<uint16_t>(e.pattern));
            }

        case OperandType::SVEMulImm:
            // SVE multiplier: 'mul #N' where sv.val is already N (=imm4+1)
            if (sv.val >= 10) {
                std::ostringstream _oss; _oss << "mul #0x" << std::hex << sv.val;
                return _oss.str();
            }
            return "mul #" + std::to_string(sv.val);

        case OperandType::SVEVLxImm:
            // SVE VL specifier: vlx2 or vlx4
            return sv.val == 4 ? "vlx4" : "vlx2";


        case OperandType::Prefetch:
            {
                const char* s = prefetch_to_string(e.prefetch);
                if (s) return s;
                std::ostringstream oss; oss << "#0x" << std::hex << static_cast<uint32_t>(e.prefetch); return oss.str();
            }

        case OperandType::Barrier:
            {
                const char* s = barrier_to_string(e.barrier);
                if (s) return s;
                return "#" + std::to_string(static_cast<uint16_t>(e.barrier));
            }

        case OperandType::FloatImmediate:
            {
                // Literal zero marker (FCMPE/FCMP #0.0)
                if (sv.val == 0xFFFF) return "#0.0";
                // Decode ARM VFPExpandImm{64}: imm8 → double
                // exp = NOT(imm8[6]):Replicate{8}(imm8[6]):imm8[5:4]
                // frac = imm8[3:0]:Zeros{48}
                uint64_t sign_bit = (sv.val >> 7) & 1;
                uint64_t b = (sv.val >> 6) & 1;
                uint64_t cd = (sv.val >> 4) & 0x3;
                uint64_t efgh = sv.val & 0xF;
                // NOT(b):Replicate{8}(b):cd = 11-bit exponent
                uint64_t exp = ((1 - b) << 10) | ((b ? 0xFF : 0x00) << 2) | cd;
                uint64_t frac = static_cast<uint64_t>(efgh) << 48;
                uint64_t bits = (sign_bit << 63) | (exp << 52) | frac;
                double fval;
                std::memcpy(&fval, &bits, 8);
                std::ostringstream oss;
                oss << "#" << std::fixed << std::setprecision(8) << fval;
                return oss.str();
            }

        case OperandType::IndexedRegisterList:
        case OperandType::RegisterList:
            {
                // Detect list type from Register enum value of first element
                auto _list_reg = rl.first;
                auto _list_arr = register_arrangement(_list_reg);
                auto _list_num = register_num(_list_reg);
                const char* prefix;
                uint32_t mask;
                uint32_t base_num = _list_num;
                uint16_t rv = static_cast<uint16_t>(_list_reg);
                if (rv >= REG_P_BASE && rv < REG_PN_BASE) {
                    prefix = "p"; mask = 15;
                } else if (rv >= REG_Z_BASE && rv < REG_P_BASE) {
                    prefix = "z"; mask = 31;
                } else if (rv >= REG_V_BASE && rv < REG_Z_BASE) {
                    prefix = "v"; mask = 31;
                } else {
                    mask = 31; prefix = "v";
                }
                const char* arr_str = (_list_arr != Arrangement::None) ? arrangement_to_string(_list_arr) : nullptr;
                uint32_t stride = (rl.stride > 1) ? static_cast<uint32_t>(rl.stride) : 1;
                // Use range notation for count>=3 when consecutive and non-wrapping
                bool is_sve = (rv >= REG_Z_BASE && rv < REG_P_BASE);
                if (is_sve && stride == 1 && rl.count >= 3 && (base_num + rl.count - 1) <= 31) {
                    std::string result = std::string("{ ") + prefix + std::to_string(base_num);
                    if (arr_str) { result += "."; result += arr_str; }
                    result += std::string(" - ") + prefix + std::to_string(base_num + rl.count - 1);
                    if (arr_str) { result += "."; result += arr_str; }
                    result += " }";
                    return result;
                }
                std::string result = "{ ";
                for (uint32_t i = 0; i < rl.count; ++i) {
                    if (i > 0) result += ", ";
                    uint32_t reg = (base_num + i * stride) & mask;
                    result += std::string(prefix) + std::to_string(reg);
                    if (arr_str) { result += "."; result += arr_str; }
                }
                result += " }";
                if (type == OperandType::IndexedRegisterList) {
                    result += "[" + std::to_string(rl.elem_index) + "]";
                }
                return result;
            }


        case OperandType::MemorySVEOffset:
            // [Zn.T, #offset] or [Zn.T] when offset==0
            {
                std::string result = "[" + std::string(register_to_string(msve.base));
                if (msve.offset != 0) {
                    std::ostringstream oss;
                    oss << ", #";
                    if (msve.offset < 0) {
                        if (msve.offset >= -9) oss << std::dec << msve.offset;
                        else oss << "-0x" << std::hex << (-msve.offset);
                    } else {
                        if (msve.offset <= 9) oss << std::dec << msve.offset;
                        else oss << "0x" << std::hex << msve.offset;
                    }
                    result += oss.str();
                }
                result += "]";
                return result;
            }

        default:
            return std::to_string(sv.val);
    }
}
#endif // VEDA64_STRINGS

// Unified decode function - dispatches to format-based group decoders
std::optional<Instruction> decode(uint32_t insn, bool aliases) {
    return decode_format(insn, aliases);
}

} // namespace veda64
