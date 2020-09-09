/**
    Developed by Eduardo Luiz Oliani

    Ununciado:
    Fazer um programa que permita a inclus�o de um grafo (dirigido ou n�o dirigido), mostrando o Grafo (desenhado) ou a Matriz/lista de adjac�ncias.
    O programa deve permitir:
    - Incluir ou excluir v�rtices e arestas/arcos a qualquer tempo (OK)
    - Fazer busca em Largura e Profundidade. Com op��o de buscar algum elemento do grafo ou mostrar todos os v�rtices do grafo na ordem de visita��o. (OK)
    - O ponto de inicio da busca deve ser informado pelo usu�rio.

    --> Trabalho pode ser feito em duplas.
    --> Aten��o ao prazo para publica��o da solu��o.


*/
#include <stdio.h>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <graph.h>
#include <windows.h>


using namespace std;

int main(){
    //Gera��o do grafo
    int tam = 7;
    Graph grafo(tam);
    int matriz[tam][tam];
    int total_vertices = 0;
    int input = 0;

    for (int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++)
            matriz[i][j] = 0;
    }

    do{
        system("cls");
        cout << "1 - Adicionar aresta";
        cout << "\n2 - Remover aresta";
        cout << "\n3 - Verificar adjac�ncia entre 2 vertices";
        cout << "\n4 - Vizualizar Grau de saida de um no";
        cout << "\n5 - Vizualizar matriz";
        cout << "\n6 - Busca em profundidade (DFS)";
        cout << "\n7 - Busca em largura (BFS)";
        cout << "\n0 - Sair";
        cout << "\nDigite uma opcao: ";
        cin >> (input);

        if (input == 1){ // ADD Aresta
            int n1 = 0;
            int n2 = 0;
            while(n1 <= 0 || n1 > tam -1){
                cout << "Dgite o valor primeiro no: ";
                 cin >> n1;
                 if (n1 <= 0 || n1 > tam -1){
                     cout << "Entrada inv�lida, pressione enter e tente novamente!";
                     system("pause");
                 }
            }
            while(n2 <= 0 || n2 > tam -1){
                cout << "Digite o valor do no adjacente de " << n1 << ":";
                cin >> n2;
                if (n2 <= 0 || n2 > 20){
                    cout << "Entrada inv�lida, pressione enter e tente novamente!";
                    system("pause");
                }
            }
            cout << n1 << " -> " << n2 << "  - Vertice adicionado com sucesso!";
            total_vertices += 1;
            grafo.addAresta(n1, n2);
            system("pause");
            matriz[n1 - 1][n2 - 1] = 1;
        } else if (input == 2){
            int node_i;
            int node_j;
            cout << "Digite o ponta A da aresta a ser removida: ";
            cin >> node_i;
            cout << "Digite o ponta B da aresta a ser removida: ";
            cin >> node_j;
            if (node_i > 0 && node_i <= tam && node_i > 0 && node_j <= tam){
                grafo.removerAresta(node_i,node_j);

            }

        } else if (input == 3){
            int a,b;
            cout << "Digite a ponta A para verificar a adjacencia: ";
            cin >> a;
            cout << "Digite a ponta B para verificar a adjacencia: ";
            cin >> b;
            if (a > 0 && a < tam && b >0 && b < tam){
                if (matriz[a -1][b -1] == 1){
                    cout << "\nA e B sao adacentes!";
                }
                else{ cout << "\nA e B nao sao adacentes!\n"; }
            } else{
               cout << "\nA e B nao sao adacentes!\n";
            }
            system("pause");

        } else if (input == 4){
            cout << "Digite o veritice a ser obtido o grau de saida: ";
            int valor;
            cin >> valor;
            if (valor > 0 && valor <= tam){
                cout << grafo.grauSaida(valor);
                system("pause");
            }
            else{
                cout << "Entrada invalida";
                system("pause");
            }
        } else if (input == 5){
            system("cls");
            cout << "Matriz representando a estrutura atual: \n\n";
            cout <<  "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |16 |17 |18 |19 |20 |";
            for (int i = 0; i < tam; i++){
                if (i <= 8)
                   cout << "\n" << " " << i + 1<< " | ";
                else
                cout << "\n" << i + 1 << " | ";
                for(int j = 0; j < tam; j++){
                    cout << matriz[i][j] << " | ";
                }
            }
            cout << "\n";
            system("pause");
        } else if (input == 6){
            int raiz;
            cout << "Digite a raiz de pesquisa DFS: ";
            cin >> raiz;
            grafo.dfs(raiz);
            system("pause");
        } else if(input == 7){
            int raiz;
            cout << "Digite a raiz de pesquisa BTS: ";
            cin >> raiz;
            grafo.dfs(raiz);
            system("pause");
        }else{
            cout << "Input invalida";
            system("pause");
        }

    }while(input != 0);

    return 0;
}
