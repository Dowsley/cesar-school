#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void par(int n)
{
	if ( (n%2) == 0 && n != 0)
		printf("%d ", n);
}


void impar(int n)
{
	if ( (n%2) != 0 && n != 0)
		printf("%d ", n);
}

void callback(int* array, int len, void (*printNumber)(int))
{
	for (int i = 0; i < len; i++)
		printNumber(array[i]);
}

int main(int argc, char *argv[])
{
	char choice = argv[1][0];

	int len = argc - 2;
	int* array = malloc(len * sizeof(int));

	for (int i = 2, j = 0; i < argc; i++, j++)
		array[j] = atoi(argv[i]);

	if (choice == 'p')
		callback(array, len, par);
	else
		callback(array, len, impar);

	return 0;
}