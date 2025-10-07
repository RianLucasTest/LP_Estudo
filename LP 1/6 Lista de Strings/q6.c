#include<stdio.h>
#include<stdlib.h>

int main(){
    char frase[50];
    int i;

    printf("Digite uma 'string':\n");
    gets(frase);

    printf("Voce digitou:\n");

    for(i = 0; frase[i] != '\0'; i++){
        if(frase[i] == ' ')
            printf("\n");
        else{
            printf("%c", frase[i]);
        }
    }
    printf("\n");


    system("PAUSE");
    return 0;
}