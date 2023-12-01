#include <stdio.h>

// Função para calcular o comprimento de uma string
size_t meu_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Função para converter uma string para maiúsculas
void meu_strupr(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

int main() {
    // Exemplo de strings usando apenas stdio.h

    // Declarando uma string para armazenar o nome
    char nome[100];

    // Solicitando ao usuário que insira seu nome
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    // Removendo o caractere de nova linha do final da string
    size_t len = meu_strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }

    // Exibindo o comprimento do nome
    printf("O comprimento do seu nome é: %lu\n", len);

    // Exibindo o nome em maiúsculas
    meu_strupr(nome);
    printf("Seu nome em maiúsculas é: %s\n", nome);

    return 0;
}
