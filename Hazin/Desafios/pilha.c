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

void enfileirar(master* Master, int new_id)
{
	node* new_node = malloc(sizeof(node*));
	new_node->id = new_id;
	new_node->next = NULL;

	if (Master->end == NULL && Master->start == NULL){
		Master->end = new_node;
		Master->start = new_node;
	}

	else{
		node* atual = Master->end;
		atual->next = new_node;
		Master->end = new_node;
	}
}



void desenfileirar(master* Master, int old_id)
{
	node* atual = Master->start;
	node* prev;
	while (atual->id != old_id)
	{
		prev = atual;
		atual = atual->next;
	}

	if (atual == Master->start)
		Master->start = atual->next;
	else if (atual == Master->end)
	{
		prev->next = NULL;
		Master->end = prev;
	}
	else
		prev->next = atual->next;
	
	free(atual);
}



void displayQueue(master* Master)
{
	node* atual = Master->start;
	while (atual != NULL)
	{
		printf("%d ", atual->id);
		atual = atual->next;
	}
}