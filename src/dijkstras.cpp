#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = -1;  // Using -1 to denote undefined

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source}); // {weight, vertex}

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& edge : G[u]) {
            int v = edge.dst; // or src
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> shortest_path;
    for (int current = destination; current != -1; current = previous[current]) {
        shortest_path.push_back(current);
    }

    reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    for (auto num: v) {
        cout << num << endl;
    }
    cout << "Total is " << total << endl;
}