#include "manip_matrizes.h"
#include <stdio.h>
#include <stdlib.h>

// compilar
//  gcc -o calcmatriz main.c manip_matrizes.c
//  ./calcmatriz

int main() {
  int linhas, colunas;
  FILE *file;
  pessoa pessoas[10];
  int verificacao;
  int usuariologado = -1;
  verificacao = arquivoexiste("dados.bin");
  if (verificacao == 0) { // O arquivo existe
    escrever(pessoas, 10);
  } else {
    ler(&file, pessoas, 10);
  }
  printf("%d\n", verificacao);
  menuinicial(pessoas, usuariologado, linhas, colunas);

  return 0;
}
