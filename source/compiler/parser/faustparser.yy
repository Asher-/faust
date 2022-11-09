/* -*- Mode: C++; tab-width: 2; c-basic-offset: 4 -*- */

/* Parser for the Faust language */
%require "3.2"
%language "c++"
%define api.value.type variant

%define api.token.raw
%define api.token.constructor
%define api.token.prefix {FAUST_}

%define api.namespace {::Faust::Compiler::Parser}
%define api.parser.class {Implementation}
//%define api.location.type { Type::Location }

%define parse.assert /* runtime assertions to catch invalid uses */
%define parse.trace /* set yydebug = 1 to print trace to stderr */
%define parse.error detailed /* simple, detailed, verbose */
%define parse.lac full /* look-ahead correction (5.8.3 LAC) */

%param { Type::Driver& driver }

%header "faustparser.hh"   /* Generate faustparser.hh */

%locations /* Generate location.hh */
%verbose   /* Generate faustparser.output */

%initial-action
{
  @$.begin.filename = @$.end.filename = &driver._streamName;
};

%code requires { /* Faust requires */
  #include <string>
  #include "compiler/parser/type/tokens.hh"
  #include "compiler/parser/location.hh"
  namespace Faust { namespace Compiler { namespace Parser {
    namespace Type { struct Driver; }
    namespace Lexer {
      struct Implementation;
  } } } }
}

%code { /* Faust code */
  #include "compiler/parser/type/driver.hh"
}

%{ /* Faust */

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

%}

%start program

/* With local environment (lowest priority)*/
%left WITH
%left LETREC

/* Block Diagram Algebra */
/*%left SEQ SPLIT MIX*/
%right SPLIT MIX
%right SEQ
%right COMMA
%left REC

/* Primitive boxes */

//%left LT LE EQ GT GE NE
%nonassoc LT LE EQ GT GE NE

%left ADD SUB OR
%left MUL DIV MOD AND XOR LSH RSH
%left POWOP
%left FDELAY
%left DELAY1
/*%left APPL*/
%left DOT

%token <std::string> MEM
%token <std::string> PREFIX

%token <std::string> INTCAST
%token <std::string> FLOATCAST
%token <std::string> ANYCAST
%token <std::string> FFUNCTION
%token <std::string> FCONSTANT
%token <std::string> FVARIABLE

%token <std::string> BUTTON
%token <std::string> CHECKBOX
%token <std::string> VSLIDER
%token <std::string> HSLIDER
%token <std::string> NENTRY
%token <std::string> VGROUP
%token <std::string> HGROUP
%token <std::string> TGROUP

%token <std::string> HBARGRAPH
%token <std::string> VBARGRAPH
%token <std::string> SOUNDFILE

%token <std::string> ATTACH

%token <std::string> ACOS
%token <std::string> ASIN
%token <std::string> ATAN
%token <std::string> ATAN2
%token <std::string> COS
%token <std::string> SIN
%token <std::string> TAN

%token <std::string> EXP
%token <std::string> LOG
%token <std::string> LOG10
%token <std::string> POWFUN
%token <std::string> SQRT

%token <std::string> ABS
%token <std::string> MIN
%token <std::string> MAX

%token <std::string> FMOD
%token <std::string> REMAINDER

%token <std::string> FLOOR
%token <std::string> CEIL
%token <std::string> RINT

%token <std::string> RDTBL
%token <std::string> RWTBL

%token <std::string> SELECT2
%token <std::string> SELECT3

%token <int> INT
%token <float> FLOAT

%token <std::string> LAMBDA
%token <std::string> DOT

%token <std::string> WIRE
%token <std::string> CUT
%token <std::string> ENDDEF
%token <std::string> VIRG
%left <std::string> LPAR
%token <std::string> RPAR
%token <std::string> LBRAQ
%token <std::string> RBRAQ
%left <std::string> LCROC
%token <std::string> RCROC
%token <std::string> WITH
%token <std::string> LETREC
%token <std::string> WHERE
%token <std::string> DEF

%token <std::string> IMPORT
%token <std::string> COMPONENT
%token <std::string> LIBRARY
%token <std::string> ENVIRONMENT
%token <std::string> WAVEFORM
%token <std::string> ROUTE
%token <std::string> ENABLE
%token <std::string> CONTROL

%token <std::string> ITERATE_PARALLEL
%token <std::string> ISEQ
%token <std::string> ISUM
%token <std::string> IPROD

%token <std::string> INPUTS
%token <std::string> OUTPUTS

%token <std::string> STRING
%token <std::string> TAGSTRING
%token <std::string> IDENT
%token <std::string> EXTRA

%token <std::string> DECLARE

%token <std::string> CASE
%token <std::string> ARROW

%token <std::string> ASSERTBOUNDS
%token <std::string> LOWEST
%token <std::string> HIGHEST

%token <int> FLOATMODE
%token <int> DOUBLEMODE
%token <int> QUADMODE
%token <int> FIXEDPOINTMODE

 /* Beg<std::string> in and End tags for documentations, equations and diagrams */
%token <std::string> BDOC
%token <std::string> EDOC
%token <std::string> BEQN
%token <std::string> EEQN
%token <std::string> BDGM
%token <std::string> EDGM
%token <std::string> BLST
%token <std::string> ELST
%token <std::string> BMETADATA
%token <std::string> EMETADATA
%token <std::string> DOCCHAR
%token <std::string> NOTICE
%token <std::string> LISTING

%token <std::string> LSTTRUE
%token <std::string> LSTFALSE
%token <std::string> LSTDEPENDENCIES
%token <std::string> LSTMDOCTAGS
%token <std::string> LSTDISTRIBUTED
%token <std::string> LSTEQ
%token <std::string> LSTQ
%token <std::string> ENDL

%type <Type::exp> doc
%type <Type::exp> doc.attribute.list
%type <Type::exp> doc.attribute.definition
%type <bool> doc.attribute.value
%type <std::string> doc.text
%type <Type::exp> doc.equation
%type <Type::exp> doc.diagram
%type <Type::exp> doc.notice
%type <Type::exp> doc.list
%type <Type::exp> doc.metadata

%type <Type::exp> expression
%type <Type::exp> expression.component
%type <Type::exp> expression.composition
%type <Type::exp> expression.composition.mix
%type <Type::exp> expression.composition.record
%type <Type::exp> expression.composition.sequence
%type <Type::exp> expression.composition.split
%type <Type::exp> expression.composition.list
%type <Type::exp> expression.environment
%type <Type::exp> expression.infix
%type <Type::exp> expression.infix.definitions.local
%type <Type::exp> expression.infix.environment.access
%type <Type::exp> expression.infix.math
%type <Type::exp> expression.infix.math.algebra
%type <Type::exp> expression.infix.math.comparison
%type <Type::exp> expression.infix.math.logic
%type <Type::exp> expression.infix.math.shift
%type <Type::exp> expression.infix.prefix
%type <Type::exp> expression.infix.signal.delay
%type <Type::exp> expression.iterate.parallel
%type <Type::exp> expression.iterate.sequence
%type <Type::exp> expression.iterate.sum
%type <Type::exp> expression.iterate.product
%type <Type::exp> expression.lambda
%type <Type::exp> expression.lambda.params
%type <Type::exp> expression.lambda.params.start
%type <Type::exp> expression.lambda.params.append
%type <Type::exp> expression.letrec
%type <Type::exp> expression.letrec.list
%type <Type::exp> expression.letrec.list.start
%type <Type::exp> expression.letrec.list.append
%type <Type::exp> expression.letrec.equation
%type <Type::exp> expression.letrec.equation.name
%type <Type::exp> expression.library
%type <Type::exp> expression.math
%type <Type::exp> expression.math.comparison
%type <Type::exp> expression.math.rounding
%type <Type::exp> expression.math.scalar
%type <Type::exp> expression.math.signal
%type <Type::exp> expression.math.signal.algebra
%type <Type::exp> expression.math.signal.shift
%type <Type::exp> expression.math.signal.power
%type <Type::exp> expression.math.trigonometry
%type <Type::exp> expression.parallel
%type <Type::exp> expression.parenthesis
%type <Type::exp> expression.signal
%type <Type::exp> expression.signal.control
%type <Type::exp> expression.signal.delay
%type <Type::exp> expression.signal.logic

%type <Type::exp> primitive
%type <Type::exp> primitive.foreign
%type <Type::exp> primitive.foreign.constant
%type <Type::exp> primitive.foreign.function
%type <Type::exp> primitive.foreign.function.signature
%type <Type::exp> primitive.foreign.variable
%type <Type::exp> primitive.signal.input.implicit
%type <Type::exp> primitive.signal.input.terminate
%type <Type::exp> primitive.signal.inputs
%type <Type::exp> primitive.number
%type <Type::exp> primitive.type.number.list
%type <Type::exp> primitive.type.number.list.start
%type <Type::exp> primitive.type.number.list.append
%type <Type::exp> primitive.type.number.list.member
%type <Type::exp> primitive.signal.outputs
%type <Type::exp> primitive.signal
%type <Type::exp> primitive.signal.route
%type <Type::exp> primitive.signal.source
%type <Type::exp> primitive.signal.source.soundfile
%type <Type::exp> primitive.signal.source.table
%type <Type::exp> primitive.signal.source.waveform
%type <Type::exp> primitive.string.quoted
%type <Type::exp> primitive.string.tag
%type <Type::exp> primitive.string.unquoted
%type <Type::exp> primitive.type
%type <Type::exp> primitive.type.list
%type <Type::exp> primitive.type.list.start
%type <Type::exp> primitive.type.list.append
%type <Type::exp> primitive.type.number
%type <Type::exp> primitive.type.number.int
%type <Type::exp> primitive.type.number.float
%type <Type::exp> primitive.type.any

%type <Type::exp> primitive.ui
%type <Type::exp> primitive.ui.button
%type <Type::exp> primitive.ui.checkbox
%type <Type::exp> primitive.ui.vslider
%type <Type::exp> primitive.ui.hslider
%type <Type::exp> primitive.ui.nentry
%type <Type::exp> primitive.ui.vgroup
%type <Type::exp> primitive.ui.hgroup
%type <Type::exp> primitive.ui.tgroup
%type <Type::exp> primitive.ui.vbargraph
%type <Type::exp> primitive.ui.hbargraph

%type <Type::exp> program

%type <Type::exp> statement
%type <Type::exp> statement.definition
%type <Type::exp> statement.definition.substitution
%type <Type::exp> statement.definition.error
%type <Type::exp> statement.definition.function
%type <Type::exp> statement.definition.function.incomplete
%type <Type::exp> statement.definition.list
%type <Type::exp> statement.definition.list.start
%type <Type::exp> statement.definition.list.start.qualified
%type <Type::exp> statement.definition.list.append
%type <Type::exp> statement.definition.list.append.qualified
%type <Type::exp> statement.definition.with
%type <Type::exp> statement.declare.doc
%type <Type::exp> statement.declare.metadata
%type <Type::exp> statement.declare.feature.metadata
%type <Type::exp> statement.identifier
%type <Type::exp> statement.identifier.box
%type <Type::exp> statement.identifier.waveform
%type <Type::exp> statement.import
%type <Type::exp> statement.list
%type <Type::exp> statement.list.start
%type <Type::exp> statement.list.start.qualified
%type <Type::exp> statement.list.append
%type <Type::exp> statement.list.append.qualified
%type <int> statement.math.precision
%type <int> statement.math.precision.list
%type <int> statement.math.precision.list.start
%type <int> statement.math.precision.list.append
%type <Type::exp> statement.signal.pattern.rule
%type <Type::exp> statement.signal.pattern.rule.list
%type <Type::exp> statement.signal.pattern.rule.list.start
%type <Type::exp> statement.signal.pattern.rule.list.append

%% /* grammar rules and actions follow; tokens in caps, rules lowercase */


/***********************************************/
/******************** Start ********************/
/***********************************************/

program:
		statement.list {
			$$ = $[statement.list];
			gGlobal->gResult = formatDefinitions($$);
		}
  | /* empty */ { $$ = gGlobal->nil; }

/*--------------------------------------------*
|  Everything else is in alphabetical order.  |
*--------------------------------------------*/

/*********************************************/
/******************** Doc ********************/
/*********************************************/

doc:
		doc.text {
			$$ = docTxt($[doc.text].c_str());
//			delete $[doc.text];
		}
  | doc.equation { $$ = docEqn($[doc.equation]); }
  | doc.diagram { $$ = docDgm($[doc.diagram]); }
  | doc.notice { $$ = docNtc(); }
  | doc.list { $$ = docLst(); }
  | doc.metadata { $$ = docMtd($[doc.metadata]); }
	| /* empty */ { $$ = gGlobal->nil; }

  doc.text:
      DOCCHAR { $$ = $DOCCHAR; }
    | doc.text[prior] DOCCHAR { $$ = $prior.append(yytext); }

  doc.equation:
      BEQN expression EEQN { $$ = $expression; }

  doc.diagram:
      BDGM expression EDGM { $$ = $expression; }

  doc.notice:
      NOTICE { }

  doc.list:
      BLST doc.attribute.list ELST { }
   |  BLST /* Empty list */ ELST { }

    doc.attribute.list:
        doc.attribute.definition {}
      | doc.attribute.list doc.attribute.definition { }

    doc.attribute.definition:
        LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ {
          gGlobal->gLstDependenciesSwitch = $[doc.attribute.value];
        }
      | LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ {
          gGlobal->gStripDocSwitch = $[doc.attribute.value];
          gGlobal->gStripDocSwitch ? gGlobal->gStripDocSwitch=false
                                   : gGlobal->gStripDocSwitch=true;
        }
      | LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ {
          gGlobal->gLstDistributedSwitch = $[doc.attribute.value];
        }

    doc.attribute.value:
        LSTTRUE { $$ = true; }
      | LSTFALSE { $$ = false; }

  doc.metadata:
    BMETADATA statement.identifier[metadata] EMETADATA { $$ = $metadata; }

/****************************************************/
/******************** Expression ********************/
/****************************************************/

expression:
		statement.definition.with
  | expression.letrec
  | expression.parallel
  | expression.composition
  
  /******************** Component ********************/
  
  expression.component:
      COMPONENT LPAR primitive.string.unquoted RPAR { $$ = boxComponent($[primitive.string.unquoted]); }

  /******************** Composition ********************/

  expression.composition:
      expression.composition.sequence
    | expression.composition.split
    | expression.composition.mix
    | expression.composition.record
    | expression.infix

    expression.composition.list:
        expression.composition { $$ = cons($[expression.composition],gGlobal->nil); }
      | expression.composition.list[prior] COMMA expression.composition[next] { $$ = cons($next,$prior); }

    expression.composition.mix:
        expression.composition[lhs] MIX expression.composition[rhs] { $$ = boxMerge($lhs,$rhs); }
        
    expression.composition.record:
        expression.composition[lhs] REC expression.composition[rhs] { $$ = boxRec($lhs,$rhs); }
      
    expression.composition.sequence:
        expression.composition[lhs] SEQ expression.composition[rhs] { $$ = boxSeq($lhs,$rhs); }

    expression.composition.split:
        expression.composition[lhs] SPLIT expression.composition[rhs] { $$ = boxSplit($lhs,$rhs); }
        
  /******************** Environment ********************/

  expression.environment:
      ENVIRONMENT LBRAQ statement.list RBRAQ {
        $$ = boxWithLocalDef(boxEnvironment(),formatDefinitions($[statement.list]));
      }

  /******************** Infix ********************/

  expression.infix:
      expression.infix.definitions.local
    | expression.infix.environment.access
    | expression.infix.math
    | expression.infix.signal.delay
    | expression.infix.prefix
    | expression.component
    | expression.environment
    | expression.iterate.parallel
    | expression.iterate.sequence
    | expression.iterate.sum
    | expression.iterate.product
    | expression.lambda
    | expression.library
    | expression.math
    | expression.parenthesis
    | expression.signal

    | statement.identifier.box

    | primitive

  expression.infix.definitions.local:
      expression.infix[lhs] LCROC statement.definition.list[defs] RCROC {
        $$ = boxModifLocalDef($lhs,formatDefinitions($defs));
      }
      
  expression.infix.environment.access:
      expression.infix[lhs] DOT statement.identifier.box[rhs] { $$ = boxAccess($lhs,$rhs); }

  expression.infix.math:
      expression.infix.math.algebra
    | expression.infix.math.comparison
    | expression.infix.math.logic
    | expression.infix.math.shift

  expression.infix.math.algebra:
      expression.infix[lhs] ADD   expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigAdd)); }
    | expression.infix[lhs] SUB   expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigSub)); }
    | expression.infix[lhs] MUL   expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigMul)); }
    | expression.infix[lhs] DIV   expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigDiv)); }
    | expression.infix[lhs] MOD   expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigRem)); }
    | expression.infix[lhs] POWOP expression.infix[rhs] {
        $$ = boxSeq(boxPar($lhs,$rhs),gGlobal->gPowPrim->box());
      }

  expression.infix.math.comparison:
      expression.infix[lhs] LT expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigLT)); }
    | expression.infix[lhs] LE expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigLE)); }
    | expression.infix[lhs] GT expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigGT)); }
    | expression.infix[lhs] GE expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigGE)); }
    | expression.infix[lhs] EQ expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigEQ)); }
    | expression.infix[lhs] NE expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigNE)); }

  expression.infix.math.logic:
      expression.infix[lhs] AND expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigAND)); }
    | expression.infix[lhs] OR  expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigOR)); }
    | expression.infix[lhs] XOR expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigXOR)); }

  expression.infix.math.shift:
      expression.infix[lhs] LSH expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigLeftShift)); }
    | expression.infix[lhs] RSH expression.infix[rhs] {
        $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigARightShift));
      }

  expression.infix.prefix:
      expression.infix[lhs] LPAR  expression.composition.list RPAR { $$ = buildBoxAppl($lhs,$[expression.composition.list]); }
  
  expression.infix.signal.delay:
      expression.infix[lhs] FDELAY expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigDelay)); }
    | expression.infix[lhs] DELAY1 { $$ = boxSeq($lhs,boxPrim1(sigDelay1)); }

  /******************** Iteration ********************/

  expression.iterate.parallel:
      ITERATE_PARALLEL LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR {
        $$ = boxIPar($[statement.identifier.box],$[expression.composition],$expression);
      }

  expression.iterate.sequence:
      ISEQ LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR {
        $$ = boxISeq($[statement.identifier.box],$[expression.composition],$expression);
      }

  expression.iterate.sum:
      ISUM LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR {
        $$ = boxISum($[statement.identifier.box],$[expression.composition],$expression);
      }

  expression.iterate.product:
      IPROD LPAR statement.identifier.box COMMA expression.composition COMMA expression RPAR {
        $$ = boxIProd($[statement.identifier.box],$[expression.composition],$expression);
      }

  /******************** Lambda ********************/

  expression.lambda:
      LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR {
        $$ = buildBoxAbstr($[expression.lambda.params],$expression);
      }
  
  expression.lambda.params:
		expression.lambda.params.start
  | expression.lambda.params.append

    expression.lambda.params.start:
        statement.identifier.box { $$ = cons($[statement.identifier.box],gGlobal->nil); }

    expression.lambda.params.append:
        expression.lambda.params[prior] COMMA statement.identifier.box[next] { $$ = cons($next,$prior); }

  /******************** Letrec ********************/

  expression.letrec:
    expression[lhs] LETREC LBRAQ /* empty expression.letrec.list */ RBRAQ {
			$$ = boxWithRecDef($lhs,formatDefinitions(gGlobal->nil), gGlobal->nil);
		}
  | expression[lhs] LETREC LBRAQ expression.letrec.list RBRAQ {
			$$ = boxWithRecDef($lhs,formatDefinitions($[expression.letrec.list]), gGlobal->nil);
		}
  | expression[lhs] LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ {
			$$ = boxWithRecDef($lhs,formatDefinitions($[expression.letrec.list]),formatDefinitions($[expression.letrec.list]));
		}

  expression.letrec.list:
      expression.letrec.list.start
    | expression.letrec.list.append

    expression.letrec.list.start:
        expression.letrec.equation[item] { $$ = cons($item, gGlobal->nil); }
        
    expression.letrec.list.append:
        expression.letrec.list[prior] expression.letrec.equation[next] { $$ = cons ($next,$prior); }
        
  expression.letrec.equation:
      expression.letrec.equation.name[variable] DEF expression ENDDEF {
        $$ = cons($variable,cons(gGlobal->nil,$expression));
        setDefProp($variable, yyfilename, yylineno);
      }
    | error ENDDEF { $$ = gGlobal->nil; yyerr++; }

    expression.letrec.equation.name:
        DELAY1 statement.identifier.box { $$=$[statement.identifier.box]; }


  /******************** Library ********************/

  expression.library:
      LIBRARY LPAR primitive.string.unquoted RPAR { $$ = boxLibrary($[primitive.string.unquoted]); }

  /******************** Math ********************/

  expression.math:
      expression.math.signal
    | expression.math.scalar
    | expression.math.comparison
    | expression.math.trigonometry
    | expression.math.rounding

    expression.math.comparison:
        LT { $$ = boxPrim2(sigLT); }
      | LE { $$ = boxPrim2(sigLE); }
      | GT { $$ = boxPrim2(sigGT); }
      | GE { $$ = boxPrim2(sigGE); }
      | EQ { $$ = boxPrim2(sigEQ); }
      | NE { $$ = boxPrim2(sigNE); }

      expression.math.rounding:
          ABS { $$ = gGlobal->gAbsPrim->box(); }
        | MIN { $$ = gGlobal->gMinPrim->box(); }
        | MAX { $$ = gGlobal->gMaxPrim->box(); }
        | FLOOR { $$ = gGlobal->gFloorPrim->box(); }
        | CEIL { $$ = gGlobal->gCeilPrim->box(); }
        | ASSERTBOUNDS { $$ = boxPrim3(sigAssertBounds);}
        | LOWEST { $$ = boxPrim1(sigLowest);}
        | HIGHEST { $$ = boxPrim1(sigHighest);}
        | RINT { $$ = gGlobal->gRintPrim->box(); }

    expression.math.signal:
        expression.math.signal.algebra
      | expression.math.signal.shift
      | expression.math.signal.power

      expression.math.signal.algebra:
          ADD { $$ = boxPrim2(sigAdd); }
        | SUB { $$ = boxPrim2(sigSub); }
        | MUL { $$ = boxPrim2(sigMul); }
        | DIV { $$ = boxPrim2(sigDiv); }
        | MOD { $$ = boxPrim2(sigRem); }
        | FMOD { $$ = gGlobal->gFmodPrim->box(); }
        | REMAINDER { $$ = gGlobal->gRemainderPrim->box(); }
        | SUB statement.identifier.box { $$ = boxSeq(boxPar(boxInt(0),$[statement.identifier.box]),boxPrim2(sigSub)); }

      expression.math.signal.shift:
          LSH { $$ = boxPrim2(sigLeftShift); }
        | RSH { $$ = boxPrim2(sigARightShift); }

      expression.math.signal.power:
          EXP { $$ = gGlobal->gExpPrim->box(); }
        | LOG { $$ = gGlobal->gLogPrim->box(); }
        | LOG10 { $$ = gGlobal->gLog10Prim->box(); }
        | POWOP { $$ = gGlobal->gPowPrim->box(); }
        | POWFUN { $$ = gGlobal->gPowPrim->box(); }
        | SQRT { $$ = gGlobal->gSqrtPrim->box(); }

      expression.math.scalar:
          ADD INT { $$ = boxInt(str2int(yytext)); }
        | ADD FLOAT { $$ = boxReal($FLOAT); }
        | SUB INT { $$ = boxInt ( -$INT ); }
        | SUB FLOAT { $$ = boxReal( -$FLOAT ); }

      expression.math.trigonometry:
          ACOS { $$ = gGlobal->gAcosPrim->box(); }
        | ASIN { $$ = gGlobal->gAsinPrim->box(); }
        | ATAN { $$ = gGlobal->gAtanPrim->box(); }
        | ATAN2 { $$ = gGlobal->gAtan2Prim->box(); }
        | COS { $$ = gGlobal->gCosPrim->box(); }
        | SIN { $$ = gGlobal->gSinPrim->box(); }
        | TAN { $$ = gGlobal->gTanPrim->box(); }

  /******************** Parenthesis ********************/

  expression.parenthesis:
    LPAR expression RPAR { $$ = $expression; }

  /******************** Parallel ********************/

  expression.parallel:
      expression[lhs] COMMA expression[rhs] {
        $$ = boxPar($lhs,$rhs);
      }
      
  /******************** Signal ********************/

  expression.signal:
      expression.signal.control
    | expression.signal.delay
    | expression.signal.logic
  
    expression.signal.control:
        ATTACH { $$ = boxPrim2(sigAttach); }
      | ENABLE { $$ = boxPrim2(sigEnable); }
      | CONTROL { $$ = boxPrim2(sigControl); }

    expression.signal.delay:
        MEM { $$ = boxPrim1(sigDelay1); }
      | PREFIX { $$ = boxPrim2(sigPrefix); }
      | FDELAY { $$ = boxPrim2(sigDelay); }

    expression.signal.logic:
        AND { $$ = boxPrim2(sigAND); }
      | OR { $$ = boxPrim2(sigOR); }
      | XOR { $$ = boxPrim2(sigXOR); }
      | SELECT2 { $$ = boxPrim3(sigSelect2); }
      | SELECT3 { $$ = boxPrim4(sigSelect3); }
      | CASE LBRAQ statement.signal.pattern.rule.list RBRAQ { $$ = boxCase(checkRulelist($[statement.signal.pattern.rule.list])); }

/***************************************************/
/******************** Primitive ********************/
/***************************************************/

primitive:
    primitive.foreign
  | primitive.number
  | primitive.type.number
  | primitive.signal
  | primitive.ui
  
  /******************** Foreign ********************/

  primitive.foreign:
    primitive.foreign.constant
  | primitive.foreign.function
  | primitive.foreign.variable

  /******************** Number ********************/

  primitive.number:
      INT { $$ = boxInt(str2int(yytext)); }
    | FLOAT { $$ = boxReal(atof(yytext)); }

  /******************** String ********************/
        
  primitive.string.quoted:
      STRING { $$ = tree(yytext); }

  primitive.string.unquoted:
      STRING { $$ = unquote(yytext); }

  primitive.string.tag:
      STRING { $$ = tree(yytext); }
    | TAGSTRING { $$ = tree(yytext); }

  /******************** Signal ********************/

  primitive.signal:
    primitive.signal.inputs
  | primitive.signal.input.implicit
  | primitive.signal.input.terminate
  | primitive.signal.outputs
  | primitive.signal.route
  | primitive.signal.source
  
  primitive.signal.input.implicit:
      WIRE { $$ = boxWire(); }

  primitive.signal.input.terminate:
      CUT { $$ = boxCut(); }

  primitive.type:
      primitive.type.number
    | primitive.type.any

    /******************** Numbers ********************/

    primitive.type.number.list:
        primitive.type.number.list.start
      | primitive.type.number.list.append

      primitive.type.number.list.member:
          primitive.number {
            gGlobal->gWaveForm.push_back($[primitive.number]);
          }
        | expression.math.scalar {
            gGlobal->gWaveForm.push_back($[expression.math.scalar]);
          }

      primitive.type.number.list.start:
        primitive.type.number.list.member
        
      primitive.type.number.list.append:
          primitive.type.number.list COMMA primitive.type.number.list.member

    primitive.type.number:
        primitive.type.number.int
      | primitive.type.number.float

      primitive.type.number.int:
          INTCAST { $$ = boxPrim1(sigIntCast); }

      primitive.type.number.float:
          FLOATCAST { $$ = boxPrim1(sigFloatCast); }

    primitive.type.any:
        ANYCAST { $$ = tree(2); }

    primitive.signal.route:
        ROUTE[fake] LPAR expression.composition[arg1] COMMA expression.composition[arg2] RPAR {
          $$ = boxRoute($arg1, $arg2, boxPar(boxInt(0),boxInt(0)));
        } /* fake route */
      | ROUTE LPAR expression.composition[arg1] COMMA expression.composition[arg2] COMMA expression RPAR {
          $$ = boxRoute($arg1, $arg2, $expression);
        }
        
    primitive.signal.source:
        primitive.signal.source.waveform
      | primitive.signal.source.soundfile
      | primitive.signal.source.table

      primitive.signal.source.table:
          RDTBL { $$ = boxPrim3(sigReadOnlyTable); }
        | RWTBL { $$ = boxPrim5(sigWriteReadTable); }

      primitive.signal.source.soundfile:
          SOUNDFILE LPAR primitive.string.unquoted COMMA expression.composition RPAR {
            $$ = boxSoundfile( $[primitive.string.unquoted], $[expression.composition] );
          }
        
      primitive.signal.source.waveform:
        WAVEFORM LBRAQ primitive.type.number.list RBRAQ {
          $$ = boxWaveform(gGlobal->gWaveForm);
          gGlobal->gWaveForm.clear();
          /* primitive.type.number.list pushes values onto gGlobal->gWaveForm */
        }

    /******************** Type ********************/

    primitive.type.list:
        primitive.type.list.start
      | primitive.type.list.append

      primitive.type.list.start:
          primitive.type { $$ = cons($[primitive.type],gGlobal->nil); }

      primitive.type.list.append:
          primitive.type.list[prior] COMMA primitive.type[next] { $$ = cons($next,$prior); }


  /******************** UI ********************/

  primitive.ui:
      primitive.ui.button
   |  primitive.ui.checkbox
   |  primitive.ui.vslider
   |  primitive.ui.hslider
   |  primitive.ui.nentry
   |  primitive.ui.vgroup
   |  primitive.ui.hgroup
   |  primitive.ui.tgroup
   |  primitive.ui.vbargraph
   |  primitive.ui.hbargraph

    primitive.ui.button:
        BUTTON LPAR primitive.string.unquoted RPAR { $$ = boxButton($[primitive.string.unquoted]); }

    primitive.ui.checkbox:
        CHECKBOX LPAR primitive.string.unquoted RPAR { $$ = boxCheckbox($[primitive.string.unquoted]); }

    primitive.ui.vslider:
        VSLIDER LPAR primitive.string.unquoted COMMA expression.composition[arg1] COMMA expression.composition[arg2] COMMA expression.composition[arg3] COMMA expression.composition[arg4] RPAR {
          $$ = boxVSlider($[primitive.string.unquoted],$arg1,$arg2,$arg3,$arg4);
        }

    primitive.ui.hslider:
        HSLIDER LPAR primitive.string.unquoted COMMA expression.composition[arg1] COMMA expression.composition[arg2] COMMA expression.composition[arg3] COMMA expression.composition[arg4] RPAR {
          $$ = boxHSlider($[primitive.string.unquoted],$arg1,$arg2,$arg3,$arg4);
        }

    primitive.ui.nentry:
        NENTRY LPAR primitive.string.unquoted COMMA expression.composition[arg1] COMMA expression.composition[arg2] COMMA expression.composition[arg3] COMMA expression.composition[arg4] RPAR {
          $$ = boxNumEntry($[primitive.string.unquoted],$arg1,$arg2,$arg3,$arg4);
        }

    primitive.ui.vgroup:
        VGROUP LPAR primitive.string.unquoted COMMA expression RPAR { $$ = boxVGroup($[primitive.string.unquoted], $expression); }

    primitive.ui.hgroup:
        HGROUP LPAR primitive.string.unquoted COMMA expression RPAR { $$ = boxHGroup($[primitive.string.unquoted], $expression); }

    primitive.ui.tgroup:
        TGROUP LPAR primitive.string.unquoted COMMA expression RPAR { $$ = boxTGroup($[primitive.string.unquoted], $expression); }

    primitive.ui.vbargraph:
        VBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition[arg1] COMMA expression.composition[arg2] RPAR {
          $$ = boxVBargraph($[primitive.string.unquoted],$arg1,$arg2);
        }

    primitive.ui.hbargraph:
        HBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition[arg1] COMMA expression.composition[arg2] RPAR {
          $$ = boxHBargraph($[primitive.string.unquoted],$arg1,$arg2);
        }

    /******************** Foreign ********************/

    primitive.foreign.function:
        FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag COMMA primitive.string.unquoted RPAR {
          $$ = boxFFun(ffunction($[primitive.foreign.function.signature],$[primitive.string.tag],$[primitive.string.unquoted]));
        }

      primitive.foreign.function.signature:
          primitive.type.number statement.identifier.waveform[fun] LPAR primitive.type.list RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun,cons($fun,cons($fun,gGlobal->nil))), $[primitive.type.list]));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] LPAR primitive.type.list RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun2,gGlobal->nil))), $[primitive.type.list]));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] OR statement.identifier.waveform[fun3] LPAR primitive.type.list RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun3,gGlobal->nil))), $[primitive.type.list]));
          }
        | primitive.type.number statement.identifier.waveform[fun] LPAR RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun,cons($fun,cons($fun,gGlobal->nil))), gGlobal->nil));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] LPAR RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun2,gGlobal->nil))), gGlobal->nil));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] OR statement.identifier.waveform[fun3] LPAR RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun3,gGlobal->nil))), gGlobal->nil));
          }

    primitive.foreign.constant:
        FCONSTANT LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR {
          $$ = boxFConst( $[primitive.type.number], $[statement.identifier], $[primitive.string.tag]);
        }

    primitive.foreign.variable:
        FVARIABLE LPAR primitive.type.number statement.identifier COMMA primitive.string.tag RPAR {
          $$ = boxFVar( $[primitive.type.number], $[statement.identifier], $[primitive.string.tag] );
        }

    /******************** I/O ********************/

    primitive.signal.inputs:
        INPUTS LPAR expression RPAR { $$ = boxInputs($expression); }

    primitive.signal.outputs:
        OUTPUTS LPAR expression RPAR { $$ = boxOutputs($expression); }

/***************************************************/
/******************** Statement ********************/
/***************************************************/


statement:
    statement.definition
  | statement.declare.metadata
  | statement.declare.feature.metadata
  | statement.declare.doc
  | statement.import

  /******************** Definition ********************/

  statement.definition:
      statement.definition.function
    | statement.definition.substitution
    | statement.definition.error

    statement.definition.function.incomplete:
      statement.identifier.box LPAR expression.composition.list RPAR DEF expression {
        $$ = cons(
          $[statement.identifier.box],
          cons( $[expression.composition.list], $expression )
        );
        setDefProp($[statement.identifier.box], yyfilename, yylineno);
      }
      
    statement.definition.function:
        statement.definition.function.incomplete ENDDEF {
          $$ = $[statement.definition.function.incomplete];
        }
      | statement.definition.function.incomplete error ENDL {
          yyerr++;
//          error(*yylocationp, std::string("Missing semicolon.");
//          delete (yysemantic_stack_[(1) - (1)].stringVal);
          $$ = $[statement.definition.function.incomplete];
          yyerrok;
        }

      
    statement.definition.substitution:
        statement.identifier.box[substitution_name] DEF expression[body] ENDDEF {
          $$ = cons($substitution_name,cons(gGlobal->nil,$body));
          setDefProp($substitution_name, yyfilename, yylineno);
        }
    
    statement.definition.with:
      expression WITH LBRAQ statement.definition.list RBRAQ {
        $$ = boxWithLocalDef($expression,formatDefinitions($[statement.definition.list]));
      }

    statement.definition.error:
        error ENDDEF {
          $$ = gGlobal->nil;
          yyerr++;
        }

    statement.definition.list:
        statement.definition.list.start
      | statement.definition.list.start.qualified
      | statement.definition.list.append
      | statement.definition.list.append.qualified

      statement.definition.list.start:
          statement.definition {
            $$ = cons( $[statement.definition.list.start], gGlobal->nil );
          }

      statement.definition.list.start.qualified:
          statement.math.precision.list statement.definition {
            if (acceptdefinition($[statement.math.precision.list]))
              $$ = cons( $[statement.definition], gGlobal->nil );
            else
              $$ = gGlobal->nil;
          }

      statement.definition.list.append:
          statement.definition.list statement.definition {
            $$ = cons ($[statement.definition],$[statement.definition.list]);
          }
          
      statement.definition.list.append.qualified:
          statement.definition.list statement.math.precision.list statement.definition {
            if (acceptdefinition($[statement.math.precision.list]))
              $$ = cons ($[statement.definition],$[statement.definition.list]);
            else
              $$ = $[statement.definition.list];
          }

  /******************** Declare ********************/

  statement.declare.metadata:
      DECLARE statement.identifier[key] primitive.string.quoted[value] ENDDEF {
        declareMetadata($key,$value);
        $$ = gGlobal->nil;
      }

  statement.declare.feature.metadata:
      DECLARE statement.identifier[feature] statement.identifier[key] primitive.string.quoted[value] ENDDEF {
        declareDefinitionMetadata( $feature, $key, $value );
        $$ = gGlobal->nil;
      }

  statement.declare.doc:
      BDOC doc[body] EDOC {
        declareDoc($body);
        $$ = gGlobal->nil;
      }

  /******************** Identifier ********************/

  statement.identifier:
      IDENT {
        $$ = tree(yytext);
        setUseProp($$, yyfilename, yylineno);
      }

  statement.identifier.box:
      IDENT {
        $$ = boxIdent(yytext);
        setUseProp($$, yyfilename, yylineno);
      }

  statement.identifier.waveform:
      IDENT { $$ = tree(yytext); }

  /******************** Import ********************/

  statement.import:
      IMPORT LPAR primitive.string.unquoted[filename] RPAR ENDDEF { $$ = importFile($filename); }

  /******************** List ********************/

  statement.list:
      statement.list.start
    | statement.list.start.qualified
    | statement.list.append
    | statement.list.append.qualified
   
    statement.list.start:
        statement {
          $$ = cons($statement, gGlobal->nil);
        }

    statement.list.start.qualified:
        statement.math.precision.list statement {
          if (acceptdefinition($[statement.math.precision.list]))
            $$ = cons($statement, gGlobal->nil);
          else
            $$ = gGlobal->nil;
        }

    statement.list.append:
        statement.list statement {
          $$ = cons($statement,$[statement.list]);
        }
    
    statement.list.append.qualified:
        statement.list statement.math.precision.list statement {
          if (acceptdefinition($[statement.math.precision.list]))
            $$ = cons($[statement.list],$[statement]);
          else
            $$=$[statement.list];
        }

  /******************** Math ********************/

    statement.math.precision:
        FLOATMODE { $$ = 1; }
      | DOUBLEMODE { $$ = 2; }
      | QUADMODE { $$ = 4; }
      | FIXEDPOINTMODE { $$ = 8; }

      statement.math.precision.list:
          statement.math.precision.list.start
        | statement.math.precision.list.append

        statement.math.precision.list.start:
            statement.math.precision

        statement.math.precision.list.append:
            statement.math.precision.list statement.math.precision {
              $$ = $[statement.math.precision.list] | $[statement.math.precision];
            }

  /******************** Rules ********************/

  statement.signal.pattern.rule.list:
      statement.signal.pattern.rule.list.start
    | statement.signal.pattern.rule.list.append

    statement.signal.pattern.rule.list.start:
        statement.signal.pattern.rule { $$ = cons($[statement.signal.pattern.rule],gGlobal->nil); }
    
    statement.signal.pattern.rule.list.append:
        statement.signal.pattern.rule.list[prior] statement.signal.pattern.rule[next] { $$ = cons($next,$prior); }

  statement.signal.pattern.rule:
      LPAR expression.composition.list RPAR ARROW expression ENDDEF { $$ = cons($[expression.composition.list],$expression); }

%%
