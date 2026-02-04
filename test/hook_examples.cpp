// Comprehensive hook examples for Windows ARM64
// Demonstrates various hooking patterns using veda64
//
// This file contains complete, self-contained examples.
// Each namespace demonstrates a different hooking pattern.

#include "veda64.hpp"

#if defined(_WIN32) && (defined(_M_ARM64) || defined(__aarch64__))
#include "hook.hpp"
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
namespace LoggingHook {

struct LogEntry {
    std::chrono::system_clock::time_point timestamp;
    int arg1, arg2, result;
};

static int (*original_func)(int, int) = nullptr;
static Hook::HookHandle hook_handle = nullptr;
static std::mutex log_mutex;
static std::vector<LogEntry> call_log;

static int detour_func(int a, int b) {
    auto start = std::chrono::system_clock::now();
    int result = original_func(a, b);
    std::lock_guard<std::mutex> lock(log_mutex);
    call_log.push_back({start, a, b, result});
    return result;
}

bool install(void* target) {
    Hook::HookStatus status;
    hook_handle = Hook::install_ex(target, reinterpret_cast<void*>(&detour_func),
                                   reinterpret_cast<void**>(&original_func), &status);
    return hook_handle != nullptr;
}

std::vector<LogEntry> uninstall() {
    if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; }
    std::lock_guard<std::mutex> lock(log_mutex);
    auto result = std::move(call_log);
    call_log.clear();
    return result;
}

void clear_log() {
    std::lock_guard<std::mutex> lock(log_mutex);
    call_log.clear();
}

} // namespace LoggingHook

// ============================================================================
// Example 2: ValidationHook
// Validates allocation sizes and rejects oversized requests
// ============================================================================
namespace ValidationHook {

struct Stats { size_t total_bytes, alloc_count, reject_count; };

static void* (*original_alloc)(size_t) = nullptr;
static Hook::HookHandle hook_handle = nullptr;
static size_t max_alloc_size = 100 * 1024 * 1024;
static bool log_allocations = false;
static size_t total_allocated = 0;
static size_t allocation_count = 0;
static size_t rejected_count = 0;

static void* detour_alloc(size_t size) {
    if (size > max_alloc_size) {
        rejected_count++;
        if (log_allocations) std::cerr << "[ValidationHook] Rejected: " << size << std::endl;
        return nullptr;
    }
    void* result = original_alloc(size);
    if (result) { total_allocated += size; allocation_count++; }
    return result;
}

bool install(void* target, size_t max_size) {
    max_alloc_size = max_size;
    Hook::HookStatus status;
    hook_handle = Hook::install_ex(target, reinterpret_cast<void*>(&detour_alloc),
                                   reinterpret_cast<void**>(&original_alloc), &status);
    return hook_handle != nullptr;
}

void uninstall() { if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; } }
void set_logging(bool enable) { log_allocations = enable; }
Stats get_stats() { return {total_allocated, allocation_count, rejected_count}; }
void reset_stats() { total_allocated = allocation_count = rejected_count = 0; }

} // namespace ValidationHook

// ============================================================================
// ReturnModifyHook Implementation
// ============================================================================
namespace ReturnModifyHook {

static BOOL (WINAPI *original_func)() = nullptr;
static Hook::HookHandle hook_handle = nullptr;
static bool force_result = false;
static BOOL forced_value = FALSE;

static BOOL WINAPI detour_func() {
    return force_result ? forced_value : original_func();
}

bool install() {
    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (!kernel32) return false;
    void* target = GetProcAddress(kernel32, "IsDebuggerPresent");
    if (!target) return false;
    Hook::HookStatus status;
    hook_handle = Hook::install_ex(target, reinterpret_cast<void*>(&detour_func),
                                   reinterpret_cast<void**>(&original_func), &status);
    return hook_handle != nullptr;
}

void uninstall() { if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; } }
void set_forced_result(bool enable, BOOL value) { force_result = enable; forced_value = value; }

} // namespace ReturnModifyHook

// ============================================================================
// StringHook Implementation
// ============================================================================
namespace StringHook {

typedef HANDLE (WINAPI *CreateFileAFunc)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
static CreateFileAFunc original_func = nullptr;
static Hook::HookHandle hook_handle = nullptr;
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
    void* target = GetProcAddress(kernel32, "CreateFileA");
    if (!target) return false;
    Hook::HookStatus status;
    hook_handle = Hook::install_ex(target, reinterpret_cast<void*>(&detour_func),
                                   reinterpret_cast<void**>(&original_func), &status);
    return hook_handle != nullptr;
}

void uninstall() { if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; } }
void set_callback(FileAccessCallback cb) { callback = cb; }
void set_redirect(const std::string& from, const std::string& to) { redirect_from = from; redirect_to = to; }

} // namespace StringHook

// ============================================================================
// Example 5: ProfilingHook
// Measures function execution time with high-resolution timer
// ============================================================================
namespace ProfilingHook {

struct ProfileData { uint64_t call_count, total_ticks, min_ticks, max_ticks; };

typedef int (*TargetFuncType)(int);
static TargetFuncType original_func = nullptr;
static Hook::HookHandle hook_handle = nullptr;
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

bool install(void* target) {
    Hook::HookStatus status;
    hook_handle = Hook::install_ex(target, reinterpret_cast<void*>(&detour_func),
                                   reinterpret_cast<void**>(&original_func), &status);
    return hook_handle != nullptr;
}

void uninstall() { if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; } }
ProfileData get_data() { std::lock_guard<std::mutex> lock(mtx); return data; }
void reset() { std::lock_guard<std::mutex> lock(mtx); data = {0, 0, UINT64_MAX, 0}; }

double get_average_ms() {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    std::lock_guard<std::mutex> lock(mtx);
    if (data.call_count == 0) return 0.0;
    return (double)data.total_ticks / data.call_count / freq.QuadPart * 1000.0;
}

} // namespace ProfilingHook

// ============================================================================
// ConditionalHook Implementation
// ============================================================================
namespace ConditionalHook {

static DWORD (WINAPI *original_sleep)(DWORD) = nullptr;
static Hook::HookHandle hook_handle = nullptr;
static bool skip_long = false;
static DWORD max_ms = 1000;
static bool accelerate = false;
static float accel_factor = 10.0f;

static DWORD WINAPI detour_sleep(DWORD ms) {
    if (skip_long && ms > max_ms) return 0;
    if (accelerate) { ms = static_cast<DWORD>(ms / accel_factor); if (ms == 0) ms = 1; }
    return original_sleep(ms);
}

bool install() {
    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (!kernel32) return false;
    void* target = GetProcAddress(kernel32, "Sleep");
    if (!target) return false;
    Hook::HookStatus status;
    hook_handle = Hook::install_ex(target, reinterpret_cast<void*>(&detour_sleep),
                                   reinterpret_cast<void**>(&original_sleep), &status);
    return hook_handle != nullptr;
}

void uninstall() { if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; } }
void configure(bool skip, DWORD max, bool acc, float f) { skip_long = skip; max_ms = max; accelerate = acc; accel_factor = f; }

} // namespace ConditionalHook

// ============================================================================
// MacroExample Implementation
// ============================================================================
namespace MacroExample {

VEDA64_DECLARE_ORIGINAL(MessageBoxA, int, HWND, LPCSTR, LPCSTR, UINT)
static Hook::HookHandle hook_handle = nullptr;

static int MessageBoxA_hook(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
    std::string new_caption = "[Hooked] ";
    new_caption += lpCaption ? lpCaption : "Message";
    return VEDA64_CALL_ORIGINAL(MessageBoxA, hWnd, lpText, new_caption.c_str(), uType);
}

bool install() {
    HMODULE user32 = GetModuleHandleA("user32.dll");
    if (!user32) user32 = LoadLibraryA("user32.dll");
    if (!user32) return false;
    void* target = GetProcAddress(user32, "MessageBoxA");
    if (!target) return false;
    hook_handle = VEDA64_INSTALL_HOOK(MessageBoxA, target);
    return hook_handle != nullptr;
}

void uninstall() { if (hook_handle) { Hook::remove(hook_handle); hook_handle = nullptr; } }

} // namespace MacroExample

// ============================================================================
// Example 8: HookManager
// Manages multiple hooks with automatic cleanup
// ============================================================================
class HookManager {
public:
    struct HookInfo {
        Hook::HookHandle handle;
        std::string name;
        void* target;
        void* detour;
        bool enabled;
    };

    HookManager() { Hook::initialize(); }
    ~HookManager() { remove_all(); }

    bool add(const std::string& name, void* target, void* detour, void** original) {
        std::lock_guard<std::mutex> lock(mutex_);
        Hook::HookStatus status;
        auto h = Hook::install_ex(target, detour, original, &status);
        if (!h) return false;
        hooks_.push_back({h, name, target, detour, true});
        return true;
    }

    bool remove(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto it = hooks_.begin(); it != hooks_.end(); ++it) {
            if (it->name == name) { Hook::remove(it->handle); hooks_.erase(it); return true; }
        }
        return false;
    }

    void remove_all() {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& info : hooks_) Hook::remove(info.handle);
        hooks_.clear();
    }

    bool enable(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& info : hooks_) {
            if (info.name == name) {
                info.enabled = (Hook::enable(info.handle) == Hook::HookStatus::Success);
                return info.enabled;
            }
        }
        return false;
    }

    bool disable(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& info : hooks_) {
            if (info.name == name) {
                if (Hook::disable(info.handle) == Hook::HookStatus::Success) {
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

#endif // Windows ARM64
