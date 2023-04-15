#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
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
     * @brief função que verifica se a aresta é a unica da lista de adjacencia
     * e verifica se a aresta é considerada ponte ou não
     * 
     * @param vertex1 um extremo da aresta
     * @param vertex2 o outro extremo da aresta
     * @return true se for a unica aresta / não for uma ponte
     * @return false se for uma ponte
     */
    bool isValidEdge(int vertex1, int vertex2);

    /**
     * @brief recursão para achar o circuito euleriano
     * 
     * @param vertex vertice que a recursão está no momento
     * @param circuit vetor com os vértices do circuito
     */
    void EulerianCircuitRec(int vertex, vector<int>& circuit);

    /**
     * @brief essa função conta quantos vertices são alcançaveis a partir do vertice de entrada
     * 
     * @param vertex vertice de inicio
     * @param visited vertices ja visitados
     * @return int quantos vertices forem alcançados
     */
    int DFSCnt(int vertex,  vector<bool>& visited);

    /**
     * @brief marca, sem removê-la do grafom uma aresta para não usa-la na função seguinte
     * 
     * @param v1 um extremo da aresta
     * @param v2 o outro extremo da aresta
     */
    void mark_edge(int v1, int v2);

    /**
     * @brief desmarca a marcação da função 'mark_edge'
     * 
     * @param v1 um extremo da aresta
     * @param v2 o outro extremo da aresta
     */
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
};

#endif