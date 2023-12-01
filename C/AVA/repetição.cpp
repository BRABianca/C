#include <stdio.h>

int main() {
    // Exemplo de loop for
    printf("Exemplo de loop for:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // Exemplo de loop while
    printf("Exemplo de loop while:\n");
    int j = 1;
    while (j <= 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n\n");

    // Exemplo de loop do-while
    printf("Exemplo de loop do-while:\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);

    return 0;
}
/*
Neste exemplo, são apresentados três tipos de loops:

Loop for:

Inicia uma variável i em 1.
Executa enquanto i for menor ou igual a 5.
Incrementa i a cada iteração.
Loop while:

Inicia uma variável j em 1.
Executa enquanto j for menor ou igual a 5.
Incrementa j a cada iteração.
Loop do-while:

Inicia uma variável k em 1.
Executa o bloco de código pelo menos uma vez e, em seguida, continua enquanto k for menor ou igual a 5.
Incrementa k a cada iteração.
*/