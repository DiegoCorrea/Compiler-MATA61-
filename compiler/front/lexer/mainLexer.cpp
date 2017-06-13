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
        fprintf(fl_output,"KEY \"%s\" %d\n", yytext, yylineno);
      break;
      case DEC:
        fprintf(fl_output,"DEC \"%s\" %d\n", yytext, yylineno);
      break;
      case SYM:
        fprintf(fl_output,"SYM \"%s\" %d\n", yytext, yylineno);
      break;
      case ID:
        fprintf(fl_output,"ID \"%s\" %d\n", yytext, yylineno);
      break;
      case ERROR:
        fprintf(fl_output,"SAINDO------------------\n");
        exit(1);
      break;
    }
    ntoken = yylex();
  }
  fclose( fl_output );
  return 0;
}