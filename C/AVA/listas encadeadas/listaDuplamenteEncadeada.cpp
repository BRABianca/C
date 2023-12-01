#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
struct Node {
    int dado;
    struct Node* proximo;
    struct Node* anterior;
};

// Função para imprimir os elementos da lista
void imprimirLista(struct Node* cabeca) {
    struct Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d <-> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para inserir um novo nó no início da lista
struct Node* inserirInicio(struct Node* cabeca, int dado) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = dado;
    novoNo->anterior = NULL;
    novoNo->proximo = cabeca;

    if (cabeca != NULL) {
        cabeca->anterior = novoNo;
    }

    return novoNo;
}

// Função para inserir um novo nó no final da lista
struct Node* inserirFinal(struct Node* cabeca, int dado) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = dado;
    novoNo->proximo = NULL;

    if (cabeca == NULL) {
        novoNo->anterior = NULL;
        return novoNo;
    }

    struct Node* atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novoNo;
    novoNo->anterior = atual;

    return cabeca;
}

// Função para liberar a memória alocada para a lista
void liberarLista(struct Node* cabeca) {
    struct Node* atual = cabeca;
    struct Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    struct Node* lista = NULL;

    // Inserir elementos na lista
    lista = inserirInicio(lista, 3);
    lista = inserirInicio(lista, 2);
    lista = inserirInicio(lista, 1);
    lista = inserirFinal(lista, 4);
    lista = inserirFinal(lista, 5);

    // Imprimir a lista
    printf("Lista inicial:\n");
    imprimirLista(lista);

    // Liberar memória alocada para a lista
    liberarLista(lista);

    return 0;
}

/*
Lista Duplamente Encadeada: Em uma lista duplamente encadeada, cada nó possui dois ponteiros, um apontando para o próximo nó e outro para o nó anterior.

Struct Node: A estrutura Node representa um nó da lista duplamente encadeada, contendo um dado e ponteiros para o próximo e anterior.

Inserção no Início e no Final: As funções inserirInicio e inserirFinal são utilizadas para adicionar novos nós no início e no final da lista, respectivamente.

Liberação de Memória: A função liberarLista é utilizada para liberar a memória alocada para todos os nós da lista.
*/