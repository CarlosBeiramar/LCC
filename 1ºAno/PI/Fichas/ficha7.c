typedef struct slist *LInt;

typedef struct slist {
int valor;
LInt prox;
} Nodo

//1 a)

LInt insere (Nodo x){
    l=aux;
    aux = malloc(sizeof(struct Nodo));
    aux->valor=10;
    aux=aux->prox;
    aux=malloc(sizeof(struct Nodo));
    aux->valor=5;
    aux=aux->prox;
    aux=malloc(sizeof(struct Nodo));
    aux->valor = 15;
    aux->prox=NULL;
    return l;
}


void ShowList(LInt l){
    while (l){
        printf("%d\n",l->valor);
        l=l->prox;
    }
}

void ShowList2(LInt l){
   if (l){
       printf("%d",l->valor);
   }
   ShowList2(l->prox);
}

//b)

LInt cons (LInt l, int x){
    LInt aux;
    aux = malloc(sizeof(struct slist));
    aux->valor=x;
    aux->prox = l;
    return aux;
}
// outra forma

LInt cons1 (LInt l,int x){
    Nodo aux = {x,l};
   l=aux;
   return l;
}

//c)

LInt tail (LInt l){
    LInt aux=l->prox;
    free(l);

    return aux;
}

//d)

LInt init (LInt l){
    LInt aux;
    LInt ant;
    ant=l;
    aux=l;
    while (aux->prox){
        ant=aux;
        aux=aux->prox;
    }
    ant->prox=NULL;
    free(aux);
    return l;
}

//e)

LInt snoc (LInt l, int x){
    LInt aux;
    aux=l;
    while(l){
        l=l->prox;
    }
    l=malloc(sizeof(Nodo));
    l->valor=x;
    l->prox=NULL;

    return aux;

}

LInt concat (LInt a, LInt b){
    LInt aux=a;
    if (a==NULL && b!=NULL){return b;}
    else if (a!=NULL && b==NULL){return a;}
    else if (a!=NULL && b!=NULL){
        while(aux){
            aux=aux->prox;
        }
        aux=b;
        return a;
    }
}

//2

typedef struct aluno(){
    char nome[60];
    char numero[7];
    float nota;
}Aluno

typedef struct turma *Lturma;

typedef struct Turma
{
    Aluno aluno;
    Lturma prox;
}Turma;

void showTurma (Lturma t){
    while (t){
    printf("%s %s %d",Turma->aluno.nome,Turma->aluno.numero,Turma->aluno.nota);
    t=t->prox;
    }
}

int main () {
    ALuno a1={"Joao","A22222",15.5},a2={"Ana","A32323",14.3},a3={"Filipe","A44751",12.7};
    Lturma t1;
    t1=cons(cons(cons(t1,a3),a2),a1);
    showTurma(t1);
    return 0;
}


