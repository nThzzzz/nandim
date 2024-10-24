#ifndef manip_matrizes
#define manip_matrizes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

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
void transposta(Fracao **matriz, int linhas, int colunas,pessoa pessoas[],int usuariologado);
void soma(pessoa pessoas[], int usuariologado);
void inversa(pessoa pessoas[],int usuariologado);
void sub(pessoa pessoas[], int usuariologado);
void multi(pessoa pessoas[], int usuariologado);
void login(pessoa pessoas[], int usuariologado);
void cadastrar(pessoa pessoas[], int usuariologado);
void sistemalinear(pessoa pessoas[], int usuariologado);
void decomposicaoLU(pessoa pessoas[], int usuariologado);

//---------- Aux ----------
void limpaterminal();
void espera();
void limpabuffer();
int verificaCPF(char *cpf);
void verifica_linhas(int *linhas_rece, int *colunas_rece);
void verifica_ordens(int *n);

//---------- TXT e Binário ----------
int arquivoexiste(const char *filename);
void escrever(pessoa pessoas[], int quantidade);
void ler(FILE *file, pessoa pessoas[], int quantidade);
void criaTXTHISTORICO(FILE **file,int usuariologado,pessoa pessoas[]);
void gravaMatrizesEmTxt(Fracao **matriz1, Fracao **matriz2, Fracao **matrizresultante, int linhas, int colunas,int usuariologado,pessoa pessoas[],char opc);
void lerhistorico(int usuariologado, pessoa pessoas[]);
void gravaSistemaEmTxt(Fracao **equacoes, Fracao *independentes, Fracao *solucoes, 
 int icognitas, int eqs, int usuariologado, pessoa pessoas[]);


//---------- Cria matrizes ----------
void cria_matriz(Fracao ***matriz, int linhas, int colunas, int segunda_matriz, int mesma_ordem);
void free_matriz(Fracao **matriz, int linhas);
void cria_submatriz(Fracao ***matriz, int linhas, int colunas);


#endif
