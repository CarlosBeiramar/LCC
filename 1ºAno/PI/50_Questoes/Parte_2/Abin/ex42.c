#include "abin.h"

/* Apresente uma definição da função "int contaFolhas (ABin a)" que dada uma
 árvore binária de inteiros, conta quantos dos seus nodos são folhas, i.e.,
 que não têm nenhum descendente. */
 
int contaFolhas (ABin a) {
    int conta=0;
    while (a!=NULL){
        if (a->esq==0 && a->dir==0) {
            conta=1;
        }else{
         conta += contaFolhas(a->esq);
         conta += contaFolhas(a->dir); 
        }
    }
    return conta;
}