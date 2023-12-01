#include <stdio.h>
#include <string.h>

#define MAX_NOME 20
#define MAX_ALUNOS 100

// Definição do tipo de registro para representar os dados de um aluno
struct tipoReg {
    char nome[MAX_NOME];
    float nota1, nota2;
    float media;
};

// Função para calcular a média de cada aluno
void mediaAluno(int n, struct tipoReg v[MAX_ALUNOS]) {
    for (int i = 0; i < n; i++) {
        // Cálculo da média ponderada com peso 1 para nota1 e peso 2 para nota2
        v[i].media = (v[i].nota1 + 2 * v[i].nota2) / 3.0;
    }
}

// Função para calcular a média geral da turma
float mediaGeral(int n, struct tipoReg v[MAX_ALUNOS]) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += v[i].media;
    }
    return soma / n; // Retorna a média da soma das médias de todos os alunos
}

// Função para buscar o índice do vetor onde se encontra o aluno com maior média
int buscaMaior(int n, struct tipoReg v[MAX_ALUNOS]) {
    int indiceMaior = 0;
    float maiorMedia = v[0].media;

    // Itera sobre os alunos a partir do segundo
    for (int i = 1; i < n; i++) {
        if (v[i].media > maiorMedia) {
            maiorMedia = v[i].media;
            indiceMaior = i;
        }
    }

    return indiceMaior; // Retorna o índice do aluno com a maior média
}

int main() {
    int n;

    // Leitura do número de alunos
    scanf("%d", &n);

    // Verifica se o número de alunos está no intervalo permitido
    if (n < 1 || n > MAX_ALUNOS) {
        printf("Número de alunos fora do intervalo.\n");
        return 1; // Encerra o programa com código de erro
    }

    struct tipoReg alunos[MAX_ALUNOS];

    // Leitura dos dados dos alunos
    for (int i = 0; i < n; i++) {
        scanf("%s %f %f", alunos[i].nome, &alunos[i].nota1, &alunos[i].nota2);
    }

    // Calcula a média de cada aluno
    mediaAluno(n, alunos);

    // Calcula a média geral da turma
    float mediaTurma = mediaGeral(n, alunos);

    // Encontra o índice do aluno com a maior média
    int indiceMaiorMedia = buscaMaior(n, alunos);

    // Imprime a média geral da turma e o nome do aluno com a maior média
    printf("%.1f\n", mediaTurma);
    printf("%s\n", alunos[indiceMaiorMedia].nome);

    return 0; // Programa finalizado com sucesso
}

/*
Struct tipoReg: Define a estrutura tipoReg para armazenar os dados de um aluno.

Funções:
    mediaAluno: Calcula a média de cada aluno com pesos diferentes para as notas.
    mediaGeral: Calcula a média geral da turma.
    buscaMaior: Encontra o índice do aluno com a maior média.

Main:
    Lê o número de alunos e seus dados.
    Chama as funções para calcular médias e encontrar o aluno com a maior média.
    Imprime a média geral da turma e o nome do aluno com a maior média.
*/