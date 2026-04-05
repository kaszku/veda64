// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_HOOK

#include <veda64/branch_follow.hpp>
#include "veda64.hpp"
#include <unordered_set>

namespace veda64 {

FlowInfo classify_flow(uint32_t insn, uint64_t address) {
    FlowInfo fi;
    fi.address = address;
    auto decoded = decode(insn);
    if (!decoded) { fi.type = FlowType::Unknown; fi.has_fallthrough = false; return fi; }
    auto m = decoded->mnemonic;
    switch (m) {
    case Mnemonic::B:
        if (decoded->condition != Condition::None && decoded->condition != Condition::AL) {
            // B.cond — conditional branch
            fi.type = FlowType::ConditionalBranch;
            for (auto& op : decoded->operands)
                if (op.type == OperandType::Relative)
                    { fi.target = address + static_cast<int64_t>(op.iv.value); break; }
        } else {
            // Unconditional B
            fi.type = FlowType::Branch;
            fi.has_fallthrough = false;
            if (!decoded->operands.empty() && decoded->operands[0].type == OperandType::Relative)
                fi.target = address + static_cast<int64_t>(decoded->operands[0].iv.value);
        }
        break;
    case Mnemonic::BR:
        fi.type = FlowType::Branch;
        fi.has_fallthrough = false;
        fi.is_indirect = true;
        break;
    case Mnemonic::BL:
        fi.type = FlowType::Call;
        if (!decoded->operands.empty() && decoded->operands[0].type == OperandType::Relative)
            fi.target = address + static_cast<int64_t>(decoded->operands[0].iv.value);
        break;
    case Mnemonic::BLR:
        fi.type = FlowType::Call;
        fi.is_indirect = true;
        break;
    case Mnemonic::BC:
        fi.type = FlowType::ConditionalBranch;
        for (auto& op : decoded->operands)
            if (op.type == OperandType::Relative)
                { fi.target = address + static_cast<int64_t>(op.iv.value); break; }
        break;
    case Mnemonic::CBZ: case Mnemonic::CBNZ:
    case Mnemonic::TBZ: case Mnemonic::TBNZ:
        fi.type = FlowType::ConditionalBranch;
        for (auto& op : decoded->operands)
            if (op.type == OperandType::Relative)
                { fi.target = address + static_cast<int64_t>(op.iv.value); break; }
        break;
    case Mnemonic::RET: case Mnemonic::RETAA: case Mnemonic::RETAB:
    case Mnemonic::ERET: case Mnemonic::ERETAA: case Mnemonic::ERETAB:
        fi.type = FlowType::Return;
        fi.has_fallthrough = false;
        break;
    case Mnemonic::SVC: case Mnemonic::HVC: case Mnemonic::SMC:
    case Mnemonic::BRK: case Mnemonic::HLT:
        fi.type = FlowType::Exception;
        fi.has_fallthrough = (m != Mnemonic::BRK && m != Mnemonic::HLT);
        break;
    default:
        fi.type = FlowType::Sequential;
        break;
    }
    return fi;
}

BasicBlock walk_basic_block(uint64_t start,
    std::function<uint32_t(uint64_t)> read_insn, size_t max_insns) {
    BasicBlock bb;
    bb.start = start;
    uint64_t pc = start;
    for (size_t i = 0; i < max_insns; i++) {
        uint32_t insn = read_insn(pc);
        auto fi = classify_flow(insn, pc);
        bb.instructions.push_back(fi);
        pc += 4;
        // Terminator check: stop block at branches, returns, exceptions
        if (fi.type != FlowType::Sequential && fi.type != FlowType::Call) {
            if (fi.target != 0) bb.successors.push_back(fi.target);
            if (fi.has_fallthrough) bb.successors.push_back(pc);
            bb.end = pc;
            return bb;
        }
    }
    bb.end = pc;
    return bb;
}

std::vector<BasicBlock> walk_cfg(uint64_t entry,
    std::function<uint32_t(uint64_t)> read_insn,
    size_t max_blocks, size_t max_insns_per_block) {
    std::vector<BasicBlock> blocks;
    std::unordered_set<uint64_t> visited;
    std::vector<uint64_t> worklist = {entry};
    while (!worklist.empty() && blocks.size() < max_blocks) {
        uint64_t addr = worklist.back();
        worklist.pop_back();
        if (visited.count(addr)) continue;
        visited.insert(addr);
        auto bb = walk_basic_block(addr, read_insn, max_insns_per_block);
        for (auto succ : bb.successors) {
            if (!visited.count(succ)) worklist.push_back(succ);
        }
        blocks.push_back(std::move(bb));
    }
    return blocks;
}

} // namespace veda64

#endif // VEDA64_HOOK
