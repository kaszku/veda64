#include "veda64.hpp"
#include "format/format.hpp"
#include <cstring>
#include <sstream>

namespace veda64 {

#if !defined(VEDA64_NO_STRINGS) && !defined(VEDA64_NO_MNEMONIC_OPERANDS)
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
        case Mnemonic::ASR: return "asr";
        case Mnemonic::ASRD: return "asrd";
        case Mnemonic::ASRR: return "asrr";
        case Mnemonic::ASRV: return "asrv";
        case Mnemonic::AUTIA1716: return "autia1716";
        case Mnemonic::AUTIA171615: return "autia171615";
        case Mnemonic::AUTIASP: return "autiasp";
        case Mnemonic::AUTIASPPC: return "autiasppc";
        case Mnemonic::AUTIASPPCR: return "autiasppcr";
        case Mnemonic::AUTIAZ: return "autiaz";
        case Mnemonic::AUTIB1716: return "autib1716";
        case Mnemonic::AUTIB171615: return "autib171615";
        case Mnemonic::AUTIBSP: return "autibsp";
        case Mnemonic::AUTIBSPPC: return "autibsppc";
        case Mnemonic::AUTIBSPPCR: return "autibsppcr";
        case Mnemonic::AUTIBZ: return "autibz";
        case Mnemonic::AXFLAG: return "axflag";
        case Mnemonic::B: return "b";
        case Mnemonic::BC: return "bc";
        case Mnemonic::BCAX: return "bcax";
        case Mnemonic::BDEP: return "bdep";
        case Mnemonic::BEXT: return "bext";
        case Mnemonic::BFADD: return "bfadd";
        case Mnemonic::BFCLAMP: return "bfclamp";
        case Mnemonic::BFCVT: return "bfcvt";
        case Mnemonic::BFCVTN: return "bfcvtn";
        case Mnemonic::BFCVTNT: return "bfcvtnt";
        case Mnemonic::BFDOT: return "bfdot";
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
        case Mnemonic::BMOPA: return "bmopa";
        case Mnemonic::BMOPS: return "bmops";
        case Mnemonic::BR: return "br";
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
        case Mnemonic::CBBGE: return "cbbge";
        case Mnemonic::CBBGT: return "cbbgt";
        case Mnemonic::CBBHI: return "cbbhi";
        case Mnemonic::CBBHS: return "cbbhs";
        case Mnemonic::CBGE: return "cbge";
        case Mnemonic::CBGT: return "cbgt";
        case Mnemonic::CBHGE: return "cbhge";
        case Mnemonic::CBHGT: return "cbhgt";
        case Mnemonic::CBHHI: return "cbhhi";
        case Mnemonic::CBHHS: return "cbhhs";
        case Mnemonic::CBHI: return "cbhi";
        case Mnemonic::CBHS: return "cbhs";
        case Mnemonic::CBLO: return "cblo";
        case Mnemonic::CBLT: return "cblt";
        case Mnemonic::CBNZ: return "cbnz";
        case Mnemonic::CBZ: return "cbz";
        case Mnemonic::CCMN: return "ccmn";
        case Mnemonic::CCMP: return "ccmp";
        case Mnemonic::CDOT: return "cdot";
        case Mnemonic::CFINV: return "cfinv";
        case Mnemonic::CHKFEAT: return "chkfeat";
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
        case Mnemonic::CMPGE: return "cmpge";
        case Mnemonic::CMPGT: return "cmpgt";
        case Mnemonic::CMPHI: return "cmphi";
        case Mnemonic::CMPHS: return "cmphs";
        case Mnemonic::CMTST: return "cmtst";
        case Mnemonic::CNOT: return "cnot";
        case Mnemonic::CNT: return "cnt";
        case Mnemonic::CNTP: return "cntp";
        case Mnemonic::COMPACT: return "compact";
        case Mnemonic::CPY: return "cpy";
        case Mnemonic::CSDB: return "csdb";
        case Mnemonic::CSEL: return "csel";
        case Mnemonic::CSINC: return "csinc";
        case Mnemonic::CSINV: return "csinv";
        case Mnemonic::CSNEG: return "csneg";
        case Mnemonic::CTZ: return "ctz";
        case Mnemonic::DCPS1: return "dcps1";
        case Mnemonic::DCPS2: return "dcps2";
        case Mnemonic::DCPS3: return "dcps3";
        case Mnemonic::DECP: return "decp";
        case Mnemonic::DGH: return "dgh";
        case Mnemonic::DMB: return "dmb";
        case Mnemonic::DRPS: return "drps";
        case Mnemonic::DSB: return "dsb";
        case Mnemonic::DUP: return "dup";
        case Mnemonic::DUPM: return "dupm";
        case Mnemonic::DUPQ: return "dupq";
        case Mnemonic::EON: return "eon";
        case Mnemonic::EOR: return "eor";
        case Mnemonic::EOR3: return "eor3";
        case Mnemonic::EORBT: return "eorbt";
        case Mnemonic::EORQV: return "eorqv";
        case Mnemonic::EORS: return "eors";
        case Mnemonic::EORTB: return "eortb";
        case Mnemonic::EORV: return "eorv";
        case Mnemonic::ERET: return "eret";
        case Mnemonic::ESB: return "esb";
        case Mnemonic::EXPAND: return "expand";
        case Mnemonic::EXT: return "ext";
        case Mnemonic::EXTQ: return "extq";
        case Mnemonic::EXTR: return "extr";
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
        case Mnemonic::FCMP: return "fcmp";
        case Mnemonic::FCMPE: return "fcmpe";
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
        case Mnemonic::FMLALB: return "fmlalb";
        case Mnemonic::FMLALL: return "fmlall";
        case Mnemonic::FMLALLBB: return "fmlallbb";
        case Mnemonic::FMLALLBT: return "fmlallbt";
        case Mnemonic::FMLALLTB: return "fmlalltb";
        case Mnemonic::FMLALLTT: return "fmlalltt";
        case Mnemonic::FMLALT: return "fmlalt";
        case Mnemonic::FMLS: return "fmls";
        case Mnemonic::FMLSL: return "fmlsl";
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
        case Mnemonic::GCSSTR: return "gcsstr";
        case Mnemonic::GCSSTTR: return "gcssttr";
        case Mnemonic::GMI: return "gmi";
        case Mnemonic::HINT: return "hint";
        case Mnemonic::HISTCNT: return "histcnt";
        case Mnemonic::HISTSEG: return "histseg";
        case Mnemonic::HLT: return "hlt";
        case Mnemonic::HVC: return "hvc";
        case Mnemonic::INCP: return "incp";
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
        case Mnemonic::LDFF1B: return "ldff1b";
        case Mnemonic::LDFF1D: return "ldff1d";
        case Mnemonic::LDFF1H: return "ldff1h";
        case Mnemonic::LDFF1SB: return "ldff1sb";
        case Mnemonic::LDFF1SH: return "ldff1sh";
        case Mnemonic::LDFF1SW: return "ldff1sw";
        case Mnemonic::LDFF1W: return "ldff1w";
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
        case Mnemonic::LDRB: return "ldrb";
        case Mnemonic::LDRH: return "ldrh";
        case Mnemonic::LDRSB: return "ldrsb";
        case Mnemonic::LDRSH: return "ldrsh";
        case Mnemonic::LDRSW: return "ldrsw";
        case Mnemonic::LDTNP: return "ldtnp";
        case Mnemonic::LDTP: return "ldtp";
        case Mnemonic::LDTR: return "ldtr";
        case Mnemonic::LDTRB: return "ldtrb";
        case Mnemonic::LDTRH: return "ldtrh";
        case Mnemonic::LDTRSB: return "ldtrsb";
        case Mnemonic::LDTRSH: return "ldtrsh";
        case Mnemonic::LDTRSW: return "ldtrsw";
        case Mnemonic::LDTXR: return "ldtxr";
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
        case Mnemonic::MLS: return "mls";
        case Mnemonic::MOVA: return "mova";
        case Mnemonic::MOVAZ: return "movaz";
        case Mnemonic::MOVI: return "movi";
        case Mnemonic::MOVK: return "movk";
        case Mnemonic::MOVN: return "movn";
        case Mnemonic::MOVPRFX: return "movprfx";
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
        case Mnemonic::MVNI: return "mvni";
        case Mnemonic::NAND: return "nand";
        case Mnemonic::NANDS: return "nands";
        case Mnemonic::NBSL: return "nbsl";
        case Mnemonic::NEG: return "neg";
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
        case Mnemonic::PACGA: return "pacga";
        case Mnemonic::PACIA1716: return "pacia1716";
        case Mnemonic::PACIA171615: return "pacia171615";
        case Mnemonic::PACIASP: return "paciasp";
        case Mnemonic::PACIASPPC: return "paciasppc";
        case Mnemonic::PACIAZ: return "paciaz";
        case Mnemonic::PACIB1716: return "pacib1716";
        case Mnemonic::PACIB171615: return "pacib171615";
        case Mnemonic::PACIBSP: return "pacibsp";
        case Mnemonic::PACIBSPPC: return "pacibsppc";
        case Mnemonic::PACIBZ: return "pacibz";
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
        case Mnemonic::PTEST: return "ptest";
        case Mnemonic::PTRUE: return "ptrue";
        case Mnemonic::PTRUES: return "ptrues";
        case Mnemonic::RADDHN: return "raddhn";
        case Mnemonic::RADDHNB: return "raddhnb";
        case Mnemonic::RADDHNT: return "raddhnt";
        case Mnemonic::RAX1: return "rax1";
        case Mnemonic::RBIT: return "rbit";
        case Mnemonic::RDFFR: return "rdffr";
        case Mnemonic::RDFFRS: return "rdffrs";
        case Mnemonic::RDSVL: return "rdsvl";
        case Mnemonic::RDVL: return "rdvl";
        case Mnemonic::RET: return "ret";
        case Mnemonic::REV: return "rev";
        case Mnemonic::REV16: return "rev16";
        case Mnemonic::REV32: return "rev32";
        case Mnemonic::REV64: return "rev64";
        case Mnemonic::REVD: return "revd";
        case Mnemonic::RMIF: return "rmif";
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
        case Mnemonic::SBFM: return "sbfm";
        case Mnemonic::SCLAMP: return "sclamp";
        case Mnemonic::SCVTF: return "scvtf";
        case Mnemonic::SCVTFLT: return "scvtflt";
        case Mnemonic::SDIV: return "sdiv";
        case Mnemonic::SDIVR: return "sdivr";
        case Mnemonic::SDOT: return "sdot";
        case Mnemonic::SEL: return "sel";
        case Mnemonic::SETFFR: return "setffr";
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
        case Mnemonic::SMOP4A: return "smop4a";
        case Mnemonic::SMOP4S: return "smop4s";
        case Mnemonic::SMOPA: return "smopa";
        case Mnemonic::SMOPS: return "smops";
        case Mnemonic::SMOV: return "smov";
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
        case Mnemonic::STCPH: return "stcph";
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
        case Mnemonic::SUQADD: return "suqadd";
        case Mnemonic::SUTMOPA: return "sutmopa";
        case Mnemonic::SUVDOT: return "suvdot";
        case Mnemonic::SVC: return "svc";
        case Mnemonic::SVDOT: return "svdot";
        case Mnemonic::SYS: return "sys";
        case Mnemonic::SYSL: return "sysl";
        case Mnemonic::SYSP: return "sysp";
        case Mnemonic::TBL: return "tbl";
        case Mnemonic::TBLQ: return "tblq";
        case Mnemonic::TBNZ: return "tbnz";
        case Mnemonic::TBX: return "tbx";
        case Mnemonic::TBXQ: return "tbxq";
        case Mnemonic::TBZ: return "tbz";
        case Mnemonic::TRN1: return "trn1";
        case Mnemonic::TRN2: return "trn2";
        case Mnemonic::TSB: return "tsb";
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
        case Mnemonic::UVDOT: return "uvdot";
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

// Format a general purpose register
std::string Operand::format_register(uint32_t reg, bool is_64bit, bool is_sp) {
    if (reg == 31) {
        if (is_sp) {
            return is_64bit ? "sp" : "wsp";
        } else {
            return is_64bit ? "xzr" : "wzr";
        }
    }
    // Use register aliases for x29 (fp) and x30 (lr)
    if (is_64bit) {
        if (reg == 29) return "fp";
        if (reg == 30) return "lr";
    }
    char prefix = is_64bit ? 'x' : 'w';
    return std::string(1, prefix) + std::to_string(reg);
}

// Format a vector register
std::string Operand::format_vector_register(uint32_t reg, const char* arrangement) {
    std::string result = "v" + std::to_string(reg);
    if (arrangement && arrangement[0] != '\0') {
        result += ".";
        result += arrangement;
    }
    return result;
}

// Synthesize pseudo-instruction aliases
std::optional<std::string> synthesize_alias(const Instruction& insn) {
    // MOV Aliases: ADD/ORR with sp or Rn==Rm pattern
    if (insn.mnemonic == Mnemonic::ADD && insn.operands.size() >= 3) {
        auto& op0 = insn.operands[0];
        auto& op1 = insn.operands[1];
        auto& op2 = insn.operands[2];
        if ((op0.value == 31 || op1.value == 31) &&
            op2.type == OperandType::Immediate && op2.value == 0) {
            return std::string("mov ") + op0.to_string() + ", " + op1.to_string();
        }
    }

    if (insn.mnemonic == Mnemonic::ORR && insn.operands.size() >= 2) {
        // MOV Rd, Rm = ORR Rd, XZR/WZR, Rm (no shift)
        if (insn.operands.size() == 2 && insn.operands[1].type == OperandType::Register) {
            // 2-operand form: MOV alias encoding (Rn=XZR is implicit)
            return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string();
        }
        if (insn.operands.size() >= 3 && insn.operands[1].value == 31 && insn.operands[1].type == OperandType::Register) {
            bool no_shift = insn.operands.size() < 4 || insn.operands[3].type != OperandType::Shift || insn.operands[3].value == 0;
            if (no_shift) {
                return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[2].to_string();
            }
        }
    }

    // MOVZ/MOVN/MOVK with or without shifts -> MOV/MVN alias
    if (insn.mnemonic == Mnemonic::MOVZ && insn.operands.size() >= 2) {
        // Check if there's a shift operand
        bool has_shift = insn.operands.size() >= 3 && insn.operands[2].type == OperandType::Shift;
        if (has_shift) {
            // Compute the final shifted value
            uint64_t imm = insn.operands[1].value;
            uint32_t shift_amt = insn.operands[2].value & 0xFF;
            uint64_t final_val = imm << shift_amt;
            std::ostringstream oss;
            oss << "mov " << insn.operands[0].to_string() << ", #0x" << std::hex << final_val;
            return oss.str();
        } else {
            return std::string("mov ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string();
        }
    }

    if (insn.mnemonic == Mnemonic::MOVN && insn.operands.size() >= 2) {
        bool has_shift = insn.operands.size() >= 3 && insn.operands[2].type == OperandType::Shift;
        if (has_shift) {
            // Compute the final shifted and inverted value
            uint64_t imm = insn.operands[1].value;
            uint32_t shift_amt = insn.operands[2].value & 0xFF;
            uint64_t final_val = ~(imm << shift_amt);
            // Mask to register size
            if (!insn.operands[0].is_64bit) final_val &= 0xFFFFFFFFULL;
            std::ostringstream oss;
            oss << "mov " << insn.operands[0].to_string() << ", #0x" << std::hex << final_val;
            return oss.str();
        } else {
            return std::string("mvn ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string();
        }
    }

    if (insn.mnemonic == Mnemonic::SUBS && insn.operands.size() >= 3) {
        if (insn.operands[0].value == 31) {
            std::string result = "cmp";
            for (size_t i = 1; i < insn.operands.size(); ++i) {
                result += (i == 1 ? " " : ", ") + insn.operands[i].to_string();
            }
            return result;
        }
    }

    if (insn.mnemonic == Mnemonic::ADDS && insn.operands.size() >= 3) {
        if (insn.operands[0].value == 31) {
            std::string result = "cmn";
            for (size_t i = 1; i < insn.operands.size(); ++i) {
                result += (i == 1 ? " " : ", ") + insn.operands[i].to_string();
            }
            return result;
        }
    }

    if (insn.mnemonic == Mnemonic::ANDS && insn.operands.size() >= 3) {
        if (insn.operands[0].value == 31) {
            std::string result = "tst";
            for (size_t i = 1; i < insn.operands.size(); ++i) {
                result += (i == 1 ? " " : ", ") + insn.operands[i].to_string();
            }
            return result;
        }
    }

    // NEG Aliases: SUB/SUBS with Rn==31 (register form only, not immediate)
    if (insn.mnemonic == Mnemonic::SUB && insn.operands.size() >= 3) {
        if (insn.operands[1].value == 31 && insn.operands[2].type == OperandType::Register) {
            return std::string("neg ") + insn.operands[0].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    if (insn.mnemonic == Mnemonic::SUBS && insn.operands.size() >= 3) {
        if (insn.operands[1].value == 31 && insn.operands[0].value != 31 && insn.operands[2].type == OperandType::Register) {
            return std::string("negs ") + insn.operands[0].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    // MUL Aliases: MADD/MSUB with Ra==31
    if (insn.mnemonic == Mnemonic::MADD && insn.operands.size() >= 4) {
        if (insn.operands[3].value == 31) {
            return std::string("mul ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    if (insn.mnemonic == Mnemonic::MSUB && insn.operands.size() >= 4) {
        if (insn.operands[3].value == 31) {
            return std::string("mneg ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
    }

    // ROR Aliases: EXTR with Rn==Rm (ROR is EXTR with both operands same)
    if (insn.mnemonic == Mnemonic::EXTR && insn.operands.size() >= 4) {
        if (insn.operands[1].value == insn.operands[2].value) {
            return std::string("ror ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[3].to_string();
        }
    }

    // RORV -> ROR alias (variable rotate is just called ROR in disassembly)
    if (insn.mnemonic == Mnemonic::RORV && insn.operands.size() >= 3) {
        return std::string("ror ") + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
    }

    // CSEL condition suffix (cseleq, cselne, etc.)
    if (insn.mnemonic == Mnemonic::CSEL && insn.operands.size() >= 4 && insn.operands[3].type == OperandType::Condition) {
        const char* conds[] = {"eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc",
                               "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"};
        uint32_t cond = insn.operands[3].value;
        if (cond < 16) {
            return std::string("csel") + conds[cond] + " " + insn.operands[0].to_string() + ", " + insn.operands[1].to_string() + ", " + insn.operands[2].to_string();
        }
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

    if (!operands.empty()) {
        result += " ";
        for (size_t i = 0; i < operands.size(); ++i) {
            if (i > 0) result += ", ";
            result += operands[i].to_string();
        }
    }

    return result;
}

// Format operand for disassembly
std::string Operand::to_string() const {
    switch (type) {
        case OperandType::Register: {
            return format_register(value, is_64bit, is_sp);
        }

        case OperandType::Immediate:
            {
                std::ostringstream oss;
                // Use decimal for small values (0-15), hex for larger
                if (value <= 15) {
                    oss << "#" << std::dec << value;
                } else {
                    oss << "#0x" << std::hex << value;
                }
                return oss.str();
            }

        case OperandType::SignedImmediate:
            {
                std::ostringstream oss;
                int32_t sval = static_cast<int32_t>(value);
                if (sval < 0) {
                    if (sval >= -15) {
                        oss << "#" << std::dec << sval;
                    } else {
                        oss << "#-0x" << std::hex << (-sval);
                    }
                } else {
                    if (sval <= 15) {
                        oss << "#" << std::dec << sval;
                    } else {
                        oss << "#0x" << std::hex << sval;
                    }
                }
                return oss.str();
            }

        case OperandType::VectorRegister:
            // is_64bit used to select Q prefix for 128-bit context (STP/LDP Q)
            if (is_64bit) return "q" + std::to_string(value);
            return format_vector_register(value, "");

        case OperandType::SVERegister:
            return "z" + std::to_string(value);

        case OperandType::PredicateRegister:
            return "p" + std::to_string(value);

        case OperandType::SMETileRegister:
            return "za" + std::to_string(value);

        case OperandType::MemoryBase:
            // [Xn|SP]
            return "[" + format_register(base_reg, true, true) + "]";

        case OperandType::MemoryOffset:
            // [Xn|SP, #offset]
            if (offset == 0) {
                return "[" + format_register(base_reg, true, true) + "]";
            }
            {
                std::ostringstream oss;
                oss << "[" << format_register(base_reg, true, true) << ", #";
                if (offset < 0) {
                    if (offset >= -15) oss << std::dec << offset;
                    else oss << "-0x" << std::hex << (-offset);
                } else {
                    if (offset <= 15) oss << std::dec << offset;
                    else oss << "0x" << std::hex << offset;
                }
                oss << "]";
                return oss.str();
            }

        case OperandType::MemoryPreIndex:
            // [Xn|SP, #offset]!
            {
                std::ostringstream oss;
                oss << "[" << format_register(base_reg, true, true) << ", #";
                if (offset < 0) {
                    if (offset >= -15) oss << std::dec << offset;
                    else oss << "-0x" << std::hex << (-offset);
                } else {
                    if (offset <= 15) oss << std::dec << offset;
                    else oss << "0x" << std::hex << offset;
                }
                oss << "]!";
                return oss.str();
            }

        case OperandType::MemoryPostIndex:
            // [Xn|SP], #offset
            {
                std::ostringstream oss;
                oss << "[" << format_register(base_reg, true, true) << "], #";
                if (offset < 0) {
                    if (offset >= -15) oss << std::dec << offset;
                    else oss << "-0x" << std::hex << (-offset);
                } else {
                    if (offset <= 15) oss << std::dec << offset;
                    else oss << "0x" << std::hex << offset;
                }
                return oss.str();
            }

        case OperandType::MemoryRegOffset:
            // [Xn|SP, Rm{, extend {#amount}}]
            {
                std::string result = "[" + format_register(base_reg, true, true) + ", ";
                result += format_register(index_reg, true, false);
                if (extend != 0 || amount != 0) {
                    const char* extends[] = {"UXTB", "UXTH", "UXTW", "UXTX",
                                             "SXTB", "SXTH", "SXTW", "SXTX"};
                    if (extend < 8) {
                        result += ", " + std::string(extends[extend]);
                        if (amount != 0) {
                            result += " #" + std::to_string(amount);
                        }
                    }
                }
                result += "]";
                return result;
            }

        case OperandType::SystemRegister:
            return "s" + std::to_string(value);

        case OperandType::Condition:
            // Format condition codes
            {
                const char* conds[] = {"eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc",
                                       "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"};
                if (value < 16) return conds[value];
                return "cond" + std::to_string(value);
            }

        case OperandType::Shift:
            {
                // value encodes shift_type in bits [9:8] and amount in bits [7:0]
                const char* shifts[] = {"lsl", "lsr", "asr", "ror"};
                uint32_t shift_type = (value >> 8) & 0x3;
                uint32_t shift_amount = value & 0xFF;
                if (value < 4) return shifts[value];  // Legacy: bare shift type
                return std::string(shifts[shift_type]) + " #" + std::to_string(shift_amount);
            }

        case OperandType::Extend:
            {
                const char* extends[] = {"uxtb", "uxth", "uxtw", "uxtx",
                                         "sxtb", "sxth", "sxtw", "sxtx"};
                if (value < 8) return extends[value];
                return "ext" + std::to_string(value);
            }

        case OperandType::Index:
            return "[" + std::to_string(value) + "]";

        case OperandType::Label:
            // Format as signed hex offset
            {
                std::ostringstream oss;
                int32_t sval = static_cast<int32_t>(value);
                if (sval < 0) oss << "#-0x" << std::hex << (-sval);
                else oss << "#0x" << std::hex << sval;
                return oss.str();
            }

        case OperandType::Relative:
            // Format as PC-relative offset (.+0x10 or .-0x10)
            {
                std::ostringstream oss;
                int32_t sval = static_cast<int32_t>(value);
                if (sval < 0) oss << ".-0x" << std::hex << (-sval);
                else oss << ".+0x" << std::hex << sval;
                return oss.str();
            }

        case OperandType::Pattern:
            // SVE pattern specifier
            return "#" + std::to_string(value);

        case OperandType::Prefetch:
            // Prefetch operation
            {
                const char* prfops[] = {"pldl1keep", "pldl1strm", "pldl2keep", "pldl2strm",
                                        "pldl3keep", "pldl3strm", "#6", "#7",
                                        "plil1keep", "plil1strm", "plil2keep", "plil2strm",
                                        "plil3keep", "plil3strm", "#14", "#15",
                                        "pstl1keep", "pstl1strm", "pstl2keep", "pstl2strm",
                                        "pstl3keep", "pstl3strm", "#22", "#23"};
                if (value < 24) return prfops[value];
                return "#" + std::to_string(value);
            }

        case OperandType::Barrier:
            // Barrier option
            {
                const char* barriers[] = {"#0", "oshld", "oshst", "osh",
                                          "#4", "nshld", "nshst", "nsh",
                                          "#8", "ishld", "ishst", "ish",
                                          "#12", "ld", "st", "sy"};
                if (value < 16) return barriers[value];
                return "#" + std::to_string(value);
            }

        default:
            return std::to_string(value);
    }
}
#endif // !VEDA64_NO_STRINGS

// Unified decode function - dispatches to format-based group decoders
std::optional<Instruction> decode(uint32_t insn) {
    return decode_format(insn);
}

} // namespace veda64
