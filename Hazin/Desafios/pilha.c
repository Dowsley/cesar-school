#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int valor;
	struct node* prox;
}node;

void empilhar(node**, int);
void desempilhar(node**);
void imprimir(node**);



int main()
{
	node* topo = NULL;

	while (1)
	{
		char string[11];
		int v;

		scanf("%s", string);

		int op1 = strcmp(string, "Empilhar");
		int op2 = strcmp(string, "Desempilhar");
		int op3 = strcmp(string, "Imprimir");
		int op4 = strcmp(string, "Finalizar");

		if (op1 == 0)
		{
			scanf("%d", &v);
			empilhar(&topo, v);
		}

		else if (op2 == 0)
		{
			desempilhar(&topo);
		}

		else if (op3 == 0)
		{
			imprimir(&topo);
		}

		else if (op4 == 0)
			break;
	}

	return 0;
}


void empilhar(node** topo, int v)
{
	node* novo_node = malloc(sizeof(node*));
	novo_node->valor = v;
	novo_node->prox = NULL;

	if (*topo == NULL)
		*topo = novo_node;
	else
	{
		novo_node->prox = *topo;
		*topo = novo_node;
	}
}


void desempilhar(node** topo)
{
	node* condenado = *topo;
	*topo = condenado->prox;
	free(condenado);

}


void imprimir(node** topo)
{
	node* atual = *topo;

	while(atual != NULL)
	{
		if (atual->prox != NULL)
			printf("%d ", atual->valor);
		else
			printf("%d\n", atual->valor);
		atual = atual->prox;
	}

}