# Algoritmos de Ordenação e Busca em C

Implementação em **C (padrão C11)** de algoritmos clássicos de ordenação (*QuickSort*) e busca (*Busca Binária*) com alocação dinâmica de memória e contagem de operações para análise empírica de desempenho.

## Conceitos aplicados
- Alocação e liberação explícita de memória (`malloc` e `free`).
- Recursão e particionamento com *QuickSort*.
- Busca binária iterativa em vetores ordenados.

## Como compilar e executar (Linux)
```bash
gcc -Wall -Wextra -std=c11 busca_ordenacao.c -o busca_ordenacao
./busca_ordenacao