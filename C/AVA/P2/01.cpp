/*
Leia um inteiro m e uma matriz M de dimensão mxm, a ser alocada estaticamente e, em seguida, apresente a soma da diagonal principal. 



Seu código deve utilizar a notação de ponteiros para manipular a matriz, tanto na leitura quanto na determinação da soma dos elementos da diagonal principal. Entretanto, para a determinação da soma dos elementos da digaonal princiapal apenas UM ÚNICO ponteiro e UMA ÚNICA estrutura de repetição deverão serão ser utilizados para percorrer a matriz M.



Utilize as instruções fornecids para iniciar sua implementação, sem realizar alterações nas mesmas.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m;
    scanf("%d", &m);

    // Alocação dinâmica de memória para uma matriz 2D
    int **M = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        M[i] = (int *)malloc(m * sizeof(int));
    }

    int i, j;

    // Leitura da matriz
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    // Cálculo da soma dos elementos da diagonal principal
    int soma = 0;
    for (i = 0; i < m; i++) {
        soma += M[i][i];
    }

    // Impressão do resultado
    printf("%d\n", soma);

    // Liberação de memória alocada dinamicamente
    for (int i = 0; i < m; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}
/*
Alocação Dinâmica de Memória:
    Usa malloc para alocar dinamicamente um array de ponteiros para inteiros (M).
    Usa um segundo loop para alocar dinamicamente cada linha da matriz.
Leitura da Matriz:
    Utiliza dois loops aninhados para percorrer e ler os elementos da matriz alocada dinamicamente.
Cálculo da Soma da Diagonal Principal:
    Utiliza um loop para percorrer os elementos da diagonal principal da matriz.
    Acumula a soma dos elementos em uma variável soma.
Impressão do Resultado:
    Imprime a soma dos elementos da diagonal principal.
Liberação de Memória Alocada Dinamicamente:
    Usa free para liberar a memória alocada dinamicamente, primeiro para cada linha e depois para o array de ponteiros.
*/

/*
Reposta do autor: 

#include <stdio.h>


int main()
{
    int i, m, soma=0, *pt;
    
    scanf("%d", &m);
    
    // matriz de dimensão mXm
    int M[m][m];
    
     // leitura da matriz
    for(i = 0; i < m; i++)
        for(pt = M[i]; pt< M[i]+m; pt++)
            scanf("%d", pt);
   
        
    // determinação da soma dos elementos da diagonal principal       
    for(pt = &M[0][0]; pt<= &M[m-1][m-1]; pt+=m+1)
        soma += *pt;
   
    // impressão do resultado
    printf("%d", soma);
    
    // fim da main
    return 1;
}
*/