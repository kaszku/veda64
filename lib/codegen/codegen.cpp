// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include <codegen/emitter.hpp>

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
    // Back-patch all pending references
    for (auto& p : label.m_patches) {
        int32_t diff = static_cast<int32_t>(label.m_bound_offset - p.insn_offset);
        uint32_t insn;
        std::memcpy(&insn, m_write_ptr + p.insn_offset, 4);
        switch (p.type) {
        case PatchType::Imm26:
            insn = (insn & 0xFC000000U) | ((diff >> 2) & 0x03FFFFFFU);
            break;
        case PatchType::Imm19:
            insn = (insn & 0xFF00001FU) | (((diff >> 2) & 0x7FFFF) << 5);
            break;
        case PatchType::Imm14:
            insn = (insn & 0xFFF8001FU) | (((diff >> 2) & 0x3FFF) << 5);
            break;
        case PatchType::Adr21: {
            uint32_t immlo = diff & 0x3;
            uint32_t immhi = (diff >> 2) & 0x7FFFF;
            insn = (insn & 0x9F00001FU) | (immlo << 29) | (immhi << 5);
            break;
        }
        }
        std::memcpy(m_write_ptr + p.insn_offset, &insn, 4);
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
