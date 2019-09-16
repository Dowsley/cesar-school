#include <stdlib.h>
#include <stdio.h>

typedef struct node_pilha{
	int valor;
	struct node_pilha* prox;
	struct node_pilha* esquerda;
	struct node_pilha* direita;
}node_pilha;

typedef struct node_fila{
	struct node_pilha* topo;
	struct node_fila* prox; 
}node_fila;

typedef struct fila{
	struct node_fila* start;
	struct node_fila* end;
}fila;

void empilhar(fila*, int);
int desempilhar(fila*);
void imprimir_pilha(node_pilha*);

void enfileirar(fila*);
void imprimir_fila(fila*);
void desenfileirar(fila*);

int buscador(fila*);


void empilhar(fila* Fila, int id)
{
	node_pilha* novo_node = malloc(sizeof(node_pilha*));
	novo_node->valor = id;

	if ((Fila->end)->topo == NULL)
	{
		(Fila->end)->topo = novo_node;
		novo_node->prox = NULL;
	}
	else
	{
		novo_node->prox = (Fila->end)->topo;
		(Fila->end)->topo = novo_node;
	}
}



int desempilhar(fila* Fila)
{
	node_pilha* condenado = (Fila->start)->topo;

	if (condenado == NULL)
	{
		desenfileirar(Fila);
		return 0;
	}

	else
	{
		int valor = condenado->valor;

		(Fila->start)->topo = condenado->prox;
		free(condenado);

		return valor;
	}
}



void imprimir_pilha(node_pilha* topo)
{
	node_pilha* atual = topo;

	while(atual != NULL)
	{
		if (atual->prox != NULL)
			printf("%d -> ", atual->valor);
		else
			printf("%d\n", atual->valor);
		atual = atual->prox;
	}

}



void enfileirar(fila* Fila)
{
	node_fila* novo_node = malloc(sizeof(node_fila*));
	novo_node->prox = NULL;
	novo_node->topo = NULL;

	if (Fila->end == NULL && Fila->start == NULL){
		Fila->end = novo_node;
		Fila->start = novo_node;
	}

	else{
		node_fila* atual = Fila->end;
		atual->prox = novo_node;
		Fila->end = novo_node;
	}
}



void desenfileirar(fila* Fila)
{
	node_fila* condenado = (Fila->start);
	node_fila* atual = condenado->prox;
	Fila->start = atual;

	free(condenado);
}



void imprimir_fila(fila* Fila)
{
	node_fila* atual = Fila->start;
	int i = 0;
	while (atual != NULL)
	{
		printf("%d: ", i);
		imprimir_pilha(atual->topo);

		atual = atual->prox;

		i += 1;
	}
}



int buscador(fila* Fila)
{
	int x, count = 0;
	while (1)
	{
		x = desempilhar(Fila);

		if (x == 1)
			break;

		if (x != 0)
			count += 1;
	}

	return count;
}



int main()
{
	int n;   // Número de caixas total (Suas numerações vão de 1 a n)
	int p;	 // Número de pilhas (Tem que ser menor ou igual à quantidade de caixas)
	int q;   // Número de caixas na dada linha
	int id;   // Identificador de caixa
	int buscas;
	fila Fila;

	while (1)
	{
		Fila.end = NULL;
		Fila.start = NULL;
		scanf("%d %d", &n, &p);

		if (n == 0 && p == 0)
			break;

		for (int i = 0; i < p; i++)
		{
			enfileirar(&Fila);

			scanf("%d", &q);
			for (; q > 0; q--)
			{
				scanf("%d", &id);
				empilhar(&Fila, id);
			}
		}

		//imprimir_fila(&Fila);
		buscas = buscador(&Fila);
		printf("%d\n", buscas);

	}
	
	return 0;
}