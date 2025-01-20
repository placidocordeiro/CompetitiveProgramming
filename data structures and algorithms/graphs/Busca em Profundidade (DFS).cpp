#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, const vector<vector<int>>& grafo, vector<bool>& visitado) {
    visitado[v] = true;
    cout << v << " ";

    for (int adj : grafo[v]) {
        if (!visitado[adj]) {
            dfs(adj, grafo, visitado);
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

    vector<bool> visitado(n, false);
    dfs(0, grafo, visitado);

    return 0;
}
