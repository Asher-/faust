/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "faustparser.y"


#include "global.hh"

#include "tree.hh"
#include "xtended.hh"
#include "boxes.hh"
#include "prim2.hh"
#include "signals.hh"
#include "errormsg.hh"
#include "sourcereader.hh"
#include "doc.hh"
#include "ppbox.hh"

#include <string>
#include <list>

#include "string_substitution.hh"

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYMAXDEPTH	100000

using namespace std;

extern char* 		yytext;
extern const char* 	yyfilename;
extern int 			yylineno;
extern int 			yyerr;

int yylex();


#line 105 "faustparser.cpp"

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

#include "faustparser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SPLIT = 3,                      /* SPLIT  */
  YYSYMBOL_MIX = 4,                        /* MIX  */
  YYSYMBOL_SEQ = 5,                        /* SEQ  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_REC = 7,                        /* REC  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_ADD = 14,                       /* ADD  */
  YYSYMBOL_SUB = 15,                       /* SUB  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_XOR = 21,                       /* XOR  */
  YYSYMBOL_LSH = 22,                       /* LSH  */
  YYSYMBOL_RSH = 23,                       /* RSH  */
  YYSYMBOL_POWOP = 24,                     /* POWOP  */
  YYSYMBOL_FDELAY = 25,                    /* FDELAY  */
  YYSYMBOL_DELAY1 = 26,                    /* DELAY1  */
  YYSYMBOL_MEM = 27,                       /* MEM  */
  YYSYMBOL_PREFIX = 28,                    /* PREFIX  */
  YYSYMBOL_INTCAST = 29,                   /* INTCAST  */
  YYSYMBOL_FLOATCAST = 30,                 /* FLOATCAST  */
  YYSYMBOL_ANYCAST = 31,                   /* ANYCAST  */
  YYSYMBOL_FFUNCTION = 32,                 /* FFUNCTION  */
  YYSYMBOL_FCONSTANT = 33,                 /* FCONSTANT  */
  YYSYMBOL_FVARIABLE = 34,                 /* FVARIABLE  */
  YYSYMBOL_BUTTON = 35,                    /* BUTTON  */
  YYSYMBOL_CHECKBOX = 36,                  /* CHECKBOX  */
  YYSYMBOL_VSLIDER = 37,                   /* VSLIDER  */
  YYSYMBOL_HSLIDER = 38,                   /* HSLIDER  */
  YYSYMBOL_NENTRY = 39,                    /* NENTRY  */
  YYSYMBOL_VGROUP = 40,                    /* VGROUP  */
  YYSYMBOL_HGROUP = 41,                    /* HGROUP  */
  YYSYMBOL_TGROUP = 42,                    /* TGROUP  */
  YYSYMBOL_HBARGRAPH = 43,                 /* HBARGRAPH  */
  YYSYMBOL_VBARGRAPH = 44,                 /* VBARGRAPH  */
  YYSYMBOL_SOUNDFILE = 45,                 /* SOUNDFILE  */
  YYSYMBOL_ATTACH = 46,                    /* ATTACH  */
  YYSYMBOL_ACOS = 47,                      /* ACOS  */
  YYSYMBOL_ASIN = 48,                      /* ASIN  */
  YYSYMBOL_ATAN = 49,                      /* ATAN  */
  YYSYMBOL_ATAN2 = 50,                     /* ATAN2  */
  YYSYMBOL_COS = 51,                       /* COS  */
  YYSYMBOL_SIN = 52,                       /* SIN  */
  YYSYMBOL_TAN = 53,                       /* TAN  */
  YYSYMBOL_EXP = 54,                       /* EXP  */
  YYSYMBOL_LOG = 55,                       /* LOG  */
  YYSYMBOL_LOG10 = 56,                     /* LOG10  */
  YYSYMBOL_POWFUN = 57,                    /* POWFUN  */
  YYSYMBOL_SQRT = 58,                      /* SQRT  */
  YYSYMBOL_ABS = 59,                       /* ABS  */
  YYSYMBOL_MIN = 60,                       /* MIN  */
  YYSYMBOL_MAX = 61,                       /* MAX  */
  YYSYMBOL_FMOD = 62,                      /* FMOD  */
  YYSYMBOL_REMAINDER = 63,                 /* REMAINDER  */
  YYSYMBOL_FLOOR = 64,                     /* FLOOR  */
  YYSYMBOL_CEIL = 65,                      /* CEIL  */
  YYSYMBOL_RINT = 66,                      /* RINT  */
  YYSYMBOL_RDTBL = 67,                     /* RDTBL  */
  YYSYMBOL_RWTBL = 68,                     /* RWTBL  */
  YYSYMBOL_SELECT2 = 69,                   /* SELECT2  */
  YYSYMBOL_SELECT3 = 70,                   /* SELECT3  */
  YYSYMBOL_INT = 71,                       /* INT  */
  YYSYMBOL_FLOAT = 72,                     /* FLOAT  */
  YYSYMBOL_LAMBDA = 73,                    /* LAMBDA  */
  YYSYMBOL_DOT = 74,                       /* DOT  */
  YYSYMBOL_WIRE = 75,                      /* WIRE  */
  YYSYMBOL_CUT = 76,                       /* CUT  */
  YYSYMBOL_ENDDEF = 77,                    /* ENDDEF  */
  YYSYMBOL_VIRG = 78,                      /* VIRG  */
  YYSYMBOL_LPAR = 79,                      /* LPAR  */
  YYSYMBOL_RPAR = 80,                      /* RPAR  */
  YYSYMBOL_LBRAQ = 81,                     /* LBRAQ  */
  YYSYMBOL_RBRAQ = 82,                     /* RBRAQ  */
  YYSYMBOL_LCROC = 83,                     /* LCROC  */
  YYSYMBOL_RCROC = 84,                     /* RCROC  */
  YYSYMBOL_WITH = 85,                      /* WITH  */
  YYSYMBOL_LETREC = 86,                    /* LETREC  */
  YYSYMBOL_WHERE = 87,                     /* WHERE  */
  YYSYMBOL_DEF = 88,                       /* DEF  */
  YYSYMBOL_IMPORT = 89,                    /* IMPORT  */
  YYSYMBOL_COMPONENT = 90,                 /* COMPONENT  */
  YYSYMBOL_LIBRARY = 91,                   /* LIBRARY  */
  YYSYMBOL_ENVIRONMENT = 92,               /* ENVIRONMENT  */
  YYSYMBOL_WAVEFORM = 93,                  /* WAVEFORM  */
  YYSYMBOL_ROUTE = 94,                     /* ROUTE  */
  YYSYMBOL_ENABLE = 95,                    /* ENABLE  */
  YYSYMBOL_CONTROL = 96,                   /* CONTROL  */
  YYSYMBOL_ITERATE_PARALLEL = 97,          /* ITERATE_PARALLEL  */
  YYSYMBOL_ISEQ = 98,                      /* ISEQ  */
  YYSYMBOL_ISUM = 99,                      /* ISUM  */
  YYSYMBOL_IPROD = 100,                    /* IPROD  */
  YYSYMBOL_INPUTS = 101,                   /* INPUTS  */
  YYSYMBOL_OUTPUTS = 102,                  /* OUTPUTS  */
  YYSYMBOL_STRING = 103,                   /* STRING  */
  YYSYMBOL_TAGSTRING = 104,                /* TAGSTRING  */
  YYSYMBOL_IDENT = 105,                    /* IDENT  */
  YYSYMBOL_EXTRA = 106,                    /* EXTRA  */
  YYSYMBOL_DECLARE = 107,                  /* DECLARE  */
  YYSYMBOL_CASE = 108,                     /* CASE  */
  YYSYMBOL_ARROW = 109,                    /* ARROW  */
  YYSYMBOL_ASSERTBOUNDS = 110,             /* ASSERTBOUNDS  */
  YYSYMBOL_LOWEST = 111,                   /* LOWEST  */
  YYSYMBOL_HIGHEST = 112,                  /* HIGHEST  */
  YYSYMBOL_FLOATMODE = 113,                /* FLOATMODE  */
  YYSYMBOL_DOUBLEMODE = 114,               /* DOUBLEMODE  */
  YYSYMBOL_QUADMODE = 115,                 /* QUADMODE  */
  YYSYMBOL_FIXEDPOINTMODE = 116,           /* FIXEDPOINTMODE  */
  YYSYMBOL_BDOC = 117,                     /* BDOC  */
  YYSYMBOL_EDOC = 118,                     /* EDOC  */
  YYSYMBOL_BEQN = 119,                     /* BEQN  */
  YYSYMBOL_EEQN = 120,                     /* EEQN  */
  YYSYMBOL_BDGM = 121,                     /* BDGM  */
  YYSYMBOL_EDGM = 122,                     /* EDGM  */
  YYSYMBOL_BLST = 123,                     /* BLST  */
  YYSYMBOL_ELST = 124,                     /* ELST  */
  YYSYMBOL_BMETADATA = 125,                /* BMETADATA  */
  YYSYMBOL_EMETADATA = 126,                /* EMETADATA  */
  YYSYMBOL_DOCCHAR = 127,                  /* DOCCHAR  */
  YYSYMBOL_NOTICE = 128,                   /* NOTICE  */
  YYSYMBOL_LISTING = 129,                  /* LISTING  */
  YYSYMBOL_LSTTRUE = 130,                  /* LSTTRUE  */
  YYSYMBOL_LSTFALSE = 131,                 /* LSTFALSE  */
  YYSYMBOL_LSTDEPENDENCIES = 132,          /* LSTDEPENDENCIES  */
  YYSYMBOL_LSTMDOCTAGS = 133,              /* LSTMDOCTAGS  */
  YYSYMBOL_LSTDISTRIBUTED = 134,           /* LSTDISTRIBUTED  */
  YYSYMBOL_LSTEQ = 135,                    /* LSTEQ  */
  YYSYMBOL_LSTQ = 136,                     /* LSTQ  */
  YYSYMBOL_YYACCEPT = 137,                 /* $accept  */
  YYSYMBOL_program = 138,                  /* program  */
  YYSYMBOL_doc = 139,                      /* doc  */
  YYSYMBOL_140_doc_text = 140,             /* doc.text  */
  YYSYMBOL_141_doc_equation = 141,         /* doc.equation  */
  YYSYMBOL_142_doc_diagram = 142,          /* doc.diagram  */
  YYSYMBOL_143_doc_notice = 143,           /* doc.notice  */
  YYSYMBOL_144_doc_list = 144,             /* doc.list  */
  YYSYMBOL_145_doc_attribute_list = 145,   /* doc.attribute.list  */
  YYSYMBOL_146_doc_attribute_definition = 146, /* doc.attribute.definition  */
  YYSYMBOL_147_doc_attribute_value = 147,  /* doc.attribute.value  */
  YYSYMBOL_148_doc_metadata = 148,         /* doc.metadata  */
  YYSYMBOL_expression = 149,               /* expression  */
  YYSYMBOL_150_expression_component = 150, /* expression.component  */
  YYSYMBOL_151_expression_composition = 151, /* expression.composition  */
  YYSYMBOL_152_expression_composition_list = 152, /* expression.composition.list  */
  YYSYMBOL_153_expression_composition_mix = 153, /* expression.composition.mix  */
  YYSYMBOL_154_expression_composition_record = 154, /* expression.composition.record  */
  YYSYMBOL_155_expression_composition_sequence = 155, /* expression.composition.sequence  */
  YYSYMBOL_156_expression_composition_split = 156, /* expression.composition.split  */
  YYSYMBOL_157_expression_environment = 157, /* expression.environment  */
  YYSYMBOL_158_expression_infix = 158,     /* expression.infix  */
  YYSYMBOL_159_expression_infix_definitions_local = 159, /* expression.infix.definitions.local  */
  YYSYMBOL_160_expression_infix_environment_access = 160, /* expression.infix.environment.access  */
  YYSYMBOL_161_expression_infix_math = 161, /* expression.infix.math  */
  YYSYMBOL_162_expression_infix_math_algebra = 162, /* expression.infix.math.algebra  */
  YYSYMBOL_163_expression_infix_math_comparison = 163, /* expression.infix.math.comparison  */
  YYSYMBOL_164_expression_infix_math_logic = 164, /* expression.infix.math.logic  */
  YYSYMBOL_165_expression_infix_math_shift = 165, /* expression.infix.math.shift  */
  YYSYMBOL_166_expression_infix_prefix = 166, /* expression.infix.prefix  */
  YYSYMBOL_167_expression_infix_signal_delay = 167, /* expression.infix.signal.delay  */
  YYSYMBOL_168_expression_iterate_parallel = 168, /* expression.iterate.parallel  */
  YYSYMBOL_169_expression_iterate_sequence = 169, /* expression.iterate.sequence  */
  YYSYMBOL_170_expression_iterate_sum = 170, /* expression.iterate.sum  */
  YYSYMBOL_171_expression_iterate_product = 171, /* expression.iterate.product  */
  YYSYMBOL_172_expression_lambda = 172,    /* expression.lambda  */
  YYSYMBOL_173_expression_lambda_params = 173, /* expression.lambda.params  */
  YYSYMBOL_174_expression_lambda_params_start = 174, /* expression.lambda.params.start  */
  YYSYMBOL_175_expression_lambda_params_append = 175, /* expression.lambda.params.append  */
  YYSYMBOL_176_expression_letrec = 176,    /* expression.letrec  */
  YYSYMBOL_177_expression_letrec_list = 177, /* expression.letrec.list  */
  YYSYMBOL_178_expression_letrec_list_start = 178, /* expression.letrec.list.start  */
  YYSYMBOL_179_expression_letrec_list_append = 179, /* expression.letrec.list.append  */
  YYSYMBOL_180_expression_letrec_equation = 180, /* expression.letrec.equation  */
  YYSYMBOL_181_expression_letrec_equation_name = 181, /* expression.letrec.equation.name  */
  YYSYMBOL_182_expression_library = 182,   /* expression.library  */
  YYSYMBOL_183_expression_math = 183,      /* expression.math  */
  YYSYMBOL_184_expression_math_comparison = 184, /* expression.math.comparison  */
  YYSYMBOL_185_expression_math_rounding = 185, /* expression.math.rounding  */
  YYSYMBOL_186_expression_math_signal = 186, /* expression.math.signal  */
  YYSYMBOL_187_expression_math_signal_algebra = 187, /* expression.math.signal.algebra  */
  YYSYMBOL_188_expression_math_signal_shift = 188, /* expression.math.signal.shift  */
  YYSYMBOL_189_expression_math_signal_power = 189, /* expression.math.signal.power  */
  YYSYMBOL_190_expression_math_scalar = 190, /* expression.math.scalar  */
  YYSYMBOL_191_expression_math_trigonometry = 191, /* expression.math.trigonometry  */
  YYSYMBOL_192_expression_parenthesis = 192, /* expression.parenthesis  */
  YYSYMBOL_193_expression_parallel = 193,  /* expression.parallel  */
  YYSYMBOL_194_expression_signal = 194,    /* expression.signal  */
  YYSYMBOL_195_expression_signal_control = 195, /* expression.signal.control  */
  YYSYMBOL_196_expression_signal_delay = 196, /* expression.signal.delay  */
  YYSYMBOL_197_expression_signal_logic = 197, /* expression.signal.logic  */
  YYSYMBOL_primitive = 198,                /* primitive  */
  YYSYMBOL_199_primitive_foreign = 199,    /* primitive.foreign  */
  YYSYMBOL_200_primitive_number = 200,     /* primitive.number  */
  YYSYMBOL_201_primitive_string_quoted = 201, /* primitive.string.quoted  */
  YYSYMBOL_202_primitive_string_unquoted = 202, /* primitive.string.unquoted  */
  YYSYMBOL_203_primitive_string_tag = 203, /* primitive.string.tag  */
  YYSYMBOL_204_primitive_signal = 204,     /* primitive.signal  */
  YYSYMBOL_205_primitive_signal_input_implicit = 205, /* primitive.signal.input.implicit  */
  YYSYMBOL_206_primitive_signal_input_terminate = 206, /* primitive.signal.input.terminate  */
  YYSYMBOL_207_primitive_type = 207,       /* primitive.type  */
  YYSYMBOL_208_primitive_type_number_list = 208, /* primitive.type.number.list  */
  YYSYMBOL_209_primitive_type_number_list_member = 209, /* primitive.type.number.list.member  */
  YYSYMBOL_210_primitive_type_number_list_start = 210, /* primitive.type.number.list.start  */
  YYSYMBOL_211_primitive_type_number_list_append = 211, /* primitive.type.number.list.append  */
  YYSYMBOL_212_primitive_type_number = 212, /* primitive.type.number  */
  YYSYMBOL_213_primitive_type_number_int = 213, /* primitive.type.number.int  */
  YYSYMBOL_214_primitive_type_number_float = 214, /* primitive.type.number.float  */
  YYSYMBOL_215_primitive_type_any = 215,   /* primitive.type.any  */
  YYSYMBOL_216_primitive_signal_route = 216, /* primitive.signal.route  */
  YYSYMBOL_217_primitive_signal_source = 217, /* primitive.signal.source  */
  YYSYMBOL_218_primitive_signal_source_table = 218, /* primitive.signal.source.table  */
  YYSYMBOL_219_primitive_signal_source_soundfile = 219, /* primitive.signal.source.soundfile  */
  YYSYMBOL_220_primitive_signal_source_waveform = 220, /* primitive.signal.source.waveform  */
  YYSYMBOL_221_primitive_type_list = 221,  /* primitive.type.list  */
  YYSYMBOL_222_primitive_type_list_start = 222, /* primitive.type.list.start  */
  YYSYMBOL_223_primitive_type_list_append = 223, /* primitive.type.list.append  */
  YYSYMBOL_224_primitive_ui = 224,         /* primitive.ui  */
  YYSYMBOL_225_primitive_ui_button = 225,  /* primitive.ui.button  */
  YYSYMBOL_226_primitive_ui_checkbox = 226, /* primitive.ui.checkbox  */
  YYSYMBOL_227_primitive_ui_vslider = 227, /* primitive.ui.vslider  */
  YYSYMBOL_228_primitive_ui_hslider = 228, /* primitive.ui.hslider  */
  YYSYMBOL_229_primitive_ui_nentry = 229,  /* primitive.ui.nentry  */
  YYSYMBOL_230_primitive_ui_vgroup = 230,  /* primitive.ui.vgroup  */
  YYSYMBOL_231_primitive_ui_hgroup = 231,  /* primitive.ui.hgroup  */
  YYSYMBOL_232_primitive_ui_tgroup = 232,  /* primitive.ui.tgroup  */
  YYSYMBOL_233_primitive_ui_vbargraph = 233, /* primitive.ui.vbargraph  */
  YYSYMBOL_234_primitive_ui_hbargraph = 234, /* primitive.ui.hbargraph  */
  YYSYMBOL_235_primitive_foreign_function = 235, /* primitive.foreign.function  */
  YYSYMBOL_236_primitive_foreign_function_signature = 236, /* primitive.foreign.function.signature  */
  YYSYMBOL_237_primitive_foreign_constant = 237, /* primitive.foreign.constant  */
  YYSYMBOL_238_primitive_foreign_variable = 238, /* primitive.foreign.variable  */
  YYSYMBOL_239_primitive_signal_inputs = 239, /* primitive.signal.inputs  */
  YYSYMBOL_240_primitive_signal_outputs = 240, /* primitive.signal.outputs  */
  YYSYMBOL_statement = 241,                /* statement  */
  YYSYMBOL_242_statement_definition = 242, /* statement.definition  */
  YYSYMBOL_243_statement_definition_function = 243, /* statement.definition.function  */
  YYSYMBOL_244_statement_definition_substitution = 244, /* statement.definition.substitution  */
  YYSYMBOL_245_statement_definition_with = 245, /* statement.definition.with  */
  YYSYMBOL_246_statement_definition_error = 246, /* statement.definition.error  */
  YYSYMBOL_247_statement_definition_list = 247, /* statement.definition.list  */
  YYSYMBOL_248_statement_definition_list_start = 248, /* statement.definition.list.start  */
  YYSYMBOL_249_statement_definition_list_start_qualified = 249, /* statement.definition.list.start.qualified  */
  YYSYMBOL_250_statement_definition_list_append = 250, /* statement.definition.list.append  */
  YYSYMBOL_251_statement_definition_list_append_qualified = 251, /* statement.definition.list.append.qualified  */
  YYSYMBOL_252_statement_declare_metadata = 252, /* statement.declare.metadata  */
  YYSYMBOL_253_statement_declare_feature_metadata = 253, /* statement.declare.feature.metadata  */
  YYSYMBOL_254_statement_declare_doc = 254, /* statement.declare.doc  */
  YYSYMBOL_255_statement_identifier = 255, /* statement.identifier  */
  YYSYMBOL_256_statement_identifier_box = 256, /* statement.identifier.box  */
  YYSYMBOL_257_statement_identifier_waveform = 257, /* statement.identifier.waveform  */
  YYSYMBOL_258_statement_import = 258,     /* statement.import  */
  YYSYMBOL_259_statement_list = 259,       /* statement.list  */
  YYSYMBOL_260_statement_list_start = 260, /* statement.list.start  */
  YYSYMBOL_261_statement_list_start_qualified = 261, /* statement.list.start.qualified  */
  YYSYMBOL_262_statement_list_append = 262, /* statement.list.append  */
  YYSYMBOL_263_statement_list_append_qualified = 263, /* statement.list.append.qualified  */
  YYSYMBOL_264_statement_math_precision = 264, /* statement.math.precision  */
  YYSYMBOL_265_statement_math_precision_list = 265, /* statement.math.precision.list  */
  YYSYMBOL_266_statement_math_precision_list_start = 266, /* statement.math.precision.list.start  */
  YYSYMBOL_267_statement_math_precision_list_append = 267, /* statement.math.precision.list.append  */
  YYSYMBOL_268_statement_signal_pattern_rule_list = 268, /* statement.signal.pattern.rule.list  */
  YYSYMBOL_269_statement_signal_pattern_rule_list_start = 269, /* statement.signal.pattern.rule.list.start  */
  YYSYMBOL_270_statement_signal_pattern_rule_list_append = 270, /* statement.signal.pattern.rule.list.append  */
  YYSYMBOL_271_statement_signal_pattern_rule = 271 /* statement.signal.pattern.rule  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   754

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  300
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  565

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   391


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   356,   356,   360,   371,   375,   376,   377,   378,   379,
     380,   383,   384,   387,   390,   393,   396,   397,   400,   401,
     404,   407,   412,   417,   418,   421,   428,   429,   430,   431,
     436,   441,   442,   443,   444,   445,   448,   449,   452,   455,
     458,   461,   466,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   490,
     492,   495,   500,   503,   504,   505,   506,   509,   510,   511,
     512,   513,   514,   519,   520,   521,   522,   523,   524,   527,
     528,   529,   532,   533,   538,   541,   542,   547,   552,   557,
     562,   569,   574,   575,   578,   581,   586,   589,   592,   597,
     598,   601,   604,   607,   611,   614,   620,   625,   626,   627,
     628,   629,   632,   633,   634,   635,   636,   637,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   651,   652,   653,
     656,   657,   658,   659,   660,   661,   662,   663,   666,   667,
     670,   671,   672,   673,   674,   675,   678,   679,   680,   681,
     684,   685,   686,   687,   688,   689,   690,   695,   700,   707,
     708,   709,   712,   713,   714,   717,   718,   719,   722,   723,
     724,   725,   726,   727,   734,   735,   736,   737,   738,   743,
     744,   745,   750,   751,   756,   759,   762,   763,   768,   769,
     770,   771,   772,   773,   776,   779,   782,   783,   788,   789,
     792,   795,   800,   803,   806,   807,   810,   813,   816,   819,
     822,   827,   828,   829,   832,   833,   836,   841,   850,   851,
     854,   857,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   872,   875,   878,   881,   886,   891,   896,   899,   902,
     905,   910,   917,   922,   925,   928,   931,   934,   937,   942,
     947,   954,   957,   965,   966,   967,   968,   969,   974,   975,
     976,   979,   988,   994,   999,  1005,  1006,  1007,  1008,  1011,
    1016,  1024,  1029,  1039,  1045,  1051,  1059,  1065,  1071,  1076,
    1081,  1082,  1083,  1084,  1087,  1092,  1100,  1105,  1115,  1116,
    1117,  1118,  1121,  1122,  1125,  1128,  1135,  1136,  1139,  1142,
    1145
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SPLIT", "MIX", "SEQ",
  "COMMA", "REC", "LT", "LE", "EQ", "GT", "GE", "NE", "ADD", "SUB", "OR",
  "MUL", "DIV", "MOD", "AND", "XOR", "LSH", "RSH", "POWOP", "FDELAY",
  "DELAY1", "MEM", "PREFIX", "INTCAST", "FLOATCAST", "ANYCAST",
  "FFUNCTION", "FCONSTANT", "FVARIABLE", "BUTTON", "CHECKBOX", "VSLIDER",
  "HSLIDER", "NENTRY", "VGROUP", "HGROUP", "TGROUP", "HBARGRAPH",
  "VBARGRAPH", "SOUNDFILE", "ATTACH", "ACOS", "ASIN", "ATAN", "ATAN2",
  "COS", "SIN", "TAN", "EXP", "LOG", "LOG10", "POWFUN", "SQRT", "ABS",
  "MIN", "MAX", "FMOD", "REMAINDER", "FLOOR", "CEIL", "RINT", "RDTBL",
  "RWTBL", "SELECT2", "SELECT3", "INT", "FLOAT", "LAMBDA", "DOT", "WIRE",
  "CUT", "ENDDEF", "VIRG", "LPAR", "RPAR", "LBRAQ", "RBRAQ", "LCROC",
  "RCROC", "WITH", "LETREC", "WHERE", "DEF", "IMPORT", "COMPONENT",
  "LIBRARY", "ENVIRONMENT", "WAVEFORM", "ROUTE", "ENABLE", "CONTROL",
  "ITERATE_PARALLEL", "ISEQ", "ISUM", "IPROD", "INPUTS", "OUTPUTS",
  "STRING", "TAGSTRING", "IDENT", "EXTRA", "DECLARE", "CASE", "ARROW",
  "ASSERTBOUNDS", "LOWEST", "HIGHEST", "FLOATMODE", "DOUBLEMODE",
  "QUADMODE", "FIXEDPOINTMODE", "BDOC", "EDOC", "BEQN", "EEQN", "BDGM",
  "EDGM", "BLST", "ELST", "BMETADATA", "EMETADATA", "DOCCHAR", "NOTICE",
  "LISTING", "LSTTRUE", "LSTFALSE", "LSTDEPENDENCIES", "LSTMDOCTAGS",
  "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "$accept", "program", "doc",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-494)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -55,   -47,  -494,   -65,  -494,  -494,  -494,  -494,   347,
      54,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,   -51,
    -494,    33,  -494,  -494,  -494,  -494,  -494,    80,  -494,  -494,
    -494,   -10,  -494,   -18,   512,   512,   132,   -65,  -494,  -494,
     -28,     0,  -494,  -494,  -494,  -494,  -494,  -494,   512,   512,
    -494,    80,  -494,  -494,  -494,    23,  -494,    22,    10,  -494,
    -494,  -494,  -494,  -494,  -494,   -14,    -9,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,    65,    77,    83,    96,   102,   110,   124,   141,   148,
     161,   163,   164,   165,   168,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,   170,  -494,  -494,   512,   172,   173,   130,   174,
     193,  -494,  -494,   197,   201,   205,   210,   211,   216,   200,
    -494,  -494,  -494,     9,  -494,   435,  -494,  -494,  -494,  -494,
    -494,   617,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,     6,  -494,    18,   166,   176,
     254,  -494,   177,  -494,  -494,   435,    20,    29,  -494,   235,
    -494,   237,  -494,  -494,  -494,  -494,  -494,   154,   154,   154,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   218,    24,   -10,   -10,    80,   362,   512,   218,   218,
     218,   218,   512,   512,   257,   512,   260,   270,  -494,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,  -494,   218,   512,    85,  -494,   185,   225,   227,  -494,
    -494,  -494,   512,   264,  -494,  -494,  -494,   267,   369,   -65,
     -65,   299,   309,   400,   403,   408,   413,   415,   417,   442,
     445,   448,    37,  -494,  -494,  -494,  -494,   375,   377,    63,
     -14,    -5,  -494,  -494,    25,  -494,  -494,  -494,   477,   453,
     454,   455,   463,    74,   106,   512,   -43,  -494,  -494,  -494,
     465,    85,    16,   435,   435,   136,  -494,   636,   636,   636,
     636,   636,   636,   373,   373,   373,   358,   358,   358,   358,
     358,   358,   358,   379,   348,  -494,    38,  -494,    58,  -494,
    -494,  -494,  -494,    85,    35,    35,    35,   435,   512,  -494,
      44,   103,   470,   471,  -494,  -494,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   218,   404,  -494,  -494,  -494,
     362,  -494,   512,   512,   512,   512,   512,  -494,  -494,    39,
    -494,  -494,   100,   409,   218,  -494,    15,  -494,  -494,  -494,
     418,  -494,  -494,  -494,    85,  -494,  -494,  -494,   351,   402,
     407,   152,   267,   387,  -494,  -494,   580,   103,   103,   488,
     493,   498,   202,   213,   220,   589,   594,   266,  -494,   510,
    -494,    45,   678,   683,   698,   717,   481,  -494,  -494,  -494,
    -494,    85,  -494,   512,  -494,  -494,  -494,  -494,  -494,    72,
    -494,  -494,  -494,  -494,  -494,    40,  -494,  -494,   -10,   535,
     536,   512,   512,   512,  -494,  -494,  -494,   512,   512,  -494,
     512,   512,  -494,   512,   512,   512,   512,   512,   120,   182,
     267,   399,   372,  -494,   538,  -494,  -494,   722,   727,   732,
     330,   335,   222,   224,   233,   240,   242,   244,   206,  -494,
    -494,   540,  -494,    50,  -494,  -494,   512,   512,   512,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,   434,  -494,
     737,   742,   747,  -494,    59,   512,   512,   512,  -494,   340,
     355,   366,  -494,  -494,  -494
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,   277,     0,   288,   289,   290,   291,    10,
       0,   284,   253,   258,   259,   260,   254,   255,   256,     0,
     257,     0,   280,   281,   282,   283,   294,     0,   292,   293,
     264,     0,   276,     0,     0,     0,     0,     0,    11,    15,
       0,     4,     5,     6,     7,     8,     9,     1,     0,     0,
     286,     0,   285,   295,   185,     0,   184,     0,     0,   112,
     113,   116,   114,   115,   117,   130,   131,   169,   132,   133,
     134,   168,   170,   138,   139,   143,   167,   165,   166,   206,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   150,   151,   152,   153,
     154,   155,   156,   140,   141,   142,   144,   145,   118,   119,
     120,   135,   136,   121,   122,   126,   214,   215,   171,   172,
     182,   183,     0,   194,   195,     0,     0,     0,     0,     0,
       0,   163,   164,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,    48,    29,    33,    34,    31,    32,
      49,    35,    43,    44,    45,    63,    64,    65,    66,    47,
      46,    50,    51,    52,    53,    54,    27,    55,    56,   109,
     111,   107,   127,   128,   129,   108,   110,    57,    28,    58,
     159,   160,   161,    60,   174,   175,   177,   189,   190,   176,
     204,   205,   192,   193,   213,   212,   211,   178,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   180,   179,
     181,   188,   191,    26,    59,     0,    17,     0,     0,     0,
       0,    18,     0,   275,    12,    36,     0,     0,   287,     0,
     273,     0,   146,   147,   148,   149,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,     0,     0,    14,     0,     0,     0,    16,
      19,    25,     0,     0,   262,   279,   274,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,   157,     0,     0,     0,
       0,     0,   201,   200,     0,   202,   198,   199,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   297,   298,
     158,     0,     0,    41,    38,    40,    39,    73,    74,    77,
      75,    76,    78,    67,    68,    80,    69,    70,    71,    79,
      81,    82,    83,    72,    85,    62,     0,   269,     0,   265,
     266,   267,   268,     0,     0,     0,     0,    37,     0,   278,
       0,     0,     0,     0,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,   106,    42,
       0,   217,     0,     0,     0,     0,     0,   251,   252,     0,
     173,   299,     0,     0,     0,    96,     0,    99,   100,   101,
       0,    84,    61,   271,     0,   270,    23,    24,     0,     0,
       0,     0,     0,     0,   186,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
     203,     0,     0,     0,     0,     0,     0,   263,   104,   105,
      97,     0,   102,     0,   272,    20,    21,    22,   261,     0,
     208,   246,   220,   196,   197,     0,   218,   219,     0,     0,
       0,     0,     0,     0,   237,   238,   239,     0,     0,   216,
       0,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
     103,     0,   247,     0,   221,   242,     0,     0,     0,   241,
     240,    91,   210,    87,    88,    89,    90,   300,     0,   244,
       0,     0,     0,   248,     0,     0,     0,     0,   245,     0,
       0,     0,   234,   235,   236
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,   401,
    -168,  -494,    12,  -494,   -48,  -188,  -494,  -494,  -494,  -494,
    -494,   390,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,   268,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -249,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -246,   634,  -171,  -216,  -494,  -494,  -494,
     181,  -494,   285,  -494,  -494,  -233,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -493,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,  -494,
    -494,  -494,  -494,  -494,   -13,  -267,  -494,  -494,  -494,  -494,
    -340,  -494,  -494,  -494,  -494,  -494,  -494,  -494,   -24,     2,
    -421,  -494,   443,  -494,  -494,  -494,  -494,   -26,     3,  -494,
    -494,  -494,  -494,  -494,   353
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    40,    41,    42,    43,    44,    45,   220,   221,
     438,    46,   143,   144,   145,   226,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   322,   323,   324,   166,
     426,   427,   428,   429,   430,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    57,    55,   446,   186,   187,   188,
     482,   334,   335,   336,   337,   189,   190,   191,   484,   192,
     193,   194,   195,   196,   485,   486,   487,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   308,
     209,   210,   211,   212,    11,    12,    13,    14,   213,    15,
     378,   379,   380,   381,   382,    16,    17,    18,    33,   214,
     390,    20,    21,    22,    23,    24,    25,    26,   383,    28,
      29,   346,   347,   348,   349
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     225,    53,    19,    27,   307,   309,   310,   332,    50,    58,
     333,   422,   265,   222,    52,   265,   423,   423,   533,    -3,
       1,   479,    30,    19,    51,    53,   302,   377,    48,    19,
     265,   410,    31,    -2,     1,   265,   345,    49,   228,   420,
      32,   424,   424,   405,   302,   302,   512,   215,   269,   270,
     271,   501,   272,    19,    47,   554,   512,   232,   233,     1,
     442,   227,   234,   235,     1,   512,   234,   235,   236,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     265,     1,   327,   328,   377,    56,     1,    32,   510,   531,
     223,   266,   267,    54,   266,   267,     3,   470,   425,   230,
     303,     1,   471,   229,   326,   376,   304,   411,     2,   266,
     267,   433,   265,    56,   266,   267,   435,   406,   431,   466,
     513,     1,     2,   443,     3,   502,     4,   224,   295,   268,
     549,   508,     5,     6,     7,     8,     9,   252,     3,   558,
       4,   271,   432,   272,   237,   409,     5,     6,     7,     8,
       9,   511,     2,   296,   417,   433,   238,   419,   265,   266,
     267,   332,   239,     3,   333,   436,   437,   474,     3,     2,
       4,     5,     6,     7,     8,   240,     5,     6,     7,     8,
       9,   241,   467,    79,    80,     3,   418,     4,   265,   242,
       3,   266,   267,     5,     6,     7,     8,     9,     5,     6,
       7,     8,   529,   243,   377,     3,   444,   445,   265,   338,
     483,   255,   265,     5,     6,     7,     8,   439,   440,   265,
     244,   353,   354,   355,   356,     3,   265,   245,   265,   478,
     265,   489,   490,     5,     6,     7,     8,   266,   267,   265,
     246,   433,   247,   248,   249,   225,   265,   250,   265,   251,
     265,   253,   254,   325,   387,   256,   216,    19,    27,   530,
     339,   340,   341,   342,   217,   218,   219,   266,   267,   269,
     270,   271,   257,   272,   343,   344,   258,   350,   483,   483,
     259,   264,   494,   547,   260,   392,   393,   266,   267,   261,
     262,   266,   267,   495,   375,   263,    19,   225,   266,   267,
     496,   297,   541,   301,   542,   266,   267,   266,   267,   266,
     267,   298,   305,   543,   306,   483,    50,   514,   266,   267,
     544,   384,   545,     3,   546,   266,   267,   266,   267,   266,
     267,    19,    51,   269,   270,   271,   345,   272,   269,   270,
     271,   351,   272,   269,   270,   271,   499,   272,   449,   450,
     451,   352,   388,    19,   455,   456,   457,    53,   269,   270,
     271,   385,   272,   386,   461,   462,   463,   464,   465,   269,
     270,   271,   389,   272,   291,   391,   330,   331,   299,   394,
      19,   434,   289,   290,   291,    19,   217,   218,   219,   395,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     441,    79,    80,   480,   290,   291,   396,   458,    53,   397,
     539,   452,   453,   454,   398,   540,    79,    80,   480,   399,
     562,   400,   292,   401,    19,   434,   469,   293,    79,    80,
     480,   294,   292,   120,   121,   563,    19,   293,   269,   270,
     271,   294,   272,   517,   518,   519,   564,   292,   402,   520,
     521,   403,   293,   292,   404,   407,   294,   408,   293,   413,
     414,   415,   294,    79,    80,   480,    34,   481,    35,   416,
      36,   265,    37,    19,    38,    39,   447,   448,   459,   532,
     269,   270,   271,   412,   272,   509,   468,   475,   550,   551,
     552,   269,   270,   271,   491,   272,   269,   270,   271,   492,
     272,   269,   270,   271,   493,   272,   473,   559,   560,   561,
      19,   434,   522,   523,   553,   524,   525,   526,   527,   528,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   476,    77,
      78,    79,    80,   477,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   488,   123,   124,   500,
     507,   125,   269,   270,   271,   497,   272,   269,   270,   271,
     498,   272,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   515,   516,     3,   535,   548,
     139,   300,   140,   141,   142,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    -4,    -4,    -4,    -4,    -4,    -4,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   269,   270,   271,   503,   272,   269,   270,   271,   504,
     272,   292,   231,   534,   472,   460,   293,     0,   329,   421,
     294,   269,   270,   271,   505,   272,     0,     0,     0,     0,
     292,     0,     0,     0,     0,   293,     0,     0,     0,   294,
     269,   270,   271,   506,   272,   269,   270,   271,   536,   272,
     269,   270,   271,   537,   272,   269,   270,   271,   538,   272,
     269,   270,   271,   555,   272,   269,   270,   271,   556,   272,
     269,   270,   271,   557,   272
};

static const yytype_int16 yycheck[] =
{
      48,    27,     0,     0,   237,   238,   239,   256,    21,    33,
     256,   351,     6,    37,    27,     6,     1,     1,   511,     0,
       1,   442,    77,    21,    21,    51,     6,   294,    79,    27,
       6,     6,    79,     0,     1,     6,    79,    88,    51,    82,
     105,    26,    26,     6,     6,     6,     6,    35,     3,     4,
       5,     6,     7,    51,     0,   548,     6,    71,    72,     1,
      16,    49,    71,    72,     1,     6,    71,    72,    66,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       6,     1,   253,   254,   351,   103,     1,   105,    16,   510,
     118,    85,    86,   103,    85,    86,   105,    82,    82,    77,
      80,     1,    87,    80,    80,   293,    77,    82,    89,    85,
      86,   378,     6,   103,    85,    86,   383,    80,    80,    80,
      80,     1,    89,    79,   105,    80,   107,   127,   122,   120,
      80,   471,   113,   114,   115,   116,   117,   125,   105,    80,
     107,     5,    84,     7,    79,    82,   113,   114,   115,   116,
     117,    79,    89,   135,    80,   422,    79,   345,     6,    85,
      86,   410,    79,   105,   410,   130,   131,   434,   105,    89,
     107,   113,   114,   115,   116,    79,   113,   114,   115,   116,
     117,    79,    82,    29,    30,   105,    80,   107,     6,    79,
     105,    85,    86,   113,   114,   115,   116,   117,   113,   114,
     115,   116,    82,    79,   471,   105,   103,   104,     6,   257,
     443,    81,     6,   113,   114,   115,   116,   385,   386,     6,
      79,   269,   270,   271,   272,   105,     6,    79,     6,    77,
       6,   447,   448,   113,   114,   115,   116,    85,    86,     6,
      79,   508,    79,    79,    79,   293,     6,    79,     6,    79,
       6,    79,    79,   251,   302,    81,   124,   255,   255,    77,
     258,   259,   260,   261,   132,   133,   134,    85,    86,     3,
       4,     5,    79,     7,   262,   263,    79,   265,   511,   512,
      79,    81,    80,    77,    79,   309,   310,    85,    86,    79,
      79,    85,    86,    80,   292,    79,   294,   345,    85,    86,
      80,   135,    80,   126,    80,    85,    86,    85,    86,    85,
      86,   135,    77,    80,    77,   548,   329,   488,    85,    86,
      80,   136,    80,   105,    80,    85,    86,    85,    86,    85,
      86,   329,   329,     3,     4,     5,    79,     7,     3,     4,
       5,    81,     7,     3,     4,     5,    80,     7,   396,   397,
     398,    81,    88,   351,   402,   403,   404,   383,     3,     4,
       5,   136,     7,   136,   412,   413,   414,   415,   416,     3,
       4,     5,   105,     7,    26,     6,    14,    15,   124,    80,
     378,   378,    24,    25,    26,   383,   132,   133,   134,    80,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     388,    29,    30,    31,    25,    26,     6,   405,   434,     6,
      80,   399,   400,   401,     6,    80,    29,    30,    31,     6,
      80,     6,    74,     6,   422,   422,   424,    79,    29,    30,
      31,    83,    74,    71,    72,    80,   434,    79,     3,     4,
       5,    83,     7,   491,   492,   493,    80,    74,     6,   497,
     498,     6,    79,    74,     6,    80,    83,    80,    79,     6,
       6,     6,    83,    29,    30,    31,   119,    80,   121,     6,
     123,     6,   125,   471,   127,   128,     6,     6,    74,    80,
       3,     4,     5,     6,     7,   473,    77,   136,   536,   537,
     538,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    88,   555,   556,   557,
     508,   508,   500,   501,    80,   503,   504,   505,   506,   507,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   136,    27,
      28,    29,    30,   136,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     6,    75,    76,    79,
     109,    79,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    80,    80,   105,    80,    79,
     108,   220,   110,   111,   112,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    74,    58,   512,   426,   410,    79,    -1,   255,   346,
      83,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,    89,   105,   107,   113,   114,   115,   116,   117,
     138,   241,   242,   243,   244,   246,   252,   253,   254,   256,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
      77,    79,   105,   255,   119,   121,   123,   125,   127,   128,
     139,   140,   141,   142,   143,   144,   148,     0,    79,    88,
     241,   265,   241,   264,   103,   202,   103,   201,   255,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    27,    28,    29,
      30,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    75,    76,    79,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   108,
     110,   111,   112,   149,   150,   151,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   176,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   204,   205,   206,   212,
     213,   214,   216,   217,   218,   219,   220,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   237,
     238,   239,   240,   245,   256,   149,   124,   132,   133,   134,
     145,   146,   255,   118,   127,   151,   152,   149,   241,    80,
      77,   201,    71,    72,    71,    72,   256,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,   149,    79,    79,    81,    81,    79,    79,    79,
      79,    79,    79,    79,    81,     6,    85,    86,   120,     3,
       4,     5,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    74,    79,    83,   122,   135,   135,   135,   124,
     146,   126,     6,    80,    77,    77,    77,   212,   236,   212,
     212,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   173,   174,   175,   256,    80,   202,   202,   259,
      14,    15,   190,   200,   208,   209,   210,   211,   151,   256,
     256,   256,   256,   149,   149,    79,   268,   269,   270,   271,
     149,    81,    81,   151,   151,   151,   151,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   256,   152,   242,   247,   248,
     249,   250,   251,   265,   136,   136,   136,   151,    88,   105,
     257,     6,   255,   255,    80,    80,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,    80,    80,    80,    82,
       6,    82,     6,     6,     6,     6,     6,    80,    80,   152,
      82,   271,   247,     1,    26,    82,   177,   178,   179,   180,
     181,    80,    84,   242,   265,   242,   130,   131,   147,   147,
     147,   149,    16,    79,   103,   104,   203,     6,     6,   151,
     151,   151,   149,   149,   149,   151,   151,   151,   256,    74,
     209,   151,   151,   151,   151,   151,    80,    82,    77,   256,
      82,    87,   180,    88,   242,   136,   136,   136,    77,   257,
      31,    80,   207,   212,   215,   221,   222,   223,     6,   203,
     203,     6,     6,     6,    80,    80,    80,     6,     6,    80,
      79,     6,    80,     6,     6,     6,     6,   109,   247,   149,
      16,    79,     6,    80,   202,    80,    80,   151,   151,   151,
     151,   151,   149,   149,   149,   149,   149,   149,   149,    82,
      77,   257,    80,   221,   207,    80,     6,     6,     6,    80,
      80,    80,    80,    80,    80,    80,    80,    77,    79,    80,
     151,   151,   151,    80,   221,     6,     6,     6,    80,   151,
     151,   151,    80,    80,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   137,   138,   138,   139,   139,   139,   139,   139,   139,
     139,   140,   140,   141,   142,   143,   144,   144,   145,   145,
     146,   146,   146,   147,   147,   148,   149,   149,   149,   149,
     150,   151,   151,   151,   151,   151,   152,   152,   153,   154,
     155,   156,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   160,   161,   161,   161,   161,   162,   162,   162,
     162,   162,   162,   163,   163,   163,   163,   163,   163,   164,
     164,   164,   165,   165,   166,   167,   167,   168,   169,   170,
     171,   172,   173,   173,   174,   175,   176,   176,   176,   177,
     177,   178,   179,   180,   180,   181,   182,   183,   183,   183,
     183,   183,   184,   184,   184,   184,   184,   184,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   186,   186,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     189,   189,   189,   189,   189,   189,   190,   190,   190,   190,
     191,   191,   191,   191,   191,   191,   191,   192,   193,   194,
     194,   194,   195,   195,   195,   196,   196,   196,   197,   197,
     197,   197,   197,   197,   198,   198,   198,   198,   198,   199,
     199,   199,   200,   200,   201,   202,   203,   203,   204,   204,
     204,   204,   204,   204,   205,   206,   207,   207,   208,   208,
     209,   209,   210,   211,   212,   212,   213,   214,   215,   216,
     216,   217,   217,   217,   218,   218,   219,   220,   221,   221,
     222,   223,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   236,   236,   236,   236,   236,   237,
     238,   239,   240,   241,   241,   241,   241,   241,   242,   242,
     242,   243,   244,   245,   246,   247,   247,   247,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   259,   259,   259,   260,   261,   262,   263,   264,   264,
     264,   264,   265,   265,   266,   267,   268,   268,   269,   270,
     271
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
       1,     7,     4,     5,     2,     1,     1,     1,     1,     1,
       2,     2,     3,     4,     5,     3,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement.list  */
#line 356 "faustparser.y"
                               {
			(yyval.exp) = (yyvsp[0].exp);
			gGlobal->gResult = formatDefinitions((yyval.exp));
		}
#line 1881 "faustparser.cpp"
    break;

  case 3: /* program: %empty  */
#line 360 "faustparser.y"
                { (yyval.exp) = gGlobal->nil; }
#line 1887 "faustparser.cpp"
    break;

  case 4: /* doc: doc.text  */
#line 371 "faustparser.y"
                         {
			(yyval.exp) = docTxt((yyvsp[0].cppstr)->c_str());
			delete (yyvsp[0].cppstr);
		}
#line 1896 "faustparser.cpp"
    break;

  case 5: /* doc: doc.equation  */
#line 375 "faustparser.y"
                 { (yyval.exp) = docEqn((yyvsp[0].exp)); }
#line 1902 "faustparser.cpp"
    break;

  case 6: /* doc: doc.diagram  */
#line 376 "faustparser.y"
                { (yyval.exp) = docDgm((yyvsp[0].exp)); }
#line 1908 "faustparser.cpp"
    break;

  case 7: /* doc: doc.notice  */
#line 377 "faustparser.y"
               { (yyval.exp) = docNtc(); }
#line 1914 "faustparser.cpp"
    break;

  case 8: /* doc: doc.list  */
#line 378 "faustparser.y"
             { (yyval.exp) = docLst(); }
#line 1920 "faustparser.cpp"
    break;

  case 9: /* doc: doc.metadata  */
#line 379 "faustparser.y"
                 { (yyval.exp) = docMtd((yyvsp[0].exp)); }
#line 1926 "faustparser.cpp"
    break;

  case 10: /* doc: %empty  */
#line 380 "faustparser.y"
                      { (yyval.exp) = gGlobal->nil; }
#line 1932 "faustparser.cpp"
    break;

  case 11: /* doc.text: DOCCHAR  */
#line 383 "faustparser.y"
              { (yyval.cppstr) = new string(yytext); }
#line 1938 "faustparser.cpp"
    break;

  case 12: /* doc.text: doc.text DOCCHAR  */
#line 384 "faustparser.y"
                              { (yyval.cppstr) = &((yyvsp[-1].cppstr)->append(yytext)); }
#line 1944 "faustparser.cpp"
    break;

  case 13: /* doc.equation: BEQN expression EEQN  */
#line 387 "faustparser.y"
                           { (yyval.exp) = (yyvsp[-1].exp); }
#line 1950 "faustparser.cpp"
    break;

  case 14: /* doc.diagram: BDGM expression EDGM  */
#line 390 "faustparser.y"
                           { (yyval.exp) = (yyvsp[-1].exp); }
#line 1956 "faustparser.cpp"
    break;

  case 15: /* doc.notice: NOTICE  */
#line 393 "faustparser.y"
             { }
#line 1962 "faustparser.cpp"
    break;

  case 16: /* doc.list: BLST doc.attribute.list ELST  */
#line 396 "faustparser.y"
                                   { }
#line 1968 "faustparser.cpp"
    break;

  case 17: /* doc.list: BLST ELST  */
#line 397 "faustparser.y"
                                 { }
#line 1974 "faustparser.cpp"
    break;

  case 18: /* doc.attribute.list: doc.attribute.definition  */
#line 400 "faustparser.y"
                                 {}
#line 1980 "faustparser.cpp"
    break;

  case 19: /* doc.attribute.list: doc.attribute.list doc.attribute.definition  */
#line 401 "faustparser.y"
                                                    { }
#line 1986 "faustparser.cpp"
    break;

  case 20: /* doc.attribute.definition: LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ  */
#line 404 "faustparser.y"
                                                            {
          gGlobal->gLstDependenciesSwitch = (yyvsp[-1].b);
        }
#line 1994 "faustparser.cpp"
    break;

  case 21: /* doc.attribute.definition: LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ  */
#line 407 "faustparser.y"
                                                        {
          gGlobal->gStripDocSwitch = (yyvsp[-1].b);
          gGlobal->gStripDocSwitch ? gGlobal->gStripDocSwitch=false
                                   : gGlobal->gStripDocSwitch=true;
        }
#line 2004 "faustparser.cpp"
    break;

  case 22: /* doc.attribute.definition: LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ  */
#line 412 "faustparser.y"
                                                           {
          gGlobal->gLstDistributedSwitch = (yyvsp[-1].b);
        }
#line 2012 "faustparser.cpp"
    break;

  case 23: /* doc.attribute.value: LSTTRUE  */
#line 417 "faustparser.y"
                { (yyval.b) = true; }
#line 2018 "faustparser.cpp"
    break;

  case 24: /* doc.attribute.value: LSTFALSE  */
#line 418 "faustparser.y"
                 { (yyval.b) = false; }
#line 2024 "faustparser.cpp"
    break;

  case 25: /* doc.metadata: BMETADATA statement.identifier EMETADATA  */
#line 421 "faustparser.y"
                                                       { (yyval.exp) = (yyvsp[-1].exp); }
#line 2030 "faustparser.cpp"
    break;

  case 30: /* expression.component: COMPONENT LPAR primitive.string.unquoted RPAR  */
#line 436 "faustparser.y"
                                                    { (yyval.exp) = boxComponent((yyvsp[-1].exp)); }
#line 2036 "faustparser.cpp"
    break;

  case 36: /* expression.composition.list: expression.composition  */
#line 448 "faustparser.y"
                               { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 2042 "faustparser.cpp"
    break;

  case 37: /* expression.composition.list: expression.composition.list COMMA expression.composition  */
#line 449 "faustparser.y"
                                                                              { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 2048 "faustparser.cpp"
    break;

  case 38: /* expression.composition.mix: expression.composition MIX expression.composition  */
#line 452 "faustparser.y"
                                                                    { (yyval.exp) = boxMerge((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2054 "faustparser.cpp"
    break;

  case 39: /* expression.composition.record: expression.composition REC expression.composition  */
#line 455 "faustparser.y"
                                                                    { (yyval.exp) = boxRec((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2060 "faustparser.cpp"
    break;

  case 40: /* expression.composition.sequence: expression.composition SEQ expression.composition  */
#line 458 "faustparser.y"
                                                                    { (yyval.exp) = boxSeq((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2066 "faustparser.cpp"
    break;

  case 41: /* expression.composition.split: expression.composition SPLIT expression.composition  */
#line 461 "faustparser.y"
                                                                      { (yyval.exp) = boxSplit((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2072 "faustparser.cpp"
    break;

  case 42: /* expression.environment: ENVIRONMENT LBRAQ statement.list RBRAQ  */
#line 466 "faustparser.y"
                                             {
        (yyval.exp) = boxWithLocalDef(boxEnvironment(),formatDefinitions((yyvsp[-1].exp)));
      }
#line 2080 "faustparser.cpp"
    break;

  case 61: /* expression.infix.definitions.local: expression.infix LCROC statement.definition.list RCROC  */
#line 495 "faustparser.y"
                                                                        {
        (yyval.exp) = boxModifLocalDef((yyvsp[-3].exp),formatDefinitions((yyvsp[-1].exp)));
      }
#line 2088 "faustparser.cpp"
    break;

  case 62: /* expression.infix.environment.access: expression.infix DOT statement.identifier.box  */
#line 500 "faustparser.y"
                                                              { (yyval.exp) = boxAccess((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2094 "faustparser.cpp"
    break;

  case 67: /* expression.infix.math.algebra: expression.infix ADD expression.infix  */
#line 509 "faustparser.y"
                                                        { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigAdd)); }
#line 2100 "faustparser.cpp"
    break;

  case 68: /* expression.infix.math.algebra: expression.infix SUB expression.infix  */
#line 510 "faustparser.y"
                                                        { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigSub)); }
#line 2106 "faustparser.cpp"
    break;

  case 69: /* expression.infix.math.algebra: expression.infix MUL expression.infix  */
#line 511 "faustparser.y"
                                                        { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigMul)); }
#line 2112 "faustparser.cpp"
    break;

  case 70: /* expression.infix.math.algebra: expression.infix DIV expression.infix  */
#line 512 "faustparser.y"
                                                        { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigDiv)); }
#line 2118 "faustparser.cpp"
    break;

  case 71: /* expression.infix.math.algebra: expression.infix MOD expression.infix  */
#line 513 "faustparser.y"
                                                        { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigRem)); }
#line 2124 "faustparser.cpp"
    break;

  case 72: /* expression.infix.math.algebra: expression.infix POWOP expression.infix  */
#line 514 "faustparser.y"
                                                        {
        (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),gGlobal->gPowPrim->box());
      }
#line 2132 "faustparser.cpp"
    break;

  case 73: /* expression.infix.math.comparison: expression.infix LT expression.infix  */
#line 519 "faustparser.y"
                                                     { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigLT)); }
#line 2138 "faustparser.cpp"
    break;

  case 74: /* expression.infix.math.comparison: expression.infix LE expression.infix  */
#line 520 "faustparser.y"
                                                     { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigLE)); }
#line 2144 "faustparser.cpp"
    break;

  case 75: /* expression.infix.math.comparison: expression.infix GT expression.infix  */
#line 521 "faustparser.y"
                                                     { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigGT)); }
#line 2150 "faustparser.cpp"
    break;

  case 76: /* expression.infix.math.comparison: expression.infix GE expression.infix  */
#line 522 "faustparser.y"
                                                     { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigGE)); }
#line 2156 "faustparser.cpp"
    break;

  case 77: /* expression.infix.math.comparison: expression.infix EQ expression.infix  */
#line 523 "faustparser.y"
                                                     { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigEQ)); }
#line 2162 "faustparser.cpp"
    break;

  case 78: /* expression.infix.math.comparison: expression.infix NE expression.infix  */
#line 524 "faustparser.y"
                                                     { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigNE)); }
#line 2168 "faustparser.cpp"
    break;

  case 79: /* expression.infix.math.logic: expression.infix AND expression.infix  */
#line 527 "faustparser.y"
                                                      { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigAND)); }
#line 2174 "faustparser.cpp"
    break;

  case 80: /* expression.infix.math.logic: expression.infix OR expression.infix  */
#line 528 "faustparser.y"
                                                      { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigOR)); }
#line 2180 "faustparser.cpp"
    break;

  case 81: /* expression.infix.math.logic: expression.infix XOR expression.infix  */
#line 529 "faustparser.y"
                                                      { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigXOR)); }
#line 2186 "faustparser.cpp"
    break;

  case 82: /* expression.infix.math.shift: expression.infix LSH expression.infix  */
#line 532 "faustparser.y"
                                                      { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigLeftShift)); }
#line 2192 "faustparser.cpp"
    break;

  case 83: /* expression.infix.math.shift: expression.infix RSH expression.infix  */
#line 533 "faustparser.y"
                                                      {
        (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigARightShift));
      }
#line 2200 "faustparser.cpp"
    break;

  case 84: /* expression.infix.prefix: expression.infix LPAR expression.composition.list RPAR  */
#line 538 "faustparser.y"
                                                                   { (yyval.exp) = buildBoxAppl((yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2206 "faustparser.cpp"
    break;

  case 85: /* expression.infix.signal.delay: expression.infix FDELAY expression.infix  */
#line 541 "faustparser.y"
                                                         { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigDelay)); }
#line 2212 "faustparser.cpp"
    break;

  case 86: /* expression.infix.signal.delay: expression.infix DELAY1  */
#line 542 "faustparser.y"
                                   { (yyval.exp) = boxSeq((yyvsp[-1].exp),boxPrim1(sigDelay1)); }
#line 2218 "faustparser.cpp"
    break;

  case 87: /* expression.iterate.parallel: ITERATE_PARALLEL LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR  */
#line 547 "faustparser.y"
                                                                                                        {
        (yyval.exp) = boxIPar((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
      }
#line 2226 "faustparser.cpp"
    break;

  case 88: /* expression.iterate.sequence: ISEQ LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR  */
#line 552 "faustparser.y"
                                                                                            {
        (yyval.exp) = boxISeq((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
      }
#line 2234 "faustparser.cpp"
    break;

  case 89: /* expression.iterate.sum: ISUM LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR  */
#line 557 "faustparser.y"
                                                                                            {
        (yyval.exp) = boxISum((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
      }
#line 2242 "faustparser.cpp"
    break;

  case 90: /* expression.iterate.product: IPROD LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR  */
#line 562 "faustparser.y"
                                                                                             {
        (yyval.exp) = boxIProd((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
      }
#line 2250 "faustparser.cpp"
    break;

  case 91: /* expression.lambda: LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR  */
#line 569 "faustparser.y"
                                                                         {
        (yyval.exp) = buildBoxAbstr((yyvsp[-5].exp),(yyvsp[-1].exp));
      }
#line 2258 "faustparser.cpp"
    break;

  case 94: /* expression.lambda.params.start: statement.identifier.box  */
#line 578 "faustparser.y"
                                 { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 2264 "faustparser.cpp"
    break;

  case 95: /* expression.lambda.params.append: expression.lambda.params COMMA statement.identifier.box  */
#line 581 "faustparser.y"
                                                                             { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 2270 "faustparser.cpp"
    break;

  case 96: /* expression.letrec: expression LETREC LBRAQ RBRAQ  */
#line 586 "faustparser.y"
                                                                          {
			(yyval.exp) = boxWithRecDef((yyvsp[-3].exp),formatDefinitions(gGlobal->nil), gGlobal->nil);
		}
#line 2278 "faustparser.cpp"
    break;

  case 97: /* expression.letrec: expression LETREC LBRAQ expression.letrec.list RBRAQ  */
#line 589 "faustparser.y"
                                                              {
			(yyval.exp) = boxWithRecDef((yyvsp[-4].exp),formatDefinitions((yyvsp[-1].exp)), gGlobal->nil);
		}
#line 2286 "faustparser.cpp"
    break;

  case 98: /* expression.letrec: expression LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ  */
#line 592 "faustparser.y"
                                                                                              {
			(yyval.exp) = boxWithRecDef((yyvsp[-6].exp),formatDefinitions((yyvsp[-3].exp)),formatDefinitions((yyvsp[-3].exp)));
		}
#line 2294 "faustparser.cpp"
    break;

  case 101: /* expression.letrec.list.start: expression.letrec.equation  */
#line 601 "faustparser.y"
                                         { (yyval.exp) = cons((yyvsp[0].exp), gGlobal->nil); }
#line 2300 "faustparser.cpp"
    break;

  case 102: /* expression.letrec.list.append: expression.letrec.list expression.letrec.equation  */
#line 604 "faustparser.y"
                                                                       { (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-1].exp)); }
#line 2306 "faustparser.cpp"
    break;

  case 103: /* expression.letrec.equation: expression.letrec.equation.name DEF expression ENDDEF  */
#line 607 "faustparser.y"
                                                                      {
        (yyval.exp) = cons((yyvsp[-3].exp),cons(gGlobal->nil,(yyvsp[-1].exp)));
        setDefProp((yyvsp[-3].exp), yyfilename, yylineno);
      }
#line 2315 "faustparser.cpp"
    break;

  case 104: /* expression.letrec.equation: error ENDDEF  */
#line 611 "faustparser.y"
                   { (yyval.exp) = gGlobal->nil; yyerr++; }
#line 2321 "faustparser.cpp"
    break;

  case 105: /* expression.letrec.equation.name: DELAY1 statement.identifier.box  */
#line 614 "faustparser.y"
                                        { (yyval.exp)=(yyvsp[0].exp); }
#line 2327 "faustparser.cpp"
    break;

  case 106: /* expression.library: LIBRARY LPAR primitive.string.unquoted RPAR  */
#line 620 "faustparser.y"
                                                  { (yyval.exp) = boxLibrary((yyvsp[-1].exp)); }
#line 2333 "faustparser.cpp"
    break;

  case 112: /* expression.math.comparison: LT  */
#line 632 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigLT); }
#line 2339 "faustparser.cpp"
    break;

  case 113: /* expression.math.comparison: LE  */
#line 633 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigLE); }
#line 2345 "faustparser.cpp"
    break;

  case 114: /* expression.math.comparison: GT  */
#line 634 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigGT); }
#line 2351 "faustparser.cpp"
    break;

  case 115: /* expression.math.comparison: GE  */
#line 635 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigGE); }
#line 2357 "faustparser.cpp"
    break;

  case 116: /* expression.math.comparison: EQ  */
#line 636 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigEQ); }
#line 2363 "faustparser.cpp"
    break;

  case 117: /* expression.math.comparison: NE  */
#line 637 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigNE); }
#line 2369 "faustparser.cpp"
    break;

  case 118: /* expression.math.rounding: ABS  */
#line 640 "faustparser.y"
              { (yyval.exp) = gGlobal->gAbsPrim->box(); }
#line 2375 "faustparser.cpp"
    break;

  case 119: /* expression.math.rounding: MIN  */
#line 641 "faustparser.y"
              { (yyval.exp) = gGlobal->gMinPrim->box(); }
#line 2381 "faustparser.cpp"
    break;

  case 120: /* expression.math.rounding: MAX  */
#line 642 "faustparser.y"
              { (yyval.exp) = gGlobal->gMaxPrim->box(); }
#line 2387 "faustparser.cpp"
    break;

  case 121: /* expression.math.rounding: FLOOR  */
#line 643 "faustparser.y"
                { (yyval.exp) = gGlobal->gFloorPrim->box(); }
#line 2393 "faustparser.cpp"
    break;

  case 122: /* expression.math.rounding: CEIL  */
#line 644 "faustparser.y"
               { (yyval.exp) = gGlobal->gCeilPrim->box(); }
#line 2399 "faustparser.cpp"
    break;

  case 123: /* expression.math.rounding: ASSERTBOUNDS  */
#line 645 "faustparser.y"
                       { (yyval.exp) = boxPrim3(sigAssertBounds);}
#line 2405 "faustparser.cpp"
    break;

  case 124: /* expression.math.rounding: LOWEST  */
#line 646 "faustparser.y"
                 { (yyval.exp) = boxPrim1(sigLowest);}
#line 2411 "faustparser.cpp"
    break;

  case 125: /* expression.math.rounding: HIGHEST  */
#line 647 "faustparser.y"
                  { (yyval.exp) = boxPrim1(sigHighest);}
#line 2417 "faustparser.cpp"
    break;

  case 126: /* expression.math.rounding: RINT  */
#line 648 "faustparser.y"
               { (yyval.exp) = gGlobal->gRintPrim->box(); }
#line 2423 "faustparser.cpp"
    break;

  case 130: /* expression.math.signal.algebra: ADD  */
#line 656 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigAdd); }
#line 2429 "faustparser.cpp"
    break;

  case 131: /* expression.math.signal.algebra: SUB  */
#line 657 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigSub); }
#line 2435 "faustparser.cpp"
    break;

  case 132: /* expression.math.signal.algebra: MUL  */
#line 658 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigMul); }
#line 2441 "faustparser.cpp"
    break;

  case 133: /* expression.math.signal.algebra: DIV  */
#line 659 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigDiv); }
#line 2447 "faustparser.cpp"
    break;

  case 134: /* expression.math.signal.algebra: MOD  */
#line 660 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigRem); }
#line 2453 "faustparser.cpp"
    break;

  case 135: /* expression.math.signal.algebra: FMOD  */
#line 661 "faustparser.y"
               { (yyval.exp) = gGlobal->gFmodPrim->box(); }
#line 2459 "faustparser.cpp"
    break;

  case 136: /* expression.math.signal.algebra: REMAINDER  */
#line 662 "faustparser.y"
                    { (yyval.exp) = gGlobal->gRemainderPrim->box(); }
#line 2465 "faustparser.cpp"
    break;

  case 137: /* expression.math.signal.algebra: SUB statement.identifier.box  */
#line 663 "faustparser.y"
                                       { (yyval.exp) = boxSeq(boxPar(boxInt(0),(yyvsp[0].exp)),boxPrim2(sigSub)); }
#line 2471 "faustparser.cpp"
    break;

  case 138: /* expression.math.signal.shift: LSH  */
#line 666 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigLeftShift); }
#line 2477 "faustparser.cpp"
    break;

  case 139: /* expression.math.signal.shift: RSH  */
#line 667 "faustparser.y"
              { (yyval.exp) = boxPrim2(sigARightShift); }
#line 2483 "faustparser.cpp"
    break;

  case 140: /* expression.math.signal.power: EXP  */
#line 670 "faustparser.y"
              { (yyval.exp) = gGlobal->gExpPrim->box(); }
#line 2489 "faustparser.cpp"
    break;

  case 141: /* expression.math.signal.power: LOG  */
#line 671 "faustparser.y"
              { (yyval.exp) = gGlobal->gLogPrim->box(); }
#line 2495 "faustparser.cpp"
    break;

  case 142: /* expression.math.signal.power: LOG10  */
#line 672 "faustparser.y"
                { (yyval.exp) = gGlobal->gLog10Prim->box(); }
#line 2501 "faustparser.cpp"
    break;

  case 143: /* expression.math.signal.power: POWOP  */
#line 673 "faustparser.y"
                { (yyval.exp) = gGlobal->gPowPrim->box(); }
#line 2507 "faustparser.cpp"
    break;

  case 144: /* expression.math.signal.power: POWFUN  */
#line 674 "faustparser.y"
                 { (yyval.exp) = gGlobal->gPowPrim->box(); }
#line 2513 "faustparser.cpp"
    break;

  case 145: /* expression.math.signal.power: SQRT  */
#line 675 "faustparser.y"
               { (yyval.exp) = gGlobal->gSqrtPrim->box(); }
#line 2519 "faustparser.cpp"
    break;

  case 146: /* expression.math.scalar: ADD INT  */
#line 678 "faustparser.y"
                  { (yyval.exp) = boxInt(str2int(yytext)); }
#line 2525 "faustparser.cpp"
    break;

  case 147: /* expression.math.scalar: ADD FLOAT  */
#line 679 "faustparser.y"
                    { (yyval.exp) = boxReal(atof(yytext)); }
#line 2531 "faustparser.cpp"
    break;

  case 148: /* expression.math.scalar: SUB INT  */
#line 680 "faustparser.y"
                  { (yyval.exp) = boxInt ( -str2int(yytext) ); }
#line 2537 "faustparser.cpp"
    break;

  case 149: /* expression.math.scalar: SUB FLOAT  */
#line 681 "faustparser.y"
                    { (yyval.exp) = boxReal( -atof(yytext) ); }
#line 2543 "faustparser.cpp"
    break;

  case 150: /* expression.math.trigonometry: ACOS  */
#line 684 "faustparser.y"
               { (yyval.exp) = gGlobal->gAcosPrim->box(); }
#line 2549 "faustparser.cpp"
    break;

  case 151: /* expression.math.trigonometry: ASIN  */
#line 685 "faustparser.y"
               { (yyval.exp) = gGlobal->gAsinPrim->box(); }
#line 2555 "faustparser.cpp"
    break;

  case 152: /* expression.math.trigonometry: ATAN  */
#line 686 "faustparser.y"
               { (yyval.exp) = gGlobal->gAtanPrim->box(); }
#line 2561 "faustparser.cpp"
    break;

  case 153: /* expression.math.trigonometry: ATAN2  */
#line 687 "faustparser.y"
                { (yyval.exp) = gGlobal->gAtan2Prim->box(); }
#line 2567 "faustparser.cpp"
    break;

  case 154: /* expression.math.trigonometry: COS  */
#line 688 "faustparser.y"
              { (yyval.exp) = gGlobal->gCosPrim->box(); }
#line 2573 "faustparser.cpp"
    break;

  case 155: /* expression.math.trigonometry: SIN  */
#line 689 "faustparser.y"
              { (yyval.exp) = gGlobal->gSinPrim->box(); }
#line 2579 "faustparser.cpp"
    break;

  case 156: /* expression.math.trigonometry: TAN  */
#line 690 "faustparser.y"
              { (yyval.exp) = gGlobal->gTanPrim->box(); }
#line 2585 "faustparser.cpp"
    break;

  case 157: /* expression.parenthesis: LPAR expression RPAR  */
#line 695 "faustparser.y"
                         { (yyval.exp) = (yyvsp[-1].exp); }
#line 2591 "faustparser.cpp"
    break;

  case 158: /* expression.parallel: expression COMMA expression  */
#line 700 "faustparser.y"
                                            {
        (yyval.exp) = boxPar((yyvsp[-2].exp),(yyvsp[0].exp));
      }
#line 2599 "faustparser.cpp"
    break;

  case 162: /* expression.signal.control: ATTACH  */
#line 712 "faustparser.y"
               { (yyval.exp) = boxPrim2(sigAttach); }
#line 2605 "faustparser.cpp"
    break;

  case 163: /* expression.signal.control: ENABLE  */
#line 713 "faustparser.y"
               { (yyval.exp) = boxPrim2(sigEnable); }
#line 2611 "faustparser.cpp"
    break;

  case 164: /* expression.signal.control: CONTROL  */
#line 714 "faustparser.y"
                { (yyval.exp) = boxPrim2(sigControl); }
#line 2617 "faustparser.cpp"
    break;

  case 165: /* expression.signal.delay: MEM  */
#line 717 "faustparser.y"
            { (yyval.exp) = boxPrim1(sigDelay1); }
#line 2623 "faustparser.cpp"
    break;

  case 166: /* expression.signal.delay: PREFIX  */
#line 718 "faustparser.y"
               { (yyval.exp) = boxPrim2(sigPrefix); }
#line 2629 "faustparser.cpp"
    break;

  case 167: /* expression.signal.delay: FDELAY  */
#line 719 "faustparser.y"
               { (yyval.exp) = boxPrim2(sigDelay); }
#line 2635 "faustparser.cpp"
    break;

  case 168: /* expression.signal.logic: AND  */
#line 722 "faustparser.y"
            { (yyval.exp) = boxPrim2(sigAND); }
#line 2641 "faustparser.cpp"
    break;

  case 169: /* expression.signal.logic: OR  */
#line 723 "faustparser.y"
           { (yyval.exp) = boxPrim2(sigOR); }
#line 2647 "faustparser.cpp"
    break;

  case 170: /* expression.signal.logic: XOR  */
#line 724 "faustparser.y"
            { (yyval.exp) = boxPrim2(sigXOR); }
#line 2653 "faustparser.cpp"
    break;

  case 171: /* expression.signal.logic: SELECT2  */
#line 725 "faustparser.y"
                { (yyval.exp) = boxPrim3(sigSelect2); }
#line 2659 "faustparser.cpp"
    break;

  case 172: /* expression.signal.logic: SELECT3  */
#line 726 "faustparser.y"
                { (yyval.exp) = boxPrim4(sigSelect3); }
#line 2665 "faustparser.cpp"
    break;

  case 173: /* expression.signal.logic: CASE LBRAQ statement.signal.pattern.rule.list RBRAQ  */
#line 727 "faustparser.y"
                                                            { (yyval.exp) = boxCase(checkRulelist((yyvsp[-1].exp))); }
#line 2671 "faustparser.cpp"
    break;

  case 182: /* primitive.number: INT  */
#line 750 "faustparser.y"
          { (yyval.exp) = boxInt(str2int(yytext)); }
#line 2677 "faustparser.cpp"
    break;

  case 183: /* primitive.number: FLOAT  */
#line 751 "faustparser.y"
            { (yyval.exp) = boxReal(atof(yytext)); }
#line 2683 "faustparser.cpp"
    break;

  case 184: /* primitive.string.quoted: STRING  */
#line 756 "faustparser.y"
             { (yyval.exp) = tree(yytext); }
#line 2689 "faustparser.cpp"
    break;

  case 185: /* primitive.string.unquoted: STRING  */
#line 759 "faustparser.y"
             { (yyval.exp) = unquote(yytext); }
#line 2695 "faustparser.cpp"
    break;

  case 186: /* primitive.string.tag: STRING  */
#line 762 "faustparser.y"
             { (yyval.exp) = tree(yytext); }
#line 2701 "faustparser.cpp"
    break;

  case 187: /* primitive.string.tag: TAGSTRING  */
#line 763 "faustparser.y"
                { (yyval.exp) = tree(yytext); }
#line 2707 "faustparser.cpp"
    break;

  case 194: /* primitive.signal.input.implicit: WIRE  */
#line 776 "faustparser.y"
           { (yyval.exp) = boxWire(); }
#line 2713 "faustparser.cpp"
    break;

  case 195: /* primitive.signal.input.terminate: CUT  */
#line 779 "faustparser.y"
          { (yyval.exp) = boxCut(); }
#line 2719 "faustparser.cpp"
    break;

  case 200: /* primitive.type.number.list.member: primitive.number  */
#line 792 "faustparser.y"
                           {
            gGlobal->gWaveForm.push_back((yyvsp[0].exp));
          }
#line 2727 "faustparser.cpp"
    break;

  case 201: /* primitive.type.number.list.member: expression.math.scalar  */
#line 795 "faustparser.y"
                                 {
            gGlobal->gWaveForm.push_back((yyvsp[0].exp));
          }
#line 2735 "faustparser.cpp"
    break;

  case 206: /* primitive.type.number.int: INTCAST  */
#line 810 "faustparser.y"
                  { (yyval.exp) = boxPrim1(sigIntCast); }
#line 2741 "faustparser.cpp"
    break;

  case 207: /* primitive.type.number.float: FLOATCAST  */
#line 813 "faustparser.y"
                    { (yyval.exp) = boxPrim1(sigFloatCast); }
#line 2747 "faustparser.cpp"
    break;

  case 208: /* primitive.type.any: ANYCAST  */
#line 816 "faustparser.y"
                { (yyval.exp) = tree(2); }
#line 2753 "faustparser.cpp"
    break;

  case 209: /* primitive.signal.route: ROUTE LPAR expression.composition COMMA expression.composition RPAR  */
#line 819 "faustparser.y"
                                                                                              {
          (yyval.exp) = boxRoute((yyvsp[-3].exp), (yyvsp[-1].exp), boxPar(boxInt(0),boxInt(0)));
        }
#line 2761 "faustparser.cpp"
    break;

  case 210: /* primitive.signal.route: ROUTE LPAR expression.composition COMMA expression.composition COMMA expression RPAR  */
#line 822 "faustparser.y"
                                                                                                         {
          (yyval.exp) = boxRoute((yyvsp[-5].exp), (yyvsp[-3].exp), (yyvsp[-1].exp));
        }
#line 2769 "faustparser.cpp"
    break;

  case 214: /* primitive.signal.source.table: RDTBL  */
#line 832 "faustparser.y"
                { (yyval.exp) = boxPrim3(sigReadOnlyTable); }
#line 2775 "faustparser.cpp"
    break;

  case 215: /* primitive.signal.source.table: RWTBL  */
#line 833 "faustparser.y"
                { (yyval.exp) = boxPrim5(sigWriteReadTable); }
#line 2781 "faustparser.cpp"
    break;

  case 216: /* primitive.signal.source.soundfile: SOUNDFILE LPAR primitive.string.unquoted COMMA expression.composition RPAR  */
#line 836 "faustparser.y"
                                                                                     {
            (yyval.exp) = boxSoundfile( (yyvsp[-3].exp), (yyvsp[-1].exp) );
          }
#line 2789 "faustparser.cpp"
    break;

  case 217: /* primitive.signal.source.waveform: WAVEFORM LBRAQ primitive.type.number.list RBRAQ  */
#line 841 "faustparser.y"
                                                        {
          (yyval.exp) = boxWaveform(gGlobal->gWaveForm);
          gGlobal->gWaveForm.clear();
          /* primitive.type.number.list pushes values onto gGlobal->gWaveForm */
        }
#line 2799 "faustparser.cpp"
    break;

  case 220: /* primitive.type.list.start: primitive.type  */
#line 854 "faustparser.y"
                         { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 2805 "faustparser.cpp"
    break;

  case 221: /* primitive.type.list.append: primitive.type.list COMMA primitive.type  */
#line 857 "faustparser.y"
                                                                { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 2811 "faustparser.cpp"
    break;

  case 232: /* primitive.ui.button: BUTTON LPAR primitive.string.unquoted RPAR  */
#line 875 "faustparser.y"
                                                   { (yyval.exp) = boxButton((yyvsp[-1].exp)); }
#line 2817 "faustparser.cpp"
    break;

  case 233: /* primitive.ui.checkbox: CHECKBOX LPAR primitive.string.unquoted RPAR  */
#line 878 "faustparser.y"
                                                     { (yyval.exp) = boxCheckbox((yyvsp[-1].exp)); }
#line 2823 "faustparser.cpp"
    break;

  case 234: /* primitive.ui.vslider: VSLIDER LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition COMMA expression.composition COMMA expression.composition RPAR  */
#line 881 "faustparser.y"
                                                                                                                                                                                                {
          (yyval.exp) = boxVSlider((yyvsp[-9].exp),(yyvsp[-7].exp),(yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
        }
#line 2831 "faustparser.cpp"
    break;

  case 235: /* primitive.ui.hslider: HSLIDER LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition COMMA expression.composition COMMA expression.composition RPAR  */
#line 886 "faustparser.y"
                                                                                                                                                                                                {
          (yyval.exp) = boxHSlider((yyvsp[-9].exp),(yyvsp[-7].exp),(yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
        }
#line 2839 "faustparser.cpp"
    break;

  case 236: /* primitive.ui.nentry: NENTRY LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition COMMA expression.composition COMMA expression.composition RPAR  */
#line 891 "faustparser.y"
                                                                                                                                                                                               {
          (yyval.exp) = boxNumEntry((yyvsp[-9].exp),(yyvsp[-7].exp),(yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
        }
#line 2847 "faustparser.cpp"
    break;

  case 237: /* primitive.ui.vgroup: VGROUP LPAR primitive.string.unquoted COMMA expression RPAR  */
#line 896 "faustparser.y"
                                                                    { (yyval.exp) = boxVGroup((yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 2853 "faustparser.cpp"
    break;

  case 238: /* primitive.ui.hgroup: HGROUP LPAR primitive.string.unquoted COMMA expression RPAR  */
#line 899 "faustparser.y"
                                                                    { (yyval.exp) = boxHGroup((yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 2859 "faustparser.cpp"
    break;

  case 239: /* primitive.ui.tgroup: TGROUP LPAR primitive.string.unquoted COMMA expression RPAR  */
#line 902 "faustparser.y"
                                                                    { (yyval.exp) = boxTGroup((yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 2865 "faustparser.cpp"
    break;

  case 240: /* primitive.ui.vbargraph: VBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition RPAR  */
#line 905 "faustparser.y"
                                                                                                                            {
          (yyval.exp) = boxVBargraph((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
        }
#line 2873 "faustparser.cpp"
    break;

  case 241: /* primitive.ui.hbargraph: HBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition COMMA expression.composition RPAR  */
#line 910 "faustparser.y"
                                                                                                                            {
          (yyval.exp) = boxHBargraph((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp));
        }
#line 2881 "faustparser.cpp"
    break;

  case 242: /* primitive.foreign.function: FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag COMMA primitive.string.unquoted RPAR  */
#line 917 "faustparser.y"
                                                                                                                            {
          (yyval.exp) = boxFFun(ffunction((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)));
        }
#line 2889 "faustparser.cpp"
    break;

  case 243: /* primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform LPAR primitive.type.list RPAR  */
#line 922 "faustparser.y"
                                                                                                 {
            (yyval.exp) = cons((yyvsp[-4].exp), cons(cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),gGlobal->nil))), (yyvsp[-1].exp)));
          }
#line 2897 "faustparser.cpp"
    break;

  case 244: /* primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform LPAR primitive.type.list RPAR  */
#line 925 "faustparser.y"
                                                                                                                                         {
            (yyval.exp) = cons((yyvsp[-6].exp), cons(cons((yyvsp[-5].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),gGlobal->nil))), (yyvsp[-1].exp)));
          }
#line 2905 "faustparser.cpp"
    break;

  case 245: /* primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform OR statement.identifier.waveform LPAR primitive.type.list RPAR  */
#line 928 "faustparser.y"
                                                                                                                                                                                {
            (yyval.exp) = cons((yyvsp[-8].exp), cons(cons((yyvsp[-7].exp),cons((yyvsp[-5].exp),cons((yyvsp[-3].exp),gGlobal->nil))), (yyvsp[-1].exp)));
          }
#line 2913 "faustparser.cpp"
    break;

  case 246: /* primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform LPAR RPAR  */
#line 931 "faustparser.y"
                                                                             {
            (yyval.exp) = cons((yyvsp[-3].exp), cons(cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),gGlobal->nil))), gGlobal->nil));
          }
#line 2921 "faustparser.cpp"
    break;

  case 247: /* primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform LPAR RPAR  */
#line 934 "faustparser.y"
                                                                                                                     {
            (yyval.exp) = cons((yyvsp[-5].exp), cons(cons((yyvsp[-4].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),gGlobal->nil))), gGlobal->nil));
          }
#line 2929 "faustparser.cpp"
    break;

  case 248: /* primitive.foreign.function.signature: primitive.type.number statement.identifier.waveform OR statement.identifier.waveform OR statement.identifier.waveform LPAR RPAR  */
#line 937 "faustparser.y"
                                                                                                                                                            {
            (yyval.exp) = cons((yyvsp[-7].exp), cons(cons((yyvsp[-6].exp),cons((yyvsp[-4].exp),cons((yyvsp[-2].exp),gGlobal->nil))), gGlobal->nil));
          }
#line 2937 "faustparser.cpp"
    break;

  case 249: /* primitive.foreign.constant: FCONSTANT LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR  */
#line 942 "faustparser.y"
                                                                                                  {
          (yyval.exp) = boxFConst( (yyvsp[-4].exp), (yyvsp[-3].exp), (yyvsp[-1].exp));
        }
#line 2945 "faustparser.cpp"
    break;

  case 250: /* primitive.foreign.variable: FVARIABLE LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR  */
#line 947 "faustparser.y"
                                                                                                  {
          (yyval.exp) = boxFVar( (yyvsp[-4].exp), (yyvsp[-3].exp), (yyvsp[-1].exp) );
        }
#line 2953 "faustparser.cpp"
    break;

  case 251: /* primitive.signal.inputs: INPUTS LPAR expression RPAR  */
#line 954 "faustparser.y"
                                    { (yyval.exp) = boxInputs((yyvsp[-1].exp)); }
#line 2959 "faustparser.cpp"
    break;

  case 252: /* primitive.signal.outputs: OUTPUTS LPAR expression RPAR  */
#line 957 "faustparser.y"
                                     { (yyval.exp) = boxOutputs((yyvsp[-1].exp)); }
#line 2965 "faustparser.cpp"
    break;

  case 261: /* statement.definition.function: statement.identifier.box LPAR expression.composition.list RPAR DEF expression ENDDEF  */
#line 979 "faustparser.y"
                                                                                             {
          (yyval.exp) = cons(
            (yyvsp[-6].exp),
            cons( (yyvsp[-4].exp), (yyvsp[-1].exp) )
          );
          setDefProp((yyvsp[-6].exp), yyfilename, yylineno);
        }
#line 2977 "faustparser.cpp"
    break;

  case 262: /* statement.definition.substitution: statement.identifier.box DEF expression ENDDEF  */
#line 988 "faustparser.y"
                                                                                {
          (yyval.exp) = cons((yyvsp[-3].exp),cons(gGlobal->nil,(yyvsp[-1].exp)));
          setDefProp((yyvsp[-3].exp), yyfilename, yylineno);
        }
#line 2986 "faustparser.cpp"
    break;

  case 263: /* statement.definition.with: expression WITH LBRAQ statement.definition.list RBRAQ  */
#line 994 "faustparser.y"
                                                            {
        (yyval.exp) = boxWithLocalDef((yyvsp[-4].exp),formatDefinitions((yyvsp[-1].exp)));
      }
#line 2994 "faustparser.cpp"
    break;

  case 264: /* statement.definition.error: error ENDDEF  */
#line 999 "faustparser.y"
                     {
          (yyval.exp) = gGlobal->nil;
          yyerr++;
        }
#line 3003 "faustparser.cpp"
    break;

  case 269: /* statement.definition.list.start: statement.definition  */
#line 1011 "faustparser.y"
                               {
            (yyval.exp) = cons( (yyval.exp), gGlobal->nil );
          }
#line 3011 "faustparser.cpp"
    break;

  case 270: /* statement.definition.list.start.qualified: statement.math.precision.list statement.definition  */
#line 1016 "faustparser.y"
                                                             {
            if (acceptdefinition((yyvsp[-1].numvariant)))
              (yyval.exp) = cons( (yyvsp[0].exp), gGlobal->nil );
            else
              (yyval.exp) = gGlobal->nil;
          }
#line 3022 "faustparser.cpp"
    break;

  case 271: /* statement.definition.list.append: statement.definition.list statement.definition  */
#line 1024 "faustparser.y"
                                                         {
            (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-1].exp));
          }
#line 3030 "faustparser.cpp"
    break;

  case 272: /* statement.definition.list.append.qualified: statement.definition.list statement.math.precision.list statement.definition  */
#line 1029 "faustparser.y"
                                                                                       {
            if (acceptdefinition((yyvsp[-1].numvariant)))
              (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-2].exp));
            else
              (yyval.exp) = (yyvsp[-2].exp);
          }
#line 3041 "faustparser.cpp"
    break;

  case 273: /* statement.declare.metadata: DECLARE statement.identifier primitive.string.quoted ENDDEF  */
#line 1039 "faustparser.y"
                                                                              {
        declareMetadata((yyvsp[-2].exp),(yyvsp[-1].exp));
        (yyval.exp) = gGlobal->nil;
      }
#line 3050 "faustparser.cpp"
    break;

  case 274: /* statement.declare.feature.metadata: DECLARE statement.identifier statement.identifier primitive.string.quoted ENDDEF  */
#line 1045 "faustparser.y"
                                                                                                            {
        declareDefinitionMetadata( (yyvsp[-3].exp), (yyvsp[-2].exp), (yyvsp[-1].exp) );
        (yyval.exp) = gGlobal->nil;
      }
#line 3059 "faustparser.cpp"
    break;

  case 275: /* statement.declare.doc: BDOC doc EDOC  */
#line 1051 "faustparser.y"
                          {
        declareDoc((yyvsp[-1].exp));
        (yyval.exp) = gGlobal->nil;
      }
#line 3068 "faustparser.cpp"
    break;

  case 276: /* statement.identifier: IDENT  */
#line 1059 "faustparser.y"
            {
        (yyval.exp) = tree(yytext);
        setUseProp((yyval.exp), yyfilename, yylineno);
      }
#line 3077 "faustparser.cpp"
    break;

  case 277: /* statement.identifier.box: IDENT  */
#line 1065 "faustparser.y"
            {
        (yyval.exp) = boxIdent(yytext);
        setUseProp((yyval.exp), yyfilename, yylineno);
      }
#line 3086 "faustparser.cpp"
    break;

  case 278: /* statement.identifier.waveform: IDENT  */
#line 1071 "faustparser.y"
            { (yyval.exp) = tree(yytext); }
#line 3092 "faustparser.cpp"
    break;

  case 279: /* statement.import: IMPORT LPAR primitive.string.unquoted RPAR ENDDEF  */
#line 1076 "faustparser.y"
                                                                  { (yyval.exp) = importFile((yyvsp[-2].exp)); }
#line 3098 "faustparser.cpp"
    break;

  case 284: /* statement.list.start: statement  */
#line 1087 "faustparser.y"
                  {
          (yyval.exp) = cons((yyvsp[0].exp), gGlobal->nil);
        }
#line 3106 "faustparser.cpp"
    break;

  case 285: /* statement.list.start.qualified: statement.math.precision.list statement  */
#line 1092 "faustparser.y"
                                                {
          if (acceptdefinition((yyvsp[-1].numvariant)))
            (yyval.exp) = cons((yyvsp[0].exp), gGlobal->nil);
          else
            (yyval.exp) = gGlobal->nil;
        }
#line 3117 "faustparser.cpp"
    break;

  case 286: /* statement.list.append: statement.list statement  */
#line 1100 "faustparser.y"
                                 {
          (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-1].exp));
        }
#line 3125 "faustparser.cpp"
    break;

  case 287: /* statement.list.append.qualified: statement.list statement.math.precision.list statement  */
#line 1105 "faustparser.y"
                                                               {
          if (acceptdefinition((yyvsp[-1].numvariant)))
            (yyval.exp) = cons((yyvsp[-2].exp),(yyvsp[0].exp));
          else
            (yyval.exp)=(yyvsp[-2].exp);
        }
#line 3136 "faustparser.cpp"
    break;

  case 288: /* statement.math.precision: FLOATMODE  */
#line 1115 "faustparser.y"
                  { (yyval.numvariant) = 1; }
#line 3142 "faustparser.cpp"
    break;

  case 289: /* statement.math.precision: DOUBLEMODE  */
#line 1116 "faustparser.y"
                   { (yyval.numvariant) = 2; }
#line 3148 "faustparser.cpp"
    break;

  case 290: /* statement.math.precision: QUADMODE  */
#line 1117 "faustparser.y"
                 { (yyval.numvariant) = 4; }
#line 3154 "faustparser.cpp"
    break;

  case 291: /* statement.math.precision: FIXEDPOINTMODE  */
#line 1118 "faustparser.y"
                       { (yyval.numvariant) = 8; }
#line 3160 "faustparser.cpp"
    break;

  case 295: /* statement.math.precision.list.append: statement.math.precision.list statement.math.precision  */
#line 1128 "faustparser.y"
                                                                   {
              (yyval.numvariant) = (yyvsp[-1].numvariant) | (yyvsp[0].numvariant);
            }
#line 3168 "faustparser.cpp"
    break;

  case 298: /* statement.signal.pattern.rule.list.start: statement.signal.pattern.rule  */
#line 1139 "faustparser.y"
                                      { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 3174 "faustparser.cpp"
    break;

  case 299: /* statement.signal.pattern.rule.list.append: statement.signal.pattern.rule.list statement.signal.pattern.rule  */
#line 1142 "faustparser.y"
                                                                                      { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-1].exp)); }
#line 3180 "faustparser.cpp"
    break;

  case 300: /* statement.signal.pattern.rule: LPAR expression.composition.list RPAR ARROW expression ENDDEF  */
#line 1145 "faustparser.y"
                                                                    { (yyval.exp) = cons((yyvsp[-4].exp),(yyvsp[-1].exp)); }
#line 3186 "faustparser.cpp"
    break;


#line 3190 "faustparser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1148 "faustparser.y"

