#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // número de vértices

	// ponteiro para um array contendo as listas de adjacências
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o número de vértices

		/*
			cria as listas onde cada lista é uma lista de pairs
			onde cada pair é formado pelo vértice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
	Grafo g(6);

	g.addAresta(0, 0, INFINITO);
	g.addAresta(0, 1, 3);
	g.addAresta(0, 2, 8);
	g.addAresta(0, 3, 4);
	g.addAresta(0, 4, INFINITO);
	g.addAresta(0, 5, INFINITO);

	g.addAresta(1, 0, 3);
	g.addAresta(1, 1, INFINITO);
	g.addAresta(1, 2, INFINITO);
	g.addAresta(1, 3, 6);
	g.addAresta(1, 4, INFINITO);
	g.addAresta(1, 5, INFINITO);

	g.addAresta(2, 0, 8);
	g.addAresta(2, 1, INFINITO);
	g.addAresta(2, 2, INFINITO);
	g.addAresta(2, 3, INFINITO);
	g.addAresta(2, 4, 7);
	g.addAresta(2, 5, INFINITO);

	g.addAresta(3, 0, 4);
	g.addAresta(3, 1, 6);
	g.addAresta(3, 2, INFINITO);
	g.addAresta(3, 3, INFINITO);
	g.addAresta(3, 4, 1);
	g.addAresta(3, 5, 3);

	g.addAresta(4, 0, INFINITO);
	g.addAresta(4, 1, INFINITO);
	g.addAresta(4, 2, 7);
	g.addAresta(4, 3, 1);
	g.addAresta(4, 4, INFINITO);
	g.addAresta(4, 5, 1);

	g.addAresta(5, 0, 10);
	g.addAresta(5, 1, INFINITO);
	g.addAresta(5, 2, INFINITO);
	g.addAresta(5, 3, 3);
	g.addAresta(5, 4, 1);
	g.addAresta(5, 5, INFINITO);

	cout << g.dijkstra(0, 5) << endl;

	return 0;
}