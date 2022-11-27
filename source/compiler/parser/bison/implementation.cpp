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
        value.YY_MOVE_OR_COPY< FloatType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_285_statement_math_precision: // statement.math.precision
      case symbol_kind::S_286_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_287_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_288_statement_math_precision_list_append: // statement.math.precision.list.append
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
      case symbol_kind::S_224_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_226_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_230_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_231_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_232_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_233_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_234_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_235_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_236_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_237_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_238_primitive_type_list: // primitive.type.list
      case symbol_kind::S_239_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_240_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_241_primitive_ui: // primitive.ui
      case symbol_kind::S_242_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_243_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_244_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_245_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_246_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_247_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_248_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_249_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_250_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_251_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_252_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_253_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_254_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_255_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_256_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_257_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_259_statement_definition: // statement.definition
      case symbol_kind::S_260_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_261_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_262_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_263_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_264_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_265_statement_definition_function: // statement.definition.function
      case symbol_kind::S_266_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_267_statement_definition_with: // statement.definition.with
      case symbol_kind::S_268_statement_definition_list: // statement.definition.list
      case symbol_kind::S_269_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_270_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_271_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_272_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_273_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_274_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_275_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_276_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_277_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_278_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_279_statement_import: // statement.import
      case symbol_kind::S_280_statement_list: // statement.list
      case symbol_kind::S_281_statement_list_start: // statement.list.start
      case symbol_kind::S_282_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_283_statement_list_append: // statement.list.append
      case symbol_kind::S_284_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_289_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_290_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_291_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_292_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
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

      case symbol_kind::S_225_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_227_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_228_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
        value.move< FloatType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_285_statement_math_precision: // statement.math.precision
      case symbol_kind::S_286_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_287_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_288_statement_math_precision_list_append: // statement.math.precision.list.append
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
      case symbol_kind::S_224_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_226_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_230_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_231_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_232_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_233_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_234_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_235_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_236_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_237_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_238_primitive_type_list: // primitive.type.list
      case symbol_kind::S_239_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_240_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_241_primitive_ui: // primitive.ui
      case symbol_kind::S_242_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_243_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_244_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_245_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_246_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_247_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_248_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_249_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_250_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_251_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_252_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_253_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_254_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_255_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_256_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_257_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_259_statement_definition: // statement.definition
      case symbol_kind::S_260_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_261_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_262_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_263_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_264_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_265_statement_definition_function: // statement.definition.function
      case symbol_kind::S_266_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_267_statement_definition_with: // statement.definition.with
      case symbol_kind::S_268_statement_definition_list: // statement.definition.list
      case symbol_kind::S_269_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_270_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_271_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_272_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_273_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_274_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_275_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_276_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_277_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_278_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_279_statement_import: // statement.import
      case symbol_kind::S_280_statement_list: // statement.list
      case symbol_kind::S_281_statement_list_start: // statement.list.start
      case symbol_kind::S_282_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_283_statement_list_append: // statement.list.append
      case symbol_kind::S_284_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_289_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_290_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_291_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_292_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
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

      case symbol_kind::S_225_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_227_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_228_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
        value.copy< FloatType > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_285_statement_math_precision: // statement.math.precision
      case symbol_kind::S_286_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_287_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_288_statement_math_precision_list_append: // statement.math.precision.list.append
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
      case symbol_kind::S_224_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_226_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_230_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_231_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_232_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_233_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_234_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_235_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_236_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_237_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_238_primitive_type_list: // primitive.type.list
      case symbol_kind::S_239_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_240_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_241_primitive_ui: // primitive.ui
      case symbol_kind::S_242_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_243_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_244_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_245_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_246_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_247_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_248_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_249_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_250_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_251_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_252_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_253_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_254_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_255_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_256_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_257_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_259_statement_definition: // statement.definition
      case symbol_kind::S_260_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_261_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_262_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_263_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_264_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_265_statement_definition_function: // statement.definition.function
      case symbol_kind::S_266_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_267_statement_definition_with: // statement.definition.with
      case symbol_kind::S_268_statement_definition_list: // statement.definition.list
      case symbol_kind::S_269_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_270_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_271_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_272_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_273_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_274_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_275_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_276_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_277_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_278_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_279_statement_import: // statement.import
      case symbol_kind::S_280_statement_list: // statement.list
      case symbol_kind::S_281_statement_list_start: // statement.list.start
      case symbol_kind::S_282_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_283_statement_list_append: // statement.list.append
      case symbol_kind::S_284_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_289_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_290_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_291_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_292_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
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

      case symbol_kind::S_225_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_227_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_228_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
        value.move< FloatType > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_285_statement_math_precision: // statement.math.precision
      case symbol_kind::S_286_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_287_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_288_statement_math_precision_list_append: // statement.math.precision.list.append
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
      case symbol_kind::S_224_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_226_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_230_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_231_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_232_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_233_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_234_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_235_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_236_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_237_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_238_primitive_type_list: // primitive.type.list
      case symbol_kind::S_239_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_240_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_241_primitive_ui: // primitive.ui
      case symbol_kind::S_242_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_243_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_244_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_245_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_246_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_247_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_248_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_249_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_250_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_251_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_252_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_253_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_254_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_255_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_256_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_257_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_259_statement_definition: // statement.definition
      case symbol_kind::S_260_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_261_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_262_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_263_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_264_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_265_statement_definition_function: // statement.definition.function
      case symbol_kind::S_266_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_267_statement_definition_with: // statement.definition.with
      case symbol_kind::S_268_statement_definition_list: // statement.definition.list
      case symbol_kind::S_269_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_270_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_271_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_272_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_273_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_274_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_275_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_276_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_277_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_278_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_279_statement_import: // statement.import
      case symbol_kind::S_280_statement_list: // statement.list
      case symbol_kind::S_281_statement_list_start: // statement.list.start
      case symbol_kind::S_282_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_283_statement_list_append: // statement.list.append
      case symbol_kind::S_284_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_289_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_290_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_291_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_292_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
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

      case symbol_kind::S_225_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_227_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_228_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
  self._location.streamName() = self._streamName;
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
        yylhs.value.emplace< FloatType > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_193_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_206_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_285_statement_math_precision: // statement.math.precision
      case symbol_kind::S_286_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_287_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_288_statement_math_precision_list_append: // statement.math.precision.list.append
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
      case symbol_kind::S_224_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_226_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_230_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_231_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_232_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_233_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_234_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_235_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_236_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_237_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_238_primitive_type_list: // primitive.type.list
      case symbol_kind::S_239_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_240_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_241_primitive_ui: // primitive.ui
      case symbol_kind::S_242_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_243_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_244_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_245_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_246_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_247_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_248_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_249_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_250_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_251_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_252_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_253_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_254_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_255_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_256_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_257_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_259_statement_definition: // statement.definition
      case symbol_kind::S_260_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_261_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_262_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_263_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_264_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_265_statement_definition_function: // statement.definition.function
      case symbol_kind::S_266_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_267_statement_definition_with: // statement.definition.with
      case symbol_kind::S_268_statement_definition_list: // statement.definition.list
      case symbol_kind::S_269_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_270_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_271_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_272_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_273_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_274_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_275_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_276_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_277_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_278_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_279_statement_import: // statement.import
      case symbol_kind::S_280_statement_list: // statement.list
      case symbol_kind::S_281_statement_list_start: // statement.list.start
      case symbol_kind::S_282_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_283_statement_list_append: // statement.list.append
      case symbol_kind::S_284_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_289_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_290_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_291_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_292_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
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

      case symbol_kind::S_225_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_227_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_228_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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

  case 84: // expression.infix.prefix: expression.infix LPAR statement.definition.function.args RPAR
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

  case 213: // primitive.type.number.int.list.member.as.tree: primitive.type.number.int.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 214: // primitive.type.number.int.list.member.as.tree: expression.math.scalar.int.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 215: // primitive.type.number.list.as.tree: primitive.type.number.list.start.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 216: // primitive.type.number.list.as.tree: primitive.type.number.list.append.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 217: // primitive.type.number.list.member.as.tree: primitive.type.number.int.list.member.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 218: // primitive.type.number.list.member.as.tree: primitive.type.number.float.list.member.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 219: // primitive.type.number.list.start.as.tree: primitive.type.number.list.member.as.tree
                                                  {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 220: // primitive.type.number.list.append.as.tree: primitive.type.number.list.as.tree COMMA primitive.type.number.list.member.as.tree
                                                                                           {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 221: // primitive.type.number.float.list.member.as.tree: primitive.type.number.float.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 222: // primitive.type.number.float.list.member.as.tree: expression.math.scalar.float.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 223: // primitive.signal.route: primitive.signal.route.implied.outputs
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 224: // primitive.signal.route: primitive.signal.route.implied.connections
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 225: // primitive.signal.route: primitive.signal.route.explicit
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 226: // primitive.signal.route.implied.outputs: ROUTE LPAR statement.definition.function.arg RPAR
                                                                         {
            yylhs.value.as < Tree > () = ::boxRoute(
              yystack_[1].value.as < Tree > (),
              yystack_[1].value.as < Tree > (),
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 227: // primitive.signal.route.implied.connections: ROUTE LPAR statement.definition.function.arg COMMA statement.definition.function.arg RPAR
                                                                                                                     {
            yylhs.value.as < Tree > () = ::boxRoute(
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > (),
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 228: // primitive.signal.route.explicit: ROUTE LPAR statement.definition.function.arg COMMA statement.definition.function.arg COMMA expression RPAR
                                                                                                                                      {
            yylhs.value.as < Tree > () = boxRoute(
              yystack_[5].value.as < Tree > (),
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > ()
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 229: // primitive.signal.source: primitive.signal.source.waveform.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 230: // primitive.signal.source: primitive.signal.source.soundfile
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 231: // primitive.signal.source: primitive.signal.source.table
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 232: // primitive.signal.source.table: RDTBL
                {
            yylhs.value.as < Tree > () = ::boxPrim3(sigReadOnlyTable);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 233: // primitive.signal.source.table: RWTBL
                {
            yylhs.value.as < Tree > () = ::boxPrim5(sigWriteReadTable);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 234: // primitive.signal.source.soundfile: SOUNDFILE LPAR primitive.string.unquoted.as.tree COMMA expression.composition RPAR
                                                                                             {
            yylhs.value.as < Tree > () = ::boxSoundfile( yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 235: // primitive.signal.source.waveform.as.tree: WAVEFORM LBRAQ primitive.type.number.list.as.tree RBRAQ
                                                                {
          yylhs.value.as < Tree > () = ::boxWaveform( yystack_[1].value.as < std::vector<Tree> > () );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 236: // primitive.type.list: primitive.type.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 237: // primitive.type.list: primitive.type.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 238: // primitive.type.list.start: primitive.type
                         {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),::Faust::Primitive::Symbols::asTree().nil);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 239: // primitive.type.list.append: primitive.type.list COMMA primitive.type
                                                   {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[0].value.as < Tree > (),
              yystack_[2].value.as < Tree > ()
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 240: // primitive.ui: primitive.ui.button
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 241: // primitive.ui: primitive.ui.checkbox
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 242: // primitive.ui: primitive.ui.vslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 243: // primitive.ui: primitive.ui.hslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 244: // primitive.ui: primitive.ui.nentry
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 245: // primitive.ui: primitive.ui.vgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 246: // primitive.ui: primitive.ui.hgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 247: // primitive.ui: primitive.ui.tgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 248: // primitive.ui: primitive.ui.vbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 249: // primitive.ui: primitive.ui.hbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 250: // primitive.ui.button: BUTTON LPAR primitive.string.unquoted.as.tree RPAR
                                                           {
          yylhs.value.as < Tree > () = ::boxButton(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 251: // primitive.ui.checkbox: CHECKBOX LPAR primitive.string.unquoted.as.tree RPAR
                                                             {
          yylhs.value.as < Tree > () = ::boxCheckbox(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 252: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                                    {
          yylhs.value.as < Tree > () = ::boxVSlider(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 253: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                                    {
          yylhs.value.as < Tree > () = ::boxHSlider(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 254: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                                                                                                   {
          yylhs.value.as < Tree > () = ::boxNumEntry(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 255: // primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                                                                            {
          yylhs.value.as < Tree > () = ::boxVGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 256: // primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                                                                            {
          yylhs.value.as < Tree > () = ::boxHGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 257: // primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                                                                            {
          yylhs.value.as < Tree > () = ::boxTGroup(yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 258: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                  {
          yylhs.value.as < Tree > () = ::boxVBargraph(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 259: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                                                                                                                                                  {
          yylhs.value.as < Tree > () = ::boxHBargraph(yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 260: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag.as.tree COMMA primitive.string.unquoted.as.tree RPAR
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

  case 261: // primitive.foreign.function.signature: primitive.type.cast.number statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
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

  case 262: // primitive.foreign.function.signature: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
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

  case 263: // primitive.foreign.function.signature: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
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

  case 264: // primitive.foreign.function.signature: primitive.type.cast.number statement.foreign.function.identifier.as.tree LPAR RPAR
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

  case 265: // primitive.foreign.function.signature: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
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

  case 266: // primitive.foreign.function.signature: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
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

  case 267: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.cast.number statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                                                                                                                       {
          yylhs.value.as < Tree > () = ::boxFConst(
            yystack_[4].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 268: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.cast.number statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                                                                                                                       {
          yylhs.value.as < Tree > () = ::boxFVar(
            yystack_[4].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 269: // primitive.signal.inputs: INPUTS LPAR expression RPAR
                                    {
          yylhs.value.as < Tree > () = ::boxInputs(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 270: // primitive.signal.outputs: OUTPUTS LPAR expression RPAR
                                     {
          yylhs.value.as < Tree > () = ::boxOutputs(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 271: // statement: statement.definition
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 272: // statement: statement.declare.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 273: // statement: statement.declare.feature.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 274: // statement: statement.declare.doc
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 275: // statement: statement.import
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 276: // statement.definition: statement.definition.function
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 277: // statement.definition: statement.definition.assignment
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 278: // statement.definition.function.arg: expression.composition.serial
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 279: // statement.definition.function.args: statement.definition.function.args.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 280: // statement.definition.function.args: statement.definition.function.args.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 281: // statement.definition.function.args.start: statement.definition.function.arg
                                        {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[0].value.as < Tree > (),
          ::Faust::Primitive::Symbols::asTree().nil
        );
       yylhs.value.as < Tree > ()->location() = yylhs.location;
     }
    break;

  case 282: // statement.definition.function.args.append: statement.definition.function.args COMMA statement.definition.function.arg
                                                                                 {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[0].value.as < Tree > (),
          yystack_[2].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 283: // statement.definition.function.declaration: statement.box.identifier.as.tree LPAR statement.definition.function.args RPAR DEF expression
                                                                                                   {
        yylhs.value.as < Tree > () = cons(
          yystack_[5].value.as < Tree > (),
          ::cons( yystack_[3].value.as < Tree > (), yystack_[0].value.as < Tree > () )
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 284: // statement.definition.function: statement.definition.function.declaration ENDDEF
                                                         {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 285: // statement.definition.function: statement.definition.function.declaration ENDOFINPUT
                                                             {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 286: // statement.definition.function: statement.definition.function.declaration ENDL
                                                       {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 287: // statement.definition.function: ENDDEF error
                     {
        yyerrok;
        yyclearin;
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 288: // statement.definition.assignment: statement.box.identifier.as.tree DEF expression ENDDEF
                                                               {
          yylhs.value.as < Tree > () = cons(
            yystack_[3].value.as < Tree > (),
            ::cons( ::Faust::Primitive::Symbols::asTree().nil, yystack_[1].value.as < Tree > () )
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 289: // statement.definition.with: expression WITH LBRAQ statement.definition.list RBRAQ
                                                            {
        yylhs.value.as < Tree > () = ::boxWithLocalDef(
          yystack_[4].value.as < Tree > (),
          self.formatDefinitions(yystack_[1].value.as < Tree > ())
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 290: // statement.definition.list: statement.definition.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 291: // statement.definition.list: statement.definition.list.start.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 292: // statement.definition.list: statement.definition.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 293: // statement.definition.list: statement.definition.list.append.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 294: // statement.definition.list.start: statement.definition
                               {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[0].value.as < Tree > (),
              ::Faust::Primitive::Symbols::asTree().nil
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 295: // statement.definition.list.start.qualified: statement.math.precision.list statement.definition
                                                             {
            if (self.acceptdefinition(yystack_[1].value.as < IntType > ()))
              yylhs.value.as < Tree > () = ::cons( yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil );
            else
              yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 296: // statement.definition.list.append: statement.definition.list statement.definition
                                                         {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ());
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 297: // statement.definition.list.append.qualified: statement.definition.list statement.math.precision.list statement.definition
                                                                                       {
            if (self.acceptdefinition(yystack_[1].value.as < IntType > ()))
              yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),yystack_[2].value.as < Tree > ());
            else
              yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > ();
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 298: // statement.declare.metadata: DECLARE statement.identifier.as.tree primitive.string.quoted.as.tree ENDDEF
                                                                                              {
        self.declareMetadata(yystack_[2].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 299: // statement.declare.feature.metadata: DECLARE statement.identifier.as.tree statement.identifier.as.tree primitive.string.quoted.as.tree ENDDEF
                                                                                                                                    {
        self.declareDefinitionMetadata( yystack_[3].value.as < Tree > (), yystack_[2].value.as < Tree > (), yystack_[1].value.as < Tree > () );
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 300: // statement.declare.doc: BDOC doc EDOC
                          {
        ::declareDoc(yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 301: // statement.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::tree(self._lexer->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 302: // statement.box.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::boxIdent(self._lexer->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 303: // statement.foreign.function.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::tree(self._lexer->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 304: // statement.import: IMPORT LPAR primitive.string.unquoted.as.tree RPAR ENDDEF
                                                                          {
        yylhs.value.as < Tree > () = ::importFile(yystack_[2].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 305: // statement.list: statement.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 306: // statement.list: statement.list.start.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 307: // statement.list: statement.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 308: // statement.list: statement.list.append.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 309: // statement.list.start: statement
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

  case 310: // statement.list.start.qualified: statement.math.precision.list statement
                                                {
          if ( yystack_[0].value.as < Tree > () != ::Faust::Primitive::Symbols::asTree().nil
            && self.acceptdefinition(yystack_[1].value.as < IntType > ()))
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil);
          else
            yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 311: // statement.list.append: statement.list statement
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

  case 312: // statement.list.append.qualified: statement.list statement.math.precision.list statement
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

  case 313: // statement.math.precision: FLOATMODE
                  {
          yylhs.value.as < IntType > () = 1;
        }
    break;

  case 314: // statement.math.precision: DOUBLEMODE
                   {
          yylhs.value.as < IntType > () = 2;
        }
    break;

  case 315: // statement.math.precision: QUADMODE
                 {
          yylhs.value.as < IntType > () = 4;
        }
    break;

  case 316: // statement.math.precision: FIXEDPOINTMODE
                       {
          yylhs.value.as < IntType > () = 8;
        }
    break;

  case 317: // statement.math.precision.list: statement.math.precision.list.start
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 318: // statement.math.precision.list: statement.math.precision.list.append
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 319: // statement.math.precision.list.start: statement.math.precision
            { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 320: // statement.math.precision.list.append: statement.math.precision.list statement.math.precision
                                                                   {
              yylhs.value.as < IntType > () = yystack_[1].value.as < IntType > () | yystack_[0].value.as < IntType > ();
            }
    break;

  case 321: // statement.signal.pattern.rule: LPAR statement.definition.function.args RPAR ARROW expression ENDDEF
                                                                           {
        yylhs.value.as < Tree > () = ::cons(yystack_[4].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 322: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 323: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 324: // statement.signal.pattern.rule.list.start: statement.signal.pattern.rule
                                      {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 325: // statement.signal.pattern.rule.list.append: statement.signal.pattern.rule.list statement.signal.pattern.rule
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


  const short BisonImplementation::yypact_ninf_ = -436;

  const signed char BisonImplementation::yytable_ninf_ = -1;

  const short
  BisonImplementation::yypact_[] =
  {
     759,    32,   -28,  -436,   -44,  -436,  -436,  -436,  -436,   361,
      87,  -436,  -436,     9,  -436,  -436,  -436,  -436,  -436,    68,
    -436,   759,  -436,  -436,  -436,  -436,  -436,   759,  -436,  -436,
    -436,     8,  -436,   101,   529,   529,    86,   -44,  -436,  -436,
      37,     6,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,   529,   529,  -436,   759,  -436,  -436,  -436,  -436,    89,
    -436,  -436,    80,    79,  -436,  -436,  -436,  -436,  -436,  -436,
      -8,   121,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,   113,   127,   136,   154,
     176,   181,   193,   208,   210,   225,   232,   234,   247,   260,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,   261,  -436,  -436,
     529,   262,   265,   177,   264,   267,  -436,  -436,   297,   299,
     305,   306,   308,   309,   314,  -436,  -436,  -436,    44,  -436,
    -436,  -436,   418,  -436,  -436,  -436,  -436,  -436,   341,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,    22,  -436,   257,   270,   271,   184,  -436,   272,
    -436,  -436,   418,  -436,    12,  -436,  -436,   137,  -436,   133,
    -436,   349,  -436,  -436,  -436,  -436,  -436,   168,   168,   168,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,   315,    54,     8,     8,   759,   198,   529,   315,   315,
     315,   315,   529,   529,   365,   372,   373,   529,  -436,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,  -436,   315,   529,   765,  -436,   321,   322,   345,  -436,
    -436,  -436,   529,   389,  -436,  -436,  -436,   378,   477,   -44,
     -44,   408,   410,   485,   487,   488,   492,   496,   507,   508,
     513,   515,    15,  -436,  -436,  -436,  -436,   442,   443,   626,
      -8,   235,  -436,  -436,  -436,  -436,  -436,    51,  -436,  -436,
    -436,  -436,    95,   519,   524,   525,   549,    60,    66,   529,
    -436,    21,  -436,  -436,   765,    28,   550,   418,   227,   215,
    -436,   632,   651,   669,   742,   758,   773,   786,   390,   441,
     808,   416,   226,   259,   406,   213,   238,   298,   124,  -436,
     108,  -436,   633,  -436,  -436,  -436,  -436,   765,   201,   201,
     201,  -436,   529,  -436,    42,   166,   555,   600,  -436,  -436,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   315,
     580,  -436,  -436,  -436,   198,  -436,   529,  -436,   529,   529,
     529,   529,  -436,  -436,   109,  -436,  -436,   415,   537,   315,
    -436,    23,  -436,  -436,  -436,   530,  -436,  -436,  -436,   765,
    -436,  -436,  -436,   481,   497,   499,   195,   378,   263,  -436,
    -436,  -436,   624,   166,   166,   222,   296,   445,    69,    72,
      75,   505,   606,   195,   554,  -436,   557,  -436,   110,   694,
     715,   720,   854,   595,  -436,  -436,  -436,  -436,   765,  -436,
     529,  -436,  -436,  -436,  -436,    77,  -436,  -436,  -436,  -436,
    -436,   129,  -436,  -436,     8,   625,   627,   529,   529,   529,
    -436,  -436,  -436,   529,   529,  -436,   529,   529,  -436,   529,
     529,   529,   529,   529,   737,   158,   378,   303,   288,  -436,
     629,  -436,  -436,   877,   907,   912,   115,   120,    78,    81,
      88,    96,   105,   111,   164,  -436,  -436,   635,  -436,   131,
    -436,  -436,   529,   529,   529,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,   339,  -436,   917,   922,   927,  -436,
     139,   529,   529,   529,  -436,   125,   174,   179,  -436,  -436,
    -436
  };

  const short
  BisonImplementation::yydefact_[] =
  {
       3,     0,     0,   302,     0,   313,   314,   315,   316,    10,
       0,   309,   271,     0,   276,   277,   272,   273,   274,     0,
     275,     2,   305,   306,   307,   308,   319,     0,   317,   318,
     287,     0,   301,     0,     0,     0,     0,     0,    11,    15,
       0,     4,     5,     6,     7,     9,     8,     1,   285,   284,
     286,     0,     0,   311,     0,   310,   320,   193,   194,     0,
     191,   192,     0,     0,   112,   113,   116,   114,   115,   117,
     130,   131,   172,   132,   133,   134,   171,   173,   138,   139,
     143,   170,   168,   169,   210,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   154,   155,   156,   157,   158,   159,   160,   140,   141,
     142,   144,   145,   118,   119,   120,   135,   136,   121,   122,
     126,   232,   233,   174,   175,   187,   188,     0,   204,   205,
       0,     0,     0,     0,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,    48,
      28,    31,    30,    35,    36,    33,    34,    49,    37,    43,
      44,    45,    63,    64,    65,    66,    47,    46,    50,    51,
      52,    53,    54,    27,    55,    56,   109,   111,   107,   127,
     128,   129,   108,   150,   146,   153,   147,   110,    57,    58,
     162,   163,   164,    60,   177,   178,   189,   190,   185,   186,
     180,   199,   200,   179,   208,   209,   202,   223,   224,   225,
     203,   231,   230,   229,   181,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   183,   182,   184,   198,   201,
      26,    59,     0,    18,     0,     0,     0,     0,    19,     0,
     300,    12,   278,   281,     0,   279,   280,     0,   312,     0,
     298,     0,   148,   151,   149,   152,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,     0,     0,    14,     0,     0,     0,    17,
      20,    16,     0,     0,   288,   304,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,   161,     0,     0,     0,
       0,     0,   214,   222,   213,   221,   217,     0,   219,   215,
     216,   218,     0,     0,     0,     0,     0,     0,     0,     0,
     324,     0,   322,   323,     0,     0,    32,    41,    38,    40,
      39,    73,    74,    77,    75,    76,    78,    67,    68,    80,
      69,    70,    71,    79,    81,    82,    83,    72,    85,    62,
       0,   294,     0,   290,   291,   292,   293,     0,     0,     0,
       0,   282,     0,   303,     0,     0,     0,     0,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,   106,    42,     0,   235,     0,   226,     0,     0,
       0,     0,   269,   270,     0,   176,   325,     0,     0,     0,
      96,     0,    99,   100,   101,     0,    84,    61,   296,     0,
     295,    24,    25,     0,     0,     0,   283,     0,     0,   195,
     196,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    95,     0,   220,     0,     0,
       0,     0,     0,     0,   289,   104,   105,    97,     0,   102,
       0,   297,    21,    22,    23,     0,   212,   264,   238,   206,
     207,     0,   236,   237,     0,     0,     0,     0,     0,     0,
     255,   256,   257,     0,     0,   234,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   261,
       0,   267,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,   103,     0,   265,     0,
     239,   260,     0,     0,     0,   259,   258,    91,   228,    87,
      88,    89,    90,   321,     0,   262,     0,     0,     0,   266,
       0,     0,     0,     0,   263,     0,     0,     0,   252,   253,
     254
  };

  const short
  BisonImplementation::yypgoto_[] =
  {
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
     469,   -76,   -24,  -436,   280,  -436,   -45,  -436,  -436,  -436,
    -436,  -436,   601,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,   279,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -261,  -436,  -260,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -259,  -258,  -436,   655,  -436,  -224,  -436,  -135,  -436,  -436,
    -436,   196,  -245,  -436,  -436,  -436,  -436,  -436,   301,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -409,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
     -19,  -309,  -267,  -279,  -436,  -436,  -436,  -436,  -436,  -436,
    -355,  -436,  -436,  -436,  -436,  -436,  -436,  -436,   -30,     0,
    -435,  -436,   439,  -436,  -436,  -436,  -436,   -23,     1,  -436,
    -436,   366,  -436,  -436,  -436
  };

  const short
  BisonImplementation::yydefgoto_[] =
  {
       0,    10,    40,    41,    42,    43,    44,    45,    46,   237,
     238,   463,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   342,   343,   344,
     173,   451,   452,   453,   454,   455,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    61,    62,    58,    59,   471,   472,   200,   201,
     202,   508,   203,   204,   205,   510,   356,   357,   358,   359,
     360,   361,   206,   207,   208,   209,   210,   211,   212,   213,
     511,   512,   513,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   328,   226,   227,   228,   229,
      11,    12,   243,   244,   245,   246,    13,    14,    15,   230,
     402,   403,   404,   405,   406,    16,    17,    18,    33,   231,
     414,    20,    21,    22,    23,    24,    25,    26,   407,    28,
      29,   370,   371,   372,   373
  };

  const short
  BisonImplementation::yytable_[] =
  {
      19,    27,    53,    63,    56,   401,   242,   239,    55,    48,
     362,   232,   327,   329,   330,   352,   353,   354,   355,   447,
     322,    19,    54,   429,   448,   285,   286,    19,   247,   448,
     287,    56,   505,    30,   400,   248,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   285,   286,   347,
     348,   449,   287,    31,    19,   411,   449,   285,   286,   434,
     467,    32,   287,   285,   286,   401,   252,   253,   287,   285,
     286,   256,   285,   286,   287,   285,   286,   287,   285,   286,
     287,   285,   286,   287,   285,   286,   287,    47,    49,   287,
     444,   285,   286,   458,   323,   536,   287,   430,   460,   285,
     286,   557,   369,   436,   287,   445,   272,   497,   285,   286,
     498,    57,   450,   287,   285,   286,   322,   322,   527,   287,
     289,   290,   291,   468,   292,   289,   290,   291,   559,   292,
     289,   290,   291,   241,   292,   435,   346,   538,   458,   538,
     285,   286,   442,   534,   315,   287,    50,   538,   443,    51,
     501,   520,   311,   312,   521,   240,    52,   522,   537,   250,
     567,   285,   286,   568,   288,   580,   287,   285,   286,   488,
     569,   249,   287,   352,   353,   354,   355,   437,   570,   289,
     290,   291,    60,   292,   289,   290,   291,   571,   292,   401,
     456,   493,   528,   572,   257,   254,   255,   565,   285,   286,
      84,    85,   566,   287,    60,   313,    32,   588,   258,   314,
     233,   539,   325,   575,   350,   351,   324,   259,   234,   235,
     236,   584,   291,   509,   292,   458,     3,   289,   290,   291,
     517,   292,   242,   290,   291,   260,   292,   556,   308,   309,
     310,   311,   312,   573,   377,   378,   379,   380,   305,   306,
     307,   308,   309,   310,   311,   312,   589,   261,   367,   368,
     275,   590,   262,   376,   309,   310,   311,   312,   242,   469,
     470,   345,   125,   126,   263,    19,    27,   242,   363,   364,
     365,   366,   306,   307,   308,   309,   310,   311,   312,   264,
     540,   265,   509,   509,   313,    84,    85,   506,   314,   416,
     417,   289,   290,   291,   518,   292,   266,   313,   319,   254,
     255,   314,   399,   267,    19,   268,   234,   235,   236,   313,
      84,    85,   506,   314,   242,   310,   311,   312,   269,   509,
      53,   461,   462,   464,   465,    84,    85,   506,   515,   516,
     313,   270,   271,   273,   314,   507,   274,   276,   277,    19,
      54,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    84,    85,   506,    19,   475,   476,   477,   278,   313,
     279,   481,   482,   314,    56,   558,   280,   281,   466,   282,
     283,   242,   316,   489,   490,   491,   492,   284,   321,   478,
     479,   480,    19,   459,   483,   317,   318,    19,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
       3,   579,   313,   289,   290,   291,   314,   292,   326,   485,
     307,   308,   309,   310,   311,   312,    56,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   369,    19,   459,   496,
     289,   290,   291,   519,   292,   374,   375,   408,   409,    19,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   543,   544,   545,   314,   535,   412,   546,   547,
      34,   410,    35,   413,    36,   415,    37,   313,    38,    39,
     418,   314,   419,   420,     1,   421,   422,   313,    19,   494,
     423,   314,   548,   549,   424,   550,   551,   552,   553,   554,
     289,   290,   291,   523,   292,   425,   426,   576,   577,   578,
       3,   427,   313,   428,   431,   432,   314,   438,     5,     6,
       7,     8,   439,   440,    19,   459,   585,   586,   587,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   441,   287,    82,
      83,    84,    85,   473,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   474,   486,
     130,   289,   290,   291,   524,   292,   495,   502,   500,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   514,   503,     3,   504,   525,   144,   526,   145,
     146,   147,    -1,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   289,
     290,   291,   529,   292,   533,     1,   320,   541,   484,   542,
     433,   561,     1,   313,   349,     2,   574,   314,   251,   457,
     289,   290,   291,   530,   292,   289,   290,   291,   531,   292,
     499,     3,   313,     4,   560,   487,   314,   446,     3,     5,
       6,     7,     8,     9,     0,     0,     5,     6,     7,     8,
     313,     0,     0,     0,   314,    -1,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,     1,     0,     0,     0,
       0,   555,     0,   313,     0,     0,     0,   314,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,     1,   313,
       0,     0,     3,   314,     1,     0,     0,     0,     2,     0,
       5,     6,     7,     8,   313,     0,     0,     0,   314,   289,
     290,   291,   532,   292,     3,     0,     4,   313,     0,     0,
       3,   314,     5,     6,     7,     8,     9,     0,     5,     6,
       7,     8,   289,   290,   291,   562,   292,     0,     0,   313,
       0,     0,     0,   314,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   289,   290,   291,   563,   292,   289,   290,   291,
     564,   292,   289,   290,   291,   581,   292,   289,   290,   291,
     582,   292,   289,   290,   291,   583,   292
  };

  const short
  BisonImplementation::yycheck_[] =
  {
       0,     0,    21,    33,    27,   314,    51,    37,    27,     0,
     277,    35,   257,   258,   259,   276,   276,   276,   276,   374,
       8,    21,    21,     8,     1,     3,     4,    27,    52,     1,
       8,    54,   467,     1,   313,    54,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,     3,     4,   273,
     274,    28,     8,    81,    54,   322,    28,     3,     4,     8,
      18,   105,     8,     3,     4,   374,    74,    75,     8,     3,
       4,    71,     3,     4,     8,     3,     4,     8,     3,     4,
       8,     3,     4,     8,     3,     4,     8,     0,    79,     8,
     369,     3,     4,   402,    82,    18,     8,    82,   407,     3,
       4,   536,    81,     8,     8,    84,   130,    84,     3,     4,
      87,   103,    84,     8,     3,     4,     8,     8,     8,     8,
       5,     6,     7,    81,     9,     5,     6,     7,   537,     9,
       5,     6,     7,   127,     9,    84,    82,     8,   447,     8,
       3,     4,    82,   498,   122,     8,   137,     8,    82,    81,
     459,    82,    28,    29,    82,   118,    88,    82,    81,    79,
      82,     3,     4,    82,   120,   574,     8,     3,     4,   436,
      82,    82,     8,   434,   434,   434,   434,    82,    82,     5,
       6,     7,   103,     9,     5,     6,     7,    82,     9,   498,
      82,    82,    82,    82,    81,    74,    75,    82,     3,     4,
      32,    33,    82,     8,   103,    81,   105,    82,    81,    85,
     124,    82,    79,    82,    16,    17,    79,    81,   132,   133,
     134,    82,     7,   468,     9,   534,   105,     5,     6,     7,
       8,     9,   277,     6,     7,    81,     9,    79,    25,    26,
      27,    28,    29,    79,   289,   290,   291,   292,    22,    23,
      24,    25,    26,    27,    28,    29,    82,    81,   282,   283,
      83,    82,    81,   287,    26,    27,    28,    29,   313,   103,
     104,   271,    74,    75,    81,   275,   275,   322,   278,   279,
     280,   281,    23,    24,    25,    26,    27,    28,    29,    81,
     514,    81,   537,   538,    81,    32,    33,    34,    85,   329,
     330,     5,     6,     7,     8,     9,    81,    81,   124,    74,
      75,    85,   312,    81,   314,    81,   132,   133,   134,    81,
      32,    33,    34,    85,   369,    27,    28,    29,    81,   574,
     349,   130,   131,   409,   410,    32,    33,    34,   473,   474,
      81,    81,    81,    81,    85,    82,    81,    83,    81,   349,
     349,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    32,    33,    34,   374,   420,   421,   422,    81,    81,
      81,   426,   427,    85,   407,    82,    81,    81,   412,    81,
      81,   436,   135,   438,   439,   440,   441,    83,   126,   423,
     424,   425,   402,   402,   428,   135,   135,   407,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     105,    82,    81,     5,     6,     7,    85,     9,    79,   429,
      24,    25,    26,    27,    28,    29,   459,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    81,   447,   447,   449,
       5,     6,     7,     8,     9,    83,    83,   136,   136,   459,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    81,   517,   518,   519,    85,   500,    88,   523,   524,
     119,   136,   121,   105,   123,     8,   125,    81,   127,   128,
      82,    85,    82,     8,    79,     8,     8,    81,   498,    84,
       8,    85,   526,   527,     8,   529,   530,   531,   532,   533,
       5,     6,     7,     8,     9,     8,     8,   562,   563,   564,
     105,     8,    81,     8,    82,    82,    85,     8,   113,   114,
     115,   116,     8,     8,   534,   534,   581,   582,   583,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     8,     8,    30,
      31,    32,    33,     8,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     8,    29,
      81,     5,     6,     7,     8,     9,    79,   136,    88,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     8,   136,   105,   136,    82,   108,    81,   110,
     111,   112,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     5,
       6,     7,     8,     9,   109,    79,   237,    82,   428,    82,
      84,    82,    79,    81,   275,    89,    81,    85,    63,    86,
       5,     6,     7,     8,     9,     5,     6,     7,     8,     9,
     451,   105,    81,   107,   538,   434,    85,   371,   105,   113,
     114,   115,   116,   117,    -1,    -1,   113,   114,   115,   116,
      81,    -1,    -1,    -1,    85,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    79,    -1,    -1,    -1,
      -1,    84,    -1,    81,    -1,    -1,    -1,    85,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    79,    81,
      -1,    -1,   105,    85,    79,    -1,    -1,    -1,    89,    -1,
     113,   114,   115,   116,    81,    -1,    -1,    -1,    85,     5,
       6,     7,     8,     9,   105,    -1,   107,    81,    -1,    -1,
     105,    85,   113,   114,   115,   116,   117,    -1,   113,   114,
     115,   116,     5,     6,     7,     8,     9,    -1,    -1,    81,
      -1,    -1,    -1,    85,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,     5,     6,     7,     8,     9,     5,     6,     7,
       8,     9,     5,     6,     7,     8,     9,     5,     6,     7,
       8,     9,     5,     6,     7,     8,     9
  };

  const short
  BisonImplementation::yystos_[] =
  {
       0,    79,    89,   105,   107,   113,   114,   115,   116,   117,
     139,   258,   259,   264,   265,   266,   273,   274,   275,   277,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
       1,    81,   105,   276,   119,   121,   123,   125,   127,   128,
     140,   141,   142,   143,   144,   145,   146,     0,     0,    79,
     137,    81,    88,   258,   286,   258,   285,   103,   212,   213,
     103,   210,   211,   276,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    30,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      81,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   108,   110,   111,   112,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   178,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     216,   217,   218,   220,   221,   222,   230,   231,   232,   233,
     234,   235,   236,   237,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   254,   255,   256,   257,
     267,   277,   150,   124,   132,   133,   134,   147,   148,   276,
     118,   127,   154,   260,   261,   262,   263,   150,   258,    82,
      79,   211,    74,    75,    74,    75,   277,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,   150,    81,    81,    83,    83,    81,    81,    81,
      81,    81,    81,    81,    83,     3,     4,     8,   120,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    81,    85,   122,   135,   135,   135,   124,
     148,   126,     8,    82,    79,    79,    79,   220,   253,   220,
     220,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   175,   176,   177,   277,    82,   213,   213,   280,
      16,    17,   194,   196,   208,   209,   224,   225,   226,   227,
     228,   229,   260,   277,   277,   277,   277,   150,   150,    81,
     289,   290,   291,   292,    83,    83,   150,   154,   154,   154,
     154,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   277,
     261,   259,   268,   269,   270,   271,   272,   286,   136,   136,
     136,   260,    88,   105,   278,     8,   276,   276,    82,    82,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
      82,    82,    82,    84,     8,    84,     8,    82,     8,     8,
       8,     8,    82,    82,   261,    84,   289,   268,     1,    28,
      84,   179,   180,   181,   182,   183,    82,    86,   259,   286,
     259,   130,   131,   149,   149,   149,   150,    18,    81,   103,
     104,   214,   215,     8,     8,   154,   154,   154,   150,   150,
     150,   154,   154,   150,   152,   277,    29,   226,   260,   154,
     154,   154,   154,    82,    84,    79,   277,    84,    87,   182,
      88,   259,   136,   136,   136,   278,    34,    82,   219,   220,
     223,   238,   239,   240,     8,   215,   215,     8,     8,     8,
      82,    82,    82,     8,     8,    82,    81,     8,    82,     8,
       8,     8,     8,   109,   268,   150,    18,    81,     8,    82,
     213,    82,    82,   154,   154,   154,   154,   154,   150,   150,
     150,   150,   150,   150,   150,    84,    79,   278,    82,   238,
     219,    82,     8,     8,     8,    82,    82,    82,    82,    82,
      82,    82,    82,    79,    81,    82,   154,   154,   154,    82,
     238,     8,     8,     8,    82,   154,   154,   154,    82,    82,
      82
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
     221,   222,   223,   224,   224,   225,   225,   226,   226,   227,
     228,   229,   229,   230,   230,   230,   231,   232,   233,   234,
     234,   234,   235,   235,   236,   237,   238,   238,   239,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   253,   253,   253,   253,   253,   254,   255,   256,
     257,   258,   258,   258,   258,   258,   259,   259,   260,   261,
     261,   262,   263,   264,   265,   265,   265,   265,   266,   267,
     268,   268,   268,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   280,   280,   280,   281,
     282,   283,   284,   285,   285,   285,   285,   286,   286,   287,
     288,   289,   290,   290,   291,   292
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     4,     6,     8,     1,
       1,     1,     1,     1,     6,     4,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,    12,    12,    12,     6,     6,     6,     8,     8,
       8,     5,     7,     9,     4,     6,     8,     7,     7,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     2,     2,     2,     2,     4,     5,
       1,     1,     1,     1,     1,     2,     2,     3,     4,     5,
       3,     1,     1,     1,     5,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     6,     1,     1,     1,     2
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
  "primitive.type.cast.any",
  "primitive.type.number.int.list.member.as.tree",
  "primitive.type.number.list.as.tree",
  "primitive.type.number.list.member.as.tree",
  "primitive.type.number.list.start.as.tree",
  "primitive.type.number.list.append.as.tree",
  "primitive.type.number.float.list.member.as.tree",
  "primitive.signal.route", "primitive.signal.route.implied.outputs",
  "primitive.signal.route.implied.connections",
  "primitive.signal.route.explicit", "primitive.signal.source",
  "primitive.signal.source.table", "primitive.signal.source.soundfile",
  "primitive.signal.source.waveform.as.tree", "primitive.type.list",
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
  "statement.definition.with", "statement.definition.list",
  "statement.definition.list.start",
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
       0,   429,   429,   434,   448,   451,   455,   459,   463,   467,
     471,   477,   480,   485,   491,   497,   502,   510,   513,   518,
     521,   526,   530,   536,   542,   545,   554,   555,   556,   561,
     569,   570,   573,   579,   580,   581,   582,   583,   586,   592,
     598,   604,   612,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   640,   649,   655,   656,   657,   658,   661,   665,   669,
     673,   677,   681,   687,   691,   695,   699,   703,   707,   713,
     717,   721,   727,   731,   737,   743,   747,   755,   765,   775,
     785,   797,   806,   807,   810,   819,   830,   838,   846,   858,
     859,   862,   871,   880,   890,   897,   906,   914,   915,   916,
     917,   918,   921,   925,   929,   933,   937,   941,   947,   951,
     955,   959,   963,   967,   971,   975,   979,   985,   986,   987,
     990,   994,   998,  1002,  1006,  1010,  1014,  1018,  1030,  1034,
    1040,  1044,  1048,  1052,  1056,  1060,  1066,  1067,  1070,  1073,
    1078,  1084,  1087,  1092,  1098,  1102,  1106,  1110,  1114,  1118,
    1122,  1130,  1138,  1139,  1140,  1143,  1147,  1151,  1157,  1161,
    1165,  1171,  1175,  1179,  1183,  1187,  1191,  1201,  1202,  1203,
    1204,  1205,  1210,  1211,  1212,  1217,  1218,  1221,  1226,  1231,
    1237,  1245,  1250,  1256,  1261,  1267,  1270,  1275,  1283,  1284,
    1285,  1286,  1287,  1288,  1291,  1297,  1303,  1304,  1309,  1310,
    1313,  1319,  1325,  1333,  1334,  1337,  1338,  1341,  1342,  1345,
    1350,  1357,  1358,  1363,  1364,  1365,  1368,  1378,  1388,  1400,
    1401,  1402,  1405,  1409,  1415,  1421,  1429,  1430,  1433,  1439,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
    1463,  1469,  1475,  1481,  1487,  1493,  1499,  1505,  1511,  1517,
    1525,  1537,  1551,  1567,  1583,  1599,  1615,  1633,  1643,  1655,
    1661,  1672,  1673,  1674,  1675,  1676,  1681,  1682,  1685,  1688,
    1689,  1692,  1701,  1710,  1719,  1723,  1727,  1731,  1739,  1748,
    1759,  1760,  1761,  1762,  1765,  1774,  1783,  1789,  1800,  1807,
    1814,  1823,  1829,  1835,  1843,  1851,  1852,  1853,  1854,  1857,
    1868,  1878,  1889,  1903,  1906,  1909,  1912,  1919,  1920,  1923,
    1926,  1933,  1940,  1941,  1944,  1953
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


