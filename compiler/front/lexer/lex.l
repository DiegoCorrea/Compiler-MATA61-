%option noyywrap
%{
	#include <stdio.h>
	//#include "grammar.tab.h"
	#include "tokens.h"
%}
%option yylineno

letter      [a-zA-Z]
number      [0-9]
id          {letter}({number}*{letter}*[_]*)*
dec         [1-9]{number}*
sym         ([(]|[)]|[{]|[}]|[[]|[]]|[,]|[;]|[=]|[+]|[-]|[*]|[/]|[<]|[>]|[<=]|[>=]|[==]|[!=]|[&&]|[||]|[!])
key         (let|def|if|else|while|return|break|continue)
whitespace  [ \n\t]
comment     "//".*
error       (^key|^sym|^id|^number|^whitespace)

%%

{key}       { return KEY; }
{dec}       { return DEC; }
{error}     { return ERROR; } 
{sym}       { return SYM; }
{id}        { return ID; }
{comment}
{whitespace}


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