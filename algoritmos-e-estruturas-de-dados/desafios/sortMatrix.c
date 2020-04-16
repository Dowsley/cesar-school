/* NOTA: 
De acordo com todas as fontes que li, é impossível passar uma matriz como argumento sem ela ter um tamanho fixo.
Pra simular tamanhos eu usei constantes pra simular uma matriz N x M.
O nome da função é "find" */

#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

int* find(int matrix[N][M], int key);

int main()
{
	int matrix[N][M] = {
		{1,12,13},
		{10,40,200},
		{12,41,3024}
	};

	int* x = find(matrix, 3024);
	printf("Number found: %d\n", *x);

	return 0;
}

// Finds number and returns his memory adress in the matrix. Null (0) if it doesn't exist.
int* find(int matrix[N][M], int key)
{	
	// Searches every line (i) of the matrix and checks if the key MAY BE between the first and the last term. 
	for (int i = 0; i < N; i++)
	{
		// Found it
		if (key == matrix[i][0])
			return &matrix[i][0];
		// Found it
		else if (key == matrix[i][M-1])
			return &matrix[i][M-1];

		// If it MAY BE between the first and last term... 
		else if (matrix[i][0] < key && key < matrix[i][M-1])
		{
			// Searches for the key in between.
			for (int j = 0; j < M; j++)
				if (matrix[i][j] == key)
					return &matrix[i][j];
		}	
	}

	return NULL;
}
