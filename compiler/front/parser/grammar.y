%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "tree.h"
  int yylex(void);
  void yyerror(char const *);
  FILE *yyin;
  FILE *fl_output;
  extern int yylineno;

  struct ast *ROOT;
%}
%union {
  int itype;
  struct ast *astNode;
}
%code requires
{
    #include "tree.h"
}

%type <astNode> start program decvar
%type <astNode> decvarassign decfunc expr funccall unop identifier
%token <astNode> ID
%token <itype> DEC

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
%left BIGGERTHAN LESSTHAN EQUAL NOTEQUAL LESSOREQUAL BIGGEROREQUAL
%nonassoc UMINUS 


%start start

%%
start: 
    {fprintf(fl_output,"[program");}        program     {
        fprintf(fl_output,"\n]"); 
        ROOT = newast("program");
        astAddChild(ROOT, $2);

        astPrint(ROOT, 0);
    }
;
program:
    decvar program                                      {
        struct ast *instantFather = newast("decvar");
        astAddChild(instantFather, $1);
    }
    | decfunc program
    | %empty {
        $$ = NULL;
    }
;
decvar:
    LET_T {fprintf(fl_output,"\n\t[decvar ");} ID decvarassign SEMICOLON          {
        struct ast *instant = newast("ID");
        if($3 != NULL){
            astAddChild($4,instant);
            $$ = $4;
        }
        else{
            $$ = instant;
        }
    }
;
identifier:
    ID {
        $$ = newast("ID");
    }
;
decvarassign:
    %empty                                  {
        fprintf(fl_output," [ID] ]");
        $$ = NULL;
    }
    | ASSIGN {fprintf(fl_output,"[assign [ID]");} expr {
        fprintf(fl_output," ]");
        struct ast *instantFather = newast("=");
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
;
decfunc:
    DEF_T {fprintf(fl_output,"\n\t[decfunc \n");} decfuncids
;
decfuncids:
    MAIN_T {fprintf(fl_output,"\t\t[main]");} LPARENT {fprintf(fl_output,"\t\t[Paramlist ");} paramlist {fprintf(fl_output," ] \n");} RPARENT block 
    | ID {fprintf(fl_output,"\t\t[FUNC NAME]");} LPARENT {fprintf(fl_output,"\t\t[Paramlist ");} paramlist {fprintf(fl_output," ] \n");} RPARENT  block
;
block:
    LBRACE {fprintf(fl_output,"\t\t[block \n");} blockstatements RBRACE {fprintf(fl_output,"\t\t ] \n");}
;
blockstatements:
     decvar blockstatements
     | statement
     | %empty
;
paramlist: 
    ID                                              {fprintf(fl_output,"[ ID ] ");}
    | ID {fprintf(fl_output,"[ ID ] ");} COMMA paramlist
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
    ID ASSIGN {fprintf(fl_output,"\t\t\t\t[assign [ID] ");} expr {fprintf(fl_output," ] \n");}
    | %empty
;
conditional: 
    IF_T {fprintf(fl_output,"\t\t\t\t [if \n");} LPARENT expr RPARENT block elseconditional     {fprintf(fl_output,"\t\t\t ]\n");}
    
;
elseconditional:
    %empty
    |  ELSE_T  block 
;
loop:
    WHILE_T {fprintf(fl_output,"\t\t\t\t[while \n");} LPARENT expr RPARENT block              {fprintf(fl_output,"\t\t\t\t ]n");}
;
break:
    BREAK_T SEMICOLON                                   {fprintf(fl_output,"\t\t\t\t[break] \n");}
;
continue:
    CONTINUE_T SEMICOLON                                {fprintf(fl_output,"\t\t\t\t[continue] \n");}
;
return:
    {fprintf(fl_output,"\t\t\t[return\n\t\t\t\t");}   RETURN_T expr SEMICOLON                         {fprintf(fl_output,"\n\t\t\t]\n");}
;
expr:
    unop expr                    %prec UMINUS   {
        astAddChild($1,$2);
        $$ = $1;
    }
    | LPARENT expr RPARENT                      {
        $$ = $2;
    }
    | funccall                                  {
        $$ = $1;
    }
    | DEC                                       {
        fprintf(fl_output,"[DEC] ");
        $$ = newast("DEC");
    }
    | ID                                        {
        fprintf(fl_output,"[ID] ");
        $$ = newast("ID");
    }
    | expr PLUS expr                            {
        fprintf(fl_output,"[+ [ID] [ID]");
        struct ast *instantFather = newast("+");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr MINUS expr                           {
        fprintf(fl_output,"[- [ID] [ID]");
        struct ast *instantFather = newast("-");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr MULTIPLY expr                        {
        fprintf(fl_output,"[* [ID] [ID]");
        struct ast *instantFather = newast("*");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr DIVIDER expr                         {
        fprintf(fl_output,"[/ [ID] [ID]");
        struct ast *instantFather = newast("/");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr LESSTHAN expr                        {fprintf(fl_output,"[< [ID] [ID]");}
    | expr LESSOREQUAL expr                     {fprintf(fl_output,"[<= [ID] [ID]");}
    | expr BIGGERTHAN expr                      {fprintf(fl_output,"[> [ID] [ID]");}
    | expr BIGGEROREQUAL expr                   {fprintf(fl_output,"[>= [ID] [ID]");}
    | expr EQUAL expr                           {fprintf(fl_output,"[== [ID] [ID]");}
    | expr NOTEQUAL expr                        {fprintf(fl_output,"[!= [ID] [ID]");}
    | expr AND expr                             {fprintf(fl_output,"[&& [ID] [ID]");}
    | expr OR expr                              {fprintf(fl_output,"[|| [ID] [ID]");}
    | %empty {
        $$ = NULL;
    }
;
binop:
    PLUS                                            {fprintf(fl_output,"+ ");}
    | MINUS                                         {fprintf(fl_output,"- ");}
    | MULTIPLY                                      {fprintf(fl_output,"* ");}
    | DIVIDER                                       {fprintf(fl_output,"/  ");}
    | LESSTHAN                                      {fprintf(fl_output,"<  ");}
    | LESSOREQUAL                                   {fprintf(fl_output,"<= ");}
    | BIGGERTHAN                                    {fprintf(fl_output,">  ");}
    | BIGGEROREQUAL                                 {fprintf(fl_output,">= ");}
    | EQUAL                                         {fprintf(fl_output,"== ");}
    | NOTEQUAL                                      {fprintf(fl_output,"!= ");}
    | AND                                           {fprintf(fl_output,"&& ");}
    | OR                                            {fprintf(fl_output,"|| ");}
;
unop:
    MINUS                                           {
        fprintf(fl_output,"-");
        $$ = newast("-");
    }
    | NOT                                           {
        fprintf(fl_output,"!");
        $$ = newast("!");
    }
;
funccall:
    ID LPARENT RPARENT                              {
        fprintf(fl_output," [funccall ]\n");
        struct ast *instantFather = newast("funccall");
        $$ = instantFather;
    }
    | ID  LPARENT {fprintf(fl_output," [funccall \n\t\t\tID]\n");}{fprintf(fl_output,"\t\t\t[arglist ");} arglist   {fprintf(fl_output,"\t\t\t]\n ");} RPARENT
;
arglist:
    expr arglistparams                                  {fprintf(fl_output,"\t\t\t ]\n");}
;
arglistparams:
    %empty
    | COMMA arglist
;
%%

void yyerror(char const *err){
  printf("Error na linha %d: %s\n", yylineno, err);
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
struct ast *newast(char nodetype[MAX_NODE_TYPE]) {
    struct ast *no = (struct ast *)malloc(sizeof(struct ast));
    no->childrens = NULL;
    no->nextParent = NULL;
    no->previousParent = NULL;

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    printf("\nValor: %s\n", nodetype);
    return (struct ast *)no;
}
void astAddChild(struct ast *father, struct ast *child){
    struct ast *walkNode;
    if(father->childrens == NULL){
        father->childrens = child;
    }else{
        for(walkNode = father->childrens; walkNode->nextParent != NULL;walkNode = walkNode->nextParent);

        walkNode->nextParent = child;
        child->previousParent = walkNode;
    }
}
void astNumAddChild(struct ast *father, struct ast *child){
    struct ast *walkNode;
    if(father->childrens == NULL){
        father->childrens = child;
    }else{
        for(walkNode = father->childrens; walkNode->nextParent != NULL;walkNode = walkNode->nextParent);

        walkNode->nextParent = child;
        child->previousParent = walkNode;
    }
}

struct ast *newnum(char nodetype[MAX_NODE_TYPE], int d){
    struct numval *no = malloc(sizeof(struct numval));

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->number = d;
    return (struct ast *)no;
}

void astPrint(struct ast *father, int tab){
    struct ast *walker;

    for(walker = father; walker != NULL; walker = walker->nextParent){
        for(int i = 0; i < tab; i++)
            printf("\t");            
        printf("[%s \n", walker->nodetype);

        if(walker->childrens != NULL)
            astPrint(walker->childrens,tab+1);

        for(int i = 0; i < tab; i++)
            printf("\t");
        printf("]\n");
    }
}