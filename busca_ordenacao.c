#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, indice_pivo - 1);
        quicksort(vetor, indice_pivo + 1, fim);
    }
}

int busca_binaria(const int vetor[], int tamanho, int alvo, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    *comparacoes = 0;

    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio] == alvo) {
            return meio;
        }
        if (vetor[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int dados_iniciais[] = {42, 15, 8, 99, 23, 4, 16, 71, 30, 11};
    int n = (int)(sizeof(dados_iniciais) / sizeof(dados_iniciais[0]));

    int *vetor = (int *)malloc((size_t)n * sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = dados_iniciais[i];
    }

    quicksort(vetor, 0, n - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int alvo = 23;
    int comparacoes = 0;
    int posicao = busca_binaria(vetor, n, alvo, &comparacoes);

    if (posicao != -1) {
        printf("Elemento %d encontrado no indice %d (%d comparacoes).\n",
               alvo, posicao, comparacoes);
    } else {
        printf("Elemento %d nao encontrado.\n", alvo);
    }

    free(vetor);
    return 0;
}