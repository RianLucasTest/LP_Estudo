#include<stdio.h>
#include<stdlib.h>

int main(){
    int qtd, num, cont, soma;
    soma = 0;
    printf("Insira o tamanho da sua sequencia de numeros\n");
    scanf("%d", &qtd); 

    for(cont = 0; cont < qtd; cont++){
        printf("Digite um numero inteiro\n");
        scanf("%d", &num);
        soma = soma + num;
    }
    printf("A soma da sequencia de numeros e: %d\n", soma);
    
    system("PAUSE");
    return 0;
}