#include<stdio.h>
#include<stdlib.h>

int main(){
    int cont, num, maior;
    maior = 0;
    
    for(cont = 0; cont < 10; cont++ ){
        printf("Insira um numero:\n");
        scanf("%d", &num);
        if (num > maior){
            maior = num;
        }
        
    }
    printf("O maior numero digitado e: %d\n\n", maior);

    system("PAUSE");
    return 0;
}