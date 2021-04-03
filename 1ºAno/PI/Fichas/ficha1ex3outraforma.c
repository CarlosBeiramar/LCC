#include <stdio.h>
void quadrado (int x) {
	int i,j;
	for (i=1; i<=x; i++){
		for (j=1; j<=x; j++)
			if (j % 2 == 0)
				putchar ('_');
			else
				putchar ('#');
			putchar ('\n');
		}   

}

int main ()  {
	quadrado (5);
	return 0;
}


