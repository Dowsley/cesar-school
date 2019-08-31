// Posiçoes de memoria compartilhada por 2 ou mais variaveis

#include <stdio.h>

int main()
{
	union tipo_u{
		int i;
		double d;
	};

	union tipo_u u;
	u.i = 10;

	return 0;
}