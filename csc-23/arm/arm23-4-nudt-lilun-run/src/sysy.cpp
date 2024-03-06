#include "tree/ParseTreeWalker.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
#include "SysYLexer.h"
#include "SysYParser.h"
using namespace antlr4;
// #include "SysYFormatter.h"
#include "SysYIRGenerator.h"
#include "backend/codegen.hpp"
using namespace sysy;
using backend::CodeGen;

int main(int argc, char **argv)
{
    bool genir = false;
    if (argc > 2)
    {
        genir = true;
    }
    if (argc > 5)
    {
        ifstream fin(argv[4]);
        if (not fin)
        {
            cerr << "Failed to open file " << argv[4];
            return EXIT_FAILURE;
        }
        ofstream fout(argv[3]);
        if (not fout)
        {
            cerr << "Failed to open file " << argv[3];
            return EXIT_FAILURE;
        }
        ANTLRInputStream input(fin);
        SysYLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        SysYParser parser(&tokens);
        auto moduleAST = parser.module();

        SysYIRGenerator generator;
        generator.visitModule(moduleAST);
        auto moduleIR = generator.get();
        DCE dce0(moduleIR);
        dce0.Run();
        Inline Inl(moduleIR);
        auto InlIR = Inl.Run();
        LoopFind loopfind1(InlIR);
        auto loopfindIR1 = loopfind1.Run();
        LoopUnroll loopunroll1(loopfindIR1, 1);
        auto loopunrollIR1 = loopunroll1.Run();
        LoadCut ldCut(loopunrollIR1);
        auto ldCutIR = ldCut.Run();
        CommonExp CmExp(ldCutIR);
        auto CmExpIR = CmExp.Run();
        ConstSpread ConSp(CmExpIR);
        auto ConSpIR = ConSp.Run();
        InstrCombine InstrCb(ConSpIR);
        auto InstrCbIR = InstrCb.Run();
        DCE dce(InstrCbIR);
        auto DceIR = dce.Run();
        // LoopFind loopfind2(DceIR);
        // auto loopfindIR2 = loopfind2.Run();
        // LoopUnroll loopunroll2(loopfindIR2, 2);
        // auto loopunrollIR2 = loopunroll2.Run();
        LoadCut ldCut2(DceIR);
        auto ldCutIR2 = ldCut2.Run();
        CommonExp CmExp2(ldCutIR2);
        auto CmExpIR2 = CmExp2.Run();
        ConstSpread ConSp2(CmExpIR2, 2);
        auto ConSpIR2 = ConSp2.Run();
        InstrCombine InstrCb2(ConSpIR2);
        auto InstrCbIR2 = InstrCb2.Run();
        DCE dce2(InstrCbIR2);
        auto DceIR2 = dce2.Run();

        auto finalIR = DceIR2;
        CodeGen codegen(finalIR);
        string asmCode = codegen.code_gen();
        fout << asmCode << endl;
        fout.close();
        ;

        return EXIT_SUCCESS;
    }
    if (argc == 5)
    {
        ifstream fin(argv[4]);
        if (not fin)
        {
            cerr << "Failed to open file " << argv[4];
            return EXIT_FAILURE;
        }
        ofstream fout(argv[3]);
        if (not fout)
        {
            cerr << "Failed to open file " << argv[3];
            return EXIT_FAILURE;
        }
        ANTLRInputStream input(fin);
        SysYLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        SysYParser parser(&tokens);
        auto moduleAST = parser.module();

        SysYIRGenerator generator;
        generator.visitModule(moduleAST);
        auto moduleIR = generator.get();
        // only generate SysY IR code
        // if (genir)
        //{
        //  moduleIR->print(cout);
        //  return EXIT_SUCCESS;
        //}
        CodeGen codegen(moduleIR);
        string asmCode = codegen.code_gen();
        fout << asmCode << endl;
        fout.close();
        ;

        return EXIT_SUCCESS;
    }
    else if (argc == 3)
    {
        ifstream fin(argv[2]);
        if (not fin)
        {
            cerr << "Failed to open file " << argv[2];
            return EXIT_FAILURE;
        }
        ofstream fout(argv[1]);
        if (not fout)
        {
            cerr << "Failed to open file " << argv[1];
            return EXIT_FAILURE;
        }
        ANTLRInputStream input(fin);
        SysYLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        SysYParser parser(&tokens);
        auto moduleAST = parser.module();

        SysYIRGenerator generator;
        generator.visitModule(moduleAST);
        auto moduleIR = generator.get();
        // only generate SysY IR code
        // if (genir)
        //{
        //  moduleIR->print(cout);
        //  return EXIT_SUCCESS;
        //}
        CodeGen codegen(moduleIR);
        string asmCode = codegen.code_gen();
        fout << asmCode << endl;
        fout.close();
        ;

        return EXIT_SUCCESS;
    }
    else
    {
        if (argc > 3)
        {
            cerr << "Usage: " << argv[0] << "inputfile [ir]\n";
            return EXIT_FAILURE;
        }
        bool genir = false;
        if (argc > 2)
        {
            genir = true;
        }
        ifstream fin(argv[1]);
        if (not fin)
        {
            cerr << "Failed to open file " << argv[1];
            return EXIT_FAILURE;
        }
        ANTLRInputStream input(fin);
        SysYLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        SysYParser parser(&tokens);
        auto moduleAST = parser.module();

        SysYIRGenerator generator;
        generator.visitModule(moduleAST);
        auto moduleIR = generator.get();
        // only generate SysY IR code
        if (genir)
        {
            moduleIR->print(cout);
            return EXIT_SUCCESS;
        }

        CodeGen codegen(moduleIR);
        string asmCode = codegen.code_gen();
        cout << asmCode << endl;
        ;

        return EXIT_SUCCESS;
    }
}