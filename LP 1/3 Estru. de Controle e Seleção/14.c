#include <stdio.h>
#include <stdlib.h>

int main(){
    int A, B, C, maior, cat1, cat2;

    printf("Valor de A:\n");
    scanf("%i", &A);
    maior = A;
    printf("Valor de B:\n");
    scanf("%i", &B);
    if(B > maior){
        maior = B;
    }
    printf("Valor de C:\n");
    scanf("%i", &C);
    if(C > maior){
        maior = C;
    }
    
    if(maior == A){
        cat1 = B;
        cat2 = C;
    }
    if(maior == B){
        cat1 = A;
        cat2 = C;
    }
    if(maior == C){
        cat1 = A;
        cat2 = B;
    }

    if ((maior*maior) == ((cat1*cat1) + (cat2*cat2))){
        printf("Os valores podem ser lados de um triangulo retangulo\n");
    }
    else
        printf("Os valores nao podem ser lados de um triangulo retangulo\n");
    
    
    system("PAUSE");
    return 0;
}