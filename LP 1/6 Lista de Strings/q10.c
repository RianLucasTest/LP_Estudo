#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define TAM 50

int main(){
    char str[TAM], remo;
    int i, j;

    printf("Insira uma string:\n");
    gets(str);
    printf("Digite um caracter a ser removido da string:\n");
    scanf(" %c", &remo);

    for(i = 0; str[i] != '\0'; i++){
        while(str[i] == remo){
            for(j = i; str[j] != '\0'; j++){
                str[j] = str[j+1];
            }
        }
    }
    printf("A sua string sem esse caracter e:\n\n%s\n", str);

    system("PAUSE");
    return 0;
}