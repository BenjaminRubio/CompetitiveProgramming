#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct LCA
{
    int N, LOG;
    vector<int> A, D;
    vector<vector<int>> G;
    int &anc(int u, int l) { return A[l * N + u]; }
    LCA(vector<vector<int>> &G, int N, int root) : G(G), N(N)
    {
        D.assign(N, -1); A.resize(N * (LOG + 1));
        dfs(root, -1, 0), LOG = 31 - __builtin_clz(N);
        rep(l, LOG + 1) if (l) rep(u, N)
        {
            int a = anc(u, l - 1);
            anc(u, l) = (a == -1 ? -1 : anc(a, l - 1));
        }
    }
    void dfs(int u, int p, int depth)
    {
        anc(u, 0) = p, D[u] = depth;
        for (int v : G[u]) if (D[v] == -1) dfs(v, u, depth + 1);
    }
    int raise(int u, int k)
    {
        for (int l = 0; k; l++, k >>= 1) if (k & 1) u = anc(u, l);
        return u;
    }
    int lca(int u, int v)
    {       
        if (D[u] < D[v]) swap(u, v); 
        u = raise(u, D[u] - D[v]);
        if (u == v) return u;
        for (int l = LOG; l >= 0; l--) if (anc(u, l) != anc(v, l))
            u = anc(u, l), v = anc(v, l);
        return anc(u,0);
    }
    int dist(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v)]; }
    int raise_in_path(int u, int v, int k)
    {
        if (D[u] - D[lca(u, v)] >= k) return raise(u, k);
        return raise(v, dist(u, v) - k);
    }
    int add_child(int p, int u)
    {
        G[p].push_back(u);
        D[u] = D[p] + 1, anc(u, 0) = p;
        rep(l, LOG) if (l)
        {
            p = anc(p, l - 1);
            if (p == -1) break;
            anc(u, l) = p;
        }
    }
};
