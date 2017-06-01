#include <iostream>

extern "C" {
  int yyparse();
  void yyerror(const char *);
  int yylex();
}

int main(){
  int result = yyparse();
  if(result == 0){
    std::cout << "Entrada valida" << std::endl;
  } else {
    std::cout << "Entrada invalida" << std::endl;
  }

  return result;
}