#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int);
void merge(int*, int*, int, int);


int main()
{
    int array[10] = {4,2,3,1,9,7,6,8,5,0};

    mergeSort(array, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);

    printf("\n");

    return 0;
}


void mergeSort(int* array, int len)
{
    // Further segmentation
    if (len != 1)
    {
        int lenLeft = len/2;
        int lenRight = len - (len/2);

        mergeSort(array, lenLeft);
        mergeSort(array+lenLeft+1, lenRight);
        merge(array, array+lenLeft+1, lenLeft, lenRight);
    }
}


void merge(int* left, int* right, int lenLeft, int lenRight)
{
    int aux[lenLeft + lenRight];
    int i = 0, j = 0, z = 0;
    while (i < lenLeft && j < lenRight)
    {
        if (left[i] > right[j])
        {
            aux[z] = right[j];
            z++;
            j++;
        }
        else
        {
            aux[z] = left[i];
            z++;
            i++;
        }
    }

    while(i < lenLeft)
    {
        aux[z] = left[i];
        z++;
        i++;
    }

    while( j < lenRight)
    {
        aux[z] = right[j];
        z++;
        j++;
    }

    // Swap de arrays
    for(int i = 0;i < lenLeft+lenRight;i++)
    {
        left[i] = aux[i];
    }
}
