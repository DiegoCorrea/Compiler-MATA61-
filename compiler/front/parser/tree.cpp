# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include "tree.h"

struct ast *newast(char nodetype[MAX_NODE_TYPE]) {
    struct ast *no = (struct ast *)malloc(sizeof(struct ast));
    no->childrens = NULL;
    no->nextParent = NULL;
    no->previousParent = NULL;

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
   // printando("\nValor: %s\n", nodetype);
    return (struct ast *)no;
}
void astAddChild(struct ast *father,struct ast *child){
    struct ast *walkNode;
    if(father->childrens == NULL){
        father->childrens = child;
    }else{
        for(walkNode = father->childrens; walkNode->nextParent != NULL;walkNode = walkNode->nextParent);

        walkNode->nextParent = child;
        child->previousParent = walkNode;
    }
}
void printando(struct ast *no){
    //printando("\nValor: %s\n", no->nodetype);
}
/*
struct ast *newnum(double d){
    struct numval \*no = malloc(sizeof(struct numval));

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->number = d;
    return (struct ast *)no;
}
struct ast *newcmp(char nodetype[MAX_NODE_TYPE], struct ast *l, struct ast *r){
    struct ast *no = malloc(sizeof(struct ast));
    
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->l = l;
    no->r = r;
    return no;
}
struct ast *newfunc(char nodetype[MAX_NODE_TYPE], struct ast *l){
    struct fncall *no = malloc(sizeof(struct fncall));

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->l = l;
    no->functype = functype;
    return (struct ast *)no;
}
struct ast *newcall(struct symbol *s, struct ast *l){
    struct ufncall *no = malloc(sizeof(struct ufncall));
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->l = l;
    no->s = s;
    return (struct ast *)no;
}
struct ast *newref(struct symbol *s){
    struct symref *no = malloc(sizeof(struct symref));

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->s = s;
    return (struct ast *)no;
}
struct ast *newasgn(struct symbol *s, struct ast *v){
    struct symasgn *no = malloc(sizeof(struct symasgn));
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
    strcpy(no->nodetype,nodetype);
    no->s = s;
    no->v = v;
    return (struct ast *)no;
}
struct ast *newflow(char nodetype[MAX_NODE_TYPE], struct ast *cond, struct ast *tl, struct ast *el){
    struct flow *no = malloc(sizeof(struct flow));

    if(!no) {
        //yyerror("out of space");
        exit(0);
    }
   strcpy(no->nodetype,nodetype);
    no->cond = cond;
    no->tl = tl;
    no->el = el;
    return (struct ast *)no;
}
*/