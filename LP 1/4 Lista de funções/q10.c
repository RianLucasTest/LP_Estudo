#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int Dado();

int main(){
    short int x1, x2, soma=0, ponto, i=0;
    srand(time(NULL));
    system("PAUSE");
    while(soma!=ponto){
        x1=Dado();
        x2=Dado();
        soma = x1 + x2;
        printf("A soma dos dados foi: %d\n", soma);
        while(i<1){
            if(soma==7 || soma==11){
                printf("Voce ganhou!\n");
                system("PAUSE");
                return 0;
            }
            if(soma==2 || soma==3 || soma==12){
                printf("Voce perdeu!\n");
                system("PAUSE");
                return 0;
            }
            else{
                ponto = soma;
                soma=0;
            }
            i++;
        }
        if(soma==7){
            printf("Voce perdeu\n");
            system("PAUSE");
            return 0;
        }
    }
    printf("Voce ganhou!\n");
    system("PAUSE");
    return 0;
}
int Dado(){
    return (1+rand()%6);
}