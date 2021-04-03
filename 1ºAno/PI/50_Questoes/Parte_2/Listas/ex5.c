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

void insertOrd (LInt *l, int x){
        LInt n;
    if (*l==NULL) { n=newLInt(x,NULL); *l=n;}
    else {
         while ((*l)!=NULL&&x>(*l)->valor) {
             l=&((*l)->prox);
         }
         n=newLInt(x,*l);
         *l=n;
    }
}