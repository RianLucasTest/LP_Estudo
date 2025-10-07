#include<stdlib.h>
#include<stdio.h>

int Primo(int);

int main(){

    printf("Numeros primos de 1 a 1000:\n");
    for(int i=1; i<=1000; i++){
        if(Primo(i)==1){
            printf("> %d\n", i);
        }
    }

    system("PAUSE");
    return 0;
}


int Primo(int num){
    int cont=0;
    for(int i=1; i<=num; i++){
        if(num%i == 0){
            cont++;
        }
        if(cont>2){
            break;
        }
    }
    if(cont == 2){
        return 1;
    }
    else{
        return 0;
    }
}