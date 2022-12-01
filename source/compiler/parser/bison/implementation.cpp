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
#define yylex self.lexer()->lex




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
      case symbol_kind::S_198_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_210_primitive_type_number_float: // primitive.type.number.float
        value.YY_MOVE_OR_COPY< FloatType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_196_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_209_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_295_statement_math_precision: // statement.math.precision
      case symbol_kind::S_296_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_297_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_298_statement_math_precision_list_append: // statement.math.precision.list.append
        value.YY_MOVE_OR_COPY< IntType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_154_expression_component: // expression.component
      case symbol_kind::S_155_expression_composition: // expression.composition
      case symbol_kind::S_156_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_157_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_158_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_159_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_160_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_161_expression_composition_split: // expression.composition.split
      case symbol_kind::S_162_expression_environment: // expression.environment
      case symbol_kind::S_163_expression_infix: // expression.infix
      case symbol_kind::S_164_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_165_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_166_expression_infix_math: // expression.infix.math
      case symbol_kind::S_167_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_168_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_169_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_170_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_171_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_172_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_173_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_174_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_175_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_176_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_177_expression_lambda: // expression.lambda
      case symbol_kind::S_178_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_179_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_180_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_181_expression_letrec: // expression.letrec
      case symbol_kind::S_182_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_183_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_184_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_185_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_186_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_187_expression_library: // expression.library
      case symbol_kind::S_188_expression_math: // expression.math
      case symbol_kind::S_189_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_190_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_191_expression_math_signal: // expression.math.signal
      case symbol_kind::S_192_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_193_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_194_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_195_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_197_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_199_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_200_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_201_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_202_expression_signal: // expression.signal
      case symbol_kind::S_203_expression_signal_control: // expression.signal.control
      case symbol_kind::S_204_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_205_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_207_primitive_foreign: // primitive.foreign
      case symbol_kind::S_208_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_211_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_212_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_214_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_216_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_218_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_219_primitive_signal: // primitive.signal
      case symbol_kind::S_220_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_221_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_222_primitive_type: // primitive.type
      case symbol_kind::S_223_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_224_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_225_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_226_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_227_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_232_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_233_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_234_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_235_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_236_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_237_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_238_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_239_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_240_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_241_primitive_type_list: // primitive.type.list
      case symbol_kind::S_242_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_243_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_244_primitive_ui: // primitive.ui
      case symbol_kind::S_245_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_246_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_247_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_248_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_249_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_250_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_251_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_252_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_253_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_254_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_255_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_256_primitive_foreign_function_signature_names_1_args_0: // primitive.foreign.function.signature.names.1.args.0
      case symbol_kind::S_257_primitive_foreign_function_signature_names_1_args_list: // primitive.foreign.function.signature.names.1.args.list
      case symbol_kind::S_258_primitive_foreign_function_signature_names_2_args_0: // primitive.foreign.function.signature.names.2.args.0
      case symbol_kind::S_259_primitive_foreign_function_signature_names_2_args_list: // primitive.foreign.function.signature.names.2.args.list
      case symbol_kind::S_260_primitive_foreign_function_signature_names_3_args_0: // primitive.foreign.function.signature.names.3.args.0
      case symbol_kind::S_261_primitive_foreign_function_signature_names_3_args_list: // primitive.foreign.function.signature.names.3.args.list
      case symbol_kind::S_262_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_263_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_264_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_265_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_266_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_268_statement_definition: // statement.definition
      case symbol_kind::S_269_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_270_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_271_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_272_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_273_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_274_statement_definition_function: // statement.definition.function
      case symbol_kind::S_276_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_277_statement_definition_with: // statement.definition.with
      case symbol_kind::S_278_statement_definition_list: // statement.definition.list
      case symbol_kind::S_279_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_280_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_281_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_282_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_283_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_284_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_285_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_286_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_287_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_288_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_289_statement_import: // statement.import
      case symbol_kind::S_290_statement_list: // statement.list
      case symbol_kind::S_291_statement_list_start: // statement.list.start
      case symbol_kind::S_292_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_293_statement_list_append: // statement.list.append
      case symbol_kind::S_294_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_299_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_300_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_301_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_302_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.YY_MOVE_OR_COPY< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition_dependencies: // doc.attribute.definition.dependencies
      case symbol_kind::S_149_doc_attribute_definition_doc_tags: // doc.attribute.definition.doc.tags
      case symbol_kind::S_150_doc_attribute_definition_distributed: // doc.attribute.definition.distributed
      case symbol_kind::S_151_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_152_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_213_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_215_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_217_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_275_statement_definition_assignment_operator: // statement.definition.assignment.operator
      case symbol_kind::S_303_statement_terminal: // statement.terminal
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_228_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_230_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
      case symbol_kind::S_198_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_210_primitive_type_number_float: // primitive.type.number.float
        value.move< FloatType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_196_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_209_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_295_statement_math_precision: // statement.math.precision
      case symbol_kind::S_296_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_297_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_298_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< IntType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_154_expression_component: // expression.component
      case symbol_kind::S_155_expression_composition: // expression.composition
      case symbol_kind::S_156_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_157_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_158_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_159_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_160_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_161_expression_composition_split: // expression.composition.split
      case symbol_kind::S_162_expression_environment: // expression.environment
      case symbol_kind::S_163_expression_infix: // expression.infix
      case symbol_kind::S_164_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_165_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_166_expression_infix_math: // expression.infix.math
      case symbol_kind::S_167_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_168_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_169_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_170_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_171_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_172_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_173_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_174_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_175_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_176_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_177_expression_lambda: // expression.lambda
      case symbol_kind::S_178_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_179_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_180_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_181_expression_letrec: // expression.letrec
      case symbol_kind::S_182_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_183_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_184_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_185_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_186_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_187_expression_library: // expression.library
      case symbol_kind::S_188_expression_math: // expression.math
      case symbol_kind::S_189_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_190_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_191_expression_math_signal: // expression.math.signal
      case symbol_kind::S_192_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_193_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_194_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_195_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_197_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_199_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_200_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_201_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_202_expression_signal: // expression.signal
      case symbol_kind::S_203_expression_signal_control: // expression.signal.control
      case symbol_kind::S_204_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_205_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_207_primitive_foreign: // primitive.foreign
      case symbol_kind::S_208_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_211_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_212_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_214_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_216_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_218_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_219_primitive_signal: // primitive.signal
      case symbol_kind::S_220_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_221_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_222_primitive_type: // primitive.type
      case symbol_kind::S_223_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_224_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_225_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_226_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_227_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_232_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_233_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_234_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_235_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_236_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_237_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_238_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_239_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_240_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_241_primitive_type_list: // primitive.type.list
      case symbol_kind::S_242_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_243_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_244_primitive_ui: // primitive.ui
      case symbol_kind::S_245_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_246_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_247_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_248_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_249_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_250_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_251_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_252_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_253_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_254_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_255_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_256_primitive_foreign_function_signature_names_1_args_0: // primitive.foreign.function.signature.names.1.args.0
      case symbol_kind::S_257_primitive_foreign_function_signature_names_1_args_list: // primitive.foreign.function.signature.names.1.args.list
      case symbol_kind::S_258_primitive_foreign_function_signature_names_2_args_0: // primitive.foreign.function.signature.names.2.args.0
      case symbol_kind::S_259_primitive_foreign_function_signature_names_2_args_list: // primitive.foreign.function.signature.names.2.args.list
      case symbol_kind::S_260_primitive_foreign_function_signature_names_3_args_0: // primitive.foreign.function.signature.names.3.args.0
      case symbol_kind::S_261_primitive_foreign_function_signature_names_3_args_list: // primitive.foreign.function.signature.names.3.args.list
      case symbol_kind::S_262_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_263_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_264_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_265_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_266_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_268_statement_definition: // statement.definition
      case symbol_kind::S_269_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_270_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_271_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_272_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_273_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_274_statement_definition_function: // statement.definition.function
      case symbol_kind::S_276_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_277_statement_definition_with: // statement.definition.with
      case symbol_kind::S_278_statement_definition_list: // statement.definition.list
      case symbol_kind::S_279_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_280_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_281_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_282_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_283_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_284_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_285_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_286_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_287_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_288_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_289_statement_import: // statement.import
      case symbol_kind::S_290_statement_list: // statement.list
      case symbol_kind::S_291_statement_list_start: // statement.list.start
      case symbol_kind::S_292_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_293_statement_list_append: // statement.list.append
      case symbol_kind::S_294_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_299_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_300_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_301_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_302_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.move< Tree > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition_dependencies: // doc.attribute.definition.dependencies
      case symbol_kind::S_149_doc_attribute_definition_doc_tags: // doc.attribute.definition.doc.tags
      case symbol_kind::S_150_doc_attribute_definition_distributed: // doc.attribute.definition.distributed
      case symbol_kind::S_151_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_152_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_213_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_215_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_217_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_275_statement_definition_assignment_operator: // statement.definition.assignment.operator
      case symbol_kind::S_303_statement_terminal: // statement.terminal
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_228_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_230_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
      case symbol_kind::S_198_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_210_primitive_type_number_float: // primitive.type.number.float
        value.copy< FloatType > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_196_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_209_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_295_statement_math_precision: // statement.math.precision
      case symbol_kind::S_296_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_297_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_298_statement_math_precision_list_append: // statement.math.precision.list.append
        value.copy< IntType > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_154_expression_component: // expression.component
      case symbol_kind::S_155_expression_composition: // expression.composition
      case symbol_kind::S_156_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_157_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_158_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_159_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_160_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_161_expression_composition_split: // expression.composition.split
      case symbol_kind::S_162_expression_environment: // expression.environment
      case symbol_kind::S_163_expression_infix: // expression.infix
      case symbol_kind::S_164_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_165_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_166_expression_infix_math: // expression.infix.math
      case symbol_kind::S_167_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_168_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_169_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_170_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_171_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_172_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_173_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_174_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_175_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_176_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_177_expression_lambda: // expression.lambda
      case symbol_kind::S_178_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_179_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_180_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_181_expression_letrec: // expression.letrec
      case symbol_kind::S_182_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_183_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_184_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_185_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_186_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_187_expression_library: // expression.library
      case symbol_kind::S_188_expression_math: // expression.math
      case symbol_kind::S_189_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_190_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_191_expression_math_signal: // expression.math.signal
      case symbol_kind::S_192_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_193_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_194_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_195_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_197_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_199_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_200_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_201_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_202_expression_signal: // expression.signal
      case symbol_kind::S_203_expression_signal_control: // expression.signal.control
      case symbol_kind::S_204_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_205_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_207_primitive_foreign: // primitive.foreign
      case symbol_kind::S_208_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_211_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_212_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_214_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_216_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_218_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_219_primitive_signal: // primitive.signal
      case symbol_kind::S_220_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_221_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_222_primitive_type: // primitive.type
      case symbol_kind::S_223_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_224_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_225_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_226_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_227_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_232_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_233_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_234_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_235_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_236_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_237_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_238_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_239_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_240_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_241_primitive_type_list: // primitive.type.list
      case symbol_kind::S_242_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_243_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_244_primitive_ui: // primitive.ui
      case symbol_kind::S_245_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_246_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_247_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_248_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_249_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_250_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_251_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_252_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_253_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_254_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_255_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_256_primitive_foreign_function_signature_names_1_args_0: // primitive.foreign.function.signature.names.1.args.0
      case symbol_kind::S_257_primitive_foreign_function_signature_names_1_args_list: // primitive.foreign.function.signature.names.1.args.list
      case symbol_kind::S_258_primitive_foreign_function_signature_names_2_args_0: // primitive.foreign.function.signature.names.2.args.0
      case symbol_kind::S_259_primitive_foreign_function_signature_names_2_args_list: // primitive.foreign.function.signature.names.2.args.list
      case symbol_kind::S_260_primitive_foreign_function_signature_names_3_args_0: // primitive.foreign.function.signature.names.3.args.0
      case symbol_kind::S_261_primitive_foreign_function_signature_names_3_args_list: // primitive.foreign.function.signature.names.3.args.list
      case symbol_kind::S_262_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_263_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_264_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_265_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_266_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_268_statement_definition: // statement.definition
      case symbol_kind::S_269_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_270_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_271_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_272_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_273_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_274_statement_definition_function: // statement.definition.function
      case symbol_kind::S_276_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_277_statement_definition_with: // statement.definition.with
      case symbol_kind::S_278_statement_definition_list: // statement.definition.list
      case symbol_kind::S_279_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_280_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_281_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_282_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_283_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_284_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_285_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_286_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_287_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_288_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_289_statement_import: // statement.import
      case symbol_kind::S_290_statement_list: // statement.list
      case symbol_kind::S_291_statement_list_start: // statement.list.start
      case symbol_kind::S_292_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_293_statement_list_append: // statement.list.append
      case symbol_kind::S_294_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_299_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_300_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_301_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_302_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.copy< Tree > (that.value);
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition_dependencies: // doc.attribute.definition.dependencies
      case symbol_kind::S_149_doc_attribute_definition_doc_tags: // doc.attribute.definition.doc.tags
      case symbol_kind::S_150_doc_attribute_definition_distributed: // doc.attribute.definition.distributed
      case symbol_kind::S_151_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_152_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_213_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_215_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_217_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_275_statement_definition_assignment_operator: // statement.definition.assignment.operator
      case symbol_kind::S_303_statement_terminal: // statement.terminal
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_228_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_230_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
      case symbol_kind::S_198_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_210_primitive_type_number_float: // primitive.type.number.float
        value.move< FloatType > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_196_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_209_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_295_statement_math_precision: // statement.math.precision
      case symbol_kind::S_296_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_297_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_298_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< IntType > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_154_expression_component: // expression.component
      case symbol_kind::S_155_expression_composition: // expression.composition
      case symbol_kind::S_156_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_157_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_158_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_159_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_160_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_161_expression_composition_split: // expression.composition.split
      case symbol_kind::S_162_expression_environment: // expression.environment
      case symbol_kind::S_163_expression_infix: // expression.infix
      case symbol_kind::S_164_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_165_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_166_expression_infix_math: // expression.infix.math
      case symbol_kind::S_167_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_168_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_169_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_170_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_171_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_172_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_173_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_174_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_175_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_176_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_177_expression_lambda: // expression.lambda
      case symbol_kind::S_178_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_179_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_180_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_181_expression_letrec: // expression.letrec
      case symbol_kind::S_182_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_183_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_184_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_185_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_186_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_187_expression_library: // expression.library
      case symbol_kind::S_188_expression_math: // expression.math
      case symbol_kind::S_189_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_190_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_191_expression_math_signal: // expression.math.signal
      case symbol_kind::S_192_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_193_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_194_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_195_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_197_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_199_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_200_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_201_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_202_expression_signal: // expression.signal
      case symbol_kind::S_203_expression_signal_control: // expression.signal.control
      case symbol_kind::S_204_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_205_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_207_primitive_foreign: // primitive.foreign
      case symbol_kind::S_208_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_211_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_212_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_214_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_216_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_218_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_219_primitive_signal: // primitive.signal
      case symbol_kind::S_220_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_221_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_222_primitive_type: // primitive.type
      case symbol_kind::S_223_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_224_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_225_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_226_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_227_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_232_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_233_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_234_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_235_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_236_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_237_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_238_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_239_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_240_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_241_primitive_type_list: // primitive.type.list
      case symbol_kind::S_242_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_243_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_244_primitive_ui: // primitive.ui
      case symbol_kind::S_245_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_246_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_247_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_248_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_249_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_250_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_251_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_252_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_253_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_254_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_255_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_256_primitive_foreign_function_signature_names_1_args_0: // primitive.foreign.function.signature.names.1.args.0
      case symbol_kind::S_257_primitive_foreign_function_signature_names_1_args_list: // primitive.foreign.function.signature.names.1.args.list
      case symbol_kind::S_258_primitive_foreign_function_signature_names_2_args_0: // primitive.foreign.function.signature.names.2.args.0
      case symbol_kind::S_259_primitive_foreign_function_signature_names_2_args_list: // primitive.foreign.function.signature.names.2.args.list
      case symbol_kind::S_260_primitive_foreign_function_signature_names_3_args_0: // primitive.foreign.function.signature.names.3.args.0
      case symbol_kind::S_261_primitive_foreign_function_signature_names_3_args_list: // primitive.foreign.function.signature.names.3.args.list
      case symbol_kind::S_262_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_263_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_264_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_265_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_266_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_268_statement_definition: // statement.definition
      case symbol_kind::S_269_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_270_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_271_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_272_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_273_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_274_statement_definition_function: // statement.definition.function
      case symbol_kind::S_276_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_277_statement_definition_with: // statement.definition.with
      case symbol_kind::S_278_statement_definition_list: // statement.definition.list
      case symbol_kind::S_279_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_280_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_281_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_282_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_283_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_284_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_285_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_286_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_287_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_288_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_289_statement_import: // statement.import
      case symbol_kind::S_290_statement_list: // statement.list
      case symbol_kind::S_291_statement_list_start: // statement.list.start
      case symbol_kind::S_292_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_293_statement_list_append: // statement.list.append
      case symbol_kind::S_294_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_299_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_300_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_301_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_302_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        value.move< Tree > (that.value);
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition_dependencies: // doc.attribute.definition.dependencies
      case symbol_kind::S_149_doc_attribute_definition_doc_tags: // doc.attribute.definition.doc.tags
      case symbol_kind::S_150_doc_attribute_definition_distributed: // doc.attribute.definition.distributed
      case symbol_kind::S_151_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_152_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_213_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_215_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_217_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_275_statement_definition_assignment_operator: // statement.definition.assignment.operator
      case symbol_kind::S_303_statement_terminal: // statement.terminal
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_228_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_230_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
  self.location().streamName() = self.streamName();
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
      case symbol_kind::S_198_expression_math_scalar_float: // expression.math.scalar.float
      case symbol_kind::S_210_primitive_type_number_float: // primitive.type.number.float
        yylhs.value.emplace< FloatType > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_196_expression_math_scalar_int: // expression.math.scalar.int
      case symbol_kind::S_209_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_295_statement_math_precision: // statement.math.precision
      case symbol_kind::S_296_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_297_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_298_statement_math_precision_list_append: // statement.math.precision.list.append
        yylhs.value.emplace< IntType > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_145_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_154_expression_component: // expression.component
      case symbol_kind::S_155_expression_composition: // expression.composition
      case symbol_kind::S_156_expression_composition_parallel: // expression.composition.parallel
      case symbol_kind::S_157_expression_composition_serial: // expression.composition.serial
      case symbol_kind::S_158_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_159_expression_composition_recursive: // expression.composition.recursive
      case symbol_kind::S_160_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_161_expression_composition_split: // expression.composition.split
      case symbol_kind::S_162_expression_environment: // expression.environment
      case symbol_kind::S_163_expression_infix: // expression.infix
      case symbol_kind::S_164_expression_infix_definitions_substitution: // expression.infix.definitions.substitution
      case symbol_kind::S_165_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_166_expression_infix_math: // expression.infix.math
      case symbol_kind::S_167_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_168_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_169_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_170_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_171_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_172_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_173_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_174_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_175_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_176_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_177_expression_lambda: // expression.lambda
      case symbol_kind::S_178_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_179_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_180_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_181_expression_letrec: // expression.letrec
      case symbol_kind::S_182_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_183_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_184_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_185_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_186_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_187_expression_library: // expression.library
      case symbol_kind::S_188_expression_math: // expression.math
      case symbol_kind::S_189_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_190_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_191_expression_math_signal: // expression.math.signal
      case symbol_kind::S_192_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_193_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_194_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_195_expression_math_scalar_as_tree: // expression.math.scalar.as.tree
      case symbol_kind::S_197_expression_math_scalar_int_as_tree: // expression.math.scalar.int.as.tree
      case symbol_kind::S_199_expression_math_scalar_float_as_tree: // expression.math.scalar.float.as.tree
      case symbol_kind::S_200_expression_math_trigonometry_as_tree: // expression.math.trigonometry.as.tree
      case symbol_kind::S_201_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_202_expression_signal: // expression.signal
      case symbol_kind::S_203_expression_signal_control: // expression.signal.control
      case symbol_kind::S_204_expression_signal_delay: // expression.signal.delay
      case symbol_kind::S_205_expression_signal_logic: // expression.signal.logic
      case symbol_kind::S_primitive: // primitive
      case symbol_kind::S_207_primitive_foreign: // primitive.foreign
      case symbol_kind::S_208_primitive_type_number_as_tree: // primitive.type.number.as.tree
      case symbol_kind::S_211_primitive_type_number_int_as_tree: // primitive.type.number.int.as.tree
      case symbol_kind::S_212_primitive_type_number_float_as_tree: // primitive.type.number.float.as.tree
      case symbol_kind::S_214_primitive_string_quoted_as_tree: // primitive.string.quoted.as.tree
      case symbol_kind::S_216_primitive_string_unquoted_as_tree: // primitive.string.unquoted.as.tree
      case symbol_kind::S_218_primitive_string_tag_as_tree: // primitive.string.tag.as.tree
      case symbol_kind::S_219_primitive_signal: // primitive.signal
      case symbol_kind::S_220_primitive_signal_input_wire: // primitive.signal.input.wire
      case symbol_kind::S_221_primitive_signal_input_terminate: // primitive.signal.input.terminate
      case symbol_kind::S_222_primitive_type: // primitive.type
      case symbol_kind::S_223_primitive_type_cast_number: // primitive.type.cast.number
      case symbol_kind::S_224_primitive_type_cast_number_int: // primitive.type.cast.number.int
      case symbol_kind::S_225_primitive_type_cast_number_float: // primitive.type.cast.number.float
      case symbol_kind::S_226_primitive_type_cast_any: // primitive.type.cast.any
      case symbol_kind::S_227_primitive_type_number_int_list_member_as_tree: // primitive.type.number.int.list.member.as.tree
      case symbol_kind::S_229_primitive_type_number_list_member_as_tree: // primitive.type.number.list.member.as.tree
      case symbol_kind::S_232_primitive_type_number_float_list_member_as_tree: // primitive.type.number.float.list.member.as.tree
      case symbol_kind::S_233_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_234_primitive_signal_route_implied_outputs: // primitive.signal.route.implied.outputs
      case symbol_kind::S_235_primitive_signal_route_implied_connections: // primitive.signal.route.implied.connections
      case symbol_kind::S_236_primitive_signal_route_explicit: // primitive.signal.route.explicit
      case symbol_kind::S_237_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_238_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_239_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_240_primitive_signal_source_waveform_as_tree: // primitive.signal.source.waveform.as.tree
      case symbol_kind::S_241_primitive_type_list: // primitive.type.list
      case symbol_kind::S_242_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_243_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_244_primitive_ui: // primitive.ui
      case symbol_kind::S_245_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_246_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_247_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_248_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_249_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_250_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_251_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_252_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_253_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_254_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_255_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_256_primitive_foreign_function_signature_names_1_args_0: // primitive.foreign.function.signature.names.1.args.0
      case symbol_kind::S_257_primitive_foreign_function_signature_names_1_args_list: // primitive.foreign.function.signature.names.1.args.list
      case symbol_kind::S_258_primitive_foreign_function_signature_names_2_args_0: // primitive.foreign.function.signature.names.2.args.0
      case symbol_kind::S_259_primitive_foreign_function_signature_names_2_args_list: // primitive.foreign.function.signature.names.2.args.list
      case symbol_kind::S_260_primitive_foreign_function_signature_names_3_args_0: // primitive.foreign.function.signature.names.3.args.0
      case symbol_kind::S_261_primitive_foreign_function_signature_names_3_args_list: // primitive.foreign.function.signature.names.3.args.list
      case symbol_kind::S_262_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_263_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_264_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_265_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_266_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_268_statement_definition: // statement.definition
      case symbol_kind::S_269_statement_definition_function_arg: // statement.definition.function.arg
      case symbol_kind::S_270_statement_definition_function_args: // statement.definition.function.args
      case symbol_kind::S_271_statement_definition_function_args_start: // statement.definition.function.args.start
      case symbol_kind::S_272_statement_definition_function_args_append: // statement.definition.function.args.append
      case symbol_kind::S_273_statement_definition_function_declaration: // statement.definition.function.declaration
      case symbol_kind::S_274_statement_definition_function: // statement.definition.function
      case symbol_kind::S_276_statement_definition_assignment: // statement.definition.assignment
      case symbol_kind::S_277_statement_definition_with: // statement.definition.with
      case symbol_kind::S_278_statement_definition_list: // statement.definition.list
      case symbol_kind::S_279_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_280_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_281_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_282_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_283_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_284_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_285_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_286_statement_identifier_as_tree: // statement.identifier.as.tree
      case symbol_kind::S_287_statement_box_identifier_as_tree: // statement.box.identifier.as.tree
      case symbol_kind::S_288_statement_foreign_function_identifier_as_tree: // statement.foreign.function.identifier.as.tree
      case symbol_kind::S_289_statement_import: // statement.import
      case symbol_kind::S_290_statement_list: // statement.list
      case symbol_kind::S_291_statement_list_start: // statement.list.start
      case symbol_kind::S_292_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_293_statement_list_append: // statement.list.append
      case symbol_kind::S_294_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_299_statement_signal_pattern_rule: // statement.signal.pattern.rule
      case symbol_kind::S_300_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_301_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_302_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
        yylhs.value.emplace< Tree > ();
        break;

      case symbol_kind::S_146_doc_list: // doc.list
      case symbol_kind::S_147_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_148_doc_attribute_definition_dependencies: // doc.attribute.definition.dependencies
      case symbol_kind::S_149_doc_attribute_definition_doc_tags: // doc.attribute.definition.doc.tags
      case symbol_kind::S_150_doc_attribute_definition_distributed: // doc.attribute.definition.distributed
      case symbol_kind::S_151_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_152_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_213_primitive_string_quoted: // primitive.string.quoted
      case symbol_kind::S_215_primitive_string_unquoted: // primitive.string.unquoted
      case symbol_kind::S_217_primitive_string_tag: // primitive.string.tag
      case symbol_kind::S_275_statement_definition_assignment_operator: // statement.definition.assignment.operator
      case symbol_kind::S_303_statement_terminal: // statement.terminal
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_228_primitive_type_number_list_as_tree: // primitive.type.number.list.as.tree
      case symbol_kind::S_230_primitive_type_number_list_start_as_tree: // primitive.type.number.list.start.as.tree
      case symbol_kind::S_231_primitive_type_number_list_append_as_tree: // primitive.type.number.list.append.as.tree
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
			self.ast() = self.formatDefinitions(yylhs.value.as < Tree > ());
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
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > ().append(self.lexer()->YYText());
      }
    break;

  case 13: // doc.equation: BEQN expression EEQN
                           {
        yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 14: // doc.equation: BEQN error EEQN
                      {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 15: // doc.diagram: BDGM expression EDGM
                           {
        yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 16: // doc.diagram: BDGM error EDGM
                      {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 17: // doc.notice: NOTICE
             {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
      }
    break;

  case 18: // doc.metadata: BMETADATA statement.identifier.as.tree EMETADATA
                                                       {
        yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 19: // doc.metadata: BMETADATA error EMETADATA
                                {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 20: // doc.list: BLST doc.attribute.list ELST
                                   {
        yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
      }
    break;

  case 21: // doc.list: BLST ELST
                                 {
        yylhs.value.as < bool > () = ::Faust::Primitive::Symbols::asTree().nil;
      }
    break;

  case 22: // doc.list: BLST error ELST
                      {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 23: // doc.attribute.list: doc.attribute.definition
                                 {
          yylhs.value.as < bool > () = yystack_[0].value.as < bool > ();
        }
    break;

  case 24: // doc.attribute.list: doc.attribute.list doc.attribute.definition
                                                    {
          yylhs.value.as < bool > () = yystack_[0].value.as < bool > ();
        }
    break;

  case 25: // doc.attribute.definition.dependencies: LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ
                                                            {
          yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
          self.lstDependenciesSwitch() = yystack_[1].value.as < bool > ();
        }
    break;

  case 26: // doc.attribute.definition.dependencies: LSTDEPENDENCIES LSTEQ LSTQ error LSTQ
                                              {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 27: // doc.attribute.definition.doc.tags: LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ
                                                        {
          yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
          self.stripDocSwitch() = yystack_[1].value.as < bool > ();
          self.stripDocSwitch() ? self.stripDocSwitch()=false
                                   : self.stripDocSwitch()=true;
        }
    break;

  case 28: // doc.attribute.definition.doc.tags: LSTMDOCTAGS LSTEQ LSTQ error LSTQ
                                          {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 29: // doc.attribute.definition.distributed: LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ
                                                           {
          yylhs.value.as < bool > () = yystack_[1].value.as < bool > ();
          self.lstDistributedSwitch() = yystack_[1].value.as < bool > ();
        }
    break;

  case 30: // doc.attribute.definition.distributed: LSTDISTRIBUTED LSTEQ LSTQ error LSTQ
                                             {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 31: // doc.attribute.definition: doc.attribute.definition.dependencies
        { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
    break;

  case 32: // doc.attribute.definition: doc.attribute.definition.doc.tags
        { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
    break;

  case 33: // doc.attribute.definition: doc.attribute.definition.distributed
        { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
    break;

  case 34: // doc.attribute.value: LSTTRUE
                {
          yylhs.value.as < bool > () = true;
        }
    break;

  case 35: // doc.attribute.value: LSTFALSE
                 {
          yylhs.value.as < bool > () = false;
        }
    break;

  case 36: // expression: statement.definition.with
                { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 37: // expression: expression.letrec
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 38: // expression: expression.composition
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 39: // expression.component: COMPONENT LPAR primitive.string.unquoted.as.tree RPAR
                                                            {
        yylhs.value.as < Tree > () = ::boxComponent(yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 40: // expression.component: COMPONENT LPAR error RPAR
                                {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 41: // expression.composition: expression.composition.serial
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 42: // expression.composition: expression.composition.parallel
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 43: // expression.composition.parallel: expression COMMA expression
                                            {
        yylhs.value.as < Tree > () = ::boxPar( yystack_[2].value.as < Tree > (), yystack_[0].value.as < Tree > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 44: // expression.composition.serial: expression.composition.sequence
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 45: // expression.composition.serial: expression.composition.split
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 46: // expression.composition.serial: expression.composition.mix
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 47: // expression.composition.serial: expression.composition.recursive
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 48: // expression.composition.serial: expression.infix
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 49: // expression.composition.mix: expression.composition.serial MIX expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = ::boxMerge( yystack_[2].value.as < Tree > (), yystack_[0].value.as < Tree > () );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 50: // expression.composition.recursive: expression.composition.serial REC expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = ::boxRec(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 51: // expression.composition.sequence: expression.composition.serial SEQ expression.composition.serial
                                                                                  {
          yylhs.value.as < Tree > () = ::boxSeq(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 52: // expression.composition.split: expression.composition.serial SPLIT expression.composition.serial
                                                                                    {
          yylhs.value.as < Tree > () = ::boxSplit(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 53: // expression.environment: ENVIRONMENT LBRAQ statement.list RBRAQ
                                             {
        yylhs.value.as < Tree > () = ::boxWithLocalDef(boxEnvironment(),self.formatDefinitions(yystack_[1].value.as < Tree > ()));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 54: // expression.environment: ENVIRONMENT LBRAQ error RBRAQ
                                    {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 55: // expression.infix: expression.infix.definitions.substitution
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 56: // expression.infix: expression.infix.environment.access
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 57: // expression.infix: expression.infix.math
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 58: // expression.infix: expression.infix.signal.delay
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 59: // expression.infix: expression.infix.prefix
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 60: // expression.infix: expression.component
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 61: // expression.infix: expression.environment
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 62: // expression.infix: expression.iterate.parallel
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 63: // expression.infix: expression.iterate.sequence
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 64: // expression.infix: expression.iterate.sum
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 65: // expression.infix: expression.iterate.product
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 66: // expression.infix: expression.lambda
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 67: // expression.infix: expression.library
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 68: // expression.infix: expression.math
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 69: // expression.infix: expression.parenthesis
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 70: // expression.infix: expression.signal
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 71: // expression.infix: statement.box.identifier.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 72: // expression.infix: primitive
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 73: // expression.infix.definitions.substitution: expression.infix LCROC statement.definition.list RCROC
                                                                        {
        yylhs.value.as < Tree > () = boxModifLocalDef(
          yystack_[3].value.as < Tree > (),
          self.formatDefinitions(yystack_[1].value.as < Tree > ())
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 74: // expression.infix.definitions.substitution: expression.infix LCROC error RCROC
                                              {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 75: // expression.infix.environment.access: expression.infix DOT statement.box.identifier.as.tree
                                                                      {
        yylhs.value.as < Tree > () = ::boxAccess(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ());      
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 76: // expression.infix.math: expression.infix.math.algebra
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 77: // expression.infix.math: expression.infix.math.comparison
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 78: // expression.infix.math: expression.infix.math.logic
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 79: // expression.infix.math: expression.infix.math.shift
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 80: // expression.infix.math.algebra: expression.infix ADD expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigAdd));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 81: // expression.infix.math.algebra: expression.infix SUB expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigSub));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 82: // expression.infix.math.algebra: expression.infix MUL expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigMul));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 83: // expression.infix.math.algebra: expression.infix DIV expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigDiv));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 84: // expression.infix.math.algebra: expression.infix MOD expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigRem));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 85: // expression.infix.math.algebra: expression.infix POWOP expression.infix
                                                        {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxMathPrimitive( "pow" ));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 86: // expression.infix.math.comparison: expression.infix LT expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigLT));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 87: // expression.infix.math.comparison: expression.infix LE expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigLE));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 88: // expression.infix.math.comparison: expression.infix GT expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigGT));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 89: // expression.infix.math.comparison: expression.infix GE expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigGE));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 90: // expression.infix.math.comparison: expression.infix EQ expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigEQ));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 91: // expression.infix.math.comparison: expression.infix NE expression.infix
                                                     {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigNE));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 92: // expression.infix.math.logic: expression.infix AND expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigAND));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 93: // expression.infix.math.logic: expression.infix OR expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigOR));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 94: // expression.infix.math.logic: expression.infix XOR expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigXOR));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 95: // expression.infix.math.shift: expression.infix LSH expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigLeftShift));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 96: // expression.infix.math.shift: expression.infix RSH expression.infix
                                                      {
        yylhs.value.as < Tree > () = ::boxSeq(::boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigARightShift));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 97: // expression.infix.prefix: expression.infix LPAR statement.definition.function.args RPAR
                                                                         {
        yylhs.value.as < Tree > () = ::buildBoxAppl(yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 98: // expression.infix.prefix: expression.infix LPAR error RPAR
                                            {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 99: // expression.infix.signal.delay: expression.infix FDELAY expression.infix
                                                         {
        yylhs.value.as < Tree > () = ::boxSeq(boxPar(yystack_[2].value.as < Tree > (),yystack_[0].value.as < Tree > ()),::boxPrim2(sigDelay));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 100: // expression.infix.signal.delay: expression.infix DELAY1
                                   {
        yylhs.value.as < Tree > () = ::boxSeq(yystack_[1].value.as < Tree > (),::boxPrim1(sigDelay1));
        yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 101: // expression.iterate.parallel: ITERATE_PARALLEL LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                                       {
        yylhs.value.as < Tree > () = ::boxIPar(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 102: // expression.iterate.parallel: ITERATE_PARALLEL LPAR error RPAR
                                       {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 103: // expression.iterate.sequence: ISEQ LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                           {
        yylhs.value.as < Tree > () = ::boxISeq(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 104: // expression.iterate.sequence: ISEQ LPAR error RPAR
                           {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 105: // expression.iterate.sum: ISUM LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                           {
        yylhs.value.as < Tree > () = ::boxISum(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 106: // expression.iterate.sum: ISUM LPAR error RPAR
                           {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 107: // expression.iterate.product: IPROD LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR
                                                                                                            {
        yylhs.value.as < Tree > () = boxIProd(
          yystack_[5].value.as < Tree > (),
          yystack_[3].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 108: // expression.iterate.product: IPROD LPAR error RPAR
                            {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 109: // expression.lambda: LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR
                                                                         {
        yylhs.value.as < Tree > () = ::buildBoxAbstr(
          yystack_[5].value.as < Tree > (),
          yystack_[1].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 110: // expression.lambda: LAMBDA LPAR error RPAR DOT LPAR expression RPAR
                                                      {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 111: // expression.lambda: LAMBDA LPAR expression.lambda.params RPAR DOT LPAR error RPAR
                                                                    {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 112: // expression.lambda.params: expression.lambda.params.start
                { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 113: // expression.lambda.params: expression.lambda.params.append
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 114: // expression.lambda.params.start: statement.box.identifier.as.tree
                                         {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 115: // expression.lambda.params.append: expression.lambda.params COMMA statement.box.identifier.as.tree
                                                                        {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            yystack_[2].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 116: // expression.letrec: expression LETREC LBRAQ RBRAQ
                                                                          {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[3].value.as < Tree > (),
        self.formatDefinitions(::Faust::Primitive::Symbols::asTree().nil),
        ::Faust::Primitive::Symbols::asTree().nil
      );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
		}
    break;

  case 117: // expression.letrec: expression LETREC LBRAQ expression.letrec.list RBRAQ
                                                              {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[4].value.as < Tree > (),
        self.formatDefinitions(yystack_[1].value.as < Tree > ()),
        ::Faust::Primitive::Symbols::asTree().nil
      );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
		}
    break;

  case 118: // expression.letrec: expression LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ
                                                                                              {
			yylhs.value.as < Tree > () = boxWithRecDef(
        yystack_[6].value.as < Tree > (),
        self.formatDefinitions(yystack_[3].value.as < Tree > ()),
        self.formatDefinitions(yystack_[3].value.as < Tree > ())
      );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
		}
    break;

  case 119: // expression.letrec: expression LETREC LBRAQ error RBRAQ
                                             {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 120: // expression.letrec: expression LETREC LBRAQ error WHERE statement.definition.list RBRAQ
                                                                             {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 121: // expression.letrec: expression LETREC LBRAQ expression.letrec.list WHERE error RBRAQ
                                                                          {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 122: // expression.letrec.list: expression.letrec.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 123: // expression.letrec.list: expression.letrec.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 124: // expression.letrec.list.start: expression.letrec.equation
                                         {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 125: // expression.letrec.list.append: expression.letrec.list expression.letrec.equation
                                                          {
          yylhs.value.as < Tree > () = cons (
            yystack_[0].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 126: // expression.letrec.equation: expression.letrec.equation.name DEF expression statement.terminal
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

  case 127: // expression.letrec.equation: error DEF statement.terminal
                                   {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 128: // expression.letrec.equation: expression.letrec.equation.name DEF error
                                                {
        yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > ();
        yyclearin;
        yyerrok;
      }
    break;

  case 129: // expression.letrec.equation.name: DELAY1 statement.box.identifier.as.tree
                                                {
          yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 130: // expression.library: LIBRARY LPAR primitive.string.unquoted.as.tree RPAR
                                                          {
        yylhs.value.as < Tree > () = ::boxLibrary( yystack_[1].value.as < Tree > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 131: // expression.library: LIBRARY LPAR error RPAR
                              {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 132: // expression.math: expression.math.signal
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 133: // expression.math: expression.math.scalar.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 134: // expression.math: expression.math.comparison
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 135: // expression.math: expression.math.trigonometry.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 136: // expression.math: expression.math.rounding
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 137: // expression.math.comparison: LT
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigLT);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 138: // expression.math.comparison: LE
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigLE);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 139: // expression.math.comparison: GT
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigGT);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 140: // expression.math.comparison: GE
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigGE);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 141: // expression.math.comparison: EQ
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigEQ);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 142: // expression.math.comparison: NE
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigNE);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 143: // expression.math.rounding: ABS
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "abs" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 144: // expression.math.rounding: MIN
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "min" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 145: // expression.math.rounding: MAX
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "max" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 146: // expression.math.rounding: FLOOR
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "floor" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 147: // expression.math.rounding: CEIL
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "ceil" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 148: // expression.math.rounding: ASSERTBOUNDS
                       {
            yylhs.value.as < Tree > () = ::boxPrim3(sigAssertBounds);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 149: // expression.math.rounding: LOWEST
                 {
            yylhs.value.as < Tree > () = ::boxPrim1(sigLowest);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 150: // expression.math.rounding: HIGHEST
                  {
            yylhs.value.as < Tree > () = ::boxPrim1(sigHighest);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 151: // expression.math.rounding: RINT
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "rint" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 152: // expression.math.signal: expression.math.signal.algebra
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 153: // expression.math.signal: expression.math.signal.shift
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 154: // expression.math.signal: expression.math.signal.power
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 155: // expression.math.signal.algebra: ADD
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigAdd);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 156: // expression.math.signal.algebra: SUB
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigSub);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 157: // expression.math.signal.algebra: MUL
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigMul);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 158: // expression.math.signal.algebra: DIV
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigDiv);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 159: // expression.math.signal.algebra: MOD
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigRem);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 160: // expression.math.signal.algebra: FMOD
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "fmod" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 161: // expression.math.signal.algebra: REMAINDER
                    {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "remainder" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 162: // expression.math.signal.algebra: SUB statement.box.identifier.as.tree
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

  case 163: // expression.math.signal.shift: LSH
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigLeftShift);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 164: // expression.math.signal.shift: RSH
              {
            yylhs.value.as < Tree > () = ::boxPrim2(sigARightShift);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 165: // expression.math.signal.power: EXP
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "exp" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 166: // expression.math.signal.power: LOG
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "log" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 167: // expression.math.signal.power: LOG10
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "log10" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 168: // expression.math.signal.power: POWOP
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "pow" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 169: // expression.math.signal.power: POWFUN
                 {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "pow" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 170: // expression.math.signal.power: SQRT
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "sqrt" );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 171: // expression.math.scalar.as.tree: expression.math.scalar.int.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 172: // expression.math.scalar.as.tree: expression.math.scalar.float.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 173: // expression.math.scalar.int: ADD INT
                  {
            yylhs.value.as < IntType > () = std::stoi(self.lexer()->YYText());
          }
    break;

  case 174: // expression.math.scalar.int: SUB INT
                  {
            yylhs.value.as < IntType > () = -yystack_[0].value.as < IntType > ();
          }
    break;

  case 175: // expression.math.scalar.int.as.tree: expression.math.scalar.int
                                     {
            yylhs.value.as < Tree > () = ::boxInt( yystack_[0].value.as < IntType > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 176: // expression.math.scalar.float: ADD FLOAT
                    {
            yylhs.value.as < FloatType > () = yystack_[0].value.as < FloatType > ();
          }
    break;

  case 177: // expression.math.scalar.float: SUB FLOAT
                    {
            yylhs.value.as < FloatType > () = -yystack_[0].value.as < FloatType > ();
          }
    break;

  case 178: // expression.math.scalar.float.as.tree: expression.math.scalar.float
                                       {
            yylhs.value.as < Tree > () = ::boxReal( yystack_[0].value.as < FloatType > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 179: // expression.math.trigonometry.as.tree: ACOS
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "acos" );
          
          }
    break;

  case 180: // expression.math.trigonometry.as.tree: ASIN
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "asin" );
        
          }
    break;

  case 181: // expression.math.trigonometry.as.tree: ATAN
               {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "atan" );
        
          }
    break;

  case 182: // expression.math.trigonometry.as.tree: ATAN2
                {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "atan2" );
        
          }
    break;

  case 183: // expression.math.trigonometry.as.tree: COS
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "cos" );
        
          }
    break;

  case 184: // expression.math.trigonometry.as.tree: SIN
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "sin" );
        
          }
    break;

  case 185: // expression.math.trigonometry.as.tree: TAN
              {
            yylhs.value.as < Tree > () = ::boxMathPrimitive( "tan" );
        
          }
    break;

  case 186: // expression.parenthesis: LPAR expression RPAR
                         {
      yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 187: // expression.parenthesis: LPAR error RPAR
                    {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
    break;

  case 188: // expression.signal: expression.signal.control
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 189: // expression.signal: expression.signal.delay
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 190: // expression.signal: expression.signal.logic
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 191: // expression.signal.control: ATTACH
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigAttach);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 192: // expression.signal.control: ENABLE
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigEnable);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 193: // expression.signal.control: CONTROL
                {
          yylhs.value.as < Tree > () = ::boxPrim2(sigControl);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 194: // expression.signal.delay: MEM
            {
          yylhs.value.as < Tree > () = ::boxPrim1(sigDelay1);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 195: // expression.signal.delay: PREFIX
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigPrefix);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 196: // expression.signal.delay: FDELAY
               {
          yylhs.value.as < Tree > () = ::boxPrim2(sigDelay);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 197: // expression.signal.logic: AND
            {
          yylhs.value.as < Tree > () = ::boxPrim2(sigAND);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 198: // expression.signal.logic: OR
           {
          yylhs.value.as < Tree > () = ::boxPrim2(sigOR);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 199: // expression.signal.logic: XOR
            {
          yylhs.value.as < Tree > () = ::boxPrim2(sigXOR);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 200: // expression.signal.logic: SELECT2
                {
          yylhs.value.as < Tree > () = ::boxPrim3(sigSelect2);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 201: // expression.signal.logic: SELECT3
                {
          yylhs.value.as < Tree > () = ::boxPrim4(sigSelect3);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 202: // expression.signal.logic: CASE LBRAQ statement.signal.pattern.rule.list RBRAQ
                                                            {
          yylhs.value.as < Tree > () = ::boxCase(self.checkRulelist(yystack_[1].value.as < Tree > ()));
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 203: // expression.signal.logic: CASE LBRAQ error RBRAQ
                               {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 204: // primitive: primitive.foreign
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 205: // primitive: primitive.type.number.as.tree
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 206: // primitive: primitive.type.cast.number
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 207: // primitive: primitive.signal
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 208: // primitive: primitive.ui
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 209: // primitive.foreign: primitive.foreign.constant
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 210: // primitive.foreign: primitive.foreign.function
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 211: // primitive.foreign: primitive.foreign.variable
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 212: // primitive.type.number.as.tree: primitive.type.number.int.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 213: // primitive.type.number.as.tree: primitive.type.number.float.as.tree
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 214: // primitive.type.number.int: INT
          {
        yylhs.value.as < IntType > () = std::stoi(self.lexer()->YYText());
      }
    break;

  case 215: // primitive.type.number.float: FLOAT
            {
        yylhs.value.as < FloatType > () = std::atof(self.lexer()->YYText());
      }
    break;

  case 216: // primitive.type.number.int.as.tree: primitive.type.number.int
                                {
        yylhs.value.as < Tree > () = boxInt( yystack_[0].value.as < IntType > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 217: // primitive.type.number.float.as.tree: primitive.type.number.float
                                  {
        yylhs.value.as < Tree > () = boxReal( yystack_[0].value.as < FloatType > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 218: // primitive.string.quoted: STRING
             {
        yylhs.value.as < std::string > () = self.lexer()->YYText();
      }
    break;

  case 219: // primitive.string.quoted.as.tree: primitive.string.quoted
                              {
        yylhs.value.as < Tree > () = ::tree( yystack_[0].value.as < std::string > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 220: // primitive.string.unquoted: STRING
             {
        yylhs.value.as < std::string > () = self.unquote(self.lexer()->YYText());
      }
    break;

  case 221: // primitive.string.unquoted.as.tree: primitive.string.unquoted
                                {
        yylhs.value.as < Tree > () = ::tree( yystack_[0].value.as < std::string > () );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 222: // primitive.string.tag: STRING
             {
        yylhs.value.as < std::string > () = self.lexer()->YYText();
      }
    break;

  case 223: // primitive.string.tag: TAGSTRING
                {
        yylhs.value.as < std::string > () = self.lexer()->YYText();
      }
    break;

  case 224: // primitive.string.tag.as.tree: primitive.string.tag
                         {
      yylhs.value.as < Tree > () = ::tree( yystack_[0].value.as < std::string > () );
      yylhs.value.as < Tree > ()->location() = yylhs.location;
    }
    break;

  case 225: // primitive.signal: primitive.signal.inputs
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 226: // primitive.signal: primitive.signal.input.wire
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 227: // primitive.signal: primitive.signal.input.terminate
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 228: // primitive.signal: primitive.signal.outputs
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 229: // primitive.signal: primitive.signal.route
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 230: // primitive.signal: primitive.signal.source
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 231: // primitive.signal.input.wire: WIRE
           {
        yylhs.value.as < Tree > () = ::boxWire();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 232: // primitive.signal.input.terminate: CUT
          {
        yylhs.value.as < Tree > () = ::boxCut();
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 233: // primitive.type: primitive.type.cast.number
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 234: // primitive.type: primitive.type.cast.any
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 235: // primitive.type.cast.number: primitive.type.cast.number.int
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 236: // primitive.type.cast.number: primitive.type.cast.number.float
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 237: // primitive.type.cast.number.int: INTCAST
                  {
            yylhs.value.as < Tree > () = ::boxPrim1(sigIntCast);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 238: // primitive.type.cast.number.float: FLOATCAST
                    {
            yylhs.value.as < Tree > () = ::boxPrim1(sigFloatCast);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 239: // primitive.type.cast.any: ANYCAST
                {
          yylhs.value.as < Tree > () = ::tree(2);
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 240: // primitive.type.number.int.list.member.as.tree: primitive.type.number.int.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 241: // primitive.type.number.int.list.member.as.tree: expression.math.scalar.int.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 242: // primitive.type.number.list.as.tree: primitive.type.number.list.start.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 243: // primitive.type.number.list.as.tree: primitive.type.number.list.append.as.tree
        { yylhs.value.as < std::vector<Tree> > () = yystack_[0].value.as < std::vector<Tree> > (); }
    break;

  case 244: // primitive.type.number.list.member.as.tree: primitive.type.number.int.list.member.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 245: // primitive.type.number.list.member.as.tree: primitive.type.number.float.list.member.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 246: // primitive.type.number.list.start.as.tree: primitive.type.number.list.member.as.tree
                                                  {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 247: // primitive.type.number.list.append.as.tree: primitive.type.number.list.as.tree COMMA primitive.type.number.list.member.as.tree
                                                                                           {
          yylhs.value.as < std::vector<Tree> > ().push_back( yystack_[0].value.as < Tree > () );
        }
    break;

  case 248: // primitive.type.number.float.list.member.as.tree: primitive.type.number.float.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 249: // primitive.type.number.float.list.member.as.tree: expression.math.scalar.float.as.tree
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 250: // primitive.signal.route: primitive.signal.route.implied.outputs
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 251: // primitive.signal.route: primitive.signal.route.implied.connections
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 252: // primitive.signal.route: primitive.signal.route.explicit
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 253: // primitive.signal.route.implied.outputs: ROUTE LPAR statement.definition.function.arg RPAR
                                                                         {
            yylhs.value.as < Tree > () = ::boxRoute(
              yystack_[1].value.as < Tree > (),
              yystack_[1].value.as < Tree > (),
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 254: // primitive.signal.route.implied.connections: ROUTE LPAR statement.definition.function.arg COMMA statement.definition.function.arg RPAR
                                                                                                                     {
            yylhs.value.as < Tree > () = ::boxRoute(
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > (),
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 255: // primitive.signal.route.explicit: ROUTE LPAR statement.definition.function.arg COMMA statement.definition.function.arg COMMA expression RPAR
                                                                                                                                      {
            yylhs.value.as < Tree > () = boxRoute(
              yystack_[5].value.as < Tree > (),
              yystack_[3].value.as < Tree > (),
              yystack_[1].value.as < Tree > ()
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 256: // primitive.signal.source: primitive.signal.source.waveform.as.tree
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 257: // primitive.signal.source: primitive.signal.source.soundfile
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 258: // primitive.signal.source: primitive.signal.source.table
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 259: // primitive.signal.source.table: RDTBL
                {
            yylhs.value.as < Tree > () = ::boxPrim3(sigReadOnlyTable);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 260: // primitive.signal.source.table: RWTBL
                {
            yylhs.value.as < Tree > () = ::boxPrim5(sigWriteReadTable);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 261: // primitive.signal.source.soundfile: SOUNDFILE LPAR primitive.string.unquoted.as.tree COMMA expression.composition RPAR
                                                                                             {
            yylhs.value.as < Tree > () = ::boxSoundfile( yystack_[3].value.as < Tree > (), yystack_[1].value.as < Tree > () );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 262: // primitive.signal.source.waveform.as.tree: WAVEFORM LBRAQ primitive.type.number.list.as.tree RBRAQ
                                                                {
          yylhs.value.as < Tree > () = ::boxWaveform( yystack_[1].value.as < std::vector<Tree> > () );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 263: // primitive.type.list: primitive.type.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 264: // primitive.type.list: primitive.type.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 265: // primitive.type.list.start: primitive.type
                         {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),::Faust::Primitive::Symbols::asTree().nil);
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 266: // primitive.type.list.append: primitive.type.list COMMA primitive.type
                                                   {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[0].value.as < Tree > (),
              yystack_[2].value.as < Tree > ()
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 267: // primitive.ui: primitive.ui.button
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 268: // primitive.ui: primitive.ui.checkbox
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 269: // primitive.ui: primitive.ui.vslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 270: // primitive.ui: primitive.ui.hslider
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 271: // primitive.ui: primitive.ui.nentry
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 272: // primitive.ui: primitive.ui.vgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 273: // primitive.ui: primitive.ui.hgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 274: // primitive.ui: primitive.ui.tgroup
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 275: // primitive.ui: primitive.ui.vbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 276: // primitive.ui: primitive.ui.hbargraph
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 277: // primitive.ui.button: BUTTON LPAR primitive.string.unquoted.as.tree RPAR
                                                           {
          yylhs.value.as < Tree > () = ::boxButton(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 278: // primitive.ui.button: BUTTON LPAR error RPAR
                               {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 279: // primitive.ui.checkbox: CHECKBOX LPAR primitive.string.unquoted.as.tree RPAR
                                                             {
          yylhs.value.as < Tree > () = ::boxCheckbox(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 280: // primitive.ui.checkbox: CHECKBOX LPAR error RPAR
                                 {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 281: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yylhs.value.as < Tree > () = ::boxVSlider(
            yystack_[9].value.as < Tree > (),
            yystack_[7].value.as < Tree > (),
            yystack_[5].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 282: // primitive.ui.vslider: VSLIDER LPAR error COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 283: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA error COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 284: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA error COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 285: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA error COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 286: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA error RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 287: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yylhs.value.as < Tree > () = ::boxHSlider(
            yystack_[9].value.as < Tree > (),
            yystack_[7].value.as < Tree > (),
            yystack_[5].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 288: // primitive.ui.hslider: HSLIDER LPAR error COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 289: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA error COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 290: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA error COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 291: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA error COMMA expression.composition.serial RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 292: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA error RPAR
                     {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 293: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                    {
          yylhs.value.as < Tree > () = ::boxNumEntry(yystack_[9].value.as < Tree > (),yystack_[7].value.as < Tree > (),yystack_[5].value.as < Tree > (),yystack_[3].value.as < Tree > (),yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 294: // primitive.ui.nentry: NENTRY LPAR error COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 295: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA error COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 296: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA error COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 297: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA error COMMA expression.composition.serial RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 298: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial COMMA expression.composition.serial COMMA error RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 299: // primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 300: // primitive.ui.vgroup: VGROUP LPAR error COMMA expression RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 301: // primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted.as.tree COMMA error RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 302: // primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 303: // primitive.ui.hgroup: HGROUP LPAR error COMMA expression RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 304: // primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted.as.tree COMMA error RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 305: // primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted.as.tree COMMA expression RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 306: // primitive.ui.tgroup: TGROUP LPAR error COMMA expression RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 307: // primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted.as.tree COMMA error RPAR
                    {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 308: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                       {
          yylhs.value.as < Tree > () = ::boxVBargraph(
            yystack_[5].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 309: // primitive.ui.vbargraph: VBARGRAPH LPAR error COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 310: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA error COMMA expression.composition.serial RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 311: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA error RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 312: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 313: // primitive.ui.hbargraph: HBARGRAPH LPAR error COMMA expression.composition.serial COMMA expression.composition.serial RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 314: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA error COMMA expression.composition.serial RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 315: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted.as.tree COMMA expression.composition.serial COMMA error RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 316: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag.as.tree COMMA primitive.string.unquoted.as.tree RPAR
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

  case 317: // primitive.foreign.function: FFUNCTION LPAR error COMMA primitive.string.tag.as.tree COMMA primitive.string.unquoted.as.tree RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 318: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA error COMMA primitive.string.unquoted.as.tree RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 319: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag.as.tree COMMA error RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 320: // primitive.foreign.function.signature.names.1.args.0: primitive.type.cast.number statement.foreign.function.identifier.as.tree LPAR RPAR
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

  case 321: // primitive.foreign.function.signature.names.1.args.0: error statement.foreign.function.identifier.as.tree LPAR RPAR
                                                                              {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 322: // primitive.foreign.function.signature.names.1.args.0: primitive.type.cast.number error LPAR RPAR
                                                     {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 323: // primitive.foreign.function.signature.names.1.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
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

  case 324: // primitive.foreign.function.signature.names.1.args.list: error statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                                                  {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 325: // primitive.foreign.function.signature.names.1.args.list: primitive.type.cast.number error LPAR primitive.type.list RPAR
                                                                         {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 326: // primitive.foreign.function.signature.names.1.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree LPAR error RPAR
                                                                                                         {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 327: // primitive.foreign.function.signature.names.2.args.0: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
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

  case 328: // primitive.foreign.function.signature.names.2.args.0: error statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
                          {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 329: // primitive.foreign.function.signature.names.2.args.0: primitive.type.cast.number error OR statement.foreign.function.identifier.as.tree LPAR RPAR
                                               {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 330: // primitive.foreign.function.signature.names.2.args.0: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR error LPAR RPAR
                                               {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 331: // primitive.foreign.function.signature.names.2.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
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

  case 332: // primitive.foreign.function.signature.names.2.args.list: error statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                              {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 333: // primitive.foreign.function.signature.names.2.args.list: primitive.type.cast.number error OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                   {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 334: // primitive.foreign.function.signature.names.2.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR error LPAR primitive.type.list RPAR
                                                                   {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 335: // primitive.foreign.function.signature.names.2.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR error RPAR
                                                     {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 336: // primitive.foreign.function.signature.names.3.args.0: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
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

  case 337: // primitive.foreign.function.signature.names.3.args.0: error statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
                          {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 338: // primitive.foreign.function.signature.names.3.args.0: primitive.type.cast.number error OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR RPAR
                                               {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 339: // primitive.foreign.function.signature.names.3.args.0: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR error OR statement.foreign.function.identifier.as.tree LPAR RPAR
                                               {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 340: // primitive.foreign.function.signature.names.3.args.0: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR error LPAR RPAR
                                               {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 341: // primitive.foreign.function.signature.names.3.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
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

  case 342: // primitive.foreign.function.signature.names.3.args.list: error statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                              {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 343: // primitive.foreign.function.signature.names.3.args.list: primitive.type.cast.number error OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                   {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 344: // primitive.foreign.function.signature.names.3.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR error OR statement.foreign.function.identifier.as.tree LPAR primitive.type.list RPAR
                                                                   {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 345: // primitive.foreign.function.signature.names.3.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR error LPAR primitive.type.list RPAR
                                                                   {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 346: // primitive.foreign.function.signature.names.3.args.list: primitive.type.cast.number statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree OR statement.foreign.function.identifier.as.tree LPAR error RPAR
                                                     {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 347: // primitive.foreign.function.signature: primitive.foreign.function.signature.names.1.args.0
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 348: // primitive.foreign.function.signature: primitive.foreign.function.signature.names.1.args.list
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 349: // primitive.foreign.function.signature: primitive.foreign.function.signature.names.2.args.0
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 350: // primitive.foreign.function.signature: primitive.foreign.function.signature.names.2.args.list
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 351: // primitive.foreign.function.signature: primitive.foreign.function.signature.names.3.args.0
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 352: // primitive.foreign.function.signature: primitive.foreign.function.signature.names.3.args.list
          { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 353: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.cast.number statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                       {
          yylhs.value.as < Tree > () = ::boxFConst(
            yystack_[4].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 354: // primitive.foreign.constant: FCONSTANT LPAR error statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                       {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 355: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.cast.number error COMMA primitive.string.tag.as.tree RPAR
                       {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 356: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.cast.number statement.identifier.as.tree COMMA error RPAR
                       {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
    break;

  case 357: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.cast.number statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                       {
          yylhs.value.as < Tree > () = ::boxFVar(
            yystack_[4].value.as < Tree > (),
            yystack_[3].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 358: // primitive.foreign.variable: FVARIABLE LPAR error statement.identifier.as.tree COMMA primitive.string.tag.as.tree RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 359: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.cast.number error COMMA primitive.string.tag.as.tree RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 360: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.cast.number statement.identifier.as.tree COMMA error RPAR
                       {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 361: // primitive.signal.inputs: INPUTS LPAR expression RPAR
                                    {
          yylhs.value.as < Tree > () = ::boxInputs(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 362: // primitive.signal.inputs: INPUTS LPAR error RPAR
                               {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 363: // primitive.signal.outputs: OUTPUTS LPAR expression RPAR
                                     {
          yylhs.value.as < Tree > () = ::boxOutputs(yystack_[1].value.as < Tree > ());
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 364: // primitive.signal.outputs: OUTPUTS LPAR error RPAR
                                {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 365: // statement: statement.definition
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 366: // statement: statement.declare.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 367: // statement: statement.declare.feature.metadata
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 368: // statement: statement.declare.doc
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 369: // statement: statement.import
    { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 370: // statement.definition: statement.definition.function
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 371: // statement.definition: statement.definition.assignment
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 372: // statement.definition.function.arg: expression.composition.serial
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 373: // statement.definition.function.args: statement.definition.function.args.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 374: // statement.definition.function.args: statement.definition.function.args.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 375: // statement.definition.function.args.start: statement.definition.function.arg
                                        {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[0].value.as < Tree > (),
          ::Faust::Primitive::Symbols::asTree().nil
        );
       yylhs.value.as < Tree > ()->location() = yylhs.location;
     }
    break;

  case 376: // statement.definition.function.args.append: statement.definition.function.args COMMA statement.definition.function.arg
                                                                                 {
        yylhs.value.as < Tree > () = ::cons(
          yystack_[0].value.as < Tree > (),
          yystack_[2].value.as < Tree > ()
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 377: // statement.definition.function.declaration: statement.box.identifier.as.tree LPAR statement.definition.function.args RPAR DEF expression
                                                                                                   {
        yylhs.value.as < Tree > () = cons(
          yystack_[5].value.as < Tree > (),
          ::cons( yystack_[3].value.as < Tree > (), yystack_[0].value.as < Tree > () )
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 378: // statement.definition.function.declaration: error LPAR statement.definition.function.args RPAR DEF expression
                                                                        {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 379: // statement.definition.function.declaration: statement.box.identifier.as.tree LPAR error RPAR DEF expression
                                                                      {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 380: // statement.definition.function: statement.definition.function.declaration statement.terminal
                                                                     {
          yylhs.value.as < Tree > () = yystack_[1].value.as < Tree > ();
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 381: // statement.definition.function: error statement.terminal
                                 {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 382: // statement.definition.assignment.operator: DEF
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
    break;

  case 383: // statement.definition.assignment: statement.box.identifier.as.tree statement.definition.assignment.operator expression statement.terminal
                                        {
          yylhs.value.as < Tree > () = cons(
            yystack_[3].value.as < Tree > (),
            ::cons( ::Faust::Primitive::Symbols::asTree().nil, yystack_[1].value.as < Tree > () )
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 384: // statement.definition.assignment: error statement.definition.assignment.operator expression statement.terminal
                                        {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 385: // statement.definition.assignment: statement.box.identifier.as.tree error expression statement.terminal
                                        {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 386: // statement.definition.assignment: statement.box.identifier.as.tree statement.definition.assignment.operator error statement.terminal
                                   {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 387: // statement.definition.assignment: statement.box.identifier.as.tree statement.definition.assignment.operator expression error
                           {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    break;

  case 388: // statement.definition.with: expression WITH LBRAQ statement.definition.list RBRAQ
                                                            {
        yylhs.value.as < Tree > () = ::boxWithLocalDef(
          yystack_[4].value.as < Tree > (),
          self.formatDefinitions(yystack_[1].value.as < Tree > ())
        );
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 389: // statement.definition.with: error WITH LBRAQ statement.definition.list RBRAQ
                                                       {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 390: // statement.definition.with: expression WITH LBRAQ error RBRAQ
                                        {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 391: // statement.definition.list: statement.definition.list.start
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 392: // statement.definition.list: statement.definition.list.start.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 393: // statement.definition.list: statement.definition.list.append
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 394: // statement.definition.list: statement.definition.list.append.qualified
        { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 395: // statement.definition.list.start: statement.definition
                               {
            yylhs.value.as < Tree > () = ::cons(
              yystack_[0].value.as < Tree > (),
              ::Faust::Primitive::Symbols::asTree().nil
            );
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 396: // statement.definition.list.start.qualified: statement.math.precision.list statement.definition
                                                             {
            if (self.acceptdefinition(yystack_[1].value.as < IntType > ()))
              yylhs.value.as < Tree > () = ::cons( yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil );
            else
              yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 397: // statement.definition.list.append: statement.definition.list statement.definition
                                                         {
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),yystack_[1].value.as < Tree > ());
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 398: // statement.definition.list.append.qualified: statement.definition.list statement.math.precision.list statement.definition
                                                                                       {
            if (self.acceptdefinition(yystack_[1].value.as < IntType > ()))
              yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (),yystack_[2].value.as < Tree > ());
            else
              yylhs.value.as < Tree > () = yystack_[2].value.as < Tree > ();
            yylhs.value.as < Tree > ()->location() = yylhs.location;
          }
    break;

  case 399: // statement.declare.metadata: DECLARE statement.identifier.as.tree primitive.string.quoted.as.tree statement.terminal
                           {
        self.declareMetadata(yystack_[2].value.as < Tree > (),yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 400: // statement.declare.metadata: DECLARE error primitive.string.quoted.as.tree statement.terminal
                                                                              {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 401: // statement.declare.metadata: DECLARE statement.identifier.as.tree error statement.terminal
                                                                         {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 402: // statement.declare.metadata: DECLARE statement.identifier.as.tree primitive.string.quoted.as.tree error
                                                                                             {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 403: // statement.declare.feature.metadata: DECLARE statement.identifier.as.tree statement.identifier.as.tree primitive.string.quoted.as.tree statement.terminal
                           {
        self.declareDefinitionMetadata( yystack_[3].value.as < Tree > (), yystack_[2].value.as < Tree > (), yystack_[1].value.as < Tree > () );
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 404: // statement.declare.feature.metadata: DECLARE error statement.identifier.as.tree primitive.string.quoted.as.tree statement.terminal
                           {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 405: // statement.declare.feature.metadata: DECLARE statement.identifier.as.tree error primitive.string.quoted.as.tree statement.terminal
                           {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 406: // statement.declare.feature.metadata: DECLARE statement.identifier.as.tree statement.identifier.as.tree error statement.terminal
                           {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 407: // statement.declare.doc: BDOC doc EDOC
                          {
        ::declareDoc(yystack_[1].value.as < Tree > ());
        yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 408: // statement.declare.doc: BDOC error EDOC
                      {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 409: // statement.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::tree(self.lexer()->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 410: // statement.box.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::boxIdent(self.lexer()->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 411: // statement.foreign.function.identifier.as.tree: IDENT
            {
        yylhs.value.as < Tree > () = ::tree(self.lexer()->YYText());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 412: // statement.import: IMPORT LPAR primitive.string.unquoted.as.tree RPAR statement.terminal
                                                                                      {
        yylhs.value.as < Tree > () = ::importFile(yystack_[2].value.as < Tree > ());
        yylhs.value.as < Tree > ()->location() = yylhs.location;
      }
    break;

  case 413: // statement.import: IMPORT LPAR error RPAR statement.terminal
                                                {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 414: // statement.import: IMPORT LPAR primitive.string.unquoted.as.tree RPAR error
                                                                         {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 415: // statement.list: statement.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 416: // statement.list: statement.list.start.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 417: // statement.list: statement.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 418: // statement.list: statement.list.append.qualified
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 419: // statement.list.start: statement
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

  case 420: // statement.list.start.qualified: statement.math.precision.list statement
                                                {
          if ( yystack_[0].value.as < Tree > () != ::Faust::Primitive::Symbols::asTree().nil
            && self.acceptdefinition(yystack_[1].value.as < IntType > ()))
            yylhs.value.as < Tree > () = ::cons(yystack_[0].value.as < Tree > (), ::Faust::Primitive::Symbols::asTree().nil);
          else
            yylhs.value.as < Tree > () = ::Faust::Primitive::Symbols::asTree().nil;
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 421: // statement.list.append: statement.list statement
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

  case 422: // statement.list.append.qualified: statement.list statement.math.precision.list statement
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

  case 423: // statement.math.precision: FLOATMODE
                  {
          yylhs.value.as < IntType > () = 1;
        }
    break;

  case 424: // statement.math.precision: DOUBLEMODE
                   {
          yylhs.value.as < IntType > () = 2;
        }
    break;

  case 425: // statement.math.precision: QUADMODE
                 {
          yylhs.value.as < IntType > () = 4;
        }
    break;

  case 426: // statement.math.precision: FIXEDPOINTMODE
                       {
          yylhs.value.as < IntType > () = 8;
        }
    break;

  case 427: // statement.math.precision.list: statement.math.precision.list.start
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 428: // statement.math.precision.list: statement.math.precision.list.append
          { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 429: // statement.math.precision.list.start: statement.math.precision
            { yylhs.value.as < IntType > () = yystack_[0].value.as < IntType > (); }
    break;

  case 430: // statement.math.precision.list.append: statement.math.precision.list statement.math.precision
                                                                   {
              yylhs.value.as < IntType > () = yystack_[1].value.as < IntType > () | yystack_[0].value.as < IntType > ();
            }
    break;

  case 431: // statement.signal.pattern.rule: LPAR statement.definition.function.args RPAR ARROW expression statement.terminal
                                                                                       {
        yylhs.value.as < Tree > () = ::cons(yystack_[4].value.as < Tree > (),yystack_[1].value.as < Tree > ());
      }
    break;

  case 432: // statement.signal.pattern.rule: LPAR error RPAR ARROW expression statement.terminal
                                                          {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 433: // statement.signal.pattern.rule: LPAR statement.definition.function.args RPAR ARROW error statement.terminal
                                                                                  {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 434: // statement.signal.pattern.rule: LPAR statement.definition.function.args RPAR ARROW expression error
                                                                          {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    break;

  case 435: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.start
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 436: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.append
      { yylhs.value.as < Tree > () = yystack_[0].value.as < Tree > (); }
    break;

  case 437: // statement.signal.pattern.rule.list.start: statement.signal.pattern.rule
                                      {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            ::Faust::Primitive::Symbols::asTree().nil
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 438: // statement.signal.pattern.rule.list.append: statement.signal.pattern.rule.list statement.signal.pattern.rule
                                                                         {
          yylhs.value.as < Tree > () = ::cons(
            yystack_[0].value.as < Tree > (),
            yystack_[1].value.as < Tree > ()
          );
          yylhs.value.as < Tree > ()->location() = yylhs.location;
        }
    break;

  case 439: // statement.terminal: ENDDEF
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
    break;

  case 440: // statement.terminal: ENDL
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
    break;

  case 441: // statement.terminal: ENDOFINPUT
                 { return 0; }
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
        report_syntax_error (yyctx);
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

  const char *
  BisonImplementation::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "ENDOFINPUT", "error", "invalid token", "WITH", "LETREC", "SPLIT",
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
  "doc.attribute.definition.dependencies",
  "doc.attribute.definition.doc.tags",
  "doc.attribute.definition.distributed", "doc.attribute.definition",
  "doc.attribute.value", "expression", "expression.component",
  "expression.composition", "expression.composition.parallel",
  "expression.composition.serial", "expression.composition.mix",
  "expression.composition.recursive", "expression.composition.sequence",
  "expression.composition.split", "expression.environment",
  "expression.infix", "expression.infix.definitions.substitution",
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
  "primitive.foreign.function",
  "primitive.foreign.function.signature.names.1.args.0",
  "primitive.foreign.function.signature.names.1.args.list",
  "primitive.foreign.function.signature.names.2.args.0",
  "primitive.foreign.function.signature.names.2.args.list",
  "primitive.foreign.function.signature.names.3.args.0",
  "primitive.foreign.function.signature.names.3.args.list",
  "primitive.foreign.function.signature", "primitive.foreign.constant",
  "primitive.foreign.variable", "primitive.signal.inputs",
  "primitive.signal.outputs", "statement", "statement.definition",
  "statement.definition.function.arg",
  "statement.definition.function.args",
  "statement.definition.function.args.start",
  "statement.definition.function.args.append",
  "statement.definition.function.declaration",
  "statement.definition.function",
  "statement.definition.assignment.operator",
  "statement.definition.assignment", "statement.definition.with",
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
  "statement.signal.pattern.rule.list.append", "statement.terminal", YY_NULLPTR
    };
    return yy_sname[yysymbol];
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




  const short BisonImplementation::yypact_ninf_ = -563;

  const signed char BisonImplementation::yytable_ninf_ = -11;

  const short
  BisonImplementation::yypact_[] =
  {
     192,    59,   -49,  -563,    84,  -563,  -563,  -563,  -563,    86,
      73,  -563,  -563,    71,  -563,  -563,  -563,  -563,  -563,   303,
    -563,   290,  -563,  -563,  -563,  -563,  -563,   254,  -563,  -563,
    -563,  -563,  4158,  -563,  -563,   862,  -563,    43,   439,  -563,
      80,    16,   965,  1068,    24,    85,  -563,  -563,    26,    98,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,   862,  1171,  1274,
    -563,   254,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
     191,   524,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,   117,   162,   235,   258,
     294,   315,   320,   339,   372,   411,   418,   428,   471,   495,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,   503,  -563,  -563,
    1377,   508,   525,   259,   422,   529,  -563,  -563,   533,   553,
     565,   573,   589,   592,   437,  -563,  -563,  -563,  -563,  4345,
    -563,  -563,  -563,  -563,  -563,  4391,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,   124,  -563,  -563,
    -563,   212,    66,  -563,  -563,  4345,  -563,  -563,   265,  -563,
    -563,   304,  -563,  -563,    71,   478,    33,    75,    83,  -563,
      31,   111,    40,    99,   421,  -563,   426,   452,   542,   698,
    -563,  -563,  -563,  -563,   577,   599,  -563,  -563,    66,   606,
     305,    60,    64,  -563,  -563,  -563,  -563,  -563,  -563,   674,
     776,   795,    88,   241,   248,   257,   261,   269,   286,   291,
     297,   310,   596,    94,    90,   374,   314,   324,   326,   728,
    4158,    97,   105,   123,   132,  1480,  1583,    20,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    -563,   632,  1686,   365,  4158,   654,   672,   679,   684,   862,
    -563,    71,    82,  -563,    71,    71,  -563,  -563,  -563,    71,
      71,  -563,  -563,  -563,  -563,  -563,   615,   634,   635,  -563,
    -563,  -563,  -563,  -563,   685,   713,  -563,  -563,  -563,    23,
     134,  -563,  -563,  -563,  -563,  -563,  -563,   770,   693,   136,
     693,   140,   730,   736,   742,   743,   802,   818,   821,   830,
     831,   832,   839,   861,   863,   883,   934,   939,   940,   957,
     960,   961,   963,   785,   306,  -563,  -563,  -563,  -563,  -563,
     911,   962,   968,   969,    29,   309,   191,   455,  -563,  -563,
    -563,  -563,  -563,   219,  -563,  -563,  -563,  -563,   327,   986,
    1037,   989,  1064,   992,  1088,  1065,  1140,   102,   442,   264,
     518,  1069,  1789,  -563,     7,  -563,  -563,  4345,   703,   167,
    -563,  4411,  4430,  4504,  4521,  4537,  4552,  4311,  4572,  4588,
    4603,  4617,  4636,  4651,  4623,  4664,   630,  4639,   719,  -563,
    1072,   355,    30,  -563,   158,  -563,  -563,  -563,  -563,   488,
    -563,   862,   488,   502,   391,  1163,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,    22,    38,    57,   862,   862,   593,  -563,
      61,   113,   331,   126,  1166,  1167,  1169,  1191,  1242,  1243,
    -563,  -563,  -563,  -563,  4158,  1892,  4158,  1995,  4158,  2098,
     862,  2201,   862,  2304,   862,  2407,  4158,  2510,  4158,  2613,
     862,  1227,   632,  1228,  -563,  -563,  -563,  -563,  -563,  -563,
     728,  -563,  4158,  -563,  -563,  4158,  -563,  4158,  -563,  4158,
    -563,  4158,  -563,  -563,  -563,  -563,  -563,  1192,   373,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,   488,  -563,   214,   180,
      41,   344,   644,   632,  -563,   499,  -563,  -563,  -563,  1189,
    1142,  -563,  -563,  1144,  1217,  1218,  1241,  1244,   214,   214,
    -563,  -563,  -563,  1294,  1276,   912,  1276,   917,   148,   429,
    1375,  1397,   593,   593,   215,   593,   593,   250,   828,  1403,
     837,  1354,  1448,  1454,  1557,  1449,  1660,   605,   266,   620,
     622,   280,   637,   639,   362,   645,  1763,  1456,  1866,  1969,
    1457,  2072,   214,  1384,  1399,  -563,  1402,  -563,   394,  2175,
    2278,  2381,  2484,  1400,  1405,  -563,  -563,  -563,  -563,  -563,
     488,    71,  -563,  1396,  -563,   506,  -563,  2716,  -563,  -563,
    -563,  -563,  -563,  -563,   596,   433,  -563,  -563,  -563,  -563,
    -563,   424,  -563,  -563,   456,  -563,   430,   473,   510,  1404,
    -563,   458,   596,   333,  1426,  1477,  1478,  1485,  1486,  1487,
    1501,  1504,  4158,  4158,  2819,  4158,  4158,  2922,  4158,  4158,
    3025,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    4158,  4158,  3128,  4158,  4158,  3231,  -563,   862,  3334,   862,
    -563,   862,   862,   862,   862,   862,  3437,   420,  -563,    42,
     434,   212,    66,  1505,  1276,  1015,   773,  -563,  1276,  1020,
    -563,  1276,  1118,   170,   562,  -563,  -563,  1507,  1529,  1530,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  2587,  2690,
    1609,  2793,  2896,  2999,  1654,  3102,  3205,  3308,  1655,  3411,
     626,   717,  1588,   729,   734,   759,  1589,   788,   647,   370,
     668,   681,   687,   690,   697,   710,    66,    60,    96,  -563,
    -563,  -563,  -563,  -563,  1591,  -563,   461,  -563,  1605,  -563,
     464,  1608,  -563,   480,  1611,  1633,  1638,  -563,   482,  -563,
    -563,  -563,  4158,  4158,  4158,  3540,  4158,  4158,  4158,  3643,
    4158,  4158,  4158,  3746,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  1123,  -563,  1221,  -563,  1226,  -563,
    1324,   604,  -563,  -563,  3514,  3617,  3720,  1682,  3823,  3926,
    4029,  4132,  1707,  4336,  4455,  4460,  4472,  1757,  4477,  -563,
     500,  -563,   515,  -563,   530,  -563,   545,  1684,  -563,   570,
    4158,  4158,  4158,  4158,  3849,  4158,  4158,  4158,  4158,  3952,
    4158,  4158,  4158,  4158,  4055,  -563,  -563,  -563,  -563,  -563,
    -563,   808,   814,   859,  4235,  1691,  4266,  4271,  4276,  4281,
    4286,  1692,  4291,  4296,  4301,  4306,  4313,  1693,  4318,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563
  };

  const short
  BisonImplementation::yydefact_[] =
  {
       0,     0,     0,   410,     0,   423,   424,   425,   426,     0,
       0,   419,   365,     0,   370,   371,   366,   367,   368,     0,
     369,     0,   415,   416,   417,   418,   429,     0,   427,   428,
     441,   439,     0,   382,   440,     0,   381,     0,     0,   409,
       0,     0,     0,     0,     0,     0,    11,    17,     0,     4,
       5,     6,     7,     9,     8,     1,   380,     0,     0,     0,
     421,     0,   420,   430,   137,   138,   141,   139,   140,   142,
     155,   156,   198,   157,   158,   159,   197,   199,   163,   164,
     168,   196,   194,   195,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   179,   180,   181,   182,   183,   184,   185,   165,   166,
     167,   169,   170,   143,   144,   145,   160,   161,   146,   147,
     151,   259,   260,   200,   201,   214,   215,     0,   231,   232,
       0,     0,     0,     0,     0,     0,   192,   193,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,    60,   372,
      46,    47,    44,    45,    61,    48,    55,    56,    57,    76,
      77,    78,    79,    59,    58,    62,    63,    64,    65,    66,
      67,    68,   134,   136,   132,   152,   153,   154,   133,   175,
     171,   178,   172,   135,    69,    70,   188,   189,   190,    72,
     204,   205,   216,   217,   212,   213,   207,   226,   227,   206,
     235,   236,   229,   250,   251,   252,   230,   258,   257,   256,
     208,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   210,   209,   211,   225,   228,   375,     0,   373,   374,
      71,     0,     0,    38,    42,    41,    37,    36,     0,   220,
     221,     0,   218,   219,     0,     0,     0,     0,     0,   408,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
      31,    32,    33,    23,     0,     0,   407,    12,     0,     0,
       0,     0,     0,   422,   173,   176,   174,   177,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     384,     0,     0,   400,     0,     0,   401,   402,   399,     0,
       0,    14,    13,    16,    15,    22,     0,     0,     0,    20,
      24,    19,    18,   385,     0,     0,   386,   387,   383,     0,
       0,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   113,   114,   187,   186,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   249,
     240,   248,   244,     0,   246,   242,   243,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   437,     0,   435,   436,    52,    49,    51,
      50,    86,    87,    90,    88,    89,    91,    80,    81,    93,
      82,    83,    84,    92,    94,    95,    96,    85,    99,    75,
       0,     0,     0,   395,     0,   391,   392,   393,   394,     0,
     376,     0,     0,     0,     0,    43,   413,   414,   412,   404,
     405,   406,   403,     0,     0,     0,     0,     0,     0,   411,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   277,   280,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    39,   131,   130,    54,    53,
       0,   262,     0,   253,   102,     0,   104,     0,   106,     0,
     108,     0,   362,   361,   364,   363,   203,     0,     0,   202,
     438,    98,    97,    74,    73,   397,     0,   396,   378,     0,
       0,     0,     0,     0,   116,     0,   122,   123,   124,     0,
       0,    34,    35,     0,     0,     0,     0,     0,   379,   377,
     222,   223,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,   115,     0,   247,     0,     0,
       0,     0,     0,     0,     0,   398,   389,   390,   388,   119,
       0,     0,   129,     0,   117,     0,   125,     0,    26,    25,
      28,    27,    30,    29,     0,     0,   239,   321,   265,   233,
     234,     0,   263,   264,     0,   322,     0,     0,     0,     0,
     320,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   300,   301,   299,   303,   304,   302,   306,   307,   305,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
     254,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,   128,     0,     0,     0,     0,     0,   324,     0,     0,
     325,     0,     0,     0,     0,   326,   323,     0,     0,     0,
     354,   355,   356,   353,   358,   359,   360,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     121,   118,   126,   317,     0,   328,     0,   266,     0,   329,
       0,     0,   330,     0,     0,     0,     0,   327,     0,   318,
     319,   316,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,   314,   315,   312,   309,   310,
     311,   308,   110,   111,   109,   255,   101,   103,   105,   107,
     432,   433,   434,   431,     0,   332,     0,   333,     0,   334,
       0,     0,   335,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   337,
       0,   338,     0,   339,     0,   340,     0,     0,   336,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,   343,   344,   345,   346,
     341,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
     283,   284,   285,   286,   281,   288,   289,   290,   291,   292,
     287,   294,   295,   296,   297,   298,   293
  };

  const short
  BisonImplementation::yypgoto_[] =
  {
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  1533,   222,    35,  -563,  1259,  -563,   -32,
    -563,  -563,  -563,  -563,  -563,  4438,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  1220,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -292,
    -563,  -286,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -283,  -279,  -563,   -22,  -563,  -235,  -563,
     -36,  -563,  -563,  -563,  1057,  -271,  -563,  -563,  -563,  -563,
    -563,  1277,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -562,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,   -16,
    -319,  -296,   -52,  -563,  -563,  -563,  -563,  1799,  -563,  -563,
    -455,  -563,  -563,  -563,  -563,  -563,  -563,  -563,   -23,    19,
    -358,  -563,  1525,  -563,  -563,  -563,  -563,   -25,     3,  -563,
    -563,  1424,  -563,  -563,  -563,   -12
  };

  const short
  BisonImplementation::yydefgoto_[] =
  {
       0,    10,    48,    49,    50,    51,    52,    53,    54,   259,
     260,   261,   262,   263,   583,   232,   148,   233,   234,   235,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     404,   405,   406,   236,   575,   576,   577,   578,   579,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   243,   244,   240,   241,   592,
     593,   196,   197,   198,   668,   199,   200,   201,   670,   422,
     423,   424,   425,   426,   427,   202,   203,   204,   205,   206,
     207,   208,   209,   671,   672,   673,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   371,   372,
     373,   374,   375,   376,   377,   222,   223,   224,   225,    11,
      12,   226,   227,   228,   229,    13,    14,    35,    15,   237,
     474,   475,   476,   477,   478,    16,    17,    18,    40,   230,
     500,    20,    21,    22,    23,    24,    25,    26,   479,    28,
      29,   443,   444,   445,   446,    36
  };

  const short
  BisonImplementation::yytable_[] =
  {
     149,    56,    63,    27,   428,    60,   270,   418,   370,   379,
     381,    62,   502,   419,   473,   245,   420,   248,   247,    19,
     421,   441,   265,   580,    61,   254,   149,   569,   571,    30,
      30,   498,    37,    30,   336,   676,    63,   681,   480,   584,
      19,    30,    30,   336,   238,   273,    19,   383,   385,   387,
     389,   391,   393,   395,   397,   399,   401,   402,   586,    30,
      30,   411,   413,   336,    30,   367,    30,   337,   338,   337,
     338,    30,   339,    55,   339,    30,   347,   251,   253,   594,
      19,   246,    30,   487,   349,    38,   264,    41,   442,   382,
     278,   559,   268,   336,   272,   403,    30,   842,   429,   337,
     338,   442,   337,   338,   339,   336,   431,   339,    31,    31,
      32,    32,    31,   538,   337,   338,   563,    33,    33,   339,
      31,    31,    32,    32,   433,   647,   790,   600,   499,    33,
      33,   596,   334,   435,   249,   501,   242,   505,    31,    31,
      32,   508,   595,    31,   266,    31,   239,    33,   255,   677,
      31,   351,   581,   582,    31,   565,   256,   257,   258,     1,
     567,    31,   353,   473,   473,   295,    34,    34,   581,   582,
      34,   804,   408,   796,   310,    31,   311,   800,    34,    34,
     803,     1,   808,   242,   552,    39,   242,   581,   582,    39,
      39,   239,    -3,     1,   597,   727,    34,    34,   279,     3,
     730,    34,     3,    34,   -10,    42,   335,    43,    34,    44,
       3,    45,    34,    46,    47,   336,   686,   337,   338,    34,
     340,   354,   339,   344,   345,   267,   350,   540,     3,   590,
     591,   352,   343,    34,   346,   348,   665,     3,   674,   499,
     678,    39,   384,   280,   564,    39,   638,   645,   418,   386,
     565,   690,   565,   499,   419,     1,   363,   420,   388,   366,
     368,   421,   390,     3,   646,   274,   275,   336,   149,   336,
     392,     5,     6,     7,     8,   499,   447,   448,   449,   450,
     471,     2,   870,   336,   872,     3,   874,   394,   876,   879,
      -2,     1,   396,     5,     6,     7,     8,     3,   398,     4,
     149,    27,   149,   541,    57,     5,     6,     7,     8,     9,
       1,   400,   407,   334,   532,   410,   281,    19,   590,   591,
     430,   432,   434,   436,   669,   412,   669,   414,   669,   486,
     488,   473,   489,   490,   748,   542,   473,   491,   492,   282,
     438,   440,   298,     2,   239,     1,   554,   341,   702,   598,
     469,   239,    19,   590,   591,   504,   506,   507,   509,     3,
     239,     4,   705,   334,   239,   336,   472,     5,     6,     7,
       8,     9,   239,   336,   485,   283,   794,   337,   338,     2,
     798,   334,   339,   801,    58,   805,   342,   365,   533,   239,
     558,    33,   572,   539,   239,     3,   284,     4,     2,    60,
     239,   285,   719,     5,     6,     7,     8,     9,   565,   543,
     149,   565,   599,   239,     3,     2,     4,   239,    61,   573,
     286,     1,     5,     6,     7,     8,     9,   239,   648,   733,
     679,     3,   736,     4,    19,     1,   239,   562,   736,     5,
       6,     7,     8,     9,   708,   337,   338,   747,   749,     3,
     339,   734,   833,   287,    63,   644,   409,     5,     6,     7,
       8,    84,    85,   666,   669,   669,   736,   601,   669,   736,
       3,   669,   736,   669,   738,   574,   720,   566,     5,     6,
       7,     8,   608,   610,   611,   613,   614,   616,   736,     1,
     736,   741,   288,    19,   626,   628,   629,   631,    19,   289,
     653,    19,    19,   570,   789,   299,   737,   729,   736,   290,
     149,   680,   740,   639,   735,   640,   568,   641,   791,   642,
     307,   337,   338,   736,   553,     3,   339,   573,   743,   276,
     277,   588,   589,     5,     6,     7,     8,   739,   736,     3,
     746,    63,   242,   845,    39,   355,   847,     5,     6,     7,
       8,   635,   291,   736,   742,   617,   619,   620,   622,   623,
     625,   356,   849,   806,   853,   632,   684,   685,   687,   688,
     689,   691,   566,   669,   566,   669,   292,   669,   736,   669,
     669,   242,   895,   654,   293,    19,   655,   357,    19,   296,
      19,   744,   652,     3,    84,    85,   666,   896,   276,   277,
     555,     5,     6,     7,     8,   877,   297,     3,   337,   338,
     300,     3,   897,   339,   301,     5,     6,     7,     8,     5,
       6,     7,     8,   337,   338,   337,   338,   898,   339,     3,
     339,   308,   309,   310,   302,   311,    84,    85,   666,   728,
     337,   338,   337,   338,   807,   339,   303,   339,   337,   338,
     337,   338,   900,   339,   304,   339,   328,   329,   330,   331,
     758,   759,   761,   762,   763,   765,   766,   767,   769,    19,
     305,   337,   338,   306,    19,   369,   339,   358,   770,   771,
     773,   774,   775,   777,   337,   338,   878,   701,   364,   339,
     337,   338,   732,   337,   338,   339,   590,   591,   339,   239,
     337,   338,   703,   361,   704,   339,    84,    85,   824,   309,
     310,   332,   311,   337,   338,   333,   585,   587,   339,   706,
     792,   707,   308,   309,   310,   362,   311,   709,   649,   832,
     566,   650,   651,   566,   308,   309,   310,     3,   311,   308,
     309,   310,   481,   311,   416,   417,    19,   330,   331,    19,
     834,   493,   778,   780,   781,   482,   782,   783,   784,   785,
     786,   788,   483,   835,   308,   309,   310,   484,   311,   836,
     494,   495,   837,   496,   840,   841,   843,   378,   503,   838,
     854,   855,   856,   858,   859,   860,   861,   863,   864,   865,
     866,   868,   839,   308,   309,   310,   380,   311,    39,   825,
     332,   497,   125,   126,   333,    84,    85,   666,    84,    85,
     514,   827,   510,   308,   309,   310,   828,   311,   511,   308,
     309,   310,   359,   311,   512,   513,   515,    84,    85,   516,
     256,   257,   258,   308,   309,   310,   692,   311,   517,   518,
     519,   829,   308,   309,   310,   694,   311,   520,   901,   902,
     903,   904,   906,   907,   908,   909,   910,   912,   913,   914,
     915,   916,   918,   231,   308,   309,   310,   531,   311,   521,
     831,   522,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     919,   523,    82,    83,    84,    85,   920,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   921,   524,   130,    84,    85,   666,   525,   526,    84,
      85,   666,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   527,   250,     3,   528,   529,
     144,   530,   145,   146,   147,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   534,   667,    82,    83,    84,    85,   675,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   535,   545,   130,    84,    85,   666,
     536,   537,    84,    85,   666,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   544,   252,
       3,   546,   547,   144,   548,   145,   146,   147,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   549,   795,    82,    83,
      84,    85,   799,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   550,   551,   130,
      84,    85,   666,   556,   561,    84,    85,   666,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   339,   269,     3,   602,   603,   144,   604,   145,   146,
     147,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   605,
     802,    82,    83,    84,    85,   869,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     606,   607,   130,    84,    85,   666,   634,   636,    84,    85,
     666,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   643,   271,     3,   657,   658,   144,
     659,   145,   146,   147,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   664,   871,    82,    83,    84,    85,   873,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   660,   661,   130,    84,    85,   666,   308,
     309,   310,   695,   311,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   662,   294,     3,
     663,   499,   144,   682,   145,   146,   147,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   683,   875,    82,    83,    84,
      85,   693,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   696,   699,   130,   308,
     309,   310,   697,   311,   711,   714,   716,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     717,   437,     3,   718,   651,   144,   745,   145,   146,   147,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   750,   725,
      82,    83,    84,    85,   726,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   751,
     752,   130,   308,   309,   310,   698,   311,   753,   754,   755,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   756,   439,     3,   757,   793,   144,   809,
     145,   146,   147,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   810,   811,    82,    83,    84,    85,   814,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   818,   822,   130,   308,   309,   310,   700,   311,
     826,   830,   844,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   846,   470,     3,   848,
     883,   144,   850,   145,   146,   147,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   851,   888,    82,    83,    84,    85,
     852,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   893,   899,   130,   308,   309,
     310,   710,   311,   923,   929,   935,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   633,
     557,     3,   360,   797,   144,   656,   145,   146,   147,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   637,    59,    82,
      83,    84,    85,   415,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   560,     0,
     130,   308,   309,   310,   712,   311,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,   609,     3,     0,     0,   144,     0,   145,
     146,   147,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,   130,   308,   309,   310,   713,   311,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,   612,     3,     0,     0,
     144,     0,   145,   146,   147,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,   130,   308,   309,   310,
     715,   311,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,   615,
       3,     0,     0,   144,     0,   145,   146,   147,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,   130,
     308,   309,   310,   721,   311,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,   618,     3,     0,     0,   144,     0,   145,   146,
     147,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,   130,   308,   309,   310,   722,   311,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,   621,     3,     0,     0,   144,
       0,   145,   146,   147,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,   130,   308,   309,   310,   723,
     311,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,   624,     3,
       0,     0,   144,     0,   145,   146,   147,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,   130,   308,
     309,   310,   724,   311,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,   627,     3,     0,     0,   144,     0,   145,   146,   147,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,   130,   308,   309,   310,   812,   311,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,   630,     3,     0,     0,   144,     0,
     145,   146,   147,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,   130,   308,   309,   310,   813,   311,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,   731,     3,     0,
       0,   144,     0,   145,   146,   147,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,   130,   308,   309,
     310,   815,   311,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
     760,     3,     0,     0,   144,     0,   145,   146,   147,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
     130,   308,   309,   310,   816,   311,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,   764,     3,     0,     0,   144,     0,   145,
     146,   147,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,   130,   308,   309,   310,   817,   311,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,   768,     3,     0,     0,
     144,     0,   145,   146,   147,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,   130,   308,   309,   310,
     819,   311,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,   772,
       3,     0,     0,   144,     0,   145,   146,   147,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,   130,
     308,   309,   310,   820,   311,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,   776,     3,     0,     0,   144,     0,   145,   146,
     147,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,   130,   308,   309,   310,   821,   311,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,   779,     3,     0,     0,   144,
       0,   145,   146,   147,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,   130,   308,   309,   310,   823,
     311,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,   787,     3,
       0,     0,   144,     0,   145,   146,   147,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,   130,   308,
     309,   310,   880,   311,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,   857,     3,     0,     0,   144,     0,   145,   146,   147,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,   130,   308,   309,   310,   881,   311,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,   862,     3,     0,     0,   144,     0,
     145,   146,   147,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,   130,   308,   309,   310,   882,   311,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,   867,     3,     0,
       0,   144,     0,   145,   146,   147,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,   130,   308,   309,
     310,   884,   311,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
     905,     3,     0,     0,   144,     0,   145,   146,   147,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
     130,   308,   309,   310,   885,   311,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,   911,     3,     0,     0,   144,     0,   145,
     146,   147,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,   130,   308,   309,   310,   886,   311,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,   917,     3,     0,     0,
     144,     0,   145,   146,   147,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,   130,   308,   309,   310,
     887,   311,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
       3,     0,     0,   144,     0,   145,   146,   147,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,   130,
     308,   309,   310,     0,   311,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,     3,     0,     0,   144,     0,   145,   146,
     147,   308,   309,   310,     0,   311,   308,   309,   310,     0,
     311,   308,   309,   310,     0,   311,   308,   309,   310,     0,
     311,   308,   309,   310,     0,   311,   308,   309,   310,     0,
     311,   308,   309,   310,     0,   311,   308,   309,   310,     0,
     311,   308,   309,   310,     0,   311,     0,   922,   308,   309,
     310,     0,   311,   308,   309,   310,     0,   311,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   308,   309,   310,   889,   311,     0,     0,   924,     0,
     308,   309,   310,   925,   311,     0,     0,     0,   926,     0,
       0,     0,     0,   927,     0,     0,     0,     0,   928,     0,
       0,     0,     0,   930,     0,     0,     0,     0,   931,     0,
       0,     0,     0,   932,     0,     0,     0,     0,   933,     0,
       0,     0,   332,     0,     0,   934,   333,     0,     0,     0,
     936,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   -11,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   -11,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     308,   309,   310,   890,   311,   308,   309,   310,   891,   311,
       0,     0,   332,     0,     0,     0,   333,   308,   309,   310,
     892,   311,   308,   309,   310,   894,   311,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   333,   -11,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   -11,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   -11,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   -11,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     0,     0,     0,   332,     0,     0,     0,   333,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,     0,     0,     0,   333,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,     0,
       0,     0,   333,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,     0,     0,     0,   333,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   326,   327,   328,
     329,   330,   331,   332,     0,     0,     0,   333,   324,   325,
     326,   327,   328,   329,   330,   331,   329,   330,   331,   332,
       0,     0,     0,   333,   325,   326,   327,   328,   329,   330,
     331,     0,     0,     0,   332,     0,     0,     0,   333,   327,
     328,   329,   330,   331,     0,     0,     0,     0,   332,     0,
       0,     0,   333,     0,   332,     0,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,     0,
     332,   333,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,   332,     0,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,     0,     0,   333,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468
  };

  const short
  BisonImplementation::yycheck_[] =
  {
      32,    13,    27,     0,   300,    21,    58,   299,   279,   280,
     281,    27,   370,   299,   333,    38,   299,    40,    40,     0,
     299,     1,    45,     1,    21,     1,    58,   482,   483,     0,
       0,     8,    81,     0,     3,   597,    61,   599,   334,     1,
      21,     0,     0,     3,     1,    61,    27,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,     1,     0,
       0,   296,   297,     3,     0,     1,     0,     3,     4,     3,
       4,     0,     8,     0,     8,     0,     1,    42,    43,    18,
      61,     1,     0,     1,     1,     1,     1,     1,    81,     1,
      71,    84,    57,     3,    59,     1,     0,     1,     1,     3,
       4,    81,     3,     4,     8,     3,     1,     8,    79,    79,
      81,    81,    79,    84,     3,     4,    86,    88,    88,     8,
      79,    79,    81,    81,     1,    84,    84,     1,   105,    88,
      88,    18,     8,     1,   118,     1,   103,     1,    79,    79,
      81,     1,    81,    79,   118,    79,   103,    88,   124,     1,
      79,   120,   130,   131,    79,   474,   132,   133,   134,     1,
     479,    79,   122,   482,   483,   130,   137,   137,   130,   131,
     137,     1,    82,   735,     7,    79,     9,   739,   137,   137,
     742,     1,   744,   103,    82,   105,   103,   130,   131,   105,
     105,   103,     0,     1,    81,   650,   137,   137,    81,   105,
     655,   137,   105,   137,   118,   119,    82,   121,   137,   123,
     105,   125,   137,   127,   128,     3,     1,     3,     4,   137,
     232,   122,     8,   245,   246,   127,   248,     8,   105,   103,
     104,   120,   244,   137,   246,   247,   594,   105,   596,   105,
     598,   105,     1,    81,    86,   105,   542,   566,   540,     1,
     569,     1,   571,   105,   540,     1,   268,   540,     1,   271,
     272,   540,     1,   105,    84,    74,    75,     3,   300,     3,
       1,   113,   114,   115,   116,   105,   308,   309,   310,   311,
     332,    89,   844,     3,   846,   105,   848,     1,   850,   851,
       0,     1,     1,   113,   114,   115,   116,   105,     1,   107,
     332,   298,   334,    84,     1,   113,   114,   115,   116,   117,
       1,     1,   293,     8,     8,     1,    81,   298,   103,   104,
     301,   302,   303,   304,   595,     1,   597,     1,   599,   341,
     342,   650,   344,   345,     1,     8,   655,   349,   350,    81,
     305,   306,    83,    89,   103,     1,    82,    82,    82,    18,
     331,   103,   333,   103,   104,   378,   379,   380,   381,   105,
     103,   107,    82,     8,   103,     3,     1,   113,   114,   115,
     116,   117,   103,     3,   339,    81,   734,     3,     4,    89,
     738,     8,     8,   741,    81,   743,    82,    82,    82,   103,
     442,    88,     1,    84,   103,   105,    81,   107,    89,   415,
     103,    81,     8,   113,   114,   115,   116,   117,   727,    82,
     442,   730,    81,   103,   105,    89,   107,   103,   415,    28,
      81,     1,   113,   114,   115,   116,   117,   103,    84,   664,
       1,   105,     8,   107,   415,     1,   103,    82,     8,   113,
     114,   115,   116,   117,    82,     3,     4,   682,   683,   105,
       8,    18,    82,    81,   479,    82,    82,   113,   114,   115,
     116,    32,    33,    34,   735,   736,     8,   503,   739,     8,
     105,   742,     8,   744,    18,    84,    82,   474,   113,   114,
     115,   116,   514,   515,   516,   517,   518,   519,     8,     1,
       8,    18,    81,   474,   526,   527,   528,   529,   479,    81,
       1,   482,   483,     1,    84,    83,    82,     1,     8,    81,
     542,    82,    82,   545,    81,   547,   481,   549,    84,   551,
      83,     3,     4,     8,    82,   105,     8,    28,    18,    74,
      75,   496,   497,   113,   114,   115,   116,    81,     8,   105,
      82,   566,   103,    82,   105,   124,    82,   113,   114,   115,
     116,   532,    81,     8,    81,   520,   521,   522,   523,   524,
     525,   135,    82,     1,    82,   530,   602,   603,   604,   605,
     606,   607,   569,   844,   571,   846,    81,   848,     8,   850,
     851,   103,    82,    84,    81,   566,    87,   135,   569,    81,
     571,    81,   573,   105,    32,    33,    34,    82,    74,    75,
      82,   113,   114,   115,   116,     1,    81,   105,     3,     4,
      81,   105,    82,     8,    81,   113,   114,   115,   116,   113,
     114,   115,   116,     3,     4,     3,     4,    82,     8,   105,
       8,     5,     6,     7,    81,     9,    32,    33,    34,   651,
       3,     4,     3,     4,    82,     8,    81,     8,     3,     4,
       3,     4,    82,     8,    81,     8,    26,    27,    28,    29,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   650,
      81,     3,     4,    81,   655,     1,     8,   135,   710,   711,
     712,   713,   714,   715,     3,     4,    82,    82,    82,     8,
       3,     4,   657,     3,     4,     8,   103,   104,     8,   103,
       3,     4,    82,   126,    82,     8,    32,    33,    82,     6,
       7,    81,     9,     3,     4,    85,   494,   495,     8,    82,
     732,    82,     5,     6,     7,   126,     9,    82,    84,    82,
     727,    87,    88,   730,     5,     6,     7,   105,     9,     5,
       6,     7,    88,     9,    16,    17,   727,    28,    29,   730,
      82,   136,   717,   718,   719,    83,   721,   722,   723,   724,
     725,   726,    83,    82,     5,     6,     7,    83,     9,    82,
     136,   136,    82,    88,   786,   787,   788,     1,     8,    82,
     812,   813,   814,   815,   816,   817,   818,   819,   820,   821,
     822,   823,    82,     5,     6,     7,     1,     9,   105,    82,
      81,    88,    74,    75,    85,    32,    33,    34,    32,    33,
       8,    82,    82,     5,     6,     7,    82,     9,    82,     5,
       6,     7,   124,     9,    82,    82,     8,    32,    33,     8,
     132,   133,   134,     5,     6,     7,     8,     9,     8,     8,
       8,    82,     5,     6,     7,     8,     9,     8,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,     1,     5,     6,     7,    82,     9,     8,
      82,     8,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      82,     8,    30,    31,    32,    33,    82,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    82,     8,    81,    32,    33,    34,     8,     8,    32,
      33,    34,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     8,     1,   105,     8,     8,
     108,     8,   110,   111,   112,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    82,    82,    30,    31,    32,    33,    82,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    82,     8,    81,    32,    33,    34,
      82,    82,    32,    33,    34,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    82,     1,
     105,    82,     8,   108,    82,   110,   111,   112,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     8,    82,    30,    31,
      32,    33,    82,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    82,     8,    81,
      32,    33,    34,    84,    82,    32,    33,    34,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     8,     1,   105,     8,     8,   108,     8,   110,   111,
     112,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     8,
      82,    30,    31,    32,    33,    82,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       8,     8,    81,    32,    33,    34,    29,    29,    32,    33,
      34,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    82,     1,   105,    88,   136,   108,
     136,   110,   111,   112,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     8,    82,    30,    31,    32,    33,    82,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   136,   136,    81,    32,    33,    34,     5,
       6,     7,     8,     9,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   136,     1,   105,
     136,   105,   108,     8,   110,   111,   112,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     8,    82,    30,    31,    32,
      33,     8,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     8,     8,    81,     5,
       6,     7,     8,     9,     8,     8,    82,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      81,     1,   105,    81,    88,   108,    82,   110,   111,   112,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    82,   109,
      30,    31,    32,    33,   109,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    82,
      82,    81,     5,     6,     7,     8,     9,    82,    82,    82,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    82,     1,   105,    82,    82,   108,    82,
     110,   111,   112,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    82,    82,    30,    31,    32,    33,     8,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     8,     8,    81,     5,     6,     7,     8,     9,
      82,    82,    81,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    81,     1,   105,    81,
       8,   108,    81,   110,   111,   112,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    81,     8,    30,    31,    32,    33,
      82,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     8,    82,    81,     5,     6,
       7,     8,     9,    82,    82,    82,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   530,
       1,   105,   259,   736,   108,   575,   110,   111,   112,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   540,    19,    30,
      31,    32,    33,   298,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,   444,    -1,
      81,     5,     6,     7,     8,     9,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,     1,   105,    -1,    -1,   108,    -1,   110,
     111,   112,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,     1,   105,    -1,    -1,
     108,    -1,   110,   111,   112,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,     1,
     105,    -1,    -1,   108,    -1,   110,   111,   112,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,     1,   105,    -1,    -1,   108,    -1,   110,   111,
     112,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    -1,    81,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,     1,   105,    -1,    -1,   108,
      -1,   110,   111,   112,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,     1,   105,
      -1,    -1,   108,    -1,   110,   111,   112,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    -1,    81,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,     1,   105,    -1,    -1,   108,    -1,   110,   111,   112,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      -1,    81,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,     1,   105,    -1,    -1,   108,    -1,
     110,   111,   112,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    -1,    81,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,     1,   105,    -1,
      -1,   108,    -1,   110,   111,   112,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
       1,   105,    -1,    -1,   108,    -1,   110,   111,   112,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    -1,
      81,     5,     6,     7,     8,     9,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,     1,   105,    -1,    -1,   108,    -1,   110,
     111,   112,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,     1,   105,    -1,    -1,
     108,    -1,   110,   111,   112,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,     1,
     105,    -1,    -1,   108,    -1,   110,   111,   112,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,     1,   105,    -1,    -1,   108,    -1,   110,   111,
     112,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    -1,    81,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,     1,   105,    -1,    -1,   108,
      -1,   110,   111,   112,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,     1,   105,
      -1,    -1,   108,    -1,   110,   111,   112,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    -1,    81,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,     1,   105,    -1,    -1,   108,    -1,   110,   111,   112,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      -1,    81,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,     1,   105,    -1,    -1,   108,    -1,
     110,   111,   112,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    -1,    81,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,     1,   105,    -1,
      -1,   108,    -1,   110,   111,   112,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    81,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
       1,   105,    -1,    -1,   108,    -1,   110,   111,   112,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    -1,
      81,     5,     6,     7,     8,     9,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,     1,   105,    -1,    -1,   108,    -1,   110,
     111,   112,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,     1,   105,    -1,    -1,
     108,    -1,   110,   111,   112,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,   111,   112,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,   111,
     112,     5,     6,     7,    -1,     9,     5,     6,     7,    -1,
       9,     5,     6,     7,    -1,     9,     5,     6,     7,    -1,
       9,     5,     6,     7,    -1,     9,     5,     6,     7,    -1,
       9,     5,     6,     7,    -1,     9,     5,     6,     7,    -1,
       9,     5,     6,     7,    -1,     9,    -1,    82,     5,     6,
       7,    -1,     9,     5,     6,     7,    -1,     9,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     5,     6,     7,     8,     9,    -1,    -1,    82,    -1,
       5,     6,     7,    82,     9,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    81,    -1,    -1,    82,    85,    -1,    -1,    -1,
      82,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       5,     6,     7,     8,     9,     5,     6,     7,     8,     9,
      -1,    -1,    81,    -1,    -1,    -1,    85,     5,     6,     7,
       8,     9,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    81,    -1,    -1,    -1,    85,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    81,    -1,
      -1,    -1,    85,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    81,    -1,    -1,    -1,    85,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    24,    25,    26,
      27,    28,    29,    81,    -1,    -1,    -1,    85,    22,    23,
      24,    25,    26,    27,    28,    29,    27,    28,    29,    81,
      -1,    -1,    -1,    85,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    -1,    81,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      81,    85,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329
  };

  const short
  BisonImplementation::yystos_[] =
  {
       0,     1,    89,   105,   107,   113,   114,   115,   116,   117,
     139,   267,   268,   273,   274,   276,   283,   284,   285,   287,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,    79,    81,    88,   137,   275,   303,    81,     1,   105,
     286,     1,   119,   121,   123,   125,   127,   128,   140,   141,
     142,   143,   144,   145,   146,     0,   303,     1,    81,   275,
     267,   296,   267,   295,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    30,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      81,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   108,   110,   111,   112,   154,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   219,   220,   221,   223,
     224,   225,   233,   234,   235,   236,   237,   238,   239,   240,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   263,   264,   265,   266,   269,   270,   271,   272,
     287,     1,   153,   155,   156,   157,   181,   277,     1,   103,
     215,   216,   103,   213,   214,   286,     1,   214,   286,   118,
       1,   153,     1,   153,     1,   124,   132,   133,   134,   147,
     148,   149,   150,   151,     1,   286,   118,   127,   153,     1,
     270,     1,   153,   267,    74,    75,    74,    75,   287,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,     1,   153,    81,    81,    83,    83,
      81,    81,    81,    81,    81,    81,    81,    83,     5,     6,
       7,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    81,    85,     8,    82,     3,     3,     4,     8,
     303,    82,    82,   303,   214,   214,   303,     1,   303,     1,
     214,   120,   120,   122,   122,   124,   135,   135,   135,   124,
     151,   126,   126,   303,    82,    82,   303,     1,   303,     1,
     223,   256,   257,   258,   259,   260,   261,   262,     1,   223,
       1,   223,     1,   216,     1,   216,     1,   216,     1,   216,
       1,   216,     1,   216,     1,   216,     1,   216,     1,   216,
       1,   216,   216,     1,   178,   179,   180,   287,    82,    82,
       1,   216,     1,   216,     1,   290,    16,    17,   197,   199,
     211,   212,   227,   228,   229,   230,   231,   232,   269,     1,
     287,     1,   287,     1,   287,     1,   287,     1,   153,     1,
     153,     1,    81,   299,   300,   301,   302,   157,   157,   157,
     157,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   287,
       1,   270,     1,   268,   278,   279,   280,   281,   282,   296,
     269,    88,    83,    83,    83,   153,   303,     1,   303,   303,
     303,   303,   303,   136,   136,   136,    88,    88,     8,   105,
     288,     1,   288,     8,   286,     1,   286,   286,     1,   286,
      82,    82,    82,    82,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,    82,     8,    82,    82,    82,    82,    82,    84,    84,
       8,    84,     8,    82,    82,     8,    82,     8,    82,     8,
      82,     8,    82,    82,    82,    82,    84,     1,   270,    84,
     299,    82,    82,    86,    86,   268,   296,   268,   153,   278,
       1,   278,     1,    28,    84,   182,   183,   184,   185,   186,
       1,   130,   131,   152,     1,   152,     1,   152,   153,   153,
     103,   104,   217,   218,    18,    81,    18,    81,    18,    81,
       1,   218,     8,     8,     8,     8,     8,     8,   157,     1,
     157,   157,     1,   157,   157,     1,   157,   153,     1,   153,
     153,     1,   153,   153,     1,   153,   157,     1,   157,   157,
       1,   157,   153,   155,    29,   287,    29,   229,   269,   157,
     157,   157,   157,    82,    82,   268,    84,    84,    84,    84,
      87,    88,   287,     1,    84,    87,   185,    88,   136,   136,
     136,   136,   136,   136,     8,   288,    34,    82,   222,   223,
     226,   241,   242,   243,   288,    82,   241,     1,   288,     1,
      82,   241,     8,     8,   218,   218,     1,   218,   218,   218,
       1,   218,     8,     8,     8,     8,     8,     8,     8,     8,
       8,    82,    82,    82,    82,    82,    82,    82,    82,    82,
       8,     8,     8,     8,     8,     8,    82,    81,    81,     8,
      82,     8,     8,     8,     8,   109,   109,   278,   303,     1,
     278,     1,   153,   216,    18,    81,     8,    82,    18,    81,
      82,    18,    81,    18,    81,    82,    82,   216,     1,   216,
      82,    82,    82,    82,    82,    82,    82,    82,   157,   157,
       1,   157,   157,   157,     1,   157,   157,   157,     1,   157,
     157,   157,     1,   157,   157,   157,     1,   157,   153,     1,
     153,   153,   153,   153,   153,   153,   153,     1,   153,    84,
      84,    84,   303,    82,   288,    82,   241,   222,   288,    82,
     241,   288,    82,   241,     1,   288,     1,    82,   241,    82,
      82,    82,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
     303,   303,     1,   303,    81,    82,    81,    82,    81,    82,
      81,    81,    82,    82,   157,   157,   157,     1,   157,   157,
     157,   157,     1,   157,   157,   157,   157,     1,   157,    82,
     241,    82,   241,    82,   241,    82,   241,     1,    82,   241,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,    82,    82,    82,    82,    82,
      82,   157,   157,   157,   157,     1,   157,   157,   157,   157,
     157,     1,   157,   157,   157,   157,   157,     1,   157,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82
  };

  const short
  BisonImplementation::yyr1_[] =
  {
       0,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   145,   145,
     146,   146,   146,   147,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   151,   152,   152,   153,   153,   153,   154,
     154,   155,   155,   156,   157,   157,   157,   157,   157,   158,
     159,   160,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   164,   164,   165,   166,   166,   166,   166,
     167,   167,   167,   167,   167,   167,   168,   168,   168,   168,
     168,   168,   169,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   177,
     177,   177,   178,   178,   179,   180,   181,   181,   181,   181,
     181,   181,   182,   182,   183,   184,   185,   185,   185,   186,
     187,   187,   188,   188,   188,   188,   188,   189,   189,   189,
     189,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   191,   191,   191,   192,   192,   192,   192,   192,
     192,   192,   192,   193,   193,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   197,   198,   198,   199,   200,
     200,   200,   200,   200,   200,   200,   201,   201,   202,   202,
     202,   203,   203,   203,   204,   204,   204,   205,   205,   205,
     205,   205,   205,   205,   206,   206,   206,   206,   206,   207,
     207,   207,   208,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   217,   218,   219,   219,   219,   219,   219,
     219,   220,   221,   222,   222,   223,   223,   224,   225,   226,
     227,   227,   228,   228,   229,   229,   230,   231,   232,   232,
     233,   233,   233,   234,   235,   236,   237,   237,   237,   238,
     238,   239,   240,   241,   241,   242,   243,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   245,   245,   246,
     246,   247,   247,   247,   247,   247,   247,   248,   248,   248,
     248,   248,   248,   249,   249,   249,   249,   249,   249,   250,
     250,   250,   251,   251,   251,   252,   252,   252,   253,   253,
     253,   253,   254,   254,   254,   254,   255,   255,   255,   255,
     256,   256,   256,   257,   257,   257,   257,   258,   258,   258,
     258,   259,   259,   259,   259,   259,   260,   260,   260,   260,
     260,   261,   261,   261,   261,   261,   261,   262,   262,   262,
     262,   262,   262,   263,   263,   263,   263,   264,   264,   264,
     264,   265,   265,   266,   266,   267,   267,   267,   267,   267,
     268,   268,   269,   270,   270,   271,   272,   273,   273,   273,
     274,   274,   275,   276,   276,   276,   276,   276,   277,   277,
     277,   278,   278,   278,   278,   279,   280,   281,   282,   283,
     283,   283,   283,   284,   284,   284,   284,   285,   285,   286,
     287,   288,   289,   289,   289,   290,   290,   290,   290,   291,
     292,   293,   294,   295,   295,   295,   295,   296,   296,   297,
     298,   299,   299,   299,   299,   300,   300,   301,   302,   303,
     303,   303
  };

  const signed char
  BisonImplementation::yyr2_[] =
  {
       0,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     3,     3,     3,     3,     1,     3,     3,
       3,     2,     3,     1,     2,     5,     5,     5,     5,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     3,
       2,     8,     4,     8,     4,     8,     4,     8,     4,     8,
       8,     8,     1,     1,     1,     3,     4,     5,     7,     5,
       7,     7,     1,     1,     1,     2,     4,     3,     3,     2,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     4,     6,     8,     1,     1,     1,     1,
       1,     6,     4,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       4,     4,     4,     5,     5,     5,     5,     6,     6,     6,
       6,     7,     7,     7,     7,     7,     8,     8,     8,     8,
       8,     9,     9,     9,     9,     9,     9,     1,     1,     1,
       1,     1,     1,     7,     7,     7,     7,     7,     7,     7,
       7,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     6,     6,
       2,     2,     1,     4,     4,     4,     4,     4,     5,     5,
       5,     1,     1,     1,     1,     1,     2,     2,     3,     4,
       4,     4,     4,     5,     5,     5,     5,     3,     3,     1,
       1,     1,     5,     5,     5,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     6,     6,     6,     6,     1,     1,     1,     2,     1,
       1,     1
  };




#if YYDEBUG
  const short
  BisonImplementation::yyrline_[] =
  {
       0,   440,   440,   445,   459,   462,   466,   470,   474,   478,
     482,   488,   491,   496,   500,   507,   511,   518,   523,   527,
     536,   539,   542,   549,   552,   557,   561,   568,   574,   581,
     585,   592,   593,   594,   597,   600,   609,   610,   611,   616,
     620,   629,   630,   633,   639,   640,   641,   642,   643,   646,
     652,   658,   664,   672,   676,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   705,   712,   719,   725,   726,   727,   728,
     731,   735,   739,   743,   747,   751,   757,   761,   765,   769,
     773,   777,   783,   787,   791,   797,   801,   807,   811,   818,
     822,   830,   838,   845,   853,   860,   868,   875,   883,   892,
     899,   904,   911,   912,   915,   924,   935,   943,   951,   959,
     964,   969,   978,   979,   982,   991,  1000,  1010,  1015,  1022,
    1031,  1035,  1044,  1045,  1046,  1047,  1048,  1051,  1055,  1059,
    1063,  1067,  1071,  1077,  1081,  1085,  1089,  1093,  1097,  1101,
    1105,  1109,  1115,  1116,  1117,  1120,  1124,  1128,  1132,  1136,
    1140,  1144,  1148,  1160,  1164,  1170,  1174,  1178,  1182,  1186,
    1190,  1196,  1197,  1200,  1203,  1208,  1214,  1217,  1222,  1228,
    1232,  1236,  1240,  1244,  1248,  1252,  1260,  1264,  1273,  1274,
    1275,  1278,  1282,  1286,  1292,  1296,  1300,  1306,  1310,  1314,
    1318,  1322,  1326,  1330,  1341,  1342,  1343,  1344,  1345,  1350,
    1351,  1352,  1357,  1358,  1361,  1366,  1371,  1377,  1385,  1390,
    1396,  1401,  1407,  1410,  1415,  1423,  1424,  1425,  1426,  1427,
    1428,  1431,  1437,  1443,  1444,  1449,  1450,  1453,  1459,  1465,
    1473,  1474,  1477,  1478,  1481,  1482,  1485,  1490,  1497,  1498,
    1503,  1504,  1505,  1508,  1518,  1528,  1540,  1541,  1542,  1545,
    1549,  1555,  1561,  1569,  1570,  1573,  1579,  1591,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,  1599,  1600,  1603,  1607,  1614,
    1618,  1625,  1640,  1650,  1660,  1670,  1680,  1692,  1707,  1717,
    1727,  1737,  1747,  1759,  1768,  1778,  1788,  1798,  1808,  1820,
    1827,  1834,  1843,  1850,  1857,  1866,  1873,  1880,  1889,  1900,
    1908,  1916,  1926,  1934,  1942,  1950,  1962,  1975,  1983,  1991,
    2001,  2017,  2022,  2029,  2043,  2048,  2053,  2060,  2078,  2085,
    2092,  2101,  2119,  2126,  2133,  2140,  2149,  2168,  2176,  2184,
    2192,  2202,  2221,  2229,  2237,  2245,  2253,  2263,  2264,  2265,
    2266,  2267,  2268,  2271,  2281,  2288,  2295,  2304,  2314,  2321,
    2328,  2339,  2343,  2350,  2354,  2366,  2367,  2368,  2369,  2370,
    2375,  2376,  2379,  2382,  2383,  2386,  2395,  2404,  2411,  2416,
    2423,  2427,  2434,  2437,  2445,  2451,  2457,  2463,  2471,  2478,
    2483,  2492,  2493,  2494,  2495,  2498,  2507,  2516,  2522,  2533,
    2540,  2545,  2550,  2557,  2565,  2573,  2581,  2591,  2596,  2605,
    2611,  2617,  2625,  2629,  2634,  2643,  2644,  2645,  2646,  2649,
    2660,  2670,  2681,  2695,  2698,  2701,  2704,  2711,  2712,  2715,
    2718,  2725,  2728,  2733,  2738,  2747,  2748,  2751,  2760,  2771,
    2772,  2773
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


