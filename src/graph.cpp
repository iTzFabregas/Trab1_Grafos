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

bool Graph::isBridge(int vertex1, int vertex2) {

    int cnt = 0;
    for (int i : graph_map[vertex1]) {
        if (i >= 0) {
            cnt++;
        }
    }
    // SE ESSA FOR A UNICA ARESTA SAINDO DESSE VERTICE, TERA QUE SER ESSA ARESTA
    if (cnt == 1) {
        return true;
    }
    
    vector<bool> visited(num_vert, false);
    int cnt1 = DFSCnt(vertex1, visited);
    
    mark_edge(vertex1, vertex2);
    visited.assign(num_vert, false);
    int cnt2 = DFSCnt(vertex1, visited);
 
    unmark_edge(vertex1, vertex2);

    // 2.d) If count1 is greater, then edge (u, v) is a
    // bridge
    return (cnt1 > cnt2) ? false : true;
}

void Graph::mark_edge(int v1, int v2) {
    list<int>::iterator iv1 = find(graph_map[v1].begin(), graph_map[v1].end(), v2);
    *iv1 = -2;
    list<int>::iterator iv2 = find(graph_map[v2].begin(), graph_map[v2].end(), v1);
    *iv2 = -2;
}

void Graph::unmark_edge(int v1, int v2) {
    list<int>::iterator iv1 = find(graph_map[v1].begin(), graph_map[v1].end(), -2);
    *iv1 = v2;
    list<int>::iterator iv2 = find(graph_map[v2].begin(), graph_map[v2].end(), -2);
    *iv2 = v1;
}


int Graph::DFSCnt(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    int cnt = 1;
 
    for (int prox_v : graph_map[vertex]) {  
        if (prox_v >= 0 && !visited[prox_v]) {
            cnt += DFSCnt(prox_v, visited);
        }
    }
    return cnt;
}

void Graph::EulerianCircuit() {
    vector<int> circuit;
    circuit.push_back(0);
    EulerianCircuitRec(0, circuit);

    for (int v : circuit) {
        cout << v << " ";
    }
    cout << endl;
}


void Graph::EulerianCircuitRec(int vertex, vector<int>& circuit) {

    for (int prox_v : graph_map[vertex]) {
        if (prox_v >= 0 && isBridge(vertex, prox_v)) {
            circuit.push_back(prox_v);
            remove_edge(vertex, prox_v);
            EulerianCircuitRec(prox_v, circuit);
        }
    }
}







bool Graph::isEulerian() {

    // VERIFICA SE TEM ALGUM VERTICE COM GRAU IMPAR
    for (int vertex = 0; vertex < num_vert; vertex++) {
        int d = graph_map[vertex].size();
        if (d % 2 != 0) {
            return false;
        }
    }

    // TENDO EM VISTA QUE TODOS OS GRAFOS SAO CONEXOS, ENTAO É SÓ VERIFICAR O GRAU DOS VERTICES
    return true;
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