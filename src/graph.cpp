#include "../lib/graph.hpp"

using namespace std;

Graph::Graph(int v) {
    this->num_vert = v;
    for (int i = 0; i < v; i++)
    {
        graph_map[i] = {};
    }
    
}

void Graph::add_edge(int v1, int v2) {

    graph_map[v1].push_back(v2);
    graph_map[v2].push_back(v1);
}

void Graph::sort(int v1, int v2) {
    graph_map[v1].sort();
    graph_map[v2].sort();
}

void Graph::remove_edge(int v1, int v2) {
    list<int>::iterator iv1 = find(graph_map[v1].begin(), graph_map[v1].end(), v2);
    *iv1 = -1;
    list<int>::iterator iv2 = find(graph_map[v2].begin(), graph_map[v2].end(), v1);
    *iv2 = -1;
}

void Graph::print() {
    for (auto it = graph_map.begin(); it != graph_map.end(); it++)
    {   
        cout << ">>" << it->first << endl;
        
        for (auto x : it->second)
        {
            cout << x << " ";
        }
        cout << endl;   
    }
}

void Graph::startEulerianCircuit() {
    vector<int> circuit;
    circuit.push_back(0);
    findEulerianCircuit(0, circuit);

    if (circuit.back() == 0) {
        cout << "Sim" << endl;
        for (int v : circuit) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "Não";
    }
}

void Graph::findEulerianCircuit(int vertex, vector<int>& circuit) {

    for (int prox_v : graph_map[vertex]) {
        if (prox_v != -1) {
            circuit.push_back(prox_v);
            remove_edge(vertex, prox_v);
            findEulerianCircuit(prox_v, circuit);
        }

    }
    
}
