#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para alocar dinamicamente uma string
char* alocarString(int tamanho) {
    char* str = (char*)malloc(tamanho * sizeof(char));
    if (str == NULL) {
        printf("Erro na alocação de memória para a string.\n");
        exit(EXIT_FAILURE);
    }
    return str;
}

// Função para copiar uma string para outra
void copiarString(char *destino, const char *origem) {
    strcpy(destino, origem);
}

// Função para concatenar duas strings
char* concatenarStrings(const char *str1, const char *str2) {
    char *resultado = alocarString(strlen(str1) + strlen(str2) + 1);
    strcpy(resultado, str1);
    strcat(resultado, str2);
    return resultado;
}

int main() {
    // Exemplo de string literal
    const char *saudacao = "Olá, ";

    // Alocar dinamicamente uma string
    char *nome = alocarString(20);

    // Ler uma string do usuário
    printf("Digite seu nome: ");
    scanf("%s", nome);

    // Copiar strings
    char *mensagem = alocarString(50);
    copiarString(mensagem, saudacao);

    // Concatenar strings
    char *mensagemFinal = concatenarStrings(mensagem, nome);

    // Imprimir a mensagem final
    printf("%s\n", mensagemFinal);

    // Liberar a memória alocada
    free(nome);
    free(mensagem);
    free(mensagemFinal);

    return 0;
}
/*
Ponteiro para String: A função alocarString retorna um ponteiro para caractere, que é usado para armazenar uma string alocada dinamicamente.

Alocação Dinâmica: A função alocarString ilustra como alocar dinamicamente memória para uma string.

Manipulação de Strings: As funções copiarString e concatenarStrings demonstram a manipulação de strings usando ponteiros.

Liberação de Memória: O código mostra como liberar a memória alocada dinamicamente usando free.
*/