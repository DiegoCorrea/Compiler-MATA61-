%option noyywrap
%{
  #include "gramar.tab.h"
%}

id 		[a-zA-Z][a-zA-Z]*[0-9]*[a-zA-Z]*

dec		[0-9][0-9]*
key		
sym		
whitespace [ \n\t]

%%

{id}				{ return ID; }
{whitespace}

%%