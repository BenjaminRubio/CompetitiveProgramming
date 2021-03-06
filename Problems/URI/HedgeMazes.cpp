#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct DSU
{
    vector<int> p;
    DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

int R, C, Q, u, v;
vector<vector<int>> G;
vector<int> D, L;

void dfs(int u, int p, int d, DSU &dsu)
{
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            dfs(v, u, d + 1, dsu);
            if (L[v] > D[u]) dsu.unite(u, v);
            L[u] = min(L[u], L[v]);
        }
        else L[u] = min(L[u], D[v]);
    }
}

int main()
{
    while (cin >> R >> C >> Q && R)
    {
        G.assign(R, {});
        rep(_, C)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }

        DSU dsu(R);
        D.assign(R, -1); L.resize(R);
        rep(u, R) if (D[u] == -1) dfs(u, -1, 0, dsu);

        while (Q--)
        {
            cin >> u >> v; u--, v--;
            cout << (dsu.sameSet(u, v) ? 'Y' : 'N') << '\n';
        }
        cout << "-\n";
    }
}