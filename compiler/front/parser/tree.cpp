# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include "tree.h"

struct ast *newast(char nodetype[MAX_NODE_TYPE]) {
    struct ast *no = (struct ast *)malloc(sizeof(struct ast));
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    
    strcpy(no->nodetype,nodetype);
    no->childrens = NULL;
    no->nextBrother = NULL;
    no->previousBrother = NULL;

    return (struct ast *)no;
}
void astAddChild(struct ast *father, struct ast *child){
    struct ast *walkNode;
    if(father->childrens == NULL){
        father->childrens = child;
    }else{
        for(walkNode = father->childrens; walkNode->nextBrother != NULL; walkNode = walkNode->nextBrother);

        walkNode->nextBrother = child;
        child->previousBrother = walkNode;
    }
}
void astNumAddChild(struct ast *father, struct ast *child){
    struct ast *walkNode;
    if(father->childrens == NULL){
        father->childrens = child;
    }else{
        for(walkNode = father->childrens; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);

        walkNode->nextBrother = child;
        child->previousBrother = walkNode;
    }
}

struct ast *newnum(char nodetype[MAX_NODE_TYPE], int d){
    struct numval *no = malloc(sizeof(struct numval));

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->number = d;
    return (struct ast *)no;
}

void astPrint(struct ast *father, int tab){
    struct ast *walker;

    for(walker = father; walker != NULL; walker = walker->nextBrother){
        for(int i = 0; i < tab; i++)
            printf("\t");            
        printf("[%s \n", walker->nodetype);

        if(walker->childrens != NULL)
            astPrint(walker->childrens,tab+1);

        for(int i = 0; i < tab; i++)
            printf("\t");
        printf("]\n");
    }
}
void astAddChildrens(struct ast **head_list, struct ast *newBrother){
    struct ast *walkNode;
    if(*head_list != NULL){
        for(walkNode = *head_list; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
        walkNode->nextBrother = newBrother;
    }
    else{
        *head_list = newBrother;
    }
}
void astBrothers(struct ast *leftBrother, struct ast *rightBrother){
    struct ast *walkNode;
    for(walkNode = leftBrother; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
    walkNode->nextBrother = rightBrother;
    rightBrother->previousBrother = walkNode;
}