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

void appendL (LInt *l, int x){
    LInt pt,novo,ant;
    ant=NULL;
    pt=*l;
    while (pt!=NULL){
        ant=pt; pt=pt->prox;
    }
    novo = malloc (sizeof (struct lligada));
    novo -> valor = x; novo->prox=NULL;
    if (ant==NULL)(*l)=novo;else ant->prox=novo;
}