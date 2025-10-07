#include <stdio.h>
#include <stdlib.h>

#define LIN 4
#define COL 4

void LerMatriz(char mat[LIN][COL]);
int EhPalindromo(char mat[LIN][COL]);
void PrintMatriz(char mat[LIN][COL]);

int main() {
    char mat1[LIN][COL], mat2[LIN][COL];

    printf("Digite a primeira matriz 4x4:\n");
    LerMatriz(mat1);

    printf("Digite a segunda matriz 4x4:\n");
    LerMatriz(mat2);

    printf("\nPrimeira matriz:\n");
    PrintMatriz(mat1);
    printf("\nSegunda matriz:\n");
    PrintMatriz(mat2);

    if (EhPalindromo(mat1))
        printf("\nA primeira matriz eh palindromo!\n");
    else
        printf("\nA primeira matriz NAO eh palindromo.\n");

    if (EhPalindromo(mat2))
        printf("\nA segunda matriz eh palindromo!\n");
    else
        printf("\nA segunda matriz NAO eh palindromo.\n");

    return 0;
}

// Função para ler matriz 4x4
void LerMatriz(char mat[LIN][COL]) {
    int i, j;
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf(" %c", &mat[i][j]);  // Espaço antes do %c para consumir o ENTER
        }
    }
}

// Função para imprimir matriz
void PrintMatriz(char mat[LIN][COL]) {
    int i, j;
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se matriz é palíndromo
int EhPalindromo(char mat[LIN][COL]) {
    int i, j;

    // Verifica simetria de linhas
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL / 2; j++) {
            if (mat[i][j] != mat[i][COL - j - 1])
                return 0;
        }
    }

    // Verifica simetria de colunas
    for (j = 0; j < COL; j++) {
        for (i = 0; i < LIN / 2; i++) {
            if (mat[i][j] != mat[LIN - i - 1][j])
                return 0;
        }
    }

    return 1;
}
