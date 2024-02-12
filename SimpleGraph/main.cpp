
#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph g(3, 0);

    g.insertGraph("A");
    g.insertGraph("B");
    g.insertGraph("C");
    g.insertEdge("A", "B", 1);
    g.insertEdge("B", "C", 1);
    g.insertEdge("C", "A", 1);

    std::cout << "O grafo é regular? " << (g.isRegular() ? "Sim" : "Não") << std::endl;
    std::cout << "O grafo tem loop? " << (g.hasLoop() ? "Sim" : "Não") << std::endl;

    return 0;
};
