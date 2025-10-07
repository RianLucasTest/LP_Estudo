#include <stdio.h>
#include <stdlib.h>

int main() {
    int cat1, cat2, hip;

    printf("O conjunto dos Numeros de Pitagoras e:\n");

    for(hip = 1; hip < 500; hip++){
        for(cat1 = 1; cat1 < 500; cat1++){
            for(cat2 = 1; cat2 < 500; cat2++){
                if((hip * hip) == (cat1 * cat1) + (cat2 * cat2)){
                    printf("hip = %d, cat1 = %d, cat2 = %d\n", hip, cat1, cat2);
                }
            }
        }
    }

    system("PAUSE");
    return 0;
}