#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int valor;
    struct node* prox;
}node;


void inserir_node(node** head, int novo_valor);
node** gerar_tabela(int);
void inserir_tabela(node**, int, int);
void exibir(node**, int);


//------------ PROGRAMA PRINCIPAL -----------//
int main()
{
    int n, c, tamanho, novo_valor;

    scanf("%d", &n);

    for (n; n > 0; n--)
    {
        scanf("%d %d", &tamanho, &c);

        node** tabela = gerar_tabela(tamanho);

        for (c; c > 0; c--)
        {
            scanf("%d", &novo_valor);
            inserir_tabela(tabela, novo_valor, tamanho);
        }
        exibir(tabela, tamanho);
        if (n != 1)
            printf("\n\n");
    }
    printf("\n");
    return 0;
}


//------------ PRINTA A TABELA -----------//
void exibir(node** tabela, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        node* head = tabela[i];
        printf("%d", i);

        if (head == NULL)
            printf(" -> \\");
        else
        {
            node* atual = head;
            while (atual != NULL)
            {
                printf(" -> %d", atual->valor);
                atual = atual->prox;
            }
            if (atual == NULL)
                printf(" -> \\");
        }
        if (i != tamanho - 1)
            printf("\n");
    }
}



//------------ GERA UM NODE PARA INSERIR NUMA LISTA ENCADEADA -----------//
void inserir_node(node** head, int novo_valor)
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



//------------ CRIA TABELA HASH (PONTEIRO DE PONTEIROS) -----------//
node** gerar_tabela(int tamanho)
{
    node** tabela = calloc(tamanho, sizeof(node*));   // Cria n espaços de tamanho X.
    return tabela;
}



//------------ INSERE ENDEREÇO NOVO NA TABELA HASH -----------//
void inserir_tabela(node** tabela, int novo_valor, int tamanho)
{
    if (novo_valor < 0)
        novo_valor *= -1;

    int local =  novo_valor % tamanho;

    if (tabela[local] == NULL)   // Se não existe HEAD...
    {
        tabela[local] = malloc(sizeof(node*));

        node* head = NULL;
        inserir_node(&head, novo_valor);

        tabela[local] = head;

    } else {   // Se existir...
        node* head = tabela[local];

        inserir_node(&head, novo_valor);

        tabela[local] = head;
    }

}