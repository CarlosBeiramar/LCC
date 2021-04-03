#include "abin.h"

/* Defina uma função "void removeMaiorA (ABin *)" que remove o maior elemento
 de uma árvore binária de procura. */
void removeMaiorA (ABin *a) {
    ABin b;
    if (a!=NULL) {
    while( (*a)->dir != NULL) {
        a=&((*a)->dir);
        b=(*a)->esq;
        free(*a);
        *a=b;
        }
    }
}