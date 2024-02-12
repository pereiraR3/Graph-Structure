#include <iostream> 
using namespace std;

typedef string TypeItem;

// Create the simple graph 
class Graph{ 
    
    private:
        
        int edgeNull;
        int maxVertex;
        int numVertex; 
        TypeItem *vertexes; 
        int** matrixAdj; 

    public:

        Graph(int max, int edgenull); 
        ~Graph();
        int isFull();
        void insertGraph(TypeItem item);
        void insertEdge(TypeItem itemA, TypeItem itemB, int peso);
        int getWeight(TypeItem itemIn, TypeItem itemOut);
        int getDegree(TypeItem item);
        int getIndex(TypeItem item);
        void showMatrix();
        void showVertexes();
        void validatedGraph(); 
        bool isRegular();
        bool hasLoop();
};