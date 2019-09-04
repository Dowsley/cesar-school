#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
	int valor;
	struct node* prox;
}node;

void add(node**, int);
void exibir(node**);


/***** PROGRAMA PRINCIPAL *****/
int main()
{
	node* head = NULL;

	add(&head, 4);
	add(&head, 2);
	add(&head, 3);
	add(&head, 10);

	exibir(&head);

	return 0;
}


void add(node** head, int novo_valor)
{
	node* novo_node = malloc(sizeof(node*));

	/* Cria um novo node, depois decide onde irá inserir */
	(*novo_node).valor = novo_valor;
	(*novo_node).prox = NULL;

	if (*head == NULL)   // Encontrou a cauda
		*head = novo_node;
	else   // Vai procurar a cauda
	{
		node* atual = *head;

		while ((*atual).prox != NULL)   // Procurando cauda
			atual   = (*atual).prox;   // Passa de node pra node

		(*atual).prox = novo_node;   // Coloca o novo node na cauda null.
	}
}


void exibir(node** head)
{
		printf("LISTA");
        if (head == NULL)
            printf(" -> \\");
        else
        {
            node* atual = *head;
            while (atual != NULL)
            {
                printf(" -> %d", atual->valor);
                atual = atual->prox;
            }
            if (atual == NULL)
                printf(" -> \\");
        }
}