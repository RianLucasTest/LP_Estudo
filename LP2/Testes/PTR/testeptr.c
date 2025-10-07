#include<stdio.h>
void ptr_test(void);

int main(void){
    //ptr_test();

    char** naipe={"copas","ouro","espadas","paus"};

    for(int i=0; i<4;i++){
        printf("->%s", *naipe);
    }







    
    return 0;
}








void ptr_test(void){
    
    int n=10;
    int* ptr=&n;
    int** pptr=&ptr;

    printf("\n");
    printf( "=====VALORES=====\n"
            "Valor por var: %d\n"
            "Valor por ptr1: %d\n"
            "Valor por ptr2: %d\n", n, *ptr, **pptr);
    printf("\n");
    
    
    printf( "=====Enderecos_n=====\n"
            "Endereco por var: %p\n"
            "Endereco por ptr1: %p\n"
            "Endereco por ptr2: %p\n", &n, ptr, *pptr);
    printf("\n");

    
    printf( "=====Endereco ptrs=====\n"
            "Endereco de ptr1: %p\n"
            "Endereco ptr1 por ptr2: %p\n"
            "Endereco de ptr2: %p\n", &ptr, pptr, &pptr);
    printf("\n");
    
}