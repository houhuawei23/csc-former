/*
    SPDX-License-Identifier: Apache-2.0
    Copyright 2023 CMMC Authors
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
        http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
// Automatically generated file, do not edit!

#include "../../../cmmc/CodeGen/Target.hpp"
#include "../../../cmmc/CodeGen/MIR.hpp"
#include "../../../cmmc/CodeGen/InstInfo.hpp"
#include <{{target}}/InstInfoDecl.hpp>

CMMC_TARGET_NAMESPACE_BEGIN

{% for inst in insts %}
class {{target}}InstInfo{{inst.name}} final: public InstInfo {
public:
    {{target}}InstInfo{{inst.name}}() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out {% for val in inst.Format %} << {%if val is integer %} ::cmmc::mir::{{target}}::OperandDumper{ inst.getOperand({{val}}) } {%else%} "{{val}}" {%endif%} {%endfor%};
        {% if inst.Comment|length != 0 %} if(printComment) out {% for val in inst.Comment %} << {%if val is integer %} ::cmmc::mir::{{target}}::OperandDumper{ inst.getOperand({{val}}) } {%else%} "{{val}}" {%endif%} {%endfor%}; {% else %} CMMC_UNUSED(printComment); {% endif %}
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount({{inst.operands|length}}) && mir::checkISASpecificOperands(inst, ctx, {{inst.operands|length}}) {% for op in inst.operands %} && ::cmmc::mir::{{target}}::isOperand{{op.class}}(inst.getOperand({{op.idx}})) {% endfor %} {%if inst.CustomVerifier%} && ::cmmc::mir::{{target}}::verifyInst{{inst.name}}(inst) {%endif%} ;
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return {{inst.operands|length}};
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            {% for op in inst.operands %}case {{op.idx}}: return OperandFlag{{op.flag}};{% endfor %}
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone {% for flag in inst.Flag %}| InstFlag{{flag}}{% endfor %};
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "{{target}}.{{inst.name}}";
    }
};
{% endfor %}

class {{target}}InstInfo final: public TargetInstInfo {
    {% for inst in insts %} {{target}}InstInfo{{inst.name}} mInstInfo{{inst.name}}; {% endfor %}
public:
    {{target}}InstInfo() = default;
    const InstInfo& getInstInfo(uint32_t opcode) const override {
        switch (opcode) {
            {% for inst in insts %}case {{target}}Inst::{{inst.name}}: return mInstInfo{{inst.name}};{% endfor %}
            default: return TargetInstInfo::getInstInfo(opcode);
        }
    }
    bool matchBranch(const MIRInst& inst, MIRBasicBlock*& target, double& prob) const override {
        auto& instInfo = getInstInfo(inst.opcode());
        if(requireFlag(instInfo.getInstFlag(), InstFlagBranch)) {
            if(inst.opcode() < ISASpecificBegin)
                return TargetInstInfo::matchBranch(inst, target, prob); 
            switch(inst.opcode()) {
            {%for branch in branches%} case {{branch.inst}}: target = dynamic_cast<MIRBasicBlock*>(inst.getOperand({{branch.target}}).reloc()); prob = {% if branch.prob != -1 %} inst.getOperand({{branch.prob}}).prob() {% else %} 1.0 {% endif %}; break; {% endfor %}
            default: reportUnreachable(CMMC_LOCATION());
            }
            return true;
        }
        return false;
    }
    void redirectBranch(MIRInst& inst, MIRBasicBlock* target) const override {
        if(inst.opcode() < ISASpecificBegin)
            return TargetInstInfo::redirectBranch(inst, target);
        assert(requireFlag(getInstInfo(inst.opcode()).getInstFlag(), InstFlagBranch));
        switch(inst.opcode()) {
        {%for branch in branches%} case {{branch.inst}}: inst.setOperand<{{branch.target}}>(MIROperand::asReloc(target)); break; {% endfor %}
        default: reportUnreachable(CMMC_LOCATION());
        }
    }
    MIRInst emitGoto(MIRBasicBlock* target) const override {
        return emitGotoImpl(target);
    }
    void inverseBranch(MIRInst& inst, MIRBasicBlock* newTarget) const override {
        inverseBranchImpl(inst, newTarget);
    }
    std::pair<intmax_t, intmax_t> getAddressingImmRange() const override {
        return getAddressingImmRangeImpl();
    }
};

const TargetInstInfo& get{{target}}InstInfo() {
    static {{target}}InstInfo instance;
    return instance;
}

CMMC_TARGET_NAMESPACE_END
