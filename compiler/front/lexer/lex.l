%option noyywrap
%{
	#include <stdio.h>
	#include "grammar.tab.h"
	#include "tokens.h"
%}

letter				[a-zA-Z]
number				[0-9]
id					{letter}({number}*{letter}*[_]*)*
dec					[1-9]{number}*
sym					([(]|[)]|[{]|[}]|[[]|[]]|[,]|[;]|[=]|[+]|[-]|[*]|[/]|[<]|[>]|[<=]|[>=]|[==]|[!=]|[&&]|[||]|[!])
key					(var|function|if|else|while|return|break|continue)
whitespace			[ \n\t]

%%

{key}				{ return KEY; }
{dec}				{ return DEC; }
{sym}				{ return SYM; }
{id}				{ return ID; }
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