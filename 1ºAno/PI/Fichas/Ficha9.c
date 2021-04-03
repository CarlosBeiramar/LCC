
//arvore binaria: 17 22 7 5 13 34 15
//Insercao de numeros em arvores binarias

//inorder: 5,7,13,17,17,22,34  
//preorder: 17,13,7,5,15,22,34  
//posorder: 5,7,15,13,34,22,17


typedef struct abin{
    int valor;
    struct abin *esq,*dir;
}*ABin,NoddABin;


void inorder(ABin a){
    if(a){
        inorder(a->esq);
        printf("%d",a->valor);
        inorder(a->dir);
    }
}

void preorder(ABin a){
    if(a){
        printf("%d",a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }
}

void posorder(ABin a){
    if (a){
        posorder(a->esq);
        posorder(a->dir);
        printf("%d",a->valor);
    }
}

int procuraAbin (ABin a,int x){
    int res=0;
    if (a){
        if (x>a->valor){
            res=procuraAbin(a->dir,x);
        }
        if (x<a->valor){
            res=procuraAbin(a->esq,x);
        }
        else{
            res=1;
            }
    }
    return res;
}

ABin insABin (Abin a,int x){
    if (a){
        if(x<a->valor){
            a->esq=insABin(a->esq,x);
        }
        if (x>a->valor){
            a->dir=insABin(a->dir,x);
        }
    }else{
        a=(ABin)malloc(sizeof(NoddABin));
        a->valor = x;
        a->esq=NULL;
        a->dir=NULL;
    }
    return a;
}

int efolha(ABin a){
    return !a->esq && !a->dir; 
}

//nao é vazia.
Abin maxAbin (Abin a){
    while(a && a->dir){
        a=a->dir;
    }
    return a;
}

Abin minAbin(ABin a){
    while(a && a->esq){
        a=a->esq;
    }
    return a;
}






