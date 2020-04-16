#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
	int valor;
	int altura;
	struct No* esquerda;
	struct No* direita;
	struct No* pai;
}No;

//void buscar(No*, int);
void inserir(No**, int);
int altura(No*);
void atualizaAltura(No*);
No* RSE(No*);
No* RSD(No*);
void RDE(No*);
void RDD(No*);


int main()
{
	int Q;   // Número de queries.
	int x;   // Entrada.
	int choice;   // Escolha entre 1 e 2 (inserir e procurar, respectivamente).

	No* raiz = NULL;

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &choice, &x);

		if (choice == 1)
			inserir(&raiz, x);

		else if (choice == 2)
			//buscar(raiz, x);
	}

	return 0;
}


No* inserir(No** raiz, int novo_valor)
{
	No* novo_no = (No*)malloc(sizeof(No));
	novo_no->valor = novo_valor;
	novo_no->altura = 0;
	novo_no->esquerda = NULL;
	novo_no->direita = NULL;
	novo_no-> pai = NULL;

	if (*raiz == NULL)
        *raiz = novo_no;

    else
    {
        if (novo_valor <= (*raiz)->valor)
        {
            inserir(&(*raiz)->esquerda, novo_valor);
            if ( (altura((*raiz)->esquerda) - (altura((*raiz)->direita)) ) == 2 )
            {
	            if (novo_valor < (*raiz)->esquerda->valor)
	        		RSD(*raiz);
	            else 
	            	RDD(*raiz);
            }
        }
        
        else
        {
        	inserir(&(*raiz)->direita, novo_valor);
            if ( (altura((*raiz)->direita) - (altura((*raiz)->esquerda)) ) == 2 )
            {
	            if (novo_valor > (*raiz)->direita->valor)
	        		RSE(*raiz);
	            else 
	            	RDE(*raiz);
            }
        }
        atualizaAltura(*raiz);
    }
}


int altura(No* no)
{
	if (no == NULL) return 0;
	else return no->altura;
}


void atualizaAltura(No* raiz)
{
	int altDireita;
	int altEsquerda;

	if (raiz != NULL)
	{
		altDireita = altura(raiz->direita);
		altEsquerda = altura(raiz->esquerda);

		raiz->altura = ((altDireita > altEsquerda ) ? altDireita : altEsquerda);
	}
}


No* RSE(No* raiz)   // Rotação simples para esquerda
{
	No* aux = (No*)malloc(sizeof(No));

	aux = raiz->direita;
	raiz->direita = aux->esquerda;
	aux->esquerda = raiz;
	aux->pai = raiz->pai;

	if (raiz->pai != NULL)   // Aponta o pai para o novo eixo.
	{
		if ( raiz->pai->valor >= (raiz->valor))
			raiz->pai->esquerda = aux;
		else
			raiz->pai->direita = aux;
	}

	raiz->pai = aux;
	raiz->direita->pai = raiz;

	
	atualizaAltura( raiz->esquerda );
	atualizaAltura(raiz);

	return aux;
}


No* RSD(No* raiz)   // Rotação simples para direita
{
	No* aux = (No*)malloc(sizeof(No));

	aux = raiz->esquerda;
	raiz->esquerda = aux->direita;
	aux->direita = raiz;
	aux->pai = raiz->pai;

	if (raiz->pai != NULL)   // Aponta o pai para o novo eixo.
	{
		if ( raiz->pai->valor >= (raiz->valor))
			raiz->pai->esquerda = aux;
		else
			raiz->pai->direita = aux;
	}

	raiz->pai = aux;
	raiz->esquerda->pai = raiz;

	atualizaAltura(raiz->direita);
	atualizaAltura(raiz);

	return aux;
}


void RDE(No* raiz)   // Rotação dupla para esquerda (Rsd + Rse)
{
	raiz->direita = RSD(raiz->direita);
	RSE(raiz);
}


void RDD(No* raiz)   // Rotação dupla para direita (Rse + Rsd)
{
	raiz->esquerda = RSE(raiz->direita);
	RSD(raiz);
}