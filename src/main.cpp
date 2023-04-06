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

    int vertices, edges;
    file >> vertices >> edges;

    // INICIALIZA O GRAFO
    Graph graph(vertices);

    // LE TODAS AS ARESTAS
    int v1, v2;
    for (int i = 0; i < edges; i++) {
        file >> v1 >> v2;
        graph.add_edge(v1, v2);
    }
    graph.sort();
    // graph.print();

    // FECHA O ARQUIVO DE ENTRADA
    file.close();

    // ALGORITMO PARA VER SE TEM UM CIRCUITO EULERIANO
    // SE TIVER, ALGORITMO PARA ACHÁ-LO
    if (graph.isEulerian()){
        cout << "Sim" << endl;

        vector<int> circuit;
        graph.startEulerianCircuit(circuit);

        for (int v : circuit) {
            cout << v << " ";
        }
    } else {
        cout << "Não";
    }
    cout << endl;
}   