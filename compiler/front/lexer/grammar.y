%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  void yyerror(char const *);
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
            program            
;
program:
    decvar program
    | decfunc program
    | %empty
;
decvar:
    LET_T ID decvarassign SEMICOLON          
;
decvarassign:
    %empty
    | ASSIGN expr                                   
;
decfunc:
    DEF_T  decfuncids
;
decfuncids:
    MAIN_T  LPARENT  paramlist  RPARENT block 
    | ID  LPARENT  paramlist  RPARENT  block 
;
block:
    LBRACE  blockstatements RBRACE                  
;
blockstatements:
     decvar blockstatements
     | statement
     | %empty
;
paramlist: 
    ID                                              
    | ID COMMA  paramlist
    | %empty
;
statement:
    assigner  SEMICOLON statement                    
    | funccall  SEMICOLON statement                  
    | conditional statement                             
    | loop statement                                    
    | return
    | break
    | continue
    | %empty
;
assigner:
    ID ASSIGN expr                                      
    | %empty
;
conditional:
    IF_T LPARENT expr RPARENT block ELSE_T block        
    | IF_T LPARENT expr RPARENT block                   
    
;
loop:
    WHILE_T  LPARENT expr RPARENT block              
;
break:
    BREAK_T SEMICOLON                                   
;
continue:
    CONTINUE_T SEMICOLON                                
;
return:
       RETURN_T expr SEMICOLON                         
;
expr:
    unop expr                    %prec UMINUS       
    | LPARENT expr RPARENT
    | funccall
    | DEC                                           
    | ID                                            
    | expr PLUS expr                              
    | expr MINUS expr                           
    | expr MULTIPLY expr                        
    | expr DIVIDER expr                         
    | expr LESSTHAN expr                        
    | expr LESSOREQUAL expr                     
    | expr BIGGERTHAN expr                      
    | expr BIGGEROREQUAL expr                   
    | expr EQUAL expr                           
    | expr NOTEQUAL expr                        
    | expr AND expr                             
    | expr OR expr                              
    | %empty
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
funccall:
    ID LPARENT RPARENT                                  
    | ID LPARENT  arglist    RPARENT                    
;
arglist:
    expr arglistparams                                  
;
arglistparams:
    %empty
    | COMMA arglist
;
%%

void yyerror(char const *err){
  printf("Error: %s\n", err);
  exit(1);
}