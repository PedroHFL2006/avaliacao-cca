/*
 UNIPÊ - Complexidade e Computabilidade de Algoritmo
 Professor: Herriotr
 Avaliação 01

 Integrantes:
 Pedro Henrique Figueiredo Lima - RGM 40111831
 Deyvid Lucas da Cunha Amorim - RGM 34040722
 Marcio Gomes
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ler_tamanho(char *msg) {
    int n;
    do {
        printf("%s", msg);
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

int perguntar_modo() {
    int op;
    do {
        printf("\n1 - Preencher manualmente\n");
        printf("2 - Preencher com valores aleatorios\n");
        printf("Opcao: ");
        scanf("%d", &op);
    } while (op != 1 && op != 2);
    return op == 1;
}

void preencher_vetor(int n, int V[n], int manual, int max) {
    for (int i = 0; i < n; i++) {
        if (manual) {
            printf("[%d]: ", i);
            scanf("%d", &V[i]);
        } else {
            V[i] = rand() % (max + 1);
        }
    }
}

void preencher_matriz(int n, int M[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void preencher_matriz_3d(int n, int M[n][n][n], int manual) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (manual) {
                    printf("[%d][%d][%d]: ", i, j, k);
                    scanf("%d", &M[i][j][k]);
                } else {
                    M[i][j][k] = rand() % 10;
                }
            }
        }
    }
}

// cria a matriz dinamica perguntando linhas e colunas e preenche com aleatorios
void *criar_matriz_aleatoria(int *linhas, int *colunas) {
    int l = ler_tamanho("Quantidade de linhas: ");
    int c = ler_tamanho("Quantidade de colunas: ");
    int (*M)[c] = malloc(sizeof(int[l][c]));

    *linhas = l;
    *colunas = c;
    if (M == NULL) return NULL;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            M[i][j] = rand() % 10;
        }
    }
    return M;
}

void imprimir_vetor(char *nome, int n, int V[n]) {
    printf("\n%s: ", nome);
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void imprimir_matriz(char *nome, int linhas, int colunas, int M[linhas][colunas]) {
    printf("\n%s:\n", nome);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
}

void imprimir_matriz_3d(char *nome, int n, int M[n][n][n]) {
    printf("\n%s:\n", nome);
    for (int i = 0; i < n; i++) {
        printf("%s[%d]:\n", nome, i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%4d", M[i][j][k]);
            }
            printf("\n");
        }
    }
}

int comparar(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Funcao 1
long long contagem_ocorrencias(int n, int V[n], int k, int K_vec[k]) {
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

// Funcao 2
int analise_triangular(int n, int A[n][n]) {
    int contador = 0;
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

// Funcao 3
int comparacao_3d(int n, int A[n][n][n], int B[n][n][n]) {
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

// Funcao 4
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

// Funcao 5
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

int elementos_ordenados(int n, int A[n], int B[n]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (busca_binaria(n, B, A[i])) {
            total++;
        }
    }
    return total;
}

void opcao1() {
    int n = ler_tamanho("Tamanho do vetor (n): ");
    int k = ler_tamanho("Quantidade de elementos buscados (k): ");
    int manual = perguntar_modo();
    int *V = malloc(n * sizeof(int));
    int *K_vec = malloc(k * sizeof(int));

    printf("\nVetor V\n");
    preencher_vetor(n, V, manual, 20);
    printf("\nVetor de buscados\n");
    preencher_vetor(k, K_vec, manual, 20);

    imprimir_vetor("V", n, V);
    imprimir_vetor("Buscados", k, K_vec);
    printf("\nResultado: %lld\n", contagem_ocorrencias(n, V, k, K_vec));

    free(V);
    free(K_vec);
}

void opcao2() {
    int n, linhas, colunas;
    void *p;

    if (perguntar_modo()) {
        n = ler_tamanho("Tamanho da matriz (n): ");
        p = malloc(sizeof(int[n][n]));
        preencher_matriz(n, p);
    } else {
        p = criar_matriz_aleatoria(&linhas, &colunas);
        while (linhas != colunas) {
            printf("A matriz precisa ser quadrada.\n");
            free(p);
            p = criar_matriz_aleatoria(&linhas, &colunas);
        }
        n = linhas;
    }

    int (*A)[n] = p;
    imprimir_matriz("Matriz A", n, n, A);
    printf("\nResultado: %d\n", analise_triangular(n, A));
    free(A);
}

void opcao3() {
    int n = ler_tamanho("Tamanho dos arranjos (n): ");
    int manual = perguntar_modo();
    int (*A)[n][n] = malloc(sizeof(int[n][n][n]));
    int (*B)[n][n] = malloc(sizeof(int[n][n][n]));

    printf("\nArranjo A\n");
    preencher_matriz_3d(n, A, manual);
    printf("\nArranjo B\n");
    preencher_matriz_3d(n, B, manual);

    imprimir_matriz_3d("A", n, A);
    imprimir_matriz_3d("B", n, B);
    printf("\nResultado: %d\n", comparacao_3d(n, A, B));

    free(A);
    free(B);
}

void opcao4() {
    int n = ler_tamanho("Tamanho do vetor (n): ");
    int manual = perguntar_modo();
    int *V = malloc(n * sizeof(int));

    // acima de 20 o fatorial nao cabe em unsigned long long
    for (int i = 0; i < n; i++) {
        if (manual) {
            do {
                printf("[%d] (0 a 20): ", i);
                scanf("%d", &V[i]);
            } while (V[i] < 0 || V[i] > 20);
        } else {
            V[i] = rand() % 21;
        }
    }

    imprimir_vetor("V", n, V);
    printf("\nResultado: %llu\n", processar_vetor(n, V));
    free(V);
}

void opcao5() {
    int n = ler_tamanho("Tamanho dos vetores (n): ");
    int manual = perguntar_modo();
    int *A = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));

    printf("\nVetor A\n");
    preencher_vetor(n, A, manual, 50);
    printf("\nVetor B\n");
    preencher_vetor(n, B, manual, 50);
    qsort(B, n, sizeof(int), comparar);

    imprimir_vetor("A", n, A);
    imprimir_vetor("B ordenado", n, B);
    printf("\nResultado: %d\n", elementos_ordenados(n, A, B));

    free(A);
    free(B);
}

void opcao6() {
    int linhas, colunas;
    void *p = criar_matriz_aleatoria(&linhas, &colunas);
    int (*M)[colunas] = p;
    imprimir_matriz("Matriz gerada", linhas, colunas, M);
    free(M);
}

int main() {
    srand(time(NULL));

    int op;
    do {
        printf("\n===== AVALIACAO 01 - CCA =====\n");
        printf("Integrantes:\n");
        printf("Pedro Henrique Figueiredo Lima - RGM 40111831\n");
        printf("Deyvid Lucas da Cunha Amorim - RGM 34040722\n");
        printf("Marcio Gomes\n");
        printf("\n");
        printf("1 - Contagem de ocorrencias distintas\n");
        printf("2 - Analise de pares em matriz triangular\n");
        printf("3 - Comparacao de matrizes tridimensionais\n");
        printf("4 - Analise de casos assimetricos\n");
        printf("5 - Contagem de elementos em vetor ordenado\n");
        printf("6 - Criar matriz dinamica aleatoria\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: opcao1(); break;
            case 2: opcao2(); break;
            case 3: opcao3(); break;
            case 4: opcao4(); break;
            case 5: opcao5(); break;
            case 6: opcao6(); break;
            case 0: break;
            default: printf("Opcao invalida\n");
        }
    } while (op != 0);

    return 0;
}
