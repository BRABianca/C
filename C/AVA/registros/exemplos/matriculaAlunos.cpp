#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_CARACTERES 30

// Estrutura para representar um aluno
struct tAluno {
    int matricula;
    char nome[MAX_CARACTERES];
    char curso[MAX_CARACTERES];
};

// Protótipos das funções
void lerAlunos(struct tAluno alunos[MAX_ALUNOS]);
void listarAlunosPorCurso(struct tAluno alunos[MAX_ALUNOS], const char curso[MAX_CARACTERES]);

int main() {
    struct tAluno alunos[MAX_ALUNOS];
    char curso[MAX_CARACTERES];

    // Leitura dos dados dos alunos
    lerAlunos(alunos);

    // Leitura do curso e listagem dos alunos do curso
    printf("Digite o nome do curso: ");
    scanf(" %[^\n]", curso);

    listarAlunosPorCurso(alunos, curso);

    return 0;
}

void lerAlunos(struct tAluno alunos[MAX_ALUNOS]) {
    printf("Entre com os dados dos alunos:\n");

    for (int i = 0; i < MAX_ALUNOS; ++i) {
        scanf("%d", &alunos[i].matricula);
        scanf(" %[^\n]", alunos[i].nome);
        scanf(" %[^\n]", alunos[i].curso);
    }
}

void listarAlunosPorCurso(struct tAluno alunos[MAX_ALUNOS], const char curso[MAX_CARACTERES]) {
    printf("Alunos do curso %s:\n", curso);

    for (int i = 0; i < MAX_ALUNOS; ++i) {
        if (strcmp(alunos[i].curso, curso) == 0) {
            printf("%d %s\n", alunos[i].matricula, alunos[i].nome);
        }
    }
}

/*
#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_CARACTERES 30

struct tAluno {
    int matricula;
    char nome[MAX_CARACTERES];
    char curso[MAX_CARACTERES];
};

void lerAlunos(struct tAluno alunos[MAX_ALUNOS]);
void listarAlunosPorCurso(struct tAluno alunos[MAX_ALUNOS], const char curso[MAX_CARACTERES]);

int main() {
    struct tAluno alunos[MAX_ALUNOS];
    char curso[MAX_CARACTERES];

    lerAlunos(alunos);

    scanf(" %[^\n]", curso);

    listarAlunosPorCurso(alunos, curso);

    return 0;
}

void lerAlunos(struct tAluno alunos[MAX_ALUNOS]) {
    for (int i = 0; i < MAX_ALUNOS; ++i) {
        scanf("%d", &alunos[i].matricula);
        scanf(" %[^\n]", alunos[i].nome);
        scanf(" %[^\n]", alunos[i].curso);
    }
}

void listarAlunosPorCurso(struct tAluno alunos[MAX_ALUNOS], const char curso[MAX_CARACTERES]) {
    for (int i = 0; i < MAX_ALUNOS; ++i) {
        if (strcmp(alunos[i].curso, curso) == 0) {
            printf("%d %s\n", alunos[i].matricula, alunos[i].nome);
        }
    }
}
*/