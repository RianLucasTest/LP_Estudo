#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[50];

    printf("Digite uma 'string'\n");
    gets(str);
    printf("Voce digitou:\n   %s\n", str);

    system("PAUSE");
    return 0;
}
