#include<stdio.h>
#include<stdlib.h>

int main(){
    int h_trab, h_extra;
    float valor_hn, salario;
    h_trab = 1;

    while (h_trab > 0){
        printf("Insira o numero de horas trabalhadas (0 para finalizar):\n");
        scanf("%d", &h_trab);
        if (h_trab <= 0){
            break;
        }
        printf("Insira o valor da hora normal do trabalhador:\n");
        scanf("%f", &valor_hn);
        
        if(h_trab <= 40){
            salario = h_trab * valor_hn;
        }
        else{
            h_extra = h_trab - 40;
            salario = (40 * valor_hn) + (h_extra * 1.5 * valor_hn);
        }
        printf("Salario e: %.2f \n\n", salario);

    }

    system("PAUSE");
    return 0;
}