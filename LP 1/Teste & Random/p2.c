#include<stdlib.h>
#include<stdio.h>

int main(){
    int ide, tempo, melhort=0, tmedio=0, cont=0, idewin=0;

    printf("Digite o identificado do atleta\n");
    scanf("%d", &ide);   

    while(ide > 0){ 
        printf("Digite o tempo do atleta (em segundos)\n");
        scanf("%d", &tempo);  

        if(cont == 0)
            melhort = tempo;
        if(tempo < melhort){
            melhort = tempo;
            idewin = ide;
        }   
        cont++;
        tmedio += tempo;

        printf("Digite o identificado do atleta\n");
        scanf("%d", &ide);  
    }
    tmedio /= cont;
    printf("O melhor corredor foi o %d\n", idewin);
    printf("O tempo medio foi de %d", tmedio);
    
    return 0;
}

//Escreva um programa que processe os resultados de uma maratona. para cada corredor o programa deverá receber o identificador do atleta(inteiro positivo) 
//e o tempo de corrida em segundos. Seu programa deverá informar o identificador do atleta que chegou primeiro (melhor tempo) 
//e o tempo médio de todos os corredores. desconhece-se o número de pessoas que participaram da maratona, 
//o programa finalizará quando o identificador do atleta não seja válido (inteiro negativo ou zero)