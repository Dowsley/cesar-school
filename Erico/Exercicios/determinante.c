#include <stdio.h>

int len = 3;
int nlen = 5;
int det = 0, temp;
int matriz[3][3] = {2,3,4,5,2,8,4,2,1};   // Matriz inicial, entrada. [len][len]
int matriz_nova[3][5];   // Nova matriz para calcular o determinante. [len][len+len-1]

int main()
{
	for (int l = 0; l < len; l++)   // varredor de linhas
	{
		/* Fabricador da nova matriz */
		for (int c = 0; c < len; c++)   // varredor de colunas
		{
			if (c != len-1)   // Elementos espelhados
			{
				matriz_nova[l][c] = matriz[l][c];
				matriz_nova[l][c+len] =  matriz[l][c];
			}

			else   // Elementos axis
				matriz_nova[l][c] = matriz[l][c];
		}
	}
		
		/* Calculador da determinante */
		for (int c = 0; c < nlen; c++)   // Percorre a primeira linha como ponto de partida
		{
			temp = 1;
			for (int c_temp = c, l = 0, cont = 0; cont < len; c_temp++, l++, cont++)
			{
				printf("Eu estou na linha %d e na coluna %d.\n", l, c_temp);

				if (c_temp > 4){
					printf("Caralho: %d", matriz_nova[l][c_temp]);
					if (matriz_nova[l][c_temp])
						printf("Porraaaaa vai se foder");
					temp = 0;
					break;
				}

				if (matriz_nova[l][c_temp])
					temp = temp * matriz_nova[l][c_temp];
				else
				{
					temp = 0;
					break;
				}
			}
			printf("Temp: %d\n",temp);
			det += temp;


			temp = 1;
			for (int c_temp = c, l = 0, cont = 0; cont < len; c_temp--, l++, cont++)
			{
				printf("Estou na linha %d e na coluna %d.\n", l, c_temp);	
				if (c_temp < 0)
				{
					temp = 0;
					break;
				}

				if (matriz_nova[l][c_temp])
					temp = temp * matriz_nova[l][c_temp];
					else
				{
					temp = 0;
					break;
				}
			}
			printf("Temp: %d\n", temp);
			det -= temp;
		}
		printf("-----A determinante eh: %d-----", det);

	return 0;
}
