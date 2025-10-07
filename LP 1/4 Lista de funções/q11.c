#include<stdlib.h>
#include<stdio.h>

int HoraDia(int);

int main(){
    int tempo;
    printf("Digite a hora do dia em segundos para converter\n");
    scanf("%d", &tempo);
    HoraDia(tempo);
    system("PAUSE");
    return 0;
}

int HoraDia(int tempo){
    int min, seg, hora;
    if(tempo<0){ printf("Horario invalido\n");}
    if(tempo>86400){ printf("Horario invalido\n");}
    else{
        seg = tempo % 60;
        min = tempo / 60;
        hora = min / 60;
        min = min % 60;
        printf("A hora e: %02d:%02d:%02d\n", hora, min, seg);
    }
    return 0;
}