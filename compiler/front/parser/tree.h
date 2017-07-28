#ifndef __TREE_H
#define __TREE_H

#define MAX_NODE_TYPE 63
struct ast {
    char nodetype[MAX_NODE_TYPE];
    union {
		int number;
		char *string;
    } value;

    struct ast *childrens;
    struct ast *nextParent;
    struct ast *previousParent;
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
void astAddChild(struct ast *father,struct ast *child);
struct ast *newnum(char nodetype[MAX_NODE_TYPE], int d);
void astPrint(struct ast *father, int tab);
void astAddBrother(struct ast **head_list,struct ast *newBrother);

/*
struct ast *newcmp(char cmptype[MAX_NODE_TYPE], struct ast *l, struct ast *r);
struct ast *newfunc(char functype[MAX_NODE_TYPE], struct ast *l);
struct ast *newcall(struct symbol *s, struct ast *l);
struct ast *newref(struct symbol *s);
struct ast *newasgn(struct symbol *s, struct ast *v);
struct ast *newflow(char nodetype[MAX_NODE_TYPE], struct ast *cond, struct ast *tl, struct ast *tr);

void dodef(struct symbol *name, struct symlist *syms, struct ast *stmts);

double eval(struct ast *);

void treefree(struct ast *);
void printando(struct ast *);
*/

#endif // __TREE_H