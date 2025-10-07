#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, dig, out;
    out = num = dig = 0;
    
    printf("Digite o numero que voce quer inverter:\n");
    scanf("%d", &num);

    while(num > 0){
        dig = num % 10;
        num = num / 10;
        out = dig + (out * 10); 
    }

    printf("O numero invertido e: %d\n\n", out);

    system("PAUSE");
    return 0;
}