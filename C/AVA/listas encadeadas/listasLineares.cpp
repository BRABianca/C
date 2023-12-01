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

// Função para remover um nó com um valor específico da lista
struct Node* remover(struct Node* cabeca, int dado) {
    struct Node* atual = cabeca;
    struct Node* anterior = NULL;

    // Caso o nó a ser removido seja o primeiro
    if (atual != NULL && atual->dado == dado) {
        cabeca = atual->proximo;
        free(atual);
        return cabeca;
    }

    // Buscar o nó a ser removido
    while (atual != NULL && atual->dado != dado) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se o nó não foi encontrado
    if (atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", dado);
        return cabeca;
    }

    // Remover o nó
    anterior->proximo = atual->proximo;
    free(atual);
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

    // Remover um elemento da lista
    int elementoRemover = 2;
    lista = remover(lista, elementoRemover);
    printf("\nLista após remover %d:\n", elementoRemover);
    imprimirLista(lista);

    // Liberar memória alocada para a lista
    liberarLista(lista);

    return 0;
}

/*
Lista Encadeada Simples: A lista encadeada simples é uma estrutura de dados na qual cada nó contém um dado e um ponteiro para o próximo nó na sequência.

Struct Node: A estrutura Node representa um nó da lista, contendo um dado e um ponteiro para o próximo nó.

Inserção e Remoção: As funções inserirInicio, inserirFinal e remover são utilizadas para manipular os elementos da lista.

Liberação de Memória: A função liberarLista é utilizada para liberar a memória alocada para todos os nós da lista.
*/