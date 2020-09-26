#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, Q, u, v, d;
vector<int> DD;
vector<vector<int>> G;

struct LCA
{
    int n, maxe;
    vector<int> A, D;
    int& anc(int u, int e) { return A[e * n + u]; }
    void dfs(int u, int p, int depth)
    {
        anc(u,0) = p;
        D[u] = depth;
        for (int v : G[u]) if (D[v] == -1) dfs(v, u, depth + 1);
    }
    LCA(int root)
    {
        n = G.size();
        maxe = 31 - __builtin_clz(n);
        D.assign(n, -1);
        A.resize(n * (maxe + 1));
        dfs(root, -1, 0);
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
    int dist(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v)]; }
    int kth_in_path(int u, int v, int k)
    {
        int l = lca(u, v);
        if (D[u] - D[l] >= k) return raise(u, k);
        return raise(v, dist(u, v) - k);
    }
};

void dfs(int u, int p, int d)
{
    DD[u] = d;
    for (int v : G[u]) if (v != p) dfs(v, u, d + 1);
}

int main()
{
    cin >> N >> Q;

    G.assign(N, {});
    rep(i, N - 1)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }

    LCA lca(0);

    DD.assign(N, -1);
    dfs(0, -1, 0); int M = -1, id1, id2;
    rep(i, N) if (DD[i] > M) M = DD[i], id1 = i;

    DD.assign(N, -1);
    dfs(id1, -1, 0); M = -1;
    rep(i, N) if (DD[i] > M) M = DD[i], id2 = i;

    while (Q--)
    {
        cin >> v >> d; v--;

        if (lca.dist(v, id1) >= d) cout << lca.kth_in_path(v, id1, d) + 1 << '\n';
        else if (lca.dist(v, id2) >= d) cout << lca.kth_in_path(v, id2, d) + 1 << '\n';
        else cout << 0 << '\n';
    }
}