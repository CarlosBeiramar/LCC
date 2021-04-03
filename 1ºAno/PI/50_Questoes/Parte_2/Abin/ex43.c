ABin cloneMirror (ABin a) {
    ABin clone=NULL;
    if (a)
    {
        clone=(ABin) malloc(sizeof(struct nodo));
        clone->valor=a->valor;
        clone->esq=cloneMirror(a->dir);
        clone->dir=cloneMirror(a->esq);
    }
    return clone;
}