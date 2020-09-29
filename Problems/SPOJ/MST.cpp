#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

int N, M, u, v, w;
vector<vector<Edge>> G;

int main()
{
    cin >> N >> M;

    G.assign(N, {});
    rep(i, M)
    {
        cin >> u >> v >> w; u--, v--;
        G[u].emplace_back(u, v, w);
        G[v].emplace_back(v, u, w);
    }

    vector<bool> V(N, 0);

    long long ans = 0, c = 1; V[0] = 1;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for (Edge &p : G[0]) q.emplace(0, p.v, p.w);

    while (!q.empty())
    {
        Edge e = q.top(); q.pop();

        if (V[e.v]) continue;

        int u = e.u, v = e.v, w = e.w;
        V[v] = true, ans += w;

        if (++c == N) break;

        for (Edge &p : G[v]) if (!V[p.v]) q.emplace(v, p.v, p.w);
    }
    
    cout << ans << '\n';
}