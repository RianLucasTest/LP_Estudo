#include<stdlib.h>
#include<stdio.h>
int SelQuad(int, int);

int main(){
    int sel, lado;
    printf("Selecione qual quadrado deseja:\n\nQuadrado vazado---> 0\nQuadrado cheio---> 1\n");
    scanf("%d", &sel);
    printf("Insira a medida dos lados:\n");
    scanf("%d", &lado);
    SelQuad (sel, lado);
    system("PAUSE");
    return 0;
}

int SelQuad(int sel, int lado){
    int cont1, cont2;
    switch(sel){
        case(1):
                for(cont1 = 0; cont1 < lado; cont1++){
                    for(cont2 = 0; cont2 < lado; cont2++){
                        printf("*");
                    }
                    printf("\n");
                }
            printf("\n");
            break;
        case(0):
            for(cont2 = 1; cont2 <= lado; cont2++){
                if(cont2 == 1){
                    for(cont1 = 1; cont1 <= lado; cont1++){
                        printf("*");
                    }
                    printf("\n");
                }
                else{
                    if(cont2 == lado){
                        for(cont1 = 1; cont1 <= lado; cont1++){
                            printf("*");
                        }
                        printf("\n");
                    }
                    else{
                        for(cont1 = 1; cont1 <= lado; cont1++){
                            if(cont1 == 1){
                                printf("*");
                            } 
                            else{
                                if(cont1 == lado){
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
            break;
            printf("\n");
        default:
            printf("Seleção invalida\n");
            break;
    }
        return 0;
}