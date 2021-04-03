#include "abin.h"

/* Apresente uma definição não recursiva da função "int maiorAB (ABin)" que
 calcula o maior elemento de uma árvore binária de procura não vazia. */
 
int maiorAB (ABin a) {
    while (a->dir != NULL) { 
        a=a->dir;
    }
    return a->valor;
}