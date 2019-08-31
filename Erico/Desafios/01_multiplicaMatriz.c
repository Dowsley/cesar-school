#include <stdio.h>
#include <string.h>

int main(){
	int m1[3][3] = {1,2,3,5,4,0,2,2,1};
	int m2[3][3] = {1,5,2,2,0,2,3,1,2};
	int mf[3][3];
	int soma;

	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			soma = 0;
			for(int z = 0; z < 3; z++){
				soma += m1[x][z] * m2[z][y];
			}
			
			mf[x][y] = soma;
			printf("%d\t", mf[x][y]);
		}
		printf("\n");
	}

	return 0;
}
