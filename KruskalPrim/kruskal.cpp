#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura para representar uma aresta no grafo
struct Aresta {
    int origem, destino, peso;
};

// Estrutura para representar um grafo
struct Grafo {
    int V, E;
    vector<Aresta> arestas;
};

// Estrutura para representar um subconjunto para o algoritmo de união-encontro
struct subset {
    int parent, rank;
};

// Função para encontrar o subconjunto de um elemento i
int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Função de união de dois subconjuntos x e y
void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Função para o algoritmo de Kruskal para encontrar a MST
void KruskalMST(Grafo& grafo) {
    vector<Aresta> resultado; 
    int e = 0;  
    int i = 0;  

    sort(grafo.arestas.begin(), grafo.arestas.end(), [](Aresta a, Aresta b) {
        return a.peso < b.peso;
    });

    subset *subsets = new subset[(grafo.V * sizeof(subset))];

    for (int v = 0; v < grafo.V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < grafo.V - 1 && i < grafo.E) {
        Aresta next_aresta = grafo.arestas[i++];

        int x = find(subsets, next_aresta.origem);
        int y = find(subsets, next_aresta.destino);

        if (x != y) {
            resultado.push_back(next_aresta);
            Union(subsets, x, y);
            e++;
        }
    }

    cout << "Arestas na Árvore Geradora Mínima usando Kruskal\n";
    int pesoMinimoTotal = 0;
    for (i = 0; i < e; ++i) {
        cout << resultado[i].origem << " -- " << resultado[i].destino << " == " << resultado[i].peso << endl;
        pesoMinimoTotal += resultado[i].peso;
    }
    cout << "Peso total da Árvore Geradora Mínima: " << pesoMinimoTotal << endl;
}

int main() {
    /* Exemplo de entrada */
    int V = 4;  // Número de vértices
    int E = 5;  // Número de arestas
    Grafo grafo = {V, E};

    // Adicionar arestas {origem, destino, peso}
    grafo.arestas = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    KruskalMST(grafo);

    return 0;
}
