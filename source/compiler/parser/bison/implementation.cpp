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
#include "tlib/list.hh"

#include "compiler/errors/errormsg.hh"
#include "compiler/block_diagram/boxes/boxes.hh"
#include "compiler/signals/tree.hh"
#include "compiler/signals/prim2.hh"
#include "compiler/file_handling/sourcereader.hh"

#include "documentator/doc.hh"

#include "faust/primitive/math.hh"
#include "faust/primitive/math/functions.hh"

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
  BisonImplementation::BisonImplementation (Implementation& self_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      self (self_yyarg)
  {}

  BisonImplementation::~BisonImplementation ()
  {}

  BisonImplementation::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  BisonImplementation::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  BisonImplementation::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  BisonImplementation::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  BisonImplementation::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  BisonImplementation::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  BisonImplementation::symbol_kind_type
  BisonImplementation::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  BisonImplementation::stack_symbol_type::stack_symbol_type ()
  {}

  BisonImplementation::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_195_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_207_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_233_primitive_type_number_float_list_member: // primitive.type.number.float.list.member
        value.YY_MOVE_OR_COPY< FloatType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_225_primitive_type_number_int_list_member: // primitive.type.number.int.list.member
      case symbol_kind::S_298_statement_math_precision: // statement.math.precision
      case symbol_kind::S_299_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_300_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_301_statement_math_precision_list_append: // statement.math.precision.list.append
        value.YY_MOVE_OR_COPY< IntType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
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
      case symbol_kind::S_192_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_194_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_196_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_197_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_198_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_199_expression_signal: // expression.signal
      case symbol_kind::S_200_expression_signal_control: // expression.signal.control
      case symbol_kind::S_201_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_202_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_204_primitive_foreign: // primitive.foreign
      case symbol_kind::S_205_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_208_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_209_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_211_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_213_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_215_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_216_primitive_signal: // primitive.signal
      case symbol_kind::S_217_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_218_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_219_primitive_type: // primitive.type
      case symbol_kind::S_220_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_221_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_222_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_223_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_229_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_237_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_240_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_241_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_242_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_243_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_244_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_245_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_246_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_247_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_248_primitive_signal_source_waveform_int_as_tree: // primitive.signal.source.waveform.int.as.tree
      case symbol_kind::S_249_primitive_signal_source_waveform_float_as_tree: // primitive.signal.source.waveform.float.as.tree
      case symbol_kind::S_250_primitive_type_list: // primitive.type.list
      case symbol_kind::S_251_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_252_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_253_primitive_ui: // primitive.ui
      case symbol_kind::S_254_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_255_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_256_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_257_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_258_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_259_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_260_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_261_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_262_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_263_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_264_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_265_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_266_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_267_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_268_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_269_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_271_statement_definition: // statement.definition
      case symbol_kind::S_272_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_273_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_274_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_275_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_276_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_277_statement_definition_function: // statement.definition.function
      case symbol_kind::S_278_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_279_statement_definition_with: // statement.definition.with
      case symbol_kind::S_280_statement_definition_error: // statement.definition.error
      case symbol_kind::S_281_statement_definition_list: // statement.definition.list
      case symbol_kind::S_282_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_283_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_284_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_285_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_286_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_287_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_288_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_289_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_290_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_291_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_292_statement_import: // statement.import
      case symbol_kind::S_293_statement_list: // statement.list
      case symbol_kind::S_294_statement_list_start: // statement.list.start
      case symbol_kind::S_295_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_296_statement_list_append: // statement.list.append
      case symbol_kind::S_297_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_302_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_303_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_304_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_305_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.YY_MOVE_OR_COPY< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
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
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
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
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_210_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_212_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_214_primitive_string_tag: // primitive.string.tag
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_232_primitive_type_number_float_list: // primitive.type.number.float.list
      case symbol_kind::S_234_primitive_type_number_float_list_start: // primitive.type.number.float.list.start
      case symbol_kind::S_235_primitive_type_number_float_list_append: // primitive.type.number.float.list.append
        value.YY_MOVE_OR_COPY< std::vector<FloatType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_224_primitive_type_number_int_list: // primitive.type.number.int.list
      case symbol_kind::S_226_primitive_type_number_int_list_start: // primitive.type.number.int.list.start
      case symbol_kind::S_227_primitive_type_number_int_list_append: // primitive.type.number.int.list.append
        value.YY_MOVE_OR_COPY< std::vector<IntType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_228_primitive_type_number_int_list_as_tree: // primitive.type.number.int.list.as.tree
      case symbol_kind::S_230_primitive_type_number_int_list_start_as_tree: // primitive.type.number.int.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_int_list_append_as_tree: // primitive.type.number.int.list.append.as.tree
      case symbol_kind::S_236_primitive_type_number_float_list_as_tree: // primitive.type.number.float.list.as.tree
      case symbol_kind::S_238_primitive_type_number_float_list_start_as_tree: // primitive.type.number.float.list.start.as.tree
      case symbol_kind::S_239_primitive_type_number_float_list_append_as_tree: // primitive.type.number.float.list.append.as.tree
        value.YY_MOVE_OR_COPY< std::vector<Tree> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  BisonImplementation::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_195_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_207_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_233_primitive_type_number_float_list_member: // primitive.type.number.float.list.member
        value.move< FloatType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_225_primitive_type_number_int_list_member: // primitive.type.number.int.list.member
      case symbol_kind::S_298_statement_math_precision: // statement.math.precision
      case symbol_kind::S_299_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_300_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_301_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< IntType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
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
      case symbol_kind::S_192_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_194_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_196_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_197_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_198_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_199_expression_signal: // expression.signal
      case symbol_kind::S_200_expression_signal_control: // expression.signal.control
      case symbol_kind::S_201_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_202_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_204_primitive_foreign: // primitive.foreign
      case symbol_kind::S_205_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_208_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_209_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_211_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_213_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_215_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_216_primitive_signal: // primitive.signal
      case symbol_kind::S_217_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_218_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_219_primitive_type: // primitive.type
      case symbol_kind::S_220_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_221_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_222_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_223_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_229_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_237_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_240_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_241_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_242_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_243_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_244_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_245_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_246_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_247_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_248_primitive_signal_source_waveform_int_as_tree: // primitive.signal.source.waveform.int.as.tree
      case symbol_kind::S_249_primitive_signal_source_waveform_float_as_tree: // primitive.signal.source.waveform.float.as.tree
      case symbol_kind::S_250_primitive_type_list: // primitive.type.list
      case symbol_kind::S_251_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_252_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_253_primitive_ui: // primitive.ui
      case symbol_kind::S_254_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_255_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_256_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_257_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_258_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_259_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_260_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_261_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_262_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_263_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_264_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_265_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_266_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_267_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_268_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_269_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_271_statement_definition: // statement.definition
      case symbol_kind::S_272_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_273_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_274_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_275_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_276_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_277_statement_definition_function: // statement.definition.function
      case symbol_kind::S_278_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_279_statement_definition_with: // statement.definition.with
      case symbol_kind::S_280_statement_definition_error: // statement.definition.error
      case symbol_kind::S_281_statement_definition_list: // statement.definition.list
      case symbol_kind::S_282_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_283_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_284_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_285_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_286_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_287_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_288_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_289_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_290_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_291_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_292_statement_import: // statement.import
      case symbol_kind::S_293_statement_list: // statement.list
      case symbol_kind::S_294_statement_list_start: // statement.list.start
      case symbol_kind::S_295_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_296_statement_list_append: // statement.list.append
      case symbol_kind::S_297_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_302_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_303_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_304_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_305_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.move< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.move< bool > (YY_MOVE (that.value));
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
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
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
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_210_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_212_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_214_primitive_string_tag: // primitive.string.tag
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_232_primitive_type_number_float_list: // primitive.type.number.float.list
      case symbol_kind::S_234_primitive_type_number_float_list_start: // primitive.type.number.float.list.start
      case symbol_kind::S_235_primitive_type_number_float_list_append: // primitive.type.number.float.list.append
        value.move< std::vector<FloatType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_224_primitive_type_number_int_list: // primitive.type.number.int.list
      case symbol_kind::S_226_primitive_type_number_int_list_start: // primitive.type.number.int.list.start
      case symbol_kind::S_227_primitive_type_number_int_list_append: // primitive.type.number.int.list.append
        value.move< std::vector<IntType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_228_primitive_type_number_int_list_as_tree: // primitive.type.number.int.list.as.tree
      case symbol_kind::S_230_primitive_type_number_int_list_start_as_tree: // primitive.type.number.int.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_int_list_append_as_tree: // primitive.type.number.int.list.append.as.tree
      case symbol_kind::S_236_primitive_type_number_float_list_as_tree: // primitive.type.number.float.list.as.tree
      case symbol_kind::S_238_primitive_type_number_float_list_start_as_tree: // primitive.type.number.float.list.start.as.tree
      case symbol_kind::S_239_primitive_type_number_float_list_append_as_tree: // primitive.type.number.float.list.append.as.tree
        value.move< std::vector<Tree> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  BisonImplementation::stack_symbol_type&
  BisonImplementation::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_195_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_207_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_233_primitive_type_number_float_list_member: // primitive.type.number.float.list.member
        value.copy< FloatType > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_225_primitive_type_number_int_list_member: // primitive.type.number.int.list.member
      case symbol_kind::S_298_statement_math_precision: // statement.math.precision
      case symbol_kind::S_299_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_300_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_301_statement_math_precision_list_append: // statement.math.precision.list.append
        value.copy< IntType > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
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
      case symbol_kind::S_192_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_194_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_196_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_197_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_198_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_199_expression_signal: // expression.signal
      case symbol_kind::S_200_expression_signal_control: // expression.signal.control
      case symbol_kind::S_201_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_202_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_204_primitive_foreign: // primitive.foreign
      case symbol_kind::S_205_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_208_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_209_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_211_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_213_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_215_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_216_primitive_signal: // primitive.signal
      case symbol_kind::S_217_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_218_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_219_primitive_type: // primitive.type
      case symbol_kind::S_220_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_221_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_222_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_223_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_229_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_237_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_240_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_241_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_242_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_243_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_244_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_245_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_246_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_247_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_248_primitive_signal_source_waveform_int_as_tree: // primitive.signal.source.waveform.int.as.tree
      case symbol_kind::S_249_primitive_signal_source_waveform_float_as_tree: // primitive.signal.source.waveform.float.as.tree
      case symbol_kind::S_250_primitive_type_list: // primitive.type.list
      case symbol_kind::S_251_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_252_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_253_primitive_ui: // primitive.ui
      case symbol_kind::S_254_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_255_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_256_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_257_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_258_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_259_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_260_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_261_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_262_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_263_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_264_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_265_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_266_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_267_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_268_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_269_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_271_statement_definition: // statement.definition
      case symbol_kind::S_272_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_273_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_274_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_275_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_276_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_277_statement_definition_function: // statement.definition.function
      case symbol_kind::S_278_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_279_statement_definition_with: // statement.definition.with
      case symbol_kind::S_280_statement_definition_error: // statement.definition.error
      case symbol_kind::S_281_statement_definition_list: // statement.definition.list
      case symbol_kind::S_282_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_283_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_284_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_285_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_286_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_287_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_288_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_289_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_290_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_291_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_292_statement_import: // statement.import
      case symbol_kind::S_293_statement_list: // statement.list
      case symbol_kind::S_294_statement_list_start: // statement.list.start
      case symbol_kind::S_295_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_296_statement_list_append: // statement.list.append
      case symbol_kind::S_297_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_302_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_303_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_304_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_305_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.copy< Tree > (that.value);
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.copy< bool > (that.value);
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
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
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
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_210_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_212_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_214_primitive_string_tag: // primitive.string.tag
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_232_primitive_type_number_float_list: // primitive.type.number.float.list
      case symbol_kind::S_234_primitive_type_number_float_list_start: // primitive.type.number.float.list.start
      case symbol_kind::S_235_primitive_type_number_float_list_append: // primitive.type.number.float.list.append
        value.copy< std::vector<FloatType> > (that.value);
        break;

      case symbol_kind::S_224_primitive_type_number_int_list: // primitive.type.number.int.list
      case symbol_kind::S_226_primitive_type_number_int_list_start: // primitive.type.number.int.list.start
      case symbol_kind::S_227_primitive_type_number_int_list_append: // primitive.type.number.int.list.append
        value.copy< std::vector<IntType> > (that.value);
        break;

      case symbol_kind::S_228_primitive_type_number_int_list_as_tree: // primitive.type.number.int.list.as.tree
      case symbol_kind::S_230_primitive_type_number_int_list_start_as_tree: // primitive.type.number.int.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_int_list_append_as_tree: // primitive.type.number.int.list.append.as.tree
      case symbol_kind::S_236_primitive_type_number_float_list_as_tree: // primitive.type.number.float.list.as.tree
      case symbol_kind::S_238_primitive_type_number_float_list_start_as_tree: // primitive.type.number.float.list.start.as.tree
      case symbol_kind::S_239_primitive_type_number_float_list_append_as_tree: // primitive.type.number.float.list.append.as.tree
        value.copy< std::vector<Tree> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  BisonImplementation::stack_symbol_type&
  BisonImplementation::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_195_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_207_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_233_primitive_type_number_float_list_member: // primitive.type.number.float.list.member
        value.move< FloatType > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_225_primitive_type_number_int_list_member: // primitive.type.number.int.list.member
      case symbol_kind::S_298_statement_math_precision: // statement.math.precision
      case symbol_kind::S_299_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_300_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_301_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< IntType > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
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
      case symbol_kind::S_192_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_194_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_196_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_197_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_198_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_199_expression_signal: // expression.signal
      case symbol_kind::S_200_expression_signal_control: // expression.signal.control
      case symbol_kind::S_201_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_202_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_204_primitive_foreign: // primitive.foreign
      case symbol_kind::S_205_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_208_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_209_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_211_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_213_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_215_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_216_primitive_signal: // primitive.signal
      case symbol_kind::S_217_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_218_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_219_primitive_type: // primitive.type
      case symbol_kind::S_220_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_221_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_222_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_223_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_229_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_237_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_240_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_241_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_242_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_243_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_244_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_245_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_246_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_247_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_248_primitive_signal_source_waveform_int_as_tree: // primitive.signal.source.waveform.int.as.tree
      case symbol_kind::S_249_primitive_signal_source_waveform_float_as_tree: // primitive.signal.source.waveform.float.as.tree
      case symbol_kind::S_250_primitive_type_list: // primitive.type.list
      case symbol_kind::S_251_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_252_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_253_primitive_ui: // primitive.ui
      case symbol_kind::S_254_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_255_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_256_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_257_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_258_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_259_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_260_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_261_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_262_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_263_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_264_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_265_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_266_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_267_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_268_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_269_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_271_statement_definition: // statement.definition
      case symbol_kind::S_272_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_273_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_274_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_275_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_276_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_277_statement_definition_function: // statement.definition.function
      case symbol_kind::S_278_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_279_statement_definition_with: // statement.definition.with
      case symbol_kind::S_280_statement_definition_error: // statement.definition.error
      case symbol_kind::S_281_statement_definition_list: // statement.definition.list
      case symbol_kind::S_282_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_283_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_284_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_285_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_286_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_287_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_288_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_289_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_290_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_291_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_292_statement_import: // statement.import
      case symbol_kind::S_293_statement_list: // statement.list
      case symbol_kind::S_294_statement_list_start: // statement.list.start
      case symbol_kind::S_295_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_296_statement_list_append: // statement.list.append
      case symbol_kind::S_297_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_302_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_303_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_304_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_305_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.move< Tree > (that.value);
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        value.move< bool > (that.value);
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
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
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
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_210_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_212_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_214_primitive_string_tag: // primitive.string.tag
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_232_primitive_type_number_float_list: // primitive.type.number.float.list
      case symbol_kind::S_234_primitive_type_number_float_list_start: // primitive.type.number.float.list.start
      case symbol_kind::S_235_primitive_type_number_float_list_append: // primitive.type.number.float.list.append
        value.move< std::vector<FloatType> > (that.value);
        break;

      case symbol_kind::S_224_primitive_type_number_int_list: // primitive.type.number.int.list
      case symbol_kind::S_226_primitive_type_number_int_list_start: // primitive.type.number.int.list.start
      case symbol_kind::S_227_primitive_type_number_int_list_append: // primitive.type.number.int.list.append
        value.move< std::vector<IntType> > (that.value);
        break;

      case symbol_kind::S_228_primitive_type_number_int_list_as_tree: // primitive.type.number.int.list.as.tree
      case symbol_kind::S_230_primitive_type_number_int_list_start_as_tree: // primitive.type.number.int.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_int_list_append_as_tree: // primitive.type.number.int.list.append.as.tree
      case symbol_kind::S_236_primitive_type_number_float_list_as_tree: // primitive.type.number.float.list.as.tree
      case symbol_kind::S_238_primitive_type_number_float_list_start_as_tree: // primitive.type.number.float.list.start.as.tree
      case symbol_kind::S_239_primitive_type_number_float_list_append_as_tree: // primitive.type.number.float.list.append.as.tree
        value.move< std::vector<Tree> > (that.value);
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
  BisonImplementation::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  BisonImplementation::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  BisonImplementation::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  BisonImplementation::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  BisonImplementation::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  BisonImplementation::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  BisonImplementation::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  BisonImplementation::debug_level_type
  BisonImplementation::debug_level () const
  {
    return yydebug_;
  }

  void
  BisonImplementation::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  BisonImplementation::state_type
  BisonImplementation::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  BisonImplementation::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  BisonImplementation::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  BisonImplementation::operator() ()
  {
    return parse ();
  }

  int
  BisonImplementation::parse ()
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
            symbol_type yylookahead (yylex (self));
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
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_195_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_207_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_233_primitive_type_number_float_list_member: // primitive.type.number.float.list.member
        yylhs.value.emplace< FloatType > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_225_primitive_type_number_int_list_member: // primitive.type.number.int.list.member
      case symbol_kind::S_298_statement_math_precision: // statement.math.precision
      case symbol_kind::S_299_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_300_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_301_statement_math_precision_list_append: // statement.math.precision.list.append
        yylhs.value.emplace< IntType > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
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
      case symbol_kind::S_192_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_194_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_196_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_197_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_198_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_199_expression_signal: // expression.signal
      case symbol_kind::S_200_expression_signal_control: // expression.signal.control
      case symbol_kind::S_201_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_202_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_204_primitive_foreign: // primitive.foreign
      case symbol_kind::S_205_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_208_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_209_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_211_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_213_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_215_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_216_primitive_signal: // primitive.signal
      case symbol_kind::S_217_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_218_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_219_primitive_type: // primitive.type
      case symbol_kind::S_220_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_221_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_222_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_223_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_229_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_237_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_240_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_241_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_242_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_243_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_244_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_245_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_246_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_247_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_248_primitive_signal_source_waveform_int_as_tree: // primitive.signal.source.waveform.int.as.tree
      case symbol_kind::S_249_primitive_signal_source_waveform_float_as_tree: // primitive.signal.source.waveform.float.as.tree
      case symbol_kind::S_250_primitive_type_list: // primitive.type.list
      case symbol_kind::S_251_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_252_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_253_primitive_ui: // primitive.ui
      case symbol_kind::S_254_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_255_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_256_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_257_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_258_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_259_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_260_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_261_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_262_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_263_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_264_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_265_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_266_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_267_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_268_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_269_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_271_statement_definition: // statement.definition
      case symbol_kind::S_272_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_273_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_274_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_275_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_276_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_277_statement_definition_function: // statement.definition.function
      case symbol_kind::S_278_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_279_statement_definition_with: // statement.definition.with
      case symbol_kind::S_280_statement_definition_error: // statement.definition.error
      case symbol_kind::S_281_statement_definition_list: // statement.definition.list
      case symbol_kind::S_282_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_283_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_284_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_285_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_286_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_287_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_288_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_289_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_290_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_291_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_292_statement_import: // statement.import
      case symbol_kind::S_293_statement_list: // statement.list
      case symbol_kind::S_294_statement_list_start: // statement.list.start
      case symbol_kind::S_295_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_296_statement_list_append: // statement.list.append
      case symbol_kind::S_297_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_302_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_303_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_304_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_305_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        yylhs.value.emplace< Tree > ();
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_attribute_value: // doc.attribute.value
        yylhs.value.emplace< bool > ();
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
      case symbol_kind::S_FLOATMODE: // FLOATMODE
      case symbol_kind::S_DOUBLEMODE: // DOUBLEMODE
      case symbol_kind::S_QUADMODE: // QUADMODE
      case symbol_kind::S_FIXEDPOINTMODE: // FIXEDPOINTMODE
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
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_210_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_212_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_214_primitive_string_tag: // primitive.string.tag
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_232_primitive_type_number_float_list: // primitive.type.number.float.list
      case symbol_kind::S_234_primitive_type_number_float_list_start: // primitive.type.number.float.list.start
      case symbol_kind::S_235_primitive_type_number_float_list_append: // primitive.type.number.float.list.append
        yylhs.value.emplace< std::vector<FloatType> > ();
        break;

      case symbol_kind::S_224_primitive_type_number_int_list: // primitive.type.number.int.list
      case symbol_kind::S_226_primitive_type_number_int_list_start: // primitive.type.number.int.list.start
      case symbol_kind::S_227_primitive_type_number_int_list_append: // primitive.type.number.int.list.append
        yylhs.value.emplace< std::vector<IntType> > ();
        break;

      case symbol_kind::S_228_primitive_type_number_int_list_as_tree: // primitive.type.number.int.list.as.tree
      case symbol_kind::S_230_primitive_type_number_int_list_start_as_tree: // primitive.type.number.int.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_int_list_append_as_tree: // primitive.type.number.int.list.append.as.tree
      case symbol_kind::S_236_primitive_type_number_float_list_as_tree: // primitive.type.number.float.list.as.tree
      case symbol_kind::S_238_primitive_type_number_float_list_start_as_tree: // primitive.type.number.float.list.start.as.tree
      case symbol_kind::S_239_primitive_type_number_float_list_append_as_tree: // primitive.type.number.float.list.append.as.tree
        yylhs.value.emplace< std::vector<Tree> > ();
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
      yylhs.value.as < Tree > ()->location() = yylhs.location;
			self._ast = self.formatDefinitions(yylhs.value.as < Tree > ());
		}
    break;

  case 3: // program: %empty
           {
    yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
    yylhs.value.as < Tree > ()->location() = yylhs.location;
  }
    break;

  case 4: // doc: doc.text
                         {
			yylhs.value.as < Tree > () = ::docTxt(yystack_[0].value.as < std::string > ().c_str());
		}
    break;

  case 5: // doc: doc.equation
                 {
      yylhs.value.as < Tree > () = ::docEqn(yystack_[0].value.as < Tree > ());
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 6: // doc: doc.diagram
                {
      yylhs.value.as < Tree > () = ::docDgm(yystack_[0].value.as < Tree > ());
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 7: // doc: doc.notice
               {
      yylhs.value.as < Tree > () = ::docNtc();
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 8: // doc: doc.list
             {
      yylhs.value.as < Tree > () = ::docLst();
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 9: // doc: doc.metadata
                 {
      yylhs.value.as < Tree > () = ::docMtd(yystack_[0].value.as < Tree > ());
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 10: // doc: %empty
                 {
      yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 11: // doc.text: DOCCHAR
              {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
      }
    break;

  case 12: // doc.text: doc.text DOCCHAR
                              {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > ().append(self._lexer->YYText());
      }
    break;

  case 13: // doc.equation: BEQN expression EEQN
                           {
        yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 14: // doc.diagram: BDGM expression EDGM
                           {
        yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 15: // doc.notice: NOTICE
             {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
      }
    break;

  case 16: // doc.metadata: BMETADATA statement.identifier.as.tree EMETADATA
                                                       {
        yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 17: // doc.list: BLST doc.attribute.list ELST
                                   {
        yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
      }
    break;

  case 18: // doc.list: BLST ELST
                                 {
        yylhs.value.as < bool > () = ::Faust::Primitive::Symbols::asTree().nil;
      }
    break;

  case 19: // doc.attribute.list: doc.attribute.definition
                                 {
          yylhs.value.as < bool > () = yystack_[0].value.as < bool > ();
        }
    break;

  case 20: // doc.attribute.list: doc.attribute.list doc.attribute.definition
                                                    {
          yylhs.value.as < bool > () = yystack_[0].value.as < bool > ();
        }
    break;

  case 21: // doc.attribute.definition: LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ
                                                            {
          yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
          self._lstDependenciesSwitch = yystack_[1].value.as < bool > ();
        }
    break;

  case 22: // doc.attribute.definition: LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ
                                                        {
          yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
          self._stripDocSwitch = yystack_[1].value.as < bool > ();
          self._stripDocSwitch ? self._stripDocSwitch=false
                                   : self._stripDocSwitch=true;
        }
    break;

  case 23: // doc.attribute.definition: LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ
                                                           {
          yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
          self._lstDistributedSwitch = yystack_[1].value.as < bool > ();
        }
    break;

  case 24: // doc.attribute.value: LSTTRUE
                {
          yylhs.value.as < bool > () = true;
        }
    break;

  case 25: // doc.attribute.value: LSTFALSE
                 {
          yylhs.value.as < bool > () = false;
        }
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

  case 29: // expression.component: COMPONENT LPAR primitive.string.unquoted.as.tree RPAR
                                                            {
        yylhs.value.as < Tree > () = ::boxComponent(yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
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
        yylhs.value.as < Tree > () = ::boxPar( yystack_[2].value.as < Tree > (), yystack_[0].value.as < Tree > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
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
          yylhs.value.as < Tree > () = ::boxMerge( yystack_[2].value.as < Tree > (), yystack_[0].value.as < Tree > () );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 39: // expression.composition.recursive: expression.composition.serial REC expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = ::boxRec(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 40: // expression.composition.sequence: expression.composition.serial SEQ expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = ::boxSeq(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 41: // expression.composition.split: expression.composition.serial SPLIT expression.composition.serial
                                                                                    {
          yylhs.value.as < Tree > () = ::boxSplit(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 42: // expression.environment: ENVIRONMENT LBRAQ statement.list RBRAQ
                                             {
        yylhs.value.as < Tree > () = ::boxWithLocalDef(boxEnvironment(),self.formatDefinitions(yystack_[1].value.as < Tree > ()));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
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

  case 59: // expression.infix: statement.box.identifier.as.tree
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
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 62: // expression.infix.environment.access: expression.infix DOT statement.box.identifier.as.tree
                                                                      {
        yylhs.value.as < Tree > () = ::boxAccess(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());      
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
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
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigAdd));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 68: // expression.infix.math.algebra: expression.infix SUB expression.infix
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigSub));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 69: // expression.infix.math.algebra: expression.infix MUL expression.infix
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigMul));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 70: // expression.infix.math.algebra: expression.infix DIV expression.infix
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigDiv));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 71: // expression.infix.math.algebra: expression.infix MOD expression.infix
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigRem));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 72: // expression.infix.math.algebra: expression.infix POWOP expression.infix
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxMathPrimitive( "pow" ));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 73: // expression.infix.math.comparison: expression.infix LT expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigLT));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 74: // expression.infix.math.comparison: expression.infix LE expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigLE));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 75: // expression.infix.math.comparison: expression.infix GT expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigGT));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 76: // expression.infix.math.comparison: expression.infix GE expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigGE));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 77: // expression.infix.math.comparison: expression.infix EQ expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigEQ));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 78: // expression.infix.math.comparison: expression.infix NE expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigNE));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 79: // expression.infix.math.logic: expression.infix AND expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigAND));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 80: // expression.infix.math.logic: expression.infix OR expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigOR));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 81: // expression.infix.math.logic: expression.infix XOR expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigXOR));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 82: // expression.infix.math.shift: expression.infix LSH expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigLeftShift));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 83: // expression.infix.math.shift: expression.infix RSH expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigARightShift));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 84: // expression.infix.prefix: expression.infix LPAR expression.composition.parallel RPAR
                                                                       {
        yylhs.value.as < Tree > () = ::buildBoxAppl(yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 85: // expression.infix.signal.delay: expression.infix FDELAY expression.infix
                                                         {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigDelay));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 86: // expression.infix.signal.delay: expression.infix DELAY1
                                   {
        yylhs.value.as < Tree > () = ::boxSeq(yystack_[1].value.as < Tree > (),::boxPrim1(sigDelay1));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 87: // expression.iterate.parallel: ITERATE_PARALLEL LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                                       {
        yylhs.value.as < Tree > () = ::boxIPar(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 88: // expression.iterate.sequence: ISEQ LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                           {
        yylhs.value.as < Tree > () = ::boxISeq(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 89: // expression.iterate.sum: ISUM LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                           {
        yylhs.value.as < Tree > () = ::boxISum(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 90: // expression.iterate.product: IPROD LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                            {
        yylhs.value.as < Tree > () = boxIProd(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 91: // expression.lambda: LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR
                                                                         {
        yylhs.value.as < Tree > () = ::buildBoxAbstr(
          yystack_[5].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 92: // expression.lambda.params: expression.lambda.params.start
                { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 93: // expression.lambda.params: expression.lambda.params.append
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 94: // expression.lambda.params.start: statement.box.identifier.as.tree
                                         {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 95: // expression.lambda.params.append: expression.lambda.params COMMA statement.box.identifier.as.tree
                                                                        {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            yystack_[2].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 96: // expression.letrec: expression LETREC LBRAQ RBRAQ
                                                                          {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[3].value.as < Tree > (),
        self.formatDefinitions(::Faust::Primitive::Symbols::asTree().nil),
        ::Faust::Primitive::Symbols::asTree().nil
      );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
		}
    break;

  case 97: // expression.letrec: expression LETREC LBRAQ expression.letrec.list RBRAQ
                                                              {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[4].value.as < Tree > (),
        self.formatDefinitions(yystack_[1].value.as < Tree > ()),
        ::Faust::Primitive::Symbols::asTree().nil
      );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
		}
    break;

  case 98: // expression.letrec: expression LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ
                                                                                              {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[6].value.as < Tree > (),
        self.formatDefinitions(yystack_[3].value.as < Tree > ()),
        self.formatDefinitions(yystack_[3].value.as < Tree > ())
      );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
		}
    break;

  case 99: // expression.letrec.list: expression.letrec.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 100: // expression.letrec.list: expression.letrec.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 101: // expression.letrec.list.start: expression.letrec.equation
                                         {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 102: // expression.letrec.list.append: expression.letrec.list expression.letrec.equation
                                                          {
          yylhs.value.as < Tree > () = cons (
            yystack_[0].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 103: // expression.letrec.equation: expression.letrec.equation.name DEF expression ENDDEF
                                                            {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[3].value.as < Tree > (),
          cons(
            ::Faust::Primitive::Symbols::asTree().nil,
            yystack_[1].value.as < Tree > ()
          )
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 104: // expression.letrec.equation: error ENDDEF
                   {
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        self._lexer->LexerError("Expected expression.");
        yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 105: // expression.letrec.equation.name: DELAY1 statement.box.identifier.as.tree
                                                {
          yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 106: // expression.library: LIBRARY LPAR primitive.string.unquoted.as.tree RPAR
                                                          {
        yylhs.value.as < Tree > () = ::boxLibrary( yystack_[1].value.as < Tree > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 107: // expression.math: expression.math.signal
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 108: // expression.math: expression.math.scalar.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 109: // expression.math: expression.math.comparison
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 110: // expression.math: expression.math.trigonometry.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 111: // expression.math: expression.math.rounding
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 112: // expression.math.comparison: LT
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigLT);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 113: // expression.math.comparison: LE
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigLE);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 114: // expression.math.comparison: GT
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigGT);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 115: // expression.math.comparison: GE
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigGE);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 116: // expression.math.comparison: EQ
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigEQ);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 117: // expression.math.comparison: NE
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigNE);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 118: // expression.math.rounding: ABS
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "abs" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 119: // expression.math.rounding: MIN
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "min" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 120: // expression.math.rounding: MAX
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "max" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 121: // expression.math.rounding: FLOOR
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "floor" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 122: // expression.math.rounding: CEIL
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "ceil" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 123: // expression.math.rounding: ASSERTBOUNDS
                       {
            yylhs.value.as < Tree > () = ::boxPrim3(sigAssertBounds);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 124: // expression.math.rounding: LOWEST
                 {
            yylhs.value.as < Tree > () = ::boxPrim1(sigLowest);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 125: // expression.math.rounding: HIGHEST
                  {
            yylhs.value.as < Tree > () = ::boxPrim1(sigHighest);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 126: // expression.math.rounding: RINT
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "rint" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
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
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigAdd);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 131: // expression.math.signal.algebra: SUB
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigSub);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 132: // expression.math.signal.algebra: MUL
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigMul);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 133: // expression.math.signal.algebra: DIV
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigDiv);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 134: // expression.math.signal.algebra: MOD
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigRem);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 135: // expression.math.signal.algebra: FMOD
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "fmod" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 136: // expression.math.signal.algebra: REMAINDER
                    {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "remainder" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 137: // expression.math.signal.algebra: SUB statement.box.identifier.as.tree
                                               {
            yylhs.value.as < Tree > () = ::boxSeq(
              ::boxPar(
                ::boxInt(0),
                yystack_[0].value.as < Tree > ()
              ),
              ::boxPrim2(sigSub)
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 138: // expression.math.signal.shift: LSH
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigLeftShift);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 139: // expression.math.signal.shift: RSH
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigARightShift);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 140: // expression.math.signal.power: EXP
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "exp" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 141: // expression.math.signal.power: LOG
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "log" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 142: // expression.math.signal.power: LOG10
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "log10" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 143: // expression.math.signal.power: POWOP
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "pow" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 144: // expression.math.signal.power: POWFUN
                 {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "pow" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 145: // expression.math.signal.power: SQRT
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "sqrt" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 146: // expression.math.scalar.as.tree: expression.math.scalar.int.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 147: // expression.math.scalar.as.tree: expression.math.scalar.float.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 148: // expression.math.scalar.int: ADD INT
                  {
            yylhs.value.as < IntType > () = std::stoi(self._lexer->YYText());
          }
    break;

  case 149: // expression.math.scalar.int: SUB INT
                  {
            yylhs.value.as < IntType > () = -yystack_[0].value.as < IntType > ();
          }
    break;

  case 150: // expression.math.scalar.int.as.tree: expression.math.scalar.int
                                     {
            yylhs.value.as < Tree > () = ::boxInt( yystack_[0].value.as < IntType > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 151: // expression.math.scalar.float: ADD FLOAT
                    {
            yylhs.value.as < FloatType > () = yystack_[0].value.as < FloatType > ();
          }
    break;

  case 152: // expression.math.scalar.float: SUB FLOAT
                    {
            yylhs.value.as < FloatType > () = -yystack_[0].value.as < FloatType > ();
          }
    break;

  case 153: // expression.math.scalar.float.as.tree: expression.math.scalar.float
                                       {
            yylhs.value.as < Tree > () = ::boxReal( yystack_[0].value.as < FloatType > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 154: // expression.math.trigonometry.as.tree: ACOS
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "acos" );
          
          }
    break;

  case 155: // expression.math.trigonometry.as.tree: ASIN
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "asin" );
        
          }
    break;

  case 156: // expression.math.trigonometry.as.tree: ATAN
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "atan" );
        
          }
    break;

  case 157: // expression.math.trigonometry.as.tree: ATAN2
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "atan2" );
        
          }
    break;

  case 158: // expression.math.trigonometry.as.tree: COS
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "cos" );
        
          }
    break;

  case 159: // expression.math.trigonometry.as.tree: SIN
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "sin" );
        
          }
    break;

  case 160: // expression.math.trigonometry.as.tree: TAN
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "tan" );
        
          }
    break;

  case 161: // expression.parenthesis: LPAR expression RPAR
                         {
      yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 162: // expression.signal: expression.signal.control
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 163: // expression.signal: expression.signal.delay
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 164: // expression.signal: expression.signal.logic
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 165: // expression.signal.control: ATTACH
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigAttach);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 166: // expression.signal.control: ENABLE
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigEnable);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 167: // expression.signal.control: CONTROL
                {
          yylhs.value.as < Tree > () = ::boxPrim2(sigControl);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 168: // expression.signal.delay: MEM
            {
          yylhs.value.as < Tree > () = ::boxPrim1(sigDelay1);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 169: // expression.signal.delay: PREFIX
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigPrefix);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 170: // expression.signal.delay: FDELAY
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigDelay);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 171: // expression.signal.logic: AND
            {
          yylhs.value.as < Tree > () = ::boxPrim2(sigAND);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 172: // expression.signal.logic: OR
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigOR);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 173: // expression.signal.logic: XOR
            {
          yylhs.value.as < Tree > () = ::boxPrim2(sigXOR);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 174: // expression.signal.logic: SELECT2
                {
          yylhs.value.as < Tree > () = ::boxPrim3(sigSelect2);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 175: // expression.signal.logic: SELECT3
                {
          yylhs.value.as < Tree > () = ::boxPrim4(sigSelect3);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 176: // expression.signal.logic: CASE LBRAQ statement.signal.pattern.rule.list RBRAQ
                                                            {
          yylhs.value.as < Tree > () = ::boxCase(self.checkRulelist(yystack_[1].value.as < Tree > ()));
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 177: // primitive: primitive.foreign
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 178: // primitive: primitive.type.number.as.tree
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 179: // primitive: primitive.type.cast.number
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 180: // primitive: primitive.signal
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 181: // primitive: primitive.ui
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 182: // primitive.foreign: primitive.foreign.constant
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 183: // primitive.foreign: primitive.foreign.function
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 184: // primitive.foreign: primitive.foreign.variable
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 185: // primitive.type.number.as.tree: primitive.type.number.int.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 186: // primitive.type.number.as.tree: primitive.type.number.float.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 187: // primitive.type.number.int: INT
          {
        yylhs.value.as < IntType > () = std::stoi(self._lexer->YYText());
      }
    break;

  case 188: // primitive.type.number.float: FLOAT
            {
        yylhs.value.as < FloatType > () = std::atof(self._lexer->YYText());
      }
    break;

  case 189: // primitive.type.number.int.as.tree: primitive.type.number.int
                                {
        yylhs.value.as < Tree > () = boxInt( yystack_[0].value.as < IntType > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 190: // primitive.type.number.float.as.tree: primitive.type.number.float
                                  {
        yylhs.value.as < Tree > () = boxReal( yystack_[0].value.as < FloatType > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 191: // primitive.string.quoted: STRING
             {
        yylhs.value.as < std::string > () = self._lexer->YYText();
      }
    break;

  case 192: // primitive.string.quoted.as.tree: primitive.string.quoted
                              {
        yylhs.value.as < Tree > () = ::tree( yystack_[0].value.as < std::string > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 193: // primitive.string.unquoted: STRING
             {
        yylhs.value.as < std::string > () = self.unquote(self._lexer->YYText());
      }
    break;

  case 194: // primitive.string.unquoted.as.tree: primitive.string.unquoted
                                {
        yylhs.value.as < Tree > () = ::tree( yystack_[0].value.as < std::string > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 195: // primitive.string.tag: STRING
             {
        yylhs.value.as < std::string > () = self._lexer->YYText();
      }
    break;

  case 196: // primitive.string.tag: TAGSTRING
                {
        yylhs.value.as < std::string > () = self._lexer->YYText();
      }
    break;

  case 197: // primitive.string.tag.as.tree: primitive.string.tag
                         {
      yylhs.value.as < Tree > () = ::tree( yystack_[0].value.as < std::string > () );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 198: // primitive.signal: primitive.signal.inputs
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 199: // primitive.signal: primitive.signal.input.wire
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 200: // primitive.signal: primitive.signal.input.terminate
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 201: // primitive.signal: primitive.signal.outputs
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 202: // primitive.signal: primitive.signal.route
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 203: // primitive.signal: primitive.signal.source
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 204: // primitive.signal.input.wire: WIRE
           {
        yylhs.value.as < Tree > () = ::boxWire();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 205: // primitive.signal.input.terminate: CUT
          {
        yylhs.value.as < Tree > () = ::boxCut();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 206: // primitive.type: primitive.type.cast.number
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 207: // primitive.type: primitive.type.cast.any
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 208: // primitive.type.cast.number: primitive.type.cast.number.int
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 209: // primitive.type.cast.number: primitive.type.cast.number.float
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 210: // primitive.type.cast.number.int: INTCAST
                  {
            yylhs.value.as < Tree > () = ::boxPrim1(sigIntCast);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 211: // primitive.type.cast.number.float: FLOATCAST
                    {
            yylhs.value.as < Tree > () = ::boxPrim1(sigFloatCast);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 212: // primitive.type.cast.any: ANYCAST
                {
          yylhs.value.as < Tree > () = ::tree(2);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 213: // primitive.type.number.int.list: primitive.type.number.int.list.start
        { yylhs.value.as < std::vector<IntType> > () = yystack_[0].value.as < std::vector<IntType> > (); }
    break;

  case 214: // primitive.type.number.int.list: primitive.type.number.int.list.append
        { yylhs.value.as < std::vector<IntType> > () = yystack_[0].value.as < std::vector<IntType> > (); }
    break;

  case 215: // primitive.type.number.int.list.member: primitive.type.number.int
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 216: // primitive.type.number.int.list.member: expression.math.scalar.int
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 217: // primitive.type.number.int.list.start: primitive.type.number.int.list.member
                                              {
          yylhs.value.as < std::vector<IntType> > ().push_back( yystack_[0].value.as < IntType > () );
        }
    break;

  case 218: // primitive.type.number.int.list.append: primitive.type.number.int.list COMMA primitive.type.number.int.list.member
                                                                                   {
          yylhs.value.as < std::vector<IntType> > ().push_back( yystack_[0].value.as < IntType > () );
        }
    break;

  case 219: // primitive.type.number.int.list.as.tree: primitive.type.number.int.list.start.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 220: // primitive.type.number.int.list.as.tree: primitive.type.number.int.list.append.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 221: // primitive.type.number.int.list.member.as.tree: primitive.type.number.int.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 222: // primitive.type.number.int.list.member.as.tree: expression.math.scalar.int.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 223: // primitive.type.number.int.list.start.as.tree: primitive.type.number.int.list.member.as.tree
                                                      {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 224: // primitive.type.number.int.list.append.as.tree: primitive.type.number.int.list COMMA primitive.type.number.int.list.member.as.tree
                                                                                           {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 225: // primitive.type.number.float.list: primitive.type.number.float.list.start
        { yylhs.value.as < std::vector<FloatType> > () = yystack_[0].value.as < std::vector<FloatType> > (); }
    break;

  case 226: // primitive.type.number.float.list: primitive.type.number.float.list.append
        { yylhs.value.as < std::vector<FloatType> > () = yystack_[0].value.as < std::vector<FloatType> > (); }
    break;

  case 227: // primitive.type.number.float.list.member: primitive.type.number.float
          { yylhs.value.as < FloatType > () = yystack_[0].value.as < FloatType > (); }
    break;

  case 228: // primitive.type.number.float.list.member: expression.math.scalar.float
          { yylhs.value.as < FloatType > () = yystack_[0].value.as < FloatType > (); }
    break;

  case 229: // primitive.type.number.float.list.start: primitive.type.number.float.list.member
                                                {
          yylhs.value.as < std::vector<FloatType> > ().push_back( yystack_[0].value.as < FloatType > () );
        }
    break;

  case 230: // primitive.type.number.float.list.append: primitive.type.number.float.list COMMA primitive.type.number.float.list.member
                                                                                       {
          yylhs.value.as < std::vector<FloatType> > ().push_back( yystack_[0].value.as < FloatType > () );
        }
    break;

  case 231: // primitive.type.number.float.list.as.tree: primitive.type.number.float.list.start.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 232: // primitive.type.number.float.list.as.tree: primitive.type.number.float.list.append.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 233: // primitive.type.number.float.list.member.as.tree: primitive.type.number.float.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 234: // primitive.type.number.float.list.member.as.tree: expression.math.scalar.float.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 235: // primitive.type.number.float.list.start.as.tree: primitive.type.number.float.list.member.as.tree
                                                        {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 236: // primitive.type.number.float.list.append.as.tree: primitive.type.number.float.list COMMA primitive.type.number.float.list.member.as.tree
                                                                                               {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 237: // primitive.signal.route: primitive.signal.route.implied.outputs
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 238: // primitive.signal.route: primitive.signal.route.implied.connections
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 239: // primitive.signal.route: primitive.signal.route.explicit
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 240: // primitive.signal.route.implied.outputs: ROUTE LPAR expression.composition.serial RPAR
                                                                     {
            yylhs.value.as < Tree > () = ::boxRoute(
              yystack_[1].value.as < Tree > (),
              yystack_[1].value.as < Tree > (),
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 241: // primitive.signal.route.implied.connections: ROUTE LPAR expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                             {
            yylhs.value.as < Tree > () = ::boxRoute(
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > (),
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 242: // primitive.signal.route.explicit: ROUTE LPAR expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.parallel RPAR
                                                                                                                                                   {
            yylhs.value.as < Tree > () = boxRoute(
              yystack_[5].value.as < Tree > (),
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > ()
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 243: // primitive.signal.source: primitive.signal.source.waveform.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 244: // primitive.signal.source: primitive.signal.source.soundfile
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 245: // primitive.signal.source: primitive.signal.source.table
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 246: // primitive.signal.source.table: RDTBL
                {
            yylhs.value.as < Tree > () = ::boxPrim3(sigReadOnlyTable);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 247: // primitive.signal.source.table: RWTBL
                {
            yylhs.value.as < Tree > () = ::boxPrim5(sigWriteReadTable);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 248: // primitive.signal.source.soundfile: SOUNDFILE LPAR primitive.string.unquoted.as.tree COMMA expression.composition RPAR
                                                                                             {
            yylhs.value.as < Tree > () = ::boxSoundfile( yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 249: // primitive.signal.source.waveform.as.tree: primitive.signal.source.waveform.int.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 250: // primitive.signal.source.waveform.as.tree: primitive.signal.source.waveform.float.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 251: // primitive.signal.source.waveform.int.as.tree: WAVEFORM LBRAQ primitive.type.number.int.list.as.tree RBRAQ
                                                                    {
          yylhs.value.as < Tree > () = ::boxWaveform( yystack_[1].value.as < std::vector<Tree> > () );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 252: // primitive.signal.source.waveform.float.as.tree: WAVEFORM LBRAQ primitive.type.number.float.list.as.tree RBRAQ
                                                                      {
          yylhs.value.as < Tree > () = ::boxWaveform( yystack_[1].value.as < std::vector<Tree> > () );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 253: // primitive.type.list: primitive.type.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 254: // primitive.type.list: primitive.type.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 255: // primitive.type.list.start: primitive.type
                         {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),::Faust::Primitive::Symbols::asTree().nil);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 256: // primitive.type.list.append: primitive.type.list COMMA primitive.type
                                                   {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[0].value.as < Tree > (),
              yystack_[2].value.as < Tree > ()
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 257: // primitive.ui: primitive.ui.button
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 258: // primitive.ui: primitive.ui.checkbox
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 259: // primitive.ui: primitive.ui.vslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 260: // primitive.ui: primitive.ui.hslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 261: // primitive.ui: primitive.ui.nentry
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 262: // primitive.ui: primitive.ui.vgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 263: // primitive.ui: primitive.ui.hgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 264: // primitive.ui: primitive.ui.tgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 265: // primitive.ui: primitive.ui.vbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 266: // primitive.ui: primitive.ui.hbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 267: // primitive.ui.button: BUTTON LPAR primitive.string.unquoted.as.tree RPAR
                                                           {
          yylhs.value.as < Tree > () = ::boxButton(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 268: // primitive.ui.checkbox: CHECKBOX LPAR primitive.string.unquoted.as.tree RPAR
                                                             {
          yylhs.value.as < Tree > () = ::boxCheckbox(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 269: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                                    {
          yylhs.value.as < Tree > () = ::boxVSlider(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 270: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                                    {
          yylhs.value.as < Tree > () = ::boxHSlider(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 271: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                                   {
          yylhs.value.as < Tree > () = ::boxNumEntry(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 272: // primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                                                                            {
          yylhs.value.as < Tree > () = ::boxVGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 273: // primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                                                                            {
          yylhs.value.as < Tree > () = ::boxHGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 274: // primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                                                                            {
          yylhs.value.as < Tree > () = ::boxTGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 275: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                  {
          yylhs.value.as < Tree > () = ::boxVBargraph(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 276: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                  {
          yylhs.value.as < Tree > () = ::boxHBargraph(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 277: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag.as.tree COMMA primitive.string.unquoted.as.tree RPAR
                                                                                                                                            {
          yylhs.value.as < Tree > () = ::boxFFun(
            ::ffunction(
              yystack_[5].value.as < Tree > (),
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > ()
            )
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 278: // primitive.foreign.function.signature: primitive.type.number.as.tree statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                                                                         {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[4].value.as < Tree > (),
              ::cons(
                ::cons(
                  yystack_[3].value.as < Tree > (),
                  ::cons( yystack_[3].value.as < Tree > (), ::cons( yystack_[3].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                yystack_[1].value.as < Tree > ()
              )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 279: // primitive.foreign.function.signature: primitive.type.number.as.tree statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                                                                                                                                 {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[6].value.as < Tree > (),
              ::cons(
                ::cons(
                  yystack_[5].value.as < Tree > (),
                  ::cons(
                    yystack_[3].value.as < Tree > (),
                    ::cons( yystack_[3].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                yystack_[1].value.as < Tree > ()
              )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 280: // primitive.foreign.function.signature: primitive.type.number.as.tree statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                                                                                                                                                                                        {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[8].value.as < Tree > (),
              ::cons(
                ::cons(
                  yystack_[7].value.as < Tree > (),
                  ::cons(
                    yystack_[5].value.as < Tree > (),
                    ::cons( yystack_[3].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                yystack_[1].value.as < Tree > ()
              )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 281: // primitive.foreign.function.signature: primitive.type.number.as.tree statement.foreign.function.identifier.as.tree LPAR RPAR
                                                                                                     {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[3].value.as < Tree > (),
              ::cons(
                ::cons(
                  yystack_[2].value.as < Tree > (),
                  ::cons(
                    yystack_[2].value.as < Tree > (),
                    ::cons( yystack_[2].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                ::Faust::Primitive::Symbols::asTree().nil
              )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 282: // primitive.foreign.function.signature: primitive.type.number.as.tree statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
                                                                                                                                                             {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[5].value.as < Tree > (),
              ::cons(
                ::cons(
                  yystack_[4].value.as < Tree > (),
                  ::cons(
                    yystack_[2].value.as < Tree > (),
                    ::cons( yystack_[2].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                ::Faust::Primitive::Symbols::asTree().nil
              )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 283: // primitive.foreign.function.signature: primitive.type.number.as.tree statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
                                                                                                                                                                                                                    {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[7].value.as < Tree > (),
              ::cons(
                ::cons(
                  yystack_[6].value.as < Tree > (),
                  ::cons(
                    yystack_[4].value.as < Tree > (),
                    ::cons( yystack_[2].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                ::Faust::Primitive::Symbols::asTree().nil
              )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 284: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.number.as.tree statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                                                                                                                          {
          yylhs.value.as < Tree > () = ::boxFConst(
            yystack_[4].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 285: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.number.as.tree statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                                                                                                                          {
          yylhs.value.as < Tree > () = ::boxFVar(
            yystack_[4].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 286: // primitive.signal.inputs: INPUTS LPAR expression RPAR
                                    {
          yylhs.value.as < Tree > () = ::boxInputs(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 287: // primitive.signal.outputs: OUTPUTS LPAR expression RPAR
                                     {
          yylhs.value.as < Tree > () = ::boxOutputs(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 288: // statement: statement.definition
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 289: // statement: statement.declare.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 290: // statement: statement.declare.feature.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 291: // statement: statement.declare.doc
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 292: // statement: statement.import
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 293: // statement.definition: statement.definition.function
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 294: // statement.definition: statement.definition.assignment
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 295: // statement.definition: statement.definition.error
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 296: // statement.definition.function.arg: expression.composition.serial
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 297: // statement.definition.function.args: statement.definition.function.args.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 298: // statement.definition.function.args: statement.definition.function.args.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 299: // statement.definition.function.args.start: statement.definition.function.arg
                                        {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[0].value.as < Tree > (),
          ::Faust::Primitive::Symbols::asTree().nil
        );
       yylhs.value.as < Tree > ()->location() = yylhs.location;
     }
    break;

  case 300: // statement.definition.function.args.append: statement.definition.function.args COMMA statement.definition.function.arg
                                                                                 {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[0].value.as < Tree > (),
          yystack_[2].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 301: // statement.definition.function.declaration: statement.box.identifier.as.tree LPAR statement.definition.function.args RPAR DEF expression
                                                                                                   {
        yylhs.value.as < Tree > () = cons(
          yystack_[5].value.as < Tree > (),
          ::cons( yystack_[3].value.as < Tree > (), yystack_[0].value.as < Tree > () )
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 302: // statement.definition.function: statement.definition.function.declaration ENDDEF
                                                         {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 303: // statement.definition.function: statement.definition.function.declaration ENDOFINPUT
                                                             {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 304: // statement.definition.function: statement.definition.function.declaration ENDL
                                                       {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 305: // statement.definition.function: ENDDEF error
                     {
        yyerrok;
        yyclearin;
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 306: // statement.definition.assignment: statement.box.identifier.as.tree DEF expression ENDDEF
                                                               {
          yylhs.value.as < Tree > () = cons(
            yystack_[3].value.as < Tree > (),
            ::cons( ::Faust::Primitive::Symbols::asTree().nil, yystack_[1].value.as < Tree > () )
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 307: // statement.definition.with: expression WITH LBRAQ statement.definition.list RBRAQ
                                                            {
        yylhs.value.as < Tree > () = ::boxWithLocalDef(
          yystack_[4].value.as < Tree > (),
          self.formatDefinitions(yystack_[1].value.as < Tree > ())
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 308: // statement.definition.error: error ENDDEF
                     {
          yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
          self._lexer->LexerError("Error in definition.");
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 309: // statement.definition.list: statement.definition.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 310: // statement.definition.list: statement.definition.list.start.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 311: // statement.definition.list: statement.definition.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 312: // statement.definition.list: statement.definition.list.append.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 313: // statement.definition.list.start: statement.definition
                               {
            yylhs.value.as < Tree > () = ::cons(
              yylhs.value.as < Tree > (),
              ::Faust::Primitive::Symbols::asTree().nil
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 314: // statement.definition.list.start.qualified: statement.math.precision.list statement.definition
                                                             {
            if (self.acceptdefinition(yystack_[1].value.as < IntType > ()))
              yylhs.value.as < Tree > () = ::cons( yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil );
            else
              yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 315: // statement.definition.list.append: statement.definition.list statement.definition
                                                         {
            yylhs.value.as < Tree > () = cons (yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ());
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 316: // statement.definition.list.append.qualified: statement.definition.list statement.math.precision.list statement.definition
                                                                                       {
            if (self.acceptdefinition(yystack_[1].value.as < IntType > ()))
              yylhs.value.as < Tree > () = cons (yystack_[0].value.as < Tree > (),yystack_[2].value.as < Tree > ());
            else
              yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > ();
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 317: // statement.declare.metadata: DECLARE statement.identifier.as.tree primitive.string.quoted.as.tree ENDDEF
                                                                                              {
        self.declareMetadata(yystack_[2].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 318: // statement.declare.feature.metadata: DECLARE statement.identifier.as.tree statement.identifier.as.tree primitive.string.quoted.as.tree ENDDEF
                                                                                                                                    {
        self.declareDefinitionMetadata( yystack_[3].value.as < Tree > (), yystack_[2].value.as < Tree > (), yystack_[1].value.as < Tree > () );
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 319: // statement.declare.doc: BDOC doc EDOC
                          {
        ::declareDoc(yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 320: // statement.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::tree(self._lexer->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 321: // statement.box.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::boxIdent(self._lexer->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 322: // statement.foreign.function.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::tree(self._lexer->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 323: // statement.import: IMPORT LPAR primitive.string.unquoted.as.tree RPAR ENDDEF
                                                                          {
        yylhs.value.as < Tree > () = ::importFile(yystack_[2].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 324: // statement.list: statement.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 325: // statement.list: statement.list.start.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 326: // statement.list: statement.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 327: // statement.list: statement.list.append.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 328: // statement.list.start: statement
                  {
          if ( yystack_[0].value.as < Tree > () != ::Faust::Primitive::Symbols::asTree().nil ) {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil);
          }
          else {
            yylhs.value.as < Tree > () = yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
          }
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 329: // statement.list.start.qualified: statement.math.precision.list statement
                                                {
          if ( yystack_[0].value.as < Tree > () != ::Faust::Primitive::Symbols::asTree().nil
            && self.acceptdefinition(yystack_[1].value.as < IntType > ()))
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil);
          else
            yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 330: // statement.list.append: statement.list statement
                                 {
          if ( yystack_[0].value.as < Tree > () != ::Faust::Primitive::Symbols::asTree().nil ) {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          }
          else {
            yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          }
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 331: // statement.list.append.qualified: statement.list statement.math.precision.list statement
                                                               {
          if ( yystack_[0].value.as < Tree > () != ::Faust::Primitive::Symbols::asTree().nil
            && self.acceptdefinition(yystack_[1].value.as < IntType > ())) {
            yylhs.value.as < Tree > () = ::cons(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          }
          else {
            yylhs.value.as < Tree > ()=yystack_[2].value.as < Tree > ();
          }
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 332: // statement.math.precision: FLOATMODE
                  {
          yylhs.value.as < IntType > () = 1;
        }
    break;

  case 333: // statement.math.precision: DOUBLEMODE
                   {
          yylhs.value.as < IntType > () = 2;
        }
    break;

  case 334: // statement.math.precision: QUADMODE
                 {
          yylhs.value.as < IntType > () = 4;
        }
    break;

  case 335: // statement.math.precision: FIXEDPOINTMODE
                       {
          yylhs.value.as < IntType > () = 8;
        }
    break;

  case 336: // statement.math.precision.list: statement.math.precision.list.start
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 337: // statement.math.precision.list: statement.math.precision.list.append
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 338: // statement.math.precision.list.start: statement.math.precision
            { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 339: // statement.math.precision.list.append: statement.math.precision.list statement.math.precision
                                                                   {
              yylhs.value.as < IntType > () = yystack_[1].value.as < IntType > () | yystack_[0].value.as < IntType > ();
            }
    break;

  case 340: // statement.signal.pattern.rule: LPAR expression.composition.parallel RPAR ARROW expression ENDDEF
                                                                        { yylhs.value.as < Tree > () = ::cons(yystack_[4].value.as < Tree > (),yystack_[1].value.as < Tree > ()); }
    break;

  case 341: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 342: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 343: // statement.signal.pattern.rule.list.start: statement.signal.pattern.rule
                                      {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 344: // statement.signal.pattern.rule.list.append: statement.signal.pattern.rule.list statement.signal.pattern.rule
                                                                         {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
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
  BisonImplementation::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  BisonImplementation::yytnamerr_ (const char *yystr)
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
  BisonImplementation::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // BisonImplementation::context.
  BisonImplementation::context::context (const BisonImplementation& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  BisonImplementation::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  BisonImplementation::yy_lac_check_ (symbol_kind_type yytoken) const
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
  BisonImplementation::yy_lac_establish_ (symbol_kind_type yytoken)
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
  BisonImplementation::yy_lac_discard_ (const char* event)
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
  BisonImplementation::yy_syntax_error_arguments_ (const context& yyctx,
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
  BisonImplementation::yysyntax_error_ (const context& yyctx) const
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


  const short BisonImplementation::yypact_ninf_ = -497;

  const short BisonImplementation::yytable_ninf_ = -229;

  const short
  BisonImplementation::yypact_[] =
  {
      50,   -21,    98,   -13,  -497,     3,  -497,  -497,  -497,  -497,
     387,   113,  -497,  -497,    16,  -497,  -497,  -497,  -497,  -497,
    -497,    -2,  -497,    65,  -497,  -497,  -497,  -497,  -497,    95,
    -497,  -497,  -497,  -497,    12,  -497,   -68,   554,   554,   107,
       3,  -497,  -497,    27,    -9,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,   554,   554,  -497,    95,  -497,  -497,
    -497,  -497,    93,  -497,  -497,    61,    74,  -497,  -497,  -497,
    -497,  -497,  -497,    58,     2,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,   102,
     105,   126,   169,   192,   226,   231,   237,   256,   261,   269,
     276,   294,   305,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
     331,  -497,  -497,   554,   336,   337,   114,   209,   365,  -497,
    -497,   366,   367,   373,   415,   426,   430,   290,  -497,  -497,
    -497,    51,  -497,  -497,  -497,   511,  -497,  -497,  -497,  -497,
    -497,   657,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,    24,  -497,   284,
     333,   386,   137,  -497,   270,  -497,  -497,   511,  -497,    22,
    -497,  -497,    81,  -497,   141,  -497,   434,  -497,  -497,  -497,
    -497,  -497,   151,   151,   151,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,   417,    59,    12,    12,
      95,   278,   554,   417,   417,   417,   417,   554,   554,   444,
     450,   452,   554,  -497,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,  -497,   417,   554,   122,
    -497,   398,   401,   405,  -497,  -497,  -497,   554,   454,  -497,
    -497,  -497,   440,   535,     3,     3,   464,   465,   546,   547,
     553,   574,   575,   580,   625,   626,   633,    48,  -497,  -497,
    -497,  -497,   560,   561,    21,    58,   158,   649,  -497,   652,
    -497,   653,   655,  -497,  -497,   728,  -497,  -497,  -497,   656,
    -497,  -497,  -497,   729,  -497,  -497,  -497,   675,  -497,  -497,
    -497,   282,   731,   733,   752,   753,    67,    79,   554,  -497,
       9,  -497,  -497,   122,    33,   765,   511,   378,    85,  -497,
     677,   696,   416,   769,   785,   800,   813,   438,   463,   835,
     451,   849,   820,   862,   340,   424,   475,   277,  -497,   330,
     576,  -497,    90,  -497,  -497,  -497,  -497,   122,   129,   129,
     129,  -497,   554,  -497,    46,   241,   766,   767,  -497,  -497,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   417,
     747,  -497,  -497,  -497,   142,  -497,    56,  -497,   554,  -497,
     554,   554,   554,   554,  -497,  -497,   697,  -497,  -497,   150,
     699,   417,  -497,    32,  -497,  -497,  -497,   692,  -497,  -497,
    -497,   122,  -497,  -497,  -497,   715,   716,   717,   330,   440,
     281,  -497,  -497,  -497,   857,   241,   241,   374,   544,   631,
     117,   139,   211,   721,   726,   786,  -497,   788,   793,   805,
    -497,  -497,   807,   808,  -497,  -497,   315,   738,   743,   748,
     758,   771,  -497,  -497,  -497,  -497,   122,  -497,   554,  -497,
    -497,  -497,  -497,   104,  -497,  -497,  -497,  -497,  -497,    70,
    -497,  -497,    12,   802,   810,   554,   554,   554,  -497,  -497,
    -497,   554,   554,  -497,   554,   554,  -497,   554,   554,   554,
     554,   554,   195,    94,   440,   338,   327,  -497,   811,  -497,
    -497,   763,   901,   906,   247,   292,   214,   814,   220,   243,
     264,   274,   328,  -497,  -497,   816,  -497,    80,  -497,  -497,
     554,   554,   554,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,   344,  -497,   916,   930,   961,  -497,   116,   554,
     554,   554,  -497,   321,   334,   342,  -497,  -497,  -497
  };

  const short
  BisonImplementation::yydefact_[] =
  {
       0,     0,     0,     0,   321,     0,   332,   333,   334,   335,
      10,     0,   328,   288,     0,   293,   294,   295,   289,   290,
     291,     0,   292,     0,   324,   325,   326,   327,   338,     0,
     336,   337,   308,   305,     0,   320,     0,     0,     0,     0,
       0,    11,    15,     0,     4,     5,     6,     7,     9,     8,
       1,   303,   302,   304,     0,     0,   330,     0,   329,   339,
     193,   194,     0,   191,   192,     0,     0,   112,   113,   116,
     114,   115,   117,   130,   131,   172,   132,   133,   134,   171,
     173,   138,   139,   143,   170,   168,   169,   210,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   154,   155,   156,   157,   158,   159,
     160,   140,   141,   142,   144,   145,   118,   119,   120,   135,
     136,   121,   122,   126,   246,   247,   174,   175,   187,   188,
       0,   204,   205,     0,     0,     0,     0,     0,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,    48,    28,    31,    30,    35,    36,    33,    34,
      49,    37,    43,    44,    45,    63,    64,    65,    66,    47,
      46,    50,    51,    52,    53,    54,    27,    55,    56,   109,
     111,   107,   127,   128,   129,   108,   150,   146,   153,   147,
     110,    57,    58,   162,   163,   164,    60,   177,   178,   189,
     190,   185,   186,   180,   199,   200,   179,   208,   209,   202,
     237,   238,   239,   203,   245,   244,   243,   249,   250,   181,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     183,   182,   184,   198,   201,    26,    59,     0,    18,     0,
       0,     0,     0,    19,     0,   319,    12,   296,   299,     0,
     297,   298,     0,   331,     0,   317,     0,   148,   151,   149,
     152,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
      14,     0,     0,     0,    17,    20,    16,     0,     0,   306,
     323,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,   161,     0,     0,     0,     0,     0,   150,   222,   153,
     234,   189,   190,   221,   233,     0,   217,   213,   214,     0,
     223,   219,   220,     0,   229,   225,   226,     0,   235,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,   343,
       0,   341,   342,     0,     0,    32,    41,    38,    40,    39,
      73,    74,    77,    75,    76,    78,    67,    68,    80,    69,
      70,    71,    79,    81,    82,    83,    72,    85,    62,     0,
      31,   313,     0,   309,   310,   311,   312,     0,     0,     0,
       0,   300,     0,   322,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,   106,    42,     0,   251,     0,   252,     0,   240,
       0,     0,     0,     0,   286,   287,    31,   176,   344,     0,
       0,     0,    96,     0,    99,   100,   101,     0,    84,    61,
     315,     0,   314,    24,    25,     0,     0,     0,   301,     0,
       0,   195,   196,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    95,     0,     0,     0,
     218,   224,     0,     0,   230,   236,     0,     0,     0,     0,
       0,     0,   307,   104,   105,    97,     0,   102,     0,   316,
      21,    22,    23,     0,   212,   281,   255,   206,   207,     0,
     253,   254,     0,     0,     0,     0,     0,     0,   272,   273,
     274,     0,     0,   248,     0,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,   284,
     285,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    98,   103,     0,   282,     0,   256,   277,
       0,     0,     0,   276,   275,    91,   242,    87,    88,    89,
      90,   340,     0,   279,     0,     0,     0,   283,     0,     0,
       0,     0,   280,     0,     0,     0,   269,   270,   271
  };

  const short
  BisonImplementation::yypgoto_[] =
  {
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
     658,   -38,   -30,  -497,   447,  -307,   -52,  -497,  -497,  -497,
    -497,  -497,   650,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,   429,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -263,  -262,  -269,  -268,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,   136,  -261,  -267,
    -260,  -266,  -497,   833,  -497,  -226,  -497,   -91,  -497,  -497,
    -497,   351,  -454,  -497,  -497,  -497,  -497,   449,  -497,  -497,
    -497,   472,  -497,  -497,  -497,   448,  -497,  -497,  -497,   462,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -496,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,   -19,  -313,   592,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -376,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,   -31,     0,  -463,  -497,   647,  -497,  -497,  -497,  -497,
     -26,     1,  -497,  -497,   538,  -497,  -497,  -497
  };

  const short
  BisonImplementation::yydefgoto_[] =
  {
       0,    11,    43,    44,    45,    46,    47,    48,    49,   242,
     243,   485,   419,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   347,   348,   349,
     176,   473,   474,   475,   476,   477,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    64,    65,    61,    62,   493,   494,   203,   204,
     205,   536,   206,   207,   208,   538,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   539,   540,   541,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   333,   231,   232,
     233,   234,    12,    13,   248,   249,   250,   251,    14,    15,
      16,   235,    17,   422,   423,   424,   425,   426,    18,    19,
      20,    36,   236,   434,    22,    23,    24,    25,    26,    27,
      28,   427,    30,    31,   389,   390,   391,   392
  };

  const short
  BisonImplementation::yytable_[] =
  {
      21,    29,   247,    59,    56,    66,   421,   151,   237,   244,
      58,   420,   359,   360,   362,   364,    51,   469,   357,   358,
     361,   363,     1,    21,    57,   252,   533,   290,   291,    21,
     327,    59,   292,   470,   470,    63,   537,    35,   253,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
      -3,     1,   352,   353,   290,   291,   449,    21,    32,   292,
     471,   471,   290,   291,   489,    -2,     1,   292,    34,   587,
     290,   291,   512,   513,   261,   292,   259,   260,   566,    54,
     421,   466,   290,   291,   290,   291,    55,   292,   566,   292,
     388,     1,   296,   467,   297,    52,     1,   290,   291,    33,
       2,   585,   292,   277,   328,   453,   608,     4,    35,   480,
       3,   537,   537,    50,   482,    60,   525,   472,   246,   526,
     290,   291,   564,     1,   566,   292,     4,   490,     5,     2,
     450,   129,   257,   258,     6,     7,     8,     9,    10,     3,
     255,   351,   290,   291,     2,   245,   320,   292,   537,   464,
     562,     1,   567,    53,     3,     4,   480,     5,   508,   509,
     329,   465,   603,     6,     7,     8,     9,    10,   529,     2,
       4,   293,     5,   584,     2,   254,   479,    63,     6,     7,
       8,     9,    10,   262,     3,   565,   263,   359,   360,   362,
     364,   357,   358,   361,   363,     4,     1,   280,   612,   548,
       4,     2,     5,     6,     7,     8,     9,   264,     6,     7,
       8,     9,    10,   421,   290,   291,   128,   290,   291,   292,
     330,   549,   292,   290,   291,   128,   129,     4,   292,     2,
     381,   238,   259,   260,   522,     6,     7,     8,     9,   239,
     240,   241,   396,   397,   398,   399,   290,   291,   577,   480,
     265,   292,   294,   295,   296,     4,   297,   386,   387,   483,
     484,   324,   395,     6,     7,     8,     9,   290,   291,   239,
     240,   241,   292,   266,     2,   247,   350,   290,   291,   583,
      21,    29,   292,   382,   383,   384,   385,   294,   295,   296,
     458,   297,   281,   550,   355,   356,   595,   294,   295,   296,
       4,   297,   597,   436,   437,   316,   317,   267,     6,     7,
       8,     9,   268,    87,    88,   534,   568,   418,   269,    21,
     294,   295,   296,   555,   297,   598,   294,   295,   296,   593,
     297,   290,   291,   290,   291,    56,   292,   270,   292,   294,
     295,   296,   271,   297,   491,   492,   599,   294,   295,   296,
     272,   297,   128,   129,    21,    57,   600,   273,   318,    87,
      88,   534,   319,   535,   459,   313,   314,   315,   316,   317,
      87,    88,   534,   289,   594,   274,    87,    88,   534,   294,
     295,   296,   545,   297,   295,   296,   275,   297,   497,   498,
     499,   486,   487,    21,   503,   504,   326,   556,   332,   334,
     335,    59,   488,   616,   543,   544,   516,   601,   517,   518,
     519,   520,   276,   500,   501,   502,   617,   278,   279,   321,
     586,   318,    21,   481,   618,   319,   607,    21,  -229,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   282,   283,   284,   506,
     314,   315,   316,   317,   285,    59,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   322,    21,
     481,   524,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    21,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   571,   572,   573,   286,   318,   563,   574,
     575,   319,   315,   316,   317,   318,    37,   287,    38,   319,
      39,   288,    40,   331,    41,    42,   294,   295,   296,   318,
     297,   323,     4,   319,   576,   388,    21,   578,   579,   580,
     581,   582,   318,   393,   428,   394,   319,   429,   604,   605,
     606,   430,   432,   435,   318,   433,   438,   439,   319,   294,
     295,   296,   546,   297,   440,   441,   318,   613,   614,   615,
     319,   442,    21,   481,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   443,   444,    85,    86,    87,    88,   445,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   446,   447,   133,   294,   295,   296,   547,
     297,   448,   451,   452,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,  -216,   478,     4,
    -228,  -215,   147,  -227,   148,   149,   150,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,  -229,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,  -229,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   294,   295,   296,   551,
     297,   294,   295,   296,   552,   297,   454,   456,   318,   460,
     455,   461,   319,   294,   295,   296,   557,   297,   294,   295,
     296,   558,   297,   294,   295,   296,   559,   297,   318,   457,
     462,   463,   319,   294,   295,   296,   560,   297,   294,   295,
     296,   590,   297,   292,   495,   496,   507,   318,   523,   521,
     528,   319,  -229,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,  -229,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,  -229,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   311,   312,   313,   314,   315,   316,   317,
     318,   530,   531,   532,   319,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   542,   318,   257,   553,   554,
     319,   310,   311,   312,   313,   314,   315,   316,   317,   259,
     561,   318,   258,   260,   569,   319,   312,   313,   314,   315,
     316,   317,   570,   589,   318,   505,   596,   602,   319,   256,
     325,   318,   527,   510,   514,   319,   294,   295,   296,   591,
     297,   294,   295,   296,   592,   297,   318,   588,   515,   431,
     319,   294,   295,   296,   609,   297,   511,   354,   468,     0,
     318,     0,     0,     0,   319,   294,   295,   296,   610,   297,
       0,     0,     0,   318,     0,     0,     0,   319,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   294,   295,   296,   611,
     297
  };

  const short
  BisonImplementation::yycheck_[] =
  {
       0,     0,    54,    29,    23,    36,   319,    37,    38,    40,
      29,   318,   281,   281,   281,   281,     0,   393,   281,   281,
     281,   281,     1,    23,    23,    55,   489,     3,     4,    29,
       8,    57,     8,     1,     1,   103,   490,   105,    57,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
       0,     1,   278,   279,     3,     4,     8,    57,    79,     8,
      28,    28,     3,     4,    18,     0,     1,     8,    81,   565,
       3,     4,    16,    17,    74,     8,    74,    75,     8,    81,
     393,   388,     3,     4,     3,     4,    88,     8,     8,     8,
      81,     1,     7,    84,     9,    79,     1,     3,     4,     1,
      79,   564,     8,   133,    82,    84,   602,   105,   105,   422,
      89,   565,   566,     0,   427,   103,    84,    84,   127,    87,
       3,     4,    18,     1,     8,     8,   105,    81,   107,    79,
      82,    75,    74,    75,   113,   114,   115,   116,   117,    89,
      79,    82,     3,     4,    79,   118,   122,     8,   602,    82,
     526,     1,    82,   137,    89,   105,   469,   107,    16,    17,
      79,    82,    82,   113,   114,   115,   116,   117,   481,    79,
     105,   120,   107,    79,    79,    82,    86,   103,   113,   114,
     115,   116,   117,    81,    89,    81,    81,   456,   456,   456,
     456,   454,   454,   454,   454,   105,     1,    83,    82,    82,
     105,    79,   107,   113,   114,   115,   116,    81,   113,   114,
     115,   116,   117,   526,     3,     4,    74,     3,     4,     8,
      79,    82,     8,     3,     4,    74,    75,   105,     8,    79,
     282,   124,    74,    75,    84,   113,   114,   115,   116,   132,
     133,   134,   294,   295,   296,   297,     3,     4,   555,   562,
      81,     8,     5,     6,     7,   105,     9,   287,   288,   130,
     131,   124,   292,   113,   114,   115,   116,     3,     4,   132,
     133,   134,     8,    81,    79,   327,   276,     3,     4,    84,
     280,   280,     8,   283,   284,   285,   286,     5,     6,     7,
       8,     9,    83,    82,    16,    17,    82,     5,     6,     7,
     105,     9,    82,   334,   335,    28,    29,    81,   113,   114,
     115,   116,    81,    32,    33,    34,   542,   317,    81,   319,
       5,     6,     7,     8,     9,    82,     5,     6,     7,    82,
       9,     3,     4,     3,     4,   354,     8,    81,     8,     5,
       6,     7,    81,     9,   103,   104,    82,     5,     6,     7,
      81,     9,    74,    75,   354,   354,    82,    81,    81,    32,
      33,    34,    85,    82,    82,    25,    26,    27,    28,    29,
      32,    33,    34,    83,    82,    81,    32,    33,    34,     5,
       6,     7,     8,     9,     6,     7,    81,     9,   440,   441,
     442,   429,   430,   393,   446,   447,   126,    82,   262,   263,
     264,   427,   432,    82,   495,   496,   458,    79,   460,   461,
     462,   463,    81,   443,   444,   445,    82,    81,    81,   135,
      82,    81,   422,   422,    82,    85,    82,   427,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    81,    81,    81,   449,
      26,    27,    28,    29,    81,   481,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   135,   469,
     469,   471,    21,    22,    23,    24,    25,    26,    27,    28,
      29,   481,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,   545,   546,   547,    81,    81,   528,   551,
     552,    85,    27,    28,    29,    81,   119,    81,   121,    85,
     123,    81,   125,    79,   127,   128,     5,     6,     7,    81,
       9,   135,   105,    85,   554,    81,   526,   557,   558,   559,
     560,   561,    81,    83,   136,    83,    85,   136,   590,   591,
     592,   136,    88,     8,    81,   105,    82,    82,    85,     5,
       6,     7,     8,     9,     8,     8,    81,   609,   610,   611,
      85,     8,   562,   562,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     8,     8,    30,    31,    32,    33,     8,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     8,     8,    81,     5,     6,     7,     8,
       9,     8,    82,    82,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     8,    82,   105,
       8,     8,   108,     8,   110,   111,   112,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     5,     6,     7,     8,
       9,     5,     6,     7,     8,     9,     8,     8,    81,     8,
      84,     8,    85,     5,     6,     7,     8,     9,     5,     6,
       7,     8,     9,     5,     6,     7,     8,     9,    81,    84,
       8,     8,    85,     5,     6,     7,     8,     9,     5,     6,
       7,     8,     9,     8,     8,     8,    29,    81,    79,    82,
      88,    85,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    23,    24,    25,    26,    27,    28,    29,
      81,   136,   136,   136,    85,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     8,    81,    74,    82,    81,
      85,    22,    23,    24,    25,    26,    27,    28,    29,    74,
     109,    81,    75,    75,    82,    85,    24,    25,    26,    27,
      28,    29,    82,    82,    81,   448,    82,    81,    85,    66,
     242,    81,   473,   454,   456,    85,     5,     6,     7,     8,
       9,     5,     6,     7,     8,     9,    81,   566,   456,   327,
      85,     5,     6,     7,     8,     9,   454,   280,   390,    -1,
      81,    -1,    -1,    -1,    85,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    85,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,     5,     6,     7,     8,
       9
  };

  const short
  BisonImplementation::yystos_[] =
  {
       0,     1,    79,    89,   105,   107,   113,   114,   115,   116,
     117,   139,   270,   271,   276,   277,   278,   280,   286,   287,
     288,   290,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,    79,     1,    81,   105,   289,   119,   121,   123,
     125,   127,   128,   140,   141,   142,   143,   144,   145,   146,
       0,     0,    79,   137,    81,    88,   270,   299,   270,   298,
     103,   212,   213,   103,   210,   211,   289,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    30,    31,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    81,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   108,   110,   111,
     112,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   178,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   216,   217,   218,   220,   221,   222,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   266,   267,   268,   269,   279,   290,   150,   124,   132,
     133,   134,   147,   148,   289,   118,   127,   154,   272,   273,
     274,   275,   150,   270,    82,    79,   211,    74,    75,    74,
      75,   290,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,   150,    81,    81,
      83,    83,    81,    81,    81,    81,    81,    81,    81,    83,
       3,     4,     8,   120,     5,     6,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    81,    85,
     122,   135,   135,   135,   124,   148,   126,     8,    82,    79,
      79,    79,   205,   265,   205,   205,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   175,   176,   177,
     290,    82,   213,   213,   293,    16,    17,   193,   194,   195,
     196,   206,   207,   208,   209,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   154,   290,   290,   290,   290,   150,   150,    81,   302,
     303,   304,   305,    83,    83,   150,   154,   154,   154,   154,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   290,   150,
     153,   271,   281,   282,   283,   284,   285,   299,   136,   136,
     136,   272,    88,   105,   291,     8,   289,   289,    82,    82,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
      82,    82,    82,    84,     8,    84,     8,    84,     8,    82,
       8,     8,     8,     8,    82,    82,   153,    84,   302,   281,
       1,    28,    84,   179,   180,   181,   182,   183,    82,    86,
     271,   299,   271,   130,   131,   149,   149,   149,   150,    18,
      81,   103,   104,   214,   215,     8,     8,   154,   154,   154,
     150,   150,   150,   154,   154,   152,   290,    29,    16,    17,
     225,   229,    16,    17,   233,   237,   154,   154,   154,   154,
     154,    82,    84,    79,   290,    84,    87,   182,    88,   271,
     136,   136,   136,   291,    34,    82,   219,   220,   223,   250,
     251,   252,     8,   215,   215,     8,     8,     8,    82,    82,
      82,     8,     8,    82,    81,     8,    82,     8,     8,     8,
       8,   109,   281,   150,    18,    81,     8,    82,   213,    82,
      82,   154,   154,   154,   154,   154,   150,   153,   150,   150,
     150,   150,   150,    84,    79,   291,    82,   250,   219,    82,
       8,     8,     8,    82,    82,    82,    82,    82,    82,    82,
      82,    79,    81,    82,   154,   154,   154,    82,   250,     8,
       8,     8,    82,   154,   154,   154,    82,    82,    82
  };

  const short
  BisonImplementation::yyr1_[] =
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
     191,   191,   191,   191,   191,   191,   192,   192,   193,   193,
     194,   195,   195,   196,   197,   197,   197,   197,   197,   197,
     197,   198,   199,   199,   199,   200,   200,   200,   201,   201,
     201,   202,   202,   202,   202,   202,   202,   203,   203,   203,
     203,   203,   204,   204,   204,   205,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   214,   215,   216,   216,
     216,   216,   216,   216,   217,   218,   219,   219,   220,   220,
     221,   222,   223,   224,   224,   225,   225,   226,   227,   228,
     228,   229,   229,   230,   231,   232,   232,   233,   233,   234,
     235,   236,   236,   237,   237,   238,   239,   240,   240,   240,
     241,   242,   243,   244,   244,   244,   245,   245,   246,   247,
     247,   248,   249,   250,   250,   251,   252,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   265,
     265,   265,   265,   265,   266,   267,   268,   269,   270,   270,
     270,   270,   270,   271,   271,   271,   272,   273,   273,   274,
     275,   276,   277,   277,   277,   277,   278,   279,   280,   281,
     281,   281,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   293,   293,   293,   294,   295,
     296,   297,   298,   298,   298,   298,   299,   299,   300,   301,
     302,   303,   303,   304,   305
  };

  const signed char
  BisonImplementation::yyr2_[] =
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       4,     6,     8,     1,     1,     1,     1,     1,     6,     1,
       1,     4,     4,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,    12,
      12,    12,     6,     6,     6,     8,     8,     8,     5,     7,
       9,     4,     6,     8,     7,     7,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     6,     2,     2,     2,     2,     4,     5,     2,     1,
       1,     1,     1,     1,     2,     2,     3,     4,     5,     3,
       1,     1,     1,     5,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       6,     1,     1,     1,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const BisonImplementation::yytname_[] =
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
  "expression.math.signal.power", "expression.math.scalar.as.tree",
  "expression.math.scalar.int", "expression.math.scalar.int.as.tree",
  "expression.math.scalar.float", "expression.math.scalar.float.as.tree",
  "expression.math.trigonometry.as.tree", "expression.parenthesis",
  "expression.signal", "expression.signal.control",
  "expression.signal.delay", "expression.signal.logic", "primitive",
  "primitive.foreign", "primitive.type.number.as.tree",
  "primitive.type.number.int", "primitive.type.number.float",
  "primitive.type.number.int.as.tree",
  "primitive.type.number.float.as.tree", "primitive.string.quoted",
  "primitive.string.quoted.as.tree", "primitive.string.unquoted",
  "primitive.string.unquoted.as.tree", "primitive.string.tag",
  "primitive.string.tag.as.tree", "primitive.signal",
  "primitive.signal.input.wire", "primitive.signal.input.terminate",
  "primitive.type", "primitive.type.cast.number",
  "primitive.type.cast.number.int", "primitive.type.cast.number.float",
  "primitive.type.cast.any", "primitive.type.number.int.list",
  "primitive.type.number.int.list.member",
  "primitive.type.number.int.list.start",
  "primitive.type.number.int.list.append",
  "primitive.type.number.int.list.as.tree",
  "primitive.type.number.int.list.member.as.tree",
  "primitive.type.number.int.list.start.as.tree",
  "primitive.type.number.int.list.append.as.tree",
  "primitive.type.number.float.list",
  "primitive.type.number.float.list.member",
  "primitive.type.number.float.list.start",
  "primitive.type.number.float.list.append",
  "primitive.type.number.float.list.as.tree",
  "primitive.type.number.float.list.member.as.tree",
  "primitive.type.number.float.list.start.as.tree",
  "primitive.type.number.float.list.append.as.tree",
  "primitive.signal.route", "primitive.signal.route.implied.outputs",
  "primitive.signal.route.implied.connections",
  "primitive.signal.route.explicit", "primitive.signal.source",
  "primitive.signal.source.table", "primitive.signal.source.soundfile",
  "primitive.signal.source.waveform.as.tree",
  "primitive.signal.source.waveform.int.as.tree",
  "primitive.signal.source.waveform.float.as.tree", "primitive.type.list",
  "primitive.type.list.start", "primitive.type.list.append",
  "primitive.ui", "primitive.ui.button", "primitive.ui.checkbox",
  "primitive.ui.vslider", "primitive.ui.hslider", "primitive.ui.nentry",
  "primitive.ui.vgroup", "primitive.ui.hgroup", "primitive.ui.tgroup",
  "primitive.ui.vbargraph", "primitive.ui.hbargraph",
  "primitive.foreign.function", "primitive.foreign.function.signature",
  "primitive.foreign.constant", "primitive.foreign.variable",
  "primitive.signal.inputs", "primitive.signal.outputs", "statement",
  "statement.definition", "statement.definition.function.arg",
  "statement.definition.function.args",
  "statement.definition.function.args.start",
  "statement.definition.function.args.append",
  "statement.definition.function.declaration",
  "statement.definition.function", "statement.definition.assignment",
  "statement.definition.with", "statement.definition.error",
  "statement.definition.list", "statement.definition.list.start",
  "statement.definition.list.start.qualified",
  "statement.definition.list.append",
  "statement.definition.list.append.qualified",
  "statement.declare.metadata", "statement.declare.feature.metadata",
  "statement.declare.doc", "statement.identifier.as.tree",
  "statement.box.identifier.as.tree",
  "statement.foreign.function.identifier.as.tree", "statement.import",
  "statement.list", "statement.list.start",
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
  BisonImplementation::yyrline_[] =
  {
       0,   442,   442,   447,   461,   464,   468,   472,   476,   480,
     484,   490,   493,   498,   504,   510,   515,   523,   526,   531,
     534,   539,   543,   549,   555,   558,   567,   568,   569,   574,
     582,   583,   586,   592,   593,   594,   595,   596,   599,   605,
     611,   617,   625,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   653,   662,   668,   669,   670,   671,   674,   678,   682,
     686,   690,   694,   700,   704,   708,   712,   716,   720,   726,
     730,   734,   740,   744,   750,   756,   760,   768,   778,   788,
     798,   810,   819,   820,   823,   832,   843,   851,   859,   871,
     872,   875,   884,   893,   903,   910,   919,   927,   928,   929,
     930,   931,   934,   938,   942,   946,   950,   954,   960,   964,
     968,   972,   976,   980,   984,   988,   992,   998,   999,  1000,
    1003,  1007,  1011,  1015,  1019,  1023,  1027,  1031,  1043,  1047,
    1053,  1057,  1061,  1065,  1069,  1073,  1079,  1080,  1083,  1086,
    1091,  1097,  1100,  1105,  1111,  1115,  1119,  1123,  1127,  1131,
    1135,  1143,  1151,  1152,  1153,  1156,  1160,  1164,  1170,  1174,
    1178,  1184,  1188,  1192,  1196,  1200,  1204,  1214,  1215,  1216,
    1217,  1218,  1223,  1224,  1225,  1230,  1231,  1234,  1239,  1244,
    1250,  1258,  1263,  1269,  1274,  1280,  1283,  1288,  1296,  1297,
    1298,  1299,  1300,  1301,  1304,  1310,  1316,  1317,  1322,  1323,
    1326,  1332,  1338,  1346,  1347,  1350,  1351,  1354,  1359,  1364,
    1365,  1368,  1369,  1372,  1377,  1384,  1385,  1388,  1389,  1392,
    1397,  1402,  1403,  1406,  1407,  1410,  1415,  1422,  1423,  1424,
    1427,  1437,  1447,  1459,  1460,  1461,  1464,  1468,  1474,  1480,
    1481,  1484,  1490,  1498,  1499,  1502,  1508,  1520,  1521,  1522,
    1523,  1524,  1525,  1526,  1527,  1528,  1529,  1532,  1538,  1544,
    1550,  1556,  1562,  1568,  1574,  1580,  1586,  1594,  1606,  1620,
    1636,  1652,  1668,  1684,  1702,  1712,  1724,  1730,  1741,  1742,
    1743,  1744,  1745,  1750,  1751,  1752,  1755,  1758,  1759,  1762,
    1771,  1780,  1789,  1793,  1797,  1801,  1809,  1818,  1827,  1836,
    1837,  1838,  1839,  1842,  1851,  1860,  1866,  1877,  1884,  1891,
    1900,  1906,  1912,  1920,  1928,  1929,  1930,  1931,  1934,  1945,
    1955,  1966,  1980,  1983,  1986,  1989,  1996,  1997,  2000,  2003,
    2010,  2015,  2016,  2019,  2028
  };

  void
  BisonImplementation::yy_stack_print_ () const
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
  BisonImplementation::yy_reduce_print_ (int yyrule) const
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


