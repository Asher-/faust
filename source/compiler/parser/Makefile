
													 # Verified working with:
BISON=$(shell which bison) # GNU Bison 3.8.2
FLEX=$(shell which flex)   # flex 2.6.4
GSED=$(shell which gsed)   # GNU sed 4.9

BISON_OUTPUT_STATE=bison/implementation.output
TRANSITION_HH=bison/transitions.hh
TRANSITION_CPP=bison/transitions.cpp

MAKE_PRODUCT=lexer/abstract/implementation.cpp bison/implementation.cpp bison/implementation.hh
MAKE_BYPRODUCT=$(BISON_OUTPUT_STATE) $(TRANSITION_HH) $(TRANSITION_CPP)

code : $(MAKE_PRODUCT)

bison/implementation.hh : bison.yy
bison/implementation.cpp : bison.yy
	$(BISON) -d --no-lines -o bison/implementation.cpp $(OPTIONS) bison.yy
	@# The rest of this rule contains modifications to the generated parser.
	@# Bison warns against relying on internals, but sometimes it just makes sense.
	@# For maintainability, modifications should be as narrow as possible
	@# and documented here. Avoid changes that do not clarify what internals are
	@# being used (for example by making everything public).
	@#
	@# Change YYLLOC_DEFAULT( location, ... ) to YYLLOC_DEFAULT( token, ... )
	@# where token.location == location
	@$(GSED) -i -E "s/(YYLLOC_DEFAULT \(yylhs).location(, range, yylen\))/\1\2/" bison/implementation.cpp
	@$(GSED) -i -E "s/(YYLLOC_DEFAULT \(error_token).location(, yyerror_range, 2\))/\1\2/" bison/implementation.cpp
	@# Expose yystack so that we can access reduced partial rule matches (no longer in LAC).
	@$(GSED) -i -E "s/^(\s*)(stack_type yystack_;)\s*/\1\2\n\1public:\n\1stack_type\& yystack\(\) { return yystack_; }\n\1const stack_type\& yystack\(\) const { return yystack_; }\n\1private:\n/" bison/implementation.hh
	@./make_transition_info.sh
	
lexer/abstract/implementation.cpp : lexer/faustlexer.ll
	$(FLEX) -Cf -L -I -olexer/abstract/implementation.cpp $(OPTIONS) lexer/faustlexer.ll
	@# The rest of this rule contains modifications to the generated scanner.
	@# Flex warns against relying on internals, but sometimes it just makes sense.
	@# For maintainability, modifications should be as narrow as possible
	@# and documented here. Avoid changes that do not clarify what internals are
	@# being used (for example by making everything public).
	@#
	@# Fix conversion precision warning from std::streamsize being other than int (Mac OS, likely others)
	@$(GSED) -i -E "s/return yyin.gcount\(\)/return static_cast<int>(yyin.gcount())/" lexer/abstract/implementation.cpp

clean:
	rm -f $(MAKE_PRODUCT) $(MAKE_BYPRODUCT)
