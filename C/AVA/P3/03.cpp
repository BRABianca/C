/*Escreva um código que implemente uma função que, dada uma lista circular cujo o ponteiro para o có cursos é 'pt_cursos', realize a inserção de um novo elemento cuja chave é x na posição imediatamente anterior ao cursor, caso este elemento ainda não exista na lista.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
typedef struct no {
    int chave;
    struct no *prox;
} celula;

// Função para inserir um novo elemento antes do cursor
void Insere(int x, celula **L); 
void Imprime(celula *L);

// Função principal
int main(){
    celula *pt_cursor = NULL;
    int i, n = 10;

    // Loop para inserir elementos na lista
    for(i = 1; i <= n; i++)
        Insere(i, &pt_cursor);
    
    // Imprime a lista circular
    Imprime(pt_cursor);

    return 0;
}

// Função para inserir um novo elemento antes do cursor
void Insere(int x, celula **L){
    celula *pt_aux = *L;
    celula *novo;

    // Se a lista estiver vazia
    if(*L == NULL){
        novo = (celula*) malloc(sizeof(celula));
        novo->chave = x;
        novo->prox = novo;
        *L = novo;
    } else {
        // Avança na lista até descobrir se já existe um elemento com chave x ou até chegar ao final
        while(pt_aux->prox != *L && pt_aux->chave != x)
            pt_aux = pt_aux->prox;

        // Se não encontrou um elemento com chave x, insere o novo elemento antes do cursor
        if(pt_aux->chave != x){
            novo = (celula*) malloc(sizeof(celula));
            novo->chave = x;
            novo->prox = *L;
            pt_aux->prox = novo;
        }
    }
}

// Função para imprimir os elementos da lista circular
void Imprime(celula *L){
    celula *aux = L;

    // Loop para percorrer a lista circular e imprimir os elementos
    do{
        printf("%d ", aux->chave);
        aux = aux->prox;
    } while(aux != L);

    printf("\n");
}

/*Agora, com os comentários, o código está mais explicativo:

celula: Define a estrutura de um nó da lista.

Insere: Função para inserir um novo elemento antes do cursor na lista circular.

Imprime: Função para imprimir os elementos da lista circular.

main: Função principal que cria uma lista 

circular inserindo elementos de 1 a 10 e imprime a lista resultante.
*/