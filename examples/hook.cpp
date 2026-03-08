// Example: Inline hooking on Windows ARM64
// Build: cmake -DVEDA64_STRINGS=ON -DVEDA64_HOOK=ON .. && cmake --build .
// Run:   ./example_hook
// Note:  Windows ARM64 only

#include "veda64.hpp"

#if defined(VEDA64_HOOK) && defined(_WIN32) && (defined(_M_ARM64) || defined(__aarch64__))
#include <cstdio>
#include <windows.h>

using namespace veda64;

// ============================================================================
// Example 1: Hook a user-defined function
// ============================================================================

// Prevent the compiler from inlining/shrinking the target below 16 bytes
#pragma optimize("", off)
static int target_function(int a, int b) {
    volatile int x = a;
    volatile int y = b;
    return x + y;
}
#pragma optimize("", on)

static int (*original_func)(int, int) = nullptr;
static hook::HookHandle func_handle = nullptr;

static int detour_function(int a, int b) {
    printf("  [hook] target_function(%d, %d) intercepted\n", a, b);
    int result = original_func(a, b);  // call original
    printf("  [hook] original returned %d, adding 1000\n", result);
    return result + 1000;  // modify result
}

static void example_basic_hook() {
    printf("=== Basic function hook ===\n");

    printf("  Before hook: target_function(3, 4) = %d\n",
           target_function(3, 4));

    hook::initialize();
    auto status = hook::install(
        &target_function, &detour_function, &original_func, &func_handle);

    if (status == hook::HookStatus::Success) {
        hook::enable(func_handle);
        printf("  After hook:\n");
        int result = target_function(3, 4);
        printf("  Result: %d (expected 1007)\n", result);

        // Disable temporarily
        hook::disable(func_handle);
        printf("  Disabled: target_function(3, 4) = %d (expected 7)\n",
               target_function(3, 4));

        // Re-enable
        hook::enable(func_handle);
        printf("  Re-enabled: target_function(3, 4) = %d (expected 1007)\n",
               target_function(3, 4));

        hook::remove(func_handle);
        printf("  Removed: target_function(3, 4) = %d (expected 7)\n",
               target_function(3, 4));
    } else {
        printf("  Hook install failed: %d\n", static_cast<int>(status));
    }
}

// ============================================================================
// Example 2: Hook an NT syscall (NtClose)
// ============================================================================

typedef LONG NTSTATUS;
typedef NTSTATUS (NTAPI *NtClose_t)(HANDLE);

static NtClose_t original_NtClose = nullptr;
static hook::HookHandle ntclose_handle = nullptr;
static int close_count = 0;

static NTSTATUS NTAPI hooked_NtClose(HANDLE h) {
    close_count++;
    return original_NtClose(h);
}

static void example_syscall_hook() {
    printf("\n=== NT syscall hook (NtClose) ===\n");

    auto ntdll = GetModuleHandleA("ntdll.dll");
    auto pNtClose = reinterpret_cast<NtClose_t>(
        GetProcAddress(ntdll, "NtClose"));

    if (!pNtClose) {
        printf("  Failed to find NtClose\n");
        return;
    }

    // Install with void* overload (for GetProcAddress results)
    auto status = hook::install(
        pNtClose, &hooked_NtClose, &original_NtClose, &ntclose_handle);

    if (status == hook::HookStatus::Success) {
        hook::enable(ntclose_handle);

        // Create and close a handle to trigger the hook
        close_count = 0;
        HANDLE event = CreateEventA(nullptr, FALSE, FALSE, nullptr);
        CloseHandle(event);  // goes through NtClose

        printf("  NtClose called %d time(s) after CloseHandle\n", close_count);
        hook::remove(ntclose_handle);
    } else {
        printf("  Hook install failed: %d\n", static_cast<int>(status));
    }
}

// ============================================================================
// Example 3: Enable/disable all hooks at once
// ============================================================================

#pragma optimize("", off)
static int func_a(int x) { volatile int v = x; return v * 2; }
static int func_b(int x) { volatile int v = x; return v * 3; }
#pragma optimize("", on)

static int (*orig_a)(int) = nullptr;
static int (*orig_b)(int) = nullptr;
static hook::HookHandle handle_a = nullptr;
static hook::HookHandle handle_b = nullptr;

static int detour_a(int x) { return orig_a(x) + 100; }
static int detour_b(int x) { return orig_b(x) + 200; }

static void example_batch_hooks() {
    printf("\n=== Batch enable/disable ===\n");

    hook::install(&func_a, &detour_a, &orig_a, &handle_a);
    hook::install(&func_b, &detour_b, &orig_b, &handle_b);

    printf("  Before enable: func_a(5)=%d, func_b(5)=%d\n",
           func_a(5), func_b(5));

    hook::enable_all();
    printf("  After enable_all: func_a(5)=%d, func_b(5)=%d\n",
           func_a(5), func_b(5));

    hook::disable_all();
    printf("  After disable_all: func_a(5)=%d, func_b(5)=%d\n",
           func_a(5), func_b(5));

    hook::remove_all();
}

int main() {
    // Use non-thread-safe mode for examples (avoids process suspension)
    hook::HookConfig cfg;
    cfg.thread_safe = false;
    hook::set_config(cfg);

    example_basic_hook();
    example_syscall_hook();
    example_batch_hooks();

    hook::shutdown();
    return 0;
}

#else // !VEDA64_HOOK || !Windows || !ARM64

#include <cstdio>
int main() {
    printf("Hook examples require -DVEDA64_HOOK=ON on Windows ARM64\n");
    return 0;
}

#endif
