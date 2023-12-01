#include <stdio.h>

// Função para realizar busca sequencial em um array
int buscaSequencial(const int array[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == elemento) {
            return i; // Retorna a posição se o elemento for encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para realizar busca binária em um array ordenado
int buscaBinaria(const int array[], int inicio, int fim, int elemento) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (array[meio] == elemento) {
            return meio; // Retorna a posição se o elemento for encontrado
        } else if (array[meio] < elemento) {
            return buscaBinaria(array, meio + 1, fim, elemento);
        } else {
            return buscaBinaria(array, inicio, meio - 1, elemento);
        }
    }

    return -1; // Retorna -1 se o elemento não for encontrado
}

int main() {
    const int tamanhoArray = 10;
    int meuArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int elementoBusca;

    // Solicita ao usuário o elemento a ser buscado
    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elementoBusca);

    // Busca Sequencial
    int posicaoSequencial = buscaSequencial(meuArray, tamanhoArray, elementoBusca);
    if (posicaoSequencial != -1) {
        printf("Busca Sequencial: Elemento encontrado na posição %d\n", posicaoSequencial);
    } else {
        printf("Busca Sequencial: Elemento não encontrado.\n");
    }

    // Busca Binária (array deve estar ordenado)
    int posicaoBinaria = buscaBinaria(meuArray, 0, tamanhoArray - 1, elementoBusca);
    if (posicaoBinaria != -1) {
        printf("Busca Binária: Elemento encontrado na posição %d\n", posicaoBinaria);
    } else {
        printf("Busca Binária: Elemento não encontrado.\n");
    }

    return 0;
}

/*
Busca Sequencial: A função buscaSequencial percorre o array linearmente para encontrar o elemento desejado. É eficiente para arrays não ordenados.

Busca Binária: A função buscaBinaria é uma abordagem mais eficiente para arrays ordenados. Ela divide repetidamente o array ao meio até encontrar o elemento desejado.

Ordenação: A Busca Binária requer um array ordenado. Se o array não estiver ordenado, pode-se usar a Busca Sequencial ou ordenar o array antes da Busca Binária.

Retorno: As funções retornam a posição do elemento se encontrado ou -1 se não encontrado.
*/