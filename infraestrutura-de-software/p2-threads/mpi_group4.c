#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <mpi.h>

struct rusage r_usage;

int quantaslinhas(char *file){

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


int main(int argc,char *argv[])
{
    int comm_sz, my_rank;
    double time = 0.0;
    clock_t init = clock();
    int i,j,k;
    int tamanho;
    tamanho = quantaslinhas(argv[1]);
    int matriz1[tamanho][tamanho];
    int matriz2[tamanho][tamanho];
    int matrizfinal[tamanho][tamanho];
    char output1[tamanho];
    char output2[tamanho];
    int linhas = 0;
    int colunas = 0;

    FILE* filepointer1 = fopen(argv[1],"r");
    FILE* filepointer2 = fopen(argv[2],"r");
    FILE* filepointer3 = fopen(argv[3],"w");

    for (linhas = 0; linhas < tamanho; linhas++)
    {
        for(colunas = 0; colunas < tamanho; colunas++)
        {
            fscanf(filepointer1,"%s",output1);
            fscanf(filepointer2,"%s",output2);
            matriz1[linhas][colunas] = atoi(output1);
            matriz2[linhas][colunas] = atoi(output2);
        }
    }
    fclose(filepointer1);
    fclose(filepointer2);

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
    MPI_Request request;
    MPI_Status status;

    int parte;
    int soma = 0;
    int end,start;

    if(my_rank == 0){
    parte = 0;
    end = (tamanho * (parte+1)) / 2; 
    start = (parte * tamanho) / 2;
    for ( i = start; i < end; i++)
        {
            for ( j = 0; j < tamanho; j++)
            {
                for ( k = 0; k < tamanho; k++)
                {
                    soma = soma + matriz1[i][k] * matriz2[k][j];         
                }
                matrizfinal[i][j] = soma;
                soma = 0;
                MPI_Send(&matrizfinal[i][j], tamanho, MPI_INT, comm_sz-1, 1, MPI_COMM_WORLD);
            }
        }
    }

    if(my_rank == 1){
    parte = 1;
    end = (tamanho * (parte+1)) / 2; 
    start = (parte * tamanho) / 2;

    MPI_Recv(&matrizfinal[i][j], tamanho, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    for (i = start; i < end; i++)
        {
            for ( j = 0; j < tamanho; j++)
            {
                for ( k = 0; k < tamanho; k++)
                {
                   soma = soma + matriz1[i][k] * matriz2[k][j];          
                }
                //should be here
                //MPI_Recv(&matrizfinal[i][j], tamanho, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                matrizfinal[i][j] = soma;
                soma = 0;
            }
        }
    }

    for(i = 0;i < tamanho ;i++){
        for(j = 0;j < tamanho ;j++){
            if (j == tamanho -1){
                fprintf(filepointer3, "%d",matrizfinal[i][j]);
            }
            else{
                fprintf(filepointer3, "%d ",matrizfinal[i][j]);
            }
        }
        if (i == tamanho -1){
            continue;
        }
        else{
            fputs("\n",filepointer3);
        }
    }
    fclose(filepointer3);
    clock_t fim = clock();
    int memoryusage;
    memoryusage = getrusage(RUSAGE_SELF,&r_usage); 
    time += (double)(fim-init)/CLOCKS_PER_SEC;
    FILE* compare = fopen("compare.txt","a");
    fprintf(compare, "Mpi: Tempo - %f  Memória - %ld\n",time,r_usage.ru_maxrss);
    fclose(compare);
    MPI_Finalize();
}
