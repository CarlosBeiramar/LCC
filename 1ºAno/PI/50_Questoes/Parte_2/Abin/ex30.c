#include "abin.h"

/* Defina uma função "void mirror (ABin *)" que inverte uma árvore (sem criar
 uma nova árvore). */
void mirror (ABin *a) {
    ABin p;
    if ((*a)!=NULL){
        p=(*a)->esq;
        (*a)->esq=(*a)->dir;
        (*a)->dir=p;
    
        mirror(&(*a)->dir);
        mirror(&(*a)->esq);
    }
    
}