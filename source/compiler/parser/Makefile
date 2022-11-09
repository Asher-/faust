
OUT  = faustlexer.cpp faustparser.cpp faustparser.hpp
YACC = bison
LEX = flex
PREFIX := FAUST
#OPTIONS:= -I -P$(PREFIX)

code : $(OUT)

faustparser.hpp : faustparser.yy
faustparser.cpp : faustparser.yy
	$(YACC) -d --no-lines -o faustparser.cpp $(OPTIONS) faustparser.yy

faustlexer.cpp : lexer/faustlexer.ll
	$(LEX) -Cf -I -olexer/faustlexer.cpp $(OPTIONS) lexer/faustlexer.ll

clean:
	rm -f $(OUT)
