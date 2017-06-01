%option noyywrap
%{
	#include "grammar.tab.h"
	#include <stdio.h>
%}

letter			[a-zA-Z]
number			[0-9]
id					{letter}({number}*{letter}*)*
whitespace	[ \n\t]

%%

"function"	{ printf("FUNCTION\n"); return FUNCTION; }
"("					{ printf("(\n"); return LPARENT; }
")"					{ printf(")\n"); return RPARENT; }
"{"					{ printf("{\n"); return LEFT_BRACE; }
"}"					{ printf("}\n"); return RIGHT_BRACE; }
{id}				{ printf("ID\n"); return ID; }
{whitespace}

%%