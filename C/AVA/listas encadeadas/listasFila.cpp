#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int dado;
    struct Node* proximo;
};

// Função para imprimir os elementos da lista
void imprimirFila(struct Node* frente) {
    struct Node* atual = frente;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para enfileirar um novo elemento
struct Node* enfileirar(struct Node* frente, struct Node** tras, int dado) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = dado;
    novoNo->proximo = NULL;

    if (*tras == NULL) {
        *tras = novoNo;
        return novoNo;
    }

    (*tras)->proximo = novoNo;
    *tras = novoNo;
    return frente;
}

// Função para desenfileirar o elemento da frente
struct Node* desenfileirar(struct Node* frente, struct Node** tras) {
    if (frente == NULL) {
        printf("A fila está vazia.\n");
        return NULL;
    }

    struct Node* novaFrente = frente->proximo;
    free(frente);

    if (novaFrente == NULL) {
        *tras = NULL;
    }

    return novaFrente;
}

// Função para liberar a memória alocada para a fila
void liberarFila(struct Node* frente) {
    struct Node* atual = frente;
    struct Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    struct Node* filaFrente = NULL;
    struct Node* filaTras = NULL;

    // Enfileirar elementos
    filaFrente = enfileirar(filaFrente, &filaTras, 1);
    filaFrente = enfileirar(filaFrente, &filaTras, 2);
    filaFrente = enfileirar(filaFrente, &filaTras, 3);

    // Imprimir a fila
    printf("Fila inicial:\n");
    imprimirFila(filaFrente);

    // Desenfileirar um elemento
    printf("\nDesenfileirando...\n");
    filaFrente = desenfileirar(filaFrente, &filaTras);
    imprimirFila(filaFrente);

    // Liberar memória alocada para a fila
    liberarFila(filaFrente);

    return 0;
}

/*
Fila (FIFO): Uma fila é uma lista linear onde a inserção ocorre no final e a remoção ocorre no início.

Struct Node: A estrutura Node representa um nó da fila, contendo um dado e um ponteiro para o próximo nó.

Enfileirar e Desenfileirar: As funções enfileirar e desenfileirar são utilizadas para manipular os elementos da fila.

Liberação de Memória: A função liberarFila é utilizada para liberar a memória alocada para todos os nós da fila.
*/