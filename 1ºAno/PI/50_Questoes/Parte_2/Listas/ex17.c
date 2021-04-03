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

LInt cloneRev (LInt l){
    LInt tmp,r;
    r=NULL;
    tmp=NULL;
    while(l!=NULL){
        r=(LInt)malloc(sizeof(struct lligada));
        r->valor = l->valor;
        r->prox=tmp;
        tmp=r;
        l=l->prox;
        }
    return r;
}