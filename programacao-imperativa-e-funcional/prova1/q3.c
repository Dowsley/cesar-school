#include <stdlib.h>
#include <stdio.h>

int* getNEvenNumbers(int N)
{
	int* evenNumbers = malloc(sizeof(int*));
	int init = 2;

	for (int i = 0; i < N; i++)
	{
		evenNumbers[i] = init;
		init += 2;
	}

	return evenNumbers;
}

int main(int argc, char *argv[])
{
	int N = atoi(argv[1]);

	int* evenNumbers = getNEvenNumbers(N);

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", evenNumbers[i]);
	}

	return 0;
}