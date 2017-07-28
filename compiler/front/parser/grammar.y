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
  struct ast *ROOT_CHILDS = NULL;
%}
%union {
  int itype;
  struct ast *astNode;
}
%code requires
{
    #include "tree.h"
}

%type <astNode> start program decvar decvarassign
%type <astNode> decfunc decfuncids paramlist arglist arglistparams
%type <astNode> block blockstatements assigner loop return break continue statement elseconditional
%type <astNode> expr funccall unop identifier
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
    program {
        ROOT = newast("program");
        astAddChild(ROOT, $1);

        astPrint(ROOT, 0);
    }
;
program:
    program decvar {
        struct ast *instantFather = newast("decvar");
        astAddChild(instantFather, $2);
        astAddChildrens(&ROOT_CHILDS, instantFather);
        $$ = ROOT_CHILDS;
    }
    |program decfunc 
    | %empty {
        $$ = NULL;
    }
;
decvar:
    LET_T ID decvarassign SEMICOLON {
        struct ast *id = newast("ID");
        if($3 != NULL){
            struct ast *assign = newast("assign");
            astAddChild(assign,id);
            astAddChild(assign,$3);
            $$ = assign;
        }
        else{
            $$ = id;
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
        $$ = NULL;
    }
    | ASSIGN  expr {
        $$ = $2;
    }
;
decfunc:
    DEF_T  decfuncids {
        struct ast *decfunc = newast("decfunc");
        decfunc->childrens = $2;
        $$ = decfunc;
    }
;
decfuncids:
    MAIN_T  LPARENT  paramlist  RPARENT block {
        struct ast *main = newast("main");
        if($3 != NULL) {
            struct ast *assign = newast("paramlist");
            astAddChild(assign,main);
            astAddChild(assign,$3);
            $$ = assign;
        } else {
            $$ = main;
        }
    }
    | ID  LPARENT  paramlist  RPARENT  block {

    }
;
block:
    LBRACE  blockstatements RBRACE {

    }
;
blockstatements:
     decvar blockstatements {

     }
     | statement {

     }
     | %empty{
        $$ = NULL;
    }
;
paramlist: 
    ID {
        $$ = newast("ID");
    }
    | ID COMMA paramlist {
        astBrothers(newast("ID"),$3);
        $$ = $1;
    }
    | %empty{
        $$ = NULL;
    }
;
statement:
    assigner SEMICOLON statement {

    }
    | funccall SEMICOLON statement {

    }
    | conditional statement {

    }
    | loop statement {

    }
    | return
    | break
    | continue
    | %empty{
        $$ = NULL;
    }
;
assigner:
    ID ASSIGN  expr {
        struct ast *id = newast("ID");
        if($3 != NULL){
            struct ast *assign = newast("assign");
            astAddChild(assign,id);
            astAddChild(assign,$3);
            $$ = assign;
        }
        else{
            $$ = id;
        }
    }
    | %empty{
        $$ = NULL;
    }
;
conditional: 
    IF_T LPARENT expr RPARENT block elseconditional {
    }
;
elseconditional:
    %empty {
        $$ = NULL;
    }
    | ELSE_T block {
        $$ = $2;
    }
;
loop:
    WHILE_T  LPARENT expr RPARENT block{
        struct ast *instantFather = newast("while");
        astAddChild(instantFather,$3);
        astAddChild(instantFather,$5);
        $$ = instantFather;
    }
;
break:
    BREAK_T SEMICOLON {
        struct ast *instantFather = newast("break");
        $$ = instantFather;
    }
;
continue:
    CONTINUE_T SEMICOLON {
        struct ast *instantFather = newast("continue");
        $$ = instantFather;
    }
;
return:
     RETURN_T expr SEMICOLON {
        struct ast *instantFather = newast("return");
        astAddChild(instantFather,$2);
        $$ = instantFather;
    }
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
        $$ = newast("DEC");
    }
    | ID                                        {
        $$ = newast("ID");
    }
    | expr PLUS expr                            {
        struct ast *instantFather = newast("+");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr MINUS expr                           {
        struct ast *instantFather = newast("-");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr MULTIPLY expr                        {
        struct ast *instantFather = newast("*");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr DIVIDER expr                         {
        struct ast *instantFather = newast("/");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr LESSTHAN expr {
        struct ast *instantFather = newast("<");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr LESSOREQUAL expr {
        struct ast *instantFather = newast("<=");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr BIGGERTHAN expr {
        struct ast *instantFather = newast(">");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr BIGGEROREQUAL expr {
        struct ast *instantFather = newast(">=");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr EQUAL expr {
        struct ast *instantFather = newast("==");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr NOTEQUAL expr {
        struct ast *instantFather = newast("!=");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr AND expr {
        struct ast *instantFather = newast("&&");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | expr OR expr {
        struct ast *instantFather = newast("||");
        astAddChild(instantFather,$1);
        astAddChild(instantFather,$3);
        $$ = instantFather;
    }
    | %empty {
        $$ = NULL;
    }
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
    ID LPARENT RPARENT {
        struct ast *instantFather = newast("funccall");
        astAddChild(instantFather, newast("ID"));
        $$ = instantFather;
    }
    | ID LPARENT arglist RPARENT {
        struct ast *instantFather = newast("funccall");
        astAddChild(instantFather, newast("ID"));
        astAddChild(instantFather, $3);
        $$ = instantFather;
    }
;
arglist:
    expr {
        struct ast *instantFather = newast("arglist");
        astAddChild(instantFather, $1);
        astAddChild(instantFather, $2);
        $$ = instantFather;
    }
    expr COMMA arglist {
        struct ast *instantFather = newast("arglist");
        astAddChild(instantFather, $1);
        astAddChild(instantFather, $2);
        $$ = instantFather;
    }
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
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    
    strcpy(no->nodetype,nodetype);
    no->childrens = NULL;
    no->nextParent = NULL;
    no->previousParent = NULL;

    return (struct ast *)no;
}
void astAddChild(struct ast *father, struct ast *child){
    struct ast *walkNode;
    if(father->childrens == NULL){
        father->childrens = child;
    }else{
        for(walkNode = father->childrens; walkNode->nextParent != NULL; walkNode = walkNode->nextParent);

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
void astAddChildrens(struct ast **head_list, struct ast *newBrother){
    struct ast *walkNode;
    if(*head_list != NULL){
        for(walkNode = *head_list; walkNode->nextParent != NULL;walkNode = walkNode->nextParent);
        walkNode->nextParent = newBrother;
    }
    else{
        *head_list = newBrother;
    }
}
void astBrothers(struct ast *leftBrother, struct ast *rightBrother){
    leftBrother->nextParent = rightBrother;
    rightBrother->previousParent = leftBrother;
}