#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "./codeGenerator.h"
FILE *MIPS_FILE;

void astPrintBack(struct ast *ASTROOT, int tab){
  struct ast *walker;

  for(walker = ASTROOT; walker != NULL; walker = walker->nextBrother){
    for(int i = 0; i < tab; i++){
      printf("\t");
    }
    if(strcmp(walker->nodetype,"DEC") == 0){
      printf("[%d \n", walker->dec.number);
    } else if(strcmp(walker->nodetype,"ID") == 0){
      char *name = walker->identification->name;
      printf("[%s \n", name);
    } else{
      printf("[%s \n", walker->nodetype);
    }
    if(walker->childrens != NULL)
      astPrintBack(walker->childrens,tab+1);

    for(int i = 0; i < tab; i++){
      printf("\t");
    }
    printf("]\n");
  }
}
//////////////////////////////////////////////////////
void codeGenerator(struct ast *ASTROOT, char** argv){
  MIPS_FILE = fopen(argv[2], "w+" );
  fprintf(MIPS_FILE, ".globl __start\n");

  if (ASTROOT != NULL) {
    printf("[CODE GEN]ASTROOT Com estrutura\n");
    astPrintBack(ASTROOT,0);

    codeGen(ASTROOT);
  } else {
    printf("[CODE GEN]ASTROOT = NULL\n");
  }
  fclose( MIPS_FILE );
}
void codeGen(struct ast *ASTROOT){
  fprintf(MIPS_FILE, ".data \n");
  codeGenGlobalVariables(ASTROOT);
  fprintf(MIPS_FILE, ".text\n");
  codeGenFunction(ASTROOT);
  codeGenStartMips(ASTROOT);
}
void codeGenStartMips(struct ast *ASTROOT){
  fprintf(MIPS_FILE, "\n__start:\n");
  codeGenPushFunction(ASTROOT);
}
void codeGenGlobalVariables(struct ast *ASTROOT){
  char const *tmp = "Nada";
  codeGenSingleGlobalVariable(tmp);
  tmp = "Dupla";
  codeGenSingleGlobalVariable(tmp);
  tmp = "Mais";
  codeGenSingleGlobalVariable(tmp);
}
void codeGenSingleGlobalVariable(char const *varName) {
  fprintf(MIPS_FILE, "  %s:\t.word\t1\n", varName);
}
void codeGenPrintIntegerOnScreen() {
  fprintf(MIPS_FILE, "  li $v0, 1\n");
  fprintf(MIPS_FILE, "  syscall\n");
}
void codeGenPushFunction(struct ast *ASTROOT){
  fprintf(MIPS_FILE, "  move $fp, $sp\n");
  fprintf(MIPS_FILE, "  sw $ra, 0($sp)\n");
  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4\n");
}
void codeGenSum(){
  fprintf(MIPS_FILE, "  lw	$a0, 0($sp)\n");
  fprintf(MIPS_FILE, "  lw	$t0, 4($sp)\n");
  fprintf(MIPS_FILE, "  addi	$sp, $sp, -4\n");
}
void codeGenFunction(struct ast *ASTROOT){
  codeGenPushFunction(ASTROOT);
  codeGenFunctionLoadParameters();
  codeGenFunctionBlock();
  codeGenPopFunction();
}
void codeGenFunctionBlock(){

}
void codeGenFunctionLoadParameters(){

}
void codeGenPopFunction(){
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 4\n");
  fprintf(MIPS_FILE, "  jr $ra\n");
}
