#include <iostream>
#include "tokens.h"
extern "C" {
  int yyparse();
  void yyerror(const char *);
  int yylex();
  void lexicalInput(int argc, char** argv);
}
extern int yylineno;
extern char* yytext;

int main(int argc, char** argv){
  int ntoken;

  lexicalInput(argc,argv);
  FILE *fl_output = fopen(argv[2], "w+" );

  ntoken = yylex();
  while(ntoken){
    switch(ntoken){
      case KEY:
        fprintf(fl_output,"KEY\t\t\"%s\"\n", yytext);
      break;
      case DEC:
        fprintf(fl_output,"DEC\t\t\"%s\"\n", yytext);
      break;
      case SYM:
        fprintf(fl_output,"SYM\t\t\"%s\"\n", yytext);
      break;
      case ID:
        fprintf(fl_output,"ID\t\t\"%s\"\n", yytext);
      break;
    }

    ntoken = yylex();
  }

  fclose( fl_output );

  return 0;
}