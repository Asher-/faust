 /* -*- Mode: C++; tab-width: 2; c-basic-offset: 4 -*- */

/* Parser for the Faust language */
%require "3.2"
%language "c++"
%define api.value.type variant

%define api.token.raw
%define api.token.constructor
%define api.token.prefix {FAUST_}

%define api.namespace {::Faust::Compiler::Parser}
%define api.parser.class {BisonImplementation}
%define api.location.type {::Faust::Compiler::Parser::Location::Implementation}

%define parse.assert /* runtime assertions to catch invalid uses */
%define parse.trace /* set yydebug = 1 to print trace to stderr */
%define parse.error custom /* simple, detailed, verbose, custom   */
%define parse.lac full /* look-ahead correction (5.8.3 LAC) */

%param {Implementation& self}

%header "bison/implementation.hh"   /* Generate faustparser.hh */

%locations /* Generate location.hh */
%verbose   /* Generate faustparser.output */

%initial-action
{
  self.location().streamName() = self.streamName();
};

%code requires { /* Faust requires */
  #include <string>
  #include "compiler/parser/type/tokens.hh"
  #include "compiler/parser/location/implementation.hh"
  namespace Faust { namespace Compiler { namespace Parser {
    struct Implementation;
    namespace Lexer { struct Implementation; }
  } } }
  using FloatType = float;
  using IntType = int;
}

%code { /* Faust code */
  #include "compiler/parser/implementation.hh"
}

%{ /* Faust */

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

%}

%start program

/* With local environment (lowest priority)*/
%left <std::string> WITH
%left <std::string> LETREC

/* Block Diagram Algebra */
%right <std::string> SPLIT
%right <std::string> MIX
%right <std::string> SEQ
%right <std::string> COMMA
%left <std::string> REC

/* Primitive boxes */

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

%token <IntType> INT
%token <FloatType> FLOAT

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

%token <std::string> FLOATMODE
%token <std::string> DOUBLEMODE
%token <std::string> QUADMODE
%token <std::string> FIXEDPOINTMODE

%token ENDOFINPUT 0

 /* Begin and End tags for documentations, equations and diagrams */
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
%type <bool> doc.attribute.list
%type <bool> doc.attribute.definition
%type <bool> doc.attribute.definition.dependencies
%type <bool> doc.attribute.definition.doc.tags
%type <bool> doc.attribute.definition.distributed
%type <bool> doc.attribute.value
%type <std::string> doc.text
%type <Tree> doc.equation
%type <Tree> doc.diagram
%type <std::string> doc.notice
%type <bool> doc.list
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
%type <Tree> expression.environment
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
%type <Tree> expression.math.scalar.as.tree
%type <Tree> expression.math.scalar.int.as.tree
%type <Tree> expression.math.scalar.float.as.tree
%type <FloatType> expression.math.scalar.float
%type <IntType> expression.math.scalar.int
%type <Tree> expression.math.signal
%type <Tree> expression.math.signal.algebra
%type <Tree> expression.math.signal.shift
%type <Tree> expression.math.signal.power

%type <Tree> expression.math.trigonometry.as.tree
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
%type <Tree> primitive.foreign.function.signature.names.1.args.0
%type <Tree> primitive.foreign.function.signature.names.1.args.list
%type <Tree> primitive.foreign.function.signature.names.2.args.0
%type <Tree> primitive.foreign.function.signature.names.2.args.list
%type <Tree> primitive.foreign.function.signature.names.3.args.0
%type <Tree> primitive.foreign.function.signature.names.3.args.list
%type <Tree> primitive.foreign.variable
%type <Tree> primitive.signal.input.wire
%type <Tree> primitive.signal.input.terminate
%type <Tree> primitive.signal.inputs
%type <Tree> primitive.type.number.as.tree
%type <IntType> primitive.type.number.int
%type <FloatType> primitive.type.number.float
%type <Tree> primitive.type.number.int.as.tree
%type <Tree> primitive.type.number.float.as.tree
%type <Tree> primitive.type.number.float.list.member.as.tree
%type <Tree> primitive.type.number.int.list.member.as.tree
%type <std::vector<Tree>> primitive.type.number.list.as.tree
%type <std::vector<Tree>> primitive.type.number.list.start.as.tree
%type <std::vector<Tree>> primitive.type.number.list.append.as.tree
%type <Tree> primitive.type.number.list.member.as.tree
%type <Tree> primitive.signal.outputs
%type <Tree> primitive.signal
%type <Tree> primitive.signal.route
%type <Tree> primitive.signal.route.implied.outputs
%type <Tree> primitive.signal.route.implied.connections
%type <Tree> primitive.signal.route.explicit
%type <Tree> primitive.signal.source
%type <Tree> primitive.signal.source.soundfile
%type <Tree> primitive.signal.source.table
%type <Tree> primitive.signal.source.waveform.as.tree
%type <std::string> primitive.string.quoted
%type <Tree> primitive.string.quoted.as.tree
%type <std::string> primitive.string.tag
%type <Tree> primitive.string.tag.as.tree
%type <std::string> primitive.string.unquoted
%type <Tree> primitive.string.unquoted.as.tree
%type <Tree> primitive.type
%type <Tree> primitive.type.list
%type <Tree> primitive.type.list.start
%type <Tree> primitive.type.list.append
%type <Tree> primitive.type.cast.number
%type <Tree> primitive.type.cast.number.float
%type <Tree> primitive.type.cast.number.int
%type <Tree> primitive.type.cast.any

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
%type <Tree> statement.box.identifier.as.tree
%type <Tree> statement.definition
%type <Tree> statement.definition.assignment
%type <std::string> statement.definition.assignment.operator
%type <std::string> statement.terminal
%type <Tree> statement.definition.function
%type <Tree> statement.definition.function.arg
%type <Tree> statement.definition.function.args
%type <Tree> statement.definition.function.args.start
%type <Tree> statement.definition.function.args.append
%type <Tree> statement.definition.function.declaration
%type <Tree> statement.definition.list
%type <Tree> statement.definition.list.start
%type <Tree> statement.definition.list.start.qualified
%type <Tree> statement.definition.list.append
%type <Tree> statement.definition.list.append.qualified
%type <Tree> statement.definition.with
%type <Tree> statement.declare.doc
%type <Tree> statement.declare.metadata
%type <Tree> statement.declare.feature.metadata
%type <Tree> statement.identifier.as.tree
%type <Tree> statement.foreign.function.identifier.as.tree
%type <Tree> statement.import
%type <Tree> statement.list
%type <Tree> statement.list.start
%type <Tree> statement.list.start.qualified
%type <Tree> statement.list.append
%type <Tree> statement.list.append.qualified
%type <IntType> statement.math.precision
%type <IntType> statement.math.precision.list
%type <IntType> statement.math.precision.list.start
%type <IntType> statement.math.precision.list.append
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
      $$->location() = @$;
			self.ast() = self.formatDefinitions($$);
		}
  | %empty {
    $$ = ::Faust::Primitive::Symbols::asTree().nil;
    $$->location() = @$;
  }

/*-----------------------------------------------------*
|  Everything else is in (mostly) alphabetical order.  |
*-----------------------------------------------------*/

/*********************************************/
/******************** Doc ********************/
/*********************************************/

doc:
		doc.text {
			$$ = ::docTxt($[doc.text].c_str());
		}
  | doc.equation {
      $$ = ::docEqn($[doc.equation]);
      $$->location() = @$;
    }
  | doc.diagram {
      $$ = ::docDgm($[doc.diagram]);
      $$->location() = @$;
    }
  | doc.notice {
      $$ = ::docNtc();
      $$->location() = @$;
    }
  | doc.list {
      $$ = ::docLst();
      $$->location() = @$;
    }
  | doc.metadata {
      $$ = ::docMtd($[doc.metadata]);
      $$->location() = @$;
    }
	| %empty {
      $$ = ::Faust::Primitive::Symbols::asTree().nil;
      $$->location() = @$;
    }

  doc.text:
      DOCCHAR {
        $$ = $DOCCHAR;
      }
    | doc.text[prior] DOCCHAR {
        $$ = $prior.append(self.lexer()->YYText());
      }

  doc.equation:
      BEQN expression EEQN {
        $$ = $expression;
        $$->location() = @$;
      }
    | BEQN error EEQN {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

  doc.diagram:
      BDGM expression EDGM {
        $$ = $expression;
        $$->location() = @$;
      }
    | BDGM error EDGM {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

  doc.notice:
      NOTICE {
        $$ = $NOTICE;
      }

  doc.metadata:
      BMETADATA statement.identifier.as.tree EMETADATA {
        $$ = $[statement.identifier.as.tree];
        $$->location() = @$;
      }
    | BMETADATA error EMETADATA {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

  /*------------------- doc.list -------------------*/

  doc.list:
      BLST doc.attribute.list ELST {
        $$ = $[doc.attribute.list];
      }
   |  BLST /* Empty list */ ELST {
        $$ = ::Faust::Primitive::Symbols::asTree().nil;
      }
    | BLST error ELST {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

    doc.attribute.list:
        doc.attribute.definition {
          $$ = $[doc.attribute.definition];
        }
      | doc.attribute.list doc.attribute.definition {
          $$ = $[doc.attribute.definition];
        }

    doc.attribute.definition.dependencies:
        LSTDEPENDENCIES LSTEQ LSTQ doc.attribute.value LSTQ {
          $$ = $[doc.attribute.value];
          self.lstDependenciesSwitch() = $[doc.attribute.value];
        }
      | LSTDEPENDENCIES LSTEQ LSTQ error LSTQ {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
      
    doc.attribute.definition.doc.tags:
        LSTMDOCTAGS LSTEQ LSTQ doc.attribute.value LSTQ {
          $$ = $[doc.attribute.value];
          self.stripDocSwitch() = $[doc.attribute.value];
          self.stripDocSwitch() ? self.stripDocSwitch()=false
                                   : self.stripDocSwitch()=true;
        }
      | LSTMDOCTAGS LSTEQ LSTQ error LSTQ {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
      
    doc.attribute.definition.distributed:
        LSTDISTRIBUTED LSTEQ LSTQ doc.attribute.value LSTQ {
          $$ = $[doc.attribute.value];
          self.lstDistributedSwitch() = $[doc.attribute.value];
        }
      | LSTDISTRIBUTED LSTEQ LSTQ error LSTQ {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

    doc.attribute.definition:
        doc.attribute.definition.dependencies
      | doc.attribute.definition.doc.tags
      | doc.attribute.definition.distributed

    doc.attribute.value:
        LSTTRUE {
          $$ = true;
        }
      | LSTFALSE {
          $$ = false;
        }

/****************************************************/
/******************** Expression ********************/
/****************************************************/

expression:
		statement.definition.with
  | expression.letrec
  | expression.composition

  /******************** Component ********************/
  
  expression.component:
      COMPONENT LPAR primitive.string.unquoted.as.tree RPAR {
        $$ = ::boxComponent($[primitive.string.unquoted.as.tree]);
        $$->location() = @$;
      }
    | COMPONENT LPAR error RPAR {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

  /******************** Composition ********************/

  expression.composition:
    expression.composition.serial
  | expression.composition.parallel
  
  expression.composition.parallel:
      expression[lhs] COMMA expression[rhs] {
        $$ = ::boxPar( $lhs, $rhs );
        $$->location() = @$;
      }
                
  expression.composition.serial:
      expression.composition.sequence
    | expression.composition.split
    | expression.composition.mix
    | expression.composition.recursive
    | expression.infix

    expression.composition.mix:
        expression.composition.serial[lhs] MIX expression.composition.serial[rhs] {
          $$ = ::boxMerge( $lhs, $rhs );
          $$->location() = @$;
        }
          
    expression.composition.recursive:
        expression.composition.serial[lhs] REC expression.composition.serial[rhs] {
          $$ = ::boxRec($lhs,$rhs);
          $$->location() = @$;
        }
      
    expression.composition.sequence:
        expression.composition.serial[lhs] SEQ expression.composition.serial[rhs] {
          $$ = ::boxSeq($lhs,$rhs);
          $$->location() = @$;
        }

    expression.composition.split:
        expression.composition.serial[lhs] SPLIT expression.composition.serial[rhs] {
          $$ = ::boxSplit($lhs,$rhs);
          $$->location() = @$;
        }

  /******************** Environment ********************/

  expression.environment:
      ENVIRONMENT LBRAQ statement.list RBRAQ {
        $$ = ::boxWithLocalDef(boxEnvironment(),self.formatDefinitions($[statement.list]));
        $$->location() = @$;
      }
    | ENVIRONMENT LBRAQ error RBRAQ {
      yyclearin;
      yyerrok;
      ++self.errorCount();
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
    | statement.box.identifier.as.tree
    | primitive

  expression.infix.definitions.substitution:
      expression.infix[lhs] LCROC statement.definition.list[defs] RCROC {
        $$ = boxModifLocalDef(
          $lhs,
          self.formatDefinitions($defs)
        );
        $$->location() = @$;
      }
    | expression.infix[lhs] LCROC error RCROC {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
      
  expression.infix.environment.access:
      expression.infix[lhs] DOT statement.box.identifier.as.tree[rhs] {
        $$ = ::boxAccess($lhs,$rhs);      
        $$->location() = @$;
      }

  expression.infix.math:
      expression.infix.math.algebra
    | expression.infix.math.comparison
    | expression.infix.math.logic
    | expression.infix.math.shift

  expression.infix.math.algebra:
      expression.infix[lhs] ADD expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigAdd));
        $$->location() = @$;
      }
    | expression.infix[lhs] SUB expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigSub));
        $$->location() = @$;
      }
    | expression.infix[lhs] MUL expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigMul));
        $$->location() = @$;
      }
    | expression.infix[lhs] DIV expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigDiv));
        $$->location() = @$;
      }
    | expression.infix[lhs] MOD expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigRem));
        $$->location() = @$;
      }
    | expression.infix[lhs] POWOP expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxMathPrimitive( "pow" ));
        $$->location() = @$;
      }

  expression.infix.math.comparison:
      expression.infix[lhs] LT expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigLT));
        $$->location() = @$;
      }
    | expression.infix[lhs] LE expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigLE));
        $$->location() = @$;
      }
    | expression.infix[lhs] GT expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigGT));
        $$->location() = @$;
      }
    | expression.infix[lhs] GE expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigGE));
        $$->location() = @$;
      }
    | expression.infix[lhs] EQ expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigEQ));
        $$->location() = @$;
      }
    | expression.infix[lhs] NE expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigNE));
        $$->location() = @$;
      }

  expression.infix.math.logic:
      expression.infix[lhs] AND expression.infix[rhs] {
        $$ = ::boxSeq(boxPar($lhs,$rhs),::boxPrim2(sigAND));
        $$->location() = @$;
      }
    | expression.infix[lhs] OR  expression.infix[rhs] {
        $$ = ::boxSeq(boxPar($lhs,$rhs),::boxPrim2(sigOR));
        $$->location() = @$;
      }
    | expression.infix[lhs] XOR expression.infix[rhs] {
        $$ = ::boxSeq(boxPar($lhs,$rhs),::boxPrim2(sigXOR));
        $$->location() = @$;
      }

  expression.infix.math.shift:
      expression.infix[lhs] LSH expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigLeftShift));
        $$->location() = @$;
      }
    | expression.infix[lhs] RSH expression.infix[rhs] {
        $$ = ::boxSeq(::boxPar($lhs,$rhs),::boxPrim2(sigARightShift));
        $$->location() = @$;
      }

  expression.infix.prefix:
      expression.infix[lhs] LPAR statement.definition.function.args RPAR {
        $$ = ::buildBoxAppl($lhs,$[statement.definition.function.args]);
        $$->location() = @$;
      }
    | expression.infix[lhs] LPAR error RPAR {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
  
  expression.infix.signal.delay:
      expression.infix[lhs] FDELAY expression.infix[rhs] {
        $$ = ::boxSeq(boxPar($lhs,$rhs),::boxPrim2(sigDelay));
        $$->location() = @$;
      }
    | expression.infix[lhs] DELAY1 {
        $$ = ::boxSeq($lhs,::boxPrim1(sigDelay1));
        $$->location() = @$;
    }

  /******************** Iteration ********************/

  expression.iterate.parallel:
      ITERATE_PARALLEL LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR {
        $$ = ::boxIPar(
          $[statement.box.identifier.as.tree],
          $[expression.composition.serial],
          $expression
        );
        $$->location() = @$;
      }
    | ITERATE_PARALLEL LPAR error RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  expression.iterate.sequence:
      ISEQ LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR {
        $$ = ::boxISeq(
          $[statement.box.identifier.as.tree],
          $[expression.composition.serial],
          $expression
        );
        $$->location() = @$;
      }
    | ISEQ LPAR error RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  expression.iterate.sum:
      ISUM LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR {
        $$ = ::boxISum(
          $[statement.box.identifier.as.tree],
          $[expression.composition.serial],
          $expression
        );
        $$->location() = @$;
      }
    | ISUM LPAR error RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  expression.iterate.product:
      IPROD LPAR statement.box.identifier.as.tree COMMA expression.composition.serial COMMA expression RPAR {
        $$ = boxIProd(
          $[statement.box.identifier.as.tree],
          $[expression.composition.serial],
          $expression
        );
        $$->location() = @$;
      }
    | IPROD LPAR error RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  /******************** Lambda ********************/

  expression.lambda:
      LAMBDA LPAR expression.lambda.params RPAR DOT LPAR expression RPAR {
        $$ = ::buildBoxAbstr(
          $[expression.lambda.params],
          $expression
        );
        $$->location() = @$;
      }
    | LAMBDA LPAR error RPAR DOT LPAR expression RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | LAMBDA LPAR expression.lambda.params RPAR DOT LPAR error RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
  
  expression.lambda.params:
		expression.lambda.params.start
  | expression.lambda.params.append

    expression.lambda.params.start:
        statement.box.identifier.as.tree {
          $$ = ::cons(
            $[statement.box.identifier.as.tree],
            ::Faust::Primitive::Symbols::asTree().nil
          );
          $$->location() = @$;
        }

    expression.lambda.params.append:
        expression.lambda.params COMMA statement.box.identifier.as.tree {
          $$ = ::cons(
            $[statement.box.identifier.as.tree],
            $[expression.lambda.params]
          );
          $$->location() = @$;
        }

  /******************** Letrec ********************/

  expression.letrec:
    expression[lhs] LETREC LBRAQ /* empty expression.letrec.list */ RBRAQ {
			$$ = boxWithRecDef(
        $lhs,
        self.formatDefinitions(::Faust::Primitive::Symbols::asTree().nil),
        ::Faust::Primitive::Symbols::asTree().nil
      );
      $$->location() = @$;
		}
  | expression[lhs] LETREC LBRAQ expression.letrec.list RBRAQ {
			$$ = boxWithRecDef(
        $lhs,
        self.formatDefinitions($[expression.letrec.list]),
        ::Faust::Primitive::Symbols::asTree().nil
      );
      $$->location() = @$;
		}
  | expression[lhs] LETREC LBRAQ expression.letrec.list WHERE statement.definition.list RBRAQ {
			$$ = boxWithRecDef(
        $lhs,
        self.formatDefinitions($[expression.letrec.list]),
        self.formatDefinitions($[expression.letrec.list])
      );
      $$->location() = @$;
		}
  | expression[lhs] LETREC LBRAQ error RBRAQ {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
  | expression[lhs] LETREC LBRAQ error WHERE statement.definition.list RBRAQ {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }
  | expression[lhs] LETREC LBRAQ expression.letrec.list WHERE error RBRAQ {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

  /*------------------- letrec.list -------------------*/

  expression.letrec.list:
      expression.letrec.list.start
    | expression.letrec.list.append

    expression.letrec.list.start:
        expression.letrec.equation[item] {
          $$ = ::cons(
            $item,
            ::Faust::Primitive::Symbols::asTree().nil
          );
          $$->location() = @$;
        }
        
    expression.letrec.list.append:
        expression.letrec.list expression.letrec.equation {
          $$ = cons (
            $[expression.letrec.equation],
            $[expression.letrec.list]
          );
          $$->location() = @$;
        }
        
  expression.letrec.equation:
      expression.letrec.equation.name DEF expression statement.terminal {
        $$ = ::cons(
          $[expression.letrec.equation.name],
          cons(
            ::Faust::Primitive::Symbols::asTree().nil,
            $expression
          )
        );
        $$->location() = @$;
      }
    | error DEF statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | expression.letrec.equation.name DEF error {
        $$ = $[expression.letrec.equation.name];
        yyclearin;
        yyerrok;
      }

    expression.letrec.equation.name:
        DELAY1 statement.box.identifier.as.tree {
          $$ = $[statement.box.identifier.as.tree];
          $$->location() = @$;
        }


  /******************** Library ********************/

  expression.library:
      LIBRARY LPAR primitive.string.unquoted.as.tree RPAR {
        $$ = ::boxLibrary( $[primitive.string.unquoted.as.tree] );
        $$->location() = @$;
      }
    | LIBRARY LPAR error RPAR {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  /******************** Math ********************/

  expression.math:
      expression.math.signal
    | expression.math.scalar.as.tree
    | expression.math.comparison
    | expression.math.trigonometry.as.tree
    | expression.math.rounding

    expression.math.comparison:
        LT {
          $$ = ::boxPrim2(sigLT);
          $$->location() = @$;
        }
      | LE {
          $$ = ::boxPrim2(sigLE);
          $$->location() = @$;
        }
      | GT {
          $$ = ::boxPrim2(sigGT);
          $$->location() = @$;
        }
      | GE {
          $$ = ::boxPrim2(sigGE);
          $$->location() = @$;
        }
      | EQ {
          $$ = ::boxPrim2(sigEQ);
          $$->location() = @$;
        }
      | NE {
          $$ = ::boxPrim2(sigNE);
          $$->location() = @$;
        }

      expression.math.rounding:
          ABS {
            $$ = ::boxMathPrimitive( "abs" );
            $$->location() = @$;
          }
        | MIN {
            $$ = ::boxMathPrimitive( "min" );
            $$->location() = @$;
          }
        | MAX {
            $$ = ::boxMathPrimitive( "max" );
            $$->location() = @$;
          }
        | FLOOR {
            $$ = ::boxMathPrimitive( "floor" );
            $$->location() = @$;
          }
        | CEIL {
            $$ = ::boxMathPrimitive( "ceil" );
            $$->location() = @$;
          }
        | ASSERTBOUNDS {
            $$ = ::boxPrim3(sigAssertBounds);
            $$->location() = @$;
          }
        | LOWEST {
            $$ = ::boxPrim1(sigLowest);
            $$->location() = @$;
          }
        | HIGHEST {
            $$ = ::boxPrim1(sigHighest);
            $$->location() = @$;
          }
        | RINT {
            $$ = ::boxMathPrimitive( "rint" );
            $$->location() = @$;
          }

    expression.math.signal:
        expression.math.signal.algebra
      | expression.math.signal.shift
      | expression.math.signal.power

      expression.math.signal.algebra:
          ADD {
            $$ = ::boxPrim2(sigAdd);
            $$->location() = @$;
          }
        | SUB {
            $$ = ::boxPrim2(sigSub);
            $$->location() = @$;
          }
        | MUL {
            $$ = ::boxPrim2(sigMul);
            $$->location() = @$;
          }
        | DIV {
            $$ = ::boxPrim2(sigDiv);
            $$->location() = @$;
          }
        | MOD {
            $$ = ::boxPrim2(sigRem);
            $$->location() = @$;
          }
        | FMOD {
            $$ = ::boxMathPrimitive( "fmod" );
            $$->location() = @$;
          }
        | REMAINDER {
            $$ = ::boxMathPrimitive( "remainder" );
            $$->location() = @$;
          }
        | SUB statement.box.identifier.as.tree {
            $$ = ::boxSeq(
              ::boxPar(
                ::boxInt(0),
                $[statement.box.identifier.as.tree]
              ),
              ::boxPrim2(sigSub)
            );
            $$->location() = @$;
        }

      expression.math.signal.shift:
          LSH {
            $$ = ::boxPrim2(sigLeftShift);
            $$->location() = @$;
          }
        | RSH {
            $$ = ::boxPrim2(sigARightShift);
            $$->location() = @$;
          }

      expression.math.signal.power:
          EXP {
            $$ = ::boxMathPrimitive( "exp" );
            $$->location() = @$;
          }
        | LOG {
            $$ = ::boxMathPrimitive( "log" );
            $$->location() = @$;
          }
        | LOG10 {
            $$ = ::boxMathPrimitive( "log10" );
            $$->location() = @$;
          }
        | POWOP {
            $$ = ::boxMathPrimitive( "pow" );
            $$->location() = @$;
          }
        | POWFUN {
            $$ = ::boxMathPrimitive( "pow" );
            $$->location() = @$;
          }
        | SQRT {
            $$ = ::boxMathPrimitive( "sqrt" );
            $$->location() = @$;
          }

      expression.math.scalar.as.tree:
        expression.math.scalar.int.as.tree
      | expression.math.scalar.float.as.tree

        expression.math.scalar.int:
          ADD INT {
            $$ = std::stoi(self.lexer()->YYText());
          }
        | SUB INT {
            $$ = -$INT;
          }

        expression.math.scalar.int.as.tree:
          expression.math.scalar.int {
            $$ = ::boxInt( $[expression.math.scalar.int] );
            $$->location() = @$;
          }

        expression.math.scalar.float:
          ADD FLOAT {
            $$ = $FLOAT;
          }
        | SUB FLOAT {
            $$ = -$FLOAT;
          }

        expression.math.scalar.float.as.tree:
          expression.math.scalar.float {
            $$ = ::boxReal( $[expression.math.scalar.float] );
            $$->location() = @$;
          }

      expression.math.trigonometry.as.tree:
          ACOS {
            $$ = ::boxMathPrimitive( "acos" );
          
          }
        | ASIN {
            $$ = ::boxMathPrimitive( "asin" );
        
          }
        | ATAN {
            $$ = ::boxMathPrimitive( "atan" );
        
          }
        | ATAN2 {
            $$ = ::boxMathPrimitive( "atan2" );
        
          }
        | COS {
            $$ = ::boxMathPrimitive( "cos" );
        
          }
        | SIN {
            $$ = ::boxMathPrimitive( "sin" );
        
          }
        | TAN {
            $$ = ::boxMathPrimitive( "tan" );
        
          }

  /******************** Parenthesis ********************/

  expression.parenthesis:
    LPAR expression RPAR {
      $$ = $expression;
      $$->location() = @$;
    }
  | LPAR error RPAR {
      yyclearin;
      yyerrok;
      ++self.errorCount();
    }

  /******************** Signal ********************/

  expression.signal:
      expression.signal.control
    | expression.signal.delay
    | expression.signal.logic
  
    expression.signal.control:
        ATTACH {
          $$ = ::boxPrim2(sigAttach);
          $$->location() = @$;
        }
      | ENABLE {
          $$ = ::boxPrim2(sigEnable);
          $$->location() = @$;
        }
      | CONTROL {
          $$ = ::boxPrim2(sigControl);
          $$->location() = @$;
        }

    expression.signal.delay:
        MEM {
          $$ = ::boxPrim1(sigDelay1);
          $$->location() = @$;
        }
      | PREFIX {
          $$ = ::boxPrim2(sigPrefix);
          $$->location() = @$;
        }
      | FDELAY {
          $$ = ::boxPrim2(sigDelay);
          $$->location() = @$;
        }

    expression.signal.logic:
        AND {
          $$ = ::boxPrim2(sigAND);
          $$->location() = @$;
        }
      | OR {
          $$ = ::boxPrim2(sigOR);
          $$->location() = @$;
        }
      | XOR {
          $$ = ::boxPrim2(sigXOR);
          $$->location() = @$;
        }
      | SELECT2 {
          $$ = ::boxPrim3(sigSelect2);
          $$->location() = @$;
        }
      | SELECT3 {
          $$ = ::boxPrim4(sigSelect3);
          $$->location() = @$;
        }
      | CASE LBRAQ statement.signal.pattern.rule.list RBRAQ {
          $$ = ::boxCase(self.checkRulelist($[statement.signal.pattern.rule.list]));
          $$->location() = @$;
        }
      | CASE LBRAQ error RBRAQ {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

/***************************************************/
/******************** Primitive ********************/
/***************************************************/

primitive:
    primitive.foreign
  | primitive.type.number.as.tree
  | primitive.type.cast.number
  | primitive.signal
  | primitive.ui
  
  /******************** Foreign ********************/

  primitive.foreign:
    primitive.foreign.constant
  | primitive.foreign.function
  | primitive.foreign.variable

  /******************** Number ********************/

  primitive.type.number.as.tree:
      primitive.type.number.int.as.tree
    | primitive.type.number.float.as.tree
    
    primitive.type.number.int:
      INT {
        $$ = std::stoi(self.lexer()->YYText());
      }

    primitive.type.number.float:
      FLOAT {
        $$ = std::atof(self.lexer()->YYText());
      }

    primitive.type.number.int.as.tree:
      primitive.type.number.int {
        $$ = boxInt( $[primitive.type.number.int] );
        $$->location() = @$;
      }

    primitive.type.number.float.as.tree:
      primitive.type.number.float {
        $$ = boxReal( $[primitive.type.number.float] );
        $$->location() = @$;
      }

  /******************** String ********************/
        
  primitive.string.quoted:
      STRING {
        $$ = self.lexer()->YYText();
      }

  primitive.string.quoted.as.tree:
      primitive.string.quoted {
        $$ = ::tree( $[primitive.string.quoted] );
        $$->location() = @$;
      }

  primitive.string.unquoted:
      STRING {
        $$ = self.unquote(self.lexer()->YYText());
      }

  primitive.string.unquoted.as.tree:
      primitive.string.unquoted {
        $$ = ::tree( $[primitive.string.unquoted] );
        $$->location() = @$;
      }

  primitive.string.tag:
      STRING {
        $$ = self.lexer()->YYText();
      }
    | TAGSTRING {
        $$ = self.lexer()->YYText();
      }

  primitive.string.tag.as.tree:
    primitive.string.tag {
      $$ = ::tree( $[primitive.string.tag] );
      $$->location() = @$;
    }

  /******************** Signal ********************/

  primitive.signal:
    primitive.signal.inputs
  | primitive.signal.input.wire
  | primitive.signal.input.terminate
  | primitive.signal.outputs
  | primitive.signal.route
  | primitive.signal.source
  
  primitive.signal.input.wire:
      WIRE {
        $$ = ::boxWire();
        $$->location() = @$;
      }

  primitive.signal.input.terminate:
      CUT {
        $$ = ::boxCut();
        $$->location() = @$;
      }

  primitive.type:
      primitive.type.cast.number
    | primitive.type.cast.any

    /******************** Numbers ********************/

    primitive.type.cast.number:
        primitive.type.cast.number.int
      | primitive.type.cast.number.float

      primitive.type.cast.number.int:
          INTCAST {
            $$ = ::boxPrim1(sigIntCast);
            $$->location() = @$;
          }

      primitive.type.cast.number.float:
          FLOATCAST {
            $$ = ::boxPrim1(sigFloatCast);
            $$->location() = @$;
          }

    primitive.type.cast.any:
        ANYCAST {
          $$ = ::tree(2);
          $$->location() = @$;
        }

    /*------------------- type.number.list.int -------------------*/

      primitive.type.number.int.list.member.as.tree:
          primitive.type.number.int.as.tree
        | expression.math.scalar.int.as.tree

    primitive.type.number.list.as.tree:
        primitive.type.number.list.start.as.tree
      | primitive.type.number.list.append.as.tree

      primitive.type.number.list.member.as.tree:
          primitive.type.number.int.list.member.as.tree
        | primitive.type.number.float.list.member.as.tree

      primitive.type.number.list.start.as.tree:
        primitive.type.number.list.member.as.tree {
          $$.push_back( $[primitive.type.number.list.member.as.tree] );
        }

      primitive.type.number.list.append.as.tree:
        primitive.type.number.list.as.tree COMMA primitive.type.number.list.member.as.tree {
          $$.push_back( $[primitive.type.number.list.member.as.tree] );
        }

    /*------------------- type.number.list.float -------------------*/

      primitive.type.number.float.list.member.as.tree:
          primitive.type.number.float.as.tree
        | expression.math.scalar.float.as.tree

    /******************** Route ********************/

    primitive.signal.route:
      primitive.signal.route.implied.outputs
    | primitive.signal.route.implied.connections
    | primitive.signal.route.explicit

      primitive.signal.route.implied.outputs:
          ROUTE LPAR statement.definition.function.arg[connections] RPAR {
            $$ = ::boxRoute(
              $connections,
              $connections,
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            $$->location() = @$;
          }

      primitive.signal.route.implied.connections:
          ROUTE LPAR statement.definition.function.arg[inputs] COMMA statement.definition.function.arg[outputs] RPAR {
            $$ = ::boxRoute(
              $inputs,
              $outputs,
              ::boxPar( ::boxInt(0), ::boxInt(0) )
            );
            $$->location() = @$;
          }

      primitive.signal.route.explicit:
          ROUTE LPAR statement.definition.function.arg[inputs] COMMA statement.definition.function.arg[outputs] COMMA expression RPAR {
            $$ = boxRoute(
              $inputs,
              $outputs,
              $[expression]
            );
            $$->location() = @$;
          }

    /******************** Source ********************/

    primitive.signal.source:
        primitive.signal.source.waveform.as.tree
      | primitive.signal.source.soundfile
      | primitive.signal.source.table

      primitive.signal.source.table:
          RDTBL {
            $$ = ::boxPrim3(sigReadOnlyTable);
            $$->location() = @$;
          }
        | RWTBL {
            $$ = ::boxPrim5(sigWriteReadTable);
            $$->location() = @$;
          }

      primitive.signal.source.soundfile:
          SOUNDFILE LPAR primitive.string.unquoted.as.tree COMMA expression.composition RPAR {
            $$ = ::boxSoundfile( $[primitive.string.unquoted.as.tree], $[expression.composition] );
            $$->location() = @$;
          }
        
      primitive.signal.source.waveform.as.tree:
        WAVEFORM LBRAQ primitive.type.number.list.as.tree RBRAQ {
          $$ = ::boxWaveform( $[primitive.type.number.list.as.tree] );
          $$->location() = @$;
        }

    /******************** Type ********************/

    primitive.type.list:
        primitive.type.list.start
      | primitive.type.list.append

      primitive.type.list.start:
          primitive.type {
            $$ = ::cons($[primitive.type],::Faust::Primitive::Symbols::asTree().nil);
            $$->location() = @$;
          }

      primitive.type.list.append:
          primitive.type.list COMMA primitive.type {
            $$ = ::cons(
              $[primitive.type],
              $[primitive.type.list]
            );
            $$->location() = @$;
          }


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
        BUTTON LPAR primitive.string.unquoted.as.tree RPAR {
          $$ = ::boxButton($[primitive.string.unquoted.as.tree]);
          $$->location() = @$;
        }
      | BUTTON LPAR error RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.checkbox:
        CHECKBOX LPAR primitive.string.unquoted.as.tree RPAR {
          $$ = ::boxCheckbox($[primitive.string.unquoted.as.tree]);
          $$->location() = @$;
        }
      | CHECKBOX LPAR error RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.vslider:
        VSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          $$ = ::boxVSlider(
            $[primitive.string.unquoted.as.tree],
            $arg1,
            $arg2,
            $arg3,
            $arg4
          );
          $$->location() = @$;
        }
      | VSLIDER LPAR error                               COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     error                               COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     error                               COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     error                               COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     error
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.hslider:
        HSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          $$ = ::boxHSlider(
            $[primitive.string.unquoted.as.tree],
            $arg1,
            $arg2,
            $arg3,
            $arg4
          );
          $$->location() = @$;
        }
      | HSLIDER LPAR error                               COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     error                               COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     error                               COMMA
                     expression.composition.serial[arg3] COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     error                               COMMA
                     expression.composition.serial[arg4]
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HSLIDER LPAR primitive.string.unquoted.as.tree   COMMA
                     expression.composition.serial[arg1] COMMA
                     expression.composition.serial[arg2] COMMA
                     expression.composition.serial[arg3] COMMA
                     error
                RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.nentry:
        NENTRY LPAR primitive.string.unquoted.as.tree   COMMA
                    expression.composition.serial[arg1] COMMA
                    expression.composition.serial[arg2] COMMA
                    expression.composition.serial[arg3] COMMA
                    expression.composition.serial[arg4]
               RPAR {
          $$ = ::boxNumEntry($[primitive.string.unquoted.as.tree],$arg1,$arg2,$arg3,$arg4);
          $$->location() = @$;
        }
      | NENTRY LPAR error                               COMMA
                    expression.composition.serial[arg1] COMMA
                    expression.composition.serial[arg2] COMMA
                    expression.composition.serial[arg3] COMMA
                    expression.composition.serial[arg4]
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | NENTRY LPAR primitive.string.unquoted.as.tree   COMMA
                    error                               COMMA
                    expression.composition.serial[arg2] COMMA
                    expression.composition.serial[arg3] COMMA
                    expression.composition.serial[arg4]
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | NENTRY LPAR primitive.string.unquoted.as.tree   COMMA
                    expression.composition.serial[arg1] COMMA
                    error                               COMMA
                    expression.composition.serial[arg3] COMMA
                    expression.composition.serial[arg4]
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | NENTRY LPAR primitive.string.unquoted.as.tree   COMMA
                    expression.composition.serial[arg1] COMMA
                    expression.composition.serial[arg2] COMMA
                    error                               COMMA
                    expression.composition.serial[arg4]
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | NENTRY LPAR primitive.string.unquoted.as.tree   COMMA
                    expression.composition.serial[arg1] COMMA
                    expression.composition.serial[arg2] COMMA
                    expression.composition.serial[arg3] COMMA
                    error
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.vgroup:
        VGROUP LPAR primitive.string.unquoted.as.tree COMMA
                    expression
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VGROUP LPAR error COMMA
                    expression
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VGROUP LPAR primitive.string.unquoted.as.tree COMMA
                    error
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.hgroup:
        HGROUP LPAR primitive.string.unquoted.as.tree COMMA
                    expression
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HGROUP LPAR error COMMA
                    expression
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HGROUP LPAR primitive.string.unquoted.as.tree COMMA
                    error
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.tgroup:
        TGROUP LPAR primitive.string.unquoted.as.tree COMMA
                    expression
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | TGROUP LPAR error COMMA
                    expression
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | TGROUP LPAR primitive.string.unquoted.as.tree COMMA
                    error
               RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.vbargraph:
        VBARGRAPH LPAR primitive.string.unquoted.as.tree   COMMA
                       expression.composition.serial[arg1] COMMA
                       expression.composition.serial[arg2]
                  RPAR {
          $$ = ::boxVBargraph(
            $[primitive.string.unquoted.as.tree],
            $arg1,
            $arg2
          );
          $$->location() = @$;
        }
      | VBARGRAPH LPAR error                               COMMA
                       expression.composition.serial[arg1] COMMA
                       expression.composition.serial[arg2]
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VBARGRAPH LPAR primitive.string.unquoted.as.tree   COMMA
                       error                               COMMA
                       expression.composition.serial[arg2]
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | VBARGRAPH LPAR primitive.string.unquoted.as.tree   COMMA
                       expression.composition.serial[arg1] COMMA
                       error
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.ui.hbargraph:
        HBARGRAPH LPAR primitive.string.unquoted.as.tree   COMMA
                       expression.composition.serial[arg1] COMMA
                       expression.composition.serial[arg2]
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HBARGRAPH LPAR error                               COMMA
                       expression.composition.serial[arg1] COMMA
                       expression.composition.serial[arg2]
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HBARGRAPH LPAR primitive.string.unquoted.as.tree   COMMA
                       error                               COMMA
                       expression.composition.serial[arg2]
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | HBARGRAPH LPAR primitive.string.unquoted.as.tree   COMMA
                       expression.composition.serial[arg1] COMMA
                       error
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    /******************** Foreign ********************/

    primitive.foreign.function:
        FFUNCTION LPAR primitive.foreign.function.signature COMMA
                       primitive.string.tag.as.tree         COMMA
                       primitive.string.unquoted.as.tree
                  RPAR {
          $$ = ::boxFFun(
            ::ffunction(
              $[primitive.foreign.function.signature],
              $[primitive.string.tag.as.tree],
              $[primitive.string.unquoted.as.tree]
            )
          );
          $$->location() = @$;
        }
      | FFUNCTION LPAR error                        COMMA
                       primitive.string.tag.as.tree COMMA
                       primitive.string.unquoted.as.tree
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | FFUNCTION LPAR primitive.foreign.function.signature COMMA
                       error                                COMMA
                       primitive.string.unquoted.as.tree
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | FFUNCTION LPAR primitive.foreign.function.signature COMMA
                       primitive.string.tag.as.tree         COMMA
                       error
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

      primitive.foreign.function.signature.names.1.args.0:
          primitive.type.cast.number statement.foreign.function.identifier.as.tree[name] LPAR RPAR {
            $$ = ::cons(
              $[primitive.type.cast.number],
              ::cons(
                ::cons(
                  $name,
                  ::cons(
                    $name,
                    ::cons( $name, ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                ::Faust::Primitive::Symbols::asTree().nil
              )
            );
            $$->location() = @$;
          }
        | error statement.foreign.function.identifier.as.tree[name] LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number error LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }

      primitive.foreign.function.signature.names.1.args.list:
          primitive.type.cast.number statement.foreign.function.identifier.as.tree[name] LPAR primitive.type.list RPAR {
            $$ = ::cons(
              $[primitive.type.cast.number],
              ::cons(
                ::cons(
                  $name,
                  ::cons( $name, ::cons( $name, ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                $[primitive.type.list]
              )
            );
            $$->location() = @$;
          }
        | error statement.foreign.function.identifier.as.tree[name] LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number error LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name] LPAR error RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
          
      primitive.foreign.function.signature.names.2.args.0:
          primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                     LPAR RPAR {
            $$ = ::cons(
              $[primitive.type.cast.number],
              ::cons(
                ::cons(
                  $name1,
                  ::cons(
                    $name2,
                    ::cons( $name2, ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                ::Faust::Primitive::Symbols::asTree().nil
              )
            );
            $$->location() = @$;
          }
        | error statement.foreign.function.identifier.as.tree[name1]
             OR statement.foreign.function.identifier.as.tree[name2]
                LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number error
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                     LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR error
                                     LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
          
      primitive.foreign.function.signature.names.2.args.list:
          primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                     LPAR primitive.type.list RPAR {
            $$ = ::cons(
              $[primitive.type.cast.number],
              ::cons(
                ::cons(
                  $name1,
                  ::cons(
                    $name2,
                    ::cons( $name2, ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                $[primitive.type.list]
              )
            );
            $$->location() = @$;
          }
        | error statement.foreign.function.identifier.as.tree[name1]
             OR statement.foreign.function.identifier.as.tree[name2]
                LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number error
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                     LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR error
                                     LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                     LPAR error RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
      
      primitive.foreign.function.signature.names.3.args.0:
          primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR RPAR {
            $$ = ::cons(
              $[primitive.type.cast.number],
              ::cons(
                ::cons(
                  $name1,
                  ::cons(
                    $name2,
                    ::cons( $name3, ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                ::Faust::Primitive::Symbols::asTree().nil
              )
            );
            $$->location() = @$;
          }
        | error statement.foreign.function.identifier.as.tree[name1]
             OR statement.foreign.function.identifier.as.tree[name2]
             OR statement.foreign.function.identifier.as.tree[name3]
                LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number error
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR error
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR error
                                     LPAR RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }

      primitive.foreign.function.signature.names.3.args.list:
          primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR primitive.type.list RPAR {
            $$ = ::cons(
              $[primitive.type.cast.number],
              ::cons(
                ::cons(
                  $name1,
                  ::cons(
                    $name2,
                    ::cons( $name3, ::Faust::Primitive::Symbols::asTree().nil )
                  )
                ),
                $[primitive.type.list]
              )
            );
            $$->location() = @$;
          }
        | error statement.foreign.function.identifier.as.tree[name1]
             OR statement.foreign.function.identifier.as.tree[name2]
             OR statement.foreign.function.identifier.as.tree[name3]
                LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number error
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR error
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR error
                                     LPAR primitive.type.list RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
        | primitive.type.cast.number statement.foreign.function.identifier.as.tree[name1]
                                  OR statement.foreign.function.identifier.as.tree[name2]
                                  OR statement.foreign.function.identifier.as.tree[name3]
                                     LPAR error RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
      
      primitive.foreign.function.signature:
          primitive.foreign.function.signature.names.1.args.0
        | primitive.foreign.function.signature.names.1.args.list
        | primitive.foreign.function.signature.names.2.args.0
        | primitive.foreign.function.signature.names.2.args.list
        | primitive.foreign.function.signature.names.3.args.0
        | primitive.foreign.function.signature.names.3.args.list

    primitive.foreign.constant:
        FCONSTANT LPAR primitive.type.cast.number statement.identifier.as.tree COMMA
                       primitive.string.tag.as.tree
                  RPAR {
          $$ = ::boxFConst(
            $[primitive.type.cast.number],
            $[statement.identifier.as.tree],
            $[primitive.string.tag.as.tree]
          );
          $$->location() = @$;
        }
      | FCONSTANT LPAR error statement.identifier.as.tree COMMA
                       primitive.string.tag.as.tree
                  RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
      | FCONSTANT LPAR primitive.type.cast.number error COMMA
                       primitive.string.tag.as.tree
                  RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }
      | FCONSTANT LPAR primitive.type.cast.number statement.identifier.as.tree COMMA
                       error
                  RPAR {
            yyclearin;
            yyerrok;
            ++self.errorCount();
          }

    primitive.foreign.variable:
        FVARIABLE LPAR primitive.type.cast.number statement.identifier.as.tree COMMA
                       primitive.string.tag.as.tree
                  RPAR {
          $$ = ::boxFVar(
            $[primitive.type.cast.number],
            $[statement.identifier.as.tree],
            $[primitive.string.tag.as.tree]
          );
          $$->location() = @$;
        }
      | FVARIABLE LPAR error statement.identifier.as.tree COMMA
                       primitive.string.tag.as.tree
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | FVARIABLE LPAR primitive.type.cast.number error COMMA
                       primitive.string.tag.as.tree
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | FVARIABLE LPAR primitive.type.cast.number statement.identifier.as.tree COMMA
                       error
                  RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    /******************** I/O ********************/

    primitive.signal.inputs:
        INPUTS LPAR expression RPAR {
          $$ = ::boxInputs($expression);
          $$->location() = @$;
        }
      | INPUTS LPAR error RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    primitive.signal.outputs:
        OUTPUTS LPAR expression RPAR {
          $$ = ::boxOutputs($expression);
          $$->location() = @$;
        }
      | OUTPUTS LPAR error RPAR {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

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

    statement.definition.function.arg:
      expression.composition.serial

    statement.definition.function.args:
      statement.definition.function.args.start
    | statement.definition.function.args.append

    statement.definition.function.args.start:
      statement.definition.function.arg {
        $$ = ::cons(
          $[statement.definition.function.arg],
          ::Faust::Primitive::Symbols::asTree().nil
        );
       $$->location() = @$;
     }
      
    statement.definition.function.args.append:
      statement.definition.function.args COMMA statement.definition.function.arg {
        $$ = ::cons(
          $[statement.definition.function.arg],
          $[statement.definition.function.args]
        );
        $$->location() = @$;
      }

    statement.definition.function.declaration:
      statement.box.identifier.as.tree LPAR statement.definition.function.args RPAR DEF expression {
        $$ = cons(
          $[statement.box.identifier.as.tree],
          ::cons( $[statement.definition.function.args], $expression )
        );
        $$->location() = @$;
      }
    | error LPAR statement.definition.function.args RPAR DEF expression {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | statement.box.identifier.as.tree LPAR error RPAR DEF expression {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

    statement.definition.function:
        statement.definition.function.declaration statement.terminal {
          $$ = $[statement.definition.function.declaration];
          $$->location() = @$;
        }
      | error statement.terminal {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }

    statement.definition.assignment.operator:
        DEF

    statement.definition.assignment:
        statement.box.identifier.as.tree statement.definition.assignment.operator
          expression statement.terminal {
          $$ = cons(
            $[statement.box.identifier.as.tree],
            ::cons( ::Faust::Primitive::Symbols::asTree().nil, $expression )
          );
          $$->location() = @$;
        }
      | error statement.definition.assignment.operator
          expression statement.terminal {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | statement.box.identifier.as.tree error
          expression statement.terminal {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | statement.box.identifier.as.tree statement.definition.assignment.operator
          error statement.terminal {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
      | statement.box.identifier.as.tree statement.definition.assignment.operator
          expression error {
          yyclearin;
          yyerrok;
          ++self.errorCount();
        }
    
    statement.definition.with:
      expression WITH LBRAQ statement.definition.list RBRAQ {
        $$ = ::boxWithLocalDef(
          $expression,
          self.formatDefinitions($[statement.definition.list])
        );
        $$->location() = @$;
      }
    | error WITH LBRAQ statement.definition.list RBRAQ {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | expression WITH LBRAQ error RBRAQ {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

    /*------------------- statement.definition.list -------------------*/

    statement.definition.list:
        statement.definition.list.start
      | statement.definition.list.start.qualified
      | statement.definition.list.append
      | statement.definition.list.append.qualified

      statement.definition.list.start:
          statement.definition {
            $$ = ::cons(
              $[statement.definition],
              ::Faust::Primitive::Symbols::asTree().nil
            );
            $$->location() = @$;
          }

      statement.definition.list.start.qualified:
          statement.math.precision.list statement.definition {
            if (self.acceptdefinition($[statement.math.precision.list]))
              $$ = ::cons( $[statement.definition], ::Faust::Primitive::Symbols::asTree().nil );
            else
              $$ = ::Faust::Primitive::Symbols::asTree().nil;
            $$->location() = @$;
          }

      statement.definition.list.append:
          statement.definition.list statement.definition {
            $$ = ::cons($[statement.definition],$[statement.definition.list]);
            $$->location() = @$;
          }
          
      statement.definition.list.append.qualified:
          statement.definition.list statement.math.precision.list statement.definition {
            if (self.acceptdefinition($[statement.math.precision.list]))
              $$ = ::cons($[statement.definition],$[statement.definition.list]);
            else
              $$ = $[statement.definition.list];
            $$->location() = @$;
          }

  /******************** Declare ********************/

  statement.declare.metadata:
      DECLARE statement.identifier.as.tree[key]
              primitive.string.quoted.as.tree[value]
        statement.terminal {
        self.declareMetadata($key,$value);
        $$ = ::Faust::Primitive::Symbols::asTree().nil;
        $$->location() = @$;
      }
    | DECLARE error primitive.string.quoted.as.tree[value] statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | DECLARE statement.identifier.as.tree[key] error statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | DECLARE statement.identifier.as.tree[key] primitive.string.quoted.as.tree[value] error {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  statement.declare.feature.metadata:
      DECLARE statement.identifier.as.tree[feature]
              statement.identifier.as.tree[key]
              primitive.string.quoted.as.tree[value]
        statement.terminal {
        self.declareDefinitionMetadata( $feature, $key, $value );
        $$ = ::Faust::Primitive::Symbols::asTree().nil;
        $$->location() = @$;
      }
    | DECLARE error
              statement.identifier.as.tree[key]
              primitive.string.quoted.as.tree[value]
        statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | DECLARE statement.identifier.as.tree[feature]
              error
              primitive.string.quoted.as.tree[value]
        statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | DECLARE statement.identifier.as.tree[feature]
              statement.identifier.as.tree[key]
              error
        statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  statement.declare.doc:
      BDOC doc[body] EDOC {
        ::declareDoc($body);
        $$ = ::Faust::Primitive::Symbols::asTree().nil;
        $$->location() = @$;
      }
    | BDOC error EDOC {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  /******************** Identifier ********************/

  statement.identifier.as.tree:
      IDENT {
        $$ = ::tree(self.lexer()->YYText());
        $$->location() = @$;
      }

  statement.box.identifier.as.tree:
      IDENT {
        $$ = ::boxIdent(self.lexer()->YYText());
        $$->location() = @$;
      }

  statement.foreign.function.identifier.as.tree:
      IDENT {
        $$ = ::tree(self.lexer()->YYText());
        $$->location() = @$;
      }

  /******************** Import ********************/

  statement.import:
      IMPORT LPAR primitive.string.unquoted.as.tree[filename] RPAR statement.terminal {
        $$ = ::importFile($filename);
        $$->location() = @$;
      }
    | IMPORT LPAR error RPAR statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | IMPORT LPAR primitive.string.unquoted.as.tree[filename] RPAR error {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  /******************** List ********************/

  statement.list:
      statement.list.start
    | statement.list.start.qualified
    | statement.list.append
    | statement.list.append.qualified
   
    statement.list.start:
        statement {
          if ( $statement != ::Faust::Primitive::Symbols::asTree().nil ) {
            $$ = ::cons($statement, ::Faust::Primitive::Symbols::asTree().nil);
          }
          else {
            $$ = $$ = ::Faust::Primitive::Symbols::asTree().nil;
          }
          $$->location() = @$;
        }

    statement.list.start.qualified:
        statement.math.precision.list statement {
          if ( $statement != ::Faust::Primitive::Symbols::asTree().nil
            && self.acceptdefinition($[statement.math.precision.list]))
            $$ = ::cons($statement, ::Faust::Primitive::Symbols::asTree().nil);
          else
            $$ = ::Faust::Primitive::Symbols::asTree().nil;
          $$->location() = @$;
        }

    statement.list.append:
        statement.list statement {
          if ( $statement != ::Faust::Primitive::Symbols::asTree().nil ) {
            $$ = ::cons($statement,$[statement.list]);
          }
          else {
            $$ = $[statement.list];
          }
          $$->location() = @$;
        }
    
    statement.list.append.qualified:
        statement.list statement.math.precision.list statement {
          if ( $statement != ::Faust::Primitive::Symbols::asTree().nil
            && self.acceptdefinition($[statement.math.precision.list])) {
            $$ = ::cons($[statement.list],$[statement]);
          }
          else {
            $$=$[statement.list];
          }
          $$->location() = @$;
        }

  /******************** Math ********************/

    statement.math.precision:
        FLOATMODE {
          $$ = 1;
        }
      | DOUBLEMODE {
          $$ = 2;
        }
      | QUADMODE {
          $$ = 4;
        }
      | FIXEDPOINTMODE {
          $$ = 8;
        }

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
      LPAR statement.definition.function.args RPAR ARROW expression statement.terminal {
        $$ = ::cons($[statement.definition.function.args],$expression);
      }
    | LPAR error RPAR ARROW expression statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | LPAR statement.definition.function.args RPAR ARROW error statement.terminal {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }
    | LPAR statement.definition.function.args RPAR ARROW expression error {
        yyclearin;
        yyerrok;
        ++self.errorCount();
      }

  /*------------------- signal.pattern.rule.list -------------------*/

  statement.signal.pattern.rule.list:
      statement.signal.pattern.rule.list.start
    | statement.signal.pattern.rule.list.append

    statement.signal.pattern.rule.list.start:
        statement.signal.pattern.rule {
          $$ = ::cons(
            $[statement.signal.pattern.rule],
            ::Faust::Primitive::Symbols::asTree().nil
          );
          $$->location() = @$;
        }
    
    statement.signal.pattern.rule.list.append:
        statement.signal.pattern.rule.list statement.signal.pattern.rule {
          $$ = ::cons(
            $[statement.signal.pattern.rule],
            $[statement.signal.pattern.rule.list]
          );
          $$->location() = @$;
        }

  /******************** Terminal ********************/

  statement.terminal:
      ENDDEF
    | ENDL /* Currently this will never match because ENDL is never returned as a token. */
    | ENDOFINPUT { return 0; } /* ENDOFINPUT cannot have a type, so has to be converted here. */


%%
