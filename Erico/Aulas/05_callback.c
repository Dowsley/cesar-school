#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*callback)(int, int);
void insertion_sort(int *array, int n, callback comparison);

int ascending(int a, int b)
{ return a > b; }

int descending(int a, int b)
{ return a < b; }

int main(void)
{

		int i, choice;
		int array[10] = {22,66,55,11,99,33,44,77,88,0};

		printf("ascending 1: descending -1: quit 0\n");
		printf("enter your choice = ");

		scanf("%d", &choice);
		if (choice==1) {
				insertion_sort(array,10, ascending);
				printf("ascending order\n");
		} else if (choice==-1) {
				insertion_sort(array,10, descending);
				printf("descending order\n");
		} else if (!choice) {
				exit(0);
		} else {
				printf("no order\n");
		}

		for(i=0;i<10;i++)
				printf("%d\t", array[i]);
		printf("\n");

		return 0;
}

void insertion_sort(int *array, int n, callback comparison)
{
	int i, j, key;
    for(j=1; j<=n-1;j++)
    {
        key=array[j];
        i=j-1;
        while(i >=0 && comparison(array[i], key))
        {
            array[i+1]=array[i];
            i=i-1;
        }
        array[i+1]=key;
    }

}
