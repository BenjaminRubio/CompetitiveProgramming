#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int n, k, u, v;
vector<vector<int>> G;
vector<bool> V;
vector<int> H, D;

int dfs(int u, int h)
{
    H[u] = h; V[u] = true;
    for (int v : G[u]) if (!V[v]) D[u] += dfs(v, h + 1) + 1;
    return D[u];
}

int main()
{
    cin >> n >> k;

    G.resize(n);
    rep(i, n - 1)
    {
        cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    V.assign(n, false); H.resize(n); D.assign(n, 0);
    dfs(0, 0);

    vector<int> A(n);
    rep(i, n)
    {
        A[i] = H[i] - D[i];
        // cerr << H[i] << ' ' << D[i] << '\n';
    }
    sort(A.begin(), A.end(), greater<int>());

    ll ans = 0;
    rep(i, k) ans += A[i];

    cout << ans << '\n';
}