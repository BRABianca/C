#include <stdio.h>

int main() {
    // Exemplo de matriz e conceitos importantes

    // Declarando uma matriz de notas com 3 alunos e 4 disciplinas
    float notas[3][4];

    // Preenchendo a matriz com notas
    printf("Informe as notas dos alunos em cada disciplina:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Nota do aluno %d na disciplina %d: ", i + 1, j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Exibindo as notas da matriz
    printf("\nNotas dos alunos em cada disciplina:\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: ", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%.2f  ", notas[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Declarando uma matriz:
Usamos float notas[3][4]; para declarar uma matriz chamada notas que tem 3 linhas (alunos) e 4 colunas (disciplinas).

Preenchendo a matriz:
Utilizamos dois loops aninhados (for) para solicitar e armazenar as notas dos alunos em cada disciplina.

Exibindo as notas da matriz:
Utilizamos dois loops aninhados (for) para percorrer e exibir as notas dos alunos em cada disciplina.

Lembre-se de que, em C, os índices de uma matriz também começam em 0. Assim, para uma matriz de 3x4, os índices válidos vão de 0 a 2 para as linhas e de 0 a 3 para as colunas.


*/