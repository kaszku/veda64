// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "ir.hpp"

namespace veda64 {
namespace ir {

Tree build_ir_ABS_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ABS_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Abs", {}, {ir::func_call("SInt", {}, {ir::ident("operand1")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_ABS_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ABS_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Abs", {}, {ir::func_call("SInt", {}, {ir::ident("operand1")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_ADC_32_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADC_32_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_ADC_64_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADC_64_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_ADCS_32_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADCS_32_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_ADCS_64_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADCS_64_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_ADD_32_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADD_32_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ExtendReg", {}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("ZeroExtend", {ir::int_lit(64)}, {ir::ident("result")})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_ADD_64_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADD_64_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ExtendReg", {}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("ZeroExtend", {ir::int_lit(64)}, {ir::ident("result")})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_ADD_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADD_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_ADD_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADD_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_ADDPT_64_addsub_pt(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADDPT_64_addsub_pt";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CPA")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("UInt", {}, {ir::ident("imm3")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(64)", nullptr));
        stmts.push_back(ir::let_decl("base", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("LSL", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}), ir::ident("shift")})));
        stmts.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Add, ir::ident("base"), ir::ident("offset"))));
        stmts.push_back(ir::assign(ir::ident("result"), ir::func_call("PointerAddCheck", {}, {ir::ident("result"), ir::ident("base")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("result")));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_ADDS_32S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADDS_32S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ExtendReg", {}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_ADDS_64S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADDS_64S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ExtendReg", {}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_ADDS_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADDS_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_ADDS_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ADDS_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_AND_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AND_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::ident("operand2"))));
    }

    return tree;
}

Tree build_ir_AND_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AND_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::ident("operand2"))));
    }

    return tree;
}

Tree build_ir_ANDS_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ANDS_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::let_decl("result", "bits(datasize)", ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::ident("operand2"))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::bit_concat({ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), false), ir::func_call("IsZeroBit", {ir::ident("datasize")}, {ir::ident("result")}), ir::bit_lit("00")})));
    }

    return tree;
}

Tree build_ir_ANDS_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ANDS_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::let_decl("result", "bits(datasize)", ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::ident("operand2"))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::bit_concat({ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), false), ir::func_call("IsZeroBit", {ir::ident("datasize")}, {ir::ident("result")}), ir::bit_lit("00")})));
    }

    return tree;
}

Tree build_ir_ASR_ASRV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ASR_ASRV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_ASR_ASRV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ASR_ASRV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_ASRV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ASRV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_ASRV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ASRV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_AUTDA_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTDA_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTDZA_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTDZA_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTDB_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTDB_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTDZB_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTDZB_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTIA_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIA_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("autia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
                    {
                        std::vector<ir::StmtPtr> bb_8;
                        bb_8.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_8) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        bb_9.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_7.push_back({ nullptr, std::move(bb_9) });
                    }
                    bb_6.push_back(ir::if_stmt(std::move(br_7)));
                }
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autia1716")), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_5.push_back({ nullptr, std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTIZA_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIZA_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("autia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
                    {
                        std::vector<ir::StmtPtr> bb_8;
                        bb_8.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_8) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        bb_9.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_7.push_back({ nullptr, std::move(bb_9) });
                    }
                    bb_6.push_back(ir::if_stmt(std::move(br_7)));
                }
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autia1716")), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_5.push_back({ nullptr, std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTIA171615_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIA171615_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("is_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("is_combined")})));
    }

    return tree;
}

Tree build_ir_AUTIASPPCR_64LRR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIASPPCR_64LRR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
    }

    return tree;
}

Tree build_ir_AUTIB_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIB_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("autib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
                    {
                        std::vector<ir::StmtPtr> bb_8;
                        bb_8.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_8) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        bb_9.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_7.push_back({ nullptr, std::move(bb_9) });
                    }
                    bb_6.push_back(ir::if_stmt(std::move(br_7)));
                }
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autib1716")), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_5.push_back({ nullptr, std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTIZB_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIZB_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rn"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("autib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
                    {
                        std::vector<ir::StmtPtr> bb_8;
                        bb_8.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_8) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        bb_9.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_7.push_back({ nullptr, std::move(bb_9) });
                    }
                    bb_6.push_back(ir::if_stmt(std::move(br_7)));
                }
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autib1716")), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_5.push_back({ nullptr, std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_AUTIB171615_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIB171615_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("is_combined", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("is_combined")})));
    }

    return tree;
}

Tree build_ir_AUTIBSPPCR_64LRR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIBSPPCR_64LRR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
    }

    return tree;
}

Tree build_ir_BIC_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BIC_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
    }

    return tree;
}

Tree build_ir_BIC_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BIC_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
    }

    return tree;
}

Tree build_ir_BICS_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BICS_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::let_decl("result", "bits(datasize)", ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::bit_concat({ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), false), ir::func_call("IsZeroBit", {ir::ident("datasize")}, {ir::ident("result")}), ir::bit_lit("00")})));
    }

    return tree;
}

Tree build_ir_BICS_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BICS_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::let_decl("result", "bits(datasize)", ir::bin_op(ir::BinOpKind::And, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::bit_concat({ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), false), ir::func_call("IsZeroBit", {ir::ident("datasize")}, {ir::ident("result")}), ir::bit_lit("00")})));
    }

    return tree;
}

Tree build_ir_CCMN_32_condcmp_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMN_32_condcmp_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["imm5"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
        stmts.push_back(ir::let_decl("imm", "bits(datasize)", ir::func_call("ZeroExtend", {}, {ir::ident("imm5")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::ident("imm")));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMN_64_condcmp_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMN_64_condcmp_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["imm5"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
        stmts.push_back(ir::let_decl("imm", "bits(datasize)", ir::func_call("ZeroExtend", {}, {ir::ident("imm5")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::ident("imm")));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMN_32_condcmp_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMN_32_condcmp_reg";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMN_64_condcmp_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMN_64_condcmp_reg";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("0")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMP_32_condcmp_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMP_32_condcmp_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["imm5"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
        stmts.push_back(ir::let_decl("imm", "bits(datasize)", ir::func_call("ZeroExtend", {}, {ir::ident("imm5")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::ident("imm")));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")), ir::bit_lit("1")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMP_64_condcmp_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMP_64_condcmp_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["imm5"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
        stmts.push_back(ir::let_decl("imm", "bits(datasize)", ir::func_call("ZeroExtend", {}, {ir::ident("imm5")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::ident("imm")));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")), ir::bit_lit("1")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMP_32_condcmp_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMP_32_condcmp_reg";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")), ir::bit_lit("1")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CCMP_64_condcmp_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CCMP_64_condcmp_reg";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["nzcv"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
        stmts.push_back(ir::var_decl("flags", "bits(4)", ir::ident("nzcv")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
                bb_2.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})));
                bb_2.push_back(ir::tuple_assign({"-", "flags"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")), ir::bit_lit("1")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("flags")));
    }

    return tree;
}

Tree build_ir_CINC_CSINC_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CINC_CSINC_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CINC_CSINC_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CINC_CSINC_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CINV_CSINV_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CINV_CSINV_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CINV_CSINV_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CINV_CSINV_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CLS_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CLS_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["op"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("CountLeadingSignBits", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CLS_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CLS_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["op"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("CountLeadingSignBits", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CLZ_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CLZ_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["op"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("CountLeadingZeroBits", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CLZ_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CLZ_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["op"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("CountLeadingZeroBits", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CMN_ADDS_32S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMN_ADDS_32S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMN_ADDS_64S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMN_ADDS_64S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMN_ADDS_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMN_ADDS_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMN_ADDS_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMN_ADDS_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMP_SUBS_32S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMP_SUBS_32S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMP_SUBS_64S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMP_SUBS_64S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMP_SUBS_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMP_SUBS_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMP_SUBS_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMP_SUBS_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CMPP_SUBPS_64S_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CMPP_SUBPS_64S_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CNEG_CSNEG_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CNEG_CSNEG_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CNEG_CSNEG_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CNEG_CSNEG_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CNT_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CNT_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("BitCount", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CNT_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CNT_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("BitCount", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CRC32B_32C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32B_32C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(79764919), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32H_32C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32H_32C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(79764919), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32W_32C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32W_32C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(79764919), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32X_64C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32X_64C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(79764919), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32CB_32C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32CB_32C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(517762881), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32CH_32C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32CH_32C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(517762881), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32CW_32C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32CW_32C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(517762881), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CRC32CX_64C_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CRC32CX_64C_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["C"] = (insn >> 12) & 0x1;
    tree.fields["sz"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CRC32")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sz"), ir::bit_lit("11"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("acc", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("val", "bits(size)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("poly", "bits(32)", ir::bit_slice(ir::int_lit(517762881), ir::int_lit(31), ir::int_lit(0), false)));
        stmts.push_back(ir::let_decl("tempacc", "bits(BinOp(op='+', left=IntLiteral(value=32), right=Identifier(name='size')))", ir::bit_concat({ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::ident("acc")}), ir::func_call("Zeros", {ir::ident("size")}, {})})));
        stmts.push_back(ir::let_decl("tempval", "bits(BinOp(op='+', left=Identifier(name='size'), right=IntLiteral(value=32)))", ir::bit_concat({ir::func_call("BitReverse", {ir::ident("size")}, {ir::ident("val")}), ir::func_call("Zeros", {ir::int_lit(32)}, {})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(32)}, {ir::ident("d")}), ir::func_call("BitReverse", {ir::int_lit(32)}, {ir::func_call("Poly32Mod2", {ir::bin_op(ir::BinOpKind::Add, ir::int_lit(32), ir::ident("size"))}, {ir::bin_op(ir::BinOpKind::Xor, ir::ident("tempacc"), ir::ident("tempval")), ir::ident("poly")})})));
    }

    return tree;
}

Tree build_ir_CSEL_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSEL_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSEL_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSEL_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSET_CSINC_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSET_CSINC_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CSET_CSINC_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSET_CSINC_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CSETM_CSINV_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSETM_CSINV_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CSETM_CSINV_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSETM_CSINV_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CSINC_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSINC_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Add, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}), ir::int_lit(1))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSINC_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSINC_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Add, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}), ir::int_lit(1))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSINV_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSINV_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSINV_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSINV_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSNEG_32_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSNEG_32_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Add, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})), ir::int_lit(1))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CSNEG_64_condsel(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSNEG_64_condsel";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["cond"] = (insn >> 12) & 0xF;
    tree.fields["o2"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Add, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")})), ir::int_lit(1))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_CTZ_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CTZ_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("CountLeadingZeroBits", {}, {ir::func_call("BitReverse", {ir::ident("datasize")}, {ir::ident("operand1")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_CTZ_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CTZ_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("CountLeadingZeroBits", {}, {ir::func_call("BitReverse", {ir::ident("datasize")}, {ir::ident("operand1")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_EON_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "EON_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Xor, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
    }

    return tree;
}

Tree build_ir_EON_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "EON_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Xor, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
    }

    return tree;
}

Tree build_ir_EOR_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "EOR_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Xor, ir::ident("operand1"), ir::ident("operand2"))));
    }

    return tree;
}

Tree build_ir_EOR_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "EOR_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Xor, ir::ident("operand1"), ir::ident("operand2"))));
    }

    return tree;
}

Tree build_ir_GMI_64G_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GMI_64G_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_MTE")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("address", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}))));
        stmts.push_back(ir::var_decl("mask", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("tag", "bits(4)", ir::func_call("AArch64_AllocationTagFromAddress", {}, {ir::ident("address")})));
        stmts.push_back(ir::assign(ir::bit_slice(ir::ident("mask"), ir::func_call("UInt", {}, {ir::ident("tag")}), ir::func_call("UInt", {}, {ir::ident("tag")}), false), ir::bit_lit("1")));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("mask")));
    }

    return tree;
}

Tree build_ir_IRG_64I_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "IRG_64I_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_MTE")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("exclude_reg", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("exclude", "bits(16)", ir::bin_op(ir::BinOpKind::Or, ir::bit_slice(ir::ident("exclude_reg"), ir::int_lit(15), ir::int_lit(0), false), ir::field_access(ir::func_call("GCR_EL1", {}, {}), "Exclude"))));
        stmts.push_back(ir::let_decl("rtag", "bits(4)", ir::func_call("AArch64_ChooseTagOrZero", {}, {ir::ident("exclude")})));
        stmts.push_back(ir::let_decl("result", "bits(64)", ir::func_call("AArch64_AddressWithAllocationTag", {}, {ir::ident("operand"), ir::ident("rtag")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("result")));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_LSL_LSLV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSL_LSLV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_LSL_LSLV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSL_LSLV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_LSLV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSLV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_LSLV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSLV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_LSR_LSRV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSR_LSRV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_LSR_LSRV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSR_LSRV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_LSRV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSRV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_LSRV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "LSRV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_MADD_32A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MADD_32A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(datasize)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Add, ir::func_call("UInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_MADD_64A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MADD_64A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(datasize)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Add, ir::func_call("UInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_MADDPT_64A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MADDPT_64A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CPA")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(64)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::var_decl("result", "bits(64)", nullptr));
        stmts.push_back(ir::let_decl("product", "integer", ir::bin_op(ir::BinOpKind::Mul, ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Add, ir::ident("operand3"), ir::bit_slice(ir::ident("product"), ir::int_lit(63), ir::int_lit(0), false))));
        stmts.push_back(ir::let_decl("overflow", "boolean", ir::bin_op(ir::BinOpKind::Ne, ir::ident("product"), ir::func_call("SInt", {}, {ir::bit_slice(ir::ident("product"), ir::int_lit(63), ir::int_lit(0), false)}))));
        stmts.push_back(ir::assign(ir::ident("result"), ir::func_call("PointerMultiplyAddCheck", {}, {ir::ident("result"), ir::ident("operand3"), ir::ident("overflow")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_MNEG_MSUB_32A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MNEG_MSUB_32A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MNEG_MSUB_64A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MNEG_MSUB_64A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MOV_ORR_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MOV_ORR_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MOV_ORR_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MOV_ORR_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MSUB_32A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MSUB_32A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(datasize)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Sub, ir::func_call("UInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_MSUB_64A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MSUB_64A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(datasize)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Sub, ir::func_call("UInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_MSUBPT_64A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MSUBPT_64A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CPA")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(64)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::var_decl("result", "bits(64)", nullptr));
        stmts.push_back(ir::let_decl("product", "integer", ir::bin_op(ir::BinOpKind::Mul, ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("operand3"), ir::bit_slice(ir::ident("product"), ir::int_lit(63), ir::int_lit(0), false))));
        stmts.push_back(ir::let_decl("overflow", "boolean", ir::bin_op(ir::BinOpKind::Ne, ir::ident("product"), ir::func_call("SInt", {}, {ir::bit_slice(ir::ident("product"), ir::int_lit(63), ir::int_lit(0), false)}))));
        stmts.push_back(ir::assign(ir::ident("result"), ir::func_call("PointerMultiplyAddCheck", {}, {ir::ident("result"), ir::ident("operand3"), ir::ident("overflow")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_MUL_MADD_32A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MUL_MADD_32A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MUL_MADD_64A_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MUL_MADD_64A_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["op31"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MVN_ORN_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MVN_ORN_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MVN_ORN_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MVN_ORN_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NEG_SUB_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NEG_SUB_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NEG_SUB_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NEG_SUB_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NEGS_SUBS_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NEGS_SUBS_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NEGS_SUBS_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NEGS_SUBS_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NGC_SBC_32_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NGC_SBC_32_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NGC_SBC_64_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NGC_SBC_64_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NGCS_SBCS_32_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NGCS_SBCS_32_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_NGCS_SBCS_64_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NGCS_SBCS_64_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_ORN_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ORN_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Or, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
    }

    return tree;
}

Tree build_ir_ORN_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ORN_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Or, ir::ident("operand1"), ir::unary_op(ir::UnaryOpKind::Not, ir::ident("operand2")))));
    }

    return tree;
}

Tree build_ir_ORR_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ORR_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Or, ir::ident("operand1"), ir::ident("operand2"))));
    }

    return tree;
}

Tree build_ir_ORR_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ORR_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("ShiftReg", {}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Or, ir::ident("operand1"), ir::ident("operand2"))));
    }

    return tree;
}

Tree build_ir_PACDA_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACDA_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                br_10.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACDZA_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACDZA_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                br_10.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACDB_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACDB_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                br_10.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACDZB_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACDZB_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACDB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                br_10.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACGA_64P_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACGA_64P_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACGA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                br_5.push_back({ ir::ident("source_is_sp"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACGA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")})})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
    }

    return tree;
}

Tree build_ir_PACIA_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIA_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("pacia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_12;
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_12.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_13) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_12.push_back({ nullptr, std::move(bb_14) });
                    }
                    bb_11.push_back(ir::if_stmt(std::move(br_12)));
                }
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_15;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_16.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacia1716")), std::move(bb_17) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_18;
                        bb_18.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_16.push_back({ nullptr, std::move(bb_18) });
                    }
                    bb_15.push_back(ir::if_stmt(std::move(br_16)));
                }
                br_10.push_back({ nullptr, std::move(bb_15) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACIZA_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIZA_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("pacia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_12;
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_12.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_13) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_12.push_back({ nullptr, std::move(bb_14) });
                    }
                    bb_11.push_back(ir::if_stmt(std::move(br_12)));
                }
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_15;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_16.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacia1716")), std::move(bb_17) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_18;
                        bb_18.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_16.push_back({ nullptr, std::move(bb_18) });
                    }
                    bb_15.push_back(ir::if_stmt(std::move(br_16)));
                }
                br_10.push_back({ nullptr, std::move(bb_15) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACIA171615_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIA171615_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
    }

    return tree;
}

Tree build_ir_PACIASPPC_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIASPPC_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSPPC")));
                bb_4.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                br_3.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
    }

    return tree;
}

Tree build_ir_PACIB_64P_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIB_64P_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("pacib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_12;
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_12.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_13) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_12.push_back({ nullptr, std::move(bb_14) });
                    }
                    bb_11.push_back(ir::if_stmt(std::move(br_12)));
                }
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_15;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_16.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacib1716")), std::move(bb_17) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_18;
                        bb_18.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_16.push_back({ nullptr, std::move(bb_18) });
                    }
                    bb_15.push_back(ir::if_stmt(std::move(br_16)));
                }
                br_10.push_back({ nullptr, std::move(bb_15) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACIZB_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIZB_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["Z"] = (insn >> 13) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("pacib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                        br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        br_8.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::ident("n"), ir::int_lit(31)), std::move(bb_9) });
                    }
                    bb_7.push_back(ir::if_stmt(std::move(br_8)));
                }
                br_3.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
            {
                std::vector<ir::StmtPtr> bb_11;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_12;
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_12.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_13) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_12.push_back({ nullptr, std::move(bb_14) });
                    }
                    bb_11.push_back(ir::if_stmt(std::move(br_12)));
                }
                br_10.push_back({ ir::ident("source_is_sp"), std::move(bb_11) });
            }
            {
                std::vector<ir::StmtPtr> bb_15;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_16.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacib1716")), std::move(bb_17) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_18;
                        bb_18.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_16.push_back({ nullptr, std::move(bb_18) });
                    }
                    bb_15.push_back(ir::if_stmt(std::move(br_16)));
                }
                br_10.push_back({ nullptr, std::move(bb_15) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_10)));
        }
    }

    return tree;
}

Tree build_ir_PACIB171615_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIB171615_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(17)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
    }

    return tree;
}

Tree build_ir_PACIBSPPC_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIBSPPC_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSPPC")));
                bb_4.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                br_3.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
    }

    return tree;
}

Tree build_ir_PACNBIASPPC_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACNBIASPPC_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
    }

    return tree;
}

Tree build_ir_PACNBIBSPPC_64LR_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACNBIBSPPC_64LR_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
    }

    return tree;
}

Tree build_ir_RBIT_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RBIT_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<ir::StmtPtr> fb_1;
            fb_1.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::ident("i")), ir::bin_op(ir::BinOpKind::Sub, ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::ident("i")), false), ir::bit_slice(ir::ident("operand"), ir::ident("i"), ir::ident("i"), false)));
            stmts.push_back(ir::for_stmt("i", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), "to", std::move(fb_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_RBIT_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RBIT_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        {
            std::vector<ir::StmtPtr> fb_1;
            fb_1.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::ident("i")), ir::bin_op(ir::BinOpKind::Sub, ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::ident("i")), false), ir::bit_slice(ir::ident("operand"), ir::ident("i"), ir::ident("i"), false)));
            stmts.push_back(ir::for_stmt("i", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), "to", std::move(fb_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_REV_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "REV_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opc"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("opc"), ir::bit_lit("11")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("container_size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("opc")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::let_decl("containers", "integer", ir::bin_op(ir::BinOpKind::Div, ir::ident("datasize"), ir::ident("container_size"))));
        {
            std::vector<ir::StmtPtr> fb_3;
            fb_3.push_back(ir::let_decl("container", "bits(container_size)", ir::bit_slice(ir::ident("operand"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true)));
            fb_3.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true), ir::func_call("Reverse", {ir::ident("container_size")}, {ir::ident("container"), ir::int_lit(8)})));
            stmts.push_back(ir::for_stmt("c", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("containers"), ir::int_lit(1)), "to", std::move(fb_3)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_REV_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "REV_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opc"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("opc"), ir::bit_lit("11")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("container_size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("opc")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::let_decl("containers", "integer", ir::bin_op(ir::BinOpKind::Div, ir::ident("datasize"), ir::ident("container_size"))));
        {
            std::vector<ir::StmtPtr> fb_3;
            fb_3.push_back(ir::let_decl("container", "bits(container_size)", ir::bit_slice(ir::ident("operand"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true)));
            fb_3.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true), ir::func_call("Reverse", {ir::ident("container_size")}, {ir::ident("container"), ir::int_lit(8)})));
            stmts.push_back(ir::for_stmt("c", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("containers"), ir::int_lit(1)), "to", std::move(fb_3)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_REV16_32_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "REV16_32_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opc"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("opc"), ir::bit_lit("11")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("container_size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("opc")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::let_decl("containers", "integer", ir::bin_op(ir::BinOpKind::Div, ir::ident("datasize"), ir::ident("container_size"))));
        {
            std::vector<ir::StmtPtr> fb_3;
            fb_3.push_back(ir::let_decl("container", "bits(container_size)", ir::bit_slice(ir::ident("operand"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true)));
            fb_3.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true), ir::func_call("Reverse", {ir::ident("container_size")}, {ir::ident("container"), ir::int_lit(8)})));
            stmts.push_back(ir::for_stmt("c", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("containers"), ir::int_lit(1)), "to", std::move(fb_3)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_REV16_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "REV16_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opc"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("opc"), ir::bit_lit("11")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("container_size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("opc")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::let_decl("containers", "integer", ir::bin_op(ir::BinOpKind::Div, ir::ident("datasize"), ir::ident("container_size"))));
        {
            std::vector<ir::StmtPtr> fb_3;
            fb_3.push_back(ir::let_decl("container", "bits(container_size)", ir::bit_slice(ir::ident("operand"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true)));
            fb_3.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true), ir::func_call("Reverse", {ir::ident("container_size")}, {ir::ident("container"), ir::int_lit(8)})));
            stmts.push_back(ir::for_stmt("c", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("containers"), ir::int_lit(1)), "to", std::move(fb_3)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_REV32_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "REV32_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opc"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("opc"), ir::bit_lit("11")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("container_size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("opc")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::let_decl("containers", "integer", ir::bin_op(ir::BinOpKind::Div, ir::ident("datasize"), ir::ident("container_size"))));
        {
            std::vector<ir::StmtPtr> fb_3;
            fb_3.push_back(ir::let_decl("container", "bits(container_size)", ir::bit_slice(ir::ident("operand"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true)));
            fb_3.push_back(ir::assign(ir::bit_slice(ir::ident("result"), ir::ident("container_size"), ir::bin_op(ir::BinOpKind::Mul, ir::ident("c"), ir::ident("container_size")), true), ir::func_call("Reverse", {ir::ident("container_size")}, {ir::ident("container"), ir::int_lit(8)})));
            stmts.push_back(ir::for_stmt("c", ir::int_lit(0), ir::bin_op(ir::BinOpKind::Sub, ir::ident("containers"), ir::int_lit(1)), "to", std::move(fb_3)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_REV64_REV_64_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "REV64_REV_64_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["opc"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_RMIF_only_rmif(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RMIF_only_rmif";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o2"] = (insn >> 4) & 0x1;
    tree.fields["mask"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FlagM")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("imm", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
        stmts.push_back(ir::let_decl("flagmask", "bits(4)", ir::ident("mask")));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("reg", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("flags", "bits(4)", ir::bit_slice(ir::bit_concat({ir::ident("reg"), ir::ident("reg")}), ir::bin_op(ir::BinOpKind::Add, ir::ident("imm"), ir::int_lit(3)), ir::ident("imm"), false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "N"), ir::bit_slice(ir::ident("flags"), ir::int_lit(3), ir::int_lit(3), false)));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("flagmask"), ir::int_lit(3), ir::int_lit(3), false), ir::bit_lit("1")), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "Z"), ir::bit_slice(ir::ident("flags"), ir::int_lit(2), ir::int_lit(2), false)));
                br_5.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("flagmask"), ir::int_lit(2), ir::int_lit(2), false), ir::bit_lit("1")), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                bb_8.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "C"), ir::bit_slice(ir::ident("flags"), ir::int_lit(1), ir::int_lit(1), false)));
                br_7.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("flagmask"), ir::int_lit(1), ir::int_lit(1), false), ir::bit_lit("1")), std::move(bb_8) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                bb_10.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "V"), ir::bit_slice(ir::ident("flags"), ir::int_lit(0), ir::int_lit(0), false)));
                br_9.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("flagmask"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1")), std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_ROR_RORV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ROR_RORV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_ROR_RORV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ROR_RORV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_RORV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RORV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_RORV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RORV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["op2"] = (insn >> 10) & 0x3;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("op2")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("n"), ir::ident("shift_type"), ir::bin_op(ir::BinOpKind::Mod, ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::ident("datasize"))})));
    }

    return tree;
}

Tree build_ir_SBC_32_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SBC_32_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_SBC_64_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SBC_64_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_SBCS_32_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SBCS_32_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_SBCS_64_addsub_carry(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SBCS_64_addsub_carry";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("X", {ir::ident("datasize")}, {ir::ident("m")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::field_access(ir::ident("PSTATE"), "C")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_SDIV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SDIV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o1"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("dividend", "integer", ir::func_call("SInt", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::let_decl("divisor", "integer", ir::func_call("SInt", {}, {ir::ident("operand2")})));
        stmts.push_back(ir::var_decl("result", "integer", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::int_lit(0)));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("divisor"), ir::int_lit(0)), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::DivRm, ir::func_call("Abs", {}, {ir::ident("dividend")}), ir::func_call("Abs", {}, {ir::ident("divisor")}))));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bin_op(ir::BinOpKind::Lt, ir::ident("dividend"), ir::int_lit(0)), ir::bin_op(ir::BinOpKind::Lt, ir::ident("divisor"), ir::int_lit(0))), std::move(bb_3) });
            }
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("result"), ir::unary_op(ir::UnaryOpKind::Negate, ir::bin_op(ir::BinOpKind::DivRm, ir::func_call("Abs", {}, {ir::ident("dividend")}), ir::func_call("Abs", {}, {ir::ident("divisor")})))));
                br_1.push_back({ nullptr, std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SDIV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SDIV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o1"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("dividend", "integer", ir::func_call("SInt", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::let_decl("divisor", "integer", ir::func_call("SInt", {}, {ir::ident("operand2")})));
        stmts.push_back(ir::var_decl("result", "integer", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::int_lit(0)));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("divisor"), ir::int_lit(0)), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::DivRm, ir::func_call("Abs", {}, {ir::ident("dividend")}), ir::func_call("Abs", {}, {ir::ident("divisor")}))));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bin_op(ir::BinOpKind::Lt, ir::ident("dividend"), ir::int_lit(0)), ir::bin_op(ir::BinOpKind::Lt, ir::ident("divisor"), ir::int_lit(0))), std::move(bb_3) });
            }
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("result"), ir::unary_op(ir::UnaryOpKind::Negate, ir::bin_op(ir::BinOpKind::DivRm, ir::func_call("Abs", {}, {ir::ident("dividend")}), ir::func_call("Abs", {}, {ir::ident("divisor")})))));
                br_1.push_back({ nullptr, std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SETF8_only_setf(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SETF8_only_setf";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 15) & 0x3F;
    tree.fields["sz"] = (insn >> 14) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["mask"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FlagM")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("reg", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "N"), ir::bit_slice(ir::ident("reg"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), false)));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "Z"), ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("reg"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), ir::int_lit(0), false), ir::func_call("Zeros", {ir::ident("size")}, {})), ir::bit_lit("1"), ir::bit_lit("0"))));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "V"), ir::bin_op(ir::BinOpKind::Xor, ir::bit_slice(ir::ident("reg"), ir::ident("size"), ir::ident("size"), false), ir::bit_slice(ir::ident("reg"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), false))));
    }

    return tree;
}

Tree build_ir_SETF16_only_setf(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SETF16_only_setf";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 15) & 0x3F;
    tree.fields["sz"] = (insn >> 14) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["o3"] = (insn >> 4) & 0x1;
    tree.fields["mask"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FlagM")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("size", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("sz")}))));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("reg", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "N"), ir::bit_slice(ir::ident("reg"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), false)));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "Z"), ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("reg"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), ir::int_lit(0), false), ir::func_call("Zeros", {ir::ident("size")}, {})), ir::bit_lit("1"), ir::bit_lit("0"))));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "V"), ir::bin_op(ir::BinOpKind::Xor, ir::bit_slice(ir::ident("reg"), ir::ident("size"), ir::ident("size"), false), ir::bit_slice(ir::ident("reg"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), ir::bin_op(ir::BinOpKind::Sub, ir::ident("size"), ir::int_lit(1)), false))));
    }

    return tree;
}

Tree build_ir_SMADDL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMADDL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(32)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(64)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Add, ir::func_call("SInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::int_lit(63), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SMAX_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMAX_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Max", {}, {ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SMAX_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMAX_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Max", {}, {ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SMIN_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMIN_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Min", {}, {ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SMIN_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMIN_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Min", {}, {ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SMNEGL_SMSUBL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMNEGL_SMSUBL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_SMSUBL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMSUBL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(32)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(64)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Sub, ir::func_call("SInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::int_lit(63), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_SMULH_64_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMULH_64_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Mul, ir::func_call("SInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::int_lit(127), ir::int_lit(64), false)));
    }

    return tree;
}

Tree build_ir_SMULL_SMADDL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMULL_SMADDL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_SUB_32_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUB_32_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ExtendReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("ZeroExtend", {ir::int_lit(64)}, {ir::ident("result")})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_SUB_64_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUB_64_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ExtendReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("ZeroExtend", {ir::int_lit(64)}, {ir::ident("result")})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_SUB_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUB_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_SUB_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUB_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_SUBP_64S_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBP_64S_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_MTE")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("operand1", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}))));
        stmts.push_back(ir::var_decl("operand2", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        stmts.push_back(ir::assign(ir::ident("operand1"), ir::func_call("SignExtend", {ir::int_lit(64)}, {ir::bit_slice(ir::ident("operand1"), ir::int_lit(55), ir::int_lit(0), false)})));
        stmts.push_back(ir::assign(ir::ident("operand2"), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("SignExtend", {ir::int_lit(64)}, {ir::bit_slice(ir::ident("operand2"), ir::int_lit(55), ir::int_lit(0), false)}))));
        stmts.push_back(ir::var_decl("result", "bits(64)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "-"}, ir::func_call("AddWithCarry", {ir::int_lit(64)}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
    }

    return tree;
}

Tree build_ir_SUBPS_64S_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBPS_64S_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_MTE")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("operand1", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}))));
        stmts.push_back(ir::var_decl("operand2", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        stmts.push_back(ir::assign(ir::ident("operand1"), ir::func_call("SignExtend", {ir::int_lit(64)}, {ir::bit_slice(ir::ident("operand1"), ir::int_lit(55), ir::int_lit(0), false)})));
        stmts.push_back(ir::assign(ir::ident("operand2"), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("SignExtend", {ir::int_lit(64)}, {ir::bit_slice(ir::ident("operand2"), ir::int_lit(55), ir::int_lit(0), false)}))));
        stmts.push_back(ir::var_decl("result", "bits(64)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::int_lit(64)}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_SUBPT_64_addsub_pt(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBPT_64_addsub_pt";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CPA")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("UInt", {}, {ir::ident("imm3")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("result", "bits(64)", nullptr));
        stmts.push_back(ir::let_decl("base", "bits(64)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("LSL", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}), ir::ident("shift")})));
        stmts.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("base"), ir::ident("offset"))));
        stmts.push_back(ir::assign(ir::ident("result"), ir::func_call("PointerAddCheck", {}, {ir::ident("result"), ir::ident("base")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("result")));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("d"), ir::int_lit(31)), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("result")));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_SUBS_32S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBS_32S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ExtendReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_SUBS_64S_addsub_ext(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBS_64S_addsub_ext";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opt"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["option"] = (insn >> 13) & 0x7;
    tree.fields["imm3"] = (insn >> 10) & 0x7;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::in_expr(ir::ident("imm3"), ir::set_lit({"BitLiteral(bits='101')", "BitLiteral(bits='110')", "BitLiteral(bits='111')"})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("shift", "integer", ir::func_call("__as", {}, {ir::func_call("UInt", {}, {ir::ident("imm3")}), ir::ident("IntegerType(width=0)")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("extend_type", "ExtendType", ir::func_call("DecodeRegExtend", {}, {ir::ident("option")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(31)), ir::func_call("SP", {ir::ident("datasize")}, {}), ir::func_call("X", {ir::ident("datasize")}, {ir::ident("n")}))));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ExtendReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("extend_type"), ir::ident("shift")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_SUBS_32_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBS_32_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_SUBS_64_addsub_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SUBS_64_addsub_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 30) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("shift"), ir::bit_lit("11")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("sf"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("imm6"), ir::int_lit(5), ir::int_lit(5), false), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("shift_type", "ShiftType", ir::func_call("DecodeShift", {}, {ir::ident("shift")})));
        stmts.push_back(ir::let_decl("shift_amount", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("ShiftReg", {ir::ident("datasize")}, {ir::ident("m"), ir::ident("shift_type"), ir::ident("shift_amount")}))));
        stmts.push_back(ir::var_decl("result", "bits(datasize)", nullptr));
        stmts.push_back(ir::var_decl("nzcv", "bits(4)", nullptr));
        stmts.push_back(ir::tuple_assign({"result", "nzcv"}, ir::func_call("AddWithCarry", {ir::ident("datasize")}, {ir::ident("operand1"), ir::ident("operand2"), ir::bit_lit("1")})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::ident("result")));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::ident("nzcv")));
    }

    return tree;
}

Tree build_ir_TST_ANDS_32_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TST_ANDS_32_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_TST_ANDS_64_log_shift(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TST_ANDS_64_log_shift";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["opc"] = (insn >> 29) & 0x3;
    tree.fields["shift"] = (insn >> 22) & 0x3;
    tree.fields["N"] = (insn >> 21) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm6"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_UDIV_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UDIV_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o1"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("dividend", "integer", ir::func_call("UInt", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::let_decl("divisor", "integer", ir::func_call("UInt", {}, {ir::ident("operand2")})));
        stmts.push_back(ir::var_decl("result", "integer", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::int_lit(0)));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("divisor"), ir::int_lit(0)), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::DivRm, ir::ident("dividend"), ir::ident("divisor"))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UDIV_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UDIV_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o1"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("dividend", "integer", ir::func_call("UInt", {}, {ir::ident("operand1")})));
        stmts.push_back(ir::let_decl("divisor", "integer", ir::func_call("UInt", {}, {ir::ident("operand2")})));
        stmts.push_back(ir::var_decl("result", "integer", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("result"), ir::int_lit(0)));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::ident("divisor"), ir::int_lit(0)), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::assign(ir::ident("result"), ir::bin_op(ir::BinOpKind::DivRm, ir::ident("dividend"), ir::ident("divisor"))));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMADDL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMADDL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(32)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(64)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Add, ir::func_call("UInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::int_lit(63), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMAX_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMAX_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Max", {}, {ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMAX_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMAX_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Max", {}, {ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMIN_32_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMIN_32_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Min", {}, {ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMIN_64_dp_2src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMIN_64_dp_2src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["opcode"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CSSC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::func_call("Min", {}, {ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})})));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::ident("datasize")}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::bin_op(ir::BinOpKind::Sub, ir::ident("datasize"), ir::int_lit(1)), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMNEGL_UMSUBL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMNEGL_UMSUBL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_UMSUBL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMSUBL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("a", "integer", ir::func_call("UInt", {}, {ir::ident("Ra")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(32)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(32)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("operand3", "bits(64)", ir::func_call("X", {}, {ir::ident("a")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Sub, ir::func_call("UInt", {}, {ir::ident("operand3")}), ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")})))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::int_lit(63), ir::int_lit(0), false)));
    }

    return tree;
}

Tree build_ir_UMULH_64_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMULH_64_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("operand2", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("result", "integer", ir::bin_op(ir::BinOpKind::Mul, ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("UInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bit_slice(ir::ident("result"), ir::int_lit(127), ir::int_lit(64), false)));
    }

    return tree;
}

Tree build_ir_UMULL_UMADDL_64WA_dp_3src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "UMULL_UMADDL_64WA_dp_3src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op54"] = (insn >> 29) & 0x3;
    tree.fields["U"] = (insn >> 23) & 0x1;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["o0"] = (insn >> 15) & 0x1;
    tree.fields["Ra"] = (insn >> 10) & 0x1F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_XPACD_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "XPACD_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["D"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("data", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("D"), ir::bit_lit("1"))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("Strip", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("data")})));
    }

    return tree;
}

Tree build_ir_XPACI_64Z_dp_1src(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "XPACI_64Z_dp_1src";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["S"] = (insn >> 29) & 0x1;
    tree.fields["opcode2"] = (insn >> 16) & 0x1F;
    tree.fields["D"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
        stmts.push_back(ir::let_decl("data", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("D"), ir::bit_lit("1"))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("Strip", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("data")})));
    }

    return tree;
}

} // namespace ir
} // namespace veda64