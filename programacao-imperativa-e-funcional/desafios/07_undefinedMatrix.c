#include <stdlib.h>
#include <stdio.h>


float** mat(int i, int j)
{
	float** matrix = calloc(i, sizeof(float*));

	for (int i = 0; i < j; i++)
		matrix[i] = calloc(i, sizeof(float));

	return matrix;
}

int main()
{
	float** matrix = mat(3,3);
	matrix[1][1] = 234;
	printf("%f\n", matrix[1][1]);
	return 0;
}