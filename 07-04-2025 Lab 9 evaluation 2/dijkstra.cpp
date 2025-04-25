#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

void dijkstra(int V, vector<vector<int>>& matrix, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (int v = 0; v < V; ++v) {
            if (matrix[u][v] != 0) {
                int newDist = dist[u] + matrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }

    cout << "\nVertex\tDistance from Source " << src << "\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> matrix(V, vector<int>(V, 0));

    cout << "Enter the distance between each pair of vertices: (note: if no edge exists, write 0)\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i == j) {
                matrix[i][j] = 0;
                continue;
            }
            cout << "Distance from vertex " << i << " to vertex " << j << ": ";
            cin >> matrix[i][j];
        }
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(V, matrix, src);
    return 0;
}
