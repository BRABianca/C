#include <stdio.h>

// Função para trocar dois elementos em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para realizar a ordenação por seleção (Selection Sort)
void selectionSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        // Encontrar o índice do menor elemento restante
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[indiceMenor]) {
                indiceMenor = j;
            }
        }

        // Trocar o menor elemento com o primeiro não ordenado
        trocar(&array[i], &array[indiceMenor]);
    }
}

// Função para imprimir os elementos de um array
void imprimirArray(const int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    const int tamanhoArray = 6;
    int meuArray[] = {64, 25, 12, 22, 11, 1};

    // Imprimir array não ordenado
    printf("Array antes da ordenação por seleção:\n");
    imprimirArray(meuArray, tamanhoArray);

    // Chamar o algoritmo de ordenação por seleção
    selectionSort(meuArray, tamanhoArray);

    // Imprimir array ordenado
    printf("Array após a ordenação por seleção:\n");
    imprimirArray(meuArray, tamanhoArray);

    return 0;
}

/*
Ordenação por Seleção: O algoritmo de ordenação por seleção divide o array em duas partes: uma parte ordenada e uma parte não ordenada. A cada iteração, ele encontra o menor elemento na parte não ordenada e o troca com o primeiro elemento não ordenado.

Função de Troca: A função trocar é utilizada para trocar dois elementos em um array.

Implementação Genérica: O código é projetado para trabalhar com arrays de inteiros, mas pode ser adaptado para outros tipos de dados.

Complexidade: O Selection Sort possui complexidade de tempo O(n^2) no pior caso, tornando-se menos eficiente para grandes conjuntos de dados.
*/