#ifndef __TREE_H
#define __TREE_H

#define MAX_NODE_TYPE 63
#define NHASH 9997

struct ast {
    char nodetype[MAX_NODE_TYPE];
    union {
		int number;
    } dec;

    union{
        struct symbol *s;
    }id;

    struct ast *childrens;
    struct ast *nextBrother;
    struct ast *previousBrother;

    struct symbol *identification;
};
struct numval {
    char nodetype[MAX_NODE_TYPE];
    int number;
};
/*
struct fncall {
    char nodetype[MAX_NODE_TYPE];
    struct ast *l;
    struct symbol *s;
};
struct flow {
    char nodetype[MAX_NODE_TYPE];
    struct ast *cond;
    struct ast *tl;
    struct ast *el;
};
struct symref {
    char nodetype[MAX_NODE_TYPE];
    struct symbol *s;
};
struct symasgn {
    char nodetype[MAX_NODE_TYPE];
    struct symbol *s;
    struct ast *v;
};
*/
struct ast *newast(char nodetype[MAX_NODE_TYPE]);
struct ast *newnum(char nodetype[MAX_NODE_TYPE], int d);
struct ast *newref(char nodetype[MAX_NODE_TYPE], struct symbol *name);

void astPrint(struct ast *father, int tab);

void astAddChild(struct ast *father,struct ast *child);
void astAddChildrens(struct ast **head_list,struct ast *newBrother);
void astNodeBrothers(struct ast *leftBrother, struct ast *rightBrother);


/* Tabela de Simbolos */
struct symbol {
    /* a variable name */
    char *name;
    int value;
    struct ast *func; /* stmt for the function */
    struct symlist *syms; /* list of dummy args */
};
struct symlist {
    struct symbol *sym;
    struct symlist *next;
};

struct symbol symtab[NHASH];
struct symbol *lookup(char*);
static unsigned symhash(char *sym);
/* list of symbols, for an argument list */
struct symlist *newsymlist(struct symbol *sym, struct symlist *next);

#endif // __TREE_H