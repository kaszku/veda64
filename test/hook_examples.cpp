// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit


#include "veda64.hpp"

#if !defined(VEDA64_NO_HOOKS) && defined(_WIN32) && (defined(_M_ARM64) || defined(__aarch64__))
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <mutex>
#include <windows.h>

namespace veda64 {
namespace examples {

// ============================================================================
// Example 1: LoggingHook
// Intercepts function calls and logs parameters with timestamps
// ============================================================================
namespace logging_hook {

struct LogEntry {
    std::chrono::system_clock::time_point timestamp;
    int arg1, arg2, result;
};

static int (*original_func)(int, int) = nullptr;
static hook::HookHandle hook_handle = nullptr;
static std::mutex log_mutex;
static std::vector<LogEntry> call_log;

static int detour_func(int a, int b) {
    auto start = std::chrono::system_clock::now();
    int result = original_func(a, b);
    std::lock_guard<std::mutex> lock(log_mutex);
    call_log.push_back({start, a, b, result});
    return result;
}

using TargetFunc = int (*)(int, int);

bool install(TargetFunc target) {
    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);
    if (status != hook::HookStatus::Success) return false;
    return hook::enable(hook_handle) == hook::HookStatus::Success;
}

std::vector<LogEntry> uninstall() {
    if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; }
    std::lock_guard<std::mutex> lock(log_mutex);
    auto result = std::move(call_log);
    call_log.clear();
    return result;
}

void clear_log() {
    std::lock_guard<std::mutex> lock(log_mutex);
    call_log.clear();
}

} // namespace logging_hook

// ============================================================================
// Example 2: ValidationHook
// Validates allocation sizes and rejects oversized requests
// ============================================================================
namespace validation_hook {

struct Stats { size_t total_bytes, alloc_count, reject_count; };

static void* (*original_alloc)(size_t) = nullptr;
static hook::HookHandle hook_handle = nullptr;
static size_t max_alloc_size = 100 * 1024 * 1024;
static bool log_allocations = false;
static size_t total_allocated = 0;
static size_t allocation_count = 0;
static size_t rejected_count = 0;

static void* detour_alloc(size_t size) {
    if (size > max_alloc_size) {
        rejected_count++;
        if (log_allocations) std::cerr << "[ValidationHook] Rejected: " << size << std::endl;
        return Arrangement::None;
    }
    void* result = original_alloc(size);
    if (result) { total_allocated += size; allocation_count++; }
    return result;
}

using AllocFunc = void* (*)(size_t);

bool install(AllocFunc target, size_t max_size) {
    max_alloc_size = max_size;
    auto status = hook::install(target, &detour_alloc, &original_alloc, &hook_handle);
    if (status != hook::HookStatus::Success) return false;
    return hook::enable(hook_handle) == hook::HookStatus::Success;
}

void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }
void set_logging(bool enable) { log_allocations = enable; }
Stats get_stats() { return {total_allocated, allocation_count, rejected_count}; }
void reset_stats() { total_allocated = allocation_count = rejected_count = 0; }

} // namespace validation_hook

// ============================================================================
// ReturnModifyHook Implementation
// ============================================================================
namespace return_modify_hook {

static BOOL (WINAPI *original_func)() = nullptr;
static hook::HookHandle hook_handle = nullptr;
static bool force_result = false;
static BOOL forced_value = FALSE;

static BOOL WINAPI detour_func() {
    return force_result ? forced_value : original_func();
}

using IsDebuggerPresent_t = BOOL (WINAPI *)();

bool install() {
    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (!kernel32) return false;
    auto target = reinterpret_cast<IsDebuggerPresent_t>(GetProcAddress(kernel32, "IsDebuggerPresent"));
    if (!target) return false;
    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);
    if (status != hook::HookStatus::Success) return false;
    return hook::enable(hook_handle) == hook::HookStatus::Success;
}

void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }
void set_forced_result(bool enable, BOOL value) { force_result = enable; forced_value = value; }

} // namespace return_modify_hook

// ============================================================================
// StringHook Implementation
// ============================================================================
namespace string_hook {

typedef HANDLE (WINAPI *CreateFileAFunc)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
static CreateFileAFunc original_func = nullptr;
static hook::HookHandle hook_handle = nullptr;
static FileAccessCallback callback = nullptr;
static std::string redirect_from;
static std::string redirect_to;

static HANDLE WINAPI detour_func(LPCSTR lpFileName, DWORD dwAccess, DWORD dwShare,
    LPSECURITY_ATTRIBUTES lpSec, DWORD dwCreate, DWORD dwFlags, HANDLE hTemplate) {
    if (callback) callback(lpFileName, dwAccess);
    if (!redirect_from.empty()) {
        std::string path(lpFileName);
        if (path.find(redirect_from) == 0) {
            path = redirect_to + path.substr(redirect_from.length());
            return original_func(path.c_str(), dwAccess, dwShare, lpSec, dwCreate, dwFlags, hTemplate);
        }
    }
    return original_func(lpFileName, dwAccess, dwShare, lpSec, dwCreate, dwFlags, hTemplate);
}

bool install() {
    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (!kernel32) return false;
    auto target = reinterpret_cast<CreateFileAFunc>(GetProcAddress(kernel32, "CreateFileA"));
    if (!target) return false;
    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);
    if (status != hook::HookStatus::Success) return false;
    return hook::enable(hook_handle) == hook::HookStatus::Success;
}

void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }
void set_callback(FileAccessCallback cb) { callback = cb; }
void set_redirect(const std::string& from, const std::string& to) { redirect_from = from; redirect_to = to; }

} // namespace string_hook

// ============================================================================
// Example 5: ProfilingHook
// Measures function execution time with high-resolution timer
// ============================================================================
namespace profiling_hook {

struct ProfileData { uint64_t call_count, total_ticks, min_ticks, max_ticks; };

typedef int (*TargetFuncType)(int);
static TargetFuncType original_func = nullptr;
static hook::HookHandle hook_handle = nullptr;
static ProfileData data = {0, 0, UINT64_MAX, 0};
static std::mutex mtx;

static int detour_func(int arg) {
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);
    int result = original_func(arg);
    QueryPerformanceCounter(&end);
    uint64_t elapsed = end.QuadPart - start.QuadPart;
    std::lock_guard<std::mutex> lock(mtx);
    data.call_count++;
    data.total_ticks += elapsed;
    if (elapsed < data.min_ticks) data.min_ticks = elapsed;
    if (elapsed > data.max_ticks) data.max_ticks = elapsed;
    return result;
}

bool install(TargetFuncType target) {
    auto status = hook::install(target, &detour_func, &original_func, &hook_handle);
    if (status != hook::HookStatus::Success) return false;
    return hook::enable(hook_handle) == hook::HookStatus::Success;
}

void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }
ProfileData get_data() { std::lock_guard<std::mutex> lock(mtx); return data; }
void reset() { std::lock_guard<std::mutex> lock(mtx); data = {0, 0, UINT64_MAX, 0}; }

double get_average_ms() {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    std::lock_guard<std::mutex> lock(mtx);
    if (data.call_count == 0) return 0.0;
    return (double)data.total_ticks / data.call_count / freq.QuadPart * 1000.0;
}

} // namespace profiling_hook

// ============================================================================
// ConditionalHook Implementation
// ============================================================================
namespace conditional_hook {

static DWORD (WINAPI *original_sleep)(DWORD) = nullptr;
static hook::HookHandle hook_handle = nullptr;
static bool skip_long = false;
static DWORD max_ms = 1000;
static bool accelerate = false;
static float accel_factor = 10.0f;

static DWORD WINAPI detour_sleep(DWORD ms) {
    if (skip_long && ms > max_ms) return 0;
    if (accelerate) { ms = static_cast<DWORD>(ms / accel_factor); if (ms == 0) ms = 1; }
    return original_sleep(ms);
}

using Sleep_t = DWORD (WINAPI *)(DWORD);

bool install() {
    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (!kernel32) return false;
    auto target = reinterpret_cast<Sleep_t>(GetProcAddress(kernel32, "Sleep"));
    if (!target) return false;
    auto status = hook::install(target, &detour_sleep, &original_sleep, &hook_handle);
    if (status != hook::HookStatus::Success) return false;
    return hook::enable(hook_handle) == hook::HookStatus::Success;
}

void uninstall() { if (hook_handle) { hook::remove(hook_handle); hook_handle = nullptr; } }
void configure(bool skip, DWORD max, bool acc, float f) { skip_long = skip; max_ms = max; accelerate = acc; accel_factor = f; }

} // namespace conditional_hook

// ============================================================================
// Example 7: HookManager
// Manages multiple hooks with automatic cleanup
// ============================================================================
class HookManager {
public:
    struct HookInfo {
        hook::HookHandle handle;
        std::string name;
        void* target;
        void* detour;
        bool enabled;
    };

    HookManager() { hook::initialize(); }
    ~HookManager() { remove_all(); }

    bool add(const std::string& name, void* target, void* detour, void** original) {
        std::lock_guard<std::mutex> lock(mutex_);
        hook::HookHandle h = nullptr;
        auto status = hook::install(target, detour, original, &h);
        if (status != hook::HookStatus::Success) return false;
        if (hook::enable(h) != hook::HookStatus::Success) { hook::remove(h); return false; }
        hooks_.push_back({h, name, target, detour, true});
        return true;
    }

    bool remove(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto it = hooks_.begin(); it != hooks_.end(); ++it) {
            if (it->name == name) { hook::remove(it->handle); hooks_.erase(it); return true; }
        }
        return false;
    }

    void remove_all() {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& info : hooks_) hook::remove(info.handle);
        hooks_.clear();
    }

    bool enable(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& info : hooks_) {
            if (info.name == name) {
                info.enabled = (hook::enable(info.handle) == hook::HookStatus::Success);
                return info.enabled;
            }
        }
        return false;
    }

    bool disable(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& info : hooks_) {
            if (info.name == name) {
                if (hook::disable(info.handle) == hook::HookStatus::Success) {
                    info.enabled = false; return true;
                }
                return false;
            }
        }
        return false;
    }

    void print_status() const {
        std::cout << "=== HookManager (" << hooks_.size() << " hooks) ===" << std::endl;
        for (const auto& info : hooks_)
            std::cout << "  " << info.name << " [" << (info.enabled ? "on" : "off") << "]" << std::endl;
    }

    size_t count() const { return hooks_.size(); }

private:
    std::vector<HookInfo> hooks_;
    mutable std::mutex mutex_;
};

} // namespace examples
} // namespace veda64

#endif // !VEDA64_NO_HOOKS && Windows ARM64
