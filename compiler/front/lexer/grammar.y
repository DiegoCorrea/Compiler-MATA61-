%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
%}

%define api.value.type{double}

%token KEY ID SYM DEC

%token LET_T
%token DEF_T

%token MAIN_T
%token IF_T
%token ELSE_T
%token WHILE_T
%token FOR_T
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

%start start

%%
start: program                                       {printf("[start \n");}
    | %empty                                         {printf("start] \n");}
;
program:
    program decvar                                   {printf("\4 [program decvar \n");}
    | program decfunc                                {printf("\4 [program decfunc \n");}
    | %empty                                         {printf("\4 program EMPTY] \n");}
;
decvar: 
    LET_T ID SEMICOLON                               {printf("\t [decvar LET_T ID SEMICOLON \n");}
    | LET_T ID ASSIGN expr SEMICOLON                 {printf("\t [decvar LET_T ID ASSIGN expr SEMICOLON \n");}
    | %empty                                         {printf("\t decvar EMPTY] \n");}
;
decfunc:
    DEF_T ID LPARENT paramlist RPARENT block         {printf("\t [decfunc DEF_T ID LPARENT paramlist RPARENT block \n");}
    | DEF_T MAIN_T LPARENT paramlist RPARENT block   {printf("\t [decfunc EF_T MAIN_T LPARENT paramlist RPARENT block \n");}
;
paramlist:
    ID                                               {printf("\t [paramlist ID \n");}
    | ID COMMA paramlist                             {printf("\t [paramlist ID COMMA paramlist \n");}
    | %empty                                         {printf("\t paramlist EMPTY] \n");}
;
block:
    LBRACE decvar statement RBRACE                   {printf("\t [block LBRACE decvar statement RBRACE \n");}
    | %empty                                         {printf("\t block EMPTY] \n");}
;
assigner:
    ID ASSIGN ID                                     {printf("\t assigner ID ASSIGN ID] \n");}
    | ID ASSIGN assigner                             {printf("\t assigner ID ASSIGN assigner \n");}
    | ID ASSIGN expr                                 {printf("\t assigner ID ASSIGN expr] \n");}
    | %empty                                         {printf("\t assigner EMPTY] \n");}
;
statement:
    assigner SEMICOLON                               {printf("\t statement assigner SEMICOLON] \n");}
    | funccall SEMICOLON                             {printf("\t statement funccall SEMICOLON] \n");}
    | conditional                                    {printf("\t statement conditional] \n");}
    | %empty                                         {printf("\t statement EMPTY] \n");}
;
conditional:
    IF_T LPARENT expr RPARENT block                  {printf("\t conditional IF_T LPARENT expr RPARENT block] \n");}
    | IF_T LPARENT expr RPARENT block ELSE_T block  {printf("\t conditional IF_T LPARENT expr RPARENT block ELSE_T block] \n");}
;
expr:
    expr binop expr                                  {printf("\t expr expr binop expr] \n");}
    | unop expr                                      {printf("\t expr unop expr] \n");}
    | LPARENT expr RPARENT                           {printf("\t expr LPARENT expr RPARENT] \n");}
    | funccall                                       {printf("\t expr funccall] \n");}
    | DEC                                            {printf("\t expr DEC] \n");}
    | ID                                             {printf("\t expr ID] \n");}
    | %empty                                         {printf("\t expr EMPTY] \n");}
;
funccall:
    ID LPARENT RPARENT                               {printf("\t funccall ID LPARENT RPARENT] \n");}
    | ID LPARENT arglist RPARENT                     {printf("\t funccall ID LPARENT arglist RPARENT] \n");}
;
arglist:
    expr                                             {printf("\t arglist expr] \n");}
    | expr COMMA arglist                             {printf("\t arglist expr COMMA arglist] \n");}
;
binop:
    PLUS
    | MINUS
    | MULTIPLY
    | DIVIDER
    | LESSTHAN
    | LESSOREQUAL
    | BIGGERTHAN
    | BIGGEROREQUAL
    | EQUAL
    | NOTEQUAL
    | AND
    | OR
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