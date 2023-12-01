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
    struct Pessoa pessoas[100]; // Supondo um limite de 100 pessoas
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
Este exemplo em C utiliza estruturas (struct) para representar uma pessoa e um registro de pessoas. Funções são usadas para adicionar pessoas ao registro e mostrar as pessoas registradas. Note que este é um exemplo simples e pode precisar ser adaptado conforme necessário para atender aos requisitos específicos do seu projeto.
*/