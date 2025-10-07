#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int GerarNum();

int main(){
    int x1, x2, resp, stop=1;
    srand(time(NULL));

    while(stop != 0){
        x1 = GerarNum();
        x2 = GerarNum();
        printf("Quanto e %d vezes %d?\n", x1, x2);
        scanf("%d", &resp);
        while(resp != x1*x2){
            printf("Tente Novamente\n");
            scanf("%d", &resp);
        }
        printf("Muito bem!\n");
    }
    system("PAUSE");
    return 0;
}

int GerarNum(){
    int i;
    i = rand() % 10;
    return i;
}