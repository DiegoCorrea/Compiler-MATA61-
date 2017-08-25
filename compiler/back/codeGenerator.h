#ifndef __CODEGENERATOR_H
#define __CODEGENERATOR_H
#include "../front/parser/tree.h"

void codeGenerator(struct ast *ASTROOT);
void astPrintBack(struct ast *father, int tab);


#endif // __CODEGENERATOR_H
