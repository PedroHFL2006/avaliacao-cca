/*
 * FUNÇÃO 4 (Refeita): Análise de Casos Assimétricos no Condicional
 * 
 * Descrição: Recebe processar_vetor que receba um vetor de inteiros de tamanho n.
 * - Se PAR: soma o valor do V[i] atual a uma variável acumuladora.
 * - Se ÍMPAR: calcula o fatorial daquele valor e o resultado é somado à variável acumuladora.
 * Retorna o somatório ao final.
 */
unsigned long long processar_vetor(int n, int V[n]) {
    unsigned long long somatorio = 0;
    for (int i = 0; i < n; i++) {
        if (V[i] % 2 == 0) {
            somatorio += V[i];
        } else {
            unsigned long long fat = 1;
            int val = V[i];
            if (val < 0) val = -val;
            if (val > 20) val = 20; // Limita a 20 para evitar estouro numérico em 64-bit
            for (int j = 1; j <= val; j++) {
                fat *= j;
            }
            somatorio += fat;
        }
    }
    return somatorio;
}

// Wrapper para compatibilidade no main.c
unsigned long long funcao4_processar_vetor(int n, int V[n]) {
    return processar_vetor(n, V);
}
