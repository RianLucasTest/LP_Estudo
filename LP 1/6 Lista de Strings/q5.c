#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[50];
    int i;

    printf("Digite uma 'string':\n");
    gets(str);

    for(i = 0; str[i] != '\0'; i++){}
    printf("Voce digitou (ordem inversa):\n");
    for(i-- ; i >= 0; i--){
        printf("%c\n", str[i]);
    }


    system("PAUSE");
    return 0;
}