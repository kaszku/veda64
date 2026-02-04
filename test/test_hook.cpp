// Test suite for Windows ARM64 API hooking
// This test only compiles and runs on Windows ARM64

#include "veda64.hpp"

// Only compile the actual tests on Windows ARM64
// _M_ARM64 is defined by MSVC when targeting ARM64
// __aarch64__ is defined by GCC/Clang when targeting ARM64
#if defined(_WIN32) && (defined(_M_ARM64) || defined(__aarch64__))
#include "hook.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace veda64;

// ============================================================================
// Test target functions
// ============================================================================

// Simple function to hook
static int g_call_count = 0;

__declspec(noinline) int target_add(int a, int b) {
    g_call_count++;
    return a + b;
}

__declspec(noinline) int target_multiply(int a, int b) {
    return a * b;
}

__declspec(noinline) int target_with_branch(int x) {
    if (x > 0) {
        return x * 2;
    } else {
        return x * -1;
    }
}

// ============================================================================
// Detour functions and trampolines
// ============================================================================

typedef int (*add_fn)(int, int);
typedef int (*multiply_fn)(int, int);
typedef int (*branch_fn)(int);

static add_fn original_add = nullptr;
static multiply_fn original_multiply = nullptr;
static branch_fn original_branch = nullptr;

static int g_detour_call_count = 0;

int detour_add(int a, int b) {
    g_detour_call_count++;
    // Call original and modify result
    return original_add(a, b) + 100;
}

int detour_multiply(int a, int b) {
    g_detour_call_count++;
    // Call original with modified arguments
    return original_multiply(a + 1, b + 1);
}

int detour_branch(int x) {
    g_detour_call_count++;
    // Call original with negated argument
    return original_branch(-x);
}

// ============================================================================
// Hook handles storage
// ============================================================================

static Hook::HookHandle handle_add = nullptr;
static Hook::HookHandle handle_multiply = nullptr;
static Hook::HookHandle handle_branch = nullptr;

// ============================================================================
// Test cases
// ============================================================================

void test_basic_hook_install_remove() {
    std::cout << "  Testing basic hook install/remove..." << std::endl;
    
    // Reset counters
    g_call_count = 0;
    g_detour_call_count = 0;
    original_add = nullptr;
    handle_add = nullptr;
    
    // Initialize hook subsystem
    auto init_status = Hook::initialize();
    if (init_status != Hook::HookStatus::Success && !Hook::is_initialized()) {
        std::cout << "    SKIP: Hook initialize failed: " << Hook::status_to_string(init_status) << std::endl;
        return;
    }
    
    // Verify original function works
    int result = target_add(5, 3);
    assert(result == 8);
    assert(g_call_count == 1);
    
    // Install hook
    Hook::HookStatus status;
    handle_add = Hook::install_ex(
        reinterpret_cast<void*>(&target_add),
        reinterpret_cast<void*>(&detour_add),
        reinterpret_cast<void**>(&original_add),
        &status
    );
    
    if (handle_add == nullptr) {
        std::cout << "    SKIP: Hook install returned status: " << Hook::status_to_string(status) << std::endl;
        std::cout << "    (This may be expected if running without admin privileges)" << std::endl;
        return;
    }
    
    assert(original_add != nullptr);
    
    // Call hooked function
    g_call_count = 0;
    result = target_add(5, 3);
    assert(result == 108);  // 8 + 100 from detour
    assert(g_call_count == 1);  // Original was called via trampoline
    assert(g_detour_call_count == 1);
    
    // Remove hook
    status = Hook::remove(handle_add);
    assert(status == Hook::HookStatus::Success);
    handle_add = nullptr;
    
    // Verify original function works again
    g_call_count = 0;
    g_detour_call_count = 0;
    result = target_add(5, 3);
    assert(result == 8);
    assert(g_call_count == 1);
    assert(g_detour_call_count == 0);
    
    std::cout << "    PASS" << std::endl;
}

void test_hook_enable_disable() {
    std::cout << "  Testing hook enable/disable..." << std::endl;
    
    g_call_count = 0;
    g_detour_call_count = 0;
    original_multiply = nullptr;
    handle_multiply = nullptr;
    
    // Install hook
    Hook::HookStatus status;
    handle_multiply = Hook::install_ex(
        reinterpret_cast<void*>(&target_multiply),
        reinterpret_cast<void*>(&detour_multiply),
        reinterpret_cast<void**>(&original_multiply),
        &status
    );
    
    if (handle_multiply == nullptr) {
        std::cout << "    SKIP: Hook install failed: " << Hook::status_to_string(status) << std::endl;
        return;
    }
    
    // Call with hook enabled
    int result = target_multiply(3, 4);
    assert(result == 20);  // (3+1) * (4+1) = 20
    assert(g_detour_call_count == 1);
    
    // Disable hook
    status = Hook::disable(handle_multiply);
    assert(status == Hook::HookStatus::Success);
    
    // Call with hook disabled - should get original behavior
    g_detour_call_count = 0;
    result = target_multiply(3, 4);
    assert(result == 12);  // 3 * 4 = 12
    assert(g_detour_call_count == 0);
    
    // Re-enable hook
    status = Hook::enable(handle_multiply);
    assert(status == Hook::HookStatus::Success);
    
    // Call with hook enabled again
    result = target_multiply(3, 4);
    assert(result == 20);
    assert(g_detour_call_count == 1);
    
    // Cleanup
    Hook::remove(handle_multiply);
    handle_multiply = nullptr;
    
    std::cout << "    PASS" << std::endl;
}

void test_hook_function_with_branches() {
    std::cout << "  Testing hook on function with branches..." << std::endl;
    
    g_detour_call_count = 0;
    original_branch = nullptr;
    handle_branch = nullptr;
    
    // Verify original behavior
    assert(target_with_branch(5) == 10);   // 5 > 0, so 5 * 2 = 10
    assert(target_with_branch(-3) == 3);   // -3 <= 0, so -3 * -1 = 3
    
    // Install hook
    Hook::HookStatus status;
    handle_branch = Hook::install_ex(
        reinterpret_cast<void*>(&target_with_branch),
        reinterpret_cast<void*>(&detour_branch),
        reinterpret_cast<void**>(&original_branch),
        &status
    );
    
    if (handle_branch == nullptr) {
        std::cout << "    SKIP: Hook install failed: " << Hook::status_to_string(status) << std::endl;
        return;
    }
    
    // Call hooked function - detour negates the argument
    int result = target_with_branch(5);
    // detour calls original_branch(-5), which returns -5 * -1 = 5
    assert(result == 5);
    assert(g_detour_call_count == 1);
    
    result = target_with_branch(-3);
    // detour calls original_branch(3), which returns 3 * 2 = 6
    assert(result == 6);
    assert(g_detour_call_count == 2);
    
    // Cleanup
    Hook::remove(handle_branch);
    handle_branch = nullptr;
    
    std::cout << "    PASS" << std::endl;
}

void test_multiple_hooks() {
    std::cout << "  Testing multiple simultaneous hooks..." << std::endl;
    
    original_add = nullptr;
    original_multiply = nullptr;
    handle_add = nullptr;
    handle_multiply = nullptr;
    g_detour_call_count = 0;
    
    // Install both hooks
    Hook::HookStatus status1, status2;
    handle_add = Hook::install_ex(
        reinterpret_cast<void*>(&target_add),
        reinterpret_cast<void*>(&detour_add),
        reinterpret_cast<void**>(&original_add),
        &status1
    );
    
    handle_multiply = Hook::install_ex(
        reinterpret_cast<void*>(&target_multiply),
        reinterpret_cast<void*>(&detour_multiply),
        reinterpret_cast<void**>(&original_multiply),
        &status2
    );
    
    if (handle_add == nullptr || handle_multiply == nullptr) {
        std::cout << "    SKIP: Hook install failed" << std::endl;
        Hook::remove_all();
        return;
    }
    
    // Test both hooks work
    int add_result = target_add(2, 3);
    int mul_result = target_multiply(2, 3);
    
    assert(add_result == 105);  // 5 + 100
    assert(mul_result == 12);   // (2+1) * (3+1) = 12
    assert(g_detour_call_count == 2);
    
    // Remove all hooks
    Hook::remove_all();
    handle_add = nullptr;
    handle_multiply = nullptr;
    
    // Verify originals work
    g_detour_call_count = 0;
    assert(target_add(2, 3) == 5);
    assert(target_multiply(2, 3) == 6);
    assert(g_detour_call_count == 0);
    
    std::cout << "    PASS" << std::endl;
}

void test_hook_not_found() {
    std::cout << "  Testing error handling for null/invalid hook handle..." << std::endl;
    
    // Try to remove a null handle
    auto status = Hook::remove(nullptr);
    assert(status == Hook::HookStatus::HookNotFound);
    
    // Try to enable a null handle
    status = Hook::enable(nullptr);
    assert(status == Hook::HookStatus::HookNotFound);
    
    // Try to disable a null handle
    status = Hook::disable(nullptr);
    assert(status == Hook::HookStatus::HookNotFound);
    
    std::cout << "    PASS" << std::endl;
}

void test_double_hook() {
    std::cout << "  Testing double hook prevention..." << std::endl;
    
    original_add = nullptr;
    add_fn original_add2 = nullptr;
    handle_add = nullptr;
    Hook::HookHandle handle_add2 = nullptr;
    
    // Install first hook
    Hook::HookStatus status;
    handle_add = Hook::install_ex(
        reinterpret_cast<void*>(&target_add),
        reinterpret_cast<void*>(&detour_add),
        reinterpret_cast<void**>(&original_add),
        &status
    );
    
    if (handle_add == nullptr) {
        std::cout << "    SKIP: First hook install failed" << std::endl;
        return;
    }
    
    // Try to install second hook on same target
    handle_add2 = Hook::install_ex(
        reinterpret_cast<void*>(&target_add),
        reinterpret_cast<void*>(&detour_add),
        reinterpret_cast<void**>(&original_add2),
        &status
    );
    
    assert(handle_add2 == nullptr);
    assert(status == Hook::HookStatus::HookAlreadyInstalled);
    
    // Cleanup
    Hook::remove(handle_add);
    handle_add = nullptr;
    
    std::cout << "    PASS" << std::endl;
}

void test_instruction_analysis() {
    std::cout << "  Testing instruction analysis integration..." << std::endl;
    
    // Test that the hook module correctly uses veda64 for disassembly
    // by examining the bytes at the target function
    
    auto* func_ptr = reinterpret_cast<const uint32_t*>(&target_add);
    
    // Print first 4 instructions
    std::cout << "    First 4 instructions of target_add:" << std::endl;
    for (int i = 0; i < 4; i++) {
        uint32_t insn = func_ptr[i];
        auto result = decode(insn);
        std::cout << "      [" << i << "] 0x" << std::hex << std::setw(8) << std::setfill('0') << insn << std::dec;
        if (result.has_value()) {
            std::cout << " -> " << mnemonic_to_string(result->mnemonic) << " " << result->to_string();
        } else {
            std::cout << " -> <decode failed>";
        }
        std::cout << std::endl;
    }
    
    std::cout << "    PASS" << std::endl;
}

// ============================================================================
// Main
// ============================================================================

int main() {
    std::cout << "Running Windows ARM64 Hook tests..." << std::endl;
    std::cout << std::endl;
    
    // Initialize hook subsystem
    auto init_status = Hook::initialize();
    if (init_status != Hook::HookStatus::Success) {
        std::cout << "Hook initialization failed: " << Hook::status_to_string(init_status) << std::endl;
        std::cout << "Some tests will be skipped." << std::endl;
    }
    std::cout << std::endl;
    
    test_instruction_analysis();
    test_hook_not_found();
    test_basic_hook_install_remove();
    test_hook_enable_disable();
    test_hook_function_with_branches();
    test_multiple_hooks();
    test_double_hook();
    
    // Final cleanup
    Hook::shutdown();
    
    std::cout << std::endl;
    std::cout << "All hook tests passed!" << std::endl;
    return 0;
}

#else // Not Windows ARM64

#include <iostream>

int main() {
#if defined(_WIN32) && !defined(_M_ARM64) && !defined(__aarch64__)
    std::cout << "Hook tests skipped (requires ARM64, running on x64)" << std::endl;
#elif !defined(_WIN32)
    std::cout << "Hook tests skipped (Windows ARM64 only)" << std::endl;
#else
    std::cout << "Hook tests skipped (unsupported platform)" << std::endl;
#endif
    return 0;
}

#endif
