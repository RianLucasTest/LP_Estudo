#include<stdio.h>
#include<stdlib.h>

int main(){
    int cont, num, maior, maior2;
    maior = 0;
    maior2 = 0;
    
    for(cont = 0; cont < 10; cont++ ){
        printf("Insira um numero:\n");
        scanf("%d", &num);
        if (num > maior){
            maior2 = maior;
            maior = num;
        }
        
    }
    printf("O maior numero digitado e: %d,\n O segundo maior e: %d\n\n", maior, maior2);

    system("PAUSE");
    return 0;
}