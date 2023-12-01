/*
Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:
• Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência (real, em kW) e tempo ativo por dia (real, em horas).
• Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada eletrodoméstico (consumo/consumo total) nesse período de tempo. Apresente este último dado em porcentagem.

Dica: utilize %.2f para impressão dos valores reais com duas casas decimais.
*/

#include <stdio.h>
#include <string.h>

#define MAX_ELETRODOMESTICOS 5
#define MAX_NOME 15

struct Eletrodomestico {
    char nome[MAX_NOME];
    float potencia; 
    float tempoAtivo; 
};

void lerEletrodomesticos(struct Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS]);
void calcularConsumoTotal(struct Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS], int tempoDias);

int main() {
    struct Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS];
    int tempoDias;

    lerEletrodomesticos(eletrodomesticos);

    scanf("%d", &tempoDias);

    calcularConsumoTotal(eletrodomesticos, tempoDias);

    return 0;
}

void lerEletrodomesticos(struct Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS]) {
    for (int i = 0; i < MAX_ELETRODOMESTICOS; ++i) {
        scanf(" %[^\n]", eletrodomesticos[i].nome);
        scanf("%f", &eletrodomesticos[i].potencia);
        scanf("%f", &eletrodomesticos[i].tempoAtivo);
    }
}

void calcularConsumoTotal(struct Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS], int tempoDias) {
    float consumoTotal = 0.0;

    for (int i = 0; i < MAX_ELETRODOMESTICOS; ++i) {
        consumoTotal += eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivo * tempoDias;
    }

    printf("%.2f\n", consumoTotal);

    for (int i = 0; i < MAX_ELETRODOMESTICOS; ++i) {
        float consumoRelativo = (eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivo * tempoDias / consumoTotal) * 100.0;
        printf("%.2f\n", consumoRelativo);
    }
}
