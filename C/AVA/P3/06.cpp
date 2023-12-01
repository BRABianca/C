//O código a seguir implementa qual método de ordenação? 

#include <stdio.h>
#define MAX 100

// Função para trocar os valores de duas variáveis
void F1(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// Função de ordenação por Selection Sort
void F2(int n, int v[MAX])
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
    {
        aux = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[aux])
                aux = j;
        F1(&v[i], &v[aux]);  // Troca o elemento atual com o menor encontrado
    }
}

int main(void)
{
    int n, i, v[MAX];

    // Leitura do tamanho da lista
    scanf("%d", &n);

    // Leitura dos elementos da lista
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    // Chamada da função de ordenação
    F2(n, v);

    // Impressão da lista ordenada
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}


/*
O código fornecido implementa o algoritmo de ordenação conhecido como "Selection Sort". Esse algoritmo consiste em iterar sobre a lista e, em cada iteração, encontrar o elemento mínimo restante e trocá-lo com o elemento atual.*/