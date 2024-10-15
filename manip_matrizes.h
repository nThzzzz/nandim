#ifndef manip_matrizes
#define manip_matrizes

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fração
typedef struct Fracao {
  int numerador;
  int denominador;
} Fracao;
typedef struct {
  char CPF[12];
  char senha[7];
  char nome[100];
  FILE *historico;
  char nome_hist[100];
} pessoa;

Fracao simplificar(Fracao f);
Fracao somar(Fracao a, Fracao b);
Fracao subtrair(Fracao a, Fracao b);
void imprimirFracao(Fracao f);
Fracao lerFracao();
int mdc(int a, int b);

void printMatriz(Fracao **matriz, int linhas, int colunas);
void transoposta(Fracao **matriz, int linhas, int colunas);
void soma(Fracao **matriz, int linhas, int colunas);
void sub(Fracao **matriz, int linhas, int colunas);
void multi(Fracao **matriz, int linhas, int colunas);
Fracao determinante(Fracao **matriz, int n);
void inversa(Fracao **matriz, int n);
void decomposicaoLU(Fracao **matriz, int n);
void menu(pessoa pessoas[], int usuariologado, int *linhas, int *colunas);
int arquivoexiste(const char *filename);
void escrever(pessoa pessoas[], int quantidade);
void ler(FILE *file, pessoa pessoas[], int quantidade);
void login(pessoa pessoas[], int usuariologado, int *linhas, int *colunas);
void cadastrar(pessoa pessoas[], int usuariologado, int *linhas, int *colunas);
void menuinicial(pessoa pessoas[], int usuariologado, int *linhas,int *colunas);
void limpaterminal();
void espera();
void limpabuffer();
int verificaCPF(char *cpf);
Fracao **criarMatriz(int *linhas, int *colunas);
void limparMatriz(Fracao **matriz, int linhas);
void criaTXTHISTORICO(FILE *file,int usuariologado,pessoa pessoas[]);
void escrevehistorico(int usuariologado,pessoa pessoas[]);
void lerhistorico(int usuariologado, pessoa pessoas[]);

#endif
