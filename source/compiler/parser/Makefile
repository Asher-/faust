
OUT=faustlexer.cpp faustparser.cpp faustparser.hpp
BISON=$(shell which bison)
FLEX=$(shell which flex)
GSED=$(shell which gsed)
PREFIX:=FAUST
#OPTIONS:=-I -P$(PREFIX)

code : $(OUT)

faustparser.hpp : faustparser.yy
faustparser.cpp : faustparser.yy
	$(BISON) -d --no-lines -o abstract/implementation.cpp $(OPTIONS) faustparser.yy
	@# Change YYLLOC_DEFAULT( location, ... ) to YYLLOC_DEFAULT( token, ... )
	@# where token.location == location
	@$(GSED) -i -E "s/(YYLLOC_DEFAULT \(yylhs).location(, range, yylen\))/\1\2/" abstract/implementation.cpp
	@$(GSED) -i -E "s/(YYLLOC_DEFAULT \(error_token).location(, yyerror_range, 2\))/\1\2/" abstract/implementation.cpp
	

faustlexer.cpp : lexer/faustlexer.ll
	$(FLEX) -Cf -L -I -olexer/abstract/implementation.cpp $(OPTIONS) lexer/faustlexer.ll

clean:
	rm -f $(OUT)
