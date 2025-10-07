#include<stdlib.h>
#include<stdio.h>
#define TAM_V 20

int Verif(int[], int);

int main(){
    int num[TAM_V], i, x;
    printf("Preencha com %d numeros (tecle 'enter' apos cada numero)\n", TAM_V);
    for(i = 0; i < TAM_V; i++){
        scanf("%d", &num[i]);
    }
    printf("Digite um valor para buscar no vetor:\n");
    scanf("%d", &x);
    if(Verif(num, x) != 0){
        printf("O valor %d foi encontrado na posicao %d\n", x, Verif(num, x));
    }
    else{
        printf("Valor nao encontrado no vetor\n");
    }
    system("PAUSE");
    return 0;
}

int Verif(int num[], int valor){
    int i;
    for(i = 0; i < TAM_V; i++){
        if(num[i] == valor){
            return i;
        }
    }    
    return 0;
}