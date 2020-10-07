#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, u, v, rc;
vector<vector<int>> G;
vector<int> D, L;
set<int> ans;

void dfs(int u, int p, int d)
{
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            dfs(v, u, d + 1);
            if ((p == -1 && ++rc == 2) || (p != -1 && L[v] >= d)) ans.insert(u);
            L[u] = min(L[u], L[v]);
        }
        else if (D[v] < d) L[u] = min(L[u], D[v]);
    }
}

int main()
{
    while (cin >> N >> M && N)
    {
        G.assign(N, {});
        rep(_, M)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }

        D.assign(N, -1); L.resize(N);
        rep(u, N) if (D[u] == -1) rc = 0, dfs(u, -1, 0);

        cout << ans.size() << '\n'; ans.clear();
    }
}