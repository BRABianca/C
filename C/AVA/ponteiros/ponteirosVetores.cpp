#include <stdio.h>

// Função para preencher um vetor com valores
void preencherVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Preencha o vetor com os valores desejados
        vetor[i] = i * 2;
    }
}

// Função para imprimir os elementos de um vetor
void imprimirVetor(const int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    const int tamanhoVetor = 5;
    int meuVetor[tamanhoVetor];

    // Preencher o vetor usando a função e ponteiro
    preencherVetor(meuVetor, tamanhoVetor);

    // Imprimir o vetor usando a função e ponteiro
    imprimirVetor(meuVetor, tamanhoVetor);

    return 0;
}

/*
Ponteiro para Vetor: A função preencherVetor recebe um ponteiro para um vetor, permitindo que ela modifique diretamente os elementos do vetor.

Parâmetros de Função: Observe como os parâmetros são passados por referência usando ponteiros.

Impressão de Vetor: A função imprimirVetor recebe um ponteiro para um vetor e imprime seus elementos.

Iteração sobre Vetor: A iteração sobre o vetor é feita usando um loop for para preenchê-lo e imprimi-lo.

Tamanho do Vetor: O tamanho do vetor é declarado como uma constante, mas você pode ajustá-lo conforme necessário.
*/