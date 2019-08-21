#include <bits/stdc++.h>
using namespace std;

int n, m, q, u, v, w;
int graph[150][150];
int dist[150][150];

void floydWarshall() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j] &&
                    dist[i][k] != 1e9                    &&
                    dist[k][j] != 1e9)
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    while (true) {
        cin >> n >> m >> q;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) graph[i][j] = 0;
                else graph[i][j] = 1e9;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u][v] = min(graph[u][v], w);
        }
        floydWarshall();
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j] &&
                        dist[i][k] != 1e9                    &&
                        dist[k][j] != 1e9)
                        dist[i][j] = -1e9;
        for (int i = 0; i < q; i++) {
            cin >> u >> v;
            if (dist[u][v] == 1e9) cout << "Impossible\n";
            else if (dist[u][v] == -1e9) cout << "-Infinite\n";
            else cout << dist[u][v] << '\n';
        }
        cout << '\n';
    }
}
