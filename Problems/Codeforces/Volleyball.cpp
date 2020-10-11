#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll INF = 1e17;

struct Edge
{
    int v; ll w;
    Edge(int v, ll w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, M, u, v, s, d; ll t;
vector<vector<Edge>> G, G_;
vector<ll> A, B, C;

int main()
{
    cin >> N >> M >> s >> d; s--, d--;

    G.resize(N); G_.resize(N);
    rep(_, M)
    {
        cin >> u >> v >> t; u--, v--;
        G[u].emplace_back(v, t); G[v].emplace_back(u, t);
    }

    A.resize(N); B.resize(N);
    rep(i, N) cin >> B[i] >> A[i];

    rep(u, N)
    {
        C.assign(N, INF);
        priority_queue<Edge> q;

        q.emplace(u, 0); C[u] = 0;
        while (!q.empty())
        {
            int v = q.top().v; ll w = q.top().w; q.pop();

            if (C[v] < w) continue;

            for (auto e : G[v]) if (C[e.v] > e.w + w)
            {
                C[e.v] = e.w + w;
                q.emplace(e.v, C[e.v]);
            }
        }

        rep(v, N) if (u != v && C[v] <= B[u]) G_[u].emplace_back(v, A[u]);
    }

    C.assign(N, INF);
    priority_queue<Edge> q;

    q.emplace(s, 0); C[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v; ll w = q.top().w; q.pop();

        if (C[u] < w) continue;

        for (auto e : G_[u]) if (C[e.v] > e.w + w)
        {
            C[e.v] = e.w + w;
            q.emplace(e.v, C[e.v]);
        }
    }

    if (C[d] > 1e16) cout << -1 << '\n';
    else cout << C[d] << '\n';
}