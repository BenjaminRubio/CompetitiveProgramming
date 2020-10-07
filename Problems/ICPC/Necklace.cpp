#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, u, v, s, t;
vector<pair<int, int>> C;
vector<multiset<int>> G;
vector<int> D, L;

void dfs(int u, int p, int d)
{
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            dfs(v, u, d + 1);
            if (L[v] > D[u]) C.emplace_back(u, v);
            L[u] = min(L[u], L[v]);
        }
        else L[u] = min(L[u], D[v]);
    }
}

bool find(int u)
{
    D[u] = 1; if (u == t) return 1;
    bool ans = 0;
    for (int v : G[u]) if (D[v] == -1) ans |= find(v);
    return ans;
}

int main()
{
    int c = 0;
    while (cin >> N >> M && N)
    {
        G.assign(N, {});
        rep(_, M)
        {
            cin >> u >> v; u--, v--;
            G[u].insert(v); G[v].insert(u);
        }

        cin >> s >> t; s--, t--;
        D.assign(N, -1); L.resize(N); C.clear();
        dfs(s, -1, 0);

        for (auto &e : C)
        {
            tie(u, v) = e;
            G[u].erase(G[u].find(v)); G[v].erase(G[v].find(u));
        }

        D.assign(N, -1);
        cout << "Case " << ++c << ": " << (find(s) ? "YES\n" : "NO\n");
    }
}