%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
  FILE *yyin;
  FILE *fl_output;
  extern int yylineno;
%}
%union {              /* define stack type */
  int itype;
}
%token ID
%token <itype> DEC

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

%token ERROR

%left PLUS MINUS
%left MULTIPLY DIVIDER 
%left BIGGERTHAN LESSTHAN EQUAL NOTEQUAL LESSOREQUAL BIGGEROREQUAL
%right UMINUS 


%start start

%%
start: 
    {fprintf(fl_output,"program");}        program            {fprintf(fl_output,"n]\n");}
;
program:
    decvar program
    | decfunc program
    | %empty
;
decvar:
    LET_T ID decvarassign SEMICOLON          {fprintf(fl_output,"DecVar\n");}
;
decvarassign:
    %empty
    | ASSIGN expr                                   {fprintf(fl_output,"Assign Var\n");}
;
decfunc:
    DEF_T {fprintf(fl_output,"t[decfunc ");} decfuncids
;
decfuncids:
    MAIN_T {fprintf(fl_output,"t\t[main]");} LPARENT {fprintf(fl_output,"t\t[Paramlist ");} paramlist {printf("]");} RPARENT block {fprintf(fl_output,"t]");}
    | ID {fprintf(fl_output,"t\t[FUNC NAME]");} LPARENT {fprintf(fl_output,"t\t[Paramlist ");} paramlist {printf("]");} RPARENT  block {fprintf(fl_output,"t]");}
;
block:
    LBRACE {fprintf(fl_output,"t\t[block");} blockstatements RBRACE                  {fprintf(fl_output,"\t]");}
;
blockstatements:
     decvar blockstatements
     | statement
     | %empty
;
paramlist: 
    ID                                              {fprintf(fl_output,"[ ID ] ");}
    | ID COMMA {fprintf(fl_output,"[ ID ] ");} paramlist
    | %empty
;
statement:
    assigner {fprintf(fl_output,"t\t\t[assign");} SEMICOLON statement                    {fprintf(fl_output," statement: assigner SEMICOLON] \n");}
    | funccall {fprintf(fl_output,"t\t\t[funccall");} SEMICOLON statement                  {fprintf(fl_output," statement: funccall SEMICOLON] \n");}
    | conditional statement                             {fprintf(fl_output," statement: conditional] \n");}
    | loop statement                                    {fprintf(fl_output," statement: loop] \n");}
    | return
    | break
    | continue
    | %empty
;
assigner:
    ID ASSIGN expr                                      {fprintf(fl_output," assigner: ID ASSIGN expr] \n");}
    | %empty
;
conditional:
    IF_T LPARENT expr RPARENT block ELSE_T block        {fprintf(fl_output," [conditional IF_T LPARENT expr RPARENT block ELSE_T block] \n");}
    | IF_T LPARENT expr RPARENT block                   {fprintf(fl_output," [conditional IF_T LPARENT expr RPARENT block] \n");}
    
;
loop:
    WHILE_T {fprintf(fl_output,"t\t\t[Stmt");} LPARENT expr RPARENT block              {fprintf(fl_output," [loop WHILE_T LPARENT expr RPARENT block \n");}
;
break:
    BREAK_T SEMICOLON                                   {fprintf(fl_output," [break] \n");}
;
continue:
    CONTINUE_T SEMICOLON                                {fprintf(fl_output," [continue] \n");}
;
return:
    {fprintf(fl_output,"t\t\t[return\n\t\t\t\t");}   RETURN_T expr SEMICOLON                         {fprintf(fl_output,"t\t\t]\n");}
;
expr:
    unop expr                    %prec UMINUS       {fprintf(fl_output," - ");}
    | LPARENT expr RPARENT
    | funccall
    | DEC                                           {fprintf(fl_output,"[DEC] ");}
    | ID                                            {fprintf(fl_output,"[ID] ");}
    | expr PLUS expr                              {fprintf(fl_output,"+ [ID ID");}
    | expr MINUS expr                           {fprintf(fl_output,"- [ID ID");}
    | expr MULTIPLY expr                        {fprintf(fl_output,"* [ID ID");}
    | expr DIVIDER expr                         {fprintf(fl_output,"/ [ID ID");}
    | expr LESSTHAN expr                        {fprintf(fl_output,"< [ID ID");}
    | expr LESSOREQUAL expr                     {fprintf(fl_output,"<= [ID ID");}
    | expr BIGGERTHAN expr                      {fprintf(fl_output,"> [ID ID");}
    | expr BIGGEROREQUAL expr                   {fprintf(fl_output,">= [ID ID");}
    | expr EQUAL expr                           {fprintf(fl_output,"== [ID ID");}
    | expr NOTEQUAL expr                        {fprintf(fl_output,"!= [ID ID");}
    | expr AND expr                             {fprintf(fl_output,"&& [ID ID");}
    | expr OR expr                              {fprintf(fl_output,"|| [ID ID");}
    | %empty
;
binop:
    PLUS                                            {fprintf(fl_output,"+ ");}
    | MINUS                                         {fprintf(fl_output,"- ");}
    | MULTIPLY                                      {fprintf(fl_output,"* ");}
    | DIVIDER                                       {fprintf(fl_output,"/  ");}
    | LESSTHAN                                      {fprintf(fl_output,"<  ");}
    | LESSOREQUAL                                   {fprintf(fl_output,">= ");}
    | BIGGERTHAN                                    {fprintf(fl_output,">  ");}
    | BIGGEROREQUAL                                 {fprintf(fl_output,">= ");}
    | EQUAL                                         {fprintf(fl_output,"== ");}
    | NOTEQUAL                                      {fprintf(fl_output,"!= ");}
    | AND                                           {fprintf(fl_output,"&& ");}
    | OR                                            {fprintf(fl_output,"|| ");}
;
unop:
    MINUS                                           {fprintf(fl_output,"-");}
    | NOT                                           {fprintf(fl_output,"!");}
;
funccall:
    ID LPARENT RPARENT                                  {fprintf(fl_output," [funccall ] \n");}
    | ID LPARENT {fprintf(fl_output,"t\t[arglist ");} arglist   {fprintf(fl_output,"\t]\n ");} RPARENT                    {fprintf(fl_output," [funccall: ID LPARENT arglist RPARENT] \n");}
;
arglist:
    expr arglistparams                                  {fprintf(fl_output," [arglist: expr \n");}
;
arglistparams:
    %empty
    | COMMA arglist
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  //printf("%d: %s at '%s'\n", yylineno, err, yytext);
  exit(1);
}
void readFromFile( argc, argv )
	int argc;
	char **argv;
{
    
	++argv, --argc;	/* skip over program name */
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
}