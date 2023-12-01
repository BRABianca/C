/* Seja uma lista linear sem cabeça duplamente encadeada com seus campos chaves ordenados em ordem crescente. Escreva um programa em C que apresente um menu ao usuário com as seguintes operações: Insere(); Imprime(); Remove(); Libera(). As operações de inserção e remoção
devem considerar o fato da lista ser ordenada (crescente), ou seja, ao se inserir um elemento, este já deve ser colocado na posição correta, para que a lista continue ordenada; ao se buscar um elemento
para realizar a remoção, deve-se interromper a busca assim que não houver mais chances do elemento buscado estar na lista.
*/

//Descrição:
//Código para realização de operações sobre listas duplamente encaeadas com ordenação dos valores das chaves

//inclusão das bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>

// Definição do tipo nó que representa uma célula da lista
typedef struct no {
    int chave;
    struct no *ant;
    struct no *prox;
} celula;

// Protótipo das Funções
void Insere(int x, celula **L);
void Remove(int x, celula **L);
void Imprime(celula *L);
void Libera(celula **L);
int Menu();

// Função Principal
int main() {
    celula *L = NULL;
    int x, op;

    do {
        op = Menu();

        if (op == 1) {
            // Elemento a ser inserido
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &x);
            Insere(x, &L);
        } else if (op == 2) {
            // Elemento a ser removido
            if (L == NULL)
                printf("Lista Vazia\n");
            else {
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &x);
                Remove(x, &L);
            }
        } else if (op == 3) {
            // Imprime a lista armazenada
            if (L == NULL)
                printf("Lista Vazia\n");
            else {
                printf("Lista Armazenada: ");
                Imprime(L);
            }
        } else if (op == 4) {
            Libera(&L);
            printf("Lista Liberada\n");
        }
    } while (op != 5);

    return 0;
}

// Implementação das Funções

// Menu de opções
int Menu() {
    int op;

    do {
        printf("\nDigite a opção correspondente a operação desejada:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Liberar\n");
        printf("5 - Sair\n");
        scanf("%d", &op);
    } while (op < 1 || op > 5);

    return op;
}

// Insere o elemento x na lista ordenada (a inserção deve ser tal que a lista resultante continue ordenada)
void Insere(int x, celula **L) {
    celula *novo, *p;
    novo = (celula *)malloc(sizeof(celula));
    novo->prox = NULL;
    novo->ant = NULL;
    novo->chave = x;

    // Caso a lista esteja vazia
    if (*L == NULL)
        *L = novo;
    else {
        // Ponteiro auxiliar para o percurso na lista
        p = *L;

        // Encontra a posição de inserção
        while (p->prox != NULL && p->chave <= x)
            p = p->prox;

        // INSERE NO FINAL
        if (p->prox == NULL && p->chave <= x) {
            novo->ant = p;
            p->prox = novo;
        }
        // INSERE NO INÍCIO
        else if (p == *L && p->chave > x) {
            novo->prox = p;
            p->ant = novo;
            *L = novo;
        }
        // INSERE NO MEIO
        else {
            // Insere antes do nó apontado por p
            novo->ant = p->ant;
            novo->prox = p;
            p->ant->prox = novo;
            p->ant = novo;
        }
    }
}

// Remove o nó da lista cuja chave é igual ao inteiro x
void Remove(int x, celula **L) {
    celula *p;

    p = *L;
    while (p != NULL && p->chave != x)
        p = p->prox;

    if (p == NULL)
        printf("Elemento %d não existe na lista.\n", x);
    else {
        // Se o elemento a ser removido é o primeiro
        if (p->ant == NULL) {
            *L = p->prox;
            if (*L != NULL)
                (*L)->ant = NULL;
        }
        // Se o elemento a ser removido está no meio ou no final
        else {
            p->ant->prox = p->prox;
            if (p->prox != NULL)
                p->prox->ant = p->ant;
        }

        printf("Elemento removido: %d\n", p->chave);
        free(p);
    }
}

// Imprime os valores das chaves dos nós da lista
void Imprime(celula *L) {
    celula *p;

    p = L;

    while (p != NULL) {
        printf("%d ", p->chave);
        p = p->prox;
    }
    printf("\n");
}

// Desloca a memória ocupada pelos nós da lista
void Libera(celula **L) {
    celula *aux;

    while (*L != NULL) {
        aux = *L;
        *L = (*L)->prox;
        free(aux);
    }
}
