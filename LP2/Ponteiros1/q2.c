#include<stdio.h>
#include"funcoesh.h"

int main(void){
    int y=5;
    int* p=&y;

    manipula(p);

    printf("Novo y: %d\n", *p);
    return 0;
}