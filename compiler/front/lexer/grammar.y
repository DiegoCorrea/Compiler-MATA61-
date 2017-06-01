%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token FUNCTION ID LPARENT RPARENT LEFT_BRACE RIGHT_BRACE

%start input

%%

input:
  FUNCTION ID LPARENT RPARENT LEFT_BRACE RIGHT_BRACE
  | %empty
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}