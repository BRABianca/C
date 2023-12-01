/*Faca um programa para cadastrar carros com os seguintes dados: 
marca (maximo de 15 letras), ano e preço. Suponha que no maximo serao cadastrados
30 carros. O seu programa deve possuir o seguinte menu:

1 - Cadastrar um carro: nesta opcao o usuario informa os dados de APENAS UM CARRO, que 
deverão ser armazenados num vetor de registros.

2 - Listar carros: lista os dados de todos os carros cadastrados

3 - Media de precos: calcula e imprime a media dos precos dos carros de um determinado
ano. O usuario informa um ano e a media dos precos dos carros deste ano
deve ser impressa.

FUNCOES A CRIAR:
1 - Uma funcao para cadastrar um carro: recebe o vetor e o numero de carros cadastrados 
ate o momento. Atencao: nesta funcao o numero de carros deverá aumentar em uma unidade.
2 - Uma funcao para listar os dados de todos os carros: recebe o vetor e o numero de carros
cadastrados ate o momento
3 - Uma funcao para calcular e retornar a media dos precos dos carros de um determinado ano 
informado pelo usuario: recebe o vetor, o numero de carros
cadastrados ate o momento e um ano, retorna a media.
*/
#include <stdio.h>
#include <string.h>

#define MAX 15
#define TAM 30

// Definição da estrutura para armazenar informações de um carro
struct tCarro {
    char marca[MAX];
    int ano;
    float preco;
};

// Protótipos das funções
void menu();
void leitura(tCarro carros[TAM], int &n);
void listarCarros(tCarro carros[TAM], int n);
double calcMedia(tCarro carros[TAM], int n, int ano);

// Função principal
int main() {
    int opcao;
    tCarro carros[TAM];
    int n = 0;  // Quantidade de carros cadastrados
    int ano;    // Ano a ser pesquisado
    double media;

    do {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (n < 30) {
                // Ler os dados de um carro - função
                leitura(carros, n);
            } else {
                printf("Vetor cheio.\n");
            }
        } else if (opcao == 2) {
            // Imprimir todos os carros cadastrados - função
            listarCarros(carros, n);
        } else if (opcao == 3) {
            // Ler um ano e imprimir a média de preços dos carros do ano
            printf("Digite um ano para pesquisar: ");
            scanf("%d", &ano);

            media = calcMedia(carros, n, ano);
            if (media == 0.0)
                printf("Nenhum carro deste ano foi encontrado.");
            else
                printf("Media dos precos dos carros: %.2f", media);
        }
    } while (opcao != 4);

    return 0;
}

// Função para exibir o menu
void menu() {
    printf("\n[1] Cadastrar um carro\n");
    printf("[2] Listar carros\n");
    printf("[3] Media de precos de um ano\n");
    printf("[4] Sair\n");
    printf("Opcao: ");
}

// Função para realizar a leitura dos dados de um carro
void leitura(tCarro carros[TAM], int &n) {
    scanf(" %[^\n]", carros[n].marca);  // Leitura da marca (incluindo espaços)
    scanf("%d", &carros[n].ano);         // Leitura do ano
    scanf("%f", &carros[n].preco);       // Leitura do preço
    n++;                                 // Incremento da quantidade de carros cadastrados
}

// Função para listar todos os carros cadastrados
void listarCarros(tCarro carros[TAM], int n) {
    int i;
    printf("Carros cadastrados:\n");
    for (i = 0; i < n; i++)
        printf("%s %d %.2f\n", carros[i].marca, carros[i].ano, carros[i].preco);
}

// Função para calcular e retornar a média dos preços dos carros de um determinado ano
double calcMedia(tCarro carros[TAM], int n, int ano) {
    double soma = 0;
    int i, cont = 0;

    for (i = 0; i < n; i++) {
        if (carros[i].ano == ano) {
            soma += carros[i].preco;
            cont += 1;
        }
    }
    if (cont != 0)
        return soma / cont;
    else
        return 0;  // Indicar que não carros do ano não foram encontrados
}
