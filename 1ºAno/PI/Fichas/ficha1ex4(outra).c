//1

#include <stdio.h>
int linha (int num) {
	int i;
	for (i=1;i<=num; i++) {
		putchar ('#');
	}
	putchar ('\n');

	return num;

}

int main () {

linha (1);
linha (2);
linha (3);
linha (4);
linha (5);
linha (4);
linha (3);
linha (2);
linha (1);
}













