#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********* FUNÇÃO QUE RETORNA ARRAY **********/

int * getRandom() {   // Criou e alterou o array dentro da função, e retornou o ponteiro pra ela.

		static int  r[10];   // Static mantém o espaço de memória reservado mesmo depois de sair da função.
		// O valor não sumiria obrigatoriamente... mas nada garantiria que ele não fosse sobrescrevido.
		int i;

		/* set the seed */
		srand( (unsigned)time( NULL ) );

		for ( i = 0; i < 10; ++i) {
				r[i] = rand();
				printf( "r[%d] = %d\n", i, r[i]);
		}

		return r;
}

int main () {

		int *p;
		int i;

		p = getRandom();

		for ( i = 0; i < 10; i++ ) {
				printf( "*(p + %d) : %d\n", i, *(p + i));
		}

		return 0;
}
