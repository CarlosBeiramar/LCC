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

LInt somasAcL (LInt l) {
   LInt p,*e=&p;
   int i=0;
   while (l) {
       (*e)=(LInt) malloc (sizeof(struct lligada));
       i+=l->valor;
       l=l->prox;
       (*e)->valor=i;
       e=&((*e)->prox);
   }
   *e=NULL;
    return p;
}