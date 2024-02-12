#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(int max, int edgenull){

    maxVertex = max;
    numVertex = 0;
    edgeNull = edgenull;
    vertexes = new TypeItem[maxVertex];
    matrixAdj = new int*[maxVertex];

    for(int i = 0; i < maxVertex; i++){
        matrixAdj[i] = new int[maxVertex];
        for(int j = 0; j < maxVertex; j++){
            matrixAdj[i][j] = edgeNull;
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