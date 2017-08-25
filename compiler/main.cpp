#include <iostream>
extern "C" {
  int yyparse();
  void yyerror(const char *);
  int yylex();
  void readFromFile(int argc, char** argv);
  void codeGenerator(int argc, char** argv);
}
extern int yylineno;
extern char* yytext;
extern FILE *fl_output;

//void lexical(int argc, char** argv);
void parser(int argc, char** argv);

int main(int argc, char** argv){
  //lexical(argc, argv);
  parser(argc, argv);
  codeGenerator(argc, argv);
  return 0;
}
void parser(int argc, char** argv){
  readFromFile(argc, argv);
  fl_output = fopen(argv[2], "w+" );

  int parser_result = yyparse();
  if(parser_result == 0){
    printf("[Parser] AST Gerada\n");
  } else{
    printf("[Parser] Entrada Invalida. Geração da AST abortada!\n");
    exit
  }
  printf("[Parser] Total de linhas no arquivo: %d\n", yylineno);
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
