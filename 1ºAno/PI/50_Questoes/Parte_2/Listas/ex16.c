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

LInt clone(Lint l){
	LInt *r;
		while (l!=NULL){
			(*r)=malloc(sizeof(struct lligada));
			(*r)->valor = l->valor;
			l=l->prox;
			r=&((*r)->prox);
		}
		return r;
}