#include <iostream>
#include "tokens.h"
extern "C" {
  int yyparse();
  void yyerror(const char *);
  int yylex();
}
extern int yylineno;
extern char* yytext;

int main(){
  int ntoken, vtoken;

  ntoken = yylex();
  while(ntoken){
    switch(ntoken){
      case KEY:
        printf("KEY\t\"%s\"\n",yytext);
      break;
      case DEC:
        printf("DEC\t\"%s\"\n",yytext);
      break;
      case SYM:
        printf("SYM\t\"%s\"\n",yytext);
      break;
      case ID:
        printf("ID\t\"%s\"\n",yytext);
      break;
    }

    ntoken = yylex();
  }
}