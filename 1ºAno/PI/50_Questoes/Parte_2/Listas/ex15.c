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

void concatL (LInt *a, LInt b){
    while ((*a)!=NULL){
        a=&((*a)->prox);
    }
     *a=b;
}