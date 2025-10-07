#include<stdio.h>
#include<stdlib.h>

int main(){
    float taxa, capital, juros, dias;
    capital = 1;

    while (capital > 0){
        printf("Insira o capital inicial do emprestimo (0 para finalizar):\n");
        scanf("%f", &capital);
        if (capital <= 0){
            break;
        }
        printf("Insira a taxa de juros (anual):\n");
        scanf("%f", &taxa);
        printf("Insira o periodo do emprestimo (dias):\n");
        scanf("%f", &dias);
        juros = (capital * taxa * dias)/365;
        printf("O valor do juros e: R$%.2f\n\n", juros);
    }

    system("PAUSE");
    return 0;
}