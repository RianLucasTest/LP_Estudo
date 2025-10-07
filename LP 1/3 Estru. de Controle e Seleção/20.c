#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, cont, maior, menor, lim;

    printf("Insira um valor inteiro\n");
    scanf("%d", &lim);
    if (lim == 0){
        printf("Nenhum valor a ser inserido.\n");
    }
    else{
        maior = menor = lim;
        
            for(cont = 1; cont < lim; cont++){ 
                printf("Insira um numero inteiro:\n");
                scanf("%d", &num);
                if(num >= maior){
                    maior = num;
                }
                if (num < menor){
                        menor = num;
                }
            
            }
    }
    printf("O maior valor inserido e %d, e o menor e %d\n", maior, menor);

    system("PAUSE");
    return 0;
}