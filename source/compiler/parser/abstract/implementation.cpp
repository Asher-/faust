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



// First part of user prologue.
 /* Faust */

#include <list>
#include <iostream>

#include "tlib/tree.hh"
#include "compiler/block_diagram/boxes/boxes.hh"
#include "compiler/signals/prim2.hh"
#include "compiler/signals/signals.hh"
#include "compiler/errors/errormsg.hh"
#include "compiler/file_handling/sourcereader.hh"
#include "documentator/doc.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"

#include "faust/primitive/math.hh"

#include "compiler/parser/lexer/implementation.hh"

#define YYMAXDEPTH	100000
#define YYLLOC_DEFAULT( token, rhs_locations, rhs_count ) \
        self.tokenDidMatch(                               \
          token,                                          \
          rhs_count,                                      \
          rhs_locations                                   \
        )


#undef yylex
#define yylex self._lexer->lex





#include "implementation.hh"


// Unqualified %code blocks.
 /* Faust code */
  #include "compiler/parser/implementation.hh"



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
#if YYDEBUG

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

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace Faust { namespace Compiler { namespace Parser {

  /// Build a parser object.
  AbstractImplementation::AbstractImplementation (Implementation& self_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      self (self_yyarg)
  {}

  AbstractImplementation::~AbstractImplementation ()
  {}

  AbstractImplementation::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  AbstractImplementation::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  AbstractImplementation::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  AbstractImplementation::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  AbstractImplementation::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  AbstractImplementation::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  AbstractImplementation::symbol_kind_type
  AbstractImplementation::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  AbstractImplementation::stack_symbol_type::stack_symbol_type ()
  {}

  AbstractImplementation::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
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
      case symbol_kind::S_206_primitive_signal_input_wire: // primitive.signal.input.wire
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
        value.YY_MOVE_OR_COPY< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  AbstractImplementation::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
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
      case symbol_kind::S_206_primitive_signal_input_wire: // primitive.signal.input.wire
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
        value.move< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (YY_MOVE (that.value));
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
        value.move< int > (YY_MOVE (that.value));
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
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  AbstractImplementation::stack_symbol_type&
  AbstractImplementation::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
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
      case symbol_kind::S_206_primitive_signal_input_wire: // primitive.signal.input.wire
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
        value.copy< Tree > (that.value);
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< float > (that.value);
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
        value.copy< int > (that.value);
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
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  AbstractImplementation::stack_symbol_type&
  AbstractImplementation::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
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
      case symbol_kind::S_206_primitive_signal_input_wire: // primitive.signal.input.wire
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
        value.move< Tree > (that.value);
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (that.value);
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
        value.move< int > (that.value);
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
        value.move< std::string > (that.value);
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
  AbstractImplementation::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  AbstractImplementation::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  AbstractImplementation::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  AbstractImplementation::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  AbstractImplementation::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  AbstractImplementation::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  AbstractImplementation::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  AbstractImplementation::debug_level_type
  AbstractImplementation::debug_level () const
  {
    return yydebug_;
  }

  void
  AbstractImplementation::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  AbstractImplementation::state_type
  AbstractImplementation::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  AbstractImplementation::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  AbstractImplementation::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  AbstractImplementation::operator() ()
  {
    return parse ();
  }

  int
  AbstractImplementation::parse ()
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

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
{
  self._location.begin().streamName() = self._location.end().streamName() = self._streamName;
}



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
            symbol_type yylookahead (yylex (self, yyla));
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_206_primitive_signal_input_wire: // primitive.signal.input.wire
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
        yylhs.value.emplace< Tree > ();
        break;

      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< float > ();
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
        yylhs.value.emplace< int > ();
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
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs, range, yylen);
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
  case 2: // program: statement.list
                               {
			yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > ();
			self._ast = self.formatDefinitions(yylhs.value.as < Tree > ());
		}
    break;

  case 3: // program: %empty
                { yylhs.value.as < Tree > () = self._nil; }
    break;

  case 4: // doc: doc.text
                         {
			yylhs.value.as < Tree > () = docTxt(yystack_[0].value.as < std::string > ().c_str());
//			delete $[doc.text];
		}
    break;

  case 5: // doc: doc.equation
                 { yylhs.value.as < Tree > () = docEqn(yystack_[0].value.as < Tree > ()); }
    break;

  case 6: // doc: doc.diagram
                { yylhs.value.as < Tree > () = docDgm(yystack_[0].value.as < Tree > ()); }
    break;

  case 7: // doc: doc.notice
               { yylhs.value.as < Tree > () = docNtc(); }
    break;

  case 8: // doc: doc.list
             { yylhs.value.as < Tree > () = docLst(); }
    break;

  case 9: // doc: doc.metadata
                 { yylhs.value.as < Tree > () = docMtd(yystack_[0].value.as < Tree > ()); }
    break;

  case 10: // doc: %empty
                      { yylhs.value.as < Tree > () = self._nil; }
    break;

  case 11: // doc.text: DOCCHAR
              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
    break;

  case 12: // doc.text: doc.text DOCCHAR
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > ().append(self._lexer->YYText()); }
    break;

  case 13: // doc.equation: BEQN expression EEQN
                           { yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > (); }
    break;

  case 14: // doc.diagram: BDGM expression EDGM
                           { yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > (); }
    break;

  case 15: // doc.notice: NOTICE
             { }
    break;

  case 16: // doc.metadata: BMETADATA statement.identifier EMETADATA
                                                       { yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > (); }
    break;

  case 17: // doc.list: BLST doc.attribute.list ELST
                                   { }
    break;

  case 18: // doc.list: BLST ELST
                                 { }
    break;

  case 19: // doc.attribute.list: doc.attribute.definition
                                 {}
    break;

  case 20: // doc.attribute.list: doc.attribute.list doc.attribute.definition
                                                    { }
    break;

  case 21: // doc.attribute.definition: LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ
                                                            {
          self._lstDependenciesSwitch = yystack_[1].value.as < bool > ();
        }
    break;

  case 22: // doc.attribute.definition: LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ
                                                        {
          self._stripDocSwitch = yystack_[1].value.as < bool > ();
          self._stripDocSwitch ? self._stripDocSwitch=false
                                   : self._stripDocSwitch=true;
        }
    break;

  case 23: // doc.attribute.definition: LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ
                                                           {
          self._lstDistributedSwitch = yystack_[1].value.as < bool > ();
        }
    break;

  case 24: // doc.attribute.value: LSTTRUE
                { yylhs.value.as < bool > () = true; }
    break;

  case 25: // doc.attribute.value: LSTFALSE
                 { yylhs.value.as < bool > () = false; }
    break;

  case 26: // expression: statement.definition.with
                { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 27: // expression: expression.letrec
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 28: // expression: expression.composition
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 29: // expression.component: COMPONENT LPAR primitive.string.unquoted RPAR
                                                    {
        yylhs.value.as < Tree > () = boxComponent(yystack_[1].value.as < Tree > ());
      }
    break;

  case 30: // expression.composition: expression.composition.serial
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 31: // expression.composition: expression.composition.parallel
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 32: // expression.composition.parallel: expression COMMA expression
                                            {
        yylhs.value.as < Tree > () = boxPar( yystack_[2].value.as < Tree > (), yystack_[0].value.as < Tree > () );
      }
    break;

  case 33: // expression.composition.serial: expression.composition.sequence
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 34: // expression.composition.serial: expression.composition.split
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 35: // expression.composition.serial: expression.composition.mix
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 36: // expression.composition.serial: expression.composition.recursive
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 37: // expression.composition.serial: expression.infix
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 38: // expression.composition.mix: expression.composition.serial MIX expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = boxMerge( yystack_[2].value.as < Tree > (), yystack_[0].value.as < Tree > () );
        }
    break;

  case 39: // expression.composition.recursive: expression.composition.serial REC expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = boxRec(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
        }
    break;

  case 40: // expression.composition.sequence: expression.composition.serial SEQ expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = boxSeq(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
        }
    break;

  case 41: // expression.composition.split: expression.composition.serial SPLIT expression.composition.serial
                                                                                    {
          yylhs.value.as < Tree > () = boxSplit(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
        }
    break;

  case 42: // expression.environment: ENVIRONMENT LBRAQ statement.list RBRAQ
                                             {
        yylhs.value.as < Tree > () = boxWithLocalDef(boxEnvironment(),self.formatDefinitions(yystack_[1].value.as < Tree > ()));
      }
    break;

  case 43: // expression.infix: expression.infix.definitions.substitution
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 44: // expression.infix: expression.infix.environment.access
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 45: // expression.infix: expression.infix.math
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 46: // expression.infix: expression.infix.signal.delay
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 47: // expression.infix: expression.infix.prefix
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 48: // expression.infix: expression.component
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 49: // expression.infix: expression.environment
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 50: // expression.infix: expression.iterate.parallel
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 51: // expression.infix: expression.iterate.sequence
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 52: // expression.infix: expression.iterate.sum
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 53: // expression.infix: expression.iterate.product
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 54: // expression.infix: expression.lambda
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 55: // expression.infix: expression.library
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 56: // expression.infix: expression.math
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 57: // expression.infix: expression.parenthesis
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 58: // expression.infix: expression.signal
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 59: // expression.infix: statement.identifier.box
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 60: // expression.infix: primitive
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 61: // expression.infix.definitions.substitution: expression.infix LCROC statement.definition.list RCROC
                                                                        {
        yylhs.value.as < Tree > () = boxModifLocalDef(
          yystack_[3].value.as < Tree > (),
          self.formatDefinitions(yystack_[1].value.as < Tree > ())
        );
      }
    break;

  case 62: // expression.infix.environment.access: expression.infix DOT statement.identifier.box
                                                              { yylhs.value.as < Tree > () = boxAccess(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()); }
    break;

  case 63: // expression.infix.math: expression.infix.math.algebra
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 64: // expression.infix.math: expression.infix.math.comparison
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 65: // expression.infix.math: expression.infix.math.logic
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 66: // expression.infix.math: expression.infix.math.shift
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 67: // expression.infix.math.algebra: expression.infix ADD expression.infix
                                                        { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigAdd)); }
    break;

  case 68: // expression.infix.math.algebra: expression.infix SUB expression.infix
                                                        { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigSub)); }
    break;

  case 69: // expression.infix.math.algebra: expression.infix MUL expression.infix
                                                        { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigMul)); }
    break;

  case 70: // expression.infix.math.algebra: expression.infix DIV expression.infix
                                                        { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigDiv)); }
    break;

  case 71: // expression.infix.math.algebra: expression.infix MOD expression.infix
                                                        { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigRem)); }
    break;

  case 72: // expression.infix.math.algebra: expression.infix POWOP expression.infix
                                                        {
        yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::Faust::Primitive::Math::functions().pow.box());
      }
    break;

  case 73: // expression.infix.math.comparison: expression.infix LT expression.infix
                                                     { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigLT)); }
    break;

  case 74: // expression.infix.math.comparison: expression.infix LE expression.infix
                                                     { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigLE)); }
    break;

  case 75: // expression.infix.math.comparison: expression.infix GT expression.infix
                                                     { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigGT)); }
    break;

  case 76: // expression.infix.math.comparison: expression.infix GE expression.infix
                                                     { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigGE)); }
    break;

  case 77: // expression.infix.math.comparison: expression.infix EQ expression.infix
                                                     { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigEQ)); }
    break;

  case 78: // expression.infix.math.comparison: expression.infix NE expression.infix
                                                     { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigNE)); }
    break;

  case 79: // expression.infix.math.logic: expression.infix AND expression.infix
                                                      { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigAND)); }
    break;

  case 80: // expression.infix.math.logic: expression.infix OR expression.infix
                                                      { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigOR)); }
    break;

  case 81: // expression.infix.math.logic: expression.infix XOR expression.infix
                                                      { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigXOR)); }
    break;

  case 82: // expression.infix.math.shift: expression.infix LSH expression.infix
                                                      { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigLeftShift)); }
    break;

  case 83: // expression.infix.math.shift: expression.infix RSH expression.infix
                                                      {
        yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigARightShift));
      }
    break;

  case 84: // expression.infix.prefix: expression.infix LPAR expression.composition.parallel RPAR
                                                                       { yylhs.value.as < Tree > () = buildBoxAppl(yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ()); }
    break;

  case 85: // expression.infix.signal.delay: expression.infix FDELAY expression.infix
                                                         { yylhs.value.as < Tree > () = boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),boxPrim2(sigDelay)); }
    break;

  case 86: // expression.infix.signal.delay: expression.infix DELAY1
                                   { yylhs.value.as < Tree > () = boxSeq(yystack_[1].value.as < Tree > (),boxPrim1(sigDelay1)); }
    break;

  case 87: // expression.iterate.parallel: ITERATE_PARALLEL LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR
                                                                                                               {
        yylhs.value.as < Tree > () = boxIPar(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 88: // expression.iterate.sequence: ISEQ LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR
                                                                                                   {
        yylhs.value.as < Tree > () = boxISeq(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 89: // expression.iterate.sum: ISUM LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR
                                                                                                   {
        yylhs.value.as < Tree > () = boxISum(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 90: // expression.iterate.product: IPROD LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR
                                                                                                    {
        yylhs.value.as < Tree > () = boxIProd(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 91: // expression.lambda: LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR
                                                                         {
        yylhs.value.as < Tree > () = buildBoxAbstr(yystack_[5].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 92: // expression.lambda.params: expression.lambda.params.start
                { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 93: // expression.lambda.params: expression.lambda.params.append
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 94: // expression.lambda.params.start: statement.identifier.box
                                 { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),self._nil); }
    break;

  case 95: // expression.lambda.params.append: expression.lambda.params COMMA statement.identifier.box
                                                                             { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),yystack_[2].value.as < Tree > ()); }
    break;

  case 96: // expression.letrec: expression LETREC LBRAQ RBRAQ
                                                                          {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[3].value.as < Tree > (),
        self.formatDefinitions(self._nil),
        self._nil
      );
		}
    break;

  case 97: // expression.letrec: expression LETREC LBRAQ expression.letrec.list RBRAQ
                                                              {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[4].value.as < Tree > (),
        self.formatDefinitions(yystack_[1].value.as < Tree > ()),
        self._nil
      );
		}
    break;

  case 98: // expression.letrec: expression LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ
                                                                                              {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[6].value.as < Tree > (),
        self.formatDefinitions(yystack_[3].value.as < Tree > ()),
        self.formatDefinitions(yystack_[3].value.as < Tree > ())
      );
		}
    break;

  case 99: // expression.letrec.list: expression.letrec.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 100: // expression.letrec.list: expression.letrec.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 101: // expression.letrec.list.start: expression.letrec.equation
                                         { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (), self._nil); }
    break;

  case 102: // expression.letrec.list.append: expression.letrec.list expression.letrec.equation
                                                                       { yylhs.value.as < Tree > () = cons (yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ()); }
    break;

  case 103: // expression.letrec.equation: expression.letrec.equation.name DEF expression ENDDEF
                                                                      {
        yylhs.value.as < Tree > () = cons(yystack_[3].value.as < Tree > (),cons(self._nil,yystack_[1].value.as < Tree > ()));
        setDefProp(yystack_[3].value.as < Tree > (), self._streamName.c_str(), self._lexer->lineno());
      }
    break;

  case 104: // expression.letrec.equation: error ENDDEF
                   { yylhs.value.as < Tree > () = self._nil; self._lexer->LexerError("Expected expression."); }
    break;

  case 105: // expression.letrec.equation.name: DELAY1 statement.identifier.box
                                        { yylhs.value.as < Tree > ()=yystack_[0].value.as < Tree > (); }
    break;

  case 106: // expression.library: LIBRARY LPAR primitive.string.unquoted RPAR
                                                  { yylhs.value.as < Tree > () = boxLibrary(yystack_[1].value.as < Tree > ()); }
    break;

  case 107: // expression.math: expression.math.signal
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 108: // expression.math: expression.math.scalar
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 109: // expression.math: expression.math.comparison
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 110: // expression.math: expression.math.trigonometry
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 111: // expression.math: expression.math.rounding
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 112: // expression.math.comparison: LT
           { yylhs.value.as < Tree > () = boxPrim2(sigLT); }
    break;

  case 113: // expression.math.comparison: LE
           { yylhs.value.as < Tree > () = boxPrim2(sigLE); }
    break;

  case 114: // expression.math.comparison: GT
           { yylhs.value.as < Tree > () = boxPrim2(sigGT); }
    break;

  case 115: // expression.math.comparison: GE
           { yylhs.value.as < Tree > () = boxPrim2(sigGE); }
    break;

  case 116: // expression.math.comparison: EQ
           { yylhs.value.as < Tree > () = boxPrim2(sigEQ); }
    break;

  case 117: // expression.math.comparison: NE
           { yylhs.value.as < Tree > () = boxPrim2(sigNE); }
    break;

  case 118: // expression.math.rounding: ABS
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().abs.box(); }
    break;

  case 119: // expression.math.rounding: MIN
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().min.box(); }
    break;

  case 120: // expression.math.rounding: MAX
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().max.box(); }
    break;

  case 121: // expression.math.rounding: FLOOR
                { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().floor.box(); }
    break;

  case 122: // expression.math.rounding: CEIL
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().ceil.box(); }
    break;

  case 123: // expression.math.rounding: ASSERTBOUNDS
                       { yylhs.value.as < Tree > () = boxPrim3(sigAssertBounds);}
    break;

  case 124: // expression.math.rounding: LOWEST
                 { yylhs.value.as < Tree > () = boxPrim1(sigLowest);}
    break;

  case 125: // expression.math.rounding: HIGHEST
                  { yylhs.value.as < Tree > () = boxPrim1(sigHighest);}
    break;

  case 126: // expression.math.rounding: RINT
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().rint.box(); }
    break;

  case 127: // expression.math.signal: expression.math.signal.algebra
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 128: // expression.math.signal: expression.math.signal.shift
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 129: // expression.math.signal: expression.math.signal.power
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 130: // expression.math.signal.algebra: ADD
              { yylhs.value.as < Tree > () = boxPrim2(sigAdd); }
    break;

  case 131: // expression.math.signal.algebra: SUB
              { yylhs.value.as < Tree > () = boxPrim2(sigSub); }
    break;

  case 132: // expression.math.signal.algebra: MUL
              { yylhs.value.as < Tree > () = boxPrim2(sigMul); }
    break;

  case 133: // expression.math.signal.algebra: DIV
              { yylhs.value.as < Tree > () = boxPrim2(sigDiv); }
    break;

  case 134: // expression.math.signal.algebra: MOD
              { yylhs.value.as < Tree > () = boxPrim2(sigRem); }
    break;

  case 135: // expression.math.signal.algebra: FMOD
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().fmod.box(); }
    break;

  case 136: // expression.math.signal.algebra: REMAINDER
                    { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().remainder.box(); }
    break;

  case 137: // expression.math.signal.algebra: SUB statement.identifier.box
                                       { yylhs.value.as < Tree > () = boxSeq(boxPar(boxInt(0),yystack_[0].value.as < Tree > ()),boxPrim2(sigSub)); }
    break;

  case 138: // expression.math.signal.shift: LSH
              { yylhs.value.as < Tree > () = boxPrim2(sigLeftShift); }
    break;

  case 139: // expression.math.signal.shift: RSH
              { yylhs.value.as < Tree > () = boxPrim2(sigARightShift); }
    break;

  case 140: // expression.math.signal.power: EXP
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().exp.box(); }
    break;

  case 141: // expression.math.signal.power: LOG
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().log.box(); }
    break;

  case 142: // expression.math.signal.power: LOG10
                { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().log10.box(); }
    break;

  case 143: // expression.math.signal.power: POWOP
                { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().pow.box(); }
    break;

  case 144: // expression.math.signal.power: POWFUN
                 { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().pow.box(); }
    break;

  case 145: // expression.math.signal.power: SQRT
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().sqrt.box(); }
    break;

  case 146: // expression.math.scalar: ADD INT
                  { yylhs.value.as < Tree > () = boxInt(std::stoi(self._lexer->YYText())); }
    break;

  case 147: // expression.math.scalar: ADD FLOAT
                    { yylhs.value.as < Tree > () = boxReal(yystack_[0].value.as < float > ()); }
    break;

  case 148: // expression.math.scalar: SUB INT
                  { yylhs.value.as < Tree > () = boxInt ( -yystack_[0].value.as < int > () ); }
    break;

  case 149: // expression.math.scalar: SUB FLOAT
                    { yylhs.value.as < Tree > () = boxReal( -yystack_[0].value.as < float > () ); }
    break;

  case 150: // expression.math.trigonometry: ACOS
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().acos.box(); }
    break;

  case 151: // expression.math.trigonometry: ASIN
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().asin.box(); }
    break;

  case 152: // expression.math.trigonometry: ATAN
               { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().atan.box(); }
    break;

  case 153: // expression.math.trigonometry: ATAN2
                { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().atan2.box(); }
    break;

  case 154: // expression.math.trigonometry: COS
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().cos.box(); }
    break;

  case 155: // expression.math.trigonometry: SIN
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().sin.box(); }
    break;

  case 156: // expression.math.trigonometry: TAN
              { yylhs.value.as < Tree > () = ::Faust::Primitive::Math::functions().tan.box(); }
    break;

  case 157: // expression.parenthesis: LPAR expression RPAR
                         { yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > (); }
    break;

  case 158: // expression.signal: expression.signal.control
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 159: // expression.signal: expression.signal.delay
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 160: // expression.signal: expression.signal.logic
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 161: // expression.signal.control: ATTACH
               { yylhs.value.as < Tree > () = boxPrim2(sigAttach); }
    break;

  case 162: // expression.signal.control: ENABLE
               { yylhs.value.as < Tree > () = boxPrim2(sigEnable); }
    break;

  case 163: // expression.signal.control: CONTROL
                { yylhs.value.as < Tree > () = boxPrim2(sigControl); }
    break;

  case 164: // expression.signal.delay: MEM
            { yylhs.value.as < Tree > () = boxPrim1(sigDelay1); }
    break;

  case 165: // expression.signal.delay: PREFIX
               { yylhs.value.as < Tree > () = boxPrim2(sigPrefix); }
    break;

  case 166: // expression.signal.delay: FDELAY
               { yylhs.value.as < Tree > () = boxPrim2(sigDelay); }
    break;

  case 167: // expression.signal.logic: AND
            { yylhs.value.as < Tree > () = boxPrim2(sigAND); }
    break;

  case 168: // expression.signal.logic: OR
           { yylhs.value.as < Tree > () = boxPrim2(sigOR); }
    break;

  case 169: // expression.signal.logic: XOR
            { yylhs.value.as < Tree > () = boxPrim2(sigXOR); }
    break;

  case 170: // expression.signal.logic: SELECT2
                { yylhs.value.as < Tree > () = boxPrim3(sigSelect2); }
    break;

  case 171: // expression.signal.logic: SELECT3
                { yylhs.value.as < Tree > () = boxPrim4(sigSelect3); }
    break;

  case 172: // expression.signal.logic: CASE LBRAQ statement.signal.pattern.rule.list RBRAQ
                                                            {
          yylhs.value.as < Tree > () = boxCase(self.checkRulelist(yystack_[1].value.as < Tree > ()));
        }
    break;

  case 173: // primitive: primitive.foreign
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 174: // primitive: primitive.number
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 175: // primitive: primitive.type.number
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 176: // primitive: primitive.signal
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 177: // primitive: primitive.ui
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 178: // primitive.foreign: primitive.foreign.constant
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 179: // primitive.foreign: primitive.foreign.function
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 180: // primitive.foreign: primitive.foreign.variable
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 181: // primitive.number: INT
          { yylhs.value.as < Tree > () = boxInt(std::stoi(self._lexer->YYText())); }
    break;

  case 182: // primitive.number: FLOAT
            { yylhs.value.as < Tree > () = boxReal(atof(self._lexer->YYText())); }
    break;

  case 183: // primitive.string.quoted: STRING
             { yylhs.value.as < Tree > () = tree(self._lexer->YYText()); }
    break;

  case 184: // primitive.string.unquoted: STRING
             { yylhs.value.as < Tree > () = self.unquote(self._lexer->YYText()); }
    break;

  case 185: // primitive.string.tag: STRING
             { yylhs.value.as < Tree > () = tree(self._lexer->YYText()); }
    break;

  case 186: // primitive.string.tag: TAGSTRING
                { yylhs.value.as < Tree > () = tree(self._lexer->YYText()); }
    break;

  case 187: // primitive.signal: primitive.signal.inputs
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 188: // primitive.signal: primitive.signal.input.wire
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 189: // primitive.signal: primitive.signal.input.terminate
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 190: // primitive.signal: primitive.signal.outputs
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 191: // primitive.signal: primitive.signal.route
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 192: // primitive.signal: primitive.signal.source
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 193: // primitive.signal.input.wire: WIRE
           { yylhs.value.as < Tree > () = boxWire(); }
    break;

  case 194: // primitive.signal.input.terminate: CUT
          { yylhs.value.as < Tree > () = boxCut(); }
    break;

  case 195: // primitive.type: primitive.type.number
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 196: // primitive.type: primitive.type.any
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 197: // primitive.type.number: primitive.type.number.int
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 198: // primitive.type.number: primitive.type.number.float
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 199: // primitive.type.number.int: INTCAST
                  { yylhs.value.as < Tree > () = boxPrim1(sigIntCast); }
    break;

  case 200: // primitive.type.number.float: FLOATCAST
                    { yylhs.value.as < Tree > () = boxPrim1(sigFloatCast); }
    break;

  case 201: // primitive.type.any: ANYCAST
                { yylhs.value.as < Tree > () = tree(2); }
    break;

  case 202: // primitive.type.number.list: primitive.type.number.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 203: // primitive.type.number.list: primitive.type.number.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 204: // primitive.type.number.list.member: primitive.number
                           {
            global::config().gWaveForm.push_back(yystack_[0].value.as < Tree > ());
          }
    break;

  case 205: // primitive.type.number.list.member: expression.math.scalar
                                 {
            global::config().gWaveForm.push_back(yystack_[0].value.as < Tree > ());
          }
    break;

  case 206: // primitive.type.number.list.start: primitive.type.number.list.member
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 207: // primitive.type.number.list.append: primitive.type.number.list COMMA primitive.type.number.list.member
          { yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > (); }
    break;

  case 208: // primitive.signal.route: primitive.signal.route.implied.outputs
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 209: // primitive.signal.route: primitive.signal.route.implied.connections
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 210: // primitive.signal.route: primitive.signal.route.explicit
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 211: // primitive.signal.route.implied.outputs: ROUTE LPAR expression.composition.serial RPAR
                                                                     {
            yylhs.value.as < Tree > () = boxRoute(yystack_[1].value.as < Tree > (), yystack_[1].value.as < Tree > (), boxPar(boxInt(0),boxInt(0)));
          }
    break;

  case 212: // primitive.signal.route.implied.connections: ROUTE LPAR expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                             {
            yylhs.value.as < Tree > () = boxRoute(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > (), boxPar(boxInt(0),boxInt(0)));
          }
    break;

  case 213: // primitive.signal.route.explicit: ROUTE LPAR expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.parallel RPAR
                                                                                                                                                   {
            yylhs.value.as < Tree > () = boxRoute(
              yystack_[5].value.as < Tree > (),
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > ()
            );
          }
    break;

  case 214: // primitive.signal.source: primitive.signal.source.waveform
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 215: // primitive.signal.source: primitive.signal.source.soundfile
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 216: // primitive.signal.source: primitive.signal.source.table
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 217: // primitive.signal.source.table: RDTBL
                { yylhs.value.as < Tree > () = boxPrim3(sigReadOnlyTable); }
    break;

  case 218: // primitive.signal.source.table: RWTBL
                { yylhs.value.as < Tree > () = boxPrim5(sigWriteReadTable); }
    break;

  case 219: // primitive.signal.source.soundfile: SOUNDFILE LPAR primitive.string.unquoted COMMA expression.composition RPAR
                                                                                     {
            yylhs.value.as < Tree > () = boxSoundfile( yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > () );
          }
    break;

  case 220: // primitive.signal.source.waveform: WAVEFORM LBRAQ primitive.type.number.list RBRAQ
                                                        {
          yylhs.value.as < Tree > () = boxWaveform(global::config().gWaveForm);
          global::config().gWaveForm.clear();
          /* primitive.type.number.list pushes values onto global::config().gWaveForm */
        }
    break;

  case 221: // primitive.type.list: primitive.type.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 222: // primitive.type.list: primitive.type.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 223: // primitive.type.list.start: primitive.type
                         { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),self._nil); }
    break;

  case 224: // primitive.type.list.append: primitive.type.list COMMA primitive.type
                                                                { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),yystack_[2].value.as < Tree > ()); }
    break;

  case 225: // primitive.ui: primitive.ui.button
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 226: // primitive.ui: primitive.ui.checkbox
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 227: // primitive.ui: primitive.ui.vslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 228: // primitive.ui: primitive.ui.hslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 229: // primitive.ui: primitive.ui.nentry
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 230: // primitive.ui: primitive.ui.vgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 231: // primitive.ui: primitive.ui.hgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 232: // primitive.ui: primitive.ui.tgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 233: // primitive.ui: primitive.ui.vbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 234: // primitive.ui: primitive.ui.hbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 235: // primitive.ui.button: BUTTON LPAR primitive.string.unquoted RPAR
                                                   { yylhs.value.as < Tree > () = boxButton(yystack_[1].value.as < Tree > ()); }
    break;

  case 236: // primitive.ui.checkbox: CHECKBOX LPAR primitive.string.unquoted RPAR
                                                     { yylhs.value.as < Tree > () = boxCheckbox(yystack_[1].value.as < Tree > ()); }
    break;

  case 237: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                            {
          yylhs.value.as < Tree > () = boxVSlider(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        }
    break;

  case 238: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                            {
          yylhs.value.as < Tree > () = boxHSlider(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        }
    break;

  case 239: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                           {
          yylhs.value.as < Tree > () = boxNumEntry(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        }
    break;

  case 240: // primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted COMMA expression RPAR
                                                                    { yylhs.value.as < Tree > () = boxVGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ()); }
    break;

  case 241: // primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted COMMA expression RPAR
                                                                    { yylhs.value.as < Tree > () = boxHGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ()); }
    break;

  case 242: // primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted COMMA expression RPAR
                                                                    { yylhs.value.as < Tree > () = boxTGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ()); }
    break;

  case 243: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                          {
          yylhs.value.as < Tree > () = boxVBargraph(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        }
    break;

  case 244: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                          {
          yylhs.value.as < Tree > () = boxHBargraph(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        }
    break;

  case 245: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag COMMA primitive.string.unquoted RPAR
                                                                                                                            {
          yylhs.value.as < Tree > () = boxFFun(ffunction(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ()));
        }
    break;

  case 246: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform LPAR primitive.type.list RPAR
                                                                                                 {
            yylhs.value.as < Tree > () = cons(yystack_[4].value.as < Tree > (), cons(cons(yystack_[3].value.as < Tree > (),cons(yystack_[3].value.as < Tree > (),cons(yystack_[3].value.as < Tree > (),self._nil))), yystack_[1].value.as < Tree > ()));
          }
    break;

  case 247: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform LPAR primitive.type.list RPAR
                                                                                                                                         {
            yylhs.value.as < Tree > () = cons(yystack_[6].value.as < Tree > (), cons(cons(yystack_[5].value.as < Tree > (),cons(yystack_[3].value.as < Tree > (),cons(yystack_[3].value.as < Tree > (),self._nil))), yystack_[1].value.as < Tree > ()));
          }
    break;

  case 248: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform OR statement.identifier.waveform LPAR primitive.type.list RPAR
                                                                                                                                                                                {
            yylhs.value.as < Tree > () = cons(yystack_[8].value.as < Tree > (), cons(cons(yystack_[7].value.as < Tree > (),cons(yystack_[5].value.as < Tree > (),cons(yystack_[3].value.as < Tree > (),self._nil))), yystack_[1].value.as < Tree > ()));
          }
    break;

  case 249: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform LPAR RPAR
                                                                             {
            yylhs.value.as < Tree > () = cons(yystack_[3].value.as < Tree > (), cons(cons(yystack_[2].value.as < Tree > (),cons(yystack_[2].value.as < Tree > (),cons(yystack_[2].value.as < Tree > (),self._nil))), self._nil));
          }
    break;

  case 250: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform LPAR RPAR
                                                                                                                     {
            yylhs.value.as < Tree > () = cons(yystack_[5].value.as < Tree > (), cons(cons(yystack_[4].value.as < Tree > (),cons(yystack_[2].value.as < Tree > (),cons(yystack_[2].value.as < Tree > (),self._nil))), self._nil));
          }
    break;

  case 251: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform OR statement.identifier.waveform LPAR RPAR
                                                                                                                                                            {
            yylhs.value.as < Tree > () = cons(yystack_[7].value.as < Tree > (), cons(cons(yystack_[6].value.as < Tree > (),cons(yystack_[4].value.as < Tree > (),cons(yystack_[2].value.as < Tree > (),self._nil))), self._nil));
          }
    break;

  case 252: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR
                                                                                                  {
          yylhs.value.as < Tree > () = boxFConst( yystack_[4].value.as < Tree > (), yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
        }
    break;

  case 253: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR
                                                                                                  {
          yylhs.value.as < Tree > () = boxFVar( yystack_[4].value.as < Tree > (), yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > () );
        }
    break;

  case 254: // primitive.signal.inputs: INPUTS LPAR expression RPAR
                                    { yylhs.value.as < Tree > () = boxInputs(yystack_[1].value.as < Tree > ()); }
    break;

  case 255: // primitive.signal.outputs: OUTPUTS LPAR expression RPAR
                                     { yylhs.value.as < Tree > () = boxOutputs(yystack_[1].value.as < Tree > ()); }
    break;

  case 256: // statement: statement.definition
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 257: // statement: statement.declare.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 258: // statement: statement.declare.feature.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 259: // statement: statement.declare.doc
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 260: // statement: statement.import
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 261: // statement.definition: statement.definition.function
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 262: // statement.definition: statement.definition.assignment
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 263: // statement.definition: statement.definition.error
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 264: // statement.definition.function.incomplete: statement.identifier.box LPAR expression.composition.parallel RPAR DEF expression
                                                                                        {
        yylhs.value.as < Tree > () = cons(
          yystack_[5].value.as < Tree > (),
          cons( yystack_[3].value.as < Tree > (), yystack_[0].value.as < Tree > () )
        );
        setDefProp(yystack_[5].value.as < Tree > (), self._streamName.c_str(), self._lexer->lineno());
      }
    break;

  case 265: // statement.definition.function: statement.definition.function.incomplete ENDDEF
                                                        {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        }
    break;

  case 266: // statement.definition.function: statement.definition.function.incomplete error ENDL
                                                            {
          self._lexer->LexerError("Incomplete function definition.");
          yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > ();
          yyerrok;
        }
    break;

  case 267: // statement.definition.assignment: statement.identifier.box DEF expression ENDDEF
                                                       {
          yylhs.value.as < Tree > () = cons(
            yystack_[3].value.as < Tree > (),
            cons( self._nil, yystack_[1].value.as < Tree > () )
          );
          setDefProp(
            yystack_[3].value.as < Tree > (),
            self._streamName.c_str(),
            self._lexer->lineno()
          );
        }
    break;

  case 268: // statement.definition.with: expression WITH LBRAQ statement.definition.list RBRAQ
                                                            {
        yylhs.value.as < Tree > () = boxWithLocalDef(yystack_[4].value.as < Tree > (),self.formatDefinitions(yystack_[1].value.as < Tree > ()));
      }
    break;

  case 269: // statement.definition.error: error ENDDEF
                     {
          yylhs.value.as < Tree > () = self._nil;
          self._lexer->LexerError("Error in definition.");
        }
    break;

  case 270: // statement.definition.list: statement.definition.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 271: // statement.definition.list: statement.definition.list.start.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 272: // statement.definition.list: statement.definition.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 273: // statement.definition.list: statement.definition.list.append.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 274: // statement.definition.list.start: statement.definition
                               {
            yylhs.value.as < Tree > () = cons( yylhs.value.as < Tree > (), self._nil );
          }
    break;

  case 275: // statement.definition.list.start.qualified: statement.math.precision.list statement.definition
                                                             {
            if (self.acceptdefinition(yystack_[1].value.as < int > ()))
              yylhs.value.as < Tree > () = cons( yystack_[0].value.as < Tree > (), self._nil );
            else
              yylhs.value.as < Tree > () = self._nil;
          }
    break;

  case 276: // statement.definition.list.append: statement.definition.list statement.definition
                                                         {
            yylhs.value.as < Tree > () = cons (yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          }
    break;

  case 277: // statement.definition.list.append.qualified: statement.definition.list statement.math.precision.list statement.definition
                                                                                       {
            if (self.acceptdefinition(yystack_[1].value.as < int > ()))
              yylhs.value.as < Tree > () = cons (yystack_[0].value.as < Tree > (),yystack_[2].value.as < Tree > ());
            else
              yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > ();
          }
    break;

  case 278: // statement.declare.metadata: DECLARE statement.identifier primitive.string.quoted ENDDEF
                                                                              {
        self.declareMetadata(yystack_[2].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = self._nil;
      }
    break;

  case 279: // statement.declare.feature.metadata: DECLARE statement.identifier statement.identifier primitive.string.quoted ENDDEF
                                                                                                            {
        self.declareDefinitionMetadata( yystack_[3].value.as < Tree > (), yystack_[2].value.as < Tree > (), yystack_[1].value.as < Tree > () );
        yylhs.value.as < Tree > () = self._nil;
      }
    break;

  case 280: // statement.declare.doc: BDOC doc EDOC
                          {
        declareDoc(yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = self._nil;
      }
    break;

  case 281: // statement.identifier: IDENT
            {
        yylhs.value.as < Tree > () = tree(self._lexer->YYText());
        setUseProp(yylhs.value.as < Tree > (), self._streamName.c_str(), self._lexer->lineno());
      }
    break;

  case 282: // statement.identifier.box: IDENT
            {
        yylhs.value.as < Tree > () = boxIdent(self._lexer->YYText());
        setUseProp(yylhs.value.as < Tree > (), self._streamName.c_str(), self._lexer->lineno());
      }
    break;

  case 283: // statement.identifier.waveform: IDENT
            { yylhs.value.as < Tree > () = tree(self._lexer->YYText()); }
    break;

  case 284: // statement.import: IMPORT LPAR primitive.string.unquoted RPAR ENDDEF
                                                                  { yylhs.value.as < Tree > () = importFile(yystack_[2].value.as < Tree > ()); }
    break;

  case 285: // statement.list: statement.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 286: // statement.list: statement.list.start.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 287: // statement.list: statement.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 288: // statement.list: statement.list.append.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 289: // statement.list.start: statement
                  {
          yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (), self._nil);
        }
    break;

  case 290: // statement.list.start.qualified: statement.math.precision.list statement
                                                {
          if (self.acceptdefinition(yystack_[1].value.as < int > ()))
            yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (), self._nil);
          else
            yylhs.value.as < Tree > () = self._nil;
        }
    break;

  case 291: // statement.list.append: statement.list statement
                                 {
          yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        }
    break;

  case 292: // statement.list.append.qualified: statement.list statement.math.precision.list statement
                                                               {
          if (self.acceptdefinition(yystack_[1].value.as < int > ()))
            yylhs.value.as < Tree > () = cons(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          else
            yylhs.value.as < Tree > ()=yystack_[2].value.as < Tree > ();
        }
    break;

  case 293: // statement.math.precision: FLOATMODE
                  { yylhs.value.as < int > () = 1; }
    break;

  case 294: // statement.math.precision: DOUBLEMODE
                   { yylhs.value.as < int > () = 2; }
    break;

  case 295: // statement.math.precision: QUADMODE
                 { yylhs.value.as < int > () = 4; }
    break;

  case 296: // statement.math.precision: FIXEDPOINTMODE
                       { yylhs.value.as < int > () = 8; }
    break;

  case 297: // statement.math.precision.list: statement.math.precision.list.start
          { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
    break;

  case 298: // statement.math.precision.list: statement.math.precision.list.append
          { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
    break;

  case 299: // statement.math.precision.list.start: statement.math.precision
            { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
    break;

  case 300: // statement.math.precision.list.append: statement.math.precision.list statement.math.precision
                                                                   {
              yylhs.value.as < int > () = yystack_[1].value.as < int > () | yystack_[0].value.as < int > ();
            }
    break;

  case 301: // statement.signal.pattern.rule: LPAR expression.composition.parallel RPAR ARROW expression ENDDEF
                                                                        { yylhs.value.as < Tree > () = cons(yystack_[4].value.as < Tree > (),yystack_[1].value.as < Tree > ()); }
    break;

  case 302: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 303: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 304: // statement.signal.pattern.rule.list.start: statement.signal.pattern.rule
                                      { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),self._nil); }
    break;

  case 305: // statement.signal.pattern.rule.list.append: statement.signal.pattern.rule.list statement.signal.pattern.rule
                                                                                      { yylhs.value.as < Tree > () = cons(yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ()); }
    break;



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
      YYLLOC_DEFAULT (error_token, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
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
  AbstractImplementation::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  AbstractImplementation::yytnamerr_ (const char *yystr)
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
  AbstractImplementation::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // AbstractImplementation::context.
  AbstractImplementation::context::context (const AbstractImplementation& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  AbstractImplementation::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  AbstractImplementation::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  AbstractImplementation::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  AbstractImplementation::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  AbstractImplementation::yy_syntax_error_arguments_ (const context& yyctx,
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
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
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
  AbstractImplementation::yysyntax_error_ (const context& yyctx) const
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


  const short AbstractImplementation::yypact_ninf_ = -474;

  const signed char AbstractImplementation::yytable_ninf_ = -4;

  const short
  AbstractImplementation::yypact_[] =
  {
      17,   -37,   -29,  -474,   -16,  -474,  -474,  -474,  -474,   447,
      91,  -474,  -474,    40,  -474,  -474,  -474,  -474,  -474,  -474,
     177,  -474,    39,  -474,  -474,  -474,  -474,  -474,   104,  -474,
    -474,  -474,   -21,  -474,   -73,   486,   486,   316,   -16,  -474,
    -474,   -24,   -13,  -474,  -474,  -474,  -474,  -474,  -474,   -11,
    -474,   486,   486,  -474,   104,  -474,  -474,  -474,    53,  -474,
      68,    38,  -474,  -474,  -474,  -474,  -474,  -474,   133,    -9,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,   101,   111,   142,   153,   158,   161,
     176,   195,   203,   211,   220,   226,   236,   242,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,   251,  -474,  -474,   486,   254,
     260,   191,   205,   283,  -474,  -474,   289,   292,   296,   301,
     302,   303,   244,  -474,  -474,  -474,    23,  -474,  -474,  -474,
     483,  -474,  -474,  -474,  -474,  -474,   589,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,    16,  -474,    59,   225,   272,   322,  -474,   245,
    -474,  -474,  -474,   355,   305,    89,  -474,   310,  -474,   330,
    -474,  -474,  -474,  -474,  -474,   193,   193,   193,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   308,
      30,   -21,   -21,   104,   352,   486,   308,   308,   308,   308,
     486,   486,   329,   331,   339,   486,  -474,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,  -474,
     308,   486,    44,  -474,   311,   315,   323,  -474,  -474,  -474,
     337,  -474,  -474,  -474,   347,   420,   -16,   -16,   360,   378,
     459,   460,   461,   466,   467,   468,   472,   473,   479,    45,
    -474,  -474,  -474,  -474,   412,   487,    56,   133,   154,  -474,
    -474,    41,  -474,  -474,  -474,   207,   557,   563,   565,   581,
      47,    82,   486,  -474,   -38,  -474,  -474,    44,    36,   582,
     483,   174,    49,  -474,   609,   628,   702,   719,   735,   376,
     748,   770,   786,   814,   835,   410,   798,   327,   392,   819,
     803,   281,  -474,   510,  -474,    62,  -474,  -474,  -474,  -474,
      44,   131,   131,   131,   486,  -474,    69,   169,   585,   587,
    -474,  -474,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   308,   639,  -474,  -474,  -474,   352,  -474,   486,  -474,
     486,   486,   486,   486,  -474,  -474,   590,  -474,  -474,   117,
     592,   308,  -474,    20,  -474,  -474,  -474,   603,  -474,  -474,
    -474,    44,  -474,  -474,  -474,   533,   537,   556,   355,   347,
     342,  -474,  -474,   685,   169,   169,   457,   653,   658,   105,
     107,   113,   670,   675,   623,  -474,   625,  -474,   290,   680,
     690,   695,   773,   598,  -474,  -474,  -474,  -474,    44,  -474,
     486,  -474,  -474,  -474,  -474,   118,  -474,  -474,  -474,  -474,
    -474,    60,  -474,  -474,   -21,   626,   629,   486,   486,   486,
    -474,  -474,  -474,   486,   486,  -474,   486,   486,  -474,   486,
     486,   486,   486,   486,   122,    95,   347,   411,   164,  -474,
     630,  -474,  -474,   867,   884,   900,   299,   306,   237,   703,
     246,   252,   267,   279,   243,  -474,  -474,   705,  -474,    80,
    -474,  -474,   486,   486,   486,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,   438,  -474,   905,   934,   939,  -474,
     171,   486,   486,   486,  -474,   324,   333,   341,  -474,  -474,
    -474
  };

  const short
  AbstractImplementation::yydefact_[] =
  {
       0,     0,     0,   282,     0,   293,   294,   295,   296,    10,
       0,   289,   256,     0,   261,   262,   263,   257,   258,   259,
       0,   260,     0,   285,   286,   287,   288,   299,     0,   297,
     298,   269,     0,   281,     0,     0,     0,     0,     0,    11,
      15,     0,     4,     5,     6,     7,     9,     8,     1,     0,
     265,     0,     0,   291,     0,   290,   300,   184,     0,   183,
       0,     0,   112,   113,   116,   114,   115,   117,   130,   131,
     168,   132,   133,   134,   167,   169,   138,   139,   143,   166,
     164,   165,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,   150,
     151,   152,   153,   154,   155,   156,   140,   141,   142,   144,
     145,   118,   119,   120,   135,   136,   121,   122,   126,   217,
     218,   170,   171,   181,   182,     0,   193,   194,     0,     0,
       0,     0,     0,     0,   162,   163,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,    48,    28,    31,
      30,    35,    36,    33,    34,    49,    37,    43,    44,    45,
      63,    64,    65,    66,    47,    46,    50,    51,    52,    53,
      54,    27,    55,    56,   109,   111,   107,   127,   128,   129,
     108,   110,    57,    58,   158,   159,   160,    60,   173,   174,
     176,   188,   189,   175,   197,   198,   191,   208,   209,   210,
     192,   216,   215,   214,   177,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   179,   178,   180,   187,   190,
      26,    59,     0,    18,     0,     0,     0,     0,    19,     0,
     280,    12,   266,     0,    31,     0,   292,     0,   278,     0,
     146,   147,   148,   149,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,    14,     0,     0,     0,    17,    20,    16,
       0,   267,   284,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,   157,     0,     0,     0,     0,     0,   205,
     204,     0,   206,   202,   203,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,   302,   303,     0,     0,    32,
      41,    38,    40,    39,    73,    74,    77,    75,    76,    78,
      67,    68,    80,    69,    70,    71,    79,    81,    82,    83,
      72,    85,    62,    31,   274,     0,   270,   271,   272,   273,
       0,     0,     0,     0,     0,   283,     0,     0,     0,     0,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,   106,    42,     0,   220,     0,   211,
       0,     0,     0,     0,   254,   255,    31,   172,   305,     0,
       0,     0,    96,     0,    99,   100,   101,     0,    84,    61,
     276,     0,   275,    24,    25,     0,     0,     0,   264,     0,
       0,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    95,     0,   207,     0,     0,
       0,     0,     0,     0,   268,   104,   105,    97,     0,   102,
       0,   277,    21,    22,    23,     0,   201,   249,   223,   195,
     196,     0,   221,   222,     0,     0,     0,     0,     0,     0,
     240,   241,   242,     0,     0,   219,     0,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,   252,   253,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,    98,   103,     0,   250,     0,
     224,   245,     0,     0,     0,   244,   243,    91,   213,    87,
      88,    89,    90,   301,     0,   247,     0,     0,     0,   251,
       0,     0,     0,     0,   248,     0,     0,     0,   237,   238,
     239
  };

  const short
  AbstractImplementation::yypgoto_[] =
  {
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
     574,  -102,   -27,  -474,   300,   -49,  -218,  -474,  -474,  -474,
    -474,  -474,   640,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,   351,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -251,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -250,   741,  -178,  -134,  -474,  -474,  -474,
     285,  -240,  -474,  -474,  -474,  -474,   401,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -473,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,   -18,  -290,  -474,
    -474,  -474,  -474,  -474,  -341,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,   -23,     0,  -414,  -474,   555,  -474,  -474,  -474,
    -474,   -25,     1,  -474,  -474,   465,  -474,  -474,  -474
  };

  const short
  AbstractImplementation::yydefgoto_[] =
  {
       0,    10,    41,    42,    43,    44,    45,    46,    47,   227,
     228,   445,   233,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   329,   330,   331,
     171,   433,   434,   435,   436,   437,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    60,    58,   453,   190,   191,   192,
     488,   193,   194,   195,   490,   341,   342,   343,   344,   196,
     197,   198,   199,   200,   201,   202,   203,   491,   492,   493,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   315,   216,   217,   218,   219,    11,    12,    13,
      14,    15,   220,    16,   385,   386,   387,   388,   389,    17,
      18,    19,    34,   221,   396,    21,    22,    23,    24,    25,
      26,    27,   390,    29,    30,   353,   354,   355,   356
  };

  const short
  AbstractImplementation::yytable_[] =
  {
      20,    28,   234,    56,    53,   314,   316,   317,   146,   222,
      55,    61,   384,   339,   340,   229,   429,    -3,     1,   273,
     274,   430,    20,    54,   275,   235,   273,   274,    20,    56,
      59,   275,    33,   273,   274,   485,   236,   430,   275,    -2,
       1,    49,    31,   352,   539,     1,   427,   345,   431,   416,
     273,   274,    32,   411,    20,   275,   279,     1,   280,   360,
     361,   362,   363,     1,   431,   242,   243,   384,   518,   244,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   560,    57,   334,   335,   273,   274,   449,   518,    33,
     275,    48,   273,   274,   230,   440,     3,   275,   273,   274,
     442,   260,   537,   275,   477,     1,     2,   478,   273,   274,
     273,   274,   333,   275,   231,   275,   273,   274,     1,    50,
     432,   275,     3,     1,     4,   417,   232,   412,     2,   424,
       5,     6,     7,     8,     9,   237,   516,   514,   303,   440,
     415,    59,   519,   276,     3,     2,     4,   238,   439,     3,
     450,   481,     5,     6,     7,     8,     9,     5,     6,     7,
       8,     3,   555,     4,   425,   339,   340,     3,   311,     5,
       6,     7,     8,     9,   536,     5,     6,     7,     8,   518,
     278,   279,   245,   280,   456,   457,   458,   500,   384,   501,
     462,   463,   246,     2,   304,   502,    82,    83,   486,   517,
     468,   474,   469,   470,   471,   472,   535,   240,   241,     3,
     489,     4,   277,   278,   279,   418,   280,     5,     6,     7,
       8,     9,     3,   247,   440,    82,    83,     3,   242,   243,
       5,     6,     7,     8,   248,     5,     6,     7,     8,   249,
     273,   274,   250,   350,   351,   275,   273,   274,   359,   273,
     274,   275,   383,   564,   275,   273,   274,   251,    51,   332,
     275,   443,   444,    20,    28,    52,   346,   347,   348,   349,
     273,   274,   451,   452,   263,   275,   252,   489,   489,   523,
     524,   525,   273,   274,   253,   526,   527,   275,   264,   419,
     446,   447,   254,   398,   399,   277,   278,   279,   507,   280,
     382,   255,    20,   426,   277,   278,   279,   256,   280,   299,
     300,   277,   278,   279,   489,   280,   520,   257,    53,   547,
     495,   496,   553,   258,   556,   557,   558,   272,   549,   277,
     278,   279,   259,   280,   550,   261,    20,    54,   277,   278,
     279,   262,   280,   565,   566,   567,   277,   278,   279,   551,
     280,   295,   296,   297,   298,   299,   300,    20,   273,   274,
     305,   552,   301,   275,   265,    56,   302,   448,   337,   338,
     266,   309,   508,   267,    82,    83,   486,   268,   459,   460,
     461,   545,   269,   270,   271,    20,   441,   310,   546,   312,
      20,    -4,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   568,   306,   301,   313,
     352,   465,   302,     3,   357,   569,    56,   296,   297,   298,
     299,   300,   358,   570,   487,   394,   123,   124,   397,    20,
     441,   476,   293,   294,   295,   296,   297,   298,   299,   300,
     223,    20,   400,    82,    83,   486,   307,   391,   224,   225,
     226,   392,   395,   515,   224,   225,   226,   301,   529,   393,
     401,   302,   277,   278,   279,   497,   280,   402,   403,   404,
      82,    83,   486,   301,   405,   406,   407,   302,    20,   528,
     408,   409,   530,   531,   532,   533,   534,   410,   277,   278,
     279,   301,   280,   538,   413,   302,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    20,   441,    80,    81,    82,    83,
     559,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   420,    35,   128,    36,   414,
      37,   421,    38,   422,    39,    40,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   423,
     275,     3,   438,   454,   142,   455,   143,   144,   145,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,    -4,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,    -4,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   277,   278,
     279,   498,   280,   277,   278,   279,   499,   280,   466,   482,
     301,   475,   473,   483,   302,   277,   278,   279,   503,   280,
     277,   278,   279,   504,   280,   277,   278,   279,   509,   280,
     301,   480,   484,   494,   302,   277,   278,   279,   510,   280,
     277,   278,   279,   511,   280,   505,   506,   513,   521,   301,
     464,   522,   541,   302,    -4,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,    -4,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,    -4,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   277,   278,
     279,   512,   280,   301,   479,   548,   554,   302,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   308,   239,   540,   302,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   467,   336,   428,
     302,   294,   295,   296,   297,   298,   299,   300,     0,   301,
     298,   299,   300,   302,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,     0,   297,   298,   299,   300,     0,
       0,   301,     0,     0,     0,   302,   292,   293,   294,   295,
     296,   297,   298,   299,   300,     0,     0,   301,     0,     0,
       0,   302,   277,   278,   279,   542,   280,     0,     0,   301,
       0,     0,     0,   302,   301,     0,     0,     0,   302,   277,
     278,   279,   543,   280,     0,   301,     0,     0,     0,   302,
     301,     0,     0,     0,   302,   277,   278,   279,   544,   280,
     277,   278,   279,   561,   280,     0,   301,     0,     0,     0,
     302,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   277,
     278,   279,   562,   280,   277,   278,   279,   563,   280
  };

  const short
  AbstractImplementation::yycheck_[] =
  {
       0,     0,    51,    28,    22,   245,   246,   247,    35,    36,
      28,    34,   302,   264,   264,    38,   357,     0,     1,     3,
       4,     1,    22,    22,     8,    52,     3,     4,    28,    54,
     103,     8,   105,     3,     4,   449,    54,     1,     8,     0,
       1,     1,    79,    81,   517,     1,    84,   265,    28,     8,
       3,     4,    81,     8,    54,     8,     7,     1,     9,   277,
     278,   279,   280,     1,    28,    74,    75,   357,     8,    69,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   554,   103,   261,   262,     3,     4,    18,     8,   105,
       8,     0,     3,     4,   118,   385,   105,     8,     3,     4,
     390,   128,   516,     8,    84,     1,    89,    87,     3,     4,
       3,     4,    82,     8,   127,     8,     3,     4,     1,    79,
      84,     8,   105,     1,   107,    84,   137,    82,    89,    82,
     113,   114,   115,   116,   117,    82,    18,   478,   122,   429,
      84,   103,    82,   120,   105,    89,   107,    79,    86,   105,
      81,   441,   113,   114,   115,   116,   117,   113,   114,   115,
     116,   105,    82,   107,    82,   416,   416,   105,    79,   113,
     114,   115,   116,   117,    79,   113,   114,   115,   116,     8,
       6,     7,    81,     9,   402,   403,   404,    82,   478,    82,
     408,   409,    81,    89,   135,    82,    32,    33,    34,    81,
     418,    84,   420,   421,   422,   423,    84,    74,    75,   105,
     450,   107,     5,     6,     7,     8,     9,   113,   114,   115,
     116,   117,   105,    81,   514,    32,    33,   105,    74,    75,
     113,   114,   115,   116,    81,   113,   114,   115,   116,    81,
       3,     4,    81,   270,   271,     8,     3,     4,   275,     3,
       4,     8,   301,    82,     8,     3,     4,    81,    81,   259,
       8,   130,   131,   263,   263,    88,   266,   267,   268,   269,
       3,     4,   103,   104,    83,     8,    81,   517,   518,   497,
     498,   499,     3,     4,    81,   503,   504,     8,    83,    82,
     392,   393,    81,   316,   317,     5,     6,     7,     8,     9,
     300,    81,   302,   352,     5,     6,     7,    81,     9,    28,
      29,     5,     6,     7,   554,     9,   494,    81,   336,    82,
     454,   455,    79,    81,   542,   543,   544,    83,    82,     5,
       6,     7,    81,     9,    82,    81,   336,   336,     5,     6,
       7,    81,     9,   561,   562,   563,     5,     6,     7,    82,
       9,    24,    25,    26,    27,    28,    29,   357,     3,     4,
     135,    82,    81,     8,    81,   390,    85,   394,    16,    17,
      81,   126,    82,    81,    32,    33,    34,    81,   405,   406,
     407,    82,    81,    81,    81,   385,   385,    82,    82,    79,
     390,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    82,   135,    81,    79,
      81,   411,    85,   105,    83,    82,   441,    25,    26,    27,
      28,    29,    83,    82,    82,    88,    74,    75,     8,   429,
     429,   431,    22,    23,    24,    25,    26,    27,    28,    29,
     124,   441,    82,    32,    33,    34,   124,   136,   132,   133,
     134,   136,   105,   480,   132,   133,   134,    81,   507,   136,
      82,    85,     5,     6,     7,     8,     9,     8,     8,     8,
      32,    33,    34,    81,     8,     8,     8,    85,   478,   506,
       8,     8,   509,   510,   511,   512,   513,     8,     5,     6,
       7,    81,     9,    82,    82,    85,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   514,   514,    30,    31,    32,    33,
      82,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     8,   119,    81,   121,    82,
     123,     8,   125,     8,   127,   128,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     8,
       8,   105,    82,     8,   108,     8,   110,   111,   112,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     5,     6,
       7,     8,     9,     5,     6,     7,     8,     9,    29,   136,
      81,    79,    82,   136,    85,     5,     6,     7,     8,     9,
       5,     6,     7,     8,     9,     5,     6,     7,     8,     9,
      81,    88,   136,     8,    85,     5,     6,     7,     8,     9,
       5,     6,     7,     8,     9,    82,    81,   109,    82,    81,
     410,    82,    82,    85,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     5,     6,
       7,     8,     9,    81,   433,    82,    81,    85,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      81,   227,    61,   518,    85,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    81,   416,   263,   354,
      85,    23,    24,    25,    26,    27,    28,    29,    -1,    81,
      27,    28,    29,    85,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    26,    27,    28,    29,    -1,
      -1,    81,    -1,    -1,    -1,    85,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    81,    -1,    -1,
      -1,    85,     5,     6,     7,     8,     9,    -1,    -1,    81,
      -1,    -1,    -1,    85,    81,    -1,    -1,    -1,    85,     5,
       6,     7,     8,     9,    -1,    81,    -1,    -1,    -1,    85,
      81,    -1,    -1,    -1,    85,     5,     6,     7,     8,     9,
       5,     6,     7,     8,     9,    -1,    81,    -1,    -1,    -1,
      85,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     5,
       6,     7,     8,     9,     5,     6,     7,     8,     9
  };

  const short
  AbstractImplementation::yystos_[] =
  {
       0,     1,    89,   105,   107,   113,   114,   115,   116,   117,
     139,   245,   246,   247,   248,   249,   251,   257,   258,   259,
     261,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,    79,    81,   105,   260,   119,   121,   123,   125,   127,
     128,   140,   141,   142,   143,   144,   145,   146,     0,     1,
      79,    81,    88,   245,   270,   245,   269,   103,   203,   103,
     202,   260,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      30,    31,    32,    33,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    81,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   108,   110,   111,   112,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   178,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     205,   206,   207,   209,   210,   211,   217,   218,   219,   220,
     221,   222,   223,   224,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   241,   242,   243,   244,
     250,   261,   150,   124,   132,   133,   134,   147,   148,   260,
     118,   127,   137,   150,   153,   150,   245,    82,    79,   202,
      74,    75,    74,    75,   261,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
     150,    81,    81,    83,    83,    81,    81,    81,    81,    81,
      81,    81,    83,     3,     4,     8,   120,     5,     6,     7,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    81,    85,   122,   135,   135,   135,   124,   148,   126,
      82,    79,    79,    79,   209,   240,   209,   209,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   175,
     176,   177,   261,    82,   203,   203,   264,    16,    17,   192,
     201,   213,   214,   215,   216,   154,   261,   261,   261,   261,
     150,   150,    81,   273,   274,   275,   276,    83,    83,   150,
     154,   154,   154,   154,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   261,   153,   246,   252,   253,   254,   255,   256,
     270,   136,   136,   136,    88,   105,   262,     8,   260,   260,
      82,    82,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,    82,    82,    82,    84,     8,    84,     8,    82,
       8,     8,     8,     8,    82,    82,   153,    84,   273,   252,
       1,    28,    84,   179,   180,   181,   182,   183,    82,    86,
     246,   270,   246,   130,   131,   149,   149,   149,   150,    18,
      81,   103,   104,   204,     8,     8,   154,   154,   154,   150,
     150,   150,   154,   154,   152,   261,    29,   214,   154,   154,
     154,   154,   154,    82,    84,    79,   261,    84,    87,   182,
      88,   246,   136,   136,   136,   262,    34,    82,   208,   209,
     212,   225,   226,   227,     8,   204,   204,     8,     8,     8,
      82,    82,    82,     8,     8,    82,    81,     8,    82,     8,
       8,     8,     8,   109,   252,   150,    18,    81,     8,    82,
     203,    82,    82,   154,   154,   154,   154,   154,   150,   153,
     150,   150,   150,   150,   150,    84,    79,   262,    82,   225,
     208,    82,     8,     8,     8,    82,    82,    82,    82,    82,
      82,    82,    82,    79,    81,    82,   154,   154,   154,    82,
     225,     8,     8,     8,    82,   154,   154,   154,    82,    82,
      82
  };

  const short
  AbstractImplementation::yyr1_[] =
  {
       0,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   142,   143,   144,   145,   146,   146,   147,
     147,   148,   148,   148,   149,   149,   150,   150,   150,   151,
     152,   152,   153,   154,   154,   154,   154,   154,   155,   156,
     157,   158,   159,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   161,   162,   163,   163,   163,   163,   164,   164,   164,
     164,   164,   164,   165,   165,   165,   165,   165,   165,   166,
     166,   166,   167,   167,   168,   169,   169,   170,   171,   172,
     173,   174,   175,   175,   176,   177,   178,   178,   178,   179,
     179,   180,   181,   182,   182,   183,   184,   185,   185,   185,
     185,   185,   186,   186,   186,   186,   186,   186,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   188,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   189,   190,   190,
     191,   191,   191,   191,   191,   191,   192,   192,   192,   192,
     193,   193,   193,   193,   193,   193,   193,   194,   195,   195,
     195,   196,   196,   196,   197,   197,   197,   198,   198,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   200,   200,
     200,   201,   201,   202,   203,   204,   204,   205,   205,   205,
     205,   205,   205,   206,   207,   208,   208,   209,   209,   210,
     211,   212,   213,   213,   214,   214,   215,   216,   217,   217,
     217,   218,   219,   220,   221,   221,   221,   222,   222,   223,
     224,   225,   225,   226,   227,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   240,   240,   240,
     240,   240,   241,   242,   243,   244,   245,   245,   245,   245,
     245,   246,   246,   246,   247,   248,   248,   249,   250,   251,
     252,   252,   252,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   264,   264,   264,   265,
     266,   267,   268,   269,   269,   269,   269,   270,   270,   271,
     272,   273,   274,   274,   275,   276
  };

  const signed char
  AbstractImplementation::yyr2_[] =
  {
       0,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     3,     3,     1,     3,     3,     2,     1,
       2,     5,     5,     5,     1,     1,     1,     1,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     2,     8,     8,     8,
       8,     8,     1,     1,     1,     3,     4,     5,     7,     1,
       1,     1,     2,     4,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     4,     6,     8,     1,     1,     1,     1,     1,     6,
       4,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,    12,    12,    12,
       6,     6,     6,     8,     8,     8,     5,     7,     9,     4,
       6,     8,     7,     7,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     2,     3,     4,     5,     2,
       1,     1,     1,     1,     1,     2,     2,     3,     4,     5,
       3,     1,     1,     1,     5,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     6,     1,     1,     1,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const AbstractImplementation::yytname_[] =
  {
  "ENDOFINPUT", "error", "\"invalid token\"", "WITH", "LETREC", "SPLIT",
  "MIX", "SEQ", "COMMA", "REC", "LT", "LE", "EQ", "GT", "GE", "NE", "ADD",
  "SUB", "OR", "MUL", "DIV", "MOD", "AND", "XOR", "LSH", "RSH", "POWOP",
  "FDELAY", "DELAY1", "DOT", "MEM", "PREFIX", "INTCAST", "FLOATCAST",
  "ANYCAST", "FFUNCTION", "FCONSTANT", "FVARIABLE", "BUTTON", "CHECKBOX",
  "VSLIDER", "HSLIDER", "NENTRY", "VGROUP", "HGROUP", "TGROUP",
  "HBARGRAPH", "VBARGRAPH", "SOUNDFILE", "ATTACH", "ACOS", "ASIN", "ATAN",
  "ATAN2", "COS", "SIN", "TAN", "EXP", "LOG", "LOG10", "POWFUN", "SQRT",
  "ABS", "MIN", "MAX", "FMOD", "REMAINDER", "FLOOR", "CEIL", "RINT",
  "RDTBL", "RWTBL", "SELECT2", "SELECT3", "INT", "FLOAT", "LAMBDA", "WIRE",
  "CUT", "ENDDEF", "VIRG", "LPAR", "RPAR", "LBRAQ", "RBRAQ", "LCROC",
  "RCROC", "WHERE", "DEF", "IMPORT", "COMPONENT", "LIBRARY", "ENVIRONMENT",
  "WAVEFORM", "ROUTE", "ENABLE", "CONTROL", "ITERATE_PARALLEL", "ISEQ",
  "ISUM", "IPROD", "INPUTS", "OUTPUTS", "STRING", "TAGSTRING", "IDENT",
  "EXTRA", "DECLARE", "CASE", "ARROW", "ASSERTBOUNDS", "LOWEST", "HIGHEST",
  "FLOATMODE", "DOUBLEMODE", "QUADMODE", "FIXEDPOINTMODE", "BDOC", "EDOC",
  "BEQN", "EEQN", "BDGM", "EDGM", "BLST", "ELST", "BMETADATA", "EMETADATA",
  "DOCCHAR", "NOTICE", "LISTING", "LSTTRUE", "LSTFALSE", "LSTDEPENDENCIES",
  "LSTMDOCTAGS", "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "ENDL", "$accept",
  "program", "doc", "doc.text", "doc.equation", "doc.diagram",
  "doc.notice", "doc.metadata", "doc.list", "doc.attribute.list",
  "doc.attribute.definition", "doc.attribute.value", "expression",
  "expression.component", "expression.composition",
  "expression.composition.parallel", "expression.composition.serial",
  "expression.composition.mix", "expression.composition.recursive",
  "expression.composition.sequence", "expression.composition.split",
  "expression.environment", "expression.infix",
  "expression.infix.definitions.substitution",
  "expression.infix.environment.access", "expression.infix.math",
  "expression.infix.math.algebra", "expression.infix.math.comparison",
  "expression.infix.math.logic", "expression.infix.math.shift",
  "expression.infix.prefix", "expression.infix.signal.delay",
  "expression.iterate.parallel", "expression.iterate.sequence",
  "expression.iterate.sum", "expression.iterate.product",
  "expression.lambda", "expression.lambda.params",
  "expression.lambda.params.start", "expression.lambda.params.append",
  "expression.letrec", "expression.letrec.list",
  "expression.letrec.list.start", "expression.letrec.list.append",
  "expression.letrec.equation", "expression.letrec.equation.name",
  "expression.library", "expression.math", "expression.math.comparison",
  "expression.math.rounding", "expression.math.signal",
  "expression.math.signal.algebra", "expression.math.signal.shift",
  "expression.math.signal.power", "expression.math.scalar",
  "expression.math.trigonometry", "expression.parenthesis",
  "expression.signal", "expression.signal.control",
  "expression.signal.delay", "expression.signal.logic", "primitive",
  "primitive.foreign", "primitive.number", "primitive.string.quoted",
  "primitive.string.unquoted", "primitive.string.tag", "primitive.signal",
  "primitive.signal.input.wire", "primitive.signal.input.terminate",
  "primitive.type", "primitive.type.number", "primitive.type.number.int",
  "primitive.type.number.float", "primitive.type.any",
  "primitive.type.number.list", "primitive.type.number.list.member",
  "primitive.type.number.list.start", "primitive.type.number.list.append",
  "primitive.signal.route", "primitive.signal.route.implied.outputs",
  "primitive.signal.route.implied.connections",
  "primitive.signal.route.explicit", "primitive.signal.source",
  "primitive.signal.source.table", "primitive.signal.source.soundfile",
  "primitive.signal.source.waveform", "primitive.type.list",
  "primitive.type.list.start", "primitive.type.list.append",
  "primitive.ui", "primitive.ui.button", "primitive.ui.checkbox",
  "primitive.ui.vslider", "primitive.ui.hslider", "primitive.ui.nentry",
  "primitive.ui.vgroup", "primitive.ui.hgroup", "primitive.ui.tgroup",
  "primitive.ui.vbargraph", "primitive.ui.hbargraph",
  "primitive.foreign.function", "primitive.foreign.function.signature",
  "primitive.foreign.constant", "primitive.foreign.variable",
  "primitive.signal.inputs", "primitive.signal.outputs", "statement",
  "statement.definition", "statement.definition.function.incomplete",
  "statement.definition.function", "statement.definition.assignment",
  "statement.definition.with", "statement.definition.error",
  "statement.definition.list", "statement.definition.list.start",
  "statement.definition.list.start.qualified",
  "statement.definition.list.append",
  "statement.definition.list.append.qualified",
  "statement.declare.metadata", "statement.declare.feature.metadata",
  "statement.declare.doc", "statement.identifier",
  "statement.identifier.box", "statement.identifier.waveform",
  "statement.import", "statement.list", "statement.list.start",
  "statement.list.start.qualified", "statement.list.append",
  "statement.list.append.qualified", "statement.math.precision",
  "statement.math.precision.list", "statement.math.precision.list.start",
  "statement.math.precision.list.append", "statement.signal.pattern.rule",
  "statement.signal.pattern.rule.list",
  "statement.signal.pattern.rule.list.start",
  "statement.signal.pattern.rule.list.append", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  AbstractImplementation::yyrline_[] =
  {
       0,   423,   423,   427,   438,   442,   443,   444,   445,   446,
     447,   450,   451,   454,   457,   460,   463,   468,   469,   472,
     473,   476,   479,   484,   489,   490,   497,   498,   499,   504,
     511,   512,   515,   520,   521,   522,   523,   524,   527,   532,
     537,   542,   568,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   592,
     594,   597,   605,   608,   609,   610,   611,   614,   615,   616,
     617,   618,   619,   624,   625,   626,   627,   628,   629,   632,
     633,   634,   637,   638,   643,   646,   647,   652,   657,   662,
     667,   674,   679,   680,   683,   686,   691,   698,   705,   716,
     717,   720,   723,   726,   730,   733,   739,   744,   745,   746,
     747,   748,   751,   752,   753,   754,   755,   756,   759,   760,
     761,   762,   763,   764,   765,   766,   767,   770,   771,   772,
     775,   776,   777,   778,   779,   780,   781,   782,   785,   786,
     789,   790,   791,   792,   793,   794,   797,   798,   799,   800,
     803,   804,   805,   806,   807,   808,   809,   814,   819,   820,
     821,   824,   825,   826,   829,   830,   831,   834,   835,   836,
     837,   838,   839,   848,   849,   850,   851,   852,   857,   858,
     859,   864,   865,   870,   873,   876,   877,   882,   883,   884,
     885,   886,   887,   890,   893,   896,   897,   902,   903,   906,
     909,   912,   917,   918,   921,   924,   929,   932,   937,   938,
     939,   942,   947,   952,   963,   964,   965,   968,   969,   972,
     977,   986,   987,   990,   993,   999,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1011,  1014,  1017,  1022,  1027,
    1032,  1035,  1038,  1041,  1046,  1053,  1058,  1061,  1064,  1067,
    1070,  1073,  1078,  1083,  1090,  1093,  1101,  1102,  1103,  1104,
    1105,  1110,  1111,  1112,  1115,  1124,  1127,  1134,  1147,  1152,
    1160,  1161,  1162,  1163,  1166,  1171,  1179,  1184,  1194,  1200,
    1206,  1214,  1220,  1226,  1231,  1236,  1237,  1238,  1239,  1242,
    1247,  1255,  1260,  1270,  1271,  1272,  1273,  1278,  1279,  1282,
    1285,  1292,  1297,  1298,  1301,  1304
  };

  void
  AbstractImplementation::yy_stack_print_ () const
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
  AbstractImplementation::yy_reduce_print_ (int yyrule) const
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
#endif // YYDEBUG


} } } // ::Faust::Compiler::Parser


