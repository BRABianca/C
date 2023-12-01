/*
Escreva um programa que leia as seguintes informações de um conjunto de n funcionários:

nome do funcionário
valor pago por hora trabalhada 
número de horas trabalhadas
Para cada funcionário deve-se calcular o seu salário, que é dado pelo número de horas trabalhadas multiplicado pelo valor pago por hora trabalhada. Entretanto, os funcionários que trabalham mais do que 40 recebem 1.5 vezes o valor da hora normal, para a quantidade de horas que execeu 40 horas.



Seu programa deve armazenar todas as informações de um funcionário em um registro. Como existem n funcionários (1 < n < 30), será necessário um vetor de registros.

Utilize a seguinte declaração para o registro de funcionário (fora da main):

struct regFunc{

     char  nome[20];

     float valor_pago_por_hora;

     float salario;

    int horas_trabalhadas;

};

bem como a seguinte declaração para a criação do vetor de registros (dentro da main):

regFunc func[MAX];



Seu pragrama deve implementar as seguintes funções, conforme os protótipos a seguir:

// Função para o cáculo do salário de cada um dos funcionários

float calcSalario(float valor_Hora, int num_Horas);



// Função para determinar o valor do maior salário

void maiorSalario(float *maior, int n, regFunc func[MAX]);



// Função para imprimir a lista de nomes e salários dos funcionários

void imprimeSalario(int n, regFunc func[MAX]);
*/

#include <stdio.h>
#define MAX 30

// Definição da estrutura para armazenar informações de um funcionário
struct regFunc {
    char nome[20];
    float valor_pago_por_hora;
    float salario;
    int horas_trabalhadas;
};

// Função para calcular o salário de um funcionário com base nas horas trabalhadas
float calcSalario(float valor_Hora, int num_Horas) {
    if (num_Horas > 40)
        return (40 * valor_Hora) + (num_Horas - 40) * 1.5 * valor_Hora;
    else
        return (num_Horas * valor_Hora);
}

// Função para imprimir os salários de todos os funcionários
void imprimeSalario(int n, struct regFunc func[MAX]) {
    for (int i = 0; i < n; i++)
        printf("%s %.2f\n", func[i].nome, func[i].salario);
}

// Função para determinar o valor do maior salário entre os funcionários
void maiorSalario(float *maior, int n, struct regFunc func[MAX]) {
    *maior = func[0].salario;

    for (int j = 1; j < n; j++)
        if (func[j].salario > *maior)
            *maior = func[j].salario;
}

int main() {
    struct regFunc func[MAX];
    int i, n;
    float maior;

    // Leitura da quantidade de funcionários
    scanf("%d", &n);

    // Leitura das informações de cada funcionário e cálculo do salário
    for (i = 0; i < n; i++) {
        scanf("%s %f %d", func[i].nome, &func[i].valor_pago_por_hora, &func[i].horas_trabalhadas);
        func[i].salario = calcSalario(func[i].valor_pago_por_hora, func[i].horas_trabalhadas);
    }

    // Impressão dos salários de todos os funcionários
    imprimeSalario(n, func);

    // Cálculo e impressão do maior salário
    maiorSalario(&maior, n, func);
    printf("%.1f", maior);

    return 0;
}

/*
Struct regFunc: Define a estrutura regFunc para armazenar informações de um funcionário, como nome, valor pago por hora, salário e horas trabalhadas.

Função calcSalario: Calcula o salário de um funcionário com base nas horas trabalhadas, aplicando um acréscimo de 50% para horas extras.

Função imprimeSalario: Imprime os salários de todos os funcionários.

Função maiorSalario: Encontra o maior salário entre os funcionários.

Main:
    Lê a quantidade de funcionários.
    Lê as informações de cada funcionário e calcula o salário.
    Imprime os salários de todos os funcionários.
    Calcula e imprime o maior salário.
Observação:
    Os comentários no código ajudam a entender a funcionalidade de cada parte.
    O código lê informações sobre funcionários, calcula salários e imprime os resultados.
*/