/*
 * UNIPÊ - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO
 * PROFESSOR: HERRIOTR
 * PROJETO DA AVALIAÇÃO 01
 *
 * INTEGRANTES DO GRUPO (5 Membros):
 * 1. Pedro
 * 2. Paulo
 * 3. João
 * 4. Gabriel
 * 5. Lucas
 *
 * Linguagem: C (Padrão C99)
 * Estrutura de Arquivos: A pasta 'funcoes/' contém exatamente os 5 arquivos .c das funções do PDF.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inclusão direta das 5 funções isoladas da pasta 'funcoes/'
#include "funcoes/funcao1.c"
#include "funcoes/funcao2.c"
#include "funcoes/funcao3.c"
#include "funcoes/funcao4.c"
#include "funcoes/funcao5.c"

/* =========================================================================
 * AUXILIARES DE INTERFACE E EXIBIÇÃO DA AVALIAÇÃO (ITEM 01 E 02 DA ATENÇÃO)
 * ========================================================================= */

void imprimir_vetor(const char* nome, int n, int V[n]) {
    printf("\n--- Exibição do Vetor '%s' (Tamanho: %d) ---\n", nome, n);
    if (n <= 50) {
        printf("[ ");
        for (int i = 0; i < n; i++) {
            printf("%d ", V[i]);
        }
        printf("]\n");
    } else {
        printf("[ ");
        for (int i = 0; i < 5; i++) printf("%d ", V[i]);
        printf("... ");
        for (int i = n - 5; i < n; i++) printf("%d ", V[i]);
        printf("] (exibindo apenas os 5 primeiros e 5 últimos de %d elementos)\n", n);
    }
}

void imprimir_matriz_2d(const char* nome, int n, int M[n][n]) {
    printf("\n--- Exibição da Matriz 2D '%s' (%dx%d) ---\n", nome, n, n);
    if (n <= 10) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%4d ", M[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("(Matriz possui %dx%d elementos. Exibindo submatriz 5x5 superior esquerda):\n", n, n);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%4d ", M[i][j]);
            }
            printf("...\n");
        }
        printf("...\n");
    }
}

void imprimir_matriz_3d(const char* nome, int n, int M[n][n][n]) {
    printf("\n--- Exibição da Matriz 3D '%s' (%dx%dx%d) ---\n", nome, n, n, n);
    if (n <= 3) {
        for (int i = 0; i < n; i++) {
            printf("Fatia z = %d:\n", i);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    printf("%4d ", M[i][j][k]);
                }
                printf("\n");
            }
        }
    } else {
        printf("(Matriz 3D possui %d^3 = %d elementos. Exibição omitida para evitar poluição visual)\n", n, n * n * n);
    }
}

void preencher_vetor(int n, int V[n], int modo_manual, int limite_rand) {
    if (modo_manual) {
        printf("Digite os %d elementos do vetor:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Vetor[%d]: ", i);
            if (scanf("%d", &V[i]) != 1) V[i] = 0;
        }
    } else {
        for (int i = 0; i < n; i++) {
            V[i] = (rand() % limite_rand) + 1;
        }
    }
}

void preencher_matriz_2d(int n, int M[n][n], int modo_manual, int limite_rand) {
    if (modo_manual) {
        printf("Digite os elementos da matriz %dx%d:\n", n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("M[%d][%d]: ", i, j);
                if (scanf("%d", &M[i][j]) != 1) M[i][j] = 0;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] = (rand() % limite_rand) + 1;
            }
        }
    }
}

void preencher_matriz_3d(int n, int M[n][n][n], int modo_manual, int limite_rand) {
    if (modo_manual) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    printf("M3D[%d][%d][%d]: ", i, j, k);
                    if (scanf("%d", &M[i][j][k]) != 1) M[i][j][k] = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    M[i][j][k] = (rand() % limite_rand) + 1;
                }
            }
        }
    }
}

int comparar_inteiros(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int escolher_modo_preenchimento(void) {
    int opcao = 0;
    printf("\nComo deseja preencher o arranjo?\n");
    printf("1 - Preenchimento Manual\n");
    printf("2 - Preenchimento Automático (Valores Randômicos)\n");
    printf("Escolha uma opção: ");
    if (scanf("%d", &opcao) != 1) opcao = 2;
    return (opcao == 1) ? 1 : 0;
}

/* =========================================================================
 * MENUS DAS 5 FUNÇÕES SOLICITADAS
 * ========================================================================= */

void executar_opcao1(void) {
    int n, k;
    printf("\n=== FUNÇÃO 1: Contagem de Ocorrências Distintas (funcao1.c) ===\n");
    printf("Digite o tamanho 'n' do vetor principal: ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 10;
    printf("Digite o tamanho 'k' do vetor de busca: ");
    if (scanf("%d", &k) != 1 || k <= 0) k = 3;

    int manual = escolher_modo_preenchimento();

    int* V = (int*)malloc(n * sizeof(int));
    int* K_vec = (int*)malloc(k * sizeof(int));

    if (!V || !K_vec) {
        printf("Erro de alocação de memória!\n");
        free(V); free(K_vec);
        return;
    }

    printf("\nPreenchendo Vetor Principal V (n = %d)...\n", n);
    preencher_vetor(n, V, manual, 20);
    printf("Preenchendo Vetor de Busca K_vec (k = %d)...\n", k);
    preencher_vetor(k, K_vec, manual, 20);

    imprimir_vetor("V (Principal)", n, V);
    imprimir_vetor("K_vec (Busca)", k, K_vec);

    long long resultado = funcao1_contagem_ocorrencias(n, V, k, K_vec);
    printf("\n>>> RESULTADO DA FUNÇÃO 1: Soma total de ocorrências = %lld <<<\n", resultado);

    free(V); free(K_vec);
}

void executar_opcao2(void) {
    int n;
    printf("\n=== FUNÇÃO 2: Análise de Pares em Matriz Triangular (funcao2.c) ===\n");
    printf("Digite a dimensão 'n' da matriz quadrada (n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 4;

    int manual = escolher_modo_preenchimento();

    int (*A)[n] = malloc(sizeof(int[n][n]));
    if (!A) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    preencher_matriz_2d(n, A, manual, 10);
    imprimir_matriz_2d("Matriz A", n, A);

    long long resultado = funcao2_analise_triangular(n, A);
    printf("\n>>> RESULTADO DA FUNÇÃO 2: Pares com soma múltipla de 5 = %lld <<<\n", resultado);

    free(A);
}

void executar_opcao3(void) {
    int n;
    printf("\n=== FUNÇÃO 3: Comparação de Matrizes Tridimensionais (funcao3.c) ===\n");
    printf("Digite a dimensão 'n' das matrizes 3D (n x n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 3;

    int manual = escolher_modo_preenchimento();

    int (*A)[n][n] = malloc(sizeof(int[n][n][n]));
    int (*B)[n][n] = malloc(sizeof(int[n][n][n]));

    if (!A || !B) {
        printf("Erro de alocação de memória!\n");
        free(A); free(B);
        return;
    }

    printf("\nPreenchendo Matriz 3D 'A'...\n");
    preencher_matriz_3d(n, A, manual, 10);
    printf("Preenchendo Matriz 3D 'B'...\n");
    preencher_matriz_3d(n, B, manual, 10);

    imprimir_matriz_3d("A", n, A);
    imprimir_matriz_3d("B", n, B);

    int resultado = funcao3_comparacao_3d(n, A, B);
    printf("\n>>> RESULTADO DA FUNÇÃO 3: %d (Soma(A) >= Soma(B)? 1=Sim, 0=Não) <<<\n", resultado);

    free(A); free(B);
}

void executar_opcao4(void) {
    int n;
    printf("\n=== FUNÇÃO 4: Análise de Casos Assimétricos no Condicional (funcao4.c) ===\n");
    printf("Digite o tamanho 'n' do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 6;

    int manual = escolher_modo_preenchimento();

    int* V = (int*)malloc(n * sizeof(int));
    if (!V) {
        printf("Erro de alocação!\n");
        return;
    }

    preencher_vetor(n, V, manual, 10);
    imprimir_vetor("Vetor V", n, V);

    unsigned long long resultado = funcao4_processar_vetor(n, V);
    printf("\n>>> RESULTADO DA FUNÇÃO 4: Somatório = %llu <<<\n", resultado);

    free(V);
}

void executar_opcao5(void) {
    int n;
    printf("\n=== FUNÇÃO 5: Contagem de Elementos Presentes em Vetor Ordenado (funcao5.c) ===\n");
    printf("Digite o tamanho 'n' dos vetores A e B: ");
    if (scanf("%d", &n) != 1 || n <= 0) n = 10;

    int manual = escolher_modo_preenchimento();

    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(n * sizeof(int));

    if (!A || !B) {
        printf("Erro de alocação!\n");
        free(A); free(B);
        return;
    }

    printf("\nPreenchendo Vetor A (Não Ordenado)...\n");
    preencher_vetor(n, A, manual, 50);

    printf("Preenchendo Vetor B...\n");
    preencher_vetor(n, B, manual, 50);

    qsort(B, n, sizeof(int), comparar_inteiros);

    imprimir_vetor("Vetor A (Desordenado)", n, A);
    imprimir_vetor("Vetor B (Ordenado)", n, B);

    long long resultado = funcao5_elementos_ordenados(n, A, B);
    printf("\n>>> RESULTADO DA FUNÇÃO 5: Total de elementos de A encontrados em B = %lld <<<\n", resultado);

    free(A); free(B);
}

void executar_benchmark_enunciado(void) {
    printf("\n==================================================================\n");
    printf("  BENCHMARK E MEDIÇÃO DE TEMPO COM OS VALORES DO ENUNCIADO\n");
    printf("==================================================================\n");

    // 1. Função 1: n = 50.000, k = 4.000
    {
        int n = 50000, k = 4000;
        printf("\n[1/5] Testando Função 1 (n = 50.000, k = 4.000)... ");
        fflush(stdout);
        int* V = (int*)malloc(n * sizeof(int));
        int* K_vec = (int*)malloc(k * sizeof(int));
        if (V && K_vec) {
            preencher_vetor(n, V, 0, 1000);
            preencher_vetor(k, K_vec, 0, 1000);

            clock_t inicio = clock();
            long long res = funcao1_contagem_ocorrencias(n, V, k, K_vec);
            clock_t fim = clock();
            double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("CONCLUÍDO!\n    -> Resultado: %lld | Tempo real medido: %.4f s\n", res, tempo);
        }
        free(V); free(K_vec);
    }

    // 2. Função 2: n = 500
    {
        int n = 500;
        printf("\n[2/5] Testando Função 2 (n = 500)... ");
        fflush(stdout);
        int (*A)[n] = malloc(sizeof(int[n][n]));
        if (A) {
            preencher_matriz_2d(n, A, 0, 100);

            clock_t inicio = clock();
            long long res = funcao2_analise_triangular(n, A);
            clock_t fim = clock();
            double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("CONCLUÍDO!\n    -> Resultado: %lld | Tempo real medido: %.4f s\n", res, tempo);
        }
        free(A);
    }

    // 3. Função 3: n = 300
    {
        int n = 300;
        printf("\n[3/5] Testando Função 3 (n = 300)... ");
        fflush(stdout);
        int (*A)[n][n] = malloc(sizeof(int[n][n][n]));
        int (*B)[n][n] = malloc(sizeof(int[n][n][n]));
        if (A && B) {
            preencher_matriz_3d(n, A, 0, 100);
            preencher_matriz_3d(n, B, 0, 100);

            clock_t inicio = clock();
            int res = funcao3_comparacao_3d(n, A, B);
            clock_t fim = clock();
            double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("CONCLUÍDO!\n    -> Resultado: %d | Tempo real medido: %.4f s\n", res, tempo);
        }
        free(A); free(B);
    }

    // 4. Função 4: n = 50.000
    {
        int n = 50000;
        printf("\n[4/5] Testando Função 4 (n = 50.000 pior caso)... ");
        fflush(stdout);
        int* V = (int*)malloc(n * sizeof(int));
        if (V) {
            preencher_vetor(n, V, 0, 19);

            clock_t inicio = clock();
            unsigned long long res = funcao4_processar_vetor(n, V);
            clock_t fim = clock();
            double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("CONCLUÍDO!\n    -> Resultado: %llu | Tempo real medido: %.4f s\n", res, tempo);
        }
        free(V);
    }

    // 5. Função 5: n = 10.000.000
    {
        int n = 10000000;
        printf("\n[5/5] Testando Função 5 (n = 10.000.000 - Alocando ~80MB RAM)... ");
        fflush(stdout);
        int* A = (int*)malloc(n * sizeof(int));
        int* B = (int*)malloc(n * sizeof(int));
        if (A && B) {
            preencher_vetor(n, A, 0, 1000000);
            preencher_vetor(n, B, 0, 1000000);
            qsort(B, n, sizeof(int), comparar_inteiros);

            clock_t inicio = clock();
            long long res = funcao5_elementos_ordenados(n, A, B);
            clock_t fim = clock();
            double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

            printf("CONCLUÍDO!\n    -> Resultado: %lld | Tempo real medido: %.4f s\n", res, tempo);
        } else {
            printf("Falha na alocação de RAM suficiente para n = 10.000.000.\n");
        }
        free(A); free(B);
    }

    printf("\n==================================================================\n");
}

int main(void) {
    srand((unsigned int)time(NULL));

    int opcao = -1;

    while (opcao != 0) {
        printf("\n==================================================================\n");
        printf(" UNIPÊ - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO\n");
        printf(" PROFESSOR: HERRIOTR | PROJETO DA AVALIAÇÃO 01\n");
        printf(" INTEGRANTES: Pedro, Paulo, João, Gabriel, Lucas\n");
        printf("==================================================================\n");
        printf(" 1. Função 1: Contagem de Ocorrências Distintas (funcoes/funcao1.c)\n");
        printf(" 2. Função 2: Análise de Pares em Matriz Triangular (funcoes/funcao2.c)\n");
        printf(" 3. Função 3: Comparação de Matrizes Tridimensionais (funcoes/funcao3.c)\n");
        printf(" 4. Função 4: Análise de Casos Assimétricos (funcoes/funcao4.c)\n");
        printf(" 5. Função 5: Contagem de Elementos em Vetor Ordenado (funcoes/funcao5.c)\n");
        printf(" 6. Executar Benchmark com Valores de 'n' do Enunciado e Medir Tempo Real\n");
        printf(" 0. Sair\n");
        printf("==================================================================\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                executar_opcao1();
                break;
            case 2:
                executar_opcao2();
                break;
            case 3:
                executar_opcao3();
                break;
            case 4:
                executar_opcao4();
                break;
            case 5:
                executar_opcao5();
                break;
            case 6:
                executar_benchmark_enunciado();
                break;
            case 0:
                printf("\nSaindo do programa. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
