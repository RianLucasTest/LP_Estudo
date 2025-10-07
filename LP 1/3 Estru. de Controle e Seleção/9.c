#include<stdio.h>
#include<stdlib.h>
//quadrado vazado de asteriscos

int main(){
    int lado, coluna, linha;

    printf("Insira o valor do lado:\n");
    scanf("%d", &lado);

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
                        if(coluna == (lado)){
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


    system("PAUSE");
    return 0;
}