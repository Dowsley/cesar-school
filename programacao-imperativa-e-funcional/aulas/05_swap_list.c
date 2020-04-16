#include <stdio.h>

void swap_v (int n, int *lista){

		int temp;
		for (int i = 0; i < n/2; i++){
				temp = lista[i];
				lista[i] = lista[n-1-i];
				lista[n-1-i] = temp;
		}

		return;
}

int main(){

		int notas[] = {1,2,3,4};
		swap_v(4,notas);
		for (int i = 0; i < 4; i++)
				printf("%d ", notas[i]);
		printf("\n");
		return 0;

}
