# ifndef __CODEGENERATOR_H
# define __CODEGENERATOR_H
# include "../front/parser/tree.h"

/*          Pilha de Variaveis         */
// type:
//b -> fim da pilha
//f -> frame pointer
//s -> stack pointer
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

struct registerStack *codeGenFunctionLoadParameters(struct ast *, struct registerStack *);

struct registerStack *codeGenFunctionBlock(struct ast *ASTBLOCK, struct registerStack *blockStack);
struct registerStack *codeGenFunctionBlockVariable(struct ast *ASTBLOCK, struct registerStack *blockStack);
struct registerStack *codeGenFunctionBlockStatements(struct ast *ASTBLOCK, struct registerStack *blockStack);

void codeGenPushFunction(struct ast *ASTROOT);
void codeGenPopFunction(int qtdeParams);
/**/
void codeGenSum();

/**/
void codeGenAssign(struct ast *tree, struct registerStack *stack);
void codeGenExpr(struct ast *tree, struct registerStack *stack);
/**/


void prinStack(struct registerStack *stack);
#endif // __CODEGENERATOR_H
