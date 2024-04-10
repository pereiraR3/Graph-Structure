#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

class Graph{

private:

        int V;
        //lista de aristas, con formato <peso,origen,destino>
        vector<pair<int,pair<int,int> > > edges;
        bool hasNegativeCycle = false;

public:

    Graph(int V);
    void addEdge(int u,int v,int w);
    void bellmanFord(int src);
    //void printDistances();

};

Graph::Graph(int V){

    this->V = V;

}

void Graph::addEdge(int u,int v,int w){

     //edges.push_back(make_pair(w,make_pair(u,v)));
    edges.push_back({w,{u,v}});

}

void Graph::bellmanFord(int src){

    //arreglo de distancias seteado inicialmente como infinito
    vector<int> dist(this->V,INF);
    //la distancia a si mismo debe ser 0
    dist[src] = 0;
    vector<pair<int,pair<int,int> > >::iterator it;

    for(int i=1;i<this->V;i++){
        for(it = edges.begin();it!=edges.end();++it){
            int u = it->second.first;
            int v = it->second.second;
            int w = it->first;
             //Relajacion de las aristas
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
        //¿Quedó alguna arista sin relajardespués de las V*E relajaciones?  
        // Quiere decir que el grafo tiene ciclos internos de peso negativo, el algoritmo Bellman Ford no funcionará correctamente. 
    for(it = edges.begin();it!=edges.end();++it){
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;
        if(dist[u] + w < dist[v]){
            this->hasNegativeCycle = true;
            //return false
        }
    }
        //Imprime todas las distancias desde el origen hasta todos los vertices. 
    if(!hasNegativeCycle){
        for(int i=0;i<V;i++){
            cout << i << " - " << dist[i] << endl;
        }
    }
}

int main(){

    int V = 6;
    //int E; cuantas aristas
    Graph g(V);

	g.addEdge(0, 0, INF);
	g.addEdge(0, 1, 3);
	g.addEdge(0, 2, 8);
	g.addEdge(0, 3, 4);
	g.addEdge(0, 4, INF);
	g.addEdge(0, 5, INF);

	g.addEdge(1, 0, 3);
	g.addEdge(1, 1, INF);
	g.addEdge(1, 2, INF);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 4, INF);
	g.addEdge(1, 5, INF);

	g.addEdge(2, 0, 8);
	g.addEdge(2, 1, INF);
	g.addEdge(2, 2, INF);
	g.addEdge(2, 3, INF);
	g.addEdge(2, 4, 7);
	g.addEdge(2, 5, INF);

	g.addEdge(3, 0, 4);
	g.addEdge(3, 1, 6);
	g.addEdge(3, 2, INF);
	g.addEdge(3, 3, INF);
	g.addEdge(3, 4, 1);
	g.addEdge(3, 5, 3);

	g.addEdge(4, 0, INF);
	g.addEdge(4, 1, INF);
	g.addEdge(4, 2, 7);
	g.addEdge(4, 3, 1);
	g.addEdge(4, 4, INF);
	g.addEdge(4, 5, 1);

	g.addEdge(5, 0, 10);
	g.addEdge(5, 1, INF);
	g.addEdge(5, 2, INF);
	g.addEdge(5, 3, 3);
	g.addEdge(5, 4, 1);
	g.addEdge(5, 5, INF);

    g.bellmanFord(0);
    return 0;

}