// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   SysYlex



#include "ParserDecl.hpp"


// Unqualified %code blocks.
#line 30 "cmmc/Frontend/ParserSysY.yy"



#line 52 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if SYSYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !SYSYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !SYSYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace SysY {
#line 144 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"

  /// Build a parser object.
  parser::parser (cmmc::DriverImpl& driver_yyarg)
#if SYSYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.YY_MOVE_OR_COPY< ArgList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.YY_MOVE_OR_COPY< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.YY_MOVE_OR_COPY< ExprPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.YY_MOVE_OR_COPY< FloatingPointStorage > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.YY_MOVE_OR_COPY< FunctionDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.YY_MOVE_OR_COPY< IntegerStorage > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.YY_MOVE_OR_COPY< NamedArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.YY_MOVE_OR_COPY< NamedVar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.YY_MOVE_OR_COPY< String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.YY_MOVE_OR_COPY< TypeRef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Def: // Def
        value.YY_MOVE_OR_COPY< VarDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefList: // DefList
        value.YY_MOVE_OR_COPY< VarDefList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DecList: // DecList
        value.YY_MOVE_OR_COPY< VarList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.move< ArgList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.move< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.move< ExprPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.move< FloatingPointStorage > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.move< FunctionDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.move< IntegerStorage > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.move< NamedArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.move< NamedVar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.move< String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.move< TypeRef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Def: // Def
        value.move< VarDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefList: // DefList
        value.move< VarDefList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DecList: // DecList
        value.move< VarList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.move< char > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.copy< ArgList > (that.value);
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.copy< Expr* > (that.value);
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.copy< ExprPack > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.copy< FloatingPointStorage > (that.value);
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.copy< FunctionDeclaration > (that.value);
        break;

      case symbol_kind::S_INT: // "Integer"
        value.copy< IntegerStorage > (that.value);
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.copy< NamedArg > (that.value);
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.copy< NamedVar > (that.value);
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.copy< String > (that.value);
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.copy< TypeRef > (that.value);
        break;

      case symbol_kind::S_Def: // Def
        value.copy< VarDef > (that.value);
        break;

      case symbol_kind::S_DefList: // DefList
        value.copy< VarDefList > (that.value);
        break;

      case symbol_kind::S_DecList: // DecList
        value.copy< VarList > (that.value);
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.copy< char > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.move< ArgList > (that.value);
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.move< Expr* > (that.value);
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.move< ExprPack > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.move< FloatingPointStorage > (that.value);
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.move< FunctionDeclaration > (that.value);
        break;

      case symbol_kind::S_INT: // "Integer"
        value.move< IntegerStorage > (that.value);
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.move< NamedArg > (that.value);
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.move< NamedVar > (that.value);
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.move< String > (that.value);
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.move< TypeRef > (that.value);
        break;

      case symbol_kind::S_Def: // Def
        value.move< VarDef > (that.value);
        break;

      case symbol_kind::S_DefList: // DefList
        value.move< VarDefList > (that.value);
        break;

      case symbol_kind::S_DecList: // DecList
        value.move< VarList > (that.value);
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.move< char > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if SYSYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if SYSYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // SYSYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_VarList: // VarList
        yylhs.value.emplace< ArgList > ();
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        yylhs.value.emplace< Expr* > ();
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        yylhs.value.emplace< ExprPack > ();
        break;

      case symbol_kind::S_FLOAT: // "Float"
        yylhs.value.emplace< FloatingPointStorage > ();
        break;

      case symbol_kind::S_FunDec: // FunDec
        yylhs.value.emplace< FunctionDeclaration > ();
        break;

      case symbol_kind::S_INT: // "Integer"
        yylhs.value.emplace< IntegerStorage > ();
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        yylhs.value.emplace< NamedArg > ();
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        yylhs.value.emplace< NamedVar > ();
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        yylhs.value.emplace< String > ();
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        yylhs.value.emplace< TypeRef > ();
        break;

      case symbol_kind::S_Def: // Def
        yylhs.value.emplace< VarDef > ();
        break;

      case symbol_kind::S_DefList: // DefList
        yylhs.value.emplace< VarDefList > ();
        break;

      case symbol_kind::S_DecList: // DecList
        yylhs.value.emplace< VarList > ();
        break;

      case symbol_kind::S_CHAR: // "Char"
        yylhs.value.emplace< char > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Program: ExtDefList "End of file"
#line 110 "cmmc/Frontend/ParserSysY.yy"
                        { driver.markEnd(); CMMC_NONTERMINAL(yylhs.location, Program, yystack_[1].location); }
#line 878 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 3: // ExtDefList: ExtDef ExtDefList
#line 112 "cmmc/Frontend/ParserSysY.yy"
                              { CMMC_NONTERMINAL(yylhs.location, ExtDefList, yystack_[1].location, yystack_[0].location); }
#line 884 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 4: // ExtDefList: %empty
#line 113 "cmmc/Frontend/ParserSysY.yy"
         { CMMC_EMPTY(yylhs.location, ExtDefList); }
#line 890 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 5: // ExtDef: QualifiedSpecifier SEMI
#line 115 "cmmc/Frontend/ParserSysY.yy"
                                { driver.addOpaqueType(std::move(yystack_[1].value.as < TypeRef > ())); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[1].location, yystack_[0].location); }
#line 896 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 6: // ExtDef: Def
#line 116 "cmmc/Frontend/ParserSysY.yy"
      { driver.addGlobalDef(std::move(yystack_[0].value.as < VarDef > ().type), std::move(yystack_[0].value.as < VarDef > ().var)); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[0].location); }
#line 902 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 7: // ExtDef: QualifiedSpecifier FunDec CompSt
#line 117 "cmmc/Frontend/ParserSysY.yy"
                                   { yystack_[1].value.as < FunctionDeclaration > ().retType = yystack_[2].value.as < TypeRef > (); driver.addFunctionDef({std::move(yystack_[1].value.as < FunctionDeclaration > ()), std::move(yystack_[0].value.as < ExprPack > ())}); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 908 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 8: // ExtDef: QualifiedSpecifier FunDec SEMI
#line 118 "cmmc/Frontend/ParserSysY.yy"
                                 { yystack_[1].value.as < FunctionDeclaration > ().retType = yystack_[2].value.as < TypeRef > (); driver.addFunctionDecl(std::move(yystack_[1].value.as < FunctionDeclaration > ())); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 914 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 9: // QualifiedSpecifier: Specifier
#line 121 "cmmc/Frontend/ParserSysY.yy"
                              { yylhs.value.as < TypeRef > () = std::move(yystack_[0].value.as < TypeRef > ()); CMMC_NONTERMINAL(yylhs.location, QualifiedSpecifier, yystack_[0].location); }
#line 920 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 10: // QualifiedSpecifier: CONST Specifier
#line 122 "cmmc/Frontend/ParserSysY.yy"
                  { yylhs.value.as < TypeRef > () = std::move(yystack_[0].value.as < TypeRef > ()); yylhs.value.as < TypeRef > ().qualifier.isConst = true;  CMMC_NONTERMINAL(yylhs.location, QualifiedSpecifier, yystack_[1].location, yystack_[0].location); }
#line 926 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 11: // Specifier: "Type"
#line 123 "cmmc/Frontend/ParserSysY.yy"
                { yylhs.value.as < TypeRef > () = { yystack_[0].value.as < String > (), TypeLookupSpace::Default, Qualifier{ false, yystack_[0].value.as < String > ().prefix().front() != 'u' } }; CMMC_NONTERMINAL(yylhs.location, Specifier, yystack_[0].location); }
#line 932 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 12: // Specifier: StructSpecifier
#line 124 "cmmc/Frontend/ParserSysY.yy"
                  { yylhs.value.as < TypeRef > () = std::move(yystack_[0].value.as < TypeRef > ()); CMMC_NONTERMINAL(yylhs.location, Specifier, yystack_[0].location); }
#line 938 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 13: // StructSpecifier: STRUCT "Identifier" LC DefList RC
#line 126 "cmmc/Frontend/ParserSysY.yy"
                                         { yylhs.value.as < TypeRef > () = { yystack_[3].value.as < String > (), TypeLookupSpace::Struct, Qualifier::getDefault() }; driver.addStructType(castLoc(yystack_[4].location), std::move(yystack_[3].value.as < String > ()), std::move(yystack_[1].value.as < VarDefList > ())); CMMC_NONTERMINAL(yylhs.location, StructSpecifier, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 944 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 14: // StructSpecifier: STRUCT "Identifier"
#line 127 "cmmc/Frontend/ParserSysY.yy"
            { yylhs.value.as < TypeRef > () = { std::move(yystack_[0].value.as < String > ()), TypeLookupSpace::Struct, Qualifier::getDefault() }; CMMC_NONTERMINAL(yylhs.location, StructSpecifier, yystack_[1].location, yystack_[0].location); }
#line 950 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 15: // VarDec: "Identifier"
#line 130 "cmmc/Frontend/ParserSysY.yy"
           { yylhs.value.as < NamedVar > () = { castLoc(yystack_[0].location), std::move(yystack_[0].value.as < String > ()), ArraySize{}, nullptr }; CMMC_NONTERMINAL(yylhs.location, VarDec, yystack_[0].location); }
#line 956 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 16: // VarDec: VarDec LB Exp RB
#line 131 "cmmc/Frontend/ParserSysY.yy"
                   { yylhs.value.as < NamedVar > () = std::move(yystack_[3].value.as < NamedVar > ()); yylhs.value.as < NamedVar > ().arraySize.push_back(std::move(yystack_[1].value.as < Expr* > ())); CMMC_NONTERMINAL(yylhs.location, VarDec, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 962 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 17: // VarDec: VarDec LB RB
#line 132 "cmmc/Frontend/ParserSysY.yy"
               { yylhs.value.as < NamedVar > () = std::move(yystack_[2].value.as < NamedVar > ()); yylhs.value.as < NamedVar > ().arraySize.push_back(nullptr); CMMC_NONTERMINAL(yylhs.location, VarDec, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 968 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 18: // FunDec: "Identifier" LP VarList RP
#line 134 "cmmc/Frontend/ParserSysY.yy"
                         { yylhs.value.as < FunctionDeclaration > ().loc = castLoc(yystack_[3].location); yylhs.value.as < FunctionDeclaration > ().symbol = std::move(yystack_[3].value.as < String > ()); yylhs.value.as < FunctionDeclaration > ().args = std::move(yystack_[1].value.as < ArgList > ()); CMMC_NONTERMINAL(yylhs.location, FunDec, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 974 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 19: // FunDec: "Identifier" LP RP
#line 135 "cmmc/Frontend/ParserSysY.yy"
           { yylhs.value.as < FunctionDeclaration > ().loc = castLoc(yystack_[2].location); yylhs.value.as < FunctionDeclaration > ().symbol = std::move(yystack_[2].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, FunDec, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 980 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 20: // VarList: ParamDec COMMA VarList
#line 137 "cmmc/Frontend/ParserSysY.yy"
                                { CMMC_CONCAT_PACK(yylhs.value.as < ArgList > (), yystack_[2].value.as < NamedArg > (), yystack_[0].value.as < ArgList > ()); CMMC_NONTERMINAL(yylhs.location, VarList, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 986 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 21: // VarList: ParamDec
#line 138 "cmmc/Frontend/ParserSysY.yy"
           { yylhs.value.as < ArgList > () = { std::move(yystack_[0].value.as < NamedArg > ()) }; CMMC_NONTERMINAL(yylhs.location, VarList, yystack_[0].location); }
#line 992 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 22: // ParamDec: QualifiedSpecifier VarDec
#line 140 "cmmc/Frontend/ParserSysY.yy"
                                    { yylhs.value.as < NamedArg > () = NamedArg{ std::move(yystack_[1].value.as < TypeRef > ()), std::move(yystack_[0].value.as < NamedVar > ()) }; CMMC_NONTERMINAL(yylhs.location, ParamDec, yystack_[1].location, yystack_[0].location); }
#line 998 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 23: // ParamDec: QualifiedSpecifier
#line 141 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < NamedArg > () = NamedArg{ std::move(yystack_[0].value.as < TypeRef > ()), NamedVar{} }; CMMC_NONTERMINAL(yylhs.location, ParamDec, yystack_[0].location); }
#line 1004 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 24: // CompSt: LC StmtList RC
#line 144 "cmmc/Frontend/ParserSysY.yy"
                       { yylhs.value.as < ExprPack > () = std::move(yystack_[1].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, CompSt, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1010 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 25: // StmtList: Stmt StmtList
#line 145 "cmmc/Frontend/ParserSysY.yy"
                        { CMMC_CONCAT_PACK(yylhs.value.as < ExprPack > (), yystack_[1].value.as < Expr* > (), yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, StmtList, yystack_[1].location, yystack_[0].location); }
#line 1016 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 26: // StmtList: %empty
#line 146 "cmmc/Frontend/ParserSysY.yy"
         { yylhs.value.as < ExprPack > () = {}; CMMC_EMPTY(yylhs.location, StmtList);}
#line 1022 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 27: // Stmt: ExpCommaSep SEMI
#line 148 "cmmc/Frontend/ParserSysY.yy"
                       { yylhs.value.as < Expr* > () = yystack_[1].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1028 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 28: // Stmt: CompSt
#line 149 "cmmc/Frontend/ParserSysY.yy"
         { yylhs.value.as < Expr* > () = CMMC_SCOPE(yystack_[0].location, yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[0].location); }
#line 1034 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 29: // Stmt: RETURN Exp SEMI
#line 150 "cmmc/Frontend/ParserSysY.yy"
                  { yylhs.value.as < Expr* > () = CMMC_RETURN(yystack_[2].location, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1040 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 30: // Stmt: RETURN SEMI
#line 151 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_RETURN(yystack_[1].location, nullptr); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1046 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 31: // Stmt: IF LP Exp RP Stmt
#line 152 "cmmc/Frontend/ParserSysY.yy"
                               { yylhs.value.as < Expr* > () = CMMC_IF(yystack_[4].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1052 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 32: // Stmt: IF LP Exp RP Stmt ELSE Stmt
#line 153 "cmmc/Frontend/ParserSysY.yy"
                              { yylhs.value.as < Expr* > () = CMMC_IF_ELSE(yystack_[6].location, yystack_[4].value.as < Expr* > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[6].location, yystack_[5].location, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1058 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 33: // Stmt: WHILE LP Exp RP Stmt
#line 154 "cmmc/Frontend/ParserSysY.yy"
                       { yylhs.value.as < Expr* > () = CMMC_WHILE(yystack_[4].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1064 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 34: // Stmt: BREAK SEMI
#line 155 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BREAK(yystack_[1].location); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1070 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 35: // Stmt: CONTINUE SEMI
#line 156 "cmmc/Frontend/ParserSysY.yy"
                { yylhs.value.as < Expr* > () = CMMC_CONTINUE(yystack_[1].location); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1076 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 36: // Stmt: Def
#line 157 "cmmc/Frontend/ParserSysY.yy"
      { yylhs.value.as < Expr* > () = CMMC_DEF(yystack_[0].value.as < VarDef > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[0].location); }
#line 1082 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 37: // Stmt: SEMI
#line 158 "cmmc/Frontend/ParserSysY.yy"
       { yylhs.value.as < Expr* > () = CMMC_EMPTY_STMT(yystack_[0].location); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[0].location); }
#line 1088 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 38: // Stmt: FOR LP Stmt ForOptional SEMI ForOptional RP Stmt
#line 159 "cmmc/Frontend/ParserSysY.yy"
                                                   { yylhs.value.as < Expr* > () = CMMC_FOR_LOOP(yystack_[7].location, yystack_[5].value.as < Expr* > (), yystack_[4].value.as < Expr* > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[7].location, yystack_[6].location, yystack_[5].location, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1094 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 39: // Stmt: DO Stmt WHILE LP Exp RP SEMI
#line 160 "cmmc/Frontend/ParserSysY.yy"
                               { yylhs.value.as < Expr* > () = CMMC_DO_WHILE(yystack_[6].location, yystack_[5].value.as < Expr* > (), yystack_[2].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[6].location, yystack_[5].location, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1100 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 40: // Stmt: GOTO "Identifier" SEMI
#line 161 "cmmc/Frontend/ParserSysY.yy"
               { yylhs.value.as < Expr* > () = CMMC_GOTO(yystack_[2].location, yystack_[1].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1106 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 41: // Stmt: "Identifier" COLON
#line 162 "cmmc/Frontend/ParserSysY.yy"
           { yylhs.value.as < Expr* > () = CMMC_LABEL(yystack_[1].location, yystack_[1].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1112 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 42: // Stmt: SWITCH LP Exp RP CompSt
#line 163 "cmmc/Frontend/ParserSysY.yy"
                          { yylhs.value.as < Expr* > () = CMMC_SWITCH(yystack_[4].location, yystack_[2].value.as < Expr* > (), CMMC_SCOPE(yystack_[0].location, yystack_[0].value.as < ExprPack > ())); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1118 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 43: // Stmt: CASE Exp COLON
#line 164 "cmmc/Frontend/ParserSysY.yy"
                 { yylhs.value.as < Expr* > () = CMMC_CASE(yystack_[2].location, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1124 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 44: // ExpCommaSep: Exp COMMA ExpCommaSep
#line 166 "cmmc/Frontend/ParserSysY.yy"
                                   { yylhs.value.as < Expr* > () = CMMC_COMMA_OP(yystack_[1].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, ExpCommaSep, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1130 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 45: // ExpCommaSep: Exp
#line 167 "cmmc/Frontend/ParserSysY.yy"
      { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, ExpCommaSep, yystack_[0].location); }
#line 1136 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 46: // ForOptional: Exp
#line 169 "cmmc/Frontend/ParserSysY.yy"
                 { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, ForOptional, yystack_[0].location); }
#line 1142 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 47: // ForOptional: %empty
#line 170 "cmmc/Frontend/ParserSysY.yy"
         { yylhs.value.as < Expr* > () = nullptr; CMMC_EMPTY(yylhs.location, ForOptional); }
#line 1148 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 48: // DefList: Def DefList
#line 172 "cmmc/Frontend/ParserSysY.yy"
                     { CMMC_CONCAT_PACK(yylhs.value.as < VarDefList > (), yystack_[1].value.as < VarDef > (), yystack_[0].value.as < VarDefList > ()); CMMC_NONTERMINAL(yylhs.location, DefList, yystack_[1].location, yystack_[0].location); }
#line 1154 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 49: // DefList: %empty
#line 173 "cmmc/Frontend/ParserSysY.yy"
         { yylhs.value.as < VarDefList > () = {}; CMMC_EMPTY(yylhs.location, DefList); }
#line 1160 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 50: // Def: QualifiedSpecifier DecList SEMI
#line 175 "cmmc/Frontend/ParserSysY.yy"
                                     { yylhs.value.as < VarDef > () = VarDef{castLoc(yystack_[2].location), std::move(yystack_[2].value.as < TypeRef > ()), std::move(yystack_[1].value.as < VarList > ())}; CMMC_NONTERMINAL(yylhs.location, Def, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1166 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 51: // DecList: Dec
#line 177 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < VarList > () = {yystack_[0].value.as < NamedVar > ()}; CMMC_NONTERMINAL(yylhs.location, DecList, yystack_[0].location); }
#line 1172 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 52: // DecList: Dec COMMA DecList
#line 178 "cmmc/Frontend/ParserSysY.yy"
                    { CMMC_CONCAT_PACK(yylhs.value.as < VarList > (), yystack_[2].value.as < NamedVar > (), yystack_[0].value.as < VarList > ()); CMMC_NONTERMINAL(yylhs.location, DecList, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1178 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 53: // Dec: VarDec
#line 180 "cmmc/Frontend/ParserSysY.yy"
            { yylhs.value.as < NamedVar > () = yystack_[0].value.as < NamedVar > (); CMMC_NONTERMINAL(yylhs.location, Dec, yystack_[0].location); }
#line 1184 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 54: // Dec: VarDec ASSIGN Initializer
#line 181 "cmmc/Frontend/ParserSysY.yy"
                            { yylhs.value.as < NamedVar > () = yystack_[2].value.as < NamedVar > (); yylhs.value.as < NamedVar > ().initialValue = yystack_[0].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Dec, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1190 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 55: // Initializer: Exp
#line 183 "cmmc/Frontend/ParserSysY.yy"
                 { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Initializer, yystack_[0].location); }
#line 1196 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 56: // Initializer: LC InitializerList RC
#line 184 "cmmc/Frontend/ParserSysY.yy"
                        { yylhs.value.as < Expr* > () = CMMC_ARRAY_INITIALIZER(yystack_[2].location, yystack_[1].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Initializer, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1202 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 57: // Initializer: LC RC
#line 185 "cmmc/Frontend/ParserSysY.yy"
        { yylhs.value.as < Expr* > () = CMMC_ARRAY_INITIALIZER(yystack_[1].location, ExprPack{}); CMMC_NONTERMINAL(yylhs.location, Initializer, yystack_[1].location, yystack_[0].location); }
#line 1208 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 58: // InitializerList: Initializer COMMA InitializerList
#line 187 "cmmc/Frontend/ParserSysY.yy"
                                                   { CMMC_CONCAT_PACK(yylhs.value.as < ExprPack > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, InitializerList, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1214 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 59: // InitializerList: Initializer
#line 188 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < ExprPack > () = { yystack_[0].value.as < Expr* > () }; CMMC_NONTERMINAL(yylhs.location, InitializerList, yystack_[0].location); }
#line 1220 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 60: // Exp: Exp ASSIGN Exp
#line 191 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Assign, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1226 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 61: // Exp: Exp AND Exp
#line 192 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LogicalAnd, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1232 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 62: // Exp: Exp OR Exp
#line 193 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LogicalOr, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1238 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 63: // Exp: Exp LT Exp
#line 194 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LessThan, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1244 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 64: // Exp: Exp LE Exp
#line 195 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LessEqual, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1250 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 65: // Exp: Exp GT Exp
#line 196 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, GreaterThan, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1256 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 66: // Exp: Exp GE Exp
#line 197 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, GreaterEqual, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1262 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 67: // Exp: Exp NE Exp
#line 198 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, NotEqual, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1268 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 68: // Exp: Exp EQ Exp
#line 199 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Equal, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1274 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 69: // Exp: Exp PLUS Exp
#line 200 "cmmc/Frontend/ParserSysY.yy"
               { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Add, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1280 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 70: // Exp: Exp MINUS Exp
#line 201 "cmmc/Frontend/ParserSysY.yy"
                { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Sub, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1286 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 71: // Exp: Exp MUL Exp
#line 202 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Mul, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1292 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 72: // Exp: Exp DIV Exp
#line 203 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Div, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1298 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 73: // Exp: Exp REM Exp
#line 204 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Rem, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1304 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 74: // Exp: Exp BAND Exp
#line 205 "cmmc/Frontend/ParserSysY.yy"
               { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, BitwiseAnd, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1310 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 75: // Exp: Exp BOR Exp
#line 206 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, BitwiseOr, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1316 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 76: // Exp: Exp XOR Exp
#line 207 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Xor, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1322 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 77: // Exp: Exp SHL Exp
#line 208 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, ShiftLeft, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1328 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 78: // Exp: Exp SHR Exp
#line 209 "cmmc/Frontend/ParserSysY.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, ShiftRight, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1334 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 79: // Exp: LP Exp COMMA Exp RP
#line 210 "cmmc/Frontend/ParserSysY.yy"
                      { yylhs.value.as < Expr* > () = CMMC_COMMA_OP(yystack_[2].location, yystack_[3].value.as < Expr* > (), yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1340 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 80: // Exp: LP Exp RP
#line 211 "cmmc/Frontend/ParserSysY.yy"
            { yylhs.value.as < Expr* > () = yystack_[1].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1346 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 81: // Exp: LP Specifier RP Exp
#line 212 "cmmc/Frontend/ParserSysY.yy"
                                          { yylhs.value.as < Expr* > () = CMMC_CAST_OP(yystack_[2].location, std::move(yystack_[2].value.as < TypeRef > ()), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1352 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 82: // Exp: INC Exp
#line 213 "cmmc/Frontend/ParserSysY.yy"
                           {yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[1].location, PrefixInc, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1358 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 83: // Exp: DEC Exp
#line 214 "cmmc/Frontend/ParserSysY.yy"
                           {yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[1].location, PrefixDec, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1364 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 84: // Exp: Exp INC
#line 215 "cmmc/Frontend/ParserSysY.yy"
                           {yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[0].location, SuffixInc, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1370 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 85: // Exp: Exp DEC
#line 216 "cmmc/Frontend/ParserSysY.yy"
                           {yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[0].location, SuffixDec, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1376 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 86: // Exp: BAND Exp
#line 217 "cmmc/Frontend/ParserSysY.yy"
                         {yylhs.value.as < Expr* > () = CMMC_ADDRESS_OP(yystack_[1].location, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1382 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 87: // Exp: MUL Exp
#line 218 "cmmc/Frontend/ParserSysY.yy"
                      {yylhs.value.as < Expr* > () = CMMC_DEREF_OP(yystack_[1].location, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1388 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 88: // Exp: MINUS Exp
#line 219 "cmmc/Frontend/ParserSysY.yy"
                         { yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, Neg, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1394 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 89: // Exp: PLUS Exp
#line 220 "cmmc/Frontend/ParserSysY.yy"
                       { yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, Positive, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1400 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 90: // Exp: NOT Exp
#line 221 "cmmc/Frontend/ParserSysY.yy"
          { yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, LogicalNot, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1406 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 91: // Exp: BNOT Exp
#line 222 "cmmc/Frontend/ParserSysY.yy"
           { yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, BitwiseNot, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1412 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 92: // Exp: Exp LP Args RP
#line 223 "cmmc/Frontend/ParserSysY.yy"
                 { yylhs.value.as < Expr* > () = CMMC_CALL(yystack_[2].location, yystack_[3].value.as < Expr* > (), yystack_[1].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1418 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 93: // Exp: Exp LP RP
#line 224 "cmmc/Frontend/ParserSysY.yy"
            { yylhs.value.as < Expr* > () = CMMC_CALL(yystack_[1].location, yystack_[2].value.as < Expr* > (), ExprPack{}); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1424 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 94: // Exp: Exp LB Exp RB
#line 225 "cmmc/Frontend/ParserSysY.yy"
                { yylhs.value.as < Expr* > () = CMMC_ARRAY_INDEX(yystack_[2].location, yystack_[3].value.as < Expr* > (), yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1430 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 95: // Exp: Exp DOT "Identifier"
#line 226 "cmmc/Frontend/ParserSysY.yy"
             { yylhs.value.as < Expr* > () = CMMC_STRUCT_INDEX(yystack_[0].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1436 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 96: // Exp: "Identifier"
#line 227 "cmmc/Frontend/ParserSysY.yy"
     { yylhs.value.as < Expr* > () = CMMC_ID(yystack_[0].location, yystack_[0].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1442 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 97: // Exp: "Integer"
#line 228 "cmmc/Frontend/ParserSysY.yy"
      { yylhs.value.as < Expr* > () = CMMC_INT(yystack_[0].location, yystack_[0].value.as < IntegerStorage > ().val, yystack_[0].value.as < IntegerStorage > ().width, yystack_[0].value.as < IntegerStorage > ().isSigned); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1448 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 98: // Exp: "Float"
#line 229 "cmmc/Frontend/ParserSysY.yy"
        { yylhs.value.as < Expr* > () = CMMC_FLOAT(yystack_[0].location, yystack_[0].value.as < FloatingPointStorage > ().val, yystack_[0].value.as < FloatingPointStorage > ().isFloat); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1454 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 99: // Exp: "Char"
#line 230 "cmmc/Frontend/ParserSysY.yy"
       { yylhs.value.as < Expr* > () = CMMC_CHAR(yystack_[0].location, yystack_[0].value.as < char > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1460 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 100: // Exp: "String"
#line 231 "cmmc/Frontend/ParserSysY.yy"
         { yylhs.value.as < Expr* > () = CMMC_STRING(yystack_[0].location, yystack_[0].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1466 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 101: // Exp: Exp QUEST Exp COLON Exp
#line 232 "cmmc/Frontend/ParserSysY.yy"
                                       { yylhs.value.as < Expr* > () = CMMC_SELECT(yystack_[3].location, yystack_[4].value.as < Expr* > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1472 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 102: // Exp: Exp PLUS_ASSIGN Exp
#line 233 "cmmc/Frontend/ParserSysY.yy"
                      { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Add, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1478 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 103: // Exp: Exp MINUS_ASSIGN Exp
#line 234 "cmmc/Frontend/ParserSysY.yy"
                       { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Sub, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1484 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 104: // Exp: Exp MUL_ASSIGN Exp
#line 235 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Mul, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1490 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 105: // Exp: Exp DIV_ASSIGN Exp
#line 236 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Div, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1496 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 106: // Exp: Exp REM_ASSIGN Exp
#line 237 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Rem, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1502 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 107: // Exp: Exp BAND_ASSIGN Exp
#line 238 "cmmc/Frontend/ParserSysY.yy"
                      { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, BitwiseAnd, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1508 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 108: // Exp: Exp BOR_ASSIGN Exp
#line 239 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, BitwiseOr, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1514 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 109: // Exp: Exp XOR_ASSIGN Exp
#line 240 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Xor, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1520 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 110: // Exp: Exp SHL_ASSIGN Exp
#line 241 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, ShiftLeft, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1526 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 111: // Exp: Exp SHR_ASSIGN Exp
#line 242 "cmmc/Frontend/ParserSysY.yy"
                     { yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, ShiftRight, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1532 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 112: // Args: Exp COMMA Args
#line 244 "cmmc/Frontend/ParserSysY.yy"
                     { CMMC_CONCAT_PACK(yylhs.value.as < ExprPack > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Args, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1538 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;

  case 113: // Args: Exp
#line 245 "cmmc/Frontend/ParserSysY.yy"
      { yylhs.value.as < ExprPack > () = { yystack_[0].value.as < Expr* > () }; CMMC_NONTERMINAL(yylhs.location, Args, yystack_[0].location); }
#line 1544 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"
    break;


#line 1548 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -70;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      36,   -70,    38,    -2,     8,    13,    36,    -1,   -70,   -70,
     -70,   -70,   -55,   -70,   -70,   -70,   -43,   -70,   -12,   -48,
     -25,   -14,    36,    -6,   126,   242,   -70,   200,   -70,   -70,
      41,    41,    -7,    36,   -70,    41,   -10,     4,   -70,   -70,
     -70,   -70,   -70,   332,   332,   332,   332,   332,   332,   332,
     332,   286,   115,   -70,   972,   -70,   408,     3,     1,     5,
     200,     6,    15,    17,   317,    57,     7,   332,   -70,   -70,
      35,   200,    51,   -70,   455,   -70,   -70,   -70,   -70,    45,
     -70,    36,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
      50,   361,   -70,    56,    48,   -70,   -70,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,    61,   332,   273,   332,   332,   332,
     -70,   -70,   332,   332,   104,   200,   -70,   -70,   -70,   502,
      68,   332,   549,   -70,   -70,   -70,   332,   -70,   332,   332,
     -70,   126,   -70,     9,     9,   -13,   -13,   -13,  1066,  1207,
    1019,  1113,  1160,  1272,  1272,  1272,  1272,  1254,  1254,   972,
     972,   972,   972,   972,   972,   972,   972,   972,   972,   972,
     -70,   596,   -70,   643,    55,   690,  1319,  1319,   737,   784,
      66,   332,   -70,   -70,   831,   -70,   -70,   -13,   878,   -70,
     332,   332,   -70,   -70,   200,   200,   332,    73,   972,    70,
     -70,   972,   -70,   125,   -70,   925,   332,   -70,   200,    81,
      76,   -70,   -70,   200,   -70
  };

  const signed char
  parser::yydefact_[] =
  {
       4,    11,     0,     0,     0,     0,     4,     0,     9,    12,
       6,    10,    14,     1,     2,     3,    15,     5,    53,     0,
       0,    51,    49,     0,     0,     0,     8,    26,     7,    50,
       0,     0,     0,    49,    19,    23,     0,    21,    97,    98,
      99,   100,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    55,    17,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    28,
       0,    26,     0,    36,    45,    15,    52,    13,    48,    22,
      18,     0,    82,    83,    89,    88,    87,    90,    91,    86,
       0,     0,    57,    59,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    41,     0,     0,     0,     0,    35,    34,    30,     0,
       0,     0,     0,    24,    25,    27,     0,    20,     0,     0,
      80,     0,    56,    69,    70,    71,    72,    73,    61,    74,
      62,    75,    76,    63,    65,    64,    66,    68,    67,    60,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      95,     0,    93,   113,     0,     0,    77,    78,     0,     0,
       0,    47,    29,    40,     0,    43,    44,    81,     0,    58,
       0,     0,    92,    94,     0,     0,     0,     0,    46,     0,
      79,   101,   112,    31,    33,     0,    47,    42,     0,     0,
       0,    32,    39,     0,    38
  };

  const short
  parser::yypgoto_[] =
  {
     -70,   -70,   137,   -70,    29,     2,   -70,   109,   -70,    74,
     -70,   -16,    83,   -21,    14,   -69,   128,    12,   132,   -70,
     134,    18,   -24,   -38
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,    31,     8,     9,    18,    19,    36,
      37,    69,    70,    71,    72,   207,    32,    73,    20,    21,
      93,    94,    74,   184
  };

  const unsigned char
  parser::yytable_[] =
  {
      54,    56,     1,    28,    11,    12,    16,    26,    13,    22,
      95,    96,    10,    14,     2,     3,    27,    23,    10,    82,
      83,    84,    85,    86,    87,    88,    89,    91,    54,     7,
      29,    24,    95,    96,    33,     7,    99,   100,   101,   134,
     139,   124,    30,   142,     1,    33,     1,   126,    75,   127,
      25,    80,    35,    90,    17,    34,     2,     3,    77,     3,
      81,   132,   131,   124,   140,   133,   135,   141,   180,   126,
     136,   127,   137,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     143,   181,   183,   185,   186,   187,   145,    25,   188,   189,
      35,   148,   151,   152,   191,   190,   202,   194,    38,    39,
      40,    41,    42,   193,   197,   198,   206,    54,   216,    38,
      39,    40,    41,    42,    27,   218,   222,   223,    43,    44,
      45,    46,    47,    15,    79,    48,    49,   220,    50,    43,
      44,    45,    46,    47,   144,   147,    48,    49,    53,    50,
     196,    78,    76,   212,     0,     0,     0,   208,     0,   199,
       0,     0,     0,     0,     0,    51,   211,   183,     0,    52,
      92,     0,   215,   213,   214,     0,    51,     0,     0,     0,
      52,     0,   208,   217,     0,     0,     0,   221,     0,     0,
       0,     0,   224,    38,    39,    40,    41,    57,     1,    58,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       2,     3,     0,    43,    44,    45,    46,    47,     0,     0,
      48,    49,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,    42,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
      51,     0,     0,     0,    27,    43,    44,    45,    46,    47,
       0,     0,    48,    49,     0,    50,    38,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     1,     0,    43,    44,    45,    46,
      47,     0,    51,    48,    49,    55,    50,     3,     0,    43,
      44,    45,    46,    47,     0,     0,    48,    49,     0,    50,
      38,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    51,   182,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    51,    48,    49,     0,
      50,     0,     0,     0,     0,    43,    44,    45,    46,    47,
       0,     0,    48,    49,     0,    50,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,     0,    51,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   149,     0,   125,
       0,   126,   150,   127,     0,     0,     0,     0,     0,   128,
     129,    95,    96,    97,    98,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,     0,   126,     0,
     127,   130,     0,     0,     0,     0,   128,   129,    95,    96,
      97,    98,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   146,     0,   125,     0,   126,     0,   127,     0,     0,
       0,     0,     0,   128,   129,    95,    96,    97,    98,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   192,     0,     0,
     125,     0,   126,     0,   127,     0,     0,     0,     0,     0,
     128,   129,    95,    96,    97,    98,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,   125,   195,   126,
       0,   127,     0,     0,     0,     0,     0,   128,   129,    95,
      96,    97,    98,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   125,   200,   126,     0,   127,     0,
       0,     0,     0,     0,   128,   129,    95,    96,    97,    98,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   201,
       0,   125,     0,   126,     0,   127,     0,     0,     0,     0,
       0,   128,   129,    95,    96,    97,    98,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,   125,     0,
     126,     0,   127,   203,     0,     0,     0,     0,   128,   129,
      95,    96,    97,    98,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   204,   127,
       0,     0,     0,     0,     0,   128,   129,    95,    96,    97,
      98,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   205,   127,     0,     0,     0,
       0,     0,   128,   129,    95,    96,    97,    98,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   209,   127,     0,     0,     0,     0,     0,   128,
     129,    95,    96,    97,    98,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   210,
     127,     0,     0,     0,     0,     0,   128,   129,    95,    96,
      97,    98,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   219,   127,     0,     0,
       0,     0,     0,   128,   129,    95,    96,    97,    98,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     125,     0,   126,     0,   127,     0,     0,     0,     0,     0,
     128,   129,    95,    96,    97,    98,    99,   100,   101,     0,
       0,   102,   103,     0,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,     0,   126,
       0,   127,     0,     0,     0,     0,     0,   128,   129,    95,
      96,    97,    98,    99,   100,   101,     0,     0,     0,   103,
       0,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,   126,     0,   127,     0,
       0,     0,     0,     0,   128,   129,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,   103,     0,     0,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,   126,     0,   127,     0,     0,     0,     0,
       0,   128,   129,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,   103,     0,     0,     0,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
     126,     0,   127,     0,     0,     0,     0,     0,   128,   129,
      95,    96,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,     0,   126,     0,   127,
       0,     0,     0,     0,     0,   128,   129,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,    95,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,     0,     0,   126,     0,   127,     0,     0,     0,
       0,     0,   128,   129,     0,     0,   124,     0,     0,     0,
       0,     0,   126,     0,   127,     0,     0,     0,     0,     0,
     128,   129,    95,    96,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,     0,   126,
       0,   127
  };

  const short
  parser::yycheck_[] =
  {
      24,    25,     8,    19,     2,     7,     7,    55,     0,    64,
      23,    24,     0,     0,    20,    21,    64,    60,     6,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
      55,    43,    23,    24,    22,     6,    27,    28,    29,    60,
      64,    54,    56,    67,     8,    33,     8,    60,     7,    62,
      62,    61,    23,    51,    55,    61,    20,    21,    65,    21,
      56,    60,    59,    54,     7,    60,    60,    60,     7,    60,
      55,    62,    55,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      65,   125,   126,   127,   128,   129,    55,    62,   132,   133,
      81,    61,    56,    65,   135,    11,    61,   141,     3,     4,
       5,     6,     7,    55,   148,   149,    60,   151,    55,     3,
       4,     5,     6,     7,    64,    10,    55,    61,    23,    24,
      25,    26,    27,     6,    35,    30,    31,   216,    33,    23,
      24,    25,    26,    27,    71,    81,    30,    31,    24,    33,
     146,    33,    30,   201,    -1,    -1,    -1,   191,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    60,   200,   201,    -1,    64,
      65,    -1,   206,   204,   205,    -1,    60,    -1,    -1,    -1,
      64,    -1,   216,   209,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,   223,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    64,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    -1,    33,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    23,    24,    25,    26,
      27,    -1,    60,    30,    31,    63,    33,    21,    -1,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    -1,    33,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,     3,     4,     5,     6,     7,
      23,    24,    25,    26,    27,    -1,    60,    30,    31,    -1,
      33,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    60,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    58,    -1,    60,    -1,
      62,    63,    -1,    -1,    -1,    -1,    68,    69,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    58,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    58,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      -1,    58,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62
  };

  const signed char
  parser::yystos_[] =
  {
       0,     8,    20,    21,    81,    82,    83,    84,    85,    86,
      97,    85,     7,     0,     0,    82,     7,    55,    87,    88,
      98,    99,    64,    60,    43,    62,    55,    64,    91,    55,
      56,    84,    96,    97,    61,    84,    89,    90,     3,     4,
       5,     6,     7,    23,    24,    25,    26,    27,    30,    31,
      33,    60,    64,   100,   102,    63,   102,     7,     9,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    55,    91,
      92,    93,    94,    97,   102,     7,    98,    65,    96,    87,
      61,    56,   102,   102,   102,   102,   102,   102,   102,   102,
      85,   102,    65,   100,   101,    23,    24,    25,    26,    27,
      28,    29,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    58,    60,    62,    68,    69,
      63,    59,    60,    60,    93,    60,    55,    55,    55,   102,
       7,    60,   102,    65,    92,    55,    56,    89,    61,    56,
      61,    56,    65,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
       7,   102,    61,   102,   103,   102,   102,   102,   102,   102,
      11,    93,    55,    55,   102,    59,    94,   102,   102,   101,
      59,    56,    61,    63,    61,    61,    60,    95,   102,    61,
      61,   102,   103,    93,    93,   102,    55,    91,    10,    61,
      95,    93,    55,    61,    93
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    80,    81,    82,    82,    83,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      89,    89,    90,    90,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    98,    98,    99,    99,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       2,     1,     1,     5,     2,     1,     4,     3,     4,     3,
       3,     1,     2,     1,     3,     2,     0,     2,     1,     3,
       2,     5,     7,     5,     2,     2,     1,     1,     8,     7,
       3,     2,     5,     3,     3,     1,     1,     0,     2,     0,
       3,     1,     3,     1,     3,     1,     3,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     3,     4,     3,     1,     1,     1,     1,
       1,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1
  };


#if SYSYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"End of file\"", "error", "\"invalid token\"", "\"Integer\"",
  "\"Float\"", "\"Char\"", "\"String\"", "\"Identifier\"", "\"Type\"",
  "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN",
  "GOTO", "SWITCH", "CASE", "CONST", "STRUCT", "UNION", "INC", "DEC",
  "PLUS", "MINUS", "MUL", "DIV", "REM", "NOT", "BNOT", "AND", "BAND", "OR",
  "BOR", "XOR", "LT", "GT", "LE", "GE", "EQ", "NE", "ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "BAND_ASSIGN", "BOR_ASSIGN", "XOR_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "DOT", "SEMI", "COMMA", "SHARP", "QUEST", "COLON", "LP", "RP", "LB",
  "RB", "LC", "RC", "ERR", "SELECT", "SHL", "SHR", "UPLUS", "UMINUS",
  "PREFIX_INC", "PREFIX_DEC", "DEREF", "ADDRESS", "EXPLICIT_CAST",
  "SUFFIX_INC", "SUFFIX_DEC", "THEN", "$accept", "Program", "ExtDefList",
  "ExtDef", "QualifiedSpecifier", "Specifier", "StructSpecifier", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "ExpCommaSep", "ForOptional", "DefList", "Def", "DecList", "Dec",
  "Initializer", "InitializerList", "Exp", "Args", YY_NULLPTR
  };
#endif


#if SYSYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   110,   110,   112,   113,   115,   116,   117,   118,   121,
     122,   123,   124,   126,   127,   130,   131,   132,   134,   135,
     137,   138,   140,   141,   144,   145,   146,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   166,   167,   169,   170,   172,   173,
     175,   177,   178,   180,   181,   183,   184,   185,   187,   188,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   244,   245
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // SYSYDEBUG


} // SysY
#line 2400 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserImpl.hpp"

#line 247 "cmmc/Frontend/ParserSysY.yy"

void SysY::parser::error(const location_type& l, const std::string& m) {
    reportError() << l << ": "sv << m << '\n';
}
