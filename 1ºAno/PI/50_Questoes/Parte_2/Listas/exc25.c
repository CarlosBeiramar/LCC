#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void remreps (LInt l){
    LInt r,j;
    while(l!=NULL) {
        r=l->prox;
        while (j!=NULL && l->valor==r->valor) {
            j=r->prox;
            free(r);
            r=j;
            }
        l->prox=r;
        l=l->prox;
    }
}