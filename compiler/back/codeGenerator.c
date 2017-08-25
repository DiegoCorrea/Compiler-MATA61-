#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "./codeGenerator.h"

void codeGenerator(struct ast *ASTROOT){
  if (ASTROOT != NULL) {
    printf("[CODE GEN]ASTROOT Com estrutura\n");
    astPrintBack(ASTROOT,0);
  } else {
    printf("[CODE GEN]ASTROOT = NULL\n");
  }
}
void astPrintBack(struct ast *father, int tab){
    struct ast *walker;

    for(walker = father; walker != NULL; walker = walker->nextBrother){
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
