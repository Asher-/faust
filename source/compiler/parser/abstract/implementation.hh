// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2022-2021 Free Software Foundation, Inc.

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
 ** \file abstract/implementation.hh
 ** Define the ::Faust::Compiler::Parser::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_ABSTRACT_IMPLEMENTATION_HH_INCLUDED
# define YY_YY_ABSTRACT_IMPLEMENTATION_HH_INCLUDED
// "%code requires" blocks.
 /* Faust requires */
  #include <string>
  #include "compiler/parser/type/tokens.hh"
  #include "compiler/parser/abstract/location.hh"
  namespace Faust { namespace Compiler { namespace Parser {
    struct Implementation;
    namespace Lexer { struct Implementation; }
  } } }


# include <cassert>
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
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
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
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace Faust { namespace Compiler { namespace Parser {




  /// A Bison parser.
  class AbstractImplementation
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
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
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
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
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
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
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
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
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
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
      yytypeid_ = YY_NULLPTR;
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
      // program
      // doc
      // doc.equation
      // doc.diagram
      // doc.notice
      // doc.metadata
      // doc.list
      // doc.attribute.list
      // doc.attribute.definition
      // expression
      // expression.component
      // expression.composition
      // expression.composition.parallel
      // expression.composition.serial
      // expression.composition.mix
      // expression.composition.recursive
      // expression.composition.sequence
      // expression.composition.split
      // expression.environment
      // expression.infix
      // expression.infix.definitions.substitution
      // expression.infix.environment.access
      // expression.infix.math
      // expression.infix.math.algebra
      // expression.infix.math.comparison
      // expression.infix.math.logic
      // expression.infix.math.shift
      // expression.infix.prefix
      // expression.infix.signal.delay
      // expression.iterate.parallel
      // expression.iterate.sequence
      // expression.iterate.sum
      // expression.iterate.product
      // expression.lambda
      // expression.lambda.params
      // expression.lambda.params.start
      // expression.lambda.params.append
      // expression.letrec
      // expression.letrec.list
      // expression.letrec.list.start
      // expression.letrec.list.append
      // expression.letrec.equation
      // expression.letrec.equation.name
      // expression.library
      // expression.math
      // expression.math.comparison
      // expression.math.rounding
      // expression.math.signal
      // expression.math.signal.algebra
      // expression.math.signal.shift
      // expression.math.signal.power
      // expression.math.scalar
      // expression.math.trigonometry
      // expression.parenthesis
      // expression.signal
      // expression.signal.control
      // expression.signal.delay
      // expression.signal.logic
      // primitive
      // primitive.foreign
      // primitive.number
      // primitive.string.quoted
      // primitive.string.unquoted
      // primitive.string.tag
      // primitive.signal
      // primitive.signal.input.implicit
      // primitive.signal.input.terminate
      // primitive.type
      // primitive.type.number
      // primitive.type.number.int
      // primitive.type.number.float
      // primitive.type.any
      // primitive.type.number.list
      // primitive.type.number.list.member
      // primitive.type.number.list.start
      // primitive.type.number.list.append
      // primitive.signal.route
      // primitive.signal.route.implied.outputs
      // primitive.signal.route.implied.connections
      // primitive.signal.route.explicit
      // primitive.signal.source
      // primitive.signal.source.table
      // primitive.signal.source.soundfile
      // primitive.signal.source.waveform
      // primitive.type.list
      // primitive.type.list.start
      // primitive.type.list.append
      // primitive.ui
      // primitive.ui.button
      // primitive.ui.checkbox
      // primitive.ui.vslider
      // primitive.ui.hslider
      // primitive.ui.nentry
      // primitive.ui.vgroup
      // primitive.ui.hgroup
      // primitive.ui.tgroup
      // primitive.ui.vbargraph
      // primitive.ui.hbargraph
      // primitive.foreign.function
      // primitive.foreign.function.signature
      // primitive.foreign.constant
      // primitive.foreign.variable
      // primitive.signal.inputs
      // primitive.signal.outputs
      // statement
      // statement.definition
      // statement.definition.function.incomplete
      // statement.definition.function
      // statement.definition.assignment
      // statement.definition.with
      // statement.definition.error
      // statement.definition.list
      // statement.definition.list.start
      // statement.definition.list.start.qualified
      // statement.definition.list.append
      // statement.definition.list.append.qualified
      // statement.declare.metadata
      // statement.declare.feature.metadata
      // statement.declare.doc
      // statement.identifier
      // statement.identifier.box
      // statement.identifier.waveform
      // statement.import
      // statement.list
      // statement.list.start
      // statement.list.start.qualified
      // statement.list.append
      // statement.list.append.qualified
      // statement.signal.pattern.rule
      // statement.signal.pattern.rule.list
      // statement.signal.pattern.rule.list.start
      // statement.signal.pattern.rule.list.append
      char dummy1[sizeof (Tree)];

      // doc.attribute.value
      char dummy2[sizeof (bool)];

      // FLOAT
      char dummy3[sizeof (float)];

      // INT
      // FLOATMODE
      // DOUBLEMODE
      // QUADMODE
      // FIXEDPOINTMODE
      // statement.math.precision
      // statement.math.precision.list
      // statement.math.precision.list.start
      // statement.math.precision.list.append
      char dummy4[sizeof (int)];

      // WITH
      // LETREC
      // SPLIT
      // MIX
      // SEQ
      // COMMA
      // REC
      // LT
      // LE
      // EQ
      // GT
      // GE
      // NE
      // ADD
      // SUB
      // OR
      // MUL
      // DIV
      // MOD
      // AND
      // XOR
      // LSH
      // RSH
      // POWOP
      // FDELAY
      // DELAY1
      // DOT
      // MEM
      // PREFIX
      // INTCAST
      // FLOATCAST
      // ANYCAST
      // FFUNCTION
      // FCONSTANT
      // FVARIABLE
      // BUTTON
      // CHECKBOX
      // VSLIDER
      // HSLIDER
      // NENTRY
      // VGROUP
      // HGROUP
      // TGROUP
      // HBARGRAPH
      // VBARGRAPH
      // SOUNDFILE
      // ATTACH
      // ACOS
      // ASIN
      // ATAN
      // ATAN2
      // COS
      // SIN
      // TAN
      // EXP
      // LOG
      // LOG10
      // POWFUN
      // SQRT
      // ABS
      // MIN
      // MAX
      // FMOD
      // REMAINDER
      // FLOOR
      // CEIL
      // RINT
      // RDTBL
      // RWTBL
      // SELECT2
      // SELECT3
      // LAMBDA
      // WIRE
      // CUT
      // ENDDEF
      // VIRG
      // LPAR
      // RPAR
      // LBRAQ
      // RBRAQ
      // LCROC
      // RCROC
      // WHERE
      // DEF
      // IMPORT
      // COMPONENT
      // LIBRARY
      // ENVIRONMENT
      // WAVEFORM
      // ROUTE
      // ENABLE
      // CONTROL
      // ITERATE_PARALLEL
      // ISEQ
      // ISUM
      // IPROD
      // INPUTS
      // OUTPUTS
      // STRING
      // TAGSTRING
      // IDENT
      // EXTRA
      // DECLARE
      // CASE
      // ARROW
      // ASSERTBOUNDS
      // LOWEST
      // HIGHEST
      // BDOC
      // EDOC
      // BEQN
      // EEQN
      // BDGM
      // EDGM
      // BLST
      // ELST
      // BMETADATA
      // EMETADATA
      // DOCCHAR
      // NOTICE
      // LISTING
      // LSTTRUE
      // LSTFALSE
      // LSTDEPENDENCIES
      // LSTMDOCTAGS
      // LSTDISTRIBUTED
      // LSTEQ
      // LSTQ
      // ENDL
      // doc.text
      char dummy5[sizeof (std::string)];
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

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

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
        FAUST_YYEMPTY = -2,
    FAUST_ENDOFINPUT = 0,          // ENDOFINPUT
    FAUST_YYerror = 1,             // error
    FAUST_YYUNDEF = 2,             // "invalid token"
    FAUST_WITH = 3,                // WITH
    FAUST_LETREC = 4,              // LETREC
    FAUST_SPLIT = 5,               // SPLIT
    FAUST_MIX = 6,                 // MIX
    FAUST_SEQ = 7,                 // SEQ
    FAUST_COMMA = 8,               // COMMA
    FAUST_REC = 9,                 // REC
    FAUST_LT = 10,                 // LT
    FAUST_LE = 11,                 // LE
    FAUST_EQ = 12,                 // EQ
    FAUST_GT = 13,                 // GT
    FAUST_GE = 14,                 // GE
    FAUST_NE = 15,                 // NE
    FAUST_ADD = 16,                // ADD
    FAUST_SUB = 17,                // SUB
    FAUST_OR = 18,                 // OR
    FAUST_MUL = 19,                // MUL
    FAUST_DIV = 20,                // DIV
    FAUST_MOD = 21,                // MOD
    FAUST_AND = 22,                // AND
    FAUST_XOR = 23,                // XOR
    FAUST_LSH = 24,                // LSH
    FAUST_RSH = 25,                // RSH
    FAUST_POWOP = 26,              // POWOP
    FAUST_FDELAY = 27,             // FDELAY
    FAUST_DELAY1 = 28,             // DELAY1
    FAUST_DOT = 29,                // DOT
    FAUST_MEM = 30,                // MEM
    FAUST_PREFIX = 31,             // PREFIX
    FAUST_INTCAST = 32,            // INTCAST
    FAUST_FLOATCAST = 33,          // FLOATCAST
    FAUST_ANYCAST = 34,            // ANYCAST
    FAUST_FFUNCTION = 35,          // FFUNCTION
    FAUST_FCONSTANT = 36,          // FCONSTANT
    FAUST_FVARIABLE = 37,          // FVARIABLE
    FAUST_BUTTON = 38,             // BUTTON
    FAUST_CHECKBOX = 39,           // CHECKBOX
    FAUST_VSLIDER = 40,            // VSLIDER
    FAUST_HSLIDER = 41,            // HSLIDER
    FAUST_NENTRY = 42,             // NENTRY
    FAUST_VGROUP = 43,             // VGROUP
    FAUST_HGROUP = 44,             // HGROUP
    FAUST_TGROUP = 45,             // TGROUP
    FAUST_HBARGRAPH = 46,          // HBARGRAPH
    FAUST_VBARGRAPH = 47,          // VBARGRAPH
    FAUST_SOUNDFILE = 48,          // SOUNDFILE
    FAUST_ATTACH = 49,             // ATTACH
    FAUST_ACOS = 50,               // ACOS
    FAUST_ASIN = 51,               // ASIN
    FAUST_ATAN = 52,               // ATAN
    FAUST_ATAN2 = 53,              // ATAN2
    FAUST_COS = 54,                // COS
    FAUST_SIN = 55,                // SIN
    FAUST_TAN = 56,                // TAN
    FAUST_EXP = 57,                // EXP
    FAUST_LOG = 58,                // LOG
    FAUST_LOG10 = 59,              // LOG10
    FAUST_POWFUN = 60,             // POWFUN
    FAUST_SQRT = 61,               // SQRT
    FAUST_ABS = 62,                // ABS
    FAUST_MIN = 63,                // MIN
    FAUST_MAX = 64,                // MAX
    FAUST_FMOD = 65,               // FMOD
    FAUST_REMAINDER = 66,          // REMAINDER
    FAUST_FLOOR = 67,              // FLOOR
    FAUST_CEIL = 68,               // CEIL
    FAUST_RINT = 69,               // RINT
    FAUST_RDTBL = 70,              // RDTBL
    FAUST_RWTBL = 71,              // RWTBL
    FAUST_SELECT2 = 72,            // SELECT2
    FAUST_SELECT3 = 73,            // SELECT3
    FAUST_INT = 74,                // INT
    FAUST_FLOAT = 75,              // FLOAT
    FAUST_LAMBDA = 76,             // LAMBDA
    FAUST_WIRE = 77,               // WIRE
    FAUST_CUT = 78,                // CUT
    FAUST_ENDDEF = 79,             // ENDDEF
    FAUST_VIRG = 80,               // VIRG
    FAUST_LPAR = 81,               // LPAR
    FAUST_RPAR = 82,               // RPAR
    FAUST_LBRAQ = 83,              // LBRAQ
    FAUST_RBRAQ = 84,              // RBRAQ
    FAUST_LCROC = 85,              // LCROC
    FAUST_RCROC = 86,              // RCROC
    FAUST_WHERE = 87,              // WHERE
    FAUST_DEF = 88,                // DEF
    FAUST_IMPORT = 89,             // IMPORT
    FAUST_COMPONENT = 90,          // COMPONENT
    FAUST_LIBRARY = 91,            // LIBRARY
    FAUST_ENVIRONMENT = 92,        // ENVIRONMENT
    FAUST_WAVEFORM = 93,           // WAVEFORM
    FAUST_ROUTE = 94,              // ROUTE
    FAUST_ENABLE = 95,             // ENABLE
    FAUST_CONTROL = 96,            // CONTROL
    FAUST_ITERATE_PARALLEL = 97,   // ITERATE_PARALLEL
    FAUST_ISEQ = 98,               // ISEQ
    FAUST_ISUM = 99,               // ISUM
    FAUST_IPROD = 100,             // IPROD
    FAUST_INPUTS = 101,            // INPUTS
    FAUST_OUTPUTS = 102,           // OUTPUTS
    FAUST_STRING = 103,            // STRING
    FAUST_TAGSTRING = 104,         // TAGSTRING
    FAUST_IDENT = 105,             // IDENT
    FAUST_EXTRA = 106,             // EXTRA
    FAUST_DECLARE = 107,           // DECLARE
    FAUST_CASE = 108,              // CASE
    FAUST_ARROW = 109,             // ARROW
    FAUST_ASSERTBOUNDS = 110,      // ASSERTBOUNDS
    FAUST_LOWEST = 111,            // LOWEST
    FAUST_HIGHEST = 112,           // HIGHEST
    FAUST_FLOATMODE = 113,         // FLOATMODE
    FAUST_DOUBLEMODE = 114,        // DOUBLEMODE
    FAUST_QUADMODE = 115,          // QUADMODE
    FAUST_FIXEDPOINTMODE = 116,    // FIXEDPOINTMODE
    FAUST_BDOC = 117,              // BDOC
    FAUST_EDOC = 118,              // EDOC
    FAUST_BEQN = 119,              // BEQN
    FAUST_EEQN = 120,              // EEQN
    FAUST_BDGM = 121,              // BDGM
    FAUST_EDGM = 122,              // EDGM
    FAUST_BLST = 123,              // BLST
    FAUST_ELST = 124,              // ELST
    FAUST_BMETADATA = 125,         // BMETADATA
    FAUST_EMETADATA = 126,         // EMETADATA
    FAUST_DOCCHAR = 127,           // DOCCHAR
    FAUST_NOTICE = 128,            // NOTICE
    FAUST_LISTING = 129,           // LISTING
    FAUST_LSTTRUE = 130,           // LSTTRUE
    FAUST_LSTFALSE = 131,          // LSTFALSE
    FAUST_LSTDEPENDENCIES = 132,   // LSTDEPENDENCIES
    FAUST_LSTMDOCTAGS = 133,       // LSTMDOCTAGS
    FAUST_LSTDISTRIBUTED = 134,    // LSTDISTRIBUTED
    FAUST_LSTEQ = 135,             // LSTEQ
    FAUST_LSTQ = 136,              // LSTQ
    FAUST_ENDL = 137               // ENDL
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
        YYNTOKENS = 138, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // ENDOFINPUT
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_WITH = 3,                              // WITH
        S_LETREC = 4,                            // LETREC
        S_SPLIT = 5,                             // SPLIT
        S_MIX = 6,                               // MIX
        S_SEQ = 7,                               // SEQ
        S_COMMA = 8,                             // COMMA
        S_REC = 9,                               // REC
        S_LT = 10,                               // LT
        S_LE = 11,                               // LE
        S_EQ = 12,                               // EQ
        S_GT = 13,                               // GT
        S_GE = 14,                               // GE
        S_NE = 15,                               // NE
        S_ADD = 16,                              // ADD
        S_SUB = 17,                              // SUB
        S_OR = 18,                               // OR
        S_MUL = 19,                              // MUL
        S_DIV = 20,                              // DIV
        S_MOD = 21,                              // MOD
        S_AND = 22,                              // AND
        S_XOR = 23,                              // XOR
        S_LSH = 24,                              // LSH
        S_RSH = 25,                              // RSH
        S_POWOP = 26,                            // POWOP
        S_FDELAY = 27,                           // FDELAY
        S_DELAY1 = 28,                           // DELAY1
        S_DOT = 29,                              // DOT
        S_MEM = 30,                              // MEM
        S_PREFIX = 31,                           // PREFIX
        S_INTCAST = 32,                          // INTCAST
        S_FLOATCAST = 33,                        // FLOATCAST
        S_ANYCAST = 34,                          // ANYCAST
        S_FFUNCTION = 35,                        // FFUNCTION
        S_FCONSTANT = 36,                        // FCONSTANT
        S_FVARIABLE = 37,                        // FVARIABLE
        S_BUTTON = 38,                           // BUTTON
        S_CHECKBOX = 39,                         // CHECKBOX
        S_VSLIDER = 40,                          // VSLIDER
        S_HSLIDER = 41,                          // HSLIDER
        S_NENTRY = 42,                           // NENTRY
        S_VGROUP = 43,                           // VGROUP
        S_HGROUP = 44,                           // HGROUP
        S_TGROUP = 45,                           // TGROUP
        S_HBARGRAPH = 46,                        // HBARGRAPH
        S_VBARGRAPH = 47,                        // VBARGRAPH
        S_SOUNDFILE = 48,                        // SOUNDFILE
        S_ATTACH = 49,                           // ATTACH
        S_ACOS = 50,                             // ACOS
        S_ASIN = 51,                             // ASIN
        S_ATAN = 52,                             // ATAN
        S_ATAN2 = 53,                            // ATAN2
        S_COS = 54,                              // COS
        S_SIN = 55,                              // SIN
        S_TAN = 56,                              // TAN
        S_EXP = 57,                              // EXP
        S_LOG = 58,                              // LOG
        S_LOG10 = 59,                            // LOG10
        S_POWFUN = 60,                           // POWFUN
        S_SQRT = 61,                             // SQRT
        S_ABS = 62,                              // ABS
        S_MIN = 63,                              // MIN
        S_MAX = 64,                              // MAX
        S_FMOD = 65,                             // FMOD
        S_REMAINDER = 66,                        // REMAINDER
        S_FLOOR = 67,                            // FLOOR
        S_CEIL = 68,                             // CEIL
        S_RINT = 69,                             // RINT
        S_RDTBL = 70,                            // RDTBL
        S_RWTBL = 71,                            // RWTBL
        S_SELECT2 = 72,                          // SELECT2
        S_SELECT3 = 73,                          // SELECT3
        S_INT = 74,                              // INT
        S_FLOAT = 75,                            // FLOAT
        S_LAMBDA = 76,                           // LAMBDA
        S_WIRE = 77,                             // WIRE
        S_CUT = 78,                              // CUT
        S_ENDDEF = 79,                           // ENDDEF
        S_VIRG = 80,                             // VIRG
        S_LPAR = 81,                             // LPAR
        S_RPAR = 82,                             // RPAR
        S_LBRAQ = 83,                            // LBRAQ
        S_RBRAQ = 84,                            // RBRAQ
        S_LCROC = 85,                            // LCROC
        S_RCROC = 86,                            // RCROC
        S_WHERE = 87,                            // WHERE
        S_DEF = 88,                              // DEF
        S_IMPORT = 89,                           // IMPORT
        S_COMPONENT = 90,                        // COMPONENT
        S_LIBRARY = 91,                          // LIBRARY
        S_ENVIRONMENT = 92,                      // ENVIRONMENT
        S_WAVEFORM = 93,                         // WAVEFORM
        S_ROUTE = 94,                            // ROUTE
        S_ENABLE = 95,                           // ENABLE
        S_CONTROL = 96,                          // CONTROL
        S_ITERATE_PARALLEL = 97,                 // ITERATE_PARALLEL
        S_ISEQ = 98,                             // ISEQ
        S_ISUM = 99,                             // ISUM
        S_IPROD = 100,                           // IPROD
        S_INPUTS = 101,                          // INPUTS
        S_OUTPUTS = 102,                         // OUTPUTS
        S_STRING = 103,                          // STRING
        S_TAGSTRING = 104,                       // TAGSTRING
        S_IDENT = 105,                           // IDENT
        S_EXTRA = 106,                           // EXTRA
        S_DECLARE = 107,                         // DECLARE
        S_CASE = 108,                            // CASE
        S_ARROW = 109,                           // ARROW
        S_ASSERTBOUNDS = 110,                    // ASSERTBOUNDS
        S_LOWEST = 111,                          // LOWEST
        S_HIGHEST = 112,                         // HIGHEST
        S_FLOATMODE = 113,                       // FLOATMODE
        S_DOUBLEMODE = 114,                      // DOUBLEMODE
        S_QUADMODE = 115,                        // QUADMODE
        S_FIXEDPOINTMODE = 116,                  // FIXEDPOINTMODE
        S_BDOC = 117,                            // BDOC
        S_EDOC = 118,                            // EDOC
        S_BEQN = 119,                            // BEQN
        S_EEQN = 120,                            // EEQN
        S_BDGM = 121,                            // BDGM
        S_EDGM = 122,                            // EDGM
        S_BLST = 123,                            // BLST
        S_ELST = 124,                            // ELST
        S_BMETADATA = 125,                       // BMETADATA
        S_EMETADATA = 126,                       // EMETADATA
        S_DOCCHAR = 127,                         // DOCCHAR
        S_NOTICE = 128,                          // NOTICE
        S_LISTING = 129,                         // LISTING
        S_LSTTRUE = 130,                         // LSTTRUE
        S_LSTFALSE = 131,                        // LSTFALSE
        S_LSTDEPENDENCIES = 132,                 // LSTDEPENDENCIES
        S_LSTMDOCTAGS = 133,                     // LSTMDOCTAGS
        S_LSTDISTRIBUTED = 134,                  // LSTDISTRIBUTED
        S_LSTEQ = 135,                           // LSTEQ
        S_LSTQ = 136,                            // LSTQ
        S_ENDL = 137,                            // ENDL
        S_YYACCEPT = 138,                        // $accept
        S_program = 139,                         // program
        S_doc = 140,                             // doc
        S_141_doc_text = 141,                    // doc.text
        S_142_doc_equation = 142,                // doc.equation
        S_143_doc_diagram = 143,                 // doc.diagram
        S_144_doc_notice = 144,                  // doc.notice
        S_145_doc_metadata = 145,                // doc.metadata
        S_146_doc_list = 146,                    // doc.list
        S_147_doc_attribute_list = 147,          // doc.attribute.list
        S_148_doc_attribute_definition = 148,    // doc.attribute.definition
        S_149_doc_attribute_value = 149,         // doc.attribute.value
        S_expression = 150,                      // expression
        S_151_expression_component = 151,        // expression.component
        S_152_expression_composition = 152,      // expression.composition
        S_153_expression_composition_parallel = 153, // expression.composition.parallel
        S_154_expression_composition_serial = 154, // expression.composition.serial
        S_155_expression_composition_mix = 155,  // expression.composition.mix
        S_156_expression_composition_recursive = 156, // expression.composition.recursive
        S_157_expression_composition_sequence = 157, // expression.composition.sequence
        S_158_expression_composition_split = 158, // expression.composition.split
        S_159_expression_environment = 159,      // expression.environment
        S_160_expression_infix = 160,            // expression.infix
        S_161_expression_infix_definitions_substitution = 161, // expression.infix.definitions.substitution
        S_162_expression_infix_environment_access = 162, // expression.infix.environment.access
        S_163_expression_infix_math = 163,       // expression.infix.math
        S_164_expression_infix_math_algebra = 164, // expression.infix.math.algebra
        S_165_expression_infix_math_comparison = 165, // expression.infix.math.comparison
        S_166_expression_infix_math_logic = 166, // expression.infix.math.logic
        S_167_expression_infix_math_shift = 167, // expression.infix.math.shift
        S_168_expression_infix_prefix = 168,     // expression.infix.prefix
        S_169_expression_infix_signal_delay = 169, // expression.infix.signal.delay
        S_170_expression_iterate_parallel = 170, // expression.iterate.parallel
        S_171_expression_iterate_sequence = 171, // expression.iterate.sequence
        S_172_expression_iterate_sum = 172,      // expression.iterate.sum
        S_173_expression_iterate_product = 173,  // expression.iterate.product
        S_174_expression_lambda = 174,           // expression.lambda
        S_175_expression_lambda_params = 175,    // expression.lambda.params
        S_176_expression_lambda_params_start = 176, // expression.lambda.params.start
        S_177_expression_lambda_params_append = 177, // expression.lambda.params.append
        S_178_expression_letrec = 178,           // expression.letrec
        S_179_expression_letrec_list = 179,      // expression.letrec.list
        S_180_expression_letrec_list_start = 180, // expression.letrec.list.start
        S_181_expression_letrec_list_append = 181, // expression.letrec.list.append
        S_182_expression_letrec_equation = 182,  // expression.letrec.equation
        S_183_expression_letrec_equation_name = 183, // expression.letrec.equation.name
        S_184_expression_library = 184,          // expression.library
        S_185_expression_math = 185,             // expression.math
        S_186_expression_math_comparison = 186,  // expression.math.comparison
        S_187_expression_math_rounding = 187,    // expression.math.rounding
        S_188_expression_math_signal = 188,      // expression.math.signal
        S_189_expression_math_signal_algebra = 189, // expression.math.signal.algebra
        S_190_expression_math_signal_shift = 190, // expression.math.signal.shift
        S_191_expression_math_signal_power = 191, // expression.math.signal.power
        S_192_expression_math_scalar = 192,      // expression.math.scalar
        S_193_expression_math_trigonometry = 193, // expression.math.trigonometry
        S_194_expression_parenthesis = 194,      // expression.parenthesis
        S_195_expression_signal = 195,           // expression.signal
        S_196_expression_signal_control = 196,   // expression.signal.control
        S_197_expression_signal_delay = 197,     // expression.signal.delay
        S_198_expression_signal_logic = 198,     // expression.signal.logic
        S_primitive = 199,                       // primitive
        S_200_primitive_foreign = 200,           // primitive.foreign
        S_201_primitive_number = 201,            // primitive.number
        S_202_primitive_string_quoted = 202,     // primitive.string.quoted
        S_203_primitive_string_unquoted = 203,   // primitive.string.unquoted
        S_204_primitive_string_tag = 204,        // primitive.string.tag
        S_205_primitive_signal = 205,            // primitive.signal
        S_206_primitive_signal_input_implicit = 206, // primitive.signal.input.implicit
        S_207_primitive_signal_input_terminate = 207, // primitive.signal.input.terminate
        S_208_primitive_type = 208,              // primitive.type
        S_209_primitive_type_number = 209,       // primitive.type.number
        S_210_primitive_type_number_int = 210,   // primitive.type.number.int
        S_211_primitive_type_number_float = 211, // primitive.type.number.float
        S_212_primitive_type_any = 212,          // primitive.type.any
        S_213_primitive_type_number_list = 213,  // primitive.type.number.list
        S_214_primitive_type_number_list_member = 214, // primitive.type.number.list.member
        S_215_primitive_type_number_list_start = 215, // primitive.type.number.list.start
        S_216_primitive_type_number_list_append = 216, // primitive.type.number.list.append
        S_217_primitive_signal_route = 217,      // primitive.signal.route
        S_218_primitive_signal_route_implied_outputs = 218, // primitive.signal.route.implied.outputs
        S_219_primitive_signal_route_implied_connections = 219, // primitive.signal.route.implied.connections
        S_220_primitive_signal_route_explicit = 220, // primitive.signal.route.explicit
        S_221_primitive_signal_source = 221,     // primitive.signal.source
        S_222_primitive_signal_source_table = 222, // primitive.signal.source.table
        S_223_primitive_signal_source_soundfile = 223, // primitive.signal.source.soundfile
        S_224_primitive_signal_source_waveform = 224, // primitive.signal.source.waveform
        S_225_primitive_type_list = 225,         // primitive.type.list
        S_226_primitive_type_list_start = 226,   // primitive.type.list.start
        S_227_primitive_type_list_append = 227,  // primitive.type.list.append
        S_228_primitive_ui = 228,                // primitive.ui
        S_229_primitive_ui_button = 229,         // primitive.ui.button
        S_230_primitive_ui_checkbox = 230,       // primitive.ui.checkbox
        S_231_primitive_ui_vslider = 231,        // primitive.ui.vslider
        S_232_primitive_ui_hslider = 232,        // primitive.ui.hslider
        S_233_primitive_ui_nentry = 233,         // primitive.ui.nentry
        S_234_primitive_ui_vgroup = 234,         // primitive.ui.vgroup
        S_235_primitive_ui_hgroup = 235,         // primitive.ui.hgroup
        S_236_primitive_ui_tgroup = 236,         // primitive.ui.tgroup
        S_237_primitive_ui_vbargraph = 237,      // primitive.ui.vbargraph
        S_238_primitive_ui_hbargraph = 238,      // primitive.ui.hbargraph
        S_239_primitive_foreign_function = 239,  // primitive.foreign.function
        S_240_primitive_foreign_function_signature = 240, // primitive.foreign.function.signature
        S_241_primitive_foreign_constant = 241,  // primitive.foreign.constant
        S_242_primitive_foreign_variable = 242,  // primitive.foreign.variable
        S_243_primitive_signal_inputs = 243,     // primitive.signal.inputs
        S_244_primitive_signal_outputs = 244,    // primitive.signal.outputs
        S_statement = 245,                       // statement
        S_246_statement_definition = 246,        // statement.definition
        S_247_statement_definition_function_incomplete = 247, // statement.definition.function.incomplete
        S_248_statement_definition_function = 248, // statement.definition.function
        S_249_statement_definition_assignment = 249, // statement.definition.assignment
        S_250_statement_definition_with = 250,   // statement.definition.with
        S_251_statement_definition_error = 251,  // statement.definition.error
        S_252_statement_definition_list = 252,   // statement.definition.list
        S_253_statement_definition_list_start = 253, // statement.definition.list.start
        S_254_statement_definition_list_start_qualified = 254, // statement.definition.list.start.qualified
        S_255_statement_definition_list_append = 255, // statement.definition.list.append
        S_256_statement_definition_list_append_qualified = 256, // statement.definition.list.append.qualified
        S_257_statement_declare_metadata = 257,  // statement.declare.metadata
        S_258_statement_declare_feature_metadata = 258, // statement.declare.feature.metadata
        S_259_statement_declare_doc = 259,       // statement.declare.doc
        S_260_statement_identifier = 260,        // statement.identifier
        S_261_statement_identifier_box = 261,    // statement.identifier.box
        S_262_statement_identifier_waveform = 262, // statement.identifier.waveform
        S_263_statement_import = 263,            // statement.import
        S_264_statement_list = 264,              // statement.list
        S_265_statement_list_start = 265,        // statement.list.start
        S_266_statement_list_start_qualified = 266, // statement.list.start.qualified
        S_267_statement_list_append = 267,       // statement.list.append
        S_268_statement_list_append_qualified = 268, // statement.list.append.qualified
        S_269_statement_math_precision = 269,    // statement.math.precision
        S_270_statement_math_precision_list = 270, // statement.math.precision.list
        S_271_statement_math_precision_list_start = 271, // statement.math.precision.list.start
        S_272_statement_math_precision_list_append = 272, // statement.math.precision.list.append
        S_273_statement_signal_pattern_rule = 273, // statement.signal.pattern.rule
        S_274_statement_signal_pattern_rule_list = 274, // statement.signal.pattern.rule.list
        S_275_statement_signal_pattern_rule_list_start = 275, // statement.signal.pattern.rule.list.start
        S_276_statement_signal_pattern_rule_list_append = 276 // statement.signal.pattern.rule.list.append
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_154_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_155_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_156_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_157_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_158_expression_composition_split: // expression.composition.split
      case symbol_kind::S_159_expression_environment: // expression.environment
      case symbol_kind::S_160_expression_infix: // expression.infix
      case symbol_kind::S_161_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_162_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_163_expression_infix_math: // expression.infix.math
      case symbol_kind::S_164_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_165_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_166_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_167_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_168_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_169_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_170_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_171_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_172_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_173_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_174_expression_lambda: // expression.lambda
      case symbol_kind::S_175_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_176_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_177_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_178_expression_letrec: // expression.letrec
      case symbol_kind::S_179_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_180_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_181_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_182_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_183_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_184_expression_library: // expression.library
      case symbol_kind::S_185_expression_math: // expression.math
      case symbol_kind::S_186_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_187_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_188_expression_math_signal: // expression.math.signal
      case symbol_kind::S_189_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_190_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_191_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_192_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_193_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_194_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_195_expression_signal: // expression.signal
      case symbol_kind::S_196_expression_signal_control: // expression.signal.control
      case symbol_kind::S_197_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_198_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_200_primitive_foreign: // primitive.foreign
      case symbol_kind::S_201_primitive_number: // primitive.number
      case symbol_kind::S_202_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_203_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_204_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_205_primitive_signal: // primitive.signal
      case symbol_kind::S_206_primitive_signal_input_implicit: // primitive.signal.input.implicit
      case symbol_kind::S_207_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_208_primitive_type: // primitive.type
      case symbol_kind::S_209_primitive_type_number: // primitive.type.number
      case symbol_kind::S_210_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_211_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_212_primitive_type_any: // primitive.type.any
      case symbol_kind::S_213_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_214_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_215_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_216_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_219_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_220_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_221_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_222_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_223_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_224_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_225_primitive_type_list: // primitive.type.list
      case symbol_kind::S_226_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_227_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_228_primitive_ui: // primitive.ui
      case symbol_kind::S_229_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_230_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_231_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_232_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_233_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_234_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_235_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_236_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_237_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_238_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_239_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_240_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_241_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_242_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_243_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_244_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_246_statement_definition: // statement.definition
      case symbol_kind::S_247_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_248_statement_definition_function: // statement.definition.function
      case symbol_kind::S_249_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_250_statement_definition_with: // statement.definition.with
      case symbol_kind::S_251_statement_definition_error: // statement.definition.error
      case symbol_kind::S_252_statement_definition_list: // statement.definition.list
      case symbol_kind::S_253_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_254_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_255_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_256_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_257_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_258_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_259_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_260_statement_identifier: // statement.identifier
      case symbol_kind::S_261_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_262_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_263_statement_import: // statement.import
      case symbol_kind::S_264_statement_list: // statement.list
      case symbol_kind::S_265_statement_list_start: // statement.list.start
      case symbol_kind::S_266_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_267_statement_list_append: // statement.list.append
      case symbol_kind::S_268_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_274_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_275_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_276_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.move< Tree > (std::move (that.value));
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
      case symbol_kind::S_269_statement_math_precision: // statement.math.precision
      case symbol_kind::S_270_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_271_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_272_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
      case symbol_kind::S_SPLIT: // SPLIT
      case symbol_kind::S_MIX: // MIX
      case symbol_kind::S_SEQ: // SEQ
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_REC: // REC
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_XOR: // XOR
      case symbol_kind::S_LSH: // LSH
      case symbol_kind::S_RSH: // RSH
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_FDELAY: // FDELAY
      case symbol_kind::S_DELAY1: // DELAY1
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_MEM: // MEM
      case symbol_kind::S_PREFIX: // PREFIX
      case symbol_kind::S_INTCAST: // INTCAST
      case symbol_kind::S_FLOATCAST: // FLOATCAST
      case symbol_kind::S_ANYCAST: // ANYCAST
      case symbol_kind::S_FFUNCTION: // FFUNCTION
      case symbol_kind::S_FCONSTANT: // FCONSTANT
      case symbol_kind::S_FVARIABLE: // FVARIABLE
      case symbol_kind::S_BUTTON: // BUTTON
      case symbol_kind::S_CHECKBOX: // CHECKBOX
      case symbol_kind::S_VSLIDER: // VSLIDER
      case symbol_kind::S_HSLIDER: // HSLIDER
      case symbol_kind::S_NENTRY: // NENTRY
      case symbol_kind::S_VGROUP: // VGROUP
      case symbol_kind::S_HGROUP: // HGROUP
      case symbol_kind::S_TGROUP: // TGROUP
      case symbol_kind::S_HBARGRAPH: // HBARGRAPH
      case symbol_kind::S_VBARGRAPH: // VBARGRAPH
      case symbol_kind::S_SOUNDFILE: // SOUNDFILE
      case symbol_kind::S_ATTACH: // ATTACH
      case symbol_kind::S_ACOS: // ACOS
      case symbol_kind::S_ASIN: // ASIN
      case symbol_kind::S_ATAN: // ATAN
      case symbol_kind::S_ATAN2: // ATAN2
      case symbol_kind::S_COS: // COS
      case symbol_kind::S_SIN: // SIN
      case symbol_kind::S_TAN: // TAN
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_LOG: // LOG
      case symbol_kind::S_LOG10: // LOG10
      case symbol_kind::S_POWFUN: // POWFUN
      case symbol_kind::S_SQRT: // SQRT
      case symbol_kind::S_ABS: // ABS
      case symbol_kind::S_MIN: // MIN
      case symbol_kind::S_MAX: // MAX
      case symbol_kind::S_FMOD: // FMOD
      case symbol_kind::S_REMAINDER: // REMAINDER
      case symbol_kind::S_FLOOR: // FLOOR
      case symbol_kind::S_CEIL: // CEIL
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RDTBL: // RDTBL
      case symbol_kind::S_RWTBL: // RWTBL
      case symbol_kind::S_SELECT2: // SELECT2
      case symbol_kind::S_SELECT3: // SELECT3
      case symbol_kind::S_LAMBDA: // LAMBDA
      case symbol_kind::S_WIRE: // WIRE
      case symbol_kind::S_CUT: // CUT
      case symbol_kind::S_ENDDEF: // ENDDEF
      case symbol_kind::S_VIRG: // VIRG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_LBRAQ: // LBRAQ
      case symbol_kind::S_RBRAQ: // RBRAQ
      case symbol_kind::S_LCROC: // LCROC
      case symbol_kind::S_RCROC: // RCROC
      case symbol_kind::S_WHERE: // WHERE
      case symbol_kind::S_DEF: // DEF
      case symbol_kind::S_IMPORT: // IMPORT
      case symbol_kind::S_COMPONENT: // COMPONENT
      case symbol_kind::S_LIBRARY: // LIBRARY
      case symbol_kind::S_ENVIRONMENT: // ENVIRONMENT
      case symbol_kind::S_WAVEFORM: // WAVEFORM
      case symbol_kind::S_ROUTE: // ROUTE
      case symbol_kind::S_ENABLE: // ENABLE
      case symbol_kind::S_CONTROL: // CONTROL
      case symbol_kind::S_ITERATE_PARALLEL: // ITERATE_PARALLEL
      case symbol_kind::S_ISEQ: // ISEQ
      case symbol_kind::S_ISUM: // ISUM
      case symbol_kind::S_IPROD: // IPROD
      case symbol_kind::S_INPUTS: // INPUTS
      case symbol_kind::S_OUTPUTS: // OUTPUTS
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TAGSTRING: // TAGSTRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_EXTRA: // EXTRA
      case symbol_kind::S_DECLARE: // DECLARE
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_ARROW: // ARROW
      case symbol_kind::S_ASSERTBOUNDS: // ASSERTBOUNDS
      case symbol_kind::S_LOWEST: // LOWEST
      case symbol_kind::S_HIGHEST: // HIGHEST
      case symbol_kind::S_BDOC: // BDOC
      case symbol_kind::S_EDOC: // EDOC
      case symbol_kind::S_BEQN: // BEQN
      case symbol_kind::S_EEQN: // EEQN
      case symbol_kind::S_BDGM: // BDGM
      case symbol_kind::S_EDGM: // EDGM
      case symbol_kind::S_BLST: // BLST
      case symbol_kind::S_ELST: // ELST
      case symbol_kind::S_BMETADATA: // BMETADATA
      case symbol_kind::S_EMETADATA: // EMETADATA
      case symbol_kind::S_DOCCHAR: // DOCCHAR
      case symbol_kind::S_NOTICE: // NOTICE
      case symbol_kind::S_LISTING: // LISTING
      case symbol_kind::S_LSTTRUE: // LSTTRUE
      case symbol_kind::S_LSTFALSE: // LSTFALSE
      case symbol_kind::S_LSTDEPENDENCIES: // LSTDEPENDENCIES
      case symbol_kind::S_LSTMDOCTAGS: // LSTMDOCTAGS
      case symbol_kind::S_LSTDISTRIBUTED: // LSTDISTRIBUTED
      case symbol_kind::S_LSTEQ: // LSTEQ
      case symbol_kind::S_LSTQ: // LSTQ
      case symbol_kind::S_ENDL: // ENDL
      case symbol_kind::S_141_doc_text: // doc.text
        value.move< std::string > (std::move (that.value));
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
      basic_symbol (typename Base::kind_type t, Tree&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Tree& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_154_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_155_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_156_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_157_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_158_expression_composition_split: // expression.composition.split
      case symbol_kind::S_159_expression_environment: // expression.environment
      case symbol_kind::S_160_expression_infix: // expression.infix
      case symbol_kind::S_161_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_162_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_163_expression_infix_math: // expression.infix.math
      case symbol_kind::S_164_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_165_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_166_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_167_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_168_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_169_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_170_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_171_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_172_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_173_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_174_expression_lambda: // expression.lambda
      case symbol_kind::S_175_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_176_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_177_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_178_expression_letrec: // expression.letrec
      case symbol_kind::S_179_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_180_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_181_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_182_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_183_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_184_expression_library: // expression.library
      case symbol_kind::S_185_expression_math: // expression.math
      case symbol_kind::S_186_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_187_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_188_expression_math_signal: // expression.math.signal
      case symbol_kind::S_189_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_190_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_191_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_192_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_193_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_194_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_195_expression_signal: // expression.signal
      case symbol_kind::S_196_expression_signal_control: // expression.signal.control
      case symbol_kind::S_197_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_198_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_200_primitive_foreign: // primitive.foreign
      case symbol_kind::S_201_primitive_number: // primitive.number
      case symbol_kind::S_202_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_203_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_204_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_205_primitive_signal: // primitive.signal
      case symbol_kind::S_206_primitive_signal_input_implicit: // primitive.signal.input.implicit
      case symbol_kind::S_207_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_208_primitive_type: // primitive.type
      case symbol_kind::S_209_primitive_type_number: // primitive.type.number
      case symbol_kind::S_210_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_211_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_212_primitive_type_any: // primitive.type.any
      case symbol_kind::S_213_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_214_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_215_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_216_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_219_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_220_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_221_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_222_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_223_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_224_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_225_primitive_type_list: // primitive.type.list
      case symbol_kind::S_226_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_227_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_228_primitive_ui: // primitive.ui
      case symbol_kind::S_229_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_230_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_231_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_232_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_233_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_234_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_235_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_236_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_237_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_238_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_239_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_240_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_241_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_242_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_243_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_244_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_246_statement_definition: // statement.definition
      case symbol_kind::S_247_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_248_statement_definition_function: // statement.definition.function
      case symbol_kind::S_249_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_250_statement_definition_with: // statement.definition.with
      case symbol_kind::S_251_statement_definition_error: // statement.definition.error
      case symbol_kind::S_252_statement_definition_list: // statement.definition.list
      case symbol_kind::S_253_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_254_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_255_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_256_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_257_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_258_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_259_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_260_statement_identifier: // statement.identifier
      case symbol_kind::S_261_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_262_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_263_statement_import: // statement.import
      case symbol_kind::S_264_statement_list: // statement.list
      case symbol_kind::S_265_statement_list_start: // statement.list.start
      case symbol_kind::S_266_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_267_statement_list_append: // statement.list.append
      case symbol_kind::S_268_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_274_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_275_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_276_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.template destroy< Tree > ();
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< float > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
      case symbol_kind::S_269_statement_math_precision: // statement.math.precision
      case symbol_kind::S_270_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_271_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_272_statement_math_precision_list_append: // statement.math.precision.list.append
        value.template destroy< int > ();
        break;

      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
      case symbol_kind::S_SPLIT: // SPLIT
      case symbol_kind::S_MIX: // MIX
      case symbol_kind::S_SEQ: // SEQ
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_REC: // REC
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_XOR: // XOR
      case symbol_kind::S_LSH: // LSH
      case symbol_kind::S_RSH: // RSH
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_FDELAY: // FDELAY
      case symbol_kind::S_DELAY1: // DELAY1
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_MEM: // MEM
      case symbol_kind::S_PREFIX: // PREFIX
      case symbol_kind::S_INTCAST: // INTCAST
      case symbol_kind::S_FLOATCAST: // FLOATCAST
      case symbol_kind::S_ANYCAST: // ANYCAST
      case symbol_kind::S_FFUNCTION: // FFUNCTION
      case symbol_kind::S_FCONSTANT: // FCONSTANT
      case symbol_kind::S_FVARIABLE: // FVARIABLE
      case symbol_kind::S_BUTTON: // BUTTON
      case symbol_kind::S_CHECKBOX: // CHECKBOX
      case symbol_kind::S_VSLIDER: // VSLIDER
      case symbol_kind::S_HSLIDER: // HSLIDER
      case symbol_kind::S_NENTRY: // NENTRY
      case symbol_kind::S_VGROUP: // VGROUP
      case symbol_kind::S_HGROUP: // HGROUP
      case symbol_kind::S_TGROUP: // TGROUP
      case symbol_kind::S_HBARGRAPH: // HBARGRAPH
      case symbol_kind::S_VBARGRAPH: // VBARGRAPH
      case symbol_kind::S_SOUNDFILE: // SOUNDFILE
      case symbol_kind::S_ATTACH: // ATTACH
      case symbol_kind::S_ACOS: // ACOS
      case symbol_kind::S_ASIN: // ASIN
      case symbol_kind::S_ATAN: // ATAN
      case symbol_kind::S_ATAN2: // ATAN2
      case symbol_kind::S_COS: // COS
      case symbol_kind::S_SIN: // SIN
      case symbol_kind::S_TAN: // TAN
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_LOG: // LOG
      case symbol_kind::S_LOG10: // LOG10
      case symbol_kind::S_POWFUN: // POWFUN
      case symbol_kind::S_SQRT: // SQRT
      case symbol_kind::S_ABS: // ABS
      case symbol_kind::S_MIN: // MIN
      case symbol_kind::S_MAX: // MAX
      case symbol_kind::S_FMOD: // FMOD
      case symbol_kind::S_REMAINDER: // REMAINDER
      case symbol_kind::S_FLOOR: // FLOOR
      case symbol_kind::S_CEIL: // CEIL
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RDTBL: // RDTBL
      case symbol_kind::S_RWTBL: // RWTBL
      case symbol_kind::S_SELECT2: // SELECT2
      case symbol_kind::S_SELECT3: // SELECT3
      case symbol_kind::S_LAMBDA: // LAMBDA
      case symbol_kind::S_WIRE: // WIRE
      case symbol_kind::S_CUT: // CUT
      case symbol_kind::S_ENDDEF: // ENDDEF
      case symbol_kind::S_VIRG: // VIRG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_LBRAQ: // LBRAQ
      case symbol_kind::S_RBRAQ: // RBRAQ
      case symbol_kind::S_LCROC: // LCROC
      case symbol_kind::S_RCROC: // RCROC
      case symbol_kind::S_WHERE: // WHERE
      case symbol_kind::S_DEF: // DEF
      case symbol_kind::S_IMPORT: // IMPORT
      case symbol_kind::S_COMPONENT: // COMPONENT
      case symbol_kind::S_LIBRARY: // LIBRARY
      case symbol_kind::S_ENVIRONMENT: // ENVIRONMENT
      case symbol_kind::S_WAVEFORM: // WAVEFORM
      case symbol_kind::S_ROUTE: // ROUTE
      case symbol_kind::S_ENABLE: // ENABLE
      case symbol_kind::S_CONTROL: // CONTROL
      case symbol_kind::S_ITERATE_PARALLEL: // ITERATE_PARALLEL
      case symbol_kind::S_ISEQ: // ISEQ
      case symbol_kind::S_ISUM: // ISUM
      case symbol_kind::S_IPROD: // IPROD
      case symbol_kind::S_INPUTS: // INPUTS
      case symbol_kind::S_OUTPUTS: // OUTPUTS
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TAGSTRING: // TAGSTRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_EXTRA: // EXTRA
      case symbol_kind::S_DECLARE: // DECLARE
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_ARROW: // ARROW
      case symbol_kind::S_ASSERTBOUNDS: // ASSERTBOUNDS
      case symbol_kind::S_LOWEST: // LOWEST
      case symbol_kind::S_HIGHEST: // HIGHEST
      case symbol_kind::S_BDOC: // BDOC
      case symbol_kind::S_EDOC: // EDOC
      case symbol_kind::S_BEQN: // BEQN
      case symbol_kind::S_EEQN: // EEQN
      case symbol_kind::S_BDGM: // BDGM
      case symbol_kind::S_EDGM: // EDGM
      case symbol_kind::S_BLST: // BLST
      case symbol_kind::S_ELST: // ELST
      case symbol_kind::S_BMETADATA: // BMETADATA
      case symbol_kind::S_EMETADATA: // EMETADATA
      case symbol_kind::S_DOCCHAR: // DOCCHAR
      case symbol_kind::S_NOTICE: // NOTICE
      case symbol_kind::S_LISTING: // LISTING
      case symbol_kind::S_LSTTRUE: // LSTTRUE
      case symbol_kind::S_LSTFALSE: // LSTFALSE
      case symbol_kind::S_LSTDEPENDENCIES: // LSTDEPENDENCIES
      case symbol_kind::S_LSTMDOCTAGS: // LSTMDOCTAGS
      case symbol_kind::S_LSTDISTRIBUTED: // LSTDISTRIBUTED
      case symbol_kind::S_LSTEQ: // LSTEQ
      case symbol_kind::S_LSTQ: // LSTQ
      case symbol_kind::S_ENDL: // ENDL
      case symbol_kind::S_141_doc_text: // doc.text
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return AbstractImplementation::symbol_name (this->kind ());
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
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::FAUST_ENDOFINPUT
                   || (token::FAUST_YYerror <= tok && tok <= token::FAUST_YYUNDEF));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const float& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::FAUST_FLOAT);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::FAUST_INT
                   || (token::FAUST_FLOATMODE <= tok && tok <= token::FAUST_FIXEDPOINTMODE));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::FAUST_WITH <= tok && tok <= token::FAUST_SELECT3)
                   || (token::FAUST_LAMBDA <= tok && tok <= token::FAUST_HIGHEST)
                   || (token::FAUST_BDOC <= tok && tok <= token::FAUST_ENDL));
#endif
      }
    };

    /// Build a parser object.
    AbstractImplementation (Implementation& self_yyarg);
    virtual ~AbstractImplementation ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    AbstractImplementation (const AbstractImplementation&) = delete;
    /// Non copyable.
    AbstractImplementation& operator= (const AbstractImplementation&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
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
      make_ENDOFINPUT (location_type l)
      {
        return symbol_type (token::FAUST_ENDOFINPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_ENDOFINPUT (const location_type& l)
      {
        return symbol_type (token::FAUST_ENDOFINPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::FAUST_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::FAUST_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::FAUST_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::FAUST_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WITH (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_WITH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WITH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_WITH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LETREC (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LETREC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LETREC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LETREC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPLIT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SPLIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SPLIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SPLIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIX (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_MIX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MIX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_MIX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SEQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SEQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REC (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_REC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_REC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_GT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_GT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_GE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_GE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_NE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_NE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ADD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ADD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SUB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUB (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SUB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_MUL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MUL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_MUL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_DIV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DIV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_MOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_MOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_XOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_XOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_XOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSH (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSH (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RSH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RSH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POWOP (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_POWOP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_POWOP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_POWOP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FDELAY (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FDELAY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FDELAY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FDELAY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELAY1 (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_DELAY1, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DELAY1 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DELAY1, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEM (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_MEM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MEM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_MEM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIX (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_PREFIX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_PREFIX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTCAST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_INTCAST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTCAST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_INTCAST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOATCAST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FLOATCAST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOATCAST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FLOATCAST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANYCAST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ANYCAST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ANYCAST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ANYCAST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FFUNCTION (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FFUNCTION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FFUNCTION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FFUNCTION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FCONSTANT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FCONSTANT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FCONSTANT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FCONSTANT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FVARIABLE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FVARIABLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FVARIABLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FVARIABLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BUTTON (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_BUTTON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BUTTON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_BUTTON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHECKBOX (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_CHECKBOX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHECKBOX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_CHECKBOX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VSLIDER (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_VSLIDER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VSLIDER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_VSLIDER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HSLIDER (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_HSLIDER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HSLIDER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_HSLIDER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NENTRY (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_NENTRY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NENTRY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_NENTRY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VGROUP (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_VGROUP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VGROUP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_VGROUP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HGROUP (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_HGROUP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HGROUP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_HGROUP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TGROUP (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_TGROUP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TGROUP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_TGROUP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HBARGRAPH (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_HBARGRAPH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HBARGRAPH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_HBARGRAPH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VBARGRAPH (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_VBARGRAPH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VBARGRAPH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_VBARGRAPH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOUNDFILE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SOUNDFILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SOUNDFILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SOUNDFILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATTACH (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ATTACH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATTACH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ATTACH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ACOS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ACOS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ACOS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ACOS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASIN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ASIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ASIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATAN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ATAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ATAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATAN2 (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ATAN2, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATAN2 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ATAN2, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_COS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_COS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_TAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_TAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXP (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EXP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EXP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOG (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LOG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOG (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LOG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOG10 (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LOG10, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOG10 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LOG10, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POWFUN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_POWFUN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_POWFUN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_POWFUN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SQRT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SQRT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SQRT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SQRT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ABS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ABS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ABS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ABS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_MIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_MIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_MAX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MAX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_MAX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FMOD (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FMOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FMOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FMOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REMAINDER (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_REMAINDER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REMAINDER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_REMAINDER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOOR (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_FLOOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FLOOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CEIL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_CEIL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CEIL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_CEIL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RINT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RINT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RINT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RINT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RDTBL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RDTBL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RDTBL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RDTBL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RWTBL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RWTBL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RWTBL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RWTBL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELECT2 (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SELECT2, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SELECT2 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SELECT2, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELECT3 (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_SELECT3, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SELECT3 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_SELECT3, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (int v, location_type l)
      {
        return symbol_type (token::FAUST_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const int& v, const location_type& l)
      {
        return symbol_type (token::FAUST_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (float v, location_type l)
      {
        return symbol_type (token::FAUST_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const float& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAMBDA (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LAMBDA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LAMBDA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LAMBDA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WIRE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_WIRE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WIRE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_WIRE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CUT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_CUT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CUT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_CUT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDDEF (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ENDDEF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENDDEF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ENDDEF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VIRG (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_VIRG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VIRG (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_VIRG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAR (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LPAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LPAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAR (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RPAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RPAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRAQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LBRAQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRAQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LBRAQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRAQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RBRAQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRAQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RBRAQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCROC (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LCROC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LCROC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LCROC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCROC (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_RCROC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RCROC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_RCROC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHERE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_WHERE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHERE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_WHERE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEF (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_DEF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DEF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPORT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_IMPORT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IMPORT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_IMPORT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPONENT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_COMPONENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMPONENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_COMPONENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIBRARY (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LIBRARY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LIBRARY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LIBRARY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENVIRONMENT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ENVIRONMENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENVIRONMENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ENVIRONMENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WAVEFORM (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_WAVEFORM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WAVEFORM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_WAVEFORM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROUTE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ROUTE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ROUTE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ROUTE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENABLE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ENABLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENABLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ENABLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTROL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_CONTROL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONTROL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_CONTROL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ITERATE_PARALLEL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ITERATE_PARALLEL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ITERATE_PARALLEL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ITERATE_PARALLEL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ISEQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ISEQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ISEQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ISEQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ISUM (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ISUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ISUM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ISUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IPROD (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_IPROD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IPROD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_IPROD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUTS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_INPUTS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INPUTS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_INPUTS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUTS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_OUTPUTS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUTS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_OUTPUTS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAGSTRING (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_TAGSTRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TAGSTRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_TAGSTRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_IDENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_IDENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTRA (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EXTRA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXTRA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EXTRA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECLARE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_DECLARE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DECLARE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DECLARE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_CASE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_CASE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ARROW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ARROW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSERTBOUNDS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ASSERTBOUNDS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSERTBOUNDS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ASSERTBOUNDS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWEST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LOWEST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOWEST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LOWEST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HIGHEST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_HIGHEST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HIGHEST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_HIGHEST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOATMODE (int v, location_type l)
      {
        return symbol_type (token::FAUST_FLOATMODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOATMODE (const int& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FLOATMODE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLEMODE (int v, location_type l)
      {
        return symbol_type (token::FAUST_DOUBLEMODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLEMODE (const int& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DOUBLEMODE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUADMODE (int v, location_type l)
      {
        return symbol_type (token::FAUST_QUADMODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QUADMODE (const int& v, const location_type& l)
      {
        return symbol_type (token::FAUST_QUADMODE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIXEDPOINTMODE (int v, location_type l)
      {
        return symbol_type (token::FAUST_FIXEDPOINTMODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FIXEDPOINTMODE (const int& v, const location_type& l)
      {
        return symbol_type (token::FAUST_FIXEDPOINTMODE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BDOC (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_BDOC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BDOC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_BDOC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EDOC (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EDOC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EDOC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EDOC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BEQN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_BEQN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BEQN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_BEQN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EEQN (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EEQN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EEQN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EEQN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BDGM (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_BDGM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BDGM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_BDGM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EDGM (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EDGM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EDGM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EDGM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BLST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_BLST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BLST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_BLST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELST (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ELST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ELST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BMETADATA (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_BMETADATA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BMETADATA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_BMETADATA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EMETADATA (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_EMETADATA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EMETADATA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_EMETADATA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOCCHAR (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_DOCCHAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOCCHAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_DOCCHAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOTICE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_NOTICE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOTICE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_NOTICE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LISTING (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LISTING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LISTING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LISTING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTTRUE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTTRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTTRUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTTRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTFALSE (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTFALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTFALSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTFALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTDEPENDENCIES (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTDEPENDENCIES, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTDEPENDENCIES (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTDEPENDENCIES, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTMDOCTAGS (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTMDOCTAGS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTMDOCTAGS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTMDOCTAGS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTDISTRIBUTED (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTDISTRIBUTED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTDISTRIBUTED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTDISTRIBUTED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTEQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTEQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTEQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTEQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSTQ (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_LSTQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSTQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_LSTQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDL (std::string v, location_type l)
      {
        return symbol_type (token::FAUST_ENDL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENDL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FAUST_ENDL, v, l);
      }
#endif


    class context
    {
    public:
      context (const AbstractImplementation& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const AbstractImplementation& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    AbstractImplementation (const AbstractImplementation&);
    /// Non copyable.
    AbstractImplementation& operator= (const AbstractImplementation&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

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

    static const short yypact_ninf_;
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
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const short yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const short yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
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
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


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
      yylast_ = 948,     ///< Last index in yytable_.
      yynnts_ = 139,  ///< Number of nonterminal symbols.
      yyfinal_ = 48 ///< Termination state number.
    };


    // User arguments.
    Implementation& self;

  };

  inline
  AbstractImplementation::symbol_kind_type
  AbstractImplementation::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  AbstractImplementation::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_154_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_155_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_156_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_157_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_158_expression_composition_split: // expression.composition.split
      case symbol_kind::S_159_expression_environment: // expression.environment
      case symbol_kind::S_160_expression_infix: // expression.infix
      case symbol_kind::S_161_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_162_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_163_expression_infix_math: // expression.infix.math
      case symbol_kind::S_164_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_165_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_166_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_167_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_168_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_169_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_170_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_171_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_172_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_173_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_174_expression_lambda: // expression.lambda
      case symbol_kind::S_175_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_176_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_177_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_178_expression_letrec: // expression.letrec
      case symbol_kind::S_179_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_180_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_181_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_182_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_183_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_184_expression_library: // expression.library
      case symbol_kind::S_185_expression_math: // expression.math
      case symbol_kind::S_186_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_187_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_188_expression_math_signal: // expression.math.signal
      case symbol_kind::S_189_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_190_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_191_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_192_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_193_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_194_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_195_expression_signal: // expression.signal
      case symbol_kind::S_196_expression_signal_control: // expression.signal.control
      case symbol_kind::S_197_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_198_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_200_primitive_foreign: // primitive.foreign
      case symbol_kind::S_201_primitive_number: // primitive.number
      case symbol_kind::S_202_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_203_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_204_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_205_primitive_signal: // primitive.signal
      case symbol_kind::S_206_primitive_signal_input_implicit: // primitive.signal.input.implicit
      case symbol_kind::S_207_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_208_primitive_type: // primitive.type
      case symbol_kind::S_209_primitive_type_number: // primitive.type.number
      case symbol_kind::S_210_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_211_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_212_primitive_type_any: // primitive.type.any
      case symbol_kind::S_213_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_214_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_215_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_216_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_219_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_220_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_221_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_222_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_223_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_224_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_225_primitive_type_list: // primitive.type.list
      case symbol_kind::S_226_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_227_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_228_primitive_ui: // primitive.ui
      case symbol_kind::S_229_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_230_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_231_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_232_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_233_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_234_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_235_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_236_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_237_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_238_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_239_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_240_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_241_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_242_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_243_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_244_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_246_statement_definition: // statement.definition
      case symbol_kind::S_247_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_248_statement_definition_function: // statement.definition.function
      case symbol_kind::S_249_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_250_statement_definition_with: // statement.definition.with
      case symbol_kind::S_251_statement_definition_error: // statement.definition.error
      case symbol_kind::S_252_statement_definition_list: // statement.definition.list
      case symbol_kind::S_253_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_254_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_255_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_256_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_257_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_258_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_259_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_260_statement_identifier: // statement.identifier
      case symbol_kind::S_261_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_262_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_263_statement_import: // statement.import
      case symbol_kind::S_264_statement_list: // statement.list
      case symbol_kind::S_265_statement_list_start: // statement.list.start
      case symbol_kind::S_266_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_267_statement_list_append: // statement.list.append
      case symbol_kind::S_268_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_274_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_275_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_276_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.copy< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
      case symbol_kind::S_269_statement_math_precision: // statement.math.precision
      case symbol_kind::S_270_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_271_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_272_statement_math_precision_list_append: // statement.math.precision.list.append
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
      case symbol_kind::S_SPLIT: // SPLIT
      case symbol_kind::S_MIX: // MIX
      case symbol_kind::S_SEQ: // SEQ
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_REC: // REC
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_XOR: // XOR
      case symbol_kind::S_LSH: // LSH
      case symbol_kind::S_RSH: // RSH
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_FDELAY: // FDELAY
      case symbol_kind::S_DELAY1: // DELAY1
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_MEM: // MEM
      case symbol_kind::S_PREFIX: // PREFIX
      case symbol_kind::S_INTCAST: // INTCAST
      case symbol_kind::S_FLOATCAST: // FLOATCAST
      case symbol_kind::S_ANYCAST: // ANYCAST
      case symbol_kind::S_FFUNCTION: // FFUNCTION
      case symbol_kind::S_FCONSTANT: // FCONSTANT
      case symbol_kind::S_FVARIABLE: // FVARIABLE
      case symbol_kind::S_BUTTON: // BUTTON
      case symbol_kind::S_CHECKBOX: // CHECKBOX
      case symbol_kind::S_VSLIDER: // VSLIDER
      case symbol_kind::S_HSLIDER: // HSLIDER
      case symbol_kind::S_NENTRY: // NENTRY
      case symbol_kind::S_VGROUP: // VGROUP
      case symbol_kind::S_HGROUP: // HGROUP
      case symbol_kind::S_TGROUP: // TGROUP
      case symbol_kind::S_HBARGRAPH: // HBARGRAPH
      case symbol_kind::S_VBARGRAPH: // VBARGRAPH
      case symbol_kind::S_SOUNDFILE: // SOUNDFILE
      case symbol_kind::S_ATTACH: // ATTACH
      case symbol_kind::S_ACOS: // ACOS
      case symbol_kind::S_ASIN: // ASIN
      case symbol_kind::S_ATAN: // ATAN
      case symbol_kind::S_ATAN2: // ATAN2
      case symbol_kind::S_COS: // COS
      case symbol_kind::S_SIN: // SIN
      case symbol_kind::S_TAN: // TAN
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_LOG: // LOG
      case symbol_kind::S_LOG10: // LOG10
      case symbol_kind::S_POWFUN: // POWFUN
      case symbol_kind::S_SQRT: // SQRT
      case symbol_kind::S_ABS: // ABS
      case symbol_kind::S_MIN: // MIN
      case symbol_kind::S_MAX: // MAX
      case symbol_kind::S_FMOD: // FMOD
      case symbol_kind::S_REMAINDER: // REMAINDER
      case symbol_kind::S_FLOOR: // FLOOR
      case symbol_kind::S_CEIL: // CEIL
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RDTBL: // RDTBL
      case symbol_kind::S_RWTBL: // RWTBL
      case symbol_kind::S_SELECT2: // SELECT2
      case symbol_kind::S_SELECT3: // SELECT3
      case symbol_kind::S_LAMBDA: // LAMBDA
      case symbol_kind::S_WIRE: // WIRE
      case symbol_kind::S_CUT: // CUT
      case symbol_kind::S_ENDDEF: // ENDDEF
      case symbol_kind::S_VIRG: // VIRG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_LBRAQ: // LBRAQ
      case symbol_kind::S_RBRAQ: // RBRAQ
      case symbol_kind::S_LCROC: // LCROC
      case symbol_kind::S_RCROC: // RCROC
      case symbol_kind::S_WHERE: // WHERE
      case symbol_kind::S_DEF: // DEF
      case symbol_kind::S_IMPORT: // IMPORT
      case symbol_kind::S_COMPONENT: // COMPONENT
      case symbol_kind::S_LIBRARY: // LIBRARY
      case symbol_kind::S_ENVIRONMENT: // ENVIRONMENT
      case symbol_kind::S_WAVEFORM: // WAVEFORM
      case symbol_kind::S_ROUTE: // ROUTE
      case symbol_kind::S_ENABLE: // ENABLE
      case symbol_kind::S_CONTROL: // CONTROL
      case symbol_kind::S_ITERATE_PARALLEL: // ITERATE_PARALLEL
      case symbol_kind::S_ISEQ: // ISEQ
      case symbol_kind::S_ISUM: // ISUM
      case symbol_kind::S_IPROD: // IPROD
      case symbol_kind::S_INPUTS: // INPUTS
      case symbol_kind::S_OUTPUTS: // OUTPUTS
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TAGSTRING: // TAGSTRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_EXTRA: // EXTRA
      case symbol_kind::S_DECLARE: // DECLARE
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_ARROW: // ARROW
      case symbol_kind::S_ASSERTBOUNDS: // ASSERTBOUNDS
      case symbol_kind::S_LOWEST: // LOWEST
      case symbol_kind::S_HIGHEST: // HIGHEST
      case symbol_kind::S_BDOC: // BDOC
      case symbol_kind::S_EDOC: // EDOC
      case symbol_kind::S_BEQN: // BEQN
      case symbol_kind::S_EEQN: // EEQN
      case symbol_kind::S_BDGM: // BDGM
      case symbol_kind::S_EDGM: // EDGM
      case symbol_kind::S_BLST: // BLST
      case symbol_kind::S_ELST: // ELST
      case symbol_kind::S_BMETADATA: // BMETADATA
      case symbol_kind::S_EMETADATA: // EMETADATA
      case symbol_kind::S_DOCCHAR: // DOCCHAR
      case symbol_kind::S_NOTICE: // NOTICE
      case symbol_kind::S_LISTING: // LISTING
      case symbol_kind::S_LSTTRUE: // LSTTRUE
      case symbol_kind::S_LSTFALSE: // LSTFALSE
      case symbol_kind::S_LSTDEPENDENCIES: // LSTDEPENDENCIES
      case symbol_kind::S_LSTMDOCTAGS: // LSTMDOCTAGS
      case symbol_kind::S_LSTDISTRIBUTED: // LSTDISTRIBUTED
      case symbol_kind::S_LSTEQ: // LSTEQ
      case symbol_kind::S_LSTQ: // LSTQ
      case symbol_kind::S_ENDL: // ENDL
      case symbol_kind::S_141_doc_text: // doc.text
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  AbstractImplementation::symbol_kind_type
  AbstractImplementation::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  AbstractImplementation::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  AbstractImplementation::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_154_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_155_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_156_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_157_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_158_expression_composition_split: // expression.composition.split
      case symbol_kind::S_159_expression_environment: // expression.environment
      case symbol_kind::S_160_expression_infix: // expression.infix
      case symbol_kind::S_161_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_162_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_163_expression_infix_math: // expression.infix.math
      case symbol_kind::S_164_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_165_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_166_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_167_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_168_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_169_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_170_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_171_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_172_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_173_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_174_expression_lambda: // expression.lambda
      case symbol_kind::S_175_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_176_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_177_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_178_expression_letrec: // expression.letrec
      case symbol_kind::S_179_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_180_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_181_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_182_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_183_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_184_expression_library: // expression.library
      case symbol_kind::S_185_expression_math: // expression.math
      case symbol_kind::S_186_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_187_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_188_expression_math_signal: // expression.math.signal
      case symbol_kind::S_189_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_190_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_191_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_192_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_193_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_194_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_195_expression_signal: // expression.signal
      case symbol_kind::S_196_expression_signal_control: // expression.signal.control
      case symbol_kind::S_197_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_198_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_200_primitive_foreign: // primitive.foreign
      case symbol_kind::S_201_primitive_number: // primitive.number
      case symbol_kind::S_202_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_203_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_204_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_205_primitive_signal: // primitive.signal
      case symbol_kind::S_206_primitive_signal_input_implicit: // primitive.signal.input.implicit
      case symbol_kind::S_207_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_208_primitive_type: // primitive.type
      case symbol_kind::S_209_primitive_type_number: // primitive.type.number
      case symbol_kind::S_210_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_211_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_212_primitive_type_any: // primitive.type.any
      case symbol_kind::S_213_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_214_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_215_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_216_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_219_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_220_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_221_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_222_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_223_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_224_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_225_primitive_type_list: // primitive.type.list
      case symbol_kind::S_226_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_227_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_228_primitive_ui: // primitive.ui
      case symbol_kind::S_229_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_230_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_231_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_232_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_233_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_234_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_235_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_236_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_237_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_238_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_239_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_240_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_241_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_242_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_243_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_244_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_246_statement_definition: // statement.definition
      case symbol_kind::S_247_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_248_statement_definition_function: // statement.definition.function
      case symbol_kind::S_249_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_250_statement_definition_with: // statement.definition.with
      case symbol_kind::S_251_statement_definition_error: // statement.definition.error
      case symbol_kind::S_252_statement_definition_list: // statement.definition.list
      case symbol_kind::S_253_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_254_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_255_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_256_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_257_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_258_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_259_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_260_statement_identifier: // statement.identifier
      case symbol_kind::S_261_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_262_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_263_statement_import: // statement.import
      case symbol_kind::S_264_statement_list: // statement.list
      case symbol_kind::S_265_statement_list_start: // statement.list.start
      case symbol_kind::S_266_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_267_statement_list_append: // statement.list.append
      case symbol_kind::S_268_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_274_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_275_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_276_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.move< Tree > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
      case symbol_kind::S_269_statement_math_precision: // statement.math.precision
      case symbol_kind::S_270_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_271_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_272_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
      case symbol_kind::S_SPLIT: // SPLIT
      case symbol_kind::S_MIX: // MIX
      case symbol_kind::S_SEQ: // SEQ
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_REC: // REC
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_MUL: // MUL
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_XOR: // XOR
      case symbol_kind::S_LSH: // LSH
      case symbol_kind::S_RSH: // RSH
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_FDELAY: // FDELAY
      case symbol_kind::S_DELAY1: // DELAY1
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_MEM: // MEM
      case symbol_kind::S_PREFIX: // PREFIX
      case symbol_kind::S_INTCAST: // INTCAST
      case symbol_kind::S_FLOATCAST: // FLOATCAST
      case symbol_kind::S_ANYCAST: // ANYCAST
      case symbol_kind::S_FFUNCTION: // FFUNCTION
      case symbol_kind::S_FCONSTANT: // FCONSTANT
      case symbol_kind::S_FVARIABLE: // FVARIABLE
      case symbol_kind::S_BUTTON: // BUTTON
      case symbol_kind::S_CHECKBOX: // CHECKBOX
      case symbol_kind::S_VSLIDER: // VSLIDER
      case symbol_kind::S_HSLIDER: // HSLIDER
      case symbol_kind::S_NENTRY: // NENTRY
      case symbol_kind::S_VGROUP: // VGROUP
      case symbol_kind::S_HGROUP: // HGROUP
      case symbol_kind::S_TGROUP: // TGROUP
      case symbol_kind::S_HBARGRAPH: // HBARGRAPH
      case symbol_kind::S_VBARGRAPH: // VBARGRAPH
      case symbol_kind::S_SOUNDFILE: // SOUNDFILE
      case symbol_kind::S_ATTACH: // ATTACH
      case symbol_kind::S_ACOS: // ACOS
      case symbol_kind::S_ASIN: // ASIN
      case symbol_kind::S_ATAN: // ATAN
      case symbol_kind::S_ATAN2: // ATAN2
      case symbol_kind::S_COS: // COS
      case symbol_kind::S_SIN: // SIN
      case symbol_kind::S_TAN: // TAN
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_LOG: // LOG
      case symbol_kind::S_LOG10: // LOG10
      case symbol_kind::S_POWFUN: // POWFUN
      case symbol_kind::S_SQRT: // SQRT
      case symbol_kind::S_ABS: // ABS
      case symbol_kind::S_MIN: // MIN
      case symbol_kind::S_MAX: // MAX
      case symbol_kind::S_FMOD: // FMOD
      case symbol_kind::S_REMAINDER: // REMAINDER
      case symbol_kind::S_FLOOR: // FLOOR
      case symbol_kind::S_CEIL: // CEIL
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RDTBL: // RDTBL
      case symbol_kind::S_RWTBL: // RWTBL
      case symbol_kind::S_SELECT2: // SELECT2
      case symbol_kind::S_SELECT3: // SELECT3
      case symbol_kind::S_LAMBDA: // LAMBDA
      case symbol_kind::S_WIRE: // WIRE
      case symbol_kind::S_CUT: // CUT
      case symbol_kind::S_ENDDEF: // ENDDEF
      case symbol_kind::S_VIRG: // VIRG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_LBRAQ: // LBRAQ
      case symbol_kind::S_RBRAQ: // RBRAQ
      case symbol_kind::S_LCROC: // LCROC
      case symbol_kind::S_RCROC: // RCROC
      case symbol_kind::S_WHERE: // WHERE
      case symbol_kind::S_DEF: // DEF
      case symbol_kind::S_IMPORT: // IMPORT
      case symbol_kind::S_COMPONENT: // COMPONENT
      case symbol_kind::S_LIBRARY: // LIBRARY
      case symbol_kind::S_ENVIRONMENT: // ENVIRONMENT
      case symbol_kind::S_WAVEFORM: // WAVEFORM
      case symbol_kind::S_ROUTE: // ROUTE
      case symbol_kind::S_ENABLE: // ENABLE
      case symbol_kind::S_CONTROL: // CONTROL
      case symbol_kind::S_ITERATE_PARALLEL: // ITERATE_PARALLEL
      case symbol_kind::S_ISEQ: // ISEQ
      case symbol_kind::S_ISUM: // ISUM
      case symbol_kind::S_IPROD: // IPROD
      case symbol_kind::S_INPUTS: // INPUTS
      case symbol_kind::S_OUTPUTS: // OUTPUTS
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TAGSTRING: // TAGSTRING
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_EXTRA: // EXTRA
      case symbol_kind::S_DECLARE: // DECLARE
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_ARROW: // ARROW
      case symbol_kind::S_ASSERTBOUNDS: // ASSERTBOUNDS
      case symbol_kind::S_LOWEST: // LOWEST
      case symbol_kind::S_HIGHEST: // HIGHEST
      case symbol_kind::S_BDOC: // BDOC
      case symbol_kind::S_EDOC: // EDOC
      case symbol_kind::S_BEQN: // BEQN
      case symbol_kind::S_EEQN: // EEQN
      case symbol_kind::S_BDGM: // BDGM
      case symbol_kind::S_EDGM: // EDGM
      case symbol_kind::S_BLST: // BLST
      case symbol_kind::S_ELST: // ELST
      case symbol_kind::S_BMETADATA: // BMETADATA
      case symbol_kind::S_EMETADATA: // EMETADATA
      case symbol_kind::S_DOCCHAR: // DOCCHAR
      case symbol_kind::S_NOTICE: // NOTICE
      case symbol_kind::S_LISTING: // LISTING
      case symbol_kind::S_LSTTRUE: // LSTTRUE
      case symbol_kind::S_LSTFALSE: // LSTFALSE
      case symbol_kind::S_LSTDEPENDENCIES: // LSTDEPENDENCIES
      case symbol_kind::S_LSTMDOCTAGS: // LSTMDOCTAGS
      case symbol_kind::S_LSTDISTRIBUTED: // LSTDISTRIBUTED
      case symbol_kind::S_LSTEQ: // LSTEQ
      case symbol_kind::S_LSTQ: // LSTQ
      case symbol_kind::S_ENDL: // ENDL
      case symbol_kind::S_141_doc_text: // doc.text
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  AbstractImplementation::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  AbstractImplementation::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  AbstractImplementation::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  AbstractImplementation::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  AbstractImplementation::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  AbstractImplementation::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  AbstractImplementation::symbol_kind_type
  AbstractImplementation::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  AbstractImplementation::symbol_kind_type
  AbstractImplementation::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} } } // ::Faust::Compiler::Parser




#endif // !YY_YY_ABSTRACT_IMPLEMENTATION_HH_INCLUDED
