/*
Dado um inteiro positivo $n$ e em seguida $n$ valores inteiros, armazene estes em um vetor. Implemente uma função recursiva para a determinação do maior elemento deste vetor. Esta função deverá ser invocada dentro da main() e deve ter o seguinte protótipo:

int Maximo(int n, int v[])



Faça a alocação dinâmica do vetor a ser utilizado, bem como a liberação da memória alocada antes do seu programa terminar.
*/

#include <stdio.h>
#include <stdlib.h>

int Maximo(int n, int v[]) {
    if (n == 1) {
        return v[0];
    }
    int max_subarray = Maximo(n - 1, v);
    return (v[n - 1] > max_subarray) ? v[n - 1] : max_subarray;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));
    
    if (v == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int max_element = Maximo(n, v);

    printf("Maior elemento do vetor: %d\n", max_element);

    free(v);

    return 0;
}



/*
Resposta professora:

 // ENCONTRA O MAIOR ELEMENTO DE UM VETOR
#include <stdio.h>
#include <stdlib.h> //malloc, free

int Maximo(int n, int v[])
{
  int aux;
  
  if(n == 1)
    return v[0];
  else
  {
    aux = Maximo(n-1, v);
    if(aux > v[n-1])
      return aux;
    else
      return v[n-1];
  } 
}

int main() {

  
  int *v, n;

  // tamanho do vetor
  scanf("%d", &n);

  // alocando o vetor
  v = (int *) malloc(n* sizeof(int));

  for(int i=0; i< n; i++)
    scanf("%d", (v+i));

  printf("Maior elemento do vetor: %d \n", Maximo(n, v));
  
  // libera memória alocada dinamicamente
  free(v);
  
  return 0;
}
*/