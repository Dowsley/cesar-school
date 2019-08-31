/* 2. Converta a temperatura de Fahrenheit para Celsius e vice-versa */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INICIO 0
#define FIM 300
#define INCR 20


int main()
{
	int f;
	printf("| F |\t|   C  |\n");
	
	for (f = INICIO; f <= FIM; f += INCR)
	{

		printf("|%3d|\t|%6.2f|\n", f, (5.0/9.0) * (f - 32));

	} 
}