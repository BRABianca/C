/*
Faça um programa para simular uma agenda de compromissos e:
 • Crie e leia um vetor de 5 estruturas de dados com: compromisso (máximo 60 letras) e data, nesta ordem. A data deve ser outra estrutura de dados contendo dia, mês e ano. 
• Leia dois inteiros M e A e mostre todos os compromissos do mês M do ano A. Repita o procedimento até ler M = 0.
Dica: utilize  scanf("%d/%d/%d", &variavel_dia, &variavel_mes, &variavel_ano); para leitura formatada da data.

*/
#include <stdio.h>
#include <string.h>

#define MAX_COMPROMISSOS 5
#define MAX_CARACTERES 60

// Estrutura para representar a data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Estrutura para representar um compromisso
struct Compromisso {
    char descricao[MAX_CARACTERES];
    struct Data data;
};

// Protótipo das funções
void lerCompromissos(struct Compromisso compromissos[MAX_COMPROMISSOS]);
void mostrarCompromissosDoMes(struct Compromisso compromissos[MAX_COMPROMISSOS], int mes, int ano);

int main() {
    struct Compromisso compromissos[MAX_COMPROMISSOS];
    int mes, ano;

    // Leitura dos compromissos
    lerCompromissos(compromissos);

    // Leitura e exibição dos compromissos para o mês e ano especificados
    do {
        printf("\nDigite o mês e o ano (M/A): ");
        scanf("%d/%d", &mes, &ano);

        if (mes != 0) {
            mostrarCompromissosDoMes(compromissos, mes, ano);
        }
    } while (mes != 0);

    return 0;
}

void lerCompromissos(struct Compromisso compromissos[MAX_COMPROMISSOS]) {
    printf("Entre com os compromissos:\n");

    for (int i = 0; i < MAX_COMPROMISSOS; ++i) {
        printf("Compromisso %d:\n", i + 1);

        // Leitura da descrição do compromisso
        scanf(" %[^\n]", compromissos[i].descricao);

        // Leitura da data do compromisso
        scanf("%d/%d/%d", &compromissos[i].data.dia, &compromissos[i].data.mes, &compromissos[i].data.ano);
    }
}

void mostrarCompromissosDoMes(struct Compromisso compromissos[MAX_COMPROMISSOS], int mes, int ano) {
    printf("Compromissos para o mês %d do ano %d:\n", mes, ano);

    for (int i = 0; i < MAX_COMPROMISSOS; ++i) {
        if (compromissos[i].data.mes == mes && compromissos[i].data.ano == ano) {
            printf("%s\n", compromissos[i].descricao);
        }
    }
}
/*
Resposta no AVA:

#include <stdio.h>
#include <string.h>

#define MAX_COMPROMISSOS 5
#define MAX_CARACTERES 60

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    char descricao[MAX_CARACTERES];
    struct Data data;
};

void lerCompromissos(struct Compromisso compromissos[MAX_COMPROMISSOS]);
void mostrarCompromissosDoMes(struct Compromisso compromissos[MAX_COMPROMISSOS], int mes, int ano);

int main() {
    struct Compromisso compromissos[MAX_COMPROMISSOS];
    int mes, ano;

    lerCompromissos(compromissos);

    do {
        scanf("%d/%d", &mes, &ano);
        if (mes != 0) {
            mostrarCompromissosDoMes(compromissos, mes, ano);
        }
    } while (mes != 0);

    return 0;
}

void lerCompromissos(struct Compromisso compromissos[MAX_COMPROMISSOS]) {
    for (int i = 0; i < MAX_COMPROMISSOS; ++i) {
        scanf(" %[^\n]", compromissos[i].descricao);
        scanf("%d/%d/%d", &compromissos[i].data.dia, &compromissos[i].data.mes, &compromissos[i].data.ano);
    }
}

void mostrarCompromissosDoMes(struct Compromisso compromissos[MAX_COMPROMISSOS], int mes, int ano) {
    for (int i = 0; i < MAX_COMPROMISSOS; ++i) {
        if (compromissos[i].data.mes == mes && compromissos[i].data.ano == ano) {
            printf("%s\n", compromissos[i].descricao);
        }
    }
}

*/