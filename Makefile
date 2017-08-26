all:
	$(MAKE) grammar
	$(MAKE) lex
	gcc -std=gnu99 -c compiler/front/parser/grammar.tab.c
	mv *.o compiler/front/parser/
	gcc -c compiler/front/lexer/lex.yy.c
	mv *.o compiler/front/lexer/
	ar rvs compiler/front/front.a compiler/front/parser/grammar.tab.o compiler/front/lexer/lex.yy.o
	g++ -std=c++11 -Wall -Wextra -o compilador compiler/main.cpp compiler/front/front.a compiler/back/codeGenerator.c

grammar:
	bison -d compiler/front/parser/grammar.y
	mv grammar.tab.* compiler/front/parser/

lex:
	flex compiler/front/lexer/lex.l
	mv lex.yy.* compiler/front/lexer/

test:
	$(MAKE) all
	./compilador input/codeGen/good-0.jsc output/codeGen/good-0.syn

report:
	 bison -d -r all --report-file=compiler/front/front.log compiler/front/lexer/grammar.y
