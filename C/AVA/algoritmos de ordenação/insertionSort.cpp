#include <stdio.h>

// Função para realizar a ordenação por inserção (Insertion Sort)
void insertionSort(int array[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];
        int j = i - 1;

        // Mover os elementos maiores que a chave para a direita
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        // Inserir a chave na posição correta
        array[j + 1] = chave;
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
    printf("Array antes da ordenação por inserção:\n");
    imprimirArray(meuArray, tamanhoArray);

    // Chamar o algoritmo de ordenação por inserção
    insertionSort(meuArray, tamanhoArray);

    // Imprimir array ordenado
    printf("Array após a ordenação por inserção:\n");
    imprimirArray(meuArray, tamanhoArray);

    return 0;
}

/*
Ordenação por Inserção: O algoritmo de ordenação por inserção constrói uma sequência ordenada de elementos um de cada vez. Ele é eficiente para pequenos conjuntos de dados ou quando os dados estão quase ordenados.

Chave e Deslocamento: A chave é o elemento atual sendo comparado e movido para a posição correta. O deslocamento ocorre quando elementos maiores que a chave são movidos para a direita.

Implementação Genérica: O código é projetado para trabalhar com arrays de inteiros, mas pode ser adaptado para outros tipos de dados.

Complexidade: O Insertion Sort possui complexidade de tempo O(n^2) no pior caso, mas pode ser mais eficiente que outros algoritmos de ordenação para conjuntos de dados pequenos.
*/