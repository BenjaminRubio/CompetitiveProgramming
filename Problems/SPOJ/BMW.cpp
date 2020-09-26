#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Edge
{
    int u, v; ll w;
    Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &e) const { return w < e.w; }
};

int tt, N, M, A, B; ll V;
vector<vector<Edge>> G, T;
vector<bool> U;

ll dfs(int u, int p, int d)
{
    if (u == d) return LLONG_MAX;
    ll ans = LLONG_MIN;
    for (Edge &e : T[u]) if (e.v != p)
        ans = max(ans, min(e.w, dfs(e.v, u, d)));
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> tt;
    while (tt--)
    {
        cin >> N >> M;

        G.assign(N, {});
        rep(_, M)
        {
            cin >> A >> B >> V; A--, B--;
            G[A].emplace_back(A, B, V);
            G[B].emplace_back(B, A, V);
        }

        U.assign(N, false);
        T.assign(N, {});

        int c = 1; U[0] = true;

        priority_queue<Edge> q;
        for (Edge &p : G[0]) q.emplace(0, p.v, p.w);

        while (!q.empty())
        {
            Edge e = q.top(); q.pop();

            if (U[e.v]) continue;

            int u = e.u, v = e.v; ll w = e.w; U[v] = true;
            T[u].emplace_back(u, v, w);
            T[v].emplace_back(v, u, w);

            if (++c == N) break;

            for (Edge &p : G[v]) if (!U[p.v]) q.emplace(v, p.v, p.w);
        }

        ll ans = dfs(0, -1, N - 1);
        if (ans >= 0) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}