#include<stdio.h>
#include"funcoesh.h"


int main(void){
    int x, y;
    int* pa = &x;
    int* pb = &y;

    verif(pa, pb);


    return 0;
}