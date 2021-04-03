#include <stdio.h>

//1

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

//2

//3

int maxInd (int v[], int N) {
    int i=0,max=v[0],indice=0;
    for (i=1;i<N;i++){
        if (v[i]>max){
            max=v[i];
            indice=i;
        }
    }
    return indice;
}

//4


int main () {
    int N[7] = {1,2,4,5,6,7,8};
    int x=3;
    //insere (N,7,x);
    int c=maxInd(N,7);
        printf("%d",c);

    printf("\n");
    return 0;
}