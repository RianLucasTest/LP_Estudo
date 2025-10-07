#include<stdio.h>
#include"funcoesh.h"

int main(void){
    int v1=10, v2=20, v3=30;
    
    int* ap[3]={NULL, NULL, NULL};

    ap[0] = &v1;
    ap[1] = &v2;
    ap[2] = &v3;
    array_ptr(ap, 3);
    

    return 0;
}