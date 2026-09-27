/*
 * FUNÇÃO 1: Contagem de Ocorrências Distintas
 * 
 * Descrição: Recebe um vetor de inteiros de tamanho n e uma lista de k
 * elementos a serem buscados (vetor de tamanho k). Percorre a lista de k
 * elementos e, para cada um, conta quantas vezes ele aparece no vetor principal
 * de n elementos, retornando a soma da quantidade de aparições.
 */
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
