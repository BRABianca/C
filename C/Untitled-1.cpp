#include <stdio.h> // Inclusão de biblioteca padrão para entrada/saída

// Declaração de função
int soma(int a, int b) {
    return a + b;
}

int main() {
    // Declaração e inicialização de variáveis
    int x = 5;
    int y = 3;

    // Estrutura de controle condicional
    if (x > y) {
        printf("x é maior que y\n");
    } else {
        printf("x não é maior que y\n");
    }

    // Estrutura de controle de repetição
    for (int i = 0; i < 5; i++) {
        printf("Contagem: %d\n", i);
    }

    // Chamada de função e saída
    int resultado = soma(x, y);
    printf("A soma de x e y é: %d\n", resultado);

    return 0;
}
