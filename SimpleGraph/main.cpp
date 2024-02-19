#include <iostream>
#include "graph.h"
#include <vector>

using namespace std;

int main() {
    Graph g(3, 0);

    g.insertGraph("A");
    g.insertGraph("B");
    g.insertGraph("C");
    g.insertEdge("A", "B", 1);
    g.insertEdge("B", "C", 1);
    g.insertEdge("C", "A", 1);

    cout << "Matriz de Adjacência:" << endl;
    g.showMatrix();

    cout << "\nLista de Vértices:" << endl;
    g.showVertexes();

    cout << "\nInserindo aresta ('B', 'A', 1):" << endl;
    g.insertEdge("A", "A", 1);
    g.showMatrix();

    cout << "\nRemovendo aresta ('C', 'A'):" << endl;
    g.removeEdge("C", "A");
    g.showMatrix();
    cout << "\n" << endl;
    ////// Testando Exercício 01  //////

    cout << "** EXERCÍCIO 01 **" << endl;
    cout << "\nDescobrindo se a matriz é simétrica ou não:" << endl;
    cout << "resultado: " << g.isSymmetric() << "\n"<< endl;

    ////// Testando Exercício 02 //////

    cout << "** EXERCÍCIO 02 **" << endl;
    cout << "Classificando o Grafo:" << endl;
    g.classifyGraph();
    cout << "\n" << endl; 


    ////// Testando Exercício 03  //////

    cout << "** EXERCÍCIO 03 **" << endl;
    g.inOutDegrees();
    cout << "\n" << endl;

    ////// Testando Exercício 04  //////

    cout << "** EXERCÍCIO 04 **" << endl;
    g.removeEdge("B", "C");
    g.showMatrix();
    cout << "\n" << endl;

    ////// Testando Exercício 05  //////
    cout << "** EXERCÍCIO 05 **" << endl;
    g.complementMatrix();
    cout << "\n" << endl;


    //// Testando Exercício 06 /////

    Graph graph(5, 0);

    graph.insertGraph("A");
    graph.insertGraph("B");
    graph.insertGraph("C");
    graph.insertGraph("D");
    graph.insertGraph("E");

    // Definir arestas usando um vetor de pares (vértice1, vértice2)
    std::vector<std::pair<string, string>> edges = {
        {"A", "B"},
        {"B", "C"},
        {"C", "D"},
        {"D", "A"},
        {"A", "C"}
    };

    // Adicionar as arestas à matriz de adjacência usando o método edgesToAdjacencyMatrix()
    cout << "** EXERCÍCIO 06 **" << endl;
    graph.edgesToAdjacencyMatrix(edges);

    // Exibir a matriz de adjacência resultante
    std::cout << "Matriz de Adjacência do Grafo:" << std::endl;
    graph.showMatrix();

    return 0;
}
