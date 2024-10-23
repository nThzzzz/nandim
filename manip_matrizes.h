#ifndef manip_matrizes
#define manip_matrizes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Fracao {
  int numerador;
  int denominador;
} Fracao;

typedef struct {
  char CPF[12];
  char senha[7];
  char nome[100];
} pessoa;

// ----- Fração -----
Fracao simplificar(Fracao f);
Fracao somar(Fracao a, Fracao b);
Fracao subtrair(Fracao a, Fracao b);
void imprimirFracao(Fracao f);
Fracao lerFracao();
int mdc(int a, int b);
int comparar(Fracao a, Fracao b);

// ---------- Menus ---------
void menu(pessoa pessoas[], int usuariologado);
void menuinicial(pessoa pessoas[], int usuariologado);

// ---------- Principal ----------
void printMatriz(Fracao **matriz, int linhas, int colunas);
void transoposta(Fracao **matriz, int linhas, int colunas);
void soma();
void sub();
void login(pessoa pessoas[], int usuariologado);
void cadastrar(pessoa pessoas[], int usuariologado);
void sistemalinear();

//---------- Aux ----------
void limpaterminal();
void espera();
void limpabuffer();
int verificaCPF(char *cpf);
int arquivoexiste(const char *filename);
void escrever(pessoa pessoas[], int quantidade);
void ler(FILE *file, pessoa pessoas[], int quantidade);

//---------- Cria matrizes ----------
void cria_matriz(Fracao ***matriz, int linhas, int colunas, int segunda_matriz, int mesma_ordem);
void free_matriz(Fracao **matriz, int linhas);

#endif