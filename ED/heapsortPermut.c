#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int printVet(int vet[], int n){
    for(int i=0; i<n; i++){
        printf("[%3d]", i);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("[%3d]", vet[i]);
    }
    printf("\n");
    return(0);
}

int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return(0);
}

int heapify(int vet[], int n, int ini){
    int esq = 2*ini + 1;
    int dir = 2*ini + 2;
    int imax;

    if(esq < n && vet[esq] > vet[ini]){
        imax = esq;
    }
    else{
        imax = ini;
    }
    
    if(dir < n && vet[dir] > vet[imax]){
        imax = dir;
    }

    if(imax != ini){
        swap(&vet[ini], &vet[imax]);
        heapify(vet, n, imax);
    }
    return(0);
}

int heapsort(int vet[], int size){

    for(int i = size/2 - 1; i >= 0; i--){
        heapify(vet, size, i);
    }

    for(int i=size-1; i>0; i--){
        swap(&vet[0], &vet[i]);
        heapify(vet, i, 0);
    }
    return(0);
}

int main(){
    int vet[10];
    srand(time(NULL));

    clock_t ini = clock();
    for(int i=0; i<10; i++){

        for(int j=0; j<10; j++){
            vet[j] = rand()%21;
        }

        printf("--------\nCombinacao %d:\n->Antes:\n", i+1);
        printVet(vet, 10);

        heapsort(vet, 10);

        printf("Depois:\n");
        printVet(vet, 10);

    }
    clock_t fim = clock();

    double tempoTot = (double)(fim - ini)/CLOCKS_PER_SEC;

    printf("Tempo total para as 10 combinacoes: %f segundos\n", tempoTot);

    return(0);
}