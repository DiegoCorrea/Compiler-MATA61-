%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token KEY ID SYM DEC

%start input

%%

input:
  KEY ID SYM SYM SYM SYM
  | %empty
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}