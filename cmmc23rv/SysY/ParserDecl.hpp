// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/runner/work/cmmc/cmmc/build/generated/SysY/ParserDecl.hpp
 ** Define the SysY::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_SYSY_HOME_RUNNER_WORK_CMMC_CMMC_BUILD_GENERATED_SYSY_PARSERDECL_HPP_INCLUDED
# define YY_SYSY_HOME_RUNNER_WORK_CMMC_CMMC_BUILD_GENERATED_SYSY_PARSERDECL_HPP_INCLUDED
// "%code requires" blocks.
#line 24 "cmmc/Frontend/ParserSysY.yy"

#include "../cmmc/Support/Arena.hpp"
#include "../cmmc/Frontend/Driver.hpp"
  using namespace cmmc;

#line 55 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserDecl.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef SYSYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define SYSYDEBUG 1
#  else
#   define SYSYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define SYSYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined SYSYDEBUG */

namespace SysY {
#line 198 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserDecl.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef SYSYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define SYSYSTYPE in C++, use %define api.value.type"
# endif
    typedef SYSYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // VarList
      char dummy1[sizeof (ArgList)];

      // Stmt
      // ExpCommaSep
      // ForOptional
      // Initializer
      // Exp
      char dummy2[sizeof (Expr*)];

      // CompSt
      // StmtList
      // InitializerList
      // Args
      char dummy3[sizeof (ExprPack)];

      // "Float"
      char dummy4[sizeof (FloatingPointStorage)];

      // FunDec
      char dummy5[sizeof (FunctionDeclaration)];

      // "Integer"
      char dummy6[sizeof (IntegerStorage)];

      // ParamDec
      char dummy7[sizeof (NamedArg)];

      // VarDec
      // Dec
      char dummy8[sizeof (NamedVar)];

      // "String"
      // "Identifier"
      // "Type"
      char dummy9[sizeof (String)];

      // QualifiedSpecifier
      // Specifier
      // StructSpecifier
      char dummy10[sizeof (TypeRef)];

      // Def
      char dummy11[sizeof (VarDef)];

      // DefList
      char dummy12[sizeof (VarDefList)];

      // DecList
      char dummy13[sizeof (VarList)];

      // "Char"
      char dummy14[sizeof (char)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef  std::pair<uint32_t, yy::location>  location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        SYSYEMPTY = -2,
    END = 0,                       // "End of file"
    SYSYerror = 256,               // error
    SYSYUNDEF = 257,               // "invalid token"
    INT = 258,                     // "Integer"
    FLOAT = 259,                   // "Float"
    CHAR = 260,                    // "Char"
    STRING = 261,                  // "String"
    ID = 262,                      // "Identifier"
    TYPE = 263,                    // "Type"
    IF = 264,                      // IF
    ELSE = 265,                    // ELSE
    WHILE = 266,                   // WHILE
    DO = 267,                      // DO
    FOR = 268,                     // FOR
    CONTINUE = 269,                // CONTINUE
    BREAK = 270,                   // BREAK
    RETURN = 271,                  // RETURN
    GOTO = 272,                    // GOTO
    SWITCH = 273,                  // SWITCH
    CASE = 274,                    // CASE
    CONST = 275,                   // CONST
    STRUCT = 276,                  // STRUCT
    UNION = 277,                   // UNION
    INC = 278,                     // INC
    DEC = 279,                     // DEC
    PLUS = 280,                    // PLUS
    MINUS = 281,                   // MINUS
    MUL = 282,                     // MUL
    DIV = 283,                     // DIV
    REM = 284,                     // REM
    NOT = 285,                     // NOT
    BNOT = 286,                    // BNOT
    AND = 287,                     // AND
    BAND = 288,                    // BAND
    OR = 289,                      // OR
    BOR = 290,                     // BOR
    XOR = 291,                     // XOR
    LT = 292,                      // LT
    GT = 293,                      // GT
    LE = 294,                      // LE
    GE = 295,                      // GE
    EQ = 296,                      // EQ
    NE = 297,                      // NE
    ASSIGN = 298,                  // ASSIGN
    PLUS_ASSIGN = 299,             // PLUS_ASSIGN
    MINUS_ASSIGN = 300,            // MINUS_ASSIGN
    MUL_ASSIGN = 301,              // MUL_ASSIGN
    DIV_ASSIGN = 302,              // DIV_ASSIGN
    REM_ASSIGN = 303,              // REM_ASSIGN
    BAND_ASSIGN = 304,             // BAND_ASSIGN
    BOR_ASSIGN = 305,              // BOR_ASSIGN
    XOR_ASSIGN = 306,              // XOR_ASSIGN
    SHL_ASSIGN = 307,              // SHL_ASSIGN
    SHR_ASSIGN = 308,              // SHR_ASSIGN
    DOT = 309,                     // DOT
    SEMI = 310,                    // SEMI
    COMMA = 311,                   // COMMA
    SHARP = 312,                   // SHARP
    QUEST = 313,                   // QUEST
    COLON = 314,                   // COLON
    LP = 315,                      // LP
    RP = 316,                      // RP
    LB = 317,                      // LB
    RB = 318,                      // RB
    LC = 319,                      // LC
    RC = 320,                      // RC
    ERR = 321,                     // ERR
    SELECT = 322,                  // SELECT
    SHL = 323,                     // SHL
    SHR = 324,                     // SHR
    UPLUS = 325,                   // UPLUS
    UMINUS = 326,                  // UMINUS
    PREFIX_INC = 327,              // PREFIX_INC
    PREFIX_DEC = 328,              // PREFIX_DEC
    DEREF = 329,                   // DEREF
    ADDRESS = 330,                 // ADDRESS
    EXPLICIT_CAST = 331,           // EXPLICIT_CAST
    SUFFIX_INC = 332,              // SUFFIX_INC
    SUFFIX_DEC = 333,              // SUFFIX_DEC
    THEN = 334                     // THEN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 80, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "End of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_INT = 3,                               // "Integer"
        S_FLOAT = 4,                             // "Float"
        S_CHAR = 5,                              // "Char"
        S_STRING = 6,                            // "String"
        S_ID = 7,                                // "Identifier"
        S_TYPE = 8,                              // "Type"
        S_IF = 9,                                // IF
        S_ELSE = 10,                             // ELSE
        S_WHILE = 11,                            // WHILE
        S_DO = 12,                               // DO
        S_FOR = 13,                              // FOR
        S_CONTINUE = 14,                         // CONTINUE
        S_BREAK = 15,                            // BREAK
        S_RETURN = 16,                           // RETURN
        S_GOTO = 17,                             // GOTO
        S_SWITCH = 18,                           // SWITCH
        S_CASE = 19,                             // CASE
        S_CONST = 20,                            // CONST
        S_STRUCT = 21,                           // STRUCT
        S_UNION = 22,                            // UNION
        S_INC = 23,                              // INC
        S_DEC = 24,                              // DEC
        S_PLUS = 25,                             // PLUS
        S_MINUS = 26,                            // MINUS
        S_MUL = 27,                              // MUL
        S_DIV = 28,                              // DIV
        S_REM = 29,                              // REM
        S_NOT = 30,                              // NOT
        S_BNOT = 31,                             // BNOT
        S_AND = 32,                              // AND
        S_BAND = 33,                             // BAND
        S_OR = 34,                               // OR
        S_BOR = 35,                              // BOR
        S_XOR = 36,                              // XOR
        S_LT = 37,                               // LT
        S_GT = 38,                               // GT
        S_LE = 39,                               // LE
        S_GE = 40,                               // GE
        S_EQ = 41,                               // EQ
        S_NE = 42,                               // NE
        S_ASSIGN = 43,                           // ASSIGN
        S_PLUS_ASSIGN = 44,                      // PLUS_ASSIGN
        S_MINUS_ASSIGN = 45,                     // MINUS_ASSIGN
        S_MUL_ASSIGN = 46,                       // MUL_ASSIGN
        S_DIV_ASSIGN = 47,                       // DIV_ASSIGN
        S_REM_ASSIGN = 48,                       // REM_ASSIGN
        S_BAND_ASSIGN = 49,                      // BAND_ASSIGN
        S_BOR_ASSIGN = 50,                       // BOR_ASSIGN
        S_XOR_ASSIGN = 51,                       // XOR_ASSIGN
        S_SHL_ASSIGN = 52,                       // SHL_ASSIGN
        S_SHR_ASSIGN = 53,                       // SHR_ASSIGN
        S_DOT = 54,                              // DOT
        S_SEMI = 55,                             // SEMI
        S_COMMA = 56,                            // COMMA
        S_SHARP = 57,                            // SHARP
        S_QUEST = 58,                            // QUEST
        S_COLON = 59,                            // COLON
        S_LP = 60,                               // LP
        S_RP = 61,                               // RP
        S_LB = 62,                               // LB
        S_RB = 63,                               // RB
        S_LC = 64,                               // LC
        S_RC = 65,                               // RC
        S_ERR = 66,                              // ERR
        S_SELECT = 67,                           // SELECT
        S_SHL = 68,                              // SHL
        S_SHR = 69,                              // SHR
        S_UPLUS = 70,                            // UPLUS
        S_UMINUS = 71,                           // UMINUS
        S_PREFIX_INC = 72,                       // PREFIX_INC
        S_PREFIX_DEC = 73,                       // PREFIX_DEC
        S_DEREF = 74,                            // DEREF
        S_ADDRESS = 75,                          // ADDRESS
        S_EXPLICIT_CAST = 76,                    // EXPLICIT_CAST
        S_SUFFIX_INC = 77,                       // SUFFIX_INC
        S_SUFFIX_DEC = 78,                       // SUFFIX_DEC
        S_THEN = 79,                             // THEN
        S_YYACCEPT = 80,                         // $accept
        S_Program = 81,                          // Program
        S_ExtDefList = 82,                       // ExtDefList
        S_ExtDef = 83,                           // ExtDef
        S_QualifiedSpecifier = 84,               // QualifiedSpecifier
        S_Specifier = 85,                        // Specifier
        S_StructSpecifier = 86,                  // StructSpecifier
        S_VarDec = 87,                           // VarDec
        S_FunDec = 88,                           // FunDec
        S_VarList = 89,                          // VarList
        S_ParamDec = 90,                         // ParamDec
        S_CompSt = 91,                           // CompSt
        S_StmtList = 92,                         // StmtList
        S_Stmt = 93,                             // Stmt
        S_ExpCommaSep = 94,                      // ExpCommaSep
        S_ForOptional = 95,                      // ForOptional
        S_DefList = 96,                          // DefList
        S_Def = 97,                              // Def
        S_DecList = 98,                          // DecList
        S_Dec = 99,                              // Dec
        S_Initializer = 100,                     // Initializer
        S_InitializerList = 101,                 // InitializerList
        S_Exp = 102,                             // Exp
        S_Args = 103                             // Args
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.move< ArgList > (std::move (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.move< Expr* > (std::move (that.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.move< ExprPack > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.move< FloatingPointStorage > (std::move (that.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.move< FunctionDeclaration > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.move< IntegerStorage > (std::move (that.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.move< NamedArg > (std::move (that.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.move< NamedVar > (std::move (that.value));
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.move< String > (std::move (that.value));
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.move< TypeRef > (std::move (that.value));
        break;

      case symbol_kind::S_Def: // Def
        value.move< VarDef > (std::move (that.value));
        break;

      case symbol_kind::S_DefList: // DefList
        value.move< VarDefList > (std::move (that.value));
        break;

      case symbol_kind::S_DecList: // DecList
        value.move< VarList > (std::move (that.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.move< char > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ArgList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ArgList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expr*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expr*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExprPack&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExprPack& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FloatingPointStorage&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FloatingPointStorage& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FunctionDeclaration&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FunctionDeclaration& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IntegerStorage&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IntegerStorage& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NamedArg&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NamedArg& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NamedVar&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NamedVar& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, String&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const String& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeRef&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeRef& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VarDef&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VarDef& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VarDefList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VarDefList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VarList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VarList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, char&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const char& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_VarList: // VarList
        value.template destroy< ArgList > ();
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.template destroy< Expr* > ();
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.template destroy< ExprPack > ();
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.template destroy< FloatingPointStorage > ();
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.template destroy< FunctionDeclaration > ();
        break;

      case symbol_kind::S_INT: // "Integer"
        value.template destroy< IntegerStorage > ();
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.template destroy< NamedArg > ();
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.template destroy< NamedVar > ();
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.template destroy< String > ();
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.template destroy< TypeRef > ();
        break;

      case symbol_kind::S_Def: // Def
        value.template destroy< VarDef > ();
        break;

      case symbol_kind::S_DefList: // DefList
        value.template destroy< VarDefList > ();
        break;

      case symbol_kind::S_DecList: // DecList
        value.template destroy< VarList > ();
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.template destroy< char > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, FloatingPointStorage v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const FloatingPointStorage& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, IntegerStorage v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const IntegerStorage& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, String v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const String& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, char v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const char& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (cmmc::DriverImpl& driver_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if SYSYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYSYerror (location_type l)
      {
        return symbol_type (token::SYSYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_SYSYerror (const location_type& l)
      {
        return symbol_type (token::SYSYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYSYUNDEF (location_type l)
      {
        return symbol_type (token::SYSYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_SYSYUNDEF (const location_type& l)
      {
        return symbol_type (token::SYSYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (IntegerStorage v, location_type l)
      {
        return symbol_type (token::INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const IntegerStorage& v, const location_type& l)
      {
        return symbol_type (token::INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (FloatingPointStorage v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const FloatingPointStorage& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (char v, location_type l)
      {
        return symbol_type (token::CHAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const char& v, const location_type& l)
      {
        return symbol_type (token::CHAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (String v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const String& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (String v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const String& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (String v, location_type l)
      {
        return symbol_type (token::TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const String& v, const location_type& l)
      {
        return symbol_type (token::TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (location_type l)
      {
        return symbol_type (token::DO, std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const location_type& l)
      {
        return symbol_type (token::DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO (location_type l)
      {
        return symbol_type (token::GOTO, std::move (l));
      }
#else
      static
      symbol_type
      make_GOTO (const location_type& l)
      {
        return symbol_type (token::GOTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (location_type l)
      {
        return symbol_type (token::CONST, std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const location_type& l)
      {
        return symbol_type (token::CONST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (location_type l)
      {
        return symbol_type (token::STRUCT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const location_type& l)
      {
        return symbol_type (token::STRUCT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION (location_type l)
      {
        return symbol_type (token::UNION, std::move (l));
      }
#else
      static
      symbol_type
      make_UNION (const location_type& l)
      {
        return symbol_type (token::UNION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC (location_type l)
      {
        return symbol_type (token::INC, std::move (l));
      }
#else
      static
      symbol_type
      make_INC (const location_type& l)
      {
        return symbol_type (token::INC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC (location_type l)
      {
        return symbol_type (token::DEC, std::move (l));
      }
#else
      static
      symbol_type
      make_DEC (const location_type& l)
      {
        return symbol_type (token::DEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (location_type l)
      {
        return symbol_type (token::MUL, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL (const location_type& l)
      {
        return symbol_type (token::MUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REM (location_type l)
      {
        return symbol_type (token::REM, std::move (l));
      }
#else
      static
      symbol_type
      make_REM (const location_type& l)
      {
        return symbol_type (token::REM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BNOT (location_type l)
      {
        return symbol_type (token::BNOT, std::move (l));
      }
#else
      static
      symbol_type
      make_BNOT (const location_type& l)
      {
        return symbol_type (token::BNOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BAND (location_type l)
      {
        return symbol_type (token::BAND, std::move (l));
      }
#else
      static
      symbol_type
      make_BAND (const location_type& l)
      {
        return symbol_type (token::BAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOR (location_type l)
      {
        return symbol_type (token::BOR, std::move (l));
      }
#else
      static
      symbol_type
      make_BOR (const location_type& l)
      {
        return symbol_type (token::BOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR (location_type l)
      {
        return symbol_type (token::XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR (const location_type& l)
      {
        return symbol_type (token::XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_ASSIGN (location_type l)
      {
        return symbol_type (token::PLUS_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_ASSIGN (const location_type& l)
      {
        return symbol_type (token::PLUS_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_ASSIGN (location_type l)
      {
        return symbol_type (token::MINUS_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS_ASSIGN (const location_type& l)
      {
        return symbol_type (token::MINUS_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_ASSIGN (location_type l)
      {
        return symbol_type (token::MUL_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL_ASSIGN (const location_type& l)
      {
        return symbol_type (token::MUL_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ASSIGN (location_type l)
      {
        return symbol_type (token::DIV_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_ASSIGN (const location_type& l)
      {
        return symbol_type (token::DIV_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REM_ASSIGN (location_type l)
      {
        return symbol_type (token::REM_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_REM_ASSIGN (const location_type& l)
      {
        return symbol_type (token::REM_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BAND_ASSIGN (location_type l)
      {
        return symbol_type (token::BAND_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_BAND_ASSIGN (const location_type& l)
      {
        return symbol_type (token::BAND_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOR_ASSIGN (location_type l)
      {
        return symbol_type (token::BOR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_BOR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::BOR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ASSIGN (location_type l)
      {
        return symbol_type (token::XOR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::XOR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHL_ASSIGN (location_type l)
      {
        return symbol_type (token::SHL_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SHL_ASSIGN (const location_type& l)
      {
        return symbol_type (token::SHL_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHR_ASSIGN (location_type l)
      {
        return symbol_type (token::SHR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SHR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::SHR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI (location_type l)
      {
        return symbol_type (token::SEMI, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMI (const location_type& l)
      {
        return symbol_type (token::SEMI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHARP (location_type l)
      {
        return symbol_type (token::SHARP, std::move (l));
      }
#else
      static
      symbol_type
      make_SHARP (const location_type& l)
      {
        return symbol_type (token::SHARP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUEST (location_type l)
      {
        return symbol_type (token::QUEST, std::move (l));
      }
#else
      static
      symbol_type
      make_QUEST (const location_type& l)
      {
        return symbol_type (token::QUEST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LP (location_type l)
      {
        return symbol_type (token::LP, std::move (l));
      }
#else
      static
      symbol_type
      make_LP (const location_type& l)
      {
        return symbol_type (token::LP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RP (location_type l)
      {
        return symbol_type (token::RP, std::move (l));
      }
#else
      static
      symbol_type
      make_RP (const location_type& l)
      {
        return symbol_type (token::RP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LB (location_type l)
      {
        return symbol_type (token::LB, std::move (l));
      }
#else
      static
      symbol_type
      make_LB (const location_type& l)
      {
        return symbol_type (token::LB, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RB (location_type l)
      {
        return symbol_type (token::RB, std::move (l));
      }
#else
      static
      symbol_type
      make_RB (const location_type& l)
      {
        return symbol_type (token::RB, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LC (location_type l)
      {
        return symbol_type (token::LC, std::move (l));
      }
#else
      static
      symbol_type
      make_LC (const location_type& l)
      {
        return symbol_type (token::LC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RC (location_type l)
      {
        return symbol_type (token::RC, std::move (l));
      }
#else
      static
      symbol_type
      make_RC (const location_type& l)
      {
        return symbol_type (token::RC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ERR (location_type l)
      {
        return symbol_type (token::ERR, std::move (l));
      }
#else
      static
      symbol_type
      make_ERR (const location_type& l)
      {
        return symbol_type (token::ERR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELECT (location_type l)
      {
        return symbol_type (token::SELECT, std::move (l));
      }
#else
      static
      symbol_type
      make_SELECT (const location_type& l)
      {
        return symbol_type (token::SELECT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHL (location_type l)
      {
        return symbol_type (token::SHL, std::move (l));
      }
#else
      static
      symbol_type
      make_SHL (const location_type& l)
      {
        return symbol_type (token::SHL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHR (location_type l)
      {
        return symbol_type (token::SHR, std::move (l));
      }
#else
      static
      symbol_type
      make_SHR (const location_type& l)
      {
        return symbol_type (token::SHR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UPLUS (location_type l)
      {
        return symbol_type (token::UPLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UPLUS (const location_type& l)
      {
        return symbol_type (token::UPLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS (location_type l)
      {
        return symbol_type (token::UMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UMINUS (const location_type& l)
      {
        return symbol_type (token::UMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIX_INC (location_type l)
      {
        return symbol_type (token::PREFIX_INC, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIX_INC (const location_type& l)
      {
        return symbol_type (token::PREFIX_INC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIX_DEC (location_type l)
      {
        return symbol_type (token::PREFIX_DEC, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIX_DEC (const location_type& l)
      {
        return symbol_type (token::PREFIX_DEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEREF (location_type l)
      {
        return symbol_type (token::DEREF, std::move (l));
      }
#else
      static
      symbol_type
      make_DEREF (const location_type& l)
      {
        return symbol_type (token::DEREF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDRESS (location_type l)
      {
        return symbol_type (token::ADDRESS, std::move (l));
      }
#else
      static
      symbol_type
      make_ADDRESS (const location_type& l)
      {
        return symbol_type (token::ADDRESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXPLICIT_CAST (location_type l)
      {
        return symbol_type (token::EXPLICIT_CAST, std::move (l));
      }
#else
      static
      symbol_type
      make_EXPLICIT_CAST (const location_type& l)
      {
        return symbol_type (token::EXPLICIT_CAST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUFFIX_INC (location_type l)
      {
        return symbol_type (token::SUFFIX_INC, std::move (l));
      }
#else
      static
      symbol_type
      make_SUFFIX_INC (const location_type& l)
      {
        return symbol_type (token::SUFFIX_INC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUFFIX_DEC (location_type l)
      {
        return symbol_type (token::SUFFIX_DEC, std::move (l));
      }
#else
      static
      symbol_type
      make_SUFFIX_DEC (const location_type& l)
      {
        return symbol_type (token::SUFFIX_DEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (location_type l)
      {
        return symbol_type (token::THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const location_type& l)
      {
        return symbol_type (token::THEN, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if SYSYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1381,     ///< Last index in yytable_.
      yynnts_ = 24,  ///< Number of nonterminal symbols.
      yyfinal_ = 13 ///< Termination state number.
    };


    // User arguments.
    cmmc::DriverImpl& driver;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
    };
    // Last valid token kind.
    const int code_max = 334;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.copy< ArgList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.copy< Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.copy< ExprPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.copy< FloatingPointStorage > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.copy< FunctionDeclaration > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.copy< IntegerStorage > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.copy< NamedArg > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.copy< NamedVar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.copy< String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.copy< TypeRef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Def: // Def
        value.copy< VarDef > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefList: // DefList
        value.copy< VarDefList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DecList: // DecList
        value.copy< VarList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.copy< char > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_VarList: // VarList
        value.move< ArgList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_ExpCommaSep: // ExpCommaSep
      case symbol_kind::S_ForOptional: // ForOptional
      case symbol_kind::S_Initializer: // Initializer
      case symbol_kind::S_Exp: // Exp
        value.move< Expr* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_InitializerList: // InitializerList
      case symbol_kind::S_Args: // Args
        value.move< ExprPack > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // "Float"
        value.move< FloatingPointStorage > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FunDec: // FunDec
        value.move< FunctionDeclaration > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // "Integer"
        value.move< IntegerStorage > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ParamDec: // ParamDec
        value.move< NamedArg > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_Dec: // Dec
        value.move< NamedVar > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // "String"
      case symbol_kind::S_ID: // "Identifier"
      case symbol_kind::S_TYPE: // "Type"
        value.move< String > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_QualifiedSpecifier: // QualifiedSpecifier
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
        value.move< TypeRef > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Def: // Def
        value.move< VarDef > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DefList: // DefList
        value.move< VarDefList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DecList: // DecList
        value.move< VarList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CHAR: // "Char"
        value.move< char > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // SysY
#line 3125 "/home/runner/work/cmmc/cmmc/build/generated/SysY/ParserDecl.hpp"




#endif // !YY_SYSY_HOME_RUNNER_WORK_CMMC_CMMC_BUILD_GENERATED_SYSY_PARSERDECL_HPP_INCLUDED
