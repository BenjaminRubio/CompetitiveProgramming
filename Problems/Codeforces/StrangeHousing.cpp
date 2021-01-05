#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M, u, v;
vector<int> C, V;
vector<vector<int>> G;

void dfs(int u, int p)
{
    V[u] = 1;
    if (C[u] == -1 && p == 0)
    {
        C[u] = 1;
        for (int v : G[u]) C[v] = 0;
    }
    else C[u] = 0;
    for (int v : G[u]) if (!V[v]) dfs(v, C[u]);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        G.assign(N, {});
        rep(_, M)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }

        C.assign(N, -1); V.assign(N, 0);
        dfs(0, 0);

        bool flag = 0;
        rep(i, N) flag |= (C[i] == -1);

        if (flag) cout << "NO\n";
        else
        {
            cout << "YES\n";
            
            int ans = 0;
            rep(i, N) if (C[i] == 1) ans++;

            cout << ans << '\n';
            rep(i, N) if (C[i] == 1) cout << i + 1 << ' ';
            cout << '\n';
        }
    }
}