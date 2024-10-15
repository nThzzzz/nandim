#include "manip_matrizes.h"
#include <stdio.h>
#include <stdlib.h>

// Função para calcular o MDC (Máximo Divisor Comum)
int mdc(int a, int b) {
  if (b == 0)
    return a;
  return mdc(b, a % b);
}

// Função para simplificar a fração
Fracao simplificar(Fracao f) {
  int divisor_comum = mdc(f.numerador, f.denominador);
  f.numerador /= divisor_comum;
  f.denominador /= divisor_comum;
  return f;
}

// Função para somar duas frações
Fracao somar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador =
      a.numerador * b.denominador + b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Função para subtrair duas frações
Fracao subtrair(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador =
      a.numerador * b.denominador - b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Funcao que dividi frações
Fracao dividir(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador;
  resultado.denominador = a.denominador * b.numerador;
  return simplificar(resultado);
}

// Função que multiplica frações
Fracao multiplicar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.numerador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Função para ler um número inteiro ou uma fração
Fracao lerFracao() {
  Fracao f;
  char frac[20];

  // Tenta ler a fração (numerador/denominador) ou inteiro
  scanf("%s", frac);

  // Tenta analisar a entrada como uma fração
  if (sscanf(frac, "%d/%d", &f.numerador, &f.denominador) == 2) { // Genial
    // Se a fração for válida
    if (f.denominador == 0) {
      printf("Denominador não pode ser zero.\n");
      f.denominador = 1;
    }
  } else {
    // Se não for uma fração, leia como número inteiro
    f.numerador = atoi(frac); // Converte de string pra numero
    f.denominador = 1;
  }
  return simplificar(f);
}

// Pra usar em casos que se inicia como 0;
Fracao fracPadrao() {
  Fracao f;

  f.numerador = 0;
  f.denominador = 1;

  return simplificar(f);
}

Fracao frac_unitaria_Positiva() {
  Fracao f;
  f.numerador = 1;
  f.denominador = 1;
  return simplificar(f);
}

Fracao frac_unitaria_Negativa() {
  Fracao f;

  f.numerador = -1;
  f.denominador = 1;

  return simplificar(f);
}

int comparar(Fracao a, Fracao b) {
  if (a.numerador == b.numerador && a.denominador == b.denominador) {
    return 0;
  } else {
    return 1;
  }
}

// Função para imprimir a fração
void imprimirFracao(Fracao f) {
  f = simplificar(f);
  if (f.denominador == 1) {
    printf("  %d  ", f.numerador); // Se denominador for 1, é um número inteiro
  } else {
    printf(" %d/%d ", f.numerador,
           f.denominador); // Caso contrário, imprime a fração
  }
}

// Função para imprimir a matriz de frações
void printMatriz(Fracao **matriz, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      imprimirFracao(matriz[i][j]);
    }
    printf("\n");
  }
}

void transoposta(Fracao **matriz, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      imprimirFracao(matriz[j][i]);
    }

    printf("\n");
  }
  return;
}

// Funçao soma de matrizes
void soma(Fracao **matriz, int linhas, int colunas) {

  Fracao **matriz2 = (Fracao **)malloc(linhas * sizeof(Fracao *));
  Fracao **matrizresultante = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas; i++) {
    matriz2[i] = malloc(colunas * sizeof(Fracao));
  }
  for (int i = 0; i < linhas; i++) {
    matrizresultante[i] = malloc(colunas * sizeof(Fracao));
  }

  // Entrada da segunda matriz
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("Digite o número da posição %d x %d da segunda matriz: \n", i + 1,
             j + 1);
      matriz2[i][j] = lerFracao();
    }
  }

  // Soma
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      matrizresultante[i][j] = somar(matriz[i][j], matriz2[i][j]);
    }
  }

  printf("A matriz resultante da soma é: \n");
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
  return;
}

// Função subtração de matrizes
void sub(Fracao **matriz, int linhas, int colunas) {

  Fracao **matriz2 = (Fracao **)malloc(linhas * sizeof(Fracao *));
  Fracao **matrizresultante = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas; i++) {
    matriz2[i] = malloc(colunas * sizeof(Fracao));
  }
  for (int i = 0; i < linhas; i++) {
    matrizresultante[i] = malloc(colunas * sizeof(Fracao));
  }

  // Entrada da segunda matriz
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("Digite o número da posição %d x %d da segunda matriz: \n", i + 1,
             j + 1);
      matriz2[i][j] = lerFracao();
    }
  }

  // Sub
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      matrizresultante[i][j] = subtrair(matriz[i][j], matriz2[i][j]);
    }
  }

  printf("A matriz resultante da subtração é: \n");
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
  return;
}

// //Função de multiplicação de matrizes
void multi(Fracao **matriz, int linhas, int colunas) {
  int linhas2, colunas2;
  printf("Digite o número de linhas da segunda matriz: ");
  scanf("%d", &linhas2);
  printf("Digite o número de colunas da segunda matriz: ");
  scanf("%d", &colunas2);

  if (colunas != linhas2) {
    printf(
        "Multiplicação de matrizes inválida! O número de colunas da primeira "
        "matriz deve ser igual ao número de linhas da segunda matriz.\n");

    return;
  }

  Fracao **matriz2 = (Fracao **)malloc(linhas2 * sizeof(Fracao *));
  Fracao **matrizresultante = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas2; i++) {
    matriz2[i] = malloc(colunas2 * sizeof(Fracao));
  }
  for (int i = 0; i < linhas; i++) {
    matrizresultante[i] = malloc(colunas2 * sizeof(Fracao));
  }

  // Entrada da segunda matriz
  for (int i = 0; i < linhas2; i++) {
    for (int j = 0; j < colunas2; j++) {
      printf("Digite o número da posição %d x %d da segunda matriz: \n", i + 1,
             j + 1);
      matriz2[i][j] = lerFracao();
    }
  }

  // Multiplicação
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas2; j++) {
      matrizresultante[i][j] = fracPadrao();
      for (int k = 0; k < colunas; k++) {
        matrizresultante[i][j] = somar(
            matrizresultante[i][j], multiplicar(matriz[i][k], matriz2[k][j]));
      }
    }
  }

  // Exibe a matriz resultante
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
  return;
}

// Função para calcular o determinante
Fracao determinante(Fracao **matriz, int n) {
  Fracao det = fracPadrao();

  if (n == 1) {
    return matriz[0][0];
  } else if (n == 2) {
    return subtrair(multiplicar(matriz[0][0], matriz[1][1]),
                    multiplicar(matriz[0][1], matriz[1][0]));
  } else {
    for (int x = 0; x < n; x++) {
      Fracao **submatriz = (Fracao **)malloc((n - 1) * sizeof(Fracao *));
      for (int i = 0; i < n - 1; i++) {
        submatriz[i] = malloc((n - 1) * sizeof(Fracao));
      }

      for (int i = 1; i < n;
           i++) { // inicia com 1 pra não copiar a linha errada para submatriz
                  // da pra fazer sem soq da mais trabalho
        int subi = 0;
        for (int j = 0; j < n; j++) {
          if (j == x) { // Ve se nao ta usando uma coluna qur vai ser excluida
            continue;
          }
          submatriz[i - 1][subi] = matriz[i][j];
          subi++;
        }
      }

      if (x % 2 == 0) {
        det = somar(
            multiplicar(multiplicar(frac_unitaria_Positiva(), matriz[0][x]),
                        determinante(submatriz, n - 1)),
            fracPadrao());
      } else {
        det = somar(
            multiplicar(multiplicar(frac_unitaria_Negativa(), matriz[0][x]),
                        determinante(submatriz, n - 1)),
            fracPadrao());
      }
      // det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * determinante(submatriz, n
      // - 1); // Vou reduzindo ate ficar 2:2

      for (int i = 0; i < n - 1; i++) {
        free(submatriz[i]);
      }
      free(submatriz);
    }
  }
  return det;
}

// Função para calcular a inversa
void inversa(Fracao **matriz, int n) {
  Fracao det = determinante(matriz, n);
  if (comparar(determinante(matriz, n), fracPadrao()) == 0) {
    printf("Matriz não tem inversa (determinante é zero).\n");
    return;
  }

  Fracao **inversa = (Fracao **)malloc(n * sizeof(Fracao *));
  Fracao **cofatores = (Fracao **)malloc(n * sizeof(Fracao *));

  for (int i = 0; i < n; i++) {
    inversa[i] = malloc(n * sizeof(Fracao));
    cofatores[i] = malloc(n * sizeof(Fracao));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      Fracao **submatriz = (Fracao **)malloc((n - 1) * sizeof(Fracao *));
      for (int x = 0; x < n - 1; x++) {
        submatriz[x] = malloc((n - 1) * sizeof(Fracao));
      }

      int subi = 0;
      for (int a = 0; a < n; a++) {
        if (a == i)
          continue;
        int subj = 0;
        for (int b = 0; b < n; b++) {
          if (b == j) {
            continue;
          }
          submatriz[subi][subj] = matriz[a][b];
          subj++;
        }
        subi++;
      }

      if ((i + j) % 2 == 0) {
        cofatores[i][j] = multiplicar(frac_unitaria_Positiva(),
                                      determinante(submatriz, n - 1));
      } else {
        cofatores[i][j] = multiplicar(frac_unitaria_Negativa(),
                                      determinante(submatriz, n - 1));
      }
      // cofatores[i][j] = (float)((i + j) % 2 == 0 ? 1 : -1) *
      // determinante(submatriz, n - 1);

      for (int x = 0; x < n - 1; x++) {
        free(submatriz[x]);
      }
      free(submatriz);
    }
  }

  // Transposta da matriz de cofatores
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      inversa[i][j] = dividir(cofatores[j][i], det);
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
  return;
}

void decomposicaoLU(Fracao **matriz, int n) {

  Fracao **matrizL = (Fracao **)malloc(n * sizeof(Fracao *));
  Fracao **matrizU = (Fracao **)malloc(n * sizeof(Fracao *));

  for (int i = 0; i < n; i++) {
    matrizL[i] = malloc(n * sizeof(Fracao));
  }
  for (int i = 0; i < n; i++) {
    matrizU[i] = malloc(n * sizeof(Fracao));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= j)
        matrizU[i][j] = matriz[i][j]; // Copia elementos de A para U
      else
        matrizU[i][j] = fracPadrao();

      if (i == j)
        matrizL[i][j] =
            frac_unitaria_Positiva(); // Elementos da diagonal de L são 1
      else if (i > j)
        matrizL[i][j] = fracPadrao();
    }
  }

  // Fatoração LU
  for (int k = 0; k < n - 1; k++) {
    for (int i = k + 1; i < n; i++) {
      matrizL[i][k] =
          dividir(matriz[i][k], matriz[k][k]); // Calcula o multiplicador
      for (int j = k; j < n; j++) {
        matriz[i][j] =
            subtrair(matriz[i][j], multiplicar(matrizL[i][k], matriz[k][j]));
        matrizU[i][j] = matriz[i][j];
        // matriz[i][j] = matriz[i][j] - matrizL[i][k] * matriz[k][j];  //
        // Eliminação matrizU[i][j] = matriz[i][j];   //Atualiza U com os
        // valores resultantes
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
  return;
}

void menu(pessoa pessoas[], int usuariologado, int *linhas, int *colunas) {
  int condicao = 1;
  printf("--------------------------------------|+| CALCULADORA 2 "
         "|+|--------------------------------------\n");
  printf("Qual operação deseja realizar: "
         "\nSoma\t\t-\t(+)\nSubtração\t-\t(-)\nMultiplicação\t-\t(*)"
         "\nInversa\t\t-\t(I)\nTransposta\t-\t(T)\nDeterminante\t-\t(D)"
         "\nDecomposição LU\t-\t(X)\n");
  printf("--------------------------------------|+| CALCULADORA 2 "
         "|+|--------------------------------------\n");

  while (condicao) {
    getchar(); // Limpa o buffer do enter anterior
    char opc = getchar();
    switch (opc) {
    case '+':
      menu(pessoas, usuariologado, linhas, colunas);
      break;
    case '-':
      menu(pessoas, usuariologado, linhas, colunas);
      break;
    case '*':
      menu(pessoas, usuariologado, linhas, colunas);
      break;
    case 'T':
      menu(pessoas, usuariologado, linhas, colunas);
      break;
    case 'D':
      menu(pessoas, usuariologado, linhas, colunas);
      break;

    case 'I':
      menu(pessoas, usuariologado, linhas, colunas);
      break;
    default:
      condicao = 0;
      menuinicial(pessoas, usuariologado, linhas, colunas);
      ;
      break;
    }
  }
}
int arquivoexiste(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    fclose(file);
    return 1; // Arquivo existe
  }
  return 0; // Arquivo não existe
}
void escrever(pessoa pessoas[], int quantidade) {
  FILE *file = fopen("dados.bin", "wb");

  fwrite(pessoas, sizeof(pessoa), 10, file);
  fclose(file);
}

// Lê as informações e as atribui a variáveis
void ler(FILE *file, pessoa pessoas[], int quantidade) {
  file = fopen("dados.bin", "rb");

  fread(pessoas, sizeof(pessoa), 10, file);

  fclose(file);
}

void login(pessoa pessoas[], int usuariologado, int *linhas, int *colunas) {
  limpaterminal();
  char cpflogin[12];
  char senhalogin[7];

  printf("|------------------------------[Login]------------------------------|"
         "\n");
  printf("Digite o CPF: ");
  scanf("%s", cpflogin);

  if (strlen(cpflogin) != 11) {
    printf("CPF inválido!\n");
    limpabuffer();
    espera();
    limpaterminal();
    menu(pessoas, usuariologado, linhas,
         colunas); // Chamando o novo menu sem cotações
  }
  limpabuffer();

  for (int i = 0; i < 10; i++) {
    if (strcmp(cpflogin, pessoas[i].CPF) == 0) {
      printf("Digite sua senha: ");
      scanf("%s", senhalogin);
      if (strlen(senhalogin) != 6) {
        printf("Senha inválida!\n");
        limpabuffer();
        espera();
        menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
      }
      limpabuffer();
      if (strcmp(senhalogin, pessoas[i].senha) == 0) {
        printf("Logado com sucesso\n");
        usuariologado = i;
        criaTXTHISTORICO(pessoas[usuariologado].historico, usuariologado,
                         pessoas);
        escrevehistorico(usuariologado, pessoas);
        lerhistorico(usuariologado, pessoas);
        // espera();
        // menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo
        // menu
        return;
      } else {
        printf("Senha incorreta\n");
        espera();
        menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
        return;
      }
    }
  }
  printf("CPF não cadastrado!\n");
  espera();
  menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
}

void cadastrar(pessoa pessoas[], int usuariologado, int *linhas, int *colunas) {
  limpaterminal();
  char cpfcadastro[12];
  char senhacadastro[7];
  int cadastrados = 0;

  printf("|------------------------------[Cadastro]----------------------------"
         "|\n");
  if (cadastrados == 9) {
    printf("Limite de cadastro atingido!\n");
    espera();
    menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
    return;
  } else {
    printf("Digite seu CPF (Só pode possuir 11 dígitos): ");
    scanf("%s", cpfcadastro);
    if (strlen(cpfcadastro) != 11) {
      printf("CPF inválido\n");
      limpabuffer();
      espera();
      menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
      return;
    }
    limpabuffer();
    for (int i = 0; i < 10; i++) {
      if ((strcmp(cpfcadastro, pessoas[i].CPF) == 0)) {
        printf("CPF já cadastrado\n");
        espera();
        menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
        return;
      } else if ((strlen(cpfcadastro) != 11) ||
                 (verificaCPF(cpfcadastro) == 0)) {
        printf("CPF inválido!\n");
        espera();
        menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
        return;
      } else if (pessoas[i].CPF[0] == '\0') {
        printf("Digite sua senha (numérica com 6 dígitos): ");
        scanf("%s", senhacadastro);
        if (strlen(senhacadastro) != 6) {
          limpabuffer();
          printf("Senha inválida\n");
          espera();
          menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
          return;
        }
        limpabuffer();
        if (strlen(senhacadastro) == 6) {
          strcpy(pessoas[i].CPF, cpfcadastro);
          strcpy(pessoas[i].senha, senhacadastro);
          while (1) {
            printf("Digite seu nome: ");
            fgets(pessoas[i].nome, 100, stdin);
            size_t len = strlen(pessoas[i].nome);
            if (len > 0 && pessoas[i].nome[len - 1] == '\n') {
              pessoas[i].nome[len - 1] = '\0';
            }

            if (strlen(pessoas[i].nome) < 5) {
              printf(
                  "Nome inválido (DEVE POSSUIR 5 LETRAS), tente novamente!\n");
            } else {
              break;
            }
          }
          cadastrados += 1;
          printf("Cadastro realizado com sucesso!\n");
          espera();
          menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
          return;
        } else {
          printf("Senha inválida. Deve ter 6 dígitos.\n");
          espera();
          menu(pessoas, usuariologado, linhas, colunas); // Chamando o novo menu
          return;
        }
      }
    }
  }
}

void menuinicial(pessoa pessoas[], int usuariologado, int *linhas,
                 int *colunas) {
  limpaterminal();
  char opc;
  while (1) {
    printf(" |---------------[Menu Inicial]---------------| \n");
    printf(" | [1] Cadastro                               | \n");
    printf(" | [2] Login                                  | \n");
    printf(" | [3] Sair                                   | \n");
    printf(" |--------------------------------------------| \n");
    printf(" Digite a opção: ");
    scanf(" %c", &opc);
    getchar();

    switch (opc) {
    case '1':
      cadastrar(pessoas, usuariologado, linhas, colunas);
      return;
    case '2':
      login(pessoas, usuariologado, linhas, colunas);
      return;
    case '3':
      escrever(pessoas, 10);
      exit(0);
      return;
    default:
      printf(" Opção inválida, tente novamente\n");
      break;
    }
  }
}

void limpaterminal() {
  system("cls || clear")
      /*printf("teste")*/;
}

// Função que espera a ação do usuário para dar prosseguimento
void espera() {
  printf("Aperte ENTER para SAIR!\n");
  limpabuffer();
}

void limpabuffer() {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  return;
}

int verificaCPF(char *cpf) {
  int numeros_cpf[11];
  int soma = 0;
  int maxv1 = 10;
  int maxv2 = 11;
  int resto = 0;
  int veri = 0;
  int verificador1 = 0, verificador2 = 0;
  for (int i = 0; i < 11; i++) {
    numeros_cpf[i] = cpf[i] - 48;
  }
  for (int i = 0; i < 11; i++) {
    // implementação da verificação de cpfs com todos os digitos iguais
    if (numeros_cpf[i] == numeros_cpf[0]) {
      veri += 1;
    }
  }
  if (veri == 11) {
    printf("CPF Inválido");
  } else {

    for (int i = 0; i < 9; i++) {
      soma += numeros_cpf[i] * maxv1;
      maxv1--;
    }

    resto = soma % 11;

    if (resto == 1 || resto == 0) {
      verificador1 = 0;
    } else {
      verificador1 = 11 - resto;
    }
    soma = 0;

    for (int i = 0; i < 10; i++) {
      soma += numeros_cpf[i] * maxv2;
      maxv2--;
    }

    resto = soma % 11;
    if (resto == 1 || resto == 0) {
      verificador2 = 0;
    } else {
      verificador2 = 11 - resto;
    }

    if (verificador1 == numeros_cpf[9] && verificador2 == numeros_cpf[10]) {
      return 1;
    } else {
      return 0;
    }
  }
}

Fracao **criarMatriz(int *linhas, int *colunas) { // Função de criar matrizes
  printf("Digite o número de linhas: ");
  scanf("%d", linhas);
  printf("Digite o número de colunas: ");
  scanf("%d", colunas);
  // Pego as linhas e as colunas por endereço e salvo nas variáveis, assim
  // podemos usar elas em outras funções,como se fosse uma variável global, mas
  // não sendo porque usamos ponteiros, slk a cabeça do pae abriu nessa ta

  // Alocação dinâmica da matriz
  Fracao **matriz = (Fracao **)malloc(*linhas * sizeof(Fracao *));
  for (int i = 0; i < *linhas; i++) {
    matriz[i] = (Fracao *)malloc(*colunas * sizeof(Fracao));
  }

  // Leitura dos elementos da matriz
  for (int i = 0; i < *linhas; i++) {
    for (int j = 0; j < *colunas; j++) {
      printf("Digite o número da posição %d x %d: \n", i + 1, j + 1);
      matriz[i][j] = lerFracao();
    }
  }
  return matriz;
}
void limparMatriz(Fracao **matriz, int linhas) {
  // Liberação da memória alocada para a matriz
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

void criaTXTHISTORICO(FILE *file, int usuariologado, pessoa pessoas[]) {
  char nomeregistro[100];
  sprintf(nomeregistro, "historico_%s.txt", pessoas[usuariologado].CPF);
  strcpy(pessoas[usuariologado].nome_hist, nomeregistro);
  file = fopen(nomeregistro, "a");
  if (file) {
    printf("Arquivo criado com sucesso!\n");
  } else {
    printf("Erro ao criar o arquivo!\n");
  }
  fclose(file);
}

void escrevehistorico(int usuariologado, pessoa pessoas[]) {
  int **matriz[2][2];
  int **matriz1[2][2];
  FILE *file = pessoas[usuariologado].historico;
  file = fopen(pessoas[usuariologado].nome_hist, "a");
  fprintf(file, "\n::: VALORES DIGITADOS :::\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &matriz[i][j]);
      fprintf(file, "%d\t", matriz[i][j]);
    }
    fprintf(file, "\t\t\t");
    for (int j = 0; j < 2; j++) {
      scanf("%d", &matriz1[i][j]);
      fprintf(file, "%d\t", matriz1[i][j]);
    }
    fprintf(file, "\n");
  }
  fclose(file);
}

void lerhistorico(int usuariologado, pessoa pessoas[]) {
  char linha[300];
  FILE *file = pessoas[usuariologado].historico;
  file = fopen(pessoas[usuariologado].nome_hist, "r");
  while (fgets(linha, sizeof(linha), file)) {
    printf("%s", linha);
    printf("\n");
  }
  fclose(file);
}
