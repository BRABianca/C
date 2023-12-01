#include <stdio.h>

// Função recursiva para calcular o fatorial de um número
int calcularFatorial(int n) {
    // Caso base
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Chamada recursiva
        return n * calcularFatorial(n - 1);
    }
}

// Função principal
int main() {
    int numero;

    // Solicita ao usuário um número para calcular o fatorial
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &numero);

    // Chama a função recursiva para calcular o fatorial
    int resultado = calcularFatorial(numero);

    // Imprime o resultado
    printf("O fatorial de %d é: %d\n", numero, resultado);

    return 0;
}

/*
Recursão: A função calcularFatorial chama a si mesma para resolver um problema menor, reduzindo-o iterativamente até atingir um caso base (quando n é 0 ou 1). O caso base evita chamadas infinitas e permite que a recursão retorne resultados.

Caso Base: O caso base é crucial em funções recursivas para evitar a recursão infinita. No exemplo, o caso base é quando n é 0 ou 1, onde a função retorna 1.

Chamada Recursiva: A função calcularFatorial chama a si mesma com um argumento menor (n - 1) para resolver subproblemas.

Função Principal: A função main solicita um número ao usuário, chama a função recursiva para calcular o fatorial e imprime o resultado.
*/