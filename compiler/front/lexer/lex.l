%option noyywrap
%{
	#include <stdio.h>
	//#include "grammar.tab.h"
	#include "tokens.h"
%}
%option yylineno

letter      [a-zA-Z]
number      [0-9]
id          [A-Za-z][A-Za-z0-9_]*
dec         [0-9]{number}*
sym         ([(]|[)]|[{]|[}]|[[]|[]]|[,]|[;]|[=]|[+]|[-]|[*]|[/]|[<]|[>]|<=|>=|==|!=|&&|"||"|[!])
key         (let|if|else|while|return|break|continue)
whitespace  [ \n\t]
comment     "//".*
error       (^{key}|^{sym}|^{id}|^{number}|^{whitespace})

%%

"def"         { return DEFFUNC; }
{key}         { return KEY; }
{dec}         { return DEC; }
{sym}         { return SYM; }
{id}          { return ID; }
{error}       { return ERROR; } 
{comment}	    
{whitespace}  
.             { return ERROR;}

%%
lexicalInput( argc, argv )
	int argc;
	char **argv;
{
	++argv, --argc;	/* skip over program name */
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
}