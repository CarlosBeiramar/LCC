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

int maximo (LInt l){
    int r,j=0;
    while (l!=NULL){
        r=l->valor;
        if (r>j){j=r;}
        l=l->prox;
    }
    return j;
}