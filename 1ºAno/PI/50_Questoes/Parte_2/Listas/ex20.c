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

int drop (int n, LInt *l){
    int i,conta=0;
    LInt p;
    for (i=0;*l && n>i;i++){
        p=(*l)->prox;
        free (*l);
        *l=p;
    }
    
    return i;
}