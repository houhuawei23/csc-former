// Automatically generated file, do not edit!

#pragma once
#include "mir/instinfo.hpp"
#include "mir/mir.hpp"
#include "target/InstInfoDecl.hpp"

TARGET_NAMESPACE_BEGIN

class RISCVInstInfoADD final : public InstInfo {
   public:
    RISCVInstInfoADD() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::ADD";

        out <<

            "add"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSUB final : public InstInfo {
   public:
    RISCVInstInfoSUB() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SUB";

        out

            <<

            "sub"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoXOR final : public InstInfo {
   public:
    RISCVInstInfoXOR() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::XOR";

        out

            <<

            "xor"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoOR final : public InstInfo {
   public:
    RISCVInstInfoOR() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::OR";

        out

            <<

            "or"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAND final : public InstInfo {
   public:
    RISCVInstInfoAND() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AND";

        out

            <<

            "and"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSLL final : public InstInfo {
   public:
    RISCVInstInfoSLL() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SLL";

        out

            <<

            "sll"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSRL final : public InstInfo {
   public:
    RISCVInstInfoSRL() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SRL";

        out

            <<

            "srl"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSRA final : public InstInfo {
   public:
    RISCVInstInfoSRA() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SRA";

        out

            <<

            "sra"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSLT final : public InstInfo {
   public:
    RISCVInstInfoSLT() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SLT";

        out

            <<

            "slt"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSLTU final : public InstInfo {
   public:
    RISCVInstInfoSLTU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SLTU";

        out

            <<

            "sltu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoADDI final : public InstInfo {
   public:
    RISCVInstInfoADDI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::ADDI";

        out

            <<

            "addi"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoXORI final : public InstInfo {
   public:
    RISCVInstInfoXORI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::XORI";

        out

            <<

            "xori"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoORI final : public InstInfo {
   public:
    RISCVInstInfoORI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::ORI";

        out

            <<

            "ori"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoANDI final : public InstInfo {
   public:
    RISCVInstInfoANDI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::ANDI";

        out

            <<

            "andi"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSLTI final : public InstInfo {
   public:
    RISCVInstInfoSLTI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SLTI";

        out

            <<

            "slti"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSLTIU final : public InstInfo {
   public:
    RISCVInstInfoSLTIU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SLTIU";

        out

            <<

            "sltiu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSLLI final : public InstInfo {
   public:
    RISCVInstInfoSLLI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SLLI";

        out

            <<

            "slli"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSRLI final : public InstInfo {
   public:
    RISCVInstInfoSRLI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SRLI";

        out

            <<

            "srli"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSRAI final : public InstInfo {
   public:
    RISCVInstInfoSRAI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SRAI";

        out

            <<

            "srai"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLB final : public InstInfo {
   public:
    RISCVInstInfoLB() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LB";

        out

            <<

            "lb"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLH final : public InstInfo {
   public:
    RISCVInstInfoLH() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LH";

        out

            <<

            "lh"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLW final : public InstInfo {
   public:
    RISCVInstInfoLW() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LW";

        out

            <<

            "lw"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLBU final : public InstInfo {
   public:
    RISCVInstInfoLBU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LBU";

        out

            <<

            "lbu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLHU final : public InstInfo {
   public:
    RISCVInstInfoLHU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LHU";

        out

            <<

            "lhu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSB final : public InstInfo {
   public:
    RISCVInstInfoSB() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SB";

        out

            <<

            "sb"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            "("

            <<

            inst.operand(2)

            <<

            ")"

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSH final : public InstInfo {
   public:
    RISCVInstInfoSH() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SH";

        out

            <<

            "sh"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            "("

            <<

            inst.operand(2)

            <<

            ")"

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSW final : public InstInfo {
   public:
    RISCVInstInfoSW() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SW";

        out

            <<

            "sw"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            "("

            <<

            inst.operand(2)

            <<

            ")"

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoBEQ final : public InstInfo {
   public:
    RISCVInstInfoBEQ() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::BEQ";

        out

            <<

            "beq"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoBNE final : public InstInfo {
   public:
    RISCVInstInfoBNE() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::BNE";

        out

            <<

            "bne"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoBLT final : public InstInfo {
   public:
    RISCVInstInfoBLT() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::BLT";

        out

            <<

            "blt"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoBGE final : public InstInfo {
   public:
    RISCVInstInfoBGE() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::BGE";

        out

            <<

            "bge"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoBLTU final : public InstInfo {
   public:
    RISCVInstInfoBLTU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::BLTU";

        out

            <<

            "bltu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoBGEU final : public InstInfo {
   public:
    RISCVInstInfoBGEU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::BGEU";

        out

            <<

            "bgeu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoJAL final : public InstInfo {
   public:
    RISCVInstInfoJAL() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::JAL";

        out

            <<

            "jal"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoJALR final : public InstInfo {
   public:
    RISCVInstInfoJALR() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::JALR";

        out

            <<

            "jalr"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLUI final : public InstInfo {
   public:
    RISCVInstInfoLUI() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LUI";

        out

            <<

            "lui"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAUIPC final : public InstInfo {
   public:
    RISCVInstInfoAUIPC() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AUIPC";

        out

            <<

            "auipc"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoMUL final : public InstInfo {
   public:
    RISCVInstInfoMUL() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::MUL";

        out

            <<

            "mul"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoMULH final : public InstInfo {
   public:
    RISCVInstInfoMULH() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::MULH";

        out

            <<

            "mulh"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoMULHSU final : public InstInfo {
   public:
    RISCVInstInfoMULHSU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::MULHSU";

        out

            <<

            "mulhsu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoMULHU final : public InstInfo {
   public:
    RISCVInstInfoMULHU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::MULHU";

        out

            <<

            "mulhu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoDIV final : public InstInfo {
   public:
    RISCVInstInfoDIV() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::DIV";

        out

            <<

            "div"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoDIVU final : public InstInfo {
   public:
    RISCVInstInfoDIVU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::DIVU";

        out

            <<

            "divu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoREM final : public InstInfo {
   public:
    RISCVInstInfoREM() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::REM";

        out

            <<

            "rem"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoREMU final : public InstInfo {
   public:
    RISCVInstInfoREMU() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::REMU";

        out

            <<

            "remu"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoLR final : public InstInfo {
   public:
    RISCVInstInfoLR() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::LR";

        out

            <<

            "lr.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoSC final : public InstInfo {
   public:
    RISCVInstInfoSC() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::SC";

        out

            <<

            "sc.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAMOSWAP final : public InstInfo {
   public:
    RISCVInstInfoAMOSWAP() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AMOSWAP";

        out

            <<

            "amoswap.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAMOADD final : public InstInfo {
   public:
    RISCVInstInfoAMOADD() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AMOADD";

        out

            <<

            "amoadd.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAMOAND final : public InstInfo {
   public:
    RISCVInstInfoAMOAND() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AMOAND";

        out

            <<

            "amoand.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAMOOR final : public InstInfo {
   public:
    RISCVInstInfoAMOOR() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AMOOR";

        out

            <<

            "amoor.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfoAMOXOR final : public InstInfo {
   public:
    RISCVInstInfoAMOXOR() = default;

    void print(std::ostream& out, const MIRInst& inst, bool comment) const {
        // out << "RISCVInst::AMOXOR";

        out

            <<

            "amoxor.w"

            <<

            inst.operand(0)

            <<

            ", "

            <<

            inst.operand(1)

            <<

            ", "

            <<

            inst.operand(2)

            ;
    }

    uint32_t operand_num() const { return 3; }

    OperandFlag operand_flag(uint32_t idx) const {}
};

class RISCVInstInfo final : public TargetInstInfo {
    RISCVInstInfoADD _instinfoADD;

    RISCVInstInfoSUB _instinfoSUB;

    RISCVInstInfoXOR _instinfoXOR;

    RISCVInstInfoOR _instinfoOR;

    RISCVInstInfoAND _instinfoAND;

    RISCVInstInfoSLL _instinfoSLL;

    RISCVInstInfoSRL _instinfoSRL;

    RISCVInstInfoSRA _instinfoSRA;

    RISCVInstInfoSLT _instinfoSLT;

    RISCVInstInfoSLTU _instinfoSLTU;

    RISCVInstInfoADDI _instinfoADDI;

    RISCVInstInfoXORI _instinfoXORI;

    RISCVInstInfoORI _instinfoORI;

    RISCVInstInfoANDI _instinfoANDI;

    RISCVInstInfoSLTI _instinfoSLTI;

    RISCVInstInfoSLTIU _instinfoSLTIU;

    RISCVInstInfoSLLI _instinfoSLLI;

    RISCVInstInfoSRLI _instinfoSRLI;

    RISCVInstInfoSRAI _instinfoSRAI;

    RISCVInstInfoLB _instinfoLB;

    RISCVInstInfoLH _instinfoLH;

    RISCVInstInfoLW _instinfoLW;

    RISCVInstInfoLBU _instinfoLBU;

    RISCVInstInfoLHU _instinfoLHU;

    RISCVInstInfoSB _instinfoSB;

    RISCVInstInfoSH _instinfoSH;

    RISCVInstInfoSW _instinfoSW;

    RISCVInstInfoBEQ _instinfoBEQ;

    RISCVInstInfoBNE _instinfoBNE;

    RISCVInstInfoBLT _instinfoBLT;

    RISCVInstInfoBGE _instinfoBGE;

    RISCVInstInfoBLTU _instinfoBLTU;

    RISCVInstInfoBGEU _instinfoBGEU;

    RISCVInstInfoJAL _instinfoJAL;

    RISCVInstInfoJALR _instinfoJALR;

    RISCVInstInfoLUI _instinfoLUI;

    RISCVInstInfoAUIPC _instinfoAUIPC;

    RISCVInstInfoMUL _instinfoMUL;

    RISCVInstInfoMULH _instinfoMULH;

    RISCVInstInfoMULHSU _instinfoMULHSU;

    RISCVInstInfoMULHU _instinfoMULHU;

    RISCVInstInfoDIV _instinfoDIV;

    RISCVInstInfoDIVU _instinfoDIVU;

    RISCVInstInfoREM _instinfoREM;

    RISCVInstInfoREMU _instinfoREMU;

    RISCVInstInfoLR _instinfoLR;

    RISCVInstInfoSC _instinfoSC;

    RISCVInstInfoAMOSWAP _instinfoAMOSWAP;

    RISCVInstInfoAMOADD _instinfoAMOADD;

    RISCVInstInfoAMOAND _instinfoAMOAND;

    RISCVInstInfoAMOOR _instinfoAMOOR;

    RISCVInstInfoAMOXOR _instinfoAMOXOR;

   public:
    RISCVInstInfo() = default;
    InstInfo& get_instinfo(uint32_t opcode) {
        switch (opcode) {
            case RISCVInst::ADD:
                return _instinfoADD;

            case RISCVInst::SUB:
                return _instinfoSUB;

            case RISCVInst::XOR:
                return _instinfoXOR;

            case RISCVInst::OR:
                return _instinfoOR;

            case RISCVInst::AND:
                return _instinfoAND;

            case RISCVInst::SLL:
                return _instinfoSLL;

            case RISCVInst::SRL:
                return _instinfoSRL;

            case RISCVInst::SRA:
                return _instinfoSRA;

            case RISCVInst::SLT:
                return _instinfoSLT;

            case RISCVInst::SLTU:
                return _instinfoSLTU;

            case RISCVInst::ADDI:
                return _instinfoADDI;

            case RISCVInst::XORI:
                return _instinfoXORI;

            case RISCVInst::ORI:
                return _instinfoORI;

            case RISCVInst::ANDI:
                return _instinfoANDI;

            case RISCVInst::SLTI:
                return _instinfoSLTI;

            case RISCVInst::SLTIU:
                return _instinfoSLTIU;

            case RISCVInst::SLLI:
                return _instinfoSLLI;

            case RISCVInst::SRLI:
                return _instinfoSRLI;

            case RISCVInst::SRAI:
                return _instinfoSRAI;

            case RISCVInst::LB:
                return _instinfoLB;

            case RISCVInst::LH:
                return _instinfoLH;

            case RISCVInst::LW:
                return _instinfoLW;

            case RISCVInst::LBU:
                return _instinfoLBU;

            case RISCVInst::LHU:
                return _instinfoLHU;

            case RISCVInst::SB:
                return _instinfoSB;

            case RISCVInst::SH:
                return _instinfoSH;

            case RISCVInst::SW:
                return _instinfoSW;

            case RISCVInst::BEQ:
                return _instinfoBEQ;

            case RISCVInst::BNE:
                return _instinfoBNE;

            case RISCVInst::BLT:
                return _instinfoBLT;

            case RISCVInst::BGE:
                return _instinfoBGE;

            case RISCVInst::BLTU:
                return _instinfoBLTU;

            case RISCVInst::BGEU:
                return _instinfoBGEU;

            case RISCVInst::JAL:
                return _instinfoJAL;

            case RISCVInst::JALR:
                return _instinfoJALR;

            case RISCVInst::LUI:
                return _instinfoLUI;

            case RISCVInst::AUIPC:
                return _instinfoAUIPC;

            case RISCVInst::MUL:
                return _instinfoMUL;

            case RISCVInst::MULH:
                return _instinfoMULH;

            case RISCVInst::MULHSU:
                return _instinfoMULHSU;

            case RISCVInst::MULHU:
                return _instinfoMULHU;

            case RISCVInst::DIV:
                return _instinfoDIV;

            case RISCVInst::DIVU:
                return _instinfoDIVU;

            case RISCVInst::REM:
                return _instinfoREM;

            case RISCVInst::REMU:
                return _instinfoREMU;

            case RISCVInst::LR:
                return _instinfoLR;

            case RISCVInst::SC:
                return _instinfoSC;

            case RISCVInst::AMOSWAP:
                return _instinfoAMOSWAP;

            case RISCVInst::AMOADD:
                return _instinfoAMOADD;

            case RISCVInst::AMOAND:
                return _instinfoAMOAND;

            case RISCVInst::AMOOR:
                return _instinfoAMOOR;

            case RISCVInst::AMOXOR:
                return _instinfoAMOXOR;

            default:
                return TargetInstInfo::get_instinfo(opcode);
        }
    }
};

const TargetInstInfo& getRISCVInstInfo() {
    static RISCVInstInfo instance;
    return instance;
}
TARGET_NAMESPACE_END