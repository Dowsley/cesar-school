#include <stdio.h>

int traco(int matriz[][3]) {
//int traco(int (*matriz)[3]) {
		int count, traco=0;
		for(count=0 ; count < 3 ; count++){
				printf("%d\n",count*3+count);
				traco += *(*(matriz+count)+count);
		}
		return traco;
}

int main(){
		int grid[][3] = {{1,2,3},{4,5,6},{7,8,9}};
		printf("%d\n",traco(grid));
		return 0;
}
