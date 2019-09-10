#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int anagrama(char* p1, char* p2)
{
	int size1 = strlen(p1);
	int size2 = strlen(p2);
	
	if (size1 == size2)
	{
		int soma1 = 0, soma2 = 0;
		for (int i = 0; i < size1; i++)
		{
			soma1 += p1[i];
			soma2 += p2[i];
		}

		if (soma1 == soma2)
			return 1;
	}

	return 0;
}


int main(int argc, char *argv[])
{
	int x = anagrama(argv[1], argv[2]);
	printf("%d\n", x);

	return 0;
}