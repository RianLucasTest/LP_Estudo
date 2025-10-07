#include <stdio.h>
#include <stdlib.h>
int QuadCheio (int);
int QuadVazad (int);
int Triangulo (int);

int main (){
    int lado;

    printf("Digite o valor do lado das formas(sera impresso formas com lados n, ate n+2):\n");
    scanf("%d", &lado);

    for (int i=lado; i <= (lado+2); i++){
        QuadCheio (i);
        QuadVazad (i);
        Triangulo (i);
    }

    system("PAUSE");
    return 0;
}

//quadrado cheio
int QuadCheio (int lado){
    int cont1, cont2;

        for(cont1 = 0; cont1 < lado; cont1++){
            for(cont2 = 0; cont2 < lado; cont2++){
                printf("*");
            }
            printf("\n");
        }
    printf("\n");
    return 0;
}

//quadrado vazado
int QuadVazad (int lado){
    int coluna, linha;

    for(linha = 1; linha <= lado; linha++){
        if(linha == 1){
            for(coluna = 1; coluna <= lado; coluna++){
                printf("*");
            }
            printf("\n");
        }
        else{
            if(linha == lado){
                for(coluna = 1; coluna <= lado; coluna++){
                    printf("*");
                }
                printf("\n");
            }
            else{
                for(coluna = 1; coluna <= lado; coluna++){
                    if(coluna == 1){
                        printf("*");
                    } 
                    else{
                        if(coluna == lado){
                            printf("*");
                        }
                        else{
                            printf(" ");
                        }
                    }
                    
                }
                printf("\n");
                
            }
        }
    }

    printf("\n");
    return 0;
}

//triangulo 
int Triangulo (int lado){
    int c, cont;

    printf("\n"); 

    for(c = 1; c <= lado; c++){
          for(cont = 1; cont <= c; cont++){
        printf("*");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}