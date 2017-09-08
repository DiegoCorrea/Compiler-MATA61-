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

  codeGenStartMips(ASTROOT);

  codeGenFunctions(ASTROOT->childrens);

}
void codeGenStartMips(struct ast *ASTROOT){
  printf("\n__start:\n");
  fprintf(MIPS_FILE, "\n__start:\n");

  printf("  move $fp, $sp \t\t#Start Mips\n");
  fprintf(MIPS_FILE, "  move $fp, $sp \t\t#Start Mips\n");

  printf("  addiu $sp, $sp, -4 \t\t#Start Mips\n");
  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Start Mips\n");

  fprintf(MIPS_FILE, "  jal _func_main \t\t#Start Mips\n");

  printf("  li $v0, 10 \t\t#Start Mips\n");
  fprintf(MIPS_FILE, "  li $v0, 10 \t\t#Start Mips\n");

  printf("  syscall \t\t#Start Mips\n");
  fprintf(MIPS_FILE, "  syscall \t\t#Start Mips\n");
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
    printf("  %s: \t .word \t %d \n", name,variable->nextBrother->dec.number);
    fprintf(MIPS_FILE, "  %s: \t .word \t %d \n", name,variable->nextBrother->dec.number);
  } else {
    printf("  %s: \t .word \n", name);
    fprintf(MIPS_FILE, "  %s: \t .word \n", name);
  }

}
////////////////////////////////////////////////////////////////

void codeGenFunctions(struct ast *ASTROOT){
  for(struct ast *walker = ASTROOT; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"decfunc") == 0) {
      struct ast *id = walker->childrens,
       *paramsTree = walker->childrens->nextBrother,
       *blockTree = walker->childrens->nextBrother->nextBrother;

      struct registerStack *blockStack = newVariableOnStack(NULL, 0, 'b');
      codeGenFunctionCreateLabel(id);
      blockStack = codeGenFunctionActivationRecord(paramsTree->childrens, blockStack);
      blockStack = codeGenFunctionBlock(blockTree, blockStack);
      codeGenPopFunction();
      //prinStack(blockStack);
    }
  }
  codeGenPrintFunction();
}
void codeGenFunctionCreateLabel(struct ast *func){
  printf("\n_func_%s: \t\t#Create Label\n", func->identification->name);
  fprintf(MIPS_FILE, "\n_func_%s: \t\t#Create Label\n", func->identification->name);
}
struct registerStack *codeGenFunctionActivationRecord(struct ast *PARAMS, struct registerStack *blockStack){
  printf("  sw $fp, 0($sp) \t\t#Activation Record\n");
  fprintf(MIPS_FILE, "  sw $fp, 0($sp) \t\t#Activation Record\n");

  printf("  move $fp, $sp \t\t#Activation Record\n");
  fprintf(MIPS_FILE, "  move $fp, $sp \t\t#Activation Record\n");

  printf("  addiu $sp, $sp, -4 \t\t#Activation Record\n");
  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Activation Record\n");

  blockStack = codeGenFunctionLoadParameters(PARAMS, blockStack);

  printf("  sw $ra, 0($sp) \t\t#Activation Record\n");
  fprintf(MIPS_FILE, "  sw $ra, 0($sp) \t\t#Activation Record\n");

  printf("  move $fp, $sp \t\t#Activation Record\n");
  fprintf(MIPS_FILE, "  move $fp, $sp \t\t#Activation Record\n");

  printf("  addiu $sp, $sp, -4 \t\t#Activation Record\n");
  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Activation Record\n");

  return blockStack;
}
struct registerStack *codeGenFunctionLoadParameters(struct ast *PARAMS, struct registerStack *blockStack){
  if (PARAMS != NULL) {
    struct ast *walker;
    int offset = 4;
    for(walker = PARAMS; walker->nextBrother != NULL; walker = walker->nextBrother, offset+=4);

    for(; walker != NULL; walker = walker->previousBrother){

      blockStack = varStackPush(blockStack, newVariableOnStack(walker->identification, offset, 'f'));

      printf("  sw %d($fp), 0($sp)\n", offset);
      fprintf(MIPS_FILE, "  lw $a0, %d($fp)\n", offset);
      fprintf(MIPS_FILE, "  sw $a0, 0($sp)\n", offset);

      printf("  addiu $sp, $sp, -4\n");
      fprintf(MIPS_FILE, "  addiu $sp, $sp, -4\n");

      offset -= 4;
    }
  }
  return blockStack;
}
///////////////////// Block ////////////////////////////
struct registerStack *codeGenFunctionBlockVariable(struct ast *ASTBLOCK, struct registerStack *blockStack){
  int offset = 0;

  for(struct ast *walker = ASTBLOCK; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"decvar") == 0) {
      struct ast *declaration = walker->childrens;
      struct registerStack *variable = varStackPush(blockStack, newVariableOnStack(declaration->identification, offset, 's'));

      if (declaration->nextBrother != NULL) {
        codeGenExpr(declaration->nextBrother, blockStack);
      } else {
        printf("  addiu $sp, $sp, -4 \t\t#codeGenFunctionBlockVariable\n");
        fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#codeGenFunctionBlockVariable\n");
      }

      offset += 4;
    }
  }
}
struct registerStack *codeGenFunctionBlockStatements(struct ast *ASTBLOCK, struct registerStack *blockStack ){
  for(struct ast *walker = ASTBLOCK; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"funccall") == 0) {
      struct ast *funccall = walker->childrens;
      for (struct ast *arg = funccall->nextBrother->childrens; arg != NULL; arg = arg->nextBrother) {

        codeGenExpr(arg, blockStack);
      }
      fprintf(MIPS_FILE, "  jal _func_%s\n",funccall->identification->name);
    }
  }
}
struct registerStack *codeGenFunctionBlock(struct ast *ASTBLOCK, struct registerStack *blockStack){
  codeGenFunctionBlockVariable(ASTBLOCK->childrens, blockStack);
  codeGenFunctionBlockStatements(ASTBLOCK->childrens, blockStack);
}
////////////////// Fim do Block ///////////////////////
void codeGenPopFunction(){
  fprintf(MIPS_FILE, "  move $sp, $fp \t\t#POP Function\n");
  fprintf(MIPS_FILE, "  lw $ra, 0($sp) \t\t#POP Function\n");

  fprintf(MIPS_FILE, "  addiu $sp, $sp, 4 \t\t#POP Function\n");

  fprintf(MIPS_FILE, "  lw $fp, 0($sp) \t\t#POP Function\n");
  fprintf(MIPS_FILE, "  jr $ra \t\t#POP Function\n");
}
void codeGenPrintFunction() {
  fprintf(MIPS_FILE, "\n_func_print:\n");
  printf("\n_func_print:\n");
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp)\n");
  fprintf(MIPS_FILE, "  li $v0, 1\n");
  printf("  li $v0, 1\n");
  fprintf(MIPS_FILE, "  syscall\n");
  printf("  syscall\n");

  fprintf(MIPS_FILE, "  li $v0, 11\n");
  fprintf(MIPS_FILE, "  li $a0, 0x0a\n");
  fprintf(MIPS_FILE, "  syscall\n");

  fprintf(MIPS_FILE, "  addiu $sp, $sp, 4\n");
  fprintf(MIPS_FILE, "  lw $fp, 4($sp)\n");
  fprintf(MIPS_FILE, "  addiu $sp, $sp, 4\n");

  printf("  jr $ra\n");
  fprintf(MIPS_FILE, "  jr $ra\n");
}
////////////////////////////////////////////////////////
/*              Expressions             */
void codeGenSum(){
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp) \t\t\t#codeGen [SUM]\n");
  fprintf(MIPS_FILE, "  lw	$t0, 8($sp) \t\t\t#codeGen [SUM]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 8 \t\t\t#codeGen [SUM]\n");
  fprintf(MIPS_FILE, "  add 	$a0, $t0, $a0 \t\t\t#codeGen [SUM]\n");
  fprintf(MIPS_FILE, "  sw	$a0, 0($sp) \t\t\t#codeGen [SUM]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t\t#codeGen [SUM]\n");
}
void codeGenSub(){
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp) \t\t\t#codeGen [SUB]\n");
  fprintf(MIPS_FILE, "  lw	$t0, 8($sp) \t\t\t#codeGen [SUB]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 8 \t\t\t#codeGen [SUB]\n");
  fprintf(MIPS_FILE, "  sub 	$a0, $t0, $a0 \t\t\t#codeGen [SUB]\n");
  fprintf(MIPS_FILE, "  sw	$a0, 0($sp) \t\t\t#codeGen [SUB]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t\t#codeGen [SUB]\n");
}
void codeGenMul(){
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp) \t\t\t#codeGen [MUL]\n");
  fprintf(MIPS_FILE, "  lw	$t0, 8($sp) \t\t\t#codeGen [MUL]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 8 \t\t\t#codeGen [MUL]\n");
  fprintf(MIPS_FILE, "  mul 	$a0, $t0, $a0 \t\t\t#codeGen [MUL]\n");
  fprintf(MIPS_FILE, "  sw	$a0, 0($sp) \t\t\t#codeGen [MUL]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t\t#codeGen [MUL]\n");
}
void codeGenDiv(){
  fprintf(MIPS_FILE, "  lw  $a0, 4($sp) \t\t\t#codeGen [DIV]\n");
  fprintf(MIPS_FILE, "  lw  $t0, 8($sp) \t\t\t#codeGen [DIV]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 8 \t\t\t#codeGen [DIV]\n");
  fprintf(MIPS_FILE, "  div	$t0, $a0 \t\t\t#codeGen [DIV]\n");
  fprintf(MIPS_FILE, "  mfhi	$a0 \t\t\t#codeGen [DIV]\n");
  fprintf(MIPS_FILE, "  sw	$a0, 0($sp) \t\t\t#codeGen [DIV]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t\t#codeGen [DIV]\n");
}
void codeGenNegate(){
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp) \t\t\t#codeGen [NEGATE]\n");
  fprintf(MIPS_FILE, "  lw	$t0, 8($sp) \t\t\t#codeGen [NEGATE]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 8 \t\t\t#codeGen [NEGATE]\n");
  fprintf(MIPS_FILE, "  add 	$a0, $t0, $a0 \t\t\t#codeGen [NEGATE]\n");
  fprintf(MIPS_FILE, "  sw	$a0, 0($sp) \t\t\t#codeGen [NEGATE]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t\t#codeGen [NEGATE]\n");
}
void codeGenSignalChange(){
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp) \t\t\t#codeGen [SIGNAL CHANGE]\n");
  fprintf(MIPS_FILE, "  lw	$t0, 8($sp) \t\t\t#codeGen [SIGNAL CHANGE]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 8 \t\t\t#codeGen [SIGNAL CHANGE]\n");
  fprintf(MIPS_FILE, "  add 	$a0, $t0, $a0 \t\t\t#codeGen [SIGNAL CHANGE]\n");
  fprintf(MIPS_FILE, "  sw	$a0, 0($sp) \t\t\t#codeGen [SIGNAL CHANGE]\n");
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t\t#codeGen [SIGNAL CHANGE]\n");
}
///////////////////////////////////////////////////////////////////
/*              Assign            */
void codeGenAssign(struct ast *tree, struct registerStack *stack) {
  if (strcmp(tree->nodetype,"DEC") == 0) {
    printf("  li $a0, %d\n", tree->dec.number);
    fprintf(MIPS_FILE, "  li $a0, %d\n", tree->dec.number);
  }
}
void codeGenExpr(struct ast *tree, struct registerStack *stack) {
  if(tree != NULL){
    struct ast *walker;
    codeGenExpr(tree->childrens, stack);
    codeGenExpr(tree->nextBrother, stack);
    if (strcmp(tree->nodetype,"DEC") == 0) {
      printf("  li $a0, %d \t\t\t#codeGenExpr [DEC]\n", tree->dec.number);
      fprintf(MIPS_FILE, "  li $a0, %d \t\t\t#codeGenExpr [DEC]\n", tree->dec.number);

      printf("  sw $a0, 0($sp) \t\t#codeGenExpr [DEC]\n");
      fprintf(MIPS_FILE, "  sw $a0, 0($sp) \t\t#codeGenExpr [DEC]\n");

      printf("  addiu	$sp, $sp, -4 \t\t#codeGenExpr [DEC]\n");
      fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t#codeGenExpr [DEC]\n");
    }
    if (strcmp(tree->nodetype,"ID") == 0) {
      printf("  lw $a0, %d \t\t#codeGenExpr [ID]\n", tree->dec.number);
      fprintf(MIPS_FILE, "  lw $a0, %d \t\t#codeGenExpr [ID]\n", tree->dec.number);

      printf("  sw $a0, 0($sp) \t\t#codeGenExpr [ID]\n");
      fprintf(MIPS_FILE, "  sw $a0, 0($sp) \t\t#codeGenExpr [ID]\n");

      printf("  addiu	$sp, $sp, -4 \t\t#codeGenExpr [ID]\n");
      fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t#codeGenExpr [ID]\n");
    }
    if (strcmp(tree->nodetype,"+") == 0) {
      codeGenSum();
    } else if (strcmp(tree->nodetype,"-") == 0) {
      codeGenSub();
    } else if (strcmp(tree->nodetype,"*") == 0) {
      codeGenMul();
    } else if (strcmp(tree->nodetype,"/") == 0) {
      codeGenDiv();
    } else if (strcmp(tree->nodetype,"!") == 0) {
      codeGenNegate();
    } else if (strcmp(tree->nodetype,"-") == 0) {
      codeGenSignalChange();
    }
  }
}



/////////////////// Stack /////////////////////////////
struct registerStack *newVariableOnStack(struct symbol *sym, int offset, char type) {
    struct registerStack *variable = (struct registerStack *)malloc(sizeof(struct registerStack));
    if(!variable) {
      exit(0);
    }

    variable->id = sym;
    variable->offset = offset;
    variable->bottom = NULL;
    variable->type = type;

    return (struct registerStack *)variable;
}
struct registerStack *varStackPush(struct registerStack *stack, struct registerStack *new_var){
  if (stack != NULL) {
    new_var->bottom = stack;
  }

  return new_var;
}

void prinStack(struct registerStack *stack){
  printf("[Pilha de Variavel]\n");
  for (; stack != NULL; stack = stack->bottom) {
    if (stack->type != 'b') {
      printf("id: %s... offset %d($%cp)\n", stack->id->name, stack->offset, stack->type);
    } else {
      printf("[Fim da pilha do block]\n");
    }
  }
}
