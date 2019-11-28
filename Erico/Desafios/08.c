#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    int head[2];
    int tail[4];

    for(int i = 0; fscanf(fp, "%d", &head[i]); i++)
    {
        if(fgetc(fp)=='\n')
            break;
    }

    for(int i=0; fscanf(fp, "%d", &tail[i]); i++)
    {
        if(fgetc(fp)==EOF)
            break;
    }

    return 0;
}
