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
    //printf("[CODE GEN]ASTROOT Com estrutura\n");
    //astPrintBack(ASTROOT,0);

    //printf("\n\n--[Code Gen Start]\n\n");
    codeGen(ASTROOT);
  } else {
    printf("[CODE GEN] ASTROOT = NULL\n");
  }
  fclose( MIPS_FILE );
}
void codeGen(struct ast *ASTROOT){
  //fprintf(MIPS_FILE, ".globl main\n");

  fprintf(MIPS_FILE, ".data \n");

  codeGenGlobalVariables(ASTROOT->childrens);

  fprintf(MIPS_FILE, ".text\n");

  codeGenStartMips(ASTROOT);

  codeGenFunctions(ASTROOT->childrens);

}
void codeGenStartMips(struct ast *ASTROOT){
  fprintf(MIPS_FILE, "\nmain:\n");

  fprintf(MIPS_FILE, "  move $fp, $sp \t\t#Start Mips\n");

  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Start Mips\n");

  fprintf(MIPS_FILE, "  jal _func_main \t\t#Start Mips\n");

  fprintf(MIPS_FILE, "  li $v0, 10 \t\t#Start Mips\n");

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
    fprintf(MIPS_FILE, "  %s: \t .word \t %d \n", name,variable->nextBrother->dec.number);
  } else {
    fprintf(MIPS_FILE, "  %s: \t .word \n", name);
  }

}
////////////////////////////////////////////////////////////////

void codeGenFunctions(struct ast *ASTROOT){
  for(struct ast *walker = ASTROOT; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"decfunc") == 0) {
      struct ast *id = walker->childrens,
       *paramsList = walker->childrens->nextBrother,
       *blockTree = walker->childrens->nextBrother->nextBrother;
       int qtdeParams = 0;
      for (struct ast *tmpCount = paramsList->childrens; tmpCount != NULL; tmpCount = tmpCount->nextBrother, qtdeParams++);

      struct registerStack *blockStack = newVariableOnStack(NULL, 0, 'e');

      codeGenFunctionCreateLabel(id);
      blockStack = codeGenFunctionActivationRecord(paramsList->childrens, blockStack, qtdeParams);
      blockStack = codeGenFunctionBlock(blockTree, blockStack);
      codeGenPopFunction(qtdeParams);
      //prinStack(blockStack);
    }
  }
  codeGenPrintFunction();
}
void codeGenFunctionCreateLabel(struct ast *func){
  fprintf(MIPS_FILE, "\n_func_%s: \t\t#Create Label\n", func->identification->name);
}
struct registerStack *codeGenFunctionActivationRecord(struct ast *PARAMS, struct registerStack *blockStack, int qtdeParams){
  fprintf(MIPS_FILE, "  sw $fp, 0($sp) \t\t#Activation Record\n");

  fprintf(MIPS_FILE, "  move $fp, $sp \t\t#Activation Record\n");

  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Activation Record\n");

  blockStack = codeGenFunctionLoadParameters(PARAMS, blockStack, qtdeParams);

  fprintf(MIPS_FILE, "  sw $ra, 0($sp) \t\t#Activation Record\n");

  fprintf(MIPS_FILE, "  move $fp, $sp \t\t#Activation Record\n");

  fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Activation Record\n");

  return blockStack;
}
struct registerStack *codeGenFunctionLoadParameters(struct ast *PARAMS, struct registerStack *blockStack, int qtdeParams){
  if (PARAMS != NULL) {
    struct ast *walker= PARAMS;

    for(int offset = 1; offset <= qtdeParams && walker != NULL; offset++, walker = walker->nextBrother){

      blockStack = varStackPush(blockStack, newVariableOnStack(walker->identification, offset, 'f'));
      fprintf(MIPS_FILE, "  lw $a0, %d($fp) \t\t#Load Parameters\n", offset*4);
      fprintf(MIPS_FILE, "  sw $a0, 0($sp) \t\t#Load Parameters\n");

      fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Load Parameters\n");
    }
  }
  return blockStack;
}
///////////////////// Block ////////////////////////////
struct registerStack *codeGenFunctionBlockVariable(struct ast *ASTBLOCK, struct registerStack *blockStack){
  int offset = 1;
  for(struct ast *walker = ASTBLOCK; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"decvar") == 0) {
      struct ast *declaration = walker->childrens;
      blockStack = varStackPush(blockStack, newVariableOnStack(declaration->identification, offset, 's'));

      if (declaration->nextBrother != NULL) {
        codeGenExpr(declaration->nextBrother, blockStack);
      } else {
        fprintf(MIPS_FILE, "  addiu $sp, $sp, -4 \t\t#Function Variable declaration\n");
      }
      offset++;
    }
  }
  return blockStack;
}
void codeGenFunctionCall(struct ast *walker, struct registerStack *blockStack){
  struct ast *funccall = walker->childrens;
  int qtdeArgs = 0;

  for(struct ast *args = funccall->nextBrother->childrens; args != NULL; args = args->nextBrother, qtdeArgs++) {
    codeGenExpr(args->childrens, blockStack);
  }
  fprintf(MIPS_FILE, "  jal _func_%s\n",funccall->identification->name);
  fprintf(MIPS_FILE, "  addiu $sp, $sp, %d \t\t#POP Arg List\n", 4*(qtdeArgs));
}
struct registerStack *codeGenFunctionBlockStatements(struct ast *ASTBLOCK, struct registerStack *blockStack ) {
  for(struct ast *walker = ASTBLOCK; walker != NULL; walker = walker->nextBrother){
    if (strcmp(walker->nodetype,"funccall") == 0) {
      codeGenFunctionCall(walker,blockStack);
    }
    if (strcmp(walker->nodetype,"assign") == 0) {
      codeGenAssign(walker->childrens, blockStack);
    }
    if (strcmp(walker->nodetype,"return") == 0) {
      codeGenExpr(walker->nextBrother, blockStack);
    }
    if (strcmp(walker->nodetype,"if") == 0) {
      codeGenIF(walker,blockStack);
    }
  }
  return blockStack;
}
struct registerStack *codeGenFunctionBlock(struct ast *ASTBLOCK, struct registerStack *blockStack){
  blockStack = codeGenFunctionBlockVariable(ASTBLOCK->childrens, blockStack);
  blockStack = codeGenFunctionBlockStatements(ASTBLOCK->childrens, blockStack);

  return blockStack;
}
void codeGenIF(struct ast *ASTIF, struct registerStack *blockStack){

}
////////////////// Fim do Block ///////////////////////
void codeGenPopFunction(int qtdeParams){
  fprintf(MIPS_FILE, "  move $sp, $fp \t\t#POP Function\n");
  fprintf(MIPS_FILE, "  lw $ra, 0($sp) \t\t#POP Function\n");

  fprintf(MIPS_FILE, "  addiu $sp, $sp, %d \t\t#POP Function\n", 4*(qtdeParams + 1));

  fprintf(MIPS_FILE, "  lw $fp, 0($sp) \t\t#POP Function\n");
  fprintf(MIPS_FILE, "  jr $ra \t\t#POP Function\n");
}
void codeGenPrintFunction() {
  fprintf(MIPS_FILE, "\n_func_print:\n");
  fprintf(MIPS_FILE, "  lw	$a0, 4($sp)\n");
  fprintf(MIPS_FILE, "  li $v0, 1\n");
  fprintf(MIPS_FILE, "  syscall\n");

  fprintf(MIPS_FILE, "  li $v0, 11\n");
  fprintf(MIPS_FILE, "  li $a0, 0x0a\n");
  fprintf(MIPS_FILE, "  syscall\n");

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
  struct registerStack *variable = searchOnStack(stack, tree);
  codeGenExpr(tree->nextBrother, stack);
  if(variable->type != 'e'){
    if(variable->type == 'f'){
      fprintf(MIPS_FILE, "  sw $a0, %d($fp) \t\t\t#Assign\n", variable->offset*4);
    }
    else{
      fprintf(MIPS_FILE, "  sw $a0, -%d($fp) \t\t\t#Assign\n", variable->offset*4);
    }
  }
  fprintf(MIPS_FILE, "  addiu	$sp, $sp, 4 \t\t#Assign\n");
}
void codeGenExpr(struct ast *tree, struct registerStack *stack) {
  if(tree != NULL){
    struct ast *walker;
    codeGenExpr(tree->childrens, stack);
    codeGenExpr(tree->nextBrother, stack);
    if (strcmp(tree->nodetype,"DEC") == 0) {
      fprintf(MIPS_FILE, "  li $a0, %d \t\t\t#codeGenExpr [DEC]\n", tree->dec.number);

      fprintf(MIPS_FILE, "  sw $a0, 0($sp) \t\t#codeGenExpr [DEC]\n");

      fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t#codeGenExpr [DEC]\n");
    }
    if (strcmp(tree->nodetype,"ID") == 0) {
      struct registerStack *variable = searchOnStack(stack, tree);
      if(variable->type != 'e'){
        if(variable->type == 'f'){
          fprintf(MIPS_FILE, "  lw $a0, %d($fp) \t\t\t#codeGenExpr [ID]\n", variable->offset*4);
        }
        else{
          fprintf(MIPS_FILE, "  lw $a0, -%d($fp) \t\t\t#codeGenExpr [ID]\n", variable->offset*4);
        }
        fprintf(MIPS_FILE, "  sw $a0, 0($sp) \t\t#codeGenExpr [ID]\n");

        fprintf(MIPS_FILE, "  addiu	$sp, $sp, -4 \t\t#codeGenExpr [ID]\n");
      }
    }
    if (strcmp(tree->nodetype,"*") == 0) {
      codeGenMul();
    } else if (strcmp(tree->nodetype,"/") == 0) {
      codeGenDiv();
    } else if (strcmp(tree->nodetype,"!") == 0) {
      codeGenNegate();
    } else if (strcmp(tree->nodetype,"+") == 0) {
      codeGenSum();
    } else if (strcmp(tree->nodetype,"-") == 0) {
      codeGenSub();
    } else if (strcmp(tree->nodetype,"-") == 0) {
      codeGenSignalChange();
    } else if (strcmp(tree->nodetype,"funccall") == 0) {
      codeGenFunctionCall(tree->childrens, stack);
    } else if (strcmp(tree->nodetype,">") == 0) {
      codeGenExpr(tree->childrens, stack);
    } else if (strcmp(tree->nodetype,">=") == 0) {
      codeGenExpr(tree->childrens, stack);
    } else if (strcmp(tree->nodetype,"<") == 0) {
      codeGenExpr(tree->childrens, stack);
    } else if (strcmp(tree->nodetype,"<=") == 0) {
      codeGenExpr(tree->childrens, stack);
    } else if (strcmp(tree->nodetype,"==") == 0) {
      codeGenExpr(tree->childrens, stack);
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
struct registerStack *searchOnStack(struct registerStack *stack, struct ast *to_search){
  for (; stack != NULL && stack->id != to_search->identification ; stack = stack->bottom);
  return stack;
}
void prinStack(struct registerStack *stack){
  printf("[Pilha de Variavel]\n");
  for (; stack != NULL; stack = stack->bottom) {
    if (stack->type != 'e') {
      if(stack->type == 'f')
        printf("id: %s... offset %d($fp)\n", stack->id->name, stack->offset*4);
      else
        printf("id: %s... offset -%d($fp)\n", stack->id->name, stack->offset*4);
    } else {
      printf("[Fim da pilha do block]\n");
    }
  }
}
