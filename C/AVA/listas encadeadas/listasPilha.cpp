#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int dado;
    struct Node* proximo;
};

// Função para imprimir os elementos da lista
void imprimirPilha(struct Node* topo) {
    struct Node* atual = topo;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para empilhar um novo elemento
struct Node* empilhar(struct Node* topo, int dado) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = dado;
    novoNo->proximo = topo;
    return novoNo;
}

// Função para desempilhar o elemento do topo
struct Node* desempilhar(struct Node* topo) {
    if (topo == NULL) {
        printf("A pilha está vazia.\n");
        return NULL;
    }

    struct Node* novoTopo = topo->proximo;
    free(topo);
    return novoTopo;
}

// Função para liberar a memória alocada para a pilha
void liberarPilha(struct Node* topo) {
    struct Node* atual = topo;
    struct Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    struct Node* pilha = NULL;

    // Empilhar elementos
    pilha = empilhar(pilha, 1);
    pilha = empilhar(pilha, 2);
    pilha = empilhar(pilha, 3);

    // Imprimir a pilha
    printf("Pilha inicial:\n");
    imprimirPilha(pilha);

    // Desempilhar um elemento
    printf("\nDesempilhando...\n");
    pilha = desempilhar(pilha);
    imprimirPilha(pilha);

    // Liberar memória alocada para a pilha
    liberarPilha(pilha);

    return 0;
}

/*
Pilha (LIFO): Uma pilha é uma lista linear onde a inserção e remoção de elementos ocorrem apenas no topo.

Struct Node: A estrutura Node representa um nó da pilha, contendo um dado e um ponteiro para o próximo nó.

Empilhar e Desempilhar: As funções empilhar e desempilhar são utilizadas para manipular os elementos da pilha.

Liberação de Memória: A função liberarPilha é utilizada para liberar a memória alocada para todos os nós da pilha.
*/