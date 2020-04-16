/* DAR SWAP NUM ARRAY SEM USAR ARRAY AUXILIAR. */
#include <stdio.h>

void swap (int*);



int main()
{
	int array[5] = {1,2,3,4,5};

	swap(array);

	for (int c = 0; c < 5; c++)
		printf("%d ", array[c]);
	
	return 0;
}


void swap(int* array)
{

	for (int i = 0, j = 4; i != j; i++, j--)
	{
		int tempi = array[i];
		int tempj = array[j];
		array[i] = tempj;
		array[j] = tempi;

		if (i > j) break;
	}
}