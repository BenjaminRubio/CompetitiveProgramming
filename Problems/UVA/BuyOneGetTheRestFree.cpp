#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

class Dinic
{
    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vector<ll> D; vector<int> q, W;

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
    ll dfs(int u, ll f)
    {
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i)
        {
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f or D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int n) : n(n), G(n), D(n), q(n) {}
    void addEdge(int u, int v, ll cap)
    {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size(), 0, 0}); // cap if bidirectional
    }
    ll maxFlow(int s, int t)
    {
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

struct Flight { int u, v, c, p, e; };

int T, N, D, M, u, v, c, p, e;
vector<Flight> F; vector<int> Z;

int main()
{
    cin >> T;
    rep(tt, T)
    {
        cin >> N >> D >> M; F.clear();

        rep(_, M)
        {
            cin >> u >> v >> c >> p >> e; u--, v--;
            F.push_back({u, v, c, p, e});
        }

        int s = 0; Z.resize(N);
        rep(i, N) { cin >> Z[i]; s += Z[i]; }

        int l = 0, r = 5000000;
        while (l < r)
        {
            int m = (l + r) / 2;

            Dinic flow(N * (D + 1) + 1);

            for (Flight f : F) if (f.p <= m)
                flow.addEdge(N * f.e + f.u + 1, N * (f.e + 1) + f.v + 1, f.c);
            rep(i, N) rep(d, D) flow.addEdge(N * d + i + 1, N * (d + 1) + i + 1, 1e9);
            rep(i, N) flow.addEdge(0, i + 1, Z[i]);

            if (flow.maxFlow(0, N * D) >= s) r = m;
            else l = m + 1;
        }

        cout << "Case #" << tt + 1 << ": ";
        if (l < 5000000) cout << l << '\n';
        else cout << "Impossible\n";
    }
}