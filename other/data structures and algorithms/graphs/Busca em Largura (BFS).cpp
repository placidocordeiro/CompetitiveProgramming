#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& grafo) {
    int n = grafo.size();
    vector<bool> visitado(n, false);
    queue<int> fila;

    visitado[start] = true;
    fila.push(start);

    while (!fila.empty()) {
        int v = fila.front();
        fila.pop();
        cout << v << " ";

        for (int adj : grafo[v]) {
            if (!visitado[adj]) {
                visitado[adj] = true;
                fila.push(adj);
            }
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> grafo(n);
    grafo[0] = {1, 2};
    grafo[1] = {2};
    grafo[2] = {0, 3};
    grafo[3] = {3};

    bfs(0, grafo);
    return 0;
}
