int depthOrd (ABin a, int x) {
    int i,j;
    while (a && !i) {
        if (a->valor > x) 
            a=a->esq;
        else if(a->valor<x)
                a=a->dir;
            else i=1;
            j++;
    }
    if(!i) j=-1;
    return j;
}