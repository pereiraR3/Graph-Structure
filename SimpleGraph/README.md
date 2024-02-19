# Graph Algorithms

Este repositório contém uma implementação em C++ de uma classe `Graph` que fornece funcionalidades para manipulação de grafos, incluindo a criação, inserção de vértices e arestas, cálculos de grau, verificação de propriedades do grafo, entre outras operações comuns.

## Estrutura do Código

O código consiste em uma classe `Graph` que utiliza uma matriz de adjacência para representar o grafo. Algumas das principais funcionalidades incluem:

- **Criação do Grafo:**
  - O construtor `Graph(int max, int edgenull)` inicializa a estrutura do grafo com um número máximo de vértices e um valor nulo para representar ausência de aresta.

- **Inserção de Vértices e Arestas:**
  - Métodos como `insertGraph()`, `insertEdge()` e `edgesToAdjacencyMatrix()` são fornecidos para inserção de vértices e arestas no grafo.

- **Operações com Matriz de Adjacência:**
  - Métodos como `showMatrix()` exibem a matriz de adjacência do grafo.
  - `complementMatrix()` calcula e exibe a matriz de adjacência do complemento do grafo.

- **Propriedades do Grafo:**
  - Métodos como `isRegular()`, `hasLoop()`, `isComplete()` e `classifyGraph()` permitem verificar propriedades do grafo, como regularidade e completude.

- **Manipulação de Arestas:**
  - `removeEdge()` remove uma aresta específica do grafo.

- **Cálculos de Grau:**
  - `getDegree()` calcula o grau de um vértice.
  - `inOutDegrees()` exibe os graus de entrada e saída de todos os vértices.

- **Verificação de Simetria:**
  - `isSymmetric()` verifica se a matriz de adjacência do grafo é simétrica.

## Uso

Para utilizar a classe `Graph`, inclua os arquivos `graph.h` e `graph.cpp` em seu projeto C++. Em seguida, você pode criar uma instância da classe `Graph` e realizar operações com grafos.

```cpp
#include <iostream>
#include "graph.h"

int main() {
    // Exemplo de uso da classe Graph
    Graph graph(5, -1); // Criar um grafo com 5 vértices e valor nulo para ausência de aresta
    
    // Inserir vértices e arestas
    graph.insertGraph('A');
    graph.insertGraph('B');
    graph.insertEdge('A', 'B', 1);

    // Exibir a matriz de adjacência
    std::cout << "Matriz de Adjacência do Grafo:" << std::endl;
    graph.showMatrix();

    // Realizar outras operações com o grafo...

    return 0;
}
