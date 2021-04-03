#include <stdio.h>

int main (int argc, char *argv[]){      //argc = argument counter; char*argv[] é um apontador para um array de strings;
    FILE *input;
    Dicionario d1;
    initDic(&d1);                        //p.exe para executar (argc=1,argv{"p.exe"});
    int r=0, count=0;                   //p.exe teste.txt (argc=2,argv{"p.exe","teste.txt});
    char word[100];
        if (argc==1) input=stdin;       // se nao receber ficheiro como argumento vai ler do teclado
        else input=fopen(argv[1],"r");  //recebendo o ficheiro abrimos o ficheiro para o ler
        if (input==NULL) r=1;           //se o ficheiro for NULL 
        else {
            while ((fscanf(input,"%s",word)==1)) //quanto encontra palavras incrementa, qd se chega ao fim do ficheiro o fscanf devolve 0
            acrescenta(&d1,word)
            fclose (input);
        printf ("%d palavras\n", count);  
    }
return r;
}


typedef struct entrada {
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario;

//1
void initDic (Dicionario *)
//2
int acrescenta (Dicionario *, char *);
//3
char *maisFreq (Dicionario , int *);


void initDic (Dicionario *d){
    *d=NULL;
}

int acrescenta (Dicionario *d,char *pal){
   Dicionario t=*d;
   Dicionario pr=NULL,ant;
   while(t){
       if(strcmp(t->palavra,p)==0){
           t->ocorr++;
           return t->ocorr;
       }
       else if (strcmp(t->palavra,p)==1){
           pr=malloc(sizeof(struct entrada));
           pr->palavra=p;
           pr->ocorr=1;
           pr->prox=t->prox;
           t=pr;
           return 1;
       }
       else{
           ant=t;t=t->prox;
       }
   }
   if (!t){
       pr=malloc(sizeof(struct entrada));
       pr->palavra=p;
       pr->ocorr=1;
       pr->prox=t;
       ant=pr;
       return 1;
   }
}


/*
char*nova=strdup(palavra);
        ou
char *nova=(char*)malloc(sizeof(strlen(palavra)));
strcpy(nova,palavra);
_________________________________________________________________________
char *strdup (const char *s) {                                           |
    char *d = malloc (strlen (s) + 1);   // Space for length plus nul    |
    if (d == NULL) return NULL;          // No memory                    |
    strcpy (d,s);                        // Copy the characters          |
    return d;                            // Return the new string        |
}                                                                        |
_________________________________________________________________________|
*/

char *maisFreq (Dicionario d, int *c){
    int maior=0;
    char *palavra=NULL;
    while(d){
        if(d->ocorr>maior){
            maior=d->ocorr;
            palavra=d->palavra;
        }
        d=d->prox;
    }
    *c=maior;
    return palavra;
}