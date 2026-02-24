// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "ir.hpp"

namespace veda64 {
namespace ir {

Tree build_ir_UDF_only_perm_undef(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UDF_only_perm_undef";

    tree.fields["imm16"] = (insn >> 0) & 0xFFFF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
    }

    return tree;
}

} // namespace ir
} // namespace veda64