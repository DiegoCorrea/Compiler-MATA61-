all:
	$(MAKE) grammar
	$(MAKE) lex
	gcc -c compiler/front/lexer/grammar.tab.c compiler/front/lexer/lex.yy.c
	mv *.o compiler/front/lexer/
	ar rvs compiler/front/lexer/lexgram.a compiler/front/lexer/grammar.tab.o compiler/front/lexer/lex.yy.o
	g++ -std=c++11 -Wall -Wextra compiler/front/lexer/mainLexer.cpp compiler/front/lexer/lexgram.a
	mv a.out bin/

grammar:
	bison -d compiler/front/lexer/grammar.y
	mv grammar.tab.* compiler/front/lexer/

lex:
	flex compiler/front/lexer/lex.l
	mv lex.yy.* compiler/front/lexer/

run:
	$(MAKE) all
	./bin/a.out < input/1.jsc
	./bin/a.out < input/2.jsc
	./bin/a.out < input/3.jsc
	./bin/a.out < input/4.jsc