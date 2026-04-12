#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(void){
    int a[32][32][32]={0};
    
    for(int i=0; i<32; i++){
        for(int j=0; j<32; j++){
            for(int k=0; k<32;k++){
                a[i][j][k] = pow((i-16), 2) + pow((j-16), 2) + pow((k-16), 2);
                if(a[i][j][k] >= 54 && a[i][j][k] <= 74){
                    printf("a[%d][%d][%d]=%d\n", i, j, k, a[i][j][k]);
                }
            }
        }
    }
}