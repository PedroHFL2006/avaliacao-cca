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
 * Compila em qualquer padrão do GCC (inclusive o gnu90 do Dev-C++ antigo):
 *     gcc main.c -o programa
 */

#define __USE_MINGW_ANSI_STDIO 1  /* habilita %lld / %llu no MinGW (Dev-C++) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* =========================================================================
 * ALOCAÇÃO DINÂMICA DE ARRANJOS
 * ========================================================================= */

int *criar_vetor(int n) {
    return (int *)malloc(n * sizeof(int));
}

int **criar_matriz(int linhas, int colunas) {
    int i;
    int **M = (int **)malloc(linhas * sizeof(int *));
    int *dados = (int *)malloc(linhas * colunas * sizeof(int));
    if (!M || !dados) {
        free(M); free(dados);
        return NULL;
    }
    for (i = 0; i < linhas; i++) {
        M[i] = dados + i * colunas;
    }
    return M;
}

void liberar_matriz(int **M) {
    if (M) {
        free(M[0]);
        free(M);
    }
}

int ***criar_matriz_3d(int n) {
    int i, j;
    int ***M = (int ***)malloc(n * sizeof(int **));
    int **linhas = (int **)malloc(n * n * sizeof(int *));
    int *dados = (int *)malloc((size_t)n * n * n * sizeof(int));
    if (!M || !linhas || !dados) {
        free(M); free(linhas); free(dados);
        return NULL;
    }
    for (i = 0; i < n; i++) {
        M[i] = linhas + i * n;
        for (j = 0; j < n; j++) {
            M[i][j] = dados + ((size_t)i * n + j) * n;
        }
    }
    return M;
}

void liberar_matriz_3d(int ***M) {
    if (M) {
        free(M[0][0]);
        free(M[0]);
        free(M);
    }
}

/* =========================================================================
 * ATENÇÃO 01: pergunta quantas linhas e colunas o arranjo deve ter,
 * cria a matriz dinamicamente e preenche com valores aleatórios.
 * ========================================================================= */

int **criar_matriz_aleatoria(int *linhas, int *colunas) {
    int i, j;
    int **M;

    printf("Quantas linhas a matriz deve ter? ");
    if (scanf("%d", linhas) != 1 || *linhas <= 0) *linhas = 3;
    printf("Quantas colunas a matriz deve ter? ");
    if (scanf("%d", colunas) != 1 || *colunas <= 0) *colunas = 3;

    M = criar_matriz(*linhas, *colunas);
    if (!M) return NULL;

    for (i = 0; i < *linhas; i++) {
        for (j = 0; j < *colunas; j++) {
            M[i][j] = rand() % 100;
        }
    }
    return M;
}

/* =========================================================================
 * ATENÇÃO 02: exibição completa dos arranjos para conferência
 * ========================================================================= */

void imprimir_vetor(const char *nome, int n, int *V) {
    int i;
    printf("\n--- Vetor %s (%d elementos) ---\n[ ", nome, n);
    for (i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("]\n");
}

void imprimir_matriz(const char *nome, int linhas, int colunas, int **M) {
    int i, j;
    printf("\n--- Matriz %s (%d x %d) ---\n", nome, linhas, colunas);
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%5d ", M[i][j]);
        }
        printf("\n");
    }
}

void imprimir_matriz_3d(const char *nome, int n, int ***M) {
    int i, j, k;
    printf("\n--- Arranjo 3D %s (%d x %d x %d) ---\n", nome, n, n, n);
    for (i = 0; i < n; i++) {
        printf("%s[%d]:\n", nome, i);
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                printf("%5d ", M[i][j][k]);
            }
            printf("\n");
        }
    }
}

/* =========================================================================
 * PREENCHIMENTO (manual ou aleatório)
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

void preencher_vetor(int n, int *V, int manual, int min, int max) {
    int i;
    char rotulo[32];
    for (i = 0; i < n; i++) {
        if (manual) {
            sprintf(rotulo, "[%d]", i);
            V[i] = ler_inteiro(rotulo, min, max);
        } else {
            V[i] = min + rand() % (max - min + 1);
        }
    }
}

void preencher_matriz(int n, int **M, int manual, int min, int max) {
    int i, j;
    char rotulo[32];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (manual) {
                sprintf(rotulo, "[%d][%d]", i, j);
                M[i][j] = ler_inteiro(rotulo, min, max);
            } else {
                M[i][j] = min + rand() % (max - min + 1);
            }
        }
    }
}

void preencher_matriz_3d(int n, int ***M, int manual, int min, int max) {
    int i, j, k;
    char rotulo[48];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (manual) {
                    sprintf(rotulo, "[%d][%d][%d]", i, j, k);
                    M[i][j][k] = ler_inteiro(rotulo, min, max);
                } else {
                    M[i][j][k] = min + rand() % (max - min + 1);
                }
            }
        }
    }
}

int escolher_modo_preenchimento(void) {
    int opcao = 0;
    printf("\nComo deseja preencher o arranjo?\n");
    printf("1 - Manual\n");
    printf("2 - Valores aleatórios\n");
    printf("Escolha uma opção: ");
    if (scanf("%d", &opcao) != 1) opcao = 2;
    return opcao == 1;
}

int comparar_inteiros(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

/* =========================================================================
 * FUNÇÃO 1: Contagem de ocorrências
 * Para cada um dos k elementos de K_vec, conta quantas vezes ele aparece
 * no vetor V (tamanho n) e devolve a soma dessas contagens.
 * ========================================================================= */

long long funcao1_contagem_ocorrencias(int n, int *V, int k, int *K_vec) {
    int i, j, contador;
    long long soma_total = 0;
    for (i = 0; i < k; i++) {
        contador = 0;
        for (j = 0; j < n; j++) {
            if (V[j] == K_vec[i]) {
                contador++;
            }
        }
        soma_total += contador;
    }
    return soma_total;
}

/* =========================================================================
 * FUNÇÃO 2: Pares em matriz triangular
 * Compara cada A[i][j] da metade superior (diagonal inclusa) com o oposto
 * A[j][i] e conta quantas vezes A[i][j] + A[j][i] é múltiplo de 5.
 * ========================================================================= */

long long funcao2_analise_triangular(int n, int **A) {
    int i, j, soma;
    long long contador = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            soma = A[i][j] + A[j][i];
            if (soma % 5 == 0) {
                contador++;
            }
        }
    }
    return contador;
}

/* =========================================================================
 * FUNÇÃO 3: Comparação de arranjos tridimensionais
 * Soma todos os elementos de A, depois todos os de B, e retorna 1 se
 * soma(A) >= soma(B) ou 0 caso contrário.
 * ========================================================================= */

int funcao3_comparacao_3d(int n, int ***A, int ***B) {
    int i, j, k;
    long long somaA = 0, somaB = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                somaA += A[i][j][k];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                somaB += B[i][j][k];
            }
        }
    }
    if (somaA >= somaB) return 1;
    return 0;
}

/* =========================================================================
 * FUNÇÃO 4: Casos assimétricos no condicional
 * Para cada V[i]: se for par, soma o próprio valor; se for ímpar, soma
 * o fatorial dele. Valores aceitos: 0 a 20 (20! é o maior fatorial que
 * cabe em 64 bits), validados na leitura.
 * ========================================================================= */

unsigned long long funcao4_processar_vetor(int n, int *V) {
    int i, j;
    unsigned long long somatorio = 0, fat;
    for (i = 0; i < n; i++) {
        if (V[i] % 2 == 0) {
            somatorio += V[i];
        } else {
            fat = 1;
            for (j = 1; j <= V[i]; j++) {
                fat *= j;
            }
            somatorio += fat;
        }
    }
    return somatorio;
}

/* =========================================================================
 * FUNÇÃO 5: Elementos de A presentes no vetor ordenado B
 * Para cada elemento de A faz uma busca binária em B e conta os encontrados.
 * ========================================================================= */

int busca_binaria(int n, int *B, int chave) {
    int inicio = 0, fim = n - 1, meio;
    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;
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

long long funcao5_elementos_ordenados(int n, int *A, int *B) {
    int i;
    long long total_encontrados = 0;
    for (i = 0; i < n; i++) {
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
    int n, k, manual;
    int *V, *K_vec;
    printf("\n=== FUNÇÃO 1: Contagem de ocorrências ===\n");
    printf("Tamanho n do vetor principal: ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 10;
    printf("Tamanho k do vetor de busca: ");
    if (scanf("%d", &k) != 1 || k <= 0) k = 3;
    manual = escolher_modo_preenchimento();

    V = criar_vetor(n);
    K_vec = criar_vetor(k);
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
    int n, manual;
    int **A;
    printf("\n=== FUNÇÃO 2: Pares em matriz triangular ===\n");
    printf("Dimensão n da matriz (n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 4;
    manual = escolher_modo_preenchimento();

    A = criar_matriz(n, n);
    if (!A) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    preencher_matriz(n, A, manual, 0, 9);
    imprimir_matriz("A", n, n, A);

    printf("\n>>> Resultado da Função 2: pares com soma múltipla de 5 = %lld\n",
           funcao2_analise_triangular(n, A));
    liberar_matriz(A);
}

void executar_opcao3(void) {
    int n, manual;
    int ***A, ***B;
    printf("\n=== FUNÇÃO 3: Comparação de arranjos 3D ===\n");
    printf("Dimensão n dos arranjos (n x n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 3;
    manual = escolher_modo_preenchimento();

    A = criar_matriz_3d(n);
    B = criar_matriz_3d(n);
    if (!A || !B) {
        printf("Erro de alocação de memória!\n");
        liberar_matriz_3d(A); liberar_matriz_3d(B);
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
    liberar_matriz_3d(A); liberar_matriz_3d(B);
}

void executar_opcao4(void) {
    int n, manual;
    int *V;
    printf("\n=== FUNÇÃO 4: Casos assimétricos no condicional ===\n");
    printf("Tamanho n do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 6;
    manual = escolher_modo_preenchimento();

    V = criar_vetor(n);
    if (!V) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    if (manual) printf("Digite valores entre 0 e 20.\n");
    preencher_vetor(n, V, manual, 0, 20);
    imprimir_vetor("V", n, V);

    printf("\n>>> Resultado da Função 4: somatório = %llu\n",
           funcao4_processar_vetor(n, V));
    free(V);
}

void executar_opcao5(void) {
    int n, manual;
    int *A, *B;
    printf("\n=== FUNÇÃO 5: Elementos presentes em vetor ordenado ===\n");
    printf("Tamanho n dos vetores A e B: ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 10;
    manual = escolher_modo_preenchimento();

    A = criar_vetor(n);
    B = criar_vetor(n);
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
    int **M;
    printf("\n=== ATENÇÃO 01: Matriz dinâmica com valores aleatórios ===\n");
    M = criar_matriz_aleatoria(&linhas, &colunas);
    if (!M) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    imprimir_matriz("gerada", linhas, colunas, M);
    liberar_matriz(M);
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
    int i, j, k, n;
    clock_t inicio;

    printf("\n==================================================================\n");
    printf("  BENCHMARK: PIOR CASO COM OS VALORES DE n DO ENUNCIADO\n");
    printf("==================================================================\n");

    /* Função 1, pior caso: todos os elementos iguais, o if é sempre verdadeiro */
    {
        int *V, *K_vec;
        long long res;
        n = 50000; k = 4000;
        printf("\n[1/5] Função 1 (n = 50.000, k = 4.000)... ");
        fflush(stdout);
        V = criar_vetor(n);
        K_vec = criar_vetor(k);
        if (V && K_vec) {
            for (i = 0; i < n; i++) V[i] = 7;
            for (i = 0; i < k; i++) K_vec[i] = 7;
            inicio = clock();
            res = funcao1_contagem_ocorrencias(n, V, k, K_vec);
            printf("resultado = %lld | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        free(V); free(K_vec);
    }

    /* Função 2, pior caso: toda soma é múltipla de 5 */
    {
        int **A;
        long long res;
        n = 500;
        printf("\n[2/5] Função 2 (n = 500)... ");
        fflush(stdout);
        A = criar_matriz(n, n);
        if (A) {
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    A[i][j] = 5;
            inicio = clock();
            res = funcao2_analise_triangular(n, A);
            printf("resultado = %lld | tempo = %.4f s\n", res, cronometrar(inicio));
            liberar_matriz(A);
        } else {
            printf("falha de alocação\n");
        }
    }

    /* Função 3: o custo não depende dos valores (sempre percorre tudo) */
    {
        int ***A, ***B;
        int res;
        n = 300;
        printf("\n[3/5] Função 3 (n = 300, ~216 MB de RAM)... ");
        fflush(stdout);
        A = criar_matriz_3d(n);
        B = criar_matriz_3d(n);
        if (A && B) {
            preencher_matriz_3d(n, A, 0, 0, 99);
            preencher_matriz_3d(n, B, 0, 0, 99);
            inicio = clock();
            res = funcao3_comparacao_3d(n, A, B);
            printf("resultado = %d | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        liberar_matriz_3d(A); liberar_matriz_3d(B);
    }

    /* Função 4, pior caso: todos os valores são 19, o maior ímpar aceito */
    {
        int *V;
        unsigned long long res;
        n = 50000;
        printf("\n[4/5] Função 4 (n = 50.000, todos os valores = 19)... ");
        fflush(stdout);
        V = criar_vetor(n);
        if (V) {
            for (i = 0; i < n; i++) V[i] = 19;
            inicio = clock();
            res = funcao4_processar_vetor(n, V);
            printf("resultado = %llu | tempo = %.4f s\n", res, cronometrar(inicio));
            printf("      (50.000 x 19! passa de 64 bits; o valor exibido é o resto módulo 2^64)\n");
            free(V);
        } else {
            printf("falha de alocação\n");
        }
    }

    /* Função 5, pior caso: nenhum elemento de A está em B (A ímpar, B par) */
    {
        int *A, *B;
        long long res;
        n = 10000000;
        printf("\n[5/5] Função 5 (n = 10.000.000, ~80 MB de RAM)... ");
        fflush(stdout);
        A = criar_vetor(n);
        B = criar_vetor(n);
        if (A && B) {
            for (i = 0; i < n; i++) {
                B[i] = 2 * i;
                A[i] = 2 * (rand() % n) + 1;
            }
            inicio = clock();
            res = funcao5_elementos_ordenados(n, A, B);
            printf("resultado = %lld | tempo = %.4f s\n", res, cronometrar(inicio));
        } else {
            printf("falha de alocação\n");
        }
        free(A); free(B);
    }

    printf("\n==================================================================\n");
}

int main(void) {
    int opcao = -1;

#ifdef _WIN32
    SetConsoleOutputCP(65001);  /* acentos corretos no console do Windows */
#endif
    srand((unsigned int)time(NULL));

    while (opcao != 0) {
        printf("\n==================================================================\n");
        printf(" UNIPÊ - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO\n");
        printf(" PROFESSOR: HERRIOTR | AVALIAÇÃO 01\n");
        printf(" INTEGRANTES: Pedro, Paulo, João, Gabriel, Lucas\n");
        printf("==================================================================\n");
        printf(" 1. Função 1: Contagem de ocorrências\n");
        printf(" 2. Função 2: Pares em matriz triangular\n");
        printf(" 3. Função 3: Comparação de arranjos 3D\n");
        printf(" 4. Função 4: Casos assimétricos no condicional\n");
        printf(" 5. Função 5: Elementos presentes em vetor ordenado\n");
        printf(" 6. Benchmark do pior caso com os valores de n do enunciado\n");
        printf(" 7. ATENÇÃO 01: criar matriz dinâmica com valores aleatórios\n");
        printf(" 0. Sair\n");
        printf("==================================================================\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            if (c == EOF) break;
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1: executar_opcao1(); break;
            case 2: executar_opcao2(); break;
            case 3: executar_opcao3(); break;
            case 4: executar_opcao4(); break;
            case 5: executar_opcao5(); break;
            case 6: executar_benchmark(); break;
            case 7: executar_opcao_atencao01(); break;
            case 0: printf("\nSaindo do programa.\n"); break;
            default: printf("\nOpção inválida!\n"); break;
        }
    }
    return 0;
}
