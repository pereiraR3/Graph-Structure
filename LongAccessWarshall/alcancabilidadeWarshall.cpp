#include <stdio.h>
#define MAX_VERTICES 100 // Máximo de vértices suportados

// Função para realizar a multiplicação booleana de matrizes
void booleanMultiply(int n, int A[][MAX_VERTICES], int B[][MAX_VERTICES], int C[][MAX_VERTICES]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] |= A[i][k] & B[k][j];
            }
        }
    }
}

// Função para calcular as matrizes de alcançabilidade A(1), A(2),..., A(N) e R
void calculateReachabilityMatrices(int n, int adjMatrix[][MAX_VERTICES], int R[][MAX_VERTICES]) {
    int temp1[MAX_VERTICES][MAX_VERTICES], temp2[MAX_VERTICES][MAX_VERTICES];

    // Copiando a matriz de adjacências para R (base para A(1))
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = adjMatrix[i][j];
        }
    }

    // Calculando A(2) até A(N) e atualizando R
    for (int k = 2; k <= n; k++) {
        booleanMultiply(n, R, adjMatrix, temp1); // Multiplicação booleana de R e adjMatrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] |= temp1[i][j]; // Atualizando R com o resultado da multiplicação
            }
        }
    }
}

// Algoritmo de Warshall para calcular a matriz de alcançabilidade
void warshall(int n, int adjMatrix[][MAX_VERTICES], int M[][MAX_VERTICES]) {
    // Inicializando M com a matriz de adjacências
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = adjMatrix[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] |= (M[i][k] & M[k][j]);
            }
        }
    }
}

int main() {
    int n; // Número de vértices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES], R[MAX_VERTICES][MAX_VERTICES], M[MAX_VERTICES][MAX_VERTICES];

    // Leitura da matriz de adjacências
    printf("Digite o número de vértices: ");
    scanf("%d", &n);
    printf("Digite a matriz de adjacências (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Calculando matrizes de alcançabilidade usando multiplicações booleanas
    calculateReachabilityMatrices(n, adjMatrix, R);

    printf("Matriz de Alcançabilidade Geral R:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    // Calculando a matriz de alcançabilidade geral usando o algoritmo de Warshall
    warshall(n, adjMatrix, M);

    printf("Matriz de Alcançabilidade Geral M (Warshall):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
