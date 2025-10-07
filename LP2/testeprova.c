#include<stdio.h>

int main(void){
    int vet[3] = {10, 25, 45};
    int* ptr[3]/*={&vet[0], &vet[1], &vet[2]}*/;

    for(int i=0; i<3; i++){
        *(ptr+i) = &vet[i];
        printf("--> %p\n", *(ptr+i));
        printf("--> %d\n", *(*(ptr+i)));
    }
    /*
    printf("--> %p\n", *(ptr));
    printf("--> %p\n", *(ptr+1));
    printf("--> %p\n", *(ptr+2));
    printf("VALOR\n");

    
    printf("--> %d\n", *(*(ptr)));
    printf("--> %d\n", *(*(ptr+1)));
    printf("--> %d\n", *(*(ptr+2)));*/

    return 0;
}