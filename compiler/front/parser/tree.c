# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include "./tree.h"

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
struct ast *newnum(char nodetype[MAX_NODE_TYPE], int number){
    struct ast *no = (struct ast *)malloc(sizeof(struct ast));
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }

    strcpy(no->nodetype,nodetype);
    no->dec.number = number;

    no->childrens = NULL;
    no->nextBrother = NULL;
    no->previousBrother = NULL;

    return (struct ast *)no;
}
struct ast *newref(char nodetype[MAX_NODE_TYPE], struct symbol *name){
    struct ast *no = (struct ast *)malloc(sizeof(struct ast));
    if(!no) {
        //yyerror("out of space");
        exit(0);
    }

    strcpy(no->nodetype,nodetype);
    no->identification = name;
    //printf("\n\n=====LEX: %s ===============\n\n",  no->identification->name);
    no->childrens = NULL;
    no->nextBrother = NULL;
    no->previousBrother = NULL;

    return (struct ast *)no;
}
void astPrint(struct ast *father, int tab){
    struct ast *walker;

    for(walker = father; walker != NULL; walker = walker->nextBrother){
        for(int i = 0; i < tab; i++){
            printf("\t");
            //fprintf(fl_output,"\t");
        }

        /*
        switch(walker->nodetype) {
            case "DEC":
                printf("[%d \n", walker->dec.number);
                fprintf(fl_output,"[%d \n", walker->dec.number);
            break;
            case "ID":
                printf("[%s \n", walker->nodetype);
                fprintf(fl_output,"[%s \n", walker->nodetype);
            break;
            default:
                printf("[%s \n", walker->nodetype);
                fprintf(fl_output,"[%s \n", walker->nodetype);
            break;
        }
        */

        if(strcmp(walker->nodetype,"DEC") == 0){
            printf("[%d \n", walker->dec.number);
            fprintf(fl_output,"[%d ", walker->dec.number);
        } else if(strcmp(walker->nodetype,"ID") == 0){
            char *name = walker->identification->name;
            printf("[%s \n", name);
            fprintf(fl_output,"[%s ", name);
        } else{
            printf("[%s \n", walker->nodetype);
            fprintf(fl_output,"[%s ", walker->nodetype);
        }


        if(walker->childrens != NULL)
            astPrint(walker->childrens,tab+1);

        for(int i = 0; i < tab; i++){
            printf("\t");
            //fprintf(fl_output,"\t");
        }
        printf("]\n");
        fprintf(fl_output,"]");
    }
}
void astAddChildrens(struct ast **head_list, struct ast *newBrother){
    struct ast *walkNode;
    if(*head_list != NULL){
        for(walkNode = *head_list; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
        walkNode->nextBrother = newBrother;
        newBrother->previousBrother = walkNode;
    }
    else{
        *head_list = newBrother;
    }
}
void astNodeBrothers(struct ast *leftBrother, struct ast *rightBrother){
    struct ast *walkNode;
    if(rightBrother != NULL){
        for(walkNode = leftBrother; walkNode != NULL && walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
        walkNode->nextBrother = rightBrother;
        rightBrother->previousBrother = walkNode;
    } else {
        printf("\n\n----->>>astBrother: NULL\n\n");
    }
}




static unsigned symhash(char *sym){
    unsigned int hash = 0;
    unsigned c;
    while(c = *sym++) hash = hash*9 ^ c;

    return hash;
}
struct symbol *lookup(char* sym) {
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {
        if(sp->name && !strcmp(sp->name, sym)) { return sp; }
        if(!sp->name) {
            sp->name = strdup(sym);
            sp->value = 0;
            sp->func = NULL;
            sp->syms = NULL;
            //printf("\n\n=====LEX: %s ===============\n\n",  sp->name);
            return sp;
        }
        if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
    }
}
struct vardeclaration *symStackPush(struct vardeclaration *var_stack, struct vardeclaration *var_node){
    var_node->next = var_stack;
    return var_node;
}
int onVarStack(struct vardeclaration *top_stack, struct symbol *sym){
    struct vardeclaration *walkerStack;

    for(walkerStack = top_stack; walkerStack != NULL && (strcmp(walkerStack->sym->name, sym->name) != 0); walkerStack = walkerStack->next);
    if(walkerStack != NULL && (strcmp(walkerStack->sym->name, sym->name) == 0)){
        return 0;
    }
    return 1;
}
void reservedWords(struct symbol *sym){
    if(strcmp("print", sym->name) == 0){
        exit(0);
    }
    if(strcmp("main", sym->name) == 0){
        START_OK = 1;
    }
}
void semanticCheck(struct ast *father, int nivel, struct vardeclaration *var_stack, struct vardeclaration *func_stack){
    struct ast *walkerAST;
    for(walkerAST = father; walkerAST != NULL; walkerAST = walkerAST->nextBrother){
        struct vardeclaration *var_node = (struct vardeclaration *)malloc(sizeof(struct vardeclaration));

        if(strcmp(walkerAST->nodetype,"decvar") == 0){
            if(walkerAST->childrens->nextBrother != NULL){
                semanticCheck(walkerAST->childrens->nextBrother, nivel+1, var_stack, func_stack);
            }
                //var_node->sym = walkerAST->childrens->childrens->identification;
                //var_node->nivel = nivel;

                //printf("\n=========Assign: %s", var_node->sym->name);

                //var_stack = symStackPush(var_stack, var_node);
               // printf("\n=========Semantico add VAR: %s", var_node->sym->name);


                var_node->sym = walkerAST->childrens->identification;
                var_node->nivel = nivel;

                var_stack = symStackPush(var_stack, var_node);
                printf("\n=========Semantico add VAR: %s", var_node->sym->name);
        } else if(strcmp(walkerAST->nodetype,"decfunc") == 0){
            struct ast *walkChild = walkerAST->childrens;

            reservedWords(walkChild->identification);
            if(onVarStack(func_stack, walkChild->identification) == 0){
                exit(0);
            }

            var_node->sym = walkChild->identification;
            var_node->nivel = nivel;
            func_stack = symStackPush(func_stack, var_node);

            walkChild = walkChild->nextBrother;

            for(struct ast *params_node = walkChild->childrens; params_node != NULL; params_node = params_node->nextBrother){
                var_node = (struct vardeclaration *)malloc(sizeof(struct vardeclaration));

                var_node->sym = walkChild->identification;
                var_node->nivel = nivel;

                var_stack = symStackPush(var_stack, var_node);
            }


            //printf("\n=========Semantico add FUNCCCCC: %s", help->nodetype);

            //semanticCheck(help, nivel+1, var_stack, func_stack);
        }else if(strcmp(walkerAST->nodetype,"funccall") == 0){
            if(onVarStack(func_stack, walkerAST->childrens->identification) == 0){
                printf("\n=========%s: Na Pilha", walkerAST->identification->name);
            } else {
                exit(0);
            }
        } else if(strcmp(walkerAST->nodetype,"ID") == 0){
            if(onVarStack(var_stack, walkerAST->identification) == 0){
                printf("\n=========%s: Na Pilha", walkerAST->identification->name);
            } else {
                exit(0);
            }
        } else{
            semanticCheck(walkerAST->childrens, nivel+1, var_stack, func_stack);
        }
    }
}
