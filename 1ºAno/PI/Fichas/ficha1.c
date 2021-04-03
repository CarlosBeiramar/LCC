#include <stdio.h>
//1

/* 1- O output será x=12 y=16
   2- O output será x=0 e y=lixo na memória
   3- O output será A 65, B 66 2 50, b 98
   4- O output será x=100 e y=200
   5- O output será x=129 y= -71, x=128 y=-72 */

//2

/* 1- 3 5
   
   2- x=11 y= 66
   
   3- o x nunca chega a ser o valor de 11
   
   4- _#_#_#_#_#_#_#_#_#_#
   
   5- abcdefg
	  bcdefg
      cdefg
      defg
      efg
      fg
      g
   
   6- 1
      01
      11
      001
      101
      011
      111
      0001
      1001
      0101
      1101
      0011
      1011
      0111
      1111 */

//Exercícios de funções

//2

void ex2 () {
	int i,j,lado;

	printf("Insira a medida do quadrado: ");
	scanf("%d",&lado);

	for (i=0;i<lado;i++){
		for (j=0;j<lado;j++) {
			putchar ('#');
		}
		putchar ('\n');
	}
}

//3

void ex3 () {
	int i,j,lado;

	printf("Insira a medida do quadrado: ");
	scanf ("%d",&lado);

	for (i=1;i<=lado;i++) {
		for (j=1;j<=lado;j++) {
			if (i%2!=0) {
				if (j%2!=0) 
				{
					putchar ('#');
				}
			 	else 
			 		{
			 			putchar ('_');
			 		}
			}
			if (i%2==0) {

				if (j%2!=0) 
					{
						putchar ('_');
					}

				else 
					{
						putchar ('#');
					}
			}
		}
	putchar ('\n');
	}
}



//4

void ex4v1 () {
	int i,j,tam;
	
	printf("Insira até onde quer o máximo da pirâmide: ");
	scanf("%d",&tam);

	for (i=1;i<=tam;i++){
		for (j=0;j<i;j++){
			putchar ('#');
		}
		putchar ('\n');
		}
	for (i=tam;i>1;i--) {
		for (j=1;j<i;j++){
			putchar ('#');
		}
		putchar ('\n');
	  }
	}

void ex4v2 () {
	int i,j=0,tam;

	printf("Insira quantas linhas vai ter a pirâmide: ");
	scanf ("%d",&tam);

 	for (i=0;i<=tam;i++) {
 		for (j=0;j<=tam-i;j++)
 		putchar (' ');
 		for (j=0;j<2*i+1;j++)
 			putchar ('#');
 	putchar ('\n');
  }
}


//

int main () {
	// ex3 ();
	// ex4v1 ();
	ex4v2 ();
	return 0;
}






