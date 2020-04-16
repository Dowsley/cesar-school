#include <stdio.h>
#include <stdlib.h>

float** loc_float_matrix(int m, int n) {

	float **v; //point to the matrix
	int i;     //auxiliar variable

	if (m < 1 || n < 1) {
		printf("**Dimension not valid**\n");
		return(NULL);
	}

	//allocate matrix lines
	v = calloc(m, sizeof(float*));
	if (v == NULL){
		printf("**Not enough memory**\n");
		return(NULL);
	}

	//allocate matrix columns
	for (i = 0; i < m; i++){
		v[i] = calloc(n, sizeof(float));
		if (v[i] == NULL){
			printf("**Not enough memory**\n");
			return(NULL);
		}
	}

	return v;
}

int main () {
   float ** matrix = loc_float_matrix(2,2);
   *(*(matrix+1)+1) = 2;
   printf("%f\n", matrix[1][1]);
   return 0;
}
