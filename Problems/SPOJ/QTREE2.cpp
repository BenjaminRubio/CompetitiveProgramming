#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, N, u, v, w, k;
vector<vector<pair<int, int>>> G;
string s;

struct LCA
{
    int n, maxe;
    vector<int> A, D, DD;
    int& anc(int u, int e) { return A[e * n + u]; }
    void dfs(int u, int p, int dist, int depth)
    {
        anc(u,0) = p;
        D[u] = depth; DD[u] = dist;
        for (auto &e : G[u]) if (D[e.ff] == -1) dfs(e.ff, u, dist + e.ss, depth + 1);
    }
    LCA(int root)
    {
        n = G.size();
        maxe = 31 - __builtin_clz(n);
        D.assign(n, -1); DD.assign(n, -1);
        A.resize(n * (maxe + 1));
        dfs(root, -1, 0, 0);
        rep(e, maxe) rep(u, n)
        {
            int a = anc(u, e);
            anc(u, e + 1) = (a == -1 ? -1 : anc(a, e));
        }
    }
    int raise(int u, int k)
    {
        for (int e = 0; k; e++, k >>= 1) if (k & 1) u = anc(u, e);
        return u;
    }
    int lca(int u, int v)
    {       
        if (D[u] < D[v]) swap(u, v); 
        u = raise(u, D[u] - D[v]);
        if (u == v) return u;
        for (int e = maxe; e >= 0; e--) if (anc(u, e) != anc(v, e))
            u = anc(u, e), v = anc(v, e);
        return anc(u, 0);
    }
    int dist(int u, int v) { return DD[u] + DD[v] - 2 * DD[lca(u, v)]; }
    int nodes(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v)]; }
    int kth_in_path(int u, int v, int k)
    {
        int l = lca(u, v);
        if (D[u] - D[l] >= k) return raise(u, k);
        return raise(v, nodes(u, v) - k);
    }
};

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        G.assign(N, {});
        rep(i, N - 1)
        {
            cin >> u >> v >> w; u--, v--;
            G[u].emplace_back(v, w), G[v].emplace_back(u, w);
        }

        LCA lca(0);

        while (cin >> s && s != "DONE")
        {
            cin >> u >> v; u--, v--;
            if (s == "DIST") cout << lca.dist(u, v) << '\n';
            if (s == "KTH")
            {
                cin >> k;
                cout << lca.kth_in_path(u, v, k - 1) + 1 << '\n'; 
            }
        }
    }
}