#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define VET 25

int main(){
    int i, art[VET];
    float preco[VET]={0}, desc[VET]={0};
    srand(time(NULL));
    for(i = 0; i < VET; i ++){
        art[i] = 1 + rand() % 5;
    }

    for(i = 0; i < VET; i++){
        switch(art[i]){
            case 1:
                preco[i] = 100;
                desc[i] = 0.1;
                break;
            case 2:
                preco[i] = 150;
                desc[i] = 0.12;
                break;
            case 3:
                preco[i] = 180;
                desc[i] = 0.16;
                break;
            default:
                preco[i] = 200;
                desc[i] = 0.2;
                break;
        }
    }
    printf("Novos precos e descontos:\n");
    printf("Artigo\tCategoria\tPreco\tDesconto\n");
    for(i = 0; i < VET; i++){
        printf("%3d\t%3d\t\t%3.2f\t\t%3.2f\n", i+1, art[i], preco[i], desc[i]);
    }

    system("PAUSE");
    return 0;
}