#include <stdio.h>
#include <stdlib.h>

typedef struct SQUARE{
    int x1;
    int y1;
    int x2;
    int y2;
}SQUARE;

int abs(int n);
int area(SQUARE sqr);

int main(int argc, char const *argv[])
{
    SQUARE s1;
    SQUARE s2;
    SQUARE s3;

    printf("\nSquare 1 first coord: ");
    scanf("%d %d", &s1.x1, &s1.y1);
    printf("\nSquare 1 second coord: ");
    scanf("%d %d", &s1.x2, &s1.y2);

    printf("\nSquare 2 first coord: ");
    scanf("%d %d", &s2.x1, &s2.y1);
    printf("\nSquare 2 second coord: ");
    scanf("%d %d", &s2.x2, &s2.y2);

    printf("%d\n", area(s1));

    return 0;
}

// ABSOLUTE FUNCTION: Gets an number and returns its absolute value (modulus).
int abs(int n)
{
    if (n < 0)
        return (n * -1);
    return n;
}

// Returns the area of an square.
int area(SQUARE sqr)
{
    int area = abs(sqr.x1 - sqr.x2) * abs(sqr.y1 - sqr.y2);
    return area;
}

int sumArea(SQUARE s1, SQUARE s2)
{
    // If there's an intersection
    if (s1.x > &&)

    elif ()

    return total;
}
