#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph {

private:
    int num_vert;
    map<int, list<int>> graph_map;

public:
    Graph(int v);

    ~Graph();

    void add_edge(int v1, int v2);
};

#endif