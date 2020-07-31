#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N;
vector<vector<int>> D;
vector<vector<pair<int, int>>> G;

void add_node(int u, int e, int p)
{
    for (auto &v : G[u]) if (v.ff != p)
        if (D[v.ff][e] + v.ss == D[u][e]) { add_node(v.ff, e, u); return; }
    G[u].emplace_back(e, D[u][e]);
    G[e].emplace_back(u, D[u][e]);
}

int dfs(int u, int e, int p)
{
    if (u == e) return 0;
    for (auto &v : G[u]) if (v.ff != p)
    {
        int aux = dfs(v.ff, e, u);
        if (aux != -1) return aux + v.ss;
    }
    return -1;
}

bool check(int s, int u, int p, int d)
{
    if (D[s][u] != d) return false;
    for (auto &v : G[u]) if (v.ff != p)
        if (!check(s, v.ff, u, d + v.ss)) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cout.tie(0);

    cin >> N;

    D.assign(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> D[i][j];

    bool flag = true;
    rep(i, N) rep(j, N) if (D[i][j] != D[j][i] || (i != j && !D[i][j]))
        flag = false;
    rep(i, N) if (D[i][i]) flag = false;

    if (!flag) { cout << "NO\n"; return 0; }

    vector<pair<int, int>> v;
    rep(i, N) if (i) v.emplace_back(D[0][i], i);

    sort(v.begin(), v.end());

    G.assign(N, {});
    for (auto &e : v) add_node(0, e.ss, -1);

    rep(i, N) if (!check(i, i, -1, 0)) { cout << "NO\n"; return 0; }
    cout << "YES\n";
}
