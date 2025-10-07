#include <stdio.h>
#include <stdlib.h>
//22. O número 3025 possui uma característica interessante. Elabore um programa que verifique se um número inteiro de 
//quatro algarismos(digitado) tem essa propriedade ou não.

int main(){
    int a, p1, p2, t;

    printf("Digite um numero de 4 digitos:\n");
    scanf("%i", &a);
    
    if(a > 9999 || a < 1000){
        printf("Erro: o numero nao tem 4 digitos\n");
    }
    else{
        p1 = a / 100;
        p2 = a % 100;

        t = (p1 + p2) * (p1 + p2);
        if (t == a){
            printf("O numero digitado possui a propriedade\n");
        }
        else{
            printf("O numero digitado nao possui a propriedade\n");
        }
    }
    
    system("PAUSE");
    return 0;
}