#include <stdio.h>
#include <stdlib.h>

// Função para intercalar dois subarrays de array[]
void merge(int array[], int inicio, int meio, int fim) {
    int i, j, k;
    int tamanho1 = meio - inicio + 1;
    int tamanho2 = fim - meio;

    // Criação de arrays temporários
    int* subarrayEsquerdo = (int*)malloc(tamanho1 * sizeof(int));
    int* subarrayDireito = (int*)malloc(tamanho2 * sizeof(int));

    // Copia os dados para os arrays temporários subarrayEsquerdo[] e subarrayDireito[]
    for (i = 0; i < tamanho1; i++)
        subarrayEsquerdo[i] = array[inicio + i];
    for (j = 0; j < tamanho2; j++)
        subarrayDireito[j] = array[meio + 1 + j];

    // Intercale os arrays temporários de volta para array[]
    i = 0;
    j = 0;
    k = inicio;
    while (i < tamanho1 && j < tamanho2) {
        if (subarrayEsquerdo[i] <= subarrayDireito[j]) {
            array[k] = subarrayEsquerdo[i];
            i++;
        } else {
            array[k] = subarrayDireito[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes de subarrayEsquerdo[], se houver algum
    while (i < tamanho1) {
        array[k] = subarrayEsquerdo[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de subarrayDireito[], se houver algum
    while (j < tamanho2) {
        array[k] = subarrayDireito[j];
        j++;
        k++;
    }

    // Liberar memória dos arrays temporários
    free(subarrayEsquerdo);
    free(subarrayDireito);
}

// Função principal do mergesort que ordena array[l..r] usando merge()
void mergesort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontrar o ponto médio do array
        int meio = inicio + (fim - inicio) / 2;

        // Ordenar as duas metades do array
        mergesort(array, inicio, meio);
        mergesort(array, meio + 1, fim);

        // Intercalar as duas metades ordenadas
        merge(array, inicio, meio, fim);
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
    printf("Array antes do mergesort:\n");
    imprimirArray(meuArray, tamanhoArray);

    // Chamar o algoritmo de ordenação mergesort
    mergesort(meuArray, 0, tamanhoArray - 1);

    // Imprimir array ordenado
    printf("Array após o mergesort:\n");
    imprimirArray(meuArray, tamanhoArray);

    return 0;
}

/*
Mergesort: O algoritmo Mergesort é baseado na divisão e conquista. Ele divide o array em duas metades, recursivamente ordena as metades e, em seguida, combina as duas metades ordenadas para obter o array final ordenado.

Função Merge: A função merge é responsável por intercalar dois subarrays ordenados em um array único.

Chamadas Recursivas: A função principal, mergesort, realiza chamadas recursivas para ordenar as duas metades do array.

Alocação Dinâmica: Alocamos dinamicamente memória para os arrays temporários subarrayEsquerdo e subarrayDireito na função merge e liberamos a memória no final.
*/