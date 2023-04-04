#include <iostream>
#include <fstream>

#include "../lib/graph.hpp"

using namespace std;

int main(void) {

    // LE O NOME DO ARQUIVO DE ENTRADA
    char filename[16];
    cin >> filename;

    // ABRE O ARQUIVO DE ENTRADA
    ifstream file;
    file.open(filename, ios::in);

    int v, a;
    file >> v >> a;
    cout << v << a;

    // INICIALIZA O GRAFO
    Graph graph(v);

    // LE TODAS AS ARESTAS
    int v1, v2;
    for (size_t i = 0; i < v; i++) {
        file >> v1 >> v2;
        graph.add_edge(v1, v2);
    }
    
    // ALGORITMO PARA ENCONTRAR O CIRCUITO EULERIANO

    file.close();


}   