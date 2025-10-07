#include<stdlib.h>
#include<stdio.h>

void Ordenar(int, int, int);

int main(){
    int x1, x2, x3;
    printf("Digite tres numero (formato 'A B C')\n");
    scanf("%d %d %d", &x1, &x2, &x3);
    Ordenar(x1, x2, x3);

    system("PAUSE");
    return 0;
}

//mantém a ordem a < b < c correta
void Ordenar(int a, int b, int c){
    int temp;
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if(a > c){
        temp = c;
        c = a;
        a = temp;
    }
    if(b > c){
        temp = c;
        c = b;
        b = temp;
    }
    printf(" %d < %d < %d\n", a, b, c);
    
    return;
}