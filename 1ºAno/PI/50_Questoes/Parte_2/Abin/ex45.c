int lookupAB (ABin a, int x) {
    int m;
    while (a) {
        if (a->valor == x) {
            m=1;
        }
        if (a->valor > x) {
            a=a->esq;
        }
        if (a->valor < x){
            a=a->dir;
        }
    }
    return m;
}