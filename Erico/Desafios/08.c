#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int aux;        // Salva numero do arquivo
    int len1 = 1;   // Qtd de numeros na 1a linha (nao le o primeiro)
    int len2 = 0;   // Qtd de numeros na 2a linha

    FILE* fp = fopen(argv[1], "r");

    /* CONTAGEM */
    while (fgetc(fp) != '\n')
    {
        fscanf(fp, "%d", &aux);
        len1++;
    }
    while (fgetc(fp) != EOF)
    {
        fscanf(fp, "%d", &aux);
        len2++;
    }

    printf("%d %d\n", len1, len2);

    return 0;
}
