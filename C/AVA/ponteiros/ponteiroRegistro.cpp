#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do registro
struct Registro {
    int codigo;
    char nome[50];
    float preco;
};

// Função para alocar dinamicamente um registro
struct Registro* alocarRegistro() {
    struct Registro* reg = (struct Registro*)malloc(sizeof(struct Registro));
    if (reg == NULL) {
        printf("Erro na alocação de memória para o registro.\n");
        exit(EXIT_FAILURE);
    }
    return reg;
}

// Função para preencher um registro com valores
void preencherRegistro(struct Registro* reg, int codigo, const char* nome, float preco) {
    reg->codigo = codigo;
    strncpy(reg->nome, nome, sizeof(reg->nome));
    reg->preco = preco;
}

// Função para imprimir um registro
void imprimirRegistro(const struct Registro* reg) {
    printf("Código: %d\n", reg->codigo);
    printf("Nome: %s\n", reg->nome);
    printf("Preço: %.2f\n", reg->preco);
}

int main() {
    // Alocar dinamicamente um registro
    struct Registro* meuRegistro = alocarRegistro();

    // Preencher o registro com valores
    preencherRegistro(meuRegistro, 1, "Produto A", 29.99);

    // Imprimir o registro
    imprimirRegistro(meuRegistro);

    // Liberar a memória alocada
    free(meuRegistro);

    return 0;
}

/*
Ponteiro para Registro: A função alocarRegistro retorna um ponteiro para um registro, que é utilizado para armazenar um registro alocado dinamicamente.

Alocação Dinâmica: A função alocarRegistro ilustra como alocar dinamicamente memória para um registro.

Manipulação de Registros: As funções preencherRegistro e imprimirRegistro mostram como preencher e imprimir os campos de um registro usando ponteiros.

Liberação de Memória: O código mostra como liberar a memória alocada dinamicamente usando free.
*/