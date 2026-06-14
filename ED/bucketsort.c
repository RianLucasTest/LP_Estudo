#include<stdio.h>
#include<stdlib.h>

void prn_vet(int x[], int size){
    for(int i=0; i<size; i++) { 
        printf("%3d,", x[i]); 
    }
}

void bubbleSort(int a[], int size){
    int aux;
     for(int i=0; i<=size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(a[j] > a[j+1]){
                aux=a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}

void bucketSort(int vet[], int n, int qtd_buc){

    int max=vet[0];
    for(int i=1; i<n; i++){
        if(vet[i] > max) { max = vet[i]; }
    }

    int qtdElem[qtd_buc]; 
    for(int i = 0; i < qtd_buc; i++){
        qtdElem[i] = 0;
    }

    int intervalo = max/qtd_buc + 1;

    int b[qtd_buc][intervalo];
    for(int i=0; i<qtd_buc; i++){
        for(int j=0; j<intervalo; j++) { 
            b[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        int idx = vet[i] / intervalo;
        b[idx][qtdElem[idx]++] = vet[i];
    }

    for(int i=0; i<qtd_buc; i++){
        bubbleSort(b[i], qtdElem[i]);
    }

    int count=0;
    for(int i=0; i<qtd_buc; i++){
        for(int j=0; j<qtdElem[i]; j++){
            vet[count] = b[i][j];
            count++;
        }
    }
}

int main(){

    int a[] = {42, 32, 33, 52, 37, 47, 51};
    int size_a = sizeof(a) / sizeof(a[0]);

    bucketSort(a, size_a, 4);

    prn_vet(a, size_a);

    return(0);
}