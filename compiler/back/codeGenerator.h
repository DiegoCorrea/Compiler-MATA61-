#ifndef __CODEGENERATOR_H
#define __CODEGENERATOR_H
#include "../front/parser/tree.h"

void astPrintBack(struct ast *ASTROOT, int tab);
/* Code Gen */
void codeGenerator(struct ast *ASTROOT, char** argv);
void codeGen(struct ast *ASTROOT);
void codeGenStartMips(struct ast *ASTROOT);
/* Code Gen Global Variables*/
void codeGenGlobalVariables(struct ast *ASTROOT);
void codeGenSingleGlobalVariable(struct ast *ASTROOT);

/**/
void codeGenPrintIntegerOnScreen();

/**/
void codeGenFunction(struct ast *ASTROOT);
void codeGenFunctionCreateLabel(struct ast *ASTROOT);
void codeGenFunctionActivationRecord(struct ast *ASTROOT);

void codeGenPushFunction(struct ast *ASTROOT);

void codeGenFunctionLoadParameters(struct ast *ASTROOT);
void codeGenFunctionBlock(struct ast *ASTBLOCK);
void codeGenFunctionBlockVariable(struct ast *ASTBLOCK);
void codeGenFunctionBlockStatements(struct ast *ASTBLOCK);
void codeGenPopFunction();
/**/
void codeGenSum();
#endif // __CODEGENERATOR_H
