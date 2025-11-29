#include <stdio.h>
#include<stdlib.h>
#include <time.h>

//Crie um programa que gere aleatoriamente uma matriz de inteiros com 
//dimensão indicada pelo usuário e armazene a matriz no arquivo "mat.txt"

//Funções auxiliares
int** aloca_matriz(int); //feita
void libera_matriz(int **, int);
void gera_matriz(int **, int);
void grava_matriz(int **, int);
void resgata_matriz(int);
void print_mat(int**, int);
//Função main()

int main(){
    int n, **mat;
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);
    mat = aloca_matriz(n);
    srand(time(NULL));
    gera_matriz(mat, n);
    grava_matriz(mat, n);
    resgata_matriz(n);
    libera_matriz(mat, n);
    return 0;
}

int** aloca_matriz(int dim){
    int** mat = malloc(sizeof(int*) * dim);

    if(mat==NULL){
        printf("ERRO ao alocar matriz\n");
        exit(1);
    }

    for(int i=0; i<dim; i++){
        *(mat+i) = malloc(sizeof(int) * dim);
        if(*(mat+i) == NULL){
            printf("ERRO ao alocar matriz\n");
            exit(1);
        }
    }
    return mat;
}

void libera_matriz(int** mat, int dim){
    for(int i=0; i<dim; i++){
        free(*(mat+i));
    }
    free(mat);
    mat=NULL;
    printf("Memoria liberada com sucesso\n");
}

void gera_matriz(int **m, int d){
    int i, j;
    for(i=0;i<d;i++)
        for(j=0;j<d;j++)
            m[i][j] = rand();
}

void grava_matriz(int **m, int d){
    int i, j;
    FILE *f;
    if ((f=fopen("mat.txt","w"))==NULL){
        printf("Erro ao criar arquivo!!!\n");
        exit(1);
    }
    fprintf(f, "%d\n", d);
    for(i=0;i<d;i++){
        for(j=0;j<d;j++)
            fprintf(f, "%7d", m[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);
}

void resgata_matriz(int dim){
    int i, j, temp;

    int** mat=aloca_matriz(dim);

    FILE* file;
    file = fopen("mat.txt", "r");
    if(file == NULL){
        printf("Erro ao criar arquivo!!!\n");
        exit(1);
    }
    fscanf(file, "%d\n", &temp);
    printf("Dimensao da matriz: %d\n", temp);

    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            fscanf(file, "%d\n", (*(mat+i)+j));
        }
    }
    print_mat(mat, dim);
    libera_matriz(mat, dim);    

}

void print_mat(int** mat, int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%d\t", *(*(mat+i)+j));
        }
        printf("\n");
    }
}