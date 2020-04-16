/* 1. Leia três números e retorne o maior deles. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		if (x > y && x > z){
			printf("%d\n", x);
		}

		else if(y > x && y > z){
			printf("%d\n", y);
		}

		else{
			printf("%d\n", z);
		}
}