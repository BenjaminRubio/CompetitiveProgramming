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
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            int df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, int cap)
    {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0});
    }
    int maxFlow(int s, int t)
    {
        t_ = t; int ans = 0;
        while (bfs(s, t)) while (int dl = dfs(s, INT_MAX)) ans += dl;
        return ans;
    }
};

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, M, S, u, v, t;
vector<int> T, C, D;
vector<vector<Edge>> G;
vector<pair<int, int>> E, V;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> S;

    G.resize(N);
    rep(_, M)
    {
        cin >> u >> v >> t; u--, v--;
        G[u].emplace_back(v, t), G[v].emplace_back(u, t);
    }

    C.resize(S);
    rep(i, S) { cin >> u; C[i] = u - 1; }

    D.assign(N, INT_MAX); D[0] = 0;
    priority_queue<Edge> q; q.emplace(0, 0);
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();
        if (D[u] < w) continue;
        for (auto e : G[u]) if (D[e.v] > e.w + w)
            D[e.v] = e.w + w, q.emplace(e.v, D[e.v]);
    }

    rep(u, N) for (Edge &e : G[u]) if (D[e.v] == D[u] + e.w)
        E.emplace_back(e.v + 1, u + 1);

    rep(i, S) V.emplace_back(D[C[i]], C[i] + 1);
    sort(V.begin(), V.end());

    int ans = 0, i = 0, j = 0;
    while ((i = j) < S)
    {
        Dinic flow(N + 1);
        while (j < S && V[j].ff == V[i].ff) flow.addEdge(0, V[j].ss, 1), j++;
        for (auto &e : E) flow.addEdge(e.ff, e.ss, 1);

        ans += flow.maxFlow(0, 1);
    }

    cout << ans << '\n';
}