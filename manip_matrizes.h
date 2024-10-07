#ifndef manip_matrizes
#define manip_matrizes

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fração
typedef struct Fracao {
    int numerador;
    int denominador;
} Fracao;

Fracao simplificar(Fracao f);
Fracao somar(Fracao a, Fracao b);
Fracao subtrair(Fracao a, Fracao b);
void imprimirFracao(Fracao f);
Fracao lerFracao();
int mdc(int a, int b);

void printMatriz(Fracao** matriz, int linhas, int colunas);
void transoposta(Fracao** matriz, int linhas, int colunas);
void soma(Fracao** matriz, int linhas, int colunas);
void sub(Fracao** matriz, int linhas, int colunas);
void multi(Fracao** matriz, int linhas, int colunas);
Fracao determinante(Fracao** matriz, int n);
void inversa(Fracao** matriz, int n);
void decomposicaoLU(Fracao** matriz, int n);

#endif