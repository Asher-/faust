
OUT=faustlexer.cpp faustparser.cpp faustparser.hpp
BISON=$(shell which bison)
FLEX=$(shell which flex)
PREFIX:=FAUST
#OPTIONS:=-I -P$(PREFIX)

code : $(OUT)

faustparser.hpp : faustparser.yy
faustparser.cpp : faustparser.yy
	$(BISON) -d --no-lines -o abstract/implementation.cpp $(OPTIONS) faustparser.yy

faustlexer.cpp : lexer/faustlexer.ll
	$(FLEX) -Cf -I -olexer/abstract/implementation.cpp $(OPTIONS) lexer/faustlexer.ll

clean:
	rm -f $(OUT)
