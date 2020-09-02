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
#include <windows.h>

using namespace std;

void startMatrix(int **matrix[20][20], int tam){
    for(int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++)
            matrix[i][j] = 0;
    }
}

void printMatrix(int **matrix[20][20], int tam){
    for(int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            cout << **matrix[i][j] << " | ";
        }
        cout << "\n";
    }
}

int main(){
    //Geração do grafo
    Graph grafo(20);
    int **matriz[20][20];
    startMatrix(matriz, 20);
    int total_vertices = 0;
    int input = NULL;

    do{
        system("cls");
        cout << "1 - Adicionar aresta\n";
        cout << "2 - Remover no";
        cout << "3 - Verificar adjacência entre 2 vertices";
        cout << "4 - Vizualizar Grau de saida de um no";
        cout << "5 - Vizualizar matriz";
        cout << "0 - Sair";
        cin >> input;

        if (input == 1){ // ADD Aresta
            int n1 = 0;
            int n2 = 0;
            while(n1 <= 0 || n1 > 20){
                cout << "Dgite o valor primeiro no: ";
                 cin >> n1;
                 if (n1 <= 0 || n1 > 20){
                     cout << "Entrada inválida, pressione enter e tente novamente!";
                     system("pause");
                 }
            }
            while(n2 <= 0 || n2 > 20){
                cout << "Dgite o valor do no adjacente de " << n1 << ":";
                cin >> n2;
                if (n2 <= 0 || n2 > 20){
                    cout << "Entrada inválida, pressione enter e tente novamente!";
                    system("pause");
                }
            }
            cout << n1 << " -> " << n2 << "  - Vertice adicionado com sucesso!";
            total_vertices += 1;
            grafo.addAresta(n1, n2);
            system("pause");
        }


    } while (input != 0);




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
