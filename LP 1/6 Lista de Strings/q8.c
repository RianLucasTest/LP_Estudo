#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define TAM 50

int main(){
    char str1[TAM], str2[TAM];
    int i, j;
    printf("Digite a primeira string:\n");
    gets(str1);
    printf("Digite a segunda string\n");
    gets(str2);
    for(j = 0; str2[j] != '\0'; j++){}
    for(i = 0, j--; i < TAM; i++, j--){
        str1[i] = tolower(str1[i]);
        str2[j] = tolower(str2[j]);
        if (str1[i] != str2[j]){
            printf("As strings nao formam anagramas\n");
            return 0;
        }
    }
    printf("As strings formam um anagrama\n");

    system("PAUSE");
    return 0;
}