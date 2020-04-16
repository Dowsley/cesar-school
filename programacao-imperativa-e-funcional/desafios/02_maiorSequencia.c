/* Escreve um programa que leia uma
sequência de 10 números inteiros e retorne
a subsequência de elementos adjacentes
que tenha o maior valor quando todos os
elementos da mesma são somados. Em caso
de duas ou mais subsequências com o maior
valor, retorne aquela de menor média. */

#include <stdio.h>
#include <stdbool.h>

int sum, aux_start, aux_end, aux_sum, cont;
int seq[10] = {3,2,4,-4,2,-200,-1,10,-100};

float med, aux_med;
int size = sizeof(seq) / sizeof(int);


int main(){
	aux_sum = seq[0];
	aux_med = seq[0];

	for (int start = 0; start < size; start++){   // Defines the start of the subsequence.
		for (int end = 0; end < size; end++){ // Defines the end of the subsequence.
			sum = 0;
			cont = 0;
			for (int i = start; i <= end; i++){ // Defines the current index being analyzed.
				sum += seq[i];
				cont += 1;
			}
			
			if (cont != 0)
				med = sum/cont;

			if (sum > aux_sum) {
				aux_start = start;
				aux_end = end;
				aux_sum = sum;
			}

			else if (sum == aux_sum){
				if (med > aux_med){
					aux_start = start;
					aux_end = end;
					aux_sum = sum;
					aux_med = med;
				}	
			}
		}
	}
	
	for (int j = aux_start; j <= aux_end; j++){ // Prints the correct subsequence, answer.
		printf("%d ", seq[j]);
	}
}
