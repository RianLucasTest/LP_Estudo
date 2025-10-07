#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, cont_dig, pot10, dig_ini, dig_fim, cont, verif;
    cont_dig = cont = verif = 0;
    pot10 = 1;

    printf("Digite um numero:\n");
    scanf("%d", &num);
    
    if(num < 0){
        printf("O numero nao e palindromo!\n");
    }
    else{

        while(pot10 <= num){
            pot10 = pot10 * 10;
            cont_dig++;
        }
        pot10 = pot10 / 10;

        while(cont < (cont_dig/2)){

            dig_ini = num / pot10;
            num = num % pot10;
            dig_fim = num % 10;
            num = num / 10;
            pot10 /= 100;
            cont++;

            if(dig_ini == dig_fim){
                verif++;
            }  
            else{
                break;
            } 
        }
        if(verif == cont){
            printf("O numero e palindromo!\n");
        }
        else{
        printf("O numero nao e palindromo!\n");
        }
    }

    system("PAUSE");
    return 0;
}