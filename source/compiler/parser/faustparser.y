/* -*- Mode: C++; tab-width: 4; c-basic-offset: 4 -*- */

/* Parser for the Faust language */

%{

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

%}

%union {
	CTree* 	exp;
	char* str;
	string* cppstr;
	bool b;
	int numvariant;
}

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

%token MEM
%token PREFIX

%token INTCAST
%token FLOATCAST
%token ANYCAST
%token FFUNCTION
%token FCONSTANT
%token FVARIABLE

%token BUTTON
%token CHECKBOX
%token VSLIDER
%token HSLIDER
%token NENTRY
%token VGROUP
%token HGROUP
%token TGROUP

%token HBARGRAPH
%token VBARGRAPH
%token SOUNDFILE

%token ATTACH

%token ACOS
%token ASIN
%token ATAN
%token ATAN2
%token COS
%token SIN
%token TAN

%token EXP
%token LOG
%token LOG10
%token POWFUN
%token SQRT

%token ABS
%token MIN
%token MAX

%token FMOD
%token REMAINDER

%token FLOOR
%token CEIL
%token RINT

%token RDTBL
%token RWTBL

%token SELECT2
%token SELECT3

%token INT
%token FLOAT

%token LAMBDA
%token DOT

%token WIRE
%token CUT
%token ENDDEF
%token VIRG
%left LPAR
%token RPAR
%token LBRAQ
%token RBRAQ
%left LCROC
%token RCROC
%token WITH
%token LETREC
%token WHERE
%token DEF

%token IMPORT
%token COMPONENT
%token LIBRARY
%token ENVIRONMENT
%token WAVEFORM
%token ROUTE
%token ENABLE
%token CONTROL

%token ITERATE_PARALLEL
%token ISEQ
%token ISUM
%token IPROD

%token INPUTS
%token OUTPUTS

%token STRING
%token TAGSTRING
%token IDENT
%token EXTRA

%token DECLARE

%token CASE
%token ARROW

%token ASSERTBOUNDS
%token LOWEST
%token HIGHEST

%token FLOATMODE
%token DOUBLEMODE
%token QUADMODE
%token FIXEDPOINTMODE

 /* Begin and End tags for documentations, equations and diagrams */
%token BDOC
%token EDOC
%token BEQN
%token EEQN
%token BDGM
%token EDGM
%token BLST
%token ELST
%token BMETADATA
%token EMETADATA
%token <cppstr> DOCCHAR
%token NOTICE
%token LISTING

%token LSTTRUE
%token LSTFALSE
%token LSTDEPENDENCIES
%token LSTMDOCTAGS
%token LSTDISTRIBUTED
%token LSTEQ
%token LSTQ

%type <exp> doc
%type <exp> doc.attribute.list
%type <exp> doc.attribute.definition
%type <b> doc.attribute.value
%type <cppstr> doc.text
%type <exp> doc.equation
%type <exp> doc.diagram
%type <exp> doc.notice
%type <exp> doc.list
%type <exp> doc.metadata

%type <exp> expression
%type <exp> expression.component
%type <exp> expression.composition
%type <exp> expression.composition.mix
%type <exp> expression.composition.record
%type <exp> expression.composition.sequence
%type <exp> expression.composition.split
%type <exp> expression.composition.list
%type <exp> expression.environment
%type <exp> expression.infix
%type <exp> expression.infix.definitions.local
%type <exp> expression.infix.environment.access
%type <exp> expression.infix.math
%type <exp> expression.infix.math.algebra
%type <exp> expression.infix.math.comparison
%type <exp> expression.infix.math.logic
%type <exp> expression.infix.math.shift
%type <exp> expression.infix.prefix
%type <exp> expression.infix.signal.delay
%type <exp> expression.iterate.parallel
%type <exp> expression.iterate.sequence
%type <exp> expression.iterate.sum
%type <exp> expression.iterate.product
%type <exp> expression.lambda
%type <exp> expression.lambda.params
%type <exp> expression.lambda.params.start
%type <exp> expression.lambda.params.append
%type <exp> expression.letrec
%type <exp> expression.letrec.list
%type <exp> expression.letrec.list.start
%type <exp> expression.letrec.list.append
%type <exp> expression.letrec.equation
%type <exp> expression.letrec.equation.name
%type <exp> expression.library
%type <exp> expression.math
%type <exp> expression.math.comparison
%type <exp> expression.math.rounding
%type <exp> expression.math.scalar
%type <exp> expression.math.signal
%type <exp> expression.math.signal.algebra
%type <exp> expression.math.signal.shift
%type <exp> expression.math.signal.power
%type <exp> expression.math.trigonometry
%type <exp> expression.parallel
%type <exp> expression.parenthesis
%type <exp> expression.signal
%type <exp> expression.signal.control
%type <exp> expression.signal.delay
%type <exp> expression.signal.logic

%type <exp> primitive
%type <exp> primitive.foreign
%type <exp> primitive.foreign.constant
%type <exp> primitive.foreign.function
%type <exp> primitive.foreign.function.signature
%type <exp> primitive.foreign.variable
%type <exp> primitive.signal.input.implicit
%type <exp> primitive.signal.input.terminate
%type <exp> primitive.signal.inputs
%type <exp> primitive.number
%type <exp> primitive.type.number.list
%type <exp> primitive.type.number.list.start
%type <exp> primitive.type.number.list.append
%type <exp> primitive.type.number.list.member
%type <exp> primitive.signal.outputs
%type <exp> primitive.signal
%type <exp> primitive.signal.route
%type <exp> primitive.signal.source
%type <exp> primitive.signal.source.soundfile
%type <exp> primitive.signal.source.table
%type <exp> primitive.signal.source.waveform
%type <exp> primitive.string.quoted
%type <exp> primitive.string.tag
%type <exp> primitive.string.unquoted
%type <exp> primitive.type
%type <exp> primitive.type.list
%type <exp> primitive.type.list.start
%type <exp> primitive.type.list.append
%type <exp> primitive.type.number
%type <exp> primitive.type.number.int
%type <exp> primitive.type.number.float
%type <exp> primitive.type.any

%type <exp> primitive.ui
%type <exp> primitive.ui.button
%type <exp> primitive.ui.checkbox
%type <exp> primitive.ui.vslider
%type <exp> primitive.ui.hslider
%type <exp> primitive.ui.nentry
%type <exp> primitive.ui.vgroup
%type <exp> primitive.ui.hgroup
%type <exp> primitive.ui.tgroup
%type <exp> primitive.ui.vbargraph
%type <exp> primitive.ui.hbargraph

%type <exp> program

%type <exp> statement
%type <exp> statement.definition
%type <exp> statement.definition.substitution
%type <exp> statement.definition.error
%type <exp> statement.definition.function
%type <exp> statement.definition.list
%type <exp> statement.definition.list.start
%type <exp> statement.definition.list.start.qualified
%type <exp> statement.definition.list.append
%type <exp> statement.definition.list.append.qualified
%type <exp> statement.definition.with
%type <exp> statement.declare.doc
%type <exp> statement.declare.metadata
%type <exp> statement.declare.feature.metadata
%type <exp> statement.identifier
%type <exp> statement.identifier.box
%type <exp> statement.identifier.waveform
%type <exp> statement.import
%type <exp> statement.list
%type <exp> statement.list.start
%type <exp> statement.list.start.qualified
%type <exp> statement.list.append
%type <exp> statement.list.append.qualified
%type <numvariant> statement.math.precision
%type <numvariant> statement.math.precision.list
%type <numvariant> statement.math.precision.list.start
%type <numvariant> statement.math.precision.list.append
%type <exp> statement.signal.pattern.rule
%type <exp> statement.signal.pattern.rule.list
%type <exp> statement.signal.pattern.rule.list.start
%type <exp> statement.signal.pattern.rule.list.append

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
			$$ = docTxt($[doc.text]->c_str());
			delete $[doc.text];
		}
  | doc.equation { $$ = docEqn($[doc.equation]); }
  | doc.diagram { $$ = docDgm($[doc.diagram]); }
  | doc.notice { $$ = docNtc(); }
  | doc.list { $$ = docLst(); }
  | doc.metadata { $$ = docMtd($[doc.metadata]); }
	| /* empty */ { $$ = gGlobal->nil; }

  doc.text:
      DOCCHAR { $$ = new string(yytext); }
    | doc.text[prior] DOCCHAR { $$ = &($prior->append(yytext)); }

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
        | ADD FLOAT { $$ = boxReal(atof(yytext)); }
        | SUB INT { $$ = boxInt ( -str2int(yytext) ); }
        | SUB FLOAT { $$ = boxReal( -atof(yytext) ); }

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

    statement.definition.function:
        statement.identifier.box LPAR expression.composition.list RPAR DEF expression ENDDEF {
          $$ = cons(
            $[statement.identifier.box],
            cons( $[expression.composition.list], $expression )
          );
          setDefProp($[statement.identifier.box], yyfilename, yylineno);
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
