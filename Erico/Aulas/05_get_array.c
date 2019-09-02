#include <stdio.h>

#define MAX_SIZE 10

void getArray(int *arr, int size);

int main() {
    	int arr[MAX_SIZE];
    	int i;

    	getArray(arr, MAX_SIZE);

    	printf("\n\nArray outside function: \n");
		for (i = 0; i < MAX_SIZE; i++)
    			printf("%d ", arr[i]);

    return 0;
}

void getArray(int *arr, int size) {

		int i;

		printf("Enter elements in array: ");
		for (i = 0; i < size; i++)
				scanf("%d", &arr[i]);

		printf("\n\nArray inside function: \n");
		for (i = 0; i < size; i++)
				printf("%d ", arr[i]);
}
