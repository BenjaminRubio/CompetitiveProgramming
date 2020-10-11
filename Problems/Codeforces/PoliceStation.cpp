#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const int INF = 1e9;

struct Edge
{
    int v, w, i;
    Edge(int v, int w, int i) : v(v), w(w), i(i) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, M, u, v;
vector<int> C;
vector<bool> I, A;
vector<vector<int>> P;
vector<pair<int, int>> E;
vector<vector<Edge>> G, G_;

ll DP1[110], DP2[110];

ll dp2(int u)
{
    if (u == N - 1) return 1;
    if (DP2[u] != -1) return DP2[u];

    ll ans = 0;
    for (auto &e : G_[u]) ans += dp2(e.v);
    return DP2[u] = ans;
}

ll dp1(int u)
{
    if (u == N - 1) return 0;
    if (DP1[u] != -1) return DP1[u];

    ll ans = 0;
    for (auto &e : G_[u]) ans += dp1(e.v) + ll(A[e.i]) * dp2(e.v);
    return DP1[u] = ans;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N >> M;

    G.resize(N); G_.resize(N);
    rep(i, M)
    {
        cin >> u >> v; u--, v--;
        E.emplace_back(u, v), E.emplace_back(v, u);
        G[u].emplace_back(v, 1, 2 * i);
        G[v].emplace_back(u, 1, 2 * i + 1);
    }

    C.assign(N, INF); P.resize(N), I.assign(2 * M, 0);
    priority_queue<Edge> q;

    q.emplace(0, 0, 0); C[0] = 0;
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();

        if (C[u] < w) continue;

        for (auto e : G[u]) if (C[e.v] >= e.w + w)
        {
            bool normal = (C[e.v] > e.w + w);
            if (normal && !P[e.v].empty())
            {
                for (int x : P[e.v]) I[x] = 0;
                P[e.v].clear();
            }
            I[e.i] = 1, P[e.v].push_back(e.i);
            C[e.v] = e.w + w;
            if (normal) q.emplace(e.v, C[e.v], e.i);
        }
    }

    rep(i, 2 * M) if (I[i]) G_[E[i].ff].emplace_back(E[i].ss, 1, i);

    double ans = 0;
    rep(i, N)
    {
        A.assign(2 * M, 0);
        for (auto &e : G[i])
        {
            int id = e.i / 2;
            if (I[2 * id]) A[2 * id] = 1;
            if (I[2 * id + 1]) A[2 * id + 1] = 1;
        }

        memset(DP1, -1, sizeof DP1);
        memset(DP2, -1, sizeof DP2);
        ans = max(ans, dp1(0) / (double)dp2(0));
    }

    cout << ans << '\n';
}