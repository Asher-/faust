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

#include "global.hh"

#include "tlib/tree.hh"
#include "compiler/math_primitives/xtended.hh"
#include "compiler/block_diagram/boxes/boxes.hh"
#include "compiler/signals/prim2.hh"
#include "compiler/signals/signals.hh"
#include "compiler/errors/errormsg.hh"
#include "compiler/file_handling/sourcereader.hh"
#include "documentator/doc.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"

#include "string_substitution.hh"

#define YYMAXDEPTH	100000

extern char* 		yytext;
extern const char* 	yyfilename;
extern int 			yylineno;
extern int 			yyerr;

#include "compiler/parser/lexer/implementation.hh"
#undef yylex
#define yylex driver._lexer->lex




#include "faustparser.hh"


// Unqualified %code blocks.
 /* Faust code */
  #include "compiler/parser/type/driver.hh"



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
  Implementation::Implementation (Type::Driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      driver (driver_yyarg)
  {}

  Implementation::~Implementation ()
  {}

  Implementation::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Implementation::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Implementation::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Implementation::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Implementation::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Implementation::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Implementation::symbol_kind_type
  Implementation::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Implementation::stack_symbol_type::stack_symbol_type ()
  {}

  Implementation::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_list: // doc.list
      case symbol_kind::S_146_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_147_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_list: // expression.composition.list
      case symbol_kind::S_154_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_155_expression_composition_record: // expression.composition.record
      case symbol_kind::S_156_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_157_expression_composition_split: // expression.composition.split
      case symbol_kind::S_158_expression_environment: // expression.environment
      case symbol_kind::S_159_expression_infix: // expression.infix
      case symbol_kind::S_160_expression_infix_definitions_local: // expression.infix.definitions.local
      case symbol_kind::S_161_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_162_expression_infix_math: // expression.infix.math
      case symbol_kind::S_163_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_164_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_165_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_166_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_167_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_168_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_169_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_170_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_171_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_172_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_173_expression_lambda: // expression.lambda
      case symbol_kind::S_174_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_175_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_176_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_177_expression_letrec: // expression.letrec
      case symbol_kind::S_178_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_179_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_180_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_181_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_182_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_183_expression_library: // expression.library
      case symbol_kind::S_184_expression_math: // expression.math
      case symbol_kind::S_185_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_186_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_187_expression_math_signal: // expression.math.signal
      case symbol_kind::S_188_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_189_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_190_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_191_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_192_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_193_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_194_expression_parallel: // expression.parallel
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
      case symbol_kind::S_209_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_210_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_211_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_212_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_213_primitive_type_number: // primitive.type.number
      case symbol_kind::S_214_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_215_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_216_primitive_type_any: // primitive.type.any
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_219_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_220_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_221_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_222_primitive_type_list: // primitive.type.list
      case symbol_kind::S_223_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_224_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_225_primitive_ui: // primitive.ui
      case symbol_kind::S_226_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_227_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_228_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_229_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_230_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_231_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_232_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_233_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_234_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_235_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_236_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_237_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_238_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_239_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_240_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_241_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_243_statement_definition: // statement.definition
      case symbol_kind::S_244_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_245_statement_definition_function: // statement.definition.function
      case symbol_kind::S_246_statement_definition_substitution: // statement.definition.substitution
      case symbol_kind::S_247_statement_definition_with: // statement.definition.with
      case symbol_kind::S_248_statement_definition_error: // statement.definition.error
      case symbol_kind::S_249_statement_definition_list: // statement.definition.list
      case symbol_kind::S_250_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_251_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_252_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_253_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_254_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_255_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_256_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_257_statement_identifier: // statement.identifier
      case symbol_kind::S_258_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_259_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_260_statement_import: // statement.import
      case symbol_kind::S_261_statement_list: // statement.list
      case symbol_kind::S_262_statement_list_start: // statement.list.start
      case symbol_kind::S_263_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_264_statement_list_append: // statement.list.append
      case symbol_kind::S_265_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_270_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_271_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_272_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
        value.YY_MOVE_OR_COPY< Type::exp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_266_statement_math_precision: // statement.math.precision
      case symbol_kind::S_267_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_268_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_269_statement_math_precision_list_append: // statement.math.precision.list.append
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_DOT: // DOT
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
      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
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

  Implementation::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_list: // doc.list
      case symbol_kind::S_146_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_147_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_list: // expression.composition.list
      case symbol_kind::S_154_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_155_expression_composition_record: // expression.composition.record
      case symbol_kind::S_156_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_157_expression_composition_split: // expression.composition.split
      case symbol_kind::S_158_expression_environment: // expression.environment
      case symbol_kind::S_159_expression_infix: // expression.infix
      case symbol_kind::S_160_expression_infix_definitions_local: // expression.infix.definitions.local
      case symbol_kind::S_161_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_162_expression_infix_math: // expression.infix.math
      case symbol_kind::S_163_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_164_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_165_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_166_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_167_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_168_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_169_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_170_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_171_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_172_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_173_expression_lambda: // expression.lambda
      case symbol_kind::S_174_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_175_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_176_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_177_expression_letrec: // expression.letrec
      case symbol_kind::S_178_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_179_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_180_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_181_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_182_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_183_expression_library: // expression.library
      case symbol_kind::S_184_expression_math: // expression.math
      case symbol_kind::S_185_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_186_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_187_expression_math_signal: // expression.math.signal
      case symbol_kind::S_188_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_189_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_190_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_191_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_192_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_193_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_194_expression_parallel: // expression.parallel
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
      case symbol_kind::S_209_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_210_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_211_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_212_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_213_primitive_type_number: // primitive.type.number
      case symbol_kind::S_214_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_215_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_216_primitive_type_any: // primitive.type.any
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_219_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_220_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_221_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_222_primitive_type_list: // primitive.type.list
      case symbol_kind::S_223_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_224_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_225_primitive_ui: // primitive.ui
      case symbol_kind::S_226_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_227_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_228_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_229_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_230_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_231_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_232_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_233_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_234_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_235_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_236_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_237_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_238_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_239_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_240_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_241_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_243_statement_definition: // statement.definition
      case symbol_kind::S_244_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_245_statement_definition_function: // statement.definition.function
      case symbol_kind::S_246_statement_definition_substitution: // statement.definition.substitution
      case symbol_kind::S_247_statement_definition_with: // statement.definition.with
      case symbol_kind::S_248_statement_definition_error: // statement.definition.error
      case symbol_kind::S_249_statement_definition_list: // statement.definition.list
      case symbol_kind::S_250_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_251_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_252_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_253_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_254_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_255_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_256_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_257_statement_identifier: // statement.identifier
      case symbol_kind::S_258_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_259_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_260_statement_import: // statement.import
      case symbol_kind::S_261_statement_list: // statement.list
      case symbol_kind::S_262_statement_list_start: // statement.list.start
      case symbol_kind::S_263_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_264_statement_list_append: // statement.list.append
      case symbol_kind::S_265_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_270_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_271_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_272_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
        value.move< Type::exp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_148_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_266_statement_math_precision: // statement.math.precision
      case symbol_kind::S_267_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_268_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_269_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< int > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_DOT: // DOT
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
      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
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
  Implementation::stack_symbol_type&
  Implementation::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_list: // doc.list
      case symbol_kind::S_146_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_147_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_list: // expression.composition.list
      case symbol_kind::S_154_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_155_expression_composition_record: // expression.composition.record
      case symbol_kind::S_156_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_157_expression_composition_split: // expression.composition.split
      case symbol_kind::S_158_expression_environment: // expression.environment
      case symbol_kind::S_159_expression_infix: // expression.infix
      case symbol_kind::S_160_expression_infix_definitions_local: // expression.infix.definitions.local
      case symbol_kind::S_161_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_162_expression_infix_math: // expression.infix.math
      case symbol_kind::S_163_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_164_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_165_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_166_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_167_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_168_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_169_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_170_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_171_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_172_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_173_expression_lambda: // expression.lambda
      case symbol_kind::S_174_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_175_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_176_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_177_expression_letrec: // expression.letrec
      case symbol_kind::S_178_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_179_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_180_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_181_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_182_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_183_expression_library: // expression.library
      case symbol_kind::S_184_expression_math: // expression.math
      case symbol_kind::S_185_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_186_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_187_expression_math_signal: // expression.math.signal
      case symbol_kind::S_188_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_189_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_190_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_191_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_192_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_193_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_194_expression_parallel: // expression.parallel
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
      case symbol_kind::S_209_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_210_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_211_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_212_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_213_primitive_type_number: // primitive.type.number
      case symbol_kind::S_214_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_215_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_216_primitive_type_any: // primitive.type.any
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_219_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_220_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_221_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_222_primitive_type_list: // primitive.type.list
      case symbol_kind::S_223_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_224_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_225_primitive_ui: // primitive.ui
      case symbol_kind::S_226_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_227_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_228_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_229_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_230_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_231_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_232_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_233_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_234_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_235_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_236_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_237_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_238_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_239_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_240_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_241_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_243_statement_definition: // statement.definition
      case symbol_kind::S_244_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_245_statement_definition_function: // statement.definition.function
      case symbol_kind::S_246_statement_definition_substitution: // statement.definition.substitution
      case symbol_kind::S_247_statement_definition_with: // statement.definition.with
      case symbol_kind::S_248_statement_definition_error: // statement.definition.error
      case symbol_kind::S_249_statement_definition_list: // statement.definition.list
      case symbol_kind::S_250_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_251_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_252_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_253_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_254_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_255_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_256_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_257_statement_identifier: // statement.identifier
      case symbol_kind::S_258_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_259_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_260_statement_import: // statement.import
      case symbol_kind::S_261_statement_list: // statement.list
      case symbol_kind::S_262_statement_list_start: // statement.list.start
      case symbol_kind::S_263_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_264_statement_list_append: // statement.list.append
      case symbol_kind::S_265_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_270_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_271_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_272_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
        value.copy< Type::exp > (that.value);
        break;

      case symbol_kind::S_148_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_266_statement_math_precision: // statement.math.precision
      case symbol_kind::S_267_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_268_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_269_statement_math_precision_list_append: // statement.math.precision.list.append
        value.copy< int > (that.value);
        break;

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
      case symbol_kind::S_DOT: // DOT
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
      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
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

  Implementation::stack_symbol_type&
  Implementation::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_doc: // doc
      case symbol_kind::S_142_doc_equation: // doc.equation
      case symbol_kind::S_143_doc_diagram: // doc.diagram
      case symbol_kind::S_144_doc_notice: // doc.notice
      case symbol_kind::S_145_doc_list: // doc.list
      case symbol_kind::S_146_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_147_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_list: // expression.composition.list
      case symbol_kind::S_154_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_155_expression_composition_record: // expression.composition.record
      case symbol_kind::S_156_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_157_expression_composition_split: // expression.composition.split
      case symbol_kind::S_158_expression_environment: // expression.environment
      case symbol_kind::S_159_expression_infix: // expression.infix
      case symbol_kind::S_160_expression_infix_definitions_local: // expression.infix.definitions.local
      case symbol_kind::S_161_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_162_expression_infix_math: // expression.infix.math
      case symbol_kind::S_163_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_164_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_165_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_166_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_167_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_168_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_169_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_170_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_171_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_172_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_173_expression_lambda: // expression.lambda
      case symbol_kind::S_174_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_175_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_176_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_177_expression_letrec: // expression.letrec
      case symbol_kind::S_178_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_179_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_180_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_181_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_182_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_183_expression_library: // expression.library
      case symbol_kind::S_184_expression_math: // expression.math
      case symbol_kind::S_185_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_186_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_187_expression_math_signal: // expression.math.signal
      case symbol_kind::S_188_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_189_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_190_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_191_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_192_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_193_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_194_expression_parallel: // expression.parallel
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
      case symbol_kind::S_209_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_210_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_211_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_212_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_213_primitive_type_number: // primitive.type.number
      case symbol_kind::S_214_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_215_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_216_primitive_type_any: // primitive.type.any
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_219_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_220_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_221_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_222_primitive_type_list: // primitive.type.list
      case symbol_kind::S_223_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_224_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_225_primitive_ui: // primitive.ui
      case symbol_kind::S_226_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_227_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_228_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_229_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_230_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_231_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_232_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_233_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_234_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_235_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_236_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_237_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_238_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_239_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_240_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_241_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_243_statement_definition: // statement.definition
      case symbol_kind::S_244_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_245_statement_definition_function: // statement.definition.function
      case symbol_kind::S_246_statement_definition_substitution: // statement.definition.substitution
      case symbol_kind::S_247_statement_definition_with: // statement.definition.with
      case symbol_kind::S_248_statement_definition_error: // statement.definition.error
      case symbol_kind::S_249_statement_definition_list: // statement.definition.list
      case symbol_kind::S_250_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_251_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_252_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_253_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_254_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_255_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_256_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_257_statement_identifier: // statement.identifier
      case symbol_kind::S_258_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_259_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_260_statement_import: // statement.import
      case symbol_kind::S_261_statement_list: // statement.list
      case symbol_kind::S_262_statement_list_start: // statement.list.start
      case symbol_kind::S_263_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_264_statement_list_append: // statement.list.append
      case symbol_kind::S_265_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_270_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_271_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_272_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
        value.move< Type::exp > (that.value);
        break;

      case symbol_kind::S_148_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_266_statement_math_precision: // statement.math.precision
      case symbol_kind::S_267_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_268_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_269_statement_math_precision_list_append: // statement.math.precision.list.append
        value.move< int > (that.value);
        break;

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
      case symbol_kind::S_DOT: // DOT
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
      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
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
  Implementation::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Implementation::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  Implementation::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Implementation::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Implementation::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Implementation::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Implementation::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Implementation::debug_level_type
  Implementation::debug_level () const
  {
    return yydebug_;
  }

  void
  Implementation::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Implementation::state_type
  Implementation::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Implementation::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Implementation::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Implementation::operator() ()
  {
    return parse ();
  }

  int
  Implementation::parse ()
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
  yyla.location.begin.filename = yyla.location.end.filename = &driver._streamName;
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
      case symbol_kind::S_145_doc_list: // doc.list
      case symbol_kind::S_146_doc_attribute_list: // doc.attribute.list
      case symbol_kind::S_147_doc_attribute_definition: // doc.attribute.definition
      case symbol_kind::S_149_doc_metadata: // doc.metadata
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_151_expression_component: // expression.component
      case symbol_kind::S_152_expression_composition: // expression.composition
      case symbol_kind::S_153_expression_composition_list: // expression.composition.list
      case symbol_kind::S_154_expression_composition_mix: // expression.composition.mix
      case symbol_kind::S_155_expression_composition_record: // expression.composition.record
      case symbol_kind::S_156_expression_composition_sequence: // expression.composition.sequence
      case symbol_kind::S_157_expression_composition_split: // expression.composition.split
      case symbol_kind::S_158_expression_environment: // expression.environment
      case symbol_kind::S_159_expression_infix: // expression.infix
      case symbol_kind::S_160_expression_infix_definitions_local: // expression.infix.definitions.local
      case symbol_kind::S_161_expression_infix_environment_access: // expression.infix.environment.access
      case symbol_kind::S_162_expression_infix_math: // expression.infix.math
      case symbol_kind::S_163_expression_infix_math_algebra: // expression.infix.math.algebra
      case symbol_kind::S_164_expression_infix_math_comparison: // expression.infix.math.comparison
      case symbol_kind::S_165_expression_infix_math_logic: // expression.infix.math.logic
      case symbol_kind::S_166_expression_infix_math_shift: // expression.infix.math.shift
      case symbol_kind::S_167_expression_infix_prefix: // expression.infix.prefix
      case symbol_kind::S_168_expression_infix_signal_delay: // expression.infix.signal.delay
      case symbol_kind::S_169_expression_iterate_parallel: // expression.iterate.parallel
      case symbol_kind::S_170_expression_iterate_sequence: // expression.iterate.sequence
      case symbol_kind::S_171_expression_iterate_sum: // expression.iterate.sum
      case symbol_kind::S_172_expression_iterate_product: // expression.iterate.product
      case symbol_kind::S_173_expression_lambda: // expression.lambda
      case symbol_kind::S_174_expression_lambda_params: // expression.lambda.params
      case symbol_kind::S_175_expression_lambda_params_start: // expression.lambda.params.start
      case symbol_kind::S_176_expression_lambda_params_append: // expression.lambda.params.append
      case symbol_kind::S_177_expression_letrec: // expression.letrec
      case symbol_kind::S_178_expression_letrec_list: // expression.letrec.list
      case symbol_kind::S_179_expression_letrec_list_start: // expression.letrec.list.start
      case symbol_kind::S_180_expression_letrec_list_append: // expression.letrec.list.append
      case symbol_kind::S_181_expression_letrec_equation: // expression.letrec.equation
      case symbol_kind::S_182_expression_letrec_equation_name: // expression.letrec.equation.name
      case symbol_kind::S_183_expression_library: // expression.library
      case symbol_kind::S_184_expression_math: // expression.math
      case symbol_kind::S_185_expression_math_comparison: // expression.math.comparison
      case symbol_kind::S_186_expression_math_rounding: // expression.math.rounding
      case symbol_kind::S_187_expression_math_signal: // expression.math.signal
      case symbol_kind::S_188_expression_math_signal_algebra: // expression.math.signal.algebra
      case symbol_kind::S_189_expression_math_signal_shift: // expression.math.signal.shift
      case symbol_kind::S_190_expression_math_signal_power: // expression.math.signal.power
      case symbol_kind::S_191_expression_math_scalar: // expression.math.scalar
      case symbol_kind::S_192_expression_math_trigonometry: // expression.math.trigonometry
      case symbol_kind::S_193_expression_parenthesis: // expression.parenthesis
      case symbol_kind::S_194_expression_parallel: // expression.parallel
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
      case symbol_kind::S_209_primitive_type_number_list: // primitive.type.number.list
      case symbol_kind::S_210_primitive_type_number_list_member: // primitive.type.number.list.member
      case symbol_kind::S_211_primitive_type_number_list_start: // primitive.type.number.list.start
      case symbol_kind::S_212_primitive_type_number_list_append: // primitive.type.number.list.append
      case symbol_kind::S_213_primitive_type_number: // primitive.type.number
      case symbol_kind::S_214_primitive_type_number_int: // primitive.type.number.int
      case symbol_kind::S_215_primitive_type_number_float: // primitive.type.number.float
      case symbol_kind::S_216_primitive_type_any: // primitive.type.any
      case symbol_kind::S_217_primitive_signal_route: // primitive.signal.route
      case symbol_kind::S_218_primitive_signal_source: // primitive.signal.source
      case symbol_kind::S_219_primitive_signal_source_table: // primitive.signal.source.table
      case symbol_kind::S_220_primitive_signal_source_soundfile: // primitive.signal.source.soundfile
      case symbol_kind::S_221_primitive_signal_source_waveform: // primitive.signal.source.waveform
      case symbol_kind::S_222_primitive_type_list: // primitive.type.list
      case symbol_kind::S_223_primitive_type_list_start: // primitive.type.list.start
      case symbol_kind::S_224_primitive_type_list_append: // primitive.type.list.append
      case symbol_kind::S_225_primitive_ui: // primitive.ui
      case symbol_kind::S_226_primitive_ui_button: // primitive.ui.button
      case symbol_kind::S_227_primitive_ui_checkbox: // primitive.ui.checkbox
      case symbol_kind::S_228_primitive_ui_vslider: // primitive.ui.vslider
      case symbol_kind::S_229_primitive_ui_hslider: // primitive.ui.hslider
      case symbol_kind::S_230_primitive_ui_nentry: // primitive.ui.nentry
      case symbol_kind::S_231_primitive_ui_vgroup: // primitive.ui.vgroup
      case symbol_kind::S_232_primitive_ui_hgroup: // primitive.ui.hgroup
      case symbol_kind::S_233_primitive_ui_tgroup: // primitive.ui.tgroup
      case symbol_kind::S_234_primitive_ui_vbargraph: // primitive.ui.vbargraph
      case symbol_kind::S_235_primitive_ui_hbargraph: // primitive.ui.hbargraph
      case symbol_kind::S_236_primitive_foreign_function: // primitive.foreign.function
      case symbol_kind::S_237_primitive_foreign_function_signature: // primitive.foreign.function.signature
      case symbol_kind::S_238_primitive_foreign_constant: // primitive.foreign.constant
      case symbol_kind::S_239_primitive_foreign_variable: // primitive.foreign.variable
      case symbol_kind::S_240_primitive_signal_inputs: // primitive.signal.inputs
      case symbol_kind::S_241_primitive_signal_outputs: // primitive.signal.outputs
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_243_statement_definition: // statement.definition
      case symbol_kind::S_244_statement_definition_function_incomplete: // statement.definition.function.incomplete
      case symbol_kind::S_245_statement_definition_function: // statement.definition.function
      case symbol_kind::S_246_statement_definition_substitution: // statement.definition.substitution
      case symbol_kind::S_247_statement_definition_with: // statement.definition.with
      case symbol_kind::S_248_statement_definition_error: // statement.definition.error
      case symbol_kind::S_249_statement_definition_list: // statement.definition.list
      case symbol_kind::S_250_statement_definition_list_start: // statement.definition.list.start
      case symbol_kind::S_251_statement_definition_list_start_qualified: // statement.definition.list.start.qualified
      case symbol_kind::S_252_statement_definition_list_append: // statement.definition.list.append
      case symbol_kind::S_253_statement_definition_list_append_qualified: // statement.definition.list.append.qualified
      case symbol_kind::S_254_statement_declare_metadata: // statement.declare.metadata
      case symbol_kind::S_255_statement_declare_feature_metadata: // statement.declare.feature.metadata
      case symbol_kind::S_256_statement_declare_doc: // statement.declare.doc
      case symbol_kind::S_257_statement_identifier: // statement.identifier
      case symbol_kind::S_258_statement_identifier_box: // statement.identifier.box
      case symbol_kind::S_259_statement_identifier_waveform: // statement.identifier.waveform
      case symbol_kind::S_260_statement_import: // statement.import
      case symbol_kind::S_261_statement_list: // statement.list
      case symbol_kind::S_262_statement_list_start: // statement.list.start
      case symbol_kind::S_263_statement_list_start_qualified: // statement.list.start.qualified
      case symbol_kind::S_264_statement_list_append: // statement.list.append
      case symbol_kind::S_265_statement_list_append_qualified: // statement.list.append.qualified
      case symbol_kind::S_270_statement_signal_pattern_rule_list: // statement.signal.pattern.rule.list
      case symbol_kind::S_271_statement_signal_pattern_rule_list_start: // statement.signal.pattern.rule.list.start
      case symbol_kind::S_272_statement_signal_pattern_rule_list_append: // statement.signal.pattern.rule.list.append
      case symbol_kind::S_273_statement_signal_pattern_rule: // statement.signal.pattern.rule
        yylhs.value.emplace< Type::exp > ();
        break;

      case symbol_kind::S_148_doc_attribute_value: // doc.attribute.value
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
      case symbol_kind::S_266_statement_math_precision: // statement.math.precision
      case symbol_kind::S_267_statement_math_precision_list: // statement.math.precision.list
      case symbol_kind::S_268_statement_math_precision_list_start: // statement.math.precision.list.start
      case symbol_kind::S_269_statement_math_precision_list_append: // statement.math.precision.list.append
        yylhs.value.emplace< int > ();
        break;

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
      case symbol_kind::S_DOT: // DOT
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
      case symbol_kind::S_WITH: // WITH
      case symbol_kind::S_LETREC: // LETREC
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
  case 2: // program: statement.list
                               {
			yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > ();
			gGlobal->gResult = formatDefinitions(yylhs.value.as < Type::exp > ());
		}
    break;

  case 3: // program: %empty
                { yylhs.value.as < Type::exp > () = gGlobal->nil; }
    break;

  case 4: // doc: doc.text
                         {
			yylhs.value.as < Type::exp > () = docTxt(yystack_[0].value.as < std::string > ().c_str());
//			delete $[doc.text];
		}
    break;

  case 5: // doc: doc.equation
                 { yylhs.value.as < Type::exp > () = docEqn(yystack_[0].value.as < Type::exp > ()); }
    break;

  case 6: // doc: doc.diagram
                { yylhs.value.as < Type::exp > () = docDgm(yystack_[0].value.as < Type::exp > ()); }
    break;

  case 7: // doc: doc.notice
               { yylhs.value.as < Type::exp > () = docNtc(); }
    break;

  case 8: // doc: doc.list
             { yylhs.value.as < Type::exp > () = docLst(); }
    break;

  case 9: // doc: doc.metadata
                 { yylhs.value.as < Type::exp > () = docMtd(yystack_[0].value.as < Type::exp > ()); }
    break;

  case 10: // doc: %empty
                      { yylhs.value.as < Type::exp > () = gGlobal->nil; }
    break;

  case 11: // doc.text: DOCCHAR
              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
    break;

  case 12: // doc.text: doc.text DOCCHAR
                              { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > ().append(yytext); }
    break;

  case 13: // doc.equation: BEQN expression EEQN
                           { yylhs.value.as < Type::exp > () = yystack_[1].value.as < Type::exp > (); }
    break;

  case 14: // doc.diagram: BDGM expression EDGM
                           { yylhs.value.as < Type::exp > () = yystack_[1].value.as < Type::exp > (); }
    break;

  case 15: // doc.notice: NOTICE
             { }
    break;

  case 16: // doc.list: BLST doc.attribute.list ELST
                                   { }
    break;

  case 17: // doc.list: BLST ELST
                                 { }
    break;

  case 18: // doc.attribute.list: doc.attribute.definition
                                 {}
    break;

  case 19: // doc.attribute.list: doc.attribute.list doc.attribute.definition
                                                    { }
    break;

  case 20: // doc.attribute.definition: LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ
                                                            {
          gGlobal->gLstDependenciesSwitch = yystack_[1].value.as < bool > ();
        }
    break;

  case 21: // doc.attribute.definition: LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ
                                                        {
          gGlobal->gStripDocSwitch = yystack_[1].value.as < bool > ();
          gGlobal->gStripDocSwitch ? gGlobal->gStripDocSwitch=false
                                   : gGlobal->gStripDocSwitch=true;
        }
    break;

  case 22: // doc.attribute.definition: LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ
                                                           {
          gGlobal->gLstDistributedSwitch = yystack_[1].value.as < bool > ();
        }
    break;

  case 23: // doc.attribute.value: LSTTRUE
                { yylhs.value.as < bool > () = true; }
    break;

  case 24: // doc.attribute.value: LSTFALSE
                 { yylhs.value.as < bool > () = false; }
    break;

  case 25: // doc.metadata: BMETADATA statement.identifier EMETADATA
                                                       { yylhs.value.as < Type::exp > () = yystack_[1].value.as < Type::exp > (); }
    break;

  case 26: // expression: statement.definition.with
                { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 27: // expression: expression.letrec
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 28: // expression: expression.parallel
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 29: // expression: expression.composition
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 30: // expression.component: COMPONENT LPAR primitive.string.unquoted RPAR
                                                    { yylhs.value.as < Type::exp > () = boxComponent(yystack_[1].value.as < Type::exp > ()); }
    break;

  case 31: // expression.composition: expression.composition.sequence
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 32: // expression.composition: expression.composition.split
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 33: // expression.composition: expression.composition.mix
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 34: // expression.composition: expression.composition.record
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 35: // expression.composition: expression.infix
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 36: // expression.composition.list: expression.composition
                               { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),gGlobal->nil); }
    break;

  case 37: // expression.composition.list: expression.composition.list COMMA expression.composition
                                                                              { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),yystack_[2].value.as < Type::exp > ()); }
    break;

  case 38: // expression.composition.mix: expression.composition MIX expression.composition
                                                                    { yylhs.value.as < Type::exp > () = boxMerge(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()); }
    break;

  case 39: // expression.composition.record: expression.composition REC expression.composition
                                                                    { yylhs.value.as < Type::exp > () = boxRec(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()); }
    break;

  case 40: // expression.composition.sequence: expression.composition SEQ expression.composition
                                                                    { yylhs.value.as < Type::exp > () = boxSeq(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()); }
    break;

  case 41: // expression.composition.split: expression.composition SPLIT expression.composition
                                                                      { yylhs.value.as < Type::exp > () = boxSplit(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()); }
    break;

  case 42: // expression.environment: ENVIRONMENT LBRAQ statement.list RBRAQ
                                             {
        yylhs.value.as < Type::exp > () = boxWithLocalDef(boxEnvironment(),formatDefinitions(yystack_[1].value.as < Type::exp > ()));
      }
    break;

  case 43: // expression.infix: expression.infix.definitions.local
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 44: // expression.infix: expression.infix.environment.access
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 45: // expression.infix: expression.infix.math
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 46: // expression.infix: expression.infix.signal.delay
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 47: // expression.infix: expression.infix.prefix
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 48: // expression.infix: expression.component
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 49: // expression.infix: expression.environment
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 50: // expression.infix: expression.iterate.parallel
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 51: // expression.infix: expression.iterate.sequence
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 52: // expression.infix: expression.iterate.sum
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 53: // expression.infix: expression.iterate.product
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 54: // expression.infix: expression.lambda
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 55: // expression.infix: expression.library
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 56: // expression.infix: expression.math
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 57: // expression.infix: expression.parenthesis
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 58: // expression.infix: expression.signal
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 59: // expression.infix: statement.identifier.box
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 60: // expression.infix: primitive
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 61: // expression.infix.definitions.local: expression.infix LCROC statement.definition.list RCROC
                                                                        {
        yylhs.value.as < Type::exp > () = boxModifLocalDef(yystack_[3].value.as < Type::exp > (),formatDefinitions(yystack_[1].value.as < Type::exp > ()));
      }
    break;

  case 62: // expression.infix.environment.access: expression.infix DOT statement.identifier.box
                                                              { yylhs.value.as < Type::exp > () = boxAccess(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()); }
    break;

  case 63: // expression.infix.math: expression.infix.math.algebra
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 64: // expression.infix.math: expression.infix.math.comparison
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 65: // expression.infix.math: expression.infix.math.logic
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 66: // expression.infix.math: expression.infix.math.shift
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 67: // expression.infix.math.algebra: expression.infix ADD expression.infix
                                                        { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigAdd)); }
    break;

  case 68: // expression.infix.math.algebra: expression.infix SUB expression.infix
                                                        { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigSub)); }
    break;

  case 69: // expression.infix.math.algebra: expression.infix MUL expression.infix
                                                        { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigMul)); }
    break;

  case 70: // expression.infix.math.algebra: expression.infix DIV expression.infix
                                                        { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigDiv)); }
    break;

  case 71: // expression.infix.math.algebra: expression.infix MOD expression.infix
                                                        { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigRem)); }
    break;

  case 72: // expression.infix.math.algebra: expression.infix POWOP expression.infix
                                                        {
        yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),gGlobal->gPowPrim->box());
      }
    break;

  case 73: // expression.infix.math.comparison: expression.infix LT expression.infix
                                                     { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigLT)); }
    break;

  case 74: // expression.infix.math.comparison: expression.infix LE expression.infix
                                                     { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigLE)); }
    break;

  case 75: // expression.infix.math.comparison: expression.infix GT expression.infix
                                                     { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigGT)); }
    break;

  case 76: // expression.infix.math.comparison: expression.infix GE expression.infix
                                                     { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigGE)); }
    break;

  case 77: // expression.infix.math.comparison: expression.infix EQ expression.infix
                                                     { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigEQ)); }
    break;

  case 78: // expression.infix.math.comparison: expression.infix NE expression.infix
                                                     { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigNE)); }
    break;

  case 79: // expression.infix.math.logic: expression.infix AND expression.infix
                                                      { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigAND)); }
    break;

  case 80: // expression.infix.math.logic: expression.infix OR expression.infix
                                                      { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigOR)); }
    break;

  case 81: // expression.infix.math.logic: expression.infix XOR expression.infix
                                                      { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigXOR)); }
    break;

  case 82: // expression.infix.math.shift: expression.infix LSH expression.infix
                                                      { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigLeftShift)); }
    break;

  case 83: // expression.infix.math.shift: expression.infix RSH expression.infix
                                                      {
        yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigARightShift));
      }
    break;

  case 84: // expression.infix.prefix: expression.infix LPAR expression.composition.list RPAR
                                                                   { yylhs.value.as < Type::exp > () = buildBoxAppl(yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ()); }
    break;

  case 85: // expression.infix.signal.delay: expression.infix FDELAY expression.infix
                                                         { yylhs.value.as < Type::exp > () = boxSeq(boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigDelay)); }
    break;

  case 86: // expression.infix.signal.delay: expression.infix DELAY1
                                   { yylhs.value.as < Type::exp > () = boxSeq(yystack_[1].value.as < Type::exp > (),boxPrim1(sigDelay1)); }
    break;

  case 87: // expression.iterate.parallel: ITERATE_PARALLEL LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR
                                                                                                        {
        yylhs.value.as < Type::exp > () = boxIPar(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
      }
    break;

  case 88: // expression.iterate.sequence: ISEQ LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR
                                                                                            {
        yylhs.value.as < Type::exp > () = boxISeq(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
      }
    break;

  case 89: // expression.iterate.sum: ISUM LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR
                                                                                            {
        yylhs.value.as < Type::exp > () = boxISum(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
      }
    break;

  case 90: // expression.iterate.product: IPROD LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR
                                                                                             {
        yylhs.value.as < Type::exp > () = boxIProd(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
      }
    break;

  case 91: // expression.lambda: LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR
                                                                         {
        yylhs.value.as < Type::exp > () = buildBoxAbstr(yystack_[5].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
      }
    break;

  case 92: // expression.lambda.params: expression.lambda.params.start
                { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 93: // expression.lambda.params: expression.lambda.params.append
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 94: // expression.lambda.params.start: statement.identifier.box
                                 { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),gGlobal->nil); }
    break;

  case 95: // expression.lambda.params.append: expression.lambda.params COMMA statement.identifier.box
                                                                             { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),yystack_[2].value.as < Type::exp > ()); }
    break;

  case 96: // expression.letrec: expression LETREC LBRAQ RBRAQ
                                                                          {
			yylhs.value.as < Type::exp > () = boxWithRecDef(yystack_[3].value.as < Type::exp > (),formatDefinitions(gGlobal->nil), gGlobal->nil);
		}
    break;

  case 97: // expression.letrec: expression LETREC LBRAQ expression.letrec.list RBRAQ
                                                              {
			yylhs.value.as < Type::exp > () = boxWithRecDef(yystack_[4].value.as < Type::exp > (),formatDefinitions(yystack_[1].value.as < Type::exp > ()), gGlobal->nil);
		}
    break;

  case 98: // expression.letrec: expression LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ
                                                                                              {
			yylhs.value.as < Type::exp > () = boxWithRecDef(yystack_[6].value.as < Type::exp > (),formatDefinitions(yystack_[3].value.as < Type::exp > ()),formatDefinitions(yystack_[3].value.as < Type::exp > ()));
		}
    break;

  case 99: // expression.letrec.list: expression.letrec.list.start
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 100: // expression.letrec.list: expression.letrec.list.append
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 101: // expression.letrec.list.start: expression.letrec.equation
                                         { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (), gGlobal->nil); }
    break;

  case 102: // expression.letrec.list.append: expression.letrec.list expression.letrec.equation
                                                                       { yylhs.value.as < Type::exp > () = cons (yystack_[0].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ()); }
    break;

  case 103: // expression.letrec.equation: expression.letrec.equation.name DEF expression ENDDEF
                                                                      {
        yylhs.value.as < Type::exp > () = cons(yystack_[3].value.as < Type::exp > (),cons(gGlobal->nil,yystack_[1].value.as < Type::exp > ()));
        setDefProp(yystack_[3].value.as < Type::exp > (), yyfilename, yylineno);
      }
    break;

  case 104: // expression.letrec.equation: error ENDDEF
                   { yylhs.value.as < Type::exp > () = gGlobal->nil; yyerr++; }
    break;

  case 105: // expression.letrec.equation.name: DELAY1 statement.identifier.box
                                        { yylhs.value.as < Type::exp > ()=yystack_[0].value.as < Type::exp > (); }
    break;

  case 106: // expression.library: LIBRARY LPAR primitive.string.unquoted RPAR
                                                  { yylhs.value.as < Type::exp > () = boxLibrary(yystack_[1].value.as < Type::exp > ()); }
    break;

  case 107: // expression.math: expression.math.signal
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 108: // expression.math: expression.math.scalar
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 109: // expression.math: expression.math.comparison
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 110: // expression.math: expression.math.trigonometry
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 111: // expression.math: expression.math.rounding
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 112: // expression.math.comparison: LT
           { yylhs.value.as < Type::exp > () = boxPrim2(sigLT); }
    break;

  case 113: // expression.math.comparison: LE
           { yylhs.value.as < Type::exp > () = boxPrim2(sigLE); }
    break;

  case 114: // expression.math.comparison: GT
           { yylhs.value.as < Type::exp > () = boxPrim2(sigGT); }
    break;

  case 115: // expression.math.comparison: GE
           { yylhs.value.as < Type::exp > () = boxPrim2(sigGE); }
    break;

  case 116: // expression.math.comparison: EQ
           { yylhs.value.as < Type::exp > () = boxPrim2(sigEQ); }
    break;

  case 117: // expression.math.comparison: NE
           { yylhs.value.as < Type::exp > () = boxPrim2(sigNE); }
    break;

  case 118: // expression.math.rounding: ABS
              { yylhs.value.as < Type::exp > () = gGlobal->gAbsPrim->box(); }
    break;

  case 119: // expression.math.rounding: MIN
              { yylhs.value.as < Type::exp > () = gGlobal->gMinPrim->box(); }
    break;

  case 120: // expression.math.rounding: MAX
              { yylhs.value.as < Type::exp > () = gGlobal->gMaxPrim->box(); }
    break;

  case 121: // expression.math.rounding: FLOOR
                { yylhs.value.as < Type::exp > () = gGlobal->gFloorPrim->box(); }
    break;

  case 122: // expression.math.rounding: CEIL
               { yylhs.value.as < Type::exp > () = gGlobal->gCeilPrim->box(); }
    break;

  case 123: // expression.math.rounding: ASSERTBOUNDS
                       { yylhs.value.as < Type::exp > () = boxPrim3(sigAssertBounds);}
    break;

  case 124: // expression.math.rounding: LOWEST
                 { yylhs.value.as < Type::exp > () = boxPrim1(sigLowest);}
    break;

  case 125: // expression.math.rounding: HIGHEST
                  { yylhs.value.as < Type::exp > () = boxPrim1(sigHighest);}
    break;

  case 126: // expression.math.rounding: RINT
               { yylhs.value.as < Type::exp > () = gGlobal->gRintPrim->box(); }
    break;

  case 127: // expression.math.signal: expression.math.signal.algebra
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 128: // expression.math.signal: expression.math.signal.shift
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 129: // expression.math.signal: expression.math.signal.power
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 130: // expression.math.signal.algebra: ADD
              { yylhs.value.as < Type::exp > () = boxPrim2(sigAdd); }
    break;

  case 131: // expression.math.signal.algebra: SUB
              { yylhs.value.as < Type::exp > () = boxPrim2(sigSub); }
    break;

  case 132: // expression.math.signal.algebra: MUL
              { yylhs.value.as < Type::exp > () = boxPrim2(sigMul); }
    break;

  case 133: // expression.math.signal.algebra: DIV
              { yylhs.value.as < Type::exp > () = boxPrim2(sigDiv); }
    break;

  case 134: // expression.math.signal.algebra: MOD
              { yylhs.value.as < Type::exp > () = boxPrim2(sigRem); }
    break;

  case 135: // expression.math.signal.algebra: FMOD
               { yylhs.value.as < Type::exp > () = gGlobal->gFmodPrim->box(); }
    break;

  case 136: // expression.math.signal.algebra: REMAINDER
                    { yylhs.value.as < Type::exp > () = gGlobal->gRemainderPrim->box(); }
    break;

  case 137: // expression.math.signal.algebra: SUB statement.identifier.box
                                       { yylhs.value.as < Type::exp > () = boxSeq(boxPar(boxInt(0),yystack_[0].value.as < Type::exp > ()),boxPrim2(sigSub)); }
    break;

  case 138: // expression.math.signal.shift: LSH
              { yylhs.value.as < Type::exp > () = boxPrim2(sigLeftShift); }
    break;

  case 139: // expression.math.signal.shift: RSH
              { yylhs.value.as < Type::exp > () = boxPrim2(sigARightShift); }
    break;

  case 140: // expression.math.signal.power: EXP
              { yylhs.value.as < Type::exp > () = gGlobal->gExpPrim->box(); }
    break;

  case 141: // expression.math.signal.power: LOG
              { yylhs.value.as < Type::exp > () = gGlobal->gLogPrim->box(); }
    break;

  case 142: // expression.math.signal.power: LOG10
                { yylhs.value.as < Type::exp > () = gGlobal->gLog10Prim->box(); }
    break;

  case 143: // expression.math.signal.power: POWOP
                { yylhs.value.as < Type::exp > () = gGlobal->gPowPrim->box(); }
    break;

  case 144: // expression.math.signal.power: POWFUN
                 { yylhs.value.as < Type::exp > () = gGlobal->gPowPrim->box(); }
    break;

  case 145: // expression.math.signal.power: SQRT
               { yylhs.value.as < Type::exp > () = gGlobal->gSqrtPrim->box(); }
    break;

  case 146: // expression.math.scalar: ADD INT
                  { yylhs.value.as < Type::exp > () = boxInt(str2int(yytext)); }
    break;

  case 147: // expression.math.scalar: ADD FLOAT
                    { yylhs.value.as < Type::exp > () = boxReal(yystack_[0].value.as < float > ()); }
    break;

  case 148: // expression.math.scalar: SUB INT
                  { yylhs.value.as < Type::exp > () = boxInt ( -yystack_[0].value.as < int > () ); }
    break;

  case 149: // expression.math.scalar: SUB FLOAT
                    { yylhs.value.as < Type::exp > () = boxReal( -yystack_[0].value.as < float > () ); }
    break;

  case 150: // expression.math.trigonometry: ACOS
               { yylhs.value.as < Type::exp > () = gGlobal->gAcosPrim->box(); }
    break;

  case 151: // expression.math.trigonometry: ASIN
               { yylhs.value.as < Type::exp > () = gGlobal->gAsinPrim->box(); }
    break;

  case 152: // expression.math.trigonometry: ATAN
               { yylhs.value.as < Type::exp > () = gGlobal->gAtanPrim->box(); }
    break;

  case 153: // expression.math.trigonometry: ATAN2
                { yylhs.value.as < Type::exp > () = gGlobal->gAtan2Prim->box(); }
    break;

  case 154: // expression.math.trigonometry: COS
              { yylhs.value.as < Type::exp > () = gGlobal->gCosPrim->box(); }
    break;

  case 155: // expression.math.trigonometry: SIN
              { yylhs.value.as < Type::exp > () = gGlobal->gSinPrim->box(); }
    break;

  case 156: // expression.math.trigonometry: TAN
              { yylhs.value.as < Type::exp > () = gGlobal->gTanPrim->box(); }
    break;

  case 157: // expression.parenthesis: LPAR expression RPAR
                         { yylhs.value.as < Type::exp > () = yystack_[1].value.as < Type::exp > (); }
    break;

  case 158: // expression.parallel: expression COMMA expression
                                            {
        yylhs.value.as < Type::exp > () = boxPar(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ());
      }
    break;

  case 159: // expression.signal: expression.signal.control
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 160: // expression.signal: expression.signal.delay
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 161: // expression.signal: expression.signal.logic
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 162: // expression.signal.control: ATTACH
               { yylhs.value.as < Type::exp > () = boxPrim2(sigAttach); }
    break;

  case 163: // expression.signal.control: ENABLE
               { yylhs.value.as < Type::exp > () = boxPrim2(sigEnable); }
    break;

  case 164: // expression.signal.control: CONTROL
                { yylhs.value.as < Type::exp > () = boxPrim2(sigControl); }
    break;

  case 165: // expression.signal.delay: MEM
            { yylhs.value.as < Type::exp > () = boxPrim1(sigDelay1); }
    break;

  case 166: // expression.signal.delay: PREFIX
               { yylhs.value.as < Type::exp > () = boxPrim2(sigPrefix); }
    break;

  case 167: // expression.signal.delay: FDELAY
               { yylhs.value.as < Type::exp > () = boxPrim2(sigDelay); }
    break;

  case 168: // expression.signal.logic: AND
            { yylhs.value.as < Type::exp > () = boxPrim2(sigAND); }
    break;

  case 169: // expression.signal.logic: OR
           { yylhs.value.as < Type::exp > () = boxPrim2(sigOR); }
    break;

  case 170: // expression.signal.logic: XOR
            { yylhs.value.as < Type::exp > () = boxPrim2(sigXOR); }
    break;

  case 171: // expression.signal.logic: SELECT2
                { yylhs.value.as < Type::exp > () = boxPrim3(sigSelect2); }
    break;

  case 172: // expression.signal.logic: SELECT3
                { yylhs.value.as < Type::exp > () = boxPrim4(sigSelect3); }
    break;

  case 173: // expression.signal.logic: CASE LBRAQ statement.signal.pattern.rule.list RBRAQ
                                                            { yylhs.value.as < Type::exp > () = boxCase(checkRulelist(yystack_[1].value.as < Type::exp > ())); }
    break;

  case 174: // primitive: primitive.foreign
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 175: // primitive: primitive.number
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 176: // primitive: primitive.type.number
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 177: // primitive: primitive.signal
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 178: // primitive: primitive.ui
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 179: // primitive.foreign: primitive.foreign.constant
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 180: // primitive.foreign: primitive.foreign.function
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 181: // primitive.foreign: primitive.foreign.variable
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 182: // primitive.number: INT
          { yylhs.value.as < Type::exp > () = boxInt(str2int(yytext)); }
    break;

  case 183: // primitive.number: FLOAT
            { yylhs.value.as < Type::exp > () = boxReal(atof(yytext)); }
    break;

  case 184: // primitive.string.quoted: STRING
             { yylhs.value.as < Type::exp > () = tree(yytext); }
    break;

  case 185: // primitive.string.unquoted: STRING
             { yylhs.value.as < Type::exp > () = unquote(yytext); }
    break;

  case 186: // primitive.string.tag: STRING
             { yylhs.value.as < Type::exp > () = tree(yytext); }
    break;

  case 187: // primitive.string.tag: TAGSTRING
                { yylhs.value.as < Type::exp > () = tree(yytext); }
    break;

  case 188: // primitive.signal: primitive.signal.inputs
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 189: // primitive.signal: primitive.signal.input.implicit
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 190: // primitive.signal: primitive.signal.input.terminate
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 191: // primitive.signal: primitive.signal.outputs
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 192: // primitive.signal: primitive.signal.route
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 193: // primitive.signal: primitive.signal.source
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 194: // primitive.signal.input.implicit: WIRE
           { yylhs.value.as < Type::exp > () = boxWire(); }
    break;

  case 195: // primitive.signal.input.terminate: CUT
          { yylhs.value.as < Type::exp > () = boxCut(); }
    break;

  case 196: // primitive.type: primitive.type.number
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 197: // primitive.type: primitive.type.any
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 198: // primitive.type.number.list: primitive.type.number.list.start
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 199: // primitive.type.number.list: primitive.type.number.list.append
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 200: // primitive.type.number.list.member: primitive.number
                           {
            gGlobal->gWaveForm.push_back(yystack_[0].value.as < Type::exp > ());
          }
    break;

  case 201: // primitive.type.number.list.member: expression.math.scalar
                                 {
            gGlobal->gWaveForm.push_back(yystack_[0].value.as < Type::exp > ());
          }
    break;

  case 202: // primitive.type.number.list.start: primitive.type.number.list.member
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 203: // primitive.type.number.list.append: primitive.type.number.list COMMA primitive.type.number.list.member
          { yylhs.value.as < Type::exp > () = yystack_[2].value.as < Type::exp > (); }
    break;

  case 204: // primitive.type.number: primitive.type.number.int
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 205: // primitive.type.number: primitive.type.number.float
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 206: // primitive.type.number.int: INTCAST
                  { yylhs.value.as < Type::exp > () = boxPrim1(sigIntCast); }
    break;

  case 207: // primitive.type.number.float: FLOATCAST
                    { yylhs.value.as < Type::exp > () = boxPrim1(sigFloatCast); }
    break;

  case 208: // primitive.type.any: ANYCAST
                { yylhs.value.as < Type::exp > () = tree(2); }
    break;

  case 209: // primitive.signal.route: ROUTE LPAR expression.composition COMMA expression.composition RPAR
                                                                                              {
          yylhs.value.as < Type::exp > () = boxRoute(yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > (), boxPar(boxInt(0),boxInt(0)));
        }
    break;

  case 210: // primitive.signal.route: ROUTE LPAR expression.composition COMMA expression.composition COMMA expression RPAR
                                                                                                         {
          yylhs.value.as < Type::exp > () = boxRoute(yystack_[5].value.as < Type::exp > (), yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 211: // primitive.signal.source: primitive.signal.source.waveform
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 212: // primitive.signal.source: primitive.signal.source.soundfile
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 213: // primitive.signal.source: primitive.signal.source.table
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 214: // primitive.signal.source.table: RDTBL
                { yylhs.value.as < Type::exp > () = boxPrim3(sigReadOnlyTable); }
    break;

  case 215: // primitive.signal.source.table: RWTBL
                { yylhs.value.as < Type::exp > () = boxPrim5(sigWriteReadTable); }
    break;

  case 216: // primitive.signal.source.soundfile: SOUNDFILE LPAR primitive.string.unquoted COMMA expression.composition RPAR
                                                                                     {
            yylhs.value.as < Type::exp > () = boxSoundfile( yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > () );
          }
    break;

  case 217: // primitive.signal.source.waveform: WAVEFORM LBRAQ primitive.type.number.list RBRAQ
                                                        {
          yylhs.value.as < Type::exp > () = boxWaveform(gGlobal->gWaveForm);
          gGlobal->gWaveForm.clear();
          /* primitive.type.number.list pushes values onto gGlobal->gWaveForm */
        }
    break;

  case 218: // primitive.type.list: primitive.type.list.start
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 219: // primitive.type.list: primitive.type.list.append
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 220: // primitive.type.list.start: primitive.type
                         { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),gGlobal->nil); }
    break;

  case 221: // primitive.type.list.append: primitive.type.list COMMA primitive.type
                                                                { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),yystack_[2].value.as < Type::exp > ()); }
    break;

  case 222: // primitive.ui: primitive.ui.button
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 223: // primitive.ui: primitive.ui.checkbox
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 224: // primitive.ui: primitive.ui.vslider
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 225: // primitive.ui: primitive.ui.hslider
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 226: // primitive.ui: primitive.ui.nentry
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 227: // primitive.ui: primitive.ui.vgroup
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 228: // primitive.ui: primitive.ui.hgroup
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 229: // primitive.ui: primitive.ui.tgroup
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 230: // primitive.ui: primitive.ui.vbargraph
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 231: // primitive.ui: primitive.ui.hbargraph
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 232: // primitive.ui.button: BUTTON LPAR primitive.string.unquoted RPAR
                                                   { yylhs.value.as < Type::exp > () = boxButton(yystack_[1].value.as < Type::exp > ()); }
    break;

  case 233: // primitive.ui.checkbox: CHECKBOX LPAR primitive.string.unquoted RPAR
                                                     { yylhs.value.as < Type::exp > () = boxCheckbox(yystack_[1].value.as < Type::exp > ()); }
    break;

  case 234: // primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition COMMA expression.composition COMMA expression.composition RPAR
                                                                                                                                                                                                {
          yylhs.value.as < Type::exp > () = boxVSlider(yystack_[9].value.as < Type::exp > (),yystack_[7].value.as < Type::exp > (),yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 235: // primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition COMMA expression.composition COMMA expression.composition RPAR
                                                                                                                                                                                                {
          yylhs.value.as < Type::exp > () = boxHSlider(yystack_[9].value.as < Type::exp > (),yystack_[7].value.as < Type::exp > (),yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 236: // primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition COMMA expression.composition COMMA expression.composition RPAR
                                                                                                                                                                                               {
          yylhs.value.as < Type::exp > () = boxNumEntry(yystack_[9].value.as < Type::exp > (),yystack_[7].value.as < Type::exp > (),yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 237: // primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted COMMA expression RPAR
                                                                    { yylhs.value.as < Type::exp > () = boxVGroup(yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > ()); }
    break;

  case 238: // primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted COMMA expression RPAR
                                                                    { yylhs.value.as < Type::exp > () = boxHGroup(yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > ()); }
    break;

  case 239: // primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted COMMA expression RPAR
                                                                    { yylhs.value.as < Type::exp > () = boxTGroup(yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > ()); }
    break;

  case 240: // primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition RPAR
                                                                                                                            {
          yylhs.value.as < Type::exp > () = boxVBargraph(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 241: // primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition RPAR
                                                                                                                            {
          yylhs.value.as < Type::exp > () = boxHBargraph(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 242: // primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag COMMA primitive.string.unquoted RPAR
                                                                                                                            {
          yylhs.value.as < Type::exp > () = boxFFun(ffunction(yystack_[5].value.as < Type::exp > (),yystack_[3].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ()));
        }
    break;

  case 243: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform LPAR primitive.type.list RPAR
                                                                                                 {
            yylhs.value.as < Type::exp > () = cons(yystack_[4].value.as < Type::exp > (), cons(cons(yystack_[3].value.as < Type::exp > (),cons(yystack_[3].value.as < Type::exp > (),cons(yystack_[3].value.as < Type::exp > (),gGlobal->nil))), yystack_[1].value.as < Type::exp > ()));
          }
    break;

  case 244: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform LPAR primitive.type.list RPAR
                                                                                                                                         {
            yylhs.value.as < Type::exp > () = cons(yystack_[6].value.as < Type::exp > (), cons(cons(yystack_[5].value.as < Type::exp > (),cons(yystack_[3].value.as < Type::exp > (),cons(yystack_[3].value.as < Type::exp > (),gGlobal->nil))), yystack_[1].value.as < Type::exp > ()));
          }
    break;

  case 245: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform OR statement.identifier.waveform LPAR primitive.type.list RPAR
                                                                                                                                                                                {
            yylhs.value.as < Type::exp > () = cons(yystack_[8].value.as < Type::exp > (), cons(cons(yystack_[7].value.as < Type::exp > (),cons(yystack_[5].value.as < Type::exp > (),cons(yystack_[3].value.as < Type::exp > (),gGlobal->nil))), yystack_[1].value.as < Type::exp > ()));
          }
    break;

  case 246: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform LPAR RPAR
                                                                             {
            yylhs.value.as < Type::exp > () = cons(yystack_[3].value.as < Type::exp > (), cons(cons(yystack_[2].value.as < Type::exp > (),cons(yystack_[2].value.as < Type::exp > (),cons(yystack_[2].value.as < Type::exp > (),gGlobal->nil))), gGlobal->nil));
          }
    break;

  case 247: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform LPAR RPAR
                                                                                                                     {
            yylhs.value.as < Type::exp > () = cons(yystack_[5].value.as < Type::exp > (), cons(cons(yystack_[4].value.as < Type::exp > (),cons(yystack_[2].value.as < Type::exp > (),cons(yystack_[2].value.as < Type::exp > (),gGlobal->nil))), gGlobal->nil));
          }
    break;

  case 248: // primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform OR statement.identifier.waveform LPAR RPAR
                                                                                                                                                            {
            yylhs.value.as < Type::exp > () = cons(yystack_[7].value.as < Type::exp > (), cons(cons(yystack_[6].value.as < Type::exp > (),cons(yystack_[4].value.as < Type::exp > (),cons(yystack_[2].value.as < Type::exp > (),gGlobal->nil))), gGlobal->nil));
          }
    break;

  case 249: // primitive.foreign.constant: FCONSTANT LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR
                                                                                                  {
          yylhs.value.as < Type::exp > () = boxFConst( yystack_[4].value.as < Type::exp > (), yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 250: // primitive.foreign.variable: FVARIABLE LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR
                                                                                                  {
          yylhs.value.as < Type::exp > () = boxFVar( yystack_[4].value.as < Type::exp > (), yystack_[3].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > () );
        }
    break;

  case 251: // primitive.signal.inputs: INPUTS LPAR expression RPAR
                                    { yylhs.value.as < Type::exp > () = boxInputs(yystack_[1].value.as < Type::exp > ()); }
    break;

  case 252: // primitive.signal.outputs: OUTPUTS LPAR expression RPAR
                                     { yylhs.value.as < Type::exp > () = boxOutputs(yystack_[1].value.as < Type::exp > ()); }
    break;

  case 253: // statement: statement.definition
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 254: // statement: statement.declare.metadata
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 255: // statement: statement.declare.feature.metadata
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 256: // statement: statement.declare.doc
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 257: // statement: statement.import
    { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 258: // statement.definition: statement.definition.function
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 259: // statement.definition: statement.definition.substitution
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 260: // statement.definition: statement.definition.error
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 261: // statement.definition.function.incomplete: statement.identifier.box LPAR expression.composition.list RPAR DEF expression
                                                                                    {
        yylhs.value.as < Type::exp > () = cons(
          yystack_[5].value.as < Type::exp > (),
          cons( yystack_[3].value.as < Type::exp > (), yystack_[0].value.as < Type::exp > () )
        );
        setDefProp(yystack_[5].value.as < Type::exp > (), yyfilename, yylineno);
      }
    break;

  case 262: // statement.definition.function: statement.definition.function.incomplete ENDDEF
                                                        {
          yylhs.value.as < Type::exp > () = yystack_[1].value.as < Type::exp > ();
        }
    break;

  case 263: // statement.definition.function: statement.definition.function.incomplete error ENDL
                                                            {
          yyerr++;
//          error(*yylocationp, std::string("Missing semicolon.");
//          delete (yysemantic_stack_[(1) - (1)].stringVal);
          yylhs.value.as < Type::exp > () = yystack_[2].value.as < Type::exp > ();
          yyerrok;
        }
    break;

  case 264: // statement.definition.substitution: statement.identifier.box DEF expression ENDDEF
                                                                                {
          yylhs.value.as < Type::exp > () = cons(yystack_[3].value.as < Type::exp > (),cons(gGlobal->nil,yystack_[1].value.as < Type::exp > ()));
          setDefProp(yystack_[3].value.as < Type::exp > (), yyfilename, yylineno);
        }
    break;

  case 265: // statement.definition.with: expression WITH LBRAQ statement.definition.list RBRAQ
                                                            {
        yylhs.value.as < Type::exp > () = boxWithLocalDef(yystack_[4].value.as < Type::exp > (),formatDefinitions(yystack_[1].value.as < Type::exp > ()));
      }
    break;

  case 266: // statement.definition.error: error ENDDEF
                     {
          yylhs.value.as < Type::exp > () = gGlobal->nil;
          yyerr++;
        }
    break;

  case 267: // statement.definition.list: statement.definition.list.start
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 268: // statement.definition.list: statement.definition.list.start.qualified
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 269: // statement.definition.list: statement.definition.list.append
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 270: // statement.definition.list: statement.definition.list.append.qualified
        { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 271: // statement.definition.list.start: statement.definition
                               {
            yylhs.value.as < Type::exp > () = cons( yylhs.value.as < Type::exp > (), gGlobal->nil );
          }
    break;

  case 272: // statement.definition.list.start.qualified: statement.math.precision.list statement.definition
                                                             {
            if (acceptdefinition(yystack_[1].value.as < int > ()))
              yylhs.value.as < Type::exp > () = cons( yystack_[0].value.as < Type::exp > (), gGlobal->nil );
            else
              yylhs.value.as < Type::exp > () = gGlobal->nil;
          }
    break;

  case 273: // statement.definition.list.append: statement.definition.list statement.definition
                                                         {
            yylhs.value.as < Type::exp > () = cons (yystack_[0].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
          }
    break;

  case 274: // statement.definition.list.append.qualified: statement.definition.list statement.math.precision.list statement.definition
                                                                                       {
            if (acceptdefinition(yystack_[1].value.as < int > ()))
              yylhs.value.as < Type::exp > () = cons (yystack_[0].value.as < Type::exp > (),yystack_[2].value.as < Type::exp > ());
            else
              yylhs.value.as < Type::exp > () = yystack_[2].value.as < Type::exp > ();
          }
    break;

  case 275: // statement.declare.metadata: DECLARE statement.identifier primitive.string.quoted ENDDEF
                                                                              {
        declareMetadata(yystack_[2].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        yylhs.value.as < Type::exp > () = gGlobal->nil;
      }
    break;

  case 276: // statement.declare.feature.metadata: DECLARE statement.identifier statement.identifier primitive.string.quoted ENDDEF
                                                                                                            {
        declareDefinitionMetadata( yystack_[3].value.as < Type::exp > (), yystack_[2].value.as < Type::exp > (), yystack_[1].value.as < Type::exp > () );
        yylhs.value.as < Type::exp > () = gGlobal->nil;
      }
    break;

  case 277: // statement.declare.doc: BDOC doc EDOC
                          {
        declareDoc(yystack_[1].value.as < Type::exp > ());
        yylhs.value.as < Type::exp > () = gGlobal->nil;
      }
    break;

  case 278: // statement.identifier: IDENT
            {
        yylhs.value.as < Type::exp > () = tree(yytext);
        setUseProp(yylhs.value.as < Type::exp > (), yyfilename, yylineno);
      }
    break;

  case 279: // statement.identifier.box: IDENT
            {
        yylhs.value.as < Type::exp > () = boxIdent(yytext);
        setUseProp(yylhs.value.as < Type::exp > (), yyfilename, yylineno);
      }
    break;

  case 280: // statement.identifier.waveform: IDENT
            { yylhs.value.as < Type::exp > () = tree(yytext); }
    break;

  case 281: // statement.import: IMPORT LPAR primitive.string.unquoted RPAR ENDDEF
                                                                  { yylhs.value.as < Type::exp > () = importFile(yystack_[2].value.as < Type::exp > ()); }
    break;

  case 282: // statement.list: statement.list.start
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 283: // statement.list: statement.list.start.qualified
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 284: // statement.list: statement.list.append
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 285: // statement.list: statement.list.append.qualified
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 286: // statement.list.start: statement
                  {
          yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (), gGlobal->nil);
        }
    break;

  case 287: // statement.list.start.qualified: statement.math.precision.list statement
                                                {
          if (acceptdefinition(yystack_[1].value.as < int > ()))
            yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (), gGlobal->nil);
          else
            yylhs.value.as < Type::exp > () = gGlobal->nil;
        }
    break;

  case 288: // statement.list.append: statement.list statement
                                 {
          yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ());
        }
    break;

  case 289: // statement.list.append.qualified: statement.list statement.math.precision.list statement
                                                               {
          if (acceptdefinition(yystack_[1].value.as < int > ()))
            yylhs.value.as < Type::exp > () = cons(yystack_[2].value.as < Type::exp > (),yystack_[0].value.as < Type::exp > ());
          else
            yylhs.value.as < Type::exp > ()=yystack_[2].value.as < Type::exp > ();
        }
    break;

  case 290: // statement.math.precision: FLOATMODE
                  { yylhs.value.as < int > () = 1; }
    break;

  case 291: // statement.math.precision: DOUBLEMODE
                   { yylhs.value.as < int > () = 2; }
    break;

  case 292: // statement.math.precision: QUADMODE
                 { yylhs.value.as < int > () = 4; }
    break;

  case 293: // statement.math.precision: FIXEDPOINTMODE
                       { yylhs.value.as < int > () = 8; }
    break;

  case 294: // statement.math.precision.list: statement.math.precision.list.start
          { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
    break;

  case 295: // statement.math.precision.list: statement.math.precision.list.append
          { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
    break;

  case 296: // statement.math.precision.list.start: statement.math.precision
            { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
    break;

  case 297: // statement.math.precision.list.append: statement.math.precision.list statement.math.precision
                                                                   {
              yylhs.value.as < int > () = yystack_[1].value.as < int > () | yystack_[0].value.as < int > ();
            }
    break;

  case 298: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.start
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 299: // statement.signal.pattern.rule.list: statement.signal.pattern.rule.list.append
      { yylhs.value.as < Type::exp > () = yystack_[0].value.as < Type::exp > (); }
    break;

  case 300: // statement.signal.pattern.rule.list.start: statement.signal.pattern.rule
                                      { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),gGlobal->nil); }
    break;

  case 301: // statement.signal.pattern.rule.list.append: statement.signal.pattern.rule.list statement.signal.pattern.rule
                                                                                      { yylhs.value.as < Type::exp > () = cons(yystack_[0].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ()); }
    break;

  case 302: // statement.signal.pattern.rule: LPAR expression.composition.list RPAR ARROW expression ENDDEF
                                                                    { yylhs.value.as < Type::exp > () = cons(yystack_[4].value.as < Type::exp > (),yystack_[1].value.as < Type::exp > ()); }
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
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
  Implementation::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  Implementation::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "SPLIT", "MIX", "SEQ", "COMMA",
  "REC", "LT", "LE", "EQ", "GT", "GE", "NE", "ADD", "SUB", "OR", "MUL",
  "DIV", "MOD", "AND", "XOR", "LSH", "RSH", "POWOP", "FDELAY", "DELAY1",
  "MEM", "PREFIX", "INTCAST", "FLOATCAST", "ANYCAST", "FFUNCTION",
  "FCONSTANT", "FVARIABLE", "BUTTON", "CHECKBOX", "VSLIDER", "HSLIDER",
  "NENTRY", "VGROUP", "HGROUP", "TGROUP", "HBARGRAPH", "VBARGRAPH",
  "SOUNDFILE", "ATTACH", "ACOS", "ASIN", "ATAN", "ATAN2", "COS", "SIN",
  "TAN", "EXP", "LOG", "LOG10", "POWFUN", "SQRT", "ABS", "MIN", "MAX",
  "FMOD", "REMAINDER", "FLOOR", "CEIL", "RINT", "RDTBL", "RWTBL",
  "SELECT2", "SELECT3", "INT", "FLOAT", "LAMBDA", "DOT", "WIRE", "CUT",
  "ENDDEF", "VIRG", "LPAR", "RPAR", "LBRAQ", "RBRAQ", "LCROC", "RCROC",
  "WITH", "LETREC", "WHERE", "DEF", "IMPORT", "COMPONENT", "LIBRARY",
  "ENVIRONMENT", "WAVEFORM", "ROUTE", "ENABLE", "CONTROL",
  "ITERATE_PARALLEL", "ISEQ", "ISUM", "IPROD", "INPUTS", "OUTPUTS",
  "STRING", "TAGSTRING", "IDENT", "EXTRA", "DECLARE", "CASE", "ARROW",
  "ASSERTBOUNDS", "LOWEST", "HIGHEST", "FLOATMODE", "DOUBLEMODE",
  "QUADMODE", "FIXEDPOINTMODE", "BDOC", "EDOC", "BEQN", "EEQN", "BDGM",
  "EDGM", "BLST", "ELST", "BMETADATA", "EMETADATA", "DOCCHAR", "NOTICE",
  "LISTING", "LSTTRUE", "LSTFALSE", "LSTDEPENDENCIES", "LSTMDOCTAGS",
  "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "ENDL", "$accept", "program", "doc",
  "doc.text", "doc.equation", "doc.diagram", "doc.notice", "doc.list",
  "doc.attribute.list", "doc.attribute.definition", "doc.attribute.value",
  "doc.metadata", "expression", "expression.component",
  "expression.composition", "expression.composition.list",
  "expression.composition.mix", "expression.composition.record",
  "expression.composition.sequence", "expression.composition.split",
  "expression.environment", "expression.infix",
  "expression.infix.definitions.local",
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
  "expression.parallel", "expression.signal", "expression.signal.control",
  "expression.signal.delay", "expression.signal.logic", "primitive",
  "primitive.foreign", "primitive.number", "primitive.string.quoted",
  "primitive.string.unquoted", "primitive.string.tag", "primitive.signal",
  "primitive.signal.input.implicit", "primitive.signal.input.terminate",
  "primitive.type", "primitive.type.number.list",
  "primitive.type.number.list.member", "primitive.type.number.list.start",
  "primitive.type.number.list.append", "primitive.type.number",
  "primitive.type.number.int", "primitive.type.number.float",
  "primitive.type.any", "primitive.signal.route",
  "primitive.signal.source", "primitive.signal.source.table",
  "primitive.signal.source.soundfile", "primitive.signal.source.waveform",
  "primitive.type.list", "primitive.type.list.start",
  "primitive.type.list.append", "primitive.ui", "primitive.ui.button",
  "primitive.ui.checkbox", "primitive.ui.vslider", "primitive.ui.hslider",
  "primitive.ui.nentry", "primitive.ui.vgroup", "primitive.ui.hgroup",
  "primitive.ui.tgroup", "primitive.ui.vbargraph",
  "primitive.ui.hbargraph", "primitive.foreign.function",
  "primitive.foreign.function.signature", "primitive.foreign.constant",
  "primitive.foreign.variable", "primitive.signal.inputs",
  "primitive.signal.outputs", "statement", "statement.definition",
  "statement.definition.function.incomplete",
  "statement.definition.function", "statement.definition.substitution",
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
  "statement.math.precision.list.append",
  "statement.signal.pattern.rule.list",
  "statement.signal.pattern.rule.list.start",
  "statement.signal.pattern.rule.list.append",
  "statement.signal.pattern.rule", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // Implementation::context.
  Implementation::context::context (const Implementation& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Implementation::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  Implementation::yy_lac_check_ (symbol_kind_type yytoken) const
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
  Implementation::yy_lac_establish_ (symbol_kind_type yytoken)
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
  Implementation::yy_lac_discard_ (const char* event)
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
  Implementation::yy_syntax_error_arguments_ (const context& yyctx,
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
  Implementation::yysyntax_error_ (const context& yyctx) const
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


  const short Implementation::yypact_ninf_ = -451;

  const signed char Implementation::yytable_ninf_ = -4;

  const short
  Implementation::yypact_[] =
  {
      25,   -26,     7,  -451,    -9,  -451,  -451,  -451,  -451,   343,
     116,  -451,  -451,    28,  -451,  -451,  -451,  -451,  -451,  -451,
      23,  -451,    46,  -451,  -451,  -451,  -451,  -451,    81,  -451,
    -451,  -451,    15,  -451,    79,   513,   513,   287,    -9,  -451,
    -451,    19,    45,  -451,  -451,  -451,  -451,  -451,  -451,   -11,
    -451,   513,   513,  -451,    81,  -451,  -451,  -451,    48,  -451,
      80,    66,  -451,  -451,  -451,  -451,  -451,  -451,     8,    51,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,   106,   108,   126,   133,   140,   151,
     162,   164,   166,   172,   182,   188,   216,   222,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,   228,  -451,  -451,   513,   233,
     235,   119,   168,   264,  -451,  -451,   270,   271,   272,   285,
     290,   296,   193,  -451,  -451,  -451,    59,  -451,   691,  -451,
    -451,  -451,  -451,  -451,   618,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,    14,  -451,
     184,   210,   273,   291,  -451,   191,  -451,  -451,  -451,   691,
      10,    12,  -451,   328,  -451,   329,  -451,  -451,  -451,  -451,
    -451,    77,    77,    77,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,   305,    69,    15,    15,    81,
     239,   513,   305,   305,   305,   305,   513,   513,   356,   513,
     355,   364,  -451,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   513,   513,  -451,   305,   513,    94,  -451,
     310,   313,   314,  -451,  -451,  -451,   513,   363,  -451,  -451,
    -451,   332,   453,    -9,    -9,   383,   385,   461,   463,   466,
     467,   468,   475,   476,   477,   480,    13,  -451,  -451,  -451,
    -451,   417,   418,    76,     8,   143,  -451,  -451,     9,  -451,
    -451,  -451,   427,   501,   502,   503,   504,    88,   142,   513,
      -1,  -451,  -451,  -451,   533,    94,    30,   691,   691,    78,
    -451,   637,   637,   637,   637,   637,   637,   374,   374,   374,
     333,   333,   333,   333,   333,   333,   333,    36,   339,  -451,
      44,  -451,    62,  -451,  -451,  -451,  -451,    94,    87,    87,
      87,   691,   513,  -451,    41,   121,   538,   581,  -451,  -451,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   305,
     516,  -451,  -451,  -451,   239,  -451,   513,   513,   513,   513,
     513,  -451,  -451,    47,  -451,  -451,   124,   514,   305,  -451,
      26,  -451,  -451,  -451,   528,  -451,  -451,  -451,    94,  -451,
    -451,  -451,   481,   483,   484,    18,   332,    37,  -451,  -451,
     616,   121,   121,   437,   473,   489,   146,   207,   214,   499,
     510,   266,  -451,   614,  -451,    67,   590,   595,   679,   684,
     591,  -451,  -451,  -451,  -451,    94,  -451,   513,  -451,  -451,
    -451,  -451,    42,  -451,  -451,  -451,  -451,  -451,    49,  -451,
    -451,    15,   619,   627,   513,   513,   513,  -451,  -451,  -451,
     513,   513,  -451,   513,   513,  -451,   513,   513,   513,   513,
     513,   170,   195,   332,   359,   173,  -451,   628,  -451,  -451,
     699,   718,   723,   301,   324,   217,   236,   238,   240,   250,
     252,   262,  -451,  -451,   630,  -451,    53,  -451,  -451,   513,
     513,   513,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,   372,  -451,   728,   733,   738,  -451,    70,   513,   513,
     513,  -451,   337,   349,   367,  -451,  -451,  -451
  };

  const short
  Implementation::yydefact_[] =
  {
       0,     0,     0,   279,     0,   290,   291,   292,   293,    10,
       0,   286,   253,     0,   258,   259,   260,   254,   255,   256,
       0,   257,     0,   282,   283,   284,   285,   296,     0,   294,
     295,   266,     0,   278,     0,     0,     0,     0,     0,    11,
      15,     0,     4,     5,     6,     7,     8,     9,     1,     0,
     262,     0,     0,   288,     0,   287,   297,   185,     0,   184,
       0,     0,   112,   113,   116,   114,   115,   117,   130,   131,
     169,   132,   133,   134,   168,   170,   138,   139,   143,   167,
     165,   166,   206,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   150,
     151,   152,   153,   154,   155,   156,   140,   141,   142,   144,
     145,   118,   119,   120,   135,   136,   121,   122,   126,   214,
     215,   171,   172,   182,   183,     0,   194,   195,     0,     0,
       0,     0,     0,     0,   163,   164,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,    48,    29,    33,
      34,    31,    32,    49,    35,    43,    44,    45,    63,    64,
      65,    66,    47,    46,    50,    51,    52,    53,    54,    27,
      55,    56,   109,   111,   107,   127,   128,   129,   108,   110,
      57,    28,    58,   159,   160,   161,    60,   174,   175,   177,
     189,   190,   176,   204,   205,   192,   193,   213,   212,   211,
     178,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   180,   179,   181,   188,   191,    26,    59,     0,    17,
       0,     0,     0,     0,    18,     0,   277,    12,   263,    36,
       0,     0,   289,     0,   275,     0,   146,   147,   148,   149,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,    14,
       0,     0,     0,    16,    19,    25,     0,     0,   264,   281,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
     157,     0,     0,     0,     0,     0,   201,   200,     0,   202,
     198,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,   299,   300,   158,     0,     0,    41,    38,    40,
      39,    73,    74,    77,    75,    76,    78,    67,    68,    80,
      69,    70,    71,    79,    81,    82,    83,    72,    85,    62,
       0,   271,     0,   267,   268,   269,   270,     0,     0,     0,
       0,    37,     0,   280,     0,     0,     0,     0,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,   106,    42,     0,   217,     0,     0,     0,     0,
       0,   251,   252,     0,   173,   301,     0,     0,     0,    96,
       0,    99,   100,   101,     0,    84,    61,   273,     0,   272,
      23,    24,     0,     0,     0,   261,     0,     0,   186,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,   203,     0,     0,     0,     0,     0,
       0,   265,   104,   105,    97,     0,   102,     0,   274,    20,
      21,    22,     0,   208,   246,   220,   196,   197,     0,   218,
     219,     0,     0,     0,     0,     0,     0,   237,   238,   239,
       0,     0,   216,     0,     0,   209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,   103,     0,   247,     0,   221,   242,     0,
       0,     0,   241,   240,    91,   210,    87,    88,    89,    90,
     302,     0,   244,     0,     0,     0,   248,     0,     0,     0,
       0,   245,     0,     0,     0,   234,   235,   236
  };

  const short
  Implementation::yypgoto_[] =
  {
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,   487,
    -113,  -451,   -19,  -451,   -40,  -265,  -451,  -451,  -451,  -451,
    -451,   387,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,   282,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -250,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -248,   652,  -209,  -161,  -451,  -451,  -451,
     199,  -451,   303,  -451,  -451,  -236,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -450,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,   -20,  -295,  -451,  -451,  -451,  -451,
    -451,  -341,  -451,  -451,  -451,  -451,  -451,  -451,  -451,   -25,
       0,  -425,  -451,   456,  -451,  -451,  -451,  -451,   -24,     1,
    -451,  -451,  -451,  -451,  -451,   368
  };

  const short
  Implementation::yydefgoto_[] =
  {
       0,    10,    41,    42,    43,    44,    45,    46,   223,   224,
     442,    47,   146,   147,   148,   230,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   326,   327,   328,   169,
     430,   431,   432,   433,   434,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    60,    58,   450,   189,   190,   191,
     485,   338,   339,   340,   341,   192,   193,   194,   487,   195,
     196,   197,   198,   199,   488,   489,   490,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   312,
     212,   213,   214,   215,    11,    12,    13,    14,    15,   216,
      16,   382,   383,   384,   385,   386,    17,    18,    19,    34,
     217,   394,    21,    22,    23,    24,    25,    26,    27,   387,
      29,    30,   350,   351,   352,   353
  };

  const short
  Implementation::yytable_[] =
  {
      20,    28,    53,   381,    56,   311,   313,   314,    55,    61,
     336,   229,   337,   225,   426,   414,   306,   218,   269,   409,
     269,   482,    20,    54,   269,    -3,     1,   427,    20,    49,
      56,   427,   380,   231,   232,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,    -2,     1,   331,   332,
     306,    31,   428,   306,    20,   515,   428,   446,   513,   515,
     381,   294,   295,     1,   536,   269,    82,    83,   483,   240,
     273,   274,   275,   504,   276,   269,   515,     1,   349,   236,
     237,   424,     1,   275,   423,   276,    32,   437,   534,   308,
     307,   415,   439,   410,   269,     1,    33,   270,   271,   270,
     271,   557,    51,   270,   271,    50,    82,    83,   474,   256,
     296,    52,   429,   475,     2,   297,    48,   484,    57,   298,
     447,   514,   238,   239,   435,     1,   228,   470,   233,   516,
       3,   437,     4,   552,   511,     2,   299,   226,     5,     6,
       7,     8,     9,   478,   270,   271,   436,   505,   269,   330,
     561,     3,   269,     4,   270,   271,     3,   234,   413,     5,
       6,     7,     8,     9,   336,     2,   337,     3,   421,    59,
       2,     1,   227,   270,   271,     5,     6,     7,     8,   272,
     381,     3,    59,     4,    33,   241,     3,   242,     4,     5,
       6,     7,     8,     9,     5,     6,     7,     8,     9,     3,
     259,   269,    82,    83,   483,   243,   471,     5,     6,     7,
       8,   486,   244,   269,   238,   239,   437,   440,   441,   245,
     269,   342,   422,   269,   448,   449,   497,   270,   271,     3,
     246,   270,   271,   357,   358,   359,   360,     5,     6,     7,
       8,   247,   269,   248,   269,   249,   269,   347,   348,   260,
     354,   250,   532,   334,   335,   329,   269,   229,   269,    20,
      28,   251,   343,   344,   345,   346,   391,   252,   269,   273,
     274,   275,   533,   276,   268,     3,   443,   444,   486,   486,
     270,   271,   517,     5,     6,     7,     8,   498,   396,   397,
     492,   493,   270,   271,   499,   253,   379,   544,    20,   270,
     271,   254,   270,   271,   273,   274,   275,   255,   276,   229,
     123,   124,   257,    53,   258,   486,   545,   305,   546,   300,
     547,   270,   271,   270,   271,   270,   271,   273,   274,   275,
     548,   276,   549,    20,    54,   270,   271,   270,   271,   550,
     273,   274,   275,   261,   276,   301,   502,   270,   271,   262,
     263,   264,   273,   274,   275,    20,   276,   293,   294,   295,
     453,   454,   455,    56,   265,   295,   459,   460,   461,   266,
     273,   274,   275,   445,   276,   267,   465,   466,   467,   468,
     469,   542,    20,   438,   456,   457,   458,    20,    82,    83,
     483,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    82,    83,   483,   543,   309,   310,   296,   302,   462,
       3,   219,   297,   296,    56,   303,   298,   565,   297,   220,
     221,   222,   298,   220,   221,   222,    20,   438,   473,   566,
     273,   274,   275,   416,   276,   349,   355,   393,    20,   535,
     273,   274,   275,   494,   276,   356,   388,   567,   296,   389,
     390,   392,   556,   297,   520,   521,   522,   298,   512,   395,
     523,   524,    35,   398,    36,   399,    37,   400,    38,   401,
      39,    40,   402,   403,   404,    20,   273,   274,   275,   495,
     276,   405,   406,   407,   525,   526,   408,   527,   528,   529,
     530,   531,   273,   274,   275,   496,   276,   411,   412,   553,
     554,   555,   273,   274,   275,   500,   276,   417,   418,   419,
     420,    20,   438,   273,   274,   275,   501,   276,   562,   563,
     564,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   269,
      80,    81,    82,    83,   451,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   452,   126,   127,
     463,   472,   128,   273,   274,   275,   506,   276,   273,   274,
     275,   507,   276,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   477,   479,     3,   480,
     481,   142,   491,   143,   144,   145,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,    -4,    -4,    -4,    -4,    -4,
      -4,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   273,   274,   275,   508,   276,   273,   274,   275,
     509,   276,   296,   503,   273,   274,   275,   297,   276,   518,
     510,   298,   273,   274,   275,   539,   276,   519,   538,   551,
     304,   296,   476,   235,   537,   333,   297,   464,   425,     0,
     298,   273,   274,   275,   540,   276,   273,   274,   275,   541,
     276,   273,   274,   275,   558,   276,   273,   274,   275,   559,
     276,   273,   274,   275,   560,   276
  };

  const short
  Implementation::yycheck_[] =
  {
       0,     0,    22,   298,    28,   241,   242,   243,    28,    34,
     260,    51,   260,    38,   355,     6,     6,    36,     6,     6,
       6,   446,    22,    22,     6,     0,     1,     1,    28,     1,
      54,     1,   297,    52,    54,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,     1,   257,   258,
       6,    77,    26,     6,    54,     6,    26,    16,    16,     6,
     355,    25,    26,     1,   514,     6,    29,    30,    31,    69,
       3,     4,     5,     6,     7,     6,     6,     1,    79,    71,
      72,    82,     1,     5,   349,     7,    79,   382,   513,    77,
      80,    82,   387,    80,     6,     1,   105,    85,    86,    85,
      86,   551,    79,    85,    86,    77,    29,    30,    82,   128,
      74,    88,    82,    87,    89,    79,     0,    80,   103,    83,
      79,    79,    71,    72,    80,     1,   137,    80,    80,    80,
     105,   426,   107,    80,   475,    89,   122,   118,   113,   114,
     115,   116,   117,   438,    85,    86,    84,    80,     6,    80,
      80,   105,     6,   107,    85,    86,   105,    77,    82,   113,
     114,   115,   116,   117,   414,    89,   414,   105,    80,   103,
      89,     1,   127,    85,    86,   113,   114,   115,   116,   120,
     475,   105,   103,   107,   105,    79,   105,    79,   107,   113,
     114,   115,   116,   117,   113,   114,   115,   116,   117,   105,
      81,     6,    29,    30,    31,    79,    82,   113,   114,   115,
     116,   447,    79,     6,    71,    72,   511,   130,   131,    79,
       6,   261,    80,     6,   103,   104,    80,    85,    86,   105,
      79,    85,    86,   273,   274,   275,   276,   113,   114,   115,
     116,    79,     6,    79,     6,    79,     6,   266,   267,    81,
     269,    79,    82,    14,    15,   255,     6,   297,     6,   259,
     259,    79,   262,   263,   264,   265,   306,    79,     6,     3,
       4,     5,    77,     7,    81,   105,   389,   390,   514,   515,
      85,    86,   491,   113,   114,   115,   116,    80,   313,   314,
     451,   452,    85,    86,    80,    79,   296,    80,   298,    85,
      86,    79,    85,    86,     3,     4,     5,    79,     7,   349,
      71,    72,    79,   333,    79,   551,    80,   126,    80,   135,
      80,    85,    86,    85,    86,    85,    86,     3,     4,     5,
      80,     7,    80,   333,   333,    85,    86,    85,    86,    77,
       3,     4,     5,    79,     7,   135,    80,    85,    86,    79,
      79,    79,     3,     4,     5,   355,     7,    24,    25,    26,
     400,   401,   402,   387,    79,    26,   406,   407,   408,    79,
       3,     4,     5,   392,     7,    79,   416,   417,   418,   419,
     420,    80,   382,   382,   403,   404,   405,   387,    29,    30,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    29,    30,    31,    80,    77,    77,    74,   135,   409,
     105,   124,    79,    74,   438,   124,    83,    80,    79,   132,
     133,   134,    83,   132,   133,   134,   426,   426,   428,    80,
       3,     4,     5,     6,     7,    79,    81,   105,   438,    80,
       3,     4,     5,     6,     7,    81,   136,    80,    74,   136,
     136,    88,    80,    79,   494,   495,   496,    83,   477,     6,
     500,   501,   119,    80,   121,    80,   123,     6,   125,     6,
     127,   128,     6,     6,     6,   475,     3,     4,     5,     6,
       7,     6,     6,     6,   503,   504,     6,   506,   507,   508,
     509,   510,     3,     4,     5,     6,     7,    80,    80,   539,
     540,   541,     3,     4,     5,     6,     7,     6,     6,     6,
       6,   511,   511,     3,     4,     5,     6,     7,   558,   559,
     560,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     6,
      27,    28,    29,    30,     6,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     6,    75,    76,
      74,    77,    79,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    88,   136,   105,   136,
     136,   108,     6,   110,   111,   112,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    74,    79,     3,     4,     5,    79,     7,    80,
     109,    83,     3,     4,     5,     6,     7,    80,    80,    79,
     223,    74,   430,    61,   515,   259,    79,   414,   350,    -1,
      83,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7
  };

  const short
  Implementation::yystos_[] =
  {
       0,     1,    89,   105,   107,   113,   114,   115,   116,   117,
     139,   242,   243,   244,   245,   246,   248,   254,   255,   256,
     258,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,    77,    79,   105,   257,   119,   121,   123,   125,   127,
     128,   140,   141,   142,   143,   144,   145,   149,     0,     1,
      77,    79,    88,   242,   267,   242,   266,   103,   203,   103,
     202,   257,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      27,    28,    29,    30,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    75,    76,    79,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   108,   110,   111,   112,   150,   151,   152,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   177,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   205,
     206,   207,   213,   214,   215,   217,   218,   219,   220,   221,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   238,   239,   240,   241,   247,   258,   150,   124,
     132,   133,   134,   146,   147,   257,   118,   127,   137,   152,
     153,   150,   242,    80,    77,   202,    71,    72,    71,    72,
     258,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,   150,    79,    79,    81,
      81,    79,    79,    79,    79,    79,    79,    79,    81,     6,
      85,    86,   120,     3,     4,     5,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    74,    79,    83,   122,
     135,   135,   135,   124,   147,   126,     6,    80,    77,    77,
      77,   213,   237,   213,   213,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   174,   175,   176,   258,
      80,   203,   203,   261,    14,    15,   191,   201,   209,   210,
     211,   212,   152,   258,   258,   258,   258,   150,   150,    79,
     270,   271,   272,   273,   150,    81,    81,   152,   152,   152,
     152,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   258,
     153,   243,   249,   250,   251,   252,   253,   267,   136,   136,
     136,   152,    88,   105,   259,     6,   257,   257,    80,    80,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
      80,    80,    80,    82,     6,    82,     6,     6,     6,     6,
       6,    80,    80,   153,    82,   273,   249,     1,    26,    82,
     178,   179,   180,   181,   182,    80,    84,   243,   267,   243,
     130,   131,   148,   148,   148,   150,    16,    79,   103,   104,
     204,     6,     6,   152,   152,   152,   150,   150,   150,   152,
     152,   152,   258,    74,   210,   152,   152,   152,   152,   152,
      80,    82,    77,   258,    82,    87,   181,    88,   243,   136,
     136,   136,   259,    31,    80,   208,   213,   216,   222,   223,
     224,     6,   204,   204,     6,     6,     6,    80,    80,    80,
       6,     6,    80,    79,     6,    80,     6,     6,     6,     6,
     109,   249,   150,    16,    79,     6,    80,   203,    80,    80,
     152,   152,   152,   152,   152,   150,   150,   150,   150,   150,
     150,   150,    82,    77,   259,    80,   222,   208,    80,     6,
       6,     6,    80,    80,    80,    80,    80,    80,    80,    80,
      77,    79,    80,   152,   152,   152,    80,   222,     6,     6,
       6,    80,   152,   152,   152,    80,    80,    80
  };

  const short
  Implementation::yyr1_[] =
  {
       0,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   142,   143,   144,   145,   145,   146,   146,
     147,   147,   147,   148,   148,   149,   150,   150,   150,   150,
     151,   152,   152,   152,   152,   152,   153,   153,   154,   155,
     156,   157,   158,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   160,   161,   162,   162,   162,   162,   163,   163,   163,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   165,
     165,   165,   166,   166,   167,   168,   168,   169,   170,   171,
     172,   173,   174,   174,   175,   176,   177,   177,   177,   178,
     178,   179,   180,   181,   181,   182,   183,   184,   184,   184,
     184,   184,   185,   185,   185,   185,   185,   185,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   187,   187,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     190,   190,   190,   190,   190,   190,   191,   191,   191,   191,
     192,   192,   192,   192,   192,   192,   192,   193,   194,   195,
     195,   195,   196,   196,   196,   197,   197,   197,   198,   198,
     198,   198,   198,   198,   199,   199,   199,   199,   199,   200,
     200,   200,   201,   201,   202,   203,   204,   204,   205,   205,
     205,   205,   205,   205,   206,   207,   208,   208,   209,   209,
     210,   210,   211,   212,   213,   213,   214,   215,   216,   217,
     217,   218,   218,   218,   219,   219,   220,   221,   222,   222,
     223,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   237,   237,   237,   237,   237,   238,
     239,   240,   241,   242,   242,   242,   242,   242,   243,   243,
     243,   244,   245,   245,   246,   247,   248,   249,   249,   249,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   261,   261,   261,   262,   263,   264,   265,
     266,   266,   266,   266,   267,   267,   268,   269,   270,   270,
     271,   272,   273
  };

  const signed char
  Implementation::yyr2_[] =
  {
       0,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     3,     3,     1,     3,     2,     1,     2,
       5,     5,     5,     1,     1,     3,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     3,     3,     3,
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
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     6,
       8,     1,     1,     1,     1,     1,     6,     4,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,    12,    12,    12,     6,     6,     6,
       8,     8,     8,     5,     7,     9,     4,     6,     8,     7,
       7,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     2,     3,     4,     5,     2,     1,     1,     1,
       1,     1,     2,     2,     3,     4,     5,     3,     1,     1,
       1,     5,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     6
  };




#if YYDEBUG
  const short
  Implementation::yyrline_[] =
  {
       0,   392,   392,   396,   407,   411,   412,   413,   414,   415,
     416,   419,   420,   423,   426,   429,   432,   433,   436,   437,
     440,   443,   448,   453,   454,   457,   464,   465,   466,   467,
     472,   477,   478,   479,   480,   481,   484,   485,   488,   491,
     494,   497,   502,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   526,
     528,   531,   536,   539,   540,   541,   542,   545,   546,   547,
     548,   549,   550,   555,   556,   557,   558,   559,   560,   563,
     564,   565,   568,   569,   574,   577,   578,   583,   588,   593,
     598,   605,   610,   611,   614,   617,   622,   625,   628,   633,
     634,   637,   640,   643,   647,   650,   656,   661,   662,   663,
     664,   665,   668,   669,   670,   671,   672,   673,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   687,   688,   689,
     692,   693,   694,   695,   696,   697,   698,   699,   702,   703,
     706,   707,   708,   709,   710,   711,   714,   715,   716,   717,
     720,   721,   722,   723,   724,   725,   726,   731,   736,   743,
     744,   745,   748,   749,   750,   753,   754,   755,   758,   759,
     760,   761,   762,   763,   770,   771,   772,   773,   774,   779,
     780,   781,   786,   787,   792,   795,   798,   799,   804,   805,
     806,   807,   808,   809,   812,   815,   818,   819,   824,   825,
     828,   831,   836,   839,   842,   843,   846,   849,   852,   855,
     858,   863,   864,   865,   868,   869,   872,   877,   886,   887,
     890,   893,   899,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   911,   914,   917,   922,   927,   932,   935,   938,
     941,   946,   953,   958,   961,   964,   967,   970,   973,   978,
     983,   990,   993,  1001,  1002,  1003,  1004,  1005,  1010,  1011,
    1012,  1015,  1024,  1027,  1037,  1043,  1048,  1054,  1055,  1056,
    1057,  1060,  1065,  1073,  1078,  1088,  1094,  1100,  1108,  1114,
    1120,  1125,  1130,  1131,  1132,  1133,  1136,  1141,  1149,  1154,
    1164,  1165,  1166,  1167,  1170,  1171,  1174,  1177,  1184,  1185,
    1188,  1191,  1194
  };

  void
  Implementation::yy_stack_print_ () const
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
  Implementation::yy_reduce_print_ (int yyrule) const
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


