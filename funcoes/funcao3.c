/*
 * FUNÇÃO 3: Comparação de Matrizes Tridimensionais
 * 
 * Descrição: Recebe dois arranjos tridimensionais de inteiros, A e B, ambos com dimensões n x n x n.
 * 1. Percorre A completamente para calcular a soma de todos os seus elementos.
 * 2. Percorre B completamente para calcular a soma de todos os seus elementos.
 * 3. Compara as duas somas finais e retorna 1 se soma(A) >= soma(B), e 0 caso contrário.
 */
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

    return (somaA >= somaB) ? 1 : 0;
}
