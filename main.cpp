/*
    Developed by Eduardo Luiz Oliani

    Ununciado:



    Fazer um programa que permita a inclusão de um grafo (dirigido ou não dirigido), mostrando o Grafo (desenhado) ou a Matriz/lista de adjacências.
    O programa deve permitir:
    - Incluir ou excluir vértices e arestas/arcos a qualquer tempo
    - Fazer busca em Largura e Profundidade. Com opção de buscar algum elemento do grafo ou mostrar todos os vértices do grafo na ordem de visitação.
    - O ponto de inicio da busca deve ser informado pelo usuário.

    --> Trabalho pode ser feito em duplas.
    --> Atenção ao prazo para publicação da solução.

    Caracterísitcas co que eu fiz até agora:

    Grafo Dirigido
    Ainda não é possível incluir e excluir arestas e vértices
    Não é possível fazer busca em profundidade, apenas em largura, uma vez que a o grafo é dirigido
    Temos várias arestas onde cada aresta contém a informação do seu adjacente

    como seria o desenho do grafo gerado abaixo


    | 0 |-->| 1 |
      |     ^ |
      |    /  |
      |   /   |
      V  /    V
    | 3 |-->| 2 |


    Retornos possíveis -> verificar se um vértice é adjascente do outro ou não


*/

#include <iostream>
#include <list>
#include <algorithm>
#include <graph.h>

using namespace std;

int main()
{
    //Geração do grafo
    Graph grafo(4);

    //add aresta
    grafo.addAresta(0,1);
    grafo.addAresta(0,3);
    grafo.addAresta(1,2);
    grafo.addAresta(3,1);
    grafo.addAresta(3,2);

    //Mostrando grau de saido do vértice
    cout << "\nGrau de saida do vertice 1: " << grafo.grauSaida(1);
    cout << "\nGrau de saida do vertice 2: " << grafo.grauSaida(2);
    cout << "\nGrau de saida do vertice 3: " << grafo.grauSaida(3);
    cout << "\n";

    //Verifica adjascentes
    if(grafo.verifificarAdjacencia(0,1))
        cout << "\n0 e adjascente de 1";
    else
        cout << "\n0 nao e adjascente de 1";

    if(grafo.verifificarAdjacencia(1,0))
       cout << "\n1 e adjascente de 0";
    else
        cout << "\n1 nao e adjascente de 0";

    cout << "\n";
    return 0;
}
