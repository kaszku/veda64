// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include <codegen/emitter.hpp>
#include "veda64.hpp"
#include <format/format.hpp>

using namespace veda64::format;

#include <cstring>
#include <stdexcept>

#ifdef _WIN32
#include <cstdint>

// NT syscall declarations (linked via ntdll.lib)
#ifndef NtCurrentProcess
#define NtCurrentProcess() (reinterpret_cast<void*>(static_cast<intptr_t>(-1)))
#endif

// Memory protection constants
constexpr unsigned long CODEGEN_PAGE_READWRITE = 0x04;
constexpr unsigned long CODEGEN_PAGE_EXECUTE_READ = 0x20;
constexpr unsigned long CODEGEN_MEM_COMMIT = 0x1000;
constexpr unsigned long CODEGEN_MEM_RESERVE = 0x2000;
constexpr unsigned long CODEGEN_MEM_RELEASE = 0x8000;

extern "C" {
__declspec(dllimport) long __stdcall NtAllocateVirtualMemory(
    void* ProcessHandle, void** BaseAddress, unsigned long* ZeroBits,
    size_t* RegionSize, unsigned long AllocationType, unsigned long Protect);
__declspec(dllimport) long __stdcall NtFreeVirtualMemory(
    void* ProcessHandle, void** BaseAddress,
    size_t* RegionSize, unsigned long FreeType);
__declspec(dllimport) long __stdcall NtProtectVirtualMemory(
    void* ProcessHandle, void** BaseAddress,
    size_t* RegionSize, unsigned long NewProtect, unsigned long* OldProtect);
__declspec(dllimport) long __stdcall NtFlushInstructionCache(
    void* ProcessHandle, void* BaseAddress, size_t Length);
}
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace veda64 {
namespace codegen {

CodeGenerator::CodeGenerator(size_t capacity)
    : m_capacity(capacity), m_offset(0), m_owns_buffer(true) {
#ifdef _WIN32
    void* base = nullptr;
    size_t size = capacity;
    long status = NtAllocateVirtualMemory(NtCurrentProcess(), &base, nullptr,
        &size, CODEGEN_MEM_COMMIT | CODEGEN_MEM_RESERVE, CODEGEN_PAGE_READWRITE);
    if (status < 0) throw std::runtime_error("NtAllocateVirtualMemory failed");
    m_write_ptr = static_cast<uint8_t*>(base);
    m_exec_ptr = m_write_ptr;
#else
    m_write_ptr = static_cast<uint8_t*>(mmap(nullptr, capacity,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    if (m_write_ptr == MAP_FAILED) throw std::runtime_error("mmap failed");
    m_exec_ptr = m_write_ptr;
#endif
}

CodeGenerator::CodeGenerator(void* write_ptr, void* exec_ptr, size_t capacity)
    : m_write_ptr(static_cast<uint8_t*>(write_ptr)),
      m_exec_ptr(static_cast<uint8_t*>(exec_ptr)),
      m_capacity(capacity), m_offset(0), m_owns_buffer(false) {}

CodeGenerator::~CodeGenerator() {
    if (m_owns_buffer && m_write_ptr) {
#ifdef _WIN32
        void* base = m_write_ptr;
        size_t size = 0;
        NtFreeVirtualMemory(NtCurrentProcess(), &base, &size, CODEGEN_MEM_RELEASE);
#else
        munmap(m_write_ptr, m_capacity);
#endif
    }
}

CodeGenerator& CodeGenerator::ready() {
#ifdef _WIN32
    if (m_owns_buffer) {
        void* base = m_exec_ptr;
        size_t size = m_offset;
        unsigned long old_protect;
        NtProtectVirtualMemory(NtCurrentProcess(), &base, &size,
            CODEGEN_PAGE_EXECUTE_READ, &old_protect);
    }
    NtFlushInstructionCache(NtCurrentProcess(), m_exec_ptr, m_offset);
#else
    if (m_owns_buffer) {
        mprotect(m_exec_ptr, m_capacity, PROT_READ | PROT_EXEC);
    }
    __builtin___clear_cache(reinterpret_cast<char*>(m_exec_ptr),
        reinterpret_cast<char*>(m_exec_ptr + m_offset));
#endif
    return *this;
}

void CodeGenerator::emit(uint32_t insn) {
    if (m_offset + 4 > m_capacity) throw std::runtime_error("codegen buffer overflow");
    std::memcpy(m_write_ptr + m_offset, &insn, 4);
    m_offset += 4;
}

void CodeGenerator::patch(size_t offset, uint32_t insn) {
    std::memcpy(m_write_ptr + offset, &insn, 4);
}

CodeGenerator& CodeGenerator::bind(Label& label) {
    label.m_bound_offset = m_offset;
    // Back-patch all pending references using the proper encoders
    for (auto& p : label.m_patches) {
        int32_t diff = static_cast<int32_t>(label.m_bound_offset - p.insn_offset);
        uint32_t insn;
        std::memcpy(&insn, m_write_ptr + p.insn_offset, 4);
        auto decoded = decode(insn);
        if (!decoded) continue;  // should not happen
        uint32_t patched = insn;
        switch (p.type) {
        case PatchType::Imm26: {
            // B or BL — re-encode with correct offset
            if (decoded->mnemonic == Mnemonic::BL)
                patched = control::encode_bl_only_branch_imm(diff >> 2);
            else
                patched = control::encode_b_only_branch_imm(diff >> 2);
            break;
        }
        case PatchType::Imm19: {
            // B.cond, CBZ, CBNZ — decode fields, re-encode
            auto m = decoded->mnemonic;
            if (m == Mnemonic::CBZ || m == Mnemonic::CBNZ) {
                uint32_t rt = insn & 0x1F;
                uint32_t sf = (insn >> 31) & 1;
                if (m == Mnemonic::CBZ)
                    patched = sf ? control::encode_cbz_64_compbranch(rt, diff >> 2)
                                : control::encode_cbz_32_compbranch(rt, diff >> 2);
                else
                    patched = sf ? control::encode_cbnz_64_compbranch(rt, diff >> 2)
                                : control::encode_cbnz_32_compbranch(rt, diff >> 2);
            } else {
                // B.cond
                uint32_t cond = insn & 0xF;
                patched = control::encode_b_only_condbranch(cond, diff >> 2);
            }
            break;
        }
        case PatchType::Imm14: {
            // TBZ/TBNZ — extract rt, b5, b40, op and re-encode
            uint32_t rt = insn & 0x1F;
            uint32_t b40 = (insn >> 19) & 0x1F;
            uint32_t b5 = (insn >> 31) & 1;
            uint32_t op = (insn >> 24) & 1;
            if (op == 0)
                patched = control::encode_tbz_only_testbranch(rt, diff >> 2, b40, b5);
            else
                patched = control::encode_tbnz_only_testbranch(rt, diff >> 2, b40, b5);
            break;
        }
        case PatchType::Adr21: {
            // ADR/ADRP — extract rd and re-encode with split immhi/immlo
            uint32_t rd = insn & 0x1F;
            int32_t immlo = diff & 0x3;
            int32_t immhi = (diff >> 2) & 0x7FFFF;
            if (decoded->mnemonic == Mnemonic::ADRP)
                patched = dpimm::encode_adrp_only_pcreladdr(rd, immhi, immlo);
            else
                patched = dpimm::encode_adr_only_pcreladdr(rd, immhi, immlo);
            break;
        }
        }
        std::memcpy(m_write_ptr + p.insn_offset, &patched, 4);
    }
    label.m_patches.clear();
    return *this;
}

int32_t CodeGenerator::label_offset(Label& label, PatchType type) {
    if (label.is_bound()) {
        return static_cast<int32_t>(label.m_bound_offset - m_offset);
    }
    label.m_patches.push_back({m_offset, type});
    return 0;  // placeholder
}

} // namespace codegen
} // namespace veda64
