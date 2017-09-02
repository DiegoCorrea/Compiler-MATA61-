#ifndef __CODEGENERATOR_H
#define __CODEGENERATOR_H
#include "../front/parser/tree.h"

/*          Pilha de Variaveis         */
struct registerStack {
  int offset;
  struct symbol *id;

  char type;

  struct registerStack *bottom;
};
struct registerStack *newVariableOnStack(struct symbol *sym, int offset, char type);
struct registerStack *varStackPush(struct registerStack *stack, struct registerStack *new_var);

/////////////////////////////////////////////////////

void astPrintBack(struct ast *ASTROOT, int tab);

/*          Code Gen          */
void codeGenerator(struct ast *ASTROOT, char** argv);
void codeGen(struct ast *ASTROOT);
void codeGenStartMips(struct ast *ASTROOT);
/* Code Gen Global Variables*/
void codeGenGlobalVariables(struct ast *ASTROOT);
void codeGenSingleGlobalVariable(struct ast *ASTROOT);

/**/
void codeGenPrintIntegerOnScreen();
void codeGenPrintFunction();
/**/
void codeGenFunctions(struct ast *ASTROOT);
void codeGenFunctionCreateLabel(struct ast *ASTROOT);
struct registerStack *codeGenFunctionActivationRecord(struct ast *PARAMS, struct registerStack *blockStack);

void codeGenPushFunction(struct ast *ASTROOT);

struct registerStack *codeGenFunctionLoadParameters(struct ast *, struct registerStack *);

void codeGenFunctionBlock(struct ast *ASTBLOCK, struct registerStack *blockStack);
void codeGenFunctionBlockVariable(struct ast *ASTBLOCK, struct registerStack *blockStack);
void codeGenFunctionBlockStatements(struct ast *ASTBLOCK, struct registerStack *blockStack);

void codeGenPopFunction();
/**/
void codeGenSum();


void prinStack(struct registerStack *stack);
#endif // __CODEGENERATOR_H
