// veda64 API Hooking for Windows ARM64
// Inline hooking with automatic instruction relocation
// Auto-generated - do not edit
#pragma once

// Hook support is only available on Windows
#if defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT)

#include "veda64.hpp"
#include <cstdint>
#include <cstddef>
#include <memory>

#ifdef _WIN32
#define VEDA64_HOOK_API __declspec(dllexport)
#else
#define VEDA64_HOOK_API
#endif

namespace veda64 {
namespace Hook {

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
VEDA64_HOOK_API const char* status_to_string(HookStatus status);
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
VEDA64_HOOK_API void set_config(const HookConfig& config);
VEDA64_HOOK_API HookConfig get_config();

// Initialize the hooking subsystem
// Must be called before any other hook functions
VEDA64_HOOK_API HookStatus initialize();

// Shutdown the hooking subsystem
// Automatically removes all installed hooks
VEDA64_HOOK_API void shutdown();

// Check if hooking subsystem is initialized
VEDA64_HOOK_API bool is_initialized();

// Install an inline hook
// target: address of function to hook
// detour: address of your hook function
// original: receives pointer to trampoline for calling original function
// Returns: handle to the hook, or nullptr on failure
VEDA64_HOOK_API HookHandle install(void* target, void* detour, void** original);

// Install hook with status output
VEDA64_HOOK_API HookHandle install_ex(void* target, void* detour, void** original, HookStatus* status);

// Remove a previously installed hook
// Restores original bytes and frees trampoline
VEDA64_HOOK_API HookStatus remove(HookHandle handle);

// Remove all hooks
VEDA64_HOOK_API void remove_all();

// Enable a disabled hook
VEDA64_HOOK_API HookStatus enable(HookHandle handle);

// Disable a hook (restores original bytes but keeps trampoline)
VEDA64_HOOK_API HookStatus disable(HookHandle handle);

// Check if hook is enabled
VEDA64_HOOK_API bool is_enabled(HookHandle handle);

// Get hook information
VEDA64_HOOK_API void* get_target(HookHandle handle);
VEDA64_HOOK_API void* get_detour(HookHandle handle);
VEDA64_HOOK_API void* get_trampoline(HookHandle handle);

// Get number of bytes overwritten at target
VEDA64_HOOK_API size_t get_hook_size(HookHandle handle);

// Get number of instructions relocated to trampoline
VEDA64_HOOK_API size_t get_relocated_count(HookHandle handle);

#ifndef VEDA64_NO_STRINGS
// Debug: Dump hook information
VEDA64_HOOK_API void dump_hook(HookHandle handle);
#endif

// ============================================================================
// Low-level API for advanced usage
// ============================================================================

namespace Detail {

// ARM64 jump sequences
// Minimum hook size is 16 bytes (LDR X16, [PC+8]; BR X16; .quad target)

// Generate a jump sequence to target address
// buffer: output buffer (must be at least 16 bytes)
// target: destination address
// Returns: number of bytes written
VEDA64_HOOK_API size_t generate_jump(uint8_t* buffer, void* target);

// Generate a call sequence (saves return address)
// buffer: output buffer (must be at least 20 bytes)
// target: destination address
// Returns: number of bytes written
VEDA64_HOOK_API size_t generate_call(uint8_t* buffer, void* target);

// Check if an instruction is PC-relative
VEDA64_HOOK_API bool is_pc_relative(uint32_t insn);

// Check if an instruction can be safely relocated
VEDA64_HOOK_API bool can_relocate(uint32_t insn);

// Relocate a single instruction to a new address
// insn: original instruction encoding
// old_pc: original PC value
// new_pc: new PC value
// out_insn: receives relocated instruction(s)
// out_count: receives number of output instructions
// Returns: true if relocation successful
VEDA64_HOOK_API bool relocate_instruction(
    uint32_t insn,
    uint64_t old_pc,
    uint64_t new_pc,
    uint32_t* out_insn,
    size_t* out_count
);

// Allocate executable memory for trampolines
VEDA64_HOOK_API void* alloc_executable(size_t size);

// Free executable memory
VEDA64_HOOK_API void free_executable(void* ptr, size_t size);

// Make memory region writable temporarily
// Returns previous protection value
VEDA64_HOOK_API uint32_t make_writable(void* addr, size_t size);

// Restore memory protection
VEDA64_HOOK_API void restore_protection(void* addr, size_t size, uint32_t old_protect);

// Flush instruction cache
VEDA64_HOOK_API void flush_icache(void* addr, size_t size);

// Suspend all threads except current (for safe hook installation)
VEDA64_HOOK_API void suspend_threads();

// Resume all suspended threads
VEDA64_HOOK_API void resume_threads();

} // namespace Detail

// ============================================================================
// Convenience macros
// ============================================================================

// Helper macro to declare original function pointer
#define VEDA64_DECLARE_ORIGINAL(name, ret, ...) \
    using name##_t = ret(__VA_ARGS__); \
    static name##_t* name##_original = nullptr;

// Helper macro to install hook
#define VEDA64_INSTALL_HOOK(name, target) \
    veda64::Hook::install((void*)(target), (void*)&name##_hook, (void**)&name##_original)

// Helper macro to call original function
#define VEDA64_CALL_ORIGINAL(name, ...) \
    (name##_original ? name##_original(__VA_ARGS__) : (decltype(name##_original(__VA_ARGS__)))0)

} // namespace Hook
} // namespace veda64

#endif // _WIN32 || VEDA64_HOOK_SUPPORT
