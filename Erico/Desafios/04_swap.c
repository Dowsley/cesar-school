#include <stdio.h>
// Trocar 2 valores de 2 variaveis e ntre si: 


void swap(int *el1, int *el2)
{
	int temp;
	temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}

int main()
{
	int a = 10, b = 20;

	swap(&a, &b);
	
	return 0;
}



// NAO FUNCIONA, POIS O ESCOPO É DIFERENTE
/*
int swap(int, int);

int main()
{
	int x = 3;
	int y = 4;
	swap(x, y);

	printf("%d %d\n", x, y);
	return 0;
}

int swap(int x, int y)
{
	int temp_y = x;
	int temp_x = y;

	x = temp_x;
	y = temp_y;

	return 0;
}
*/