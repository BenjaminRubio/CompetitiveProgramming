#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, u, v;
string S;
vector<vector<int>> G;
vector<bool> V, A;

bool dfs(int u)  // Detects if there is a cycle in G
{
    V[u] = A[u] = 1;
    bool ans = false;
    for (int v : G[u])
    {
        if (A[v]) return true;
        if (!V[v]) ans |= dfs(v);
    }
    A[u] = 0;
    return ans;
}

int DP[300010][27];

int dp(int u, int c)
{
    if (DP[u][c] != -1) return DP[u][c];

    bool b = (S[u] - 'a') == c;

    int ans = b;
    for (int v : G[u]) ans = max(ans, dp(v, c) + b);

    return DP[u][c] = ans;
}

int main()
{
    cin >> N >> M >> S;

    G.assign(N, {});
    // Load graph with reverse edges
    rep(i, M) { cin >> u >> v; u--, v--; G[v].push_back(u); }

    bool cycle = false;
    V.assign(N, false); A.assign(N, false);
    rep(i, N) if (!V[i]) cycle |= dfs(i);

    if (cycle) { cout << -1 << '\n'; return 0; }

    memset(DP, -1, sizeof DP);

    int ans = 0;
    rep(i, N) rep(j, 27) ans = max(ans, dp(i, j));

    cout << ans << '\n';
}