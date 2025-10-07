#include <stdio.h>
#include <stdlib.h>

//

int main() {
    int n, c, cont, c2;

    printf("Digite o valor do lado do triângulo:\n");
    scanf("%d", &n);
    c2 = n;
    printf("\n"); 

    //padrão(1)
    for(c = 1; c <= n; c++){
        for(cont = 1; cont <= c; cont++){
           printf("*");
        }
        printf("\n");
    }
    printf("\n");

    //padrão(2)
    for(c = n; c > 0; c--){
        for(cont = 1; cont <= c; cont++){
           printf("*");
        }
        printf("\n");
    }
    printf("\n");

   //padrão(3)
   for(c = 1; c <= n; c++){
        if(c==1){

        }
        else{
            for(cont = 1; cont < c; cont++){
            printf(" ");
            }
        }
        for(cont = c2; cont >= 1; cont--){
            printf("*");
        }
        c2--;
        printf("\n");
    }
    printf("\n");

    //padrão(4)
    for(c = 1; c <= n; c++){
        if(c==n){

        }
        else{
            for(cont = c2; cont > 1; cont--){
                printf(" ");
            }
            c2--;
        }
        for(cont = 1; cont <= c; cont++){
            printf("*");
            }
            printf("\n"); 
    }
    printf("\n"); 

    system("PAUSE");
    return 0;
}