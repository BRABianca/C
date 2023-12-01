#include <stdio.h>

int main() {
    float operando1, operando2, resultado;
    char operador;
    int n;

    printf("Digite o número de operações: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite a operação (por exemplo, 2 + 3): ");
        scanf("%f %c %f", &operando1, &operador, &operando2);

        switch (operador) {
            case '+':
                resultado = operando1 + operando2;
                printf("Resultado: %f\n", resultado);
                break;
            case '-':
                resultado = operando1 - operando2;
                printf("Resultado: %f\n", resultado);
                break;
            case '*':
                resultado = operando1 * operando2;
                printf("Resultado: %f\n", resultado);
                break;
            case '/':
                if (operando2 != 0) {
                    resultado = operando1 / operando2;
                    printf("Resultado: %f\n", resultado);
                } else {
                    printf("Erro: Divisão por zero\n");
                }
                break;
            default:
                printf("Erro: Operador inválido\n");
        }
    }

    return 0;
}
