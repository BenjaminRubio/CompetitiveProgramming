#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

class Dinic
{
    struct Edge { int to, rev, f, c; };
    int n, t_; vector<vector<Edge>> G;
    vector<int> D, q, W;

    bool bfs(int s, int t)
    {
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l)
        {
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    int dfs(int u, int f)
    {
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i)
        {
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f or D[v] != D[u] + 1) continue;
            int df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int n) : n(n), G(n), D(n), q(n) {}
    void addEdge(int u, int v, int cap)
    {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size(), 0, 0});
    }
    int maxFlow(int s, int t)
    {
        t_ = t; int ans = 0;
        while (bfs(s, t)) while (int dl = dfs(s, INT_MAX)) ans += dl;
        return ans;
    }
};

int N, a, b;
vector<pair<int, int>> G;
vector<int> C;

int main()
{
    cin >> N;

    C.assign(N, 0);
    rep(i, N)
    {
        cin >> a >> b; a--, b--;
        C[a]++, C[b]++; G.emplace_back(a, b);
    }

    int ans = N;
    rep(i, N)
    {
        Dinic flow(2 * N + 2);
        rep(j, N) if (i != j)
        {
            flow.addEdge(0, j + 1, 1);
            if (G[j].ff != i && G[j].ss != i)
                flow.addEdge(j + 1, G[j].ff + N + 1, 1),
                flow.addEdge(j + 1, G[j].ss + N + 1, 1);
            if (j == G[i].ff || j == G[i].ss)
                flow.addEdge(j + N + 1, 2 * N + 1, C[i] - 2);
            else flow.addEdge(j + N + 1, 2 * N + 1, C[i] - 1);
        }
        if (flow.maxFlow(0, 2 * N + 1) == N - 1 - C[i]) ans--;
    }

    cout << ans << '\n';
}