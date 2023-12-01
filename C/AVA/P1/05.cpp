/*
Faça um programa que leia um inteiro n (1 < n < 100) e em seguinda leia n valores inteiros e os armazene em um vetor. Implemente a seguinte função

para determinar o maior e o menor valor existente no conjunto de entrada.



void Maior_Menor(int n, int *vetor, int *maior, int * menor);



Atenção: Todas as suas manipulações sobre o vetor devem ser feitas utilizando a notação de ponteiros (assim, o uso dos colchetes só será permitido para a declaração do vetor).
*/

#include<stdio.h>
#define MAX 100

/*prototipo da funcao*/
void Maior_Menor(int n, int *vetor, int *maior, int * menor)
{
  int *pt_vetor;

  
  // iniciando as variáveis maior e menor
  *maior = *vetor;
  *menor = *vetor;
  
  // buscando o maior e o menor valor dentre os elementos do vetor
  for(pt_vetor = vetor; pt_vetor < vetor + n; pt_vetor++)
  {
    if(*pt_vetor > *maior)
      *maior = *pt_vetor;
    else if(*pt_vetor < *menor)
      *menor = *pt_vetor;
  }

}

int main(void)
{
    int n, i;
    int vetor[MAX];
    int maior, menor;

    // tamanho do conjunto de inteiros
    scanf("%d", &n);
    
    // leitura do conjunto de inteiros
    for(i = 0; i < n; i++)
        scanf("%d", (vetor + i));

    // determinação do maior e do menor elemento do conjunto
    Maior_Menor(n, vetor, &maior, &menor);

    // saída
    printf("Maior elemento do vetor: %d\n", maior);
    printf("Menor elemento do vetor: %d\n", menor);
 
    return 0;
}