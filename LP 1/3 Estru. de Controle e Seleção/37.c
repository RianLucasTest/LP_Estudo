#include <stdio.h>
#include <stdlib.h>

int main() {
    float celsius, faren;

    printf("Farenheit\tCelsius\n");

    for(faren = 50; faren <= 150; faren+=5){
        celsius = (5.0/9.0) + (faren - 32);
        printf("%.2f\t\t%.2f\n", faren, celsius);
    }


    system("PAUSE");
    return 0;
}