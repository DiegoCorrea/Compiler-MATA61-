all:
	$(MAKE) grammar
	$(MAKE) lex
	gcc -std=gnu99 -c compiler/front/parser/grammar.tab.c 
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
	./compilador input/good-5.jsc output/good-5.syn
	./compilador input/good-7.jsc output/good-7.syn
	./compilador input/good-8.jsc output/good-8.syn
	./compilador input/good-9.jsc output/good-9.syn
	./compilador input/good-10.jsc output/good-10.syn
	./compilador input/good-11.jsc output/good-11.syn
	./compilador input/good-12.jsc output/good-12.syn

report:
	 bison -d -r all --report-file=compiler/front/front.log compiler/front/lexer/grammar.y
