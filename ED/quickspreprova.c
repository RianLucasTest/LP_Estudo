#include<stdio.h>
#include<stdlib.h>
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

int partition_hoare(int vet[], int ini, int fim, int* i, int* j){
    *i = ini; *j=fim;
    int iPivo = ini + rand()%(fim-ini+1);
    int pivo = vet[iPivo];

    while(*i <= *j){

        while(*i <= fim && vet[*i] < pivo){
            (*i)++;
        }
        while(*j >= ini && vet[*j] > pivo){
            (*j)--;
        }
        if(*i <= *j){
            swap(&vet[*i], &vet[*j]);
            (*i)++; (*j)--;
        }

    }
    return(0);
}

int partition_lomotu(int vet[], int ini, int fim){
    int pivo = vet[fim];
    int i=ini;

    for(int k=ini; k<fim; k++){
        if(vet[k] <= pivo){
            swap(&vet[i], &vet[k]);
            i++;
        }
    }
    swap(&vet[i], &vet[fim]);
    return(i);
}

int quicksort_hoare(int vet[], int ini, int fim){
    if(ini >= fim){
        return(0);
    }
    int i, j;
    partition_hoare(vet, ini, fim, &i, &j);
    quicksort_hoare(vet, ini, j);
    quicksort_hoare(vet, i, fim);
    return(0);
}

int quicksort_lomotu(int vet[], int ini, int fim){
    if(ini >= fim){
        return(0);
    }
    int q=partition_lomotu(vet, ini, fim);
    quicksort_lomotu(vet, ini, q-1);
    quicksort_lomotu(vet, q+1, fim);
    return(0);
}

int merge(int vet[], int ini, int meio, int fim){

    int n1, n2;
    n1 = meio - ini+1;
    n2 = fim - meio;
    int aux1[n1], aux2[n2];

    for(int i=0; i<n1; i++){
        aux1[i] = vet[ini+i];
    }
    for(int i=0; i<n2; i++){
        aux2[i] = vet[meio+1+i];
    }

    int cont=ini, i=0, j=0;
    while(i<n1 && j<n2){
        if(aux1[i] <= aux2[j]){
            vet[cont] = aux1[i];
            cont++; i++;
        }
        else{
            vet[cont] = aux2[j];
            cont++; j++;
        }
    }
    while(i<n1){
        vet[cont] = aux1[i];
        cont++; i++;
    }
    while(j<n2){
        vet[cont] = aux2[j];
        cont++; j++;
    }
    return(0);
}

int mergesort(int vet[], int ini, int fim){
    if(ini >= fim){
        return(0);
    }

    int meio = (ini+fim)/2;
    mergesort(vet, ini, meio);
    mergesort(vet, meio+1, fim);
    merge(vet, ini, meio, fim);
    return(0);
}

int heapify(int vet[], int n, int ini){
    int iesq = 2*ini+1;
    int idir = 2*ini+2;
    int imax=ini;

    if(iesq < n && vet[iesq] >= vet[imax]){
        imax = iesq;
    }
    if(idir < n && vet[idir] >= vet[imax]){
        imax = idir;
    }

    if(imax != ini){
        swap(&vet[imax], &vet[ini]);
        heapify(vet, n, imax);
    }

    return(0);
}

int montar_heap(int vet[], int n){
    for(int i=n/2 -1; i>=0; i--){
        heapify(vet, n, i);
    }
    return(0);
}

int heapsort(int vet[], int n){ //n==size
    montar_heap(vet, n);
    for(int i=n-1; i>0; i--){
        swap(&vet[i], &vet[0]);
        heapify(vet, i, 0);
    }
    return(0);
}

int main(){

    srand(time(NULL));
    int vet[]={9,3,6,2,7,8,1,5,4};
    int fim=sizeof(vet)/sizeof(vet[0]);
    printf("%d\n", fim);

    /*
    //QUICKSORT
    printVet(vet, fim);
    printf("QUICK\n");
    quicksort_hoare(vet, 0, fim);
    printVet(vet, fim);*/

    /*
    //MERGESORT
    printVet(vet, fim);
    printf("MERGE\n");
    mergesort(vet, 0, fim-1);
    printVet(vet, fim);*/

    
    printVet(vet, fim);
    printf("HEAP\n");
    heapsort(vet, fim); //aqui fim==size
    printVet(vet, fim);


    return(0);
}