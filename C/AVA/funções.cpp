#include <stdio.h>

// Função para calcular a média de um conjunto de notas
float calcularMedia(float notas[], int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }

    return soma / tamanho;
}

// Função para determinar o status de aprovação com base na média
void verificarAprovacao(float media) {
    if (media >= 6.0) {
        printf("Aprovado! Parabéns!\n");
    } else {
        printf("Reprovado. Estude mais para a próxima!\n");
    }
}

int main() {
    // Exemplo de funções e conceitos importantes

    // Declarando um vetor para armazenar as notas
    float notas[3];

    // Preenchendo o vetor com notas
    printf("Informe as notas do aluno:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Calculando a média usando a função calcularMedia
    float media = calcularMedia(notas, 3);

    // Exibindo a média
    printf("A média do aluno é: %.2f\n", media);

    // Verificando o status de aprovação usando a função verificarAprovacao
    verificarAprovacao(media);

    return 0;
}

/*
Função calcularMedia:
Aceita um vetor de notas e seu tamanho como argumentos.
Calcula a média das notas e a retorna.

Função verificarAprovacao:
Aceita a média como argumento.
Imprime uma mensagem indicando se o aluno foi aprovado ou reprovado com base na média.

Função main:
Declara um vetor para armazenar as notas do aluno.
Preenche o vetor com notas inseridas pelo usuário.
Chama a função calcularMedia para calcular a média.
Exibe a média.
Chama a função verificarAprovacao para verificar o status de aprovação.
*/