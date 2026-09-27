# RELATÓRIO DE ANÁLISE DE COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMOS

**UNIVERSIDADE DOS IPÊS - UNIPÊ**  
**DISCIPLINA:** COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO  
**PROFESSOR:** HERRIOTR  
**PROJETO DA AVALIAÇÃO 01**

---

### **INTEGRANTES DO GRUPO (5 MEMBROS):**
1. **Pedro**
2. **Paulo**
3. **João**
4. **Gabriel**
5. **Lucas**

---

## 1. PARÂMETROS GERAIS DA ANÁLISE DE TEMPO
Para todos os cálculos teóricos de tempo de execução, considera-se a especificação dada no enunciado do professor Herriotr:
* **Linguagem de Programação Utilizada:** **Linguagem C (Padrão C99)**.
* **Capacidade de Processamento do Computador:** $10^8$ ($100.000.000$) instruções por segundo.
* **Fórmula do Tempo:** $\text{Tempo (segundos)} = \frac{\text{Número Total de Instruções/Operações}}{10^8 \text{ instruções/segundo}}$

---

## 2. ESTRUTURA MODULAR DO PROJETO EM C E ARQUIVOS DE ENTREGA

Cada uma das 5 funções solicitadas no arquivo PDF da avaliação foi organizada em seu **arquivo `.c` dedicado** na pasta `funcoes/`, e os **pseudocódigos em Portugol** estão no relatório de texto:

```
Avaliação CCA/
├── main.c                          # Programa principal em C99 (Menu, preenchimento e exibição)
├── relatorio_complexidade.md       # Relatório com os Pseudocódigos em Portugol, fórmulas em LaTeX e tabelas
├── relatorio_complexidade.txt       # Arquivo de texto puro com os Pseudocódigos em Portugol e cálculos teóricos
└── funcoes/                        # Pasta contendo os 5 arquivos C isolados do PDF
    ├── funcao1.c                   # FUNÇÃO 1: Contagem de Ocorrências Distintas
    ├── funcao2.c                   # FUNÇÃO 2: Análise de Pares em Matriz Triangular
    ├── funcao3.c                   # FUNÇÃO 3: Comparação de Matrizes Tridimensionais
    ├── funcao4.c                   # FUNÇÃO 4: Análise de Casos Assimétricos (Par/Fatorial Ímpar)
    └── funcao5.c                   # FUNÇÃO 5: Contagem em Vetor Ordenado (Busca Binária)
```

### **Como Compilar o Projeto no Terminal (GCC):**
```bash
gcc -std=c99 -Wall main.c -o programa.exe
```

---

## 3. ANÁLISE DETALHADA DAS 5 FUNÇÕES

---

### **FUNÇÃO 1: Contagem de Ocorrências Distintas (`funcoes/funcao1.c`)**

#### **A. Descrição do Problema**
A função recebe um vetor principal $V$ de inteiros com tamanho $n$ e um vetor de busca $K\_vec$ com $k$ elementos. Para cada um dos $k$ elementos de busca, a função conta quantas vezes ele aparece no vetor principal $V$ e retorna a soma total acumulada de ocorrências.

#### **B. Algoritmo em Pseudocódigo**
```text
função contagem_ocorrencias(V, n, K_vec, k):
    soma_total <- 0                       // c1 (1 vez)
    para i <- 0 até k-1 faça             // c2 (k + 1 vezes)
        contador <- 0                     // c3 (k vezes)
        para j <- 0 até n-1 faça         // c4 (k * (n + 1) vezes)
            se V[j] == K_vec[i] então     // c5 (k * n vezes)
                contador <- contador + 1  // c6 (no máximo k * n vezes)
            fim_se
        fim_para
        soma_total <- soma_total + contador // c7 (k vezes)
    fim_para
    retorne soma_total                   // c8 (1 vez)
fim_funcao
```

#### **C. Tabela de Complexidade por Linha**
| Linha | Comando | Custo por Execução | Frequência de Execução |
| :--- | :--- | :--- | :--- |
| 1 | `soma_total <- 0` | $c_1$ | $1$ |
| 2 | `para i <- 0 até k-1 faça` | $c_2$ | $k + 1$ |
| 3 | `contador <- 0` | $c_3$ | $k$ |
| 4 | `para j <- 0 até n-1 faça` | $c_4$ | $k(n + 1)$ |
| 5 | `se V[j] == K_vec[i] então` | $c_5$ | $k \cdot n$ |
| 6 | `contador <- contador + 1` | $c_6$ | $k \cdot n$ *(no pior caso)* |
| 7 | `soma_total <- soma_total + contador` | $c_7$ | $k$ |
| 8 | `retorne soma_total` | $c_8$ | $1$ |

#### **D. Expressão da Função de Complexidade $T(n, k)$**
$$T(n, k) = c_1 + c_2(k+1) + c_3 k + c_4 k(n+1) + c_5 k n + c_6 k n + c_7 k + c_8$$
$$T(n, k) = (c_4 + c_5 + c_6) \cdot k \cdot n + (c_2 + c_3 + c_4 + c_7) \cdot k + (c_1 + c_2 + c_8)$$
$$T(n, k) = A \cdot k \cdot n + B \cdot k + C$$

#### **E. Notação Big-O**
$$\mathbf{O(k \cdot n)}$$

#### **F. Cálculo do Tempo Gasto**
* **Parâmetros Fornecidos:** $n = 50.000$ e $k = 4.000$.
* **Número de Operações Principais ($k \cdot n$):**
  $$\text{Operações} = 4.000 \times 50.000 = 200.000.000 = 2 \times 10^8 \text{ instruções}$$
* **Cálculo do Tempo de Processamento:**
  $$\text{Tempo} = \frac{2 \times 10^8 \text{ instruções}}{10^8 \text{ instruções/segundo}} = \mathbf{2,00 \text{ segundos}}$$

---

### **FUNÇÃO 2: Análise de Pares em Matriz Triangular (`funcoes/funcao2.c`)**

#### **A. Descrição do Problema**
A função recebe uma matriz quadrada $A$ de ordem $n \times n$. Ela testa os elementos da metade superior (acima da diagonal principal) com seus pares opostos presentes na metade inferior (abaixo da diagonal principal), incluindo também os elementos da própria diagonal principal. Se a soma $A[i][j] + A[j][i]$ for múltiplo de 5, um contador é incrementado.

#### **B. Algoritmo em Pseudocódigo**
```text
função analise_triangular(A, n):
    contador <- 0                           // c1 (1 vez)
    para i <- 0 até n-1 faça                 // c2 (n + 1 vezes)
        para j <- i até n-1 faça             // c3 (somatório de (n - i + 1))
            soma <- A[i][j] + A[j][i]        // c4 (n(n+1)/2 vezes)
            se soma % 5 == 0 então           // c5 (n(n+1)/2 vezes)
                contador <- contador + 1      // c6 (no máximo n(n+1)/2 vezes)
            fim_se
        fim_para
    fim_para
    retorne contador                       // c7 (1 vez)
fim_funcao
```

#### **C. Tabela de Complexidade por Linha**
| Linha | Comando | Custo por Execução | Frequência de Execução |
| :--- | :--- | :--- | :--- |
| 1 | `contador <- 0` | $c_1$ | $1$ |
| 2 | `para i <- 0 até n-1 faça` | $c_2$ | $n + 1$ |
| 3 | `para j <- i até n-1 faça` | $c_3$ | $\frac{n(n+3)}{2}$ |
| 4 | `soma <- A[i][j] + A[j][i]` | $c_4$ | $\frac{n(n+1)}{2}$ |
| 5 | `se soma % 5 == 0 então` | $c_5$ | $\frac{n(n+1)}{2}$ |
| 6 | `contador <- contador + 1` | $c_6$ | $\frac{n(n+1)}{2}$ *(no pior caso)* |
| 7 | `retorne contador` | $c_7$ | $1$ |

#### **D. Expressão da Função de Complexidade $T(n)$**
$$T(n) = \frac{c_3 + c_4 + c_5 + c_6}{2} \cdot n^2 + \left( c_2 + \frac{3 c_3 + c_4 + c_5 + c_6}{2} \right) \cdot n + (c_1 + c_2 + c_7)$$
$$T(n) = A \cdot n^2 + B \cdot n + C$$

#### **E. Notação Big-O**
$$\mathbf{O(n^2)}$$

#### **F. Cálculo do Tempo Gasto**
* **Parâmetro Fornecido:** $n = 500$.
* **Número de Pares Avaliados ($\frac{n(n+1)}{2}$):**
  $$\text{Pares} = \frac{500 \times 501}{2} = 125.250 \text{ pares}$$
* **Total de Instruções Estimadas:**
  $$\text{Instruções} \approx 125.250 \times 5 = 626.250 \text{ instruções}$$
* **Cálculo do Tempo de Processamento:**
  $$\text{Tempo} = \frac{626.250}{10^8} = \mathbf{0,00626 \text{ segundos} \approx 6,26 \text{ milissegundos}}$$

---

### **FUNÇÃO 3: Comparação de Matrizes Tridimensionais (`funcoes/funcao3.c`)**

#### **A. Descrição do Problema**
A função recebe dois arranjos tridimensionais $A$ e $B$, ambos de dimensão $n \times n \times n$. Ela calcula sequencialmente a soma de todos os elementos de $A$, depois a soma de todos os elementos de $B$, e por fim retorna $1$ se $\text{soma}(A) \ge \text{soma}(B)$ e $0$ caso contrário.

#### **B. Algoritmo em Pseudocódigo**
```text
função comparacao_3d(A, B, n):
    somaA <- 0                                // c1 (1 vez)
    para i <- 0 até n-1 faça                  // c2 (n + 1)
        para j <- 0 até n-1 faça              // c3 (n(n+1))
            para k <- 0 até n-1 faça          // c4 (n^2(n+1))
                somaA <- somaA + A[i][j][k]   // c5 (n^3)
            fim_para
        fim_para
    fim_para

    somaB <- 0                                // c6 (1 vez)
    para i <- 0 até n-1 faça                  // c7 (n + 1)
        para j <- 0 até n-1 faça              // c8 (n*(n+1))
            para k <- 0 até n-1 faça          // c9 (n^2*(n+1))
                somaB <- somaB + B[i][j][k]   // c10 (n^3)
            fim_para
        fim_para
    fim_para

    se somaA >= somaB então retorne 1 senão retorne 0 fim_se
fim_funcao
```

#### **C. Expressão da Função de Complexidade $T(n)$**
$$T(n) = A \cdot n^3 + B \cdot n^2 + C \cdot n + D$$

#### **D. Notação Big-O**
$$\mathbf{O(n^3)}$$

#### **E. Cálculo do Tempo Gasto**
* **Parâmetro Fornecido:** $n = 300$.
* **Número Total de Acessos nas Duas Matrizes ($A$ e $B$):**
  $$\text{Acessos Totais} = 2 \times 300^3 = 54.000.000 \text{ iterações}$$
* **Cálculo do Tempo de Processamento:**
  $$\text{Tempo} = \frac{1,08 \times 10^8}{10^8} = \mathbf{1,08 \text{ segundos}}$$

---

### **FUNÇÃO 4: Análise de Casos Assimétricos no Condicional (`funcoes/funcao4.c`)**

#### **A. Descrição do Problema**
A função percorre um vetor $V$ de tamanho $n$. Para cada elemento $V[i]$:
* Se $V[i]$ for **PAR**: soma o valor diretamente à variável acumuladora.
* Se $V[i]$ for **ÍMPAR**: calcula o fatorial de $V[i]$ e soma o resultado à variável acumuladora.

#### **B. Algoritmo em Pseudocódigo**
```text
função processar_vetor(V, n):
    somatorio <- 0                           // c1 (1 vez)
    para i <- 0 até n-1 faça                 // c2 (n + 1 vezes)
        se V[i] % 2 == 0 então               // c3 (n vezes)
            somatorio <- somatorio + V[i]     // c4 (ramo par)
        senão
            fat <- 1                         // c5 (ramo ímpar)
            para j <- 1 até V[i] faça        // c6 (V[i] + 1 vezes)
                fat <- fat * j               // c7 (V[i] vezes)
            fim_para
            somatorio <- somatorio + fat     // c8 (ramo ímpar)
        fim_se
    fim_para
    retorne somatorio                       // c9 (1 vez)
fim_funcao
```

#### **C. Expressão da Função de Complexidade $T(n, m)$ (Pior Caso)**
$$T(n, m) = A \cdot (n \cdot m) + B \cdot n + C$$

#### **D. Notação Big-O**
$$\mathbf{O(n \cdot m)} \rightarrow \mathbf{O(n)}$$

#### **E. Cálculo do Tempo Gasto**
* **Parâmetro Fornecido:** $n = 50.000$ no pior caso.
* **Com Limite Numérico Prático ($m = 20$):**
  $$\text{Tempo} = \frac{1.000.000}{10^8} = \mathbf{0,010 \text{ segundos} = 10 \text{ milissegundos}}$$

---

### **FUNÇÃO 5: Contagem de Elementos Presentes em Vetor Ordenado (`funcoes/funcao5.c`)**

#### **A. Descrição do Problema**
Implementa-se uma função auxiliar de **Busca Binária** em vetor ordenado (`busca_binaria`). A função principal recebe um vetor não ordenado $A$ de tamanho $n$ e um vetor ordenado $B$ de tamanho $n$. Para cada elemento do vetor $A$, executa-se a Busca Binária no vetor $B$ e retorna-se o número de elementos de $A$ encontrados em $B$.

#### **B. Algoritmo em Pseudocódigo**
```text
função busca_binaria(B, n, chave):
    inicio <- 0; fim <- n - 1
    enquanto inicio <= fim faça
        meio <- inicio + (fim - inicio) / 2
        se B[meio] == chave então retorne 1
        senão se B[meio] < chave então inicio <- meio + 1
        senão fim <- meio - 1
        fim_se
    fim_enquanto
    retorne 0
fim_funcao

função contagem_elementos_ordenados(A, B, n):
    total_encontrados <- 0
    para i <- 0 até n-1 faça
        encontrado <- busca_binaria(B, n, A[i])
        total_encontrados <- total_encontrados + encontrado
    fim_para
    retorne total_encontrados
fim_funcao
```

#### **C. Expressão da Função de Complexidade $T(n)$**
$$T(n) = A \cdot (n \log_2 n) + B \cdot n + C$$

#### **D. Notação Big-O**
$$\mathbf{O(n \log n)}$$

#### **E. Cálculo do Tempo Gasto**
* **Parâmetro Fornecido:** $n = 10.000.000 = 10^7$.
* **Operações Totais:** $10.000.000 \times \log_2(10.000.000) \approx 232.534.966 \text{ instruções}$.
* **Tempo Teórico Estimado:** $\mathbf{2,33 \text{ segundos}}$.

---

## 4. RESUMO COMPARATIVO DE COMPLEXIDADE E TEMPO (C99)

| Função | Arquivo Fonte | Entrada de Teste | Notação Big-O | Tempo Teórico Estimado ($10^8$ ops/s) |
| :--- | :--- | :--- | :--- | :--- |
| **Função 1** | `funcoes/funcao1.c` | $n = 50.000, k = 4.000$ | $O(k \cdot n)$ | **2,00 segundos** |
| **Função 2** | `funcoes/funcao2.c` | $n = 500$ | $O(n^2)$ | **0,00626 segundos** ($6,26 \text{ ms}$) |
| **Função 3** | `funcoes/funcao3.c` | $n = 300$ | $O(n^3)$ | **1,08 segundos** |
| **Função 4** | `funcoes/funcao4.c` | $n = 50.000$ *(Pior caso)* | $O(n)$ | **0,010 segundos** ($10 \text{ ms}$) |
| **Função 5** | `funcoes/funcao5.c` | $n = 10.000.000$ | $O(n \log n)$ | **2,33 segundos** |

---

## 5. CONCLUSÃO
As 5 funções solicitadas no PDF da prova foram organizadas de maneira totalmente **modular em arquivos `.c` e `.h` independentes** dentro da pasta `funcoes/`. As análises de complexidade Big-O e os cálculos de tempo comprovam o rigor técnico e computacional do projeto.
