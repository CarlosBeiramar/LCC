#include <stdio.h>

//1

//a)
//b) Imprime o valor de j que será 13.

//2

void swapM (int *x, int *y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
	//printf("%d %d\n",x,y);
}

//3

void swap (int v[],int i, int j){
	int x=v[i];
	printf("%d %d\n",v[i],v[j]);
	v[i]=v[j];
	v[j]=x;

	printf("%d %d\n",v[i],v[j]);
}

//4

int soma (int v[], int N){
	int soma=0,i;
	for(i=0;i<N;i++){
		soma+=v[i];
	}
	printf("%d\n",soma);
	return 0;
}

//5

int maximum (int v[], int N, int *m){
	int i=0,x=0;
	for (i=0;i<N;i++){
		if (v[i]>x){
			x=v[i];
		}
	}
	m=&x;
	*m=x;
	printf("%d\n",*m);
	return 0;
}

//6

void quadrados (int q[], int N){
	int i,j=0;
	for (i=0;i<=N;i++){
		q[j]=i*i;
		printf("%d\n",q[j]);
		j++;
	}
		
}
int main () {
    // swapM(5,6);
    int v[]={1,2,3,4,5};
    int q[]={};
    // swap(v,0,2);
    // soma (v,5);
    // maximum (v,5,0);
    // quadrados (q,10);
	return 0;
}