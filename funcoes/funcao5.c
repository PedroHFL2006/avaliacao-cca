/*
 * FUNÇÃO 5: Contagem de Elementos Presentes em Vetor Ordenado
 * 
 * Descrição: Implementa primeiro uma função auxiliar de Busca Binária em um vetor B.
 * Em seguida, implementa a função que recebe um vetor A não ordenado de tamanho n e
 * um vetor B ordenado de tamanho n. Para cada elemento do vetor A, realiza uma busca binária
 * no vetor B. Retorna o total de elementos do vetor A que foram encontrados no vetor B.
 */

// Função auxiliar de Busca Binária
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

// Função principal da Questão 5
long long funcao5_elementos_ordenados(int n, int A[n], int B[n]) {
    long long total_encontrados = 0;
    for (int i = 0; i < n; i++) {
        if (busca_binaria(n, B, A[i])) {
            total_encontrados++;
        }
    }
    return total_encontrados;
}
