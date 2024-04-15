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
#define yylex   Spllex



#include "ParserDecl.hpp"


// Unqualified %code blocks.
#line 32 "cmmc/Frontend/ParserSpl.yy"



#line 52 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"


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
#if SPLDEBUG

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

#else // !SPLDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !SPLDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace Spl {
#line 144 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"

  /// Build a parser object.
  parser::parser (cmmc::DriverImpl& driver_yyarg)
#if SPLDEBUG
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
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Exp: // Exp
        value.YY_MOVE_OR_COPY< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Args: // Args
        value.YY_MOVE_OR_COPY< ExprPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.YY_MOVE_OR_COPY< FunctionDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.YY_MOVE_OR_COPY< NamedArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.YY_MOVE_OR_COPY< NamedVar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_String: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.YY_MOVE_OR_COPY< String > (YY_MOVE (that.value));
        break;

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

      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_DecList: // DecList
        value.YY_MOVE_OR_COPY< VarList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.YY_MOVE_OR_COPY< uintmax_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Exp: // Exp
        value.move< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Args: // Args
        value.move< ExprPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.move< FunctionDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.move< NamedArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.move< NamedVar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_String: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.move< String > (YY_MOVE (that.value));
        break;

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

      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_DecList: // DecList
        value.move< VarList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.move< uintmax_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Exp: // Exp
        value.copy< Expr* > (that.value);
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Args: // Args
        value.copy< ExprPack > (that.value);
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.copy< FunctionDeclaration > (that.value);
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.copy< NamedArg > (that.value);
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.copy< NamedVar > (that.value);
        break;

      case symbol_kind::S_String: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.copy< String > (that.value);
        break;

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

      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_DecList: // DecList
        value.copy< VarList > (that.value);
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // "Integer"
        value.copy< uintmax_t > (that.value);
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
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Exp: // Exp
        value.move< Expr* > (that.value);
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Args: // Args
        value.move< ExprPack > (that.value);
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.move< FunctionDeclaration > (that.value);
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.move< NamedArg > (that.value);
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.move< NamedVar > (that.value);
        break;

      case symbol_kind::S_String: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.move< String > (that.value);
        break;

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

      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_DecList: // DecList
        value.move< VarList > (that.value);
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // "Integer"
        value.move< uintmax_t > (that.value);
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

#if SPLDEBUG
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

#if SPLDEBUG
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
#endif // SPLDEBUG

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
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Exp: // Exp
        yylhs.value.emplace< Expr* > ();
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Args: // Args
        yylhs.value.emplace< ExprPack > ();
        break;

      case symbol_kind::S_FunDec: // FunDec
        yylhs.value.emplace< FunctionDeclaration > ();
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        yylhs.value.emplace< NamedArg > ();
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        yylhs.value.emplace< NamedVar > ();
        break;

      case symbol_kind::S_String: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        yylhs.value.emplace< String > ();
        break;

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

      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_DecList: // DecList
        yylhs.value.emplace< VarList > ();
        break;

      case symbol_kind::S_CHAR: // "Char"
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLOAT: // "Float"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // "Integer"
        yylhs.value.emplace< uintmax_t > ();
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
#line 108 "cmmc/Frontend/ParserSpl.yy"
                        { driver.markEnd(); CMMC_NONTERMINAL(yylhs.location, Program, yystack_[1].location); }
#line 863 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 3: // ExtDefList: ExtDef ExtDefList
#line 110 "cmmc/Frontend/ParserSpl.yy"
                              { CMMC_NONTERMINAL(yylhs.location, ExtDefList, yystack_[1].location, yystack_[0].location); }
#line 869 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 4: // ExtDefList: %empty
#line 111 "cmmc/Frontend/ParserSpl.yy"
         { CMMC_EMPTY(yylhs.location, ExtDefList); }
#line 875 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 5: // ExtDef: Specifier ExtDecList SEMI
#line 113 "cmmc/Frontend/ParserSpl.yy"
                                  { driver.addGlobalDef(yystack_[2].value.as < TypeRef > (), yystack_[1].value.as < VarList > ()); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 881 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 6: // ExtDef: Specifier SEMI
#line 114 "cmmc/Frontend/ParserSpl.yy"
                 { driver.addOpaqueType(yystack_[1].value.as < TypeRef > ()); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[1].location, yystack_[0].location); }
#line 887 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 7: // ExtDef: Specifier FunDec CompSt
#line 115 "cmmc/Frontend/ParserSpl.yy"
                          { yystack_[1].value.as < FunctionDeclaration > ().retType = yystack_[2].value.as < TypeRef > (); driver.addFunctionDef({yystack_[1].value.as < FunctionDeclaration > (), yystack_[0].value.as < ExprPack > ()}); CMMC_NONTERMINAL(yylhs.location, ExtDef, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 893 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 8: // ExtDef: Specifier ExtDecList error
#line 116 "cmmc/Frontend/ParserSpl.yy"
                             { CMMC_MISS_SEMI(yystack_[0].location); }
#line 899 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 9: // ExtDef: Specifier error
#line 117 "cmmc/Frontend/ParserSpl.yy"
                  { CMMC_MISS_SEMI(yystack_[0].location); }
#line 905 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 10: // ExtDef: error ExtDecList SEMI
#line 118 "cmmc/Frontend/ParserSpl.yy"
                        { CMMC_MISS_SPECIFIER(yystack_[1].location); }
#line 911 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 11: // ExtDef: error SEMI
#line 119 "cmmc/Frontend/ParserSpl.yy"
             { CMMC_MISS_SPECIFIER(yystack_[0].location); }
#line 917 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 12: // ExtDecList: VarDec
#line 121 "cmmc/Frontend/ParserSpl.yy"
                   { yylhs.value.as < VarList > () = { yystack_[0].value.as < NamedVar > () }; CMMC_NONTERMINAL(yylhs.location, ExtDecList, yystack_[0].location); }
#line 923 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 13: // ExtDecList: VarDec COMMA ExtDecList
#line 122 "cmmc/Frontend/ParserSpl.yy"
                          { CMMC_CONCAT_PACK(yylhs.value.as < VarList > (), yystack_[2].value.as < NamedVar > (), yystack_[0].value.as < VarList > ()); CMMC_NONTERMINAL(yylhs.location, ExtDecList, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 929 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 14: // Specifier: "Type"
#line 125 "cmmc/Frontend/ParserSpl.yy"
                { yylhs.value.as < TypeRef > () = { yystack_[0].value.as < String > (), TypeLookupSpace::Default, Qualifier{false, true} }; CMMC_NONTERMINAL(yylhs.location, Specifier, yystack_[0].location); }
#line 935 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 15: // Specifier: StructSpecifier
#line 126 "cmmc/Frontend/ParserSpl.yy"
                  { yylhs.value.as < TypeRef > () = yystack_[0].value.as < TypeRef > (); CMMC_NONTERMINAL(yylhs.location, Specifier, yystack_[0].location); }
#line 941 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 16: // StructSpecifier: STRUCT "Identifier" LC DefList RC
#line 128 "cmmc/Frontend/ParserSpl.yy"
                                         { yylhs.value.as < TypeRef > () = { yystack_[3].value.as < String > (), TypeLookupSpace::Struct, Qualifier::getDefault() }; driver.addStructType(castLoc(yystack_[4].location), yystack_[3].value.as < String > (), yystack_[1].value.as < VarDefList > ()); CMMC_NONTERMINAL(yylhs.location, StructSpecifier, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 947 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 17: // StructSpecifier: STRUCT "Identifier"
#line 129 "cmmc/Frontend/ParserSpl.yy"
            { yylhs.value.as < TypeRef > () = { yystack_[0].value.as < String > (), TypeLookupSpace::Struct, Qualifier::getDefault() }; CMMC_NONTERMINAL(yylhs.location, StructSpecifier, yystack_[1].location, yystack_[0].location); }
#line 953 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 18: // StructSpecifier: STRUCT "Identifier" LC DefList error
#line 130 "cmmc/Frontend/ParserSpl.yy"
                                            { CMMC_MISS_RC(yylhs.location); }
#line 959 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 19: // StructSpecifier: STRUCT "Type" error
#line 131 "cmmc/Frontend/ParserSpl.yy"
                    { CMMC_BAD_STRUCT(yylhs.location); }
#line 965 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 20: // VarDec: "Identifier"
#line 134 "cmmc/Frontend/ParserSpl.yy"
           { yylhs.value.as < NamedVar > () = { castLoc(yystack_[0].location), yystack_[0].value.as < String > (), ArraySize{}, nullptr }; CMMC_NONTERMINAL(yylhs.location, VarDec, yystack_[0].location); }
#line 971 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 21: // VarDec: VarDec LB "Integer" RB
#line 135 "cmmc/Frontend/ParserSpl.yy"
                   { yylhs.value.as < NamedVar > () = yystack_[3].value.as < NamedVar > (); yylhs.value.as < NamedVar > ().arraySize.push_back(CMMC_INT(yystack_[1].location, yystack_[1].value.as < uintmax_t > (), 32U, true)); CMMC_NONTERMINAL(yylhs.location, VarDec, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 977 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 22: // VarDec: VarDec LB "Integer" error
#line 136 "cmmc/Frontend/ParserSpl.yy"
                                     { CMMC_MISS_RB(yylhs.location); }
#line 983 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 23: // VarDec: ERR
#line 137 "cmmc/Frontend/ParserSpl.yy"
      {}
#line 989 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 24: // FunDec: "Identifier" LP VarList RP
#line 139 "cmmc/Frontend/ParserSpl.yy"
                         { yylhs.value.as < FunctionDeclaration > ().loc = castLoc(yystack_[3].location); yylhs.value.as < FunctionDeclaration > ().symbol = yystack_[3].value.as < String > (); yylhs.value.as < FunctionDeclaration > ().args = yystack_[1].value.as < ArgList > (); CMMC_NONTERMINAL(yylhs.location, FunDec, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 995 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 25: // FunDec: "Identifier" LP RP
#line 140 "cmmc/Frontend/ParserSpl.yy"
           { yylhs.value.as < FunctionDeclaration > ().loc = castLoc(yystack_[2].location); yylhs.value.as < FunctionDeclaration > ().symbol = yystack_[2].value.as < String > (); CMMC_NONTERMINAL(yylhs.location, FunDec, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1001 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 26: // FunDec: "Identifier" LP VarList error
#line 141 "cmmc/Frontend/ParserSpl.yy"
                                     { CMMC_MISS_RP(yylhs.location); }
#line 1007 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 27: // FunDec: "Identifier" LP error
#line 142 "cmmc/Frontend/ParserSpl.yy"
                             { CMMC_MISS_RP(yylhs.location); }
#line 1013 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 28: // VarList: ParamDec COMMA VarList
#line 144 "cmmc/Frontend/ParserSpl.yy"
                                { CMMC_CONCAT_PACK(yylhs.value.as < ArgList > (), yystack_[2].value.as < NamedArg > (), yystack_[0].value.as < ArgList > ()); CMMC_NONTERMINAL(yylhs.location, VarList, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1019 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 29: // VarList: ParamDec
#line 145 "cmmc/Frontend/ParserSpl.yy"
           { yylhs.value.as < ArgList > () = { yystack_[0].value.as < NamedArg > () }; CMMC_NONTERMINAL(yylhs.location, VarList, yystack_[0].location); }
#line 1025 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 30: // ParamDec: Specifier VarDec
#line 147 "cmmc/Frontend/ParserSpl.yy"
                           { yylhs.value.as < NamedArg > () = NamedArg{ yystack_[1].value.as < TypeRef > (), yystack_[0].value.as < NamedVar > () }; CMMC_NONTERMINAL(yylhs.location, ParamDec, yystack_[1].location, yystack_[0].location); }
#line 1031 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 31: // CompSt: LC DefList StmtList RC
#line 150 "cmmc/Frontend/ParserSpl.yy"
                               { CMMC_SCOPE_GEN(yylhs.value.as < ExprPack > (), yystack_[2].value.as < VarDefList > (), yystack_[1].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, CompSt, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1037 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 32: // StmtList: Stmt StmtList
#line 152 "cmmc/Frontend/ParserSpl.yy"
                        { CMMC_CONCAT_PACK(yylhs.value.as < ExprPack > (), yystack_[1].value.as < Expr* > (), yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, StmtList, yystack_[1].location, yystack_[0].location); }
#line 1043 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 33: // StmtList: %empty
#line 153 "cmmc/Frontend/ParserSpl.yy"
         { yylhs.value.as < ExprPack > () = {}; CMMC_EMPTY(yylhs.location, StmtList);}
#line 1049 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 34: // Stmt: Exp SEMI
#line 155 "cmmc/Frontend/ParserSpl.yy"
               { yylhs.value.as < Expr* > () = yystack_[1].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1055 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 35: // Stmt: CompSt
#line 156 "cmmc/Frontend/ParserSpl.yy"
         { yylhs.value.as < Expr* > () = CMMC_SCOPE(yystack_[0].location, yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[0].location); }
#line 1061 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 36: // Stmt: RETURN Exp SEMI
#line 157 "cmmc/Frontend/ParserSpl.yy"
                  { yylhs.value.as < Expr* > () = CMMC_RETURN(yystack_[2].location, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1067 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 37: // Stmt: RETURN SEMI
#line 158 "cmmc/Frontend/ParserSpl.yy"
              { yylhs.value.as < Expr* > () = CMMC_RETURN(yystack_[1].location, nullptr); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1073 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 38: // Stmt: IF LP Exp RP Stmt
#line 159 "cmmc/Frontend/ParserSpl.yy"
                               { yylhs.value.as < Expr* > () = CMMC_IF(yystack_[4].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1079 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 39: // Stmt: IF LP Exp RP Stmt ELSE Stmt
#line 160 "cmmc/Frontend/ParserSpl.yy"
                              { yylhs.value.as < Expr* > () = CMMC_IF_ELSE(yystack_[6].location, yystack_[4].value.as < Expr* > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[6].location, yystack_[5].location, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1085 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 40: // Stmt: WHILE LP Exp RP Stmt
#line 161 "cmmc/Frontend/ParserSpl.yy"
                       { yylhs.value.as < Expr* > () = CMMC_WHILE(yystack_[4].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1091 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 41: // Stmt: DO Stmt WHILE LP Exp RP SEMI
#line 162 "cmmc/Frontend/ParserSpl.yy"
                               { CMMC_NEED_EXTENSION(yylhs.location, DoWhile); yylhs.value.as < Expr* > () = CMMC_DO_WHILE(yystack_[6].location, yystack_[5].value.as < Expr* > (), yystack_[2].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[6].location, yystack_[5].location, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1097 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 42: // Stmt: BREAK SEMI
#line 163 "cmmc/Frontend/ParserSpl.yy"
             { CMMC_NEED_EXTENSION(yylhs.location, Break); yylhs.value.as < Expr* > () = CMMC_BREAK(yystack_[1].location); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1103 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 43: // Stmt: CONTINUE SEMI
#line 164 "cmmc/Frontend/ParserSpl.yy"
                { CMMC_NEED_EXTENSION(yylhs.location, Continue); yylhs.value.as < Expr* > () = CMMC_CONTINUE(yystack_[1].location); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[1].location, yystack_[0].location); }
#line 1109 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 44: // Stmt: FOR LP Stmt ForOptional SEMI ForOptional RP Stmt
#line 165 "cmmc/Frontend/ParserSpl.yy"
                                                   { CMMC_NEED_EXTENSION(yylhs.location, ForLoop); yylhs.value.as < Expr* > () = CMMC_FOR_LOOP(yystack_[7].location, yystack_[5].value.as < Expr* > (), yystack_[4].value.as < Expr* > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[7].location, yystack_[6].location, yystack_[5].location, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1115 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 45: // Stmt: Exp error
#line 166 "cmmc/Frontend/ParserSpl.yy"
                           { CMMC_MISS_SEMI(yylhs.location); }
#line 1121 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 46: // Stmt: RETURN Exp error
#line 167 "cmmc/Frontend/ParserSpl.yy"
                                  { CMMC_MISS_SEMI(yylhs.location); }
#line 1127 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 47: // Stmt: RETURN error
#line 168 "cmmc/Frontend/ParserSpl.yy"
                              { CMMC_MISS_SEMI(yylhs.location); }
#line 1133 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 48: // Stmt: IF LP Exp error Stmt
#line 169 "cmmc/Frontend/ParserSpl.yy"
                                      { CMMC_MISS_RP(yylhs.location); }
#line 1139 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 49: // Stmt: IF LP Exp error Stmt ELSE Stmt
#line 170 "cmmc/Frontend/ParserSpl.yy"
                                                { CMMC_MISS_RP(yylhs.location); }
#line 1145 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 50: // Stmt: WHILE LP Exp error Stmt
#line 171 "cmmc/Frontend/ParserSpl.yy"
                                         { CMMC_MISS_RP(yylhs.location); }
#line 1151 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 51: // Stmt: SEMI
#line 172 "cmmc/Frontend/ParserSpl.yy"
       { CMMC_NEED_EXTENSION(yylhs.location, EmptyStmt); yylhs.value.as < Expr* > () = CMMC_EMPTY_STMT(yystack_[0].location); CMMC_NONTERMINAL(yylhs.location, Stmt, yystack_[0].location); }
#line 1157 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 52: // ForOptional: Exp
#line 174 "cmmc/Frontend/ParserSpl.yy"
                 { yylhs.value.as < Expr* > () = yystack_[0].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, ForOptional, yystack_[0].location); }
#line 1163 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 53: // ForOptional: %empty
#line 175 "cmmc/Frontend/ParserSpl.yy"
         { yylhs.value.as < Expr* > () = nullptr; CMMC_EMPTY(yylhs.location, ForOptional); }
#line 1169 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 54: // DefList: Def DefList
#line 178 "cmmc/Frontend/ParserSpl.yy"
                                  { CMMC_CONCAT_PACK(yylhs.value.as < VarDefList > (), yystack_[1].value.as < VarDef > (), yystack_[0].value.as < VarDefList > ()); CMMC_NONTERMINAL(yylhs.location, DefList, yystack_[1].location, yystack_[0].location); }
#line 1175 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 55: // DefList: DefList error DecList SEMI
#line 179 "cmmc/Frontend/ParserSpl.yy"
                                            { CMMC_MISS_SPECIFIER(yystack_[2].location); }
#line 1181 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 56: // DefList: %empty
#line 180 "cmmc/Frontend/ParserSpl.yy"
         { yylhs.value.as < VarDefList > () = {}; CMMC_EMPTY(yylhs.location, DefList); }
#line 1187 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 57: // Def: Specifier DecList SEMI
#line 182 "cmmc/Frontend/ParserSpl.yy"
                            { yylhs.value.as < VarDef > () = VarDef{castLoc(yystack_[2].location), std::move(yystack_[2].value.as < TypeRef > ()), std::move(yystack_[1].value.as < VarList > ())}; CMMC_NONTERMINAL(yylhs.location, Def, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1193 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 58: // Def: Specifier DecList error
#line 183 "cmmc/Frontend/ParserSpl.yy"
                                         { CMMC_MISS_SEMI(yylhs.location); }
#line 1199 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 59: // DecList: Dec
#line 185 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < VarList > () = {yystack_[0].value.as < NamedVar > ()}; CMMC_NONTERMINAL(yylhs.location, DecList, yystack_[0].location); }
#line 1205 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 60: // DecList: Dec COMMA DecList
#line 186 "cmmc/Frontend/ParserSpl.yy"
                    { CMMC_CONCAT_PACK(yylhs.value.as < VarList > (), yystack_[2].value.as < NamedVar > (), yystack_[0].value.as < VarList > ()); CMMC_NONTERMINAL(yylhs.location, DecList, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1211 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 61: // Dec: VarDec
#line 188 "cmmc/Frontend/ParserSpl.yy"
            { yylhs.value.as < NamedVar > () = yystack_[0].value.as < NamedVar > (); CMMC_NONTERMINAL(yylhs.location, Dec, yystack_[0].location); }
#line 1217 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 62: // Dec: VarDec ASSIGN Exp
#line 189 "cmmc/Frontend/ParserSpl.yy"
                    { yylhs.value.as < NamedVar > () = yystack_[2].value.as < NamedVar > (); yylhs.value.as < NamedVar > ().initialValue = yystack_[0].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Dec, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1223 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 63: // Exp: Exp ASSIGN Exp
#line 192 "cmmc/Frontend/ParserSpl.yy"
                     { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Assign, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1229 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 64: // Exp: Exp PLUS_ASSIGN Exp
#line 193 "cmmc/Frontend/ParserSpl.yy"
                      { CMMC_NEED_EXTENSION(yylhs.location, CompoundAssign); yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Add, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1235 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 65: // Exp: Exp MINUS_ASSIGN Exp
#line 194 "cmmc/Frontend/ParserSpl.yy"
                       { CMMC_NEED_EXTENSION(yylhs.location, CompoundAssign); yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Sub, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1241 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 66: // Exp: Exp MUL_ASSIGN Exp
#line 195 "cmmc/Frontend/ParserSpl.yy"
                     { CMMC_NEED_EXTENSION(yylhs.location, CompoundAssign); yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Mul, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1247 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 67: // Exp: Exp DIV_ASSIGN Exp
#line 196 "cmmc/Frontend/ParserSpl.yy"
                     { CMMC_NEED_EXTENSION(yylhs.location, CompoundAssign); yylhs.value.as < Expr* > () = CMMC_COMPOUND_ASSIGN_OP(yystack_[1].location, Div, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1253 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 68: // Exp: INC Exp
#line 197 "cmmc/Frontend/ParserSpl.yy"
                           { CMMC_NEED_EXTENSION(yylhs.location, IncDec); yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[1].location, PrefixInc, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1259 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 69: // Exp: DEC Exp
#line 198 "cmmc/Frontend/ParserSpl.yy"
                           { CMMC_NEED_EXTENSION(yylhs.location, IncDec); yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[1].location, PrefixDec, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1265 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 70: // Exp: Exp INC
#line 199 "cmmc/Frontend/ParserSpl.yy"
                           { CMMC_NEED_EXTENSION(yylhs.location, IncDec); yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[0].location, SuffixInc, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1271 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 71: // Exp: Exp DEC
#line 200 "cmmc/Frontend/ParserSpl.yy"
                           { CMMC_NEED_EXTENSION(yylhs.location, IncDec); yylhs.value.as < Expr* > () = CMMC_SELF_INCDEC_OP(yystack_[0].location, SuffixDec, yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location);}
#line 1277 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 72: // Exp: Exp QUEST Exp COLON Exp
#line 201 "cmmc/Frontend/ParserSpl.yy"
                                       { CMMC_NEED_EXTENSION(yylhs.location, Select); yylhs.value.as < Expr* > () = CMMC_SELECT(yystack_[3].location, yystack_[4].value.as < Expr* > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[4].location, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1283 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 73: // Exp: Exp AND Exp
#line 202 "cmmc/Frontend/ParserSpl.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LogicalAnd, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1289 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 74: // Exp: Exp OR Exp
#line 203 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LogicalOr, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1295 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 75: // Exp: Exp LT Exp
#line 204 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LessThan, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1301 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 76: // Exp: Exp LE Exp
#line 205 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, LessEqual, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1307 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 77: // Exp: Exp GT Exp
#line 206 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, GreaterThan, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1313 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 78: // Exp: Exp GE Exp
#line 207 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, GreaterEqual, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1319 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 79: // Exp: Exp NE Exp
#line 208 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, NotEqual, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1325 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 80: // Exp: Exp EQ Exp
#line 209 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Equal, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1331 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 81: // Exp: Exp PLUS Exp
#line 210 "cmmc/Frontend/ParserSpl.yy"
               { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Add, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1337 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 82: // Exp: Exp MINUS Exp
#line 211 "cmmc/Frontend/ParserSpl.yy"
                { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Sub, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1343 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 83: // Exp: Exp MUL Exp
#line 212 "cmmc/Frontend/ParserSpl.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Mul, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1349 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 84: // Exp: Exp DIV Exp
#line 213 "cmmc/Frontend/ParserSpl.yy"
              { yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Div, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1355 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 85: // Exp: Exp REM Exp
#line 214 "cmmc/Frontend/ParserSpl.yy"
              { CMMC_NEED_EXTENSION(yylhs.location, Remainder); yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Rem, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1361 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 86: // Exp: Exp BAND Exp
#line 215 "cmmc/Frontend/ParserSpl.yy"
               { CMMC_NEED_EXTENSION(yylhs.location, BitwiseAnd); yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, BitwiseAnd, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1367 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 87: // Exp: Exp BOR Exp
#line 216 "cmmc/Frontend/ParserSpl.yy"
              { CMMC_NEED_EXTENSION(yylhs.location, BitwiseOr); yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, BitwiseOr, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1373 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 88: // Exp: Exp XOR Exp
#line 217 "cmmc/Frontend/ParserSpl.yy"
              { CMMC_NEED_EXTENSION(yylhs.location, Xor); yylhs.value.as < Expr* > () = CMMC_BINARY_OP(yystack_[1].location, Xor, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1379 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 89: // Exp: LP Exp RP
#line 218 "cmmc/Frontend/ParserSpl.yy"
            { yylhs.value.as < Expr* > () = yystack_[1].value.as < Expr* > (); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1385 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 90: // Exp: MINUS Exp
#line 219 "cmmc/Frontend/ParserSpl.yy"
                         { yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, Neg, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1391 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 91: // Exp: NOT Exp
#line 220 "cmmc/Frontend/ParserSpl.yy"
          { yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, LogicalNot, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1397 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 92: // Exp: BNOT Exp
#line 221 "cmmc/Frontend/ParserSpl.yy"
           { CMMC_NEED_EXTENSION(yylhs.location, BitwiseNot); yylhs.value.as < Expr* > () = CMMC_UNARY_OP(yystack_[1].location, BitwiseNot, yystack_[0].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[1].location, yystack_[0].location); }
#line 1403 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 93: // Exp: "Identifier" LP Args RP
#line 222 "cmmc/Frontend/ParserSpl.yy"
                { yylhs.value.as < Expr* > () = CMMC_CALL(yystack_[2].location, CMMC_FUNC_ID(yystack_[3].location, yystack_[3].value.as < String > ()), yystack_[1].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1409 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 94: // Exp: "Identifier" LP RP
#line 223 "cmmc/Frontend/ParserSpl.yy"
           { yylhs.value.as < Expr* > () = CMMC_CALL(yystack_[1].location, CMMC_FUNC_ID(yystack_[2].location, yystack_[2].value.as < String > ()), ExprPack{}); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1415 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 95: // Exp: Exp LB Exp RB
#line 224 "cmmc/Frontend/ParserSpl.yy"
                { yylhs.value.as < Expr* > () = CMMC_ARRAY_INDEX(yystack_[2].location, yystack_[3].value.as < Expr* > (), yystack_[1].value.as < Expr* > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[3].location, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1421 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 96: // Exp: Exp DOT "Identifier"
#line 225 "cmmc/Frontend/ParserSpl.yy"
             { yylhs.value.as < Expr* > () = CMMC_STRUCT_INDEX(yystack_[0].location, yystack_[2].value.as < Expr* > (), yystack_[0].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1427 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 97: // Exp: "Identifier"
#line 226 "cmmc/Frontend/ParserSpl.yy"
     { yylhs.value.as < Expr* > () = CMMC_ID(yystack_[0].location, yystack_[0].value.as < String > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1433 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 98: // Exp: "Integer"
#line 227 "cmmc/Frontend/ParserSpl.yy"
      { yylhs.value.as < Expr* > () = CMMC_INT(yystack_[0].location, yystack_[0].value.as < uintmax_t > (), 32U, true); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1439 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 99: // Exp: "Float"
#line 228 "cmmc/Frontend/ParserSpl.yy"
        { yylhs.value.as < Expr* > () = CMMC_FLOAT(yystack_[0].location, yystack_[0].value.as < double > (), true); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1445 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 100: // Exp: "Char"
#line 229 "cmmc/Frontend/ParserSpl.yy"
       { yylhs.value.as < Expr* > () = CMMC_CHAR(yystack_[0].location, yystack_[0].value.as < char > ()); CMMC_NONTERMINAL(yylhs.location, Exp, yystack_[0].location); }
#line 1451 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 101: // Exp: LP Exp error
#line 230 "cmmc/Frontend/ParserSpl.yy"
               { CMMC_MISS_RP(yylhs.location); }
#line 1457 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 102: // Exp: "Identifier" LP Args error
#line 231 "cmmc/Frontend/ParserSpl.yy"
                   { CMMC_MISS_RP(yylhs.location); }
#line 1463 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 103: // Exp: "Identifier" LP error
#line 232 "cmmc/Frontend/ParserSpl.yy"
              { CMMC_MISS_RP(yylhs.location); }
#line 1469 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 104: // Exp: Exp LB Exp error
#line 233 "cmmc/Frontend/ParserSpl.yy"
                   { CMMC_MISS_RB(yylhs.location); }
#line 1475 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 105: // Exp: Exp ERR Exp error
#line 234 "cmmc/Frontend/ParserSpl.yy"
                    {}
#line 1481 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 106: // Exp: ERR error
#line 235 "cmmc/Frontend/ParserSpl.yy"
            {}
#line 1487 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 107: // Args: Exp COMMA Args
#line 237 "cmmc/Frontend/ParserSpl.yy"
                     { CMMC_CONCAT_PACK(yylhs.value.as < ExprPack > (), yystack_[2].value.as < Expr* > (), yystack_[0].value.as < ExprPack > ()); CMMC_NONTERMINAL(yylhs.location, Args, yystack_[2].location, yystack_[1].location, yystack_[0].location); }
#line 1493 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;

  case 108: // Args: Exp
#line 238 "cmmc/Frontend/ParserSpl.yy"
      { yylhs.value.as < ExprPack > () = { yystack_[0].value.as < Expr* > () }; CMMC_NONTERMINAL(yylhs.location, Args, yystack_[0].location); }
#line 1499 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"
    break;


#line 1503 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"

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


  const signed char parser::yypact_ninf_ = -65;

  const signed char parser::yytable_ninf_ = -55;

  const short
  parser::yypact_[] =
  {
     176,    30,   -65,    -4,     1,    35,   176,    27,   -65,   -65,
     -65,   -65,    -8,   -19,   -15,    42,   -65,   -65,   -65,   -65,
      -9,   -65,    37,    34,   -65,    25,    89,     9,   -65,    13,
     -65,   -65,     9,   -65,   -65,    18,    25,    10,     9,   -65,
     -65,    25,    19,    46,   452,   -65,   -65,   -40,    40,    51,
      95,   -65,   511,    49,   -65,   -65,     9,    25,   -65,   -65,
     -65,    54,    55,    56,   582,    57,    63,    65,    76,   615,
     615,   615,   615,   615,   -65,   615,   122,   -65,    67,   582,
     119,   615,   -65,   -65,    25,    79,   -65,   549,   615,   615,
     117,   582,   -65,   -65,   -65,   -65,   167,    71,    71,    71,
      71,    71,   215,   -65,   -65,   -65,   -65,   -65,   -65,   615,
     615,   615,   615,   615,   615,   615,   615,   615,   615,   615,
     615,   615,   615,   615,   615,   615,   615,   615,   615,   615,
     124,   -65,   615,   615,   615,   767,   -65,   -65,   -65,   -65,
     653,    22,   262,   309,    83,   615,   -65,   -65,   -65,   -65,
     554,   554,    71,    71,    71,   831,   909,   805,   857,   883,
     601,   601,   601,   601,   935,   935,   767,   767,   767,   767,
     767,   -65,   691,   356,   403,   615,   -65,   -65,   582,   582,
     582,   582,   615,    90,   767,   615,   -65,   -65,   -65,   -65,
     129,   138,   -65,   -65,   729,   615,   767,   582,   582,   101,
     115,   -65,   -65,   -65,   582,   -65
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,    14,     0,     0,     0,     0,     0,    15,    20,
      11,    23,     0,    12,    17,     0,     1,     2,     3,     9,
      20,     6,     0,     0,    10,     0,     0,    56,    19,     0,
       8,     5,    56,     7,    13,     0,     0,     0,    56,    27,
      25,     0,     0,    29,     0,    22,    21,    61,     0,    59,
      18,    16,     0,    30,    26,    24,     0,     0,    98,    99,
     100,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    35,     0,    33,
       0,     0,    58,    57,     0,     0,    28,     0,     0,     0,
       0,     0,    43,    42,    47,    37,     0,    68,    69,    90,
      91,    92,     0,   106,    31,    32,    45,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,    62,    60,    55,   103,    94,
     108,     0,     0,     0,     0,    53,    46,    36,   101,    89,
      81,    82,    83,    84,    85,    73,    86,    74,    87,    88,
      75,    77,    76,    78,    80,    79,    63,    64,    65,    66,
      67,    96,     0,     0,     0,     0,   102,    93,     0,     0,
       0,     0,     0,     0,    52,     0,   104,    95,   105,   107,
      48,    38,    50,    40,     0,    53,    72,     0,     0,     0,
       0,    49,    39,    41,     0,    44
  };

  const short
  parser::yypgoto_[] =
  {
     -65,   -65,   165,   -65,     6,    16,   -65,    96,   -65,   116,
     -65,   150,   100,   -64,   -20,    58,   -65,     3,   -65,   -63,
       5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,    12,    36,     8,    47,    23,    42,
      43,    77,    78,    79,   183,    37,    38,    85,    49,    80,
     141
  };

  const short
  parser::yytable_[] =
  {
      90,    16,    81,    14,    15,    96,    97,    98,    99,   100,
     101,    50,   102,    22,    39,    26,     7,     2,   135,    45,
      54,     2,     7,   176,   140,   142,   143,   145,    19,     3,
      25,    34,     9,     3,    20,    17,    26,     9,    30,    48,
      24,    82,    27,    28,    29,    41,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    40,    51,   172,
     173,   174,    41,    55,    46,    21,   177,    94,    10,    58,
      59,    60,   184,    61,    11,    31,    11,   136,    83,    11,
      44,    32,    35,   107,   108,    56,    52,    13,    69,    70,
      84,    71,     9,    13,    26,    72,    73,    87,    88,    89,
      91,    92,   140,    93,   190,   191,   192,   193,   130,   194,
     106,    13,   196,   103,    95,   104,   133,   137,   144,    75,
     134,   171,   184,   201,   202,    76,   182,    53,   195,   197,
     205,   107,   108,   109,   110,   111,   112,   113,   198,   203,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   146,   204,
     132,    18,    86,    33,   133,   200,    -4,     1,   134,   105,
     189,     0,     0,     0,     2,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     3,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   147,   148,     0,   132,     0,
       0,     0,   133,     0,     0,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   178,     0,     0,   132,     0,     0,   149,
     133,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     180,     0,     0,   132,     0,     0,   179,   133,     0,     0,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   186,     0,     0,
     132,     0,     0,   181,   133,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   188,     0,     0,   132,     0,     0,
       0,   133,   187,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,    57,   132,    58,    59,    60,   133,    61,
       0,    62,   134,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,    75,     0,     0,     0,    32,
     -33,    76,    57,     0,   -54,   -54,   -54,     0,   -54,     0,
     -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,     0,     0,   -54,   -54,     0,   -54,     0,     0,     0,
     -54,   -54,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,    58,    59,    60,     0,    61,     0,     0,   -54,
       0,     0,     0,     0,   -54,     0,     0,     0,   -54,   -54,
     -54,    69,    70,     0,    71,     0,   107,   108,    72,    73,
     111,   112,   113,     0,     0,    58,    59,    60,     0,    61,
       0,    62,     0,    63,    64,    65,    66,    67,    68,     0,
       0,   130,    75,   139,    69,    70,     0,    71,    76,   133,
       0,    72,    73,   134,     0,     0,     0,     0,    58,    59,
      60,     0,    61,   107,   108,   109,   110,   111,   112,   113,
      74,     0,     0,     0,     0,    75,     0,    69,    70,    32,
      71,    76,     0,     0,    72,    73,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
     134,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,    76,   107,   108,   109,   110,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   175,     0,   132,     0,     0,     0,   133,     0,
       0,     0,   134,   107,   108,   109,   110,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   132,   185,     0,     0,   133,     0,     0,     0,
     134,   107,   108,   109,   110,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     132,     0,     0,   199,   133,     0,     0,     0,   134,   107,
     108,   109,   110,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   132,     0,
       0,     0,   133,     0,     0,     0,   134,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   114,   115,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
       0,     0,   130,   107,   108,   109,   110,   111,   112,   113,
     133,     0,     0,   115,   134,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,   130,   107,
     108,   109,   110,   111,   112,   113,   133,     0,     0,   115,
     134,     0,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,   130,   107,   108,   109,   110,   111,
     112,   113,   133,     0,     0,   115,   134,     0,     0,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
     130,   107,   108,   109,   110,   111,   112,   113,   133,     0,
       0,     0,   134,     0,     0,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,     0,   130,   107,   108,   109,
     110,   111,   112,   113,   133,     0,     0,     0,   134,     0,
       0,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     0,   134
  };

  const short
  parser::yycheck_[] =
  {
      64,     0,    42,     7,     8,    68,    69,    70,    71,    72,
      73,     1,    75,     7,     1,    55,     0,     8,    81,     1,
       1,     8,     6,     1,    87,    88,    89,    91,     1,    20,
      49,    25,     7,    20,     7,     0,    55,     7,     1,    36,
      48,     1,    57,     1,    53,    29,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    54,    58,   132,
     133,   134,    56,    54,    56,    48,    54,     1,    48,     3,
       4,     5,   145,     7,    59,    48,    59,    84,    48,    59,
      32,    57,     3,    22,    23,    49,    38,     1,    22,    23,
      49,    25,     7,     7,    55,    29,    30,    53,    53,    53,
      53,    48,   175,    48,   178,   179,   180,   181,    47,   182,
       1,    25,   185,     1,    48,    58,    55,    48,    11,    53,
      59,     7,   195,   197,   198,    59,    53,    41,    48,    10,
     204,    22,    23,    24,    25,    26,    27,    28,    10,    48,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     1,    54,
      51,     6,    56,    23,    55,   195,     0,     1,    59,    79,
     175,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    20,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     1,    -1,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     1,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       1,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     1,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     1,    -1,    -1,    51,    -1,    -1,
      -1,    55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,     1,    51,     3,     4,     5,    55,     7,
      -1,     9,    59,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      58,    59,     1,    -1,     3,     4,     5,    -1,     7,    -1,
       9,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,
      59,    22,    23,    -1,    25,    -1,    22,    23,    29,    30,
      26,    27,    28,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,     9,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    47,    53,    54,    22,    23,    -1,    25,    59,    55,
      -1,    29,    30,    59,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    22,    23,    24,    25,    26,    27,    28,
      48,    -1,    -1,    -1,    -1,    53,    -1,    22,    23,    57,
      25,    59,    -1,    -1,    29,    30,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      59,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    59,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    22,    23,    24,    25,    26,    27,    28,
      55,    -1,    -1,    32,    59,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,    22,
      23,    24,    25,    26,    27,    28,    55,    -1,    -1,    32,
      59,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    22,    23,    24,    25,    26,
      27,    28,    55,    -1,    -1,    32,    59,    -1,    -1,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    22,    23,    24,    25,    26,    27,    28,    55,    -1,
      -1,    -1,    59,    -1,    -1,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    47,    22,    23,    24,
      25,    26,    27,    28,    55,    -1,    -1,    -1,    59,    -1,
      -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59
  };

  const signed char
  parser::yystos_[] =
  {
       0,     1,     8,    20,    70,    71,    72,    74,    75,     7,
      48,    59,    73,    76,     7,     8,     0,     0,    71,     1,
       7,    48,    73,    77,    48,    49,    55,    57,     1,    53,
       1,    48,    57,    80,    73,     3,    74,    84,    85,     1,
      54,    74,    78,    79,    84,     1,    56,    76,    86,    87,
       1,    58,    84,    76,     1,    54,    49,     1,     3,     4,
       5,     7,     9,    11,    12,    13,    14,    15,    16,    22,
      23,    25,    29,    30,    48,    53,    59,    80,    81,    82,
      88,    42,     1,    48,    49,    86,    78,    53,    53,    53,
      82,    53,    48,    48,     1,    48,    88,    88,    88,    88,
      88,    88,    88,     1,    58,    81,     1,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    51,    55,    59,    88,    86,    48,     1,    54,
      88,    89,    88,    88,    11,    82,     1,    48,     1,    54,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,     7,    88,    88,    88,    49,     1,    54,     1,    54,
       1,    54,    53,    83,    88,    52,     1,    56,     1,    89,
      82,    82,    82,    82,    88,    48,    88,    10,    10,    54,
      83,    82,    82,    48,    54,    82
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      79,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     3,     2,     3,     3,     2,
       3,     2,     1,     3,     1,     1,     5,     2,     5,     3,
       1,     4,     4,     1,     4,     3,     4,     3,     3,     1,
       2,     4,     2,     0,     2,     1,     3,     2,     5,     7,
       5,     7,     2,     2,     8,     2,     3,     2,     5,     7,
       5,     1,     1,     0,     2,     4,     0,     3,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     4,     3,     4,     3,     1,     1,     1,
       1,     3,     4,     3,     4,     4,     2,     3,     1
  };


#if SPLDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"End of file\"", "error", "\"invalid token\"", "\"Integer\"",
  "\"Float\"", "\"Char\"", "\"String\"", "\"Identifier\"", "\"Type\"",
  "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN",
  "GOTO", "SWITCH", "CASE", "STRUCT", "UNION", "INC", "DEC", "PLUS",
  "MINUS", "MUL", "DIV", "REM", "NOT", "BNOT", "AND", "BAND", "OR", "BOR",
  "XOR", "LT", "GT", "LE", "GE", "EQ", "NE", "ASSIGN", "PLUS_ASSIGN",
  "MINUS_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "DOT", "SEMI", "COMMA",
  "SHARP", "QUEST", "COLON", "LP", "RP", "LB", "RB", "LC", "RC", "ERR",
  "SELECT", "UMINUS", "PREFIX_INC", "PREFIX_DEC", "SUFFIX_INC",
  "SUFFIX_DEC", "FAKE_ERR", "NORMAL", "THEN", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "ForOptional", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
  };
#endif


#if SPLDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   108,   108,   110,   111,   113,   114,   115,   116,   117,
     118,   119,   121,   122,   125,   126,   128,   129,   130,   131,
     134,   135,   136,   137,   139,   140,   141,   142,   144,   145,
     147,   150,   152,   153,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   174,   175,   178,   179,   180,   182,   183,   185,
     186,   188,   189,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   237,   238
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
#endif // SPLDEBUG


} // Spl
#line 2265 "/home/runner/work/cmmc/cmmc/build/generated/Spl/ParserImpl.hpp"

#line 240 "cmmc/Frontend/ParserSpl.yy"

void Spl::parser::error(const location_type&, const std::string&) {
    // reportError() << l << ": "sv << m << '\n';
}
