/*
 * FUNÇÃO 2: Análise de Pares em Matriz Triangular
 * 
 * Descrição: Recebe uma matriz de inteiros com n linhas e n colunas. Testa todos os
 * elementos da metade superior (acima da diagonal principal) com os seus opostos
 * presentes na metade inferior (abaixo da diagonal principal), incluindo a diagonal principal.
 * Incrementa o contador toda vez que A[i][j] + A[j][i] for múltiplo de 5.
 */
long long funcao2_analise_triangular(int n, int A[n][n]) {
    long long contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // laço interno j >= i conforme dica do professor
            int soma = A[i][j] + A[j][i];
            if (soma % 5 == 0) {
                contador++;
            }
        }
    }
    return contador;
}
