#include "abin.h"

/* Defina uma função "int iguaisAB (ABin a, ABin b)" que testa se duas
 árvores são iguais (têm os mesmos elementos e a mesma forma). */
int iguaisAB (ABin a, ABin b) {
    int verifica=0;
    if (a && b)
    {
           verifica=(a->valor==b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
    }
    if (!a && !b) 
        verifica=1;
    return verifica;
}