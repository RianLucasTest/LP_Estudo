#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int GerarNum();
int Maior(int, int);
int Menor(int, int);

int main(){
    int n, prod=1, soma=0, maior, menor;
    srand(time(NULL));
    printf("Digite a quantidade de numeros\n");
    scanf("%d", &n);
    for (int x=0, i=1; i<=n; i++){
        x = GerarNum();
        if(i==1){
            maior = x;
            menor = x;
        }
        maior = Maior(x,maior);
        menor = Menor(x, menor);
        if(x%2 == 0){
            prod *= x;
        }
        if(x%2 == 1){
            soma += x;
        }
        printf("-> %d\n", x);
    }
    printf("\n");
    printf("O maior numero e %d\nO menor numero e %d\nO produtorio dos numeros pares e %d\nO somatorio dos numeros impares e %d\n", maior, menor, prod, soma);
    system("PAUSE");
    return 0;
}

int GerarNum(){
    int i;
    i = 1 + rand() % 100;
    return i;
}
int Maior(int x1, int x2){
    int maior;
    if(x1>x2){
        maior = x1;
    }
    else{
        maior = x2;
    }
    return maior;
}
int Menor(int x1, int x2){
    int menor;
    if(x1<x2){
        menor = x1;
    }
    else{
        menor = x2;
    }
    return menor;
}