/* 3. Determine se um ano é bissexto. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
	int ano;
	scanf("%d", &ano);

	if ((ano % 100 && ano % 4 == 0 ) || ano % 400 == 0 )
	    printf("Eh bissexto");

	else{
		printf("Nao eh bissexto");
	}
}