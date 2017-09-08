%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "./tree.h"

  int yylex(void);
  void yyerror(char const *);
  FILE *yyin;
  FILE *fl_output;
  extern int yylineno;

  struct ast *ROOT;
  struct ast *ROOT_CHILDS = NULL;
  int START_OK = 0;

  struct symbol symtab[NHASH];
%}
%union {
  int itype;
  struct ast *astNode;

  struct symbol *symbolValue;
  struct symlist *symbolList;
}

%type <astNode> start program decvar decvarassign decfunc decfuncids
%type <astNode> paramlist arglist
%type <astNode> block blockstatements assigner loop return break continue statement conditional elseconditional
%type <astNode> expr funccall unop
%token <symbolValue> ID

%token <itype> DEC

%token LET_T
%token DEF_T

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

%left AND OR
%left EQUAL
%left BIGGERTHAN LESSTHAN NOTEQUAL LESSOREQUAL BIGGEROREQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDER
%nonassoc UMINUS NOT


%start start

%%
start:
  program {
    ROOT = newast("program");
    astAddChild(ROOT, $1);

    semanticCheck(ROOT, 0, NULL, NULL);
    astPrint(ROOT, 0);
  }
;
program:
  program decvar {
    astAddChildrens(&ROOT_CHILDS, $2);
    $$ = ROOT_CHILDS;
  }
  | program decfunc {
    struct ast *instantFather = newast("decfunc");
    astAddChild(instantFather, $2);
    astAddChildrens(&ROOT_CHILDS, instantFather);
    $$ = ROOT_CHILDS;
  }
  | %empty {
    $$ = NULL;
  }
;
decvar:
  LET_T ID decvarassign SEMICOLON {
    struct ast *decvar_node = newast("decvar");

    struct ast *id_node = newref("ID", $2);
    astAddChild(decvar_node, id_node);

    if($3 != NULL){
      astAddChild(decvar_node, $3);

      $$ = decvar_node;
    }
    else{
      $$ = decvar_node;
    }
  }
;
decvarassign:
  %empty {
    $$ = NULL;
  }
  | ASSIGN  expr {
    $$ = $2;
  }
;
decfunc:
  DEF_T decfuncids {
    $$ = $2;
  }
;
decfuncids:
  ID  LPARENT  paramlist  RPARENT  block {
    struct ast *id_node = newref("ID", $1);

    struct ast *paramlist_node = newast("paramlist");
    astAddChild(paramlist_node, $3);

    astNodeBrothers(id_node, paramlist_node);
    astNodeBrothers(id_node, $5);

    $$ = id_node;
  }
  | ID  LPARENT RPARENT  block {
    struct ast *id_node = newref("ID", $1);

    struct ast *paramlist_node = newast("paramlist");
    astNodeBrothers(id_node, paramlist_node);

    astNodeBrothers(id_node, $4);

    $$ = id_node;
  }
;
block:
  LBRACE  blockstatements RBRACE {
    struct ast *instantFather = newast("block");

    if($2 != NULL)
      astAddChild(instantFather, $2);
    $$ = instantFather;
  }
;
blockstatements:
   decvar blockstatements {
    astNodeBrothers($1, $2);
   }
   | statement {
   }
   | %empty{
    $$ = NULL;
  }
;
paramlist:
  ID {
    $$ = newref("ID", $1);
  }
  | ID COMMA paramlist {
    struct ast *brother = newref("ID", $1);
    astNodeBrothers(brother,$3);
    $$ = brother;
  }
;
statement:
  assigner SEMICOLON statement {
    astNodeBrothers($1, $3);
  }
  | funccall SEMICOLON statement {
    astNodeBrothers($1, $3);
  }
  | conditional statement {
    astNodeBrothers($1, $2);
  }
  | loop statement {
    astNodeBrothers($1, $2);
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
    struct ast *id = newref("ID", $1);
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
    struct ast *instantFather = newast("if");
    astAddChild(instantFather,$3);
    astAddChild(instantFather,$5);
    if($6 != NULL){
      astAddChild(instantFather,$6);
    }
    $$ = instantFather;
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
        $$ = newnum("DEC", $1);
    }
    | ID                                        {
        $$ = newref("ID", $1);
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
;
unop:
    MINUS                                           {
        $$ = newast("-");
    }
    | NOT                                           {
        $$ = newast("!");
    }
;
funccall:
  ID LPARENT RPARENT {
    struct ast *instantFather = newast("funccall");
    astAddChild(instantFather, newref("ID", $1));

    struct ast *argument_list = newast("arglist");
    astAddChild(instantFather, argument_list);

    $$ = instantFather;
  }
  | ID LPARENT arglist RPARENT {
    struct ast *instantFather = newast("funccall");

    astAddChild(instantFather, newref("ID", $1));

    struct ast *argument_list = newast("arglist");
    astAddChild(argument_list, $3);

    astAddChild(instantFather, argument_list);

    $$ = instantFather;
  }
;
arglist:
  expr {
    struct ast *instantFather = newast("ARG");

    astAddChild(instantFather, $1);
    $$ = instantFather;
  }
  | expr COMMA arglist {
    struct ast *instantFather = newast("ARG");

    astAddChild(instantFather, $1);

    astNodeBrothers(instantFather, $3);
    $$ = instantFather;
  }
;
%%

void yyerror(char const *err){
  printf("[PARSER] Error na linha %d.\nMensagem: %s\n", yylineno, err);
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
    exit(0);
  }

  strcpy(no->nodetype,nodetype);
  no->childrens = NULL;
  no->nextBrother = NULL;
  no->previousBrother = NULL;

  return (struct ast *)no;
}
void astAddChild(struct ast *father, struct ast *child){
  struct ast *walkNode;
  if(father->childrens == NULL){
    father->childrens = child;
  }else{
    for(walkNode = father->childrens; walkNode->nextBrother != NULL; walkNode = walkNode->nextBrother);

    walkNode->nextBrother = child;
    child->previousBrother = walkNode;
  }
}
void astNumAddChild(struct ast *father, struct ast *child){
  struct ast *walkNode;
  if(father->childrens == NULL){
    father->childrens = child;
  }else{
    for(walkNode = father->childrens; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);

    walkNode->nextBrother = child;
    child->previousBrother = walkNode;
  }
}
struct ast *newnum(char nodetype[MAX_NODE_TYPE], int number){
  struct ast *no = (struct ast *)malloc(sizeof(struct ast));
  if(!no) {
    //yyerror("out of space");
    exit(0);
  }

  strcpy(no->nodetype,nodetype);
  no->dec.number = number;

  no->childrens = NULL;
  no->nextBrother = NULL;
  no->previousBrother = NULL;

  return (struct ast *)no;
}
struct ast *newref(char nodetype[MAX_NODE_TYPE], struct symbol *name){
  struct ast *no = (struct ast *)malloc(sizeof(struct ast));
  if(!no) {
    yyerror("out of space");
    exit(0);
  }

  strcpy(no->nodetype,nodetype);
  no->identification = name;
  no->childrens = NULL;
  no->nextBrother = NULL;
  no->previousBrother = NULL;

  return (struct ast *)no;
}
void astPrint(struct ast *father, int tab){
  struct ast *walker;

  for(walker = father; walker != NULL; walker = walker->nextBrother){
    for(int i = 0; i < tab; i++){
      fprintf(fl_output,"\t");
    }
    if(strcmp(walker->nodetype,"DEC") == 0){
      fprintf(fl_output,"[%d \n", walker->dec.number);
    } else if(strcmp(walker->nodetype,"ID") == 0){
      char *name = walker->identification->name;
      fprintf(fl_output,"[%s \n", name);
    } else {
      fprintf(fl_output,"[%s \n", walker->nodetype);
    }
    if(walker->childrens != NULL)
      astPrint(walker->childrens,tab+1);
    for(int i = 0; i < tab; i++){
      fprintf(fl_output,"\t");
    }
    fprintf(fl_output,"]\n");
  }
}
void astAddChildrens(struct ast **head_list, struct ast *newBrother){
  struct ast *walkNode;
  if(*head_list != NULL){
    for(walkNode = *head_list; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
    walkNode->nextBrother = newBrother;
    newBrother->previousBrother = walkNode;
  }
  else{
    *head_list = newBrother;
  }
}
void astNodeBrothers(struct ast *leftBrother, struct ast *rightBrother){
  struct ast *walkNode;
  if(rightBrother != NULL){
    for(walkNode = leftBrother; walkNode != NULL && walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
    walkNode->nextBrother = rightBrother;
    rightBrother->previousBrother = walkNode;
  }
}
static unsigned symhash(char *sym){
  unsigned int hash = 0;
  unsigned c;
  while(c = *sym++) hash = hash*9 ^ c;

  return hash;
}
struct symbol *lookup(char* sym) {
  struct symbol *sp = &symtab[symhash(sym)%NHASH];
  int scount = NHASH;

  while(--scount >= 0) {
    if(sp->name && !strcmp(sp->name, sym)) { return sp; }
    if(!sp->name) {
      sp->name = strdup(sym);
      sp->value = 0;
      sp->func = NULL;
      sp->syms = NULL;
      return sp;
    }
    if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
  }
}
struct vardeclaration *symStackPush(struct vardeclaration *var_stack, struct vardeclaration *var_node){
  var_node->next = var_stack;
  return var_node;
}
int onVarStack(struct vardeclaration *top_stack, struct symbol *sym){
  struct vardeclaration *walkerStack;

  for(walkerStack = top_stack; walkerStack != NULL && (strcmp(walkerStack->sym->name, sym->name) != 0); walkerStack = walkerStack->next);
  if(walkerStack != NULL && (strcmp(walkerStack->sym->name, sym->name) == 0)){
    return 0;
  }
  return 1;
}
void reservedWords(struct symbol *sym){
  if(strcmp("print", sym->name) == 0){
    exit(0);
  }
  if(strcmp("main", sym->name) == 0){
    START_OK = 1;
  }
}
void semanticCheck(struct ast *father, int nivel, struct vardeclaration *var_stack, struct vardeclaration *func_stack){
  struct ast *walkerAST;
  for(walkerAST = father; walkerAST != NULL; walkerAST = walkerAST->nextBrother){
    struct vardeclaration *var_node = (struct vardeclaration *)malloc(sizeof(struct vardeclaration));

    if(strcmp(walkerAST->nodetype,"decvar") == 0){
      if(walkerAST->childrens->nextBrother != NULL){
        semanticCheck(walkerAST->childrens->nextBrother, nivel+1, var_stack, func_stack);
      }
      var_node->sym = walkerAST->childrens->identification;
      var_node->nivel = nivel;

      var_stack = symStackPush(var_stack, var_node);
      //printf("\n[Semantico] add VAR: %s", var_node->sym->name);
    } else if(strcmp(walkerAST->nodetype,"decfunc") == 0){
      struct ast *walkChild = walkerAST->childrens;

      reservedWords(walkChild->identification);
      if(onVarStack(func_stack, walkChild->identification) == 0){
        exit(0);
      }

      var_node->sym = walkChild->identification;
      var_node->nivel = nivel;
      func_stack = symStackPush(func_stack, var_node);

      walkChild = walkChild->nextBrother;

      for(struct ast *params_node = walkChild->childrens; params_node != NULL; params_node = params_node->nextBrother){
        var_node = (struct vardeclaration *)malloc(sizeof(struct vardeclaration));

        var_node->sym = walkChild->identification;
        var_node->nivel = nivel;

        var_stack = symStackPush(var_stack, var_node);
      }
    }else if(strcmp(walkerAST->nodetype,"funccall") == 0){
      if(onVarStack(func_stack, walkerAST->childrens->identification) == 0){
        //printf("\n[Semantico] %s: Na Pilha", walkerAST->identification->name);
      } else {
        exit(0);
      }
    } else if(strcmp(walkerAST->nodetype,"ID") == 0){
      if(onVarStack(var_stack, walkerAST->identification) == 0){
        //printf("\n[Semantico] %s: Na Pilha", walkerAST->identification->name);
      } else {
        exit(0);
      }
    } else{
      semanticCheck(walkerAST->childrens, nivel+1, var_stack, func_stack);
    }
  }
}
