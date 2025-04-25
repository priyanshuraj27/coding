#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void kruskalMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<pair<int, pair<int, int>>> edges;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({graph[i][j], {i, j}});
            }
        }
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    vector<pair<int, int>> mstEdges;
    int totalWeight = 0;

    for (auto &edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mstEdges.push_back({u, v});
            totalWeight += weight;
        }
    }

    // Check if we have a valid MST
    if (mstEdges.size() != V - 1) {
        cout << "Error: The graph is not fully connected!\n";
        return;
    }

    cout << "\nMinimum Spanning Tree (MST) using Kruskal's Algorithm:\n";
    cout << "Edge \tWeight\n";
    for (auto &edge : mstEdges)
        cout << edge.first << " - " << edge.second << " \t" << graph[edge.first][edge.second] << "\n";

    cout << "Total Weight of MST: " << totalWeight << "\n";
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    kruskalMST(graph);
    return 0;
}
