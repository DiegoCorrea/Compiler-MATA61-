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

void lexinal(int argc, char** argv);
void parser();

int main(int argc, char** argv){
  parser();
  return 0;
}

void lexinal(int argc, char** argv){
  int ntoken;

  lexicalInput(argc,argv);
  FILE *fl_output = fopen(argv[2], "w+" );

  ntoken = yylex();
  while(ntoken){
    switch(ntoken){
      case KEY:
        fprintf(fl_output,"KEY\t\"%s\"\t%d\n", yytext, yylineno);
      break;
      case DEC:
        fprintf(fl_output,"DEC\t\"%s\"\t%d\n", yytext, yylineno);
      break;
      case SYM:
        fprintf(fl_output,"SYM\t\"%s\"\t%d\n", yytext, yylineno);
      break;
      case ID:
        fprintf(fl_output,"ID\t\"%s\"\t%d\n", yytext, yylineno);
      break;
      case DEFFUNC:
        fprintf(fl_output,"DEFFUNC\t\"%s\"\t%d\n", yytext, yylineno);
      break;
      case ERROR:
        fprintf(fl_output,"ERROR\t\"%s\"\t%d\n", yytext, yylineno);
        fclose( fl_output );
        exit(1);
      break;
    }
    ntoken = yylex();
  }
  fclose( fl_output );
}