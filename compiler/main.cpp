#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./front/parser/tree.h"
#include "./back/codeGenerator.h"

extern "C" {
  int yylex();
  int yyparse();
  void yyerror(const char *);

  void readFromFile(int argc, char** argv);
}

extern int yylineno;
extern char* yytext;
extern FILE *fl_output;
extern struct ast *ROOT;

void front(int argc, char** argv);
void back(struct ast *ASTROOT, char** argv);

int main(int argc, char** argv){
  front(argc, argv);
  //printf("\n");
  back(ROOT, argv);
  return 0;
}

void front(int argc, char** argv){
  readFromFile(argc, argv);
  char** rArray;
  rArray = new char*[argc+1];
  for(int i=0; i < argc; i++) {
    int len = strlen(argv[i]) + 1;
    rArray[i] = new char[len];
    strcpy(rArray[i], argv[i]);
  }
  strcat(rArray[2], ".ast");
  fl_output = fopen(rArray[2], "w+" );

  int parser_result = yyparse();
  if(parser_result == 0){
    //printf("[FRONT] AST Gerada\n");
  } else{
    //printf("[FRONT] Entrada Invalida. Geração da AST abortada!\n");
  }
  //printf("[FRONT] Total de linhas no arquivo: %d\n", yylineno);
  fclose( fl_output );
}

void back(struct ast *ASTROOT, char** argv){
  if (ASTROOT != NULL) {
    //printf("[BACK]ASTROOT Com estrutura\n");
    codeGenerator(ASTROOT, argv);
  } else {
    //printf("[BACK]ASTROOT = NULL\n");
  }
}
