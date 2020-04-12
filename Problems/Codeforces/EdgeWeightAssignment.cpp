#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, u, v, M;
vector<int> D;
vector<bool> V, B;
vector<vector<int>> G, G_;

void dfs(int u)
{
    V[u] = true;
    for (int v : G[u]) if (!V[v])
    {
        if (D[v] != 1)
        {
            G_[u].push_back(v);
            dfs(v);
            M++;
        }
        else if (!B[u]) B[u] = 1, M++;
    }
}

bool dfs2(int u, int c)
{
    bool ans = false;
    if (B[u] and c % 2) return true;
    for (int v : G_[u]) ans |= dfs2(v, c + 1);
    return ans;
}

int main()
{
    cin >> n;

    G.resize(n);
    D.assign(n, 0);
    V.assign(n, false);
    rep(i, n - 1)
    {
        cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        D[u]++; D[v]++;
    }

    int r;
    rep(i, n) if (D[i] == 1) r = i;

    M = 0;
    B.assign(n, false);
    G_.resize(n);
    dfs(G[r][0]);

    if (dfs2(G[r][0], 0)) cout << 3 << ' ' << M << '\n';
    else cout << 1 << ' ' << M << '\n';
}