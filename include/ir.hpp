// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <optional>
#include <utility>

namespace veda64 {
namespace ir {

struct Expr;
struct Stmt;
using ExprPtr = std::shared_ptr<Expr>;
using StmtPtr = std::shared_ptr<Stmt>;

enum class BinOpKind {
    // Logical
    LogicalOr,   // ||
    LogicalAnd,  // &&
    // Bitwise
    Or,          // OR
    Xor,         // XOR
    Eor,         // EOR (alias for XOR in ASL)
    And,         // AND
    // Comparison
    Eq,          // ==
    Ne,          // !=
    Lt,          // <
    Gt,          // >
    Le,          // <=
    Ge,          // >=
    // Shift
    Shl,         // <<
    Shr,         // >>
    // Arithmetic
    Add,         // +
    Sub,         // -
    Mul,         // *
    Div,         // DIV
    DivRm,       // DIVRM
    Mod,         // MOD
    Pow,         // ^
};

enum class UnaryOpKind {
    Not,       // ! and NOT
    Negate,    // -
};

enum class ExprKind {
    IntLit, BitLit, BoolLit, Ident, BinOp, UnaryOp,
    FuncCall, BitSlice, BitConcat, IfExpr, FieldAccess,
    FieldAccessMulti, SetLit, InExpr
};

struct Expr {
    ExprKind kind;
    int64_t int_val = 0;
    std::string str_val;
    bool bool_val = false;
    BinOpKind bin_op_kind = BinOpKind::Add;
    UnaryOpKind unary_op_kind = UnaryOpKind::Not;
    std::vector<ExprPtr> children;
    std::vector<std::string> str_list;
    ExprPtr hi, lo;
    bool flag = false;
    explicit Expr(ExprKind k) : kind(k) {}
};

enum class StmtKind {
    LetDecl, VarDecl, Assign, TupleAssign, IfStmt,
    CaseStmt, ForStmt, WhileStmt, ExprStmt, Assert,
    Return, Undefined, Unpredictable
};

struct Stmt {
    StmtKind kind;
    std::string name;
    std::string type_str;
    ExprPtr expr;
    ExprPtr value;
    std::vector<StmtPtr> body;
    std::vector<std::pair<ExprPtr, std::vector<StmtPtr>>> branches;
    std::vector<std::string> targets;
    std::string direction;
    ExprPtr range_end;
    explicit Stmt(StmtKind k) : kind(k) {}
};

// Expression factory helpers
inline ExprPtr int_lit(int64_t v) {
    auto e = std::make_shared<Expr>(ExprKind::IntLit);
    e->int_val = v;
    return e;
}

inline ExprPtr bit_lit(const std::string& bits) {
    auto e = std::make_shared<Expr>(ExprKind::BitLit);
    e->str_val = bits;
    return e;
}

inline ExprPtr bool_lit(bool v) {
    auto e = std::make_shared<Expr>(ExprKind::BoolLit);
    e->bool_val = v;
    return e;
}

inline ExprPtr ident(const std::string& name) {
    auto e = std::make_shared<Expr>(ExprKind::Ident);
    e->str_val = name;
    return e;
}

inline ExprPtr bin_op(BinOpKind op, ExprPtr left, ExprPtr right) {
    auto e = std::make_shared<Expr>(ExprKind::BinOp);
    e->bin_op_kind = op;
    e->children = {std::move(left), std::move(right)};
    return e;
}

inline ExprPtr unary_op(UnaryOpKind op, ExprPtr operand) {
    auto e = std::make_shared<Expr>(ExprKind::UnaryOp);
    e->unary_op_kind = op;
    e->children = {std::move(operand)};
    return e;
}

inline ExprPtr func_call(const std::string& name, std::vector<ExprPtr> type_params, std::vector<ExprPtr> args) {
    auto e = std::make_shared<Expr>(ExprKind::FuncCall);
    e->str_val = name;
    e->str_list.reserve(type_params.size());
    // Store type_params as first N children, then args
    e->int_val = static_cast<int64_t>(type_params.size());
    e->children = std::move(type_params);
    for (auto& a : args) e->children.push_back(std::move(a));
    return e;
}

inline ExprPtr bit_slice(ExprPtr base, ExprPtr hi, ExprPtr lo, bool is_width = false) {
    auto e = std::make_shared<Expr>(ExprKind::BitSlice);
    e->children = {std::move(base)};
    e->hi = std::move(hi);
    e->lo = std::move(lo);
    e->flag = is_width;
    return e;
}

inline ExprPtr bit_concat(std::vector<ExprPtr> parts) {
    auto e = std::make_shared<Expr>(ExprKind::BitConcat);
    e->children = std::move(parts);
    return e;
}

inline ExprPtr if_expr(ExprPtr cond, ExprPtr then_e, ExprPtr else_e) {
    auto e = std::make_shared<Expr>(ExprKind::IfExpr);
    e->children = {std::move(cond), std::move(then_e), std::move(else_e)};
    return e;
}

inline ExprPtr field_access(ExprPtr base, const std::string& field) {
    auto e = std::make_shared<Expr>(ExprKind::FieldAccess);
    e->str_val = field;
    e->children = {std::move(base)};
    return e;
}

inline ExprPtr field_access_multi(ExprPtr base, std::vector<std::string> fields) {
    auto e = std::make_shared<Expr>(ExprKind::FieldAccessMulti);
    e->str_list = std::move(fields);
    e->children = {std::move(base)};
    return e;
}

inline ExprPtr set_lit(std::vector<std::string> elements) {
    auto e = std::make_shared<Expr>(ExprKind::SetLit);
    e->str_list = std::move(elements);
    return e;
}

inline ExprPtr in_expr(ExprPtr val, ExprPtr collection) {
    auto e = std::make_shared<Expr>(ExprKind::InExpr);
    e->children = {std::move(val), std::move(collection)};
    return e;
}

#ifndef VEDA64_NO_STRINGS
inline const char* to_string(BinOpKind op) {
    switch (op) {
    case BinOpKind::LogicalOr: return "||";
    case BinOpKind::LogicalAnd: return "&&";
    case BinOpKind::Or: return "OR";
    case BinOpKind::Xor: return "XOR";
    case BinOpKind::Eor: return "EOR";
    case BinOpKind::And: return "AND";
    case BinOpKind::Eq: return "==";
    case BinOpKind::Ne: return "!=";
    case BinOpKind::Lt: return "<";
    case BinOpKind::Gt: return ">";
    case BinOpKind::Le: return "<=";
    case BinOpKind::Ge: return ">=";
    case BinOpKind::Shl: return "<<";
    case BinOpKind::Shr: return ">>";
    case BinOpKind::Add: return "+";
    case BinOpKind::Sub: return "-";
    case BinOpKind::Mul: return "*";
    case BinOpKind::Div: return "DIV";
    case BinOpKind::DivRm: return "DIVRM";
    case BinOpKind::Mod: return "MOD";
    case BinOpKind::Pow: return "^";
    }
    return "?";
}

inline const char* to_string(UnaryOpKind op) {
    switch (op) {
    case UnaryOpKind::Not: return "NOT";
    case UnaryOpKind::Negate: return "-";
    }
    return "?";
}
#endif // VEDA64_NO_STRINGS

// Statement factory helpers
inline StmtPtr let_decl(const std::string& name, const std::string& type_str, ExprPtr init) {
    auto s = std::make_shared<Stmt>(StmtKind::LetDecl);
    s->name = name;
    s->type_str = type_str;
    s->expr = std::move(init);
    return s;
}

inline StmtPtr var_decl(const std::string& name, const std::string& type_str, ExprPtr init) {
    auto s = std::make_shared<Stmt>(StmtKind::VarDecl);
    s->name = name;
    s->type_str = type_str;
    s->expr = std::move(init);
    return s;
}

inline StmtPtr assign(ExprPtr target, ExprPtr value) {
    auto s = std::make_shared<Stmt>(StmtKind::Assign);
    s->expr = std::move(target);
    s->value = std::move(value);
    return s;
}

inline StmtPtr tuple_assign(std::vector<std::string> targets, ExprPtr value) {
    auto s = std::make_shared<Stmt>(StmtKind::TupleAssign);
    s->targets = std::move(targets);
    s->value = std::move(value);
    return s;
}

inline StmtPtr if_stmt(std::vector<std::pair<ExprPtr, std::vector<StmtPtr>>> branches) {
    auto s = std::make_shared<Stmt>(StmtKind::IfStmt);
    s->branches = std::move(branches);
    return s;
}

inline StmtPtr case_stmt(ExprPtr expr, std::vector<std::pair<ExprPtr, std::vector<StmtPtr>>> cases) {
    auto s = std::make_shared<Stmt>(StmtKind::CaseStmt);
    s->expr = std::move(expr);
    s->branches = std::move(cases);
    return s;
}

inline StmtPtr for_stmt(const std::string& var, ExprPtr start, ExprPtr end, const std::string& dir, std::vector<StmtPtr> body) {
    auto s = std::make_shared<Stmt>(StmtKind::ForStmt);
    s->name = var;
    s->expr = std::move(start);
    s->range_end = std::move(end);
    s->direction = dir;
    s->body = std::move(body);
    return s;
}

inline StmtPtr while_stmt(ExprPtr cond, std::vector<StmtPtr> body) {
    auto s = std::make_shared<Stmt>(StmtKind::WhileStmt);
    s->expr = std::move(cond);
    s->body = std::move(body);
    return s;
}

inline StmtPtr expr_stmt(ExprPtr e) {
    auto s = std::make_shared<Stmt>(StmtKind::ExprStmt);
    s->expr = std::move(e);
    return s;
}

inline StmtPtr assert_stmt(ExprPtr cond) {
    auto s = std::make_shared<Stmt>(StmtKind::Assert);
    s->expr = std::move(cond);
    return s;
}

inline StmtPtr return_stmt(ExprPtr val = nullptr) {
    auto s = std::make_shared<Stmt>(StmtKind::Return);
    s->expr = std::move(val);
    return s;
}

inline StmtPtr undefined() {
    return std::make_shared<Stmt>(StmtKind::Undefined);
}

inline StmtPtr unpredictable() {
    return std::make_shared<Stmt>(StmtKind::Unpredictable);
}

// Lifted IR tree for a single instruction
struct Tree {
    std::string encoding_name;
    std::map<std::string, uint32_t> fields;
    std::vector<StmtPtr> decode_stmts;
    std::vector<StmtPtr> execute_stmts;
};

// Lift an ARM64 instruction to its ASL IR tree
std::optional<Tree> lift(uint32_t insn);

// Total encoding count: 4623
constexpr uint16_t ENCODING_COUNT = 4623;

} // namespace ir
} // namespace veda64