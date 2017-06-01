%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  int yyerror(char const *);
%}

%define api.value.type{double}

%token KEY ID SYM SYM SYM SYM

%start input

%%

input

%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}