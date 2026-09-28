# Avaliação 01 - Complexidade e Computabilidade de Algoritmo (UNIPÊ)

Professor: Herriotr

Integrantes:
1. Pedro
2. Paulo
3. João
4. Gabriel
5. Lucas

## Arquivos

- `main.c`: programa completo em um único arquivo (as 5 funções, a função do ATENÇÃO 01, a impressão dos arranjos e o menu).
- `relatorio_complexidade.txt`: pseudocódigo com o custo de cada linha, T(n), Big-O e tempo estimado de cada função.

## Como compilar

```
gcc -std=c99 main.c -o programa
./programa
```

O código usa C99 (VLA nos parâmetros, como pede o ATENÇÃO 03). No Dev-C++ antigo, adicione `-std=c99` em Ferramentas > Opções do Compilador antes de apertar F11.

## Menu

- 1 a 5: executam cada função, com preenchimento manual ou aleatório, e imprimem os arranjos completos. Na Função 2, o preenchimento aleatório cria a matriz com a função do ATENÇÃO 01.
- 6: benchmark do pior caso de cada função com os valores de n do enunciado.
- 7: ATENÇÃO 01, pergunta linhas e colunas, cria a matriz dinâmica e preenche com valores aleatórios.
