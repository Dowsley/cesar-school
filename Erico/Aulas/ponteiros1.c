#include <stdio.h>
#include <stdbool.h>

/* Comentários:
	- Em strings o último elemento é um "\0"
*/


/* Ponteiros e Array */
int main()
{
	int a[10];
	int b;
	int* add;
	add = a;   // ou add = &a[0];
	b = *add   // *add == a[0]

	// *(add + 1) == a[1]  -->  Pega um valor à frente do a[0], já que a[0] == *add
	// add[1] == a[1];

	// a[i] == *(a+i) == i[a]
	// add+i == a+i == &a[i]

	return 0;
}