#include "abin.h"
#include <stdio.h>
#include <stdlib.h>

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

int altura (ABin a){
    int esq,dir,alt;
    if (a==NULL) {
        return 0;}
    else {
        esq=altura(a->esq);
        dir=altura(a->dir);
    if (esq>dir) {
        alt=1+esq;
    } else {
        alt=1+dir; 
        }
    }
	return alt;
}