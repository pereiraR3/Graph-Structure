#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(int max, int edgenull){

    maxVertex = max;
    numVertex = 0;
    edgeNull = edgenull;
    vertexes = new TypeItem[maxVertex];
    matrixAdj = new int*[maxVertex];
    matrixComp = new int*[maxVertex];

    for(int i = 0; i < maxVertex; i++){
        matrixAdj[i] = new int[maxVertex];
        matrixComp[i] = new int[maxVertex];
        for(int j = 0; j < maxVertex; j++){
            matrixAdj[i][j] = edgeNull;
            matrixComp[i][j] = edgeNull;
        }
    }
    
}

Graph::~Graph(){
    try{
        delete [] vertexes;
        
        for(int i = 0; i < maxVertex; i++){
            delete [] matrixAdj[i];
        }
        
        delete [] matrixAdj;
    }catch(const std::exception& e){
        string messageError = e.what();
        cerr << "Erro: " << messageError << endl;
    }
}

int Graph::getIndex(TypeItem item){
    try {

        int counterIndex = 0;
        while(item != vertexes[counterIndex]){
            counterIndex++;
        }
        if(item == vertexes[counterIndex]){
            return counterIndex; 
        }else{
            return -1; 
        }

    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl;
    }
}

int Graph::isFull(){
    return (numVertex > maxVertex ?  true : false);
}

void Graph::insertGraph(TypeItem item){
    try{
        if(isFull()){
            cerr << "Error: graph is full!" << endl;
        }else{
            vertexes[numVertex] = item;
            numVertex++;
        }
    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl;
    }
}

void Graph::insertEdge(TypeItem itemA, TypeItem itemB, int peso){
    
    try{    
        int row = getIndex(itemA);
        int column = getIndex(itemB);

        if(row == -1 && column == -1){ 
            cerr << "Error: column " << endl; 
        }else{
            matrixAdj[row][column] = peso; 
            matrixAdj[column][row] = peso; 
        }
    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl;
    }
}

int Graph::getWeight(TypeItem itemA, TypeItem itemB){
    try{
        int row = getIndex(itemA);
        int column = getIndex(itemB);
        
        if(row == -1 || column == -1){
            return -1; 
        }

        return matrixAdj[row][column];

    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl;
        return -1;
    }
}

int Graph::getDegree(TypeItem item){
    try{
        int counterDegree = 0; 
        int indexItem = getIndex(item);

        for (int i = 0; i < numVertex; i++){
            if(matrixAdj[indexItem][i] != 0){
                counterDegree++;
            }
        }
        return counterDegree;

    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl;
        return -1; 
    }
}

void Graph::showVertexes(){
    try{

        for(int i = 0; i < numVertex; i++){
            cout << i << " : " << vertexes[i]; 
        }
        cout << endl; 

    }catch(std::exception& e){

        string messageError = e.what();
        cerr << "Error: " << messageError << endl;

    }
}

void Graph::showMatrix(){
    for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++){
            cout << "| " << matrixAdj[i][j] << " | ";
        }
        cout << endl;
    }
}

bool Graph::isRegular(){

    try{
        int currentEdge;
        int baseDegree = 0; 

        for(int i = 0; i < numVertex; i++){

            currentEdge = 0;
            for(int j = 0; j < numVertex; j++){
                if(matrixAdj[i][j] != 0){
                    currentEdge++;
                }
            }

            if(i == 0){
                baseDegree = currentEdge;
            }else{
                if(currentEdge != baseDegree){
                    return false;
                }
            }
        }
        return true;
    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl; 
    }
}

bool Graph::hasLoop(){
    try{
        for(int i = 0; i < numVertex; i ++){
            if(matrixAdj[i][i] != 0){
                return true;
            }   
        }
        return false; 

    }catch(std::exception& e){
        string messageError = e.what();
        cerr << "Error: " << messageError << endl;
    }
}

void Graph::edgesToAdjacencyMatrix(vector<pair<TypeItem, TypeItem>> edges){
    for(auto edge : edges){
        TypeItem itemV = edge.first;
        TypeItem itemW = edge.second;

        int row = getIndex(itemV);
        int column = getIndex(itemW);

        if(row != -1 && column != -1){
            matrixAdj[row][column] = 1;
            matrixAdj[column][row] = 1;
        }else{
            cerr << "Aresta " << itemV << "-" << itemW << " contém vértices inexistentes." << endl;
        }
    }
}

void Graph::complementMatrix(){
    int** complement = new int*[numVertex];
    for(int i = 0; i < numVertex; i++){
        complement[i] = new int[numVertex];
        for(int j = 0; j < numVertex; j++){
            if(i != j && matrixAdj[i][j] == edgeNull){
                complement[i][j] = 1;  
            }else{
                complement[i][j] = edgeNull;  
            }
        }
    }

    cout << "Matriz de adjacências do complemento do grafo:\n" << endl;
    for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++){
            cout << "| " << complement[i][j] << " | ";
        }
        cout << endl;
    }

    matrixComp = complement;
}

bool Graph::isSymmetric(){
    for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++){
            if(matrixAdj[i][j] != matrixAdj[j][i]){
                return false;
            }
        }
    }
    return true;
}

void Graph::removeEdge(TypeItem itemV, TypeItem itemW){
    try {
        int row = getIndex(itemV);
        int column = getIndex(itemW);

        if(row == -1 || column == -1 || matrixAdj[row][column] == edgeNull){
            cerr << "Aresta " << itemV << "-" << itemW << " não existe." << endl;
        }else{
            matrixAdj[row][column] = edgeNull;
            matrixAdj[column][row] = edgeNull;
            cout << "Aresta " << itemV << "-" << itemW << " removida com sucesso." << endl;

        }
    } catch(std::exception& e) {
        string messageError = e.what();
        cerr << "Erro: " << messageError << endl;
    }
}

void Graph::inOutDegrees(){
    for(int i = 0; i < numVertex; i++){
        int inDegree = 0;
        int outDegree = getDegree(vertexes[i]);

        for(int j = 0; j < numVertex; j++){
            if(matrixAdj[j][i] != 0){
                inDegree++;
            }
        }

        cout << "Vértice " << vertexes[i] << " - Grau de entrada: " << inDegree << ", Grau de saída: " << outDegree << endl;
    }
}

bool Graph::isComplete(){
    int maxDegree = numVertex - 1;

    if(numVertex < 3)
        return true; 

    for(int i = 0; i < numVertex; i++){

        int degree = getDegree(vertexes[i]);

        if(degree != maxDegree){
            return false;
        }
    }

    return true;
}

bool Graph::existsGraph(){
    return numVertex != 0;
}

void Graph::classifyGraph(){

    if(!existsGraph())
        return; 

    if(isRegular()){
        cout << "O grafo é regular." << endl;
    }else{
        cout << "O grafo não é regular." << endl;
    }

    if(isComplete()){
        cout << "O grafo é completo." << endl;
    }else{
        cout << "O grafo não é completo." << endl;
    }
}
