%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token KEY ID SYM DEC DEFFUNC


%start program

%%

program: 'let' ID ';'
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}