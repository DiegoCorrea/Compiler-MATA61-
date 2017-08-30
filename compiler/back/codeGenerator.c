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

  if (ASTROOT != NULL) {
    printf("[CODE GEN]ASTROOT Com estrutura\n");
    astPrintBack(ASTROOT,0);

    printf("\n\n--[Code Gen Start]\n\n");
    codeGen(ASTROOT);
  } else {
    printf("[CODE GEN]ASTROOT = NULL\n");
  }
  fclose( MIPS_FILE );
}
void codeGen(struct ast *ASTROOT){
  printf(".globl __start\n");
  fprintf(MIPS_FILE, ".globl __start\n");
  printf(".data \n");
  fprintf(MIPS_FILE, ".data \n");

  codeGenGlobalVariables(ASTROOT->childrens);

  printf(".text\n");
  fprintf(MIPS_FILE, ".text\n");
  //codeGenFunction(ASTROOT);
  codeGenStartMips(ASTROOT);
}
void codeGenStartMips(struct ast *ASTROOT){
  printf("\n__start:\n");
  fprintf(MIPS_FILE, "\n__start:\n");

  printf("  sw $fp, 0($sp)\n");
  fprintf(MIPS_FILE, "  sw $fp, 0($sp)\n");

  printf("  addiu $sp, $sp, -4\n");
  //fprintf(MIPS_FILE, "  jal _f_main\n");

  printf("  li $v0, 10\n");
  fprintf(MIPS_FILE, "  li $v0, 10\n");

  printf("  syscall\n");
  fprintf(MIPS_FILE, "  syscall\n");
}
void codeGenGlobalVariables(struct ast *ASTROOT){
  for(struct ast *walker = ASTROOT; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"decvar") == 0) {

      codeGenSingleGlobalVariable(walker->childrens);
    }
  }
}
void codeGenSingleGlobalVariable(struct ast *variable) {
  char *name = variable->identification->name;
  if (variable->nextBrother != NULL) {
    printf("  %s: \t .word \t %d \n", name,variable->dec.number);
    fprintf(MIPS_FILE, "  %s: \t .word \t %d \n", variable->identification->name,variable->dec.number);
  } else {
    printf("  %s: \t .word \n", variable->identification->name);
    fprintf(MIPS_FILE, "  %s: \t .word \n", variable->identification->name);
  }

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
