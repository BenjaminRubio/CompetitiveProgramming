#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int C, P, u, v;
vector<vector<int>> g;
vector<int> D;

int dfs(int u)
{
    int ans = 0;
    for (int v : g[u]) if (D[v] == 1) ans += dfs(v);
    return ans + 1;
}

int main()
{
    while (cin >> C >> P)
    {
        g.assign(C, {});
        D.assign(C, 0);

        rep(i, P)
        {
            cin >> u >> v; u--; v--;
            g[u].push_back(v); D[v]++;
        }

        int ans = 0;
        for (int v : g[0]) if (D[v] == 1) ans += dfs(v) * (C - dfs(v) - 1);
        rep(i, C) if (D[i] > 1) ans += dfs(i) * (C - dfs(i) - 1);

        cout << ans / 2 + C - 1 << '\n';
    }
}