/* -*- Mode: C++; tab-width: 4; c-basic-offset: 4 -*- */

/* Scanner for the Faust language */

/* C++ class-based debugger with our implementation. */
%option c++ yyclass="::Faust::Compiler::Parser::Lexer::Implementation"

%option extra-type="::Faust::Compiler::Parser::Type::Self*"

/* set yydebug = 1 to print trace to stderr */
%option debug

/* we expect single file input, no wrapping to further files */
%option noyywrap

/* we won't be inserting into the token stream */
%option nounput

/* not interactive — compiling with -Cf. */
%option never-interactive

/* C++ parser means location is non-global, must be passed in. */

%{

#include "compiler/parser/implementation.hh"
#include "compiler/parser/lexer/implementation.hh"
#include "compiler/parser/location/implementation.hh"

using Parser = ::Faust::Compiler::Parser::BisonImplementation;
using Self = ::Faust::Compiler::Parser::Implementation;
using Lexer = ::Faust::Compiler::Parser::Lexer::Implementation;
using Location = ::Faust::Compiler::Parser::Location::Implementation;
using symbol_type = typename Parser::symbol_type;

#undef YY_DECL
#define YY_DECL symbol_type Lexer::lex( Self& )

#include "tlib/tree.hh"

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
    #include "tlib/compatibility.hh"
    #include "compiler/errors/errormsg.hh"
#endif

#define register		// suppress the deprecated 'register' warning

  /* This disables inclusion of unistd.h, which is not available under Visual C++
   * on Win32. The C++ scanner uses STL streams instead. */
  #define YY_NO_UNISTD_H

  /* The following suffices to track locations accurately. Each time
   * yylex is invoked, the begin position is moved onto the end position. */
  #define YY_USER_ACTION  self._location.advanceColumn(yyleng);
  

  /* By default yylex returns int, we use token_type. Unfortunately yyterminate
   * by default returns 0, which is not of token_type. */
  #define yyterminate() return Parser::make_ENDOFINPUT( self._location );


%}

DIGIT    [0-9]
ID       _*[a-zA-Z][_a-zA-Z0-9]*
LETTER   [a-zA-Z]
NUMBER   ({DIGIT}+"."{DIGIT}*|"."{DIGIT}+|{DIGIT}+)
WS_BLANK [ \t]
WS_LINE  [\n\r]
ENDL     \n
TMACRO   \\{ID}(\[(\ *({ID}|{NUMBER}),?\ *)\])?(\{(\ *({ID}|{NUMBER}),?\ *)*\})*
NSID	 {ID}("::"{ID})*

%option yylineno
%option nounput
%x comment
%x doc
%x lst

%% /*** Regular Expressions Part ***/

"/*"							BEGIN(comment);
<comment>[^*\x0a\x0d]*			/* eat anything that's not a '*' 		*/
<comment>"*"+[^*/\x0a\x0d]*		/* eat up '*'s not followed by '/'s 	*/
<comment>\x0a\x0d				/* no need to increment yylineno here 	*/
<comment>\x0a					/* no need to increment yylineno here 	*/
<comment>\x0d					/* no need to increment yylineno here 	*/
<comment>"*"+"/"				BEGIN(INITIAL);

"<mdoc>"						{ BEGIN(doc); return Parser::make_BDOC( yytext, self._location ); }
<doc>.							return Parser::make_DOCCHAR( yytext, self._location ); /* char by char, may be slow ?? */
<doc>\n							return Parser::make_DOCCHAR( yytext, self._location ); /* keep newline chars */
<doc>"<notice/>"				return Parser::make_NOTICE( yytext, self._location );  /* autoclosing tag */
<doc>"<notice />"				return Parser::make_NOTICE( yytext, self._location );  /* autoclosing tag */
<doc>"<listing"					{ BEGIN(lst);		return Parser::make_BLST( yytext, self._location ); } /* autoclosing tag */
<doc>"[\s]*<equation>"				{ BEGIN(INITIAL); 	return Parser::make_BEQN( yytext, self._location ); }
"</equation>[\s]*"					{ BEGIN(doc); 		return Parser::make_EEQN( yytext, self._location ); }
<doc>"[\s]*<diagram>[\s]*"				{ BEGIN(INITIAL); 	return Parser::make_BDGM( yytext, self._location ); }
"</diagram>[\s]*"					{ BEGIN(doc); 		return Parser::make_EDGM( yytext, self._location ); }
<doc>"[\s]*<metadata>"				{ BEGIN(INITIAL); 	return Parser::make_BMETADATA( yytext, self._location ); }
"</metadata>[\s]*"					{ BEGIN(doc); 		return Parser::make_EMETADATA( yytext, self._location ); }
<doc>"</mdoc>"					{ BEGIN(INITIAL); 	return Parser::make_EDOC( yytext, self._location ); }

<lst>"true"						return Parser::make_LSTTRUE( yytext, self._location );
<lst>"false"					return Parser::make_LSTFALSE( yytext, self._location );
<lst>"dependencies"				return Parser::make_LSTDEPENDENCIES( yytext, self._location );
<lst>"mdoctags"					return Parser::make_LSTMDOCTAGS( yytext, self._location );
<lst>"distributed"				return Parser::make_LSTDISTRIBUTED( yytext, self._location );
<lst>"="						return Parser::make_LSTEQ( yytext, self._location );
<lst>"\""						return Parser::make_LSTQ( yytext, self._location );
<lst>"/>"						{ BEGIN(doc); 	return Parser::make_ELST( yytext, self._location ); }


{DIGIT}+    		return Parser::make_INT( std::stoi(yytext), self._location );

{DIGIT}+"f"                             return Parser::make_FLOAT( atof(yytext), self._location );
{DIGIT}+"."{DIGIT}*                     return Parser::make_FLOAT( atof(yytext), self._location );
{DIGIT}+"."{DIGIT}*"f"                  return Parser::make_FLOAT( atof(yytext), self._location );
{DIGIT}+"."{DIGIT}*e[-+]?{DIGIT}+       return Parser::make_FLOAT( atof(yytext), self._location );
{DIGIT}+"."{DIGIT}*e[-+]?{DIGIT}+"f"    return Parser::make_FLOAT( atof(yytext), self._location );
{DIGIT}+e[-+]?{DIGIT}+                  return Parser::make_FLOAT( atof(yytext), self._location );
{DIGIT}+e[-+]?{DIGIT}+"f"               return Parser::make_FLOAT( atof(yytext), self._location );
"."{DIGIT}+                             return Parser::make_FLOAT( atof(yytext), self._location );
"."{DIGIT}+"f"                          return Parser::make_FLOAT( atof(yytext), self._location );
"."{DIGIT}+e[-+]?{DIGIT}+               return Parser::make_FLOAT( atof(yytext), self._location );
"."{DIGIT}+e[-+]?{DIGIT}+"f"            return Parser::make_FLOAT( atof(yytext), self._location );

":"   		return Parser::make_SEQ( yytext, self._location );
","   		return Parser::make_COMMA( yytext, self._location );
"<:"   		return Parser::make_SPLIT( yytext, self._location );
"+>"   		return Parser::make_MIX( yytext, self._location );
":>"   		return Parser::make_MIX( yytext, self._location );
"~"   		return Parser::make_REC( yytext, self._location );

"+"   		return Parser::make_ADD( yytext, self._location );
"-"   		return Parser::make_SUB( yytext, self._location );
"*"   		return Parser::make_MUL( yytext, self._location );
"/"   		return Parser::make_DIV( yytext, self._location );
"%"   		return Parser::make_MOD( yytext, self._location );
"@"			return Parser::make_FDELAY( yytext, self._location );
"'"			return Parser::make_DELAY1( yytext, self._location );

"&"   		return Parser::make_AND( yytext, self._location );
"|"   		return Parser::make_OR( yytext, self._location );
"xor"       return Parser::make_XOR( yytext, self._location );

"<<"   		return Parser::make_LSH( yytext, self._location );
">>"   		return Parser::make_RSH( yytext, self._location );

"<"   		return Parser::make_LT( yytext, self._location );
"<="   		return Parser::make_LE( yytext, self._location );
">"   		return Parser::make_GT( yytext, self._location );
">="   		return Parser::make_GE( yytext, self._location );
"=="   		return Parser::make_EQ( yytext, self._location );
"!="   		return Parser::make_NE( yytext, self._location );

"_"			return Parser::make_WIRE( yytext, self._location );
"!"			return Parser::make_CUT( yytext, self._location );

";"			return Parser::make_ENDDEF( yytext, self._location );
"="			return Parser::make_DEF( yytext, self._location );
"("			return Parser::make_LPAR( yytext, self._location );
")"			return Parser::make_RPAR( yytext, self._location );
"{"			return Parser::make_LBRAQ( yytext, self._location );
"}"			return Parser::make_RBRAQ( yytext, self._location );
"["			return Parser::make_LCROC( yytext, self._location );
"]"			return Parser::make_RCROC( yytext, self._location );

"\\"		return Parser::make_LAMBDA( yytext, self._location );
"."			return Parser::make_DOT( yytext, self._location );
"with"		return Parser::make_WITH( yytext, self._location );
"letrec"	return Parser::make_LETREC( yytext, self._location );
"where"		return Parser::make_WHERE( yytext, self._location );

"mem"		return Parser::make_MEM( yytext, self._location );
"prefix"	return Parser::make_PREFIX( yytext, self._location );

"int"		return Parser::make_INTCAST( yytext, self._location );
"float"		return Parser::make_FLOATCAST( yytext, self._location );
"any"		return Parser::make_ANYCAST( yytext, self._location );

"rdtable"	return Parser::make_RDTBL( yytext, self._location );
"rwtable"	return Parser::make_RWTBL( yytext, self._location );

"select2"	return Parser::make_SELECT2( yytext, self._location );
"select3"	return Parser::make_SELECT3( yytext, self._location );

"ffunction"	return Parser::make_FFUNCTION( yytext, self._location );
"fconstant" return Parser::make_FCONSTANT( yytext, self._location );
"fvariable" return Parser::make_FVARIABLE( yytext, self._location );

"button"	return Parser::make_BUTTON( yytext, self._location );
"checkbox"	return Parser::make_CHECKBOX( yytext, self._location );
"vslider"	return Parser::make_VSLIDER( yytext, self._location );
"hslider"	return Parser::make_HSLIDER( yytext, self._location );
"nentry"	return Parser::make_NENTRY( yytext, self._location );
"vgroup"	return Parser::make_VGROUP( yytext, self._location );
"hgroup"	return Parser::make_HGROUP( yytext, self._location );
"tgroup"	return Parser::make_TGROUP( yytext, self._location );
"vbargraph"	return Parser::make_VBARGRAPH( yytext, self._location );
"hbargraph"	return Parser::make_HBARGRAPH( yytext, self._location );
"soundfile" return Parser::make_SOUNDFILE( yytext, self._location );

"attach"	return Parser::make_ATTACH( yytext, self._location );

"acos"		return Parser::make_ACOS( yytext, self._location );
"asin"		return Parser::make_ASIN( yytext, self._location );
"atan"		return Parser::make_ATAN( yytext, self._location );
"atan2"		return Parser::make_ATAN2( yytext, self._location );

"cos"		return Parser::make_COS( yytext, self._location );
"sin"		return Parser::make_SIN( yytext, self._location );
"tan"		return Parser::make_TAN( yytext, self._location );

"exp"		return Parser::make_EXP( yytext, self._location );
"log"		return Parser::make_LOG( yytext, self._location );
"log10"		return Parser::make_LOG10( yytext, self._location );
"^"         return Parser::make_POWOP( yytext, self._location );
"pow"       return Parser::make_POWFUN( yytext, self._location );
"sqrt"		return Parser::make_SQRT( yytext, self._location );

"abs"		return Parser::make_ABS( yytext, self._location );
"min"		return Parser::make_MIN( yytext, self._location );
"max"		return Parser::make_MAX( yytext, self._location );

"fmod"		return Parser::make_FMOD( yytext, self._location );
"remainder"	return Parser::make_REMAINDER( yytext,  self._location );

"floor"		return Parser::make_FLOOR( yytext, self._location );
"ceil"		return Parser::make_CEIL( yytext, self._location );
"rint"		return Parser::make_RINT( yytext, self._location );

"seq"		return Parser::make_ISEQ( yytext, self._location );
"par"		return Parser::make_ITERATE_PARALLEL( yytext, self._location );
"sum"		return Parser::make_ISUM( yytext, self._location );
"prod"		return Parser::make_IPROD( yytext, self._location );

"inputs"	return Parser::make_INPUTS( yytext, self._location );
"outputs"	return Parser::make_OUTPUTS( yytext, self._location );

"import"	return Parser::make_IMPORT( yytext, self._location );
"component" return Parser::make_COMPONENT( yytext, self._location );
"library"   return Parser::make_LIBRARY( yytext, self._location );
"environment"   return Parser::make_ENVIRONMENT( yytext, self._location );

"waveform"  return Parser::make_WAVEFORM( yytext, self._location );
"route"     return Parser::make_ROUTE( yytext, self._location );
"enable"   	return Parser::make_ENABLE( yytext, self._location );
"control"   return Parser::make_CONTROL( yytext, self._location );

"declare"	return Parser::make_DECLARE( yytext, self._location );

"case"		return Parser::make_CASE( yytext, self._location );
"=>"		return Parser::make_ARROW( yytext, self._location );

"assertbounds" return Parser::make_ASSERTBOUNDS( yytext, self._location );
"lowest"  return Parser::make_LOWEST( yytext, self._location );
"highest"  return Parser::make_HIGHEST( yytext, self._location );

"singleprecision" return Parser::make_FLOATMODE( yytext, self._location );
"doubleprecision"  return Parser::make_DOUBLEMODE( yytext, self._location );
"quadprecision"    return Parser::make_QUADMODE( yytext, self._location );
"fixedpointprecision"    return Parser::make_FIXEDPOINTMODE( yytext, self._location );


"::"{NSID}   	return Parser::make_IDENT( yytext, self._location );
{NSID}   		return Parser::make_IDENT( yytext, self._location );

"\""[^\"]*"\""	return Parser::make_STRING( yytext, self._location );

"<"{LETTER}*"."{LETTER}">"	return Parser::make_TAGSTRING( yytext, self._location );
"<"{LETTER}*">"				return Parser::make_TAGSTRING( yytext, self._location );


"//"[^\x0a\x0d]*	/* eat up one-line comments */


{WS_BLANK}+		self._location.step(); /* eat up whitespace */
{WS_LINE}+		self._location.advanceLine(yyleng); self._location.step(); /* eat up whitespace */

<<EOF>>		yyterminate();

       /* Catch all the alien characters. */
     .  {
          std::string error_text( std::string("invalid character: '") + yytext + "'" );
          this->LexerError( error_text.c_str() );
          return Parser::make_EXTRA( yytext, self._location );
        }

%%


