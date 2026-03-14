#include<stdio.h>
#include<stdlib.h>

int qtd_passos=0;
void hanoi(char, char, char, int);
int max0(int[], int n);
int maxm(int[], int, int);
void ordnc(int[], int, int);int minm(int [], int m, int n);



int main(void){

    hanoi('A', 'B', 'C', 3);
    printf("QTD de passos: %d\n", qtd_passos);

    int vet[5] = {3, 6, -9, 94, 2};

    max0(vet, 4);
    printf("%d\n", vet[0]);

    maxm(vet, 4, 4);
    printf("%d\n", vet[4]);

    ordnc(vet, 0, 4);
    for(int i=0; i<5; i++) { printf("__> %d\n", vet[i]); }

    return 0;
}

void hanoi(char orig, char aux, char dest, int n){
    if(n == 1){
        printf("Movimento disco %d: %c-->%c\n", n, orig, dest);
        qtd_passos++;
        return;
    }
    hanoi(orig, dest, aux, n-1);
    printf("Movimento Disco %d: %c-->%c\n", n, orig, dest);
    qtd_passos++;
    hanoi(aux, orig, dest, n-1);
}

int max0(int vet[], int n){
    if(n == 0){
        return vet[0];
    }
    if(vet[n] > vet[0]){
        int temp = vet[n];
        vet[n] = vet[0];
        vet[0] = temp;
    }
    int m= max0(vet, n-1);
    return m;
}

int maxm(int vet[], int m, int n){
    if(n==m){
        return vet[m];
    }
    if(vet[n] > vet[m]){
        int temp = vet[n];
        vet[n] = vet[m];
        vet[m] = temp;
    }
    return maxm(vet, m, n-1);
}

void ordnc(int vet[], int m, int n){
    if(m==n){
        return;
    }
    maxm(vet, m, n);
    ordnc(vet, m+1, n);
    return;
}
