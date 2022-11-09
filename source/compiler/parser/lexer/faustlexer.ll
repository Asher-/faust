/* -*- Mode: C++; tab-width: 4; c-basic-offset: 4 -*- */

/* Scanner for the Faust language */

/* C++ class-based debugger with our implementation. */
%option c++ yyclass="::Faust::Compiler::Parser::Lexer::Implementation"

%option extra-type="::Faust::Compiler::Parser::Type::Driver*"

/* set yydebug = 1 to print trace to stderr */
%option debug

/* we expect single file input, no wrapping to further files */
%option noyywrap

/* we won't be inserting into the token stream */
%option nounput

/* not interactive — compiling with -Cf. */
%option never-interactive

%{

#include "tlib/tree.hh"
#include "faustparser.hh"
#include "driver.hh"

//using Lexer = ::Faust::Compiler::Parser::Lexer::Implementation;
//using Driver = ::Faust::Compiler::Parser::Type::Driver;
//using Parser = ::Faust::Compiler::Parser::Implementation;
//using symbol_type = typename Parser::symbol_type;
//symbol_type Lexer::lex( Driver& driver );

#if defined(WIN32)
  #if !defined(__MINGW32__) && !defined(__MSYS__)
    // We don't want to include compatibility.hh here, since it pulls in whole lot
    // of unneeded stuff which breaks other things, so here's some stuff to make
    // MSVC happy.
    #include <io.h>
    #define isatty _isatty
    #define fileno _fileno
    #define YY_NO_UNISTD_H
  #endif
  #else
    #include "compatibility.hh"
    #include "compiler/errors/errormsg.hh"
    #define YY_FATAL_ERROR lexerror
#endif

#define register		// suppress the deprecated 'register' warning

  /* This disables inclusion of unistd.h, which is not available under Visual C++
   * on Win32. The C++ scanner uses STL streams instead. */
  #define YY_NO_UNISTD_H

  /* The following suffices to track locations accurately. Each time
   * yylex is invoked, the begin position is moved onto the end position. */
  #define YY_USER_ACTION  driver._location.columns(yyleng);

  /* By default yylex returns int, we use token_type. Unfortunately yyterminate
   * by default returns 0, which is not of token_type. */
  #define yyterminate() return token::END

  using Parser = ::Faust::Compiler::Parser::Implementation;
  using Driver = ::Faust::Compiler::Parser::Type::Driver;

%}

DIGIT    [0-9]
ID       _*[a-zA-Z][_a-zA-Z0-9]*
LETTER   [a-zA-Z]
NUMBER   ({DIGIT}+"."{DIGIT}*|"."{DIGIT}+|{DIGIT}+)
WSPACE   [ \t\n]
ENDL     \n
TMACRO   \\{ID}(\[(\ *({ID}|{NUMBER}),?\ *)\])?(\{(\ *({ID}|{NUMBER}),?\ *)*\})*
NSID	 {ID}("::"{ID})*

%option yylineno
%option nounput
%x comment
%x doc
%x lst

%% /*** Regular Expressions Part ***/

%{
  // Code run each time yylex is called.
  driver._location.step();
  auto& location = driver._location;
%}

"/*"							BEGIN(comment);
<comment>[^*\x0a\x0d]*			/* eat anything that's not a '*' 		*/
<comment>"*"+[^*/\x0a\x0d]*		/* eat up '*'s not followed by '/'s 	*/
<comment>\x0a\x0d				/* no need to increment yylineno here 	*/
<comment>\x0a					/* no need to increment yylineno here 	*/
<comment>\x0d					/* no need to increment yylineno here 	*/
<comment>"*"+"/"				BEGIN(INITIAL);

"<mdoc>"						{ BEGIN(doc); return Parser::make_BDOC( yytext, location ); }
<doc>.							return Parser::make_DOCCHAR( yytext, location ); /* char by char, may be slow ?? */
<doc>\n							return Parser::make_DOCCHAR( yytext, location ); /* keep newline chars */
<doc>"<notice/>"				return Parser::make_NOTICE( yytext, location );  /* autoclosing tag */
<doc>"<notice />"				return Parser::make_NOTICE( yytext, location );  /* autoclosing tag */
<doc>"<listing"					{ BEGIN(lst);		return Parser::make_BLST( yytext, location ); } /* autoclosing tag */
<doc>"[\s]*<equation>"				{ BEGIN(INITIAL); 	return Parser::make_BEQN( yytext, location ); }
"</equation>[\s]*"					{ BEGIN(doc); 		return Parser::make_EEQN( yytext, location ); }
<doc>"[\s]*<diagram>[\s]*"				{ BEGIN(INITIAL); 	return Parser::make_BDGM( yytext, location ); }
"</diagram>[\s]*"					{ BEGIN(doc); 		return Parser::make_EDGM( yytext, location ); }
<doc>"[\s]*<metadata>"				{ BEGIN(INITIAL); 	return Parser::make_BMETADATA( yytext, location ); }
"</metadata>[\s]*"					{ BEGIN(doc); 		return Parser::make_EMETADATA( yytext, location ); }
<doc>"</mdoc>"					{ BEGIN(INITIAL); 	return Parser::make_EDOC( yytext, location ); }

<lst>"true"						return Parser::make_LSTTRUE( yytext, location );
<lst>"false"					return Parser::make_LSTFALSE( yytext, location );
<lst>"dependencies"				return Parser::make_LSTDEPENDENCIES( yytext, location );
<lst>"mdoctags"					return Parser::make_LSTMDOCTAGS( yytext, location );
<lst>"distributed"				return Parser::make_LSTDISTRIBUTED( yytext, location );
<lst>"="						return Parser::make_LSTEQ( yytext, location );
<lst>"\""						return Parser::make_LSTQ( yytext, location );
<lst>"/>"						{ BEGIN(doc); 	return Parser::make_ELST( yytext, location ); }


{DIGIT}+    		return Parser::make_INT( str2int(yytext), location );

{DIGIT}+"f"                             return Parser::make_FLOAT( atof(yytext), location );
{DIGIT}+"."{DIGIT}*                     return Parser::make_FLOAT( atof(yytext), location );
{DIGIT}+"."{DIGIT}*"f"                  return Parser::make_FLOAT( atof(yytext), location );
{DIGIT}+"."{DIGIT}*e[-+]?{DIGIT}+       return Parser::make_FLOAT( atof(yytext), location );
{DIGIT}+"."{DIGIT}*e[-+]?{DIGIT}+"f"    return Parser::make_FLOAT( atof(yytext), location );
{DIGIT}+e[-+]?{DIGIT}+                  return Parser::make_FLOAT( atof(yytext), location );
{DIGIT}+e[-+]?{DIGIT}+"f"               return Parser::make_FLOAT( atof(yytext), location );
"."{DIGIT}+                             return Parser::make_FLOAT( atof(yytext), location );
"."{DIGIT}+"f"                          return Parser::make_FLOAT( atof(yytext), location );
"."{DIGIT}+e[-+]?{DIGIT}+               return Parser::make_FLOAT( atof(yytext), location );
"."{DIGIT}+e[-+]?{DIGIT}+"f"            return Parser::make_FLOAT( atof(yytext), location );

":"   		return Parser::make_SEQ( yytext, location );
","   		return Parser::make_COMMA( yytext, location );
"<:"   		return Parser::make_SPLIT( yytext, location );
"+>"   		return Parser::make_MIX( yytext, location );
":>"   		return Parser::make_MIX( yytext, location );
"~"   		return Parser::make_REC( yytext, location );

"+"   		return Parser::make_ADD( yytext, location );
"-"   		return Parser::make_SUB( yytext, location );
"*"   		return Parser::make_MUL( yytext, location );
"/"   		return Parser::make_DIV( yytext, location );
"%"   		return Parser::make_MOD( yytext, location );
"@"			return Parser::make_FDELAY( yytext, location );
"'"			return Parser::make_DELAY1( location );

"&"   		return Parser::make_AND( yytext, location );
"|"   		return Parser::make_OR( yytext, location );
"xor"       return Parser::make_XOR( yytext, location );

"<<"   		return Parser::make_LSH( yytext, location );
">>"   		return Parser::make_RSH( yytext, location );

"<"   		return Parser::make_LT( yytext, location );
"<="   		return Parser::make_LE( yytext, location );
">"   		return Parser::make_GT( yytext, location );
">="   		return Parser::make_GE( yytext, location );
"=="   		return Parser::make_EQ( yytext, location );
"!="   		return Parser::make_NE( yytext, location );

"_"			return Parser::make_WIRE( yytext, location );
"!"			return Parser::make_CUT( yytext, location );

";"			return Parser::make_ENDDEF( yytext, location );
"="			return Parser::make_DEF( yytext, location );
"("			return Parser::make_LPAR( yytext, location );
")"			return Parser::make_RPAR( yytext, location );
"{"			return Parser::make_LBRAQ( yytext, location );
"}"			return Parser::make_RBRAQ( yytext, location );
"["			return Parser::make_LCROC( yytext, location );
"]"			return Parser::make_RCROC( yytext, location );

"\\"		return Parser::make_LAMBDA( yytext, location );
"."			return Parser::make_DOT( yytext, location );
"with"		return Parser::make_WITH( yytext, location );
"letrec"	return Parser::make_LETREC( yytext, location );
"where"		return Parser::make_WHERE( yytext, location );

"mem"		return Parser::make_MEM( yytext, location );
"prefix"	return Parser::make_PREFIX( yytext, location );

"int"		return Parser::make_INTCAST( yytext, location );
"float"		return Parser::make_FLOATCAST( yytext, location );
"any"		return Parser::make_ANYCAST( yytext, location );

"rdtable"	return Parser::make_RDTBL( yytext, location );
"rwtable"	return Parser::make_RWTBL( yytext, location );

"select2"	return Parser::make_SELECT2( location );
"select3"	return Parser::make_SELECT3( location );

"ffunction"	return Parser::make_FFUNCTION( yytext, location );
"fconstant" return Parser::make_FCONSTANT( yytext, location );
"fvariable" return Parser::make_FVARIABLE( yytext, location );

"button"	return Parser::make_BUTTON( yytext, location );
"checkbox"	return Parser::make_CHECKBOX( yytext, location );
"vslider"	return Parser::make_VSLIDER( yytext, location );
"hslider"	return Parser::make_HSLIDER( yytext, location );
"nentry"	return Parser::make_NENTRY( yytext, location );
"vgroup"	return Parser::make_VGROUP( yytext, location );
"hgroup"	return Parser::make_HGROUP( yytext, location );
"tgroup"	return Parser::make_TGROUP( yytext, location );
"vbargraph"	return Parser::make_VBARGRAPH( yytext, location );
"hbargraph"	return Parser::make_HBARGRAPH( yytext, location );
"soundfile" return Parser::make_SOUNDFILE( yytext, location );

"attach"	return Parser::make_ATTACH( yytext, location );

"acos"		return Parser::make_ACOS( yytext, location );
"asin"		return Parser::make_ASIN( yytext, location );
"atan"		return Parser::make_ATAN( yytext, location );
"atan2"		return Parser::make_ATAN2( location );

"cos"		return Parser::make_COS( yytext, location );
"sin"		return Parser::make_SIN( yytext, location );
"tan"		return Parser::make_TAN( yytext, location );

"exp"		return Parser::make_EXP( yytext, location );
"log"		return Parser::make_LOG( yytext, location );
"log10"		return Parser::make_LOG1( location )0;
"^"         return Parser::make_POWOP( yytext, location );
"pow"       return Parser::make_POWFUN( yytext, location );
"sqrt"		return Parser::make_SQRT( yytext, location );

"abs"		return Parser::make_ABS( yytext, location );
"min"		return Parser::make_MIN( yytext, location );
"max"		return Parser::make_MAX( yytext, location );

"fmod"		return Parser::make_FMOD( yytext, location );
"remainder"	return Parser::make_REMAINDER( yytext, location );

"floor"		return Parser::make_FLOOR( yytext, location );
"ceil"		return Parser::make_CEIL( yytext, location );
"rint"		return Parser::make_RINT( yytext, location );

"seq"		return Parser::make_ISEQ( yytext, location );
"par"		return Parser::make_ITERATE_( location )PARALLEL;
"sum"		return Parser::make_ISUM( yytext, location );
"prod"		return Parser::make_IPROD( yytext, location );

"inputs"	return Parser::make_INPUTS( yytext, location );
"outputs"	return Parser::make_OUTPUTS( yytext, location );

"import"	return Parser::make_IMPORT( yytext, location );
"component" return Parser::make_COMPONENT( yytext, location );
"library"   return Parser::make_LIBRARY( yytext, location );
"environment"   return Parser::make_ENVIRONMENT( yytext, location );

"waveform"  return Parser::make_WAVEFORM( yytext, location );
"route"     return Parser::make_ROUTE( yytext, location );
"enable"   	return Parser::make_ENABLE( yytext, location );
"control"   return Parser::make_CONTROL( yytext, location );

"declare"	return Parser::make_DECLARE( yytext, location );

"case"		return Parser::make_CASE( yytext, location );
"=>"		return Parser::make_ARROW( yytext, location );

"assertbounds" return Parser::make_ASSERTBOUNDS( yytext, location );
"lowest"  return Parser::make_LOWEST( yytext, location );
"highest"  return Parser::make_HIGHEST( yytext, location );

"singleprecision" return Parser::make_FLOATMODE( yytext, location );
"doubleprecision"  return Parser::make_DOUBLEMODE( yytext, location );
"quadprecision"    return Parser::make_QUADMODE( yytext, location );
"fixedpointprecision"    return Parser::make_FIXEDPOINTMODE( yytext, location );


"::"{NSID}   	return Parser::make_IDENT( yytext, location );
{NSID}   		return Parser::make_IDENT( yytext, location );

"\""[^\"]*"\""	return Parser::make_STRING( yytext, location );

"<"{LETTER}*"."{LETTER}">"	return Parser::make_TAGSTRING( yytext, location );
"<"{LETTER}*">"				return Parser::make_TAGSTRING( yytext, location );


"//"[^\x0a\x0d]*	/* eat up one-line comments */

[ \t\x0a\x0d]+		/* eat up whitespace */

<<EOF>>		yyterminate();

       /* Catch all the alien characters. */
     .   {
           yleval_error (yylloc, yycontrol, "invalid character: %s", yytext);
           LOCATION_STEP (*yylloc);
           return Parser::make_EXTRA( yytext, location );
         }

%%

int yywrap() { return 1; }

