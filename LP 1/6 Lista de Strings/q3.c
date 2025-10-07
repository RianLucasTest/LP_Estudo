#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[50];
    int i;

    printf("Digite uma 'string':\n");
    gets(str);
    printf("Voce digitou:\n");
    for(i = 0; str[i] != '\0'; i++){
        printf("%c\t%d\n", str[i], str[i]);
    }

    system("PAUSE");
    return 0;
}