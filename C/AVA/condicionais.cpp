#include <stdio.h>

int main() {
    // Variáveis
    int idade;
    char possuiCarteira;

    // Entrada de dados
    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    // Limpa o buffer do teclado
    fflush(stdin);

    printf("Você possui carteira de motorista? (S/N): ");
    scanf("%c", &possuiCarteira);

    // Condições
    if (idade < 18) {
        printf("Você é menor de idade.\n");
    } else if (idade >= 18 && possuiCarteira == 'N') {
        printf("Você é maior de idade, mas não possui carteira de motorista.\n");
    } else if (idade >= 18 && possuiCarteira == 'S') {
        printf("Você é maior de idade e possui carteira de motorista.\n");
    } else {
        printf("Entrada inválida.\n");
    }

    return 0;
}
