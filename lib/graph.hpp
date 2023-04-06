#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

class Graph {

private:
    int num_vert, num_edges;
    map<int, list<int>> graph_map;

    void remove_edge(int v1, int v2);

    void findEulerianCircuit(int vertex, vector<int>& circuit);

    void DFS(int v, vector<bool>& visited, vector<int>& degree);

public:
    Graph(int v);

    void add_edge(int v1, int v2);

    void sort();

    void print();

    void startEulerianCircuit(vector<int>& circuit);

    bool isEulerian();
};

#endif