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

LInt revereL (LInt l){
    LInt l2,l1=NULL;
    while (l!=NULL) {
        l2=l->prox;
        l->prox=l1;
        l1=l;
        l=l2;
    }
    return l1;
}