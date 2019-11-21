#include <stdio.h>
#include <stdlib.h>

typedef struct RECT{
    int x1;
    int y1;
    int x2;
    int y2;
}RECT;

int abs(int n);
int area(RECT sqr);
int howManyShapes(char filename[]);
RECT* readShapes(RECT array[], char filename[], int size);
RECT* newRect(int coords[4]);


int main(int argc, char *argv[])
{
    int n = howManyShapes(argv[1]);
    RECT* rects = calloc(sizeof(RECT), n);
    readShapes(rects, argv[1], n);

    for (int i = 0; i < n; i++)
        printf("%d %d %d %d\n", rects[i].x1, rects[i].y1, rects[i].x2, rects[i].y2);

    return 0;
}


// ABSOLUTE FUNCTION: Gets an number and returns its absolute value (modulus).
int abs(int n)
{
    if (n < 0)
        return (n * -1);
    return n;
}


// Returns the area of an RECT.
int area(RECT sqr)
{
    int area = abs(sqr.x1 - sqr.x2) * abs(sqr.y1 - sqr.y2);
    return area;
}


int howManyShapes(char filename[])
{
    FILE* fp = fopen(filename, "r");
    char ch;
    int n;
    while(ch=fgetc(fp) != EOF)
        if (ch == '\n')
            n++;
    fclose(fp);
    printf("%d", n);
    return n;
}

RECT* readShapes(RECT array[], char filename[], int size)
{
    FILE* fp = fopen(filename, "r");
    int coords[4];
    int count = 0;
    int pos = 0;

    while(fgetc(fp) != EOF)
    {
        fscanf(fp, "%d", &coords[count]);
	printf("%d", coords[count]);
        count++;
        if (count % 4 == 0)
        {
            array[pos] = *(newRect(coords));
            pos++;
        }
    }
    fclose(fp);
    return array;
}

RECT* newRect(int coords[4])
{
    RECT* new = malloc(sizeof(RECT));
    new->x1 = coords[0];
    new->y1 = coords[1];
    new->x2 = coords[2];
    new->y2 = coords[3];

    return new;
}
