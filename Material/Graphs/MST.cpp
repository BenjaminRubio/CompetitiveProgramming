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
    vector<bool> visited(n, false);
    mst.assign(n, vector<Edge>());

    int total_cost = 0, count = 1;
    visited[0] = true;

    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for (Edge &p : g[0]) q.emplace(0, p.v, p.w);

    while (!q.empty())
    {
        Edge edge = q.top(); q.pop();

        if (visited[edge.v]) continue;

        int u = edge.u, v = edge.v, cost = edge.w;
        visited[v] = true;
        total_cost += cost;
        mst[u].emplace_back(v, cost);
        mst[v].emplace_back(u, cost);

        if (++count == n) break;

        for (Edge p : g[v]) if (!visited[p.v]) q.emplace(v, p.v, p.w);
    }
    
    return total_cost;
}