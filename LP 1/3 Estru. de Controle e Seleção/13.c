#include<stdio.h>
#include<stdlib.h>

int main(){
    int cont, num, dig;
    cont = 0;

    printf("Insira um numero inteiro:\n");
    scanf("%d", &num);

    
    while(num > 0){
        dig = num % 10;
        num = num / 10;
        if(dig == 7){
            cont++;
        }
    }
    printf("%d digitos sao iguais a 7\n", cont);

    system("PAUSE");
    return 0;
}