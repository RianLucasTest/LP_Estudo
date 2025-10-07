#include<stdio.h>
#include<stdlib.h>

int main(){
    int cont, num, media, soma;
    num = 0;
    soma = cont = 0;

    while(num != 9999){
        printf("Insira um Valor (9999 para finalizar e exibir media):\n");
        scanf("%d", &num);
        if(num == 9999){
            break;
        }
        cont = cont + 1;
        soma = soma + num;   
    }
    media = soma / cont;
    printf("A media desses numeros e: %d\n", media);

    system("PAUSE");
    return 0;
}