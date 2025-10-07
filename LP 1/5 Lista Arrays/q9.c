#include<stdlib.h>
#include<stdio.h>
#define TAM_VET 100

int main(){
    char num[TAM_VET];
    int i;
    printf("Preencha com %d numeros \n", TAM_VET);
    for(i = 0; i < TAM_VET; i++){
        num[i] = getchar();
        if(num[i] == 10){
            break;
        }
    }
    printf("\n");
    for(i = 0; i < TAM_VET; i++){
        if(num[i] == ' '){
            num[i] = 0;
        }
    }
    for(i = 0; i < TAM_VET; i++){
        printf("%c", num[i]);
        if(num[i] == 10){
            break;
        }
    }


    system("PAUSE");
    return 0;
}