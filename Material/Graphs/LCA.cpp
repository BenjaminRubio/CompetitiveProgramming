#include "../Template.cpp"

struct LCA
{
    vvi G;
    int N, LOG; vi A, D;
    int &anc(int u, int l) { return A[l * N + u]; }
    LCA(vector<vi> &G, int N, int root) : G(G), N(N)
    {
        LOG = 31 - __builtin_clz(N);
        D.assign(N, -1); A.resize(N * (LOG + 1));
        
        dfs(root, -1, 0);
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
        G[p].pb(u);
        D[u] = D[p] + 1, anc(u, 0) = p;
        rep(l, LOG) if (l)
        {
            p = anc(p, l - 1);
            if (p == -1) break;
            anc(u, l) = p;
        }
    }
};

// LCA with HLD ( O(N) build time, O(log(N)) queries )

struct LCA
{
    vi A, H, D, R;

    LCA(vector<vi> &G, int n) : A(n), D(n), R(n)
    {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i;
    }
    int dfs(vector<vi> &G, int u)
    {
        int ans = 1, M = 0, s;
        for (int v : G[u]) if (v != A[u])
        {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }
    int lca(int u, int v)
    {
        while (D[R[u]] > D[R[v]]) u = A[R[u]];
        while (D[R[u]] < D[R[v]]) v = A[R[v]];
        return D[u] < D[v] ? u : v;
    }
    int dist(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v)];  }
};
