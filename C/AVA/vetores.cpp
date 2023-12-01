#include <stdio.h>

int main() {
    // Exemplo de vetor e conceitos importantes

    // Declarando um vetor de notas com tamanho 5
    float notas[5];

    // Preenchendo o vetor com notas
    printf("Informe as notas dos alunos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Calculando a média das notas
    float soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += notas[i];
    }
    float media = soma / 5;

    // Exibindo as notas e a média
    printf("\nNotas dos alunos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }
    printf("\nMédia das notas: %.2f\n", media);

    return 0;
}

/*
Declarando um vetor:
Usamos float notas[5]; para declarar um vetor chamado notas que pode armazenar 5 valores de ponto flutuante.

Preenchendo o vetor:
Utilizamos um loop for para solicitar e armazenar as notas dos alunos no vetor.
Calculando a média:

Outro loop for é usado para somar todas as notas.
A média é calculada dividindo a soma pelo número de elementos no vetor.

Exibindo as notas e a média:
Finalmente, usamos um loop for para exibir as notas individuais e a média calculada.

Lembre-se de que em C, os índices do vetor começam em 0. Portanto, para um vetor de tamanho 5, os índices válidos são 0, 1, 2, 3 e 4.
*/