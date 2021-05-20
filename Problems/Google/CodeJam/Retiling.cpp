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

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int R, C, F, S;
char M[11][11], W[11][11];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

class Dinic
{
    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vl D; vi q, W;

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
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap)
    {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // cap if bidirectional
    }
    ll maxFlow(int s, int t)
    {
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

void test_case()
{
    cin >> R >> C >> F >> S;

    rep(i, R) rep(j, C) cin >> M[i][j];
    rep(i, R) rep(j, C) cin >> W[i][j];

    int ans = 0;
    rep(i, R) rep(j, C) ans += (M[i][j] != W[i][j]);

    Dinic dinic(R * C + 2);
    rep(i, R) rep(j, C)
    {
        if (!((i + j) & 1) && M[i][j] != W[i][j])
        {
            dinic.addEdge(0, 1 + i * C + j, 1);
            rep(k, 4)
            {
                int i_ = i + dr[k], j_ = j + dc[k];
                if (i_ >= 0 && i_ < R && j_ >= 0 && j_ < C)
                {
                    if (M[i_][j_] != W[i_][j_] && M[i][j] != M[i_][j_])
                    {
                        dinic.addEdge(1 + i * C + j, 1 + i_ * C + j_, 1);
                    }
                }
            }
        }
        else if (((i + j) & 1))
        {
            dinic.addEdge(1 + i * C + j, R * C + 1, 1);
        }
    }

    int flx = dinic.maxFlow(0, R * C + 1);
    // cerr << flx << endl;

    cout << F * ans - S * flx << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int num_tests; cin >> num_tests;
    rep(test, num_tests)
    {
        cout << "Case #" << test + 1 << ": ";
        test_case();
    }
}
