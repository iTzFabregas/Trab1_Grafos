#include "../lib/graph.hpp"

using namespace std;

Graph::Graph(int v) {
    this->num_vert = v;
    this->num_edges = 0;
    
}

void Graph::add_edge(int v1, int v2) {

    this->graph_map[v1].push_back(v2);
    graph_map[v1].sort();
    this->graph_map[v2].push_back(v1);
    graph_map[v2].sort();

    this->num_edges++;
}

void Graph::remove_edge(int v1, int v2) {
    list<int>::iterator it = find(graph_map[v1].begin(), graph_map[v1].end(), v2);
    this->graph_map[v1].erase(it);
    it = find(graph_map[v2].begin(), graph_map[v2].end(), v1);
    this->graph_map[v2].erase(it);

    this->num_edges--;
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
    list<int> circuit;
    findEulerianCircuit(0, circuit);

    for (int v : circuit) {
        cout << v << " ";
    }
    cout << endl;
}

int Graph::DFSCnt(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    int cnt = 1;

    for (int prox_v : graph_map[vertex]){

        //if (graph_map[prox_v].size() == 1) {
        //    continue;
        //}

        if (!visited[prox_v]) {
            cnt += DFSCnt(prox_v, visited);
        }
    }
    return cnt;
}

bool Graph::isValidEdge(int v1, int v2) {
    if (graph_map[v1].size() == 1) {
        return true;
    }

    vector<bool> visited(num_vert, false);
    int cnt1 = DFSCnt(v1, visited);
    remove_edge(v1, v2);
    visited.assign(num_vert, false);
    int cnt2 = DFSCnt(v1, visited);
    add_edge(v1, v2);

    return (cnt1 <= cnt2);
}

void Graph::findEulerianCircuit(int vertex, list<int>& circuit) {

    for (int prox_v : graph_map[vertex]) {
            cout << vertex << " " << prox_v << endl;
        if (isValidEdge(vertex, prox_v)) {
            remove_edge(vertex, prox_v);
            findEulerianCircuit(prox_v, circuit);
        }

    }
    circuit.push_back(vertex);
}
