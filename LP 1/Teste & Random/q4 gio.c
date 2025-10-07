#include<stdlib.h>
#include<stdio.h>

/*Uma grande companhia química paga seus vendedores por comissão. Os vendedores recebem
$200 por semana mais 9 por cento de suas vendas brutas naquela semana. Por exemplo, um
vendedor que vender $5000 em produtos químicos recebe $650. 800Desenvolva um programa que
receba as vendas brutas de cada vendedor na última semana, calcule seu salário e o exiba.
Processe um vendedor de cada vez.*/

int main(){

    float sal, vendas;

    printf("Entre com as vendas (digite -1 para finalizar):\n");
    scanf("%f", &vendas);

    while(vendas != -1){
        sal = 200.0 + (0.09*vendas);
        printf("Salario = %.2f\n", sal);

        printf("Entre com as vendas (digite -1 para finalizar):\n");
        scanf("%f", &vendas);
    }

    printf("fim do processamento");
    return 0;
}