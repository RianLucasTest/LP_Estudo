#include<stdlib.h>
#include<stdio.h>

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
    for(int i=size-1; i>0; i--){
        swap(&vet[0], &vet[i]);
        heapify(vet, i, 0);
    }
    return(0);
}

int main(){
    int vet[] = {1, 2, 3, 7, 17, 19, 25, 36, 100};

    int size = sizeof(vet)/sizeof(vet[0]);

    printf("Vetor inicial ANTES do heapify:\n");
    printVet(vet, size);

    for(int i = size/2 - 1; i >= 0; i--){
        heapify(vet, size, i);
    }

    printf("Vetor inicial DEPOIS do heapify:\n");
    printVet(vet, size);


    heapsort(vet, size);

    printf("Vetor ordenado com heapsort:\n");
    printVet(vet, size);

    return(0);
}