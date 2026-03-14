# veda64 TODO

## CodeGen (JIT Assembler)
- [x] SIMD/vector ops (ADD/SUB/MUL, AND/ORR/EOR/BIC/NOT, CMEQ/CMGE/CMGT/CMHI/CMHS, SHL/SSHR/USHR, DUP, INS, UMOV, MOVI, ADDP, ABS, NEG, CNT)
- [x] Atomic ops (CAS, SWP, LDADD, LDCLR, LDSET, LDEOR, STLR, LDAR, LDXR/STXR, LDAXR/STLXR, STADD/STCLR/STSET/STEOR)
- [x] Bitfield ops (BFI, BFXIL, UBFX, SBFX, UBFIZ, SBFIZ, EXTR, CLZ, CLS, RBIT, REV)
- [x] Carry ops (ADC, ADCS, SBC, SBCS, NGC)
- [x] Shift-by-immediate (LSL/LSR/ASR/ROR with immediate operand)
- [x] MSUB, MNEG, ROR, SMULL, UMULL, SMULH, UMULH
- [x] Conditional compare (CCMP, CCMN) + CSINC, CSINV, CSNEG, CINC, CINV, CNEG
- [x] Sign/zero extend aliases (SXTB, SXTH, SXTW, UXTB, UXTH)
- [x] TST immediate
- [x] Tests for all new codegen instruction groups (roundtrip + execution)
- [x] Add examples demonstrating new codegen features (examples/codegen_examples.cpp)

## Disassembler / Analysis
- [x] Branch following — walk a stream of instructions, following branch targets (classify_flow, walk_basic_block, walk_cfg)
- [x] Expose instruction relocation API (include/veda64/relocation.hpp, lib/relocation.cpp)
- [x] Update Python bindings for new public APIs (relocation + branch following)

## Tests
- [x] Add test_aliases.cpp (41 alias tests covering MOV, CMP, CMN, NEG, TST, MUL, CSET, etc.)
- [x] Functional validation for atomics, bitfield, SIMD (test_functional.cpp — CLZ, RBIT, REV, BFI, UBFX, SBFX, ADC, EXTR, MSUB)
- [x] Add tests and examples alongside every new feature

## Hook Engine
- [ ] Linux/macOS hooking support (currently Windows-only)

## Build / CI
- [x] Cross-platform CI (GitHub Actions: Ubuntu x64, Windows x64, macOS ARM64)
