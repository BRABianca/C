#include <stdio.h>

// Função que troca os valores de duas variáveis usando ponteiros
void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função principal
int main() {
    int valor1 = 5;
    int valor2 = 10;

    printf("Valores originais: %d e %d\n", valor1, valor2);

    // Chamada da função para trocar os valores usando ponteiros
    trocarValores(&valor1, &valor2);

    printf("Valores trocados: %d e %d\n", valor1, valor2);

    return 0;
}
