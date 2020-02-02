#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back

struct edge
{
    int to, w;
    edge(int v, int weight) { to = v; w = weight; }
};

struct Centroid
{
    int n;
    vector<vector<edge>> G;
    vector<int> ST, parent;
    vector<bool> visited;

    Centroid(int size)
    {
        n = size;
        G.resize(n);
        ST.assign(n, 1);
        visited.assign(n, false);
        parent.reserve(n);
    }

    void add(int u, int v, int w)
    {
        G[u].eb(v, w); G[v].eb(u, w);
    }

    int dfs(int u, int p)
    {
        for (edge v : G[u]) if (v.to != p)
            ST[u] += dfs(v.to, u);
        return ST[u];
    }

    void make(int u = 0, int p = -1, int size = -1)
    {
        if (size < 0) size = dfs(u, -1);
        for (edge v : G[u]) if (!visited[v.to] && 2 * ST[v.to] >= size)
        {
            ST[u] = 0; make(v.to, p, size); return;
        }
        visited[u] = true; parent[u] = p;
        for (edge v : G[u]) if (!visited[v.to]) make(v.to, u);
    }
};

int n, u, v, w;
vector<int> values;

int main()
{
    cin >> n;

    Centroid CD(n);
    rep(i, n - 1)
    {
        cin >> u >> v >> w;
        CD.add(u - 1, v - 1, w);
    }

    CD.make();

    
}
