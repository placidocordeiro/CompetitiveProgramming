#include <iostream>
#include <vector>
#include <queue>
#include <climits> // To use INT_MAX

// Function to execute Dijkstra's algorithm
void dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>>& graph) {
    int n = graph.size();
    std::vector<int> dist(n, INT_MAX); // Distances from start to each vertex
    dist[start] = 0;

    for(auto distance : dist) {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    // Priority queue (min-heap): {distance, vertex}
    std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>,
        std::greater<>
        > pq;
    pq.push({dist[start], start}); // Initial distance to the start vertex is 0

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        // Ignore if we found a better path earlier
        if (d > dist[v]) continue;

        // Explore the neighbors of the current vertex
        for (const auto& [neighbor, weight] : graph[v]) {
            if (dist[v] + weight < dist[neighbor]) {
                dist[neighbor] = dist[v] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print the calculated distances
    std::cout << "Distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        std::cout << "To " << i << ": " << (dist[i] == INT_MAX ? "inaccessible" : std::to_string(dist[i])) << "\n";
    }
}

int main() {
    int n = 5;
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    // Add edges (u, v, weight)
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({4, 7});
    graph[3].push_back({4, 9});

    int start = 0;

    dijkstra(start, graph);

    return 0;
}
