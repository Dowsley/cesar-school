#include <stdio.h>
#include <stdlib.h>

int* sequenceCheck(int array[], int size);

int main(int argc, char *argv[])
{
	// Place numbers in array.
	int array[argc];
	for (int i = 1; i < argc; i++)
		array[i-1] = atoi(argv[i]);

	int* index;

	index = sequenceCheck(array, argc-1);
	for (int i = index[0]; i <= index[1]; i++)
		printf("%d ", array[i]);
	
	return 0;
}

int* sequenceCheck(int array[], int size)
{
	int old_sum = -2147483647;
	int sum = 0;
	int* index = malloc(sizeof(int)*2);

	for (int start = 0; start < size; start++)
	{
		for (int end = start; end < size; end++)
		{
			sum = 0;
			for (int i = start; i <= end; i++)
			{
				sum += array[i];
			}

			// New indexes
			if (sum > old_sum)
			{
				old_sum = sum;
				index[0] = start;
				index[1] = end;
			}

			else if (sum == old_sum)
			{
				// Shortest subsequence wins
				if (end-start < index[1]-index[0])
				{
					index[0] = start;
					index[0] = end;
				}
			}
		}
	}

	return index;
}