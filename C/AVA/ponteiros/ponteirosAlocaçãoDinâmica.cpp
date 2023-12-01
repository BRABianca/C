#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente um array de inteiros
int* alocarArrayInteiros(int tamanho) {
    int* array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    return array;
}

// Função principal
int main() {
    int tamanhoArray;

    // Solicita ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanhoArray);

    // Aloca dinamicamente um array de inteiros
    int* meuArray = alocarArrayInteiros(tamanhoArray);

    // Inicializa o array com algum valor (exemplo: 0)
    for (int i = 0; i < tamanhoArray; i++) {
        meuArray[i] = 0;
    }

    // Imprime os valores do array
    printf("Valores do array:\n");
    for (int i = 0; i < tamanhoArray; i++) {
        printf("%d ", meuArray[i]);
    }

    // Libera a memória alocada
    free(meuArray);

    return 0;
}
