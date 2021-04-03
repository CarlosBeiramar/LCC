int freeAB (ABin a) {
    int conta=0;
    if(a!=NULL){
        conta += freeAB(a->esq);
        conta += freeAB(a->dir);
        free(a);
        conta++;
    }
    return conta;
}