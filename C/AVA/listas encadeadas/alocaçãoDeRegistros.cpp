#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int dado;
    struct Node* proximo;
};

// Função para imprimir os elementos da lista
void imprimirLista(struct Node* cabeca) {
    struct Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
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
    novoNo->proximo = cabeca;
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
        return novoNo;
    }

    struct Node* atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novoNo;
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
Alocação Dinâmica: A função malloc é utilizada para alocar dinamicamente memória para um novo nó da lista. É importante verificar se a alocação foi bem-sucedida.

Struct Node: A estrutura Node representa um nó da lista, contendo um dado e um ponteiro para o próximo nó.

Inserção: As funções inserirInicio e inserirFinal adicionam um novo nó no início e no final da lista, respectivamente.

Liberação de Memória: A função liberarLista libera a memória alocada para todos os nós da lista.
*/