// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include <codegen/emitter.hpp>

#include <cstring>
#include <stdexcept>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace veda64 {
namespace codegen {

CodeGenerator::CodeGenerator(size_t capacity)
    : capacity_(capacity), offset_(0), owns_buffer_(true) {
#ifdef _WIN32
    write_ptr_ = static_cast<uint8_t*>(VirtualAlloc(nullptr, capacity,
        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));
    if (!write_ptr_) throw std::runtime_error("VirtualAlloc failed");
    exec_ptr_ = write_ptr_;
#else
    write_ptr_ = static_cast<uint8_t*>(mmap(nullptr, capacity,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    if (write_ptr_ == MAP_FAILED) throw std::runtime_error("mmap failed");
    exec_ptr_ = write_ptr_;
#endif
}

CodeGenerator::CodeGenerator(void* write_ptr, void* exec_ptr, size_t capacity)
    : write_ptr_(static_cast<uint8_t*>(write_ptr)),
      exec_ptr_(static_cast<uint8_t*>(exec_ptr)),
      capacity_(capacity), offset_(0), owns_buffer_(false) {}

CodeGenerator::~CodeGenerator() {
    if (owns_buffer_ && write_ptr_) {
#ifdef _WIN32
        VirtualFree(write_ptr_, 0, MEM_RELEASE);
#else
        munmap(write_ptr_, capacity_);
#endif
    }
}

void CodeGenerator::ready() {
#ifdef _WIN32
    if (owns_buffer_) {
        DWORD old_protect;
        VirtualProtect(exec_ptr_, offset_, PAGE_EXECUTE_READ, &old_protect);
    }
    FlushInstructionCache(GetCurrentProcess(), exec_ptr_, offset_);
#else
    if (owns_buffer_) {
        mprotect(exec_ptr_, capacity_, PROT_READ | PROT_EXEC);
    }
    __builtin___clear_cache(reinterpret_cast<char*>(exec_ptr_),
        reinterpret_cast<char*>(exec_ptr_ + offset_));
#endif
}

void CodeGenerator::emit(uint32_t insn) {
    if (offset_ + 4 > capacity_) throw std::runtime_error("codegen buffer overflow");
    std::memcpy(write_ptr_ + offset_, &insn, 4);
    offset_ += 4;
}

void CodeGenerator::patch(size_t offset, uint32_t insn) {
    std::memcpy(write_ptr_ + offset, &insn, 4);
}

void CodeGenerator::bind(Label& label) {
    label.bound_offset_ = offset_;
    // Back-patch all pending references
    for (auto& p : label.patches_) {
        int32_t diff = static_cast<int32_t>(label.bound_offset_ - p.insn_offset);
        uint32_t insn;
        std::memcpy(&insn, write_ptr_ + p.insn_offset, 4);
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
        std::memcpy(write_ptr_ + p.insn_offset, &insn, 4);
    }
    label.patches_.clear();
}

int32_t CodeGenerator::label_offset(Label& label, PatchType type) {
    if (label.is_bound()) {
        return static_cast<int32_t>(label.bound_offset_ - offset_);
    }
    label.patches_.push_back({offset_, type});
    return 0;  // placeholder
}

} // namespace codegen
} // namespace veda64
