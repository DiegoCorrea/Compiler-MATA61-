#include <iostream>
//#include "tokens.h"
extern "C" {
  int yyparse();
  void yyerror(const char *);
  int yylex();
  //void lexicalInput(int argc, char** argv);
  void readFromFile(int argc, char** argv);
}
extern int yylineno;
extern char* yytext;
extern FILE *fl_output;

void lexical(int argc, char** argv);
void parser(int argc, char** argv);

int main(int argc, char** argv){
  //lexical(argc, argv);
  parser(argc, argv);
  return 0;
}
void parser(int argc, char** argv){
  readFromFile(argc, argv);
  fl_output = fopen(argv[2], "w+" );

  int parser_result = yyparse();
  if(parser_result == 0){
    printf("Eh Valida\n");
  } else{
    printf("Invalida!\n");
  }
  printf("Total de linhas: %d\n", yylineno);
  fclose( fl_output );
}

/*
void lexical(int argc, char** argv){
  int ntoken;

  lexicalInput(argc,argv);
  FILE *fl_output = fopen(argv[2], "w+" );

  ntoken = yylex();
  while(ntoken){
    //if(ntoken != ERROR){
      fprintf(fl_output,"Token:\t\"%s\"\t%d\t%d\n", yytext, ntoken, yylineno);
   // } else{
      fprintf(fl_output,"ERROR\t\"%s\"\t%d\n", yytext, yylineno);
      fclose( fl_output );
      exit(1);
   // }
    ntoken = yylex();
  }
  fclose( fl_output );
}
*/
