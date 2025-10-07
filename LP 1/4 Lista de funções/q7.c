#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int Moeda();

int main(){
    int lanc, cara=0, coroa=0, i;
    srand(time(NULL));

    for(i=1; i<=100; i++){
        lanc = Moeda();
        if(lanc == 1){
            cara++;
        }
        if(lanc == 0){
            coroa++;
        }
    }
    printf("Vezes que cada lado apareceu:\nCoroa = %d\nCara = %d\n", coroa, cara);
    system("PAUSE");
    return 0;
}

int Moeda(){
    int i;
    i = rand() % 2;
    return i;
}