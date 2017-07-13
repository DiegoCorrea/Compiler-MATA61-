%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token KEY ID SYM DEC DEF
%token LPARENT
%token RPARENT
%token LBRACE
%token RBRACE

%start program

%%

program:
    decfunc                              
    | %empty
;
decfunc:
    DEF ID LPARENT RPARENT LBRACE RBRACE 
    | %empty
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}