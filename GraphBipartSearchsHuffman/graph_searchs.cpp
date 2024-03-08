#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef string TipoItem;

class Grafo {
private:
    int arestaNula;
    int maxVertices;
    int numVertices;
    TipoItem* vertices;
    int** matrizAdjacencia;

public:
    Grafo(int max, int arestaNula) : maxVertices(max), arestaNula(arestaNula), numVertices(0) {
        vertices = new TipoItem[maxVertices];
        matrizAdjacencia = new int*[maxVertices];
        for(int i = 0; i < maxVertices; i++){
            matrizAdjacencia[i] = new int[maxVertices];
            for(int j = 0; j < maxVertices; j++){
                matrizAdjacencia[i][j] = arestaNula;
            }
        }
    }

    ~Grafo(){
        delete [] vertices;
        for(int i = 0; i < maxVertices; i++){
            delete [] matrizAdjacencia[i];
        }
        delete [] matrizAdjacencia;
    }

    int getIndice(TipoItem item){
        for(int i = 0; i < numVertices; i++){
            if(vertices[i] == item){
                return i;
            }
        }
        return -1;
    }

    void inserirVertice(TipoItem item){
        if(numVertices < maxVertices){
            vertices[numVertices++] = item;
        }
    }

    void inserirAresta(TipoItem itemA, TipoItem itemB, int peso){
        int linha = getIndice(itemA);
        int coluna = getIndice(itemB);
        if(linha != -1 && coluna != -1){
            matrizAdjacencia[linha][coluna] = peso;
            matrizAdjacencia[coluna][linha] = peso;
        }
    }

    void buscaEmLargura(TipoItem verticeInicial) {
        vector<bool> visitado(numVertices, false);
        queue<TipoItem> fila;
        
        int indiceInicial = getIndice(verticeInicial);
        visitado[indiceInicial] = true;
        fila.push(verticeInicial);
        
        while (!fila.empty()) {
            TipoItem verticeAtual = fila.front();
            fila.pop();
            cout << verticeAtual << " ";
            
            int indiceAtual = getIndice(verticeAtual);
            for (int i = 0; i < numVertices; i++) {
                if (matrizAdjacencia[indiceAtual][i] && !visitado[i]) {
                    visitado[i] = true;
                    fila.push(vertices[i]);
                }
            }
        }
        cout << endl;
    }

    void buscaEmProfundidadeUtil(int v, vector<bool> &visitado) {
        visitado[v] = true;
        cout << vertices[v] << " ";
        
        for (int i = 0; i < numVertices; i++)
            if (matrizAdjacencia[v][i] && !visitado[i])
                buscaEmProfundidadeUtil(i, visitado);
    }

    void buscaEmProfundidade(TipoItem verticeInicial) {
        vector<bool> visitado(numVertices, false);
        int indiceInicial = getIndice(verticeInicial);
        buscaEmProfundidadeUtil(indiceInicial, visitado);
        cout << endl;
    }
};

int main() {
    Grafo g(5, 0); // Exemplo com 5 vértices

    g.inserirVertice("A");
    g.inserirVertice("B");
    g.inserirVertice("C");
    g.inserirVertice("D");
    g.inserirVertice("E");

    g.inserirAresta("A", "B", 1);
    g.inserirAresta("B", "C", 1);
    g.inserirAresta("C", "D", 1);
    g.inserirAresta("D", "E", 1);
    g.inserirAresta("E", "A", 1);

    cout << "\nBusca em Profundidade a partir de A:" << endl;
    g.buscaEmProfundidade("A");

    cout << "\nBusca em Largura a partir de A:" << endl;
    g.buscaEmLargura("A");

    return 0;
}
