#include "abin.h"

/* Apresente uma definição da função "int quantosMaiores (ABin a, int x)" que,
 dada uma árvore binária de procura de inteiros e um inteiro, conta quantos
 elementos da árvore são maiores que o inteiro dado. */

int quantosMaiores (ABin a, int x) {
    int conta=0;
    if(a!= NULL) {
    if (a->valor>=x) {
        conta ++;
        conta += quantosMaiores(a->dir,x);
        conta +=quantosMaiores(a->esq,x);
    }
    else { 
        conta += quantosMaiores(a->dir,x);
        }
    }
    return conta;
}