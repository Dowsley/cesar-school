#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

struct rusage r_usage;

#define NUM_THREADS 2

struct arg_struct 
{int parte;};

int tamanho;
int** matriz1;
int** matriz2;
int** matrizfinal; 

int quantasLinhas(char *file)
{
    int i;
    char c;
    int tamanho = 1;
    int flag;

    FILE* filepointer = fopen(file,"r");

    if (filepointer == NULL)
    {
        printf("Can't open/find file\n");
        return -1;
    }
    
    for (c = getc(filepointer); c != EOF;)
    {
	c = getc(filepointer);
        if (c == '\n')
        {
            tamanho++; 
        }
    }
    fclose(filepointer);
    return tamanho;
}

int** alocaMatriz(int tamanho)
{
	int** matriz = calloc(tamanho, sizeof(int*));

	for (int i = 0; i < tamanho; i++)
		matriz[i] = calloc(tamanho, sizeof(int));

	return matriz;    
}

void preencheMatriz(int** matrix, int tamanho, FILE* filepointer) 
{
    int linhas = 0;
    int colunas = 0;
    char output[tamanho];

    for (linhas = 0; linhas < tamanho; linhas++)
    {
        for(colunas = 0; colunas < tamanho; colunas++)
        {
            fscanf(filepointer,"%s",output);
            matrix[linhas][colunas] = atoi(output);
        }
    }
}

void salvaMatrizFinal(FILE* filepointer)
{
    int i, j;
    for(i = 0;i < tamanho ;i++){
        for(j = 0;j < tamanho ;j++){
            if (j == tamanho -1){
                fprintf(filepointer, "%d",matrizfinal[i][j]);
            }
            else{
                fprintf(filepointer, "%d ",matrizfinal[i][j]);
            }
        }
        if (i == tamanho -1){
            continue;
        }
        else{
            fputs("\n",filepointer);
        }
    }
}

void* multiplicador(void* parte_arg)
{
    struct arg_struct* arg = (struct arg_struct*) parte_arg;
    int parte = arg->parte;
    int end = (tamanho * (parte+1)) / NUM_THREADS; 
    int start = (parte * tamanho) / NUM_THREADS;
    
    int soma = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            for (int k = 0; k < tamanho; k++)
            {
                soma = soma + matriz1[i][k] * matriz2[k][j];
            }
            matrizfinal[i][j] = soma;
            soma = 0;
        }
    }
}

int main(int argc,char* argv[])
{
    double time = 0.0;
    clock_t init = clock();

    tamanho = quantasLinhas(argv[1]);

    FILE* fp_input1 = fopen(argv[1],"r");
    FILE* fp_input2 = fopen(argv[2],"r");
    FILE* fp_output = fopen(argv[3],"w");

    // Aloca matrizes
    matriz1 = alocaMatriz(tamanho);
    matriz2 = alocaMatriz(tamanho);
    matrizfinal = alocaMatriz(tamanho);

    preencheMatriz(matriz1, tamanho, fp_input1);
    preencheMatriz(matriz2, tamanho, fp_input2);

    fclose(fp_input1);
    fclose(fp_input2);
    
    // Multiplicação Paralela
    pthread_t thread_id;

    struct arg_struct arg1;
    struct arg_struct arg2;
    arg1.parte = 1;
    arg2.parte = 0;

    pthread_create (&thread_id, NULL, multiplicador, (void*) &arg1);
    multiplicador((void*)&arg2);
    pthread_join (thread_id, NULL);
    salvaMatrizFinal(fp_output);
    fclose(fp_output);
    clock_t fim = clock();
    time += (double)(fim-init)/CLOCKS_PER_SEC;
    FILE* compare = fopen("compare.txt","a");
    getrusage(RUSAGE_SELF,&r_usage); 
    fprintf(compare, "Pthread: Tempo - %f  Memória - %ld\n",time,r_usage.ru_maxrss);
    fclose(compare);
    return 0;
}
