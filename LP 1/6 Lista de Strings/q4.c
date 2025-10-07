#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define TAM 50

int main(){
    char str[TAM];
    int i, par;

    printf("Digite uma string:\n");
    gets(str);
    printf("Deseja converter toda a string para maiusculas?\n");
    printf("1 para Sim, 0 para Nao\n");
    scanf("%d", &par);
    
    printf("\n");
    if(par){
        for(i = 0; str[i] != '\0'; i++){
            printf("%c", toupper(str[i]));
        }
    }
    else{
        for(i = 0; str[i] != '\0'; i++){
            printf("%c", tolower(str[i]));
        }

    }
    printf("\n");

    system("PAUSE");
    return 0;
}