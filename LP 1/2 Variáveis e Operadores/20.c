#include <stdio.h>
#include <stdlib.h>
//20. Amplie o programa do exercício anterior para uma vez recebido o salário bruto informe a
//contribuição ao INSS, o valor do IRRF e o salário líquido.

int main(){
    float salario, c, sm, sliquido, irrf;
    sm = 1518;
    c = 0;
    
    printf("Digite o valor do salario:\n");
    scanf("%f", &salario);

    if (salario <= (3 * sm)){
        c = 0.08 * salario;
        sliquido = salario - c;
    }
    else{
        c = 0.1 * salario;
        sliquido = salario - c;
    }
    if (c > sm){
        c = sm;
        sliquido = salario - c;
    }

    if (sliquido < 900){
        irrf = 0;
    }
    else{
        if (sliquido < 1800){
            irrf = (sliquido * 0.15) - 135;
        }
        else{ 
                irrf = (sliquido * 0.275) - 360;
            }
        }
    printf("A contribuicao para o INSS e %.2f, o valor do IRRF e %.2f e o salario liquido restante e %.2f\n", c, irrf, sliquido);
    
    system("PAUSE");
    return 0;
}