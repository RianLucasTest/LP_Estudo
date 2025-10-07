#include<stdio.h>

int main(void){
    int a=10, b=20;
    const int* ptr=&a;

    //*ptr = 30;
    //ERRO: "Expression must be a modifiable value"

    ptr=&b;

    return 0;
}