#include <iostream>
#include <vector>

int main() {
    int n = 4;
    std::vector<std::vector<int>> grafo(n, std::vector<int>(n, 0)); // Matriz de adjacência

    // Adicionar arestas
    grafo[0][1] = 1; // Aresta de 0 para 1
    grafo[1][2] = 1; // Aresta de 1 para 2
    grafo[2][3] = 1; // Aresta de 2 para 3
    grafo[3][0] = 1; // Aresta de 3 para 0

    // Mostrar a matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << grafo[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
