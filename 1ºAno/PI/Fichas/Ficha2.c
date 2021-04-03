#include <stdio.h>

//1

float multInt (int n, float m){
	float r;
	for(r=0;n>0;n--) {
		r+=m;
	}
	return printf("%.2f\n",r);
}

//2

float multInt2 (int n, float m) {
	int soma=0;
	while (n>=1){
		if(n%2==1){
			soma=soma+m;
			n=n/2;
			m=m*2;
		}else{
			n=n/2;
			m=m*2;
		}
	}
	return printf("O valor é:%d\n",soma);
}

//Exercício 3

//int mdc (int a,int b) {


//Exercício 4

int mdc2 (int a, int b){
	if (a==b) {
		printf("%d\n",a);
	}else {
	while (a>0 && b>0) {
		if (a>b){
			a=a-b;
		}else {
			b=b-a;
		}
	}
	if (a==0) {
	 	return printf("%d\n",b);
	}else {
		return printf("%d\n",a);
	}
}
}

//Exercício 5 
//Exercício 6 
// a)
int fib (int n) {
	int x=0;

	if (n<2){
		return 1;
	}
	if (n>=2){
		return fib(n-1)+fib(n-2);
	}
}


int main () {
	//Exercício 1:
	/*int n;
	float m;

	printf("Insira o valor m:");
	scanf("%f",&m);

	printf("Insira o valor de n:");
	scanf ("%d",&n);*/

	// multiInt1(n,m);
	// multInt2 (n,m);
	// mdc (n,m);
	// mdc2 (n,m);
	fib (5);
	return 0;
}