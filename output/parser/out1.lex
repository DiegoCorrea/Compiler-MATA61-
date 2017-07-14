 program EMPTY] 
	 [decvar LET_T ID SEMICOLON 
 [program decvar 
	 paramlist EMPTY] 
	 expr DEC] 
	 expr DEC] 
	 expr expr binop expr] 
	 expr DEC] 
	 expr DEC] 
	 expr DEC] 
	 expr DEC] 
	 expr expr binop expr] 
	 expr expr binop expr] 
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
	 expr ID] 
	 expr ID] 
	 expr ID] 
	 expr ID] 
	 expr expr binop expr] 
	 expr expr binop expr] 
	 expr expr binop expr] 
	 decvar EMPTY] 
	 expr ID] 
	 arglist expr] 
	 funccall ID LPARENT arglist RPARENT] 
	 statement funccall SEMICOLON] 
	 [block LBRACE decvar statement RBRACE 
	 conditional IF_T LPARENT expr RPARENT block] 
	 statement conditional] 
	 [block LBRACE decvar statement RBRACE 
	 [decfunc DEF_T ID LPARENT paramlist RPARENT block 
 [program decfunc 
	 [paramlist ID 
	 decvar EMPTY] 
	 expr ID] 
	 expr DEC] 
	 expr expr binop expr] 
	 decvar EMPTY] 
	 statement EMPTY] 
	 [block LBRACE decvar statement RBRACE 
	 decvar EMPTY] 
	 statement EMPTY] 
	 [block LBRACE decvar statement RBRACE 
	 conditional IF_T LPARENT expr RPARENT block ELSE_T block] 
	 statement conditional] 
	 [block LBRACE decvar statement RBRACE 
	 [decfunc DEF_T ID LPARENT paramlist RPARENT block 
 [program decfunc 
[start 
Eh Valida
Total de linhas: 18
