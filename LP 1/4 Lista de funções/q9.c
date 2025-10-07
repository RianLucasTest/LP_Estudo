#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int GerarNum();

int main(){
    int x, resp=0;
    printf("Tente adivinhar o numero\n");
    srand(time(NULL));
    x = GerarNum();
    while(resp != x){
        printf("De seu palpite:\n");
        scanf("%d", &resp);
        if(resp < x){
            printf("Muito baixo. Tente novamente.\n");
        }
        if(resp > x){
            printf("Muito alto. Tente novamente.\n");
        }
    }
    printf("Excelente! Voce adivinhou o numero!\n");
    system("PAUSE");
    return 0;
}

int GerarNum(){
    int i;
    i = 1 + rand() % 100;
    return i;
}