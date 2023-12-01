#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    char email[50];
};

// Definindo a estrutura RegistroPessoas
struct RegistroPessoas {
    struct Pessoa pessoas[100]; // Vetor de estruturas para armazenar as pessoas
    int contador; // Contador de pessoas registradas
};

// Função para adicionar uma pessoa ao registro
void adicionarPessoa(struct RegistroPessoas *registro, const char *nome, int idade, const char *email) {
    if (registro->contador < 100) { // Verifica se há espaço no registro
        struct Pessoa novaPessoa;
        snprintf(novaPessoa.nome, sizeof(novaPessoa.nome), "%s", nome);
        novaPessoa.idade = idade;
        snprintf(novaPessoa.email, sizeof(novaPessoa.email), "%s", email);

        registro->pessoas[registro->contador++] = novaPessoa;
        printf("Pessoa adicionada com sucesso!\n");
    } else {
        printf("O registro está cheio. Não é possível adicionar mais pessoas.\n");
    }
}

// Função para mostrar todas as pessoas registradas
void mostrarPessoas(const struct RegistroPessoas *registro) {
    printf("Pessoas registradas:\n");
    for (int i = 0; i < registro->contador; ++i) {
        printf("Nome: %s, Idade: %d, Email: %s\n", registro->pessoas[i].nome, registro->pessoas[i].idade, registro->pessoas[i].email);
    }
}

// Função principal
int main() {
    struct RegistroPessoas registro;
    registro.contador = 0; // Inicializa o contador

    // Exemplo de adição de pessoas
    adicionarPessoa(&registro, "Alice", 25, "alice@email.com");
    adicionarPessoa(&registro, "Bob", 30, "bob@email.com");

    // Exemplo de exibição de pessoas registradas
    mostrarPessoas(&registro);

    return 0;
}

/*
Conceitos Importantes:

Estruturas (struct): As estruturas são usadas para agrupar diferentes tipos de dados sob um único nome. No exemplo acima, struct Pessoa e struct RegistroPessoas são usadas para representar uma pessoa individual e um registro de pessoas, respectivamente.

Vetores (pessoas): Vetores são usados para armazenar múltiplos elementos do mesmo tipo em uma única variável. No exemplo, struct Pessoa pessoas[100] é um vetor que pode armazenar até 100 pessoas no registro.

Matrizes (não presente neste exemplo): Matrizes são semelhantes a vetores, mas têm duas dimensões. Você pode considerar uma matriz como um vetor de vetores. Se cada pessoa tivesse mais informações associadas (além de nome, idade e e-mail), poderíamos usar uma matriz para armazenar essas informações adicionais.

Contadores: O uso de contadores, como contador no exemplo, é comum para controlar o número de elementos em um vetor. Isso ajuda a evitar acessar posições de memória inválidas e a controlar a quantidade de espaço ocupado no vetor.

Funções: Funções são usadas para organizar o código e realizar tarefas específicas. No exemplo, adicionarPessoa e mostrarPessoas são funções que adicionam pessoas ao registro e exibem as pessoas registradas, respectivamente.
*/