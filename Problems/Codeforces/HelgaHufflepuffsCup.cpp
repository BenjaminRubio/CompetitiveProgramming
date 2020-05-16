#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, u, v;
vector<vector<int>> G, G_, E;
vector<bool> V, E_;
int id;

void dfs(int u)
{
    V[u] = true;
    for (int v : G[u]) if (!V[v])
    {
        E[u].push_back(id);
        E_[id] = u; id++;
    }
    for (int v : G[u]) if (!V[v])
    {
        G_[u].push_back(v);
        dfs(v);
    }
}

const int MOD = 1e9 + 7;

int DP1[100001][11][3];
int dp1(int u, int x, int p)
{
    if (DP1[u][x][p] != -1) return DP1[u][x][p];

    int ans = 0;
    if (p == 0) ans = (ans + dp2(E[u][0], x, p)) % MOD;
    if (p == 1) ans = (ans + dp2(E[u][0], x, p)) % MOD;
    if (p == 2) ans = (ans + dp2(E[u][0], x, p)) % MOD;

    return DP1[u][x][p] = ans;
}

int DP2[100001][11][3];
int dp2(int e, int x, int p)
{
    if (DP2[e][x][p] != -1) return DP2[e][x][p];

    int ans = 0;
    rep(i, x) ans = (ans + dp2(e + 1, x - i, p) + 
                     dp1(G[e - G[E_[e]][0]], i, p)) % MOD;
}

int main()
{
    cin >> N >> M;

    G.assign(N, {}); G_.assign(N, {}); E.assign(N, {}); E_.resize(N);
    rep(i, N - 1)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    id = 0;
    dfs(0);
    swap(G, G_);


}