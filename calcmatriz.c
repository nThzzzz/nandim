#include <stdio.h>
#include <stdlib.h>

void printMatriz(float** matriz, int linhas, int colunas);
void soma(float** matriz, int linhas, int colunas);
void sub(float** matriz, int linhas, int colunas);
void multi(float** matriz, int linhas, int colunas);
float determinante(float** matriz, int n);
void inversa(float** matriz, int n);
void transoposta(float** matriz, int linhas, int colunas);
void decomposicaoLU(float** matriz, int n);

// // Estrutura para representar uma fração
// typedef struct {
//     int numerador;
//     int denominador;
// } Fracao;

// // Função para calcular o MDC (Máximo Divisor Comum)
// int mdc(int a, int b) {
//     if (b == 0) return a;
//     return mdc(b, a % b);
// }

// // Função para simplificar a fração
// Fracao simplificar(Fracao f) {
//     int divisor_comum = mdc(f.numerador, f.denominador);
//     f.numerador /= divisor_comum;
//     f.denominador /= divisor_comum;
//     return f;
// }

// // Função para somar duas frações
// Fracao somar(Fracao a, Fracao b) {
//     Fracao resultado;
//     resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
//     resultado.denominador = a.denominador * b.denominador;
//     return simplificar(resultado);
// }

// // Função para subtrair duas frações
// Fracao subtrair(Fracao a, Fracao b) {
//     Fracao resultado;
//     resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
//     resultado.denominador = a.denominador * b.denominador;
//     return simplificar(resultado);
// }

// // Função para ler um número inteiro ou uma fração
// Fracao lerFracao() {
//     Fracao f;
//     char barra;
    
//     // Tenta ler a fração (numerador/denominador) ou inteiro
//     if (scanf("%d/%d", &f.numerador, &f.denominador) != 2) {
//         // Se não for uma fração, leia como número inteiro
//         scanf("%d", &f.numerador);
//         f.denominador = 1;  // Inteiro é considerado como denominador 1
//     }
//     return simplificar(f);
// }

// void imprimirFracao(Fracao f) {
//     f = simplificar(f);
//     if (f.denominador == 1) {
//         printf("%d", f.numerador);  // Se denominador for 1, é um número inteiro
//     } else {
//         printf("%d/%d", f.numerador, f.denominador);  // Caso contrário, imprime a fração
//     }
// }

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    // Alocação dinâmica da matriz
    float** matriz = malloc(linhas * sizeof(float*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(float));
    }

    // Leitura dos elementos da matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o número da posição %d x %d: \n", i+ 1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printMatriz(matriz, linhas, colunas);

    printf("--------------------------------------|+| CALCULADORA 2 |+|--------------------------------------\n");
    printf("Qual operação deseja realizar: \nSoma\t\t-\t(+)\nSubtração\t-\t(-)\nMultiplicação\t-\t(*)\nInversa\t\t-\t(I)\nTransposta\t-\t(T)\nDeterminante\t-\t(D)\nDecomposição LU\t-\t(X)\n");
    printf("--------------------------------------|+| CALCULADORA 2 |+|--------------------------------------\n");

    getchar();
    char opc = getchar();
    if(opc == '+'){
        soma(matriz, linhas, colunas);
    }else if(opc == '-'){
        sub(matriz, linhas, colunas);
    }else if (opc == '*') {
        multi(matriz, linhas, colunas);
    }else if(opc == 'T'){
        transoposta(matriz, linhas, colunas);
    }else if (opc == 'D') {
         if (linhas == colunas) {
             float det = determinante(matriz, linhas);
             printf("O determinante da matriz é: %.2f\n", det);
         } else {
             printf("O determinante só pode ser calculado para matrizes quadradas.\n");
         }
    } else if (opc == 'I') {
         if (linhas == colunas) {
             inversa(matriz, linhas);
         } else {
             printf("A inversa só pode ser calculada para matrizes quadradas.\n");
         }
    }else if(opc == 'X'){
        decomposicaoLU(matriz, linhas);
    }

    // Liberação de memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

void printMatriz(float** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf(" %.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}



 void transoposta(float** matriz, int linhas, int colunas) {
     for (int i = 0; i < linhas; i++) {
         for (int j = 0; j < colunas; j++) {
            printf(" %.2f ", matriz[j][i]);
        }
        printf("\n");
     }
 }

 //Funçao soma de matrizes
 void soma(float** matriz, int linhas, int colunas){

     float** matriz2 = malloc(linhas * sizeof(float*));
     float** matrizresultante = malloc(linhas * sizeof(float*));
     for (int i = 0; i < linhas; i++) {
         matriz2[i] = malloc(colunas * sizeof(float));
     }
     for (int i = 0; i < linhas; i++) {
         matrizresultante[i] = malloc(colunas * sizeof(float));
     }

    //Entrada da segunda matriz
     for (int i = 0; i < linhas; i++) {
         for (int j = 0; j < colunas; j++) {
             printf("Digite o número da posição %d x %d da segunda matriz: \n", i + 1, j + 1);
             scanf("%f", &matriz2[i][j]);
         }
     }

      //Soma
     for (int i = 0; i < linhas; i++) {
         for (int j = 0; j < colunas; j++) {
             matrizresultante[i][j] = matriz[i][j] + matriz2[i][j];
         }
     }

     printf("A matriz resultante da multiplicação é: \n");
     printMatriz(matrizresultante, linhas, colunas);

      //Liberação de memória
     for (int i = 0; i < linhas; i++) {
         free(matriz2[i]);
     }
     for (int i = 0; i < linhas; i++) {
         free(matrizresultante[i]);
     }
     free(matriz2);
     free(matrizresultante);
 }

 //Função subtração de matrizes
 void sub(float** matriz, int linhas, int colunas){

     float** matriz2 = malloc(linhas * sizeof(float*));
     float** matrizresultante = malloc(linhas * sizeof(float*));
     for (int i = 0; i < linhas; i++) {
         matriz2[i] = malloc(colunas * sizeof(float));
     }
     for (int i = 0; i < linhas; i++) {
         matrizresultante[i] = malloc(colunas * sizeof(float));
     }

     // Entrada da segunda matriz
     for (int i = 0; i < linhas; i++) {
         for (int j = 0; j < colunas; j++) {
             printf("Digite o número da posição %d x %d da segunda matriz: \n", i + 1, j + 1);
             scanf("%f", &matriz2[i][j]);
         }
     }

    //Sub
     for (int i = 0; i < linhas; i++) {
         for (int j = 0; j < colunas; j++) {
             matrizresultante[i][j] = matriz[i][j] - matriz2[i][j];
         }
     }

     printf("A matriz resultante da multiplicação é: \n");
     printMatriz(matrizresultante, linhas, colunas);

     // Liberação de memória
     for (int i = 0; i < linhas; i++) {
         free(matriz2[i]);
     }
     for (int i = 0; i < linhas; i++) {
         free(matrizresultante[i]);
     }
     free(matriz2);
     free(matrizresultante);
 }

//Função de multiplicação de matrizes
 void multi(float** matriz, int linhas, int colunas) {
     int linhas2, colunas2;
     printf("Digite o número de linhas da segunda matriz: ");
     scanf("%d", &linhas2);
     printf("Digite o número de colunas da segunda matriz: ");
     scanf("%d", &colunas2);

     if (colunas != linhas2) {
         printf("Multiplicação de matrizes inválida! O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz.\n");
         return;
     }

     float** matriz2 = malloc(linhas2 * sizeof(float*));
     float** matrizresultante = malloc(linhas * sizeof(float*));
     for (int i = 0; i < linhas2; i++) {
         matriz2[i] = malloc(colunas2 * sizeof(float));
     }
     for (int i = 0; i < linhas; i++) {
         matrizresultante[i] = malloc(colunas2 * sizeof(float));
     }

     // Entrada da segunda matriz
     for (int i = 0; i < linhas2; i++) {
         for (int j = 0; j < colunas2; j++) {
             printf("Digite o número da posição %d x %d da segunda matriz: \n", i + 1, j + 1);
             scanf("%f", &matriz2[i][j]);
         }
     }

     // Multiplicação
     for (int i = 0; i < linhas; i++) {
         for (int j = 0; j < colunas2; j++) {
             matrizresultante[i][j] = 0;
             for (int k = 0; k < colunas; k++) {
                 matrizresultante[i][j] += matriz[i][k] * matriz2[k][j];
             }
         }
     }

    //Exibe a matriz resultante
     printf("A matriz resultante da multiplicação é: \n");
     printMatriz(matrizresultante, linhas, colunas2);

     // Liberação de memória
     for (int i = 0; i < linhas2; i++) {
         free(matriz2[i]);
     }
     for (int i = 0; i < linhas; i++) {
         free(matrizresultante[i]);
     }
     free(matriz2);
     free(matrizresultante);
 }

  //Função para calcular o determinante
 float determinante(float** matriz, int n) {
     float det = 0;

     if (n == 1) {
         return matriz[0][0];
     } else if (n == 2) {
         return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
     } else {
         for (int x = 0; x < n; x++) {
             float** submatriz = malloc((n - 1) * sizeof(float*));
             for (int i = 0; i < n - 1; i++) {
                 submatriz[i] = malloc((n - 1) * sizeof(float));
             }

             for (int i = 1; i < n; i++) {  //inicia com 1 pra não copiar a linha errada para submatriz da pra fazer sem soq da mais trabalho
                 int subi = 0;
                 for (int j = 0; j < n; j++) {
                     if (j == x) {  //Ve se nao ta usando uma coluna qur vai ser excluida    
                         continue;
                     }
                     submatriz[i - 1][subi] = matriz[i][j];
                     subi++;
                 }
             }

             det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * determinante(submatriz, n - 1); // Vou reduzindo ate ficar 2:2

             for (int i = 0; i < n - 1; i++) {
                 free(submatriz[i]);
             }
             free(submatriz);
         }
     }
     return det;
 }

  //Função para calcular a inversa
 void inversa(float** matriz, int n) {
     float det = determinante(matriz, n);
     if (det == 0) {
         printf("Matriz não tem inversa (determinante é zero).\n");
         return;
     }

     float** inversa = malloc(n * sizeof(float*));
     float** cofatores = malloc(n * sizeof(float*));

     for (int i = 0; i < n; i++) {
         inversa[i] = malloc(n * sizeof(float));
         cofatores[i] = malloc(n * sizeof(float));
     }

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             float** submatriz = malloc((n - 1) * sizeof(float*));
             for (int x = 0; x < n - 1; x++) {
                 submatriz[x] = malloc((n - 1) * sizeof(float));
             }

             int subi = 0;
             for (int a = 0; a < n; a++) {
                 if (a == i) continue;
                 int subj = 0;
                 for (int b = 0; b < n; b++) {
                     if (b == j){
                         continue;
                     }
                     submatriz[subi][subj] = matriz[a][b];
                     subj++;
                 }
                 subi++;
             }

             cofatores[i][j] = (float)((i + j) % 2 == 0 ? 1 : -1) * determinante(submatriz, n - 1);

             for (int x = 0; x < n - 1; x++) {
                 free(submatriz[x]);
             }
             free(submatriz);
         }
     }

    //Transposta da matriz de cofatores
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             inversa[i][j] = cofatores[j][i] / det;
         }
     }

     printf("A matriz inversa é:\n");
     printMatriz(inversa, n, n);

     // Liberação de memória
     for (int i = 0; i < n; i++) {
         free(inversa[i]);
         free(cofatores[i]);
     }
     free(inversa);
     free(cofatores);
 }

 void decomposicaoLU(float** matriz, int n){

     float** matrizL = malloc(n * sizeof(float*));
     float** matrizU = malloc(n * sizeof(float*));

     for (int i = 0; i < n; i++) {
         matrizL[i] = malloc(n * sizeof(float));
     }
     for (int i = 0; i < n; i++) {
         matrizU[i] = malloc(n * sizeof(float));
     }

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             if (i <= j)
                 matrizU[i][j] = matriz[i][j];  // Copia elementos de A para U
             else
                 matrizU[i][j] = 0;

             if (i == j)
                 matrizL[i][j] = 1;  // Elementos da diagonal de L são 1
             else if (i > j)
                 matrizL[i][j] = 0;
         }
     }

     // Fatoração LU
     for (int k = 0; k < n - 1; k++) {
         for (int i = k + 1; i < n; i++) {
             matrizL[i][k] = matriz[i][k] / matriz[k][k];  // Calcula o multiplicador
             for (int j = k; j < n; j++) {
                matriz[i][j] = matriz[i][j] - matrizL[i][k] * matriz[k][j];  // Eliminação
                matrizU[i][j] = matriz[i][j];   //Atualiza U com os valores resultantes
             }
         }
     }
     printf("-------------Matriz U-------------\n");
     printMatriz(matrizU, n, n);
     printf("-------------Matriz L-------------\n");
     printMatriz(matrizL, n, n);


     // Liberação de memória
     for (int i = 0; i < n; i++) {
         free(matrizL[i]);
     }
     for (int i = 0; i < n; i++) {
         free(matrizU[i]);
     }
     free(matrizL);
     free(matrizU);
 }