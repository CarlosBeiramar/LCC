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

int removeAll (LInt *l, int x){
    int i=0;
    while ((*l)!=NULL) {
        if (x==(*l)->valor)  {
            *l=((*l)->prox); 
            i++;
            
        }
        
        else
        l=&((*l)->prox);
    }
    return i;
}