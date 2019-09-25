#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int valor;
	struct No* esquerda;
	struct No* direita;
}No;

int main()
{
	int Q;   // Número de queries.
	int x;   // Entrada.
	int choice;   // Escolha entre 1 e 2 (Insert e find, respectivamente).

	No* arvore = NULL;

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &choice, &x);

		if (choice == 1)
			insert(x, &arvore);

		else if (choice == 2)
			printf("\n%d", find(x, arvore));
	}

	return 0;
}


void insert(int novo_valor, No** arvore)
{

}


int find(int valor, No* arvore)
{
	if (arvore != NULL)
	{
		exibirIn(arvore->esquerda);
		printf(" %d", arvore->valor);
		exibirIn(arvore->direita);
	}
}