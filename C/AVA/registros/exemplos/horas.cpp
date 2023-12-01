/*
Dados dois horários de um mesmo dia, expressos no formato hh:mm:ss, calcule o tempo decorrido entre estes dois horários, apresentando o resultado no mesmo formato hh:mm:ss. 

Exemplo: 

                 Se os dois horários fornecidos são 07:13:22 e 13:05:56, a resposta tem de ser 05:52:34.
*/
#include <stdio.h>

// Estrutura para representar um horário
struct Horario {
    int horas;
    int minutos;
    int segundos;
};

// Função para calcular o tempo decorrido entre dois horários
struct Horario calcularTempoDecorrido(struct Horario inicio, struct Horario fim);

int main() {
    struct Horario inicio, fim, resultado;

    // Leitura dos horários
    scanf("%d:%d:%d", &inicio.horas, &inicio.minutos, &inicio.segundos);
    scanf("%d:%d:%d", &fim.horas, &fim.minutos, &fim.segundos);

    // Cálculo do tempo decorrido
    resultado = calcularTempoDecorrido(inicio, fim);

    // Exibição do resultado
    printf("%02d:%02d:%02d\n", resultado.horas, resultado.minutos, resultado.segundos);

    return 0;
}

// Função para calcular o tempo decorrido entre dois horários
struct Horario calcularTempoDecorrido(struct Horario inicio, struct Horario fim) {
    struct Horario resultado;

    // Cálculo dos segundos totais para início e fim
    int segundosInicio = inicio.horas * 3600 + inicio.minutos * 60 + inicio.segundos;
    int segundosFim = fim.horas * 3600 + fim.minutos * 60 + fim.segundos;

    // Cálculo do tempo decorrido em segundos
    int segundosDecorridos = segundosFim - segundosInicio;

    // Cálculo das horas, minutos e segundos do resultado
    resultado.horas = segundosDecorridos / 3600;
    resultado.minutos = (segundosDecorridos % 3600) / 60;
    resultado.segundos = segundosDecorridos % 60;

    return resultado;
}
