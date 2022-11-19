/* -*- Mode: C++; tab-width: 2; c-basic-offset: 4 -*- */

/* Parser for the Faust language */
%require "3.2"
%language "c++"
%define api.value.type variant

%define api.token.raw
%define api.token.constructor
%define api.token.prefix {FAUST_}

%define api.namespace {::Faust::Compiler::Parser}
%define api.parser.class {AbstractImplementation}

%define parse.assert /* runtime assertions to catch invalid uses */
%define parse.trace /* set yydebug = 1 to print trace to stderr */
%define parse.error verbose /* simple, detailed, verbose */
%define parse.lac full /* look-ahead correction (5.8.3 LAC) */

%param { Implementation& self }

%header "abstract/implementation.hh"   /* Generate faustparser.hh */

%locations /* Generate location.hh */
%verbose   /* Generate faustparser.output */

%initial-action
{
  @$.begin.filename = @$.end.filename = &this->self._streamName;
};

%code requires { /* Faust requires */
  #include <string>
  #include "compiler/parser/type/tokens.hh"
  #include "compiler/parser/abstract/location.hh"
  namespace Faust { namespace Compiler { namespace Parser {
    struct Implementation;
    namespace Lexer { struct Implementation; }
  } } }
}

%code { /* Faust code */
  #include "compiler/parser/implementation.hh"
}

%{ /* Faust */

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

#define YYMAXDEPTH	100000

#include "faust/primitive/math.hh"

#include "compiler/parser/lexer/implementation.hh"
#undef yylex
#define yylex this->self._lexer->lex


%}

%start program

/* With local environment (lowest priority)*/
%left <std::string> WITH
%left <std::string> LETREC

/* Block Diagram Algebra */
/*%left SEQ SPLIT MIX*/
%right <std::string> SPLIT
%right <std::string> MIX
%right <std::string> SEQ
%right <std::string> COMMA
%left <std::string> REC

/* Primitive boxes */

//%left LT LE EQ GT GE NE
%nonassoc <std::string> LT
%nonassoc <std::string> LE
%nonassoc <std::string> EQ
%nonassoc <std::string> GT
%nonassoc <std::string> GE
%nonassoc <std::string> NE

%left <std::string> ADD
%left <std::string> SUB
%left <std::string> OR

%left <std::string> MUL
%left <std::string> DIV
%left <std::string> MOD
%left <std::string> AND
%left <std::string> XOR
%left <std::string> LSH
%left <std::string> RSH

%left <std::string> POWOP
%left <std::string> FDELAY
%left <std::string> DELAY1
/*%left APPL*/
%left <std::string> DOT

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

%token <std::string> WIRE
%token <std::string> CUT
%token <std::string> ENDDEF
%token <std::string> VIRG
%left <std::string> LPAR
%left <std::string> RPAR
%token <std::string> LBRAQ
%left <std::string> RBRAQ
%left <std::string> LCROC
%left <std::string> RCROC
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

%token ENDOFINPUT 0

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

%type <Tree> doc
%type <Tree> doc.attribute.list
%type <Tree> doc.attribute.definition
%type <bool> doc.attribute.value
%type <std::string> doc.text
%type <Tree> doc.equation
%type <Tree> doc.diagram
%type <Tree> doc.notice
%type <Tree> doc.list
%type <Tree> doc.metadata

%type <Tree> expression
%type <Tree> expression.component
%type <Tree> expression.composition
%type <Tree> expression.composition.parallel
%type <Tree> expression.composition.serial
%type <Tree> expression.composition.mix
%type <Tree> expression.composition.recursive
%type <Tree> expression.composition.sequence
%type <Tree> expression.composition.split
//%type <Tree> expression.composition.list
//%type <Tree> expression.composition.list.start
//%type <Tree> expression.composition.list.append
%type <Tree> expression.environment
%type <Tree> statement.identifier.box
%type <Tree> expression.infix
%type <Tree> expression.infix.definitions.substitution
%type <Tree> expression.infix.environment.access
%type <Tree> expression.infix.math
%type <Tree> expression.infix.math.algebra
%type <Tree> expression.infix.math.comparison
%type <Tree> expression.infix.math.logic
%type <Tree> expression.infix.math.shift
%type <Tree> expression.infix.prefix
%type <Tree> expression.infix.signal.delay
%type <Tree> expression.iterate.parallel
%type <Tree> expression.iterate.sequence
%type <Tree> expression.iterate.sum
%type <Tree> expression.iterate.product
%type <Tree> expression.lambda
%type <Tree> expression.lambda.params
%type <Tree> expression.lambda.params.start
%type <Tree> expression.lambda.params.append
%type <Tree> expression.letrec
%type <Tree> expression.letrec.list
%type <Tree> expression.letrec.list.start
%type <Tree> expression.letrec.list.append
%type <Tree> expression.letrec.equation
%type <Tree> expression.letrec.equation.name
%type <Tree> expression.library
%type <Tree> expression.math
%type <Tree> expression.math.comparison
%type <Tree> expression.math.rounding
%type <Tree> expression.math.scalar
%type <Tree> expression.math.signal
%type <Tree> expression.math.signal.algebra
%type <Tree> expression.math.signal.shift
%type <Tree> expression.math.signal.power
%type <Tree> expression.math.trigonometry
%type <Tree> expression.parenthesis
%type <Tree> expression.signal
%type <Tree> expression.signal.control
%type <Tree> expression.signal.delay
%type <Tree> expression.signal.logic

%type <Tree> primitive
%type <Tree> primitive.foreign
%type <Tree> primitive.foreign.constant
%type <Tree> primitive.foreign.function
%type <Tree> primitive.foreign.function.signature
%type <Tree> primitive.foreign.variable
%type <Tree> primitive.signal.input.implicit
%type <Tree> primitive.signal.input.terminate
%type <Tree> primitive.signal.inputs
%type <Tree> primitive.number
%type <Tree> primitive.type.number.list
%type <Tree> primitive.type.number.list.start
%type <Tree> primitive.type.number.list.append
%type <Tree> primitive.type.number.list.member
%type <Tree> primitive.signal.outputs
%type <Tree> primitive.signal
%type <Tree> primitive.signal.route
%type <Tree> primitive.signal.route.implied.outputs
%type <Tree> primitive.signal.route.implied.connections
%type <Tree> primitive.signal.route.explicit
%type <Tree> primitive.signal.source
%type <Tree> primitive.signal.source.soundfile
%type <Tree> primitive.signal.source.table
%type <Tree> primitive.signal.source.waveform
%type <Tree> primitive.string.quoted
%type <Tree> primitive.string.tag
%type <Tree> primitive.string.unquoted
%type <Tree> primitive.type
%type <Tree> primitive.type.list
%type <Tree> primitive.type.list.start
%type <Tree> primitive.type.list.append
%type <Tree> primitive.type.number
%type <Tree> primitive.type.number.int
%type <Tree> primitive.type.number.float
%type <Tree> primitive.type.any

%type <Tree> primitive.ui
%type <Tree> primitive.ui.button
%type <Tree> primitive.ui.checkbox
%type <Tree> primitive.ui.vslider
%type <Tree> primitive.ui.hslider
%type <Tree> primitive.ui.nentry
%type <Tree> primitive.ui.vgroup
%type <Tree> primitive.ui.hgroup
%type <Tree> primitive.ui.tgroup
%type <Tree> primitive.ui.vbargraph
%type <Tree> primitive.ui.hbargraph

%type <Tree> program

%type <Tree> statement
%type <Tree> statement.definition
%type <Tree> statement.definition.assignment
%type <Tree> statement.definition.error
%type <Tree> statement.definition.function
%type <Tree> statement.definition.function.incomplete
%type <Tree> statement.definition.list
%type <Tree> statement.definition.list.start
%type <Tree> statement.definition.list.start.qualified
%type <Tree> statement.definition.list.append
%type <Tree> statement.definition.list.append.qualified
%type <Tree> statement.definition.with
%type <Tree> statement.declare.doc
%type <Tree> statement.declare.metadata
%type <Tree> statement.declare.feature.metadata
%type <Tree> statement.identifier
%type <Tree> statement.identifier.waveform
%type <Tree> statement.import
%type <Tree> statement.list
%type <Tree> statement.list.start
%type <Tree> statement.list.start.qualified
%type <Tree> statement.list.append
%type <Tree> statement.list.append.qualified
%type <int> statement.math.precision
%type <int> statement.math.precision.list
%type <int> statement.math.precision.list.start
%type <int> statement.math.precision.list.append
%type <Tree> statement.signal.pattern.rule
%type <Tree> statement.signal.pattern.rule.list
%type <Tree> statement.signal.pattern.rule.list.start
%type <Tree> statement.signal.pattern.rule.list.append

%% /* grammar rules and actions follow; tokens in caps, rules lowercase */


/***********************************************/
/******************** Start ********************/
/***********************************************/

program:
		statement.list {
			$$ = $[statement.list];
			self._ast = self.formatDefinitions($$);
		}
  | /* empty */ { $$ = self._nil; }

/*-----------------------------------------------------*
|  Everything else is in (mostly) alphabetical order.  |
*-----------------------------------------------------*/

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
	| /* empty */ { $$ = self._nil; }

  doc.text:
      DOCCHAR { $$ = $DOCCHAR; }
    | doc.text[prior] DOCCHAR { $$ = $prior.append(self._lexer->YYText()); }

  doc.equation:
      BEQN expression EEQN { $$ = $expression; }

  doc.diagram:
      BDGM expression EDGM { $$ = $expression; }

  doc.notice:
      NOTICE { }

  doc.metadata:
    BMETADATA statement.identifier[metadata] EMETADATA { $$ = $metadata; }

  /*------------------- doc.list -------------------*/

  doc.list:
      BLST doc.attribute.list ELST { }
   |  BLST /* Empty list */ ELST { }

    doc.attribute.list:
        doc.attribute.definition {}
      | doc.attribute.list doc.attribute.definition { }

    doc.attribute.definition:
        LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ {
          self._lstDependenciesSwitch = $[doc.attribute.value];
        }
      | LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ {
          self._stripDocSwitch = $[doc.attribute.value];
          self._stripDocSwitch ? self._stripDocSwitch=false
                                   : self._stripDocSwitch=true;
        }
      | LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ {
          self._lstDistributedSwitch = $[doc.attribute.value];
        }

    doc.attribute.value:
        LSTTRUE { $$ = true; }
      | LSTFALSE { $$ = false; }

/****************************************************/
/******************** Expression ********************/
/****************************************************/

expression:
		statement.definition.with
  | expression.letrec
  | expression.composition

  /******************** Component ********************/
  
  expression.component:
      COMPONENT LPAR primitive.string.unquoted RPAR {
        $$ = boxComponent($[primitive.string.unquoted]);
      }

  /******************** Composition ********************/

  expression.composition:
    expression.composition.serial
  | expression.composition.parallel
  
  expression.composition.parallel:
      expression[lhs] COMMA expression[rhs] {
        $$ = boxPar( $lhs, $rhs );
      }
                
  expression.composition.serial:
      expression.composition.sequence
    | expression.composition.split
    | expression.composition.mix
    | expression.composition.recursive
    | expression.infix

    expression.composition.mix:
        expression.composition.serial[lhs] MIX expression.composition.serial[rhs] {
          $$ = boxMerge( $lhs, $rhs );
        }
          
    expression.composition.recursive:
        expression.composition.serial[lhs] REC expression.composition.serial[rhs] {
          $$ = boxRec($lhs,$rhs);
        }
      
    expression.composition.sequence:
        expression.composition.serial[lhs] SEQ expression.composition.serial[rhs] {
          $$ = boxSeq($lhs,$rhs);
        }

    expression.composition.split:
        expression.composition.serial[lhs] SPLIT expression.composition.serial[rhs] {
          $$ = boxSplit($lhs,$rhs);
        }

    /*------------------- composition.list -------------------*/

//    expression.composition.list:
//      expression.composition.list.start
//    | expression.composition.list.append
//
//    expression.composition.list.start:
//        expression.composition.serial {
//          $$ = cons( $[expression.composition.serial], self._nil );
//        }
//
//    expression.composition.list.append:
//        expression.composition.list COMMA expression.composition.serial {
//          $$ = cons(
//            $[expression.composition.serial],
//            $[expression.composition.list]
//          );
//        }

  /******************** Environment ********************/

  expression.environment:
      ENVIRONMENT LBRAQ statement.list RBRAQ {
        $$ = boxWithLocalDef(boxEnvironment(),self.formatDefinitions($[statement.list]));
      }

  /******************** Infix ********************/

  expression.infix:
      expression.infix.definitions.substitution
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

  expression.infix.definitions.substitution:
      expression.infix[lhs] LCROC statement.definition.list[defs] RCROC {
        $$ = boxModifLocalDef(
          $lhs,
          self.formatDefinitions($defs)
        );
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
        $$ = boxSeq(boxPar($lhs,$rhs),::Faust::Primitive::Math::functions().pow.box());
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
      expression.infix[lhs] LPAR  expression.composition.parallel RPAR { $$ = buildBoxAppl($lhs,$[expression.composition.parallel]); }
  
  expression.infix.signal.delay:
      expression.infix[lhs] FDELAY expression.infix[rhs] { $$ = boxSeq(boxPar($lhs,$rhs),boxPrim2(sigDelay)); }
    | expression.infix[lhs] DELAY1 { $$ = boxSeq($lhs,boxPrim1(sigDelay1)); }

  /******************** Iteration ********************/

  expression.iterate.parallel:
      ITERATE_PARALLEL LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR {
        $$ = boxIPar($[statement.identifier.box],$[expression.composition.serial],$expression);
      }

  expression.iterate.sequence:
      ISEQ LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR {
        $$ = boxISeq($[statement.identifier.box],$[expression.composition.serial],$expression);
      }

  expression.iterate.sum:
      ISUM LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR {
        $$ = boxISum($[statement.identifier.box],$[expression.composition.serial],$expression);
      }

  expression.iterate.product:
      IPROD LPAR statement.identifier.box COMMA expression.composition.serial COMMA expression RPAR {
        $$ = boxIProd($[statement.identifier.box],$[expression.composition.serial],$expression);
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
        statement.identifier.box { $$ = cons($[statement.identifier.box],self._nil); }

    expression.lambda.params.append:
        expression.lambda.params[prior] COMMA statement.identifier.box[next] { $$ = cons($next,$prior); }

  /******************** Letrec ********************/

  expression.letrec:
    expression[lhs] LETREC LBRAQ /* empty expression.letrec.list */ RBRAQ {
			$$ = boxWithRecDef(
        $lhs,
        self.formatDefinitions(self._nil),
        self._nil
      );
		}
  | expression[lhs] LETREC LBRAQ expression.letrec.list RBRAQ {
			$$ = boxWithRecDef(
        $lhs,
        self.formatDefinitions($[expression.letrec.list]),
        self._nil
      );
		}
  | expression[lhs] LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ {
			$$ = boxWithRecDef(
        $lhs,
        self.formatDefinitions($[expression.letrec.list]),
        self.formatDefinitions($[expression.letrec.list])
      );
		}

  /*------------------- letrec.list -------------------*/

  expression.letrec.list:
      expression.letrec.list.start
    | expression.letrec.list.append

    expression.letrec.list.start:
        expression.letrec.equation[item] { $$ = cons($item, self._nil); }
        
    expression.letrec.list.append:
        expression.letrec.list[prior] expression.letrec.equation[next] { $$ = cons ($next,$prior); }
        
  expression.letrec.equation:
      expression.letrec.equation.name[variable] DEF expression ENDDEF {
        $$ = cons($variable,cons(self._nil,$expression));
        setDefProp($variable, self._streamName.c_str(), self._lexer->lineno());
      }
    | error ENDDEF { $$ = self._nil; self._lexer->LexerError("Expected expression."); }

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
          ABS { $$ = ::Faust::Primitive::Math::functions().abs.box(); }
        | MIN { $$ = ::Faust::Primitive::Math::functions().min.box(); }
        | MAX { $$ = ::Faust::Primitive::Math::functions().max.box(); }
        | FLOOR { $$ = ::Faust::Primitive::Math::functions().floor.box(); }
        | CEIL { $$ = ::Faust::Primitive::Math::functions().ceil.box(); }
        | ASSERTBOUNDS { $$ = boxPrim3(sigAssertBounds);}
        | LOWEST { $$ = boxPrim1(sigLowest);}
        | HIGHEST { $$ = boxPrim1(sigHighest);}
        | RINT { $$ = ::Faust::Primitive::Math::functions().rint.box(); }

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
        | FMOD { $$ = ::Faust::Primitive::Math::functions().fmod.box(); }
        | REMAINDER { $$ = ::Faust::Primitive::Math::functions().remainder.box(); }
        | SUB statement.identifier.box { $$ = boxSeq(boxPar(boxInt(0),$[statement.identifier.box]),boxPrim2(sigSub)); }

      expression.math.signal.shift:
          LSH { $$ = boxPrim2(sigLeftShift); }
        | RSH { $$ = boxPrim2(sigARightShift); }

      expression.math.signal.power:
          EXP { $$ = ::Faust::Primitive::Math::functions().exp.box(); }
        | LOG { $$ = ::Faust::Primitive::Math::functions().log.box(); }
        | LOG10 { $$ = ::Faust::Primitive::Math::functions().log10.box(); }
        | POWOP { $$ = ::Faust::Primitive::Math::functions().pow.box(); }
        | POWFUN { $$ = ::Faust::Primitive::Math::functions().pow.box(); }
        | SQRT { $$ = ::Faust::Primitive::Math::functions().sqrt.box(); }

      expression.math.scalar:
          ADD INT { $$ = boxInt(std::stoi(self._lexer->YYText())); }
        | ADD FLOAT { $$ = boxReal($FLOAT); }
        | SUB INT { $$ = boxInt ( -$INT ); }
        | SUB FLOAT { $$ = boxReal( -$FLOAT ); }

      expression.math.trigonometry:
          ACOS { $$ = ::Faust::Primitive::Math::functions().acos.box(); }
        | ASIN { $$ = ::Faust::Primitive::Math::functions().asin.box(); }
        | ATAN { $$ = ::Faust::Primitive::Math::functions().atan.box(); }
        | ATAN2 { $$ = ::Faust::Primitive::Math::functions().atan2.box(); }
        | COS { $$ = ::Faust::Primitive::Math::functions().cos.box(); }
        | SIN { $$ = ::Faust::Primitive::Math::functions().sin.box(); }
        | TAN { $$ = ::Faust::Primitive::Math::functions().tan.box(); }

  /******************** Parenthesis ********************/

  expression.parenthesis:
    LPAR expression RPAR { $$ = $expression; }

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
      | CASE LBRAQ statement.signal.pattern.rule.list RBRAQ {
          $$ = boxCase(self.checkRulelist($[statement.signal.pattern.rule.list]));
        }

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
      INT { $$ = boxInt(std::stoi(self._lexer->YYText())); }
    | FLOAT { $$ = boxReal(atof(self._lexer->YYText())); }

  /******************** String ********************/
        
  primitive.string.quoted:
      STRING { $$ = tree(self._lexer->YYText()); }

  primitive.string.unquoted:
      STRING { $$ = self.unquote(self._lexer->YYText()); }

  primitive.string.tag:
      STRING { $$ = tree(self._lexer->YYText()); }
    | TAGSTRING { $$ = tree(self._lexer->YYText()); }

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

    primitive.type.number:
        primitive.type.number.int
      | primitive.type.number.float

      primitive.type.number.int:
          INTCAST { $$ = boxPrim1(sigIntCast); }

      primitive.type.number.float:
          FLOATCAST { $$ = boxPrim1(sigFloatCast); }

    primitive.type.any:
        ANYCAST { $$ = tree(2); }

    /*------------------- type.number.list -------------------*/

    primitive.type.number.list:
        primitive.type.number.list.start
      | primitive.type.number.list.append

      primitive.type.number.list.member:
          primitive.number {
            global::config().gWaveForm.push_back($[primitive.number]);
          }
        | expression.math.scalar {
            global::config().gWaveForm.push_back($[expression.math.scalar]);
          }

      primitive.type.number.list.start:
        primitive.type.number.list.member
        
      primitive.type.number.list.append:
          primitive.type.number.list COMMA primitive.type.number.list.member

    /******************** Route ********************/

    primitive.signal.route:
      primitive.signal.route.implied.outputs
    | primitive.signal.route.implied.connections
    | primitive.signal.route.explicit

      primitive.signal.route.implied.outputs:
          ROUTE LPAR expression.composition.serial[connections] RPAR {
            $$ = boxRoute($connections, $connections, boxPar(boxInt(0),boxInt(0)));
          }

      primitive.signal.route.implied.connections:
          ROUTE LPAR expression.composition.serial[inputs] COMMA expression.composition.serial[outputs] RPAR {
            $$ = boxRoute($inputs, $outputs, boxPar(boxInt(0),boxInt(0)));
          }

      primitive.signal.route.explicit:
          ROUTE LPAR expression.composition.serial[inputs] COMMA expression.composition.serial[outputs] COMMA expression.composition.parallel RPAR {
            $$ = boxRoute(
              $inputs,
              $outputs,
              $[expression.composition.parallel]
            );
          }

    /******************** Source ********************/

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
          $$ = boxWaveform(global::config().gWaveForm);
          global::config().gWaveForm.clear();
          /* primitive.type.number.list pushes values onto global::config().gWaveForm */
        }

    /******************** Type ********************/

    primitive.type.list:
        primitive.type.list.start
      | primitive.type.list.append

      primitive.type.list.start:
          primitive.type { $$ = cons($[primitive.type],self._nil); }

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
        VSLIDER LPAR primitive.string.unquoted COMMA expression.composition.serial[arg1] COMMA expression.composition.serial[arg2] COMMA expression.composition.serial[arg3] COMMA expression.composition.serial[arg4] RPAR {
          $$ = boxVSlider($[primitive.string.unquoted],$arg1,$arg2,$arg3,$arg4);
        }

    primitive.ui.hslider:
        HSLIDER LPAR primitive.string.unquoted COMMA expression.composition.serial[arg1] COMMA expression.composition.serial[arg2] COMMA expression.composition.serial[arg3] COMMA expression.composition.serial[arg4] RPAR {
          $$ = boxHSlider($[primitive.string.unquoted],$arg1,$arg2,$arg3,$arg4);
        }

    primitive.ui.nentry:
        NENTRY LPAR primitive.string.unquoted COMMA expression.composition.serial[arg1] COMMA expression.composition.serial[arg2] COMMA expression.composition.serial[arg3] COMMA expression.composition.serial[arg4] RPAR {
          $$ = boxNumEntry($[primitive.string.unquoted],$arg1,$arg2,$arg3,$arg4);
        }

    primitive.ui.vgroup:
        VGROUP LPAR primitive.string.unquoted COMMA expression RPAR { $$ = boxVGroup($[primitive.string.unquoted], $expression); }

    primitive.ui.hgroup:
        HGROUP LPAR primitive.string.unquoted COMMA expression RPAR { $$ = boxHGroup($[primitive.string.unquoted], $expression); }

    primitive.ui.tgroup:
        TGROUP LPAR primitive.string.unquoted COMMA expression RPAR { $$ = boxTGroup($[primitive.string.unquoted], $expression); }

    primitive.ui.vbargraph:
        VBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition.serial[arg1] COMMA expression.composition.serial[arg2] RPAR {
          $$ = boxVBargraph($[primitive.string.unquoted],$arg1,$arg2);
        }

    primitive.ui.hbargraph:
        HBARGRAPH LPAR primitive.string.unquoted COMMA expression.composition.serial[arg1] COMMA expression.composition.serial[arg2] RPAR {
          $$ = boxHBargraph($[primitive.string.unquoted],$arg1,$arg2);
        }

    /******************** Foreign ********************/

    primitive.foreign.function:
        FFUNCTION LPAR primitive.foreign.function.signature COMMA primitive.string.tag COMMA primitive.string.unquoted RPAR {
          $$ = boxFFun(ffunction($[primitive.foreign.function.signature],$[primitive.string.tag],$[primitive.string.unquoted]));
        }

      primitive.foreign.function.signature:
          primitive.type.number statement.identifier.waveform[fun] LPAR primitive.type.list RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun,cons($fun,cons($fun,self._nil))), $[primitive.type.list]));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] LPAR primitive.type.list RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun2,self._nil))), $[primitive.type.list]));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] OR statement.identifier.waveform[fun3] LPAR primitive.type.list RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun3,self._nil))), $[primitive.type.list]));
          }
        | primitive.type.number statement.identifier.waveform[fun] LPAR RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun,cons($fun,cons($fun,self._nil))), self._nil));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] LPAR RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun2,self._nil))), self._nil));
          }
        | primitive.type.number statement.identifier.waveform[fun1] OR statement.identifier.waveform[fun2] OR statement.identifier.waveform[fun3] LPAR RPAR {
            $$ = cons($[primitive.type.number], cons(cons($fun1,cons($fun2,cons($fun3,self._nil))), self._nil));
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
    | statement.definition.assignment
    | statement.definition.error

    statement.definition.function.incomplete:
      statement.identifier.box LPAR expression.composition.parallel RPAR DEF expression {
        $$ = cons(
          $[statement.identifier.box],
          cons( $[expression.composition.parallel], $expression )
        );
        setDefProp($[statement.identifier.box], self._streamName.c_str(), self._lexer->lineno());
      }
      
    statement.definition.function:
        statement.definition.function.incomplete ENDDEF {
          $$ = $[statement.definition.function.incomplete];
        }
      | statement.definition.function.incomplete error ENDL {
          self._lexer->LexerError("Incomplete function definition.");
          $$ = $[statement.definition.function.incomplete];
          yyerrok;
        }

    statement.definition.assignment:
        statement.identifier.box DEF expression[body] ENDDEF {
          $$ = cons(
            $[statement.identifier.box],
            cons( self._nil, $body )
          );
          setDefProp(
            $[statement.identifier.box],
            self._streamName.c_str(),
            self._lexer->lineno()
          );
        }
    
    statement.definition.with:
      expression WITH LBRAQ statement.definition.list RBRAQ {
        $$ = boxWithLocalDef($expression,self.formatDefinitions($[statement.definition.list]));
      }

    statement.definition.error:
        error ENDDEF {
          $$ = self._nil;
          self._lexer->LexerError("Error in definition.");
        }

    /*------------------- statement.definition.list -------------------*/

    statement.definition.list:
        statement.definition.list.start
      | statement.definition.list.start.qualified
      | statement.definition.list.append
      | statement.definition.list.append.qualified

      statement.definition.list.start:
          statement.definition {
            $$ = cons( $[statement.definition.list.start], self._nil );
          }

      statement.definition.list.start.qualified:
          statement.math.precision.list statement.definition {
            if (self.acceptdefinition($[statement.math.precision.list]))
              $$ = cons( $[statement.definition], self._nil );
            else
              $$ = self._nil;
          }

      statement.definition.list.append:
          statement.definition.list statement.definition {
            $$ = cons ($[statement.definition],$[statement.definition.list]);
          }
          
      statement.definition.list.append.qualified:
          statement.definition.list statement.math.precision.list statement.definition {
            if (self.acceptdefinition($[statement.math.precision.list]))
              $$ = cons ($[statement.definition],$[statement.definition.list]);
            else
              $$ = $[statement.definition.list];
          }

  /******************** Declare ********************/

  statement.declare.metadata:
      DECLARE statement.identifier[key] primitive.string.quoted[value] ENDDEF {
        self.declareMetadata($key,$value);
        $$ = self._nil;
      }

  statement.declare.feature.metadata:
      DECLARE statement.identifier[feature] statement.identifier[key] primitive.string.quoted[value] ENDDEF {
        self.declareDefinitionMetadata( $feature, $key, $value );
        $$ = self._nil;
      }

  statement.declare.doc:
      BDOC doc[body] EDOC {
        declareDoc($body);
        $$ = self._nil;
      }

  /******************** Identifier ********************/

  statement.identifier:
      IDENT {
        $$ = tree(self._lexer->YYText());
        setUseProp($$, self._streamName.c_str(), self._lexer->lineno());
      }

  statement.identifier.box:
      IDENT {
        $$ = boxIdent(self._lexer->YYText());
        setUseProp($$, self._streamName.c_str(), self._lexer->lineno());
      }

  statement.identifier.waveform:
      IDENT { $$ = tree(self._lexer->YYText()); }

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
          $$ = cons($statement, self._nil);
        }

    statement.list.start.qualified:
        statement.math.precision.list statement {
          if (self.acceptdefinition($[statement.math.precision.list]))
            $$ = cons($statement, self._nil);
          else
            $$ = self._nil;
        }

    statement.list.append:
        statement.list statement {
          $$ = cons($statement,$[statement.list]);
        }
    
    statement.list.append.qualified:
        statement.list statement.math.precision.list statement {
          if (self.acceptdefinition($[statement.math.precision.list]))
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

      /*------------------- math.precision.list -------------------*/

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

  statement.signal.pattern.rule:
      LPAR expression.composition.parallel RPAR ARROW expression ENDDEF { $$ = cons($[expression.composition.parallel],$expression); }

  /*------------------- signal.pattern.rule.list -------------------*/

  statement.signal.pattern.rule.list:
      statement.signal.pattern.rule.list.start
    | statement.signal.pattern.rule.list.append

    statement.signal.pattern.rule.list.start:
        statement.signal.pattern.rule { $$ = cons($[statement.signal.pattern.rule],self._nil); }
    
    statement.signal.pattern.rule.list.append:
        statement.signal.pattern.rule.list[prior] statement.signal.pattern.rule[next] { $$ = cons($next,$prior); }

%%
