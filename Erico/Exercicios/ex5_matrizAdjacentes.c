#include <stdio.h>

/* Dada uma matriz de inteiros 4x4
Quais os índices dos 3 números adjacentes em qualquer direção (horizontal, vertical ou diagonal)
que correspondem ao maior produto de 3 números adjacentes. */

int main()
{
    int matriz[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,0,1,2}, {3,4,5,6} };

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int prod = 1;
    
            for (int c = 0; c < 3; c++)   // Horizontal
            {
                prod *= matriz[i+c][j+c]
                
            }
        }

    return 0;   // Oi!
}
