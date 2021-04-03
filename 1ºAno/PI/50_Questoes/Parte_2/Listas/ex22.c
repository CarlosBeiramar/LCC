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

int listToArray (LInt l, int v[], int N){
    int i;
    for (i=0;l && i<N; i++) {
        v[i]=l->valor;
        l=l->prox;
    }
    return i;
}