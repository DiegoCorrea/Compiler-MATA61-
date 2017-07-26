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
%left UMINUS 


%start start

%%
start:
    program                                             {printf("[Program\n");}
    | %empty
;
program:
    decvar program
    DEF_T decfunc program
    | %empty
;
decvar:
    LET_T identifier decvarassign SEMICOLON             {printf("[DecVar\n");}
;
decvarassign:
    %empty
    | ASSIGN expr                                       {printf("\tAssign Var\n");}
;
decfunc:
    identifier LPARENT paramlist RPARENT block          {printf("[Decfunc\n");} 
    MAIN_T LPARENT paramlist RPARENT block              {printf("[Main\n");} 
;
paramlist:
    %empty
    | identifier paramlistcomma
;
paramlistcomma:
    %empty
    | COMMA paramlist
;
block:
    LBRACE decvar statement RBRACE                      {printf("[LBRACE decvar statement RBRACE]\n");} 
    | %empty
;
assigner:
    %empty
    | identifier ASSIGN expr
;
expr:
    expr PLUS expr                              {printf("[+ [ID ID"); $$ = $1 + $2;}
    | expr MINUS expr                           {printf("[- [ID ID");}
    | expr MULTIPLY expr                        {printf("[* [ID ID");}
    | expr DIVIDER expr                         {printf("[/ [ID ID");}
    | expr LESSTHAN expr                        {printf("[< [ID ID");}
    | expr LESSOREQUAL expr                     {printf("[<= [ID ID");}
    | expr BIGGERTHAN expr                      {printf("[> [ID ID");}
    | expr BIGGEROREQUAL expr                   {printf("[>= [ID ID");}
    | expr EQUAL expr                           {printf("[== [ID ID");}
    | expr NOTEQUAL expr                        {printf("[!= [ID ID");}
    | expr AND expr                             {printf("[&& [ID ID");}
    | expr OR expr                              {printf("[|| [ID ID");}
    | funccall                                  {printf("[funccal\n");}
    | LPARENT expr RPARENT                      {printf("[expr ()\n");}
    | unop expr                                 {printf("[UMINUS");}
    | identifier
    | DEC
;
unop:
    MINUS                                           
    | NOT                                           
;
funccall:
    identifier LPARENT arglist RPARENT
;
arglist:
    %empty
    | expr arglistcomma                         {printf("[Arglist");}
;
arglistcomma:
    %empty
    | COMMA arglist                             {printf("--==parametro");}
;
identifier:
    ID
;
return:
    RETURN_T expr SEMICOLON                     {printf("Passando pelo rturn\n");}
;
conditional:
    IF_T LPARENT expr RPARENT block conditinalelse
;
conditinalelse:
     ELSE_T block
     | %empty
;
loop:
    WHILE_T LPARENT expr RPARENT block
;
break:
    BREAK_T SEMICOLON
;
continue:
    CONTINUE_T SEMICOLON
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
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}