 program EMPTY] 
	 [decvar LET_T ID SEMICOLON 
 [program decvar 
	 [paramlist ID 
	 expr ID] 
	 expr ID] 
	 expr ID] 
	 arglist expr] 
	 arglist expr COMMA arglist] 
	 arglist expr COMMA arglist] 
	 funccall ID LPARENT arglist RPARENT] 
	 expr funccall] 
	 [decvar LET_T ID ASSIGN expr SEMICOLON 
	 statement EMPTY] 
	 [block LBRACE decvar statement RBRACE 
	 [decfunc EF_T MAIN_T LPARENT paramlist RPARENT block 
 [program decfunc 
	 [paramlist ID 
	 [paramlist ID COMMA paramlist 
	 [paramlist ID COMMA paramlist 
	 expr ID] 
	 expr DEC] 
	 expr expr binop expr] 
	 [decvar LET_T ID ASSIGN expr SEMICOLON 
	 statement EMPTY] 
	 [block LBRACE decvar statement RBRACE 
	 [decfunc DEF_T ID LPARENT paramlist RPARENT block 
 [program decfunc 
[start 
Eh Valida
Total de linhas: 8
