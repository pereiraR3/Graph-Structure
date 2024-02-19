#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
using namespace std;

typedef string TypeItem;

class Graph {
private:
    int edgeNull;
    int maxVertex;
    int numVertex;
    TypeItem* vertexes;
    int** matrixAdj;
    int** matrixComp;


public:
    Graph(int max, int edgenull);
    ~Graph();
    int isFull();
    void insertGraph(TypeItem item);
    void insertEdge(TypeItem itemA, TypeItem itemB, int peso);
    int getWeight(TypeItem itemA, TypeItem itemB);
    int getDegree(TypeItem item);
    int getIndex(TypeItem item);
    void showMatrix();
    void showVertexes();
    void validatedGraph();
    bool isRegular();
    bool hasLoop();
    void edgesToAdjacencyMatrix(vector<pair<TypeItem, TypeItem>> edges);
    void complementMatrix();
    bool isSymmetric();
    void removeEdge(TypeItem itemV, TypeItem itemW);
    void inOutDegrees();
    bool isComplete();
    bool existsGraph();
    void classifyGraph();
};

#endif // GRAPH_H
