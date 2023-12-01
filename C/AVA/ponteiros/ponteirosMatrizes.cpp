#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente uma matriz
int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro na alocação de memória para as linhas da matriz.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória para as colunas da matriz.\n");
            exit(EXIT_FAILURE);
        }
    }

    return matriz;
}

// Função para preencher uma matriz com valores
void preencherMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Preencha a matriz com os valores desejados
            matriz[i][j] = i * colunas + j;
        }
    }
}

// Função para imprimir os elementos de uma matriz
void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada para a matriz
void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    const int linhas = 3;
    const int colunas = 4;

    // Alocar dinamicamente uma matriz
    int** minhaMatriz = alocarMatriz(linhas, colunas);

    // Preencher a matriz usando a função e ponteiro
    preencherMatriz(minhaMatriz, linhas, colunas);

    // Imprimir a matriz usando a função e ponteiro
    imprimirMatriz(minhaMatriz, linhas, colunas);

    // Liberar a memória alocada para a matriz
    liberarMatriz(minhaMatriz, linhas);

    return 0;
}
 /*
 Ponteiro para Matriz: A função alocarMatriz retorna um ponteiro para ponteiro (ou ponteiro duplo), que é utilizado para armazenar uma matriz alocada dinamicamente.

Alocação Dinâmica: As funções alocarMatriz e liberarMatriz ilustram como alocar e liberar memória para uma matriz.

Preenchimento e Impressão: As funções preencherMatriz e imprimirMatriz mostram como preencher e imprimir os elementos de uma matriz usando ponteiros.

Desalocação de Memória: A função liberarMatriz é responsável por liberar a memória alocada para a matriz.
 */