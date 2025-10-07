#include <stdio.h>
#include <stdlib.h>
//19. Elabore um programa que, para uma entrada do salário bruto, informe a contribuição ao INSS e o
//salário líquido restante.

int main(){
    float salario, c, sm, resto;
    sm = 1518;
    c = 0;
    
    printf("Digite o valor do salario:\n");
    scanf("%f", &salario);

    if (salario <= (3 * sm)){
        c = 0.08 * salario;
        resto = salario - c;
    }
    else{
        c = 0.1 * salario;
        resto = salario - c;
    }
    if (c > sm){
        c = sm;
        resto = salario - c;
    }
    printf("A contribuicao para o INSS e %.2f, e o salario liquido restante e %.2f\n", c, resto);

    system("PAUSE");
    return 0;
}