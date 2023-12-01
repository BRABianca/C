/*Escreva um código que implemente uma função que remove o nó do topo da pilha e retorna a chaves deste nó. Caso a pilha esteja vazia, o usuário deve ser informado.*/

//Função recebe o ponteiro para o topo da pilha, desempilha e retorna o valor do topo*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da pilha
typedef struct Celula {
    int chave;
    struct Celula *prox;
} Celula;

// Função para desempilhar o nó do topo da pilha
int desempilhar(Celula **lst) {
    Celula *aux;
    int num;

    if (*lst == NULL) {
        printf("A pilha está vazia.\n");
        return 0;
    } else {
        num = (*lst)->chave;
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
        return num;
    }
}

int main() {
    Celula *pilha = NULL; // Inicializa a pilha como vazia

    // Empilhando alguns valores para teste
    for (int i = 1; i <= 5; i++) {
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        novo->chave = i;
        novo->prox = pilha;
        pilha = novo;
    }

    // Desempilhando e imprimindo os valores
    printf("Desempilhando:\n");
    while (1) {
        int valor = desempilhar(&pilha);
        if (valor == 0) {
            // Se a pilha estiver vazia, encerra o loop
            break;
        } else {
            printf("%d\n", valor);
        }
    }

    return 0;
}

/*Este código cria uma pilha e empilha os valores de 1 a 5. Em seguida, desempilha os valores, imprimindo-os, até que a pilha esteja vazia. Certifique-se de liberar a memória alocada dinamicamente quando não precisar mais da pilha.*/