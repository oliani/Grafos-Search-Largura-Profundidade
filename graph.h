/**
 *  Developed by Eduardo Luiz Oliani
 *
 *
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>

class Graph{

private:
    int V; // vertex number - Total de v�rtices
    std::list<int> *adj; // array pointer - contains adjecent list - Ponteiro contendo uma lista de adjacentes

public:
    Graph(int n_vertex); // constructor
    bool addAresta(int v1, int v2); // Adiciona Aresta no grafo - v1 saida, v2 destino
    bool removerAresta(int v1, int v2);
    int grauSaida(int v); //Retorna o grau de saida de um v�rtice (n�mero de arcos que saem do v�rtice (v))
    bool verifificarAdjacencia(int v1, int v2); //Verifica se v1 � adjacente (vizinho) de v2

    void dfs(int v); //faz um dfs a partir de um vertice
    void bfs(int v);
};

#endif // GRAPH_H
