#include <stdio.h>
#include <stdlib.h>
#include "manip_matrizes.h"

//compilar 
// gcc -o calcmatriz main.c manip_matrizes.c
// ./calcmatriz

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    // Alocação dinâmica da matriz
    Fracao** matriz = (Fracao**)malloc(linhas * sizeof(Fracao*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (Fracao*)malloc(colunas * sizeof(Fracao));
    }

    // Leitura dos elementos da matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o número da posição %d x %d: \n", i + 1, j + 1);
            matriz[i][j] = lerFracao();
        }
    }

    printMatriz(matriz, linhas, colunas);

    printf("--------------------------------------|+| CALCULADORA 2 |+|--------------------------------------\n");
    printf("Qual operação deseja realizar: \nSoma\t\t-\t(+)\nSubtração\t-\t(-)\nMultiplicação\t-\t(*)\nInversa\t\t-\t(I)\nTransposta\t-\t(T)\nDeterminante\t-\t(D)\nDecomposição LU\t-\t(X)\n");
    printf("--------------------------------------|+| CALCULADORA 2 |+|--------------------------------------\n");

    getchar(); // Limpa o buffer do enter anterior
    char opc = getchar();
    if (opc == '+') {
        soma(matriz, linhas, colunas);
    } else if (opc == '-') {
        sub(matriz, linhas, colunas);
    } else if (opc == '*') {
        multi(matriz, linhas, colunas);
    } else if (opc == 'T') {
        transoposta(matriz, linhas, colunas);
    } else if (opc == 'D') {
        if (linhas == colunas) {
            Fracao det = determinante(matriz, linhas);
            printf("O determinante da matriz é: ");
            imprimirFracao(det);
            printf("\n");
        } else {
            printf("O determinante só pode ser calculado para matrizes quadradas.\n");
        }
    } else if (opc == 'I') {
        if (linhas == colunas) {
            inversa(matriz, linhas);
        } else {
            printf("A inversa só pode ser calculada para matrizes quadradas.\n");
        }
    } else if (opc == 'X') {
        decomposicaoLU(matriz, linhas);
    }

    // Liberação de memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

