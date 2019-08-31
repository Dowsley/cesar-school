#include <stdio.h>
#include <stdarg.h>

float media (int n_args, ...) {

		va_list argumentos;
		va_start (argumentos, n_args);

		int contador = 0;
		int soma = 0;

		while (contador < n_args) {
				int numero = va_arg (argumentos, int);
				soma += numero;
				contador += 1;
		}

		va_end (argumentos);
		float med = (float)(soma) / (float)(contador);
		return med;
}

int main(){

	printf("%f",media(2,2,-3));
	return 0;
}
