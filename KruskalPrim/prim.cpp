#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Número de vértices no grafo
#define V 5

// Função para encontrar o vértice com valor mínimo de chave, dos vértices que não estão incluídos na MST
int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Função para imprimir a árvore geradora mínima armazenada no vetor parent[]
void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Aresta \tPeso\n";
    int pesoMinimoTotal = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        pesoMinimoTotal += graph[i][parent[i]];
    }
    cout << "Peso total da Árvore Geradora Mínima: " << pesoMinimoTotal << endl;
}

// Função que implementa o algoritmo de Prim para encontrar a MST de um grafo representado usando adjacência de matriz
void primMST(vector<vector<int>>& graph) {
    // Array para armazenar a árvore construída
    vector<int> parent(V);

    // Valores-chave usados para escolher a aresta de menor peso na corte
    vector<int> key(V, INT_MAX);

    // Para representar o conjunto de vértices incluídos na MST
    vector<bool> mstSet(V, false);

    // Sempre inclua o primeiro vértice na MST.
    key[0] = 0; 
    parent[0] = -1; // O primeiro nó é sempre a raiz da MST

    // A MST terá V vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolha o vértice de chave mínima do conjunto de vértices ainda não incluído na MST
        int u = minKey(key, mstSet);

        // Adicione o vértice escolhido ao conjunto da MST
        mstSet[u] = true;

        // Atualize o valor da chave e o índice do pai dos vértices adjacentes do vértice escolhido.
        for (int v = 0; v < V; v++)

            // graph[u][v] é diferente de zero apenas para vértices adjacentes de m
            // mstSet[v] é falso para vértices que ainda não estão incluídos na MST
            // Atualize a chave apenas se graph[u][v] for menor que a chave[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // imprime a árvore geradora mínima construída
    printMST(parent, graph);
}

int main() {
    /* Exemplo de Grafo */
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    // Imprime a solução
    primMST(graph);

    return 0;
}
