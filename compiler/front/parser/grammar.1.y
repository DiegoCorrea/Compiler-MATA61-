%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token ID
%token DEC

%token LET_T
%token DEF_T

%token MAIN_T
%token IF_T
%token ELSE_T
%token WHILE_T
%token BREAK_T
%token CONTINUE_T
%token RETURN_T

%token LPARENT
%token RPARENT

%token LBRACE
%token RBRACE

%token LBRACKETS
%token RBRACKETS

%token COMMA
%token SEMICOLON

%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDER

%token LESSTHAN
%token BIGGERTHAN

%token LESSOREQUAL
%token BIGGEROREQUAL

%token EQUAL
%token ASSIGN
%token NOTEQUAL

%token AND
%token OR
%token NOT

%token ERROR

%left PLUS MINUS
%left MULTIPLY DIVIDER 


%start program

%%
program:
    LET_T decvar program                                 {printf("[LET_T decvar program]\n");} 
    | DEF_T decfunc program                              {printf("[DEF_T decfunc program]\n");} 
    | %empty
;
decvar:
    ID decvarassigner SEMICOLON                         {printf("[DEF_T decfunc program]\n");} 
    | %empty
;
decvarassigner:
    %empty
    | ASSIGN expr                                       {printf("[ASSIGN expr]\n");} 
    | COMMA decvar                                      {printf("[COMMA decvar]\n");} 
;
decfunc:
    ID LPARENT paramlist RPARENT block                  {printf("[ID LPARENT paramlist RPARENT block]\n");} 
    | MAIN_T {printf("----passando pelo main\n");} LPARENT  paramlist  RPARENT {printf("----Entrando no block\n");} block {printf("[MAIN_T LPARENT  paramlist  RPARENT]\n");} 
;
block:
    LBRACE decvar {printf("----dentro do block\n");} statement{printf("---depois do statement\n");} RBRACE {printf("[LBRACE decvar statement RBRACE]\n");} 
    | %empty
;
paramlist:
    expr param
;
param:
    COMMA paramlist
    | %empty
;
statement:
    assigner SEMICOLON statement
    | funccall SEMICOLON statement
    | conditional statement
    | loop statement
    | return
    | break
    | continue
    | %empty
;
assigner:
    ID ASSIGN ID                                    
    | ID ASSIGN expr                                
    | ID ASSIGN assigner                            
    | %empty
;
return:
    RETURN_T expr SEMICOLON {printf("Passando pelo rturn\n");}
;
conditional:
    IF_T LPARENT exprcompare RPARENT block conditinalelse
;
conditinalelse:
     ELSE_T block
     | %empty
;
loop:
    WHILE_T  LPARENT exprcompare RPARENT block
;
break:
    BREAK_T SEMICOLON
;
continue:
    CONTINUE_T SEMICOLON
;
exprbook:

;
expr:
    %empty
    | funccall 
    | unop expr
    | term binopcalc
;
exprcompare:
    %empty
    | unop exprcompare
    | term binopcalccompare
    | term binopcompare
;
term:
    ID
    | DEC
    | LPARENT expr RPARENT
;
funccall:
    ID LPARENT RPARENT
    | ID LPARENT {printf("passando pela fun ção\n");}  arglist  RPARENT
;
arglist:
    expr                                            
    | COMMA {printf("passando pelo COMMA\n");}  arglist                            
;
binopcalc:
    PLUS expr
    | MINUS expr
    | MULTIPLY expr
    | DIVIDER expr
;
binopcalccompare:
    PLUS exprcompare
    | MINUS exprcompare
    | MULTIPLY exprcompare
    | DIVIDER exprcompare
;
binopcompare:
    LESSTHAN exprcompare
    | LESSOREQUAL exprcompare
    | BIGGERTHAN exprcompare
    | BIGGEROREQUAL exprcompare
    | EQUAL exprcompare
    | NOTEQUAL exprcompare
    | AND exprcompare
    | OR exprcompare
;
unop:
    MINUS                                           
    | NOT                                           
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}