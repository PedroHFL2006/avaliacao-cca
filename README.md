# Avaliação 01 - Complexidade e Computabilidade de Algoritmos (UNIPÊ)

**Professor:** Herriotr  
**Curso:** Ciência da Computação / Análise e Desenvolvimento de Sistemas  
**Integrantes do Grupo:**

1. Pedro
2. Paulo
3. João
4. Gabriel
5. Lucas

---

## 📌 Sobre o Projeto

Este projeto consiste na implementação, integração e análise de complexidade temporal e espacial de 5 funções/algoritmos em linguagem **C (padrão C99)**.

O arquivo [`main.c`](main.c) funciona como o ponto central da aplicação, unindo as 5 funções isoladas presentes no diretório `funcoes/`. O programa oferece um menu interativo de terminal com opções de execução manual, aleatória e um **benchmark automatizado** com medição de tempo real para as instâncias de teste do enunciado.

---

## 📁 Estrutura de Arquivos

```text
Avaliação CCA/
├── funcoes/
│   ├── funcao1.c    # Função 1: Contagem de Ocorrências Distintas
│   ├── funcao2.c    # Função 2: Análise de Pares em Matriz Triangular
│   ├── funcao3.c    # Função 3: Comparação de Matrizes Tridimensionais
│   ├── funcao4.c    # Função 4: Análise de Casos Assimétricos
│   └── funcao5.c    # Função 5: Elementos Presentes em Vetor Ordenado
├── main.c           # Programa principal (menu, alocação, exibição e benchmark)
├── relatorio_complexidade.md # Relatório técnico detalhado com notação Big-O
├── relatorio_complexidade.txt # Versão em texto puro do relatório
└── README.md        # Guia de instruções de compilação e execução
```

---

## 🛠️ Requisitos do Sistema

- **Compilador C**: `gcc` (suporte ao padrão C99) ou equivalente (`clang`, `cl`).
- **Ambientes suportados**: Windows (PowerShell/CMD, MSYS2, MinGW, WSL Ubuntu) ou Linux/macOS.

---

## 🚀 Como Compilar e Executar

### 1. Via WSL Ubuntu (Recomendado no Windows)

Se estiver utilizando o WSL Ubuntu no Windows Terminal:

**Compilar:**

```bash
wsl gcc main.c -o programa -std=c99 -O2
```

**Executar o Menu Interativo:**

```bash
wsl ./programa
```

**Executar o Benchmark Automático (Direto):**

```bash
"6`n0" | wsl ./programa
```

---

### 2. Via MinGW / GCC Nativo (Windows PowerShell ou CMD)

Se você possui o MinGW configurado nas variáveis de ambiente (PATH):

**Compilar:**

```powershell
gcc main.c -o programa.exe -std=c99 -O2
```

**Executar:**

```powershell
.\programa.exe
```

---

### 3. Via IDEs (VS Code, Code::Blocks, Dev-C++)

- **Visual Studio Code**:
  1. Abra a pasta do projeto no VS Code.
  2. Abra o arquivo [`main.c`](main.c).
  3. Pressione `F5` ou utilize a extensão **C/C++ Runner** / botão **Run**.

- **Code::Blocks / Dev-C++**:
  1. Abra o projeto ou o arquivo [`main.c`](main.c).
  2. Clique em **Build & Run** (ou pressione a tecla `F9`).

---

## 📋 Opções do Menu do Programa

Ao executar o programa, o seguinte menu interativo será exibido:

```text
==================================================================
 UNIPÊ - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO
 PROFESSOR: HERRIOTR | PROJETO DA AVALIAÇÃO 01
 INTEGRANTES: Pedro, Paulo, João, Gabriel, Lucas
==================================================================
 1. Função 1: Contagem de Ocorrências Distintas (funcoes/funcao1.c)
 2. Função 2: Análise de Pares em Matriz Triangular (funcoes/funcao2.c)
 3. Função 3: Comparação de Matrizes Tridimensionais (funcoes/funcao3.c)
 4. Função 4: Análise de Casos Assimétricos (funcoes/funcao4.c)
 5. Função 5: Contagem de Elementos em Vetor Ordenado (funcoes/funcao5.c)
 6. Executar Benchmark com Valores de 'n' do Enunciado e Medir Tempo Real
 0. Sair
==================================================================
```

- **Opções 1 a 5**: Permitem testar individualmente cada função, informando o tamanho das entradas ($n$, $k$) e escolhendo entre preenchimento manual de dados ou geração de números aleatórios.
- **Opção 6**: Executa o teste de desempenho completo com todas as 5 funções em sequência para as dimensões máximas especificadas no projeto (ex: $n = 10.000.000$ na Função 5), reportando o tempo real medido em segundos.
