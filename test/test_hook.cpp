// Hook library tests - validates hooking subsystem functionality
// Auto-generated - do not edit
// Cross-platform tests run on any Windows target (x64 or ARM64)
// Live hook tests only run on ARM64
#include "veda64.hpp"

#if !defined(VEDA64_NO_HOOKS) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))

#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>

using namespace veda64;

void test_initialization_lifecycle() {
    std::cout << "  test_initialization_lifecycle..." << std::endl;

    // Should not be initialized yet
    hook::shutdown(); // clean slate
    assert(!hook::is_initialized());

    // Initialize
    auto status = hook::initialize();
    assert(status == hook::HookStatus::Success);
    assert(hook::is_initialized());

    // Double-init is idempotent
    status = hook::initialize();
    assert(status == hook::HookStatus::Success);
    assert(hook::is_initialized());

    // Shutdown
    hook::shutdown();
    assert(!hook::is_initialized());

    // Double-shutdown is safe
    hook::shutdown();
    assert(!hook::is_initialized());
}

void test_configuration() {
    std::cout << "  test_configuration..." << std::endl;

    hook::initialize();

    hook::HookConfig cfg;
    cfg.min_hook_size = 32;
    cfg.max_relocated_insns = 64;
    cfg.thread_safe = false;
    cfg.preserve_flags = false;
    cfg.allow_chain = true;
    hook::set_config(cfg);

    auto got = hook::get_config();
    assert(got.min_hook_size == 32);
    assert(got.max_relocated_insns == 64);
    assert(got.thread_safe == false);
    assert(got.preserve_flags == false);
    assert(got.allow_chain == true);

    hook::shutdown();
}

#ifndef VEDA64_NO_STRINGS
void test_status_strings() {
    std::cout << "  test_status_strings..." << std::endl;

    assert(hook::status_to_string(hook::HookStatus::Success) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::NotInitialized) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::InvalidTarget) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::InvalidDetour) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::AllocationFailed) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::ProtectionFailed) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::DisassemblyFailed) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::RelocationFailed) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::InstructionTooComplex) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::HookAlreadyInstalled) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::HookNotFound) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::HookDisabled) != nullptr);
    assert(hook::status_to_string(hook::HookStatus::InternalError) != nullptr);

    // Verify specific strings are not empty
    assert(strlen(hook::status_to_string(hook::HookStatus::Success)) > 0);
    assert(strlen(hook::status_to_string(hook::HookStatus::InternalError)) > 0);
}
#endif

void test_error_handling() {
    std::cout << "  test_error_handling..." << std::endl;

    // Ensure not initialized
    hook::shutdown();

    // install before initialize should fail
    hook::HookStatus status;
    int dummy_target = 0;
    int dummy_detour = 0;
    void* original = nullptr;
    hook::HookHandle handle = nullptr;
    status = hook::install(&dummy_target, &dummy_detour, &original, &handle);
    assert(handle == nullptr);
    assert(status == hook::HookStatus::NotInitialized);

    // Initialize for remaining tests
    hook::initialize();

    // null target should fail
    status = hook::install(nullptr, &dummy_detour, &original, &handle);
    assert(handle == nullptr);
    assert(status == hook::HookStatus::InvalidTarget);

    // null detour should fail
    status = hook::install(&dummy_target, nullptr, &original, &handle);
    assert(handle == nullptr);
    assert(status == hook::HookStatus::InvalidDetour);

    hook::shutdown();
}

void test_generate_jump() {
    std::cout << "  test_generate_jump..." << std::endl;

    uint8_t buffer[16] = {};
    void* target = reinterpret_cast<void*>(static_cast<uintptr_t>(0xDEADBEEFCAFE0000ULL));
    size_t written = hook::detail::generate_jump(buffer, target);
    (void)written;

    assert(written == 16);

    // First instruction: LDR X16, [PC+8] = 0x58000050
    uint32_t insn0;
    memcpy(&insn0, &buffer[0], 4);
    assert(insn0 == 0x58000050);

    // Second instruction: BR X16 = 0xD61F0200
    uint32_t insn1;
    memcpy(&insn1, &buffer[4], 4);
    assert(insn1 == 0xD61F0200);

    // Remaining 8 bytes: target address
    uint64_t addr;
    memcpy(&addr, &buffer[8], 8);
    assert(addr == reinterpret_cast<uint64_t>(target));
}

void test_generate_call() {
    std::cout << "  test_generate_call..." << std::endl;

    uint8_t buffer[16] = {};
    void* target = reinterpret_cast<void*>(static_cast<uintptr_t>(0x1234567890ABCDEFULL));
    size_t written = hook::detail::generate_call(buffer, target);
    (void)written;

    assert(written == 16);

    // First instruction: LDR X16, [PC+8] = 0x58000050
    uint32_t insn0;
    memcpy(&insn0, &buffer[0], 4);
    assert(insn0 == 0x58000050);

    // Second instruction: BLR X16 = 0xD63F0200
    uint32_t insn1;
    memcpy(&insn1, &buffer[4], 4);
    assert(insn1 == 0xD63F0200);

    // Remaining 8 bytes: target address
    uint64_t addr;
    memcpy(&addr, &buffer[8], 8);
    assert(addr == reinterpret_cast<uint64_t>(target));
}

void test_is_pc_relative() {
    std::cout << "  test_is_pc_relative..." << std::endl;

    // PC-relative instructions should return true
    assert(hook::detail::is_pc_relative(0x14000001));  // B .+4
    assert(hook::detail::is_pc_relative(0x97fa94a3));  // BL offset
    assert(hook::detail::is_pc_relative(0x54000040));  // B.EQ .+8
    assert(hook::detail::is_pc_relative(0x34000060));  // CBZ W0, .+0xC
    assert(hook::detail::is_pc_relative(0x35000068));  // CBNZ W8, .+0xC
    assert(hook::detail::is_pc_relative(0x36080040));  // TBZ W0, #1, .+8
    assert(hook::detail::is_pc_relative(0x37f800a0));  // TBNZ X0, #31, .+0x14
    assert(hook::detail::is_pc_relative(0x10000020));  // ADR X0, .+4
    assert(hook::detail::is_pc_relative(0x90000000));  // ADRP X0, current page

    // Non-PC-relative instructions should return false
    assert(!hook::detail::is_pc_relative(0x8b020020));  // ADD X0, X1, X2
    assert(!hook::detail::is_pc_relative(0x910003fd));  // MOV FP, SP
    assert(!hook::detail::is_pc_relative(0xd503201f));  // NOP
    assert(!hook::detail::is_pc_relative(0xd65f03c0));  // RET
}

void test_can_relocate() {
    std::cout << "  test_can_relocate..." << std::endl;

    // Relocatable instructions
    assert(hook::detail::can_relocate(0x14000001));  // B .+4
    assert(hook::detail::can_relocate(0x8b020020));  // ADD X0, X1, X2
    assert(hook::detail::can_relocate(0xd503201f));  // NOP

    // Non-relocatable instructions
    assert(!hook::detail::can_relocate(0xd65f03c0));  // RET
}

void test_relocate_instruction() {
    std::cout << "  test_relocate_instruction..." << std::endl;

    uint32_t out_insn[4];
    size_t out_count;
    bool ok;

    // Non-PC-relative (ADD) should be copied unchanged
    ok = hook::detail::relocate_instruction(0x8b020020, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    assert(out_insn[0] == 0x8b020020);

    // B .+4 relocated from 0x1000 to 0x2000
    // target=0x1004, new_offset=0x1004-0x2000=-0xFFC
    ok = hook::detail::relocate_instruction(0x14000001, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm26 = (-0xFFC / 4) & 0x03FFFFFF = 0x03FFFC01
    assert(out_insn[0] == (0x14000000 | 0x03FFFC01));

    // B.EQ .+8 relocated from 0x1000 to 0x3000
    // target=0x1008, new_offset=0x1008-0x3000=-0x1FF8
    ok = hook::detail::relocate_instruction(0x54000040, 0x1000, 0x3000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm19 = (-0x1FF8 / 4) & 0x7FFFF = 0x7F802
    // encoding: (insn & 0xFF00001F) | (new_imm19 << 5)
    assert(out_insn[0] == (0x54000000 | (0x7F802u << 5)));

    // CBZ W0, .+0xC relocated from 0x1000 to 0x2000
    // target=0x100C, new_offset=0x100C-0x2000=-0xFF4
    ok = hook::detail::relocate_instruction(0x34000060, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm19 = (-0xFF4 / 4) & 0x7FFFF = 0x7FC03
    // encoding: (insn & 0xFF00001F) | (new_imm19 << 5)
    assert(out_insn[0] == (0x34000000 | (0x7FC03u << 5)));

    // TBZ W0, #1, .+8 relocated from 0x1000 to 0x2000
    // target=0x1008, new_offset=0x1008-0x2000=-0xFF8
    ok = hook::detail::relocate_instruction(0x36080040, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm14 = (-0xFF8 / 4) & 0x3FFF = 0x3C02
    // encoding: (insn & 0xFFF8001F) | (new_imm14 << 5)
    assert(out_insn[0] == (0x36080000 | (0x3C02u << 5)));

    // ADR X0, .+4 relocated from 0x1000 to 0x5000
    // target=0x1004, new_offset=0x1004-0x5000=-0x3FFC
    ok = hook::detail::relocate_instruction(0x10000020, 0x1000, 0x5000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm21 = -0x3FFC & 0x1FFFFF = 0x1C0004
    // new_immlo = 0x1C0004 & 0x3 = 0
    // new_immhi = (0x1C0004 >> 2) & 0x7FFFF = 0x70001
    // encoding: (insn & 0x9F00001F) | (immlo << 29) | (immhi << 5)
    {
        uint32_t new_imm21 = static_cast<uint32_t>(static_cast<int32_t>(-0x3FFC)) & 0x1FFFFF;
        uint32_t new_immlo = new_imm21 & 0x3;
        uint32_t new_immhi = (new_imm21 >> 2) & 0x7FFFF;
        uint32_t expected = (0x10000020 & 0x9F00001F) | (new_immlo << 29) | (new_immhi << 5);
        (void)expected;
        assert(out_insn[0] == expected);
    }

    // ADRP X0, 0 relocated from 0x1000 to 0x5000
    // target_page = (0x1000 & ~0xFFF) + 0 = 0x1000
    // new_offset = 0x1000 - (0x5000 & ~0xFFF) = 0x1000 - 0x5000 = -0x4000
    ok = hook::detail::relocate_instruction(0x90000000, 0x1000, 0x5000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    {
        // new_imm21 = -0x4000 >> 12 = -4 = 0xFFFFFFFC
        int32_t new_imm21_val = static_cast<int32_t>(-0x4000) >> 12; // -4
        uint32_t new_immlo = static_cast<uint32_t>(new_imm21_val) & 0x3;
        uint32_t new_immhi = (static_cast<uint32_t>(new_imm21_val) >> 2) & 0x7FFFF;
        uint32_t expected = (0x90000000 & 0x9F00001F) | (new_immlo << 29) | (new_immhi << 5);
        (void)expected;
        assert(out_insn[0] == expected);
    }
}

#if defined(_M_ARM64) || defined(__aarch64__)

static volatile int g_hook_called = 0;

// Target function must be large enough for the 16-byte hook sequence.
// Use volatile to prevent the compiler from optimizing away the body.
#pragma optimize("", off)
__declspec(noinline) static int target_func(int a, int b) {
    volatile int x = a;
    volatile int y = b;
    volatile int sum = x + y;
    return sum;
}
#pragma optimize("", on)

static int (*original_func)(int, int) = nullptr;

static int detour_func(int a, int b) {
    g_hook_called++;
    return original_func(a, b);
}

// Helper: configure hook for testing (disable thread suspension)
static void setup_test_config() {
    hook::HookConfig cfg;
    cfg.thread_safe = false;  // Avoid NT thread enumeration in tests
    hook::set_config(cfg);
}

void test_live_hook() {
    std::cout << "  test_live_hook..." << std::endl;

    hook::initialize();
    setup_test_config();
    g_hook_called = 0;

    // Verify original behavior
    assert(target_func(3, 4) == 7);
    assert(g_hook_called == 0);

    // Install hook (starts disabled)
    hook::HookHandle handle = nullptr;
    auto status = hook::install(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        reinterpret_cast<void**>(&original_func),
        &handle);
    assert(handle != nullptr);
    assert(status == hook::HookStatus::Success);
    assert(!hook::is_enabled(handle));

    // Enable the hook
    status = hook::enable(handle);
    assert(status == hook::HookStatus::Success);
    assert(hook::is_enabled(handle));

    // Call through hook - detour should be called
    int result = target_func(3, 4);
    assert(result == 7);
    assert(g_hook_called == 1);

    // Call original through trampoline
    result = original_func(10, 20);
    assert(result == 30);
    assert(g_hook_called == 1);  // detour not called via trampoline

    // Remove hook
    auto rem_status = hook::remove(handle);
    (void)rem_status;
    assert(rem_status == hook::HookStatus::Success);

    // Verify original behavior restored
    g_hook_called = 0;
    result = target_func(5, 6);
    assert(result == 11);
    assert(g_hook_called == 0);

    hook::shutdown();
}

void test_hook_enable_disable() {
    std::cout << "  test_hook_enable_disable..." << std::endl;

    hook::initialize();
    setup_test_config();
    g_hook_called = 0;

    hook::HookHandle handle = nullptr;
    auto status = hook::install(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        reinterpret_cast<void**>(&original_func),
        &handle);
    assert(handle != nullptr);
    assert(!hook::is_enabled(handle));  // Starts disabled

    // Enable hook first
    status = hook::enable(handle);
    assert(status == hook::HookStatus::Success);
    assert(hook::is_enabled(handle));

    // Disable hook
    status = hook::disable(handle);
    assert(status == hook::HookStatus::Success);
    assert(!hook::is_enabled(handle));

    // Call should go to original
    g_hook_called = 0;
    assert(target_func(1, 2) == 3);
    assert(g_hook_called == 0);

    // Re-enable hook
    status = hook::enable(handle);
    assert(status == hook::HookStatus::Success);
    assert(hook::is_enabled(handle));

    // Call should go through detour again
    assert(target_func(1, 2) == 3);
    assert(g_hook_called == 1);

    hook::remove(handle);
    hook::shutdown();
}

void test_hook_info() {
    std::cout << "  test_hook_info..." << std::endl;

    hook::initialize();
    setup_test_config();

    hook::HookHandle handle = nullptr;
    auto status = hook::install(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        reinterpret_cast<void**>(&original_func),
        &handle);
    (void)status;
    assert(handle != nullptr);

    assert(hook::get_target(handle) == reinterpret_cast<void*>(&target_func));
    assert(hook::get_detour(handle) == reinterpret_cast<void*>(&detour_func));
    assert(hook::get_trampoline(handle) != nullptr);
    assert(hook::get_hook_size(handle) >= 16);
    assert(hook::get_relocated_count(handle) > 0);

    hook::remove(handle);
    hook::shutdown();
}

void test_double_hook_rejection() {
    std::cout << "  test_double_hook_rejection..." << std::endl;

    hook::initialize();
    setup_test_config();

    void* orig1 = nullptr;
    void* orig2 = nullptr;
    hook::HookHandle handle1 = nullptr;
    hook::HookHandle handle2 = nullptr;

    auto status = hook::install(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        &orig1, &handle1);
    assert(handle1 != nullptr);
    assert(status == hook::HookStatus::Success);

    // Second hook on same target should fail
    status = hook::install(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        &orig2, &handle2);
    assert(handle2 == nullptr);
    assert(status == hook::HookStatus::HookAlreadyInstalled);

    hook::remove(handle1);
    hook::shutdown();
}

#endif // _M_ARM64 || __aarch64__

int main() {
    std::cout << "Running hook tests..." << std::endl;

    // Cross-platform tests
    test_initialization_lifecycle();
    test_configuration();
#ifndef VEDA64_NO_STRINGS
    test_status_strings();
#endif
    test_error_handling();
    test_generate_jump();
    test_generate_call();
    test_is_pc_relative();
    test_can_relocate();
    test_relocate_instruction();

    // ARM64-only tests
#if defined(_M_ARM64) || defined(__aarch64__)
    test_live_hook();
    test_hook_enable_disable();
    test_hook_info();
    test_double_hook_rejection();
#else
    std::cout << "  (ARM64-only tests skipped on this platform)" << std::endl;
#endif

    std::cout << "All hook tests passed!" << std::endl;
    return 0;
}

#else // VEDA64_NO_HOOKS || !(_WIN32 || VEDA64_HOOK_SUPPORT)

// Hook support not available on this platform
#include <iostream>
int main() {
    std::cout << "Hook tests skipped (hooks disabled or not on Windows)" << std::endl;
    return 0;
}

#endif // !VEDA64_NO_HOOKS && (_WIN32 || VEDA64_HOOK_SUPPORT)
