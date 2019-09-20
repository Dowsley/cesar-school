#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int par(int n)
{
	if ( (n%2) == 0 && n != 0)
		printf("%d ", n);
}


int impar(int n)
{
	if ( (n%2) != 0 && n != 0)
		printf("%d ", n);
}

void callback(int* array, int (*p)(int))
{
	int len = sizeof(array) / sizeof(int);
	for (int i = 0; i < len; i++)
		(*p)(array[i]);
}

int main(int argc, char *argv[])
{
	char choice = argv[0][0];
	int len = argc - 1;
	int* array = malloc(len * sizeof(int));

	for (int i = 1; i < argc; i++)
		array[i-1] = atoi(argv[i]);

	if (choice == 'p')
		int (*p)(int) = &par;
	else
		int (*p)(int) = &impar;

	callback(array, p);

	return 0;
}