#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef string TipoItem;

class Grafo {
private:
    int arestaNula;
    int maxVertice;
    int numVertice;
    TipoItem* vertices;
    int** matrizAdj;

public:
    Grafo(int max, int arestaNula) : maxVertice(max), arestaNula(arestaNula), numVertice(0) {
        vertices = new TipoItem[maxVertice];
        matrizAdj = new int*[maxVertice];
        for(int i = 0; i < maxVertice; i++){
            matrizAdj[i] = new int[maxVertice];
            for(int j = 0; j < maxVertice; j++){
                matrizAdj[i][j] = arestaNula;
            }
        }
    }

    ~Grafo(){
        delete [] vertices;
        for(int i = 0; i < maxVertice; i++){
            delete [] matrizAdj[i];
        }
        delete [] matrizAdj;
    }

    int getIndice(TipoItem item){
        for(int i = 0; i < numVertice; i++){
            if(vertices[i] == item){
                return i;
            }
        }
        return -1;
    }

    void inserirVertice(TipoItem item){
        if(numVertice < maxVertice){
            vertices[numVertice++] = item;
        }
    }

    void inserirAresta(TipoItem itemA, TipoItem itemB, int peso){
        int linha = getIndice(itemA);
        int coluna = getIndice(itemB);
        if(linha != -1 && coluna != -1){
            matrizAdj[linha][coluna] = peso;
            matrizAdj[coluna][linha] = peso;
        }
    }

    void mostrarMatriz(){
        for(int i = 0; i < numVertice; i++){
            for(int j = 0; j < numVertice; j++){
                cout << matrizAdj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void mostrarTodosGraus(){
        for(int i = 0; i < numVertice; i++){
            int grau = 0;
            for(int j = 0; j < numVertice; j++){
                if(matrizAdj[i][j] != arestaNula) grau++;
            }
            cout << vertices[i] << " : " << grau << endl;
        }
    }

    void imprimirConjuntosBipartidos(const vector<int>& cor) {
        cout << "Conjunto 1: ";
        for (int i = 0; i < numVertice; ++i) {
            if (cor[i] == 1) {
                cout << vertices[i] << " ";
            }
        }
        cout << "\nConjunto 2: ";
        for (int i = 0; i < numVertice; ++i) {
            if (cor[i] == 0) {
                cout << vertices[i] << " ";
            }
        }
        cout << endl;
    }

    bool ehBipartido() {
        vector<int> cor(numVertice, -1);
        
        for (int i = 0; i < numVertice; i++) {
            if (cor[i] == -1) {
                if (!ehBipartidoUtil(i, cor)) {
                    return false;
                }
            }
        }
        
        imprimirConjuntosBipartidos(cor); // Mostra os conjuntos se o grafo for bipartido
        return true;
    }

    bool ehBipartidoUtil(int src, vector<int>& cor) {
        cor[src] = 1;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v = 0; v < numVertice; ++v) {
                if (matrizAdj[u][v] && cor[v] == -1) {
                    cor[v] = 1 - cor[u];
                    q.push(v);
                } else if (matrizAdj[u][v] && cor[v] == cor[u]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    Grafo bipartiteGraph(4, 0); // Cria um grafo com 4 vértices

    bipartiteGraph.inserirVertice("A");
    bipartiteGraph.inserirVertice("B");
    bipartiteGraph.inserirVertice("C");
    bipartiteGraph.inserirVertice("D");

    // Conecta A a C e D, e B a C e D
    bipartiteGraph.inserirAresta("A", "C", 1);
    bipartiteGraph.inserirAresta("A", "D", 1);
    bipartiteGraph.inserirAresta("B", "C", 1);
    bipartiteGraph.inserirAresta("B", "D", 1);

    cout << "Grafo Bipartido:" << endl;
    bipartiteGraph.mostrarTodosGraus();
    cout << "\nVerificando se o grafo é bipartido: \n";
    if (bipartiteGraph.ehBipartido()) {
        cout << "Sim\n";
    } else {
        cout << "Não\n";
    }

    Grafo nonBipartiteGraph(4, 0); // Cria um grafo com 4 vértices

    nonBipartiteGraph.inserirVertice("A");
    nonBipartiteGraph.inserirVertice("B");
    nonBipartiteGraph.inserirVertice("C");
    nonBipartiteGraph.inserirVertice("D");

    // Conecta A a C e D, e B a C e D, e também A a B
    nonBipartiteGraph.inserirAresta("A", "C", 1);
    nonBipartiteGraph.inserirAresta("A", "D", 1);
    nonBipartiteGraph.inserirAresta("B", "C", 1);
    nonBipartiteGraph.inserirAresta("B", "D", 1);
    nonBipartiteGraph.inserirAresta("A", "B", 1); // Esta aresta impede que o grafo seja bipartido

    cout << "\nGrafo Não Bipartido:" << endl;
    nonBipartiteGraph.mostrarTodosGraus();
    cout << "\nVerificando se o grafo é bipartido: ";
    if (nonBipartiteGraph.ehBipartido()) {
        cout << "Sim\n";
    } else {
        cout << "Não\n";
    }

    return 0;
}
