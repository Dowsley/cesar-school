#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct Point{
    int x,y;
}point;

typedef struct Rectangle{
    point left;
    point right;
}rectangle;

void designaPontos(rectangle* ret, int numbers[]){
    int i;
    printf("primeiro x:%d segundo x:%d\n",numbers[0],numbers[2]);
    if(numbers[0]>numbers[2]){ //se x0 for maior que x2, entao ele eh o da direita
        ret->right.x = numbers[0];
        ret->right.y = numbers[1];
        ret->left.x = numbers[2];
        ret->left.y = numbers[3];
    }
    else{
        ret->right.x = numbers[2];
        ret->right.y = numbers[3];
        ret->left.x = numbers[0];
        ret->left.y = numbers[1];
    }
}

float areaRetangulo(rectangle* ret){
    float area = (ret->right.x - ret->left.x) * (ret->right.y - ret->left.y);
    return area;
}

float areaIntersec(rectangle* ret1, rectangle* ret2){
    float areaIntersec = (MIN(ret1->right.x, ret2->right.x) - MAX(ret1->left.x, ret2->left.x)) * (MIN(ret1->right.y, ret2->right.y) - MAX(ret1->left.y, ret2->left.y));
    return areaIntersec;
}

int* extraiNumeros(int numLinha){
    FILE *arq;
    char linha[10];
    char * pch;
    int *retorno;
    int i=0,j=0;
    retorno = (int*)malloc(4*sizeof(int));
    arq = fopen("C:\\Users\\dudun\\Desktop\\erico.txt", "r");
    if(arq){
        while(!feof(arq)){
            fscanf(arq, "%[^\n]\n", linha);
            if(j==numLinha){
                pch = strtok (linha," ");
                while (pch != NULL){
                    printf ("%s\n",pch);
                    retorno[i] = atoi(pch);
                    i++;
                    pch = strtok (NULL, " ");
                }
            }
            j++;
        }
    }
    return retorno;
}

int checaIntersec(rectangle* ret1, rectangle* ret2){
    int ans=0;
    if(ret1->left.x > ret2->left.x && ret1->left.x < ret2->right.x){
        if(ret1->left.y > ret2->left.y && ret1->left.y < ret2->right.y){
            ans=1;
        }
    }

    if(ret2->left.x > ret1->left.x && ret2->left.x < ret1->right.x){
        if(ret2->left.y > ret1->left.y && ret2->left.y < ret1->right.y){
            ans=1;
        }
    }

    if(ret2->right.x > ret1->left.x && ret2->right.x < ret1->right.x){
        if(ret2->right.y > ret1->left.y && ret2->right.y < ret1->right.y){
            ans=1;
        }
    }

    if(ret1->right.x > ret2->left.x && ret1->right.x < ret2->right.x){
        if(ret1->right.y > ret2->left.y && ret1->right.y < ret2->right.y){
            ans=1;
        }
    }

    return ans;
}


int contaLinhas(){
  int j=0;
  FILE* arq;
  char linha[10];
  arq = fopen("C:\\Users\\dudun\\Desktop\\erico.txt", "r");
  if(arq){
   while(!feof(arq)){
            fscanf(arq, "%[^\n]\n", linha);
            j++;
            }
  }
  return j;
}

int main(){
    rectangle *entrada;
   // int aux[4];
    int *aux;
    int qtdRetangulos=contaLinhas();
    int i,j;
    float areas[qtdRetangulos];
    float somaAreas=0, somaIntersec=0;

    entrada = (rectangle*)malloc(qtdRetangulos*sizeof(rectangle));


    for(i=0;i<qtdRetangulos; i++){
        //scanf("%d %d %d %d", &aux[0],&aux[1],&aux[2],&aux[3]);
        aux = extraiNumeros(i);
        designaPontos(&entrada[i], aux);
        areas[i] = areaRetangulo(&entrada[i]);
        somaAreas = somaAreas + areas[i];
        printf("area: %f\n", areas[i]);
    }
    for(i=0;i<qtdRetangulos; i++){
        for(j=i+1;j<qtdRetangulos; j++){
           if(checaIntersec(&entrada[i],&entrada[j])){
            float areasec = areaIntersec(&entrada[i], &entrada[j]);
             printf("areasec: %f\n", areasec);
            somaIntersec = somaIntersec + areasec;
           }
        }

    }
    float somafinal = somaAreas - somaIntersec;

    printf("%f\n", somafinal);
    printf("left: %d %d\n", entrada->left.x, entrada->left.y);
    printf("right: %d %d\n", entrada->right.x, entrada->right.y);
    return 0;
}
