#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, u, v; char c;
vector<vector<pair<int, int>>> G;

int DP[110][110][2][30];

bool dp(int u, int v, int t, int p)
{
    if (DP[u][v][t][p] != -1) return DP[u][v][t][p];

    if (t == 0) for (auto &e : G[u]) if (p <= e.ss)
        if (dp(e.ff, v, t ^ 1, e.ss) == t) return DP[u][v][t][p] = t; 
    if (t == 1) for (auto &e : G[v]) if (p <= e.ss)
        if (dp(u, e.ff, t ^ 1, e.ss) == t) return DP[u][v][t][p] = t;

    return DP[u][v][t][p] = t ^ 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    G.resize(N);
    rep(_, M)
    {
        cin >> u >> v >> c; u--, v--;
        G[u].emplace_back(v, c - 'a' + 1);
    }

    memset(DP, -1, sizeof DP);
    rep(i, N)
    {
        rep(j, N) cout << (dp(i, j, 0, 0) ? 'B' : 'A');
        cout << '\n';
    }
}