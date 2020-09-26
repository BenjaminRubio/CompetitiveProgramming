#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

// PRIM //

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

int find_mst(vector<vector<Edge>> &g, vector<vector<Edge>> &mst)
{
    int n = g.size();
    vector<bool> V(n, false);
    mst.assign(n, {});

    int ans = 0, c = 1;
    V[0] = true;

    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for (Edge &p : g[0]) q.emplace(0, p.v, p.w);

    while (!q.empty())
    {
        Edge edge = q.top(); q.pop();

        if (V[edge.v]) continue;

        int u = edge.u, v = edge.v, w = edge.w;
        V[v] = true;
        ans += w;
        mst[u].emplace_back(u, v, w);
        mst[v].emplace_back(v, u, w);

        if (++c == n) break;

        for (Edge p : g[v]) if (!V[p.v]) q.emplace(v, p.v, p.w);
    }
    
    return ans;
}