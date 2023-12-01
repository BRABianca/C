/* 
Considere o código:

int BuscaBin_ITERATIVO(int tam, int *v, int valor)
{
    int meio, inicio, fim;

    inicio = 0;
    fim    = tam;
    
    while(inicio <= fim)
    {
        meio = (inicio+fim)/2;
        if(v[meio] == valor)
            return 1;
        else
        {
            if(valor > v[meio])
                inicio = meio+1;
            else
                fim = meio-1;
        }
    }
    return 0;
}

Quantas vezes a instrução  meio = (inicio+fim)/2  será executada  para os seguintes valores de V e x:

v[] = {3, 5, 12, 15, 18, 23, 26, 45, 49, 60, 63, 78, 79, 89, 101, 102, 103, 112, 122}

x = 103
*/

#include <stdio.h>

int BuscaBin_ITERATIVO(int tam, int *v, int valor) {
    int meio, inicio, fim, contIteracoes = 0;

    inicio = 0;
    fim = tam;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        contIteracoes++;

        if (v[meio] == valor)
            return contIteracoes;
        else {
            if (valor > v[meio])
                inicio = meio + 1;
            else
                fim = meio - 1;
        }
    }
    return contIteracoes;
}

int main() {
    int v[] = {3, 5, 12, 15, 18, 23, 26, 45, 49, 60, 63, 78, 79, 89, 101, 102, 103, 112, 122};
    int x = 103;

    int tam = sizeof(v) / sizeof(v[0]);

    int numIteracoes = BuscaBin_ITERATIVO(tam, v, x);

    printf("%d\n", numIteracoes);

    return 0;
}
