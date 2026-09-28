/*
 * UNIPÊ - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO
 * PROFESSOR: HERRIOTR
 * PROJETO DA AVALIAÇÃO 01
 *
 * INTEGRANTES DO GRUPO:
 * 1. Pedro
 * 2. Paulo
 * 3. João
 * 4. Gabriel
 * 5. Lucas
 *
 * Arquivo único: contém as 5 funções pedidas, a função do ATENÇÃO 01
 * (criação de matriz dinâmica com valores aleatórios), a exibição dos
 * arranjos (ATENÇÃO 02) e o menu principal.
 *
 * Linguagem: C99, com VLA nos parâmetros das funções (ATENÇÃO 03).
 * Compilação: gcc -std=c99 main.c -o programa
 */

#define __USE_MINGW_ANSI_STDIO 1  /* habilita %lld / %llu no MinGW (Dev-C++) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* =========================================================================
 * LEITURA E PREENCHIMENTO
 * ========================================================================= */

int ler_inteiro(const char *rotulo, int min, int max) {
    int valor, c;
    for (;;) {
        printf("%s: ", rotulo);
        if (scanf("%d", &valor) == 1 && valor >= min && valor <= max) {
            return valor;
        }
        while ((c = getchar()) != '\n' && c != EOF) { }
        if (c == EOF) exit(1);
        printf("Valor inválido. Digite um inteiro entre %d e %d.\n", min, max);
    }
}

int escolher_modo_preenchimento(void) {
    printf("\nComo deseja preencher o arranjo?\n");
    printf("1 - Manual\n");
    printf("2 - Valores aleatórios\n");
    return ler_inteiro("Escolha uma opção", 1, 2) == 1;
}

int aleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

void preencher_vetor(int n, int V[n], int manual, int min, int max) {
    char rotulo[32];
    for (int i = 0; i < n; i++) {
        if (manual) {
            sprintf(rotulo, "[%d]", i);
            V[i] = ler_inteiro(rotulo, min, max);
        } else {
            V[i] = aleatorio(min, max);
        }
    }
}

void preencher_matriz(int n, int M[n][n], int min, int max) {
    char rotulo[32];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sprintf(rotulo, "[%d][%d]", i, j);
            M[i][j] = ler_inteiro(rotulo, min, max);
        }
    }
}

void preencher_matriz_3d(int n, int M[n][n][n], int manual, int min, int max) {
    char rotulo[48];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (manual) {
                    sprintf(rotulo, "[%d][%d][%d]", i, j, k);
                    M[i][j][k] = ler_inteiro(rotulo, min, max);
                } else {
                    M[i][j][k] = aleatorio(min, max);
                }
            }
        }
    }
}

int comparar_inteiros(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

/* =========================================================================
 * ATENÇÃO 01: pergunta quantas linhas e colunas o arranjo deve ter,
 * cria a matriz dinamicamente e preenche com valores aleatórios entre
 * min e max. Retorna a matriz, que deve ser usada como int (*M)[colunas].
 * ========================================================================= */

void *criar_matriz_aleatoria(int *linhas, int *colunas, int min, int max) {
    int l = ler_inteiro("Quantas linhas o arranjo deve ter", 1, 100000);
    int c = ler_inteiro("Quantas colunas o arranjo deve ter", 1, 100000);
    int (*M)[c] = malloc(sizeof(int[l][c]));

    *linhas = l;
    *colunas = c;
    if (!M) return NULL;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            M[i][j] = aleatorio(min, max);
        }
    }
    return M;
}

/* =========================================================================
 * ATENÇÃO 02: exibição completa dos arranjos para conferência
 * ========================================================================= */

void imprimir_vetor(const char *nome, int n, int V[n]) {
    printf("\n--- Vetor %s (%d elementos) ---\n[ ", nome, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("]\n");
}

void imprimir_matriz(const char *nome, int linhas, int colunas, int M[linhas][colunas]) {
    printf("\n--- Matriz %s (%d x %d) ---\n", nome, linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%5d ", M[i][j]);
        }
        printf("\n");
    }
}

void imprimir_matriz_3d(const char *nome, int n, int M[n][n][n]) {
    printf("\n--- Arranjo 3D %s (%d x %d x %d) ---\n", nome, n, n, n);
    for (int i = 0; i < n; i++) {
        printf("%s[%d]:\n", nome, i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%5d ", M[i][j][k]);
            }
            printf("\n");
        }
    }
}

/* =========================================================================
 * FUNÇÃO 1: Contagem de ocorrências distintas
 * Para cada um dos k elementos de K_vec, conta quantas vezes ele aparece
 * no vetor V (tamanho n) e devolve a soma dessas contagens.
 * ========================================================================= */

long long funcao1_contagem_ocorrencias(int n, int V[n], int k, int K_vec[k]) {
    long long soma_total = 0;
    for (int i = 0; i < k; i++) {
        int contador = 0;
        for (int j = 0; j < n; j++) {
            if (V[j] == K_vec[i]) {
                contador++;
            }
        }
        soma_total += contador;
    }
    return soma_total;
}

/* =========================================================================
 * FUNÇÃO 2: Análise de pares em matriz triangular
 * Compara cada A[i][j] da metade superior (diagonal inclusa) com o oposto
 * A[j][i] e conta quantas vezes A[i][j] + A[j][i] é múltiplo de 5.
 * ========================================================================= */

long long funcao2_analise_triangular(int n, int A[n][n]) {
    long long contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int soma = A[i][j] + A[j][i];
            if (soma % 5 == 0) {
                contador++;
            }
        }
    }
    return contador;
}

/* =========================================================================
 * FUNÇÃO 3: Comparação de matrizes tridimensionais
 * Soma todos os elementos de A, depois todos os de B, e retorna 1 se
 * soma(A) >= soma(B) ou 0 caso contrário.
 * ========================================================================= */

int funcao3_comparacao_3d(int n, int A[n][n][n], int B[n][n][n]) {
    long long somaA = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                somaA += A[i][j][k];
            }
        }
    }

    long long somaB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                somaB += B[i][j][k];
            }
        }
    }

    if (somaA >= somaB) return 1;
    return 0;
}

/* =========================================================================
 * FUNÇÃO 4: Análise de casos assimétricos no condicional
 * Para cada V[i]: se for par, soma o próprio valor; se for ímpar, soma
 * o fatorial dele. Valores aceitos: 0 a 20 (20! é o maior fatorial que
 * cabe em 64 bits), validados na leitura.
 * ========================================================================= */

unsigned long long processar_vetor(int n, int V[n]) {
    unsigned long long somatorio = 0;
    for (int i = 0; i < n; i++) {
        if (V[i] % 2 == 0) {
            somatorio += V[i];
        } else {
            unsigned long long fat = 1;
            for (int j = 1; j <= V[i]; j++) {
                fat *= j;
            }
            somatorio += fat;
        }
    }
    return somatorio;
}

/* =========================================================================
 * FUNÇÃO 5: Contagem de elementos presentes em vetor ordenado
 * Para cada elemento de A faz uma busca binária em B e conta os encontrados.
 * ========================================================================= */

int busca_binaria(int n, int B[n], int chave) {
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (B[meio] == chave) {
            return 1;
        } else if (B[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return 0;
}

long long funcao5_elementos_ordenados(int n, int A[n], int B[n]) {
    long long total_encontrados = 0;
    for (int i = 0; i < n; i++) {
        if (busca_binaria(n, B, A[i])) {
            total_encontrados++;
        }
    }
    return total_encontrados;
}

/* =========================================================================
 * OPÇÕES DO MENU
 * ========================================================================= */

void executar_opcao1(void) {
    printf("\n=== FUNÇÃO 1: Contagem de ocorrências distintas ===\n");
    int n = ler_inteiro("Tamanho n do vetor principal", 1, 100000000);
    int k = ler_inteiro("Tamanho k do vetor de busca", 1, 100000000);
    int manual = escolher_modo_preenchimento();

    int *V = malloc(sizeof(int[n]));
    int *K_vec = malloc(sizeof(int[k]));
    if (!V || !K_vec) {
        printf("Erro de alocação de memória!\n");
        free(V); free(K_vec);
        return;
    }

    printf("\nVetor V:\n");
    preencher_vetor(n, V, manual, 1, 20);
    printf("Vetor K_vec:\n");
    preencher_vetor(k, K_vec, manual, 1, 20);
    imprimir_vetor("V", n, V);
    imprimir_vetor("K_vec", k, K_vec);

    printf("\n>>> Resultado da Função 1: soma das ocorrências = %lld\n",
           funcao1_contagem_ocorrencias(n, V, k, K_vec));
    free(V); free(K_vec);
}

void executar_opcao2(void) {
    int n, linhas, colunas;
    void *mem;

    printf("\n=== FUNÇÃO 2: Análise de pares em matriz triangular ===\n");
    if (escolher_modo_preenchimento()) {
        n = ler_inteiro("Dimensão n da matriz (n x n)", 1, 100000);
        mem = malloc(sizeof(int[n][n]));
        if (mem) preencher_matriz(n, mem, 0, 9);
    } else {
        /* ATENÇÃO 01: a matriz é criada pela função de matriz aleatória */
        for (;;) {
            mem = criar_matriz_aleatoria(&linhas, &colunas, 0, 9);
            if (linhas == colunas) break;
            printf("A Função 2 precisa de uma matriz quadrada (linhas = colunas).\n");
            free(mem);
        }
        n = linhas;
    }
    if (!mem) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    int (*A)[n] = mem;
    imprimir_matriz("A", n, n, A);

    printf("\n>>> Resultado da Função 2: pares com soma múltipla de 5 = %lld\n",
           funcao2_analise_triangular(n, A));
    free(A);
}

void executar_opcao3(void) {
    printf("\n=== FUNÇÃO 3: Comparação de matrizes tridimensionais ===\n");
    int n = ler_inteiro("Dimensão n dos arranjos (n x n x n)", 1, 1000);
    int manual = escolher_modo_preenchimento();

    int (*A)[n][n] = malloc(sizeof(int[n][n][n]));
    int (*B)[n][n] = malloc(sizeof(int[n][n][n]));
    if (!A || !B) {
        printf("Erro de alocação de memória!\n");
        free(A); free(B);
        return;
    }

    printf("\nArranjo A:\n");
    preencher_matriz_3d(n, A, manual, 0, 9);
    printf("Arranjo B:\n");
    preencher_matriz_3d(n, B, manual, 0, 9);
    imprimir_matriz_3d("A", n, A);
    imprimir_matriz_3d("B", n, B);

    printf("\n>>> Resultado da Função 3: %d (1 = soma(A) >= soma(B), 0 = caso contrário)\n",
           funcao3_comparacao_3d(n, A, B));
    free(A); free(B);
}

void executar_opcao4(void) {
    printf("\n=== FUNÇÃO 4: Análise de casos assimétricos no condicional ===\n");
    int n = ler_inteiro("Tamanho n do vetor", 1, 100000000);
    int manual = escolher_modo_preenchimento();

    int *V = malloc(sizeof(int[n]));
    if (!V) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    if (manual) printf("Digite valores entre 0 e 20.\n");
    preencher_vetor(n, V, manual, 0, 20);
    imprimir_vetor("V", n, V);

    printf("\n>>> Resultado da Função 4: somatório = %llu\n", processar_vetor(n, V));
    free(V);
}

void executar_opcao5(void) {
    printf("\n=== FUNÇÃO 5: Contagem de elementos presentes em vetor ordenado ===\n");
    int n = ler_inteiro("Tamanho n dos vetores A e B", 1, 100000000);
    int manual = escolher_modo_preenchimento();

    int *A = malloc(sizeof(int[n]));
    int *B = malloc(sizeof(int[n]));
    if (!A || !B) {
        printf("Erro de alocação de memória!\n");
        free(A); free(B);
        return;
    }

    printf("\nVetor A:\n");
    preencher_vetor(n, A, manual, 1, 50);
    printf("Vetor B (será ordenado em seguida):\n");
    preencher_vetor(n, B, manual, 1, 50);
    qsort(B, n, sizeof(int), comparar_inteiros);
    imprimir_vetor("A", n, A);
    imprimir_vetor("B (ordenado)", n, B);

    printf("\n>>> Resultado da Função 5: elementos de A encontrados em B = %lld\n",
           funcao5_elementos_ordenados(n, A, B));
    free(A); free(B);
}

void executar_opcao_atencao01(void) {
    int linhas, colunas;
    printf("\n=== ATENÇÃO 01: Matriz dinâmica com valores aleatórios ===\n");
    void *mem = criar_matriz_aleatoria(&linhas, &colunas, 0, 99);
    if (!mem) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    int (*M)[colunas] = mem;
    imprimir_matriz("gerada", linhas, colunas, M);
    free(M);
}

/* =========================================================================
 * BENCHMARK: pior caso de cada função com os valores de n do enunciado.
 * Os arranjos não são impressos aqui (milhões de elementos); a conferência
 * da impressão é feita pelas opções 1 a 5.
 * ========================================================================= */

double cronometrar(clock_t inicio) {
    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}

void executar_benchmark(void) {
    printf("\n==================================================================\n");
    printf("  BENCHMARK: PIOR CASO COM OS VALORES DE n DO ENUNCIADO\n");
    printf("==================================================================\n");

    /* Função 1, pior caso: todos os elementos iguais, o if é sempre verdadeiro */
    {
        int n = 50000, k = 4000;
        printf("\n[1/5] Função 1 (n = 50.000, k = 4.000)... ");
        fflush(stdout);
        int *V = malloc(sizeof(int[n]));
        int *K_vec = malloc(sizeof(int[k]));
        if (V && K_vec) {
            for (int i = 0; i < n; i++) V[i] = 7;
            for (int i = 0; i < k; i++) K_vec[i] = 7;
            clock_t inicio = clock();
            long long res = funcao1_contagem_ocorrencias(n, V, k, K_vec);
            printf("resultado = %lld | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        free(V); free(K_vec);
    }

    /* Função 2, pior caso: toda soma é múltipla de 5 */
    {
        int n = 500;
        printf("\n[2/5] Função 2 (n = 500)... ");
        fflush(stdout);
        int (*A)[n] = malloc(sizeof(int[n][n]));
        if (A) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    A[i][j] = 5;
            clock_t inicio = clock();
            long long res = funcao2_analise_triangular(n, A);
            printf("resultado = %lld | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        free(A);
    }

    /* Função 3: o custo não depende dos valores (sempre percorre tudo) */
    {
        int n = 300;
        printf("\n[3/5] Função 3 (n = 300, ~216 MB de RAM)... ");
        fflush(stdout);
        int (*A)[n][n] = malloc(sizeof(int[n][n][n]));
        int (*B)[n][n] = malloc(sizeof(int[n][n][n]));
        if (A && B) {
            preencher_matriz_3d(n, A, 0, 0, 99);
            preencher_matriz_3d(n, B, 0, 0, 99);
            clock_t inicio = clock();
            int res = funcao3_comparacao_3d(n, A, B);
            printf("resultado = %d | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        free(A); free(B);
    }

    /* Função 4, pior caso: todos os valores são 19, o maior ímpar aceito */
    {
        int n = 50000;
        printf("\n[4/5] Função 4 (n = 50.000, todos os valores = 19)... ");
        fflush(stdout);
        int *V = malloc(sizeof(int[n]));
        if (V) {
            for (int i = 0; i < n; i++) V[i] = 19;
            clock_t inicio = clock();
            unsigned long long res = processar_vetor(n, V);
            printf("resultado = %llu | tempo = %.4f s\n", res, cronometrar(inicio));
            printf("      (50.000 x 19! passa de 64 bits; o valor exibido é o resto módulo 2^64)\n");
        } else {
            printf("falha de alocação\n");
        }
        free(V);
    }

    /* Função 5, pior caso: nenhum elemento de A está em B (A ímpar, B par) */
    {
        int n = 10000000;
        printf("\n[5/5] Função 5 (n = 10.000.000, ~80 MB de RAM)... ");
        fflush(stdout);
        int *A = malloc(sizeof(int[n]));
        int *B = malloc(sizeof(int[n]));
        if (A && B) {
            for (int i = 0; i < n; i++) {
                B[i] = 2 * i;
                A[i] = 2 * (rand() % n) + 1;
            }
            clock_t inicio = clock();
            long long res = funcao5_elementos_ordenados(n, A, B);
            printf("resultado = %lld | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        free(A); free(B);
    }

    printf("\n==================================================================\n");
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);  /* acentos corretos no console do Windows */
#endif
    srand((unsigned int)time(NULL));

    int opcao = -1;
    while (opcao != 0) {
        printf("\n==================================================================\n");
        printf(" UNIPÊ - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO\n");
        printf(" PROFESSOR: HERRIOTR | AVALIAÇÃO 01\n");
        printf(" INTEGRANTES: Pedro, Paulo, João, Gabriel, Lucas\n");
        printf("==================================================================\n");
        printf(" 1. Função 1: Contagem de ocorrências distintas\n");
        printf(" 2. Função 2: Análise de pares em matriz triangular\n");
        printf(" 3. Função 3: Comparação de matrizes tridimensionais\n");
        printf(" 4. Função 4: Análise de casos assimétricos no condicional\n");
        printf(" 5. Função 5: Contagem de elementos presentes em vetor ordenado\n");
        printf(" 6. Benchmark do pior caso com os valores de n do enunciado\n");
        printf(" 7. ATENÇÃO 01: criar matriz dinâmica com valores aleatórios\n");
        printf(" 0. Sair\n");
        printf("==================================================================\n");

        opcao = ler_inteiro("Escolha uma opção", 0, 7);
        switch (opcao) {
            case 1: executar_opcao1(); break;
            case 2: executar_opcao2(); break;
            case 3: executar_opcao3(); break;
            case 4: executar_opcao4(); break;
            case 5: executar_opcao5(); break;
            case 6: executar_benchmark(); break;
            case 7: executar_opcao_atencao01(); break;
            case 0: printf("\nSaindo do programa.\n"); break;
        }
    }
    return 0;
}
