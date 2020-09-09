/*
 *  Developed by Eduardo Luiz Oliani
 *
 *
 */

#include "graph.h"

Graph::Graph(int n_vertex)
{
    this->V = n_vertex;
    adj = new std::list<int>[V];//cada vetor possui uma lista de vizinhos
}

bool Graph::removerAresta(int v1, int v2)
{
    this->adj[v1].remove(v2);
    return true;
}

bool Graph::addAresta(int v1, int v2)
{
    this->adj[v1].push_back(v2); //Add vertice v2 á lista de adjacentes de v1
    return true;
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

void Graph::dfs (int v){
	std::stack<int> pilha;
	bool visitados[V];

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	while(true){
		if(!visitados[v]){
			std::cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true;
			pilha.push(v);
		}

		bool achou = false;
		std::list<int>::iterator it;

		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it])
			{
				achou = true;
				break;
			}
		}

		if(achou)
			v = *it;
		else{
			pilha.pop();
			if(pilha.empty())
				break;
			v = pilha.top();
		}
	}
}

void Graph::bfs(int v){
    std::queue<int> fila;
	bool visitados[V];

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	std::cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true;

	while(true){
		std::list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				std::cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true;
				fila.push(*it);
			}
		}
		if(!fila.empty()){
			v = fila.front();
			fila.pop();
		}
		else
			break;
	}
}
