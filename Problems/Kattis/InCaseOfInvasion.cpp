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
        G[v].push_back({u, (int)G[u].size(), 0, 0});
    }
    ll maxFlow(int s, int t)
    {
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

struct Edge
{
    int v; ll w;
    Edge(int v, ll w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, M, S, u, v, w;
vector<ll> P, C, R, C_, C__;
vector<vector<Edge>> G;
vector<vector<ll>> D;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> S;

    P.resize(N); ll p = 0;
    rep(i, N) { cin >> P[i]; p += P[i]; }

    G.resize(N);
    rep(_, M)
    {
        cin >> u >> v >> w; u--, v--;
        G[u].emplace_back(v, w); G[v].emplace_back(u, w);
    }

    R.resize(S), C.resize(S);
    rep(i, S) { cin >> R[i] >> C[i]; R[i]--; }

    D.assign(N, vector<ll>(S));
    rep(s, S)
    {
        C_.assign(N, 1e17); int r = R[s];
        priority_queue<Edge> q; q.emplace(r, 0); C_[r] = 0;
        while (!q.empty())
        {
            int u = q.top().v; ll w = q.top().w; q.pop();
            if (C_[u] < w) continue;
            for (auto e : G[u]) if (C_[e.v] > e.w + w)
            {
                C_[e.v] = e.w + w;
                q.emplace(e.v, C_[e.v]);
            }
        }
        rep(u, N) D[u][s] = C_[u];
    }

    ll l = 0, r = 1e17;
    while (l < r)
    {
        ll m = (l + r) / 2ll;

        Dinic flow((1 << S) + S + 2);
        C__.assign((1 << S), 0);
        rep(u, N)
        {
            int mk = 0;
            rep(s, S) if (D[u][s] <= m) mk |= (1 << s);
            C__[mk] += P[u];
        }
        rep(mk, (1 << S)) flow.addEdge(0, mk + 1, C__[mk]);
        rep(mk, (1 << S)) rep(s, S) if (mk & (1 << s))
            flow.addEdge(mk + 1, s + 1 + (1 << S), 1e17);
        rep(s, S) flow.addEdge(s + 1 + (1 << S), (1 << S) + S + 1, C[s]);

        if (flow.maxFlow(0, (1 << S) + S + 1) == p) r = m;
        else l = m + 1;
    }

    cout << l << '\n';
}