#include<stdio.h>
#include<stdlib.h>

int main(){
    float vendas, salario;
    vendas = 1;

    while (vendas > 0 ){
        printf("Insira as vendas brutas do vendedor(-1 para finalizar):\n");
        scanf("%f", &vendas);
        if (vendas < 0)
            break;
        salario = 200 + (0.09 * vendas);
        printf("Salario: %.2f\n", salario);
    }


    system("PAUSE");
    return 0;
}