#include "abin.h"

/* Defina uma função "ABin cloneAB (ABin)" que cria uma cópia de uma árvore.
*/
ABin cloneAB (ABin a) {
    ABin p;
    if (a==NULL) {
        p=NULL;
        return p;
    }else{
        p=(ABin)malloc(sizeof(struct nodo));
        p->valor=a->valor;
        p->esq=cloneAB(a->esq);
        p->dir=cloneAB(a->dir);
    }
    return p;
}