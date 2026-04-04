// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

// Core (always available): decode, operand types, mnemonic enum
#include "veda64/util.hpp"
#include "veda64/mnemonic.hpp"
#include "veda64/types.hpp"
#include "veda64/operand.hpp"
#include "veda64/instruction.hpp"

// Optional features (controlled by CMake options)
// VEDA64_STRINGS — enables to_string() methods (inline in headers above)

#ifdef VEDA64_ASSEMBLER
#include "veda64/assembler.hpp"
#endif

#ifdef VEDA64_IR
#include "veda64/ir.hpp"
#endif

#if defined(VEDA64_HOOK) && (defined(_WIN32) || defined(VEDA64_HOOK_SUPPORT))
#include "veda64/hook.hpp"
#endif

#ifdef VEDA64_CODEGEN
#include "codegen/codegen.hpp"
#endif
