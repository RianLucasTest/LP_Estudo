#include<stdlib.h>
#include<stdio.h>
#define QTD 5
typedef struct{
    char equipe[50];    //nome da equipe
    char piloto[50];    //nome do piloto
    int largada;    //posição de largada
    float vmedia;   //velocidade media
    float ttot;     //tempo total
    float tmaior;   //volta mais rapida
} Tcarro;

int main(){
    Tcarro res[QTD], temp;
    int i, j, i_menor_volta;

    //pede dados
    printf("Insira os resultados da corrida:\n");
    for(i=0; i<QTD; i++){
        printf("==========Carro %d==========\n", i+1);
        printf("Insira o nome da equipe: ");
        fflush(stdin);
        gets(res[i].equipe);
        printf("Insira o nome do piloto: ");
        fflush(stdin);
        gets(res[i].piloto);
        printf("Insira a posicao de largada: ");
        scanf("%d", &res[i].largada);
        printf("Insira a velocidade media: ");
        scanf("%f", &res[i].vmedia);
        printf("Insira o tempo total: ");
        scanf("%f", &res[i].ttot);
        printf("Insira o tempo da volta mais rapida: ");
        scanf("%f", &res[i].tmaior);
    }

    //organiza de acordo ao tempo(posicao de cada um)
    for(i=0; i<QTD; i++){
        for(j=0; j<(QTD-i-1); j++){
            if(res[j].ttot > res[j+1].ttot){
                temp = res[j];
                res[j] = res[j+1];
                res[j+1] = temp;
            }
        }
    }

    //compara a volta mais lenta
    i_menor_volta = 0; 
    for(i=1; i<QTD; i++){
        if(res[i].tmaior > res[i_menor_volta].tmaior){
            i_menor_volta = i; 
        }
    }

    //exibições
    printf("Lista de acordo com as posicoes de cada um: \n");
    for(i=0; i<QTD; i++){
        printf("%d--> %s\n", i+1, res[i].equipe);
    }
    printf("A equipe ganhadora foi: %s\n", res[0].equipe);

    printf("O piloto que deu a volta mais lenta foi: %s\n", res[i_menor_volta].piloto);


    system("PAUSE");
    return 0;
}