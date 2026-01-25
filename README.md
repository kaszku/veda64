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
- **IR lifting**: P-code style intermediate representation with AST layer, simplification pass, and interpreter
- **JIT code generator**: xbyak/asmjit-style assembler API with typed registers, labels, and executable code emission
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
│   ├── core/                   # Core decode + enum tables
│   │   ├── veda64.cpp          # Main decode, mnemonic strings
│   │   └── *.cpp               # Barrier, pattern, prefetch, pstate, sysop, sysreg
│   ├── assembler/
│   │   └── assembler.cpp       # Text assembler
│   ├── codegen/
│   │   ├── codegen.cpp         # Buffer management, I-cache flush, labels
│   │   └── emitter.cpp         # Instruction method implementations
│   ├── hook/
│   │   ├── hook.cpp            # Inline hooking engine
│   │   ├── relocation.cpp      # Instruction relocation
│   │   └── branch_follow.cpp   # Branch tracing
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
│   ├── test_hook.cpp           # Inline hooking tests
│   └── hook_examples.cpp       # Hook usage examples
├── examples/
│   ├── decode.cpp              # Decoding and disassembly
│   ├── encode.cpp              # Encoding instructions
│   ├── ir.cpp                  # IR lifting and interpreter
│   ├── codegen.cpp             # JIT code generation
│   └── hook.cpp                # Inline hooking (Windows ARM64)
├── tools/
│   ├── veda64-disasm.cpp       # Disassembler CLI tool
│   └── veda64-interp.cpp       # IR interpreter CLI tool
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
| `VEDA64_CODEGEN` | `OFF` | Enable JIT code generator API |
| `VEDA64_ASSEMBLER` | `OFF` | Enable text assembler API (`assemble()`) |
| `VEDA64_TESTS` | `OFF` | Build the test executables |
| `VEDA64_PYTHON` | `OFF` | Build Python bindings via nanobind (requires vcpkg toolchain) |
| `VEDA64_EXAMPLES` | `OFF` | Build example programs (Windows ARM64 only) |

## Examples

The `examples/` directory contains runnable programs demonstrating each feature:

| File | Feature | Build Flags |
|------|---------|-------------|
| `decode.cpp` | Decoding, disassembly, operand inspection | `-DVEDA64_STRINGS=ON` |
| `encode.cpp` | Encoding instructions from field values | `-DVEDA64_STRINGS=ON` |
| `ir.cpp` | IR lifting, simplification, interpreter | `-DVEDA64_IR=ON` |
| `codegen.cpp` | JIT assembler: labels, memory, FP, fibonacci | `-DVEDA64_CODEGEN=ON` |
| `hook.cpp` | Inline hooking (Windows ARM64 only) | `-DVEDA64_HOOK=ON` |

```bash
cmake -DVEDA64_STRINGS=ON -DVEDA64_IR=ON -DVEDA64_CODEGEN=ON -DVEDA64_HOOK=ON -DVEDA64_EXAMPLES=ON ..
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

The library includes an xbyak/asmjit-style assembler that emits executable ARM64 code at runtime. It provides typed registers, memory operand helpers, and automatic label resolution for branches.

```cpp
#include "codegen/codegen.hpp"
using namespace veda64::codegen;

// Generate: int sum_to(int n) { int s=0; for(int i=1; i<=n; i++) s+=i; return s; }
CodeGenerator code(4096);
Label loop, done;

code.mov(w1, uint32_t(0));       // s = 0
code.mov(w2, uint32_t(1));       // i = 1
code.bind(loop);
code.cmp(w2, w0);
code.b(Condition::GT, done);     // if i > n, break
code.add(w1, w1, w2);            // s += i
code.add(w2, w2, uint32_t(1));   // i++
code.b(loop);
code.bind(done);
code.mov(w0, w1);
code.ret();
code.ready();                    // flush I-cache, make executable

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
| System | `svc`, `brk`, `nop`, `adr`, `adrp` |

#### Memory Operands

```cpp
ldr(x0, ptr(x1, 8));       // [x1, #8]     offset
str(x0, pre(x1, -16));     // [x1, #-16]!  pre-index
ldr(x0, post(x1, 8));      // [x1], #8     post-index
ldr(x0, ptr(x1, x2, 3));   // [x1, x2, LSL #3]  register offset
stp(x0, x1, ptr(sp, 16));  // [sp, #16]    pair
```

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

**CodeGen Tests** (`test_codegen.cpp`, `test_codegen_run.cpp`)
- Encode/decode roundtrip validation (arithmetic, branches, loads/stores, FP, MOV)
- 27 end-to-end execution tests: identity, arithmetic, multiply (32/64-bit), loops (sum, factorial, fibonacci, GCD), conditionals (csel, cset, cbz, tbz), stack spill, LDP/STP, FP arithmetic, shifted register, nested branches, large immediate, multiple generators

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

## Quality Assurance

### Known Aliases

The decoder correctly handles ARM architectural aliases where multiple mnemonics share the same encoding:

- **Shift operations**: ASR/ASRV, LSL/LSLV, LSR/LSRV, ROR/RORV
- **Bitfield operations**: BFC/BFM, BFI/BFM, BFXIL/BFM
- **Logical operations**: TST/ANDS, MVN/ORN
- **Arithmetic operations**: CMP/SUBS, CMN/ADDS, NEG/SUB
- **Move operations**: MOV/ORR, MOV/ADD

## License

See LICENSE file for details.

## Contributing

Contributions are welcome! Please open an issue or pull request on GitHub.

## References

- [ARM Architecture Reference Manual](https://developer.arm.com/documentation/ddi0487/latest)
