#include<stdio.h>
#include<stdlib.h>

int Perfeito(int);

int main(){
    int num;
    printf("Os numeros perfeitos de 1 a 100 sao:\n");
    for(num=1; num<=100; num++){
        if (Perfeito(num) == 1){
            printf("-->%d\n", num);
            printf("\tOs fatores de %d sao:\n", num);
            for(int i=1; i<num; i++){
                if(num%i == 0){
                printf("\t%d\n", i);
                }
            }
        }
    }
    system("PAUSE");
    return 0;
}

int Perfeito(int num){
    int verif=0;
    for(int i=1; i<num; i++){
        if(num%i == 0){
            verif +=i;
        }
    }
    if(verif == num){
        return 1;
    }
    else{
        return 0;
    }
}