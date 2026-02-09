// Hook library tests - validates hooking subsystem functionality
// Auto-generated - do not edit
// Cross-platform tests run on any Windows target (x64 or ARM64)
// Live hook tests only run on ARM64
#include "veda64.hpp"

#if defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT)

#include "hook.hpp"
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>

using namespace veda64;

void test_initialization_lifecycle() {
    std::cout << "  test_initialization_lifecycle..." << std::endl;

    // Should not be initialized yet
    Hook::shutdown(); // clean slate
    assert(!Hook::is_initialized());

    // Initialize
    auto status = Hook::initialize();
    assert(status == Hook::HookStatus::Success);
    assert(Hook::is_initialized());

    // Double-init is idempotent
    status = Hook::initialize();
    assert(status == Hook::HookStatus::Success);
    assert(Hook::is_initialized());

    // Shutdown
    Hook::shutdown();
    assert(!Hook::is_initialized());

    // Double-shutdown is safe
    Hook::shutdown();
    assert(!Hook::is_initialized());
}

void test_configuration() {
    std::cout << "  test_configuration..." << std::endl;

    Hook::initialize();

    Hook::HookConfig cfg;
    cfg.min_hook_size = 32;
    cfg.max_relocated_insns = 64;
    cfg.thread_safe = false;
    cfg.preserve_flags = false;
    cfg.allow_chain = true;
    Hook::set_config(cfg);

    auto got = Hook::get_config();
    assert(got.min_hook_size == 32);
    assert(got.max_relocated_insns == 64);
    assert(got.thread_safe == false);
    assert(got.preserve_flags == false);
    assert(got.allow_chain == true);

    Hook::shutdown();
}

#ifndef VEDA64_NO_STRINGS
void test_status_strings() {
    std::cout << "  test_status_strings..." << std::endl;

    assert(Hook::status_to_string(Hook::HookStatus::Success) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::NotInitialized) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::InvalidTarget) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::InvalidDetour) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::AllocationFailed) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::ProtectionFailed) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::DisassemblyFailed) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::RelocationFailed) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::InstructionTooComplex) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::HookAlreadyInstalled) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::HookNotFound) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::HookDisabled) != nullptr);
    assert(Hook::status_to_string(Hook::HookStatus::InternalError) != nullptr);

    // Verify specific strings are not empty
    assert(strlen(Hook::status_to_string(Hook::HookStatus::Success)) > 0);
    assert(strlen(Hook::status_to_string(Hook::HookStatus::InternalError)) > 0);
}
#endif

void test_error_handling() {
    std::cout << "  test_error_handling..." << std::endl;

    // Ensure not initialized
    Hook::shutdown();

    // install before initialize should fail
    Hook::HookStatus status;
    int dummy_target = 0;
    int dummy_detour = 0;
    void* original = nullptr;
    auto handle = Hook::install_ex(&dummy_target, &dummy_detour, &original, &status);
    assert(handle == nullptr);
    assert(status == Hook::HookStatus::NotInitialized);

    // Initialize for remaining tests
    Hook::initialize();

    // null target should fail
    handle = Hook::install_ex(nullptr, &dummy_detour, &original, &status);
    assert(handle == nullptr);
    assert(status == Hook::HookStatus::InvalidTarget);

    // null detour should fail
    handle = Hook::install_ex(&dummy_target, nullptr, &original, &status);
    assert(handle == nullptr);
    assert(status == Hook::HookStatus::InvalidDetour);

    Hook::shutdown();
}

void test_generate_jump() {
    std::cout << "  test_generate_jump..." << std::endl;

    uint8_t buffer[16] = {};
    void* target = reinterpret_cast<void*>(static_cast<uintptr_t>(0xDEADBEEFCAFE0000ULL));
    size_t written = Hook::Detail::generate_jump(buffer, target);
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
    size_t written = Hook::Detail::generate_call(buffer, target);
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
    assert(Hook::Detail::is_pc_relative(0x14000001));  // B .+4
    assert(Hook::Detail::is_pc_relative(0x97fa94a3));  // BL offset
    assert(Hook::Detail::is_pc_relative(0x54000040));  // B.EQ .+8
    assert(Hook::Detail::is_pc_relative(0x34000060));  // CBZ W0, .+0xC
    assert(Hook::Detail::is_pc_relative(0x35000068));  // CBNZ W8, .+0xC
    assert(Hook::Detail::is_pc_relative(0x36080040));  // TBZ W0, #1, .+8
    assert(Hook::Detail::is_pc_relative(0x37f800a0));  // TBNZ W0, #31, .+0x14
    assert(Hook::Detail::is_pc_relative(0x10000020));  // ADR X0, .+4
    assert(Hook::Detail::is_pc_relative(0x90000000));  // ADRP X0, current page

    // Non-PC-relative instructions should return false
    assert(!Hook::Detail::is_pc_relative(0x8b020020));  // ADD X0, X1, X2
    assert(!Hook::Detail::is_pc_relative(0x910003fd));  // MOV FP, SP
    assert(!Hook::Detail::is_pc_relative(0xd503201f));  // NOP
    assert(!Hook::Detail::is_pc_relative(0xd65f03c0));  // RET
}

void test_can_relocate() {
    std::cout << "  test_can_relocate..." << std::endl;

    // Relocatable instructions
    assert(Hook::Detail::can_relocate(0x14000001));  // B .+4
    assert(Hook::Detail::can_relocate(0x8b020020));  // ADD X0, X1, X2
    assert(Hook::Detail::can_relocate(0xd503201f));  // NOP

    // Non-relocatable instructions
    assert(!Hook::Detail::can_relocate(0xd65f03c0));  // RET
}

void test_relocate_instruction() {
    std::cout << "  test_relocate_instruction..." << std::endl;

    uint32_t out_insn[4];
    size_t out_count;
    bool ok;

    // Non-PC-relative (ADD) should be copied unchanged
    ok = Hook::Detail::relocate_instruction(0x8b020020, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    assert(out_insn[0] == 0x8b020020);

    // B .+4 relocated from 0x1000 to 0x2000
    // target=0x1004, new_offset=0x1004-0x2000=-0xFFC
    ok = Hook::Detail::relocate_instruction(0x14000001, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm26 = (-0xFFC / 4) & 0x03FFFFFF = 0x03FFFC01
    assert(out_insn[0] == (0x14000000 | 0x03FFFC01));

    // B.EQ .+8 relocated from 0x1000 to 0x3000
    // target=0x1008, new_offset=0x1008-0x3000=-0x1FF8
    ok = Hook::Detail::relocate_instruction(0x54000040, 0x1000, 0x3000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm19 = (-0x1FF8 / 4) & 0x7FFFF = 0x7F802
    // encoding: (insn & 0xFF00001F) | (new_imm19 << 5)
    assert(out_insn[0] == (0x54000000 | (0x7F802u << 5)));

    // CBZ W0, .+0xC relocated from 0x1000 to 0x2000
    // target=0x100C, new_offset=0x100C-0x2000=-0xFF4
    ok = Hook::Detail::relocate_instruction(0x34000060, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm19 = (-0xFF4 / 4) & 0x7FFFF = 0x7FC03
    // encoding: (insn & 0xFF00001F) | (new_imm19 << 5)
    assert(out_insn[0] == (0x34000000 | (0x7FC03u << 5)));

    // TBZ W0, #1, .+8 relocated from 0x1000 to 0x2000
    // target=0x1008, new_offset=0x1008-0x2000=-0xFF8
    ok = Hook::Detail::relocate_instruction(0x36080040, 0x1000, 0x2000, out_insn, &out_count);
    assert(ok);
    assert(out_count == 1);
    // new_imm14 = (-0xFF8 / 4) & 0x3FFF = 0x3C02
    // encoding: (insn & 0xFFF8001F) | (new_imm14 << 5)
    assert(out_insn[0] == (0x36080000 | (0x3C02u << 5)));

    // ADR X0, .+4 relocated from 0x1000 to 0x5000
    // target=0x1004, new_offset=0x1004-0x5000=-0x3FFC
    ok = Hook::Detail::relocate_instruction(0x10000020, 0x1000, 0x5000, out_insn, &out_count);
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
    ok = Hook::Detail::relocate_instruction(0x90000000, 0x1000, 0x5000, out_insn, &out_count);
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
    Hook::HookConfig cfg;
    cfg.thread_safe = false;  // Avoid NT thread enumeration in tests
    Hook::set_config(cfg);
}

void test_live_hook() {
    std::cout << "  test_live_hook..." << std::endl;

    Hook::initialize();
    setup_test_config();
    g_hook_called = 0;

    // Verify original behavior
    assert(target_func(3, 4) == 7);
    assert(g_hook_called == 0);

    // Install hook
    Hook::HookStatus status;
    auto handle = Hook::install_ex(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        reinterpret_cast<void**>(&original_func),
        &status);
    assert(handle != nullptr);
    assert(status == Hook::HookStatus::Success);

    // Call through hook - detour should be called
    int result = target_func(3, 4);
    assert(result == 7);
    assert(g_hook_called == 1);

    // Call original through trampoline
    result = original_func(10, 20);
    assert(result == 30);
    assert(g_hook_called == 1);  // detour not called via trampoline

    // Remove hook
    auto rem_status = Hook::remove(handle);
    (void)rem_status;
    assert(rem_status == Hook::HookStatus::Success);

    // Verify original behavior restored
    g_hook_called = 0;
    result = target_func(5, 6);
    assert(result == 11);
    assert(g_hook_called == 0);

    Hook::shutdown();
}

void test_hook_enable_disable() {
    std::cout << "  test_hook_enable_disable..." << std::endl;

    Hook::initialize();
    setup_test_config();
    g_hook_called = 0;

    Hook::HookStatus status;
    auto handle = Hook::install_ex(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        reinterpret_cast<void**>(&original_func),
        &status);
    assert(handle != nullptr);
    assert(Hook::is_enabled(handle));

    // Disable hook
    status = Hook::disable(handle);
    assert(status == Hook::HookStatus::Success);
    assert(!Hook::is_enabled(handle));

    // Call should go to original
    g_hook_called = 0;
    assert(target_func(1, 2) == 3);
    assert(g_hook_called == 0);

    // Re-enable hook
    status = Hook::enable(handle);
    assert(status == Hook::HookStatus::Success);
    assert(Hook::is_enabled(handle));

    // Call should go through detour again
    assert(target_func(1, 2) == 3);
    assert(g_hook_called == 1);

    Hook::remove(handle);
    Hook::shutdown();
}

void test_hook_info() {
    std::cout << "  test_hook_info..." << std::endl;

    Hook::initialize();
    setup_test_config();

    Hook::HookStatus status;
    auto handle = Hook::install_ex(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        reinterpret_cast<void**>(&original_func),
        &status);
    assert(handle != nullptr);

    assert(Hook::get_target(handle) == reinterpret_cast<void*>(&target_func));
    assert(Hook::get_detour(handle) == reinterpret_cast<void*>(&detour_func));
    assert(Hook::get_trampoline(handle) != nullptr);
    assert(Hook::get_hook_size(handle) >= 16);
    assert(Hook::get_relocated_count(handle) > 0);

    Hook::remove(handle);
    Hook::shutdown();
}

void test_double_hook_rejection() {
    std::cout << "  test_double_hook_rejection..." << std::endl;

    Hook::initialize();
    setup_test_config();

    Hook::HookStatus status;
    void* orig1 = nullptr;
    void* orig2 = nullptr;

    auto handle1 = Hook::install_ex(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        &orig1, &status);
    assert(handle1 != nullptr);
    assert(status == Hook::HookStatus::Success);

    // Second hook on same target should fail
    auto handle2 = Hook::install_ex(
        reinterpret_cast<void*>(&target_func),
        reinterpret_cast<void*>(&detour_func),
        &orig2, &status);
    (void)handle2;
    assert(handle2 == nullptr);
    assert(status == Hook::HookStatus::HookAlreadyInstalled);

    Hook::remove(handle1);
    Hook::shutdown();
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

#else // !(_WIN32 || VEDA64_HOOK_SUPPORT)

// Hook support not available on this platform
#include <iostream>
int main() {
    std::cout << "Hook tests skipped (not on Windows)" << std::endl;
    return 0;
}

#endif // _WIN32 || VEDA64_HOOK_SUPPORT
