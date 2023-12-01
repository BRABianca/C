#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente um array de inteiros
int* alocarArrayInteiros(int tamanho) {
    int* array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocação de memória para o array de inteiros.\n");
        exit(EXIT_FAILURE);
    }
    return array;
}

// Função para preencher um array de inteiros com valores
void preencherArrayInteiros(int* array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Preencha o array com os valores desejados
        array[i] = i * 2;
    }
}

// Função para imprimir os elementos de um array de inteiros
void imprimirArrayInteiros(const int* array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    const int tamanhoArray = 5;

    // Alocar dinamicamente um array de inteiros
    int* meuArray = alocarArrayInteiros(tamanhoArray);

    // Preencher o array usando a função e ponteiro
    preencherArrayInteiros(meuArray, tamanhoArray);

    // Imprimir o array usando a função e ponteiro
    imprimirArrayInteiros(meuArray, tamanhoArray);

    // Liberar a memória alocada
    free(meuArray);

    return 0;
}

/*
Alocação Dinâmica: A função alocarArrayInteiros ilustra como alocar dinamicamente memória para um array de inteiros.

Preenchimento e Impressão: As funções preencherArrayInteiros e imprimirArrayInteiros demonstram como preencher e imprimir os elementos de um array usando ponteiros.

Liberação de Memória: O código mostra como liberar a memória alocada dinamicamente usando free.*/