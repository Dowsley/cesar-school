#include <stdio.h>

#define ROWS 2
#define COLS 2

int main (void) {

    int a[ROWS][COLS] = {{ 1, 2 }, { 3, 4 }};
    int *p = *a;
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf (" %2d", a[i][j]);
        putchar ('\n');
    }

    /* using a pointer to access the values */
    for (i = 0; i < ROWS * COLS; p++, i++)
        printf (" %2d", *p);
    putchar ('\n');

    return 0;
}
