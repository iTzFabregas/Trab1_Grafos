#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Graph {

private:
    int num_vert, num_edges;
    map<int, list<int>> graph_map;

    void remove_edge(int v1, int v2);

    bool isValidEdge(int v1, int v2);

    int DFSCnt(int vertex, vector<bool>& visited);

    void findEulerianCircuit(int vertex, list<int>& circuit);

public:
    Graph(int v);

    void add_edge(int v1, int v2);

    void print();

    void startEulerianCircuit();
};

#endif