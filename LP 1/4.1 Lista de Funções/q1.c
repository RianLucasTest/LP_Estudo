#include<stdlib.h>
#include<stdio.h>

float Desconto(int, float);


int main(){
    int qtd;
    float preco;

    printf("Digite quantas unidades do produto:\n");
    scanf("%d", &qtd);
    printf("Digite o preco do produto:\n");
    scanf("%f", &preco);
    printf("O valor final dos produtos com desconto e de: %.2f\n", Desconto(qtd, preco));

    system("PAUSE");
    return 0;
}

float Desconto(int n, float p){
    float result;
    result = n * p;
    if(n > 12){
        result -= result * 0.1;
    }
    else if(n > 6){
        result -= result * 0.04;
    }
    return result;
}