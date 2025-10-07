#include<stdio.h>
#include<stdlib.h>
#define VET 12

int main(){
    float vendas[VET], total=0;
    int i;
    printf("Insira as vendas mensais do ano de 2015\n");
    for(i = 0; i < VET; i++){
        printf("Mes %d\n", i+1);
        scanf("%f", &vendas[i]);
        total += vendas[i];
    }
    if(total < 120000){
        printf("Valor total inválido para analise do imposto: Valor menor que 120000\n");
    }
    else if(total <= 150000){
        printf("O imposto de renda a ser pago em 2015 e de: %.2f(taxa de 25%%))\n", 0.25*total);
    }
    else if(total > 250000){
        printf("O imposto de renda a ser pago em 2015 e de: %.2f(taxa de 29%%)\n", 0.29*total);
    }
    else{
        printf("O imposto de renda a ser pago em 2015 e de: %.2f(taxa de 27%%)\n", 0.27*total);
    }

    system("PAUSE");
    return 0;
}