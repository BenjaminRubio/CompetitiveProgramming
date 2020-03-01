#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> depth;

void bfs(int s)
{
    queue<int> q; q.push(s);
    depth.assign(n, -1); depth[s] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (depth[v] == -1)
        {
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }
}