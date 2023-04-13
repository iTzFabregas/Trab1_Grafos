#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {

private:
    int num_vert;
    map<int, list<int>> graph_map;

    /**
     * @brief função para remover uma aresta do grafo
     * 
     * @param v1 um extremo da aresta
     * @param v2 o outro extremo da aresta
     */
    void remove_edge(int v1, int v2);

    /**
     * @brief 
     * 
     */
    bool isBridge(int vertex1, int vertex2);

    /**
     * @brief recursão para achar o circuito euleriano
     * 
     * @param vertex vertice que a recursão está no momento
     * @param circuit vetor com os vértices do circuito
     */
    void EulerianCircuitRec(int vertex, vector<int>& circuit);


    int DFSCnt(int vertex,  vector<bool>& visited);

    void mark_edge(int v1, int v2);

    void unmark_edge(int v1, int v2);

public:
    /**
     * @brief construtor da classe Graph
     * 
     * @param v numero de vertices
     */
    Graph(int v);

    /**
     * @brief função para adicionar uma aresta
     * 
     * @param v1 um extremo da aresta
     * @param v2 o outro extremo da aresta
     */
    void add_edge(int v1, int v2);

    /**
     * @brief função para ordenar todas as listas de adjacência dos vertices
     * 
     */
    void sort();

    /**
     * @brief função que é chamada na main para começar a recursão de achar
     * o circuito euleriano
     * 
     */
    void EulerianCircuit();

    /**
     * @brief função que verifica se o grafo possui um circuito euleriano ou não
     * 
     * @return true - se for um grafo euleriano
     * @return false - se não for um grafo euleriano
     */
    bool isEulerian();

    void print();
};

#endif