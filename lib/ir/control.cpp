// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "ir.hpp"

namespace veda64 {
namespace ir {

Tree build_ir_APAS_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "APAS_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_AT_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AT_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_AUTIA1716_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIA1716_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("autia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011100"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0011101"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_6.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_6.push_back(ir::assign(ir::ident("autia1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001100"), std::move(cb_6) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        bb_10.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_10) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_9.push_back({ nullptr, std::move(bb_11) });
                    }
                    bb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                br_7.push_back({ ir::ident("source_is_sp"), std::move(bb_8) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_13.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autia1716")), std::move(bb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_15;
                        bb_15.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_13.push_back({ nullptr, std::move(bb_15) });
                    }
                    bb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                br_7.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
    }

    return tree;
}

Tree build_ir_AUTIASP_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIASP_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("autia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011100"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0011101"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_6.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_6.push_back(ir::assign(ir::ident("autia1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001100"), std::move(cb_6) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        bb_10.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_10) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_9.push_back({ nullptr, std::move(bb_11) });
                    }
                    bb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                br_7.push_back({ ir::ident("source_is_sp"), std::move(bb_8) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_13.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autia1716")), std::move(bb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_15;
                        bb_15.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_13.push_back({ nullptr, std::move(bb_15) });
                    }
                    bb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                br_7.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
    }

    return tree;
}

Tree build_ir_AUTIAZ_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIAZ_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("autia1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011100"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0011101"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_6.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_6.push_back(ir::assign(ir::ident("autia1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001100"), std::move(cb_6) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        bb_10.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_10) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_9.push_back({ nullptr, std::move(bb_11) });
                    }
                    bb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                br_7.push_back({ ir::ident("source_is_sp"), std::move(bb_8) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_13.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autia1716")), std::move(bb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_15;
                        bb_15.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_13.push_back({ nullptr, std::move(bb_15) });
                    }
                    bb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                br_7.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
    }

    return tree;
}

Tree build_ir_AUTIB1716_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIB1716_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("autib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011110"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0011111"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_6.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_6.push_back(ir::assign(ir::ident("autib1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001110"), std::move(cb_6) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        bb_10.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_10) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_9.push_back({ nullptr, std::move(bb_11) });
                    }
                    bb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                br_7.push_back({ ir::ident("source_is_sp"), std::move(bb_8) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_13.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autib1716")), std::move(bb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_15;
                        bb_15.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_13.push_back({ nullptr, std::move(bb_15) });
                    }
                    bb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                br_7.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
    }

    return tree;
}

Tree build_ir_AUTIBSP_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIBSP_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("autib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011110"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0011111"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_6.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_6.push_back(ir::assign(ir::ident("autib1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001110"), std::move(cb_6) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        bb_10.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_10) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_9.push_back({ nullptr, std::move(bb_11) });
                    }
                    bb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                br_7.push_back({ ir::ident("source_is_sp"), std::move(bb_8) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_13.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autib1716")), std::move(bb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_15;
                        bb_15.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_13.push_back({ nullptr, std::move(bb_15) });
                    }
                    bb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                br_7.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
    }

    return tree;
}

Tree build_ir_AUTIBZ_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AUTIBZ_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("autib1716", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("auth_combined", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011110"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0011111"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_6.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_6.push_back(ir::assign(ir::ident("autib1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001110"), std::move(cb_6) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        bb_10.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::ident("auth_combined")})));
                        br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_10) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::ident("auth_combined")})));
                        br_9.push_back({ nullptr, std::move(bb_11) });
                    }
                    bb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                br_7.push_back({ ir::ident("source_is_sp"), std::move(bb_8) });
            }
            {
                std::vector<ir::StmtPtr> bb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        bb_14.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)}), ir::ident("auth_combined")})));
                        br_13.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("autib1716")), std::move(bb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_15;
                        bb_15.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AuthIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::ident("auth_combined")})));
                        br_13.push_back({ nullptr, std::move(bb_15) });
                    }
                    bb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                br_7.push_back({ nullptr, std::move(bb_12) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
    }

    return tree;
}

Tree build_ir_AXFLAG_M_pstate(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "AXFLAG_M_pstate";

    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FlagM2")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("z", "bit", ir::bin_op(ir::BinOpKind::Or, ir::field_access(ir::ident("PSTATE"), "Z"), ir::field_access(ir::ident("PSTATE"), "V"))));
        stmts.push_back(ir::let_decl("c", "bit", ir::bin_op(ir::BinOpKind::And, ir::field_access(ir::ident("PSTATE"), "C"), ir::unary_op(ir::UnaryOpKind::Not, ir::field_access(ir::ident("PSTATE"), "V")))));
        stmts.push_back(ir::assign(ir::field_access_multi(ir::ident("PSTATE"), {"N", "Z", "C", "V"}), ir::bit_concat({ir::bit_lit("0"), ir::ident("z"), ir::ident("c"), ir::bit_lit("0")})));
    }

    return tree;
}

Tree build_ir_B_only_condbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "B_only_condbranch";

    tree.fields["imm19"] = (insn >> 5) & 0x7FFFF;
    tree.fields["o0"] = (insn >> 4) & 0x1;
    tree.fields["cond"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm19"), ir::bit_lit("00")})})));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_B_only_branch_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "B_only_branch_imm";

    tree.fields["op"] = (insn >> 31) & 0x1;
    tree.fields["imm26"] = (insn >> 0) & 0x3FFFFFF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm26"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BC_only_condbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BC_only_condbranch";

    tree.fields["imm19"] = (insn >> 5) & 0x7FFFF;
    tree.fields["o0"] = (insn >> 4) & 0x1;
    tree.fields["cond"] = (insn >> 0) & 0xF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_HBC")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm19"), ir::bit_lit("00")})})));
        stmts.push_back(ir::let_decl("condition", "bits(4)", ir::ident("cond")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_3.push_back({ ir::func_call("ConditionHolds", {}, {ir::ident("condition")}), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
    }

    return tree;
}

Tree build_ir_BL_only_branch_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BL_only_branch_imm";

    tree.fields["op"] = (insn >> 31) & 0x1;
    tree.fields["imm26"] = (insn >> 0) & 0x3FFFFFF;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm26"), ir::bit_lit("00")})})));
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("AddGCSRecord", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIRCALL"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BLR_64_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BLR_64_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("AddGCSRecord", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("10")));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(30)}), ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDCALL"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BLRAA_64P_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BLRAA_64P_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                bb_9.push_back(ir::expr_stmt(ir::func_call("AddGCSRecord", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))})));
                br_8.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_9) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("10")));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(30)}), ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDCALL"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BLRAAZ_64_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BLRAAZ_64_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                bb_9.push_back(ir::expr_stmt(ir::func_call("AddGCSRecord", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))})));
                br_8.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_9) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("10")));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(30)}), ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDCALL"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BLRAB_64P_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BLRAB_64P_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                bb_9.push_back(ir::expr_stmt(ir::func_call("AddGCSRecord", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))})));
                br_8.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_9) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("10")));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(30)}), ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDCALL"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BLRABZ_64_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BLRABZ_64_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                bb_9.push_back(ir::expr_stmt(ir::func_call("AddGCSRecord", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))})));
                br_8.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_9) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("10")));
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(30)}), ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::int_lit(4))));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDCALL"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BR_64_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BR_64_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
                    {
                        std::vector<ir::StmtPtr> bb_4;
                        bb_4.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                        br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(16)), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(17))), std::move(bb_4) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_5;
                        bb_5.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("11")));
                        br_3.push_back({ nullptr, std::move(bb_5) });
                    }
                    bb_2.push_back(ir::if_stmt(std::move(br_3)));
                }
                br_1.push_back({ ir::ident("InGuardedPage"), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                br_1.push_back({ nullptr, std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDIR"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BRAA_64P_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BRAA_64P_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                        br_10.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(16)), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(17))), std::move(bb_11) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("11")));
                        br_10.push_back({ nullptr, std::move(bb_12) });
                    }
                    bb_9.push_back(ir::if_stmt(std::move(br_10)));
                }
                br_8.push_back({ ir::ident("InGuardedPage"), std::move(bb_9) });
            }
            {
                std::vector<ir::StmtPtr> bb_13;
                bb_13.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                br_8.push_back({ nullptr, std::move(bb_13) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDIR"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BRAAZ_64_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BRAAZ_64_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                        br_10.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(16)), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(17))), std::move(bb_11) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("11")));
                        br_10.push_back({ nullptr, std::move(bb_12) });
                    }
                    bb_9.push_back(ir::if_stmt(std::move(br_10)));
                }
                br_8.push_back({ ir::ident("InGuardedPage"), std::move(bb_9) });
            }
            {
                std::vector<ir::StmtPtr> bb_13;
                bb_13.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                br_8.push_back({ nullptr, std::move(bb_13) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDIR"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BRAB_64P_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BRAB_64P_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                        br_10.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(16)), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(17))), std::move(bb_11) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("11")));
                        br_10.push_back({ nullptr, std::move(bb_12) });
                    }
                    bb_9.push_back(ir::if_stmt(std::move(br_10)));
                }
                br_8.push_back({ ir::ident("InGuardedPage"), std::move(bb_9) });
            }
            {
                std::vector<ir::StmtPtr> bb_13;
                bb_13.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                br_8.push_back({ nullptr, std::move(bb_13) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDIR"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BRABZ_64_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BRABZ_64_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("0")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rm"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("source_is_sp", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("Z"), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("m"), ir::int_lit(31)))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::if_expr(ir::ident("source_is_sp"), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("m")}))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_8;
            {
                std::vector<ir::StmtPtr> bb_9;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_10;
                    {
                        std::vector<ir::StmtPtr> bb_11;
                        bb_11.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                        br_10.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(16)), ir::bin_op(ir::BinOpKind::Eq, ir::ident("n"), ir::int_lit(17))), std::move(bb_11) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("11")));
                        br_10.push_back({ nullptr, std::move(bb_12) });
                    }
                    bb_9.push_back(ir::if_stmt(std::move(br_10)));
                }
                br_8.push_back({ ir::ident("InGuardedPage"), std::move(bb_9) });
            }
            {
                std::vector<ir::StmtPtr> bb_13;
                bb_13.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("01")));
                br_8.push_back({ nullptr, std::move(bb_13) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_8)));
        }
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_INDIR"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_BRB_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BRB_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_BRK_EX_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BRK_EX_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("comment", "bits(16)", ir::ident("imm16")));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::bool_lit(true)})));
                br_1.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SoftwareBreakpoint", {}, {ir::ident("comment")})));
    }

    return tree;
}

Tree build_ir_BTI_HB_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "BTI_HB_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_BTI", {}, {ir::bit_slice(ir::ident("op2"), ir::int_lit(2), ir::int_lit(1), false)})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("SetBTypeNext", {}, {ir::bit_lit("00")})));
    }

    return tree;
}

Tree build_ir_CBBGT_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBGT_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBBGE_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBGE_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBBHI_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBHI_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBBHS_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBHS_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBBEQ_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBEQ_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBBNE_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBNE_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBBLE_CBBGE_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBLE_CBBGE_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBBLO_CBBHI_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBLO_CBBHI_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBBLS_CBBHS_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBLS_CBBHS_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBBLT_CBBGT_8_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBBLT_CBBGT_8_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBGT_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGT_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBLT_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLT_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHI_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHI_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBLO_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLO_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBEQ_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBEQ_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBNE_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBNE_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBGT_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGT_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBLT_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLT_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHI_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHI_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBLO_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLO_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBEQ_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBEQ_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBNE_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBNE_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_LT")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
        stmts.push_back(ir::let_decl("value2", "integer", ir::func_call("UInt", {}, {ir::ident("imm6")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Lt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_LT"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBGT_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGT_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBGE_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGE_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHI_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHI_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHS_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHS_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBEQ_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBEQ_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBNE_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBNE_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBGT_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGT_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBGE_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGE_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHI_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHI_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHS_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHS_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBEQ_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBEQ_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBNE_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBNE_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBGE_CBGT_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGE_CBGT_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBGE_CBGT_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBGE_CBGT_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBHGT_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHGT_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHGE_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHGE_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHHI_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHHI_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHHS_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHHS_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHEQ_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHEQ_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHNE_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHNE_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMPBR")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(8), ir::func_call("UInt", {}, {ir::ident("H")}))));
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm9"), ir::bit_lit("00")})})));
        stmts.push_back(ir::var_decl("op", "CmpOp", nullptr));
        stmts.push_back(ir::var_decl("unsigned", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_4.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_5.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(false)));
                cs_3.push_back({ ir::bit_lit("001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GT")));
                cb_6.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("010"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_GE")));
                cb_7.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("011"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_EQ")));
                cb_8.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("op"), ir::ident("Cmp_NE")));
                cb_9.push_back(ir::assign(ir::ident("unsigned"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("111"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cs_3.push_back({ nullptr, std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("cc"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("operand2", "bits(datasize)", ir::func_call("X", {}, {ir::ident("m")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("value1", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand1")}), ir::func_call("SInt", {}, {ir::ident("operand1")}))));
        stmts.push_back(ir::let_decl("value2", "integer", ir::if_expr(ir::ident("unsigned"), ir::func_call("UInt", {}, {ir::ident("operand2")}), ir::func_call("SInt", {}, {ir::ident("operand2")}))));
        stmts.push_back(ir::var_decl("cond", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_11;
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Eq, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_EQ"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ne, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_NE"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Ge, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GE"), std::move(cb_14) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("cond"), ir::bin_op(ir::BinOpKind::Gt, ir::ident("value1"), ir::ident("value2"))));
                cs_11.push_back({ ir::ident("Cmp_GT"), std::move(cb_15) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_11)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_16;
            {
                std::vector<ir::StmtPtr> bb_17;
                bb_17.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ ir::ident("cond"), std::move(bb_17) });
            }
            {
                std::vector<ir::StmtPtr> bb_18;
                bb_18.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_16.push_back({ nullptr, std::move(bb_18) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_16)));
        }
    }

    return tree;
}

Tree build_ir_CBHLE_CBHGE_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHLE_CBHGE_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBHLO_CBHHI_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHLO_CBHHI_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBHLS_CBHHS_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHLS_CBHHS_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBHLT_CBHGT_16_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHLT_CBHGT_16_regs";

    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["H"] = (insn >> 14) & 0x1;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBHS_CBHI_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHS_CBHI_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBHS_CBHI_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBHS_CBHI_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLE_CBLT_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLE_CBLT_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLE_CBLT_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLE_CBLT_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLE_CBGE_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLE_CBGE_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLE_CBGE_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLE_CBGE_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLO_CBHI_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLO_CBHI_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLO_CBHI_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLO_CBHI_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLS_CBLO_32_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLS_CBLO_32_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLS_CBLO_64_imm(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLS_CBLO_64_imm";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["imm6"] = (insn >> 15) & 0x3F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLS_CBHS_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLS_CBHS_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLS_CBHS_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLS_CBHS_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLT_CBGT_32_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLT_CBGT_32_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBLT_CBGT_64_regs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBLT_CBGT_64_regs";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["cc"] = (insn >> 21) & 0x7;
    tree.fields["Rm"] = (insn >> 16) & 0x1F;
    tree.fields["imm9"] = (insn >> 5) & 0x1FF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CBNZ_32_compbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBNZ_32_compbranch";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 24) & 0x1;
    tree.fields["imm19"] = (insn >> 5) & 0x7FFFF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm19"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsZero", {}, {ir::ident("operand1")})), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_CBNZ_64_compbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBNZ_64_compbranch";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 24) & 0x1;
    tree.fields["imm19"] = (insn >> 5) & 0x7FFFF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm19"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsZero", {}, {ir::ident("operand1")})), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_CBZ_32_compbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBZ_32_compbranch";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 24) & 0x1;
    tree.fields["imm19"] = (insn >> 5) & 0x7FFFF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm19"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::func_call("IsZero", {}, {ir::ident("operand1")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_CBZ_64_compbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CBZ_64_compbranch";

    tree.fields["sf"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 24) & 0x1;
    tree.fields["imm19"] = (insn >> 5) & 0x7FFFF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("sf")}))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm19"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("operand1", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::func_call("IsZero", {}, {ir::ident("operand1")}), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_CFINV_M_pstate(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CFINV_M_pstate";

    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

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
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "C"), ir::unary_op(ir::UnaryOpKind::Not, ir::field_access(ir::ident("PSTATE"), "C"))));
    }

    return tree;
}

Tree build_ir_CFP_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CFP_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CHKFEAT_HF_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CHKFEAT_HF_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CHK")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::func_call("AArch64_ChkFeat", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)})})));
    }

    return tree;
}

Tree build_ir_CLRBHB_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CLRBHB_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CLRBHB")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_CLRBHB", {}, {})));
    }

    return tree;
}

Tree build_ir_CLREX_BN_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CLREX_BN_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("ClearExclusiveLocal", {}, {ir::func_call("ProcessorID", {}, {})})));
    }

    return tree;
}

Tree build_ir_COSP_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "COSP_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CPP_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CPP_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_CSDB_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "CSDB_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("ConsumptionOfSpeculativeDataBarrier", {}, {})));
    }

    return tree;
}

Tree build_ir_DC_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DC_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_DCPS1_DC_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DCPS1_DC_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("Halted", {}, {})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("DCPSInstruction", {}, {ir::ident("EL1")})));
    }

    return tree;
}

Tree build_ir_DCPS2_DC_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DCPS2_DC_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("Halted", {}, {})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("DCPSInstruction", {}, {ir::ident("EL2")})));
    }

    return tree;
}

Tree build_ir_DCPS3_DC_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DCPS3_DC_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("Halted", {}, {})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("DCPSInstruction", {}, {ir::ident("EL3")})));
    }

    return tree;
}

Tree build_ir_DGH_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DGH_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_DGH")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_DGH", {}, {})));
    }

    return tree;
}

Tree build_ir_DMB_BO_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DMB_BO_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["opc"] = (insn >> 5) & 0x3;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::var_decl("domain", "MBReqDomain", nullptr));
        stmts.push_back(ir::var_decl("types", "MBReqTypes", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_1;
            {
                std::vector<ir::StmtPtr> cb_2;
                cb_2.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_OuterShareable")));
                cs_1.push_back({ ir::bit_lit("00"), std::move(cb_2) });
            }
            {
                std::vector<ir::StmtPtr> cb_3;
                cb_3.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_Nonshareable")));
                cs_1.push_back({ ir::bit_lit("01"), std::move(cb_3) });
            }
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_InnerShareable")));
                cs_1.push_back({ ir::bit_lit("10"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_FullSystem")));
                cs_1.push_back({ ir::bit_lit("11"), std::move(cb_5) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_slice(ir::ident("CRm"), ir::int_lit(3), ir::int_lit(2), false), std::move(cs_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_6;
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_All")));
                cb_7.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_FullSystem")));
                cs_6.push_back({ ir::bit_lit("00"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_Reads")));
                cs_6.push_back({ ir::bit_lit("01"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_Writes")));
                cs_6.push_back({ ir::bit_lit("10"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cb_10.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_All")));
                cs_6.push_back({ ir::bit_lit("11"), std::move(cb_10) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_slice(ir::ident("CRm"), ir::int_lit(1), ir::int_lit(0), false), std::move(cs_6)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("DataMemoryBarrier", {}, {ir::ident("domain"), ir::ident("types")})));
    }

    return tree;
}

Tree build_ir_DRPS_64E_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DRPS_64E_branch_reg";

    tree.fields["opc"] = (insn >> 21) & 0xF;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["op3"] = (insn >> 10) & 0x3F;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["op4"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("Halted", {}, {})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL0"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("DRPSInstruction", {}, {})));
    }

    return tree;
}

Tree build_ir_DSB_BO_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DSB_BO_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["opc"] = (insn >> 5) & 0x3;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::var_decl("nXS", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("alias", "DSBAlias", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_1;
            {
                std::vector<ir::StmtPtr> cb_2;
                cb_2.push_back(ir::assign(ir::ident("alias"), ir::ident("DSBAlias_SSBB")));
                cs_1.push_back({ ir::bit_lit("0000"), std::move(cb_2) });
            }
            {
                std::vector<ir::StmtPtr> cb_3;
                cb_3.push_back(ir::assign(ir::ident("alias"), ir::ident("DSBAlias_PSSBB")));
                cs_1.push_back({ ir::bit_lit("0100"), std::move(cb_3) });
            }
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("alias"), ir::ident("DSBAlias_DSB")));
                cs_1.push_back({ nullptr, std::move(cb_4) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("CRm"), std::move(cs_1)));
        }
        stmts.push_back(ir::var_decl("domain", "MBReqDomain", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_5;
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_OuterShareable")));
                cs_5.push_back({ ir::bit_lit("00"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_Nonshareable")));
                cs_5.push_back({ ir::bit_lit("01"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_InnerShareable")));
                cs_5.push_back({ ir::bit_lit("10"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_FullSystem")));
                cs_5.push_back({ ir::bit_lit("11"), std::move(cb_9) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_slice(ir::ident("CRm"), ir::int_lit(3), ir::int_lit(2), false), std::move(cs_5)));
        }
        stmts.push_back(ir::var_decl("types", "MBReqTypes", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_10;
            {
                std::vector<ir::StmtPtr> cb_11;
                cb_11.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_All")));
                cb_11.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_FullSystem")));
                cs_10.push_back({ ir::bit_lit("00"), std::move(cb_11) });
            }
            {
                std::vector<ir::StmtPtr> cb_12;
                cb_12.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_Reads")));
                cs_10.push_back({ ir::bit_lit("01"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_13;
                cb_13.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_Writes")));
                cs_10.push_back({ ir::bit_lit("10"), std::move(cb_13) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::assign(ir::ident("types"), ir::ident("MBReqTypes_All")));
                cs_10.push_back({ ir::bit_lit("11"), std::move(cb_14) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_slice(ir::ident("CRm"), ir::int_lit(1), ir::int_lit(0), false), std::move(cs_10)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_15;
            {
                std::vector<ir::StmtPtr> cb_16;
                cb_16.push_back(ir::expr_stmt(ir::func_call("SpeculativeStoreBypassBarrierToVA", {}, {})));
                cs_15.push_back({ ir::ident("DSBAlias_SSBB"), std::move(cb_16) });
            }
            {
                std::vector<ir::StmtPtr> cb_17;
                cb_17.push_back(ir::expr_stmt(ir::func_call("SpeculativeStoreBypassBarrierToPA", {}, {})));
                cs_15.push_back({ ir::ident("DSBAlias_PSSBB"), std::move(cb_17) });
            }
            {
                std::vector<ir::StmtPtr> cb_18;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_19;
                    {
                        std::vector<ir::StmtPtr> bb_20;
                        bb_20.push_back(ir::assign(ir::ident("nXS"), ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("IsHCRXEL2Enabled", {}, {})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HCRX_EL2", {}, {}), "FnXS"), ir::bit_lit("1")))));
                        br_19.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::unary_op(ir::UnaryOpKind::Not, ir::ident("nXS")), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_XS")})), std::move(bb_20) });
                    }
                    cb_18.push_back(ir::if_stmt(std::move(br_19)));
                }
                cb_18.push_back(ir::expr_stmt(ir::func_call("DataSynchronizationBarrier", {}, {ir::ident("domain"), ir::ident("types"), ir::ident("nXS")})));
                cs_15.push_back({ ir::ident("DSBAlias_DSB"), std::move(cb_18) });
            }
            {
                std::vector<ir::StmtPtr> cb_21;
                cb_21.push_back(ir::expr_stmt(ir::ident("unreachable")));
                cs_15.push_back({ nullptr, std::move(cb_21) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("alias"), std::move(cs_15)));
        }
    }

    return tree;
}

Tree build_ir_DSB_BOn_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DSB_BOn_barriers";

    tree.fields["imm2"] = (insn >> 10) & 0x3;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_XS")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("types", "MBReqTypes", ir::ident("MBReqTypes_All")));
        stmts.push_back(ir::var_decl("nXS", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("alias", "DSBAlias", ir::ident("DSBAlias_DSB")));
        stmts.push_back(ir::var_decl("domain", "MBReqDomain", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_OuterShareable")));
                cs_3.push_back({ ir::bit_lit("00"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_Nonshareable")));
                cs_3.push_back({ ir::bit_lit("01"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_InnerShareable")));
                cs_3.push_back({ ir::bit_lit("10"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("domain"), ir::ident("MBReqDomain_FullSystem")));
                cs_3.push_back({ ir::bit_lit("11"), std::move(cb_7) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("imm2"), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_8;
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::expr_stmt(ir::func_call("SpeculativeStoreBypassBarrierToVA", {}, {})));
                cs_8.push_back({ ir::ident("DSBAlias_SSBB"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cb_10.push_back(ir::expr_stmt(ir::func_call("SpeculativeStoreBypassBarrierToPA", {}, {})));
                cs_8.push_back({ ir::ident("DSBAlias_PSSBB"), std::move(cb_10) });
            }
            {
                std::vector<ir::StmtPtr> cb_11;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_12;
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::ident("nXS"), ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("IsHCRXEL2Enabled", {}, {})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HCRX_EL2", {}, {}), "FnXS"), ir::bit_lit("1")))));
                        br_12.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::unary_op(ir::UnaryOpKind::Not, ir::ident("nXS")), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_XS")})), std::move(bb_13) });
                    }
                    cb_11.push_back(ir::if_stmt(std::move(br_12)));
                }
                cb_11.push_back(ir::expr_stmt(ir::func_call("DataSynchronizationBarrier", {}, {ir::ident("domain"), ir::ident("types"), ir::ident("nXS")})));
                cs_8.push_back({ ir::ident("DSBAlias_DSB"), std::move(cb_11) });
            }
            {
                std::vector<ir::StmtPtr> cb_14;
                cb_14.push_back(ir::expr_stmt(ir::ident("unreachable")));
                cs_8.push_back({ nullptr, std::move(cb_14) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("alias"), std::move(cs_8)));
        }
    }

    return tree;
}

Tree build_ir_DVP_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "DVP_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_ERET_64E_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ERET_64E_branch_reg";

    tree.fields["opc"] = (insn >> 21) & 0xF;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["op4"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("pac", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL0")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckForERetTrap", {}, {ir::ident("pac"), ir::ident("use_key_a")})));
        stmts.push_back(ir::let_decl("target", "bits(64)", ir::func_call("ELR_ELx", {}, {})));
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_ExceptionReturn", {}, {ir::ident("target"), ir::func_call("SPSR_ELx", {}, {})})));
    }

    return tree;
}

Tree build_ir_ERETAA_64E_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ERETAA_64E_branch_reg";

    tree.fields["opc"] = (insn >> 21) & 0xF;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["op4"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("pac", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL0")), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckForERetTrap", {}, {ir::ident("pac"), ir::ident("use_key_a")})));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("ELR_ELx", {}, {})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_ExceptionReturn", {}, {ir::ident("target"), ir::func_call("SPSR_ELx", {}, {})})));
    }

    return tree;
}

Tree build_ir_ERETAB_64E_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ERETAB_64E_branch_reg";

    tree.fields["opc"] = (insn >> 21) & 0xF;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["op4"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("pac", "boolean", ir::bool_lit(true)));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL0")), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckForERetTrap", {}, {ir::ident("pac"), ir::ident("use_key_a")})));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("ELR_ELx", {}, {})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                br_5.push_back({ nullptr, std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_ExceptionReturn", {}, {ir::ident("target"), ir::func_call("SPSR_ELx", {}, {})})));
    }

    return tree;
}

Tree build_ir_ESB_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ESB_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_RAS")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("SynchronizeErrors", {}, {})));
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_ESBOperation", {}, {})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("AArch64_vESBOperation", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("EL2Enabled", {}, {})), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::expr_stmt(ir::func_call("AArch64_dESBOperation", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_E3DSE")}), ir::bin_op(ir::BinOpKind::Ne, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL3"))), std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("TakeUnmaskedSErrorInterrupts", {}, {})));
    }

    return tree;
}

Tree build_ir_GCSB_HD_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSB_HD_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("GCSSynchronizationBarrier", {}, {})));
    }

    return tree;
}

Tree build_ir_GCSPOPCX_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSPOPCX_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GCSPOPM_SYSL_RC_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSPOPM_SYSL_RC_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GCSPOPX_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSPOPX_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GCSPUSHM_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSPUSHM_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GCSPUSHX_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSPUSHX_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GCSSS1_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSSS1_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GCSSS2_SYSL_RC_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GCSSS2_SYSL_RC_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GIC_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GIC_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GICR_SYSL_RC_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GICR_SYSL_RC_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_GSB_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "GSB_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_HINT_HM_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "HINT_HM_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::var_decl("op", "SystemHintOp", nullptr));
        stmts.push_back(ir::var_decl("stream", "boolean", nullptr));
        stmts.push_back(ir::var_decl("priority", "boolean", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_1;
            {
                std::vector<ir::StmtPtr> cb_2;
                cb_2.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_NOP")));
                cs_1.push_back({ ir::bit_lit("0000000"), std::move(cb_2) });
            }
            {
                std::vector<ir::StmtPtr> cb_3;
                cb_3.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_YIELD")));
                cs_1.push_back({ ir::bit_lit("0000001"), std::move(cb_3) });
            }
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_WFE")));
                cs_1.push_back({ ir::bit_lit("0000010"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_WFI")));
                cs_1.push_back({ ir::bit_lit("0000011"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_6;
                cb_6.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_SEV")));
                cs_1.push_back({ ir::bit_lit("0000100"), std::move(cb_6) });
            }
            {
                std::vector<ir::StmtPtr> cb_7;
                cb_7.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_SEVL")));
                cs_1.push_back({ ir::bit_lit("0000101"), std::move(cb_7) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
                    {
                        std::vector<ir::StmtPtr> bb_10;
                        br_9.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_DGH")})), std::move(bb_10) });
                    }
                    cb_8.push_back(ir::if_stmt(std::move(br_9)));
                }
                cb_8.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_DGH")));
                cs_1.push_back({ ir::bit_lit("0000110"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_11;
                cb_11.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("XPACLRI")})));
                cs_1.push_back({ ir::bit_lit("0000111"), std::move(cb_11) });
            }
            {
                std::vector<ir::StmtPtr> cb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_13;
                    {
                        std::vector<ir::StmtPtr> cb_14;
                        cb_14.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACIA1716")})));
                        cs_13.push_back({ ir::bit_lit("000"), std::move(cb_14) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_15;
                        cb_15.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACIB1716")})));
                        cs_13.push_back({ ir::bit_lit("010"), std::move(cb_15) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_16;
                        cb_16.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AUTIA1716")})));
                        cs_13.push_back({ ir::bit_lit("100"), std::move(cb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_17;
                        cb_17.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AUTIB1716")})));
                        cs_13.push_back({ ir::bit_lit("110"), std::move(cb_17) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_18;
                        cs_13.push_back({ nullptr, std::move(cb_18) });
                    }
                    cb_12.push_back(ir::case_stmt(ir::ident("op2"), std::move(cs_13)));
                }
                cs_1.push_back({ ir::bit_lit("0001xxx"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_19;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_20;
                    {
                        std::vector<ir::StmtPtr> bb_21;
                        br_20.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_RAS")})), std::move(bb_21) });
                    }
                    cb_19.push_back(ir::if_stmt(std::move(br_20)));
                }
                cb_19.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_ESB")));
                cs_1.push_back({ ir::bit_lit("0010000"), std::move(cb_19) });
            }
            {
                std::vector<ir::StmtPtr> cb_22;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_23;
                    {
                        std::vector<ir::StmtPtr> bb_24;
                        br_23.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SPE")})), std::move(bb_24) });
                    }
                    cb_22.push_back(ir::if_stmt(std::move(br_23)));
                }
                cb_22.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_PSB")));
                cs_1.push_back({ ir::bit_lit("0010001"), std::move(cb_22) });
            }
            {
                std::vector<ir::StmtPtr> cb_25;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_26;
                    {
                        std::vector<ir::StmtPtr> bb_27;
                        br_26.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_TRF")})), std::move(bb_27) });
                    }
                    cb_25.push_back(ir::if_stmt(std::move(br_26)));
                }
                cb_25.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_TSB")));
                cs_1.push_back({ ir::bit_lit("0010010"), std::move(cb_25) });
            }
            {
                std::vector<ir::StmtPtr> cb_28;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_29;
                    {
                        std::vector<ir::StmtPtr> bb_30;
                        br_29.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")})), std::move(bb_30) });
                    }
                    cb_28.push_back(ir::if_stmt(std::move(br_29)));
                }
                cb_28.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_GCSB")));
                cs_1.push_back({ ir::bit_lit("0010011"), std::move(cb_28) });
            }
            {
                std::vector<ir::StmtPtr> cb_31;
                cb_31.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_CSDB")));
                cs_1.push_back({ ir::bit_lit("0010100"), std::move(cb_31) });
            }
            {
                std::vector<ir::StmtPtr> cb_32;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_33;
                    {
                        std::vector<ir::StmtPtr> bb_34;
                        br_33.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CLRBHB")})), std::move(bb_34) });
                    }
                    cb_32.push_back(ir::if_stmt(std::move(br_33)));
                }
                cb_32.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_CLRBHB")));
                cs_1.push_back({ ir::bit_lit("0010110"), std::move(cb_32) });
            }
            {
                std::vector<ir::StmtPtr> cb_35;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_36;
                    {
                        std::vector<ir::StmtPtr> cb_37;
                        cb_37.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACIAZ")})));
                        cs_36.push_back({ ir::bit_lit("000"), std::move(cb_37) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_38;
                        cb_38.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACIASP")})));
                        cs_36.push_back({ ir::bit_lit("001"), std::move(cb_38) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_39;
                        cb_39.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACIBZ")})));
                        cs_36.push_back({ ir::bit_lit("010"), std::move(cb_39) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_40;
                        cb_40.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACIBSP")})));
                        cs_36.push_back({ ir::bit_lit("011"), std::move(cb_40) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_41;
                        cb_41.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AUTIAZ")})));
                        cs_36.push_back({ ir::bit_lit("100"), std::move(cb_41) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_42;
                        cb_42.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AUTIASP")})));
                        cs_36.push_back({ ir::bit_lit("101"), std::move(cb_42) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_43;
                        cb_43.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AUTIBZ")})));
                        cs_36.push_back({ ir::bit_lit("110"), std::move(cb_43) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_44;
                        cb_44.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AUTIBSP")})));
                        cs_36.push_back({ ir::bit_lit("111"), std::move(cb_44) });
                    }
                    cb_35.push_back(ir::case_stmt(ir::ident("op2"), std::move(cs_36)));
                }
                cs_1.push_back({ ir::bit_lit("0011xxx"), std::move(cb_35) });
            }
            {
                std::vector<ir::StmtPtr> cb_45;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_46;
                    {
                        std::vector<ir::StmtPtr> bb_47;
                        br_46.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")})), std::move(bb_47) });
                    }
                    cb_45.push_back(ir::if_stmt(std::move(br_46)));
                }
                cb_45.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_BTI", {}, {ir::bit_slice(ir::ident("op2"), ir::int_lit(2), ir::int_lit(1), false)})})));
                cb_45.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_BTI")));
                cs_1.push_back({ ir::bit_lit("0100xx0"), std::move(cb_45) });
            }
            {
                std::vector<ir::StmtPtr> cb_48;
                cb_48.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("PACM")})));
                cs_1.push_back({ ir::bit_lit("0100111"), std::move(cb_48) });
            }
            {
                std::vector<ir::StmtPtr> cb_49;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_50;
                    {
                        std::vector<ir::StmtPtr> bb_51;
                        br_50.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CHK")})), std::move(bb_51) });
                    }
                    cb_49.push_back(ir::if_stmt(std::move(br_50)));
                }
                cb_49.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_CHKFEAT")));
                cs_1.push_back({ ir::bit_lit("0101000"), std::move(cb_49) });
            }
            {
                std::vector<ir::StmtPtr> cb_52;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_53;
                    {
                        std::vector<ir::StmtPtr> bb_54;
                        br_53.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PCDPHINT")})), std::move(bb_54) });
                    }
                    cb_52.push_back(ir::if_stmt(std::move(br_53)));
                }
                cb_52.push_back(ir::assign(ir::ident("stream"), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("op2"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1"))));
                cb_52.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_STSHH")));
                cs_1.push_back({ ir::bit_lit("011000x"), std::move(cb_52) });
            }
            {
                std::vector<ir::StmtPtr> cb_55;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_56;
                    {
                        std::vector<ir::StmtPtr> bb_57;
                        br_56.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMH")})), std::move(bb_57) });
                    }
                    cb_55.push_back(ir::if_stmt(std::move(br_56)));
                }
                cb_55.push_back(ir::assign(ir::ident("priority"), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("op2"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1"))));
                cb_55.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_SHUH")));
                cs_1.push_back({ ir::bit_lit("011001x"), std::move(cb_55) });
            }
            {
                std::vector<ir::StmtPtr> cb_58;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_59;
                    {
                        std::vector<ir::StmtPtr> bb_60;
                        br_59.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMH")})), std::move(bb_60) });
                    }
                    cb_58.push_back(ir::if_stmt(std::move(br_59)));
                }
                cb_58.push_back(ir::assign(ir::ident("op"), ir::ident("SystemHintOp_STCPH")));
                cs_1.push_back({ ir::bit_lit("0110100"), std::move(cb_58) });
            }
            {
                std::vector<ir::StmtPtr> cb_61;
                cs_1.push_back({ nullptr, std::move(cb_61) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_62;
            {
                std::vector<ir::StmtPtr> cb_63;
                cb_63.push_back(ir::expr_stmt(ir::func_call("Hint_Yield", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_YIELD"), std::move(cb_63) });
            }
            {
                std::vector<ir::StmtPtr> cb_64;
                cb_64.push_back(ir::expr_stmt(ir::func_call("Hint_DGH", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_DGH"), std::move(cb_64) });
            }
            {
                std::vector<ir::StmtPtr> cb_65;
                cb_65.push_back(ir::expr_stmt(ir::func_call("Hint_WFE", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_WFE"), std::move(cb_65) });
            }
            {
                std::vector<ir::StmtPtr> cb_66;
                cb_66.push_back(ir::expr_stmt(ir::func_call("Hint_WFI", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_WFI"), std::move(cb_66) });
            }
            {
                std::vector<ir::StmtPtr> cb_67;
                cb_67.push_back(ir::expr_stmt(ir::func_call("SendEvent", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_SEV"), std::move(cb_67) });
            }
            {
                std::vector<ir::StmtPtr> cb_68;
                cb_68.push_back(ir::expr_stmt(ir::func_call("SendEventLocal", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_SEVL"), std::move(cb_68) });
            }
            {
                std::vector<ir::StmtPtr> cb_69;
                cb_69.push_back(ir::expr_stmt(ir::func_call("SynchronizeErrors", {}, {})));
                cb_69.push_back(ir::expr_stmt(ir::func_call("AArch64_ESBOperation", {}, {})));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_70;
                    {
                        std::vector<ir::StmtPtr> bb_71;
                        bb_71.push_back(ir::expr_stmt(ir::func_call("AArch64_vESBOperation", {}, {})));
                        br_70.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("EL2Enabled", {}, {})), std::move(bb_71) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_72;
                        bb_72.push_back(ir::expr_stmt(ir::func_call("AArch64_dESBOperation", {}, {})));
                        br_70.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_E3DSE")}), ir::bin_op(ir::BinOpKind::Ne, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL3"))), std::move(bb_72) });
                    }
                    cb_69.push_back(ir::if_stmt(std::move(br_70)));
                }
                cb_69.push_back(ir::expr_stmt(ir::func_call("TakeUnmaskedSErrorInterrupts", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_ESB"), std::move(cb_69) });
            }
            {
                std::vector<ir::StmtPtr> cb_73;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_74;
                    {
                        std::vector<ir::StmtPtr> bb_75;
                        bb_75.push_back(ir::let_decl("trap_to_el2", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("EL2Enabled", {}, {})), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsInHost", {}, {}))), ir::bin_op(ir::BinOpKind::LogicalOr, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaveEL", {}, {ir::ident("EL3")})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("SCR_EL3", {}, {}), "FGTEn"), ir::bit_lit("1")))), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HFGITR_EL2", {}, {}), "PSBCSYNC"), ir::bit_lit("1")))));
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_76;
                            {
                                std::vector<ir::StmtPtr> bb_77;
                                bb_77.push_back(ir::var_decl("except", "ExceptionRecord", ir::func_call("ExceptionSyndrome", {}, {ir::ident("Exception_LDST64BTrap")})));
                                bb_77.push_back(ir::assign(ir::field_access(ir::field_access(ir::ident("except"), "syndrome"), "iss"), ir::bit_slice(ir::int_lit(3), ir::int_lit(24), ir::int_lit(0), false)));
                                bb_77.push_back(ir::let_decl("preferred_exception_return", "bits(64)", ir::func_call("ThisInstrAddr", {}, {})));
                                bb_77.push_back(ir::let_decl("vect_offset", "integer", ir::int_lit(0)));
                                bb_77.push_back(ir::expr_stmt(ir::func_call("AArch64_TakeException", {}, {ir::ident("EL2"), ir::ident("except"), ir::ident("preferred_exception_return"), ir::ident("vect_offset")})));
                                br_76.push_back({ ir::ident("trap_to_el2"), std::move(bb_77) });
                            }
                            bb_75.push_back(ir::if_stmt(std::move(br_76)));
                        }
                        br_74.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FGT")}), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SPEv1p5")})), std::move(bb_75) });
                    }
                    cb_73.push_back(ir::if_stmt(std::move(br_74)));
                }
                cb_73.push_back(ir::expr_stmt(ir::func_call("ProfilingSynchronizationBarrier", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_PSB"), std::move(cb_73) });
            }
            {
                std::vector<ir::StmtPtr> cb_78;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_79;
                    {
                        std::vector<ir::StmtPtr> bb_80;
                        bb_80.push_back(ir::let_decl("trap_to_el2", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("EL2Enabled", {}, {})), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsInHost", {}, {}))), ir::bin_op(ir::BinOpKind::LogicalOr, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaveEL", {}, {ir::ident("EL3")})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("SCR_EL3", {}, {}), "FGTEn2"), ir::bit_lit("1")))), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HFGITR2_EL2", {}, {}), "TSBCSYNC"), ir::bit_lit("1")))));
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_81;
                            {
                                std::vector<ir::StmtPtr> bb_82;
                                bb_82.push_back(ir::var_decl("except", "ExceptionRecord", ir::func_call("ExceptionSyndrome", {}, {ir::ident("Exception_LDST64BTrap")})));
                                bb_82.push_back(ir::assign(ir::field_access(ir::field_access(ir::ident("except"), "syndrome"), "iss"), ir::bit_slice(ir::int_lit(4), ir::int_lit(24), ir::int_lit(0), false)));
                                bb_82.push_back(ir::let_decl("preferred_exception_return", "bits(64)", ir::func_call("ThisInstrAddr", {}, {})));
                                bb_82.push_back(ir::let_decl("vect_offset", "integer", ir::int_lit(0)));
                                bb_82.push_back(ir::expr_stmt(ir::func_call("AArch64_TakeException", {}, {ir::ident("EL2"), ir::ident("except"), ir::ident("preferred_exception_return"), ir::ident("vect_offset")})));
                                br_81.push_back({ ir::ident("trap_to_el2"), std::move(bb_82) });
                            }
                            bb_80.push_back(ir::if_stmt(std::move(br_81)));
                        }
                        br_79.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FGT2")}), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_TRBEv1p1")})), std::move(bb_80) });
                    }
                    cb_78.push_back(ir::if_stmt(std::move(br_79)));
                }
                cb_78.push_back(ir::expr_stmt(ir::func_call("TraceSynchronizationBarrier", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_TSB"), std::move(cb_78) });
            }
            {
                std::vector<ir::StmtPtr> cb_83;
                cb_83.push_back(ir::expr_stmt(ir::func_call("GCSSynchronizationBarrier", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_GCSB"), std::move(cb_83) });
            }
            {
                std::vector<ir::StmtPtr> cb_84;
                cb_84.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)}), ir::func_call("AArch64_ChkFeat", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)})})));
                cs_62.push_back({ ir::ident("SystemHintOp_CHKFEAT"), std::move(cb_84) });
            }
            {
                std::vector<ir::StmtPtr> cb_85;
                cb_85.push_back(ir::expr_stmt(ir::func_call("ConsumptionOfSpeculativeDataBarrier", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_CSDB"), std::move(cb_85) });
            }
            {
                std::vector<ir::StmtPtr> cb_86;
                cb_86.push_back(ir::expr_stmt(ir::func_call("Hint_CLRBHB", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_CLRBHB"), std::move(cb_86) });
            }
            {
                std::vector<ir::StmtPtr> cb_87;
                cb_87.push_back(ir::expr_stmt(ir::func_call("SetBTypeNext", {}, {ir::bit_lit("00")})));
                cs_62.push_back({ ir::ident("SystemHintOp_BTI"), std::move(cb_87) });
            }
            {
                std::vector<ir::StmtPtr> cb_88;
                cb_88.push_back(ir::expr_stmt(ir::func_call("Hint_StoreShared", {}, {ir::ident("stream")})));
                cs_62.push_back({ ir::ident("SystemHintOp_STSHH"), std::move(cb_88) });
            }
            {
                std::vector<ir::StmtPtr> cb_89;
                cb_89.push_back(ir::expr_stmt(ir::func_call("Hint_SharedUpdate", {}, {ir::ident("priority")})));
                cs_62.push_back({ ir::ident("SystemHintOp_SHUH"), std::move(cb_89) });
            }
            {
                std::vector<ir::StmtPtr> cb_90;
                cb_90.push_back(ir::expr_stmt(ir::func_call("Hint_StoreConcurrentPriority", {}, {})));
                cs_62.push_back({ ir::ident("SystemHintOp_STCPH"), std::move(cb_90) });
            }
            {
                std::vector<ir::StmtPtr> cb_91;
                cb_91.push_back(ir::return_stmt(nullptr));
                cs_62.push_back({ ir::ident("SystemHintOp_NOP"), std::move(cb_91) });
            }
            {
                std::vector<ir::StmtPtr> cb_92;
                cb_92.push_back(ir::expr_stmt(ir::ident("unreachable")));
                cs_62.push_back({ nullptr, std::move(cb_92) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op"), std::move(cs_62)));
        }
    }

    return tree;
}

Tree build_ir_HLT_EX_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "HLT_EX_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalOr, ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("EDSCR", {}, {}), "HDE"), ir::bit_lit("0")), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaltingAllowed", {}, {}))), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::bool_lit(true)})));
                br_1.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("is_async", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::let_decl("fault", "FaultRecord", ir::func_call("NoFault", {}, {})));
        stmts.push_back(ir::expr_stmt(ir::func_call("Halt", {}, {ir::ident("DebugHalt_HaltInstruction"), ir::ident("is_async"), ir::ident("fault")})));
    }

    return tree;
}

Tree build_ir_HVC_EX_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "HVC_EX_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaveEL", {}, {ir::ident("EL2")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("imm", "bits(16)", ir::ident("imm16")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL0")), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL1")), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("EL2Enabled", {}, {}))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
            {
                std::vector<ir::StmtPtr> bb_8;
                bb_8.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaveEL", {}, {ir::ident("EL3")})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HCR_EL2", {}, {}), "HCD"), ir::bit_lit("1"))), std::move(bb_8) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_7)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                bb_10.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_9.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("HaveEL", {}, {ir::ident("EL3")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("SCR_EL3", {}, {}), "HCE"), ir::bit_lit("0"))), std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CallHypervisor", {}, {ir::ident("imm")})));
    }

    return tree;
}

Tree build_ir_IC_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "IC_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_ISB_BI_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "ISB_BI_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["opc"] = (insn >> 5) & 0x3;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("InstructionSynchronizationBarrier", {}, {})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BRBEISB", {}, {})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BRBE")}), ir::func_call("BRBEBranchOnISB", {}, {})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_MLBI_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MLBI_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_MRRS_RS_systemmovepr(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MRRS_RS_systemmovepr";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["o0"] = (insn >> 19) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SYSREG128")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("Rt"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1")), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("t2", "integer", ir::func_call("UInt", {}, {ir::bin_op(ir::BinOpKind::Add, ir::ident("Rt"), ir::int_lit(1))})));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_concat({ir::bit_lit("1"), ir::ident("o0")})));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysRegRead128", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t"), ir::ident("t2")})));
    }

    return tree;
}

Tree build_ir_MRS_RS_systemmove(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MRS_RS_systemmove";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["o0"] = (insn >> 19) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_concat({ir::bit_lit("1"), ir::ident("o0")})));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysRegRead", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t")})));
    }

    return tree;
}

Tree build_ir_MSR_SI_pstate(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MSR_SI_pstate";

    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("CFINV")})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("op1"), ir::bit_lit("000")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("op2"), ir::bit_lit("000"))), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("XAFLAG")})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("op1"), ir::bit_lit("000")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("op2"), ir::bit_lit("001"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                bb_6.push_back(ir::expr_stmt(ir::func_call("See", {}, {ir::ident("AXFLAG")})));
                br_5.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::ident("op1"), ir::bit_lit("000")), ir::bin_op(ir::BinOpKind::Eq, ir::ident("op2"), ir::bit_lit("010"))), std::move(bb_6) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        stmts.push_back(ir::var_decl("min_EL", "bits(2)", nullptr));
        stmts.push_back(ir::var_decl("need_secure", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_7;
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL1")));
                cs_7.push_back({ ir::bit_lit("00x"), std::move(cb_8) });
            }
            {
                std::vector<ir::StmtPtr> cb_9;
                cb_9.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL1")));
                cs_7.push_back({ ir::bit_lit("010"), std::move(cb_9) });
            }
            {
                std::vector<ir::StmtPtr> cb_10;
                cb_10.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL0")));
                cs_7.push_back({ ir::bit_lit("011"), std::move(cb_10) });
            }
            {
                std::vector<ir::StmtPtr> cb_11;
                cb_11.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL2")));
                cs_7.push_back({ ir::bit_lit("100"), std::move(cb_11) });
            }
            {
                std::vector<ir::StmtPtr> cb_12;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_13;
                    {
                        std::vector<ir::StmtPtr> bb_14;
                        br_13.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_VHE")})), std::move(bb_14) });
                    }
                    cb_12.push_back(ir::if_stmt(std::move(br_13)));
                }
                cb_12.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL2")));
                cs_7.push_back({ ir::bit_lit("101"), std::move(cb_12) });
            }
            {
                std::vector<ir::StmtPtr> cb_15;
                cb_15.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL3")));
                cs_7.push_back({ ir::bit_lit("110"), std::move(cb_15) });
            }
            {
                std::vector<ir::StmtPtr> cb_16;
                cb_16.push_back(ir::assign(ir::ident("min_EL"), ir::ident("EL1")));
                cb_16.push_back(ir::assign(ir::ident("need_secure"), ir::bool_lit(true)));
                cs_7.push_back({ ir::bit_lit("111"), std::move(cb_16) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("op1"), std::move(cs_7)));
        }
        stmts.push_back(ir::let_decl("operand", "bits(4)", ir::ident("CRm")));
        stmts.push_back(ir::var_decl("field", "PSTATEField", nullptr));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_17;
            {
                std::vector<ir::StmtPtr> cb_18;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_19;
                    {
                        std::vector<ir::StmtPtr> bb_20;
                        br_19.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_UAO")})), std::move(bb_20) });
                    }
                    cb_18.push_back(ir::if_stmt(std::move(br_19)));
                }
                cb_18.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_UAO")));
                cs_17.push_back({ ir::bit_lit("000011"), std::move(cb_18) });
            }
            {
                std::vector<ir::StmtPtr> cb_21;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_22;
                    {
                        std::vector<ir::StmtPtr> bb_23;
                        br_22.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAN")})), std::move(bb_23) });
                    }
                    cb_21.push_back(ir::if_stmt(std::move(br_22)));
                }
                cb_21.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_PAN")));
                cs_17.push_back({ ir::bit_lit("000100"), std::move(cb_21) });
            }
            {
                std::vector<ir::StmtPtr> cb_24;
                cb_24.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_SP")));
                cs_17.push_back({ ir::bit_lit("000101"), std::move(cb_24) });
            }
            {
                std::vector<ir::StmtPtr> cb_25;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_26;
                    {
                        std::vector<ir::StmtPtr> cb_27;
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_28;
                            {
                                std::vector<ir::StmtPtr> bb_29;
                                br_28.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_NMI")})), std::move(bb_29) });
                            }
                            cb_27.push_back(ir::if_stmt(std::move(br_28)));
                        }
                        cb_27.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_ALLINT")));
                        cs_26.push_back({ ir::bit_lit("000x"), std::move(cb_27) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_30;
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_31;
                            {
                                std::vector<ir::StmtPtr> bb_32;
                                br_31.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_EBEP")})), std::move(bb_32) });
                            }
                            cb_30.push_back(ir::if_stmt(std::move(br_31)));
                        }
                        cb_30.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_PM")));
                        cs_26.push_back({ ir::bit_lit("001x"), std::move(cb_30) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_33;
                        cs_26.push_back({ nullptr, std::move(cb_33) });
                    }
                    cb_25.push_back(ir::case_stmt(ir::ident("CRm"), std::move(cs_26)));
                }
                cs_17.push_back({ ir::bit_lit("001000"), std::move(cb_25) });
            }
            {
                std::vector<ir::StmtPtr> cb_34;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_35;
                    {
                        std::vector<ir::StmtPtr> bb_36;
                        br_35.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_DIT")})), std::move(bb_36) });
                    }
                    cb_34.push_back(ir::if_stmt(std::move(br_35)));
                }
                cb_34.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_DIT")));
                cs_17.push_back({ ir::bit_lit("011010"), std::move(cb_34) });
            }
            {
                std::vector<ir::StmtPtr> cb_37;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_38;
                    {
                        std::vector<ir::StmtPtr> cb_39;
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_40;
                            {
                                std::vector<ir::StmtPtr> bb_41;
                                br_40.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SME")})), std::move(bb_41) });
                            }
                            cb_39.push_back(ir::if_stmt(std::move(br_40)));
                        }
                        cb_39.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_SVCRSM")));
                        cs_38.push_back({ ir::bit_lit("001x"), std::move(cb_39) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_42;
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_43;
                            {
                                std::vector<ir::StmtPtr> bb_44;
                                br_43.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SME")})), std::move(bb_44) });
                            }
                            cb_42.push_back(ir::if_stmt(std::move(br_43)));
                        }
                        cb_42.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_SVCRZA")));
                        cs_38.push_back({ ir::bit_lit("010x"), std::move(cb_42) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_45;
                        {
                            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_46;
                            {
                                std::vector<ir::StmtPtr> bb_47;
                                br_46.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SME")})), std::move(bb_47) });
                            }
                            cb_45.push_back(ir::if_stmt(std::move(br_46)));
                        }
                        cb_45.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_SVCRSMZA")));
                        cs_38.push_back({ ir::bit_lit("011x"), std::move(cb_45) });
                    }
                    {
                        std::vector<ir::StmtPtr> cb_48;
                        cs_38.push_back({ nullptr, std::move(cb_48) });
                    }
                    cb_37.push_back(ir::case_stmt(ir::ident("CRm"), std::move(cs_38)));
                }
                cs_17.push_back({ ir::bit_lit("011011"), std::move(cb_37) });
            }
            {
                std::vector<ir::StmtPtr> cb_49;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_50;
                    {
                        std::vector<ir::StmtPtr> bb_51;
                        br_50.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_MTE")})), std::move(bb_51) });
                    }
                    cb_49.push_back(ir::if_stmt(std::move(br_50)));
                }
                cb_49.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_TCO")));
                cs_17.push_back({ ir::bit_lit("011100"), std::move(cb_49) });
            }
            {
                std::vector<ir::StmtPtr> cb_52;
                cb_52.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_DAIFSet")));
                cs_17.push_back({ ir::bit_lit("011110"), std::move(cb_52) });
            }
            {
                std::vector<ir::StmtPtr> cb_53;
                cb_53.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_DAIFClr")));
                cs_17.push_back({ ir::bit_lit("011111"), std::move(cb_53) });
            }
            {
                std::vector<ir::StmtPtr> cb_54;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_55;
                    {
                        std::vector<ir::StmtPtr> bb_56;
                        br_55.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SSBS")})), std::move(bb_56) });
                    }
                    cb_54.push_back(ir::if_stmt(std::move(br_55)));
                }
                cb_54.push_back(ir::assign(ir::ident("field"), ir::ident("PSTATEField_SSBS")));
                cs_17.push_back({ ir::bit_lit("011001"), std::move(cb_54) });
            }
            {
                std::vector<ir::StmtPtr> cb_57;
                cs_17.push_back({ nullptr, std::move(cb_57) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("op1"), ir::ident("op2")}), std::move(cs_17)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_58;
            {
                std::vector<ir::StmtPtr> bb_59;
                bb_59.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_58.push_back({ ir::bin_op(ir::BinOpKind::Lt, ir::func_call("UInt", {}, {ir::field_access(ir::ident("PSTATE"), "EL")}), ir::func_call("UInt", {}, {ir::ident("min_EL")})), std::move(bb_59) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_58)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_60;
            {
                std::vector<ir::StmtPtr> bb_61;
                bb_61.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_60.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::ident("need_secure"), ir::bin_op(ir::BinOpKind::Ne, ir::func_call("CurrentSecurityState", {}, {}), ir::ident("SS_Secure"))), std::move(bb_61) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_60)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_62;
            {
                std::vector<ir::StmtPtr> cb_63;
                cb_63.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "SSBS"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_SSBS"), std::move(cb_63) });
            }
            {
                std::vector<ir::StmtPtr> cb_64;
                cb_64.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "SP"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_SP"), std::move(cb_64) });
            }
            {
                std::vector<ir::StmtPtr> cb_65;
                cb_65.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckDAIFAccess", {}, {ir::ident("PSTATEField_DAIFSet")})));
                cb_65.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "D"), ir::bin_op(ir::BinOpKind::Or, ir::field_access(ir::ident("PSTATE"), "D"), ir::bit_slice(ir::ident("operand"), ir::int_lit(3), ir::int_lit(3), false))));
                cb_65.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "A"), ir::bin_op(ir::BinOpKind::Or, ir::field_access(ir::ident("PSTATE"), "A"), ir::bit_slice(ir::ident("operand"), ir::int_lit(2), ir::int_lit(2), false))));
                cb_65.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "I"), ir::bin_op(ir::BinOpKind::Or, ir::field_access(ir::ident("PSTATE"), "I"), ir::bit_slice(ir::ident("operand"), ir::int_lit(1), ir::int_lit(1), false))));
                cb_65.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "F"), ir::bin_op(ir::BinOpKind::Or, ir::field_access(ir::ident("PSTATE"), "F"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false))));
                cs_62.push_back({ ir::ident("PSTATEField_DAIFSet"), std::move(cb_65) });
            }
            {
                std::vector<ir::StmtPtr> cb_66;
                cb_66.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckDAIFAccess", {}, {ir::ident("PSTATEField_DAIFClr")})));
                cb_66.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "D"), ir::bin_op(ir::BinOpKind::And, ir::field_access(ir::ident("PSTATE"), "D"), ir::unary_op(ir::UnaryOpKind::Not, ir::bit_slice(ir::ident("operand"), ir::int_lit(3), ir::int_lit(3), false)))));
                cb_66.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "A"), ir::bin_op(ir::BinOpKind::And, ir::field_access(ir::ident("PSTATE"), "A"), ir::unary_op(ir::UnaryOpKind::Not, ir::bit_slice(ir::ident("operand"), ir::int_lit(2), ir::int_lit(2), false)))));
                cb_66.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "I"), ir::bin_op(ir::BinOpKind::And, ir::field_access(ir::ident("PSTATE"), "I"), ir::unary_op(ir::UnaryOpKind::Not, ir::bit_slice(ir::ident("operand"), ir::int_lit(1), ir::int_lit(1), false)))));
                cb_66.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "F"), ir::bin_op(ir::BinOpKind::And, ir::field_access(ir::ident("PSTATE"), "F"), ir::unary_op(ir::UnaryOpKind::Not, ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)))));
                cs_62.push_back({ ir::ident("PSTATEField_DAIFClr"), std::move(cb_66) });
            }
            {
                std::vector<ir::StmtPtr> cb_67;
                cb_67.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "PAN"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_PAN"), std::move(cb_67) });
            }
            {
                std::vector<ir::StmtPtr> cb_68;
                cb_68.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "UAO"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_UAO"), std::move(cb_68) });
            }
            {
                std::vector<ir::StmtPtr> cb_69;
                cb_69.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "DIT"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_DIT"), std::move(cb_69) });
            }
            {
                std::vector<ir::StmtPtr> cb_70;
                cb_70.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "TCO"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_TCO"), std::move(cb_70) });
            }
            {
                std::vector<ir::StmtPtr> cb_71;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_72;
                    {
                        std::vector<ir::StmtPtr> bb_73;
                        bb_73.push_back(ir::expr_stmt(ir::func_call("AArch64_SystemAccessTrap", {}, {ir::ident("EL2"), ir::int_lit(24)})));
                        br_72.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL1")), ir::func_call("IsHCRXEL2Enabled", {}, {})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HCRX_EL2", {}, {}), "TALLINT"), ir::bit_lit("1"))), ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1"))), std::move(bb_73) });
                    }
                    cb_71.push_back(ir::if_stmt(std::move(br_72)));
                }
                cb_71.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "ALLINT"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_ALLINT"), std::move(cb_71) });
            }
            {
                std::vector<ir::StmtPtr> cb_74;
                cb_74.push_back(ir::expr_stmt(ir::func_call("CheckSMEAccess", {}, {})));
                cb_74.push_back(ir::expr_stmt(ir::func_call("SetPSTATE_SM", {}, {ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)})));
                cs_62.push_back({ ir::ident("PSTATEField_SVCRSM"), std::move(cb_74) });
            }
            {
                std::vector<ir::StmtPtr> cb_75;
                cb_75.push_back(ir::expr_stmt(ir::func_call("CheckSMEAccess", {}, {})));
                cb_75.push_back(ir::expr_stmt(ir::func_call("SetPSTATE_ZA", {}, {ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)})));
                cs_62.push_back({ ir::ident("PSTATEField_SVCRZA"), std::move(cb_75) });
            }
            {
                std::vector<ir::StmtPtr> cb_76;
                cb_76.push_back(ir::expr_stmt(ir::func_call("CheckSMEAccess", {}, {})));
                cb_76.push_back(ir::expr_stmt(ir::func_call("SetPSTATE_SM", {}, {ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)})));
                cb_76.push_back(ir::expr_stmt(ir::func_call("SetPSTATE_ZA", {}, {ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)})));
                cs_62.push_back({ ir::ident("PSTATEField_SVCRSMZA"), std::move(cb_76) });
            }
            {
                std::vector<ir::StmtPtr> cb_77;
                cb_77.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "PM"), ir::bit_slice(ir::ident("operand"), ir::int_lit(0), ir::int_lit(0), false)));
                cs_62.push_back({ ir::ident("PSTATEField_PM"), std::move(cb_77) });
            }
            stmts.push_back(ir::case_stmt(ir::ident("field"), std::move(cs_62)));
        }
    }

    return tree;
}

Tree build_ir_MSR_SR_systemmove(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MSR_SR_systemmove";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["o0"] = (insn >> 19) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_concat({ir::bit_lit("1"), ir::ident("o0")})));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysRegWrite", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t")})));
    }

    return tree;
}

Tree build_ir_MSRR_SR_systemmovepr(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "MSRR_SR_systemmovepr";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["o0"] = (insn >> 19) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SYSREG128")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("Rt"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1")), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("t2", "integer", ir::func_call("UInt", {}, {ir::bin_op(ir::BinOpKind::Add, ir::ident("Rt"), ir::int_lit(1))})));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_concat({ir::bit_lit("1"), ir::ident("o0")})));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysRegWrite128", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t"), ir::ident("t2")})));
    }

    return tree;
}

Tree build_ir_NOP_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "NOP_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::return_stmt(nullptr));
    }

    return tree;
}

Tree build_ir_PACIA1716_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIA1716_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("pacia1716", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
                    {
                        std::vector<ir::StmtPtr> bb_7;
                        bb_7.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSP")));
                        bb_7.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                        br_6.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_7) });
                    }
                    cb_5.push_back(ir::if_stmt(std::move(br_6)));
                }
                cs_3.push_back({ ir::bit_lit("0011001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_8.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_8.push_back(ir::assign(ir::ident("pacia1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001000"), std::move(cb_8) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_9.push_back({ ir::ident("source_is_sp"), std::move(bb_10) });
            }
            {
                std::vector<ir::StmtPtr> bb_14;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_15;
                    {
                        std::vector<ir::StmtPtr> bb_16;
                        bb_16.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_15.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacia1716")), std::move(bb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_15.push_back({ nullptr, std::move(bb_17) });
                    }
                    bb_14.push_back(ir::if_stmt(std::move(br_15)));
                }
                br_9.push_back({ nullptr, std::move(bb_14) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_PACIASP_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIASP_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("pacia1716", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
                    {
                        std::vector<ir::StmtPtr> bb_7;
                        bb_7.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSP")));
                        bb_7.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                        br_6.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_7) });
                    }
                    cb_5.push_back(ir::if_stmt(std::move(br_6)));
                }
                cs_3.push_back({ ir::bit_lit("0011001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_8.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_8.push_back(ir::assign(ir::ident("pacia1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001000"), std::move(cb_8) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_9.push_back({ ir::ident("source_is_sp"), std::move(bb_10) });
            }
            {
                std::vector<ir::StmtPtr> bb_14;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_15;
                    {
                        std::vector<ir::StmtPtr> bb_16;
                        bb_16.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_15.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacia1716")), std::move(bb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_15.push_back({ nullptr, std::move(bb_17) });
                    }
                    bb_14.push_back(ir::if_stmt(std::move(br_15)));
                }
                br_9.push_back({ nullptr, std::move(bb_14) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_PACIAZ_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIAZ_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("pacia1716", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011000"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
                    {
                        std::vector<ir::StmtPtr> bb_7;
                        bb_7.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSP")));
                        bb_7.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                        br_6.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_7) });
                    }
                    cb_5.push_back(ir::if_stmt(std::move(br_6)));
                }
                cs_3.push_back({ ir::bit_lit("0011001"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_8.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_8.push_back(ir::assign(ir::ident("pacia1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001000"), std::move(cb_8) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_9.push_back({ ir::ident("source_is_sp"), std::move(bb_10) });
            }
            {
                std::vector<ir::StmtPtr> bb_14;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_15;
                    {
                        std::vector<ir::StmtPtr> bb_16;
                        bb_16.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_15.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacia1716")), std::move(bb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIA", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_15.push_back({ nullptr, std::move(bb_17) });
                    }
                    bb_14.push_back(ir::if_stmt(std::move(br_15)));
                }
                br_9.push_back({ nullptr, std::move(bb_14) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_PACIB1716_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIB1716_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("pacib1716", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011010"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
                    {
                        std::vector<ir::StmtPtr> bb_7;
                        bb_7.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSP")));
                        bb_7.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                        br_6.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_7) });
                    }
                    cb_5.push_back(ir::if_stmt(std::move(br_6)));
                }
                cs_3.push_back({ ir::bit_lit("0011011"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_8.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_8.push_back(ir::assign(ir::ident("pacib1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001010"), std::move(cb_8) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_9.push_back({ ir::ident("source_is_sp"), std::move(bb_10) });
            }
            {
                std::vector<ir::StmtPtr> bb_14;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_15;
                    {
                        std::vector<ir::StmtPtr> bb_16;
                        bb_16.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_15.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacib1716")), std::move(bb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_15.push_back({ nullptr, std::move(bb_17) });
                    }
                    bb_14.push_back(ir::if_stmt(std::move(br_15)));
                }
                br_9.push_back({ nullptr, std::move(bb_14) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_PACIBSP_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIBSP_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("pacib1716", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011010"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
                    {
                        std::vector<ir::StmtPtr> bb_7;
                        bb_7.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSP")));
                        bb_7.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                        br_6.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_7) });
                    }
                    cb_5.push_back(ir::if_stmt(std::move(br_6)));
                }
                cs_3.push_back({ ir::bit_lit("0011011"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_8.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_8.push_back(ir::assign(ir::ident("pacib1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001010"), std::move(cb_8) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_9.push_back({ ir::ident("source_is_sp"), std::move(bb_10) });
            }
            {
                std::vector<ir::StmtPtr> bb_14;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_15;
                    {
                        std::vector<ir::StmtPtr> bb_16;
                        bb_16.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_15.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacib1716")), std::move(bb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_15.push_back({ nullptr, std::move(bb_17) });
                    }
                    bb_14.push_back(ir::if_stmt(std::move(br_15)));
                }
                br_9.push_back({ nullptr, std::move(bb_14) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_PACIBZ_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACIBZ_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::var_decl("d", "integer", nullptr));
        stmts.push_back(ir::var_decl("n", "integer", nullptr));
        stmts.push_back(ir::var_decl("source_is_sp", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::var_decl("pacib1716", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> cs_3;
            {
                std::vector<ir::StmtPtr> cb_4;
                cb_4.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_4.push_back(ir::assign(ir::ident("n"), ir::int_lit(31)));
                cs_3.push_back({ ir::bit_lit("0011010"), std::move(cb_4) });
            }
            {
                std::vector<ir::StmtPtr> cb_5;
                cb_5.push_back(ir::assign(ir::ident("d"), ir::int_lit(30)));
                cb_5.push_back(ir::assign(ir::ident("source_is_sp"), ir::bool_lit(true)));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
                    {
                        std::vector<ir::StmtPtr> bb_7;
                        bb_7.push_back(ir::let_decl("pacinst", "PACInstType", ir::ident("PACIxSP")));
                        bb_7.push_back(ir::expr_stmt(ir::func_call("SetBTypeCompatible", {}, {ir::func_call("BTypeCompatible_PAC", {}, {ir::ident("pacinst")})})));
                        br_6.push_back({ ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_BTI")}), std::move(bb_7) });
                    }
                    cb_5.push_back(ir::if_stmt(std::move(br_6)));
                }
                cs_3.push_back({ ir::bit_lit("0011011"), std::move(cb_5) });
            }
            {
                std::vector<ir::StmtPtr> cb_8;
                cb_8.push_back(ir::assign(ir::ident("d"), ir::int_lit(17)));
                cb_8.push_back(ir::assign(ir::ident("n"), ir::int_lit(16)));
                cb_8.push_back(ir::assign(ir::ident("pacib1716"), ir::bool_lit(true)));
                cs_3.push_back({ ir::bit_lit("0001010"), std::move(cb_8) });
            }
            stmts.push_back(ir::case_stmt(ir::bit_concat({ir::ident("CRm"), ir::ident("op2")}), std::move(cs_3)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_9;
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {}), ir::func_call("PC64", {}, {})})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("SP", {ir::int_lit(64)}, {})})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_9.push_back({ ir::ident("source_is_sp"), std::move(bb_10) });
            }
            {
                std::vector<ir::StmtPtr> bb_14;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_15;
                    {
                        std::vector<ir::StmtPtr> bb_16;
                        bb_16.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB2", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")}), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(15)})})));
                        br_15.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), ir::ident("pacib1716")), std::move(bb_16) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_17;
                        bb_17.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("AddPACIB", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("X", {ir::int_lit(64)}, {ir::ident("n")})})));
                        br_15.push_back({ nullptr, std::move(bb_17) });
                    }
                    bb_14.push_back(ir::if_stmt(std::move(br_15)));
                }
                br_9.push_back({ nullptr, std::move(bb_14) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_9)));
        }
    }

    return tree;
}

Tree build_ir_PACM_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PACM_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "PACM"), ir::if_expr(ir::func_call("IsPACMEnabled", {}, {}), ir::bit_lit("1"), ir::bit_lit("0"))));
    }

    return tree;
}

Tree build_ir_PSB_HC_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PSB_HC_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SPE")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::let_decl("trap_to_el2", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("EL2Enabled", {}, {})), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsInHost", {}, {}))), ir::bin_op(ir::BinOpKind::LogicalOr, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaveEL", {}, {ir::ident("EL3")})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("SCR_EL3", {}, {}), "FGTEn"), ir::bit_lit("1")))), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HFGITR_EL2", {}, {}), "PSBCSYNC"), ir::bit_lit("1")))));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::var_decl("except", "ExceptionRecord", ir::func_call("ExceptionSyndrome", {}, {ir::ident("Exception_LDST64BTrap")})));
                        bb_6.push_back(ir::assign(ir::field_access(ir::field_access(ir::ident("except"), "syndrome"), "iss"), ir::bit_slice(ir::int_lit(3), ir::int_lit(24), ir::int_lit(0), false)));
                        bb_6.push_back(ir::let_decl("preferred_exception_return", "bits(64)", ir::func_call("ThisInstrAddr", {}, {})));
                        bb_6.push_back(ir::let_decl("vect_offset", "integer", ir::int_lit(0)));
                        bb_6.push_back(ir::expr_stmt(ir::func_call("AArch64_TakeException", {}, {ir::ident("EL2"), ir::ident("except"), ir::ident("preferred_exception_return"), ir::ident("vect_offset")})));
                        br_5.push_back({ ir::ident("trap_to_el2"), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FGT")}), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SPEv1p5")})), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("ProfilingSynchronizationBarrier", {}, {})));
    }

    return tree;
}

Tree build_ir_PSSBB_DSB_BO_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "PSSBB_DSB_BO_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["opc"] = (insn >> 5) & 0x3;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_RET_64R_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RET_64R_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("n", "integer", ir::func_call("UInt", {}, {ir::ident("Rn")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::ident("n")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("GCSInstType_PRET")})));
                bb_2.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_RETAA_64E_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RETAA_64E_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("inst_type", "GCSInstruction", nullptr));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::int_lit(30)})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        stmts.push_back(ir::var_decl("modifier2", "bits(64)", nullptr));
        stmts.push_back(ir::var_decl("use_modifier2", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("modifier2"), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)})));
                bb_4.push_back(ir::assign(ir::ident("use_modifier2"), ir::bool_lit(true)));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
                    {
                        std::vector<ir::StmtPtr> bb_8;
                        bb_8.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                        br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::ident("use_modifier2"), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_8) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        bb_9.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                        br_7.push_back({ nullptr, std::move(bb_9) });
                    }
                    bb_6.push_back(ir::if_stmt(std::move(br_7)));
                }
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::ident("use_modifier2"), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_5.push_back({ nullptr, std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_14;
            {
                std::vector<ir::StmtPtr> bb_15;
                bb_15.push_back(ir::assign(ir::ident("inst_type"), ir::if_expr(ir::ident("use_key_a"), ir::ident("GCSInstType_PRETAA"), ir::ident("GCSInstType_PRETAB"))));
                bb_15.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("inst_type")})));
                bb_15.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_14.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_15) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_14)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_RETAB_64E_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RETAB_64E_branch_reg";

    tree.fields["Z"] = (insn >> 24) & 0x1;
    tree.fields["op"] = (insn >> 21) & 0x3;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["A"] = (insn >> 11) & 0x1;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("inst_type", "GCSInstruction", nullptr));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::int_lit(30)})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        stmts.push_back(ir::var_decl("modifier2", "bits(64)", nullptr));
        stmts.push_back(ir::var_decl("use_modifier2", "boolean", ir::bool_lit(false)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("modifier2"), ir::func_call("X", {ir::int_lit(64)}, {ir::int_lit(16)})));
                bb_4.push_back(ir::assign(ir::ident("use_modifier2"), ir::bool_lit(true)));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")}), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "PACM"), ir::bit_lit("1"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
            {
                std::vector<ir::StmtPtr> bb_6;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_7;
                    {
                        std::vector<ir::StmtPtr> bb_8;
                        bb_8.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                        br_7.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::ident("use_modifier2"), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_8) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_9;
                        bb_9.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                        br_7.push_back({ nullptr, std::move(bb_9) });
                    }
                    bb_6.push_back(ir::if_stmt(std::move(br_7)));
                }
                br_5.push_back({ ir::ident("use_key_a"), std::move(bb_6) });
            }
            {
                std::vector<ir::StmtPtr> bb_10;
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_11;
                    {
                        std::vector<ir::StmtPtr> bb_12;
                        bb_12.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                        br_11.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::ident("use_modifier2"), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PAuth_LR")})), std::move(bb_12) });
                    }
                    {
                        std::vector<ir::StmtPtr> bb_13;
                        bb_13.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("auth_then_branch")})));
                        br_11.push_back({ nullptr, std::move(bb_13) });
                    }
                    bb_10.push_back(ir::if_stmt(std::move(br_11)));
                }
                br_5.push_back({ nullptr, std::move(bb_10) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_5)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_14;
            {
                std::vector<ir::StmtPtr> bb_15;
                bb_15.push_back(ir::assign(ir::ident("inst_type"), ir::if_expr(ir::ident("use_key_a"), ir::ident("GCSInstType_PRETAA"), ir::ident("GCSInstType_PRETAB"))));
                bb_15.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("inst_type")})));
                bb_15.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_14.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_15) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_14)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_RETAASPPC_only_miscbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RETAASPPC_only_miscbranch";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("opc"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("ZeroExtend", {}, {ir::bit_concat({ir::ident("imm16"), ir::bit_lit("00")})})));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("inst_type", "GCSInstruction", nullptr));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::int_lit(30)})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        stmts.push_back(ir::let_decl("modifier2", "bits(64)", ir::bin_op(ir::BinOpKind::Sub, ir::func_call("PC64", {}, {}), ir::ident("offset"))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ ir::ident("use_key_a"), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("inst_type"), ir::if_expr(ir::ident("use_key_a"), ir::ident("GCSInstType_PRETAA"), ir::ident("GCSInstType_PRETAB"))));
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("inst_type")})));
                bb_7.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_6.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_6)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_RETABSPPC_only_miscbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RETABSPPC_only_miscbranch";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("opc"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("ZeroExtend", {}, {ir::bit_concat({ir::ident("imm16"), ir::bit_lit("00")})})));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("inst_type", "GCSInstruction", nullptr));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::int_lit(30)})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        stmts.push_back(ir::let_decl("modifier2", "bits(64)", ir::bin_op(ir::BinOpKind::Sub, ir::func_call("PC64", {}, {}), ir::ident("offset"))));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ ir::ident("use_key_a"), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("inst_type"), ir::if_expr(ir::ident("use_key_a"), ir::ident("GCSInstType_PRETAA"), ir::ident("GCSInstType_PRETAB"))));
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("inst_type")})));
                bb_7.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_6.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_6)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_RETAASPPCR_64M_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RETAASPPCR_64M_branch_reg";

    tree.fields["opc"] = (insn >> 21) & 0xF;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("inst_type", "GCSInstruction", nullptr));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::int_lit(30)})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        stmts.push_back(ir::let_decl("modifier2", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ ir::ident("use_key_a"), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("inst_type"), ir::if_expr(ir::ident("use_key_a"), ir::ident("GCSInstType_PRETAA"), ir::ident("GCSInstType_PRETAB"))));
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("inst_type")})));
                bb_7.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_6.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_6)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_RETABSPPCR_64M_branch_reg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "RETABSPPCR_64M_branch_reg";

    tree.fields["opc"] = (insn >> 21) & 0xF;
    tree.fields["op2"] = (insn >> 16) & 0x1F;
    tree.fields["M"] = (insn >> 10) & 0x1;
    tree.fields["Rn"] = (insn >> 5) & 0x1F;
    tree.fields["Rm"] = (insn >> 0) & 0x1F;

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
        stmts.push_back(ir::let_decl("m", "integer", ir::func_call("UInt", {}, {ir::ident("Rm")})));
        stmts.push_back(ir::let_decl("use_key_a", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::ident("M"), ir::bit_lit("0"))));
        stmts.push_back(ir::let_decl("auth_then_branch", "boolean", ir::bool_lit(true)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::var_decl("inst_type", "GCSInstruction", nullptr));
        stmts.push_back(ir::var_decl("target", "bits(64)", ir::func_call("X", {}, {ir::int_lit(30)})));
        stmts.push_back(ir::let_decl("modifier", "bits(64)", ir::func_call("SP", {}, {})));
        stmts.push_back(ir::let_decl("modifier2", "bits(64)", ir::func_call("X", {}, {ir::ident("m")})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIA2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ ir::ident("use_key_a"), std::move(bb_4) });
            }
            {
                std::vector<ir::StmtPtr> bb_5;
                bb_5.push_back(ir::assign(ir::ident("target"), ir::func_call("AuthIB2", {}, {ir::ident("target"), ir::ident("modifier"), ir::ident("modifier2"), ir::ident("auth_then_branch")})));
                br_3.push_back({ nullptr, std::move(bb_5) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_6;
            {
                std::vector<ir::StmtPtr> bb_7;
                bb_7.push_back(ir::assign(ir::ident("inst_type"), ir::if_expr(ir::ident("use_key_a"), ir::ident("GCSInstType_PRETAA"), ir::ident("GCSInstType_PRETAB"))));
                bb_7.push_back(ir::assign(ir::ident("target"), ir::func_call("LoadCheckGCSRecord", {}, {ir::ident("target"), ir::ident("inst_type")})));
                bb_7.push_back(ir::expr_stmt(ir::func_call("SetCurrentGCSPointer", {}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("GetCurrentGCSPointer", {}, {}), ir::int_lit(8))})));
                br_6.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_GCS")}), ir::func_call("GCSPCREnabled", {}, {ir::field_access(ir::ident("PSTATE"), "EL")})), std::move(bb_7) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_6)));
        }
        stmts.push_back(ir::assign(ir::ident("BTypeNext"), ir::bit_lit("00")));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(false)));
        stmts.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::ident("target"), ir::ident("BranchType_RET"), ir::ident("branch_conditional")})));
    }

    return tree;
}

Tree build_ir_SB_only_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SB_only_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["opc"] = (insn >> 5) & 0x3;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SB")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("SpeculationBarrier", {}, {})));
    }

    return tree;
}

Tree build_ir_SEV_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SEV_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("SendEvent", {}, {})));
    }

    return tree;
}

Tree build_ir_SEVL_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SEVL_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("SendEventLocal", {}, {})));
    }

    return tree;
}

Tree build_ir_SHUH_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SHUH_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMH")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("priority", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("op2"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1"))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_SharedUpdate", {}, {ir::ident("priority")})));
    }

    return tree;
}

Tree build_ir_SMC_EX_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMC_EX_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("imm", "bits(16)", ir::ident("imm16")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("Undefined", {}, {})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::ident("PSTATE"), "EL"), ir::ident("EL0")), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckForSMCUndefOrTrap", {}, {ir::ident("imm")})));
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CallSecureMonitor", {}, {ir::ident("imm")})));
    }

    return tree;
}

Tree build_ir_SMSTART_MSR_SI_pstate(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMSTART_MSR_SI_pstate";

    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_SMSTOP_MSR_SI_pstate(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SMSTOP_MSR_SI_pstate";

    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_SSBB_DSB_BO_barriers(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SSBB_DSB_BO_barriers";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["opc"] = (insn >> 5) & 0x3;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_STCPH_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "STCPH_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_CMH")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_StoreConcurrentPriority", {}, {})));
    }

    return tree;
}

Tree build_ir_STSHH_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "STSHH_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_PCDPHINT")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("stream", "boolean", ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("op2"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1"))));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_StoreShared", {}, {ir::ident("stream")})));
    }

    return tree;
}

Tree build_ir_SVC_EX_exception(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SVC_EX_exception";

    tree.fields["opc"] = (insn >> 21) & 0x7;
    tree.fields["imm16"] = (insn >> 5) & 0xFFFF;
    tree.fields["op2"] = (insn >> 2) & 0x7;
    tree.fields["LL"] = (insn >> 0) & 0x3;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("imm", "bits(16)", ir::ident("imm16")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CheckForSVCTrap", {}, {ir::ident("imm")})));
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_CallSupervisor", {}, {ir::ident("imm")})));
    }

    return tree;
}

Tree build_ir_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_lit("01")));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysInstr", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t")})));
    }

    return tree;
}

Tree build_ir_SYSL_RC_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SYSL_RC_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_lit("01")));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysInstrWithResult", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t")})));
    }

    return tree;
}

Tree build_ir_SYSP_CR_syspairinstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "SYSP_CR_syspairinstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_SYSINSTR128")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("Rt"), ir::int_lit(0), ir::int_lit(0), false), ir::bit_lit("1")), ir::bin_op(ir::BinOpKind::Ne, ir::ident("Rt"), ir::bit_lit("11111"))), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("t2", "integer", ir::if_expr(ir::bin_op(ir::BinOpKind::Eq, ir::ident("t"), ir::int_lit(31)), ir::int_lit(31), ir::bin_op(ir::BinOpKind::Add, ir::ident("t"), ir::int_lit(1)))));
        stmts.push_back(ir::let_decl("sys_L", "bits(1)", ir::ident("L")));
        stmts.push_back(ir::let_decl("sys_op0", "bits(2)", ir::bit_lit("01")));
        stmts.push_back(ir::let_decl("sys_op1", "bits(3)", ir::ident("op1")));
        stmts.push_back(ir::let_decl("sys_op2", "bits(3)", ir::ident("op2")));
        stmts.push_back(ir::let_decl("sys_crn", "bits(4)", ir::ident("CRn")));
        stmts.push_back(ir::let_decl("sys_crm", "bits(4)", ir::ident("CRm")));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("AArch64_SysInstr128", {}, {ir::ident("sys_op0"), ir::ident("sys_op1"), ir::ident("sys_crn"), ir::ident("sys_crm"), ir::ident("sys_op2"), ir::ident("t"), ir::ident("t2")})));
    }

    return tree;
}

Tree build_ir_TBNZ_only_testbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TBNZ_only_testbranch";

    tree.fields["b5"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 24) & 0x1;
    tree.fields["b40"] = (insn >> 19) & 0x1F;
    tree.fields["imm14"] = (insn >> 5) & 0x3FFF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("b5")}))));
        stmts.push_back(ir::let_decl("bit_pos", "integer", ir::func_call("UInt", {}, {ir::bit_concat({ir::ident("b5"), ir::ident("b40")})})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm14"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Ne, ir::bit_slice(ir::ident("operand"), ir::ident("bit_pos"), ir::ident("bit_pos"), false), ir::bit_lit("0")), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_TBZ_only_testbranch(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TBZ_only_testbranch";

    tree.fields["b5"] = (insn >> 31) & 0x1;
    tree.fields["op"] = (insn >> 24) & 0x1;
    tree.fields["b40"] = (insn >> 19) & 0x1F;
    tree.fields["imm14"] = (insn >> 5) & 0x3FFF;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        stmts.push_back(ir::let_decl("t", "integer", ir::func_call("UInt", {}, {ir::ident("Rt")})));
        stmts.push_back(ir::let_decl("datasize", "integer", ir::bin_op(ir::BinOpKind::Shl, ir::int_lit(32), ir::func_call("UInt", {}, {ir::ident("b5")}))));
        stmts.push_back(ir::let_decl("bit_pos", "integer", ir::func_call("UInt", {}, {ir::bit_concat({ir::ident("b5"), ir::ident("b40")})})));
        stmts.push_back(ir::let_decl("offset", "bits(64)", ir::func_call("SignExtend", {}, {ir::bit_concat({ir::ident("imm14"), ir::bit_lit("00")})})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("operand", "bits(datasize)", ir::func_call("X", {}, {ir::ident("t")})));
        stmts.push_back(ir::let_decl("branch_conditional", "boolean", ir::bool_lit(true)));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                bb_2.push_back(ir::expr_stmt(ir::func_call("BranchTo", {ir::int_lit(64)}, {ir::bin_op(ir::BinOpKind::Add, ir::func_call("PC64", {}, {}), ir::ident("offset")), ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ ir::bin_op(ir::BinOpKind::Eq, ir::bit_slice(ir::ident("operand"), ir::ident("bit_pos"), ir::ident("bit_pos"), false), ir::bit_lit("0")), std::move(bb_2) });
            }
            {
                std::vector<ir::StmtPtr> bb_3;
                bb_3.push_back(ir::expr_stmt(ir::func_call("BranchNotTaken", {}, {ir::ident("BranchType_DIR"), ir::ident("branch_conditional")})));
                br_1.push_back({ nullptr, std::move(bb_3) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    return tree;
}

Tree build_ir_TLBI_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TLBI_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_TLBIP_SYSP_CR_syspairinstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TLBIP_SYSP_CR_syspairinstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_TRCIT_SYS_CR_systeminstrs(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TRCIT_SYS_CR_systeminstrs";

    tree.fields["L"] = (insn >> 21) & 0x1;
    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRn"] = (insn >> 12) & 0xF;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    return tree;
}

Tree build_ir_TSB_HC_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "TSB_HC_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_TRF")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::let_decl("trap_to_el2", "boolean", ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::bin_op(ir::BinOpKind::LogicalAnd, ir::in_expr(ir::field_access(ir::ident("PSTATE"), "EL"), ir::set_lit({"Identifier(name='EL0')", "Identifier(name='EL1')"})), ir::func_call("EL2Enabled", {}, {})), ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsInHost", {}, {}))), ir::bin_op(ir::BinOpKind::LogicalOr, ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("HaveEL", {}, {ir::ident("EL3")})), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("SCR_EL3", {}, {}), "FGTEn2"), ir::bit_lit("1")))), ir::bin_op(ir::BinOpKind::Eq, ir::field_access(ir::func_call("HFGITR2_EL2", {}, {}), "TSBCSYNC"), ir::bit_lit("1")))));
                {
                    std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_5;
                    {
                        std::vector<ir::StmtPtr> bb_6;
                        bb_6.push_back(ir::var_decl("except", "ExceptionRecord", ir::func_call("ExceptionSyndrome", {}, {ir::ident("Exception_LDST64BTrap")})));
                        bb_6.push_back(ir::assign(ir::field_access(ir::field_access(ir::ident("except"), "syndrome"), "iss"), ir::bit_slice(ir::int_lit(4), ir::int_lit(24), ir::int_lit(0), false)));
                        bb_6.push_back(ir::let_decl("preferred_exception_return", "bits(64)", ir::func_call("ThisInstrAddr", {}, {})));
                        bb_6.push_back(ir::let_decl("vect_offset", "integer", ir::int_lit(0)));
                        bb_6.push_back(ir::expr_stmt(ir::func_call("AArch64_TakeException", {}, {ir::ident("EL2"), ir::ident("except"), ir::ident("preferred_exception_return"), ir::ident("vect_offset")})));
                        br_5.push_back({ ir::ident("trap_to_el2"), std::move(bb_6) });
                    }
                    bb_4.push_back(ir::if_stmt(std::move(br_5)));
                }
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FGT2")}), ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_TRBEv1p1")})), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("TraceSynchronizationBarrier", {}, {})));
    }

    return tree;
}

Tree build_ir_WFE_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "WFE_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_WFE", {}, {})));
    }

    return tree;
}

Tree build_ir_WFET_only_systeminstrswithreg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "WFET_only_systeminstrswithreg";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_WFxT")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("localtimeout", "integer", ir::func_call("UInt", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")})})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("ExecuteAsNOP", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("Halted", {}, {}), ir::func_call("ConstrainUnpredictableBool", {}, {ir::ident("Unpredictable_WFxTDEBUG")})), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_WFET", {}, {ir::ident("localtimeout")})));
    }

    return tree;
}

Tree build_ir_WFI_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "WFI_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_WFI", {}, {})));
    }

    return tree;
}

Tree build_ir_WFIT_only_systeminstrswithreg(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "WFIT_only_systeminstrswithreg";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rd"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_WFxT")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
        stmts.push_back(ir::let_decl("d", "integer", ir::func_call("UInt", {}, {ir::ident("Rd")})));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("localtimeout", "integer", ir::func_call("UInt", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")})})));
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_3;
            {
                std::vector<ir::StmtPtr> bb_4;
                bb_4.push_back(ir::expr_stmt(ir::func_call("ExecuteAsNOP", {}, {})));
                br_3.push_back({ ir::bin_op(ir::BinOpKind::LogicalAnd, ir::func_call("Halted", {}, {}), ir::func_call("ConstrainUnpredictableBool", {}, {ir::ident("Unpredictable_WFxTDEBUG")})), std::move(bb_4) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_3)));
        }
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_WFIT", {}, {ir::ident("localtimeout")})));
    }

    return tree;
}

Tree build_ir_XAFLAG_M_pstate(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "XAFLAG_M_pstate";

    tree.fields["op1"] = (insn >> 16) & 0x7;
    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;
    tree.fields["Rt"] = (insn >> 0) & 0x1F;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
        {
            std::vector<std::pair<ir::ExprPtr, std::vector<ir::StmtPtr>>> br_1;
            {
                std::vector<ir::StmtPtr> bb_2;
                br_1.push_back({ ir::unary_op(ir::UnaryOpKind::Not, ir::func_call("IsFeatureImplemented", {}, {ir::ident("FEAT_FlagM2")})), std::move(bb_2) });
            }
            stmts.push_back(ir::if_stmt(std::move(br_1)));
        }
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::let_decl("n", "bit", ir::bin_op(ir::BinOpKind::And, ir::unary_op(ir::UnaryOpKind::Not, ir::field_access(ir::ident("PSTATE"), "C")), ir::unary_op(ir::UnaryOpKind::Not, ir::field_access(ir::ident("PSTATE"), "Z")))));
        stmts.push_back(ir::let_decl("z", "bit", ir::bin_op(ir::BinOpKind::And, ir::field_access(ir::ident("PSTATE"), "Z"), ir::field_access(ir::ident("PSTATE"), "C"))));
        stmts.push_back(ir::let_decl("c", "bit", ir::bin_op(ir::BinOpKind::Or, ir::field_access(ir::ident("PSTATE"), "C"), ir::field_access(ir::ident("PSTATE"), "Z"))));
        stmts.push_back(ir::let_decl("v", "bit", ir::bin_op(ir::BinOpKind::And, ir::unary_op(ir::UnaryOpKind::Not, ir::field_access(ir::ident("PSTATE"), "C")), ir::field_access(ir::ident("PSTATE"), "Z"))));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "N"), ir::ident("n")));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "Z"), ir::ident("z")));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "C"), ir::ident("c")));
        stmts.push_back(ir::assign(ir::field_access(ir::ident("PSTATE"), "V"), ir::ident("v")));
    }

    return tree;
}

Tree build_ir_XPACLRI_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "XPACLRI_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

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
        stmts.push_back(ir::let_decl("d", "integer", ir::int_lit(30)));
        stmts.push_back(ir::let_decl("data", "boolean", ir::bool_lit(false)));
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::assign(ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::func_call("Strip", {}, {ir::func_call("X", {ir::int_lit(64)}, {ir::ident("d")}), ir::ident("data")})));
    }

    return tree;
}

Tree build_ir_YIELD_HI_hints(uint32_t insn) {
    Tree tree;
    tree.encoding_name = "YIELD_HI_hints";

    tree.fields["CRm"] = (insn >> 8) & 0xF;
    tree.fields["op2"] = (insn >> 5) & 0x7;

    // Decode pseudocode
    {
        auto& stmts = tree.decode_stmts;
    }

    // Execute pseudocode
    {
        auto& stmts = tree.execute_stmts;
        stmts.push_back(ir::expr_stmt(ir::func_call("Hint_Yield", {}, {})));
    }

    return tree;
}

} // namespace ir
} // namespace veda64