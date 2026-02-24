// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))

#include <cstdint>
#include <cstddef>

namespace veda64 {
namespace hook {

// Forward declarations
struct HookContext;
struct Trampoline;

// Hook status codes
enum class HookStatus {
    Success = 0,
    NotInitialized,
    InvalidTarget,
    InvalidDetour,
    AllocationFailed,
    ProtectionFailed,
    DisassemblyFailed,
    RelocationFailed,
    InstructionTooComplex,
    HookAlreadyInstalled,
    HookNotFound,
    HookDisabled,
    InternalError
};

#ifndef VEDA64_NO_STRINGS
// Convert status to string
const char* status_to_string(HookStatus status);
#endif

// Hook handle - opaque pointer to hook context
using HookHandle = HookContext*;

// Hook configuration options
struct HookConfig {
    // Minimum bytes to overwrite (default: 16 for LDR+BR sequence)
    size_t min_hook_size = 16;

    // Maximum instructions to relocate in trampoline
    size_t max_relocated_insns = 32;

    // Enable thread-safe hook installation (uses suspend/resume)
    bool thread_safe = true;

    // Preserve CPU flags across hook
    bool preserve_flags = true;

    // Allow hooking of already-hooked functions (chain hooks)
    bool allow_chain = false;
};

// Global configuration
void set_config(const HookConfig& config);
HookConfig get_config();

// Initialize the hooking subsystem
// Must be called before any other hook functions
HookStatus initialize();

// Shutdown the hooking subsystem
// Automatically removes all installed hooks
void shutdown();

// Check if hooking subsystem is initialized
bool is_initialized();

// Internal install (void* interface)
HookStatus install_impl(void* target, void* detour, void** original, HookHandle* handle);

// Install an inline hook (starts disabled — call enable() to activate)
// Type-safe: target and detour must have matching signatures.
// original receives a callable trampoline to the original function.
// Usage: hook::install(&MessageBoxA, &my_detour, &original_ptr, &handle);
template<typename Fn>
HookStatus install(Fn* target, Fn* detour, Fn** original, HookHandle* handle = nullptr) {
    return install_impl(reinterpret_cast<void*>(target),
                        reinterpret_cast<void*>(detour),
                        reinterpret_cast<void**>(original), handle);
}

// Non-template overload for raw void* pointers
inline HookStatus install(void* target, void* detour, void** original, HookHandle* handle = nullptr) {
    return install_impl(target, detour, original, handle);
}

// Remove a previously installed hook
// Restores original bytes and frees trampoline
HookStatus remove(HookHandle handle);

// Remove all hooks
void remove_all();

// Enable a disabled hook
HookStatus enable(HookHandle handle);

// Disable a hook (restores original bytes but keeps trampoline)
HookStatus disable(HookHandle handle);

// Enable all installed hooks
HookStatus enable_all();

// Disable all installed hooks
HookStatus disable_all();

// Check if hook is enabled
bool is_enabled(HookHandle handle);

// Get hook information
void* get_target(HookHandle handle);
void* get_detour(HookHandle handle);
void* get_trampoline(HookHandle handle);

// Get number of bytes overwritten at target
size_t get_hook_size(HookHandle handle);

// Get number of instructions relocated to trampoline
size_t get_relocated_count(HookHandle handle);

#ifndef VEDA64_NO_STRINGS
// Debug: Dump hook information
void dump_hook(HookHandle handle);
#endif

// ============================================================================
// Low-level API for advanced usage
// ============================================================================

namespace detail {

// Generate a jump sequence to target address
// buffer: output buffer (must be at least 16 bytes)
// target: destination address
// Returns: number of bytes written
size_t generate_jump(uint8_t* buffer, void* target);

// Generate a call sequence (saves return address)
// buffer: output buffer (must be at least 16 bytes)
// target: destination address
// Returns: number of bytes written
size_t generate_call(uint8_t* buffer, void* target);

// Check if an instruction is PC-relative
bool is_pc_relative(uint32_t insn);

// Check if an instruction can be safely relocated
bool can_relocate(uint32_t insn);

// Detect Windows ARM64 syscall stub pattern (SVC + RET + 0 + 0)
bool is_syscall_stub(const uint8_t* target);

// Resolve forwarding stubs (follows unconditional B chains)
void* resolve_forwarding_stub(void* target);

// Relocate a single instruction to a new address
bool relocate_instruction(
    uint32_t insn,
    uint64_t old_pc,
    uint64_t new_pc,
    uint32_t* out_insn,
    size_t* out_count
);

// Allocate executable memory for trampolines
void* alloc_executable(size_t size);

// Free executable memory
void free_executable(void* ptr, size_t size);

// Make memory region writable temporarily
// Returns previous protection value
uint32_t make_writable(void* addr, size_t size);

// Restore memory protection
void restore_protection(void* addr, size_t size, uint32_t old_protect);

// Flush instruction cache
void flush_icache(void* addr, size_t size);

// Suspend all threads except current (for safe hook installation)
void suspend_threads();

// Resume all suspended threads
void resume_threads();

} // namespace detail

} // namespace hook
} // namespace veda64

#endif // !VEDA64_NO_HOOKS && (_WIN32 || VEDA64_HOOK_SUPPORT)
