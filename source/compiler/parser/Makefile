
BISON=$(shell which bison)
FLEX=$(shell which flex)
GSED=$(shell which gsed)

OUT=lexer/abstract/implementation.cpp bison/implementation.cpp bison/implementation.hh

code : $(OUT)

bison/implementation.hh : bison.yy
bison/implementation.cpp : bison.yy
	$(BISON) -d --no-lines -o bison/implementation.cpp $(OPTIONS) bison.yy
	@# Change YYLLOC_DEFAULT( location, ... ) to YYLLOC_DEFAULT( token, ... )
	@# where token.location == location
	@$(GSED) -i -E "s/(YYLLOC_DEFAULT \(yylhs).location(, range, yylen\))/\1\2/" bison/implementation.cpp
	@$(GSED) -i -E "s/(YYLLOC_DEFAULT \(error_token).location(, yyerror_range, 2\))/\1\2/" bison/implementation.cpp
	

lexer/abstract/implementation.cpp : lexer/faustlexer.ll
	$(FLEX) -Cf -L -I -olexer/abstract/implementation.cpp $(OPTIONS) lexer/faustlexer.ll

clean:
	rm -f $(OUT)
