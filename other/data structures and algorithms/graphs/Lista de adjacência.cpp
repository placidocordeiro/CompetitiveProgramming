#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4; 
    vector<vector<int>> grafo(n); // Lista de adjacência

    // Adicionar arestas
    grafo[0].push_back(1); // Aresta de 0 para 1
    grafo[0].push_back(2); // Aresta de 0 para 2
    grafo[1].push_back(2); // Aresta de 1 para 2
    grafo[2].push_back(3); // Aresta de 2 para 3
    grafo[3].push_back(0); // Aresta de 3 para 0

    // Mostrar a lista de adjacência
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int adj : grafo[i]) {
            cout << adj << " ";
        }
        cout << endl;
    }

    return 0;
}
