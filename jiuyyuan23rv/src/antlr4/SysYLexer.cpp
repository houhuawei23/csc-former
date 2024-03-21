
// Generated from ./src/antlr4/SysY.g4 by ANTLR 4.12.0

#include "SysYLexer.h"

using namespace antlr4;

using namespace antlr4;

namespace {

struct SysYLexerStaticData final {
  SysYLexerStaticData(std::vector<std::string> ruleNames, std::vector<std::string> channelNames,
                      std::vector<std::string> modeNames, std::vector<std::string> literalNames,
                      std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)),
        channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)),
        literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {
  }

  SysYLexerStaticData(const SysYLexerStaticData&) = delete;
  SysYLexerStaticData(SysYLexerStaticData&&) = delete;
  SysYLexerStaticData& operator=(const SysYLexerStaticData&) = delete;
  SysYLexerStaticData& operator=(SysYLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sysylexerLexerOnceFlag;
SysYLexerStaticData* sysylexerLexerStaticData = nullptr;

void sysylexerLexerInitialize() {
  assert(sysylexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<SysYLexerStaticData>(
      std::vector<std::string>{"INT",
                               "FLOAT",
                               "VOID",
                               "CONST",
                               "FOR",
                               "DO",
                               "WHILE",
                               "IF",
                               "ELSE",
                               "CONTINUE",
                               "BREAK",
                               "RETURN",
                               "LPAREN",
                               "RPAREN",
                               "LBRACKET",
                               "RBRACKET",
                               "LBRACES",
                               "RBRACES",
                               "COMMA",
                               "SEMICOLON",
                               "ASSIGN",
                               "ADD",
                               "SUB",
                               "MUL",
                               "DIV",
                               "MOD",
                               "LT",
                               "GT",
                               "LE",
                               "GE",
                               "EQ",
                               "NE",
                               "AND",
                               "OR",
                               "NOT",
                               "INTLITERAL",
                               "DECLITERAL",
                               "HEXLITERAL",
                               "OCTLITERAL",
                               "FLOATLITERAL",
                               "DECFLOATLITERAL",
                               "DECEXPONENT",
                               "HEXFLOATLITERAL",
                               "BINEXPONENT",
                               "IDENTIFIER",
                               "LETTER",
                               "DIGIT",
                               "STRING",
                               "ESC",
                               "SPACE",
                               "LINECOMMENT",
                               "BLOCKCOMMENT"},
      std::vector<std::string>{"DEFAULT_TOKEN_CHANNEL", "HIDDEN"}, std::vector<std::string>{"DEFAULT_MODE"},
      std::vector<std::string>{"",     "'int'",  "'float'",    "'void'",  "'const'",  "'for'", "'do'", "'while'",
                               "'if'", "'else'", "'continue'", "'break'", "'return'", "'('",   "')'",  "'['",
                               "']'",  "'{'",    "'}'",        "','",     "';'",      "'='",   "'+'",  "'-'",
                               "'*'",  "'/'",    "'%'",        "'<'",     "'>'",      "'<='",  "'>='", "'=='",
                               "'!='", "'&&'",   "'||'",       "'!'"},
      std::vector<std::string>{
          "",         "INT",         "FLOAT",       "VOID",  "CONST",      "FOR",          "DO",         "WHILE",
          "IF",       "ELSE",        "CONTINUE",    "BREAK", "RETURN",     "LPAREN",       "RPAREN",     "LBRACKET",
          "RBRACKET", "LBRACES",     "RBRACES",     "COMMA", "SEMICOLON",  "ASSIGN",       "ADD",        "SUB",
          "MUL",      "DIV",         "MOD",         "LT",    "GT",         "LE",           "GE",         "EQ",
          "NE",       "AND",         "OR",          "NOT",   "INTLITERAL", "FLOATLITERAL", "IDENTIFIER", "STRING",
          "SPACE",    "LINECOMMENT", "BLOCKCOMMENT"});
  static const int32_t serializedATNSegment[] = {
      4,   0,   42,  402, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,
      4,   7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,
      2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  2,   14,  7,   14,  2,   15,  7,
      15,  2,   16,  7,   16,  2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20,  2,   21,
      7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,   25,  7,   25,  2,   26,  7,   26,  2,
      27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29,  2,   30,  7,   30,  2,   31,  7,   31,  2,   32,  7,   32,
      2,   33,  7,   33,  2,   34,  7,   34,  2,   35,  7,   35,  2,   36,  7,   36,  2,   37,  7,   37,  2,   38,  7,
      38,  2,   39,  7,   39,  2,   40,  7,   40,  2,   41,  7,   41,  2,   42,  7,   42,  2,   43,  7,   43,  2,   44,
      7,   44,  2,   45,  7,   45,  2,   46,  7,   46,  2,   47,  7,   47,  2,   48,  7,   48,  2,   49,  7,   49,  2,
      50,  7,   50,  2,   51,  7,   51,  1,   0,   1,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,
      1,   1,   1,   1,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   3,   1,   3,   1,   3,   1,   3,   1,
      3,   1,   3,   1,   4,   1,   4,   1,   4,   1,   4,   1,   5,   1,   5,   1,   5,   1,   6,   1,   6,   1,   6,
      1,   6,   1,   6,   1,   6,   1,   7,   1,   7,   1,   7,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,
      9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   10,  1,   10,  1,   10,
      1,   10,  1,   10,  1,   10,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   11,  1,   12,  1,
      12,  1,   13,  1,   13,  1,   14,  1,   14,  1,   15,  1,   15,  1,   16,  1,   16,  1,   17,  1,   17,  1,   18,
      1,   18,  1,   19,  1,   19,  1,   20,  1,   20,  1,   21,  1,   21,  1,   22,  1,   22,  1,   23,  1,   23,  1,
      24,  1,   24,  1,   25,  1,   25,  1,   26,  1,   26,  1,   27,  1,   27,  1,   28,  1,   28,  1,   28,  1,   29,
      1,   29,  1,   29,  1,   30,  1,   30,  1,   30,  1,   31,  1,   31,  1,   31,  1,   32,  1,   32,  1,   32,  1,
      33,  1,   33,  1,   33,  1,   34,  1,   34,  1,   35,  1,   35,  1,   35,  3,   35,  225, 8,   35,  1,   36,  1,
      36,  5,   36,  229, 8,   36,  10,  36,  12,  36,  232, 9,   36,  1,   37,  1,   37,  1,   37,  4,   37,  237, 8,
      37,  11,  37,  12,  37,  238, 1,   38,  1,   38,  5,   38,  243, 8,   38,  10,  38,  12,  38,  246, 9,   38,  1,
      39,  1,   39,  3,   39,  250, 8,   39,  1,   40,  4,   40,  253, 8,   40,  11,  40,  12,  40,  254, 1,   40,  1,
      40,  5,   40,  259, 8,   40,  10,  40,  12,  40,  262, 9,   40,  1,   40,  3,   40,  265, 8,   40,  1,   40,  1,
      40,  4,   40,  269, 8,   40,  11,  40,  12,  40,  270, 1,   40,  3,   40,  274, 8,   40,  1,   40,  4,   40,  277,
      8,   40,  11,  40,  12,  40,  278, 1,   40,  3,   40,  282, 8,   40,  1,   41,  1,   41,  3,   41,  286, 8,   41,
      1,   41,  4,   41,  289, 8,   41,  11,  41,  12,  41,  290, 1,   42,  1,   42,  1,   42,  4,   42,  296, 8,   42,
      11,  42,  12,  42,  297, 1,   42,  1,   42,  5,   42,  302, 8,   42,  10,  42,  12,  42,  305, 9,   42,  1,   42,
      3,   42,  308, 8,   42,  1,   42,  1,   42,  1,   42,  1,   42,  4,   42,  314, 8,   42,  11,  42,  12,  42,  315,
      1,   42,  3,   42,  319, 8,   42,  1,   42,  1,   42,  1,   42,  4,   42,  324, 8,   42,  11,  42,  12,  42,  325,
      1,   42,  3,   42,  329, 8,   42,  1,   43,  1,   43,  3,   43,  333, 8,   43,  1,   43,  4,   43,  336, 8,   43,
      11,  43,  12,  43,  337, 1,   44,  1,   44,  1,   44,  5,   44,  343, 8,   44,  10,  44,  12,  44,  346, 9,   44,
      1,   45,  1,   45,  1,   46,  1,   46,  1,   47,  1,   47,  1,   47,  5,   47,  355, 8,   47,  10,  47,  12,  47,
      358, 9,   47,  1,   47,  1,   47,  1,   48,  1,   48,  1,   48,  1,   48,  3,   48,  366, 8,   48,  1,   49,  1,
      49,  1,   49,  1,   49,  1,   50,  1,   50,  1,   50,  1,   50,  5,   50,  376, 8,   50,  10,  50,  12,  50,  379,
      9,   50,  1,   50,  3,   50,  382, 8,   50,  1,   50,  3,   50,  385, 8,   50,  1,   50,  1,   50,  1,   51,  1,
      51,  1,   51,  1,   51,  5,   51,  393, 8,   51,  10,  51,  12,  51,  396, 9,   51,  1,   51,  1,   51,  1,   51,
      1,   51,  1,   51,  3,   356, 377, 394, 0,   52,  1,   1,   3,   2,   5,   3,   7,   4,   9,   5,   11,  6,   13,
      7,   15,  8,   17,  9,   19,  10,  21,  11,  23,  12,  25,  13,  27,  14,  29,  15,  31,  16,  33,  17,  35,  18,
      37,  19,  39,  20,  41,  21,  43,  22,  45,  23,  47,  24,  49,  25,  51,  26,  53,  27,  55,  28,  57,  29,  59,
      30,  61,  31,  63,  32,  65,  33,  67,  34,  69,  35,  71,  36,  73,  0,   75,  0,   77,  0,   79,  37,  81,  0,
      83,  0,   85,  0,   87,  0,   89,  38,  91,  0,   93,  0,   95,  39,  97,  0,   99,  40,  101, 41,  103, 42,  1,
      0,   11,  1,   0,   49,  57,  1,   0,   48,  57,  2,   0,   88,  88,  120, 120, 3,   0,   48,  57,  65,  70,  97,
      102, 1,   0,   48,  55,  2,   0,   69,  69,  101, 101, 2,   0,   43,  43,  45,  45,  2,   0,   80,  80,  112, 112,
      3,   0,   65,  90,  95,  95,  97,  122, 3,   0,   9,   10,  13,  13,  32,  32,  1,   1,   10,  10,  425, 0,   1,
      1,   0,   0,   0,   0,   3,   1,   0,   0,   0,   0,   5,   1,   0,   0,   0,   0,   7,   1,   0,   0,   0,   0,
      9,   1,   0,   0,   0,   0,   11,  1,   0,   0,   0,   0,   13,  1,   0,   0,   0,   0,   15,  1,   0,   0,   0,
      0,   17,  1,   0,   0,   0,   0,   19,  1,   0,   0,   0,   0,   21,  1,   0,   0,   0,   0,   23,  1,   0,   0,
      0,   0,   25,  1,   0,   0,   0,   0,   27,  1,   0,   0,   0,   0,   29,  1,   0,   0,   0,   0,   31,  1,   0,
      0,   0,   0,   33,  1,   0,   0,   0,   0,   35,  1,   0,   0,   0,   0,   37,  1,   0,   0,   0,   0,   39,  1,
      0,   0,   0,   0,   41,  1,   0,   0,   0,   0,   43,  1,   0,   0,   0,   0,   45,  1,   0,   0,   0,   0,   47,
      1,   0,   0,   0,   0,   49,  1,   0,   0,   0,   0,   51,  1,   0,   0,   0,   0,   53,  1,   0,   0,   0,   0,
      55,  1,   0,   0,   0,   0,   57,  1,   0,   0,   0,   0,   59,  1,   0,   0,   0,   0,   61,  1,   0,   0,   0,
      0,   63,  1,   0,   0,   0,   0,   65,  1,   0,   0,   0,   0,   67,  1,   0,   0,   0,   0,   69,  1,   0,   0,
      0,   0,   71,  1,   0,   0,   0,   0,   79,  1,   0,   0,   0,   0,   89,  1,   0,   0,   0,   0,   95,  1,   0,
      0,   0,   0,   99,  1,   0,   0,   0,   0,   101, 1,   0,   0,   0,   0,   103, 1,   0,   0,   0,   1,   105, 1,
      0,   0,   0,   3,   109, 1,   0,   0,   0,   5,   115, 1,   0,   0,   0,   7,   120, 1,   0,   0,   0,   9,   126,
      1,   0,   0,   0,   11,  130, 1,   0,   0,   0,   13,  133, 1,   0,   0,   0,   15,  139, 1,   0,   0,   0,   17,
      142, 1,   0,   0,   0,   19,  147, 1,   0,   0,   0,   21,  156, 1,   0,   0,   0,   23,  162, 1,   0,   0,   0,
      25,  169, 1,   0,   0,   0,   27,  171, 1,   0,   0,   0,   29,  173, 1,   0,   0,   0,   31,  175, 1,   0,   0,
      0,   33,  177, 1,   0,   0,   0,   35,  179, 1,   0,   0,   0,   37,  181, 1,   0,   0,   0,   39,  183, 1,   0,
      0,   0,   41,  185, 1,   0,   0,   0,   43,  187, 1,   0,   0,   0,   45,  189, 1,   0,   0,   0,   47,  191, 1,
      0,   0,   0,   49,  193, 1,   0,   0,   0,   51,  195, 1,   0,   0,   0,   53,  197, 1,   0,   0,   0,   55,  199,
      1,   0,   0,   0,   57,  201, 1,   0,   0,   0,   59,  204, 1,   0,   0,   0,   61,  207, 1,   0,   0,   0,   63,
      210, 1,   0,   0,   0,   65,  213, 1,   0,   0,   0,   67,  216, 1,   0,   0,   0,   69,  219, 1,   0,   0,   0,
      71,  224, 1,   0,   0,   0,   73,  226, 1,   0,   0,   0,   75,  233, 1,   0,   0,   0,   77,  240, 1,   0,   0,
      0,   79,  249, 1,   0,   0,   0,   81,  281, 1,   0,   0,   0,   83,  283, 1,   0,   0,   0,   85,  328, 1,   0,
      0,   0,   87,  330, 1,   0,   0,   0,   89,  339, 1,   0,   0,   0,   91,  347, 1,   0,   0,   0,   93,  349, 1,
      0,   0,   0,   95,  351, 1,   0,   0,   0,   97,  365, 1,   0,   0,   0,   99,  367, 1,   0,   0,   0,   101, 371,
      1,   0,   0,   0,   103, 388, 1,   0,   0,   0,   105, 106, 5,   105, 0,   0,   106, 107, 5,   110, 0,   0,   107,
      108, 5,   116, 0,   0,   108, 2,   1,   0,   0,   0,   109, 110, 5,   102, 0,   0,   110, 111, 5,   108, 0,   0,
      111, 112, 5,   111, 0,   0,   112, 113, 5,   97,  0,   0,   113, 114, 5,   116, 0,   0,   114, 4,   1,   0,   0,
      0,   115, 116, 5,   118, 0,   0,   116, 117, 5,   111, 0,   0,   117, 118, 5,   105, 0,   0,   118, 119, 5,   100,
      0,   0,   119, 6,   1,   0,   0,   0,   120, 121, 5,   99,  0,   0,   121, 122, 5,   111, 0,   0,   122, 123, 5,
      110, 0,   0,   123, 124, 5,   115, 0,   0,   124, 125, 5,   116, 0,   0,   125, 8,   1,   0,   0,   0,   126, 127,
      5,   102, 0,   0,   127, 128, 5,   111, 0,   0,   128, 129, 5,   114, 0,   0,   129, 10,  1,   0,   0,   0,   130,
      131, 5,   100, 0,   0,   131, 132, 5,   111, 0,   0,   132, 12,  1,   0,   0,   0,   133, 134, 5,   119, 0,   0,
      134, 135, 5,   104, 0,   0,   135, 136, 5,   105, 0,   0,   136, 137, 5,   108, 0,   0,   137, 138, 5,   101, 0,
      0,   138, 14,  1,   0,   0,   0,   139, 140, 5,   105, 0,   0,   140, 141, 5,   102, 0,   0,   141, 16,  1,   0,
      0,   0,   142, 143, 5,   101, 0,   0,   143, 144, 5,   108, 0,   0,   144, 145, 5,   115, 0,   0,   145, 146, 5,
      101, 0,   0,   146, 18,  1,   0,   0,   0,   147, 148, 5,   99,  0,   0,   148, 149, 5,   111, 0,   0,   149, 150,
      5,   110, 0,   0,   150, 151, 5,   116, 0,   0,   151, 152, 5,   105, 0,   0,   152, 153, 5,   110, 0,   0,   153,
      154, 5,   117, 0,   0,   154, 155, 5,   101, 0,   0,   155, 20,  1,   0,   0,   0,   156, 157, 5,   98,  0,   0,
      157, 158, 5,   114, 0,   0,   158, 159, 5,   101, 0,   0,   159, 160, 5,   97,  0,   0,   160, 161, 5,   107, 0,
      0,   161, 22,  1,   0,   0,   0,   162, 163, 5,   114, 0,   0,   163, 164, 5,   101, 0,   0,   164, 165, 5,   116,
      0,   0,   165, 166, 5,   117, 0,   0,   166, 167, 5,   114, 0,   0,   167, 168, 5,   110, 0,   0,   168, 24,  1,
      0,   0,   0,   169, 170, 5,   40,  0,   0,   170, 26,  1,   0,   0,   0,   171, 172, 5,   41,  0,   0,   172, 28,
      1,   0,   0,   0,   173, 174, 5,   91,  0,   0,   174, 30,  1,   0,   0,   0,   175, 176, 5,   93,  0,   0,   176,
      32,  1,   0,   0,   0,   177, 178, 5,   123, 0,   0,   178, 34,  1,   0,   0,   0,   179, 180, 5,   125, 0,   0,
      180, 36,  1,   0,   0,   0,   181, 182, 5,   44,  0,   0,   182, 38,  1,   0,   0,   0,   183, 184, 5,   59,  0,
      0,   184, 40,  1,   0,   0,   0,   185, 186, 5,   61,  0,   0,   186, 42,  1,   0,   0,   0,   187, 188, 5,   43,
      0,   0,   188, 44,  1,   0,   0,   0,   189, 190, 5,   45,  0,   0,   190, 46,  1,   0,   0,   0,   191, 192, 5,
      42,  0,   0,   192, 48,  1,   0,   0,   0,   193, 194, 5,   47,  0,   0,   194, 50,  1,   0,   0,   0,   195, 196,
      5,   37,  0,   0,   196, 52,  1,   0,   0,   0,   197, 198, 5,   60,  0,   0,   198, 54,  1,   0,   0,   0,   199,
      200, 5,   62,  0,   0,   200, 56,  1,   0,   0,   0,   201, 202, 5,   60,  0,   0,   202, 203, 5,   61,  0,   0,
      203, 58,  1,   0,   0,   0,   204, 205, 5,   62,  0,   0,   205, 206, 5,   61,  0,   0,   206, 60,  1,   0,   0,
      0,   207, 208, 5,   61,  0,   0,   208, 209, 5,   61,  0,   0,   209, 62,  1,   0,   0,   0,   210, 211, 5,   33,
      0,   0,   211, 212, 5,   61,  0,   0,   212, 64,  1,   0,   0,   0,   213, 214, 5,   38,  0,   0,   214, 215, 5,
      38,  0,   0,   215, 66,  1,   0,   0,   0,   216, 217, 5,   124, 0,   0,   217, 218, 5,   124, 0,   0,   218, 68,
      1,   0,   0,   0,   219, 220, 5,   33,  0,   0,   220, 70,  1,   0,   0,   0,   221, 225, 3,   73,  36,  0,   222,
      225, 3,   75,  37,  0,   223, 225, 3,   77,  38,  0,   224, 221, 1,   0,   0,   0,   224, 222, 1,   0,   0,   0,
      224, 223, 1,   0,   0,   0,   225, 72,  1,   0,   0,   0,   226, 230, 7,   0,   0,   0,   227, 229, 7,   1,   0,
      0,   228, 227, 1,   0,   0,   0,   229, 232, 1,   0,   0,   0,   230, 228, 1,   0,   0,   0,   230, 231, 1,   0,
      0,   0,   231, 74,  1,   0,   0,   0,   232, 230, 1,   0,   0,   0,   233, 234, 5,   48,  0,   0,   234, 236, 7,
      2,   0,   0,   235, 237, 7,   3,   0,   0,   236, 235, 1,   0,   0,   0,   237, 238, 1,   0,   0,   0,   238, 236,
      1,   0,   0,   0,   238, 239, 1,   0,   0,   0,   239, 76,  1,   0,   0,   0,   240, 244, 5,   48,  0,   0,   241,
      243, 7,   4,   0,   0,   242, 241, 1,   0,   0,   0,   243, 246, 1,   0,   0,   0,   244, 242, 1,   0,   0,   0,
      244, 245, 1,   0,   0,   0,   245, 78,  1,   0,   0,   0,   246, 244, 1,   0,   0,   0,   247, 250, 3,   81,  40,
      0,   248, 250, 3,   85,  42,  0,   249, 247, 1,   0,   0,   0,   249, 248, 1,   0,   0,   0,   250, 80,  1,   0,
      0,   0,   251, 253, 7,   1,   0,   0,   252, 251, 1,   0,   0,   0,   253, 254, 1,   0,   0,   0,   254, 252, 1,
      0,   0,   0,   254, 255, 1,   0,   0,   0,   255, 256, 1,   0,   0,   0,   256, 260, 5,   46,  0,   0,   257, 259,
      7,   1,   0,   0,   258, 257, 1,   0,   0,   0,   259, 262, 1,   0,   0,   0,   260, 258, 1,   0,   0,   0,   260,
      261, 1,   0,   0,   0,   261, 264, 1,   0,   0,   0,   262, 260, 1,   0,   0,   0,   263, 265, 3,   83,  41,  0,
      264, 263, 1,   0,   0,   0,   264, 265, 1,   0,   0,   0,   265, 282, 1,   0,   0,   0,   266, 268, 5,   46,  0,
      0,   267, 269, 7,   1,   0,   0,   268, 267, 1,   0,   0,   0,   269, 270, 1,   0,   0,   0,   270, 268, 1,   0,
      0,   0,   270, 271, 1,   0,   0,   0,   271, 273, 1,   0,   0,   0,   272, 274, 3,   83,  41,  0,   273, 272, 1,
      0,   0,   0,   273, 274, 1,   0,   0,   0,   274, 282, 1,   0,   0,   0,   275, 277, 7,   1,   0,   0,   276, 275,
      1,   0,   0,   0,   277, 278, 1,   0,   0,   0,   278, 276, 1,   0,   0,   0,   278, 279, 1,   0,   0,   0,   279,
      280, 1,   0,   0,   0,   280, 282, 3,   83,  41,  0,   281, 252, 1,   0,   0,   0,   281, 266, 1,   0,   0,   0,
      281, 276, 1,   0,   0,   0,   282, 82,  1,   0,   0,   0,   283, 285, 7,   5,   0,   0,   284, 286, 7,   6,   0,
      0,   285, 284, 1,   0,   0,   0,   285, 286, 1,   0,   0,   0,   286, 288, 1,   0,   0,   0,   287, 289, 7,   1,
      0,   0,   288, 287, 1,   0,   0,   0,   289, 290, 1,   0,   0,   0,   290, 288, 1,   0,   0,   0,   290, 291, 1,
      0,   0,   0,   291, 84,  1,   0,   0,   0,   292, 293, 5,   48,  0,   0,   293, 295, 7,   2,   0,   0,   294, 296,
      7,   3,   0,   0,   295, 294, 1,   0,   0,   0,   296, 297, 1,   0,   0,   0,   297, 295, 1,   0,   0,   0,   297,
      298, 1,   0,   0,   0,   298, 299, 1,   0,   0,   0,   299, 303, 5,   46,  0,   0,   300, 302, 7,   3,   0,   0,
      301, 300, 1,   0,   0,   0,   302, 305, 1,   0,   0,   0,   303, 301, 1,   0,   0,   0,   303, 304, 1,   0,   0,
      0,   304, 307, 1,   0,   0,   0,   305, 303, 1,   0,   0,   0,   306, 308, 3,   87,  43,  0,   307, 306, 1,   0,
      0,   0,   307, 308, 1,   0,   0,   0,   308, 329, 1,   0,   0,   0,   309, 310, 5,   48,  0,   0,   310, 311, 7,
      2,   0,   0,   311, 313, 5,   46,  0,   0,   312, 314, 7,   3,   0,   0,   313, 312, 1,   0,   0,   0,   314, 315,
      1,   0,   0,   0,   315, 313, 1,   0,   0,   0,   315, 316, 1,   0,   0,   0,   316, 318, 1,   0,   0,   0,   317,
      319, 3,   87,  43,  0,   318, 317, 1,   0,   0,   0,   318, 319, 1,   0,   0,   0,   319, 329, 1,   0,   0,   0,
      320, 321, 5,   48,  0,   0,   321, 323, 7,   2,   0,   0,   322, 324, 7,   3,   0,   0,   323, 322, 1,   0,   0,
      0,   324, 325, 1,   0,   0,   0,   325, 323, 1,   0,   0,   0,   325, 326, 1,   0,   0,   0,   326, 327, 1,   0,
      0,   0,   327, 329, 3,   87,  43,  0,   328, 292, 1,   0,   0,   0,   328, 309, 1,   0,   0,   0,   328, 320, 1,
      0,   0,   0,   329, 86,  1,   0,   0,   0,   330, 332, 7,   7,   0,   0,   331, 333, 7,   6,   0,   0,   332, 331,
      1,   0,   0,   0,   332, 333, 1,   0,   0,   0,   333, 335, 1,   0,   0,   0,   334, 336, 7,   1,   0,   0,   335,
      334, 1,   0,   0,   0,   336, 337, 1,   0,   0,   0,   337, 335, 1,   0,   0,   0,   337, 338, 1,   0,   0,   0,
      338, 88,  1,   0,   0,   0,   339, 344, 3,   91,  45,  0,   340, 343, 3,   91,  45,  0,   341, 343, 3,   93,  46,
      0,   342, 340, 1,   0,   0,   0,   342, 341, 1,   0,   0,   0,   343, 346, 1,   0,   0,   0,   344, 342, 1,   0,
      0,   0,   344, 345, 1,   0,   0,   0,   345, 90,  1,   0,   0,   0,   346, 344, 1,   0,   0,   0,   347, 348, 7,
      8,   0,   0,   348, 92,  1,   0,   0,   0,   349, 350, 7,   1,   0,   0,   350, 94,  1,   0,   0,   0,   351, 356,
      5,   34,  0,   0,   352, 355, 3,   97,  48,  0,   353, 355, 9,   0,   0,   0,   354, 352, 1,   0,   0,   0,   354,
      353, 1,   0,   0,   0,   355, 358, 1,   0,   0,   0,   356, 357, 1,   0,   0,   0,   356, 354, 1,   0,   0,   0,
      357, 359, 1,   0,   0,   0,   358, 356, 1,   0,   0,   0,   359, 360, 5,   34,  0,   0,   360, 96,  1,   0,   0,
      0,   361, 362, 5,   92,  0,   0,   362, 366, 5,   34,  0,   0,   363, 364, 5,   92,  0,   0,   364, 366, 5,   92,
      0,   0,   365, 361, 1,   0,   0,   0,   365, 363, 1,   0,   0,   0,   366, 98,  1,   0,   0,   0,   367, 368, 7,
      9,   0,   0,   368, 369, 1,   0,   0,   0,   369, 370, 6,   49,  0,   0,   370, 100, 1,   0,   0,   0,   371, 372,
      5,   47,  0,   0,   372, 373, 5,   47,  0,   0,   373, 377, 1,   0,   0,   0,   374, 376, 9,   0,   0,   0,   375,
      374, 1,   0,   0,   0,   376, 379, 1,   0,   0,   0,   377, 378, 1,   0,   0,   0,   377, 375, 1,   0,   0,   0,
      378, 381, 1,   0,   0,   0,   379, 377, 1,   0,   0,   0,   380, 382, 5,   13,  0,   0,   381, 380, 1,   0,   0,
      0,   381, 382, 1,   0,   0,   0,   382, 384, 1,   0,   0,   0,   383, 385, 7,   10,  0,   0,   384, 383, 1,   0,
      0,   0,   385, 386, 1,   0,   0,   0,   386, 387, 6,   50,  0,   0,   387, 102, 1,   0,   0,   0,   388, 389, 5,
      47,  0,   0,   389, 390, 5,   42,  0,   0,   390, 394, 1,   0,   0,   0,   391, 393, 9,   0,   0,   0,   392, 391,
      1,   0,   0,   0,   393, 396, 1,   0,   0,   0,   394, 395, 1,   0,   0,   0,   394, 392, 1,   0,   0,   0,   395,
      397, 1,   0,   0,   0,   396, 394, 1,   0,   0,   0,   397, 398, 5,   42,  0,   0,   398, 399, 5,   47,  0,   0,
      399, 400, 1,   0,   0,   0,   400, 401, 6,   51,  0,   0,   401, 104, 1,   0,   0,   0,   33,  0,   224, 230, 238,
      244, 249, 254, 260, 264, 270, 273, 278, 281, 285, 290, 297, 303, 307, 315, 318, 325, 328, 332, 337, 342, 344, 354,
      356, 365, 377, 381, 384, 394, 1,   6,   0,   0};
  staticData->serializedATN = antlr4::atn::SerializedATNView(
      serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysylexerLexerStaticData = staticData.release();
}

}  // namespace

SysYLexer::SysYLexer(CharStream* input) : Lexer(input) {
  SysYLexer::initialize();
  _interpreter =
      new atn::LexerATNSimulator(this, *sysylexerLexerStaticData->atn, sysylexerLexerStaticData->decisionToDFA,
                                 sysylexerLexerStaticData->sharedContextCache);
}

SysYLexer::~SysYLexer() {
  delete _interpreter;
}

std::string SysYLexer::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYLexer::getRuleNames() const {
  return sysylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SysYLexer::getChannelNames() const {
  return sysylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SysYLexer::getModeNames() const {
  return sysylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SysYLexer::getVocabulary() const {
  return sysylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SysYLexer::getSerializedATN() const {
  return sysylexerLexerStaticData->serializedATN;
}

const atn::ATN& SysYLexer::getATN() const {
  return *sysylexerLexerStaticData->atn;
}

void SysYLexer::initialize() {
  ::antlr4::internal::call_once(sysylexerLexerOnceFlag, sysylexerLexerInitialize);
}
