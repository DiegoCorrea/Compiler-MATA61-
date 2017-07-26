all:
	$(MAKE) grammar
	$(MAKE) lex
	gcc -c compiler/front/parser/grammar.tab.c 
	mv *.o compiler/front/parser/
	gcc -c compiler/front/lexer/lex.yy.c
	mv *.o compiler/front/lexer/
	ar rvs compiler/front/front.a compiler/front/parser/grammar.tab.o compiler/front/lexer/lex.yy.o
	g++ -std=c++11 -Wall -Wextra -o compilador compiler/main.cpp compiler/front/front.a 

grammar:
	bison -d compiler/front/parser/grammar.y
	mv grammar.tab.* compiler/front/parser/

lex:
	flex compiler/front/lexer/lex.l 
	mv lex.yy.* compiler/front/lexer/

goodtest:
	$(MAKE) all
	./compilador input/good-0.jsc output/good-0.syn
	./compilador input/good-1.jsc output/good-1.syn
	./compilador input/good-2.jsc output/good-2.syn
	./compilador input/good-3.jsc output/good-3.syn
	./compilador input/good-4.jsc output/good-4.syn

badtest:
	$(MAKE) all
	./compilador input/bad-0.jsc output/bad-0.syn
	./compilador input/bad-1.jsc output/bad-1.syn
	./compilador input/bad-2.jsc output/bad-2.syn
	./compilador input/bad-3.jsc output/bad-3.syn
	./compilador input/bad-4.jsc output/bad-4.syn

report:
	 bison -d -r all --report-file=compiler/front/front.log compiler/front/lexer/grammar.y
