#include <iostream>
#include <vector>

#define INF 10000000  // Valor infinito para representar ausência de ligação

using namespace std;

// Função para imprimir a matriz de distâncias mínimas
void imprimirMatriz(const vector<vector<int>>& distancia) {
  int n = distancia.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (distancia[i][j] == INF) {
        cout << "INF ";  // Imprime "INF" para ausência de ligação
      } else {
        cout << distancia[i][j] << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  int n = 6; // Número de vértices no grafo

  // Cria a matriz de distâncias
  vector<vector<int>> distancia(n, vector<int>(n, INF));

  // Define os pesos das arestas para o grafo fornecido (substitua pelo seu método de criação de grafo, se aplicável)
  distancia[0][0] = INF;
  distancia[0][1] = 3;
  distancia[0][2] = 8;
  distancia[0][3] = 4;
  distancia[0][4] = INF;
  distancia[0][5] = INF;

  distancia[1][0] = 3;
  distancia[1][1] = INF;
  distancia[1][2] = INF;
  distancia[1][3] = 6;
  distancia[1][4] = INF;
  distancia[1][5] = INF;

  distancia[2][0] = 8;
  distancia[2][1] = INF;
  distancia[2][2] = INF;
  distancia[2][3] = INF;
  distancia[2][4] = 7;
  distancia[2][5] = INF;

  distancia[3][0] = 4;
  distancia[3][1] = 6;
  distancia[3][2] = INF;
  distancia[3][3] = INF;
  distancia[3][4] = 1;
  distancia[3][5] = 3;

  distancia[4][0] = INF;
  distancia[4][1] = INF;
  distancia[4][2] = 7;
  distancia[4][3] = 1;
  distancia[4][4] = INF;
  distancia[4][5] = 1;

  distancia[5][0] = 10;
  distancia[5][1] = INF;
  distancia[5][2] = INF;
  distancia[5][3] = 3;
  distancia[5][4] = 1;
  distancia[5][5] = INF;

  // Algoritmo de Floyd-Warshall
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
      }
    }
  }

  // Imprime a matriz de distâncias mínimas
  cout << "Distâncias mínimas entre todos os pares de vértices:" << endl;
  imprimirMatriz(distancia);

  return 0;
}
