#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[50];
    int i;

    printf("Digite uma string:\n");
    gets(str);
    printf("Voce digitou:\n");
    for(i = 0; str[i] != '\0'; i++){
        printf("%c\n", str[i]);
    }

    system("PAUSE");
    return 0;
}