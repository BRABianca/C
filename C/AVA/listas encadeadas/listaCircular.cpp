#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista circular
struct Node {
    int dado;
    struct Node* proximo;
};

// Função para imprimir os elementos da lista
void imprimirLista(struct Node* cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    struct Node* atual = cabeca;
    do {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    } while (atual != cabeca);

    printf("(Inicio)\n");
}

// Função para inserir um novo nó no início da lista circular
struct Node* inserirInicio(struct Node* cabeca, int dado) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = dado;

    if (cabeca == NULL) {
        novoNo->proximo = novoNo;  // Lista está vazia, aponta para si mesmo
        return novoNo;
    }

    struct Node* ultimo = cabeca;
    while (ultimo->proximo != cabeca) {
        ultimo = ultimo->proximo;
    }

    novoNo->proximo = cabeca;
    cabeca = novoNo;
    ultimo->proximo = novoNo;

    return cabeca;
}

// Função para liberar a memória alocada para a lista circular
void liberarLista(struct Node* cabeca) {
    if (cabeca == NULL) {
        return;
    }

    struct Node* atual = cabeca;
    struct Node* proximo = NULL;

    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != cabeca);
}

int main() {
    struct Node* listaCircular = NULL;

    // Inserir elementos na lista circular
    listaCircular = inserirInicio(listaCircular, 3);
    listaCircular = inserirInicio(listaCircular, 2);
    listaCircular = inserirInicio(listaCircular, 1);

    // Imprimir a lista circular
    printf("Lista circular inicial:\n");
    imprimirLista(listaCircular);

    // Liberar memória alocada para a lista circular
    liberarLista(listaCircular);

    return 0;
}

/*
Lista Circular: Em uma lista circular, o último nó aponta de volta para o primeiro nó, formando um ciclo.

Struct Node: A estrutura Node representa um nó da lista circular, contendo um dado e um ponteiro para o próximo nó.

Inserção no Início: A função inserirInicio é utilizada para adicionar um novo nó no início da lista circular.

Liberação de Memória: A função liberarLista é utilizada para liberar a memória alocada para todos os nós da lista circular.
*/