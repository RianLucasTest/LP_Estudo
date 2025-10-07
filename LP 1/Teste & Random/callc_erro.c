#include<stdlib.h>
#include<stdio.h>
float mult(float, float);
float sub(float, float);
float add(float, float);
float divi(float, float);

int main(){
    float num, res_p=0;
    char op='+';
    printf("----------------Calculadora----------------\n");
    printf("\tOperacoes disponiveis\n\n\tAdicao\t\t+\n\tSubtracao\t-\n\tMultiplicacao\t*\n\tDivisao\t\t/\n\n");

    scanf("%f", &res_p);
    while(op != '='){
        scanf(" %c", &op);
        scanf("%f", &num);
        switch(op){
            case('+'):
                res_p = add(num, res_p);
                break;
            case('-'):
                res_p = sub(num, res_p);
                break;
            case('*'):
                res_p = mult(num, res_p);
                break;
            case('/'):
                res_p = divi(num, res_p);
                break;
            case('='):
                break;
            default:
                printf("Operacao invalidade: Erro");
                break;
        }
        printf("%.2f\n", res_p);
    }
    printf("Resultado final = %.2f", res_p);
    system("PAUSE");
    return 0;
}

float add(float num, float resu){
    return num+resu;
}

float sub(float num, float resu){
    return resu-num;
}

float mult(float num, float resu){
    return resu*num;
}

float divi(float num, float resu){
    return resu/num;
}