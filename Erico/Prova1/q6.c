#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *callback (int*,int)
{

}callback;

void par(int* array, int len)
{

}

void impar(int* array, int len)
{

}

int main(int argc, char *argv[])
{
	int len = argc - 1;
	int* array = malloc(len * sizeof(int));

	for (int i = 1; i < argc; i++)
		array[i-1] = atoi(argv[i]);

		

	return 0;
}