#include "graph.h"

Graph::Graph(int n_vertex)
{
    this->V = n_vertex;
    adj = new std::list<int>[V];//cada vetor possui uma lista de vizinhos
}

void Graph::addAresta(int v1, int v2)
{
    this->adj[v1].push_back(v2); //Add vertice v2 á lista de adjacentes de v1
}

int Graph::grauSaida(int v)
{
    return adj[v].size();
}

bool Graph::verifificarAdjacencia(int v1, int v2)
{
    if((find(adj[v1].begin(), adj[v1].end(), v2)) != adj[v1].end())
        return true;
    return false;
}
