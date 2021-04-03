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

LInt arrayToList (int v[], int N){
    LInt l, *e=&l;
    int i;
    while (i<N){
        *e=(LInt) malloc (sizeof (struct lligada));
        (*e)->valor=v[i];
        i++;
        e=&((*e)->prox);
        
    }
    *e=NULL;
    return l;
}