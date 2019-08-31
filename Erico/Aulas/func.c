#include <stdio.h>

/* 
- "Protótipos", dizem a entrada e a saída da função antes do main iniciar. Definir nomes não é obrigatório.
- O código será definido depois. É melhor para o compilador, e para organização.
- Em C não dá para definir funções dentro de funções. 
*/
long fact_recusive(int);
long fact_loop(int);

int main()
{
	int n;
	long f;



	return 0;
}

long fact_recusive(int n)
{
	if (n == 0)
		return 1;
	else
		return (n * fact_recusive(n-1));
}


// Definimos a função depois, tanto faz a ordem.
long fact_loop(int n)
{
	int c, fact = 1;

	for (c = 1; c <= n; c++)
		fact *= c;

	return fact;
}