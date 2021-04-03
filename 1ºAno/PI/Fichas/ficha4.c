#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 1

int maiusculas (char s[]){
    int i=0,conta=0;
    for (;s[i];i++){
        s[i]=toupper(s[i]);
        conta++;
    }
    return conta;
}

//2

int contalinhas (char s[]){
    int i=0,conta=0;
    for (;s[i];i++){
        if (s[i]=='\n'){conta++;}
    }
    return conta;
}

//3

int contaPal (char s[]) {
    int i=0,conta=0;
    for (;s[i];i++){
        if (isspace(s[i]))
        if (!isspace(s[i]) && isspace(s[i+1])){
            conta++;
        }
        if(!isspace(s[i]) && s[i+1]=='\0') {conta++;};
        
    }
    return conta;
}

//4

int procura (char *p, char *ps[], int N){
    int i=0;
    for(;i<N;i++)
    {
        if (strcmp(p,ps[i])==0){
            return i;
        }
    }
    return i;
}


int main () {
    /*char t[20] = {"igualdade"};
    int x;
    x=maiusculas(t);
    printf("%d\n",x);*/
    return 0;
}