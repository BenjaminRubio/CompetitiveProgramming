#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

int n;
vector<vector<Edge>> g;

int dijkstra(int s, int t)
{
    vector<int> cost(n, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;

    q.emplace(s, 0);
    cost[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();

        if (cost[u] < w) continue;

        for (auto e : g[u]) if (cost[e.v] > e.w + w)
        {
            cost[e.v] = e.w + w;
            q.emplace(e.v, cost[e.v]);
        }
    }
    return cost[t];
}