%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token KEY ID SYM DEC DEF


%start program

%%

program: decfunc
;
%%

decfunc:      DEF ID '(' ')'
        ;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}