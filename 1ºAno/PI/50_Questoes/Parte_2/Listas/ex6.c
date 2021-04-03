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

int removeOneOrd (LInt *l, int x){
while (*l!=NULL&&x!=(*l)->valor)
        l=&((*l)->prox);
    if (*l==NULL) return 1;
    else {
        if ((*l)->prox==NULL) *l=NULL;
        else *l=(*l)->prox;
    }
    return 0;
}