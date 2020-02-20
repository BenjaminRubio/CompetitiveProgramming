#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct LCA
{
    vector<int> E, D, H, DP;
    vector<vector<int>> *g;
    int idx, n;

    int &rmq(int i, int e) { return DP[e * idx + i]; }
    inline int log2(int x) { return 31 - __builtin_clz(x); }

    void dfs(int u, int depth)
    {
        H[u] = idx, E[idx] = u, D[idx++] = depth;
        for (int v : (*g)[u]) if (H[v] == -1)
        {
            dfs(v, depth + 1);
            E[idx] = u;
            D[idx++] = depth;
        }
    }

    LCA(vector<vector<int>> &_g, int root)
    {
        g = &_g;
        n = _g.size();
        H.assign(n, -1);
        E.resize(2 * n);
        D.resize(2 * n);
        idx = 0;
        dfs(root, 0);
        int nn = idx;
        int maxe = log2(nn);
        DP.resize(nn * (maxe + 1));
        rep(i, nn) rmq(i, 0) = i;
        repx(e, 1, maxe + 1) rep(i, nn - (1 << e) + 1)
        {
            int i1 = rmq(i, e - 1);
            int i2 = rmq(i + (1 << (e - 1)), e - 1);
            rmq(i, e) = D[i1] < D[i2] ? i1 : i2;
        }
    }

    int lca(int u, int v)
    {
        int l = H[u], r = H[v];
        if (l > r) swap(l, r);
        int len = r - l + 1;
        int e = log2(len);
        int i1 = rmq(l, e);
        int i2 = rmq(r - ((1 << e) - 1), e);
        return D[i1] < D[i2] ? E[i1] : E[i2];
    }

    int dist(int u, int v)
    {
        return D[H[u]] + D[H[v]] - 2 * D[H[lca(u, v)]];
    }
};

int T, N, M, Q, u, v;
vector<vector<int>> g;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case " << t + 1 << ":\n";
        cin >> N;

        g.assign(N, {});
        vector<bool> root(N, true);
        rep(i, N)
        {
            cin >> M;
            rep(j, M)
            {
                cin >> u;
                g[i].push_back(u - 1);
                root[u - 1] = false;
            }
        }

        int r;
        rep(i, N) if (root[i]) r = i;

        LCA lca(g, r);

        cin >> Q;
        rep(_, Q)
        {
            cin >> u >> v;
            cout << lca.lca(u - 1, v - 1) + 1 << '\n';
        }
    }
}