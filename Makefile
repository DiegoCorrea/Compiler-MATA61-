all:
	$(MAKE) grammar
	$(MAKE) lex
	gcc -c compiler/front/lexer/grammar.tab.c compiler/front/lexer/lex.yy.c
	mv *.o compiler/front/lexer/
	ar rvs compiler/front/lexer/lexgram.a compiler/front/lexer/grammar.tab.o compiler/front/lexer/lex.yy.o
	g++ -std=c++11 -Wall -Wextra -o compilador compiler/front/lexer/mainLexer.cpp compiler/front/lexer/lexgram.a 

grammar:
	bison -d compiler/front/lexer/grammar.y
	mv grammar.tab.* compiler/front/lexer/

lex:
	flex compiler/front/lexer/lex.l
	mv lex.yy.* compiler/front/lexer/

run:
	$(MAKE) all
	./compilador input/1.jsc output/out1.lex
	./compilador input/2.jsc output/out2.lex
	./compilador input/3.jsc output/out3.lex
	./compilador input/4.jsc output/out4.lex