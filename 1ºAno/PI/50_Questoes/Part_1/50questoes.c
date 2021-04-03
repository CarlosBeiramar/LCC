#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
   int x, y;
} Posicao;

// 1

void ex1 () {
	int i,j=0;
	scanf ("%d",&i);
	while (i!=0) {
		if (i>j) {
			j=i;
			scanf ("%d",&i);
		}
		else
		{
		 	scanf ("%d",&i);
		}
	}
	printf("o maior numero é: %d\n",j);
}


// 2

void ex2 () {
	int i,j=0,soma=0,nelementos=0;
	double media;	
	scanf ("%d",&i);
	while (i!=0) {
		if (i>j){
			j=i;
			soma = soma + i;
			nelementos++;
		}
		else
		{
			soma=soma+i;
			nelementos++;
			scanf ("%d",&i);

		}
	}
	media = (double) soma/nelementos;
	printf("a media é: %.2f\n",media);
}

// 3

void ex3 () {
	int x,y,z;
	y=0;z=0;
	printf("Insira um sequencia de numeros:\n");
	scanf ("%d",&x);
	while (x!=0) {
		if(x>y) {
			z=y;
			y=x;
			scanf ("%d",&x);
		}
    
		if (x>z) {
			z=x;
			scanf ("%d",&x);
		}
	}
	printf("%d\n",z);

}

//4

int bitsUm (int x){
    int soma=0;
    while (x!=0) {
        if (x%2==1) {
            soma++;
            x=x/2;
        }else {
            x=x/2;
        }
    }
    return soma;
}

//5

int trailingZ (unsigned int n) {
	int res=0;
	while (n%2==0) {
		res++;
		n=n/2;
	}
	return res;
}

//6

int qDig (unsigned int n) {
	int res=1;
	while (n> 0) {
		res++;
		n=n/10;
	}
	return res;
}

//7

char *mystrcat(char s1[], char s2[]) {
    int j=0,i=0;
    while (s1[i]!='\0') {
        i++;
    }
    while (s2[j]!='\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i]='\0';
    return s1;
}

//8

char *mystrcpy(char s1[], const char s2[]) {
    int i=0;
    for (i=0;s2[i]!='\0';i++){
        s1[i]=s2[i];
    }
    return s1;
}

//9

int mystrcmp(char s1[], char s2[]) {
    int i=0,j=0;
    while (s1[i]!='\0' && s2[j]!='\0'){
        if (s1[i]==s2[j]){
            i++;
            j++;
        }else {break;}
    }
    if (s1[i]==s2[j]){return 0;}
    if (s1[i]<s2[j]){return -1;}
    if (s1[i]>s2[j]){return 1;}
return 0;
}

//10

char *mystrstr (char s1[], char s2[]) {
     int i=0,j=0,k,encontrado=0;
     if(s1[i]=='\0' && s2[j]=='\0'){return s1;}
     for(i=0;s1[i] && !encontrado;i++){
         encontrado=1;
         for(j=i,k=0;s1[j] && s2[k] && encontrado;j++,k++){
             if(s1[j]!=s2[k]){encontrado=0;}
         }
}
return (!s2[k] && encontrado?s1+i-1:NULL);
}

//11
void strrev (char s[]) {
    int i=0,j=0;
    while (s[j]!='\0'){
        j++;
    }
    char aux[strlen(s)];
    j=j-1;
    while (j>=0) {
        aux[i]=s[j];
        i++;
        j--;
    }
    aux[i]='\0';
    for (i=0;aux[i]!='\0';i++){
        s[i]=aux[i];
    }
}

//Outra maneira de fazer 

void swap(char a[], int b, int c) {
    char temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

void strrev (char s[]) {
    int i=0,final=0;
    for(final=0;s[final]!='\0';final++);
    
    final=final-1;
    
    while (i<final){
        swap(s,i,final);
        i++;final--;
    }
}

// 12

int vogais(char c){
    int res;
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return 1;
    }
    return 0;
}

void strnoV (char t[]){
    char x[strlen (t) +1];
    int i,j=0;
    for(i=0;t[i]!='\0';i++){
        if (vogais (t[i])==0){
            x[j]=t[i];
            j++;
        }
    }
    x[j]='\0';
    for (i=0;x[i]!='\0';i++){
        t[i]=x[i];
    }
    t[i]='\0';
    
}

//outra maneira

void strnoV (char t[]){
   int i=0,k=0;
   for (;t[i];i++){
       if (vogais(t[i])){
           for (k=i;t[k]!='\0';k++){
               t[k]=t[k+1];
           }
           i--;
       }
   }
}


// 13

// 14

int conta(char x,char s[]){
    int i=0,conta=0;
    for (i=0;s[i];i++){
        if (s[i]==x){
            conta++;
        }
    }
    return conta;
}

char charMaisfreq (char s[]) {
    int i=0,x=0,res;
    char c;
    for(i=0;s[i]!='\0';i++){
        x=conta(s[i],s);
        if(x>res){
            res=x;
            c=s[i];
        }
    }
    return c;
}
//15

int iguaisConsecutivos (char s[]){
    int i=0,t=1,conta = 0;
    for (i=0;s[i]!='\0';i++){
        while (s[i]==s[i+1]){
            i++;
            t++;
        }
        if (s[i]!=s[i+1]){
            if (t>conta){
             conta=t;
             }
             t=1;
        }
       }
    return conta;
}

//16

void eliminaRepseguidas (char s[]){
    int i=0,j;
    while (s[i]!='\0'){
        if (s[i]==s[i+1]){
            for (j=i;s[j]!='\0';j++){
                s[j]=s[j+1];
            }
        }else {
            i++;
        }
    }
    for (i=0;s[i]!='\0';i++){
        printf ("%c",s[i]); 
        }
    printf ("\n");

}

int difConsecutivos(char s[]) {
    int i=0,conta=1;
    eliminaRepseguidas(s);
    for (i=0;s[i]!='\0';i++){
        conta++;
    }
    printf("%d\n",conta);
 return conta;   
}

/*int main () {
    int i=0,j;
    char s[50] = "mundo cruel!!!";
    eliminaRepseguidas (s);
    difConsecutivos (s);
    return 0;
}*/

//17

int maiorPrefixo (char s1 [], char s2 []) {
    int i=0,j=0,conta=0;
    while (s1[i]==s2[j] && s1[i]!='\0' && s2[j]!='\0'){
        conta++;
        i++;
        j++;
    }
    return conta;
}

//18

int maiorSufixo (char s1 [], char s2 []) {
    int i=0,j=0,conta=0;
     while (s1[i]!='\0'){
         i++;
     }
     while (s2[j]!='\0'){
         j++;
     }
     i=i-1;
     j=j-1;
    while (s1[i]==s2[j]){
        conta++;
        i--;
        j--;
    }
    return conta;
}

//19
int sufPref (char s1[], char s2[]) {
  int i=0,j=0,conta=0;
    char *save=s2;
    for(;*s1;++s1){
        if(*s1==*s2){
            s2++;
            res++;
        }
        else{
            res=0;
            s2=save;
        }
    }
    return res;
}

//20
int contaPal (char s[]) {
    int i=0,conta=0;
    for (;s[i];i++){
        if (!isspace(s[i]) && isspace(s[i+1])){
            conta++;
        }
        if(!isspace(s[i]) && s[i+1]=='\0') {conta++;};
        
    }
    return conta;
}

//21

/*int vogais(char c){
    int res;
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return 1;
    }
    return 0;
}*/

int contaVogais (char s[]) {
    int i=0,conta=0;
    for (i=0;s[i]!='\0';i++){
        if (vogais(s[i])){
            conta++;
        }
    }
    return conta;
}

//22

int contida(char a[], char b[])
{
    int i, j, c;
    c = 1;
    for (i = 0; a[i] && c; i++)
    {
        c = 0;
        for (j = 0; b[j] && !c; j++)
            if (a[i] == b[j])
                c = 1;
    }
    return c;
}

//23

int palindroma (char s[]) {
    int j=0,i=0;
    for (;s[j];j++);
    j=j-1;
    for (i=0;s[i];i++){
        if (s[i]==s[j]){
            j--;
        }else {
            return 0;
        }
    }
    return 1;
}

//24

int remRep (char texto []) {
    int i=0,j=0;
    for (;texto[i]!='\0';i++){
        if(texto[i]==texto[i+1]){
            for(j=i+1;texto[j]!='\0';j++){
                texto[j]=texto[j+1];
            }
            i=i-1;
        }
    }
    return strlen(texto);
}

//25
int limpaEspacos (char texto[]) {
    int r=0,i=0,j=0;
    for(;texto[i];i++){
        if (isspace(texto[i]) && isspace(texto[i+1])){
            for (j=i;texto[j];j++){
                texto[j]=texto[j+1];
            }
            i=i-1;
        }
    }
    return strlen(texto);
}

//26

  void insere (int s[], int N, int x){
   int i=N;
   for (;i>=0;i--){
       if(x<s[i-1]){
           s[i]=s[i-1];
       }
       if(x>=s[i-1] && i!=0){
           s[i]=x;
           x=s[i-1];
       }
       if(i==0){
           s[i]=x;
       }
     }
   }

//27
   void merge (int r [], int a[], int b[], int na, int nb){
       int i=0,j=0;
       for(;i<na;i++){
           r[i]=a[i];
       }
       for (j=0;i+j<na+nb;j++){
           insere(r,na+j,b[j]);
       }
   }
 
//28

int crescente (int a[], int i, int j){
       int r=1;
       for(;i<j;i++){
           if (a[i]<a[i+1])
           if (a[i]>a[i+1]){r=0;return r;}
       }
       return r;
   }

//29

 int retiraNeg (int v[], int N){
       int r =0,i=0,conta=0;
       for(;i<N;i++){
           if (v[i]>-1){
               v[r]=v[i];
               r++;
           }
           
       }
       return r;
   }

   // Outra maneira

      int retiraNeg (int v[], int N){
       int i=0,j;
       for(;i<N;i++){
           if(v[i]<0){
               for(j=i;j<N;j++){
                   v[j]=v[j+1];
               }
               N--;
               i--;
           }
       }
       return i;
   }


//30


//31
int maisFreq (int v[], int N){
       int i=1,j=1,conta=1,t=0;
       int c;
       while(i<N){
           while (v[i]==v[i-1]){
               conta++;
               i++;
           }
           if(conta>t){t=conta;c=v[i-1];conta=1;}
            i++;
        }
       return c;
   }

//32 

int maxCresc (int v[], int N) {
       int i=0,melhor=1,t=1;
       for(i=0;i<N && v[i]<=v[i+1];i++){melhor++;}
       i++;
       for(;i<N;i++){
           if(v[i]<=v[i+1]){
               t++;   
           }else{ 
               if(t>=melhor){melhor=t;}
               t=1;
           }
       }
       return melhor;
   }

//33
int elimRep (int v[], int N) {
       int i=0,j,t;
        for(i=0;i<N;i++){
            for(j=i+1;j<N;){
                if(v[i]==v[j]){
                    for(t=j;t<N;t++){
                        v[t]=v[t+1];
                        }
                    N--;
                    j--;
                    }
                
                    }
                }
       return N;
   }

//34
int elimRepOrd (int v[],int N) {
 int i=0,j,t;
        for(i=0;i<N;i++){
            for(j=i+1;j<N;){
                if(v[i]==v[j]){
                    for(t=j;t<N;t++){
                        v[t]=v[t+1];
                        }
                    N--;
                    j--;
                    }
                
                    }
                }
       return N;
   }

//35
 int comunsOrd (int a[], int na, int b[], int nb){
        int i=0,j=0,comuns=0;
       while(i<na && j<nb){
           if(a[i]==b[j]){
               j++;i++;
               comuns++;
           }
           else if(a[i]<b[j]){
               i++;
           }
           else if(a[i]>b[j]){
               j++;
           }
       }
       return comuns;
   }

//36
  int comuns (int a[], int na, int b[], int nb){
      int res=0,j=0,i=0,encontrado=0;
      while(i<na){
          j=0;
          encontrado=0;
          while(j<nb && !encontrado){
              if(a[i]==b[j]){
                  res++;
                  encontrado=1;
              }
              j++;
          }
          i++;
      }
      return res;
   }

//37

int minInd (int v[], int n) {
   int indice=0,i,min=v[0];
   for (i=1;i<n;i++){
       if (v[i]<min){
           min=v[i];
           indice=i;
       }
   }
   return indice;
}

//38

void somasAc (int v[], int Ac [], int N){
   int i=0,k=0;
   for(;i<N;i++){
       k+=v[i];
       Ac[i]=k;
   }
   
}

//39

int triSup (int N, int m [N][N]) {
    int linhas=0,colunas=0,res=0;
    for(;linhas<N;linhas++){
        for(;colunas<linhas;colunas++){
            if(m[linhas][colunas]!=0){
                return 0;
            }
        }
    }
    return 1;
}
//40

void transposta (int N, float m [N][N]) {
   int linhas=0,colunas=0;
   float tmp=0;
   for(linhas=0;linhas<N;linhas++){
       for(colunas=0;colunas<linhas;colunas++){
           tmp=m[linhas][colunas];
           m[linhas][colunas]=m[colunas][linhas];
           m[colunas][linhas]=tmp;
       }
   }
}

//41

void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int colunas=0,linhas=0;
    for(linhas=0;linhas<N;linhas++){
        for(colunas=0;colunas<M;colunas++){
            a[linhas][colunas]+=b[linhas][colunas];
        }
    }
}

//42

   int unionSet (int N, int v1[N], int v2[N], int r[N]){
       int i=0,c=0;
       for(i=0;i<N;i++){
          if(v1[i]==1 || v2[i]==1){
              r[c]=1;
              c++;
          }else{
              r[c]=0;
              c++;
          }
   }
   return c;
   }

//43

   int intersectSet (int N, int v1[N], int v2[N], int r[N]){
       int i=0,c=0;
       for(i=0;i<N;i++){
           if(v1[i]==1 && v2[i]==1){
               r[c]=1;
               c++;
           }else {
               r[c]=0;
               c++;
           }
       }
       return c;
   }

//44

int min (int a,int b){
    if (a<b){return a;}
    else{return b;}
}
   int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
      int i=0;
      for(i=0;i<N;i++){
          r[i]=min(v1[i],v2[i]);
      }
      return i;
}
//45
int max (int a, int b){
    if(a>b){return a;}
    else{return b;}
}
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i=0;   
    for (i=0;i<N;i++){
        r[i]=max(v1[i],v2[i]);
    }
    return 0;
}

//46

int cardinalMSet (int N, int v[N]){
   	  int c=0,i=0;
   	  for (i=0;i<N;i++){
   	      c+=v[i];
   	  }
   	  return c;
 }

//47

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
   int i=0;
   for (i=0;i<N;i++){
       if(mov[i]==Norte){
           inicial.y++;
       }
       if (mov[i]==Sul){
           inicial.y--;
       }
       if(mov[i]==Oeste){
           inicial.x--;
       }
       if(mov[i]==Este){
           inicial.x++;
       }
   }
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i=0;
    
        for(i=0; inicial.x != final.x || inicial.y!=final.y;i++){
            if(i==N){return -1;}
            
            if(inicial.x<final.x){
                inicial.x++;
                mov[i]=Este;
            }
            else if(inicial.x>final.x){
                inicial.x--;
                mov[i]=Oeste;
            }
            else if(inicial.y<final.y){
                inicial.y++;
                mov[i]=Norte;
            }
            else if(inicial.y>final.y){
                inicial.y--;
                mov[i]=Sul;
            }
        }
    return i;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N) {
    int i=0,conta=0;
    for (i=0;i<N;i++){                              
       if(pos[i].x==p.x+1 && pos[i].y==p.y){
           conta++;
       }
       if(pos[i].x==p.x-1 && pos[i].y==p.y){
           conta++;
       }
       if(pos[i].y==p.y+1 && pos[i].x==p.x){
           conta++;
       }
       if(pos[i].y==p.y-1 && pos[i].x==p.x){
           conta++;
       }
    }
    return conta;
}
//----------------------------------------------------------NOVAS 50----------------------------------------------------------------
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int, LInt);
int length (LInt l);


LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

ABin newABin (int, ABin, ABin);

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

//1

int length (LInt l){
    int comp=0;
    while (l!=NULL){
        comp++;
        l=l->prox;
    }
    return comp;
}

//2

void freeL (LInt l){
    LInt aux;
    while (l!=NULL){
        aux=l;
        l=l->prox;
        free(aux);
    }
}

//3

void imprimeL (LInt){
    while (l){
        printf ("%d\n",l->valor);
        l=l->prox;
    }
}

//4

LInt reverseL (LInt l){
   LInt r=NULL,x;
   while(l){
       x=l;l=l->prox;
       x->prox=r;r=x;
   } 
    return r;
}

//5

void insertOrd (LInt *l, int x){
    LInt insere;
    while(*l && (*l)->valor<x){
        l=&((*l)->prox);
    }
    if (*l!=NULL){
        insere=(LInt)malloc(sizeof(struct lligada));
        insere->valor=x;
        insere->prox=*l;
        *l=insere;
    }
    else if(*l==NULL){
        *l=(LInt)malloc(sizeof(struct lligada));
        (*l)->valor=x;
        (*l)->prox=NULL;
    }
}

//6
int removeOneOrd (LInt *l, int x){
    int res=1;
    LInt aux;
    while(*l && ((*l)->valor!=x)){
        l=&((*l)->prox);
    }
    if(*l){
        aux=(*l)->prox;
        free(*l);
        *l=aux;
        res=0;
    }
    return res;
}

//7

void merge (LInt *r, LInt l1, LInt l2){
       while(l1 && l2){
           if(l1->valor<l2->valor){
               *r=(LInt)malloc(sizeof(struct lligada));
               (*r)->valor=l1->valor;
               (*r)->prox=NULL;
               r=&((*r)->prox);
               l1=l1->prox;
           }else{
               *r=(LInt)malloc(sizeof(struct lligada));
               (*r)->valor=l2->valor;
               (*r)->prox=NULL;
               r=&((*r)->prox);
               l2=l2->prox;
           }
       }
       if(!l1){
       *r=l2;
        }
        if(!l2){
       *r=l1;
        }
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    LInt *aux1,*aux2;
    aux1=mx;
    aux2=Mx;
    while(l){
        if(x>l->valor){
            (*aux1)=(LInt)malloc(sizeof(struct lligada));
            (*aux1)->valor=l->valor;
            aux1=&((*aux1)->prox);
        }
         else{
            (*aux2)=(LInt)malloc(sizeof(struct lligada));
            (*aux2)->valor=l->valor;
            aux2=&((*aux2)->prox);
        }
        l=l->prox;
    }
}

//9

LInt parteAmeio (LInt *l){
   int elementos=0;
    LInt aux,y,*aux2;
    aux=*l;aux2=&y;
    
    while(aux){
        elementos++;
        aux=aux->prox;
    }
    
    elementos=elementos/2;
    aux=*l;
    while(elementos>0){
        *aux2=malloc(sizeof(struct lligada));
        (*aux2)->valor=(*l)->valor;
        aux2=&((*aux2)->prox);
        aux=(*l)->prox;
        free(*l);
        *l=aux;
        elementos--;
    }
    (*aux2)=NULL;
    return y;
}

//10
int removeAll (LInt *l, int x){
   LInt aux;
   int conta=0;
   while(*l){
       if((*l)->valor==x){
           aux=(*l)->prox;
           free(*l);
           *l=aux;
           conta++;
       }else{
       l=&((*l)->prox);
       }
   }
   return conta;
}

//11



//12

int maiorL(LInt *l){
    int x=0;
    while (*l){
        if((*l)->valor>x){
            x=(*l)->valor;
        }
        l=&((*l)->prox);
    }
    return x;
}
int removeMaiorL (LInt *l){
    int x;
    LInt aux;
    x=maiorL(l);
    while(*l && (*l)->valor!=x){
        l=&((*l)->prox);
    }
    aux=(*l)->prox;
    free(*l);
    *l=aux;
    return x;
}

//13

void init (LInt *l){
    while(*l && (*l)->prox){
        l=&((*l)->prox);
    }
    free(*l);
    (*l)=NULL;
}

//14

void appendL (LInt *l, int x){
    while(*l){
        l=&((*l)->prox);
    }
    *l=(LInt)malloc(sizeof(struct lligada));
    (*l)->valor=x;
    (*l)->prox=NULL;
}

//15

void concatL (LInt *a, LInt b){
    while(*a){
        a=&((*a)->prox);
    }
    *a=b;
}
//16 

LInt cloneL (LInt l){
    LInt r,*e;
    e=&r;
    while(l!=NULL){
        *e= malloc(sizeof(struct lligada));
        (*e)->valor=l->valor;
        l=l->prox;
        e=&((*e)->prox);
    }
    (*e)=NULL;
    return r;
}

//17
LInt Rev(LInt l){
    LInt x, r=NULL;
    while(l){
        x=l;l=l->prox;
        x->prox=r;
        r=x;
    }
    return r;
}

LInt clone(LInt l){
    LInt r,*e;
    e=&r;
    while(l){
        *e=malloc(sizeof(struct lligada));
        (*e)->valor=l->valor;
        e=&((*e)->prox);
        l=l->prox;
    }
    return r;
}

LInt cloneRev (LInt l){
   LInt r;
   r=Rev(l);
   r=clone(r);
    return r;
}

//18

int maximo (LInt l){
    int res=l->valor;
    l=l->prox;
    while(l){
        if (l->valor>res){
            res=l->valor;
        }
        l=l->prox;
    }
    return res;
}

//19

int take (int n, LInt *l){
    LInt *aux;
    aux=l;
    if (length(*l)<=n){
        return length(*l);
    }else{
        while(*l && n>0){
            l=&((*l)->prox);
            n--;
        }
        free(*l);
        *l=NULL;
        return length(*aux);
    }
}

//20

int drop (int n, LInt *l){
    int conta=0;
    LInt r;
    while(*l && n!=0){
        r=(*l)->prox;
        free(*l);
        *l=r;
        conta++;n--;
    }
    return conta;
}

//21

LInt NForward (LInt l, int N){
    while(N>0){
        l=l->prox;
        N--;
    }
    return l;
}

//22

int listToArray (LInt l, int v[], int N){
    int i=0;
    while (l && i<N){
        v[i]=l->valor;
        l=l->prox;
        i++;
    }
    return i;
}
//23

LInt arrayToList (int v[], int N){
    int i=0;
   LInt r,*e;
   e=&r;
   while(i<N){
       *e=malloc(sizeof(struct lligada));
       (*e)->valor=v[i];
       e=&((*e)->prox);
       i++;
   }
   *e=NULL;
    return r;
}

//24 

LInt somasAcL (LInt l) {
    LInt r,*e;
    int soma=0;
    e=&r;
    while(l){
        soma+=l->valor;
        *e=malloc(sizeof(struct lligada));
        (*e)->valor=soma;
        e=&((*e)->prox);
        l=l->prox;
    }
    *e=NULL;
    return r;
}

//26

LInt rotateL (LInt l){
    LInt head,aux;
    int res=0;
    head=l;
    aux=l;
    if(length(l)<=1){return l;}
    else {
        aux=l->prox;
    while(aux){
        res=head->valor;
        head->valor=aux->valor;
        aux->valor=res;
        head=head->prox;aux=aux->prox;
        }
    }
    return l;
}

//27
LInt parte(LInt l){

}

//28

int altura (ABin a){
    int alt=0,alturaesq=0,alturadir=0;
    if (a==NULL){
        return 0;
    }
    else {
        alturaesq=1+altura(a->esq);
        alturadir=1+altura(a->dir);
    }
    if (alturaesq>alturadir){
        alt=alturaesq;
    }
    else{alt=alturadir;}
    
	return alt;
}

//29

ABin cloneAB (ABin a) {
    ABin aux=NULL;
    if (a){
    aux=malloc(sizeof(struct nodo));
    aux->valor=a->valor;
    aux->esq=cloneAB(a->esq);
    aux->dir=cloneAB(a->dir);
    }
    return aux;
}

//30

void mirror (ABin *a) {
    ABin p;
    if(*a){
    p=(*a)->dir;
    (*a)->dir=(*a)->esq;
    (*a)->esq=p;
    
    mirror(&((*a)->dir));
    mirror(&((*a)->esq));
    }
}

//31

void inorder (ABin a, LInt * l) {
    LInt p;
    if(a){
        inorder(a->dir,l);
        p=*l;
        *l=(LInt)malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
        inorder(a->esq,l);
    }
}

//32

void preorder (ABin a, LInt * l) {
   LInt p;
   if(a){
       preorder(a->dir,l);
       preorder(a->esq,l);
       p=*l;
       (*l)=(LInt)malloc(sizeof(struct lligada));
       (*l)->valor=a->valor;
       (*l)->prox=p;
   }
}

//33

 void postorder (ABin a, LInt * l) {
    LInt p;
    if(a){
        p=*l;
        (*l)=(LInt)malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
        postorder(a->dir,l);
        postorder(a->esq,l);
    }
}

//35

int freeAB (ABin a) {
    int conta=0;
    if(a){
        free(a);conta++;
        conta+=freeAB(a->esq);
        conta+=freeAB(a->dir);
    }
    return conta;
}

//39

int nivelV (ABin a, int n, int v[]) {
    int indice = 0;
    if(a){
        if(n==1){
           v[indice]=a->valor;
           indice++;
        }else{
            indice+=nivelV(a->esq,n-1,v);
            indice+=nivelV(a->dir,n-1,v+indice);
        }
    }
    return indice;
}


//41

int somasAux(ABin a){
    int soma=0;
    if(a){
        soma=a->valor;
        soma+=somasAux(a->esq)+somasAux(a->dir);
    }
    return soma;
}

ABin somasAcA (ABin a) {
    ABin res=NULL;
    if(a){
        res=(ABin)malloc(sizeof(struct nodo));
        res->valor=somasAux(a);
        res->dir=somasAcA(a->dir);
        res->esq=somasAcA(a->esq);
    }
    return res;
}

//42

int contaFolhas (ABin a) {
    int conta=0;
   if(a){
       if(a->esq==NULL && a->dir==NULL){
           conta++;
       }else{
           conta+=contaFolhas(a->esq);
           conta+=contaFolhas(a->dir);
       }
   }
    return conta;
}

//43

ABin cloneMirror (ABin a) {
     ABin clone=NULL;
    if(a){
        clone = (ABin)malloc(sizeof(struct nodo));
        clone->valor=a->valor;
        clone->esq=cloneMirror(a->dir);
        clone->dir=cloneMirror(a->esq);
    }
    return clone;
}

//45

int lookupAB (ABin a, int x) {
    int encontrado=0;
    if(a){
        if(x>a->valor){
            encontrado=lookupAB(a->dir,x);
        }else if(x<a->valor){
            encontrado=lookupAB(a->esq,x);
        }else if(x==a->valor){
            encontrado=1;
        }
    }
    return encontrado;
}

//47

int maiorAB (ABin a) {
    int maior;
    while(a && a->dir){
        a=a->dir;
    }
    maior=a->valor;
    return maior;
}

//51

int maior(ABin a){
    if(a->dir){
        return maior(a->dir);
    }else{
        return a->valor;
    }
}

int menor (ABin a){
    if(a->esq){
        return menor(a->esq);
    }else{
        return a->valor;
    }
}

int deProcura (ABin a) {
    int res=1;
    if(!a){
        return 1;
    }else{
        if(a->esq)res=maior(a->esq)<a->valor;
        if(a->dir)res=res && (menor(a->dir)>a->valor);
        return res && deProcura(a->esq) && deProcura(a->dir);
    }
}

int main () {
	// ex1 ();
	// ex2 ();
	 ex3 ();
	// bitsUm ();
	// trailingZ ();
	// qDig ();
	// *mystrcat ();
	// mystrcmpq();
	return 0;
}