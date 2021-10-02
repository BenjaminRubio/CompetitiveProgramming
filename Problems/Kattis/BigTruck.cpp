#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 1e9;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, M, u, v, w;
vector<vector<Edge>> G, D;
vi T;

int DP[101];

int dp(int u)
{
    if (DP[u] != -1) return DP[u];

    int ans = 0;
    for (Edge e : D[u]) ans = max(ans, dp(e.v));

    return DP[u] = ans + T[u];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    T.resize(N); rep(i, N) cin >> T[i];

    cin >> M;

    G.resize(N);
    rep(_, M)
    {
        cin >> u >> v >> w; u--, v--;
        G[u].eb(v, w), G[v].eb(u, w);
    }

    vi C(N, INF); C[N - 1] = 0;
    priority_queue<Edge> q; q.emplace(N - 1, 0);
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();
        if (C[u] < w) continue;
        for (auto e : G[u]) if (C[e.v] > e.w + w)
            C[e.v] = e.w + w, q.emplace(e.v, C[e.v]);
    }

    if (C[0] == INF) { cout << "impossible\n"; return 0; }

    D.resize(N);
    rep(u, N) for (Edge e : G[u]) if (C[e.v] + e.w == C[u]) D[u].pb(e);

    memset(DP, -1, sizeof DP);

    cout << C[0] << ' ' << dp(0) << '\n';
}
