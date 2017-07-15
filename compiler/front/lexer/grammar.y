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
start: 
    {printf("[program");}        program          {printf("\n]");}
    | %empty
;
program:
    decvar program
    | decfunc program
    | %empty
;
decvar: 
    LET_T ID SEMICOLON decvar                              {printf("\n\t[decvar [ID]]\n");}
    | LET_T ID ASSIGN {printf("\n\t[decvar ");} expr SEMICOLON decvar                {printf("\t]\n");}
    | %empty
;
decfunc:
    DEF_T {printf("\n\t[decfunc ");} ID {printf("\n\t\t[FUNC NAME]");} LPARENT {printf("\n\t\t[Paramlist ");} paramlist {printf("]");} RPARENT  block {printf("\n\t]");}
    | DEF_T {printf("\n\t[decfunc ");} MAIN_T {printf("\n\t\t[main]");} LPARENT {printf("\n\t\t[Paramlist ");} paramlist {printf("]");} RPARENT block {printf("\n\t]");}
;
block:
    LBRACE {printf("\n\t\t[block");} decvar statement RBRACE                  {printf("\t\t]");}
    | %empty
;
paramlist: 
    ID                                              {printf(" [ ID ] ");}
    | ID COMMA {printf(" [ ID ] ");} paramlist
    | %empty
;
statement:
    assigner {printf("\n\t\t\t[assign");} SEMICOLON statement                    {printf("\t statement: assigner SEMICOLON] \n");}
    | funccall {printf("\n\t\t\t[funccall");} SEMICOLON statement                  {printf("\t statement: funccall SEMICOLON] \n");}
    | conditional statement                         {printf("\t statement: conditional] \n");}
    | loop statement                                {printf("\t statement: loop] \n");}
    | return statement
    | break
    | continue
    | %empty
;
assigner:
    ID ASSIGN ID                                    {printf("\t assigner: ID ASSIGN ID] \n");}
    | ID ASSIGN expr                                {printf("\t assigner: ID ASSIGN expr] \n");}
    | ID ASSIGN {printf("\n = ");} assigner                            {printf("\t assigner: ID ASSIGN assigner \n");}
    | %empty
;
return:
    {printf("\n\t\t\t[return\n\t\t\t\t");}   RETURN_T expr SEMICOLON                         {printf("\n\t\t\t]\n");}
;
conditional:
    IF_T LPARENT expr RPARENT block                 {printf("\t [conditional IF_T LPARENT expr RPARENT block] \n");}
    | IF_T LPARENT expr RPARENT block ELSE_T block  {printf("\t [conditional IF_T LPARENT expr RPARENT block ELSE_T block] \n");}
;
loop:
    WHILE_T {printf("\n\t\t\t[Stmt");} LPARENT expr RPARENT block              {printf("\t [loop WHILE_T LPARENT expr RPARENT block \n");}
;
break:
    BREAK_T SEMICOLON                               {printf("\t [break] \n");}
;
continue:
    CONTINUE_T SEMICOLON                            {printf("\t [continue] \n");}
;
expr:
    expr binop expr
    | unop expr
    | LPARENT expr RPARENT
    | funccall
    | DEC                                           {printf(" [DEC] ");}
    | ID                                            {printf(" [ID] ");}
    | %empty
;
funccall:
    ID LPARENT RPARENT                              {printf("\t [funccall ] \n");}
    | ID LPARENT {printf("\n\t\t[arglist ");} arglist {printf("\t\t]\n ");} RPARENT                    {printf("\t [funccall: ID LPARENT arglist RPARENT] \n");}
;
arglist:
    expr                                            {printf("\t [arglist: expr \n");}
    | expr COMMA arglist                            {printf("\t [arglist: expr COMMA arglist] \n");}
;
binop:
    PLUS                                            {printf(" + ");}
    | MINUS                                         {printf(" - ");}
    | MULTIPLY                                      {printf(" * ");}
    | DIVIDER                                       {printf(" /  ");}
    | LESSTHAN                                      {printf(" <  ");}
    | LESSOREQUAL                                   {printf(" >= ");}
    | BIGGERTHAN                                    {printf(" >  ");}
    | BIGGEROREQUAL                                 {printf(" >= ");}
    | EQUAL                                         {printf(" == ");}
    | NOTEQUAL                                      {printf(" != ");}
    | AND                                           {printf(" && ");}
    | OR                                            {printf(" || ");}
;
unop:
    MINUS                                           {printf(" -");}
    | NOT                                           {printf(" !");}
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}