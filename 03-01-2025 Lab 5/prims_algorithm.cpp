#include <bits/stdc++.h>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < key.size(); v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n";
    cout << "Edge \tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < graph.size(); i++) {
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << "\n";
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";
}

void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        if (u == -1) {
            cout << "Error: The graph is not fully connected!\n";
            return;
        }
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
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

    primMST(graph);
    return 0;
}
