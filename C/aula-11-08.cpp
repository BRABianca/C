#include <stdio.h>

const int MAX = 100;

void LeMatriz(int n, int m, int M[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &M[i][j]);
        }
    }
}

int ContaLinhasNulas(int n, int m, int M[MAX][MAX]) {
    int contagem = 0;
    
    for (int i = 0; i < n; i++) {
        int linhaNula = 1;
        
        for (int j = 0; j < m; j++) {
            if (M[i][j] != 0) {
                linhaNula = 0;
                break;
            }
        }
        
        if (linhaNula) {
            contagem++;
        }
    }
    
    return contagem;
}

void ContaColunasNulas(int n, int m, int M[MAX][MAX], int &conta_c) {
    conta_c = 0;
    
    for (int j = 0; j < m; j++) {
        int colunaNula = 1;
        
        for (int i = 0; i < n; i++) {
            if (M[i][j] != 0) {
                colunaNula = 0;
                break;
            }
        }
        
        if (colunaNula) {
            conta_c++;
        }
    }
}

int main() {
    int n, m;
    int M[MAX][MAX];
    
    scanf("%d %d", &n, &m);
    
    LeMatriz(n, m, M);
    
    // Preenche os elementos faltantes com zeros
    for (int i = 0; i < n; i++) {
        for (int j = m; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
    
    int linhasNulas = ContaLinhasNulas(n, m, M);
    
    int colunasNulas;
    ContaColunasNulas(n, m, M, colunasNulas);
    
    printf("Linhas nulas = %d\n", linhasNulas);
    printf("Colunas nulas = %d\n", colunasNulas);
    
    return 0;
}
