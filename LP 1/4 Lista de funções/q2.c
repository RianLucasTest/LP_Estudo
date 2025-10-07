#include<stdio.h>
#include<stdlib.h>

long int PotenciaInt (int, int);

int main(){
    int base, expo;
    printf("Digite a base:\n");
    scanf("%d", &base);
    printf("Digite o expoente:\n");
    scanf("%d", &expo);
    printf("Base^Expoente = %ld", PotenciaInt(base, expo));
    return 0;
}

long int PotenciaInt (int base, int expo){
    int i, result=1;
    for(i = 1; i<=expo; i++){
        result *= base;
    }
    return result;

}
