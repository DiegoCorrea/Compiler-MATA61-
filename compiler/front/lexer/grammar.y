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
start: program                                      {printf("[program \n");}
    | %empty                                        {printf("EMPTY] \n");}
;
program:
    program decvar                                  {printf("\t[decvar \n");}
    | program decfunc                               {printf("\t[decfunc \n");}
    | %empty                                        {printf("\tEMPTY] \n");}
;
decvar: LET_T ID SEMICOLON                          {printf("\t\t[UNIQUE \n");}
        | LET_T ID ASSIGN ID SEMICOLON              {printf("\t\t[ASSIGN \n");}
;
decfunc:
    DEF_T ID LPARENT paramlist RPARENT block        {printf("\t\t[ID \n");}
    | DEF_T MAIN_T LPARENT paramlist RPARENT block  {printf("\t\t[MAIN \n");}
;
paramlist:
    ID                                              {printf("\t\t\t[paramlist ID \n");}
    | ID COMMA paramlist                            {printf("\t\t\t[paramlist COMMA \n");}
    | %empty                                        {printf("\t\t\tEMPTY] \n");}
;
block:
    LBRACE RBRACE                                   {printf("\t\t\t[block:  \n");}
    | %empty                                        {printf("\t\t\t\tEMPTY] \n");}
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}