#include <stdio.h>

int main() {
    // Variáveis para armazenar a calificação, GPA e créditos
    char letter_grade;
    double gpa = 0.0;
    int credits = 0;

    // Solicitar ao usuário que insira a nota
    printf("Digite a nota (A, B, C, D, W): ");
    scanf(" %c", &letter_grade);

    // Usar a estrutura de controle switch para atualizar o GPA e os créditos
    switch (letter_grade) {
        case 'A':
            gpa += 4.0;
            credits += 1;
            break;
        case 'B':
            gpa += 3.0;
            credits += 1;
            break;
        case 'C':
            gpa += 2.0;
            credits += 1;
            break;
        case 'D':
            gpa += 1.0;
            credits += 1;
            break;
        case 'W':
            // Não fazer nada no caso de retirada (W)
            break;
        default:
            // Opção padrão, incrementar créditos em 1 (possivelmente para cursos sem nota)
            credits += 1;
    }

    // Exibir os resultados
    printf("GPA atualizado: %.2f\n", gpa);
    printf("Créditos atualizados: %d\n", credits);

    return 0;
}
