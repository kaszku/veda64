# veda64

A comprehensive ARM64 (AArch64) instruction encoder and decoder library with full support for the ARMv9 instruction set.

## Features

- **Complete ARM64 instruction support**: 2,292 instructions across 4,623 encoding variants
- **Encoder/Decoder**: Encode instructions to binary and decode binary to instructions
- **Instruction classes**:
  - Core A64 (general, float, fpsimd, system)
  - Advanced SIMD (advsimd)
  - SVE/SVE2 (Scalable Vector Extension)
  - SME (Scalable Matrix Extension - mortlach, mortlach2)
- **Type-safe bitfield structures**: Direct mapping to ARM64 instruction formats
- **Disassembly**: Format decoded instructions as readable assembly
- **Alias-aware decoding**: `decode(insn, true)` returns preferred ARM mnemonics (MOV instead of ADD, CMP instead of SUBS, etc.) with correct operands
- **Text assembler**: Assemble ARM64 text to binary (`assemble("ADD X0, X1, X2")` → `0x8B020020`)
- **IR lifting**: P-code style intermediate representation with AST layer, simplification pass, and interpreter
- **JIT code generator**: xbyak/asmjit-style assembler API with typed registers, labels, and executable code emission
- **Inline hooking**: Windows ARM64 inline hooking with instruction relocation via NT syscalls
- **Instruction relocation**: Relocate PC-relative instructions to new addresses
- **Control flow analysis**: Classify instruction flow, walk basic blocks, build CFGs
- **Python bindings**: Full API access via nanobind (decode, assemble, IR, codegen, hooking)
- **Rust bindings**: Safe FFI via cxx (decode, assemble, IR)
- **Comprehensive test suite**: CTest-integrated unit tests for all instruction classes
- **CMake build system**: Cross-platform build configuration

## ⚠️ Disclaimer

While this library has been designed with correctness in mind and validated against reference disassemblers, it should be thoroughly tested before use in production systems. Use at your own risk.

## Project Structure

```
veda64/
├── include/
│   ├── veda64.hpp              # Main library header
│   ├── veda64/
│   │   ├── ir.hpp              # IR lifting + interpreter API
│   │   ├── relocation.hpp      # Instruction relocation API
│   │   ├── branch_follow.hpp   # Control flow analysis API
│   │   ├── assembler.hpp       # Text assembler API
│   │   └── *.hpp               # Type headers (operand, mnemonic, etc.)
│   ├── codegen/
│   │   ├── codegen.hpp         # Umbrella include for JIT assembler
│   │   ├── emitter.hpp         # CodeGenerator class + instruction methods
│   │   ├── registers.hpp       # Typed register structs (XReg, WReg, etc.)
│   │   ├── memory.hpp          # Memory operand helpers (ptr, pre, post)
│   │   └── label.hpp           # Label class for branch resolution
│   ├── hook.hpp                # Inline hooking API (Windows)
│   └── format/                 # Format-based decoder headers
│       └── *.hpp               # Per-encoding-group decoders
├── lib/                        # Implementation files
│   ├── core/
│   │   └── veda64.cpp          # Decode, to_string, mnemonic tables
│   ├── hook/
│   │   ├── hook.cpp            # Inline hooking (Windows ARM64)
│   │   ├── relocation.cpp      # Instruction relocation
│   │   └── branch_follow.cpp   # Control flow analysis
│   ├── assembler/
│   │   └── assembler.cpp       # Text assembler implementation
│   ├── codegen/
│   │   ├── codegen.cpp         # Buffer management, I-cache flush, labels
│   │   └── emitter.cpp         # Instruction method implementations
│   ├── ir/                     # IR subsystem
│   │   ├── ir.cpp              # Lift dispatch, simplify, interpreter
│   │   ├── ir_lift.cpp         # Template interpreters (28 templates)
│   │   └── ir_tables.cpp       # 4,623-entry encoding → IR table
│   └── format/                 # Format-based decoder sources
│       └── *.cpp
├── test/                       # Test suite
│   ├── CMakeLists.txt
│   ├── test_reference.cpp      # Reference disassembly tests
│   ├── test_ir.cpp             # IR lifting + interpreter tests
│   ├── test_codegen.cpp        # Codegen encode/decode roundtrip tests
│   ├── test_codegen_run.cpp    # Codegen end-to-end execution tests
│   ├── test_aliases.cpp        # ARM architectural alias tests
│   ├── test_functional.cpp     # Functional validation (CLZ, RBIT, BFI, etc.)
│   ├── test_branch_follow.cpp  # Control flow analysis tests
│   ├── test_hook.cpp           # Inline hooking tests
│   └── hook_examples.cpp       # Hook usage examples
├── examples/
│   ├── decode.cpp              # Decoding and disassembly
│   ├── encode.cpp              # Encoding instructions
│   ├── ir.cpp                  # IR lifting and interpreter
│   ├── codegen.cpp             # JIT code generation
│   ├── codegen_examples.cpp    # Advanced codegen (SIMD, atomics, bitfield)
│   └── hook.cpp                # Inline hooking (Windows ARM64)
├── tools/
│   ├── veda64-disasm.cpp       # Disassembler CLI tool
│   └── veda64-interp.cpp       # IR interpreter CLI tool
├── rust/
│   └── veda64/                # Rust bindings (cxx-based)
│       ├── Cargo.toml
│       └── src/
│           ├── lib.rs         # High-level Rust API
│           ├── bridge.rs      # cxx bridge declarations
│           └── mnemonic.rs    # Mnemonic enum (1,521 variants)
├── CMakeLists.txt              # Root build configuration
├── LICENSE                     # MIT license
└── README.md
```

## Building

### Prerequisites

- CMake 3.14 or later
- C++17 compatible compiler (GCC, Clang, MSVC)

### Build Instructions

```bash
# Minimal build (library + disassembler only)
mkdir build && cd build
cmake ..
cmake --build .

# Build with string functions (disassembly output)
cmake -DVEDA64_STRINGS=ON ..

# Build with IR lifting and interpreter
cmake -DVEDA64_IR=ON ..

# Build with tests
cmake -DVEDA64_TESTS=ON ..
cmake --build .
ctest

# Build with hooking support (Windows only)
cmake -DVEDA64_HOOK=ON ..

# Build with JIT code generator
cmake -DVEDA64_CODEGEN=ON ..
```

### Build Everything (including Python bindings)

Python bindings require [vcpkg](https://vcpkg.io/) with nanobind:

```bash
# Install vcpkg if not already installed
git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh  # or bootstrap-vcpkg.bat on Windows

# Configure with all features enabled
mkdir build && cd build
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DVCPKG_OVERLAY_PORTS=../vcpkg_overlay_ports \
    -DVEDA64_STRINGS=ON \
    -DVEDA64_IR=ON \
    -DVEDA64_HOOK=ON \
    -DVEDA64_CODEGEN=ON \
    -DVEDA64_TESTS=ON \
    -DVEDA64_PYTHON=ON

cmake --build .
ctest
```

### CMake Options

| Option | Default | Description |
|--------|---------|-------------|
| `VEDA64_STRINGS` | `OFF` | Enable string functions (`to_string()`, `mnemonic_to_string()`, etc.) |
| `VEDA64_IR` | `OFF` | Enable IR lifting and interpreter support |
| `VEDA64_HOOK` | `OFF` | Enable inline hooking support (Windows only). Links `ntdll.lib` for NT syscalls. |
| `VEDA64_CODEGEN` | `OFF` | Enable JIT code generator / assembler API |
| `VEDA64_ASSEMBLER` | `OFF` | Enable text assembler (`assemble("ADD X0, X1, X2")`) |
| `VEDA64_TESTS` | `OFF` | Build the test executables |
| `VEDA64_PYTHON` | `OFF` | Build Python bindings via nanobind (requires vcpkg toolchain) |
| `VEDA64_EXAMPLES` | `OFF` | Build example programs (Windows ARM64 only) |

## Examples

The `examples/` directory contains runnable programs demonstrating each feature:

| File | Feature | Build Flags |
|------|---------|-------------|
| `decode.cpp` | Decoding, disassembly, operand inspection | `-DVEDA64_STRINGS=ON` |
| `encode.cpp` | Encoding instructions from field values | `-DVEDA64_STRINGS=ON` |
| `ir.cpp` | IR lifting, simplification, interpreter | `-DVEDA64_STRINGS=ON -DVEDA64_IR=ON` |
| `codegen.cpp` | JIT assembler: labels, memory, FP, fibonacci | `-DVEDA64_STRINGS=ON -DVEDA64_CODEGEN=ON` |
| `codegen_examples.cpp` | Advanced codegen: SIMD, atomics, bitfield, carry | `-DVEDA64_STRINGS=ON -DVEDA64_CODEGEN=ON` |
| `relocation.cpp` | Instruction relocation for PC-relative instructions | `-DVEDA64_STRINGS=ON` |
| `branch_follow.cpp` | Control flow analysis: classify flow, basic blocks, CFG | `-DVEDA64_STRINGS=ON` |
| `hook.cpp` | Inline hooking (Windows ARM64 only) | `-DVEDA64_HOOK=ON` |

```bash
cmake -DVEDA64_STRINGS=ON -DVEDA64_IR=ON -DVEDA64_CODEGEN=ON -DVEDA64_ASSEMBLER=ON -DVEDA64_HOOK=ON -DVEDA64_EXAMPLES=ON ..
cmake --build .
./examples/example_decode
```

## Usage

### Basic Example

```cpp
#include "veda64.hpp"
#include <iostream>

int main() {
    // Decode an instruction
    uint32_t binary = 0x8B020020;  // ADD X0, X1, X2

    auto result = veda64::decode(binary);
    if (result.has_value()) {
        std::cout << "Instruction: " << result->to_string() << std::endl;
        std::cout << "Mnemonic: " << static_cast<int>(result->mnemonic) << std::endl;
    }

    return 0;
}
```

### Decoding Instructions

```cpp
#include "veda64.hpp"

uint32_t binary = 0x91002820;  // ADD X0, X1, #0xA

auto result = veda64::decode(binary);
if (result.has_value()) {
    // Access instruction details
    std::cout << veda64::mnemonic_to_string(result->mnemonic) << std::endl;  // "ADD"
    std::cout << result->to_string() << std::endl;   // "ADD X0, X1, #10"

    // Access operands
    for (const auto& op : result->operands) {
        std::cout << op.to_string() << std::endl;
    }
}
```

### Decoding from bytes

```cpp
#include "veda64.hpp"

// ARM64 instructions are stored as little-endian in memory
uint8_t bytes[] = {0x20, 0x00, 0x02, 0x8B};  // ADD X0, X1, X2
auto result = veda64::decode(bytes);
```

### Inline Hooking (Windows ARM64)

The library includes an inline hooking engine for Windows ARM64. It uses NT syscalls directly (no Win32 API dependency) and supports thread-safe hook installation via `NtSuspendProcess`/`NtResumeProcess`.

Hooks are installed disabled by default — call `enable()` to activate.

```cpp
#include "veda64.hpp"

using namespace veda64;

// Original function pointer (filled by install)
static int (*original_add)(int, int) = nullptr;

// Your detour
static int hooked_add(int a, int b) {
    printf("add(%d, %d) called\n", a, b);
    return original_add(a, b);  // call original
}

int main() {
    hook::initialize();

    hook::HookHandle handle = nullptr;
    auto status = hook::install(&target_add, &hooked_add, &original_add, &handle);
    if (status == hook::HookStatus::Success) {
        hook::enable(handle);

        target_add(1, 2);  // prints "add(1, 2) called", returns 3

        hook::remove(handle);
    }

    hook::shutdown();  // removes all hooks
}
```

#### Hooking a Win32 API

```cpp
#include "veda64.hpp"
#include <windows.h>

using namespace veda64;

static BOOL (WINAPI *original_IsDebuggerPresent)() = nullptr;
static hook::HookHandle dbg_handle = nullptr;

static BOOL WINAPI hooked_IsDebuggerPresent() {
    return FALSE;  // always report "no debugger"
}

void install_anti_debug_hook() {
    hook::initialize();

    auto target = reinterpret_cast<decltype(&hooked_IsDebuggerPresent)>(
        GetProcAddress(GetModuleHandleA("kernel32.dll"), "IsDebuggerPresent"));
    hook::install(target, &hooked_IsDebuggerPresent, &original_IsDebuggerPresent, &dbg_handle);
    hook::enable(dbg_handle);

    // IsDebuggerPresent() now always returns FALSE
}
```

#### Profiling a function

```cpp
#include "veda64.hpp"
#include <windows.h>
#include <cstdio>

using namespace veda64;

static int (*original_compute)(int) = nullptr;
static hook::HookHandle prof_handle = nullptr;
static uint64_t total_ticks = 0, call_count = 0;

static int profiling_detour(int arg) {
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);
    int result = original_compute(arg);
    QueryPerformanceCounter(&end);
    total_ticks += end.QuadPart - start.QuadPart;
    call_count++;
    return result;
}

void install_profiler(int (*target)(int)) {
    hook::initialize();
    // Type-safe template — no casts needed when signatures match
    hook::install(target, &profiling_detour, &original_compute, &prof_handle);
    hook::enable(prof_handle);
}

void print_stats() {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    if (call_count > 0) {
        double avg_ms = (double)total_ticks / call_count / freq.QuadPart * 1000.0;
        printf("%llu calls, avg %.3f ms\n", call_count, avg_ms);
    }
}
```

### IR Lifting and Interpreter

The library includes a P-code style intermediate representation that lifts ARM64 instructions into a simplified IR for analysis and emulation.

```cpp
#include "veda64.hpp"
#include "veda64/ir.hpp"

using namespace veda64;

// Lift to flat IR ops
auto lifted = ir::lift(0x8B020020);  // ADD X0, X1, X2
if (lifted) {
    auto simplified = ir::simplify(*lifted);
    std::cout << ir::to_string(simplified) << std::endl;
}

// Lift to AST (expression tree)
auto ast = ir::lift_ast(0xEB020020, ir::IrDetail::Expanded);  // SUBS X0, X1, X2
if (ast) {
    std::cout << ir::to_string(*ast) << std::endl;
    // x0 <- sub(x1, x2)
    // N <- shr(sub(x1, x2), 63)
    // Z <- cmp_eq(sub(x1, x2), 0)
    // ...
}

// Execute against a simulated context
ir::Context ctx;
uint8_t mem[65536] = {};
ctx.memory = mem;
ctx.memory_size = sizeof(mem);
ctx.gpr[1] = 5;
ctx.gpr[2] = 3;

ir::execute(ctx, 0x8B020020);  // ADD X0, X1, X2
// ctx.gpr[0] == 8, ctx.pc == 4

ir::execute(ctx, 0xEB020020);  // SUBS X0, X1, X2
// ctx.flags[0] (N), ctx.flags[1] (Z), ctx.flags[2] (C), ctx.flags[3] (V)
```

#### IR Coverage

- **4,623/4,623** encoding variants classified into 28 IR templates (100%)
- ~50 opcodes: arithmetic, bitwise, shifts, compare, load/store, branch, FP, SIMD element ops
- SIMD element-level unrolling (vextract/vinsert per lane)
- Two detail levels: `Semantic` (high-level flag ops) and `Expanded` (fully decomposed)

#### Disassembler IR output

```bash
./veda64-disasm --ir 0x8B020020       # Flat IR ops
./veda64-disasm --ast 0xEB020020      # AST expression tree
./veda64-disasm --ast-expanded 0xEB020020  # AST with expanded flags
```

#### Interpreter CLI

```bash
./veda64-interp --x1=5 --x2=3 --dump 0x8B020020
#   x0  = 0x0000000000000008  (8)

./veda64-interp --x1=5 --x2=3 --dump 0xEB020020
#   x0  = 0x0000000000000002  (2)
#   flags: N=0 Z=0 C=1 V=0

./veda64-interp --sp=0x1000 --x1=0xDEADBEEF --step --dump 0xF90003E1 0xF94003E0
#   [0x0] str x1, [sp]
#   [0x4] ldr x0, [sp]
#   x0  = 0x00000000deadbeef
```

### JIT Code Generator

The library includes an xbyak/asmjit-style assembler that emits executable ARM64 code at runtime. It provides typed registers, memory operand helpers, automatic label resolution, and fluent method chaining — all instruction methods return `CodeGenerator&`.

```cpp
#include "codegen/codegen.hpp"
using namespace veda64::codegen;

// Generate: int sum_to(int n) { int s=0; for(int i=1; i<=n; i++) s+=i; return s; }
CodeGenerator code(4096);
Label loop, done;

code.mov(w1, uint32_t(0))         // s = 0
    .mov(w2, uint32_t(1))         // i = 1
    .bind(loop)
    .cmp(w2, w0)
    .b(Condition::GT, done)        // if i > n, break
    .add(w1, w1, w2)              // s += i
    .add(w2, w2, uint32_t(1))     // i++
    .b(loop)
    .bind(done)
    .mov(w0, w1)
    .ret()
    .ready();                      // flush I-cache, make executable

auto sum_to = code.get_code<int(*)(int)>();
sum_to(100);  // returns 5050
```

#### Supported Instructions

| Category | Instructions |
|----------|-------------|
| Arithmetic (imm) | `add`, `sub`, `adds`, `subs` |
| Arithmetic (reg) | `add`, `sub`, `adds`, `subs` (shifted/extended) |
| Logical (imm) | `and_`, `orr`, `eor`, `ands` (bitmask immediate) |
| Logical (reg) | `and_`, `orr`, `eor`, `orn`, `bic`, `ands` (shifted) |
| Move | `mov` (reg, imm16, large imm via MOVZ+MOVK), `movz`, `movn`, `movk` |
| Shift | `lsl`, `lsr`, `asr` (register) |
| Multiply/Divide | `mul`, `madd`, `sdiv`, `udiv` |
| Compare/Select | `cmp`, `cmn`, `tst`, `csel`, `cset` |
| Aliases | `neg`, `mvn` |
| Branch | `b`, `b(cc)`, `bl`, `br`, `blr`, `ret`, `cbz`, `cbnz`, `tbz`, `tbnz` |
| Load/Store GP | `ldr`, `str` (offset/pre/post/reg-offset), `ldrb`, `ldrh`, `strb`, `strh` |
| Load/Store signed | `ldrsb`, `ldrsh`, `ldrsw` |
| Load/Store pair | `ldp`, `stp` |
| Load literal | `ldr(reg, label)` |
| Scalar FP | `fadd`, `fsub`, `fmul`, `fdiv`, `fmov`, `fcmp` (single/double) |
| SIMD arithmetic | `add`, `sub`, `mul`, `addp`, `abs`, `neg`, `cnt` (vector) |
| SIMD logical | `and_`, `orr`, `eor`, `bic`, `not_`, `mvn` (vector) |
| SIMD compare | `cmeq`, `cmge`, `cmgt`, `cmhi`, `cmhs` + zero variants |
| SIMD shift | `shl`, `sshr`, `ushr` (vector by immediate) |
| SIMD element | `dup`, `ins`, `umov`, `movi` |
| Atomics | `cas`, `swp`, `ldadd`, `ldclr`, `ldset`, `ldeor`, `stlr`, `ldar`, `ldxr`, `stxr` |
| Bitfield | `bfi`, `bfxil`, `ubfx`, `sbfx`, `ubfiz`, `sbfiz`, `extr`, `clz`, `cls`, `rbit`, `rev` |
| Carry | `adc`, `adcs`, `sbc`, `sbcs` |
| Conditional | `ccmp`, `ccmn`, `csinc`, `csinv`, `csneg` |
| Extended multiply | `msub`, `mneg`, `ror`, `smull`, `umull`, `smulh`, `umulh` |
| System | `svc`, `brk`, `nop`, `adr`, `adrp` |

#### Memory Operands

```cpp
code.ldr(x0, ptr(x1, 8))       // [x1, #8]     offset
    .str(x0, pre(x1, -16))     // [x1, #-16]!  pre-index
    .ldr(x0, post(x1, 8))      // [x1], #8     post-index
    .ldr(x0, ptr(x1, x2, 3))   // [x1, x2, LSL #3]  register offset
    .stp(x0, x1, ptr(sp, 16)); // [sp, #16]    pair
```

#### Vector Register Arrangements

SIMD instructions use `VArr` — a vector register with arrangement qualifier:

```cpp
using namespace veda64::codegen;

CodeGenerator code(4096);

// Create arranged vector registers via methods on VReg
auto va = v0.s4();  // V0.4S
auto vb = v1.s4();  // V1.4S

code.add(va, vb, v2.s4())     // ADD V0.4S, V1.4S, V2.4S
    .mul(va, vb, v2.s4())     // MUL V0.4S, V1.4S, V2.4S
    .and_(v0.b16(), v1.b16(), v2.b16())  // AND V0.16B, V1.16B, V2.16B
    .shl(v0.s4(), v1.s4(), 3)  // SHL V0.4S, V1.4S, #3
    .cmeq(v0.s4(), v1.s4(), v2.s4());    // CMEQ V0.4S, V1.4S, V2.4S
```

### Instruction Relocation

Relocate PC-relative instructions to new addresses, useful for hooking trampolines and code patching:

```cpp
#include "veda64/relocation.hpp"

using namespace veda64;

uint32_t insn = 0x14000010;  // B #0x40
uint32_t out[4];
size_t count;

if (is_pc_relative(insn)) {
    // Check if relocation is possible
    if (can_relocate(insn)) {
        // Relocate from 0x1000 to 0x5000
        relocate_instruction(insn, 0x1000, 0x5000, out, &count);
        // out[0] now contains the adjusted branch
    }
}
```

| Function | Description |
|----------|-------------|
| `is_pc_relative(insn)` | Check if instruction uses PC-relative addressing |
| `can_relocate(insn)` | Check if instruction can be safely relocated |
| `relocate_instruction(insn, old_pc, new_pc, out, &count)` | Relocate with adjusted offsets |

### Control Flow Analysis

Walk basic blocks and build control flow graphs:

```cpp
#include "veda64/branch_follow.hpp"

using namespace veda64;

// Classify a single instruction's flow
auto flow = classify_flow(0x14000010, 0x1000);  // B #0x40 at address 0x1000
// flow.type == FlowType::Branch
// flow.target == 0x1040

// Walk a basic block
auto bb = walk_basic_block(0x1000, [](uint64_t addr) -> std::optional<uint32_t> {
    // Read instruction at addr from your memory source
    return read_insn_at(addr);
});
// bb.start, bb.end, bb.successors

// Build a full CFG
auto cfg = walk_cfg(0x1000, read_fn);
// cfg is a vector of BasicBlock
```

| Type | Description |
|------|-------------|
| `FlowType` | `Sequential`, `Branch`, `Call`, `ConditionalBranch`, `Return`, `Exception`, `Unknown` |
| `FlowInfo` | Flow type, instruction address, branch target, indirect flag |
| `BasicBlock` | Start/end addresses, successor list |
| `classify_flow(insn, addr)` | Classify single instruction |
| `walk_basic_block(start, reader)` | Walk one basic block |
| `walk_cfg(entry, reader)` | Build full control flow graph |

The hook engine overwrites 16 bytes at the target (LDR X16 + BR X16 + 8-byte address) and relocates the original instructions into an executable trampoline. PC-relative instructions (ADR, ADRP, B, BL, etc.) are automatically patched during relocation.

Key API functions:

| Function | Description |
|----------|-------------|
| `hook::initialize()` | Initialize the hooking subsystem (required first) |
| `hook::install(target, detour, &original, &handle)` | Install a hook (type-safe, starts disabled) |
| `hook::enable(handle)` / `hook::disable(handle)` | Enable/disable a specific hook |
| `hook::enable_all()` / `hook::disable_all()` | Enable/disable all installed hooks |
| `hook::remove(handle)` | Remove a hook and restore original bytes |
| `hook::remove_all()` | Remove all installed hooks |
| `hook::shutdown()` | Remove all hooks and shut down |

Configuration via `hook::set_config()`:

| Field | Default | Description |
|-------|---------|-------------|
| `thread_safe` | `true` | Suspend all threads during hook installation |
| `max_relocated_insns` | `32` | Maximum instructions to relocate to trampoline |
| `allow_chain` | `false` | Allow hooking already-hooked functions |

## Architecture

### Core Types

**Mnemonic** - Enumeration of 1,031 ARM64 instruction mnemonics
```cpp
enum class Mnemonic {
    ADD, SUB, LDR, STR, B, BL, ...
};
```

**OperandType** - Operand classification (24 types, `uint8_t`)
```cpp
enum class OperandType : uint8_t {
    Register, Immediate, SignedImmediate, Memory, MemoryRegOffset,
    MemorySVEOffset, Label, Relative, Shift, Extend, FloatImmediate,
    RegisterList, SMETileRegister, SystemRegister, PstateField,
    Prefetch, Barrier, Pattern, SVEMulImm, SVEVLxImm, SysOp,
    FixedSym, Unknown
};
```

**Register** - Typed register enum (332 values, `uint16_t`)
```cpp
enum class Register : uint16_t {
    W0, W1, ..., W30, WZR, WSP,      // 32-bit GP
    X0, X1, ..., X30, XZR, SP,       // 64-bit GP
    B0, ..., B31, H0, ..., H31,      // Scalar FP
    S0, ..., S31, D0, ..., D31,      // Scalar FP
    Q0, ..., Q31, V0, ..., V31,      // Vector
    Z0, ..., Z31,                     // SVE
    P0, ..., P15, PN0, ..., PN15,    // Predicate
    ZT0                               // SME
};
```

**Operand** - Compact 24-byte operand (private constructors, static factory methods)
```cpp
class Operand {
public:
    // Factory methods — the only way to create operands
    static Operand gp(uint32_t num, bool is_64, bool is_sp = false);
    static Operand vec(uint32_t num, Arrangement arr = Arrangement::None);
    static Operand sve(uint32_t num, Arrangement arr = Arrangement::None);
    static Operand imm(uint64_t val);
    static Operand memory_offset(uint32_t base, int32_t offset);
    // ... 30+ factory methods

    OperandType type;          // byte 0
    Arrangement arrangement;   // byte 1
    uint8_t extend;            // byte 2
    // ... total 24 bytes (static_assert enforced)
};
```

**Instruction** - Decoded instruction representation
```cpp
class Instruction {
    Mnemonic mnemonic;
    uint32_t raw_value;
    std::vector<Operand> operands;
    std::string to_string() const;
};
```

### Register Naming

- **64-bit general**: X0-X30, SP (stack pointer), XZR (zero register)
- **32-bit general**: W0-W30, WSP, WZR
- **Scalar FP**: B0-B31, H0-H31, S0-S31, D0-D31, Q0-Q31
- **Vector registers**: V0-V31 (with arrangement specifiers like .4S, .2D)
- **SVE registers**: Z0-Z31 (scalable vector), P0-P15/PN0-PN15 (predicate)
- **SME registers**: ZT0, ZA tiles

## Testing

The test suite validates all 4,623 encoding variants plus reference disassembly and inline hooking:

```bash
# Run all tests
ctest

# Verbose output
ctest -V
```

### Test Coverage

**Encoding Tests** (`test_control.cpp`, `test_dpimm.cpp`, `test_dpreg.cpp`, `test_ldst.cpp`, `test_simd_dp.cpp`, `test_sme.cpp`, `test_sve.cpp`, `test_reserved.cpp`)
- One test per encoding variant (4,623 total)
- Validates decode succeeds and mnemonic matches
- Verifies operand types where predictable

**UNDEF Tests** (`test_undef.cpp`)
- 442 test cases verifying Decode_UNDEF conditions return nullopt

**Reference Tests** (`test_reference.cpp`)
- Validates disassembly output against known-good strings
- 96 hand-verified reference instructions

**IR Tests** (`test_ir.cpp`)
- IR lifting tests for all 28 templates
- AST expression tree tests
- Interpreter end-to-end tests: arithmetic, flags (N/Z/C/V), division, CSEL, memory, branches

**Alias Tests** (`test_aliases.cpp`)
- 41 test cases validating ARM architectural aliases (MOV, CMP, CMN, NEG, TST, MUL, CSET, etc.)

**Functional Tests** (`test_functional.cpp`)
- Execution-level validation: CLZ, RBIT, REV, BFI, UBFX, SBFX, ADC, EXTR, MSUB

**Branch Follow Tests** (`test_branch_follow.cpp`)
- Flow classification, basic block walking, CFG construction

**CodeGen Tests** (`test_codegen.cpp`, `test_codegen_run.cpp`)
- Encode/decode roundtrip validation (arithmetic, branches, loads/stores, FP, MOV, SIMD, atomics, bitfield)
- 27+ end-to-end execution tests: identity, arithmetic, multiply (32/64-bit), loops (sum, factorial, fibonacci, GCD), conditionals (csel, cset, cbz, tbz), stack spill, LDP/STP, FP arithmetic, shifted register, nested branches, large immediate, multiple generators

**Hook Tests** (`test_hook.cpp`)
- Tests inline hooking of NT syscalls (NtClose, NtQueryVirtualMemory)
- Validates hook installation, enable/disable, and removal

## Instruction Statistics

| Class      | Instructions | Description                    |
|------------|--------------|--------------------------------|
| general    | 435          | Core A64 (add, sub, load, etc) |
| sve        | 514          | Scalable Vector Extension      |
| sve2       | 432          | SVE2 instructions              |
| advsimd    | 384          | Advanced SIMD/NEON             |
| mortlach2  | 317          | SME2 matrix operations         |
| system     | 75           | System control                 |
| float      | 66           | Floating-point                 |
| mortlach   | 34           | SME matrix operations          |
| fpsimd     | 17           | FP/SIMD scalar                 |
| unknown    | 18           | Miscellaneous                  |
| **Total**  | **2,292**    |                                |

### Encoding Coverage

- **Total encoding variants**: 4,623
- **Unique instruction patterns**: 4,471 (96.7%)
- **Architectural aliases**: 152 (3.3%)
- **Architectural aliases**: resolved via `decode(insn, true)`

## Alias-Aware Decoding

The decoder supports alias-aware mode via `decode(insn, true)`, returning the preferred ARM mnemonic and adjusted operands:

```cpp
auto raw   = veda64::decode(0x910003FD);        // ADD X29, SP, #0
auto alias = veda64::decode(0x910003FD, true);   // MOV X29, SP (2 operands, no #0)
```

### Compile-Time Aliases (Unconditional)

When an encoding always represents an alias, the decoder returns the alias mnemonic directly:

- **Arithmetic**: CMP/SUBS, CMN/ADDS, NEG/SUB, NEGS/SUBS, NGC/SBC, NGCS/SBCS
- **Logical**: TST/ANDS, MVN/ORN, MOV/ORR (register), MOV/ADD (SP)
- **Move**: MOV/MOVZ, MOV/MOVN (with immediate computation), MOVS/ORR
- **Multiply**: MUL/MADD, MNEG/MSUB, SMULL/SMADDL, UMULL/UMADDL, SMNEGL/SMSUBL, UMNEGL/UMSUBL
- **Shift (register)**: LSL/LSLV, LSR/LSRV, ASR/ASRV, ROR/RORV
- **Shift (immediate)**: LSL/UBFM, LSR/UBFM, ASR/SBFM
- **Extend**: SXTB/SBFM, SXTH/SBFM, SXTW/SBFM, UXTB/UBFM, UXTH/UBFM
- **Bitfield**: BFI/BFM, BFXIL/BFM, BFC/BFM, SBFIZ/SBFM, SBFX/SBFM, UBFIZ/UBFM, UBFX/UBFM (with lsb/width computation)
- **Conditional**: CSET/CSINC, CSETM/CSINV (with condition inversion)
- **Barriers**: SSBB/DSB, PSSBB/DSB
- **SIMD**: MVN/NOT

### Runtime Aliases (Conditional)

Some aliases apply only when specific fields match at decode time:

- **CINC/CSINC, CINV/CSINV, CNEG/CSNEG**: when `Rn == Rm` (with condition inversion)
- **MOV/ORR (SIMD vector)**: when `Rm == Rn` (operand reduced from 3 to 2)
- **ROR/EXTR**: when `Rn == Rm`
- **MOV/ORR (SVE vector)**: when `Zm == Zn`
- **MOV/AND (SVE predicate)**: when `Pm == Pg`

### Operand Adjustment

Alias decoding also transforms operands to match the alias form:
- **MOV from MOVZ/MOVN**: immediate shifted and/or inverted to final value
- **BFI/SBFIZ/UBFIZ**: `lsb = (regsize - immr) % regsize`, `width = imms + 1`
- **BFXIL/SBFX/UBFX**: `lsb = immr`, `width = imms - immr + 1`
- **CSET/CSETM/CINC/CINV/CNEG**: condition XOR'd to invert
- **MOV SIMD (ORR Rm==Rn)**: duplicate operand removed
- **MOV from ORR log_imm**: WZR operand removed (3→2 operands)
- **TST from ANDS**: XZR destination removed (3→2 operands)
- **LSL from UBFM**: shift computed from immr, imms dropped (4→3 operands)

## Python Bindings

The library includes Python bindings via [nanobind](https://github.com/wjakob/nanobind), exposing all library features:

```python
import veda64_py as v

# Decode an instruction
insn = v.decode(0x8B020020)
print(insn.mnemonic)      # Mnemonic.ADD
print(insn.to_string())   # "add x0, x1, x2"
print(len(insn.operands)) # 3

# Alias-aware decoding
alias = v.decode(0x910003FD, aliases=True)
print(alias.to_string())  # "mov x29, sp" (instead of "add x29, sp, #0")

# Text assembler (requires VEDA64_ASSEMBLER)
insn, ok, err = v.assemble("add x0, x1, x2")
print(f"0x{insn:08x}")    # 0x8b020020

# IR lifting (requires VEDA64_IR)
lifted = v.ir.lift(0x8B020020)
simplified = v.ir.simplify(lifted)
for op in simplified:
    print(op)

# Relocation
print(v.is_pc_relative(0x14000040))   # True (B instruction)
print(v.can_relocate(0x14000040))     # True

# Control flow classification
flow = v.classify_flow(0x14000010, 0x1000)
print(flow.type)    # FlowType.Branch
print(flow.target)  # 0x1040

# Walk basic blocks and CFG
code = {0x1000: 0xD2800001, 0x1004: 0x8B000021, 0x1008: 0xF1000400,
        0x100C: 0x54FFFFE1, 0x1010: 0xAA0103E0, 0x1014: 0xD65F03C0}
bb = v.walk_basic_block(0x1000, lambda addr: code.get(addr, 0))
blocks = v.walk_cfg(0x1000, lambda addr: code.get(addr, 0))
print(f"{len(blocks)} basic blocks discovered")

# JIT code generation (requires VEDA64_CODEGEN)
cg = v.codegen
gen = cg.CodeGenerator(4096)
gen.mov_x_imm(cg.x0, 42)
gen.add_x_imm(cg.x0, cg.x0, 8)
gen.ret()
gen.ready()
# Decode the generated instructions
data = gen.get_bytes()
for i in range(0, gen.size(), 4):
    insn = v.decode(int.from_bytes(data[i:i+4], 'little'))
    print(insn.to_string())

# Inline hooking (Windows only, requires VEDA64_HOOK)
if hasattr(v, 'hook'):
    v.hook.initialize()
    # status, original, handle = v.hook.install(target_addr, detour_addr)
    v.hook.shutdown()
```

### Building Python Bindings

Requires [vcpkg](https://vcpkg.io/) with the nanobind overlay port:

```bash
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DVCPKG_OVERLAY_PORTS=../vcpkg_overlay_ports \
    -DVEDA64_PYTHON=ON -DVEDA64_STRINGS=ON -DVEDA64_IR=ON -DVEDA64_CODEGEN=ON
cmake --build . --config Release
```

The built module (`veda64_py.pyd` on Windows, `veda64_py.so` on Linux) is placed in the build directory. Copy it to your Python path or use `PYTHONPATH`:

```bash
PYTHONPATH=build python -c "import veda64; print(veda64.decode(0x8B020020).to_string())"
```

## Rust Bindings

The library includes Rust bindings via [cxx](https://cxx.rs/), providing a safe, idiomatic Rust API over the C++ decoder.

```rust
use veda64::{decode, disassemble, Mnemonic, Operand, Condition};

// Decode an instruction
let insn = decode(0x8B020020).unwrap();  // ADD X0, X1, X2
println!("{}", insn);                     // "add x0, x1, x2"
assert_eq!(insn.mnemonic, Mnemonic::ADD);
assert_eq!(insn.operands.len(), 3);

// Inspect operands
for op in &insn.operands {
    match op {
        Operand::Register(reg) => println!("reg: {}", reg),
        Operand::Immediate(val) => println!("imm: {:#x}", val),
        Operand::Memory { base, offset, .. } => println!("[x{}, #{}]", base, offset),
        Operand::Shift { shift_type, amount } => println!("{:?} #{}", shift_type, amount),
        Operand::Label(off) => println!("label: {}", off),
        _ => {}
    }
}

// Quick disassembly (no struct allocation)
assert_eq!(disassemble(0xD65F03C0).as_deref(), Some("ret"));
assert_eq!(disassemble(0xD503201F).as_deref(), Some("nop"));

// Conditional branches
let insn = decode(0x54000040).unwrap();  // B.EQ
assert_eq!(insn.mnemonic, Mnemonic::B);
assert_eq!(insn.condition, Condition::EQ);

// Memory operands
let insn = decode(0xF9000420).unwrap();  // STR X0, [X1, #8]
if let Some(Operand::Memory { offset, .. }) = insn.operands.iter()
    .find(|op| matches!(op, Operand::Memory { .. })) {
    assert_eq!(*offset, 8);
}

// Mnemonic names
assert_eq!(Mnemonic::ADD.name(), "add");
assert_eq!(format!("{}", Mnemonic::LDR), "ldr");
```

### Adding to your project

```toml
[dependencies]
veda64 = { path = "path/to/veda64/rust/veda64" }
```

The crate compiles the C++ library from source via `cc` and `cxx-build` — no pre-built binaries or system dependencies needed beyond a C++17 compiler.

### Building and Testing

```bash
cargo build -p veda64
cargo test -p veda64     # 13 unit tests + 3 doc tests
```

### Test Coverage

The crate includes tests for:
- Arithmetic: ADD, SUB
- Branches: B, B.EQ (conditional)
- Loads/Stores: LDR, STR with memory offset verification
- System: NOP, RET
- Move: MOVZ
- Atomics: LDADD
- Invalid encodings
- Mnemonic display/formatting
- Disassembly string output

## License

See LICENSE file for details.

## Contributing

Contributions are welcome! Please open an issue or pull request on GitHub.

## References

- [ARM Architecture Reference Manual](https://developer.arm.com/documentation/ddi0487/latest)
- ARM A64 ISA XML Specification (2025-12)
