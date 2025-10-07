#include<stdio.h>
#include<stdlib.h>

int main(){
    char sel;
    int num1, num2, resultado;

    printf("Digite o primeiro numero:\n");
    scanf("%d", &num1);
    printf("Digite o segundo numero:\n");
    scanf("%d", &num2);
    printf("Operacoes disponives\nA\tAdicao\nS\tSubtracao\nD\tDivisao\nP\tProduto\n");
    printf("Selecione uma operacao:\n");
    scanf(" %c", &sel);

    switch (sel){
        case ('A'): case ('a'):
            resultado = num1 + num2;
            printf("O resultado da operacao e: %d\n", resultado);
            break;
        case ('S'): case ('s'): 
            resultado = num1 - num2;
            printf("O resultado da operacao e: %d\n", resultado);
            break;
        case ('D'): case ('d'):
            if(num2 == 0){
                printf("Não existe divisao\n");
            }
            else{
                resultado = num1 / num2;
            }
            printf("O resultado da operacao e: %d\n", resultado);
            break;
        case ('P'): case ('p'):
            resultado = num1 * num2;
            printf("O resultado da operacao e: %d\n", resultado);
            break;
        default:
            printf("ERRO: Opcao selecionada nao existe!\n");
    }

    system("PAUSE");
    return 0;
}