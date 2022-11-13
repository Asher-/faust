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

%{

#include "compiler/parser/implementation.hh"
#include "compiler/parser/lexer/implementation.hh"

using Parser = ::Faust::Compiler::Parser::AbstractImplementation;
using Self = ::Faust::Compiler::Parser::Implementation;
using symbol_type = typename Parser::symbol_type;

#undef YY_DECL
#define YY_DECL symbol_type Faust::Compiler::Parser::Lexer::Implementation::lex( Self& )

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
    #define YY_FATAL_ERROR lexerror
#endif

#define register		// suppress the deprecated 'register' warning

  /* This disables inclusion of unistd.h, which is not available under Visual C++
   * on Win32. The C++ scanner uses STL streams instead. */
  #define YY_NO_UNISTD_H

  /* The following suffices to track locations accurately. Each time
   * yylex is invoked, the begin position is moved onto the end position. */
  #define YY_USER_ACTION  this->self._location.columns(yyleng);
  

  /* By default yylex returns int, we use token_type. Unfortunately yyterminate
   * by default returns 0, which is not of token_type. */
  #define yyterminate() return Parser::make_ENDOFINPUT( this->self._location );


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

"/*"							BEGIN(comment);
<comment>[^*\x0a\x0d]*			/* eat anything that's not a '*' 		*/
<comment>"*"+[^*/\x0a\x0d]*		/* eat up '*'s not followed by '/'s 	*/
<comment>\x0a\x0d				/* no need to increment yylineno here 	*/
<comment>\x0a					/* no need to increment yylineno here 	*/
<comment>\x0d					/* no need to increment yylineno here 	*/
<comment>"*"+"/"				BEGIN(INITIAL);

"<mdoc>"						{ BEGIN(doc); return Parser::make_BDOC( yytext, this->self._location ); }
<doc>.							return Parser::make_DOCCHAR( yytext, this->self._location ); /* char by char, may be slow ?? */
<doc>\n							return Parser::make_DOCCHAR( yytext, this->self._location ); /* keep newline chars */
<doc>"<notice/>"				return Parser::make_NOTICE( yytext, this->self._location );  /* autoclosing tag */
<doc>"<notice />"				return Parser::make_NOTICE( yytext, this->self._location );  /* autoclosing tag */
<doc>"<listing"					{ BEGIN(lst);		return Parser::make_BLST( yytext, this->self._location ); } /* autoclosing tag */
<doc>"[\s]*<equation>"				{ BEGIN(INITIAL); 	return Parser::make_BEQN( yytext, this->self._location ); }
"</equation>[\s]*"					{ BEGIN(doc); 		return Parser::make_EEQN( yytext, this->self._location ); }
<doc>"[\s]*<diagram>[\s]*"				{ BEGIN(INITIAL); 	return Parser::make_BDGM( yytext, this->self._location ); }
"</diagram>[\s]*"					{ BEGIN(doc); 		return Parser::make_EDGM( yytext, this->self._location ); }
<doc>"[\s]*<metadata>"				{ BEGIN(INITIAL); 	return Parser::make_BMETADATA( yytext, this->self._location ); }
"</metadata>[\s]*"					{ BEGIN(doc); 		return Parser::make_EMETADATA( yytext, this->self._location ); }
<doc>"</mdoc>"					{ BEGIN(INITIAL); 	return Parser::make_EDOC( yytext, this->self._location ); }

<lst>"true"						return Parser::make_LSTTRUE( yytext, this->self._location );
<lst>"false"					return Parser::make_LSTFALSE( yytext, this->self._location );
<lst>"dependencies"				return Parser::make_LSTDEPENDENCIES( yytext, this->self._location );
<lst>"mdoctags"					return Parser::make_LSTMDOCTAGS( yytext, this->self._location );
<lst>"distributed"				return Parser::make_LSTDISTRIBUTED( yytext, this->self._location );
<lst>"="						return Parser::make_LSTEQ( yytext, this->self._location );
<lst>"\""						return Parser::make_LSTQ( yytext, this->self._location );
<lst>"/>"						{ BEGIN(doc); 	return Parser::make_ELST( yytext, this->self._location ); }


{DIGIT}+    		return Parser::make_INT( std::stoi(yytext), this->self._location );

{DIGIT}+"f"                             return Parser::make_FLOAT( atof(yytext), this->self._location );
{DIGIT}+"."{DIGIT}*                     return Parser::make_FLOAT( atof(yytext), this->self._location );
{DIGIT}+"."{DIGIT}*"f"                  return Parser::make_FLOAT( atof(yytext), this->self._location );
{DIGIT}+"."{DIGIT}*e[-+]?{DIGIT}+       return Parser::make_FLOAT( atof(yytext), this->self._location );
{DIGIT}+"."{DIGIT}*e[-+]?{DIGIT}+"f"    return Parser::make_FLOAT( atof(yytext), this->self._location );
{DIGIT}+e[-+]?{DIGIT}+                  return Parser::make_FLOAT( atof(yytext), this->self._location );
{DIGIT}+e[-+]?{DIGIT}+"f"               return Parser::make_FLOAT( atof(yytext), this->self._location );
"."{DIGIT}+                             return Parser::make_FLOAT( atof(yytext), this->self._location );
"."{DIGIT}+"f"                          return Parser::make_FLOAT( atof(yytext), this->self._location );
"."{DIGIT}+e[-+]?{DIGIT}+               return Parser::make_FLOAT( atof(yytext), this->self._location );
"."{DIGIT}+e[-+]?{DIGIT}+"f"            return Parser::make_FLOAT( atof(yytext), this->self._location );

":"   		return Parser::make_SEQ( yytext, this->self._location );
","   		return Parser::make_COMMA( yytext, this->self._location );
"<:"   		return Parser::make_SPLIT( yytext, this->self._location );
"+>"   		return Parser::make_MIX( yytext, this->self._location );
":>"   		return Parser::make_MIX( yytext, this->self._location );
"~"   		return Parser::make_REC( yytext, this->self._location );

"+"   		return Parser::make_ADD( yytext, this->self._location );
"-"   		return Parser::make_SUB( yytext, this->self._location );
"*"   		return Parser::make_MUL( yytext, this->self._location );
"/"   		return Parser::make_DIV( yytext, this->self._location );
"%"   		return Parser::make_MOD( yytext, this->self._location );
"@"			return Parser::make_FDELAY( yytext, this->self._location );
"'"			return Parser::make_DELAY1( yytext, this->self._location );

"&"   		return Parser::make_AND( yytext, this->self._location );
"|"   		return Parser::make_OR( yytext, this->self._location );
"xor"       return Parser::make_XOR( yytext, this->self._location );

"<<"   		return Parser::make_LSH( yytext, this->self._location );
">>"   		return Parser::make_RSH( yytext, this->self._location );

"<"   		return Parser::make_LT( yytext, this->self._location );
"<="   		return Parser::make_LE( yytext, this->self._location );
">"   		return Parser::make_GT( yytext, this->self._location );
">="   		return Parser::make_GE( yytext, this->self._location );
"=="   		return Parser::make_EQ( yytext, this->self._location );
"!="   		return Parser::make_NE( yytext, this->self._location );

"_"			return Parser::make_WIRE( yytext, this->self._location );
"!"			return Parser::make_CUT( yytext, this->self._location );

";"			return Parser::make_ENDDEF( yytext, this->self._location );
"="			return Parser::make_DEF( yytext, this->self._location );
"("			return Parser::make_LPAR( yytext, this->self._location );
")"			return Parser::make_RPAR( yytext, this->self._location );
"{"			return Parser::make_LBRAQ( yytext, this->self._location );
"}"			return Parser::make_RBRAQ( yytext, this->self._location );
"["			return Parser::make_LCROC( yytext, this->self._location );
"]"			return Parser::make_RCROC( yytext, this->self._location );

"\\"		return Parser::make_LAMBDA( yytext, this->self._location );
"."			return Parser::make_DOT( yytext, this->self._location );
"with"		return Parser::make_WITH( yytext, this->self._location );
"letrec"	return Parser::make_LETREC( yytext, this->self._location );
"where"		return Parser::make_WHERE( yytext, this->self._location );

"mem"		return Parser::make_MEM( yytext, this->self._location );
"prefix"	return Parser::make_PREFIX( yytext, this->self._location );

"int"		return Parser::make_INTCAST( yytext, this->self._location );
"float"		return Parser::make_FLOATCAST( yytext, this->self._location );
"any"		return Parser::make_ANYCAST( yytext, this->self._location );

"rdtable"	return Parser::make_RDTBL( yytext, this->self._location );
"rwtable"	return Parser::make_RWTBL( yytext, this->self._location );

"select2"	return Parser::make_SELECT2( yytext, this->self._location );
"select3"	return Parser::make_SELECT3( yytext, this->self._location );

"ffunction"	return Parser::make_FFUNCTION( yytext, this->self._location );
"fconstant" return Parser::make_FCONSTANT( yytext, this->self._location );
"fvariable" return Parser::make_FVARIABLE( yytext, this->self._location );

"button"	return Parser::make_BUTTON( yytext, this->self._location );
"checkbox"	return Parser::make_CHECKBOX( yytext, this->self._location );
"vslider"	return Parser::make_VSLIDER( yytext, this->self._location );
"hslider"	return Parser::make_HSLIDER( yytext, this->self._location );
"nentry"	return Parser::make_NENTRY( yytext, this->self._location );
"vgroup"	return Parser::make_VGROUP( yytext, this->self._location );
"hgroup"	return Parser::make_HGROUP( yytext, this->self._location );
"tgroup"	return Parser::make_TGROUP( yytext, this->self._location );
"vbargraph"	return Parser::make_VBARGRAPH( yytext, this->self._location );
"hbargraph"	return Parser::make_HBARGRAPH( yytext, this->self._location );
"soundfile" return Parser::make_SOUNDFILE( yytext, this->self._location );

"attach"	return Parser::make_ATTACH( yytext, this->self._location );

"acos"		return Parser::make_ACOS( yytext, this->self._location );
"asin"		return Parser::make_ASIN( yytext, this->self._location );
"atan"		return Parser::make_ATAN( yytext, this->self._location );
"atan2"		return Parser::make_ATAN2( yytext, this->self._location );

"cos"		return Parser::make_COS( yytext, this->self._location );
"sin"		return Parser::make_SIN( yytext, this->self._location );
"tan"		return Parser::make_TAN( yytext, this->self._location );

"exp"		return Parser::make_EXP( yytext, this->self._location );
"log"		return Parser::make_LOG( yytext, this->self._location );
"log10"		return Parser::make_LOG10( yytext, this->self._location );
"^"         return Parser::make_POWOP( yytext, this->self._location );
"pow"       return Parser::make_POWFUN( yytext, this->self._location );
"sqrt"		return Parser::make_SQRT( yytext, this->self._location );

"abs"		return Parser::make_ABS( yytext, this->self._location );
"min"		return Parser::make_MIN( yytext, this->self._location );
"max"		return Parser::make_MAX( yytext, this->self._location );

"fmod"		return Parser::make_FMOD( yytext, this->self._location );
"remainder"	return Parser::make_REMAINDER( yytext, this->self._location );

"floor"		return Parser::make_FLOOR( yytext, this->self._location );
"ceil"		return Parser::make_CEIL( yytext, this->self._location );
"rint"		return Parser::make_RINT( yytext, this->self._location );

"seq"		return Parser::make_ISEQ( yytext, this->self._location );
"par"		return Parser::make_ITERATE_PARALLEL( yytext, this->self._location );
"sum"		return Parser::make_ISUM( yytext, this->self._location );
"prod"		return Parser::make_IPROD( yytext, this->self._location );

"inputs"	return Parser::make_INPUTS( yytext, this->self._location );
"outputs"	return Parser::make_OUTPUTS( yytext, this->self._location );

"import"	return Parser::make_IMPORT( yytext, this->self._location );
"component" return Parser::make_COMPONENT( yytext, this->self._location );
"library"   return Parser::make_LIBRARY( yytext, this->self._location );
"environment"   return Parser::make_ENVIRONMENT( yytext, this->self._location );

"waveform"  return Parser::make_WAVEFORM( yytext, this->self._location );
"route"     return Parser::make_ROUTE( yytext, this->self._location );
"enable"   	return Parser::make_ENABLE( yytext, this->self._location );
"control"   return Parser::make_CONTROL( yytext, this->self._location );

"declare"	return Parser::make_DECLARE( yytext, this->self._location );

"case"		return Parser::make_CASE( yytext, this->self._location );
"=>"		return Parser::make_ARROW( yytext, this->self._location );

"assertbounds" return Parser::make_ASSERTBOUNDS( yytext, this->self._location );
"lowest"  return Parser::make_LOWEST( yytext, this->self._location );
"highest"  return Parser::make_HIGHEST( yytext, this->self._location );

"singleprecision" return Parser::make_FLOATMODE( std::stoi(yytext), this->self._location );
"doubleprecision"  return Parser::make_DOUBLEMODE( std::stoi(yytext), this->self._location );
"quadprecision"    return Parser::make_QUADMODE( std::stoi(yytext), this->self._location );
"fixedpointprecision"    return Parser::make_FIXEDPOINTMODE( std::stoi(yytext), this->self._location );


"::"{NSID}   	return Parser::make_IDENT( yytext, this->self._location );
{NSID}   		return Parser::make_IDENT( yytext, this->self._location );

"\""[^\"]*"\""	return Parser::make_STRING( yytext, this->self._location );

"<"{LETTER}*"."{LETTER}">"	return Parser::make_TAGSTRING( yytext, this->self._location );
"<"{LETTER}*">"				return Parser::make_TAGSTRING( yytext, this->self._location );


"//"[^\x0a\x0d]*	/* eat up one-line comments */

[ \t\x0a\x0d]+		/* eat up whitespace */

<<EOF>>		yyterminate();

       /* Catch all the alien characters. */
     .  {
          std::string error_text( std::string("invalid character: %s") + yytext );
          this->LexerError( error_text.c_str() );
          return Parser::make_EXTRA( yytext, this->self._location );
        }

%%


