#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Dinic
{
    struct Edge
    {
        int to, rev; ll f, c;
        Edge(int to, int rev, ll f, ll c) : to(to), rev(rev), f(f), c(c) {}
    };

    int n, sink;
    vector<vector<Edge>> g;
    vector<ll> dist;
    vector<int> q, work;

    bool bfs(int start, int finish)
    {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail)
        {
            int u = q[head++];
            for (const Edge &e : g[u]) if (dist[e.to] == -1 and e.f < e.c)
            {
                dist[e.to] = dist[u] + 1;
                q[tail++] = e.to;
            }
        }
        return dist[finish] != -1;
    }

    ll dfs(int u, ll f)
    {
        if (u == sink) return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i)
        {
            Edge &e = g[u][i];
            int v = e.to;
            if (e.c <= e.f or dist[v] != dist[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

public:
    Dinic(int n) : n(n), g(n), dist(n), q(n) {}

    void add_Edge(int u, int v, ll cap)
    {
        g[u].emplace_back(v, (int)g[v].size(), 0, cap);
        g[v].emplace_back(u, (int)g[u].size(), 0, 0); // cap si bidireccional
    }

    ll max_flow(int source, int dest)
    {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest))
        {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX)) ans += delta;
        }
        return ans;
    }
};