#pragma once

#include "IR.h"
#include "IRBuilder.h"
#include "SysYBaseVisitor.h"
#include "SysYParser.h"
#include <cassert>
#include <forward_list>
#include <memory>
#include <string>

namespace sysy {

class SymbolTable {
  private:
    enum Kind {
        kModule,
        kFunction,
        kBlock,
    };

  public:
    struct ModuleScope {
        SymbolTable &table;
        ModuleScope(SymbolTable &table) : table(table) { table.enter(kModule); }
        ~ModuleScope() { table.exit(); }
    };
    struct FunctionScope {
        SymbolTable &table;
        FunctionScope(SymbolTable &table) : table(table) {
            table.enter(kFunction);
        }
        ~FunctionScope() { table.exit(); }
    };

    struct BlockScope {
        SymbolTable &table;
        BlockScope(SymbolTable &table) : table(table) { table.enter(kBlock); }
        ~BlockScope() { table.exit(); }
    };

  private:
    std::forward_list<std::pair<Kind, std::map<std::string, Value *>>> symbols;

  public:
    SymbolTable() = default;

  public:
    bool isModuleScope() const { return symbols.front().first == kModule; }
    bool isFunctionScope() const { return symbols.front().first == kFunction; }
    bool isBlockScope() const { return symbols.front().first == kBlock; }
    Value *lookup(const std::string &name) const {
        for (auto &scope : symbols) {
            auto iter = scope.second.find(name);
            if (iter != scope.second.end())
                return iter->second;
        }
        return nullptr;
    }
    auto insert(const std::string &name, Value *value) {
        assert(not symbols.empty());
        return symbols.front().second.emplace(name, value);
    }
    // void remove(const std::string &name) {
    //   for (auto &scope : symbols) {
    //     auto iter = scope.find(name);
    //     if (iter != scope.end()) {
    //       scope.erase(iter);
    //       return;
    //     }
    //   }
    // }
  private:
    void enter(Kind kind) {
        symbols.emplace_front();
        symbols.front().first = kind;
    }
    void exit() { symbols.pop_front(); }
}; // class SymbolTable

class SysYIRGenerator : public SysYBaseVisitor {
  private:
    std::unique_ptr<Module> module;
    IRBuilder builder;
    SymbolTable symbols;
    int d = 0, n = 0;
    vector<int> path;
    bool isalloca;
    AllocaInst *current_alloca;
    GlobalValue *current_global;
    Type *current_type;
    int numdims = 0;

  public:
    SysYIRGenerator() = default;

  public:
    Module *get() const { return module.get(); }

  public:
    virtual std::any visitModule(SysYParser::ModuleContext *ctx) override;

    virtual std::any visitDecl(SysYParser::DeclContext *ctx) override;

    virtual std::any visitBtype(SysYParser::BtypeContext *ctx) override;

    virtual std::any visitVarDef(SysYParser::VarDefContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitInitValue(SysYParser::InitValueContext *ctx) override;

    virtual std::any visitFunc(SysYParser::FuncContext *ctx) override;

    virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override;

    virtual std::any
    visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any
    visitFuncFParam(SysYParser::FuncFParamContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitBlockStmt(SysYParser::BlockStmtContext *ctx) override;

    // virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx)
    // override;

    virtual std::any visitStmt(SysYParser::StmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any
    visitAssignStmt(SysYParser::AssignStmtContext *ctx) override;

    virtual std::any visitExpStmt(SysYParser::ExpStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitIfStmt(SysYParser::IfStmtContext *ctx) override;

    virtual std::any visitWhileStmt(SysYParser::WhileStmtContext *ctx) override;

    virtual std::any visitBreakStmt(SysYParser::BreakStmtContext *ctx) override;

    virtual std::any
    visitContinueStmt(SysYParser::ContinueStmtContext *ctx) override;

    virtual std::any
    visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override;

    virtual std::any
    visitEmptyStmt(SysYParser::EmptyStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any
    visitRelationExp(SysYParser::RelationExpContext *ctx) override;

    virtual std::any
    visitMultiplicativeExp(SysYParser::MultiplicativeExpContext *ctx) override;

    virtual std::any visitLValueExp(SysYParser::LValueExpContext *ctx) override;

    virtual std::any visitNumberExp(SysYParser::NumberExpContext *ctx) override;

    virtual std::any visitAndExp(SysYParser::AndExpContext *ctx) override;

    virtual std::any visitUnaryExp(SysYParser::UnaryExpContext *ctx) override;

    virtual std::any visitParenExp(SysYParser::ParenExpContext *ctx) override;

    virtual std::any
    visitStringExp(SysYParser::StringExpContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitOrExp(SysYParser::OrExpContext *ctx) override;

    virtual std::any visitCallExp(SysYParser::CallExpContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any
    visitAdditiveExp(SysYParser::AdditiveExpContext *ctx) override;

    virtual std::any visitEqualExp(SysYParser::EqualExpContext *ctx) override;

    virtual std::any visitCall(SysYParser::CallContext *ctx) override;

    virtual std::any visitLValue(SysYParser::LValueContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitNumber(SysYParser::NumberContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitString(SysYParser::StringContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any
    visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual std::any visitCondExp(SysYParser::ExpContext *ctx) {
        return visitChildren(ctx);
    }

  private:
    std::any visitGlobalDecl(SysYParser::DeclContext *ctx);
    std::any visitLocalDecl(SysYParser::DeclContext *ctx);
    Type *getArithmeticResultType(Type *lhs, Type *rhs) {
        assert(lhs->isIntOrFloat() and rhs->isIntOrFloat());
        return lhs == rhs ? lhs : Type::getFloatType();
    }
}; // class SysYIRGenerator

// load指令删减
class LoadCut {
  public:
    Module *OriginModule; // 输入的IR
    Module *pModule;      // 新生成的IR
    IRBuilder builder;    // IR生成器
    map<Value *, map<vector<Value *>, Instruction *>>
        AVALUE; // 记录每个变量存在哪个虚拟寄存器
    map<Value *, set<pair<Value *, vector<Value *>>>>
        RVALUE; // 记录虚拟寄存器存储哪个变量
    // set<Value *> RVALUE;            // 记录虚拟寄存器存储哪个变量
    map<Function *, bool> havecall; // 记录每个函数内是否有函数调用
    map<Function *, bool> ModifyGlbvl; // 记录函数是否修改全局变量
    bool hascall; // 记录当前函数是否有函数调用
    set<string> libfunc = {"getint",    "getch",     "getfloat",  "getarray",
                           "getfarray", "putint",    "putch",     "putfloat",
                           "putarray",  "putfarray", "starttime", "stoptime",
                           "putf"};

  public:
    LoadCut(Module *OriginModule) : OriginModule(OriginModule) {
        pModule = new Module();
    }

  public:
    // 计算每个基本块的Kill,Gen集合
    void CalKill_Gen(BasicBlock *curbb);
    // 计算每个基本块的In,Out集合
    void CalIn_Out(Function *curFunc);
    // 重新生成IR
    void RegenerateIR();
    // void RegenerateIR(std::ostream &os);
    // 将基本块按照拓扑排序生成
    void OrderBasicBlock(Function *, Function *);
    // 将基本块按照深度排序
    static bool BBCmp(BasicBlock *, BasicBlock *);
    // 分析函数是否修改了全局变量&是否有函数调用
    void AnalyzeFunc(Function *);
    void print_KILL_GEN(std::ostream &os);
    void print_IN_OUT(std::ostream &os);
    Module *Run();
    // Module *Run(std::ostream &os);
};

// 活跃变量分析
class Lifetime {
  public:
    Module *pModule;
    Lifetime(Module *pModule) : pModule(pModule) {}

  public:
    // 计算每个基本块的use,def集合
    void CalUse_Def(BasicBlock *);
    // 计算每个基本块的in,out集合
    void CalIn_out(Function *);
    void print_USE_DEF(std::ostream &os);
    void print_Live_IN_OUT(std::ostream &os);
    Module *Run();
};

// 死代码删除
class DCE {
  public:
    Module *pModule;
    DCE(Module *pModule) : pModule(pModule) {}

  public:
    Module *Run();
};

// 公共子表达式删除
class CommonExp {
  public:
    Module *OriginModule;
    Module *pModule;
    Module *ppModule;
    IRBuilder builder;
    map<Value *, Value *> Alter;
    map<Instruction::Kind, map<set<Value *>, Instruction *>> bInsts;
    map<Instruction::Kind, map<pair<Value *, Value *>, Instruction *>>
        OrderbInsts;
    map<Instruction::Kind, map<Value *, Instruction *>> uInsts;

  public:
    CommonExp(Module *OriginModule) : OriginModule(OriginModule) {
        pModule = new Module();
        ppModule = new Module();
    }
    // 计算BB产生的可用表达式
    void CalEval(BasicBlock *curbb, int pass);
    // 计算每个BB的In,Out集合
    void CalIn_Out(Function *curFunc);
    // 重新生成IR
    void RegenerateIR();
    Module *Run();
    // Module *Run(std::ostream &os);
};

// 必经节点分析
class Dom {
  public:
    Module *pModule;
    Dom(Module *pModule) : pModule(pModule) {}
    set<BasicBlock *> Allbbs;

  public:
    // 计算函数内所有基本块的必经节点
    void CalDom(Function *);
    Module *Run();
    // Module *Run(std::ostream &);
    void PRINT_DOM(std::ostream &os);
};

// 常数传播
class ConstSpread {
  public:
    Module *OriginModule;
    Module *pModule;
    IRBuilder builder;
    int pass;
    ConstSpread(Module *OriginModule, int pass = 1)
        : OriginModule(OriginModule), pass(pass) {
        pModule = new Module();
    }
    static const int MAX = 100;

  public:
    Module *Run();
    // 计算每个基本块InOut集合
    void CalIn_Out(Function *);
    // 根据每个基本块的In计算Out集合
    void Fs(BasicBlock *);
    void RegenerateIR();
};

// 指令组合
class InstrCombine {
  public:
    Module *OriginModule;
    Module *pModule;
    IRBuilder builder;
    InstrCombine(Module *OriginModule) : OriginModule(OriginModule) {
        pModule = new Module();
    }

  public:
    Module *Run();
    void RegenerateIR();
};

// 函数内联
class Inline {
  public:
    Module *OriginModule;
    Module *pModule;
    Inline(Module *OriginModule) : OriginModule(OriginModule) {
        pModule = new Module();
    }
    IRBuilder builder;

  public:
    Module *Run();
    // 分析函数是否可以内联
    void AnalyzeFunc(Function *);
    // 重新生成IR
    void RegenerateIR();
    // 为内联函数生成指令
    void GenInlineInstr();
};

// 识别循环
class LoopFind {
  public:
    Module *pModule;
    set<BasicBlock *> Allbbs;
    LoopFind(Module *pModule) : pModule(pModule) {}

  public:
    Module *Run();
    // 计算每个基本块的可达集合
    void CalAccess();
    void PRINT_ACCESS(std::ostream &os);
    // 计算函数内所有基本块的必经节点
    void CalDom(Function *);
    void PRINT_DOM(std::ostream &os);
    void GetLoop();
    void PRINT_LOOP(std::ostream &os);
};

// 不变量外提
class LCM {
  public:
};
// 循环展开
class LoopUnroll {
  public:
    Module *OriginModule;
    Module *pModule;
    int pass;
    LoopUnroll(Module *OriginModule, int pass)
        : pModule(OriginModule), pass(pass) {}
    IRBuilder builder;
    int iter_cnt = 0; // 迭代次数

  public:
    Module *Run();
    bool IsUnrollable(Loop curLoop);
    void ModifyIR();
    void Unroll(Loop);
};
} // namespace sysy