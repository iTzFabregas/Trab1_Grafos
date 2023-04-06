#include "../lib/graph.hpp"

using namespace std;

Graph::Graph(int v) {
    this->num_vert = v;
}

void Graph::add_edge(int v1, int v2) {
    graph_map[v1].push_back(v2);
    graph_map[v2].push_back(v1);
}

void Graph::sort() {
    for (int i = 0; i < num_vert; i++) {
        graph_map[i].sort();    
    }
}

void Graph::remove_edge(int v1, int v2) {
    list<int>::iterator iv1 = find(graph_map[v1].begin(), graph_map[v1].end(), v2);
    *iv1 = -1;
    list<int>::iterator iv2 = find(graph_map[v2].begin(), graph_map[v2].end(), v1);
    *iv2 = -1;
}   

void Graph::startEulerianCircuit() {
    vector<int> circuit;
    findEulerianCircuit(0, circuit);
    reverse(circuit.begin(), circuit.end());

    for (int v : circuit) {
        cout << v << " ";
    }
    cout << endl;
}

void Graph::findEulerianCircuit(int vertex, vector<int>& circuit) {

    for (int prox_v : graph_map[vertex]) {
        if (prox_v != -1) {
            remove_edge(vertex, prox_v);
            findEulerianCircuit(prox_v, circuit);
        }
    }
    circuit.push_back(vertex);
}

void Graph::DFS(int vertex1, vector<bool>& visited, vector<int>& degree) {
    visited[vertex1] = true;
    for (int vertex2 : graph_map[vertex1]) {
        degree[vertex1]++;
        if (!visited[vertex2]) {
            DFS(vertex2, visited, degree);
        }
    }
}

bool Graph::isEulerian() {
    vector<bool> visited(num_vert, false);
    vector<int> degree(num_vert, 0);

    // ENCONTRA O GRAU DE CADA VERTICE
    for (int vertex = 0; vertex < num_vert; vertex++) {
        if (!visited[vertex]) {
            DFS(vertex, visited, degree);
        }
    }

    // VERIFICA SE TEM ALGUM VERTICE COM GRAU IMPAR
    for (int d : degree) {
        if (d % 2 != 0) {
            return false;
        }
    }

    // VERIFICA SE O GRAFO É CONEXO
    visited.assign(num_vert, false);
    stack<int> stk;
    stk.push(0);
    visited[0] = true;
    int cnt = 1;
    while (!stk.empty()) {
        int vertex1 = stk.top();
        stk.pop();
        for (int vertex2 : graph_map[vertex1]) {
            if (!visited[vertex2]) {
                stk.push(vertex2);
                visited[vertex2] = true;
                cnt++;
            }
        }
    }
    return cnt == num_vert;
}
