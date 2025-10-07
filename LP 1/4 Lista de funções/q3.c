#include<stdio.h>
#include<stdlib.h>

int multiplo(int, int);

int main(){
    int n, i, x1, x2;
    printf("Digite a quantidade (n) de pares:\n");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("Digite o primeiro numero\n");
        scanf("%d", &x1);
        printf("Digite o segundo numero\n");
        scanf("%d", &x2);
        if(x1 == 0 || x2==0){
            printf("O segundo nao e multiplo do primeiro\n");
        }
        else if(multiplo(x1, x2)==1){
            printf("O segundo e multiplo do primeiro\n");
        }
        else{
            printf("O segundo nao e multiplo do primeiro\n");
        }
    }
    return 0;
}

int multiplo (int x1, int x2){
    int resp;
    if((x2%x1)== 0){
        resp = 1;
    }
    else{
        resp = 0;
    }
    return resp;
}
