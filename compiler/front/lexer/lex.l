%option noyywrap
%{
	#include <stdio.h>
	#include "grammar.tab.h"
%}
%option yylineno

letter      [a-zA-Z]
number      [0-9]
id          [A-Za-z][A-Za-z0-9_]*
dec         [0-9]{number}*
whitespace  [ \n\t]
comment     "//".*
error       (^{id}|^{number}|^{whitespace})

%%
{comment}	    
{whitespace}  
"let"         { return LET_T; }
"def"         { return DEF_T; }
"if"          { return IF_T; }
"else"        { return ELSE_T; }
"while"       { return WHILE_T; }
"break"       { return BREAK_T; }
"continue"    { return CONTINUE_T; }
"return"      { return RETURN_T; }
"main"        { return MAIN_T; }

"("           { return LPARENT ; }
")"           { return RPARENT ; }

"{"           { return LBRACE ; }
"}"           { return RBRACE ; }

"["           { return LBRACKETS ; }
"]"           { return RBRACKETS ; }

","           { return COMMA ; }
";"           { return SEMICOLON ; }

"+"           { return PLUS ; }
"-"           { return MINUS ; }
"*"           { return MULTIPLY ; }
"/"           { return DIVIDER ; }

"<"           { return LESSTHAN ; }
">"           { return BIGGERTHAN ; }

"<="          { return LESSOREQUAL ; }
">="          { return BIGGEROREQUAL ; }

"=="          { return EQUAL ; }
"="           { return ASSIGN ; }
"!="          { return NOTEQUAL ; }

"&&"          { return AND ; }
"||"          { return OR ; }
"!"           { return NOT ; }

{dec}         { return DEC; }
{id}          { return ID; }
.             { return ERROR; }

%%